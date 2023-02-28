#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
Description: Utils for hmtools
Author: Huawei OS Kernel Lab
Create: Mon Feb 01 20:17:22 2021
"""

import os

from pathlib import Path
from shutil import which
from hmtools.exceptions import HMToolsArgException


def align_up(v, align=8):
    """
    aarch64 need alignment on 8 when operating memory address
    before mmu is enabled, though alignment 4 is suitable for
    arm32, using 8 here fits both case and simplifies code
    """
    return (v + (align - 1)) & ~(align - 1)


def align_fix(v, align=8):
    """
    get aligned memory address and offset
    """
    aligned = align_up(v, align)
    fix = aligned - v
    return aligned, fix


def unlink_force(path_str):
    """
    path unlink
    """
    try:
        os.unlink(path_str)
    except FileNotFoundError:
        pass
    finally:
        pass


def find_native_tool_path(sysroot_native, tool_path_str):
    """
    find native tool path
    """
    if sysroot_native is not None:
        p = Path(sysroot_native) / tool_path_str
        if not p.is_file():
            raise HMToolsArgException(f'--sysroot-native has no {tool_path_str}')
        else:
            result = str(p)
    else:
        result = os.path.basename(tool_path_str)
        if not which(result):
            raise HMToolsArgException(f'{result} not in PATH')
    return result
