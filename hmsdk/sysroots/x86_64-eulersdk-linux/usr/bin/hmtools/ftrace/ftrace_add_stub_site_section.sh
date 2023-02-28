#!/usr/bin/env bash
# Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
# Description: Ftrace add stub site section tool..
# Author: Huawei OS Kernel Lab
# Create: Wed Oct 16 17:58:08 2019

# Error out on error
set -eu
readonly SUPPORTED_FTRACE_ARCH_LIST=("arch64le" "arch64be")
readonly DEFAULT_FTRACE_SECTION_NAME=".ftrace_stub_site"
readonly FTRACE_STUB_IP_TMP_FILE="ftrace_stub_ip_site"
readonly FTRACE_STUB_INSN_TMP_FILE="ftrace_stub_insi_site"
readonly FTRACE_STUB_SITE_TMP_FILE="ftrace_stub_site"

host_tools_list=("egrep" "awk" "cut" "xargs" "printf" "readelf")

# check dependent host tools
function check_host_tools()
{
    for i in ${host_tools_list[@]}
    do
        if [ -z $(which ${i}) ]; then
            echo "Error: ${i} not exist, install first"
            exit 1
        fi
    done

    XXD=$(which xxd)
    if [ -z "${XXD}" ]; then
        if [ -f "/usr/bin/xxd" ]; then
            XXD="/usr/bin/xxd"
        elif [ -f "/bin/xxd" ]; then
            XXD="/bin/xxd"
        elif [ -f "/sbin/xxd" ]; then
            XXD="/sbin/xxd"
        elif [ -f "/usr/local/bin/xxd" ]; then
            XXD="/usr/local/bin/xxd"
        else
            echo "Error: xxd not exist, install first"
            exit 1
        fi
    fi
}

# check sdk environment
function check_sdk_tools()
{
    # check sdk objdump tool
    if [ -z "${OBJDUMP}" ]; then
        echo "Error: sdk objdump tool not exist in environment, exit"
        exit 1
    fi

    # check sdk objcopy tool
    if [ -z "${OBJCOPY}" ]; then
        echo "Error: sdk objcopy tool not exist in environment, exit"
        exit 1
    fi
}

# check support arch
function check_arch()
{
    for i in ${SUPPORTED_FTRACE_ARCH_LIST[@]}
    do
	echo "${i}===${ftrace_arch}"
        if [ "${i}" == "${ftrace_arch}" ]; then
            return
        fi
    done
    echo "Error: arch $1 not supported yet, exit"
    exit 1
}

function print_usage()
{
    echo "Usage: $0 [option(s)] in-file [out-file]"
    echo " Add ftrace stub section to a binary file"
    echo " Options:"
    echo -e " -A\tSet output arch, default aarch64le"
    echo -e " -F\tSet ftrace section name, default ${DEFAULT_FTRACE_SECTION_NAME}"
    echo
}

function parse_params()
{
    ftrace_arch="arch64le"
    ftrace_section_name=${DEFAULT_FTRACE_SECTION_NAME}
    while getopts "A:F:" opt; do
    case "$opt" in
    A)
        ftrace_arch=${OPTARG}
        ;;
    F)
        ftrace_section_name=${OPTARG}
        ;;
    ?)
        print_usage
        exit 1
    esac
    done

    shift $(($OPTIND - 1))
    input_file=$1
    ftrace_arch=$2
    if [ $# -gt 2 ]; then
        output_file=$3
    else
	output_file=""
    fi

    if [ -z "${input_file}" ] || [ ! -f "${input_file}" ]; then
        echo "Error: must specify a exist input file, exit"
        print_usage
        exit 1
    fi

    if [ -z "${output_file}" ]; then
        output_file=${input_file}
    fi
}

function print_params()
{
    echo "Params:"
    echo "Arch        : ${ftrace_arch}"
    echo "Section name: ${ftrace_section_name}"
    echo "Input file  : ${input_file}"
    echo "Output file : ${output_file}"
    echo
}

function arch64le_check_input_file()
{
    elf=$($(which readelf) -h ${input_file} | $(which egrep) "Class.*ELF64")
    if [ -z "${elf}" ]; then
        echo "Error: ${input_file} invalid elf format"
        exit 1
    fi

    endian=$($(which readelf) -h ${input_file} | $(which egrep) "Data:.* endian")
    if [ -z "{endian}" ]; then
        echo "Error: ${input_file} invalid endian format"
        exit 1
    fi
}

function check_input_file()
{
    case "${ftrace_arch}" in
    arch64le|arch64be)
        arch64le_check_input_file
        ;;
    *)
        echo "Error: ${input_file} invalid arch"
        exit 1
        ;;
    esac
}

