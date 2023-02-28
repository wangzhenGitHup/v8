/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for keymgr
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/keymgr/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/keymgr/libsysif/keymgr/api.h --server-dest ../image/usr/include/generated/sysif_server/keymgr/libsysif/keymgr/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_KEYMGR_API_H
#define LIBSYSIF_KEYMGR_API_H
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
#ifdef SYSIF_GEN_IFACE
#include <hmkernel/compiler.h>
#include <asm/actv_rpc.h>
#include <hongmeng/errno.h>
#include <hongmeng/syscall.h>
#include <hongmeng/panic.h>
#include <libstrict/strict.h>
static int __used __noinline __opt_noframe __internal_rpccall_nobuf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_buf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_retbuf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_fallback(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_nobuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(NoBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_buf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(SendBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_retbuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(RetBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_fallback(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(, ret);
	return ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_keycall_keymgr_add(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_keycall_keymgr_add(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_keycall_keymgr_add(unsigned long long __rpc_info, void *__buf, int shm_id, struct key_add_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct key_add_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcall_keycall_keymgr_add(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_keycall_keymgr_add(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct key_add_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct key_add_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcapcall_keycall_keymgr_add(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_keycall_keymgr_request(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_keycall_keymgr_request(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_keycall_keymgr_request(unsigned long long __rpc_info, void *__buf, int shm_id, struct key_request_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct key_request_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcall_keycall_keymgr_request(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_keycall_keymgr_request(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct key_request_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct key_request_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcapcall_keycall_keymgr_request(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_keycall_keymgr_control(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_keycall_keymgr_control(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_keycall_keymgr_control(unsigned long long __rpc_info, void *__buf, int shm_id, struct keyctl_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct keyctl_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcall_keycall_keymgr_control(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_keycall_keymgr_control(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct keyctl_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct keyctl_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcapcall_keycall_keymgr_control(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

#endif
#endif
