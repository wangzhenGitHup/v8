#!/usr/bin/env bash
# Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
# Description: Example for make m536a Image
# Author: Huawei OS Kernel Lab
# Create: Mon Jun 21 20:08:32 2021

# Arguments:
# - @CROSS_COMPILE: cross compile prefix
# - @IMAGE_COMPRESS_ARCHIVE: whether compress archive, default not set
# - @IMAGE_STANDALONE_ROOTFS: whether the rootfs is outside Image, default not set
# - @IMAGE_SYSROOTPATH: path to image sysroot, default $HMSDKSYSROOTPATH
# - @IMAGE_NATIVESYSROOTPATH: path to native sysroot for make image, default $HMSDKNATIVESYSROOT
# - @IMAGE_TOOL_PATH: path to mkbootimage tools, default $IMAGE_NATIVESYSROOTPATH/usr/bin/hmtools/mkbootimage
# - @IMAGE_MANIFEST_PATH: path to image manifest, default $IMAGE_NATIVESYSROOTPATH/usr/share/manifest
# - @IMAGE_UAPPS_MANIFEST: manifest for mkproperty.py, default uapps-m536a.manifest
# - @IMAGE_UAPPS_FILES: files to be added in uapps.cpio (no need to specify properties)
# - @IMAGE_ROOTFS_MANIFEST: manifest for mkrootfs.py, default m536a-base.manifest,
#    debug m536a-base.manifest m536a-ci.manifest m536a-ci-profile-debug.manifest m536a-ci-profile-release.manifest
# - @IMAGE_DTB_PATH: dtb path, default $IMAGE_SYSROOTPATH/boot/dtbs
# - @IMAGE_DTB_FILES: dtb files, default (empty)
# - @ELFIMAGE_COMPILER_RT: compiler runtime for elf image, only for qemu, default libclang_rt.builtins.a
# - @ELFIMAGE_TEXT_START: link address of text start for elf image, only for quemu, default 0x40100000

# Function depdencies:
# mk_property <- mk_uappscpio <- mk_archive <- mk_image, mk_elfimage
# mk_rootfs <- mk_image, mk_elfimage, mk_checksum

set -e
# setup environments args
if [ "x${HMSDKSYSROOTPATH}${HMSDKNATIVESYSROOTPATH}" == "x" ]; then
	echo "env is not set, try source ../environment-setup-aarch64-euler-elf m536a"
	source ../environment-setup-aarch64-euler-elf m536a
fi
export IMAGE_DTB_FILES="aarch64/m536a-ree/m536a-hyp.dtb aarch64/m536a-ree/overlay-hyp.dtb"
export IMAGE_UAPPS_FILES="bin/init.elf bin/vdso.so bin/vfs.elf usr/bin/test-helper.elf usr/lib/policy.db usr/lib/policy_bypass.db boot/sysmgr.elf"

[ -z "$IMAGE_SYSROOTPATH" ] && export IMAGE_SYSROOTPATH=$HMSDKSYSROOTPATH
[ -z "$IMAGE_NATIVESYSROOTPATH" ] && export IMAGE_NATIVESYSROOTPATH=$HMSDKNATIVESYSROOTPATH
[ -z "$IMAGE_TOOL_PATH" ] && export IMAGE_TOOL_PATH=$IMAGE_NATIVESYSROOTPATH/usr/bin/hmtools/mkbootimage
[ -z "$IMAGE_MANIFEST_PATH" ] && export IMAGE_MANIFEST_PATH=$IMAGE_NATIVESYSROOTPATH/usr/share/manifest
[ -z "$IMAGE_UAPPS_MANIFEST" ] && export IMAGE_UAPPS_MANIFEST="uapps-m536a.manifest uapps-addon.manifest"
[ -z "$IMAGE_ROOTFS_MANIFEST" ] && export IMAGE_ROOTFS_MANIFEST="m536a-base.manifest m536a-ci.manifest m536a-ci-profile-debug.manifest kasan.manifest"
[ -z "$IMAGE_DTB_PATH" ] && export IMAGE_DTB_PATH="$IMAGE_SYSROOTPATH/boot/dtbs"

