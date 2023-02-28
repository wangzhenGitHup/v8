# Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# Description: LLVM Clang CFLAGS settings for HMbuild
# Author: Huawei OS Kernel Lab
# Create: Sat May 29 02:50:08 2021

# See Platform/Hongmeng-xxx-C. Most of required CFLAGS is consered as
# Hongmeng Platform level requirement, not only HMbuild level configuration.

string(APPEND CMAKE_C_FLAGS " ${CMAKE_C_FLAGS_WARNINGS}")

# vim:ts=4:sw=4:expandtab
