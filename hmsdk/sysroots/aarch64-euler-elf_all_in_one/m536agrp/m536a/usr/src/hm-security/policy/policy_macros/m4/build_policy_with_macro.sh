#!/bin/bash

# Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
# Author: Huawei OS Kernel Lab
# Create: Wed Oct 16 17:58:08 2019

set -e

OPTS=`getopt -o t:w:l:b:o:h: --long tmp-dir:,work-dir:,log:,build-tool:output:header: \
     -n "$0" -- "$@"`

eval set -- "$OPTS"

POLICY_TMP_DIR=""
WORK_DIR=$(pwd)
DB_NAME="policy.db"
DEF_H_NAME="policy_def.h"
POLICY_BUILD_LOG="/dev/stdout"
POLICY_BUILD_TOOL=""
POLICY_COMMON_DIR="$( cd "$(dirname "$0")" ; pwd -P )"

while true ; do
        case "$1" in
                -t|--tmp-dir) POLICY_TMP_DIR="$2"; shift 2 ;;
                -w|--work-dir) WORK_DIR="$2"; shift 2 ;;
                -l|--log) POLICY_BUILD_LOG="$2"; shift 2 ;;
                -b|--build-tool) POLICY_BUILD_TOOL="$2"; shift 2 ;;
                -o|--output) DB_NAME="$2"; shift 2 ;;
                -h|--header) DEF_H_NAME="$2"; shift 2 ;;
                --) shift ; break ;;
                *) echo "An invalid option" ; exit 1 ;;
        esac
done

if [[ ! -f "${POLICY_BUILD_TOOL}" ]]; then
	echo "\"${POLICY_BUILD_TOOL}\" is not found" && false
fi

if [[ ! -d "${WORK_DIR}" ]]; then
	echo "\"${WORK_DIR}\" is not a directory" && false
fi

if [[ "${POLICY_TMP_DIR}x" != "x" && ! -d "${POLICY_TMP_DIR}" ]]; then
	echo "\"${POLICY_TMP_DIR}\" is not a directory" && false
fi

if [[ ! -d "$(dirname ${POLICY_BUILD_LOG})" ]]; then
	echo "\"${POLICY_BUILD_LOG}\" can't created" && false
fi

if [[ "${POLICY_TMP_DIR}x" == "x" ]]; then
	POLICY_TMP_DIR=$(mktemp -d -t hm-sec-plc-XXXXXXXX)
	CREATED_TMP_DIR=1
else
	CREATED_TMP_DIR=0
fi
#echo "build policy in ${POLICY_TMP_DIR}"

exithdlr()
{
	if [[ "$1" == 1 ]]; then
		rm -r "$2"
	fi
}

trap 'exithdlr ${CREATED_TMP_DIR} ${POLICY_TMP_DIR}' EXIT

EXPANDED_FILE="${POLICY_TMP_DIR}/expanded_policy.txt"

# delete tmp files
rm ${CREATED_TMP_DIR}/plc.*.json 2> /dev/null || true
rm ${CREATED_TMP_DIR}/pure.plc.*.json 2> /dev/null || true
# log file cleanup
cat /dev/null > ${POLICY_BUILD_LOG}

MACRO_FILES=$(for f in $@; do echo "$f"; done | grep -e ".m4$" || true)
RAW_FILES=$(for f in $@; do echo "$f"; done | grep -v -e ".m4$" || true)

expand_macro()
{
	m4 -P -I "${POLICY_COMMON_DIR}" "${POLICY_COMMON_DIR}/core.m4" "$1"
}

expand_macro "${POLICY_COMMON_DIR}/base.m4" > "${EXPANDED_FILE}"
for f in ${MACRO_FILES}; do
	expand_macro "$f" >> "${EXPANDED_FILE}"
done

#csplit "${EXPANDED_FILE}" '/^#---new file---$/' '{*}' -n8 \
	#-f "${POLICY_TMP_DIR}/plc." -b '%08d.json' &>> ${POLICY_BUILD_LOG}
"${POLICY_COMMON_DIR}/split.py" "${POLICY_TMP_DIR}" < "${EXPANDED_FILE}" &>> "${POLICY_BUILD_LOG}"
rm "${POLICY_TMP_DIR}/plc.00000000.json"

for f in $(ls ${POLICY_TMP_DIR}/plc.*.json); do
	sed '0,/^#---policy begin---$/d;/^#---policy end---$/,$d' "${f}" \
		> "$(dirname ${f})/pure.$(basename ${f})"
done

"${POLICY_BUILD_TOOL}" -o "${WORK_DIR}/${DB_NAME}" -h "${WORK_DIR}/${DEF_H_NAME}" \
	-v ${POLICY_TMP_DIR}/pure.plc.*.json ${RAW_FILES} &>> "${POLICY_BUILD_LOG}"

# generate SHA256 checksum and write to the chksum placeholder of {DB_NAME}
CHKSUM=$(sha256sum "${WORK_DIR}/${DB_NAME}")
echo $CHKSUM > "${WORK_DIR}/CHKSUM"
"${POLICY_BUILD_TOOL}" -i ${CHKSUM::64} -o "${WORK_DIR}/${DB_NAME}" &>> "${POLICY_BUILD_LOG}"
