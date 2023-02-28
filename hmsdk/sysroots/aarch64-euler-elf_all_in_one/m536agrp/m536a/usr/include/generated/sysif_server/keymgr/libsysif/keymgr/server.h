/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for keymgr
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/keymgr/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/keymgr/libsysif/keymgr/api.h --server-dest ../image/usr/include/generated/sysif_server/keymgr/libsysif/keymgr/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_KEYMGR_SERVER_H
#define LIBSYSIF_KEYMGR_SERVER_H
#ifndef LIBSYSIF_KEYMGR_COMMON_H
#define LIBSYSIF_KEYMGR_COMMON_H
#include <libsysif/utils_common.h>
#include <hongmeng/compiler.h>
#include <hongmeng/types.h>
#include <asm/actv_rpc.h>
#ifndef LIBSYSIF_BASE_API_COMMON_H
#define LIBSYSIF_BASE_API_COMMON_H
#include <stddef.h>
#include <stdint.h>
#include <hmkernel/capability.h>
struct sysif_reply_header {
	int32_t retval;
	uint32_t msgsz;
};

#define SYSIF_REPLY_LEN_MAX 256UL
extern void* hm_actvpool_prepare_ret(unsigned long long sender, unsigned long credential, unsigned long size);


extern struct arch_actv_local* hm_actv_current_arch_actv_local(void);


#endif
#include <libhmsrv_key/keymgr.h>

#include <libhmsrv_key/key.h>

raw_static_assert(sizeof(struct key_add_param) <= 96,
                    keycall_keymgr_add_arg_param_is_too_large);
raw_static_assert(sizeof(struct key_request_param) <= 96,
                    keycall_keymgr_request_arg_param_is_too_large);
raw_static_assert(sizeof(struct keyctl_param) <= 96,
                    keycall_keymgr_control_arg_param_is_too_large);
struct __actvret_keycall_keymgr_add {
};

struct __actvret_keycall_keymgr_request {
};

struct __actvret_keycall_keymgr_control {
	struct keyctl_ret ret;
};

union __actvret_keycall {
	struct __actvret_keycall_keymgr_add keymgr_add;
	struct __actvret_keycall_keymgr_request keymgr_request;
	struct __actvret_keycall_keymgr_control keymgr_control;
};

enum __keymgr_mgr {
	__keymgr_INVAL_mgr=0,
	__keymgr_keymgr_mgr,
	__keymgr_MAX_mgr,
};

#define __keymgr_method_MIN __ACTV_HIGHTABLE_START
#define __keymgr_method_keymgr_add (__ACTV_HIGHTABLE_START + 1)
#define __keymgr_method_keymgr_request (__ACTV_HIGHTABLE_START + 2)
#define __keymgr_method_keymgr_control (__ACTV_HIGHTABLE_START + 3)
#define __keymgr_method_keymgr_rsvd_1 (__ACTV_HIGHTABLE_START + 4)
#define __keymgr_method_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + 5)
#define __keymgr_method_MAX_COMPAT ((__ACTV_HIGHTABLE_START + 5) * 2)
raw_static_assert(sizeof(struct __actvret_keycall_keymgr_add) < 512,
                keycall_keymgr_add_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_keycall_keymgr_request) < 512,
                keycall_keymgr_request_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_keycall_keymgr_control) < 512,
                keycall_keymgr_control_too_many_actvret_data);
raw_static_assert(sizeof(union __actvret_keycall) < 512,
        keycall_too_many_actvret_data);
extern int __actvcall_keycall_keymgr_add(unsigned long long __rpc_info, void *__buf, int shm_id, struct key_add_param param);


extern int __actvcapcall_keycall_keymgr_add(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct key_add_param param);


