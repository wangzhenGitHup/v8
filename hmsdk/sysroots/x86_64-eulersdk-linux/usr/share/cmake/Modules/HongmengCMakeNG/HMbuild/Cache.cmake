# Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# Description: Support hmbuild_cache__ operations
# Author: Huawei OS Kernel Lab
# Create: Sat Jun 05 11:33:08 2021

function(hmbuild_cache_namespace outvar)
    cmake_parse_arguments(PARSE_ARGV 0 _cache "" "SUBDIR" "")

    # See generation of HMBUILD_DIR_PREFIX. The ending '_' is tricky
    # because we need to avoid a single ending '_' for top level.
    if (_cache_SUBDIR)
        set(${outvar} "${HMBUILD_DIR_PREFIX}${_cache_SUBDIR}_" PARENT_SCOPE)
    else()
        set(${outvar} "${HMBUILD_DIR_PREFIX}" PARENT_SCOPE)
    endif()
endfunction(hmbuild_cache_namespace)

function(hmbuild_cache_clear)
    cmake_parse_arguments(PARSE_ARGV 0 _cache "" "SUBDIR" "")
    hmbuild_cache_namespace(namespace SUBDIR "${_cache_SUBDIR}")

    get_cmake_property(_varNames VARIABLES)
    foreach (_varName ${_varNames})
        if ("${_varName}" MATCHES "^hmbuild_cache_${namespace}_.*")
            unset(${_varName} CACHE)
        endif()
    endforeach()
endfunction(hmbuild_cache_clear)

function(__hmbuild_cache_append op namespace var item)
    set(varname "hmbuild_cache_${namespace}_${var}")
    set(listval "$CACHE{${varname}}")
    list(${op} listval "${item}")
    set(${varname} ${listval} CACHE INTERNAL "hmcache variable" FORCE)
endfunction(__hmbuild_cache_append)

function(hmbuild_cache_set var val)
    cmake_parse_arguments(PARSE_ARGV 0 _cache "" "SUBDIR" "")
    hmbuild_cache_namespace(namespace SUBDIR "${_cache_SUBDIR}")

    set(varname "hmbuild_cache_${namespace}_${var}")
    set(${varname} ${val} CACHE INTERNAL "hmcache variable" FORCE)
endfunction(hmbuild_cache_set)

function(hmbuild_cache_append_to var item)
    cmake_parse_arguments(PARSE_ARGV 0 _cache "PREPEND" "SUBDIR" "")
    hmbuild_cache_namespace(namespace SUBDIR "${_cache_SUBDIR}")

    if (_cache_PREPEND)
        set(_op "PREPEND")
    else()
        set(_op "APPEND")
    endif()
    __hmbuild_cache_append(${_op} "${namespace}" "${var}" "${item}")
endfunction(hmbuild_cache_append_to)


function(hmbuild_cache_val_of outvar var)
    cmake_parse_arguments(PARSE_ARGV 0 _cache "" "SUBDIR" "")
    hmbuild_cache_namespace(namespace SUBDIR "${_cache_SUBDIR}")

    set(varname "hmbuild_cache_${namespace}_${var}")
    set(${outvar} "$CACHE{${varname}}" PARENT_SCOPE)
endfunction(hmbuild_cache_val_of)

# vim:ts=4:sw=4:expandtab
