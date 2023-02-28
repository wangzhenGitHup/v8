#!/usr/bin/env python3
# coding=utf-8
# Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
# Author: Huawei OS Kernel Lab
# Create: Mon Jan 13 21:22:41 2020
"""This script splites the policy file

"""

import re
import os
import sys

if len(sys.argv) < 2:
    print("usage: split.py dir")
    exit(1)

work_dir = sys.argv[1]
if not os.path.isdir(work_dir):
    print("{} isn't a directory.".format(work_dir))
    exit(1)

i = 0
split_pattern = re.compile(r'^#---new file---$')


def write_file(file_name, input_line):
    """Write file"""
    with open(file_name, mode="a+") as f:
        f.writelines([input_line])


def new_filename(idx):
    """Return new file name"""
    file_name = "{}/plc.{:0>8d}.json".format(work_dir, idx)
    if os.path.exists(file_name):
        os.remove(file_name)
    return file_name

file = new_filename(0)

for l in sys.stdin.readlines():
    if re.match(split_pattern, l):
        i += 1
        file = new_filename(i)
    else:
        write_file(file, l)
