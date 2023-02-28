#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
Description: Generate methods statistics for audit
Author: Huawei OS Kernel Lab
Create: Thu Jun 03 16:18:55 2021
"""

import json
from typing import List, Tuple, Dict, Any, Union
from hmdsl.sysif.model import Server
from hmdsl.sysif.codegen.sysif_gen import styler
from hmdsl.common.c_biast.subst import subst
from hmdsl.common.logging import get_logger
from hmdsl.common.c_biast.biast import CTranslationUnit, CFunction, CVariableDeclaration, \
    CParameterDeclaration, CStorageQualifier, CVoidType, CSignDescriptor, CIntType, CPointerType, \
    CEnumType, CIdentifierExpression, CStringLiteral, CCallExpression, CEnumItem, \
    CIntegerConstant, CStatement, CExpressionStatement


logger = get_logger("sysif.codegen.audits_gen")


def gen_server_audit_statistics(server: Server) -> str:
    """
    Generate sysif audit statistics of a given server
    """
    methods = []
    server_name = server.name
    server_name = server_name.replace("hmnet", "net")
    for manager in server.managers:
        rsvd_num = manager.capacity - len(manager.methods)
        for method in manager.methods:
            method_name = f'{server_name}_{manager.name}_{method.name}'
            methods.append(method_name)
        methods += list(f'{server_name}_{manager.name}_rsvd_{n}' for n in range(rsvd_num, 0, -1))

    json_item = {"server_name": server_name, "methods": methods}
    return json.dumps(json_item)


def __gen_server_list_audit_statistics(configs: List[Dict[str, Any]],
                                       statistics_dict: Dict[str, List[str]]) -> str:
    rs = ['#ifndef __SYSIF_SERVER_NUM_LIST_H__\n']
    rs.append('#define __SYSIF_SERVER_NUM_LIST_H__\n')
    rs.append(__mk_server_audit_numbers_enum(configs))
    rs += __mk_sysif_table(configs, statistics_dict)
    rs.append('#endif')
    rs_to_str = list(styler.render(item) if not isinstance(item, str) else item for item in rs)

    return ''.join(rs_to_str)


def __mk_server_audit_numbers_enum(configs: List[Dict[str, Any]]) -> CTranslationUnit:
    items = [CEnumItem('__SERVER_INVAL', CIntegerConstant('0'))]
    items += list(CEnumItem(f'__server_{config["server_name"]}', None) for config in configs)
    items.append(CEnumItem('__SERVER_MAX', None))

    audit_enum = CTranslationUnit([CVariableDeclaration(
        name=None,
        type=CEnumType(name='__server_audit_numbers',
                       enum_items=items)
    )])

    return audit_enum


def __mk_sysif_table(configs: List[Dict[str, Any]], statistics_dict: Dict[str, List[str]]) \
        -> List[Union[str, CTranslationUnit]]:
    sysif_table_template = CFunction(
        name='sysif_table',
        parameters=[CParameterDeclaration(
            "callnum",
            CPointerType(CIntType(CSignDescriptor.UNSIGNED)))],
        return_type=CVoidType(),
        body=CStatement.of("""{
            @callnums:stmt
        }""")
    )

    callnums_def = []
    callnums_table = []
    nums_table, nums_start_table = __calculate_call_nums(configs, statistics_dict)
    for method, num in nums_table:
        callnums_def.append(CExpressionStatement(
            CCallExpression(CIdentifierExpression('printf'), [
                CStringLiteral(f'#define {method} {str(num)}\\n')])
        ))
        callnums_table.append(CExpressionStatement(
            CCallExpression(CIdentifierExpression('printf'), [
                CStringLiteral(f'_S({str(num)}, \\\"{method}\\\")\\n')])
        ))

    start_table = [CExpressionStatement(CCallExpression(CIdentifierExpression('printf'), [
        CStringLiteral('static const int __hm_audit_sysif_start[] = {\\n')]))]
    for server, num in nums_start_table:
        start_table.append(CExpressionStatement(
            CCallExpression(CIdentifierExpression('printf'), [
                CStringLiteral(f'{str(num)}, //start of {server}\\n')])))
    start_table.append(CExpressionStatement(CCallExpression(CIdentifierExpression('printf'), [
        CStringLiteral('};')])))

    rs = ["#ifdef AUDIT_CALL_NUMS\n"]
    rs.append(CTranslationUnit([subst(sysif_table_template, {'callnums': callnums_def}, False)]))
    rs.append("#endif\n")
    rs.append("#ifdef AUDIT_CALL_NUMS_TABLE\n")
    rs.append(CTranslationUnit([subst(sysif_table_template, {'callnums': callnums_table}, False)]))
    rs.append("#endif\n")
    rs.append("#ifdef AUDIT_SYSIF_NUMS_STARTS\n")
    nums_start_table = subst(sysif_table_template, {'callnums': start_table}, False)
    nums_start_table.name = 'sysif_nums'
    nums_start_table.storage_qualifiers = {CStorageQualifier.STATIC}
    rs.append(CTranslationUnit([nums_start_table]))
    rs.append("#endif\n")

    return rs


def __calculate_call_nums(configs: List[Dict[str, Any]],
                          statistics: Dict[str, List[str]]) -> List[List[Tuple[str, int]]]:
    call_nums = []
    call_start_nums = []

    last_num = 0
    last_server = ''
    for config in configs:
        if config["server_name"] in statistics:
            if last_num > config['start_audit_num']:
                logger.info(f"methods of {last_server} exceeded max number")
                logger.info(
                    f"""couldn't generate audit number for {config['server_name']}
                    with configured number
                    """)
            num_starts = max(last_num, config['start_audit_num'])
            call_start_nums.append((config["server_name"], num_starts))

            for method in statistics[config["server_name"]]:
                call_nums.append((method, str(num_starts)))
                num_starts += 1

            last_num = num_starts + 1
            last_server = config['server_name']
        else:
            logger.info(f"didn't find any audit statistics for {config['server_name']}")

    return [call_nums, call_start_nums]
