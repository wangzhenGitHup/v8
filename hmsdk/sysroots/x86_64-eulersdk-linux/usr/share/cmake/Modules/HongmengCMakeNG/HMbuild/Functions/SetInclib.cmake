# Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# Description: HMbuild SetInclib cmd
# Author: Huawei OS Kernel Lab
# Create: Mon Jun 28 14:16:29 2021

include(HongmengCMakeNG/Log)
include(HongmengCMakeNG/HMbuild/Cache)

function(hmbuild_set_source_inclib source inclib)
    cmake_parse_arguments (PARSE_ARGV 0 _srcinclib "" "" "")
    hmcmakeng_debug("hmbuild_set_source_inclib: source=${source} INCLIB=${inclib}")

    separate_arguments(inclib)
    foreach(lib IN LISTS inclib)
        if (NOT TARGET ${lib})
            if (DEFINED HMBUILD_MAKE_BINARIES)
                hmcmakeng_error("Inclib ${lib} not found")
            endif()
            continue()
        endif()
        set_property(SOURCE ${source} APPEND PROPERTY INCLUDE_DIRECTORIES
                     $<TARGET_PROPERTY:${lib},INTERFACE_INCLUDE_DIRECTORIES>)
        set_property(SOURCE ${source} APPEND PROPERTY COMPILE_DEFINITIONS
                     $<TARGET_PROPERTY:${lib},INTERFACE_COMPILE_DEFINITIONS>)
    endforeach()
endfunction(hmbuild_set_source_inclib)

function(hmbuild_set_dir_inclib inclib)
    hmcmakeng_debug("hmbuild_set_dir_inclib: INCLIB=${inclib}")

    separate_arguments(inclib)
    foreach(lib IN LISTS inclib)
        if (NOT TARGET ${lib})
            if (DEFINED HMBUILD_MAKE_BINARIES)
                hmcmakeng_error("Inclib ${lib} not found")
            endif()
            continue()
        endif()
        set_property(DIRECTORY APPEND PROPERTY INCLUDE_DIRECTORIES
                     $<TARGET_PROPERTY:${lib},INTERFACE_INCLUDE_DIRECTORIES>)
        set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
                     $<TARGET_PROPERTY:${lib},INTERFACE_COMPILE_DEFINITIONS>)
    endforeach()
endfunction(hmbuild_set_dir_inclib)

function(hmbuild_set_target_inclib target inclib_list)
    hmcmakeng_debug("hmbuild_set_target_inclib:target=${target} INCLIBS=${inclib_list}")

    hmbuild_target_cmakename_of(cmake_target ${target})
    foreach(lib IN LISTS inclib_list)
        if (NOT TARGET ${lib})
            if (DEFINED HMBUILD_MAKE_BINARIES)
                hmcmakeng_error("Inclib ${lib} not found")
            endif()
            continue()
        endif()
        target_include_directories("${cmake_target}" PRIVATE
                                   $<TARGET_PROPERTY:${lib},INTERFACE_INCLUDE_DIRECTORIES>)
        set_property(TARGET "${cmake_target}" APPEND PROPERTY COMPILE_DEFINITIONS
                     $<TARGET_PROPERTY:${lib},INTERFACE_COMPILE_DEFINITIONS>)
    endforeach()
endfunction(hmbuild_set_target_inclib)

function(hmbuild_append_target_inclib targets inclibs)
    hmcmakeng_debug(
            "hmbuild_append_target_inclib:targets=${targets} INCLIBS=${inclibs}")

    separate_arguments(targets)
    separate_arguments(inclibs)
    foreach(t ${targets})
        foreach(lib IN LISTS inclibs)
            hmbuild_cache_append_to(inclib_list_${t} "${lib}")
        endforeach()
    endforeach()
endfunction(hmbuild_append_target_inclib)

function(hmbuild_inclib_config_target target)
    hmbuild_cache_val_of(inclib_list inclib_list_${target})
    hmcmakeng_debug("hmbuild_inclib_config_target: inclib_list_${target}=${inclib_list}")
    if (inclib_list)
        hmbuild_set_target_inclib(${target} "${inclib_list}")
    endif(inclib_list)
endfunction(hmbuild_inclib_config_target)

# vim:ts=4:sw=4:expandtab
