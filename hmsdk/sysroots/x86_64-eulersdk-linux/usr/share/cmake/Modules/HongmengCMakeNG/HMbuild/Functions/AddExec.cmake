# Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# Description: HMbuild hmbuild_add_exec function
# Author: Huawei OS Kernel Lab
# Create: Wed May 26 13:20:30 2021

include(HongmengCMakeNG/Log)
include(HongmengCMakeNG/HMbuild/Cache)
include(HongmengCMakeNG/HMbuild/Builtin)
include(HongmengCMakeNG/HMbuild/Condition)
include(HongmengCMakeNG/HMbuild/Targets)

function(hmbuild_exec_name outvar targetname suffix appendstr)
    if ("${targetname}" MATCHES "^.*\.elf$")
        string(REGEX REPLACE "\.elf$" "${suffix}${appendstr}.elf" newname ${targetname})
        set(${outvar} "${newname}"
                PARENT_SCOPE)
    else()
        set(${outvar} "${targetname}${suffix}${appendstr}"
                PARENT_SCOPE)
    endif()
endfunction(hmbuild_exec_name)

macro(_hmbuild_add_exec_gen_names outvar target suffix)
    hmbuild_exec_name(${outvar}_release "${target}" "${suffix}" "")
    hmbuild_exec_name(${outvar}_devel   "${target}" "${suffix}" ".unstripped")
endmacro(_hmbuild_add_exec_gen_names)

function(_hmbuild_add_exec target is_static)
    _hmbuild_add_exec_gen_names(targetname ${target} "")

    hmbuild_target_output_name_of(output_name "${target}")
    if (NOT output_name)
        set(output_name "${target}")
    endif()

    _hmbuild_add_exec_gen_names(filename ${output_name} "${CONFIG_HMBUILD_OUTPUT_SUFFIX}")

    hmcmakeng_debug("hmbuild_add_dynamic_exec: targetname_release=${targetname_release}(fn=${filename_release}), targetname_devel=${targetname_devel}(fn:${filename_devel})")

    set(filepath_release "${CMAKE_CURRENT_BINARY_DIR}/${filename_release}")

    hmbuild_cache_val_of(_srcs "src_${target}")
    string(STRIP "${_srcs}" srcs)

    if (srcs)
        add_executable(${targetname_devel} ${srcs})
    else()
        # Give cmake an empty object file for hacking
        file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${target}_null.c "")
        add_executable(${targetname_devel} ${target}_null.c)
    endif()
    set_target_properties(${targetname_devel} PROPERTIES OUTPUT_NAME "${filename_devel}")
    hmbuild_target_set_cmakename(${target} "${targetname_devel}")

    hmbuild_target_link_builtin(${target})
    if (NOT is_static)
        target_link_libraries(${targetname_devel} PRIVATE
                              LibGcc::LibGcc_shared)
        target_link_options(${targetname_devel} PRIVATE
                            "-Wl,--export-dynamic")
    else()
        target_link_libraries(${targetname_devel} PRIVATE
                              LibGcc::LibGcc_static)
        target_link_options(${targetname_devel} PRIVATE
                            "-static")
    endif()
    hmcmakeng_debug("_hmbuild_add_exec: source of ${targetname_devel}: ${srcs}")

    add_custom_command(OUTPUT ${filepath_release}
                       COMMAND cmake -E copy $<TARGET_FILE:${targetname_devel}>
                                    ${filepath_release}
                       COMMAND ${CMAKE_STRIP} -D ${CONFIG_HMBUILD_STRIP_OPTION} ${filepath_release}
                       DEPENDS ${targetname_devel})

    add_custom_target(__build_${targetname_release} ALL DEPENDS ${filepath_release})
    set_target_properties(__build_${targetname_release}    PROPERTIES
                          "hmprop_output_release" ${filepath_release})
    set_target_properties(__build_${targetname_release}    PROPERTIES
                          "hmprop_output_devel" $<TARGET_FILE:${targetname_devel}>)

endfunction(_hmbuild_add_exec)

function(hmbuild_add_static_exec target)
    _hmbuild_add_exec(${target} "TRUE")
endfunction(hmbuild_add_static_exec)

function(hmbuild_add_dynamic_exec target)
    _hmbuild_add_exec(${target} "FALSE")
endfunction(hmbuild_add_dynamic_exec)

function(hmbuild_append_exec_list)
    cmake_parse_arguments (PARSE_ARGV 0 _appendexec "" "TARGET;TYPE;CONDITION" "")
    hmcmakeng_debug("hmbuild_append_exec_list: target=${_appendexec_TARGET}, type=${_appendexec_TYPE} CONDITION=${_appendexec_CONDITION}")

    # Check condition
    hmbuild_check_condition(checkcond "${_appendexec_CONDITION}")
    if (NOT ${checkcond})
        return()
    endif()

    # Append to hmcache list
    if ("${_appendexec_TYPE}" STREQUAL "static")
        hmcmakeng_debug("hmbuild_append_exec_list static")
        hmbuild_cache_append_to(targets_exec_static "${_appendexec_TARGET}")
    elseif ("${_appendexec_TYPE}" STREQUAL "dynamic")
        hmcmakeng_debug("hmbuild_append_exec_list dynamic")
        hmbuild_cache_append_to(targets_exec_dynamic "${_appendexec_TARGET}")
    else()
        hmcmakeng_error("hmbuild_append_exec_list: not supported - ${_appendexec_TYPE}")
    endif()
endfunction(hmbuild_append_exec_list)

function(hmbuild_exec_add_all_targets)
    # Headers only build?
    if (NOT (DEFINED HMBUILD_MAKE_BINARIES))
        return()
    endif()

    hmbuild_cache_val_of(targets targets_exec_static)
    foreach(t ${targets})
        hmcmakeng_status("Target: static exec ${t} in ${HMBUILD_DIR_PREFIX_VERBOSE}")
        hmbuild_add_static_exec(${t})
    endforeach()

    hmbuild_cache_val_of(targets targets_exec_dynamic)
    foreach(t ${targets})
        hmcmakeng_status("Target: dynamic exec ${t} in ${HMBUILD_DIR_PREFIX_VERBOSE}")
        hmbuild_add_dynamic_exec(${t})
    endforeach()
endfunction(hmbuild_exec_add_all_targets)

# vim:ts=4:sw=4:expandtab
