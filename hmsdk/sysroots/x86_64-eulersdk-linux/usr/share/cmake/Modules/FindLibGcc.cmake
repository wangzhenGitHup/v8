# Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# Description: FindLibGcc cmake module
# Author: Huawei OS Kernel Lab
# Create: Thu Jun 03 14:05:17 2021

# NOTE that this file should be installed by toolchain

#[=======================================================================[.rst:
FindLibGcc

Variables defined by the module
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Result variables
""""""""""""""""

LibGcc_SHARED_LIBRARY
LibGcc_STATIC_LIBRARY

Imported Targets
^^^^^^^^^^^^^^^^

This module defines :prop_tgt:`IMPORTED` target ``LibGcc::LibGcc_shared`` and
``LibGcc::LibGcc_static``, if libgcc has been found.

#]=======================================================================]

# Provide gcc_print_filename in GNU and iTrustee toolchain

if (NOT ("${CMAKE_C_COMPILER_ID}" STREQUAL ""))
    include(FindLibGcc_${CMAKE_C_COMPILER_ID})
else()
    function(gcc_print_filename outvar name)
        set(${outvar} "NOTFOUND" PARENT_SCOPE)
    endfunction(gcc_print_filename)
endif()

gcc_print_filename(LibGcc_STATIC_LIBRARY        libgcc.a)
if (NOT LibGcc_STATIC_LIBRARY)
    gcc_print_filename(LibGcc_STATIC_LIBRARY    libclang_rt.builtins.a)
endif()

gcc_print_filename(LibGcc_SHARED_LIBRARY_FILE   libgcc_s.so)
if (LibGcc_SHARED_LIBRARY_FILE)
    set(LibGcc_SHARED_LIBRARY "-lgcc_s")
else()
    gcc_print_filename(LibGcc_SHARED_LIBRARY_FILE   libclang_rt.builtins_s.so)
    if (LibGcc_SHARED_LIBRARY_FILE)
        set(LibGcc_SHARED_LIBRARY "-lclang_rt.builtins_s")
    endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LibGcc
                                  REQUIRED_VARS
                                    LibGcc_SHARED_LIBRARY
                                    LibGcc_STATIC_LIBRARY)

if (LibGcc_FOUND AND NOT TARGET LibGcc::LibGcc_shared)
    add_library(LibGcc::LibGcc_shared INTERFACE IMPORTED)
    set_target_properties(LibGcc::LibGcc_shared PROPERTIES
                          INTERFACE_LINK_LIBRARIES "${LibGcc_SHARED_LIBRARY}")
endif()

if (LibGcc_FOUND AND NOT TARGET LibGcc::LibGcc_static)
    add_library(LibGcc::LibGcc_static STATIC IMPORTED)
    set_target_properties(LibGcc::LibGcc_static PROPERTIES
                          IMPORTED_LOCATION ${LibGcc_STATIC_LIBRARY}
                          IMPORTED_LINK_INTERFACE_LANGUAGES C)
endif()

# vim:ts=4:sw=4:expandtab
