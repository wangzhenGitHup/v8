#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Provide optional type
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:29:29 PM CST
"""

from typing import TypeVar, Optional
from os import environ
from os.path import exists, join


T1 = TypeVar('T1')
T2 = TypeVar('T2')


class EOptional:
    """ This class simulates the behavior of the option monad in functional
    programming languages, e.g. OCaml.
    """

    @staticmethod
    def get(t: Optional[T1]) -> T1:
        """
        Get the basic type of an optional type, return a ValueError when it is None
        """
        if t is not None:
            return t
        else:
            raise ValueError("cannot get an object from a None value")

    @staticmethod
    def merge(t1: Optional[T1], t2: Optional[T1]) -> Optional[T1]:
        """
        merge two objects having optional types
        """
        if t1 is None and t2 is None:
            return None
        elif t1 is None:
            return t2
        elif t2 is None:
            return t1
        elif t1 == t2:
            return t1
        else:
            raise ValueError(f"merging to objects ({t1}, {t2})which are not None and inconsistent")


class PathHelper:
    """ Provides a set of path-related utilities. """

    @classmethod
    def find_executable(cls, program: str) -> str:
        """ Returns the full path of a program according to the current
        system environment.
        """
        for prefix in environ['PATH'].split(':'):
            full_path = join(prefix, program)
            if exists(full_path):
                return full_path

        raise ValueError(f"program {str} is not found in PATH")

    @staticmethod
    def rsvd_api():
        """ Reserve a public interface """
        return
