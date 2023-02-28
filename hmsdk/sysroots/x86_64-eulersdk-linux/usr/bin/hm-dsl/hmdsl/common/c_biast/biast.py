#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: Bidirectional AST Elements Of C Language
Author: Huawei OS Kernel Lab
Create: Mon 28 Dec 2020 16:30:00 PM CST
"""

from __future__ import annotations

from typing import Dict, Iterable, List, Optional, Set, Tuple, Type as SubType, Union, Any
from dataclasses import dataclass, field
from collections import Counter
from copy import deepcopy
from enum import Enum
from itertools import chain

from lark import Transformer, Token, v_args

from hmdsl.common.c_biast.parser import c_parser


class MacroExpandingError(Exception):
    """ class of macro expanding errors  """


class CBiAst:
    """ Base class of bi-directional C-Ast elements.  """

    @classmethod
    def of(cls, content: str) -> CBiAst:
        """ A function to parse a block of C codes to C BiAst """
        raise NotImplementedError(f"unimplemented method 'of' in {cls}")

    def rsvd_ast(self) -> CBiAst:
        """ reserve a public interface """
        return self


class CMacro:
    """ A BiAst element represents C macro """
    @classmethod
    def get_base_class(cls) -> SubType[CBiAst]:
        """ Base function to get base class """
        raise NotImplementedError

    def rsvd_macro(self) -> CMacro:
        """ reserve a public interface """
        return self


class CExpression(CBiAst):
    """ A BiAst element represents C Expression """
    @classmethod
    def of(cls, content: str) -> CExpression:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="expression")

    @classmethod
    def null(cls) -> CExpression:
        """ To create a `NULL` expression """
        return CIdentifierExpression('NULL')

    @property
    def precedence(self) -> int:
        """ If not explicitly specified, the precedence of an expression is
        0, i.e. the highest, by default.
        """
        return 1


@dataclass
class CTranslationUnit(CBiAst):
    """ A single pre-processed C file is called a translation
    unit.
    """

    content: List[Union[CDeclaration, CFunction]]

    @classmethod
    def of(cls, content: str) -> CTranslationUnit:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="translation_unit")


class CAttribute(CBiAst):
    """ A BiAst element represents C attribute """
    @classmethod
    def of(cls, content: str) -> CAttribute:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="attribute_specifier")

    # A set of short-cut attribute constructors

    @classmethod
    def alias(cls, alias_name: str) -> CAttribute:
        """ An alias attribute tells the compiler that the function is
        an alias of an existing one, hence we have no need to implement this
        function, e.g.::

            void f(...) {
                ...
            }

            void __attribute__((alias("f"))) g;

        """

        return CClassicalAttribute("alias", [CStringLiteral(alias_name)])

    @classmethod
    def always_inline(cls) -> CAttribute:
        """ Create an `always_inline` attribute """
        return CClassicalAttribute("always_inline")


@dataclass
class CClassicalAttribute(CAttribute):
    """ A BiAst element represents C classical attribute """
    name: str
    arguments: Optional[List[CExpression]] = None


@dataclass
class CMacroAttribute(CAttribute, CMacro):
    """ A BiAst element represents C macro attribute """
    macro_name: str
    arguments: List[CBiAst] = field(default_factory=list)

    @classmethod
    def get_base_class(cls) -> SubType[CBiAst]:
        """ To get base class """
        return CAttribute


@dataclass
class CFunction(CBiAst):
    """ A BiAst element represents C function """
    name: str
    parameters: List[CParameterDeclaration]
    return_type: CType
    body: Optional[CCompoundStatement]
    inline: bool = False
    variable_length_argument: bool = False
    storage_qualifiers: Set[CStorageQualifier] = field(default_factory=set)
    attributes: List[CAttribute] = field(default_factory=list)

    @classmethod
    def of(cls, content: str) -> CFunction:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="function_definition")


@dataclass
class CDeclaration(CBiAst):
    """ A BiAst element represents C declaration """
    name: Optional[str]
    type: CType
    attributes: List[CAttribute] = field(default_factory=list, init=False)

    @classmethod
    def of(cls, content: str) -> CDeclaration:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="declaration")

    def get_ident(self) -> CIdentifierExpression:
        """ To get identifier of a declaration """
        if self.name is None:
            raise NameError(f"cannot get identifier of an empty declaration {self}")

        return CIdentifierExpression(self.name)


@dataclass
class CMacroDeclaration(CDeclaration, CMacro):
    """ A BiAst element represents C macro declaration """
    macro_name: str
    arguments: List[CBiAst]

    @classmethod
    def get_base_class(cls) -> SubType[CBiAst]:
        """ To get base class """
        return CDeclaration


@dataclass
class CTypeDeclaration(CDeclaration):
    """ A BiAst element represents C type declaration """


@dataclass
class CVariableDeclaration(CDeclaration):
    """ A BiAst element represents C variable declaration """
    initializer: Optional[CExpression] = None
    storage_qualifiers: Set[CStorageQualifier] = field(default_factory=set)


@dataclass
class CParameterDeclaration(CDeclaration):
    """ A BiAst element represents C parameter declaration """
    @classmethod
    def of(cls, content: str) -> CDeclaration:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="parameter_declaration")


@dataclass
class CMacroParameterDeclaration(CParameterDeclaration, CMacro):
    """ A BiAst element represents C macro parameter declaration """
    macro_name: str
    arguments: List[CBiAst]

    @classmethod
    def get_base_class(cls) -> SubType[CBiAst]:
        """ To get base class """
        return CParameterDeclaration


@dataclass
class CFieldDeclaration(CDeclaration):
    """ A BiAst element represents C field declaration """
    bitwidth: Optional[int] = None


@dataclass
class CMacroFieldDeclaration(CDeclaration, CMacro):
    """ A BiAst element represents C macro field declaration """
    macro_name: str
    arguments: List[CBiAst]
    bitwidth: Optional[int] = None

    @classmethod
    def get_base_class(cls) -> SubType[CBiAst]:
        """ To get base class """
        return CFieldDeclaration


class CStorageQualifier(Enum):
    """ Enum of C storage qualifiers """
    AUTO = "auto"
    REGISTER = "register"
    STATIC = "static"
    EXTERN = "extern"
    TYPEDEF = "typedef"


class CTypeQualifier(Enum):
    """ Enum of C type qualifiers """
    CONST = "const"
    VOLATILE = "volatile"


class CFunctionSpecifier(Enum):
    """ Enum of C function specifier """
    INLINE = "inline"


@dataclass
class CType(CBiAst):
    """ A BiAst element represents C type """
    qualifiers: Set[CTypeQualifier] = field(default_factory=set, init=False)

    @classmethod
    def of(cls, content: str) -> CType:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="type_name")

    def add_qualifier(self, qualifier: CTypeQualifier) -> CType:
        """ To add a qualifier """
        self.qualifiers.add(qualifier)
        return self

    def add_qualifiers(self, qualifiers: Iterable[CTypeQualifier]) -> CType:
        """ To add qualifiers """
        self.qualifiers.update(qualifiers)
        return self


@dataclass
class CTypeOf(CType):
    """ The class :class:`CTypeOf` corresponds to the GNU *typeof* extension. """
    operand: Union[CType, CExpression]


@dataclass
class CMacroType(CType, CMacro):
    """ A BiAst element represents C macro type """
    macro_name: str
    arguments: List[CBiAst]

    @classmethod
    def get_base_class(cls) -> SubType[CBiAst]:
        """ To get base class """
        return CType


@dataclass
class CAliasType(CType):
    """ A BiAst element represents C alias type """
    name: str


@dataclass
class CVoidType(CType):
    """ A BiAst element represents C void type """


@dataclass
class CBoolType(CType):
    """ A BiAst element represents C bool type """


class CSignDescriptor(Enum):
    """ Enum of C sign descriptors """
    SIGNED = 'signed'
    UNSIGNED = 'unsigned'


@dataclass
class CIntegerType(CType):
    """ A BiAst element represents C integer type """
    sign_desc: Optional[CSignDescriptor] = CSignDescriptor.SIGNED


@dataclass
class CCharType(CIntegerType):
    """ A BiAst element represents C char type """
    sign_desc: Optional[CSignDescriptor] = None


@dataclass
class CShortType(CIntegerType):
    """ A BiAst element represents C short type """


@dataclass
class CIntType(CIntegerType):
    """ A BiAst element represents C int type """


@dataclass
class CLongType(CIntegerType):
    """ A BiAst element represents C long type """


@dataclass
class CLonglongType(CIntegerType):
    """ A BiAst element represents C long long type """


@dataclass
class CFloatType(CType):
    """ A BiAst element represents C float type """


@dataclass
class CDoubleType(CType):
    """ A BiAst element represents C double type """


@dataclass
class CLongDoubleType(CType):
    """ A BiAst element represents C long double type """


@dataclass
class CPointerType(CType):
    """ A BiAst element represents C pointer type """
    base_type: CType

    @classmethod
    def create(cls, base_type: CType, level: int) -> CType:
        """ To create a pointer type according to its nested level """
        if level < 0:
            raise ValueError(f"cannot create negative-level pointer types")
        for _ in range(level):
            base_type = CPointerType(base_type)

        return base_type


@dataclass
class CArrayType(CType):
    """ A BiAst element represents C array type """
    base_type: CType
    capacity: Optional[CExpression]


@dataclass
class CStructType(CType):
    """ A BiAst element represents C struct type """
    name: Optional[str] = None
    field_decls: Optional[List[CFieldDeclaration]] = None
    attributes: List[CAttribute] = field(default_factory=list, init=False)


@dataclass
class CUnionType(CType):
    """ A BiAst element represents C union type """
    name: Optional[str] = None
    field_decls: Optional[List[CFieldDeclaration]] = None
    attributes: List[CAttribute] = field(default_factory=list, init=False)


@dataclass
class CEnumType(CType):
    """ A BiAst element represents C enum type """
    name: Optional[str] = None
    enum_items: Optional[List[CEnumItem]] = None
    attributes: List[CAttribute] = field(default_factory=list, init=False)


@dataclass
class CFunctionType(CType):
    """ A BiAst element represents C function type """
    parameter_decls: List[CParameterDeclaration]
    return_type: CType
    variable_length_argument: bool


@dataclass
class CMacroExpression(CExpression, CMacro):
    """ A BiAst element represents C macro expression """
    macro_name: str
    arguments: List[CBiAst] = field(default_factory=list)

    @classmethod
    def get_base_class(cls) -> SubType[CBiAst]:
        """ To get base class """
        return CExpression


class CUnaryOperator(Enum):
    """ Enum of C unary operators """
    POSITIVE = "+"
    NEGATE = '-'
    SELFINC = '++'
    SELFDEC = '--'
    BNOT = '~'
    LNOT = '!'
    SIZEOF = "sizeof"
    ADDRESS = '&'
    DEREFERENCE = '*'

    @property
    def precedence(self) -> int:
        """ Precedence of unary operators """
        return 2


class CPostUnaryOperator(Enum):
    """ Enum of C post unary operators """
    SELFINC = '++'
    SELFDEC = '--'

    @property
    def precedence(self) -> int:
        """ Precedence of post unary operators """
        return 1


class CBinaryOperator(Enum):
    """ Enum of C binary operators """
    ADD = '+'
    SUB = '-'
    MUL = '*'
    DIV = '/'
    MOD = '%'
    LSHIFT = '<<'
    RSHIFT = '>>'
    LE = '<='
    LT = '<'
    GE = '>='
    GT = '>'
    EQ = '=='
    NE = '!='
    BAND = '&'
    BOR = '|'
    XOR = '^'
    LAND = '&&'
    LOR = '||'

    @property
    def precedence(self) -> int:
        """ Precedence of binary operators """
        mapping: Dict[CBinaryOperator, int] = {
            CBinaryOperator.LOR: 12,
            CBinaryOperator.LAND: 11,
            CBinaryOperator.BOR: 10,
            CBinaryOperator.XOR: 9,
            CBinaryOperator.BAND: 8,
            CBinaryOperator.EQ: 7, CBinaryOperator.NE: 7,
            CBinaryOperator.LE: 6, CBinaryOperator.GE: 6,
            CBinaryOperator.LT: 6, CBinaryOperator.GT: 6,
            CBinaryOperator.LSHIFT: 5, CBinaryOperator.RSHIFT: 5,
            CBinaryOperator.ADD: 4, CBinaryOperator.SUB: 4,
            CBinaryOperator.MUL: 3, CBinaryOperator.DIV: 3, CBinaryOperator.MOD: 3,
        }

        rs = mapping.get(self)
        if rs is None:
            raise ValueError(f"{self} is an invalid C binary operator")
        return rs


@dataclass
class CUnaryExpression(CExpression):
    """ A BiAst element represents C unary expression """
    operator: Union[CUnaryOperator, CPostUnaryOperator]
    operand: CExpression

    @property
    def precedence(self) -> int:
        """ Precedence of unary operator in an unary expression """
        return self.operator.precedence


@dataclass
class CBinaryExpression(CExpression):
    """ A BiAst element represents C binary expression """
    left: CExpression
    operator: CBinaryOperator
    right: CExpression

    @property
    def precedence(self) -> int:
        """ Precedence of binary operator in a binary expression """
        return self.operator.precedence


@dataclass
class CIdentifierExpression(CExpression):
    """ A BiAst element represents C identifier expression """
    name: str


@dataclass
class CStringLiteral(CExpression):
    """ A BiAst element represents C string literal """
    content: str


class CAssignmentOperator(Enum):
    """ Enum of C assignment operators """
    ASSIGN = '='
    ADDASSIGN = '+='
    SUBASSIGN = '-='
    MUTASSIGN = '*='
    DIVASSIGN = '/='
    MODASSIGN = '%='
    RSHIFTASSIGN = '>>='
    LSHIFTASSIGN = '<<='
    BANDASSIGN = '&='
    BORASSIGN = '|='
    XORASSIGN = '^='


@dataclass
class CAssignmentExpression(CExpression):
    """ A BiAst element represents C assignment expression """
    lhs: CExpression
    operator: CAssignmentOperator
    rhs: CExpression

    @property
    def precedence(self) -> int:
        """ Precedence of assignment expression """
        return 14


@dataclass
class CSequenceExpression(CExpression):
    """ A BiAst element represents C sequence expression """
    sequence: List[CExpression]

    @property
    def precedence(self) -> int:
        """ Precedence of sequence expression """
        return 15


@dataclass
class CConditionalExpression(CExpression):
    """ A BiAst element represents C conditional expression """
    condition: CExpression
    consequent: CExpression
    alternative: CExpression

    @property
    def precedence(self) -> int:
        """ Precedence of conditional expression """
        return 13


@dataclass
class CCastExpression(CExpression):
    """ A BiAst element represents C cast expression """
    cast_type: CType
    cast_content: CExpression

    @property
    def precedence(self) -> int:
        """ Precedence of cast expression """
        return 2


@dataclass
class CElementExpression(CExpression):
    """ A BiAst element represents C get array element expression """
    array_object: CExpression
    index: CExpression


@dataclass
class CMemberExpression(CExpression):
    """ A BiAst element represents C get memeber expression """
    object: CExpression
    member: str


@dataclass
class CCallExpression(CExpression):
    """ A BiAst element represents C function call expression """
    callee: CExpression
    arguments: List[CExpression]


@dataclass
class CCompoundExpression(CExpression):
    """ A BiAst element represents C compound expression """
    compound: CCompoundStatement


@dataclass
class CDesignator(CBiAst):
    """ A BiAst element represents C designator """

    @classmethod
    def of(cls, content: str) -> CBiAst:
        """ A function to parse a block of C codes to C BiAst """
        return super().of(content)


@dataclass
class CIndexDesignator(CDesignator):
    """ A BiAst element represents C index designator """
    index: CExpression

    @classmethod
    def of(cls, content: str) -> CBiAst:
        """ A function to parse a block of C codes to C BiAst """
        return super().of(content)


@dataclass
class CRangeDesignator(CDesignator):
    """ Specifically used to describe the range
    initializer, e.g. ``int a [] = { [0 ... 1] = 2, [2] = 3 };``.
    """

    left: CExpression
    right: CExpression

    @classmethod
    def of(cls, content: str) -> CBiAst:
        """ A function to parse a block of C codes to C BiAst """
        return super().of(content)


@dataclass
class CMemberDesignator(CDesignator):
    """ A BiAst element represents C structure member designator """
    field_name: str

    @classmethod
    def of(cls, content: str) -> CBiAst:
        """ A function to parse a block of C codes to C BiAst """
        return super().of(content)


@dataclass
class CDesignation(CBiAst):
    """ Designation, including a list of designators (potentially empty),
    is a special way to initialize array elements or struct members. For
    example, ::

        int a[10] = { [1 .. 2] = 1, [5] = 2 };
                      ^^^^^^^^      ^^^
            a range designator      an index designator

    designator is also composable, e.g.::

        struct {
            int arr[10];
        } t = { .arr[0] = 1; };
                ^^^^^^^^
                [ member designator, index designator ]

    """
    designators: List[CDesignator] = field(default_factory=list)

    @classmethod
    def of(cls, content: str) -> CDesignator:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry='designation')


@dataclass
class CConstructorExpression(CExpression):
    """ initializer is None means the declarator was not initialized,
    initializer is empty means the declarator was initialized with defaults
    """
    items: List[Tuple[CDesignation, CExpression]] = field(default_factory=list)

    @classmethod
    def create(cls, *elems: Union[CExpression, Tuple[CDesignation, CExpression]]) -> \
            CConstructorExpression:
        """ To create a constructor expression with given elements """
        ret = CConstructorExpression()
        for elem in elems:
            if isinstance(elem, CExpression):
                ret.items.append((CDesignation(), elem))
            else:
                ret.items.append(elem)

        return ret

    @classmethod
    def of(cls, content: str) -> CExpression:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="initializer")


@dataclass
class CEnumItem(CBiAst):
    """ A BiAst element represents C enum item """
    name: Optional[str]
    value: Optional[CExpression]

    @classmethod
    def of(cls, content: str) -> CEnumItem:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="enumerator")


class CConstant(CExpression):
    """ A BiAst element represents C constant """

    def __bool__(self):
        raise NotImplementedError(f"__bool__ method not implemented for {type(self).__name__}")


class CIntegerBase(Enum):
    """ A BiAst element represents C integer constants base """
    BIN = 2
    OCT = 8
    DEC = 10
    HEX = 16


@dataclass
class CIntegerConstant(CConstant):
    """ A BiAst element represents C integer constant """

    class Suffix(Enum):
        """ suffix of integer constants """
        LONG = 'L'
        LONGLONG = 'LL'
        UNSIGNED = 'U'

    value: int
    base: CIntegerBase = field(default=CIntegerBase.DEC, compare=False)
    suffixes: Set[CIntegerConstant.Suffix] = field(default_factory=set)

    def __bool__(self):
        return self.value != 0


@dataclass
class CFloatConstant(CConstant):
    """ A BiAst element represents C float constant """

    class Suffix(Enum):
        """ Enum of float constant suffix """
        FLOAT = 'F'
        LONGDOUBLE = 'L'

    value: str
    # hexadecimal floating constant is not supported currently
    suffixes: Set[CFloatConstant.Suffix] = field(default_factory=set)

    def __bool__(self):
        return float(self.value) != 0


@dataclass
class CCharConstant(CConstant):
    """ A BiAst element represents C char constant """
    value: str

    def __bool__(self):
        return self.value != r"\0"


class CStatement(CBiAst):
    """ A BiAst element represents C statement """
    @classmethod
    def of(cls, content: str) -> CStatement:
        """ A function to parse a block of C codes to C BiAst """
        return parse(content, entry="statement")

    def rsvd_ast(self) -> CStatement:
        """ reserve a public interface """
        return self


CStatementOrDeclaration = Union[CStatement, CVariableDeclaration, CTypeDeclaration]


@dataclass
class CCompoundStatement(CStatement):
    """ A BiAst element represents C compound statement """
    body: List[CStatementOrDeclaration]


@dataclass
class CExpressionStatement(CStatement):
    """ A BiAst element represents C expression statement """
    expression: CExpression


@dataclass
class CLabelledStatement(CStatement):
    """ A BiAst element represents C labelled statement """
    label: str
    body: CStatement


@dataclass
class CNullStatement(CStatement):
    """ A BiAst element represents C null statement """


@dataclass
class CMacroStatement(CStatement, CMacro):
    """ A BiAst element represents C macro statement """
    macro_name: str
    arguments: List[CBiAst]

    @classmethod
    def get_base_class(cls) -> SubType[CBiAst]:
        """ To get base class """
        return CStatement


@dataclass
class CIfStatement(CStatement):
    """ A BiAst element represents C if else statement """
    condition: CExpression
    then_statement: CStatement
    else_statement: Optional[CStatement] = None


@dataclass
class CSwitchStatement(CStatement):
    """ A BiAst element represents C switch statement """
    controller: CExpression
    cases: List[Tuple[CExpression, List[CStatementOrDeclaration]]]
    default: Optional[List[CStatementOrDeclaration]]


@dataclass
class CForStatement(CStatement):
    """ A BiAst element represents C for statement """
    initializer: Optional[Union[CVariableDeclaration, CExpression]]
    condition: Optional[CExpression]
    increment: Optional[CExpression]
    body: CStatement


@dataclass
class CWhileStatement(CStatement):
    """ A BiAst element represents C while statement """
    condition: CExpression
    body: CStatement


@dataclass
class CDoWhileStatement(CStatement):
    """ A BiAst element represents C do while statement """
    body: CStatement
    condition: CExpression


@dataclass
class CAsmOperand(CBiAst):
    """ A BiAst element represents C asm operand """
    symbolic_name: Optional[str]
    constraint: str
    cexpr: CExpression

    @classmethod
    def of(cls, content: str) -> CBiAst:
        """ A function to parse a block of C codes to C BiAst """
        return super().of(content)


@dataclass
class CAsmStatement(CStatement):
    """ A BiAst element represents C asm statement """
    template: str
    output_operands: List[CAsmOperand]
    input_operands: List[CAsmOperand]
    clobbers: List[str]
    goto_labels: List[str]
    volatile: bool
    inline: bool


class CJumpStatement(CStatement):
    """ A BiAst element represents C jump statement """

    def rsvd_ast(self) -> CJumpStatement:
        """ reserve a public interface """
        return self


@dataclass
class CBreakStatement(CJumpStatement):
    """ A BiAst element represents C break statement """


@dataclass
class CContinueStatement(CJumpStatement):
    """ A BiAst element represents C continue statement """


@dataclass
class CGotoStatement(CJumpStatement):
    """ A BiAst element represents C goto statement """
    target: str


@dataclass
class CReturnStatement(CJumpStatement):
    """ A BiAst element represents C return statement """
    value: Optional[CExpression] = None


class CTypeSpecifier(Enum):
    """ Enum of C type specifiers """
    VOID = 'void'
    BOOL = '_Bool'
    CHAR = 'char'
    SHORT = 'short'
    INT = 'int'
    LONG = 'long'
    FLOAT = 'float'
    DOUBLE = 'double'
    SIGNED = 'signed'
    UNSIGNED = 'unsigned'


@dataclass
class CTypeDecorator:
    """ A BiAst element represents C type decorator """
    qualifiers: Set[CTypeQualifier]
    base_decorator: Optional[CTypeDecorator]

    def get_type(self, base_type: CType) -> CType:
        """ To get type of the decorator """
        if self.base_decorator is not None:
            return self.base_decorator.get_type(base_type)
        else:
            return base_type


@dataclass
class CPointerDecorator(CTypeDecorator):
    """ A BiAst element represents C pointer type decorator """
    def get_type(self, base_type: CType) -> CType:
        return super().get_type(
            CPointerType(base_type).add_qualifiers(self.qualifiers)
        )


@dataclass
class CArrayDecorator(CTypeDecorator):
    """ A BiAst element represents C array decorator """
    capacity: Optional[CExpression]

    def get_type(self, base_type: CType) -> CType:
        return super().get_type(
            CArrayType(base_type, self.capacity).add_qualifiers(self.qualifiers)
        )


@dataclass
class CFunctionDecorator(CTypeDecorator):
    """ A BiAst element represents C function decorator """
    parameters: List[CParameterDeclaration]
    variable_length_argument: bool
    return_ptr_level: int = 0

    def get_type(self, base_type: CType) -> CType:
        return super().get_type(CFunctionType(
            self.parameters,
            CPointerType.create(base_type, self.return_ptr_level),
            self.variable_length_argument
        ))


@dataclass
class CDeclarator:
    """ A BiAst element represents C declarator """
    name: Optional[str]
    decorator: Optional[CTypeDecorator] = None
    attributes: List[CAttribute] = field(default_factory=list, init=False)

    def get_type(self, specifier_qualifiers: list) -> CType:
        """ To get the complete type of a declarator """
        specifiers = []
        qualifiers: Set[CTypeQualifier] = set()
        complex_specifier: Optional[CType] = None

        for sq in specifier_qualifiers:
            if isinstance(sq, CTypeSpecifier):
                specifiers.append(sq)
            elif isinstance(sq, (CMacroType, CTypeOf, CStructType,
                                 CUnionType, CEnumType, CAliasType)):
                complex_specifier = sq
            elif isinstance(sq, CTypeQualifier):
                qualifiers.add(sq)
            elif not isinstance(sq, (CStorageQualifier, CFunctionSpecifier, CAttribute)):
                # attributes, storage qualifiers and function specifier have nothing to do
                # with the type of a declaration, just pass
                raise TypeError(f"unknown type specifier or qualifier {sq}")

        specified_type: CType
        if complex_specifier is None:
            specifier_set = frozenset(Counter(specifiers).items())
            # The following valid type-specifier-set follows the specification in
            # *Section 6.7.2, Type specifiers* in ISO/C1999.
            spc_var = specifier_type_mapping.get(specifier_set)
            if spc_var is not None:
                specified_type = deepcopy(spc_var)
            else:
                raise TypeError(f"invalid set of type specifiers: {specifiers}")
        else:
            specified_type = complex_specifier

        ret_type = specified_type
        ret_type.add_qualifiers(qualifiers)

        if self.decorator is not None:
            ret_type = self.decorator.get_type(ret_type)

        return ret_type


@dataclass
class CAbstractDeclarator(CDeclarator):
    """ A BiAst element represents C abstract declarator """
    name: Optional[str] = None


@dataclass
class CInitDeclarator(CDeclarator):
    """ A BiAst element represents C init declarator """
    initializer: Optional[CExpression] = None


@dataclass
class CFieldDeclarator(CDeclarator):
    """ A BiAst element represents C structure field declarator """
    bitwidth: Optional[CExpression] = None


@dataclass
class CCaseStatement(CStatement):
    """ A BiAst element represents C case statement """
    value: CExpression
    stmt: CStatement


@dataclass
class CDefaultCaseStatement(CStatement):
    """ A BiAst element represents C default case statement """
    stmt: CStatement


class CAsmQualifier(Enum):
    """ Enum of asm qualifiers """
    VOLATILE = "volatile"
    INLINE = "inline"
    GOTO = "goto"


# _Complex and _Imaginary left unimplemented
specifier_type_mapping = {
    # void
    frozenset(Counter([CTypeSpecifier.VOID]).items()):
        CVoidType(),

    # char
    frozenset(Counter([CTypeSpecifier.CHAR]).items()):
        CCharType(sign_desc=None),

    # signed char
    frozenset(Counter([CTypeSpecifier.SIGNED, CTypeSpecifier.CHAR]).items()):
        CCharType(sign_desc=CSignDescriptor.SIGNED),

    # unsigned char
    frozenset(Counter([CTypeSpecifier.UNSIGNED, CTypeSpecifier.CHAR]).items()):
        CCharType(sign_desc=CSignDescriptor.UNSIGNED),

    # short, signed short, short int, signed short int
    frozenset(Counter([CTypeSpecifier.SHORT]).items()):
        CShortType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.SHORT, CTypeSpecifier.INT]).items()):
        CShortType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.SIGNED, CTypeSpecifier.SHORT]).items()):
        CShortType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.SIGNED,
                       CTypeSpecifier.SHORT, CTypeSpecifier.INT]).items()):
        CShortType(sign_desc=CSignDescriptor.SIGNED),

    # unsigned short, unsigned short int
    frozenset(Counter([CTypeSpecifier.UNSIGNED, CTypeSpecifier.SHORT]).items()):
        CShortType(sign_desc=CSignDescriptor.UNSIGNED),
    frozenset(Counter([CTypeSpecifier.UNSIGNED,
                       CTypeSpecifier.SHORT, CTypeSpecifier.INT]).items()):
        CShortType(sign_desc=CSignDescriptor.UNSIGNED),

    # int, signed, signed int
    frozenset(Counter([CTypeSpecifier.INT]).items()):
        CIntType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.SIGNED]).items()):
        CIntType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.SIGNED, CTypeSpecifier.INT]).items()):
        CIntType(sign_desc=CSignDescriptor.SIGNED),

    # unsigned, unsigned int
    frozenset(Counter([CTypeSpecifier.UNSIGNED]).items()):
        CIntType(sign_desc=CSignDescriptor.UNSIGNED),
    frozenset(Counter([CTypeSpecifier.UNSIGNED, CTypeSpecifier.INT]).items()):
        CIntType(sign_desc=CSignDescriptor.UNSIGNED),

    # long, signed long, long int, signed long int
    frozenset(Counter([CTypeSpecifier.LONG]).items()):
        CLongType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.LONG, CTypeSpecifier.INT]).items()):
        CLongType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.SIGNED, CTypeSpecifier.LONG]).items()):
        CLongType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.SIGNED,
                       CTypeSpecifier.LONG, CTypeSpecifier.INT]).items()):
        CLongType(sign_desc=CSignDescriptor.SIGNED),

    # unsigned long, unsigned long int
    frozenset(Counter([CTypeSpecifier.UNSIGNED, CTypeSpecifier.LONG]).items()):
        CLongType(sign_desc=CSignDescriptor.UNSIGNED),
    frozenset(Counter([CTypeSpecifier.UNSIGNED,
                       CTypeSpecifier.LONG, CTypeSpecifier.INT]).items()):
        CLongType(sign_desc=CSignDescriptor.UNSIGNED),

    # long long, signed long long, long long int, signed long long int
    frozenset(Counter([CTypeSpecifier.LONG, CTypeSpecifier.LONG]).items()):
        CLonglongType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.LONG, CTypeSpecifier.LONG, CTypeSpecifier.INT]).items()):
        CLonglongType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.SIGNED,
                       CTypeSpecifier.LONG, CTypeSpecifier.LONG]).items()):
        CLonglongType(sign_desc=CSignDescriptor.SIGNED),
    frozenset(Counter([CTypeSpecifier.SIGNED,
                       CTypeSpecifier.LONG,
                       CTypeSpecifier.LONG,
                       CTypeSpecifier.INT]).items()):
        CLonglongType(sign_desc=CSignDescriptor.SIGNED),

    # unsigned long long, unsigned long long int
    frozenset(Counter([CTypeSpecifier.UNSIGNED,
                       CTypeSpecifier.LONG, CTypeSpecifier.LONG]).items()):
        CLonglongType(sign_desc=CSignDescriptor.UNSIGNED),
    frozenset(Counter([CTypeSpecifier.UNSIGNED,
                       CTypeSpecifier.LONG,
                       CTypeSpecifier.LONG,
                       CTypeSpecifier.INT]).items()):
        CLonglongType(sign_desc=CSignDescriptor.UNSIGNED),

    # float
    frozenset(Counter([CTypeSpecifier.FLOAT]).items()):
        CFloatType(),

    # double
    frozenset(Counter([CTypeSpecifier.DOUBLE]).items()):
        CDoubleType(),

    # long double
    frozenset(Counter([CTypeSpecifier.LONG, CTypeSpecifier.DOUBLE]).items()):
        CLongDoubleType(),

    # _Bool
    frozenset(Counter([CTypeSpecifier.BOOL]).items()):
        CBoolType(),
}


class CTransformer(Transformer):
    """ A C BiAst transformer """

    # commonly used helper rules
    @staticmethod
    @v_args(inline=True)
    def pass_as_single(item):
        """ A transform handler to deal with corresponding grammar rule"""
        return item

    @staticmethod
    def pass_as_none(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return None

    @staticmethod
    def pass_as_list(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return args

    @staticmethod
    def pass_as_flatlist(args):
        """ A transform handler to deal with corresponding grammar rule"""
        ret = []
        for a in args:
            if isinstance(a, list):
                ret += a
            else:
                ret.append(a)

        return ret

    @staticmethod
    def __get_storage_qualifiers(items) -> Set[CStorageQualifier]:
        """ A transform handler to deal with corresponding grammar rule"""
        ret = set()
        for item in items:
            if isinstance(item, CStorageQualifier):
                ret.add(item)

        return ret

    @staticmethod
    def __get_attributes(*args) -> List[CAttribute]:
        attributes: List[CAttribute] = []
        for arg in args:
            attributes += list(attr for attr in arg if isinstance(attr, CAttribute))

        return attributes

    # rules of C declarations
    def init_declarator(self, args):
        """ A transform handler to deal with corresponding grammar rule"""
        ret = CInitDeclarator(args[0].name, args[0].decorator)
        ret.attributes = args[0].attributes

        if len(args) > 2:
            ret.initializer = args[2]
            ret.attributes = self.__get_attributes(args[0].attributes, args[3] or [])

        return ret

    @staticmethod
    @v_args(inline=True)
    def initializer(designated_initializers_opt):
        """ A transform handler to deal with corresponding grammar rule"""
        return designated_initializers_opt or CConstructorExpression([])

    @staticmethod
    @v_args(inline=True)
    def designated_initializer(designation_opt: Optional[CDesignation], expr: CExpression):
        """ A transform handler to deal with corresponding grammar rule"""
        return (designation_opt or CDesignation(), expr)

    @staticmethod
    def designated_initializers(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CConstructorExpression(args)

    @staticmethod
    def designation(designators: List[CDesignator]):
        """ A transform handler to deal with corresponding grammar rule"""
        return CDesignation(designators)

    @staticmethod
    @v_args(inline=True)
    def range_designator(index: CExpression, end_index_opt: Optional[CExpression]):
        """ A transform handler to deal with corresponding grammar rule"""
        if end_index_opt is None:
            return CIndexDesignator(index)
        else:
            return CRangeDesignator(index, end_index_opt)

    @staticmethod
    @v_args(inline=True)
    def member_designator(field_name):
        """ A transform handler to deal with corresponding grammar rule"""
        return CMemberDesignator(str(field_name))

    @staticmethod
    @v_args(inline=True)
    def macro_declaration(macro_name, arguments_opt) -> List[CDeclaration]:
        """ A transform handler to deal with corresponding grammar rule"""
        return [CMacroDeclaration(
            name=None,
            type=CType(),
            macro_name=str(macro_name)[1:-5],
            arguments=arguments_opt or [])]

    @v_args(inline=True)
    def declaration(self, specifiers, declarators_opt) -> List[CDeclaration]:
        """ A transform handler to deal with corresponding grammar rule"""
        if declarators_opt is None and CStorageQualifier.TYPEDEF in specifiers:
            raise NotImplementedError(f"Anonymous type alias is not supported currently.")
        elif declarators_opt is None:
            # According to Section 6.7 in C99, a declaration declares no declarators
            # iff. it is a function parameter, a struct, an union, etc.
            declarator = CAbstractDeclarator()
            decl = CVariableDeclaration(
                name=None,
                type=declarator.get_type(specifiers),
                storage_qualifiers=self.__get_storage_qualifiers(specifiers)
            )
            decl.attributes = self.__get_attributes(specifiers, declarator.attributes)
            return [decl]
        elif CStorageQualifier.TYPEDEF in specifiers:
            specifiers.remove(CStorageQualifier.TYPEDEF)
            type_decls: List[CDeclaration] = []
            for type_declarator in declarators_opt:
                type_decl = CTypeDeclaration(
                    name=type_declarator.name,
                    type=type_declarator.get_type(specifiers)
                )
                type_decl.attributes = self.__get_attributes(specifiers, type_declarator.attributes)
                type_decls.append(type_decl)
            return type_decls
        else:
            var_decls: List[CDeclaration] = []
            for var_declarator in declarators_opt:
                var_decl = CVariableDeclaration(
                    name=var_declarator.name,
                    type=var_declarator.get_type(specifiers),
                    initializer=var_declarator.initializer,
                    storage_qualifiers=self.__get_storage_qualifiers(specifiers)
                )
                var_decl.attributes = self.__get_attributes(specifiers, var_declarator.attributes)
                var_decls.append(var_decl)
            return var_decls

    @staticmethod
    def __merge_parameters(
        parameters: List[Union[CParameterDeclaration, CMacroParameterDeclaration]],
        supplements: Dict[str, CVariableDeclaration]) -> \
            List[CParameterDeclaration]:

        for param in parameters:
            if isinstance(param, CMacroParameterDeclaration) and supplements:
                raise AttributeError(f"cannot match macro parameter to parameter declarations")

            if not isinstance(param, CMacroParameterDeclaration) and param.name is not None:
                continue

            if not isinstance(param, CMacroParameterDeclaration) and \
                    isinstance(param.type, CAliasType):
                # In a function definition, a parameter must has its name. Hence here
                # the type alias should be treated as its name.
                param.name = param.type.name

                # search for the real type
                if param.name in supplements:
                    param.type = supplements[param.name].type
                    del supplements[param.name]
                else:
                    raise KeyError(f"parameter type of {param.name} not found")
            elif not isinstance(param, CMacroParameterDeclaration):
                raise AttributeError(f"parameter name omited")
            else:
                continue

        if len(supplements) != 0:
            raise ValueError(f"parameter names of {supplements} are missing")

        return parameters

    def function_definition(self, args) -> CFunction:
        """ A transform handler to deal with corresponding grammar rule"""
        rettype_specifiers, declarator, supplement_decls, body, attributes = args
        if not isinstance(declarator.decorator, CFunctionDecorator):
            raise TypeError(f"{declarator} does not declare any function")

        func_type = declarator.get_type(rettype_specifiers)
        return_type = func_type.return_type.add_qualifiers(func_type.qualifiers)
        orig_parameters = declarator.decorator.parameters
        supplements: Dict[str, CVariableDeclaration] = {} \
            if supplement_decls is None else {decl.name: decl for decl in chain(*supplement_decls)}

        parameters = self.__merge_parameters(orig_parameters, supplements)
        variable_length_argument = declarator.decorator.variable_length_argument

        rs = CFunction(
            name=declarator.name,
            parameters=parameters,
            variable_length_argument=variable_length_argument,
            return_type=return_type,
            body=body if body.body != [] else None,
            inline=CFunctionSpecifier.INLINE in rettype_specifiers,
            storage_qualifiers=self.__get_storage_qualifiers(rettype_specifiers)
        )
        rs.attributes = self.__get_attributes(
            rettype_specifiers, declarator.attributes, attributes or []
        )

        return rs

    @staticmethod
    @v_args(inline=True)
    def declaration_specifiers(specifier, specifiers):
        """ A transform handler to deal with corresponding grammar rule"""
        if not isinstance(specifier, list):
            specifier = [specifier]

        return specifier + (specifiers or [])

    @staticmethod
    @v_args(inline=True)
    def storage_class_specifier(name):
        """ A transform handler to deal with corresponding grammar rule"""
        return CStorageQualifier(str(name))

    @staticmethod
    def type_name(args):
        """ A transform handler to deal with corresponding grammar rule"""
        declarator = CAbstractDeclarator() if args[1] is None else args[1]
        return declarator.get_type(args[0])

    @staticmethod
    def direct_type_specifier(args):
        """ This rule transforms only primitive type specifiers. """
        if len(args) != 1:
            raise ValueError('Unexpected number of type specifiers')
        return CTypeSpecifier(str(args[0]))

    @staticmethod
    @v_args(inline=True)
    def specifier_qualifiers(fst, rest):
        """ A transform handler to deal with corresponding grammar rule"""
        return [fst] + (rest or [])

    @staticmethod
    @v_args(inline=True)
    def type_alias_specifier(name):
        """ A transform handler to deal with corresponding grammar rule"""
        return CAliasType(str(name))

    @staticmethod
    @v_args(inline=True)
    def typeof_specifier(expr_or_type):
        """ A transform handler to deal with corresponding grammar rule"""
        return CTypeOf(expr_or_type)

    @staticmethod
    def type_qualifier(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CTypeQualifier(str(args[0]))

    @v_args(inline=True)
    def named_struct_specifier(self, _, attributes, name, fields, attributes_end):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = CStructType(name=str(name), field_decls=fields)
        rs.attributes = self.__get_attributes(attributes or [], attributes_end or [])
        return rs

    @v_args(inline=True)
    def anonymous_struct_specifier(self, _, attributes, fields, attributes_end):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = CStructType(name=None, field_decls=fields)
        rs.attributes = self.__get_attributes(attributes or [], attributes_end or [])
        return rs

    @v_args(inline=True)
    def named_union_specifier(self, _, attributes, name, fields, attributes_end):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = CUnionType(name=str(name), field_decls=fields)
        rs.attributes = self.__get_attributes(attributes or [], attributes_end or [])
        return rs

    @v_args(inline=True)
    def anonymous_union_specifier(self, _, attributes, fields, attributes_end):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = CUnionType(name=None, field_decls=fields)
        rs.attributes = self.__get_attributes(attributes or [], attributes_end or [])
        return rs

    @v_args(inline=True)
    def named_enum_specifier(self, _, attributes, name, fields, attributes_end):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = CEnumType(name=str(name), enum_items=fields)
        rs.attributes = self.__get_attributes(attributes or [], attributes_end or [])
        return rs

    @v_args(inline=True)
    def anonymous_enum_specifier(self, _, attributes, fields, attributes_end):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = CEnumType(name=None, enum_items=fields)
        rs.attributes = self.__get_attributes(attributes or [], attributes_end or [])
        return rs

    @staticmethod
    @v_args(inline=True)
    def type_macro_specifier(macro_name, arguments_opt):
        """ A transform handler to deal with corresponding grammar rule"""
        return CMacroType(str(macro_name)[1:-5], arguments_opt or [])

    @staticmethod
    def function_specifier(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CFunctionSpecifier(str(args[0]))

    def parameter_declaration(self, args):
        """ A transform handler to deal with corresponding grammar rule"""
        declarator = args[1] or CAbstractDeclarator()
        rs = CParameterDeclaration(
            name=declarator.name,
            type=declarator.get_type(args[0] or []),
        )
        rs.attributes = self.__get_attributes(args[0] or [], declarator.attributes)
        return rs

    @staticmethod
    @v_args(inline=True)
    def macro_parameter(macro_name, arguments_opt):
        """ A transform handler to deal with corresponding grammar rule"""
        return CMacroParameterDeclaration(
            name=None,
            type=CType(),
            macro_name=str(macro_name)[1:-5],
            arguments=arguments_opt or [])

    @staticmethod
    def empty_parameter_declarations(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return [], True

    @staticmethod
    def parameter_declarations(args):
        """ A transform handler to deal with corresponding grammar rule"""
        vla = args.pop() is not None
        return args, vla

    @staticmethod
    def unamed_struct_union_field(args):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = CFieldDeclaration(None, args[0], None)
        rs.attributes = args[0].attributes
        return [rs]

    @staticmethod
    @v_args(inline=True)
    def macro_field(macro_name, arguments_opt) -> List[CDeclaration]:
        """ A transform handler to deal with corresponding grammar rule"""
        return [CMacroFieldDeclaration(
            name=None,
            type=CType(),
            macro_name=str(macro_name)[1:-5],
            arguments=arguments_opt or [],
            bitwidth=None)]

    def field_declaration(self, args):
        """ A transform handler to deal with corresponding grammar rule"""
        decls = []
        for fdeclarator in args[1]:
            decl = CFieldDeclaration(
                name=fdeclarator.name,
                type=fdeclarator.get_type(args[0] or []),
                bitwidth=fdeclarator.bitwidth
            )
            decl.attributes = self.__get_attributes(args[0] or [], fdeclarator.attributes)
            decls.append(decl)

        return decls

    @staticmethod
    def field_declarations(args):
        """ A transform handler to deal with corresponding grammar rule"""
        fields = list(arg for arg in args if arg is not None)
        return list(chain(*fields))

    @staticmethod
    def named_field_declarator(args):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = CFieldDeclarator(args[0].name, args[0].decorator, args[1])
        rs.attributes = args[0].attributes
        return rs

    @staticmethod
    def anonymous_bit_field_declarator(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CFieldDeclarator(name=None, bitwidth=args[0])

    @staticmethod
    @v_args(inline=True)
    def bitfield_descriptor(width):
        """ A transform handler to deal with corresponding grammar rule"""
        return width

    def declarator(self, args):
        """ A transform handler to deal with corresponding grammar rule"""
        if args[0] is not None:
            for pointer_qualifiers in reversed(args[0]):
                if isinstance(args[2].decorator, CFunctionDecorator):
                    args[2].decorator.return_ptr_level += 1
                else:
                    args[2].decorator = CPointerDecorator(
                        qualifiers=set(pointer_qualifiers),
                        base_decorator=args[2].decorator
                    )

        args[2].attributes = self.__get_attributes(args[1] or [], args[2].attributes, args[3] or [])

        return args[2]

    def pointer_abstract_declarator(self, args):
        """ A transform handler to deal with corresponding grammar rule"""
        declarator = CAbstractDeclarator()
        for pointer_qualifiers in reversed(args[0]):
            declarator.decorator = CPointerDecorator(
                qualifiers=set(pointer_qualifiers),
                base_decorator=declarator.decorator
            )

        declarator.attributes = self.__get_attributes(declarator.attributes, args[1] or [])

        return declarator

    def pointer_complex_abstract_declarator(self, args):
        """ A transform handler to deal with corresponding grammar rule"""
        if args[0] is not None:
            for pointer_qualifiers in reversed(args[0]):
                args[2].decorator = CPointerDecorator(
                    qualifiers=set(pointer_qualifiers),
                    base_decorator=args[2].decorator
                )

        args[2].attributes = self.__get_attributes(args[1] or [], args[2].attributes, args[3] or [])

        return args[2]

    @staticmethod
    @v_args(inline=True)
    def array_abstract_declarator(declarator_opt, capacity):
        """ A transform handler to deal with corresponding grammar rule"""
        declarator = declarator_opt or CAbstractDeclarator()
        declarator.decorator = CArrayDecorator(
            qualifiers={},
            capacity=capacity,
            base_decorator=declarator_opt.decorator if declarator_opt else None
        )
        return declarator

    @staticmethod
    @v_args(inline=True)
    def function_abstract_declarator(declarator_opt, params_pair):
        """ A transform handler to deal with corresponding grammar rule"""
        parameters, vla = params_pair
        declarator = declarator_opt or CAbstractDeclarator()

        if len(parameters) == 0:
            vla = True
        elif parameters == [CParameterDeclaration(None, CVoidType())]:
            vla = False
            parameters = []

        declarator.decorator = CFunctionDecorator(
            qualifiers={},
            parameters=parameters,
            base_decorator=declarator_opt.decorator if declarator_opt else None,
            variable_length_argument=vla
        )
        return declarator

    @staticmethod
    def named_declarator(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CDeclarator(name=str(args[0]))

    @staticmethod
    def pointer_descriptor(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return args[1:]

    @staticmethod
    @v_args(inline=True)
    def named_enum_item(name):
        """ A transform handler to deal with corresponding grammar rule"""
        return CEnumItem(name=str(name), value=None)

    @staticmethod
    @v_args(inline=True)
    def assigned_enum_item(name, _, value):
        """ A transform handler to deal with corresponding grammar rule"""
        return CEnumItem(name=str(name), value=value)

    @staticmethod
    @v_args(inline=True)
    def array_declarator(direct_declarator, capacity_opt):
        """ A transform handler to deal with corresponding grammar rule"""
        direct_declarator.decorator = CArrayDecorator(
            qualifiers={},
            capacity=capacity_opt,
            base_decorator=direct_declarator.decorator
        )

        return direct_declarator

    @staticmethod
    @v_args(inline=True)
    def function_declarator(direct_declarator, param_pair):
        """ A transform handler to deal with corresponding grammar rule"""
        parameters, vla = param_pair

        if len(parameters) == 0:
            vla = True
        elif parameters == [CParameterDeclaration(None, CVoidType())]:
            vla = False
            parameters = []

        direct_declarator.decorator = CFunctionDecorator(
            qualifiers={},
            parameters=parameters,
            base_decorator=direct_declarator.decorator,
            variable_length_argument=vla
        )
        return direct_declarator

    # rules of c expressions
    @staticmethod
    @v_args(inline=True)
    def integer_constant(literal):
        """ A transform handler to deal with corresponding grammar rule"""
        return literal

    @staticmethod
    def extract_integer(content: str, base: CIntegerBase):
        """ A transform handler to deal with corresponding grammar rule"""
        content = content.lower()
        suffixes = set()

        while content[-1] in ('u', 'l'):
            if content.endswith('u'):
                content = content[:-1]
                suffixes.add(CIntegerConstant.Suffix.UNSIGNED)
            elif content.endswith('ll'):
                content = content[:-2]
                suffixes.add(CIntegerConstant.Suffix.LONGLONG)
            elif content.endswith('l'):
                content = content[:-1]
                suffixes.add(CIntegerConstant.Suffix.LONG)

        if content == '0':
            # 0 is parsed as a oct integer constant
            base = CIntegerBase.DEC

        return CIntegerConstant(int(content, base.value), base, suffixes)

    @v_args(inline=True)
    def decimal_literal(self, literal):
        """ A transform handler to deal with corresponding grammar rule"""
        return self.extract_integer(str(literal), CIntegerBase.DEC)

    @v_args(inline=True)
    def octal_literal(self, literal):
        """ A transform handler to deal with corresponding grammar rule"""
        return self.extract_integer(str(literal), CIntegerBase.OCT)

    @v_args(inline=True)
    def hexadecimal_literal(self, literal):
        """ A transform handler to deal with corresponding grammar rule"""
        return self.extract_integer(str(literal), CIntegerBase.HEX)

    @v_args(inline=True)
    def binary_literal(self, literal):
        """ A transform handler to deal with corresponding grammar rule"""
        return self.extract_integer(str(literal), CIntegerBase.BIN)

    @staticmethod
    @v_args(inline=True)
    def char_constant(literal):
        """ A transform handler to deal with corresponding grammar rule"""
        return CCharConstant(literal[1:-1])

    @staticmethod
    def extract_float(content: str):
        """ A transform handler to deal with corresponding grammar rule"""
        content = content.lower()
        suffixes = set()

        if content.endswith('f'):
            content = content[:-1]
            suffixes.add(CFloatConstant.Suffix.FLOAT)
        elif content.endswith('l'):
            content = content[:-1]
            suffixes.add(CFloatConstant.Suffix.LONGDOUBLE)

        return CFloatConstant(str(content), suffixes)

    @v_args(inline=True)
    def floating_constant(self, literal):
        """ A transform handler to deal with corresponding grammar rule"""
        return self.extract_float(str(literal))

    @staticmethod
    @v_args(inline=True)
    def unary_expression(opr: Token, expr: CExpression) -> CUnaryExpression:
        """ A transform handler to deal with corresponding grammar rule"""
        return CUnaryExpression(CUnaryOperator(str(opr)), expr)

    @staticmethod
    @v_args(inline=True)
    def postfix_unary_expression(expr: CExpression, opr: Token) -> CUnaryExpression:
        """ A transform handler to deal with corresponding grammar rule"""
        return CUnaryExpression(CPostUnaryOperator(str(opr)), expr)

    @staticmethod
    def object_member(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CMemberExpression(args[0], args[1])

    @staticmethod
    def pointer_object_member(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CMemberExpression(CUnaryExpression(CUnaryOperator.DEREFERENCE, args[0]), args[1])

    @staticmethod
    def array_reference(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CElementExpression(args[0], args[1])

    @staticmethod
    @v_args(inline=True)
    def macro_call(macro: Token, args_opt: Optional[List[CBiAst]]):
        """ A transform handler to deal with corresponding grammar rule"""
        return CMacroExpression(str(macro)[1:-5], args_opt or [])

    @staticmethod
    def __is_typename(name: str) -> bool:
        if name.startswith('uint') and name.endswith('_t'):
            return True
        elif name.startswith('int') and name.endswith('_t'):
            return True

        return False

    @v_args(inline=True)
    def function_call(self, callee: CExpression, args_opt: Optional[List[CExpression]]) \
            -> Union[CCastExpression, CCallExpression]:
        """ A transform handler to deal with corresponding grammar rule"""
        if args_opt is not None and len(args_opt) == 1 and \
                isinstance(callee, CIdentifierExpression) and self.__is_typename(callee.name):
            return CCastExpression(CAliasType(callee.name), args_opt[0])

        return CCallExpression(callee, args_opt or [])

    @staticmethod
    @v_args(inline=True)
    def compound_literal(typ: CType, constructor: CConstructorExpression) -> \
            CCastExpression:
        """ A transform handler to deal with corresponding grammar rule"""
        return CCastExpression(typ, constructor)

    @staticmethod
    def cast_expression(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CCastExpression(args[0], args[1])

    @staticmethod
    @v_args(inline=True)
    def binary_expression(left, opr, right):
        """ A transform handler to deal with corresponding grammar rule"""
        return CBinaryExpression(left, CBinaryOperator(str(opr)), right)

    @staticmethod
    def identifier_expression(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CIdentifierExpression(str(args[0]))

    @staticmethod
    def strings(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CStringLiteral(args[0])

    @staticmethod
    def string_literal(args):
        """ A transform handler to deal with corresponding grammar rule"""
        content = ""
        for arg in args:
            content += str(arg[1:-1])
        return content

    @staticmethod
    def conditional_expression(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CConditionalExpression(args[0], args[2], args[3])

    @staticmethod
    def assignment_operator(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CAssignmentOperator(str(args[0]))

    @staticmethod
    @v_args(inline=True)
    def builtin_expression(callee, parameters):
        """ A transform handler to deal with corresponding grammar rule"""
        return CMacroExpression(callee, parameters)

    @staticmethod
    def assignment_expression(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return CAssignmentExpression(args[0], args[1], args[2])

    @staticmethod
    @v_args(inline=True)
    def compound_expression(compound):
        """ A transform handler to deal with corresponding grammar rule"""
        return CCompoundExpression(compound)

    @staticmethod
    @v_args(inline=True)
    def sequence_expression(head: CExpression, tail: CExpression) -> CSequenceExpression:
        """ A transform handler to deal with corresponding grammar rule"""
        if isinstance(head, CSequenceExpression):
            head.sequence.append(tail)
            return head

        return CSequenceExpression([head, tail])

    # rules of c statements
    @staticmethod
    @v_args(inline=True)
    def expression_statement(expr: CExpression) -> CStatement:
        """ A transform handler to deal with corresponding grammar rule"""
        return CExpressionStatement(expr)

    @staticmethod
    @v_args(inline=True)
    def labelled_statement(label, stmt):
        """ A transform handler to deal with corresponding grammar rule"""
        return CLabelledStatement(str(label), stmt)

    @staticmethod
    @v_args(inline=True)
    def macro_statement(name: Token, args_opt: Optional[List[CBiAst]]):
        """ A transform handler to deal with corresponding grammar rule"""
        return CMacroStatement(str(name)[1:-5], args_opt or [])

    @staticmethod
    def compound_statement(stmt_decls):
        """ A transform handler to deal with corresponding grammar rule"""
        compound = CCompoundStatement([])
        for item in stmt_decls:
            if isinstance(item, list):
                compound.body += item
            else:
                compound.body.append(item)

        return compound

    @staticmethod
    @v_args(inline=True)
    def if_statement(condition, then_statement, else_statement=None):
        """ A transform handler to deal with corresponding grammar rule"""
        return CIfStatement(condition, then_statement, else_statement)

    @staticmethod
    @v_args(inline=True)
    def non_default_case_statement(case_value):
        """ A transform handler to deal with corresponding grammar rule"""
        return CCaseStatement(case_value, [])

    @staticmethod
    def default_case_statement(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return CDefaultCaseStatement([])

    @staticmethod
    @v_args(inline=True)
    def switch_statement(controller, body):
        """ A transform handler to deal with corresponding grammar rule"""
        labelled_statements = []
        for item in body:
            if isinstance(item, CCaseStatement):
                labelled_statements.append((item.value, item.stmt))
            elif isinstance(item, CDefaultCaseStatement):
                labelled_statements.append((None, item.stmt))
            elif len(labelled_statements) == 0:
                raise ValueError(f"statement {item} will never be executed")
            else:
                labelled_statements[-1][1].append(item)

        cases = []
        default = None
        for (val, stmts) in labelled_statements:
            if val is not None:
                cases.append((val, stmts))
            else:
                default = stmts

        return CSwitchStatement(controller, cases, default)

    @staticmethod
    @v_args(inline=True)
    def for_statement(initializer, condition, incrementor, body):
        """ A transform handler to deal with corresponding grammar rule"""
        return CForStatement(initializer, condition, incrementor, body)

    @staticmethod
    @v_args(inline=True)
    def for_statement_decl(declaration, condition, incrementor, body):
        """ A transform handler to deal with corresponding grammar rule"""
        return CForStatement(declaration, condition, incrementor, body)

    @staticmethod
    @v_args(inline=True)
    def while_statement(condition, body):
        """ A transform handler to deal with corresponding grammar rule"""
        return CWhileStatement(condition, body)

    @staticmethod
    @v_args(inline=True)
    def do_while_statement(body, condition):
        """ A transform handler to deal with corresponding grammar rule"""
        return CDoWhileStatement(body, condition)

    @staticmethod
    def null_statement(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return CNullStatement()

    @staticmethod
    @v_args(inline=True)
    def return_statement(value):
        """ A transform handler to deal with corresponding grammar rule"""
        return CReturnStatement(value)

    @staticmethod
    def continue_statement(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return CContinueStatement()

    @staticmethod
    def break_statement(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return CBreakStatement()

    @staticmethod
    @v_args(inline=True)
    def goto_statement(target):
        """ A transform handler to deal with corresponding grammar rule"""
        return CGotoStatement(str(target))

    @staticmethod
    def asm_statement(args):
        """ A transform handler to deal with corresponding grammar rule"""
        args = args[1:]
        qualifiers = args[0]
        template = str(args[1])
        output_operands = [] if len(args) <= 2 else args[2]
        input_operands = [] if len(args) <= 3 else args[3]
        clobbers = [] if len(args) <= 4 else args[4]
        gotolabels = [] if len(args) <= 5 else args[5]

        return CAsmStatement(
            str(template),
            output_operands,
            input_operands,
            clobbers,
            gotolabels,
            CAsmQualifier.VOLATILE in qualifiers,
            CAsmQualifier.INLINE in qualifiers,
        )

    @staticmethod
    @v_args(inline=True)
    def asm_operand(symbolic_name_opt, constraint, cexpr) -> CAsmOperand:
        """ A transform handler to deal with corresponding grammar rule"""
        return CAsmOperand(
            str(symbolic_name_opt) if symbolic_name_opt is not None else None,
            str(constraint),
            cexpr
        )

    @staticmethod
    def asm_clobbers(clobbers):
        """ A transform handler to deal with corresponding grammar rule"""
        return list(str(clobber) for clobber in clobbers)

    @staticmethod
    def asm_volatile_qualifier(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return CAsmQualifier.VOLATILE

    @staticmethod
    def asm_gotolabels(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return list(str(label) for label in args)

    @staticmethod
    def asm_goto_qualifier(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return CAsmQualifier.GOTO

    @staticmethod
    def asm_inline_qualifier(_):
        """ A transform handler to deal with corresponding grammar rule"""
        return CAsmQualifier.INLINE

    # rules of c attributes
    @staticmethod
    def attribute_specifiers(args):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = []
        for arg in args:
            if isinstance(arg, CMacroAttribute):
                rs.append(arg)
            else:
                rs += arg

        return rs

    @staticmethod
    @v_args(inline=True)
    def attribute_specifier(_, attributes_opt):
        """ A transform handler to deal with corresponding grammar rule"""
        return attributes_opt

    @staticmethod
    @v_args(inline=True)
    def macro_attribute(macro_name, arguments_opt):
        """ A transform handler to deal with corresponding grammar rule"""
        return CMacroAttribute(macro_name=str(macro_name)[1:-5],
                               arguments=arguments_opt or [])

    @staticmethod
    def attributes(args):
        """ A transform handler to deal with corresponding grammar rule"""
        return list(arg for arg in args if arg is not None)

    @staticmethod
    @v_args(inline=True)
    def attribute(name, parameters_opt):
        """ A transform handler to deal with corresponding grammar rule"""
        return CClassicalAttribute(str(name), parameters_opt)

    @staticmethod
    def translation_unit(args):
        """ A transform handler to deal with corresponding grammar rule"""
        rs = []
        for unit in list(arg for arg in args if arg is not None):
            if isinstance(unit, CFunction):
                rs.append(unit)
            else:
                rs += unit
        return CTranslationUnit(rs)


# A parser cache for performance
parser_cache: Dict[Any, Any] = {}
# To set a default transformer
default_transformer = CTransformer()


def parse(content: str, entry: str, transformer_opt: Optional[CTransformer] = None):
    """ To parse and transform text to CBiAst """
    transformer = transformer_opt or default_transformer
    key = (content, entry, id(transformer))

    if key in parser_cache:
        ret = parser_cache.get(key)
    else:
        ret = transformer.transform(c_parser.parse(content, entry))
        parser_cache[key] = ret

    return deepcopy(ret)
