m4_include(`utils.m4')m4_dnl
m4_define(`HMI_LIST',`($@)')m4_dnl
m4_define(`HMI_LIST_DELIST_FIRST',`$1')m4_dnl inner function
m4_define(`HMI_LIST_DELIST_ALL',`$@')m4_dnl inner function
m4_define(`HMI_LIST_EXPAND',`HMI_LIST_CHECK_INVALID($1)HMI_LIST_DELIST_ALL$1')m4_dnl
m4_define(`HMI_LIST_CHECK_INVALID',
`m4_ifelse(m4_regexp(`$1',`^(\(.\|
\)*)$'),-1,
	`HMI_FATAL_ERROR(`A invalid list is detected.'`$2'` String:`$1'')',
	`')')m4_dnl
m4_define(`HMI_LIST_CHECK_NIL',
`m4_ifelse(`$1',`()',
	`HMI_FATAL_ERROR(`A nil list is detected.'`$2')',
	`')')m4_dnl
m4_define(`HMI_LIST_CHECK_INVALID_NIL',`HMI_LIST_CHECK_INVALID(`$1',`$2')HMI_LIST_CHECK_NIL(`$1',`$2')')m4_dnl
m4_define(`HMI_LIST_CDR',
`HMI_LIST_CHECK_INVALID_NIL(`$1',` The error is in HMI_LIST_CDR.')'m4_dnl
`HMI_LIST(m4_shift(HMI_LIST_DELIST_ALL$1))')m4_dnl
m4_dnl name like lisp
m4_define(`HMI_LIST_CAR',
`HMI_LIST_CHECK_INVALID_NIL(`$1',` The error is in HMI_LIST_CAR.')'m4_dnl
`HMI_LIST_DELIST_FIRST$1'm4_dnl
)m4_dnl name like lisp
m4_define(`HMI_LIST_APPEND',
`m4_ifelse(`$1',`()',
	`m4_ifelse(`$2',`()',
		`()',
		`HMI_LIST_CHECK_INVALID(`$2',` The error is in the second argument of HMI_LIST_APPEND.')$2'
	)',
	`HMI_LIST_CHECK_INVALID_NIL(`$1',` The error is in the first argument of HMI_LIST_APPEND.')'m4_dnl
	`m4_ifelse(`$2',`()',
		`$1',
		`HMI_LIST_CHECK_INVALID(`$2',` The error is in the second argument of HMI_LIST_APPEND.')'m4_dnl
		`HMI_LIST(HMI_LIST_DELIST_ALL$1,HMI_LIST_DELIST_ALL$2)')')'m4_dnl
)m4_dnl name like lisp
m4_define(`HMI_LIST_MAP',`HMI_LIST_CDR(HMI_LIST(HMI_FOREACH(`HMI_LIST_ITER',$1,`,$2(HMI_LIST_ITER)')))')m4_dnl
