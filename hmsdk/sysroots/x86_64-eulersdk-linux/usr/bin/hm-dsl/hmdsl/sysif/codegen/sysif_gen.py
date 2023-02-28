#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Generate sysif client and server apis
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:39:47 PM CST
"""

from typing import List, Union, Dict

from hmdsl.common.c_biast.styler.styler import CStyler
from hmdsl.sysif.model import Server
from hmdsl.sysif.print_model import print_c_header, print_datatypes
from hmdsl.sysif.parser import parse_to_tree
from hmdsl.sysif.transformer import SysifTransformer
from hmdsl.sysif.codegen.api_common import gen_api_common
from hmdsl.sysif.codegen.arguments_gen import gen_actv_args_static_assert
from hmdsl.sysif.codegen.arguments_gen import gen_actv_ret
from hmdsl.sysif.codegen.actvcall_gen import gen_actvcall
from hmdsl.sysif.codegen.actvhdlr_gen import gen_actvhdlr
from hmdsl.sysif.codegen.internal_actvcall_gen import gen_internal_actvcall
from hmdsl.sysif.codegen.internal_actvhdlr_gen import gen_internal_actvhdlr
from hmdsl.sysif.codegen.actv_selfcall_gen import gen_selfcall
from hmdsl.common.c_biast.biast import CTranslationUnit


styler = CStyler()
common_apis_cache: Dict[str, List[Union[str, CTranslationUnit]]] = {}


def get_server(source_file: str, includes: List[str], legacy_mode: bool) -> Server:
    """
    Parse dsl files of the server and generate the server object

    Args:
        source_file (str): Entry file which describe the general info of the server
        includes (List[str]): Dsl files contain server sysif methods info
        legacy_mode (bool): To forwawrd compat illegal manager name in dsl files

    Returns:
        Server: A server object
    """
    with open(source_file, 'r') as f:
        txt = f.read()
    grammar_tree = parse_to_tree(txt)
    transformer = SysifTransformer(includes, legacy_mode)
    return transformer.transform(grammar_tree)


def gen_common_actv_apis(server: Server, is_server_apis: bool) -> \
        List[Union[str, CTranslationUnit]]:
    """
    Generate common apis in both api.h and server.h

    Returns:
        List[Union[str, CTranslationUnit]]: A mixed string of C macros and C AST
    """
    if server.name in common_apis_cache:
        res = common_apis_cache.get(server.name)
    else:
        res = [f'#ifndef LIBSYSIF_{server.name.upper()}_COMMON_H\n']
        res.append(f'#define LIBSYSIF_{server.name.upper()}_COMMON_H\n')
        res.append('#include <libsysif/utils_common.h>\n')
        res.append('#include <hongmeng/compiler.h>\n')
        res.append('#include <hongmeng/types.h>\n')
        res.append('#include <asm/actv_rpc.h>\n')

        res += gen_api_common()

        res += list(print_c_header(header) for header in server.headers)
        res += list(print_datatypes(datatypes) for datatypes in server.datatypes)

        res += gen_actv_args_static_assert(server)
        res += gen_actv_ret(server)
        res.append(gen_actvcall(server))
        res.append('#endif\n')
        common_apis_cache[server.name] = res

    if is_server_apis:
        res.append(f'#ifdef __sysif_server_{server.name}_no_compat32_handlers__\n')
        res.append(f'# define __{server.name}_method_MAX __{server.name}_method_MAX_NOCOMPAT\n')
        res.append(f'#else\n')
        res.append(f'# define __{server.name}_method_MAX __{server.name}_method_MAX_COMPAT\n')
        res.append(f'#endif\n')

    return res


def gen_client_actv_apis(server: Server) -> str:
    """
    Generate client apis for server

    Args:
        server (Server): A given server object

    Returns:
        str: C Code for apis
    """
    res = [f'#ifndef LIBSYSIF_{server.name.upper()}_API_H\n']
    res.append(f'#define LIBSYSIF_{server.name.upper()}_API_H\n')

    res += gen_common_actv_apis(server, False)

    res.append('#ifdef SYSIF_GEN_IFACE\n')
    res.append('#include <hmkernel/compiler.h>\n')
    res.append('#include <asm/actv_rpc.h>\n')
    res.append('#include <hongmeng/errno.h>\n')
    res.append('#include <hongmeng/syscall.h>\n')
    res.append('#include <hongmeng/panic.h>\n')
    res.append('#include <libstrict/strict.h>\n')

    res.append(gen_internal_actvcall(server))
    res.append('#endif\n')
    res.append('#endif\n')

    res_str = ''.join(styler.render(item) if not isinstance(item, str) else item for item in res)

    return res_str


def gen_server_actv_apis(server: Server, no_selfcall: bool, override: bool) -> str:
    """
    Generate server apis

    Args:
        server (Server): A given server object
        no_selfcall (bool): Whether to generate selfcalls
        override (bool): Whether to override selfcalls

    Returns:
        str: C code for server apis
    """
    res = [f'#ifndef LIBSYSIF_{server.name.upper()}_SERVER_H\n']
    res.append(f'#define LIBSYSIF_{server.name.upper()}_SERVER_H\n')

    res += gen_common_actv_apis(server, True)

    res.append('#include <libsysif/utils.h>\n')
    res.append('#include <asm/actv_rpc.h>\n')
    res.append('#include <asm/types.h>\n')

    res += gen_actvhdlr(server)
    res.append('#ifdef SYSIF_GEN_IFACE\n')
    res.append('#include <stdint.h>\n')
    res.append('#include <asm/actv_rpc.h>\n')
    res.append('#include <hongmeng/syscall.h>\n')
    res.append('#include <hongmeng/panic.h>\n')
    res.append('#include <hongmeng/errno.h>\n')
    res.append('#include <libstrict/strict.h>\n')
    res.append('#include <libhwsecurec/securec.h>\n')
    res.append('#include <libsysif/base/server_arg_compat.h>\n')

    res += gen_internal_actvhdlr(server)
    if not no_selfcall:
        res.append(CTranslationUnit(gen_selfcall(server, override)))
    res.append('#endif\n#endif\n')

    res_str = ''.join(styler.render(item) if not isinstance(item, str) else item for item in res)

    return res_str
