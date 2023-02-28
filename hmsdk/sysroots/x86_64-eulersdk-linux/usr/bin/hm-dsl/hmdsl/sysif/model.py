#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Model for sysif server
Author: Huawei OS Kernel Lab
Create: Mon 07 Dec 2020 08:30:42 PM CST
"""

from __future__ import annotations

from dataclasses import dataclass, field
from typing import FrozenSet, List, Optional, Set, Tuple
from enum import Enum

from hmdsl.common.pyext import EOptional


CType = str
""" Should be refined in the future. For now we use simple string to represent
a type in C.
"""


@dataclass
class Element:
    """
    Represent #ifdef and #ifndef C directives
    """

    ifdef_conditions: Set[str] = field(default_factory=set, init=False)
    """ The element is dumped only if the list of macros is defined """

    ifndef_conditions: Set[str] = field(default_factory=set, init=False)
    """ The element is dumped only if the list of macros is undefined """

    def get_category(self) -> Tuple[FrozenSet[str], FrozenSet[str]]:
        """
        To Categoraize directives into #ifdefs and #ifndefs
        """
        return (frozenset(self.ifdef_conditions), frozenset(self.ifndef_conditions))


@dataclass
class CCode(Element):
    """
    A string block which is C code
    """
    content: str


@dataclass
class Server(Element):
    """ Description of A SYSIF Server. """

    name: Optional[str] = None
    """ Name of the server. It should be specified in the SYSIF DSL through the
    ``USE_SERVER_NAME(...)`` primitive.
    """

    headers: List[CCode] = field(default_factory=list)
    """ C Header files required by the set of SYSIF apis """

    datatypes: List[CCode] = field(default_factory=list)
    """ Datatype declarations required by the set of SYSIF apis """

    call_prefix: Optional[str] = None
    """ Prefix used in generating the sysif callers """

    handler_prefix: Optional[str] = None
    """ Prefix used in generating the sysif handlers  """

    group: Optional[str] = None
    """ for __internal_rpccall """

    generate_weak_handler: bool = False
    """ Whether we need to generate weak handlers. """

    managers: List[Manager] = field(default_factory=list)

    def update(self, svr: Server):
        """ Update the current server by integrating all contents from another
        server ``svr``.
        """

        for header in self.headers:
            header.ifdef_conditions |= self.ifdef_conditions
            header.ifndef_conditions |= self.ifndef_conditions
        for datatype in self.datatypes:
            datatype.ifdef_conditions |= self.ifdef_conditions
            datatype.ifndef_conditions |= self.ifndef_conditions
        for manager in self.managers:
            manager.ifdef_conditions |= self.ifdef_conditions
            manager.ifndef_conditions |= self.ifndef_conditions
        self.ifdef_conditions.clear()
        self.ifndef_conditions.clear()

        for header in svr.headers:
            header.ifdef_conditions |= svr.ifdef_conditions
            header.ifndef_conditions |= svr.ifndef_conditions
        self.headers += svr.headers
        for datatype in svr.datatypes:
            datatype.ifdef_conditions |= svr.ifdef_conditions
            datatype.ifndef_conditions |= svr.ifndef_conditions
        self.datatypes += svr.datatypes
        for mgr in svr.managers:
            mgr.ifdef_conditions |= svr.ifdef_conditions
            mgr.ifndef_conditions |= svr.ifndef_conditions
            mgr.server = self
        self.managers += svr.managers
        svr.ifdef_conditions.clear()
        svr.ifndef_conditions.clear()

        self.name = EOptional.merge(self.name, svr.name)
        self.call_prefix = EOptional.merge(self.call_prefix, svr.call_prefix)
        self.handler_prefix = EOptional.merge(self.handler_prefix, svr.handler_prefix)
        self.group = EOptional.merge(self.group, svr.group)
        self.generate_weak_handler = self.generate_weak_handler or svr.generate_weak_handler


@dataclass
class Manager(Element):
    """
    A sysif server is constructed by multiple managers
    """
    name: str
    """ Name of the manager. """

    server: Optional[Server]

    capacity: int
    """ Capacity of a manager indicates how many methods can be mounted to it.
    For example, if the capacity of a manager is 5, declaring 6 methods inside
    this manager will lead to an error.
    """

    methods: List[Method] = field(default_factory=list)


@dataclass
class Parameter(Element):
    """
    Parameter object to present parameters of sysif methods
    """
    name: str
    parameter_type: CType


class MethodType(Enum):
    """
    Enum of different types of sysif apis
    """
    NOBUF = 0
    RETBUF = 1
    BUF = 2
    FALLBACK = 3


@dataclass
class Method(Element):
    """
    A manager is constructed with multiple sysif methods
    """
    name: str
    """ The name of the method. """

    fake_mgr_name: Optional[str]
    """ There are some inconsistencies with the name of the manager in the kernel.
    This is just to compat with the inconsistencies.
    To be removed in the future...
    """

    manager: Optional[Manager]
    """ The manager of the method. """

    parameters: List[Parameter]
    """ List of the parameters of the method. """

    indirect_returned_values: Optional[List[Parameter]]
    """ If it is not None, the code generator package all these parameters in
    a struct, and return it through the last method parameter. For example, ::

        int XXX(..., struct YYY * ret);

    where ``YYY``'s definition includes all parameters in ``indirect_returned_values``.
    """

    direct_return_type: CType

    support_self_call: bool
    """ Whether the method supports self-call generation. If the option is
    set to True, the code generator will use direct-call instead of rpc-call
    on this function, when its caller is in the same module.
    """

    slow_data: bool

    stk_check: bool = True

    @property
    def manager_name(self) -> str:
        """
        To forward compat with existing sysif DSL files which defines manager name wrongly
        """
        return self.fake_mgr_name or EOptional.get(self.manager).name

    @property
    def server_name(self) -> str:
        """
        Get the server name whom the method belongs to
        """
        return EOptional.get(EOptional.get(EOptional.get(self.manager).server).name)

    @property
    def method_type(self) -> MethodType:
        """
        Get the type of the sysif method
        """
        if self.indirect_returned_values is None and not self.slow_data:
            return MethodType.NOBUF
        elif self.indirect_returned_values is None and self.slow_data:
            return MethodType.BUF
        elif self.indirect_returned_values is not None and not self.slow_data:
            return MethodType.RETBUF
        else:
            return MethodType.FALLBACK
