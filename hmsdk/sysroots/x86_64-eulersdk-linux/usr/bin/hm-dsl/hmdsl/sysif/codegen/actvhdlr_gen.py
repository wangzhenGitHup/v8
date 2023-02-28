#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Generate sysif server apis
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:34:52 PM CST
"""

from typing import List, Union
from hmdsl.common.c_biast.subst import subst
from hmdsl.sysif.model import Manager, MethodType, Server
from hmdsl.common.c_biast.biast import CTranslationUnit, CFunction, CDeclaration, \
    CVariableDeclaration, CParameterDeclaration, CFieldDeclaration, CStorageQualifier, CType, \
    CAliasType, CVoidType, CSignDescriptor, CIntType, CLongType, CLonglongType, CPointerType, \
    CStructType, CUnionType, CFunctionType, CStatement


def gen_actvhdlr(server: Server) -> List[Union[str, CTranslationUnit]]:
    """
    Generate server apis, namely actvhdlr, for the server
    """
    actvhdlr = []
    actvhdlr_bridge = []
    for manager in server.managers:
        [hdlrs, bridges] = __declare_actvhdlrs(manager)
        actvhdlr += hdlrs
        actvhdlr_bridge += bridges

    res = ['#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR\n']
    res.append(CTranslationUnit(actvhdlr))
    res.append('#else\n')
    res.append(CTranslationUnit(actvhdlr_bridge))
    res.append('#endif\n')

    actvret = []
    for manager in server.managers:
        actvret += __mk_actvret(manager)

    res.append(CTranslationUnit(actvret))
    res += __mk_actvhdlr_union(server)

    decls = CVariableDeclaration.of(
        f""" extern union {server.name}_hdlrs_union
        sysif_{server.name}_actvhdlr_table[__{server.name}_method_MAX];
        """)
    decls += CVariableDeclaration.of(
        f""" extern union {server.name}_hdlrs_union
        sysif_{server.name}_actvcapcallhdlr_table[__{server.name}_method_MAX];
        """)
    decls += CVariableDeclaration.of(
        f""" extern void sysif_show_{server.name}_methods(void);
        """)
    res.append(CTranslationUnit(decls))

    return res


def __declare_actvhdlrs(manager: Manager) -> List[List[CVariableDeclaration]]:
    handler_prefix = manager.server.handler_prefix

    actvhdlrs_template = CVariableDeclaration(
        name=None,
        type=CFunctionType(
            parameter_decls=[
                CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration.of("""@parameters:decl""")
            ],
            return_type=CType.of("""@return_type:type"""),
            variable_length_argument=False),
        storage_qualifiers={CStorageQualifier.EXTERN})

    actvhdlr = []
    actv_bridge_hdlr = []
    for method in manager.methods:
        func_name_postfix = f"""{handler_prefix}_{method.manager_name}_{method.name}"""
        params = list(
            CParameterDeclaration(p.name, CType.of(p.parameter_type)) for p in method.parameters
        )
        actvhdlr_func = subst(
            actvhdlrs_template,
            {'parameters': params,
             'return_type': CType.of(method.direct_return_type)},
            False)
        actvhdlr_func.name = f"""actvhdlr_{func_name_postfix}"""

        actvhdlr.append(actvhdlr_func)
        actv_bridge_hdlr.append(actvhdlr_func)

        actvhdlr_bridge_func = subst(
            actvhdlrs_template,
            {'parameters': [],
             'return_type': CType.of(method.direct_return_type)},
            False)
        actvhdlr_bridge_func.type.variable_length_argument = True
        actvhdlr_bridge_func.name = f"__actvshadowhdlr_{func_name_postfix}"

        actv_bridge_hdlr.append(actvhdlr_bridge_func)

    return [actvhdlr, actv_bridge_hdlr]


def __mk_actvret(manager: Manager) -> List[CFunction]:
    res = []
    call_prefix = manager.server.call_prefix
    handler_prefix = manager.server.handler_prefix

    prepare_ret_template = CFunction(
        name='',
        parameters=[CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED))],
        return_type=CType.of('@ret_type:type *'),
        body=CStatement.of(
            """{
            void * __ret =
            hm_actvpool_prepare_ret(sender, credential, @sizeof:expr(@ret_type:type));
            return (@ret_type:type *)__ret;
            }"""),
        inline=True,
        variable_length_argument=False,
        storage_qualifiers={CStorageQualifier.STATIC})

    for method in manager.methods:
        ret_type = CStructType(
            name=f'__actvret_{call_prefix}_{method.manager_name}_{method.name}',
            field_decls=None
        )

        prepare_ret = subst(
            prepare_ret_template,
            {'ret_type': ret_type},
            False)
        prepare_ret.name = \
            f'actvhdlr_{handler_prefix}_{method.manager_name}_{method.name}_prepare_ret'
        res.append(prepare_ret)

    return res


def __construct_hdlrs_union_fields(server: Server) -> List[CFieldDeclaration]:
    bridgehdlrs_template = CFieldDeclaration(
        name='%fake%',
        type=CPointerType(CFunctionType(
            parameter_decls=[
                CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration.of('@rpc_unused:decl'),
                CParameterDeclaration.of('@fallback:decl'),
                CParameterDeclaration.of("""@parameters:decl""")],
            return_type=CType.of("""@return_type:type"""),
            variable_length_argument=False)))

    res = []
    for manager in server.managers:
        for method in manager.methods:
            func_name_postfix = f"""{server.handler_prefix}_{method.manager_name}_{method.name}"""
            params = list(CParameterDeclaration(
                p.name, CType.of(p.parameter_type)
            ) for p in method.parameters)
            fallback_unused = [
                CParameterDeclaration('__actv_fallback_unused_1',
                                      CLongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('__actv_fallback_unused_2',
                                      CLongType(CSignDescriptor.UNSIGNED))] \
                if method.method_type is MethodType.FALLBACK else []

            bridgehdlr = subst(
                bridgehdlrs_template,
                {'rpc_unused': [],
                 'fallback': fallback_unused,
                 'parameters': params,
                 'return_type': CType.of(method.direct_return_type)},
                False)
            bridgehdlr.name = f"""p__actvbridgehdlr_{func_name_postfix}"""

            bridgecapcall = subst(
                bridgehdlrs_template,
                {'rpc_unused': CParameterDeclaration.of('@__RPC_CAPCALL_HDLR_UNUSED_ARGS:decl'),
                 'fallback': fallback_unused,
                 'parameters': params,
                 'return_type': CType.of(method.direct_return_type)},
                False)
            bridgecapcall.name = f"p__actvbridgecapcallhdlr_{func_name_postfix}"

            res.append(bridgehdlr)
            res.append(bridgecapcall)

    return res


def __construct_compat_hdlrs_union_fields(server: Server) -> List[CFieldDeclaration]:
    compat_template = CFieldDeclaration(
        name='%fake%',
        type=CPointerType(CFunctionType(
            parameter_decls=[
                CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('sp', CLongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('x3', CLongType(CSignDescriptor.UNSIGNED))],
            return_type=CType.of("""@return_type:type"""),
            variable_length_argument=False)))

    res = []
    for manager in server.managers:
        for method in manager.methods:
            func_name_postfix = \
                f"""{server.handler_prefix}_compat_{method.manager_name}_{method.name}"""

            compathdlr = subst(
                compat_template,
                {'return_type': CType.of(method.direct_return_type)},
                False)
            compathdlr.name = f"""p__actvbridgehdlr_{func_name_postfix}"""

            compatcapcall = subst(
                compat_template,
                {'return_type': CType.of(method.direct_return_type)},
                False)
            compatcapcall.name = f"p__actvbridgecapcallhdlr_{func_name_postfix}"
            res.append(compathdlr)
            res.append(compatcapcall)

    return res


def __construct_hdlrs_union(server: Server) -> List[CVariableDeclaration]:
    hdlrs = [
        CFieldDeclaration(
            'p_sysif_actvhdlr_ptr_void',
            CPointerType(CVoidType())),
        CFieldDeclaration(
            name='p_sysif_default_handler',
            type=CPointerType(CFunctionType(
                parameter_decls=[
                    CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED))],
                return_type=CIntType(),
                variable_length_argument=False)))]

    hdlrs += __construct_hdlrs_union_fields(server)
    compat_hdlrs = hdlrs[:]
    compat_hdlrs += __construct_compat_hdlrs_union_fields(server)

    union_template = CVariableDeclaration(None, CUnionType(
        name=f'{server.name}_hdlrs_union',
        field_decls=[CDeclaration.of("@fields:decl"),
                     CDeclaration.of('@kcall_entry:decl')]))
    hdlrs_union = subst(union_template, {'fields': hdlrs}, False)
    compat_hdlrs_union = subst(union_template, {'fields': compat_hdlrs}, False)

    return [hdlrs_union, compat_hdlrs_union]


def __mk_kcall_actv_hdlr(server: Server) -> List[List[CVariableDeclaration]]:
    hdlrs_union, hdlrs_compat_union = __construct_hdlrs_union(server)

    llt_kcall = CFieldDeclaration(
        'p_sysif_handle_kcall_entry',
        CPointerType(CFunctionType(
            parameter_decls=[],
            return_type=CIntType(),
            variable_length_argument=False)))
    hdlrs_union_llt = subst(hdlrs_union, {'kcall_entry': llt_kcall}, False)
    hdlrs_compat_union_llt = subst(hdlrs_compat_union, {'kcall_entry': llt_kcall}, False)

    aarch_kcall = CFieldDeclaration(
        "p_sysif_handle_kcall_entry",
        CPointerType(CFunctionType(
            parameter_decls=[
                CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('arg1', CAliasType('__u64')),
                CParameterDeclaration('arg2', CAliasType('__u64')),
                CParameterDeclaration('arg3', CAliasType('__u64'))],
            return_type=CIntType(),
            variable_length_argument=False)))
    hdlrs_union_aarch = subst(hdlrs_union, {'kcall_entry': aarch_kcall}, False)
    hdlrs_compat_union_aarch = subst(hdlrs_compat_union, {'kcall_entry': aarch_kcall}, False)

    arm_kcall = CFieldDeclaration(
        'p_sysif_handle_kcall_entry',
        CPointerType(CFunctionType(
            parameter_decls=[
                CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED))],
            return_type=CIntType(),
            variable_length_argument=False)))
    hdlrs_union_arm = subst(hdlrs_union, {'kcall_entry': arm_kcall}, False)
    hdlrs_compat_union_arm = subst(hdlrs_compat_union, {'kcall_entry': arm_kcall}, False)

    return [[hdlrs_union_llt, hdlrs_compat_union_llt],
            [hdlrs_union_aarch, hdlrs_compat_union_aarch],
            [hdlrs_union_arm, hdlrs_compat_union_arm]]


def __mk_actvhdlr_union(server: Server) -> List[Union[str, CTranslationUnit]]:
    unions = __mk_kcall_actv_hdlr(server)
    hdlrs_union_llt, hdlrs_compat_union_llt = unions[0]
    hdlrs_union_aarch, hdlrs_compat_union_aarch = unions[1]
    hdlrs_union_arm, hdlrs_compat_union_arm = unions[2]

    res = [f'#ifdef __sysif_server_{server.name}_no_compat32_handlers__\n']
    # make handlers union
    res.append('#ifdef __HOST_LLT__\n')
    res.append(CTranslationUnit([hdlrs_union_llt]))
    res.append('#else\n')
    res.append('#ifdef __aarch64__\n')
    res.append(CTranslationUnit([hdlrs_union_aarch]))
    res.append('#endif\n')
    res.append('#ifdef __arm__\n')
    res.append(CTranslationUnit([hdlrs_union_arm]))
    res.append('#endif\n')
    res.append('#endif\n')

    res.append('#else\n')
    res.append('#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR\n')
    res.append('#error "Only support 64-bit server, build for aarch64 please!"\n')
    res.append('#else\n')

    # make campat handlers union
    res.append('#ifdef __HOST_LLT__\n')
    res.append(CTranslationUnit([hdlrs_compat_union_llt]))
    res.append('#else\n')
    res.append('#ifdef __aarch64__\n')
    res.append(CTranslationUnit([hdlrs_compat_union_aarch]))
    res.append('#endif\n')
    res.append('#ifdef __arm__\n')
    res.append(CTranslationUnit([hdlrs_compat_union_arm]))
    res.append('#endif\n')
    res.append('#endif\n')

    res.append('#endif\n')
    res.append('#endif\n')

    return res
