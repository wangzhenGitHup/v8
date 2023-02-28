# Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# Description: llvm-ar settings for HMbuild
# Author: Huawei OS Kernel Lab
# Create: Sat May 29 02:50:08 2021

function(hmbuild_create_regular_archive target src)
    add_custom_command(OUTPUT ${target}
                       COMMAND ${CMAKE_COMMAND} -E remove -f ${target}
                       COMMAND ${BASH} -c "${CMAKE_AR} t $<TARGET_FILE:${src}> | \
                                    xargs ${CMAKE_AR} rcDs ${target}"
                       DEPENDS ${src}
                       VERBATIM)
endfunction()

# Build thin library, similar to linux
# Link flags are archive to be merged.
set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> cDrST <TARGET> <LINK_FLAGS> <OBJECTS>")

# vim:ts=4:sw=4:expandtab
