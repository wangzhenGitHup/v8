/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for freqmgr
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/freqmgr/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/freqmgr/libsysif/freqmgr/api.h --server-dest ../image/usr/include/generated/sysif_server/freqmgr/libsysif/freqmgr/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_FREQMGR_SERVER_H
#define LIBSYSIF_FREQMGR_SERVER_H
#ifndef LIBSYSIF_FREQMGR_COMMON_H
#define LIBSYSIF_FREQMGR_COMMON_H
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
#include <libbunch/bunch_ipc.h>
struct __actvret_fmcall_sysfs_read {
};

struct __actvret_fmcall_sysfs_write {
};

union __actvret_fmcall {
	struct __actvret_fmcall_sysfs_read sysfs_read;
	struct __actvret_fmcall_sysfs_write sysfs_write;
};

enum __freqmgr_mgr {
	__freqmgr_INVAL_mgr=0,
	__freqmgr_sysfs_mgr,
	__freqmgr_MAX_mgr,
};

#define __freqmgr_method_MIN __ACTV_HIGHTABLE_START
#define __freqmgr_method_sysfs_read (__ACTV_HIGHTABLE_START + 1)
#define __freqmgr_method_sysfs_write (__ACTV_HIGHTABLE_START + 2)
#define __freqmgr_method_sysfs_rsvd_2 (__ACTV_HIGHTABLE_START + 3)
#define __freqmgr_method_sysfs_rsvd_1 (__ACTV_HIGHTABLE_START + 4)
#define __freqmgr_method_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + 5)
#define __freqmgr_method_MAX_COMPAT ((__ACTV_HIGHTABLE_START + 5) * 2)
raw_static_assert(sizeof(struct __actvret_fmcall_sysfs_read) < 512,
                fmcall_sysfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fmcall_sysfs_write) < 512,
                fmcall_sysfs_write_too_many_actvret_data);
raw_static_assert(sizeof(union __actvret_fmcall) < 512,
        fmcall_too_many_actvret_data);
