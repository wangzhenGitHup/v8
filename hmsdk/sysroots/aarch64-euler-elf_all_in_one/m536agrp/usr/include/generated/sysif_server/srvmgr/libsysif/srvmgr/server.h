/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for srvmgr
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/srvmgr/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/srvmgr/libsysif/srvmgr/api.h --server-dest ../image/usr/include/generated/sysif_server/srvmgr/libsysif/srvmgr/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_SRVMGR_SERVER_H
#define LIBSYSIF_SRVMGR_SERVER_H
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
#ifdef __sysif_server_srvmgr_no_compat32_handlers__
# define __srvmgr_method_MAX __srvmgr_method_MAX_NOCOMPAT
#else
# define __srvmgr_method_MAX __srvmgr_method_MAX_COMPAT
#endif
#include <libsysif/utils.h>
#include <asm/actv_rpc.h>
#include <asm/types.h>
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
extern int actvhdlr_srvhandler_srvmgr_shutdown(unsigned long long sender, unsigned long credential);


extern int actvhdlr_srvhandler_srvmgr_notify(unsigned long long sender, unsigned long credential, int event);


extern int actvhdlr_srvhandler_srvmgr_reboot(unsigned long long sender, unsigned long credential, struct reboot_reason reboot);


#else
extern int actvhdlr_srvhandler_srvmgr_shutdown(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_srvhandler_srvmgr_shutdown(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_srvhandler_srvmgr_notify(unsigned long long sender, unsigned long credential, int event);


extern int __actvshadowhdlr_srvhandler_srvmgr_notify(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_srvhandler_srvmgr_reboot(unsigned long long sender, unsigned long credential, struct reboot_reason reboot);


extern int __actvshadowhdlr_srvhandler_srvmgr_reboot(unsigned long long sender, unsigned long credential, ...);


#endif
static inline struct __actvret_srvcall_srvmgr_shutdown* actvhdlr_srvhandler_srvmgr_shutdown_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_srvcall_srvmgr_shutdown));
	return (struct __actvret_srvcall_srvmgr_shutdown*)__ret;
}

static inline struct __actvret_srvcall_srvmgr_notify* actvhdlr_srvhandler_srvmgr_notify_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_srvcall_srvmgr_notify));
	return (struct __actvret_srvcall_srvmgr_notify*)__ret;
}

static inline struct __actvret_srvcall_srvmgr_reboot* actvhdlr_srvhandler_srvmgr_reboot_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_srvcall_srvmgr_reboot));
	return (struct __actvret_srvcall_srvmgr_reboot*)__ret;
}

#ifdef __sysif_server_srvmgr_no_compat32_handlers__
#ifdef __HOST_LLT__
union srvmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, int event);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int event);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, struct reboot_reason reboot);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_reason reboot);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union srvmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, int event);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int event);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, struct reboot_reason reboot);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_reason reboot);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union srvmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, int event);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int event);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, struct reboot_reason reboot);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_reason reboot);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
#ifdef __HOST_LLT__
union srvmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, int event);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int event);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, struct reboot_reason reboot);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_reason reboot);
	int (*p__actvbridgehdlr_srvhandler_compat_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_srvhandler_compat_srvmgr_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_srvhandler_compat_srvmgr_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union srvmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, int event);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int event);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, struct reboot_reason reboot);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_reason reboot);
	int (*p__actvbridgehdlr_srvhandler_compat_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_srvhandler_compat_srvmgr_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_srvhandler_compat_srvmgr_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union srvmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, int event);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int event);
	int (*p__actvbridgehdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, struct reboot_reason reboot);
	int (*p__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_reason reboot);
	int (*p__actvbridgehdlr_srvhandler_compat_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_srvhandler_compat_srvmgr_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_srvhandler_compat_srvmgr_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#endif
#endif
extern union srvmgr_hdlrs_union sysif_srvmgr_actvhdlr_table[__srvmgr_method_MAX];

extern union srvmgr_hdlrs_union sysif_srvmgr_actvcapcallhdlr_table[__srvmgr_method_MAX];

extern void sysif_show_srvmgr_methods(void);


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
static int __opt_nonoframe __actvbridgehdlr_srvhandler_srvmgr_shutdown(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_srvhandler_srvmgr_shutdown(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_srvhandler_srvmgr_shutdown(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_srvhandler_srvmgr_notify(unsigned long long sender, unsigned long credential, int event)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_srvhandler_srvmgr_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, event));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_srvhandler_srvmgr_notify(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int event)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_srvhandler_srvmgr_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, event));
}

