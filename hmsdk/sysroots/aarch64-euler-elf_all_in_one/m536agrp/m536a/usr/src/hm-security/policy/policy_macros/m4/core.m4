m4_include(`utils.m4')
m4_include(`list.m4')
m4_dnl
m4_define(`HMI_BEGIN',`
#---new file---
#$@
#---policy begin---
{
')m4_dnl This is the begin of a policy file.
m4_define(`HMI_END',`}
#---policy end---
')m4_dnl This is the end of a policy file.
m4_dnl
m4_define(`TYPE',`HMI_CHECK_ARG_NUM(1,$@)HMI_CHECK_VALID_C_LITERAL($1)$1_t')m4_dnl
m4_define(`T',`HMI_CHECK_ARG_NUM(1,$@)TYPE(`$1')')
m4_define(`ATTR',`HMI_CHECK_ARG_NUM(1,$@)HMI_CHECK_VALID_C_LITERAL($1)$1_a')m4_dnl
m4_define(`A',`HMI_CHECK_ARG_NUM(1,$@)ATTR(`$1')')
m4_define(`ACTION',`HMI_CHECK_ARG_NUM(1,$@)HMI_CHECK_VALID_C_LITERAL($1)ac_$1')m4_dnl
m4_define(`ABILITY',`HMI_CHECK_ARG_NUM(1,$@)HMI_CHECK_VALID_C_LITERAL($1)ab_$1')m4_dnl
m4_dnl
m4_define(`HMI_STR',`"$1"')m4_dnl
m4_define(`HMI_ATTR_S',`HMI_STR(ATTR($1))')m4_dnl
m4_define(`HMI_TYPE_S',`HMI_STR(TYPE($1))')m4_dnl
m4_define(`HMI_ACTION_S',`HMI_STR(ACTION($1))')m4_dnl
m4_define(`HMI_ABILITY_S',`HMI_STR(ABILITY($1))')m4_dnl
m4_dnl
m4_define(`HMI___DEF_TYPES', `m4_dnl
  "type_def": [
    HMI_JOIN(`,
    ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$1',`HMI_TYPE_S')))
  ],
')m4_dnl
m4_define(`HMI___DEF_ATTRS',`m4_dnl
  "attr_def": [
    HMI_JOIN(`,
    ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$1',`HMI_ATTR_S')))
  ]
')m4_dnl
m4_define(`HMI___DEF_ACTIONS',`m4_dnl
  "action_def": [
    HMI_JOIN(`,
    ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$1',`HMI_ACTION_S')))
  ]
')m4_dnl
m4_define(`HMI___DEF_ABILITIES',`m4_dnl
  "ability_def": [
    HMI_JOIN(`,
    ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$1',`HMI_ABILITY_S')))
  ]
')m4_dnl
m4_dnl
m4_define(`HMI___DEF_ABILITY_HIERACHIES',`m4_dnl
  "ability_hierachy_def": [
    HMI_JOIN(`,
    ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$1',`HMI_STR')))
  ]
')m4_dnl
m4_dnl
m4_define(`HMI__ASSOCIATE_TYPES_ATTRS',
`m4_define(`HMI__TA',`{
      HMI_TYPE_S($'`1): [
        ``HMI_JOIN(`,
        ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$2',`HMI_ATTR_S')))''
      ]
    }')m4_dnl
  "type_attr": [
    HMI_JOIN(`,
    ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$1',`HMI__TA')))
  ]
m4_undefine(`HMI__TA')'m4_dnl
)m4_dnl
m4_dnl
m4_define(`HMI___TE_POLICY',`m4_dnl
  "te_policy": [
    {
      "subject": HMI_STR($1),
      "object": HMI_STR($2),
      "action": [
        HMI_JOIN(`,
        ',HMI_LIST_EXPAND(HMI_LIST_MAP($3,`HMI_ACTION_S')))
      ]
    }
  ]
')m4_dnl
m4_dnl
m4_define(`HMI___TRANSITION',`m4_dnl
  "type_transition": [
    {
      "subject": HMI_TYPE_S($1),
      "object": HMI_TYPE_S($2),
      "tr_action": HMI_ACTION_S($3),
      "target_subject": HMI_TYPE_S($4)
    }
  ]
')m4_dnl
m4_dnl
m4_define(`HMI___RANGE',`{
            "start": $1```,'''
            "end": $2```,'''
          }')m4_dnl
m4_define(`HMI__RANGE',`HMI_LIST_CHECK_INVALID_NIL(`$1')HMI___RANGE(HMI_LIST_EXPAND(`$1'))')
m4_define(`HMI___ABILITY_POLICY',`m4_dnl
  "ability_policy": [
    {
      HMI_STR(`$1'): {
        "ability": [m4_ifelse(`$2',`()',`',`
          HMI_JOIN(`,
          ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$2',`HMI_ABILITY_S')))')
        ],
	"ability_ng": [m4_ifelse(`$3',`()',`',`
          HMI_JOIN(`,
          ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$3',`HMI_STR')))')
	],
        "mem_range": [m4_ifelse(`$4',`()',`',`
          HMI_JOIN(`,
          ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$4',`HMI__RANGE')))')
        ],
        "port_range": [m4_ifelse(`$5',`()',`',`
          HMI_JOIN(`,
          ',HMI_LIST_EXPAND(HMI_LIST_MAP(`$5',`HMI__RANGE')))')
        ]
      }
    }
  ]
')m4_dnl
m4_dnl
m4_define(`HMI___DEF_FILE_OBJECT',`m4_dnl
  "fileobj_def": [
    {
      HMI_TYPE_S(`$1'): HMI_STR(`$2')
    }
  ]
')m4_dnl
m4_dnl
m4_define(`HMI__DEF_FILE_OBJECT',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___DEF_FILE_OBJECT($@)m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_dnl
m4_define(`HMI___ANNOTATE_ABILITY_HIERACHY',`m4_dnl
  "annotate_ability_with_hierachy": [
    {
      HMI_ABILITY_S(`$1'): HMI_STR(`$2')
    }
  ]
')m4_dnl
m4_dnl
m4_define(`HMI__ANNOTATE_ABILITY_HIERACHY',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___ANNOTATE_ABILITY_HIERACHY($@)m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_dnl
m4_define(`HMI__DEF_TYPES_WITH_ATTRS',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___DEF_TYPES(`$1')m4_dnl
HMI__ASSOCIATE_TYPES_ATTRS(`$1',HMI_LIST_APPEND((generic_type),`$2'))m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_define(`DEF_TYPES_WITH_ATTRIBUTES',`HMI_CHECK_ARG_NUM(2,$@)HMI__DEF_TYPES_WITH_ATTRS(HMI_STRIP_BLANK($@))')m4_dnl
m4_dnl
m4_define(`DEF_TYPES',`DEF_TYPES_WITH_ATTRIBUTES(`HMI_LIST($@)',`()')')m4_dnl
m4_dnl
m4_define(`HMI__DEF_ATTRS',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___DEF_ATTRS(`HMI_LIST($@)')m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_define(`DEF_ATTRIBUTES',`HMI__DEF_ATTRS(HMI_STRIP_BLANK($@))')m4_dnl
m4_dnl
m4_define(`HMI__DEF_ACTIONS',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___DEF_ACTIONS(`HMI_LIST($@)')m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_define(`DEF_ACTIONS',`HMI__DEF_ACTIONS(HMI_STRIP_BLANK($@))')m4_dnl
m4_dnl
m4_define(`HMI__DEF_ABILITIES',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___DEF_ABILITIES(`HMI_LIST($@)')m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_dnl
m4_define(`DEF_ABILITIES',`HMI__DEF_ABILITIES(HMI_STRIP_BLANK($@))')m4_dnl
m4_dnl
m4_define(`HMI__DEF_ABILITY_HIERACHIES',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___DEF_ABILITY_HIERACHIES(`HMI_LIST($@)')m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_dnl
m4_define(`DEF_ABILITY_HIERACHIES',`HMI__DEF_ABILITY_HIERACHIES(HMI_STRIP_BLANK($@))')m4_dnl
m4_dnl
m4_define(`HMI__TYPE_ADD_ATTRIBUTES',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI__ASSOCIATE_TYPES_ATTRS(`$1',`$2')m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_define(`TYPE_ADD_ATTRIBUTES',`HMI_CHECK_ARG_NUM(2,$@)HMI__TYPE_ADD_ATTRIBUTES(HMI_STRIP_BLANK($@))')m4_dnl
m4_dnl
m4_define(`DEF_FILE_OBJECT',`HMI_CHECK_ARG_NUM(2,$@)HMI__DEF_FILE_OBJECT(HMI_STRIP_BLANK($1),`HMI_STRIP_END_BLANK(`$2')')')m4_dnl
m4_dnl
m4_define(`ANNOTATE_ABILITY_HIERACHY',`HMI_CHECK_ARG_NUM(2,$@)HMI__ANNOTATE_ABILITY_HIERACHY(HMI_STRIP_BLANK($1),`HMI_STRIP_END_BLANK(`$2')')')m4_dnl
m4_dnl
m4_define(`HMI__TE_POLICY',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___TE_POLICY($@)m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_define(`TE_POLICY',`HMI_CHECK_ARG_NUM(3,$@)HMI__TE_POLICY(HMI_STRIP_BLANK($@))')m4_dnl
m4_dnl
m4_define(`HMI__TRANSITION',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___TRANSITION($@)m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_define(`TRANSITION',`HMI_CHECK_ARG_NUM(4,$@)HMI__TRANSITION(HMI_STRIP_BLANK($@))')m4_dnl
m4_dnl
m4_define(`HMI__ABILITY_POLICY',`m4_dnl
HMI_BEGIN(`$0($@)')m4_dnl
HMI___ABILITY_POLICY($@)m4_dnl
HMI_END()m4_dnl
')m4_dnl
m4_dnl
m4_define(`HMI_ABILITY_POLICY_FULL_NG',`HMI_CHECK_ARG_NUM(5,$@)HMI__ABILITY_POLICY(HMI_STRIP_BLANK($@))')m4_dnl
m4_define(`ABILITY_POLICY_FULL',`HMI_CHECK_ARG_NUM(4,$@)HMI_ABILITY_POLICY_FULL_NG(`$1',`$2',(),`$3',`$4')')m4_dnl
m4_define(`ABILITY_POLICY',`HMI_ABILITY_POLICY_FULL_NG(`$1',HMI_LIST(m4_shift($@)),(),(),())')
m4_define(`ABILITY_HIERACHY_POLICY',`HMI_ABILITY_POLICY_FULL_NG(`$1',(),HMI_LIST(m4_shift($@)),(),())')
m4_define(`MEM_RANGE',`HMI_ABILITY_POLICY_FULL_NG(`$1',(),(),HMI_LIST(m4_shift($@)),())')
m4_define(`PORT_RANGE',`HMI_ABILITY_POLICY_FULL_NG(`$1',(),(),(),HMI_LIST(m4_shift($@)))')
