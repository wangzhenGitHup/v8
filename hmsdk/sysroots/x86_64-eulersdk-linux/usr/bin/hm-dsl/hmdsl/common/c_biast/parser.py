#!/usr/bin/env python3
# coding=utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
Description: C Syntax in Lark Parser
Author: Huawei OS Kernel Lab
Create: Mon 28 Dec 2020 16:30:00 PM CST
"""

from lark import Lark

grammar = """
%import common.WS

%ignore WS
%ignore C_COMMENT

translation_unit: external_declaration*

external_declaration: function_definition                                       -> pass_as_single
    | declaration                                                               -> pass_as_single
    | _SEMICOLON                                                                -> pass_as_none

function_definition: \
    declaration_specifiers declarator [declarations] compound_statement [attribute_specifiers]

function_specifier: INLINE

declaration: declaration_specifiers [init_declarators] _SEMICOLON
    | MACRODECL [_LBRACE builtin_parameters _RBRACE]                            -> macro_declaration

declarations: declaration+                                                      -> pass_as_list

nontype_declaration_specifier: storage_class_specifier                          -> pass_as_single
    | type_qualifier                                                            -> pass_as_single
    | function_specifier                                                        -> pass_as_single
    | attribute_specifier                                                       -> pass_as_single

nontypename_declaration_specifier: nontype_declaration_specifier                -> pass_as_single
    | direct_type_specifier                                                     -> pass_as_single

// qualifier and specifiers without type specifiers (e.g. T and int)
nontype_declaration_specifiers: nontype_declaration_specifier+                  -> pass_as_flatlist

nontypename_declaration_specifiers: nontypename_declaration_specifier+          -> pass_as_flatlist

declaration_specifiers: type_alias_specifier [nontype_declaration_specifiers]
    | direct_type_specifier [nontypename_declaration_specifiers]
    | nontype_declaration_specifier [declaration_specifiers]

init_declarators: init_declarator (_COMMA init_declarator)*                     -> pass_as_list

init_declarator: declarator [ASSIGN initializer [attribute_specifiers]]

initializer: assignment_expression                                              -> pass_as_single
    | _LBRACKET [designated_initializers] _COMMA? _RBRACKET

designated_initializers: designated_initializer (_COMMA designated_initializer)*

designated_initializer: [designation] initializer

designation: designator+ "="

designator: \
      _LSQUARE constant_expression ["..." constant_expression] _RSQUARE         -> range_designator
    | _DOT CNAME                                                                -> member_designator

statement: expression_statement                                                 -> pass_as_single
    | labelled_statement                                                        -> pass_as_single
    | compound_statement                                                        -> pass_as_single
    | selection_statement                                                       -> pass_as_single
    | iteration_statement                                                       -> pass_as_single
    | control_statement                                                         -> pass_as_single
    | asm_statement                                                             -> pass_as_single
    | null_statement                                                            -> pass_as_single
    | macro_statement                                                           -> pass_as_single

expression_statement: expression _SEMICOLON

null_statement: _SEMICOLON

macro_statement: MACROSTMT [_LBRACE macro_parameters _RBRACE]

labelled_statement: CNAME _COLON statement

switch_body: _LBRACKET (statement|case_statement)* _RBRACKET                    -> pass_as_list

case_statement: _CASE constant_expression _COLON                                -> non_default_case_statement
    | _DEFAULT _COLON                                                           -> default_case_statement

compound_statement: _LBRACKET (statement|declaration)* _RBRACKET

selection_statement: _IF condition statement                                    -> if_statement
    | _IF condition statement _ELSE statement                                   -> if_statement
    | _SWITCH condition switch_body                                             -> switch_statement

iteration_statement: _WHILE condition statement                                 -> while_statement
    | _DO statement _WHILE condition _SEMICOLON                                 -> do_while_statement
    | _FOR _LBRACE \
        [expression] _SEMICOLON [expression] _SEMICOLON [expression] \
        _RBRACE statement                                                       -> for_statement
    | _FOR _LBRACE \
        declaration [expression] _SEMICOLON [expression] \
        _RBRACE statement                                                       -> for_statement_decl

