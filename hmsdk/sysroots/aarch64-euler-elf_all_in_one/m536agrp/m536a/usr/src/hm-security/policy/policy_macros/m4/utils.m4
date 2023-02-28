m4_define(`HMI_FATAL_ERROR',
`m4_errprint(m4___program__:m4___file__:m4___line__`: fatal error: $*
')m4_m4exit(`1')')m4_dnl
m4_define(`HMI_FOREACH',`m4_pushdef(`$1')HMI__FOREACH($@)m4_popdef(`$1')')m4_dnl
m4_define(`HMI_FOREARCH_ARG1',`$1')m4_dnl
m4_define(`HMI__FOREACH',
	  `m4_ifelse(`$2', `()', `',
  `m4_define(`$1', HMI_FOREARCH_ARG1$2)$3`'$0(`$1', (m4_shift$2), `$3')')')m4_dnl
m4_define(`HMI_STRIP_BLANK',`m4_patsubst(`$@',`\s',`')')m4_dnl
m4_define(`HMI_STRIP_END_BLANK',m4_dnl
`m4_patsubst(`$1',`\(\s\|
\)*$',`')')m4_dnl
m4_define(`HMI_CHECK_VALID_C_LITERAL',
`m4_ifelse(m4_regexp(`$1',`^[_a-zA-Z][_a-zA-Z0-9]*$'),-1,
	   `HMI_FATAL_ERROR(`Invalid token: `$1'')',
	   `')'m4_dnl
)m4_dnl
m4_define(`HMI_CHECK_ARG_NUM',
`m4_ifelse(m4_incr($1),$#,
	   `',
	   `HMI_FATAL_ERROR(`$1 argument(s) is expected')')'m4_dnl
)m4_dnl
m4_define(`HMI_JOIN',
`m4_ifelse(`$#', `2', ``$2'',
  `m4_ifelse(`$2', `', `', ``$2'_')$0(`$1', m4_shift(m4_shift($@)))')')m4_dnl
m4_define(`_HMI_JOIN',
`m4_ifelse(`$#$2', `2', `',
  `m4_ifelse(`$2', `', `', ``$1$2'')$0(`$1', m4_shift(m4_shift($@)))')')m4_dnl
m4_define(`ECHO',`$@')m4_dnl
m4_define(`BACKTICK',m4_changequote([,])[m4_changequote([,])`m4_changequote(`,')]m4_changequote(`,'))m4_dnl
m4_define(`SINGLEQUOTE',m4_changequote([,])[m4_changequote([,])'m4_changequote(`,')]m4_changequote(`,'))m4_dnl
m4_define(`COMMENT',`m4_dnl')m4_dnl This is the hint of comment.
m4_define(`INCLUDE',`HMI_CHECK_ARG_NUM(1,$@)m4_include($@)')m4_dnl
