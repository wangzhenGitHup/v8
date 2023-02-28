#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Generate internal client apis
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:37:08 PM CST
"""

from typing import List, Union, Tuple
from hmdsl.common.c_biast.subst import subst
from hmdsl.sysif.model import Server, Manager, Method, MethodType
from hmdsl.common.c_biast.biast import CExpression, CTranslationUnit, CAttribute, CFunction, \
    CVariableDeclaration, CParameterDeclaration, CStorageQualifier, CType, CAliasType, CVoidType, \
    CSignDescriptor, CIntType, CLongType, CLonglongType, CPointerType, CFunctionType, \
    CIdentifierExpression, CStatement


def gen_internal_actvcall(server: Server) -> CTranslationUnit:
    """
    Generate definitions of actv calls
    """
    res = __mk_rpc_calls(server)
    for manager in server.managers:
        res += __mk_client_actvcall_apis(manager)

    return CTranslationUnit(res)


def __mk_client_actvcall_apis(manager: Manager) -> List[Union[CVariableDeclaration, CFunction]]:
    res = []
    for method in manager.methods:
        res += __generate_internal_actv_decls(method)
        res += __generate_internal_actvcalls(method)
    return res


def __mk_rpc_call_template(server: Server) -> Tuple[CFunction]:
    rpc_template = CFunction(
        name='%fake%',
        parameters=[CParameterDeclaration(name=None, type=CVoidType())],
        return_type=CIntType(),
        body=CStatement.of(
            """{@__RPC_DEF_RETVAR:expr(int, ret);
            @rpc_callee:expr(@group:expr, @buf_type:expr, ret);
            return ret;
            }
            """),
        storage_qualifiers={CStorageQualifier.STATIC},
        attributes=[CAttribute.of("@__used:attr"),
                    CAttribute.of("@__noinline:attr"),
                    CAttribute.of("@__opt_noframe:attr")]
    )

    rpc_cap_template = subst(
        rpc_template,
        {'group': [],
         'rpc_callee': CIdentifierExpression('__RPC_CAP_SYSCALL')},
        False)

    # function body will later be replaced by a panic if server's group tag is None
    subst(rpc_template,
          {'group': CExpression.of(server.group or 'NO_GROUP_ALERT'),
           'rpc_callee': CIdentifierExpression('__RPC_FAST_SYSCALL')},
          True)

    return (rpc_template, rpc_cap_template)


def __mk_rpc_calls(server: Server) -> List[CFunction]:
    rs = []
    rpc_template, rpc_cap_template = __mk_rpc_call_template(server)
    call_nobuf = subst(rpc_template, {'buf_type': CIdentifierExpression("NOBUF")}, False)
    call_nobuf.name = '__internal_rpccall_nobuf'
    rs.append(call_nobuf)

    call_buf = subst(rpc_template, {'buf_type': CIdentifierExpression("SENDBUF")}, False)
    call_buf.name = '__internal_rpccall_buf'
    rs.append(call_buf)

    call_ret = subst(rpc_template, {'buf_type': CIdentifierExpression("RETBUF")}, False)
    call_ret.name = '__internal_rpccall_retbuf'
    rs.append(call_ret)

    call_fallback = subst(rpc_template, {'buf_type': CIdentifierExpression("FALLBACK")}, False)
    call_fallback.name = '__internal_rpccall_fallback'
    rs.append(call_fallback)

    if server.group is None:
        for func in rs:
            func.body = CStatement.of(
                """
                {hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\\n");
                return E_HM_NOSYS;
                }
                """)

    capcall_nobuf = subst(rpc_cap_template, {'buf_type': CIdentifierExpression("NoBuf")}, False)
    capcall_nobuf.name = '__internal_rpccapcall_nobuf'
    rs.append(capcall_nobuf)

    capcall_buf = subst(rpc_cap_template, {'buf_type': CIdentifierExpression("SendBuf")}, False)
    capcall_buf.name = '__internal_rpccapcall_buf'
    rs.append(capcall_buf)

    capcall_ret = subst(rpc_cap_template, {'buf_type': CIdentifierExpression("RetBuf")}, False)
    capcall_ret.name = '__internal_rpccapcall_retbuf'
    rs.append(capcall_ret)

    capcall_fallback = subst(rpc_cap_template, {'buf_type': CIdentifierExpression("")}, False)
    capcall_fallback.name = '__internal_rpccapcall_fallback'
    rs.append(capcall_fallback)

    return rs


def __generate_internal_actv_decls(method: Method) -> List[CVariableDeclaration]:
    call_prefix = method.manager.server.call_prefix
    caller_name_postfix = f"{call_prefix}_{method.manager_name}_{method.name}"

    # postfix is nobuf, retbuf, buf, etc.
    internal_impl_postfix = method.method_type.name.lower()

    call_attributes = [CAttribute.alias(f"__internal_rpccall_{internal_impl_postfix}")]
    capcall_attributes = [CAttribute.alias(f"__internal_rpccapcall_{internal_impl_postfix}")]

    # Only for the fallback case we need to obtain the indirect_returned_values
    # from a reply buffer, namely `rply_buf`.
    rply = [CParameterDeclaration('__rply_buf', CPointerType(CVoidType())),
            CParameterDeclaration('rply_buf_sz', CLongType(CSignDescriptor.UNSIGNED))] \
        if method.method_type is MethodType.FALLBACK else []

    actv_decl_template = CVariableDeclaration(
        name='',
        type=CFunctionType(
            parameter_decls=[
                CParameterDeclaration.of("@rref:decl"),
                CParameterDeclaration('rpc_info', CLonglongType(CSignDescriptor.UNSIGNED)),
                CParameterDeclaration('__buf', CPointerType(CVoidType())),
                *rply],
            return_type=CType.of(method.direct_return_type),
            variable_length_argument=True),
        storage_qualifiers={CStorageQualifier.STATIC})

    actv_call = subst(actv_decl_template, {'rref': []}, False)
    actv_call.attributes = call_attributes
    actv_call.name = f'____actvcall_{caller_name_postfix}'

    actv_capcall = subst(actv_decl_template,
                         {'rref': CParameterDeclaration('__rref', CAliasType('rref_t'))},
                         False)
    actv_capcall.attributes = capcall_attributes
    actv_capcall.name = f"____actvcapcall_{caller_name_postfix}"

    return [actv_call, actv_capcall]


def __generate_internal_actvcall_template(method: Method) -> CFunction:
    return_type = CType.of(method.direct_return_type)
    parameters = list(CParameterDeclaration(param.name, CType.of(param.parameter_type))
                      for param in method.parameters)

    # Only for the fallback case we need to obtain the indirect_returned_values
    # from a reply buffer, namely `rply_buf`.
    rply = [CParameterDeclaration("__rply_buf", CPointerType(CVoidType())),
            CParameterDeclaration("rply_buf_sz", CLongType(CSignDescriptor.UNSIGNED))] \
        if method.method_type is MethodType.FALLBACK else []

    actv_call_template = CFunction(
        name='',
        parameters=[CParameterDeclaration.of("@rref:decl"),
                    CParameterDeclaration("__rpc_info", CLonglongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration("__buf", CPointerType(CVoidType())),
                    *rply,
                    *parameters],
        return_type=return_type,
        body=CStatement.of(
            """
            {@return_type:type __ret;
             @local_args:decl
             __ret = @callee:expr(@_rref:expr, __rpc_info, __buf, @_rply:expr, @call_args:expr);
             return __ret;
            }
            """),
        attributes=[CAttribute.of("@__opt_noframe:attr"),
                    CAttribute.of("@__opt_nostkprot:attr")])

    local_args = []
    call_args = []
    for p in method.parameters:
        local_args += CVariableDeclaration.of(
            f'{p.parameter_type} @__maybe_unused:attr __actv_local_var_{p.name} = {p.name};')

        call_args.append(CExpression.of(
            f'@__ARCH_ACTV_RPC_PASS_ARG:expr({p.name}, __actv_local_var_{p.name})'))

    return subst(actv_call_template,
                 {'return_type': return_type,
                  'local_args': local_args,
                  '_rply': list(CIdentifierExpression(param.name) for param in rply),
                  'call_args': call_args},
                 True)


def __generate_internal_actvcalls(method: Method) -> List[CFunction]:
    actv_call_template = __generate_internal_actvcall_template(method)
    call_prefix = method.manager.server.call_prefix
    caller_postfix = f"{call_prefix}_{method.manager_name}_{method.name}"
    actv_call = subst(actv_call_template,
                      {'rref': [],
                       'callee': CIdentifierExpression(f"____actvcall_{caller_postfix}"),
                       '_rref': [],
                       },
                      False)
    actv_call.name = f'__actvcall_{caller_postfix}'

    actv_capcall = subst(actv_call_template,
                         {'rref': CParameterDeclaration("__rref", CAliasType('rref_t')),
                          'callee': CIdentifierExpression(f"____actvcapcall_{caller_postfix}"),
                          '_rref': CIdentifierExpression("__rref"),
                          },
                         False)
    actv_capcall.name = f"__actvcapcall_{caller_postfix}"

    return [actv_call, actv_capcall]
