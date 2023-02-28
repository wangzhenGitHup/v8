#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Grammar of sysif DSL
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:31:25 PM CST
"""

from lark import Lark


sysif_grammar = r"""start: item*
item: server_info | subsystem | manager
    | c_item

c_item: "INCLUDE_C_HEADER" "(" path ")"                                 ->include_header
        | "DECLARE_DATATYPE_BEGIN" c_datatype* "DECLARE_DATATYPE_END"   ->declare_datatype
        | sysif_declare_datatype

c_datatype: /(.|\n)/

sysif_declare_datatype: IFDEF "SYSIF_EXPORT_API" c_datatype_block* ENDIF

c_datatype_block: c_set*                                                ->common_c_set
                | ((IFDEF | IFNDEF) condition) c_datatype_block* ENDIF  ->macro_c_set

c_set: /(((.|\n)(?!endif))|([^#](?=endif)))+/
IFDEF: "#ifdef"
IFNDEF: "#ifndef"
ENDIF: "#endif"

server_info: "USE_CALL_PREFIX" "(" info ")"         ->call_prefix
           | "USE_HANDLER_PREFIX" "(" info ")"      ->hdlr_prefix
           | "USE_SERVER_NAME" "(" info ")"         ->server_name
           | "INCLUDE_SYSIF" "(" path ")"           ->subsystems_path
           | "GEN_WEAK_HDLR"                        ->gen_weak_hdlr
           | "GROUP" "(" group_num ")"              ->group

subsystem: "INCLUDE_SUBSYSTEM" "(" path ")"

manager: "DEFINE_MANAGER" "(" manager_name "," MAX_METHOD_NUM "," method+ ")"

method: method_type "(" method_body ")"

method_type: "DEFINE_METHOD"                 ->normal
           | "DEFINE_SIMPLE_METHOD"          ->simple
           | "DEFINE_METHOD_ULONG"           ->ulong_normal
           | "DEFINE_SIMPLE_METHOD_ULONG"    ->ulong_simple

method_body: manager_name"," method_name"," params_def"," ret_def"," slowdata_def["," no_stk_check]

params_def: "ARG" "(" INT"," parameter ("," parameter)* ")"
        | "ARG_NO"  ->  no_params
ret_def: "RET" "(" INT"," parameter ("," parameter)* ")"
        | "RET_NO"  ->  no_ret

parameter: type_name "," param_name

manager_name: CNAME
method_name: CNAME
condition: CNAME
info: CNAME
group_num: INT
slowdata_def: "SLOWDATA"        -> is_slowdata
            | "SLOWDATA_NO"     -> not_slowdata
no_stk_check: "NO_STK_CHECK"
type_name: CNAME+ POINTER*
param_name: CNAME
path: (CNAME SLASH)* CNAME (EXTEND CNAME)*

POINTER: "*"
MAX_METHOD_NUM: INT
SLASH: "/"
EXTEND: "."

COMMENT: "/*" /([^\*\/]*((\*(?!\/))|(\/)|))*/ "*/"
        | /(\/\/).*\n/

%import common.CNAME
%import common.INT
%import common.WS
%ignore WS
%ignore COMMENT
"""


sysif_parser = Lark(sysif_grammar)


def parse_to_tree(txt):
    """
    Parse texts to AST using defined grammer
    """
    return sysif_parser.parse(txt)