function arch64_add_ftrace_section()
{
    # if .ftrace_stub_site section exist, return
    stub_section=$($(which readelf) -SW ${input_file} | $(which grep) "${ftrace_section_name}")
    if [ ! -z "${stub_section}" ]; then
        echo "Error: ${input_file} ${ftrace_section_name} section exist, exit"
        exit 1
    fi

    check_input_file

    stub_ip_list=$(${OBJDUMP} --prefix-addresses --show-raw-insn -hdr ${input_file} \
                   | $(which egrep) "bl.*[0-9a-e]{16}*<_mcount(@plt)*>" | $(which awk) '{print $1}')
    stub_insn_list=$(${OBJDUMP} --prefix-addresses --show-raw-insn -hdr ${input_file} \
                   | $(which egrep) "bl.*[0-9a-e]{16}*<_mcount(@plt)*>" | $(which awk) '{print $3}')
    if [ -z "${stub_ip_list}" ] || [ -z "${stub_insn_list}" ]; then
        echo "Error: ${input_file} maybe compile without -pg or matching regular expression has an error, exit"
        exit 1
    fi

    stub_ip_num=$(echo ${stub_ip_list} | wc -w)
    stub_insn_num=$(echo ${stub_insn_list} | wc -w)
    if [ "${stub_ip_num}" -ne "${stub_insn_num}" ]; then
        echo -e "ip list not match insn list, please check:\nstub_ip_list:\n${stub_ip_list}\nstub_insn_list:\n${stub_insn_list}"
        exit 1
    fi

    stub_ip_size=$[${stub_ip_num} * 8 + 8]
    echo -e "ftrace_stub_ip_list(num: ${stub_ip_num}, size: ${stub_ip_size}):\n${stub_ip_list}"
    stub_insn_size=$[${stub_insn_num} * 4]
    echo -e "ftrace_stub_insn_list(num: ${stub_insn_num}, size: ${stub_insn_size}):\n${stub_insn_list}"

    # write total number
    echo "${stub_ip_num}" | $(which xargs) $(which printf) "%016x" | ${XXD} -r -ps > ${FTRACE_STUB_IP_TMP_FILE}

    # write ip list
    echo ${stub_ip_list} | ${XXD} -r -ps >> ${FTRACE_STUB_IP_TMP_FILE}
    if [ ! -f "${FTRACE_STUB_IP_TMP_FILE}" ];then
        echo "Error: cannot create stub ip list tmp file, exit"
        exit 1
    fi
    # check the endian
    if [ "${ftrace_arch}" == "arch64le" ]; then
        ${OBJCOPY} -I binary -O binary --reverse-bytes=8 ${FTRACE_STUB_IP_TMP_FILE} ${FTRACE_STUB_IP_TMP_FILE}
        if [ $? -ne 0 ]; then
            echo "objcopy generate ip list file failed, exit"
        fi
    fi

    # write insn list
    echo ${stub_insn_list} | ${XXD} -r -ps > ${FTRACE_STUB_INSN_TMP_FILE}
    if [ ! -f "${FTRACE_STUB_INSN_TMP_FILE}" ];then
        echo "Error: cannot create stub insn list tmp file, exit"
        exit 1
    fi
    ${OBJCOPY} -I binary -O binary --reverse-bytes=4 ${FTRACE_STUB_INSN_TMP_FILE} ${FTRACE_STUB_INSN_TMP_FILE}
    if [ $? -ne 0 ]; then
        echo "objcopy generate insn list file failed, exit"
    fi

    # calc totoal size for check
    stub_total_size=$[${stub_ip_size} + ${stub_insn_size}]

    # add ftrace section to elf
    cat ${FTRACE_STUB_IP_TMP_FILE} ${FTRACE_STUB_INSN_TMP_FILE} > ${FTRACE_STUB_SITE_TMP_FILE}
    ${OBJCOPY} --add-section ${ftrace_section_name}=${FTRACE_STUB_SITE_TMP_FILE} --set-section-flags ${ftrace_section_name}=noload,readonly ${input_file} ${output_file}
    if [ $? -ne 0 ]; then
        echo "objcopy add section failed, exit"
    fi

    #check ftrace stub site section
    if [ ! -f "${output_file}" ]; then
        echo "Error: ${output_file} is not generated, please check"
        exit 1
    fi
    section_size=$($(which readelf) -SW ${output_file} | $(which grep) "${ftrace_section_name}" | cut -d ' ' -f 15)
    if [ -z "${section_size}" ]; then
       echo "Error: ${output_file} ${ftrace_section_name} not exist, exit"
       exit 1
    fi
    section_size=$(echo 0x${section_size} | $(which xargs) $(which printf) "%d")
    echo "expected section size is ${stub_total_size}, actual section size is ${section_size}"
    if [ "${section_size}" -ne "${section_size}" ]; then
        echo "Error: output file ftrace stub site section invalid, please check"
        exit 1
    fi

    echo "Add ftrace_stub_site section succeed"
    exit 0
}

function add_ftrace_section()
{
    case "${ftrace_arch}" in
    arch64le|arch64be)
        arch64_add_ftrace_section
        ;;
    *)
        echo "Error: specify invalid arch"
        exit 1
        ;;
    esac
}

parse_params $*
print_params
check_sdk_tools
set +e
set +u
check_host_tools
check_arch
add_ftrace_section