static int __opt_nonoframe __actvbridgehdlr_srvhandler_srvmgr_reboot(unsigned long long sender, unsigned long credential, struct reboot_reason reboot)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_reason), __arch_actv_rpc_stksz_alignment(struct reboot_reason));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_srvhandler_srvmgr_reboot(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_reason, reboot));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_srvhandler_srvmgr_reboot(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_reason reboot)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_reason), __arch_actv_rpc_stksz_alignment(struct reboot_reason));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_srvhandler_srvmgr_reboot(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_reason, reboot));
}

#ifndef __sysif_server_srvmgr_no_compat32_handlers__
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
static int __opt_nonoframe __actvbridgehdlr_srvhandler_compat_srvmgr_shutdown(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_srvhandler_srvmgr_shutdown(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_srvhandler_compat_srvmgr_shutdown(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_srvhandler_srvmgr_shutdown(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_srvhandler_compat_srvmgr_notify(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	int __maybe_unused _event;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_event, data, 0, arg_sz, model, type, int, _event)
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
	return __actvshadowhdlr_srvhandler_srvmgr_notify(sender, credential, _event);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_srvhandler_compat_srvmgr_notify(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	int __maybe_unused _event;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_event, data, 0, arg_sz, model, type, int, _event)
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
	return __actvshadowhdlr_srvhandler_srvmgr_notify(sender, credential, _event);
}

static int __opt_nonoframe __actvbridgehdlr_srvhandler_compat_srvmgr_reboot(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct reboot_reason __maybe_unused _reboot;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct reboot_reason);
		type = __type_of(struct reboot_reason);
		__fetch_one_arg((void*)&_reboot, data, 0, arg_sz, model, type, struct reboot_reason, _reboot)
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
	return __actvshadowhdlr_srvhandler_srvmgr_reboot(sender, credential, _reboot);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_srvhandler_compat_srvmgr_reboot(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct reboot_reason __maybe_unused _reboot;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct reboot_reason);
		type = __type_of(struct reboot_reason);
		__fetch_one_arg((void*)&_reboot, data, 0, arg_sz, model, type, struct reboot_reason, _reboot)
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
	return __actvshadowhdlr_srvhandler_srvmgr_reboot(sender, credential, _reboot);
}

#endif
#else
static int __opt_nonoframe __actvbridgehdlr_srvhandler_srvmgr_shutdown(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_srvhandler_srvmgr_shutdown(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_srvhandler_srvmgr_shutdown(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_srvhandler_srvmgr_notify(unsigned long long sender, unsigned long credential, int event)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_srvhandler_srvmgr_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, event));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_srvhandler_srvmgr_notify(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int event)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_srvhandler_srvmgr_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, event));
}

static int __opt_nonoframe __actvbridgehdlr_srvhandler_srvmgr_reboot(unsigned long long sender, unsigned long credential, struct reboot_reason reboot)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_reason), __arch_actv_rpc_stksz_alignment(struct reboot_reason));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_srvhandler_srvmgr_reboot(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_reason, reboot));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_srvhandler_srvmgr_reboot(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_reason reboot)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_reason), __arch_actv_rpc_stksz_alignment(struct reboot_reason));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_srvhandler_srvmgr_reboot(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_reason, reboot));
}

#endif
#ifdef __sysif_server_srvmgr_no_compat32_handlers__
union srvmgr_hdlrs_union sysif_srvmgr_actvhdlr_table[__srvmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __srvmgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__srvmgr_method_srvmgr_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__srvmgr_method_srvmgr_shutdown] = {
		.p__actvbridgehdlr_srvhandler_srvmgr_shutdown = (&__actvbridgehdlr_srvhandler_srvmgr_shutdown)
	},
	[__srvmgr_method_srvmgr_notify] = {
		.p__actvbridgehdlr_srvhandler_srvmgr_notify = (&__actvbridgehdlr_srvhandler_srvmgr_notify)
	},
	[__srvmgr_method_srvmgr_reboot] = {
		.p__actvbridgehdlr_srvhandler_srvmgr_reboot = (&__actvbridgehdlr_srvhandler_srvmgr_reboot)
	}
};

union srvmgr_hdlrs_union sysif_srvmgr_actvcapcallhdlr_table[__srvmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __srvmgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__srvmgr_method_srvmgr_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__srvmgr_method_srvmgr_shutdown] = {
		.p__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown = (&__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown)
	},
	[__srvmgr_method_srvmgr_notify] = {
		.p__actvbridgecapcallhdlr_srvhandler_srvmgr_notify = (&__actvbridgecapcallhdlr_srvhandler_srvmgr_notify)
	},
	[__srvmgr_method_srvmgr_reboot] = {
		.p__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot = (&__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot)
	}
};

