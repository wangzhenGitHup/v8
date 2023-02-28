#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Generate selfcall for server apis
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:33:17 PM CST
"""

from dataclasses import dataclass, field
from typing import List

from hmdsl.common.c_biast.subst import subst
from hmdsl.sysif.model import Server, Method, MethodType
from hmdsl.common.c_biast.biast import CExpression, CFunction, CParameterDeclaration, CType, \
    CAliasType, CVoidType, CSignDescriptor, CLongType, CLonglongType, CPointerType, \
    CIdentifierExpression, CStatement


@dataclass
class BufferDescription:
    """
    To describe the buffer of different types sysif methods
    """
    decls: List[CParameterDeclaration] = field(default_factory=list)
    """ the parameter declarations required to describe the buffer """

    buf_expr: CExpression = field(default_factory=CExpression.null)
    """ The expression where we refer to the buffer, NULL when the buffer
    is unavailable. Sometimes buf_expr can be nullable even if it IS
    declared. Don't know why.
    """

    buf_sz_expr: CExpression = field(default_factory=lambda: CExpression.of('0ul'))
    """ Size of the buffer. 0 if it is unavailable. """


def __gen_sendbuf(method: Method) -> BufferDescription:
    desc = BufferDescription()
    sendbuf_name = "__buf"

    if method.method_type is not MethodType.RETBUF:
        desc.decls.append(CParameterDeclaration(sendbuf_name, CPointerType(CVoidType())))

    if method.method_type in (MethodType.FALLBACK, MethodType.BUF):
        desc.buf_expr = CIdentifierExpression(sendbuf_name)
        desc.buf_sz_expr = CExpression.of(
            "@__RPC_INFO_DECODE_MEM_BUF_LEN:expr((unsigned long)__rpc_info)")

    return desc


def __gen_rplybuf(method: Method) -> BufferDescription:
    desc = BufferDescription()
    rplybuf_name = "__rply_buf"

    if method.indirect_returned_values is not None:
        # RETBUF/FALLBACK
        desc.decls.append(CParameterDeclaration(rplybuf_name, CPointerType(CVoidType())))
        desc.buf_expr = CIdentifierExpression(rplybuf_name)

        if method.method_type is MethodType.FALLBACK:
            desc.decls.append(CParameterDeclaration(f"rply_buf_sz",
                                                    CLongType(CSignDescriptor.UNSIGNED)))
            desc.buf_sz_expr = CIdentifierExpression(f"rply_buf_sz")
        else:
            desc.buf_sz_expr = CExpression.of(
                "@__RPC_INFO_DECODE_MEM_BUF_LEN:expr((unsigned long)__rpc_info)")

    return desc


def gen_selfcall(server: Server, override: bool) -> List[CFunction]:
    """
    Generate self call for server sysif apis
    """
    selfcalls = []

    for manager in server.managers:
        for method in manager.methods:
            if override:
                selfcalls += __mk_selfcall(method)
            elif method.support_self_call:
                selfcalls += __mk_selfcall(method)

    return selfcalls


def __mk_selfcall_template(method: Method) -> CFunction:
    parameters = list(CParameterDeclaration(p.name, CType.of(p.parameter_type))
                      for p in method.parameters)

    selfcall_template = CFunction(
        name='',
        parameters=[CParameterDeclaration.of("@rref:decl"),
                    CParameterDeclaration("__rpc_info", CLonglongType(CSignDescriptor.UNSIGNED)),
                    CParameterDeclaration.of("@buf_decls:decl"),
                    *parameters],
        return_type=CType.of(method.direct_return_type),
        body=CStatement.of(
            """{
            @unused_rref:stmt
            struct sysif_actv_selfcall selfcall = {
                   @_send_buf:expr,
                   @_send_bufsz:expr,
                   @_rply_buf:expr,
                   @_rply_bufsz:expr
                };
            return @callee:expr((unsigned long long)(uintptr_t)(& selfcall),
                    @__ACTV_CRED_SELFCALL:expr, @args:expr);
            }"""))

    return selfcall_template


def __mk_selfcall(method: Method) -> List[CFunction]:
    selfcall_template = __mk_selfcall_template(method)

    callee = CIdentifierExpression(
        f'actvhdlr_{method.manager.server.handler_prefix}_{method.manager_name}_{method.name}')
    func_name_postfix = f'{method.manager.server.call_prefix}_{method.manager_name}_{method.name}'

    sendbuf_desc = __gen_sendbuf(method)
    rplybuf_desc = __gen_rplybuf(method)

    if not method.support_self_call:
        selfcall_template.body = CStatement.of(
            """{
            panic(\"Invalid selfactvcall of function %s\\n\", __func__);
            return 0;
            }""")

    template = subst(selfcall_template, {
        'buf_decls': sendbuf_desc.decls + rplybuf_desc.decls,
        '_send_buf': sendbuf_desc.buf_expr,
        '_send_bufsz': sendbuf_desc.buf_sz_expr,
        '_rply_buf': rplybuf_desc.buf_expr,
        '_rply_bufsz': rplybuf_desc.buf_sz_expr,
        'callee': callee,
        'args': list(CIdentifierExpression(p.name) for p in method.parameters)
    })

    actvcall = subst(template, {'rref': [], 'unused_rref': []})
    actvcall.name = f'__actvcall_{func_name_postfix}'

    actvcapcall = subst(template, {
        'rref': CParameterDeclaration("__rref", CAliasType('rref_t')),
        'unused_rref': CStatement.of("@UNUSED:expr(__rref);"),
    })
    actvcapcall.name = f'__actvcapcall_{func_name_postfix}'

    return [actvcall, actvcapcall]
