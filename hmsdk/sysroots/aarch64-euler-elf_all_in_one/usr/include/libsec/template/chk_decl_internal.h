/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Secure check head file
 * Author: Huawei OS Kernel Lab
 * Create: Wed May 08 11:22:58 2019
 *
 * No header guard:
 * This file is a template, so it could be included at many times with
 * different macro definitions in the same file.
 */
#if !defined(__LIBSEC_DEFINITION_FILE)
# error Please specify __LIBSEC_DEFINITION_FILE
#endif
// libc
#include <stdint.h>			/* uint32_t */
// hongmeng
#include <lib/dlist.h>			/* struct dlist_node */
#include <hmkernel/capability.h>	/* cref_t */
// security
#include <libsec/method/para.h>

struct sec_chk_cred;
struct sec_chk_cred_xact;

#define DEFINE_SERVICE(SERVICE, ...)					\
	__VA_ARGS__

#define DEFINE_CHECK_POINT_ULTIMATE(NAME, _ARG, EXP_EC, _, IGNORE, SILENT)	\
	int sec_chk_##NAME(PARA_VOID(_ARG));				\
	extern struct sec_chk_point sec_chk_point_##NAME;		\
	typedef int (*sec_chk_##NAME##_ft)				\
		(const struct sec_chk_cred *cred PARA(_ARG));		\
	typedef union {							\
		void			*func;				\
		sec_chk_##NAME##_ft	func_p;				\
	} sec_chk_##NAME##_ft_union;

#define DEFINE_CHECK_POINT_EC_IGNORE(name, arg, _, ignore) DEFINE_CHECK_POINT_ULTIMATE(name, arg, E_HM_OK, \
										       _, ignore, false)
#define DEFINE_CHECK_POINT_EXPEC(name, arg, exp_ec) DEFINE_CHECK_POINT_ULTIMATE(name, arg, exp_ec, _, false, true)
#define DEFINE_CHECK_POINT_EC(name, arg, _) DEFINE_CHECK_POINT_EC_IGNORE(name, arg, _, false)
#define DEFINE_CHECK_POINT(name, arg) DEFINE_CHECK_POINT_EC(name, arg, _)
#define DEFINE_CHECK_POINT_IGNORE_SELFCALL(name, arg) DEFINE_CHECK_POINT_EC_IGNORE(name, arg, E_HM_OK, \
					    requester_frame_is_fromself())
#define DEFINE_CHECK_POINT_SILENT(name, arg) DEFINE_CHECK_POINT_ULTIMATE(name, arg, E_HM_OK, _, false, true)

#define DEFINE_HOOK_POINT(NAME, _ARG)					\
	int sec_hook_##NAME(PARA_VOID(_ARG));				\
	extern struct sec_chk_point sec_hook_point_##NAME;		\
	typedef int (*sec_hook_##NAME##_ft)(PARA_VOID(_ARG));		\
	typedef union {							\
		void			*func;				\
		sec_hook_##NAME##_ft	func_p;				\
	} sec_hook_##NAME##_ft_union;

#define DEFINE_ACTIVE_CREDCHK_CHECK_POINT(NAME, _ARG)			\
	int sec_chk_##NAME(PARA_VOID(_ARG));				\
	extern struct sec_chk_point sec_active_cred_chk_point_##NAME;	\
	typedef int (*sec_active_cred_chk_##NAME##_ft)(			\
		struct sec_chk_cred *cred PARA(_ARG));			\
	typedef union {							\
		void				*func;			\
		sec_active_cred_chk_##NAME##_ft	func_p;			\
	} sec_active_cred_chk_##NAME##_ft_union;

#define DEFINE_CHECK_POINT_XACT(NAME, _ARG)				\
	int sec_chk_##NAME(PARA_VOID(_ARG));				\
	extern struct sec_chk_point sec_chk_point_##NAME;		\
	typedef int (*sec_chk_##NAME##_ft)				\
		(struct sec_chk_cred_xact *cred PARA(_ARG));		\
	typedef union {							\
		void			*func;				\
		sec_chk_##NAME##_ft	func_p;				\
	} sec_chk_##NAME##_ft_union;

#include __LIBSEC_DEFINITION_FILE

#undef DEFINE_SERVICE
#undef DEFINE_CHECK_POINT_ULTIMATE
#undef DEFINE_CHECK_POINT
#undef DEFINE_CHECK_POINT_EC_IGNORE
#undef DEFINE_CHECK_POINT_EXPEC
#undef DEFINE_CHECK_POINT_EC
#undef DEFINE_CHECK_POINT_IGNORE_SELFCALL
#undef DEFINE_CHECK_POINT_SILENT
#undef DEFINE_HOOK_POINT
#undef DEFINE_ACTIVE_CREDCHK_CHECK_POINT
#undef DEFINE_CHECK_POINT_XACT
#include "../method/para_undef.h"
