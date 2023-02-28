INCLUDE(`builtin.m4')

DEF_TYPES(t1,t2)
DEF_ATTRIBUTES(a1,a2)
DEF_ACTIONS(ac1,ac2)
DEF_ABILITIES(ab1, ab2, ab3 )
DEF_TYPES_WITH_ATTRIBUTES( (a,b_exec,c), (r, w, x))
TYPE_ADD_ATTRIBUTES((q,w,e),(z,x,c))

TRANSITION(a_type,other_type,spawn,target_type)
DEF_FILE_OBJECT(a_type,``/BACKTICK'')
DEF_FILE_OBJECT(a_type,``shmfs:/TYPE'BACKTICK`'BACKTICK`T'') COMMENT a comment
DEF_FILE_OBJECT(a_type,``procfs:/TYPE'BACKTICK`T'')
DEF_FILE_OBJECT(a_type,``tmpfs:/TYPE'BACKTICK`T'' )

TE_POLICY(TYPE(a_type_or_attr),ATTR(other_type_or_attr),(an_action1 ,an_action2,an_action3))
ABILITY_POLICY_FULL(TYPE(a_type_or_attr),
		    (an_ability1,an_ability2,an_ability3),
		    ((1,2),(2,3)),
		    ((4,5),(6,8)))
MEM_RANGE(TYPE(a_type_or_attr),(1,2),(3,4))
ABILITY_POLICY(TYPE(a_type_or_attr),an_ability1,an_ability2)
PORT_RANGE(TYPE(a_type_or_attr),(1,2),(5,6))
