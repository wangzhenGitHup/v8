#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
Description: logger for fstools
Author: Huawei OS Kernel Lab
Create: Tue Feb 02 20:53:11 2021
"""

import logging

HMLOGGING_ROOTLOGGER_NAME = "ROOT"


def init():
    """
    logger init
    """
    logging.basicConfig(
            format='%(levelname)s:\t%(message)s',
            level=logging.DEBUG)


def set_basic_config(args):
    """
    set basic config for log
    """
    user_set_level = 0
    if args is not None and 'verbose' in args:
        user_set_level = args['verbose']
    if user_set_level > 2:
        user_set_level = 2
    level = [logging.WARNING, logging.INFO, logging.DEBUG][user_set_level]
    root_logger = logging.getLogger(HMLOGGING_ROOTLOGGER_NAME)
    root_logger.setLevel(level)


def critical(*args, logger=None):
    """
    critical log
    """
    if logger is None:
        logger = logging.getLogger(HMLOGGING_ROOTLOGGER_NAME)
    logger.critical(''.join(args))


def error(*args, logger=None):
    """
    error log
    """
    if logger is None:
        logger = logging.getLogger(HMLOGGING_ROOTLOGGER_NAME)
    logger.error(''.join(args))


def warning(*args, logger=None):
    """
    warning log
    """
    if logger is None:
        logger = logging.getLogger(HMLOGGING_ROOTLOGGER_NAME)
    logger.warning(''.join(args))


def info(*args, logger=None):
    """
    info log
    """
    if logger is None:
        logger = logging.getLogger(HMLOGGING_ROOTLOGGER_NAME)
    logger.info(''.join(args))


def debug(*args, logger=None):
    """
    debug log
    """
    if logger is None:
        logger = logging.getLogger(HMLOGGING_ROOTLOGGER_NAME)
    logger.debug(''.join(args))


def exception(*args, logger=None):
    """
    exception log
    """
    if logger is None:
        logger = logging.getLogger(HMLOGGING_ROOTLOGGER_NAME)
    logger.exception(''.join(args))
