#!/usr/bin/env bash
# Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
# Description: Example for packing sd62xx image
# Author: Huawei OS Kernel Lab
# Create: Sun Sept 26 17:15:20 2021
set -e

if [ "x${HMSDKPATH}${HMSDKPATH_NATIVE}${HMSDKSYSROOTPATH}" == "x" ]; then
    echo "env is not set"
    exit 0
fi

# or sd6221-base.manifest
HMMANIFEST="sd6220-base.manifest"
if [ $# -ge 1 ]; then
    HMMANIFEST=$1
fi

HMMANIFESTPATH=$HMSDKPATH_NATIVE/usr/share/manifest
HMTOOLSPATH=$HMSDKPATH_NATIVE/usr/bin/hmtools/mkbootimage

# multiple manifest is supported
python3 $HMTOOLSPATH/mkrootfs.py \
    --manifest=$HMMANIFESTPATH/${HMMANIFEST} \
    --sysroot=$HMSDKSYSROOTPATH \
    --output=rootfs.cpio

python3 $HMTOOLSPATH/mkarchive.py \
    --kernel=$HMSDKSYSROOTPATH/boot/kernel.elf \
    --sysproc=$HMSDKSYSROOTPATH/boot/sysmgr.elf \
    --sysproc=$HMSDKSYSROOTPATH/boot/idle.elf \
    --output=archive.cpio

if [ -f archive.cpio.xz ]; then
    rm -f archive.cpio.xz
fi
xz -e -z -7 -k archive.cpio

python3 $HMTOOLSPATH/mkbootimage.py \
    --cross-compile=$CROSS_COMPILE \
    --archive=archive.cpio.xz \
    --elfloader-elf=$HMSDKSYSROOTPATH/boot/elfloader.elf \
    --elfloader-map=$HMSDKSYSROOTPATH/boot/elfloader.map \
    --bootimage-head-elf=$HMSDKSYSROOTPATH/boot/bootimage_head.elf \
    --bootimage-head-map=$HMSDKSYSROOTPATH/boot/bootimage_head.map \
    --output=Image

# vim:ts=4:sw=4:expandtab
