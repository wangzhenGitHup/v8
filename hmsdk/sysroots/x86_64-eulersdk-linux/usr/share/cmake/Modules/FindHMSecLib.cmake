# Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# Description: HMFindModule: find hmsrv_sec
# Author: Huawei OS Kernel Lab
# Create: Tue Jun 22 17:06:52 2021

include(HMFindUtils)

FindHMLib(HMSecLib HMSecLib::HMSecLib
          INCLUDE libpolicy_api.h
          STATICLIB libhmsrv_sec.a
          SHAREDLIB hmsrv_sec
          QUIET "${HMSecLib_FIND_QUIETLY}")

find_package_handle_standard_args(HMSecLib
                                    REQUIRED_VARS
                                    HMSecLib_static_FOUND
                                    HMSecLib_shared_FOUND)

# vim:ts=4:sw=4:expandtab