extern int __actvcall_fmcall_sysfs_read(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_fmcall_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_fmcall_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __freqmgr_method_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fmcall_sysfs_read(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fmcall_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __freqmgr_method_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fmcall_sysfs_read(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fmcall_sysfs_read(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fmcall_sysfs_read(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fmcall_sysfs_read(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fmcall_sysfs_read(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fmcall_sysfs_write(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_fmcall_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_fmcall_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __freqmgr_method_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fmcall_sysfs_write(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fmcall_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __freqmgr_method_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fmcall_sysfs_write(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fmcall_sysfs_write(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fmcall_sysfs_write(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fmcall_sysfs_write(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fmcall_sysfs_write(false, false, __rref, ___void_buf, ___void_buf_sz);
}

#endif
#ifdef __sysif_server_freqmgr_no_compat32_handlers__
# define __freqmgr_method_MAX __freqmgr_method_MAX_NOCOMPAT
#else
# define __freqmgr_method_MAX __freqmgr_method_MAX_COMPAT
#endif
#include <libsysif/utils.h>
#include <asm/actv_rpc.h>
#include <asm/types.h>
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
extern int actvhdlr_fmhandler_sysfs_read(unsigned long long sender, unsigned long credential);


extern int actvhdlr_fmhandler_sysfs_write(unsigned long long sender, unsigned long credential);


#else
extern int actvhdlr_fmhandler_sysfs_read(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_fmhandler_sysfs_read(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_fmhandler_sysfs_write(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_fmhandler_sysfs_write(unsigned long long sender, unsigned long credential, ...);


#endif
static inline struct __actvret_fmcall_sysfs_read* actvhdlr_fmhandler_sysfs_read_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_fmcall_sysfs_read));
	return (struct __actvret_fmcall_sysfs_read*)__ret;
}

static inline struct __actvret_fmcall_sysfs_write* actvhdlr_fmhandler_sysfs_write_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_fmcall_sysfs_write));
	return (struct __actvret_fmcall_sysfs_write*)__ret;
}

#ifdef __sysif_server_freqmgr_no_compat32_handlers__
#ifdef __HOST_LLT__
union freqmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union freqmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union freqmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
#ifdef __HOST_LLT__
union freqmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_fmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_fmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_fmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_fmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union freqmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_fmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_fmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_fmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_fmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union freqmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_fmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_fmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_fmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_fmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_fmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#endif
#endif
extern union freqmgr_hdlrs_union sysif_freqmgr_actvhdlr_table[__freqmgr_method_MAX];

extern union freqmgr_hdlrs_union sysif_freqmgr_actvcapcallhdlr_table[__freqmgr_method_MAX];

extern void sysif_show_freqmgr_methods(void);


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
static int __opt_nonoframe __actvbridgehdlr_fmhandler_sysfs_read(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_fmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_fmhandler_sysfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_fmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_fmhandler_sysfs_write(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_fmhandler_sysfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_fmhandler_sysfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_fmhandler_sysfs_write(sender, credential);
}

#ifndef __sysif_server_freqmgr_no_compat32_handlers__
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
static int __opt_nonoframe __actvbridgehdlr_fmhandler_compat_sysfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_fmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_fmhandler_compat_sysfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_fmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_fmhandler_compat_sysfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_fmhandler_sysfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_fmhandler_compat_sysfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_fmhandler_sysfs_write(sender, credential);
}

#endif
#else
static int __opt_nonoframe __actvbridgehdlr_fmhandler_sysfs_read(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_fmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_fmhandler_sysfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_fmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_fmhandler_sysfs_write(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_fmhandler_sysfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_fmhandler_sysfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_fmhandler_sysfs_write(sender, credential);
}

#endif
#ifdef __sysif_server_freqmgr_no_compat32_handlers__
union freqmgr_hdlrs_union sysif_freqmgr_actvhdlr_table[__freqmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __freqmgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_read] = {
		.p__actvbridgehdlr_fmhandler_sysfs_read = (&__actvbridgehdlr_fmhandler_sysfs_read)
	},
	[__freqmgr_method_sysfs_write] = {
		.p__actvbridgehdlr_fmhandler_sysfs_write = (&__actvbridgehdlr_fmhandler_sysfs_write)
	}
};

union freqmgr_hdlrs_union sysif_freqmgr_actvcapcallhdlr_table[__freqmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __freqmgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_read] = {
		.p__actvbridgecapcallhdlr_fmhandler_sysfs_read = (&__actvbridgecapcallhdlr_fmhandler_sysfs_read)
	},
	[__freqmgr_method_sysfs_write] = {
		.p__actvbridgecapcallhdlr_fmhandler_sysfs_write = (&__actvbridgecapcallhdlr_fmhandler_sysfs_write)
	}
};

#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
union freqmgr_hdlrs_union sysif_freqmgr_actvhdlr_table[__freqmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __freqmgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_read * 2] = {
		.p__actvbridgehdlr_fmhandler_sysfs_read = (&__actvbridgehdlr_fmhandler_sysfs_read)
	},
	[__freqmgr_method_sysfs_read * 2 + 1] = {
		.p__actvbridgehdlr_fmhandler_compat_sysfs_read = (&__actvbridgehdlr_fmhandler_compat_sysfs_read)
	},
	[__freqmgr_method_sysfs_write * 2] = {
		.p__actvbridgehdlr_fmhandler_sysfs_write = (&__actvbridgehdlr_fmhandler_sysfs_write)
	},
	[__freqmgr_method_sysfs_write * 2 + 1] = {
		.p__actvbridgehdlr_fmhandler_compat_sysfs_write = (&__actvbridgehdlr_fmhandler_compat_sysfs_write)
	}
};

#endif
union freqmgr_hdlrs_union sysif_freqmgr_actvcapcallhdlr_table[__freqmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __freqmgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__freqmgr_method_sysfs_read * 2] = {
		.p__actvbridgecapcallhdlr_fmhandler_sysfs_read = (&__actvbridgecapcallhdlr_fmhandler_sysfs_read)
	},
	[__freqmgr_method_sysfs_read * 2 + 1] = {
		.p__actvbridgecapcallhdlr_fmhandler_compat_sysfs_read = (&__actvbridgecapcallhdlr_fmhandler_compat_sysfs_read)
	},
	[__freqmgr_method_sysfs_write * 2] = {
		.p__actvbridgecapcallhdlr_fmhandler_sysfs_write = (&__actvbridgecapcallhdlr_fmhandler_sysfs_write)
	},
	[__freqmgr_method_sysfs_write * 2 + 1] = {
		.p__actvbridgecapcallhdlr_fmhandler_compat_sysfs_write = (&__actvbridgecapcallhdlr_fmhandler_compat_sysfs_write)
	}
};

#endif
void sysif_show_freqmgr_methods(void)
{
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "fmcall", "sysfs", "read", __freqmgr_method_sysfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "fmhandler", "sysfs", "read", __freqmgr_method_sysfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "fmcall", "sysfs", "write", __freqmgr_method_sysfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "fmhandler", "sysfs", "write", __freqmgr_method_sysfs_write);
	hm_info("%s_%s, max method num: %d\n", "freqmgr", "method", __freqmgr_method_MAX);
}

#endif
#endif