control_statement: _GOTO CNAME _SEMICOLON                                       -> goto_statement
    | _CONTINUE _SEMICOLON                                                      -> continue_statement
    | _BREAK _SEMICOLON                                                         -> break_statement
    | _RETURN [expression] _SEMICOLON                                           -> return_statement

asm_statement: asm_keyword asm_qualifiers _LBRACE \
        string_literal (asm_operands (asm_operands (asm_clobbers asm_gotolabels?)?)?)? \
        _RBRACE _SEMICOLON

asm_qualifiers: asm_qualifier*                                                  -> pass_as_list

asm_qualifier: VOLATILE                                                         -> asm_volatile_qualifier
    | INLINE                                                                    -> asm_inline_qualifier
    | _GOTO                                                                     -> asm_goto_qualifier

asm_operands: _COLON (asm_operand (_COMMA asm_operand)*)?                       -> pass_as_list

asm_operand: [_LSQUARE CNAME _RSQUARE] string_literal _LBRACE expression _RBRACE

asm_clobbers: _COLON (string_literal (_COMMA string_literal)*)?

asm_gotolabels: _COLON (CNAME (_COMMA CNAME)*)?

condition: _LBRACE expression _RBRACE                                           -> pass_as_single

constant_expression: conditional_expression                                     -> pass_as_single

expression: assignment_expression                                               -> pass_as_single
    | expression _COMMA assignment_expression                                   -> sequence_expression

assignment_expression: conditional_expression                                   -> pass_as_single
    | unary_expression assignment_operator assignment_expression

assignment_operator: (ASSIGN|MUTASSIGN|DIVASSIGN|MODASSIGN| \
                      ADDASSIGN|SUBASSIGN| \
                      RSHIFTASSIGN|LSHIFTASSIGN| \
                      BANDASSIGN|BORASSIGN|XORASSIGN)

conditional_expression: logical_or_expression                                   -> pass_as_single
    | logical_or_expression QUESTION expression _COLON conditional_expression

logical_or_expression: logical_and_expression                                   -> pass_as_single
    | logical_or_expression LOR logical_and_expression                          -> binary_expression

logical_and_expression: or_expression                                           -> pass_as_single
    | logical_and_expression LAND or_expression                                 -> binary_expression

or_expression: xor_expression                                                   -> pass_as_single
    | or_expression BOR xor_expression                                          -> binary_expression

xor_expression: and_expression                                                  -> pass_as_single
    | xor_expression XOR and_expression                                         -> binary_expression

and_expression: equality_expression                                             -> pass_as_single
    | and_expression BAND equality_expression                                   -> binary_expression

equality_expression: relational_expression                                      -> pass_as_single
    | equality_expression (EQ|NE) relational_expression                         -> binary_expression

relational_expression: shift_expression                                         -> pass_as_single
    | relational_expression (LT|GT|LE|GE) shift_expression                      -> binary_expression

shift_expression: additive_expression                                           -> pass_as_single
    | shift_expression (RSHIFT|LSHIFT) additive_expression                      -> binary_expression

additive_expression: multiplicative_expression                                  -> pass_as_single
    | additive_expression (ADD|SUB) multiplicative_expression                   -> binary_expression

multiplicative_expression: cast_expression                                      -> pass_as_single
    | multiplicative_expression (MUL|DIV|MOD) cast_expression                   -> binary_expression

cast_expression: unary_expression                                               -> pass_as_single
    | _LBRACE type_name _RBRACE cast_expression                                 -> cast_expression

unary_expression: postfix_expression                                            -> pass_as_single
    | (SELFINC|SELFDEC) unary_expression                                        -> unary_expression
    | (ADD|SUB|BNOT|LNOT) cast_expression                                       -> unary_expression
    | BAND cast_expression                                                      -> unary_expression
    | MUL cast_expression                                                       -> unary_expression
    | SIZEOF unary_expression                                                   -> unary_expression
    | SIZEOF _LBRACE type_name _RBRACE                                          -> unary_expression

argument_expression_list: assignment_expression (_COMMA assignment_expression)* -> pass_as_list

