#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
Description: execute for hmtools
Author: Huawei OS Kernel Lab
Create: Wed Feb 03 08:21:54 2021
"""

import subprocess
from . import hmlogging


def execute_safe(cmd, logger=None):
    """
    cmd execute
    """
    hmlogging.info(f'execute "{cmd}"', logger=logger)
    subprocess.check_call(cmd, shell=False)


def execute_output_safe(cmd, logger=None):
    """
    cmd execute output
    """
    hmlogging.info(f'execute "{cmd}"', logger=logger)

    _bytes = subprocess.check_output(cmd, shell=False)
    result = _bytes.decode('utf-8').strip()

    hmlogging.debug(f'result of "{cmd}": \n{result}\n', logger=logger)
    return result


def execute_chain_safe(cmds, logger=None):
    """
    execute multiple cmds
    """
    if len(cmds) == 0:
        return
    hmlogging.info('execute "{}"'.format(' | '.join((' '.join(x) for x in cmds))), logger=logger)
    pi = subprocess.Popen(cmds[0], stdout=subprocess.PIPE)
    for cmd in cmds[1:]:
        pj = subprocess.Popen(cmd, stdin=pi.stdout, stdout=subprocess.PIPE)
        pi.stdout.close()
        pi = pj
    return pi.communicate()[0]
