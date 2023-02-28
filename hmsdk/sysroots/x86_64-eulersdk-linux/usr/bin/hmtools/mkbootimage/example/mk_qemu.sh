#!/usr/bin/env bash
# Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
# Description: Example for packing sd62xx image
# Author: Huawei OS Kernel Lab
# Create: Mon Sept 27 08:59:57 2021
set -e

if [ "x${HMSDKPATH}${HMSDKPATH_NATIVE}${HMSDKSYSROOTPATH}" == "x" ]; then
    echo "env is not set"
    exit 0
fi

# or qemu.arm32-le.rootfs.manifest, or others
HMMANIFEST="qemu.rootfs.manifest"
if [ $# -ge 1 ]; then
    HMMANIFEST=$1
fi

# or virt.dtb for aarch64le, or virt-be.dtb for aarch64be
# or virt-hyp.dtb for aarch64lehyp
HMDTB="vexpress-a9.dtb"
if [ $# -ge 2 ]; then
    HMDTB=$2
fi

HMMANIFESTPATH=$HMSDKPATH_NATIVE/usr/share/manifest
HMTOOLSPATH=$HMSDKPATH_NATIVE/usr/bin/hmtools/mkbootimage

# multiple manifest is supported
# NOTE: remove --force after fixlink
python3 $HMTOOLSPATH/mkrootfs.py \
    --force \
    --manifest=$HMMANIFESTPATH/${HMMANIFEST} \
    --sysroot=$HMSDKSYSROOTPATH \
    --output=rootfs.cpio

# for qemu64lehyp qemu64leiot plat,
# "--append=$HMSDKSYSROOTPATH/boot/hmvirt.elf" should be added.
python3 $HMTOOLSPATH/mkarchive.py \
    --kernel=$HMSDKSYSROOTPATH/boot/kernel.elf \
    --sysproc=$HMSDKSYSROOTPATH/boot/sysmgr.elf \
    --sysproc=$HMSDKSYSROOTPATH/boot/idle.elf \
    --dtb=$HMSDKSYSROOTPATH/boot/dtbs/$ARCH/qemu/$HMDTB \
    --output=archive.cpio

if [ -f archive.cpio.xz ]; then
    rm -f archive.cpio.xz
fi
xz -e -z -7 -k archive.cpio

python3 $HMTOOLSPATH/mkbootimage.py \
    --cross-compile=$CROSS_COMPILE \
    --archive=archive.cpio.xz \
    --rootfs=rootfs.cpio \
    --elfloader-elf=$HMSDKSYSROOTPATH/boot/elfloader.elf \
    --elfloader-map=$HMSDKSYSROOTPATH/boot/elfloader.map \
    --bootimage-head-elf=$HMSDKSYSROOTPATH/boot/bootimage_head.elf \
    --bootimage-head-map=$HMSDKSYSROOTPATH/boot/bootimage_head.map \
    --output=Image

# vim:ts=4:sw=4:expandtab