postfix_expression: primary_expression                                          -> pass_as_single
    | postfix_expression _LSQUARE expression _RSQUARE                           -> array_reference
    | postfix_expression _LBRACE [argument_expression_list] _RBRACE             -> function_call
    | postfix_expression _DOT CNAME                                             -> object_member
    | postfix_expression _ARROW CNAME                                           -> pointer_object_member
    | postfix_expression (SELFINC|SELFDEC)                                      -> postfix_unary_expression
    | MACROEXPR [_LBRACE builtin_parameters _RBRACE]                            -> macro_call
    | _LBRACE type_name _RBRACE \
        _LBRACKET designated_initializers _COMMA? _RBRACKET                     -> compound_literal
    | BUILTIN _LBRACE builtin_parameters _RBRACE                                -> builtin_expression

builtin_parameter: assignment_expression                                        -> pass_as_single
    | type_name                                                                 -> pass_as_single

builtin_parameters: builtin_parameter (_COMMA builtin_parameter)*               -> pass_as_list

macro_parameters: builtin_parameters                                            -> pass_as_single

primary_expression: constant                                                    -> pass_as_single
    | CNAME                                                                     -> identifier_expression
    | string_literal                                                            -> strings
    | _LBRACE expression _RBRACE                                                -> pass_as_single
    | _LBRACE compound_statement _RBRACE                                        -> compound_expression

constant: integer_literal                                                       -> integer_constant
    | CHAR_LITERAL                                                              -> char_constant
    | FLOAT_LITERAL                                                             -> floating_constant

integer_literal: INT_LITERAL                                                    -> decimal_literal
    | HEX_LITERAL                                                               -> hexadecimal_literal
    | OCT_LITERAL                                                               -> octal_literal
    | BIN_LITERAL                                                               -> binary_literal

storage_class_specifier: AUTO | REGISTER | STATIC | EXTERN | TYPEDEF

type_qualifier: CONST | VOLATILE

type_specifier: type_alias_specifier                                            -> pass_as_single
    | direct_type_specifier                                                     -> pass_as_single

direct_type_specifier: VOID
    | BOOL
    | CHAR
    | SHORT
    | INT
    | LONG
    | FLOAT
    | DOUBLE
    | SIGNED
    | UNSIGNED
    | MACROTYPE [_LBRACE builtin_parameters _RBRACE]                            -> type_macro_specifier
    | struct_specifier                                                          -> pass_as_single
    | union_specifier                                                           -> pass_as_single
    | enum_specifier                                                            -> pass_as_single
    | typeof_specifier                                                          -> pass_as_single

type_alias_specifier: CNAME

typeof_specifier: _TYPEOF _LBRACE (type_name | expression) _RBRACE

struct_specifier: STRUCT [attribute_specifiers] CNAME \
                  [field_declarations] [attribute_specifiers]                   -> named_struct_specifier
    | STRUCT [attribute_specifiers] field_declarations [attribute_specifiers]   -> anonymous_struct_specifier

union_specifier: UNION [attribute_specifiers] CNAME \
                 [field_declarations] [attribute_specifiers]                    -> named_union_specifier
    | UNION [attribute_specifiers] field_declarations [attribute_specifiers]    -> anonymous_union_specifier

enum_specifier: ENUM [attribute_specifiers] enumerators [attribute_specifiers]  -> anonymous_enum_specifier
    | ENUM [attribute_specifiers] CNAME [enumerators] [attribute_specifiers]    -> named_enum_specifier

field_declarations: _LBRACKET field_declaration* _RBRACKET

field_declaration: specifier_qualifiers field_declarators _SEMICOLON
    | struct_specifier _SEMICOLON                                               -> unamed_struct_union_field
    | union_specifier _SEMICOLON                                                -> unamed_struct_union_field
    | _SEMICOLON                                                                -> pass_as_none
    | MACRODECL [_LBRACE builtin_parameters _RBRACE]                            -> macro_field

field_declarators: field_declarator (_COMMA field_declarator)*                  -> pass_as_list

bitfield_descriptor: _COLON constant_expression

field_declarator: declarator [bitfield_descriptor]                              -> named_field_declarator
    | bitfield_descriptor                                                       -> anonymous_bit_field_declarator

pointer_descriptors: pointer_descriptor+                                        -> pass_as_list

pointer_descriptor: MUL type_qualifier*

abstract_declarator: pointer_descriptors [attribute_specifiers]                 -> pointer_abstract_declarator
    | [pointer_descriptors] \
      [attribute_specifiers] direct_abstract_declarator [attribute_specifiers]  -> pointer_complex_abstract_declarator