#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
union srvmgr_hdlrs_union sysif_srvmgr_actvhdlr_table[__srvmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __srvmgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__srvmgr_method_srvmgr_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__srvmgr_method_srvmgr_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__srvmgr_method_srvmgr_shutdown * 2] = {
		.p__actvbridgehdlr_srvhandler_srvmgr_shutdown = (&__actvbridgehdlr_srvhandler_srvmgr_shutdown)
	},
	[__srvmgr_method_srvmgr_shutdown * 2 + 1] = {
		.p__actvbridgehdlr_srvhandler_compat_srvmgr_shutdown = (&__actvbridgehdlr_srvhandler_compat_srvmgr_shutdown)
	},
	[__srvmgr_method_srvmgr_notify * 2] = {
		.p__actvbridgehdlr_srvhandler_srvmgr_notify = (&__actvbridgehdlr_srvhandler_srvmgr_notify)
	},
	[__srvmgr_method_srvmgr_notify * 2 + 1] = {
		.p__actvbridgehdlr_srvhandler_compat_srvmgr_notify = (&__actvbridgehdlr_srvhandler_compat_srvmgr_notify)
	},
	[__srvmgr_method_srvmgr_reboot * 2] = {
		.p__actvbridgehdlr_srvhandler_srvmgr_reboot = (&__actvbridgehdlr_srvhandler_srvmgr_reboot)
	},
	[__srvmgr_method_srvmgr_reboot * 2 + 1] = {
		.p__actvbridgehdlr_srvhandler_compat_srvmgr_reboot = (&__actvbridgehdlr_srvhandler_compat_srvmgr_reboot)
	}
};

#endif
union srvmgr_hdlrs_union sysif_srvmgr_actvcapcallhdlr_table[__srvmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __srvmgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__srvmgr_method_srvmgr_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__srvmgr_method_srvmgr_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__srvmgr_method_srvmgr_shutdown * 2] = {
		.p__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown = (&__actvbridgecapcallhdlr_srvhandler_srvmgr_shutdown)
	},
	[__srvmgr_method_srvmgr_shutdown * 2 + 1] = {
		.p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_shutdown = (&__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_shutdown)
	},
	[__srvmgr_method_srvmgr_notify * 2] = {
		.p__actvbridgecapcallhdlr_srvhandler_srvmgr_notify = (&__actvbridgecapcallhdlr_srvhandler_srvmgr_notify)
	},
	[__srvmgr_method_srvmgr_notify * 2 + 1] = {
		.p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_notify = (&__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_notify)
	},
	[__srvmgr_method_srvmgr_reboot * 2] = {
		.p__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot = (&__actvbridgecapcallhdlr_srvhandler_srvmgr_reboot)
	},
	[__srvmgr_method_srvmgr_reboot * 2 + 1] = {
		.p__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_reboot = (&__actvbridgecapcallhdlr_srvhandler_compat_srvmgr_reboot)
	}
};

#endif
void sysif_show_srvmgr_methods(void)
{
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "srvcall", "srvmgr", "shutdown", __srvmgr_method_srvmgr_shutdown);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "srvhandler", "srvmgr", "shutdown", __srvmgr_method_srvmgr_shutdown);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "srvcall", "srvmgr", "notify", __srvmgr_method_srvmgr_notify);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "srvhandler", "srvmgr", "notify", __srvmgr_method_srvmgr_notify);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "srvcall", "srvmgr", "reboot", __srvmgr_method_srvmgr_reboot);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "srvhandler", "srvmgr", "reboot", __srvmgr_method_srvmgr_reboot);
	hm_info("%s_%s, max method num: %d\n", "srvmgr", "method", __srvmgr_method_MAX);
}

int __actvcall_srvcall_srvmgr_shutdown(unsigned long long __rpc_info, void *__buf)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_srvhandler_srvmgr_shutdown((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcapcall_srvcall_srvmgr_shutdown(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_srvhandler_srvmgr_shutdown((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcall_srvcall_srvmgr_notify(unsigned long long __rpc_info, void *__buf, int event)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_srvhandler_srvmgr_notify((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, event);
}

int __actvcapcall_srvcall_srvmgr_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, int event)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_srvhandler_srvmgr_notify((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, event);
}

int __actvcall_srvcall_srvmgr_reboot(unsigned long long __rpc_info, void *__buf, struct reboot_reason reboot)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_srvhandler_srvmgr_reboot((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, reboot);
}

int __actvcapcall_srvcall_srvmgr_reboot(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct reboot_reason reboot)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_srvhandler_srvmgr_reboot((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, reboot);
}

#endif
#endif
