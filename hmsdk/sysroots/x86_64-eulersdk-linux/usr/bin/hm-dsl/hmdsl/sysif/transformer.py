#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Transformer for sysif DSL
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:32:17 PM CST
"""

from pathlib import Path
from typing import List
from lark import Transformer, v_args

from hmdsl.common.logging import get_logger
from hmdsl.sysif.model import Server, CCode, Manager, Parameter, Method
from hmdsl.sysif.parser import parse_to_tree


logger = get_logger("sysif.transformer")


class SysifTransformer(Transformer):
    """ A sysif dsl transformer """
    def __init__(self, includes: List[str], legacy_mode: bool):
        self.includes = includes
        self.legacy_mode = legacy_mode

    @staticmethod
    def c_datatype(args):
        """ A transform handler to deal with corresponding grammar rule"""
        (tok, ) = args
        return tok.value

    @staticmethod
    def declare_datatype(args):
        """ A transform handler to deal with corresponding grammar rule"""
        datatype = CCode(content="".join(args))
        return Server(datatypes=[datatype])

    @staticmethod
    def sysif_declare_datatype(args):
        """ A transform handler to deal with corresponding grammar rule"""
        datatype = CCode(content="".join(args[1:-1]))
        return Server(datatypes=[datatype])

    @staticmethod
    def common_c_set(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return "".join(args)

    @staticmethod
    @v_args(inline=True)
    def macro_c_set(macro_tag, condition, content, end_tag):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = [f'{macro_tag} {condition}\n']
        rs.append(''.join(content))
        rs.append(f'{end_tag}\n')

        return ''.join(rs)

    @staticmethod
    def c_set(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return "".join(args)

    @staticmethod
    def include_header(args):
        """ A transform handler to deal with corresponding grammar rule"""
        header = CCode(content=args[0])
        return Server(headers=[header])

    @staticmethod
    def c_item(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return args[0]

    @staticmethod
    def group_num(args):
        """ A transform handler to deal with corresponding grammar rule"""
        (tok, ) = args
        return tok.value

    @staticmethod
    def info(args):
        """ A transform handler to deal with corresponding grammar rule"""
        (tok, ) = args
        return tok.value

    @staticmethod
    def path(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return "".join(args)

    @staticmethod
    def group(args):
        """ A transform handler to deal with corresponding grammar rule"""
        res = Server(group=args[0])
        return res

    @staticmethod
    def gen_weak_hdlr(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return Server(generate_weak_handler=True)

    def subsystems_path(self, args):
        """ A transform handler to deal with corresponding grammar rule"""
        return self.__transform_file(args[0])

    @staticmethod
    def server_name(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return Server(name=args[0])

    @staticmethod
    def hdlr_prefix(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return Server(handler_prefix=args[0])

    @staticmethod
    def call_prefix(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return Server(call_prefix=args[0])

    @staticmethod
    def server(args):
        """ A transform handler to deal with corresponding grammar rule"""
        res = Server()
        for svr in args:
            res.update(svr)
        return res

    @staticmethod
    def condition(args):
        """ A transform handler to deal with corresponding grammar rule"""
        (tok, ) = args
        return tok.value

    def subsystem(self, args):
        """ A transform handler to deal with corresponding grammar rule"""
        return self.__transform_file(args[0])

    @staticmethod
    def param_name(args):
        """ A transform handler to deal with corresponding grammar rule"""
        (tok, ) = args
        return tok.value

    @staticmethod
    def type_name(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return " ".join(tok.value for tok in args)

    @staticmethod
    def parameter(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return Parameter(name=args[1], parameter_type=args[0])

    @staticmethod
    def method_name(args):
        """ A transform handler to deal with corresponding grammar rule"""
        (tok, ) = args
        return tok.value

    @staticmethod
    def manager_name(args):
        """ A transform handler to deal with corresponding grammar rule"""
        (tok, ) = args
        return tok.value

    @staticmethod
    def ret_def(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return args[1:]

    @staticmethod
    def params_def(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return args[1:]

    @staticmethod
    def no_ret(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return None

    @staticmethod
    def no_params(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return []

    @staticmethod
    def is_slowdata(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return True

    @staticmethod
    def not_slowdata(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return False

    @staticmethod
    def method_body(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return args

    @staticmethod
    def normal(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return ("int", False)

    @staticmethod
    def simple(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return ("int", True)

    @staticmethod
    def ulong_normal(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return ("unsigned long", False)

    @staticmethod
    def ulong_simple(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return ("unsigned long", True)

    @v_args(inline=True)
    def method(self, header, body):
        """ A transform handler to deal with corresponding grammar rule"""
        direct_return_type, support_self_call = header
        (mgr_name, name, params, indirect_returned_values, slow_data) = body[0:5]

        if self.legacy_mode:
            mthd = Method(name, mgr_name, None, params,
                          indirect_returned_values, direct_return_type,
                          support_self_call, slow_data)
        else:
            mthd = Method(name, None, None, params,
                          indirect_returned_values, direct_return_type,
                          support_self_call, slow_data)

        if len(body) == 6:
            mthd.stk_check = False
        else:
            """ ARG_NO don't need check """
            mthd.stk_check = len(params) > 0

        return mthd

    @staticmethod
    def manager(args):
        """ A transform handler to deal with corresponding grammar rule"""
        name = args[0]
        capacity = int(args[1].value)
        methods = args[2:]
        mgr = Manager(name, None, capacity, methods)
        for method in mgr.methods:
            method.manager = mgr
        return Server(managers=[mgr])

    @staticmethod
    def item(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return args[0]

    @staticmethod
    def start(args):
        """ A transform handler to deal with corresponding grammar rule"""
        res = Server()
        for svr in args:
            res.update(svr)
        return res

    def __transform_file(self, source_file):
        path = ""
        for include in self.includes:
            if Path(f"{include}/{source_file}").is_file():
                path = f"{include}/{source_file}"
                break
        else:
            logger.error(f"Cannot find {source_file} in the includes!")
            exit(1)

        with open(path, 'r') as f:
            txt = f.read()
        return self.transform(parse_to_tree(txt))