direct_abstract_declarator: _LBRACE abstract_declarator _RBRACE                 -> pass_as_single
    | [direct_abstract_declarator] _LSQUARE [expression] _RSQUARE                -> array_abstract_declarator
    | [direct_abstract_declarator] _LBRACE parameter_declarations _RBRACE        -> function_abstract_declarator

declarator: [pointer_descriptors] [attribute_specifiers] direct_declarator [attribute_specifiers]

direct_declarator: CNAME                                                        -> named_declarator
    | _LBRACE declarator _RBRACE                                                -> pass_as_single
    | direct_declarator _LSQUARE [expression] _RSQUARE                          -> array_declarator
    | direct_declarator _LBRACE parameter_declarations _RBRACE                  -> function_declarator

parameter_declarations:                                                         -> empty_parameter_declarations
    | parameter_declaration (_COMMA parameter_declaration)* [_COMMA AND_MORE]

parameter_declaration: declaration_specifiers [declarator|abstract_declarator]
    | MACRODECL [_LBRACE builtin_parameters _RBRACE]                            -> macro_parameter

enumerators: _LBRACKET enumerator (_COMMA enumerator)* _COMMA? _RBRACKET        -> pass_as_list

enumerator: CNAME                                                               -> named_enum_item
    | CNAME ASSIGN constant_expression                                          -> assigned_enum_item

type_name: specifier_qualifiers [abstract_declarator]

specifier_qualifiers: (type_qualifier | type_alias_specifier) [specifier_qualifiers]
    | direct_type_specifier [direct_specifier_qualifiers]

string_literal: STRING_LITERAL+

direct_specifier_qualifiers: (type_qualifier|direct_type_specifier)*            -> pass_as_list

attribute_specifiers: attribute_specifier+

attribute_specifier: ATTRIBUTE _LBRACE _LBRACE [attributes] _RBRACE _RBRACE
    | MACROATTR [_LBRACE builtin_parameters _RBRACE]                            -> macro_attribute

attributes: attribute (_COMMA attribute)*

attribute:                                                                      -> pass_as_none
    | CNAME [_LBRACE attribute_parameters _RBRACE]

attribute_parameters: [argument_expression_list]                                -> pass_as_single

ATTRIBUTE   : "__attribute__"

BUILTIN.2     : ("__builtin_va_arg" | "__builtin_offsetof" | "__builtin_types_compatible_p" | \
                 "sizeof" | "__sizeof__")

VOID        : "void"
CHAR        : "char"
SHORT       : "short"
INT         : "int"
LONG        : "long"
FLOAT       : "float"
DOUBLE      : "double"
SIGNED      : "signed"
UNSIGNED    : "unsigned"
BOOL        : "_Bool"
STRUCT      : "struct"
UNION       : "union"
ENUM        : "enum"
_TYPEOF.2   : "typeof" | "__typeof__"

CONST       : "const"
VOLATILE    : "volatile"

_SWITCH     : "switch"
_CASE       : "case"
_DEFAULT    : "default"
_IF         : "if"
_ELSE       : "else"
_WHILE      : "while"
_DO         : "do"
_FOR        : "for"
asm_keyword : "asm" | "__asm__"    -> pass_as_none

_GOTO       : "goto"
_BREAK      : "break"
_CONTINUE   : "continue"
_RETURN     : "return"

AUTO        : "auto"
REGISTER    : "register"
STATIC      : "static"
EXTERN      : "extern"
TYPEDEF     : "typedef"
INLINE      : "inline"

SIZEOF      : "sizeof"

_SEMICOLON  : ";"
_COLON      : ":"
QUESTION    : "?"
_COMMA      : ","
_DOT        : "."
SQUOTE      : "'"
DQUOTE      : /\"/
_ARROW      : "->"

_LBRACE     : "("
_RBRACE     : ")"
_LBRACKET   : "{"
_RBRACKET   : "}"
_LSQUARE    : "["
_RSQUARE    : "]"

ADD         : "+"
SUB         : "-"
MUL         : "*"
DIV         : "/"
MOD         : "%"
EQ          : "=="
NE          : "!="
LSHIFT      : "<<"
RSHIFT      : ">>"

