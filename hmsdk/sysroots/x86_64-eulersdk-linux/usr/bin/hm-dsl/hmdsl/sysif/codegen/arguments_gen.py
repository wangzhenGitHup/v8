#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Generate return types and structures for sysif apis
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:36:13 PM CST
"""

from typing import List, Union
from hmdsl.common.c_biast.subst import subst
from hmdsl.sysif.model import Server, Manager
from hmdsl.common.c_biast.biast import CTranslationUnit, CDeclaration, CVariableDeclaration, \
    CFieldDeclaration, CType, CStructType, CUnionType, CEnumType, CEnumItem, CIntegerConstant


def gen_actv_args_static_assert(server: Server) -> List[Union[str, CTranslationUnit]]:
    """
    On gcc 7.5.0 or lower version, when sysif arg struct size is over 96 byte, copy will use builtin
    memcpy, leading to callee saved register take stack cost, impact calculating stack args size.
    """
    asserts = []
    filters = ["char", "short", "int", "long", "long long", "unsigned", "unsigned char", "unsigned short",
               "unsigned int", "unsigned long", "unsigned long long", "bool", "size_t", "ssize_t", "__u8",
               "__u16", "__u32", "__u64", "__s8", "__s16", "__s32", "__s64", "uintptr_t", "uint8_t",
               "uint16_t", "uint32_t", "uint64_t", "intptr_t", "int8_t", "int16_t", "int32_t", "int64_t"]

    for manager in server.managers:
        for method in manager.methods:
            for p in method.parameters:
                if "*" in p.parameter_type or p.parameter_type in filters:
                    continue
                argname = f'{server.call_prefix}_{method.manager_name}_{method.name}_arg_{p.name}'
                asserts.append(
                    f"""raw_static_assert(sizeof({p.parameter_type}) <= 96,
                    {argname}_is_too_large);\n""")

    return asserts


def gen_actv_ret(server: Server) -> List[Union[str, CTranslationUnit]]:
    """
    Generate actv ret structures and apis for server
    """
    decls = []
    for manager in server.managers:
        decls += __mk_actvret_struct(manager)

    decls += __mk_actvret_union(server)
    res = [CTranslationUnit(decls)] + __mk_svr_enum(server)
    res += __mk_callno(server)
    res += __mk_ret_static_assert(server)

    return res


def __mk_actvret_struct(manager: Manager) -> List[CVariableDeclaration]:
    res = []

    actvret_template = CVariableDeclaration(
        name=None,
        type=CStructType(name='%fake%', field_decls=[CDeclaration.of("@fields:decl")]))

    for method in manager.methods:
        retname_postfix = f'{manager.server.call_prefix}_{method.manager_name}_{method.name}'
        fields = list(CFieldDeclaration(p.name, CType.of(p.parameter_type))
                      for p in method.indirect_returned_values or [])

        actvret = subst(actvret_template, {'fields': fields}, False)
        actvret.type.name = f'__actvret_{retname_postfix}'

        res.append(actvret)

    return res


def __mk_actvret_union(server: Server) -> List[CVariableDeclaration]:
    res = []
    union_template = CVariableDeclaration(
        name=None,
        type=CUnionType(name=f'__actvret_{server.call_prefix}',
                        field_decls=[CDeclaration.of('@fields:decl')]))

    fields = list(CFieldDeclaration(
        f'{method.manager_name}_{method.name}',
        CStructType(f'__actvret_{server.call_prefix}_{method.manager_name}_{method.name}')
    ) for manager in server.managers for method in manager.methods)

    res.append(subst(union_template, {'fields': fields}, False))

    return res


def __mk_ret_static_assert(server: Server) -> List[str]:
    asserts = []
    for manager in server.managers:
        for method in manager.methods:
            retname = f'{server.call_prefix}_{method.manager_name}_{method.name}'
            asserts.append(
                f"""raw_static_assert(sizeof(struct __actvret_{retname}) < 512,
                {retname}_too_many_actvret_data);\n""")

    asserts.append(
        f"""raw_static_assert(sizeof(union __actvret_{server.call_prefix}) < 512,
        {server.call_prefix}_too_many_actvret_data);\n""")

    return asserts


def __mk_svr_enum(server: Server) -> List[CTranslationUnit]:
    mgr_items = [CEnumItem(f'__{server.name}_INVAL_mgr', CIntegerConstant('0'))]
    mgr_items += list(
        CEnumItem(f'__{server.name}_{manager.name}_mgr', None) for manager in server.managers
    )
    mgr_items.append(CEnumItem(f'__{server.name}_MAX_mgr', None))

    server_enum = CTranslationUnit([CVariableDeclaration(
        name=None,
        type=CEnumType(
            name=f'__{server.name}_mgr',
            enum_items=mgr_items)
    )])

    return [server_enum]


def __mk_callno(server: Server) -> List[str]:
    decls = [f"#define __{server.name}_method_MIN __ACTV_HIGHTABLE_START\n"]

    cnt = 1
    pfx = f"__{server.name}_method"
    for manager in server.managers:
        decls += list(
            f'#define {pfx}_{mthd.manager_name}_{mthd.name} (__ACTV_HIGHTABLE_START + {cnt + i})\n'
            for i, mthd in enumerate(manager.methods))
        cnt += len(manager.methods)
        decls += list(
            f'#define {pfx}_{manager.name}_rsvd_{num} (__ACTV_HIGHTABLE_START + {cnt + i})\n'
            for i, num in enumerate(range(manager.capacity - len(manager.methods), 0, -1)))
        cnt = len(decls)

    decls.append(f'#define {pfx}_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + {cnt})\n')
    decls.append(f'#define {pfx}_MAX_COMPAT ((__ACTV_HIGHTABLE_START + {cnt}) * 2)\n')

    return decls
