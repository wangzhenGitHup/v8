# Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# Description: HMBase is a virtual package which is used to adding correct -I options to c command
# Author: Huawei OS Kernel Lab
# Create: Thu Jul 01 18:58:37 2021

# Detect sysroot directory, use HWSecureC as a template library
include(FindPackageHandleStandardArgs)

if (NOT TARGET HMBase::Sysroot)
    add_library(HMBase::Sysroot UNKNOWN IMPORTED)
    set_target_properties(HMBase::Sysroot PROPERTIES
                          IMPORTED_LINK_INTERFACE_LANGUAGES C)

    # HWSecureC is an isolated library which exists before libc.
    # Use it as an reference library.
    find_package(HWSecureC QUIET)
    if ((TARGET HWSecureC::HWSecureC_include) AND (TARGET HWSecureC::HWSecureC_shared))
        get_target_property(HMBase_INCLUDE_DIR HWSecureC::HWSecureC_include
                            INTERFACE_INCLUDE_DIRECTORIES)
        get_target_property(HMBase_LINK_DIR HWSecureC::HWSecureC_shared
                            INTERFACE_LINK_DIRECTORIES)
    else()
        # If HWSecureC is not found, directly set it use CMAKE_SYSROOT.
        if (DEFINED HMFIND_PATH_INCLUDE)
            set(HMBase_INCLUDE_DIR "${CMAKE_SYSROOT}/usr/${HMFIND_PATH_INCLUDE}")
        else()
            set(HMBase_INCLUDE_DIR "${CMAKE_SYSROOT}/usr/include")
        endif()

        if (DEFINED HMFIND_PATH_LIB)
            set(HMBase_LINK_DIR "${CMAKE_SYSROOT}/usr/${HMFIND_PATH_LIB}")
        else()
            set(HMBase_LINK_DIR "${CMAKE_SYSROOT}/usr/lib")
        endif()
    endif()

    set_target_properties(HMBase::Sysroot PROPERTIES
                          INTERFACE_INCLUDE_DIRECTORIES "${HMBase_INCLUDE_DIR}"
                          INTERFACE_LINK_DIRECTORIES "${HMBase_LINK_DIR}")

    # Unconditionally introduce __hmbuild__ to let compiler know it is
    # under HMbuild and follow its protocol.
    set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                 INTERFACE_COMPILE_DEFINITIONS __hmbuild__)

    # Set global feature __hm_ compile definitions
    if (HMBUILD_FEATURE_KCFI)
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_cfi__)
    else()
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_no_cfi__)
    endif()

    if (HMBUILD_FEATURE_ShadowStack)
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_shadowstack__)
    else()
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_no_shadowstack__)
    endif()

    if (HMBUILD_FEATURE_KASAN)
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_kasan__)
    else()
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_no_kasan__)
    endif()

    if (HMBUILD_FEATURE_UBSAN)
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_ubsan__)
    else()
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_no_ubsan__)
    endif()

    if (HMBUILD_FEATURE_DEBUG)
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_debug__)
    else()
        set_property(TARGET HMBase::Sysroot APPEND PROPERTY
                     INTERFACE_COMPILE_DEFINITIONS __hmfeature_no_debug__)
    endif()

endif()

find_package_handle_standard_args(HMBase
                                  REQUIRED_VARS
                                    HMBase_INCLUDE_DIR
                                    HMBase_LINK_DIR)

# vim:ts=4:sw=4:expandtab
