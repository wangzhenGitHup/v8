#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Generate internal server apis
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:38:29 PM CST
"""

from typing import List, Union, Tuple
from hmdsl.common.c_biast.subst import subst
from hmdsl.sysif.model import Server, Manager, Method, Parameter, MethodType
from hmdsl.sysif.codegen.actvcall_gen import generate_arg_stksz
from hmdsl.common.c_biast.biast import CExpression, CTranslationUnit, CAttribute, \
    CClassicalAttribute, CFunction, CVariableDeclaration, CParameterDeclaration, \
    CStorageQualifier, CType, CVoidType, CSignDescriptor, CLongType, CLonglongType, CArrayType, \
    CUnionType, CIdentifierExpression, CStringLiteral, CCallExpression, CIndexDesignator, \
    CDesignation, CConstructorExpression, CIntegerConstant, CStatement, CCompoundStatement, \
    CExpressionStatement, CReturnStatement


def gen_internal_actvhdlr(server: Server) -> List[Union[str, CTranslationUnit]]:
    """
    Generate definitions of hdlr apis
    """
    res = []
    if server.generate_weak_handler:
        res += __mk_weak_hdlr(server)
    res += __mk_actvhdlrs(server)
    res += __mk_actvhdlr_table(server)
    res.append(CTranslationUnit([__mk_sysif_show(server)]))
    return res


def __mk_weak_hdlr(server: Server) -> List[Union[str, CTranslationUnit]]:
    actvshadowhdlr = []
    actvhdlr = []
    for manager in server.managers:
        [bridges, hdlrs] = __mk_weak_actvhdlrs(manager)
        actvshadowhdlr += bridges
        actvhdlr += hdlrs

    res = ['#ifdef __ARCH_RPC_REQUIRE_BRIDGE_HDLR\n']
    res.append(CTranslationUnit(actvshadowhdlr))
    res.append('#else\n')
    res.append(CTranslationUnit(actvhdlr))
    res.append('#endif\n')
    return res


def __mk_weak_actvhdlrs(manager: Manager) -> List[List[CFunction]]:
    actvhdlr_template = CFunction(
        name='%fake%',
        parameters=[CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration.of("@params:decl")],
        return_type=CType.of("@return_type:type"),
        body=CCompoundStatement([CReturnStatement(CIdentifierExpression('E_HM_NOSYS'))]),
        attributes=[CClassicalAttribute('weak', None)])

    bridgehdlrs = []
    hdlrs = []
    for method in manager.methods:
        shadowhdlr = subst(actvhdlr_template,
                           {'params': [],
                            'return_type': CType.of(method.direct_return_type)},
                           False)
        shadowhdlr.name = \
            f'__actvshadowhdlr_{manager.server.handler_prefix}_{method.manager_name}_{method.name}'
        shadowhdlr.variable_length_argument = True
        bridgehdlrs.append(shadowhdlr)

        parameters = list(CParameterDeclaration(p.name, CType.of(p.parameter_type))
                          for p in method.parameters)
        hdlr = subst(
            actvhdlr_template,
            {'params': parameters,
             'return_type': CType.of(method.direct_return_type)},
            False)
        hdlr.name = f'actvhdlr_{manager.server.handler_prefix}_{method.manager_name}_{method.name}'
        hdlrs.append(hdlr)

    return [bridgehdlrs, hdlrs]


def __mk_actvhdlrs(server: Server) -> List[Union[str, CTranslationUnit]]:
    bridge_hdlrs = []
    compats = []
    hdlrs = []
    for manager in server.managers:
        for method in manager.methods:
            bridge_hdlrs += __mk_bridge_hdlr(method)
            compats += __mk_compat_hdlr(method)
            hdlrs += __mk_hdlr(method)

    res = ['#ifdef __ARCH_RPC_REQUIRE_BRIDGE_HDLR\n']
    res.append(CTranslationUnit(bridge_hdlrs))

    res.append(f'#ifndef __sysif_server_{server.name}_no_compat32_handlers__\n')
    res.append('#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__\n')
    res.append(CTranslationUnit(CVariableDeclaration.of(
        """struct compat_x3 {
                unsigned int reserverd;
                unsigned int w3;
        };
        """)))
    res.append('#else\n')
    res.append(CTranslationUnit(CVariableDeclaration.of(
        """struct compat_x3 {
            unsigned int w3;
            unsigned int reserverd;
        };
        """)))
    res.append('#endif\n')

    res.append(CTranslationUnit(compats))
    res.append('#endif\n')

    res.append('#else\n')

    res.append(CTranslationUnit(hdlrs))
    res.append('#endif\n')

    return res


def __mk_hdlr_template(method: Method) -> CFunction:
    parameters = list(CParameterDeclaration(p.name, CType.of(p.parameter_type))
                      for p in method.parameters)
    fallback_unused = [
        CParameterDeclaration('__actv_fallback_unused_1', CLongType(CSignDescriptor.UNSIGNED)),
        CParameterDeclaration('__actv_fallback_unused_2', CLongType(CSignDescriptor.UNSIGNED))] \
        if method.method_type is MethodType.FALLBACK else []

    hdlr_template = CFunction(
        name='%fake',
        parameters=[CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration.of('@rpc_unused:decl'),
                    *fallback_unused,
                    *parameters],
        return_type=CType.of(method.direct_return_type),
        body=CStatement.of(
            """{
            @unused_rpc:stmt
            @unused_fallback:stmt
            @frame:decl
            @stksz:decl
            @check_decl:decl
            @stk_check:stmt
            return @callee:expr(sender, credential, @append_args:expr);
            }"""),
        storage_qualifiers={CStorageQualifier.STATIC},
        attributes=[CAttribute.of("@__opt_nonoframe:attr")])

    append_args = list(CExpression.of(
        f'@__ARCH_ACTV_RPC_RECV_ARG:expr({p.parameter_type}, {p.name})')
                   for p in method.parameters)

    unused_fallback = CStatement.of(
        'UNUSED(__actv_fallback_unused_1, __actv_fallback_unused_2);'
    ) if method.method_type is MethodType.FALLBACK else []

    return subst(hdlr_template,
                 {'unused_fallback': unused_fallback, 'append_args': append_args},
                 True)


def __mk_bridge_hdlr(method: Method) -> List[CFunction]:
    bridge_req_template = __mk_hdlr_template(method)

    frame = CVariableDeclaration.of(
        'unsigned long * @__maybe_unused:attr __p_prev_frame = __builtin_frame_address(0);')
    stksz = CVariableDeclaration.of(
        'unsigned long @__maybe_unused:attr __stacksz = @__ARCH_ACTV_STACK_ARG_SIZE:expr;')

    func_call_postfix = \
        f'{method.manager.server.handler_prefix}_{method.manager_name}_{method.name}'
    is_fallback = '1' if method.method_type is MethodType.FALLBACK else '0'

    parameters = list(CParameterDeclaration(p.name, CType.of(p.parameter_type))
                      for p in method.parameters)
    if method.stk_check:
        (check_decl, stk_check_stmt) = __stk_check(parameters, '0', is_fallback, False, False)
        (check_decl_cap, stk_check_cap) = __stk_check(parameters, '1', is_fallback, False, False)
    else:
        check_decl = []
        stk_check_stmt = []
        check_decl_cap = []
        stk_check_cap = []

    bridge_req = subst(
        bridge_req_template,
        {'rpc_unused': [],
         'unused_rpc': [],
         'frame': frame,
         'stksz': stksz,
         'check_decl': check_decl,
         'stk_check': stk_check_stmt,
         'callee': CIdentifierExpression(f'__actvshadowhdlr_{func_call_postfix}')},
        False)
    bridge_req.name = f'__actvbridgehdlr_{func_call_postfix}'

    bridge_req_cap = subst(
        bridge_req_template,
        {'rpc_unused': CParameterDeclaration.of('@__RPC_CAPCALL_HDLR_UNUSED_ARGS:decl'),
         'unused_rpc': CStatement.of('UNUSED(@__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT:expr);'),
         'frame': frame,
         'stksz': stksz,
         'check_decl': check_decl_cap,
         'stk_check': stk_check_cap,
         'callee': CIdentifierExpression(f'__actvshadowhdlr_{func_call_postfix}')},
        False)
    bridge_req_cap.name = f'__actvbridgecapcallhdlr_{func_call_postfix}'

    return [bridge_req, bridge_req_cap]


def __mk_hdlr(method: Method) -> List[CFunction]:
    bridge_nreq_template = __mk_hdlr_template(method)
    func_call_postfix = \
        f'{method.manager.server.handler_prefix}_{method.manager_name}_{method.name}'
    is_fallback = '1' if method.method_type is MethodType.FALLBACK else '0'

    parameters = list(CParameterDeclaration(p.name, CType.of(p.parameter_type))
                      for p in method.parameters)
    if method.stk_check:
        (check_decl, stk_check_stmt) = __stk_check(parameters, '0', is_fallback, False, True)
        (check_decl_cap, stk_check_cap) = __stk_check(parameters, '1', is_fallback, False, True)
    else:
        check_decl = []
        stk_check_stmt = []
        check_decl_cap = []
        stk_check_cap = []

    bridge_nreq = subst(
        bridge_nreq_template,
        {'rpc_unused': [],
         'unused_rpc': [],
         'frame': [],
         'stksz': [],
         'check_decl': check_decl,
         'stk_check': stk_check_stmt,
         'callee': CIdentifierExpression(f'actvhdlr_{func_call_postfix}')},
        False)
    bridge_nreq.name = f'__actvbridgehdlr_{func_call_postfix}'

    bridge_nreq_cap = subst(
        bridge_nreq_template,
        {'rpc_unused': CParameterDeclaration.of('@__RPC_CAPCALL_HDLR_UNUSED_ARGS:decl'),
         'unused_rpc': CStatement.of('UNUSED(@__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT:expr);'),
         'frame': [],
         'stksz': [],
         'check_decl': check_decl_cap,
         'stk_check': stk_check_cap,
         'callee': CIdentifierExpression(f'actvhdlr_{func_call_postfix}')},
        False)
    bridge_nreq_cap.name = f'__actvbridgecapcallhdlr_{func_call_postfix}'

    return [bridge_nreq, bridge_nreq_cap]


def __mk_compat_hdlr_template(method: Method) -> CFunction:
    compat_template = CFunction(
        name='%fake%',
        parameters=[CParameterDeclaration('sender', CLonglongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration('credential', CLongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration('sp', CLongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration('x3', CLongType(CSignDescriptor.UNSIGNED))],
        return_type=CType.of(method.direct_return_type),
        body=CStatement.of(
            """{
            union @__maybe_unused:attr {
                unsigned long x3;
                struct compat_x3 __compat_x3;
            } ___val = {0};
            ___val.x3 = x3;
            unsigned int @__maybe_unused:attr ___w3 = ___val.__compat_x3.w3;
            char * data @__maybe_unused:attr = (char *)(uintptr_t)(sp);
            unsigned int @__maybe_unused:attr cursor = @rpc_unused:expr;
            bool @__maybe_unused:attr is_r3_passing = @abool:expr;
            enum __data_model @__maybe_unused:attr model = _DATA_MODEL_ILP32;
            enum __type @__maybe_unused:attr type;
            @def_args:decl
            @fetch_args:stmt
            @check_decl:decl
            @stk_check:stmt
            return @callee:expr(sender, credential, @args:expr);
            }"""),
        storage_qualifiers={CStorageQualifier.STATIC},
        attributes=[CAttribute.of('@__opt_nonoframe:attr')])

    def_args = list(CVariableDeclaration(f'_{p.name}', CType.of(p.parameter_type))
                    for p in method.parameters)
    for def_arg in def_args:
        def_arg.attributes = [CAttribute.of('@__maybe_unused:attr')]

    (check_decl, stk_check_stmt) = __stk_check([], 'unused', 'unused', True, False) \
        if method.stk_check else ([], [])

    return subst(compat_template,
                 {'def_args': def_args,
                  'fetch_args': __fetch(method.parameters),
                  'check_decl': check_decl,
                  'stk_check': stk_check_stmt,
                  'args': list(CIdentifierExpression(arg.name) for arg in def_args)},
                 True)


def __mk_compat_hdlr(method: Method) -> List[CFunction]:
    compat_template = __mk_compat_hdlr_template(method)
    func_postfix = \
        f'{method.manager.server.handler_prefix}_compat_{method.manager_name}_{method.name}'
    return_postfix = f'{method.manager.server.handler_prefix}_{method.manager_name}_{method.name}'

    if method.method_type is MethodType.FALLBACK:
        rpc_unused = CExpression.of('@__RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE:expr')
        rpc_unused_cap = CExpression.of('@__RPC_ACTVCALL_HDLR_UNUSED_ARGS_THREE:expr')
        passing_bool = CIdentifierExpression('false')
    else:
        rpc_unused = CExpression.of('@__RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE:expr')
        rpc_unused_cap = CExpression.of('@__RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE:expr')
        passing_bool = CIdentifierExpression('true')

    hdlr_compat = subst(
        compat_template,
        {'rpc_unused': rpc_unused,
         'abool': passing_bool,
         'callee': CIdentifierExpression(f'__actvshadowhdlr_{return_postfix}')},
        False)
    hdlr_compat.name = f'__actvbridgehdlr_{func_postfix}'

    hdlr_cap_compat = subst(
        compat_template,
        {'rpc_unused': rpc_unused_cap,
         'abool': CIdentifierExpression('false'),
         'callee': CIdentifierExpression(f'__actvshadowhdlr_{return_postfix}')},
        False)
    hdlr_cap_compat.name = f'__actvbridgecapcallhdlr_{func_postfix}'

    return [hdlr_compat, hdlr_cap_compat]


def __fetch(method_parameters: List[Parameter]) -> List[CStatement]:
    fetch_template = CStatement.of(
        """
        do{
            int fetch_sz;
            unsigned long align;
            unsigned long arg_sz = @sizeof:expr(@param_type:type);
            type = @__type_of:expr(@param_type:type);
            @__fetch_one_arg:stmt((void *)(&(@param_name:expr)), data,
                        @count:expr, arg_sz, model, type, @param_type:type, @param_name:expr)
            if(fetch_sz < 0){
                panic("failed to fetch arg: %s\\n", hmstrerror(fetch_sz));
            }
            cursor += fetch_sz;
        }while(0);
        """)

    rs = []
    for i, param in enumerate(method_parameters):
        fetch = subst(
            fetch_template,
            {'param_type': CType.of(param.parameter_type),
             'param_name': CIdentifierExpression(f'_{param.name}'),
             'count': CIntegerConstant(i)},
            False)
        rs.append(fetch)

    return rs


def __stk_check(params: CParameterDeclaration,
                is_capcall: str, is_fallback: str, is_compat: bool, is_bridge: bool) \
        -> Tuple[List[CVariableDeclaration], List[CStatement]]:
    decls = CVariableDeclaration.of(
        """struct arch_actv_local * __local = hm_actv_current_arch_actv_local();
        """)
    decls += CVariableDeclaration.of(
        """unsigned long __nr_ul = @__RPC_INFO_DECODE_STK_BUF_NR_UL:expr(__local->rpcinfo);
        """)

    if not is_compat:
        if is_bridge:
            decls += CVariableDeclaration.of(
                """unsigned long @__maybe_unused:attr __stacksz = 0ul;
                """)
        decls += CVariableDeclaration.of(
            f"""struct __arch_actv_stksz_state __stksz_state;
            """)
        stmts = generate_arg_stksz(params, is_capcall, is_fallback)
        stmts.append(CStatement.of(
            """if(__nr_ul * @sizeof:expr(unsigned long) != __stacksz){
                return E_HM_INVAL;
            }"""))

        return (decls, stmts)

    stmts = [CStatement.of(
        """if(__nr_ul * @sizeof:expr(__u32) != cursor){
            return E_HM_INVAL;
        }""")]

    return (decls, stmts)


def __mk_hdlr_table_template(server: Server, is_compat: bool) \
        -> Tuple[CVariableDeclaration, List[Tuple[CDesignation, CExpression]]]:
    svr = server.name
    hdlr_table_template = CVariableDeclaration(
        name='%fake%',
        type=CArrayType(
            base_type=CUnionType(name=f'{svr}_hdlrs_union'),
            capacity=CIdentifierExpression(f'__{svr}_method_MAX')),
        initializer=CExpression.of('@inits:expr')
    )

    if not is_compat:
        inits = [
            (CDesignation.of('[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] ='),
             CConstructorExpression.of(
                 '{.p_sysif_default_handler = &sysif_actvhdlr_default_handler}')),
            (CDesignation.of('[__ACTV_UPCALL_POOL_GRANT_CHANGE] ='),
             CConstructorExpression.of(
                 '{.p_sysif_handle_kcall_entry = &sysif_actv_pool_handle_grant_change}')),
            (CDesignation.of(
                f'[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __{svr}_method_MIN] ='),
             CConstructorExpression.of(
                 '{.p_sysif_default_handler = &sysif_actvhdlr_default_handler}'))
        ]
    else:
        inits = [
            (CDesignation.of('[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] ='),
             CConstructorExpression.of(
                 '{.p_sysif_default_handler = &sysif_actvhdlr_default_handler}')),
            (CDesignation.of('[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] ='),
             CConstructorExpression.of(
                 '{.p_sysif_handle_kcall_entry = &sysif_actv_pool_handle_grant_change}')),
            (CDesignation.of('[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] ='),
             CConstructorExpression.of(
                 '{.p_sysif_handle_kcall_entry = &sysif_actv_pool_handle_grant_change}')),
            (CDesignation.of(
                f'[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __{svr}_method_MIN * 2 + 1] ='),
             CConstructorExpression.of(
                 '{.p_sysif_default_handler = &sysif_actvhdlr_default_handler}'))
        ]

    return (hdlr_table_template, inits)


def __construct_hdlr_table(manager: Manager, is_cap: bool, is_compat: bool) -> \
        List[Tuple[CDesignation, CExpression]]:
    """ Partialy construct initializers of hdlr table with reserved methods and real methods"""
    rs = []
    cap = 'capcall' if is_cap else ''

    rsvd_method_ref = CConstructorExpression.of(
        '{.p_sysif_default_handler = &sysif_actvhdlr_reserved_default_handler}')
    if not is_compat:
        rs += list((CDesignation([CIndexDesignator(
            CIdentifierExpression(
                f'__{manager.server.name}_method_{manager.name}_rsvd_{n}'))]),
                rsvd_method_ref) for n in range(manager.capacity - len(manager.methods), 0, -1))
    else:
        rs += list((CDesignation([CIndexDesignator(
            CIdentifierExpression(
                f'__{manager.server.name}_method_{manager.name}_rsvd_{n} * 2'))]),
                rsvd_method_ref) for n in range(manager.capacity - len(manager.methods), 0, -1))
        rs += list((CDesignation([CIndexDesignator(
            CIdentifierExpression(
                f'__{manager.server.name}_method_{manager.name}_rsvd_{n} * 2 + 1'))]),
                rsvd_method_ref) for n in range(manager.capacity - len(manager.methods), 0, -1))

    for method in manager.methods:
        hdlr_name = f'{manager.server.handler_prefix}_{method.manager_name}_{method.name}'
        hdlr_name_compat = \
            f'{manager.server.handler_prefix}_compat_{method.manager_name}_{method.name}'

        hdlr_ref = CConstructorExpression.of(
            "{%s}" % f".p__actvbridge{cap}hdlr_{hdlr_name} = &__actvbridge{cap}hdlr_{hdlr_name}")
        compat_hdlr_ref = CConstructorExpression.of(
            "{%s}" % f""".p__actvbridge{cap}hdlr_{hdlr_name_compat} =
            &__actvbridge{cap}hdlr_{hdlr_name_compat}""")
        if not is_compat:
            rs.append((CDesignation([CIndexDesignator(
                CIdentifierExpression(
                    f'__{manager.server.name}_method_{method.manager_name}_{method.name}'))]),
                       hdlr_ref))
        else:
            rs.append((CDesignation([CIndexDesignator(
                CIdentifierExpression(
                    f'__{manager.server.name}_method_{method.manager_name}_{method.name} * 2'))]),
                       hdlr_ref))
            rs.append((CDesignation([CIndexDesignator(CIdentifierExpression(
                f'__{manager.server.name}_method_{method.manager_name}_{method.name} * 2 + 1'))]),
                       compat_hdlr_ref))

    return rs


def __construct_hdlr_tables(server: Server, is_compat: bool) -> \
        List[List[Tuple[CDesignation, CExpression]]]:
    """ Partialy construct initializers for actvhdlr table and actvcapcallhdlr table"""
    hdlrs = []
    capcall_hdlrs = []
    for manager in server.managers:
        hdlrs += __construct_hdlr_table(manager, False, is_compat)
        capcall_hdlrs += __construct_hdlr_table(manager, True, is_compat)

    return [hdlrs, capcall_hdlrs]


def __mk_actvhdlr_table(server: Server) -> List[Union[str, CTranslationUnit]]:
    res = [f'#ifdef __sysif_server_{server.name}_no_compat32_handlers__\n']
    ncompat_template, ncompat_inits = __mk_hdlr_table_template(server, False)
    [inits, cap_inits] = __construct_hdlr_tables(server, False)
    # make handlers table
    hdlr_table = subst(ncompat_template,
                       {'inits': CConstructorExpression(ncompat_inits + inits)},
                       False)
    hdlr_table.name = f'sysif_{server.name}_actvhdlr_table'
    res.append(CTranslationUnit([hdlr_table]))

    # make capcall handlers table
    capcallhdlr_table = subst(ncompat_template,
                              {'inits': CConstructorExpression(ncompat_inits + cap_inits)},
                              False)
    capcallhdlr_table.name = f'sysif_{server.name}_actvcapcallhdlr_table'
    res.append(CTranslationUnit([capcallhdlr_table]))

    res.append('#else\n')
    compat_template, compat_inits = __mk_hdlr_table_template(server, True)
    [inits_compat, cap_inits_compat] = __construct_hdlr_tables(server, True)
    # make compat handlers table
    res.append('#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR\n')
    res.append('#error "Only support 64-bit server, build for aarch64 please!"\n')
    res.append('#else\n')

    # make compat handlers table
    hdlr_table_compat = subst(compat_template,
                              {'inits': CConstructorExpression(compat_inits + inits_compat)},
                              False)
    hdlr_table_compat.name = f'sysif_{server.name}_actvhdlr_table'
    res.append(CTranslationUnit([hdlr_table_compat]))
    res.append('#endif\n')

    # make compat capcall handlers table
    capcallhdlr_table_compat = subst(
        compat_template,
        {'inits': CConstructorExpression(compat_inits + cap_inits_compat)},
        False)
    capcallhdlr_table_compat.name = f'sysif_{server.name}_actvcapcallhdlr_table'
    res.append(CTranslationUnit([capcallhdlr_table_compat]))
    res.append('#endif\n')

    return res


def __mk_sysif_show(server: Server) -> CFunction:
    sysif_show = CFunction(
        name=f'sysif_show_{server.name}_methods',
        parameters=[],
        return_type=CVoidType(),
        body=CStatement.of(
            """{
            @hm_debugs:stmt
            hm_info("%s_%s, max method num: %d\\n", @name:expr, "method", @method_num:expr);
            }"""))

    hm_debugs = []
    for manager in server.managers:
        for method in manager.methods:
            hm_debugs.append(CExpressionStatement(
                CCallExpression(CIdentifierExpression('hm_debug'), [
                    CStringLiteral('method is %s_%s_%s_%s, callnum is %u\\n'),
                    CStringLiteral('actvcall'),
                    CStringLiteral(manager.server.call_prefix),
                    CStringLiteral(method.manager_name),
                    CStringLiteral(method.name),
                    CIdentifierExpression(
                        f'__{manager.server.name}_method_{method.manager_name}_{method.name}')])))
            hm_debugs.append(CExpressionStatement(
                CCallExpression(CIdentifierExpression('hm_debug'), [
                    CStringLiteral('method is %s_%s_%s_%s, callnum is %u\\n'),
                    CStringLiteral('actvhdlr'),
                    CStringLiteral(manager.server.handler_prefix),
                    CStringLiteral(method.manager_name),
                    CStringLiteral(method.name),
                    CIdentifierExpression(
                        f'__{manager.server.name}_method_{method.manager_name}_{method.name}')])))

    subst(sysif_show,
          {'hm_debugs': hm_debugs,
           'name': CStringLiteral(server.name),
           'method_num': CIdentifierExpression(f'__{server.name}_method_MAX')},
          True)

    return sysif_show
