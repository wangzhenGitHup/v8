# Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
# Description: HMbuild hmbuild_exclude_cflags function
# Author: Huawei OS Kernel Lab
# Create: Fri Oct 15 11:54:16 2021

include(HongmengCMakeNG/Log)
include(HongmengCMakeNG/HMbuild/Cache)
include(HongmengCMakeNG/HMbuild/Functions/AddSrc)

#
# Applies CMAKE_C_FLAGS to all targets in the current CMake directory.
#
function(apply_global_c_flags_to_all_targets)
    set(global_c_flags_list "SHELL: ${CMAKE_C_FLAGS} ")
    hmbuild_all_targets(targets)
    foreach(t IN LISTS targets)
        hmbuild_target_cmakename_of(cmake_target ${t})
        # not use PUBILIC, otherwise will set INTERFACE_COMPILE_OPTIONS
        target_compile_options(${cmake_target} PRIVATE ${global_c_flags_list})
        hmcmakeng_debug("apply_global_c_flags_to_all_targets: apply ${cmake_target} ${global_c_flags_list}")
        hmbuild_cache_set(exclude_global_cflags_list_"${t}" "${global_c_flags_list}")
    endforeach()
endfunction(apply_global_c_flags_to_all_targets)

function(__append_cflag_to_src source_file flag)
    hmbuild_cache_val_of(already_append_flags "append_c_flags_${source_file}")
    if ("${flag}" IN_LIST already_append_flags)
        return()
    endif()
    hmbuild_cache_append_to(append_c_flags_${source_file} "${flag}")
    # Ugly: cmake behavior which about set COMPILE_OPTIONS
    # between src and others is different,
    # if directoly use 'A B' set src flags,
    # it will be set as this cflag="A B"(cmake add double quotation)
    # so need chagnge cmd 'A B' to A;B
    separate_arguments(flag)
    get_property(source_file_c_flags SOURCE ${source_file} PROPERTY COMPILE_OPTIONS)
    if(source_file_c_flags)
        list(APPEND source_file_c_flags "${flag}")
    else()
        set(source_file_c_flags "${flag}")
    endif()
    set_property(SOURCE ${source_file} PROPERTY COMPILE_OPTIONS "${source_file_c_flags}")
    hmcmakeng_debug("__append_cflag_to_src: set ${source_file}=${source_file_c_flags}")
endfunction(__append_cflag_to_src)

function(hmbuild_exclude_target_cflags target cflags_list)
    hmbuild_target_cmakename_of(cmake_target ${target})
    hmcmakeng_debug("hmbuild_exclude_target_cflags:target=${target} FLAGS=${cflags_list} cmake_target=${cmake_target}")

    # Taget cflags= global_flags;others
    # we only remove global_flags
    get_target_property(target_flags ${cmake_target} COMPILE_OPTIONS)
    hmbuild_cache_val_of(global_flags exclude_global_cflags_list_"${target}")
    foreach(f IN LISTS target_flags)
        if(NOT ("${f}" MATCHES "${global_flags}"))
            list(APPEND new_target_flags "${f}")
        endif()
    endforeach()
    hmbuild_cache_val_of(already_removed_flags "removed_c_flags_${cmake_target}")
    set(after_removed_global_flags ${global_flags})
    foreach(flag IN LISTS cflags_list)
        if (flag IN_LIST already_removed_flags)
            continue()
        endif()
        hmbuild_cache_append_to("removed_c_flags_${target}" "${flag}")
        string(REGEX REPLACE "${flag}" " " after_removed_global_flags "${after_removed_global_flags}")
    endforeach()
    hmbuild_cache_set(exclude_global_cflags_list_"${target}" "${after_removed_global_flags}")
    list(APPEND new_target_flags "${after_removed_global_flags}")
    set_target_properties(${cmake_target} PROPERTIES COMPILE_OPTIONS "${new_target_flags}")
    hmcmakeng_debug("hmbuild_exclude_target_cflags: set ${cmake_target}=${new_target_flags}")
endfunction(hmbuild_exclude_target_cflags)