# Function: mk_property
# Description: Generate properties files for system services
mk_property()
{
    # set the manifest of properties for uapps.cpio
    MANIFEST_ARG=""
    for manifest in $IMAGE_UAPPS_MANIFEST; do
        MANIFEST_ARG+=" --manifest=${IMAGE_MANIFEST_PATH}/${manifest}"
    done
    python3 $IMAGE_TOOL_PATH/mkproperty.py --force --sysroot-native=$IMAGE_NATIVESYSROOTPATH \
        --sysroot=$IMAGE_SYSROOTPATH ${MANIFEST_ARG} --output-dir=property
}

# Function: mk_uappscpio
# Description: Generate uapps.cpio
mk_uappscpio()
{
    APPEND_ARG=""
    # add all properties
    for item in $(ls -1 property); do
        if [ -f "property/${item}" ]; then
            APPEND_ARG+=" --append=property/${item}"
        fi
    done
    for item in ${IMAGE_UAPPS_FILES}; do
        APPEND_ARG+=" --append=${IMAGE_SYSROOTPATH}/${item}"
    done
    python3 $IMAGE_TOOL_PATH/mkarchive.py --force --no-name-align --no-size-align ${APPEND_ARG}\
        --append=verifyallfilessha256sum.db --output=uapps.cpio
}

# Function: mk_archive
# Description: Generate archive.cpio
mk_archive()
{
    DTB_ARG=""
    for dtb in $IMAGE_DTB_FILES; do
        DTB_ARG+=" --dtb=${IMAGE_DTB_PATH}/${dtb}"
    done
    python3 $IMAGE_TOOL_PATH/mkarchive.py \
        --force \
        --append=$IMAGE_SYSROOTPATH/boot/kernel.elf \
        --append=$IMAGE_SYSROOTPATH/boot/sysmgr.elf \
        --append=$IMAGE_SYSROOTPATH/boot/idle.elf \
        --append=$IMAGE_SYSROOTPATH/boot/hmvirt.elf \
        --append=$IMAGE_SYSROOTPATH/boot/hkip.elf \
        --append=uapps.cpio \
        ${DTB_ARG}
    if [ ! -z "$IMAGE_COMPRESS_ARCHIVE" ]; then
        rm -f archive.cpio.xz && xz -e -z -8 -k archive.cpio
    fi
}

# Function: mk_rootfs
# Description: Generate rootfs.cpio
mk_rootfs()
{
    # manifest for making rootfs.cpio
    MANIFEST_ARG_ROOTFS=""
    for manifest in $IMAGE_ROOTFS_MANIFEST; do
        MANIFEST_ARG_ROOTFS+=" --manifest=${IMAGE_MANIFEST_PATH}/${manifest}"
    done
    python3 $IMAGE_TOOL_PATH/mkrootfs.py --force --sysroot=$IMAGE_SYSROOTPATH \
        --sysroot-native=$IMAGE_NATIVESYSROOTPATH ${MANIFEST_ARG_ROOTFS}
}

# Function: mk_checksum
# Description: Generate checksum file from rootfs.cpio
mk_checksum() {
    WORK_PATH=$(pwd)
    python3 $IMAGE_TOOL_PATH/mkchksum.py --rootfscpio=$WORK_PATH/rootfs.cpio --tmpdir=$WORK_PATH/ \
        --sysroot=$IMAGE_SYSROOTPATH --sysroot-native=$IMAGE_NATIVESYSROOTPATH --output=verifyallfilessha256sum.db
}

# Function: mk_image
# Description: Generate Image
mk_image()
{
    if [ -z "$IMAGE_COMPRESS_ARCHIVE" ]; then
        ARCHIVE=archive.cpio
    else
        ARCHIVE=archive.cpio.xz
    fi
    if [ ! -z "$IMAGE_STANDALONE_ROOTFS" ]; then
        ROOTFS_ARG=""
    else
        ROOTFS_ARG=" --rootfs=rootfs.cpio"
    fi
    python3 $IMAGE_TOOL_PATH/mkbootimage.py --cross-compile=${CROSS_COMPILE} \
        --output=Image --archive=${ARCHIVE} ${ROOTFS_ARG} --elfloader-elf="${IMAGE_SYSROOTPATH}/boot/elfloader.elf" \
        --elfloader-map="${IMAGE_SYSROOTPATH}/boot/elfloader.map" \
        --bootimage-head-elf="${IMAGE_SYSROOTPATH}/boot/bootimage_head.elf" \
        --bootimage-head-map="${IMAGE_SYSROOTPATH}/boot/bootimage_head.map"
}

mk_property
mk_rootfs
mk_checksum
mk_uappscpio

mk_archive
mk_image
