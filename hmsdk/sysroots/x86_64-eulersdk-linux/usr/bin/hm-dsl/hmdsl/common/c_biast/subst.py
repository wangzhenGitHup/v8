#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
Description: Substitution of CBiAst Macros
Author: Huawei OS Kernel Lab
Create: Thu 4 Mar 2021 16:30:00 PM CST
"""
from typing import TypeVar, Union, List, cast, Mapping, Dict, Any
from dataclasses import dataclass

from hmdsl.common.c_biast.biast import CMacro, CBiAst


T = TypeVar('T')

SubstContext = Mapping[str, Union[CBiAst, List[CBiAst]]]


@dataclass
class SubstitutionError(Exception):
    """
    Specific exceptions for substitution errors
    """
    macro_name: str
    message: str


def __expect(t, item, cls, parent):
    if isinstance(item, list) and not isinstance(parent, list):
        raise SubstitutionError(t, f"cannot unfold as a list")

    for v in item if isinstance(item, list) else (item,):
        if not isinstance(v, cls):
            raise SubstitutionError(t, f"{v} is supposed to be a {cls.__name__}")

    return item


def __subst_dict(t, _, context, inplace):
    dret: Dict[str, Any] = {k: __subst(v, t, context, inplace) for k, v in t.items()}

    if not inplace:
        return dret
    else:
        t.update(dret)
        return t


def __subst_list(t, _, context, inplace):
    lret = []
    for item in t:
        updated_item = __subst(item, t, context, inplace)
        if isinstance(updated_item, list):
            lret += updated_item
        else:
            lret.append(updated_item)

    if not inplace:
        return lret
    else:
        t.clear()
        t += lret
        return t


def __subst_tuple(t, _, context, inplace):
    return tuple(__subst(item, t, context, inplace) for item in t)


def __subst_biast(t, _, context, inplace):
    cls = type(t)
    dic = __subst(t.__dict__, t, context, inplace)
    if dic is t.__dict__:
        return t
    elif inplace:
        t.__dict__ = dic
        return cast(T, t)
    else:
        ret = cls.__new__(cls)
        ret.__dict__ = dic
        return ret

    return t


def __subst(t, parent, context, inplace):
    oprs = {dict: __subst_dict,
            list: __subst_list,
            tuple: __subst_tuple}

    if type(t) in oprs:
        return oprs.get(type(t))(t, parent, context, inplace)
    elif isinstance(t, CMacro) and t.macro_name in context:
        return __expect(t.macro_name, context[t.macro_name], t.get_base_class(), parent)
    elif isinstance(t, CBiAst):
        return __subst_biast(t, parent, context, inplace)

    return t


def subst(t: T, context: SubstContext, inplace: bool = False) -> T:
    """ This is a generic function aims to perform substitution
    on the macros.

    To bypass type-checking, which does not properly works in this function, we
    use some ``cast`` function here. Please be careful when you want to change
    this function. And always be noticed that type-checker does not help with
    avoiding errors in ``subst``.
    """

    return cast(T, __subst(t, None, context, inplace))
