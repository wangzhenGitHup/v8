/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for srvmgr
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/srvmgr/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/srvmgr/libsysif/srvmgr/api.h --server-dest ../image/usr/include/generated/sysif_server/srvmgr/libsysif/srvmgr/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_SRVMGR_API_H
#define LIBSYSIF_SRVMGR_API_H
#ifndef LIBSYSIF_SRVMGR_COMMON_H
#define LIBSYSIF_SRVMGR_COMMON_H
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

#define SRVMGR_SERVER_PATH		"srvmgr-actv"

enum {
	HMINIT_EVENT_TYPE_READY,
};

#define MAX_REASON_LEN 96
struct reboot_reason {
	char reason[MAX_REASON_LEN];
};

raw_static_assert(sizeof(struct reboot_reason) <= 96,
                    srvcall_srvmgr_reboot_arg_reboot_is_too_large);
struct __actvret_srvcall_srvmgr_shutdown {
};

struct __actvret_srvcall_srvmgr_notify {
};

struct __actvret_srvcall_srvmgr_reboot {
};

union __actvret_srvcall {
	struct __actvret_srvcall_srvmgr_shutdown srvmgr_shutdown;
	struct __actvret_srvcall_srvmgr_notify srvmgr_notify;
	struct __actvret_srvcall_srvmgr_reboot srvmgr_reboot;
};

enum __srvmgr_mgr {
	__srvmgr_INVAL_mgr=0,
	__srvmgr_srvmgr_mgr,
	__srvmgr_MAX_mgr,
};

#define __srvmgr_method_MIN __ACTV_HIGHTABLE_START
#define __srvmgr_method_srvmgr_shutdown (__ACTV_HIGHTABLE_START + 1)
#define __srvmgr_method_srvmgr_notify (__ACTV_HIGHTABLE_START + 2)
#define __srvmgr_method_srvmgr_reboot (__ACTV_HIGHTABLE_START + 3)
#define __srvmgr_method_srvmgr_rsvd_1 (__ACTV_HIGHTABLE_START + 4)
#define __srvmgr_method_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + 5)
#define __srvmgr_method_MAX_COMPAT ((__ACTV_HIGHTABLE_START + 5) * 2)
raw_static_assert(sizeof(struct __actvret_srvcall_srvmgr_shutdown) < 512,
                srvcall_srvmgr_shutdown_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_srvcall_srvmgr_notify) < 512,
                srvcall_srvmgr_notify_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_srvcall_srvmgr_reboot) < 512,
                srvcall_srvmgr_reboot_too_many_actvret_data);
raw_static_assert(sizeof(union __actvret_srvcall) < 512,
        srvcall_too_many_actvret_data);
extern int __actvcall_srvcall_srvmgr_shutdown(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_srvcall_srvmgr_shutdown(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_srvcall_srvmgr_shutdown(bool is_xact_fwd, bool is_xact_allow_refwd)
{
	const unsigned long __callno = __srvmgr_method_srvmgr_shutdown;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_srvcall_srvmgr_shutdown(rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_srvcall_srvmgr_shutdown(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref)
{
	const unsigned long __callno = __srvmgr_method_srvmgr_shutdown;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_srvcall_srvmgr_shutdown(__rref, rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_srvcall_srvmgr_shutdown(void)
{
	return actvxactcall_srvcall_srvmgr_shutdown(false, false);
}

static inline int __attribute__((always_inline)) actvcapcall_srvcall_srvmgr_shutdown(rref_t __rref)
{
	return actvxactcapcall_srvcall_srvmgr_shutdown(false, false, __rref);
}

extern int __actvcall_srvcall_srvmgr_notify(unsigned long long __rpc_info, void *__buf, int event);


extern int __actvcapcall_srvcall_srvmgr_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, int event);


static inline int __attribute__((always_inline)) actvxactcall_srvcall_srvmgr_notify(bool is_xact_fwd, bool is_xact_allow_refwd, int event)
{
	const unsigned long __callno = __srvmgr_method_srvmgr_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_srvcall_srvmgr_notify(rpc_info, NULL, event);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_srvcall_srvmgr_notify(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int event)
{
	const unsigned long __callno = __srvmgr_method_srvmgr_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_srvcall_srvmgr_notify(__rref, rpc_info, NULL, event);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_srvcall_srvmgr_notify(int event)
{
	return actvxactcall_srvcall_srvmgr_notify(false, false, event);
}

static inline int __attribute__((always_inline)) actvcapcall_srvcall_srvmgr_notify(rref_t __rref, int event)
{
	return actvxactcapcall_srvcall_srvmgr_notify(false, false, __rref, event);
}

extern int __actvcall_srvcall_srvmgr_reboot(unsigned long long __rpc_info, void *__buf, struct reboot_reason reboot);


extern int __actvcapcall_srvcall_srvmgr_reboot(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct reboot_reason reboot);


static inline int __attribute__((always_inline)) actvxactcall_srvcall_srvmgr_reboot(bool is_xact_fwd, bool is_xact_allow_refwd, struct reboot_reason reboot)
{
	const unsigned long __callno = __srvmgr_method_srvmgr_reboot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_reason), __arch_actv_rpc_stksz_alignment(struct reboot_reason));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_srvcall_srvmgr_reboot(rpc_info, NULL, reboot);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_srvcall_srvmgr_reboot(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct reboot_reason reboot)
{
	const unsigned long __callno = __srvmgr_method_srvmgr_reboot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_reason), __arch_actv_rpc_stksz_alignment(struct reboot_reason));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_srvcall_srvmgr_reboot(__rref, rpc_info, NULL, reboot);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_srvcall_srvmgr_reboot(struct reboot_reason reboot)
{
	return actvxactcall_srvcall_srvmgr_reboot(false, false, reboot);
}

static inline int __attribute__((always_inline)) actvcapcall_srvcall_srvmgr_reboot(rref_t __rref, struct reboot_reason reboot)
{
	return actvxactcapcall_srvcall_srvmgr_reboot(false, false, __rref, reboot);
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

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_srvcall_srvmgr_shutdown(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_srvcall_srvmgr_shutdown(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_srvcall_srvmgr_shutdown(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_srvcall_srvmgr_shutdown(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_srvcall_srvmgr_shutdown(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_srvcall_srvmgr_shutdown(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_srvcall_srvmgr_notify(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_srvcall_srvmgr_notify(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_srvcall_srvmgr_notify(unsigned long long __rpc_info, void *__buf, int event)
{
	int __ret;
	int __maybe_unused __actv_local_var_event = event;
	__ret = ____actvcall_srvcall_srvmgr_notify(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_srvcall_srvmgr_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, int event)
{
	int __ret;
	int __maybe_unused __actv_local_var_event = event;
	__ret = ____actvcapcall_srvcall_srvmgr_notify(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_srvcall_srvmgr_reboot(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_srvcall_srvmgr_reboot(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_srvcall_srvmgr_reboot(unsigned long long __rpc_info, void *__buf, struct reboot_reason reboot)
{
	int __ret;
	struct reboot_reason __maybe_unused __actv_local_var_reboot = reboot;
	__ret = ____actvcall_srvcall_srvmgr_reboot(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(reboot, __actv_local_var_reboot));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_srvcall_srvmgr_reboot(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct reboot_reason reboot)
{
	int __ret;
	struct reboot_reason __maybe_unused __actv_local_var_reboot = reboot;
	__ret = ____actvcapcall_srvcall_srvmgr_reboot(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(reboot, __actv_local_var_reboot));
	return __ret;
}

#endif
#endif
