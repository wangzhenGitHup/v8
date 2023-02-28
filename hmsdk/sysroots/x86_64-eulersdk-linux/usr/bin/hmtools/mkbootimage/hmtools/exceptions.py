#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
Description: Exceptions can be used in hmtools
Author: Huawei OS Kernel Lab
Create: Sat Jan 30 21:20:06 2021
"""


class HMToolsBaseException(Exception):
    """
    base exception class
    """


class HMToolsArgException(HMToolsBaseException):
    """
    arg exception class
    """


class HMToolsFileNotFoundException(HMToolsBaseException):
    """
    file not found exception class
    """
