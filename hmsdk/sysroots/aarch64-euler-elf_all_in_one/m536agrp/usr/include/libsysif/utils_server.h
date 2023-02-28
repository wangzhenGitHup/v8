/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Utils of sysif for server (server.h)
 * Author: Huawei OS Kernel Lab
 * Create: Tue Aug 31 19:24:42 2021
 */

#ifndef LIBSYSIF_UTILS_SERVER_H
#define LIBSYSIF_UTILS_SERVER_H

#include <libsysif/utils_common.h>

typedef int (*sysif_hook_func_t)(long ret_code, int argc, ...);
typedef bool (*sysif_need_hook_func_t)(void);

bool need_sysif_entry(void);
void sysif_entry_need_sw_set(uint8_t *sw);
bool need_sysif_exit(void);
void sysif_exit_need_hook_set(sysif_need_hook_func_t func);

void sysif_entry_hook(long ret_code, int argc, ...);
void sysif_exit_hook(long ret_code, int argc, ...);
void sysif_set_entry_hook(sysif_hook_func_t func);
void sysif_set_exit_hook(sysif_hook_func_t func);

/* -------------------------------activation related------------------------------ */
/*
 * When bridge hdlr is required, bridge hdlr calls shadow hdlr,
 * and shadow hdlr alias to real hdlr. Shadow hdlr is used to
 * modifying argument type. For example: in aarch64, passing a
 * large structure through a implict pointer. shadow hdlr helps
 * change type of pointer to type of structure.
 */
#ifdef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#define __DEFINE_ACTVHDLR(name, rettype, ...)	\
rettype __COMB(__actvshadowhdlr, name)(unsigned long long sender, unsigned long credential, ...) \
	__attribute__((alias(__STR(__COMB(actvhdlr, name))))); \
rettype __COMB(actvhdlr, name)(__VA_ARGS__);	\
rettype __COMB(actvhdlr, name)(__VA_ARGS__)
#else
#define __DEFINE_ACTVHDLR(name, rettype, ...)	\
rettype __COMB(actvhdlr, name)(__VA_ARGS__);	\
rettype __COMB(actvhdlr, name)(__VA_ARGS__)
#endif

#define DEFINE_ACTVHDLR(name, ...)		__DEFINE_ACTVHDLR(name, int, __VA_ARGS__)
#define DEFINE_ACTVHDLR_ULONG(name, ...)	__DEFINE_ACTVHDLR(name, unsigned long, __VA_ARGS__)

#ifdef CONFIG_AUDIT
#define sysif_entry(ret_code, argc, args...)		\
	do {										\
		if (need_sysif_entry()) {	\
			sysif_entry_hook(ret_code, argc, ##args);			\
		}									\
	} while (false)

#define sysif_exit(ret_code, argc, args...)		\
	do {									\
		if (need_sysif_exit()) {				\
			sysif_exit_hook(ret_code, argc, ##args);		\
		}								\
	} while (false)
#else
#define sysif_entry(ret_code, argc, args...)
#define sysif_exit(ret_code, argc, args...)
#endif

#define ____HDLR_ARG_NR_N(t1, a1, t2, a2, t3, a3, t4, a4, t5, a5,			\
			  t6, a6, t7, a7, t8, a8, t9, a9, t10, a10, t11, a11, t12, a12,	\
			  t13, a13, t14, a14, t15, a15, n, x, ...) n
#define __HDLR_ARG_NR(...)							\
	____HDLR_ARG_NR_N(__VA_ARGS__,						\
			  15, x, 14, x, 13, x, 12, x, 11, x, 10, x, 9, x,	\
			  8, x, 7, x, 6, x, 5, x, 4, x, 3, x, 2, x, 1, x, 0, x)

#define __DEFINE_ACTVHDLR_ALS(name, m, t, n, ...)				\
static inline t __actvhdlrals_##name(__SC_MAP(n, __SC_DECL, __VA_ARGS__));	\
m(name, __SC_MAP(n, __SC_DECL, __VA_ARGS__))					\
{										\
	t ret = E_HM_OK;								\
	if (generic_cred_replace_cred(&credential) != E_HM_OK) {		\
		ret = (t)E_HM_NOENT;						\
	} else if (!sysif_actv_is_selfcall(credential)) {				\
		sysif_callinfo.sender = sender;					\
		sysif_callinfo.credential = credential;				\
		sysif_callinfo.selfcall_type = __SEC_CRED_NO_SELFCALL;		\
		sysif_entry(ret, n, __SC_MAP(n, __SC_USE, __VA_ARGS__));	\
		ret = __actvhdlrals_##name(__SC_MAP(n, __SC_USE, __VA_ARGS__));	\
		generic_cred_entry_put((unsigned long)curr_generic_cred);	\
		sysif_exit(ret, n, __SC_MAP(n, __SC_USE, __VA_ARGS__));	\
	} else {								\
		enum sec_cred_selfcall_type old_type = sysif_callinfo.selfcall_type;	\
		sysif_callinfo.selfcall_type = __SEC_CRED_ACTV_SELFCALL;		\
		ret = __actvhdlrals_##name(__SC_MAP(n, __SC_USE, __VA_ARGS__));	\
		sysif_callinfo.selfcall_type = old_type;			\
	}									\
	return ret;								\
}										\
static inline t __actvhdlrals_##name(__SC_MAP(n, __SC_DECL, __VA_ARGS__))

#define DEFINE_ACTVHDLR_ALS(name, ...)						\
	__DEFINE_ACTVHDLR_ALS(name, DEFINE_ACTVHDLR, int,			\
			__HDLR_ARG_NR(__VA_ARGS__), __VA_ARGS__)

#define DEFINE_ACTVHDLR_ULONG_ALS(name, ...)					\
	__DEFINE_ACTVHDLR_ALS(name, DEFINE_ACTVHDLR_ULONG, unsigned long,	\
			__HDLR_ARG_NR(__VA_ARGS__), __VA_ARGS__)

#ifndef __HOST_LLT__
/*
 * Define the actv handler for handling the kernel event triggered
 * by the actv upcall. The args for handling the event is defined
 * as `actv_upcall_args_u`, which is placed in `uapi/hmkernel/activation/upcall.h`.
 */
#define DECLARE_UPCALL_ACTVHDLR(name)	DECLARE_KCALL_ACTVHDLR_ENTRY(name, int)
#define DECLARE_UPCALL_ACTVHDLR_ALS	DECLARE_UPCALL_ACTVHDLR

#define __DEFINE_UPCALL_ACTVHDLR(name, als)			\
static int ____##name(unsigned long long sender,		\
		      unsigned long credential,			\
		      union __arch_actv_upcall_args_u args);	\
