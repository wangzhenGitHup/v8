#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Generate sysif client apis
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:34:03 PM CST
"""

from typing import List, Union
from hmdsl.common.c_biast.subst import subst
from hmdsl.sysif.model import Server, Manager, Method, MethodType
from hmdsl.common.c_biast.biast import CExpression, CTranslationUnit, CAttribute, CFunction, \
    CVariableDeclaration, CParameterDeclaration, CStorageQualifier, CType, CAliasType, CVoidType, \
    CSignDescriptor, CLongType, CLonglongType, CPointerType, CStructType, CFunctionType, \
    CIdentifierExpression, CStatement


def gen_actvcall(server: Server) -> CTranslationUnit:
    """
    Generate client apis, namely actvcall, for the server
    """
    res = []
    for manager in server.managers:
        res += __mk_actvcall_apis(manager)

    return CTranslationUnit(res)


def __mk_actvcall_apis(manager: Manager) -> List[Union[CVariableDeclaration, CFunction]]:
    """generate actvcall and actvcapcall APIs for a manager
    """
    res = []
    for method in manager.methods:
        res += __generate_internal_actvcall_decls(method)
        res += __generate_actvxact_calls(method)
        res += __generate_actv_calls(method)

    return res


def __generate_internal_actvcall_decls(method: Method) -> List[CVariableDeclaration]:
    call_prefix = method.manager.server.call_prefix
    caller_name_postfix = f"{call_prefix}_{method.manager_name}_{method.name}"

    return_type = CType.of(method.direct_return_type)
    parameters = list(CParameterDeclaration(param.name, CType.of(param.parameter_type))
                      for param in method.parameters)

    rply = [CParameterDeclaration('__rply_buf', CPointerType(CVoidType())),
            CParameterDeclaration('rply_buf_sz', CLongType(CSignDescriptor.UNSIGNED))] \
        if method.method_type is MethodType.FALLBACK else []

    actvcall_decl_template = CVariableDeclaration(
        name=None,
        type=CFunctionType(
            parameter_decls=[CParameterDeclaration.of("@rref:decl"),
                             CParameterDeclaration('__rpc_info',
                                                   CLonglongType(CSignDescriptor.UNSIGNED)),
                             CParameterDeclaration('__buf', CPointerType(CVoidType())),
                             *rply,
                             *parameters],
            return_type=return_type,
            variable_length_argument=False),
        storage_qualifiers={CStorageQualifier.EXTERN})

    actvcall = subst(actvcall_decl_template, {'rref': []}, False)
    actvcall.name = f"__actvcall_{caller_name_postfix}"

    actvcapcall = subst(actvcall_decl_template,
                        {'rref': CParameterDeclaration('__rref', CAliasType("rref_t"))},
                        False)
    actvcapcall.name = f"__actvcapcall_{caller_name_postfix}"

    return [actvcall, actvcapcall]


def generate_arg_stksz(params: CParameterDeclaration, is_capcall: str, is_fallback: str) \
        -> List[CStatement]:
    """
    Generate arguments stacks info for sysif method
    """
    ret = [CStatement.of(
        f"""__stksz_state =
                __arch_actv_rpc_stksz_init({is_capcall}, {is_fallback});
        """)]

    for param in params:
        ret.append(subst(CStatement.of(f"""
            __stksz_state = __arch_actv_rpc_stksz_append(
                __stksz_state,
                @sizeof:expr(@param_type:type),
                @__arch_actv_rpc_stksz_alignment:expr(@param_type:type)
            );
            """), {'param_type': param.type}, False))

    ret.append(CStatement.of('__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);'))
    return ret


def __generate_actvxact_template(method: Method) -> CFunction:
    caller_prefix = method.manager.server.call_prefix
    caller_name_postfix = f"{caller_prefix}_{method.manager_name}_{method.name}"
    return_type = CType.of(method.direct_return_type)
    orig_parameters = list(CParameterDeclaration(param.name, CType.of(param.parameter_type))
                           for param in method.parameters)

    buf = [CParameterDeclaration("___void_buf", CPointerType(CVoidType())),
           CParameterDeclaration("___void_buf_sz", CLongType(CSignDescriptor.UNSIGNED))] \
        if method.slow_data else []

    ret_buf = [
        CParameterDeclaration("__ret",
                              CPointerType(CStructType(f'__actvret_{caller_name_postfix}')))
    ] if method.indirect_returned_values is not None else []

    parameters = [*orig_parameters, *buf, *ret_buf]

    actvxact_call_template = CFunction(
        name='%fake%',
        parameters=[CParameterDeclaration("is_xact_fwd", CAliasType('bool')),
                    CParameterDeclaration("is_xact_allow_refwd", CAliasType('bool')),
                    CParameterDeclaration.of("@_rref:decl"),
                    *parameters],
        return_type=return_type,
        body=CStatement.of("""{
            const unsigned long __callno = @callno:expr;
            @return_type:type __res;

            unsigned long __stacksz = 0ul;
            struct __arch_actv_stksz_state __stksz_state;
            @argument_stksz:stmt

            do {
                unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(
                    is_xact_fwd,
                    is_xact_allow_refwd,
                    __callno,
                    @send_buf_sz:expr,
                    __stacksz / @sizeof:expr(unsigned long)
                );
                __res = @callee:expr(@rref:expr, rpc_info, @send_buf:expr, @rply:expr, @args:expr);
            } while (__res == (@return_type:type)E_HM_ACTIVATION_RPC_RETRY);
            return __res;
        }"""),
        inline=True,
        storage_qualifiers={CStorageQualifier.STATIC},
        attributes=[CAttribute.always_inline()])

    return actvxact_call_template


def __generate_actvxact_calls(method: Method) -> List[CFunction]:
    caller_prefix = method.manager.server.call_prefix
    caller_name_postfix = f"{caller_prefix}_{method.manager_name}_{method.name}"
    orig_parameters = list(CParameterDeclaration(param.name, CType.of(param.parameter_type))
                           for param in method.parameters)

    actvxact_call_template = __generate_actvxact_template(method)

    is_fallback = '1' if method.method_type is MethodType.FALLBACK else '0'

    if method.slow_data:
        send_buf = CIdentifierExpression("___void_buf")
        send_buf_sz = CIdentifierExpression("___void_buf_sz")
    elif method.indirect_returned_values is not None:
        send_buf = CIdentifierExpression("__ret")
        send_buf_sz = CExpression.of("sizeof(*__ret)")
    else:
        send_buf = CIdentifierExpression("NULL")
        send_buf_sz = CExpression.of("0ul")

    subst(actvxact_call_template, {
        'callno': CIdentifierExpression(
            f'__{method.server_name}_method_{method.manager_name}_{method.name}'),
        'return_type': actvxact_call_template.return_type,
        'send_buf_sz': send_buf_sz,
        'send_buf': send_buf,
        'rply': [CExpression.of("ptr_to_void(__ret)"),
                 CExpression.of("sizeof(*__ret)")] if is_fallback == '1' else [],
        'args': list(CIdentifierExpression(param.name) for param in orig_parameters),
        }, True)

    actvxact_call = subst(actvxact_call_template, {
        '_rref': [],
        'argument_stksz': generate_arg_stksz(orig_parameters, '0', is_fallback),
        'callee': CIdentifierExpression(f'__actvcall_{caller_name_postfix}'),
        'rref': [],
        }, False)
    actvxact_call.name = f'actvxactcall_{caller_name_postfix}'

    actvxact_capcall = subst(actvxact_call_template, {
        '_rref': CParameterDeclaration('__rref', CAliasType('rref_t')),
        'argument_stksz': generate_arg_stksz(orig_parameters, '1', is_fallback),
        'callee': CIdentifierExpression(f'__actvcapcall_{caller_name_postfix}'),
        'rref': CIdentifierExpression('__rref')
        }, False)
    actvxact_capcall.name = f'actvxactcapcall_{caller_name_postfix}'

    return [actvxact_call, actvxact_capcall]


def __generate_actv_calls(method: Method) -> List[CFunction]:
    call_prefix = method.manager.server.call_prefix
    caller_name_postfix = f"{call_prefix}_{method.manager_name}_{method.name}"

    return_type = CType.of(method.direct_return_type)
    orig_parameters = list(CParameterDeclaration(param.name, CType.of(param.parameter_type))
                           for param in method.parameters)

    buf = [CParameterDeclaration("___void_buf", CPointerType(CVoidType())),
           CParameterDeclaration("___void_buf_sz", CLongType(CSignDescriptor.UNSIGNED))] \
        if method.slow_data else []

    ret_buf = [
        CParameterDeclaration("__ret",
                              CPointerType(CStructType(f"__actvret_{caller_name_postfix}")))
    ] if method.indirect_returned_values is not None else []

    parameters = [*orig_parameters, *buf, *ret_buf]

    actvcall_func_template = CFunction(
        name='%fake%',
        parameters=[CParameterDeclaration.of("@_rref:decl"), *parameters],
        return_type=return_type,
        body=CStatement.of("{return @callee:expr(false, false, @rref:expr, @args:expr);}"),
        inline=True,
        storage_qualifiers={CStorageQualifier.STATIC},
        attributes=[CAttribute.always_inline()])

    actvcall = subst(actvcall_func_template,
                     {'_rref': [],
                      'callee': CIdentifierExpression(f'actvxactcall_{caller_name_postfix}'),
                      'rref': [],
                      'args': list(CIdentifierExpression(param.name) for param in parameters)},
                     False)

    actvcall.name = f"actvcall_{caller_name_postfix}"

    actvcapcall = subst(actvcall_func_template,
                        {'_rref': CParameterDeclaration('__rref', CAliasType("rref_t")),
                         'callee': CIdentifierExpression(f'actvxactcapcall_{caller_name_postfix}'),
                         'rref': CIdentifierExpression("__rref"),
                         'args': list(CIdentifierExpression(param.name) for param in parameters)},
                        False)
    actvcapcall.name = f"actvcapcall_{caller_name_postfix}"

    return [actvcall, actvcapcall]