LOR.1       : "||"
LAND.1      : "&&"
LNOT        : "!"
BOR.0       : "|"
XOR         : "^"
BAND.0      : "&"
BNOT        : "~"
LT.0        : "<"
LE.1        : "<="
GT.0        : ">"
GE.1        : ">="

ASSIGN      : "="
MUTASSIGN   : "*="
DIVASSIGN   : "/="
MODASSIGN   : "%="
ADDASSIGN   : "+="
SUBASSIGN   : "-="
RSHIFTASSIGN: ">>="
LSHIFTASSIGN: "<<="
BANDASSIGN  : "&="
BORASSIGN   : "|="
XORASSIGN   : "^="

SELFINC     : "++"
SELFDEC     : "--"

AND_MORE   : "..."

C_COMMENT: "/*" /([^\*\/]*((\*(?!\/))|(\/)|))*/ "*/"
    | /(\\/\\/).*\\n/

ZERO            : "0"
DIGIT           : "0" .. "9"
NONZERO_DIGIT   : "1" .. "9"
LCASE_LETTER    : "a" .. "z"
UCASE_LETTER    : "A" .. "Z"
HEX_DIGIT       : DIGIT | "a" .. "f" | "A" .. "F"
HEX_PREFIX      : "0x" | "0X"
BIN_PREFIX      : "0b" | "0B"
OCT_DIGIT       : "0" .. "7"

C_CHAR          : /[^'\\\\]/
                | ESCAPE_SEQUENCE

S_CHAR          : /[^"\\\\]/
                | ESCAPE_SEQUENCE

ESCAPE_SEQUENCE : "\\\\'" | "\\\\\\"" | "\\\\?" | "\\\\\\\\"
                | "\\\\a" | "\\\\b" | "\\\\f" | "\\\\n" | "\\\\r" | "\\\\t" | "\\\\v"
                | "\\\\" OCT_DIGIT ~ 1..3
                | "\\\\x" HEX_DIGIT+
                | "\\\\u" HEX_DIGIT ~ 4 | "\\\\U" HEX_DIGIT ~ 8

LETTER          : UCASE_LETTER | LCASE_LETTER

CNAME.1         : ("_"|LETTER) ("_"|LETTER|DIGIT)*
MACROEXPR.2     : "@" CNAME ":expr"
MACROTYPE.2     : "@" CNAME ":type"
MACROSTMT.2     : "@" CNAME ":stmt"
MACRODECL.2     : "@" CNAME ":decl"
MACROATTR.2     : "@" CNAME ":attr"

BIN_LITERAL     : BIN_PREFIX ("0" | "1")+ INTEGER_SUFFIX?
INT_LITERAL     : NONZERO_DIGIT DIGIT* INTEGER_SUFFIX?
OCT_LITERAL     : ZERO OCT_DIGIT* INTEGER_SUFFIX?
HEX_LITERAL.2     : HEX_PREFIX HEX_DIGIT+ INTEGER_SUFFIX?
CHAR_LITERAL    : SQUOTE C_CHAR SQUOTE
STRING_LITERAL  : DQUOTE S_CHAR* DQUOTE
FLOAT_LITERAL   : DIGIT* _DOT DIGIT+ EXPONENT? FLOATING_SUFFIX?
                | DIGIT+ _DOT EXPONENT? FLOATING_SUFFIX?
                | DIGIT+ EXPONENT FLOATING_SUFFIX?

EXPONENT        : ("e" | "E") [ADD | SUB] DIGIT+

U_SUFFIX        : "u" | "U"
L_SUFFIX        : ("l" "l"?) | ("L" "L"?)

INTEGER_SUFFIX  : (U_SUFFIX L_SUFFIX? | L_SUFFIX U_SUFFIX?)
FLOATING_SUFFIX : "f" | "l" | "F" | "L"
"""

entries = ['translation_unit',
           'declaration',
           'parameter_declaration',
           'function_definition',
           'type_name',
           'expression',
           'statement',
           'attribute',
           'attribute_specifier',
           'designation',
           'initializer',
           'enumerator']

c_parser = Lark(grammar, parser='earley', lexer='standard',
                maybe_placeholders=True, start=entries)
