/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Secure check head file
 * Author: Huawei OS Kernel Lab
 * Create: Wed May 08 11:23:08 2019
 *
 * No header guard:
 * This file is a template, so it could be included at many times with
 * different macro definitions in the same file.
 */
#if !defined(__LIBSEC_DEFINITION_FILE)
# error Please specify __LIBSEC_DEFINITION_FILE
#endif
// related header file
#include "chk_decl_internal.h"
// hongmeng
#include <hongmeng/errno.h>
#include <libhmlog/hmlog.h>
// security
#include <libsec/cred.h>
#include <libsec/chk.h>
#include <libsec/method/var.h>
#include <libsec/method/para.h>

#define DEFINE_SERVICE(SERVICE, ...) __VA_ARGS__

#define DEFINE_CHECK_POINT_COMMON(NAME)					\
struct sec_chk_point sec_chk_point_##NAME = {				\
	.list = {							\
		.next = &sec_chk_point_##NAME.list,			\
		.prev = &sec_chk_point_##NAME.list,			\
	},								\
};									\
struct sec_chk_method_##NAME {						\
	struct sec_chk_method_common	hook;				\
	sec_chk_##NAME##_ft		func;				\
}

#define DEFINE_CHECK_POINT_ULTIMATE(NAME, _ARG, EXP_EC, DEF_EC, IGNORE, SILENT)	\
DEFINE_CHECK_POINT_COMMON(NAME);						\
static int __sec_chk_##NAME(struct sec_chk_cred *cred_p PARA(_ARG))	\
{									\
	struct dlist_node *pos = NULL;					\
	int ret = E_HM_OK;						\
									\
	dlist_for_each(pos, &sec_chk_point_##NAME.list) {		\
		struct sec_chk_method_##NAME *meth;			\
		meth = container_of(pos, struct sec_chk_method_##NAME,	\
				    hook.node);				\
		ret = (meth->func)(cred_p VAR(_ARG));			\
		if (ret != (EXP_EC)) {					\
			break;						\
		}							\
	}								\
	if (!(SILENT) && ret != (EXP_EC)) {				\
		sec_deny_log("Access denied. (alias=%s, proc=[0x%x], ret=%s(%d))\n",	\
			     #NAME, cred_p->cnode_idx, hmstrerror(ret), ret);		\
	}								\
	return ret;							\
}									\
int sec_chk_##NAME(PARA_VOID(_ARG))					\
{									\
	struct sec_chk_cred cred = {0};					\
	int ret;							\
									\
	if (IGNORE) {							\
		ret = E_HM_OK;						\
	} else if (dlist_empty(&sec_chk_point_##NAME.list)) {		\
		ret = DEF_EC;						\
	} else {							\
		ret = sec_chk_cred_init_requester(&cred);		\
		if (ret != E_HM_OK) {					\
			ret = E_HM_SRCH;				\
		} else {						\
			ret = __sec_chk_##NAME(&cred VAR(_ARG));	\
		}							\
	}								\
									\
	return ret;							\
}

#define DEFINE_CHECK_POINT_EC_IGNORE(name, arg, errcode, ignore) DEFINE_CHECK_POINT_ULTIMATE(name, arg, E_HM_OK, \
											     errcode, ignore, __false)
#define DEFINE_CHECK_POINT_EXPEC(name, arg, exp_ec) DEFINE_CHECK_POINT_ULTIMATE(name, arg, exp_ec, E_HM_OK, \
										__false, __true)
#define DEFINE_CHECK_POINT_EC(name, arg, errcode) DEFINE_CHECK_POINT_EC_IGNORE(name, arg, errcode, __false)
#define DEFINE_CHECK_POINT(name, arg) DEFINE_CHECK_POINT_EC(name, arg, E_HM_OK)
#define DEFINE_CHECK_POINT_IGNORE_SELFCALL(name, arg) DEFINE_CHECK_POINT_EC_IGNORE(name, arg, E_HM_OK, \
					    requester_frame_is_fromself())
#define DEFINE_CHECK_POINT_SILENT(name, arg) DEFINE_CHECK_POINT_ULTIMATE(name, arg, E_HM_OK, E_HM_OK, __false, __true)