function(hmbuild_exclude_src_cflags src cflags_list)
    hmcmakeng_debug("hmbuild_exclude_src_cflags:src=${src} FLAGS=${cflags_list}")
    hmbuild_cache_val_of(removed_flags "removed_c_flags_${src}")
    foreach(flag IN LISTS cflags_list)
        if (flag IN_LIST removed_flags)
            continue()
        endif()
        hmbuild_cache_append_to("removed_c_flags_${src}" "${flag}")

        get_all_targets_contain_src(target_list "${src}")
        if (NOT target_list)
            return()
        endif()
        separate_arguments(target_list)
        foreach(target IN LISTS target_list)
            hmbuild_target_cmakename_of(cmake_target ${target})
            get_target_property(target_sources ${cmake_target} SOURCES)
            # Apply the flag to each source file except exclude src
            # because we add space in cmd proccess and src not wanted space
            string(STRIP "${flag}" stripped_flag)
            list(REMOVE_ITEM target_sources "${src}")
            foreach(s ${target_sources})
                 __append_cflag_to_src("${s}" "${stripped_flag}")
            endforeach()
            # remove targets cflag
            hmbuild_exclude_target_cflags("${target}" "${flag}")
        endforeach()
    endforeach()
endfunction(hmbuild_exclude_src_cflags)

function(hmbuild_append_source_exclude_cflags src flags)
    hmcmakeng_debug(
            "hmbuild_append_source_exclude_cflags:SRC=${src} FLAGS=${flags}")
    hmbuild_cache_append_to(exclude_cflags_list_${src} "${flags}")
    hmbuild_cache_val_of(src_list exclude_src_list)
    if (NOT ("${src}" IN_LIST src_list))
        hmbuild_cache_append_to(exclude_src_list "${src}")
    endif()
endfunction(hmbuild_append_source_exclude_cflags)

function(hmbuild_append_target_exclude_cflags targets flags)
    hmcmakeng_debug(
            "hmbuild_append_target_exclude_cflags:targets=${targets} FLAGS=${flags}")
    separate_arguments(targets)
    foreach(t ${targets})
        hmbuild_cache_append_to(exclude_cflags_list_${t} "${flags}")
    endforeach()
endfunction(hmbuild_append_target_exclude_cflags)

function(hmbuild_append_dir_exclude_cflags flags)
    hmcmakeng_debug(
            "hmbuild_append_dir_exclude_cflags:FLAGS=${flags}")
    hmbuild_cache_append_to(exclude_dir_cflags_list "${flags}")
endfunction(hmbuild_append_dir_exclude_cflags)

function(hmbuild_exclude_source_cflags)
    hmbuild_cache_val_of(src_list exclude_src_list)
    hmcmakeng_debug("hmbuild_exclude_source_cflags: src_list=${src_list}")
    if (NOT src_list)
        return()
    endif()

    foreach(src IN LISTS src_list)
        hmbuild_cache_val_of(cflag_list exclude_cflags_list_${src})
        hmcmakeng_debug(
            "hmbuild_exclude_source_cflags: exclude_cflags_list_${src}=${cflag_list}")
        hmbuild_exclude_src_cflags(${src} "${cflag_list}")
    endforeach()
endfunction(hmbuild_exclude_source_cflags)

function(hmbuild_exclude_dir_cflags)
    hmbuild_cache_val_of(cflags_list exclude_dir_cflags_list)
    hmcmakeng_debug("hmbuild_exclude_cflags_dir: exclude_dir_cflags_list=${cflags_list}")
    if (NOT cflags_list)
        return()
    endif()
    # remove all targets
    hmbuild_all_targets(targets)
    foreach (t IN LISTS targets)
        hmbuild_exclude_target_cflags(${t} "${cflags_list}")
    endforeach()
endfunction(hmbuild_exclude_dir_cflags)

function(hmbuild_exclude_cflags_config_target target)
    hmbuild_cache_val_of(cflags_list exclude_cflags_list_${target})
    hmcmakeng_debug("hmbuild_exclude_cflags_config_target: exclude_cflags_list_${target}=${cflags_list}")
    if (cflags_list)
        hmbuild_exclude_target_cflags(${target} "${cflags_list}")
    endif(cflags_list)
endfunction(hmbuild_exclude_cflags_config_target)

# vim:ts=4:sw=4:expandtab