DEFINE_KCALL_ACTVHDLR_ENTRY(name, int)				\
{								\
	union __arch_actv_upcall_args_u args;			\
	int ret = generic_cred_replace_cred(&credential);	\
	if (ret == E_HM_OK) {					\
		if (als) {					\
			sysif_actv_update_callinfo(sender, credential); \
			sysif_callinfo.selfcall_type = __SEC_CRED_NO_SELFCALL; \
		}						\
		args.buf[__ARCH_ACTV_UPCALL_ARG0] = arg1;	\
		args.buf[__ARCH_ACTV_UPCALL_ARG1] = arg2;	\
		args.buf[__ARCH_ACTV_UPCALL_ARG2] = arg3;	\
		ret = ____##name(sender, credential, args);	\
		generic_cred_entry_put((unsigned long)curr_generic_cred);\
	}							\
	return ret;						\
}								\
static int ____##name(unsigned long long sender,		\
		      unsigned long credential,			\
		      union __arch_actv_upcall_args_u args)

#define DEFINE_UPCALL_ACTVHDLR(name)		__DEFINE_UPCALL_ACTVHDLR(name, false)
#define DEFINE_UPCALL_ACTVHDLR_ALS(name)	__DEFINE_UPCALL_ACTVHDLR(name, true)

#else

#define DECLARE_UPCALL_ACTVHDLR(name)	DECLARE_KCALL_ACTVHDLR_ENTRY(name, int)
#define DECLARE_UPCALL_ACTVHDLR_ALS	DECLARE_UPCALL_ACTVHDLR

#endif

/* sysif_actvhdlr_default_handler can tell client that there is no handler for its callnum */
int sysif_actvhdlr_default_handler(unsigned long long sender, unsigned long credential);
/* sysif_actvhdlr_reserved_default_handler can tell client that there is no handler for reserved methods */
int sysif_actvhdlr_reserved_default_handler(unsigned long long sender, unsigned long credential);
/* sysif_actvhdlr_noop_handler do nothing for its callnum */
int sysif_actvhdlr_noop_handler(unsigned long long sender, unsigned long credential);
/* sysif_actv_pool_handle_grant_change handles the actv pool grant change event by default */
DECLARE_UPCALL_ACTVHDLR(sysif_actv_pool_handle_grant_change);

typedef void *(*sysif_actv_stack_alloc_t)(size_t *psize);
typedef void (*sysif_actv_stack_free_t)(void *ptr, size_t size);

int
sysif_actv_pool_handle_elastic_ex(cref_t actv_pool_cref,
				  struct actv_attr *attr,
				  sysif_actv_stack_alloc_t actv_stack_alloc,
				  sysif_actv_stack_free_t actv_stack_free);

static inline int
sysif_actv_pool_handle_elastic(cref_t actv_pool_cref,
			       struct actv_attr *attr)
{
	return sysif_actv_pool_handle_elastic_ex(actv_pool_cref, attr, NULL, NULL);
}

int
sysif_actv_pool_handle_elastic_pure_ex(struct actv_pure_attr *attr, rpc_entry_t entry);

static inline int
sysif_actv_pool_handle_elastic_pure(struct actv_pure_attr *attr)
{
	return sysif_actv_pool_handle_elastic_pure_ex(attr, arch_actv_pure_wait_rpc_entry);
}

#endif