static inline int __attribute__((always_inline)) actvxactcall_keycall_keymgr_add(bool is_xact_fwd, bool is_xact_allow_refwd, int shm_id, struct key_add_param param)
{
	const unsigned long __callno = __keymgr_method_keymgr_add;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_keycall_keymgr_add(rpc_info, NULL, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_keycall_keymgr_add(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int shm_id, struct key_add_param param)
{
	const unsigned long __callno = __keymgr_method_keymgr_add;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_keycall_keymgr_add(__rref, rpc_info, NULL, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_keycall_keymgr_add(int shm_id, struct key_add_param param)
{
	return actvxactcall_keycall_keymgr_add(false, false, shm_id, param);
}

static inline int __attribute__((always_inline)) actvcapcall_keycall_keymgr_add(rref_t __rref, int shm_id, struct key_add_param param)
{
	return actvxactcapcall_keycall_keymgr_add(false, false, __rref, shm_id, param);
}

extern int __actvcall_keycall_keymgr_request(unsigned long long __rpc_info, void *__buf, int shm_id, struct key_request_param param);


extern int __actvcapcall_keycall_keymgr_request(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct key_request_param param);


static inline int __attribute__((always_inline)) actvxactcall_keycall_keymgr_request(bool is_xact_fwd, bool is_xact_allow_refwd, int shm_id, struct key_request_param param)
{
	const unsigned long __callno = __keymgr_method_keymgr_request;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_keycall_keymgr_request(rpc_info, NULL, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_keycall_keymgr_request(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int shm_id, struct key_request_param param)
{
	const unsigned long __callno = __keymgr_method_keymgr_request;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_keycall_keymgr_request(__rref, rpc_info, NULL, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_keycall_keymgr_request(int shm_id, struct key_request_param param)
{
	return actvxactcall_keycall_keymgr_request(false, false, shm_id, param);
}

static inline int __attribute__((always_inline)) actvcapcall_keycall_keymgr_request(rref_t __rref, int shm_id, struct key_request_param param)
{
	return actvxactcapcall_keycall_keymgr_request(false, false, __rref, shm_id, param);
}

extern int __actvcall_keycall_keymgr_control(unsigned long long __rpc_info, void *__buf, int shm_id, struct keyctl_param param);


extern int __actvcapcall_keycall_keymgr_control(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct keyctl_param param);


static inline int __attribute__((always_inline)) actvxactcall_keycall_keymgr_control(bool is_xact_fwd, bool is_xact_allow_refwd, int shm_id, struct keyctl_param param, struct __actvret_keycall_keymgr_control *__ret)
{
	const unsigned long __callno = __keymgr_method_keymgr_control;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_keycall_keymgr_control(rpc_info, __ret, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_keycall_keymgr_control(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int shm_id, struct keyctl_param param, struct __actvret_keycall_keymgr_control *__ret)
{
	const unsigned long __callno = __keymgr_method_keymgr_control;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_keycall_keymgr_control(__rref, rpc_info, __ret, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_keycall_keymgr_control(int shm_id, struct keyctl_param param, struct __actvret_keycall_keymgr_control *__ret)
{
	return actvxactcall_keycall_keymgr_control(false, false, shm_id, param, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_keycall_keymgr_control(rref_t __rref, int shm_id, struct keyctl_param param, struct __actvret_keycall_keymgr_control *__ret)
{
	return actvxactcapcall_keycall_keymgr_control(false, false, __rref, shm_id, param, __ret);
}

#endif
#ifdef __sysif_server_keymgr_no_compat32_handlers__
# define __keymgr_method_MAX __keymgr_method_MAX_NOCOMPAT
#else
# define __keymgr_method_MAX __keymgr_method_MAX_COMPAT
#endif
#include <libsysif/utils.h>
#include <asm/actv_rpc.h>
#include <asm/types.h>
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
extern int actvhdlr_keyhandler_keymgr_add(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);


extern int actvhdlr_keyhandler_keymgr_request(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);


extern int actvhdlr_keyhandler_keymgr_control(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);


#else
extern int actvhdlr_keyhandler_keymgr_add(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);


extern int __actvshadowhdlr_keyhandler_keymgr_add(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_keyhandler_keymgr_request(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);


extern int __actvshadowhdlr_keyhandler_keymgr_request(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_keyhandler_keymgr_control(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);


extern int __actvshadowhdlr_keyhandler_keymgr_control(unsigned long long sender, unsigned long credential, ...);


#endif
static inline struct __actvret_keycall_keymgr_add* actvhdlr_keyhandler_keymgr_add_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_keycall_keymgr_add));
	return (struct __actvret_keycall_keymgr_add*)__ret;
}

static inline struct __actvret_keycall_keymgr_request* actvhdlr_keyhandler_keymgr_request_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_keycall_keymgr_request));
	return (struct __actvret_keycall_keymgr_request*)__ret;
}

static inline struct __actvret_keycall_keymgr_control* actvhdlr_keyhandler_keymgr_control_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_keycall_keymgr_control));
	return (struct __actvret_keycall_keymgr_control*)__ret;
}

#ifdef __sysif_server_keymgr_no_compat32_handlers__
#ifdef __HOST_LLT__
union keymgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union keymgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union keymgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
#ifdef __HOST_LLT__
union keymgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p__actvbridgehdlr_keyhandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_keyhandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_keyhandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union keymgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p__actvbridgehdlr_keyhandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_keyhandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_keyhandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union keymgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_keyhandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p__actvbridgehdlr_keyhandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_keyhandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_keyhandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#endif
#endif
extern union keymgr_hdlrs_union sysif_keymgr_actvhdlr_table[__keymgr_method_MAX];

extern union keymgr_hdlrs_union sysif_keymgr_actvcapcallhdlr_table[__keymgr_method_MAX];

extern void sysif_show_keymgr_methods(void);


#ifdef SYSIF_GEN_IFACE
#include <stdint.h>
#include <asm/actv_rpc.h>
#include <hongmeng/syscall.h>
#include <hongmeng/panic.h>
#include <hongmeng/errno.h>
#include <libstrict/strict.h>
#include <libhwsecurec/securec.h>
#include <libsysif/base/server_arg_compat.h>
#ifdef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
static int __opt_nonoframe __actvbridgehdlr_keyhandler_keymgr_add(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_add_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_keyhandler_keymgr_add(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_add_param, param));
}

static int __opt_nonoframe __actvbridgehdlr_keyhandler_keymgr_request(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_request(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_request_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_keyhandler_keymgr_request(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_request(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_request_param, param));
}

static int __opt_nonoframe __actvbridgehdlr_keyhandler_keymgr_control(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_control(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct keyctl_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_keyhandler_keymgr_control(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_control(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct keyctl_param, param));
}

#ifndef __sysif_server_keymgr_no_compat32_handlers__
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
struct compat_x3 {
	unsigned int reserverd;
	unsigned int w3;
};

#else
struct compat_x3 {
	unsigned int w3;
	unsigned int reserverd;
};

#endif
static int __opt_nonoframe __actvbridgehdlr_keyhandler_compat_keymgr_add(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct key_add_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct key_add_param);
		type = __type_of(struct key_add_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct key_add_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_add(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_keyhandler_compat_keymgr_add(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct key_add_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct key_add_param);
		type = __type_of(struct key_add_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct key_add_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_add(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgehdlr_keyhandler_compat_keymgr_request(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct key_request_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct key_request_param);
		type = __type_of(struct key_request_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct key_request_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_request(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_keyhandler_compat_keymgr_request(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct key_request_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct key_request_param);
		type = __type_of(struct key_request_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct key_request_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_request(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgehdlr_keyhandler_compat_keymgr_control(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct keyctl_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct keyctl_param);
		type = __type_of(struct keyctl_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct keyctl_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_control(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_keyhandler_compat_keymgr_control(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct keyctl_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct keyctl_param);
		type = __type_of(struct keyctl_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct keyctl_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_keyhandler_keymgr_control(sender, credential, _shm_id, _param);
}

#endif
#else
static int __opt_nonoframe __actvbridgehdlr_keyhandler_keymgr_add(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_keyhandler_keymgr_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_add_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_keyhandler_keymgr_add(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_keyhandler_keymgr_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_add_param, param));
}

static int __opt_nonoframe __actvbridgehdlr_keyhandler_keymgr_request(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_keyhandler_keymgr_request(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_request_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_keyhandler_keymgr_request(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_keyhandler_keymgr_request(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_request_param, param));
}

static int __opt_nonoframe __actvbridgehdlr_keyhandler_keymgr_control(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_keyhandler_keymgr_control(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct keyctl_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_keyhandler_keymgr_control(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_keyhandler_keymgr_control(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct keyctl_param, param));
}

#endif
#ifdef __sysif_server_keymgr_no_compat32_handlers__
union keymgr_hdlrs_union sysif_keymgr_actvhdlr_table[__keymgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __keymgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__keymgr_method_keymgr_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__keymgr_method_keymgr_add] = {
		.p__actvbridgehdlr_keyhandler_keymgr_add = (&__actvbridgehdlr_keyhandler_keymgr_add)
	},
	[__keymgr_method_keymgr_request] = {
		.p__actvbridgehdlr_keyhandler_keymgr_request = (&__actvbridgehdlr_keyhandler_keymgr_request)
	},
	[__keymgr_method_keymgr_control] = {
		.p__actvbridgehdlr_keyhandler_keymgr_control = (&__actvbridgehdlr_keyhandler_keymgr_control)
	}
};

union keymgr_hdlrs_union sysif_keymgr_actvcapcallhdlr_table[__keymgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __keymgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__keymgr_method_keymgr_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__keymgr_method_keymgr_add] = {
		.p__actvbridgecapcallhdlr_keyhandler_keymgr_add = (&__actvbridgecapcallhdlr_keyhandler_keymgr_add)
	},
	[__keymgr_method_keymgr_request] = {
		.p__actvbridgecapcallhdlr_keyhandler_keymgr_request = (&__actvbridgecapcallhdlr_keyhandler_keymgr_request)
	},
	[__keymgr_method_keymgr_control] = {
		.p__actvbridgecapcallhdlr_keyhandler_keymgr_control = (&__actvbridgecapcallhdlr_keyhandler_keymgr_control)
	}
};

#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
union keymgr_hdlrs_union sysif_keymgr_actvhdlr_table[__keymgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __keymgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__keymgr_method_keymgr_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__keymgr_method_keymgr_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__keymgr_method_keymgr_add * 2] = {
		.p__actvbridgehdlr_keyhandler_keymgr_add = (&__actvbridgehdlr_keyhandler_keymgr_add)
	},
	[__keymgr_method_keymgr_add * 2 + 1] = {
		.p__actvbridgehdlr_keyhandler_compat_keymgr_add = (&__actvbridgehdlr_keyhandler_compat_keymgr_add)
	},
	[__keymgr_method_keymgr_request * 2] = {
		.p__actvbridgehdlr_keyhandler_keymgr_request = (&__actvbridgehdlr_keyhandler_keymgr_request)
	},
	[__keymgr_method_keymgr_request * 2 + 1] = {
		.p__actvbridgehdlr_keyhandler_compat_keymgr_request = (&__actvbridgehdlr_keyhandler_compat_keymgr_request)
	},
	[__keymgr_method_keymgr_control * 2] = {
		.p__actvbridgehdlr_keyhandler_keymgr_control = (&__actvbridgehdlr_keyhandler_keymgr_control)
	},
	[__keymgr_method_keymgr_control * 2 + 1] = {
		.p__actvbridgehdlr_keyhandler_compat_keymgr_control = (&__actvbridgehdlr_keyhandler_compat_keymgr_control)
	}
};

#endif
union keymgr_hdlrs_union sysif_keymgr_actvcapcallhdlr_table[__keymgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __keymgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__keymgr_method_keymgr_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__keymgr_method_keymgr_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__keymgr_method_keymgr_add * 2] = {
		.p__actvbridgecapcallhdlr_keyhandler_keymgr_add = (&__actvbridgecapcallhdlr_keyhandler_keymgr_add)
	},
	[__keymgr_method_keymgr_add * 2 + 1] = {
		.p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_add = (&__actvbridgecapcallhdlr_keyhandler_compat_keymgr_add)
	},
	[__keymgr_method_keymgr_request * 2] = {
		.p__actvbridgecapcallhdlr_keyhandler_keymgr_request = (&__actvbridgecapcallhdlr_keyhandler_keymgr_request)
	},
	[__keymgr_method_keymgr_request * 2 + 1] = {
		.p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_request = (&__actvbridgecapcallhdlr_keyhandler_compat_keymgr_request)
	},
	[__keymgr_method_keymgr_control * 2] = {
		.p__actvbridgecapcallhdlr_keyhandler_keymgr_control = (&__actvbridgecapcallhdlr_keyhandler_keymgr_control)
	},
	[__keymgr_method_keymgr_control * 2 + 1] = {
		.p__actvbridgecapcallhdlr_keyhandler_compat_keymgr_control = (&__actvbridgecapcallhdlr_keyhandler_compat_keymgr_control)
	}
};

#endif
void sysif_show_keymgr_methods(void)
{
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "keycall", "keymgr", "add", __keymgr_method_keymgr_add);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "keyhandler", "keymgr", "add", __keymgr_method_keymgr_add);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "keycall", "keymgr", "request", __keymgr_method_keymgr_request);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "keyhandler", "keymgr", "request", __keymgr_method_keymgr_request);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "keycall", "keymgr", "control", __keymgr_method_keymgr_control);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "keyhandler", "keymgr", "control", __keymgr_method_keymgr_control);
	hm_info("%s_%s, max method num: %d\n", "keymgr", "method", __keymgr_method_MAX);
}

#endif
#endif