#define DEFINE_HOOK_POINT(NAME, _ARG)					\
struct sec_chk_point sec_hook_point_##NAME = {				\
	.list = {							\
		.prev = &sec_hook_point_##NAME.list,			\
		.next = &sec_hook_point_##NAME.list,			\
	},								\
};									\
struct sec_chk_method_##NAME {						\
	struct sec_chk_method_common	hook;				\
	sec_hook_##NAME##_ft		func;				\
};									\
int sec_hook_##NAME(PARA_VOID(_ARG))					\
{									\
	struct dlist_node *pos = NULL;					\
	int ret = E_HM_OK;						\
									\
	dlist_for_each(pos, &sec_hook_point_##NAME.list) {		\
		struct sec_chk_method_##NAME *meth;			\
		meth = container_of(pos, struct sec_chk_method_##NAME,	\
				    hook.node);				\
		ret = (meth->func)(VAR_VOID(_ARG));			\
		if (ret != E_HM_OK) {					\
			break;						\
		}							\
	}								\
	if (ret != E_HM_OK) {						\
		sec_deny_log("Access denied. (alias=%s, ret=%s(%d))\n",	\
			     #NAME, hmstrerror(ret), ret);		\
	}								\
									\
	return ret;							\
}

#define DEFINE_ACTIVE_CREDCHK_CHECK_POINT(NAME, _ARG)				\
struct sec_chk_point sec_active_cred_chk_point_##NAME = {			\
	.list = {								\
		.prev = &sec_active_cred_chk_point_##NAME.list,			\
		.next = &sec_active_cred_chk_point_##NAME.list,			\
	},									\
};										\
struct sec_chk_method_##NAME {							\
	struct sec_chk_method_common	hook;					\
	sec_active_cred_chk_##NAME##_ft	func;					\
};										\
int sec_chk_##NAME(PARA_VOID(_ARG))						\
{										\
	struct dlist_node *pos = NULL;						\
	struct sec_chk_cred cred = {0};						\
	int ret;								\
										\
	if (dlist_empty(&sec_active_cred_chk_point_##NAME.list)) {		\
		ret = E_HM_OK;							\
	} else {								\
		dlist_for_each(pos, &sec_active_cred_chk_point_##NAME.list) {	\
			struct sec_chk_method_##NAME *meth;			\
			meth = container_of(pos, struct sec_chk_method_##NAME,	\
					    hook.node);				\
			ret = (meth->func)(&cred VAR(_ARG));			\
			if (ret != E_HM_OK) {					\
				break;						\
			}							\
		}								\
		if (ret != E_HM_OK) {						\
			sec_deny_log("Access denied. (alias=%s, proc=[0x%x], ret=%s(%d))\n",	\
				     #NAME, cred.cnode_idx, hmstrerror(ret), ret);		\
		}								\
	}									\
	return ret;								\
}

#define DEFINE_CHECK_POINT_XACT(NAME, _ARG)				\
DEFINE_CHECK_POINT_COMMON(NAME);					\
static int __sec_chk_##NAME(struct sec_chk_cred_xact *cred_p PARA(_ARG))\
{									\
	int ret = E_HM_OK;						\
	struct dlist_node *dn = NULL;					\
									\
	dlist_for_each(dn, &sec_chk_point_##NAME.list) {		\
		struct sec_chk_method_##NAME *meth;			\
		meth = container_of(dn, struct sec_chk_method_##NAME,	\
				    hook.node);				\
		ret = (meth->func)(cred_p VAR(_ARG));			\
		if (ret != E_HM_OK) {					\
			break;						\
		}							\
	}								\
	if (ret != E_HM_OK) {						\
		sec_deny_log("Access denied. (alias=%s, forward=[0x%x->0x%x], ret=%s(%d))\n",\
			     #NAME, cred_p->_req.fwd_cnode_idx,		\
			     cred_p->_req.src_cnode_idx,		\
			     hmstrerror(ret), ret);			\
	}								\
	return ret;							\
}									\
int sec_chk_##NAME(PARA_VOID(_ARG))					\
{									\
	struct sec_chk_cred_xact cred = SEC_CHK_CRED_XACT_RESET;	\
	int ret;							\
									\
	if (dlist_empty(&sec_chk_point_##NAME.list)) {			\
		ret = E_HM_OK;						\
	} else {							\
		ret = sec_chk_cred_xact_init(&cred);			\
		if (ret != E_HM_OK) {					\
			ret = E_HM_SRCH;				\
		} else {						\
			ret = __sec_chk_##NAME(&cred VAR(_ARG));	\
		}							\
	}								\
	return ret;							\
}

#include __LIBSEC_DEFINITION_FILE

#undef __LIBSEC_DEFINITION_FILE
#undef DEFINE_SERVICE
#undef DEFINE_CHECK_POINT_ULTIMATE
#undef DEFINE_CHECK_POINT_EC_IGNORE
#undef DEFINE_CHECK_POINT_EXPEC
#undef DEFINE_CHECK_POINT_EC
#undef DEFINE_CHECK_POINT
#undef DEFINE_CHECK_POINT_IGNORE_SELFCALL
#undef DEFINE_CHECK_POINT_SILENT
#undef DEFINE_HOOK_POINT
#undef DEFINE_ACTIVE_CREDCHK_CHECK_POINT
#undef DEFINE_CHECK_POINT_XACT
#include "../method/para_undef.h"
#include "../method/var_undef.h"
