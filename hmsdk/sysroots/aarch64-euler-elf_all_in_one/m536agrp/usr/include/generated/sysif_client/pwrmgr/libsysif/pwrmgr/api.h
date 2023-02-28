/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for pwrmgr
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/pwrmgr/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/pwrmgr/libsysif/pwrmgr/api.h --server-dest ../image/usr/include/generated/sysif_server/pwrmgr/libsysif/pwrmgr/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_PWRMGR_API_H
#define LIBSYSIF_PWRMGR_API_H
#ifndef LIBSYSIF_PWRMGR_COMMON_H
#define LIBSYSIF_PWRMGR_COMMON_H
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
#include <libhmpm/shutdown.h>

#define PWRMGR_PATH	"pwrmgr_actv"


#define SUSPEND_STATE_INVALID		(-1)
#define SUSPEND_STATE_MEM		(0)
#define SUSPEND_STATE_MAX		(1)



#include <hmkernel/types.h>



#define WAKELOCK_NAME_MAX	64

#define WL_ACTION_ADD			__U(0)
#define WL_ACTION_REMOVE		__U(1)
#define WL_ACTION_ACQUIRE		__U(2)
#define WL_ACTION_RELEASE		__U(3)

struct wake_lock_name {
	char string[WAKELOCK_NAME_MAX];
};




#include <libhmnotifier/hm_notifier.h>

#define CPUHP_ADD_EVENT		(1U)
#define CPUHP_REMOVE_EVENT	(2U)


raw_static_assert(sizeof(struct reboot_cmd) <= 96,
                    pmcall_shutdown_reboot_enter_arg_cmd_is_too_large);
raw_static_assert(sizeof(struct wake_lock_name) <= 96,
                    pmcall_wakelock_action_arg_name_is_too_large);
raw_static_assert(sizeof(struct wake_lock_name) <= 96,
                    pmcall_wakelock_acquire_timeout_arg_wakelock_is_too_large);
raw_static_assert(sizeof(struct wake_lock_name) <= 96,
                    pmcall_wakelock_stat_arg_name_is_too_large);
raw_static_assert(sizeof(struct bunch_ipc_attr) <= 96,
                    pmcall_wakelock_stat_arg_attr_is_too_large);
raw_static_assert(sizeof(struct hm_notifier_cb) <= 96,
                    pmcall_cpuhp_add_notifier_arg_ops_is_too_large);
raw_static_assert(sizeof(struct hm_notifier_cb) <= 96,
                    pmcall_cpuhp_remove_notifier_arg_ops_is_too_large);
struct __actvret_pmcall_shutdown_enter {
};

struct __actvret_pmcall_shutdown_reboot_enter {
};

struct __actvret_pmcall_suspend_set_state {
};

struct __actvret_pmcall_sysfs_read {
};

struct __actvret_pmcall_sysfs_write {
};

struct __actvret_pmcall_wakelock_action {
};

struct __actvret_pmcall_wakelock_acquire_timeout {
};

struct __actvret_pmcall_wakelock_get_count {
	unsigned int count;
};

struct __actvret_pmcall_wakelock_save_count {
};

struct __actvret_pmcall_wakelock_stat {
};

struct __actvret_pmcall_cpuhp_add_notifier {
};

struct __actvret_pmcall_cpuhp_remove_notifier {
};

struct __actvret_pmcall_cpuhp_action {
};

union __actvret_pmcall {
	struct __actvret_pmcall_shutdown_enter shutdown_enter;
	struct __actvret_pmcall_shutdown_reboot_enter shutdown_reboot_enter;
	struct __actvret_pmcall_suspend_set_state suspend_set_state;
	struct __actvret_pmcall_sysfs_read sysfs_read;
	struct __actvret_pmcall_sysfs_write sysfs_write;
	struct __actvret_pmcall_wakelock_action wakelock_action;
	struct __actvret_pmcall_wakelock_acquire_timeout wakelock_acquire_timeout;
	struct __actvret_pmcall_wakelock_get_count wakelock_get_count;
	struct __actvret_pmcall_wakelock_save_count wakelock_save_count;
	struct __actvret_pmcall_wakelock_stat wakelock_stat;
	struct __actvret_pmcall_cpuhp_add_notifier cpuhp_add_notifier;
	struct __actvret_pmcall_cpuhp_remove_notifier cpuhp_remove_notifier;
	struct __actvret_pmcall_cpuhp_action cpuhp_action;
};

enum __pwrmgr_mgr {
	__pwrmgr_INVAL_mgr=0,
	__pwrmgr_shutdown_mgr,
	__pwrmgr_suspend_mgr,
	__pwrmgr_sysfs_mgr,
	__pwrmgr_wakelock_mgr,
	__pwrmgr_cpuhp_mgr,
	__pwrmgr_MAX_mgr,
};

#define __pwrmgr_method_MIN __ACTV_HIGHTABLE_START
#define __pwrmgr_method_shutdown_enter (__ACTV_HIGHTABLE_START + 1)
#define __pwrmgr_method_shutdown_reboot_enter (__ACTV_HIGHTABLE_START + 2)
#define __pwrmgr_method_shutdown_rsvd_2 (__ACTV_HIGHTABLE_START + 3)
#define __pwrmgr_method_shutdown_rsvd_1 (__ACTV_HIGHTABLE_START + 4)
#define __pwrmgr_method_suspend_set_state (__ACTV_HIGHTABLE_START + 5)
#define __pwrmgr_method_suspend_rsvd_1 (__ACTV_HIGHTABLE_START + 6)
#define __pwrmgr_method_sysfs_read (__ACTV_HIGHTABLE_START + 7)
#define __pwrmgr_method_sysfs_write (__ACTV_HIGHTABLE_START + 8)
#define __pwrmgr_method_sysfs_rsvd_2 (__ACTV_HIGHTABLE_START + 9)
#define __pwrmgr_method_sysfs_rsvd_1 (__ACTV_HIGHTABLE_START + 10)
#define __pwrmgr_method_wakelock_action (__ACTV_HIGHTABLE_START + 11)
#define __pwrmgr_method_wakelock_acquire_timeout (__ACTV_HIGHTABLE_START + 12)
#define __pwrmgr_method_wakelock_get_count (__ACTV_HIGHTABLE_START + 13)
#define __pwrmgr_method_wakelock_save_count (__ACTV_HIGHTABLE_START + 14)
#define __pwrmgr_method_wakelock_stat (__ACTV_HIGHTABLE_START + 15)
#define __pwrmgr_method_wakelock_rsvd_3 (__ACTV_HIGHTABLE_START + 16)
#define __pwrmgr_method_wakelock_rsvd_2 (__ACTV_HIGHTABLE_START + 17)
#define __pwrmgr_method_wakelock_rsvd_1 (__ACTV_HIGHTABLE_START + 18)
#define __pwrmgr_method_cpuhp_add_notifier (__ACTV_HIGHTABLE_START + 19)
#define __pwrmgr_method_cpuhp_remove_notifier (__ACTV_HIGHTABLE_START + 20)
#define __pwrmgr_method_cpuhp_action (__ACTV_HIGHTABLE_START + 21)
#define __pwrmgr_method_cpuhp_rsvd_5 (__ACTV_HIGHTABLE_START + 22)
#define __pwrmgr_method_cpuhp_rsvd_4 (__ACTV_HIGHTABLE_START + 23)
#define __pwrmgr_method_cpuhp_rsvd_3 (__ACTV_HIGHTABLE_START + 24)
#define __pwrmgr_method_cpuhp_rsvd_2 (__ACTV_HIGHTABLE_START + 25)
#define __pwrmgr_method_cpuhp_rsvd_1 (__ACTV_HIGHTABLE_START + 26)
#define __pwrmgr_method_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + 27)
#define __pwrmgr_method_MAX_COMPAT ((__ACTV_HIGHTABLE_START + 27) * 2)
raw_static_assert(sizeof(struct __actvret_pmcall_shutdown_enter) < 512,
                pmcall_shutdown_enter_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_shutdown_reboot_enter) < 512,
                pmcall_shutdown_reboot_enter_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_suspend_set_state) < 512,
                pmcall_suspend_set_state_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_sysfs_read) < 512,
                pmcall_sysfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_sysfs_write) < 512,
                pmcall_sysfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_wakelock_action) < 512,
                pmcall_wakelock_action_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_wakelock_acquire_timeout) < 512,
                pmcall_wakelock_acquire_timeout_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_wakelock_get_count) < 512,
                pmcall_wakelock_get_count_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_wakelock_save_count) < 512,
                pmcall_wakelock_save_count_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_wakelock_stat) < 512,
                pmcall_wakelock_stat_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_cpuhp_add_notifier) < 512,
                pmcall_cpuhp_add_notifier_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_cpuhp_remove_notifier) < 512,
                pmcall_cpuhp_remove_notifier_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_pmcall_cpuhp_action) < 512,
                pmcall_cpuhp_action_too_many_actvret_data);
raw_static_assert(sizeof(union __actvret_pmcall) < 512,
        pmcall_too_many_actvret_data);
extern int __actvcall_pmcall_shutdown_enter(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_pmcall_shutdown_enter(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_shutdown_enter(bool is_xact_fwd, bool is_xact_allow_refwd)
{
	const unsigned long __callno = __pwrmgr_method_shutdown_enter;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_shutdown_enter(rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_shutdown_enter(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref)
{
	const unsigned long __callno = __pwrmgr_method_shutdown_enter;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_shutdown_enter(__rref, rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_shutdown_enter(void)
{
	return actvxactcall_pmcall_shutdown_enter(false, false);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_shutdown_enter(rref_t __rref)
{
	return actvxactcapcall_pmcall_shutdown_enter(false, false, __rref);
}

extern int __actvcall_pmcall_shutdown_reboot_enter(unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd);


extern int __actvcapcall_pmcall_shutdown_reboot_enter(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_shutdown_reboot_enter(bool is_xact_fwd, bool is_xact_allow_refwd, struct reboot_cmd cmd)
{
	const unsigned long __callno = __pwrmgr_method_shutdown_reboot_enter;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_shutdown_reboot_enter(rpc_info, NULL, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_shutdown_reboot_enter(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct reboot_cmd cmd)
{
	const unsigned long __callno = __pwrmgr_method_shutdown_reboot_enter;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_shutdown_reboot_enter(__rref, rpc_info, NULL, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_shutdown_reboot_enter(struct reboot_cmd cmd)
{
	return actvxactcall_pmcall_shutdown_reboot_enter(false, false, cmd);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_shutdown_reboot_enter(rref_t __rref, struct reboot_cmd cmd)
{
	return actvxactcapcall_pmcall_shutdown_reboot_enter(false, false, __rref, cmd);
}

extern int __actvcall_pmcall_suspend_set_state(unsigned long long __rpc_info, void *__buf, int state);


extern int __actvcapcall_pmcall_suspend_set_state(rref_t __rref, unsigned long long __rpc_info, void *__buf, int state);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_suspend_set_state(bool is_xact_fwd, bool is_xact_allow_refwd, int state)
{
	const unsigned long __callno = __pwrmgr_method_suspend_set_state;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_suspend_set_state(rpc_info, NULL, state);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_suspend_set_state(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int state)
{
	const unsigned long __callno = __pwrmgr_method_suspend_set_state;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_suspend_set_state(__rref, rpc_info, NULL, state);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_suspend_set_state(int state)
{
	return actvxactcall_pmcall_suspend_set_state(false, false, state);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_suspend_set_state(rref_t __rref, int state)
{
	return actvxactcapcall_pmcall_suspend_set_state(false, false, __rref, state);
}

extern int __actvcall_pmcall_sysfs_read(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_pmcall_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __pwrmgr_method_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_sysfs_read(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __pwrmgr_method_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_sysfs_read(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_sysfs_read(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_pmcall_sysfs_read(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_sysfs_read(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_pmcall_sysfs_read(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_pmcall_sysfs_write(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_pmcall_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __pwrmgr_method_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_sysfs_write(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __pwrmgr_method_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_sysfs_write(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_sysfs_write(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_pmcall_sysfs_write(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_sysfs_write(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_pmcall_sysfs_write(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_pmcall_wakelock_action(unsigned long long __rpc_info, void *__buf, unsigned int action, struct wake_lock_name name);


extern int __actvcapcall_pmcall_wakelock_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int action, struct wake_lock_name name);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_wakelock_action(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int action, struct wake_lock_name name)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_wakelock_action(rpc_info, NULL, action, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_wakelock_action(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int action, struct wake_lock_name name)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_wakelock_action(__rref, rpc_info, NULL, action, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_wakelock_action(unsigned int action, struct wake_lock_name name)
{
	return actvxactcall_pmcall_wakelock_action(false, false, action, name);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_wakelock_action(rref_t __rref, unsigned int action, struct wake_lock_name name)
{
	return actvxactcapcall_pmcall_wakelock_action(false, false, __rref, action, name);
}

extern int __actvcall_pmcall_wakelock_acquire_timeout(unsigned long long __rpc_info, void *__buf, struct wake_lock_name wakelock, unsigned long msec);


extern int __actvcapcall_pmcall_wakelock_acquire_timeout(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct wake_lock_name wakelock, unsigned long msec);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_wakelock_acquire_timeout(bool is_xact_fwd, bool is_xact_allow_refwd, struct wake_lock_name wakelock, unsigned long msec)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_acquire_timeout;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_wakelock_acquire_timeout(rpc_info, NULL, wakelock, msec);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_wakelock_acquire_timeout(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct wake_lock_name wakelock, unsigned long msec)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_acquire_timeout;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_wakelock_acquire_timeout(__rref, rpc_info, NULL, wakelock, msec);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_wakelock_acquire_timeout(struct wake_lock_name wakelock, unsigned long msec)
{
	return actvxactcall_pmcall_wakelock_acquire_timeout(false, false, wakelock, msec);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_wakelock_acquire_timeout(rref_t __rref, struct wake_lock_name wakelock, unsigned long msec)
{
	return actvxactcapcall_pmcall_wakelock_acquire_timeout(false, false, __rref, wakelock, msec);
}

extern int __actvcall_pmcall_wakelock_get_count(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_pmcall_wakelock_get_count(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_wakelock_get_count(bool is_xact_fwd, bool is_xact_allow_refwd, struct __actvret_pmcall_wakelock_get_count *__ret)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_get_count;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_wakelock_get_count(rpc_info, __ret);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_wakelock_get_count(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct __actvret_pmcall_wakelock_get_count *__ret)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_get_count;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_wakelock_get_count(__rref, rpc_info, __ret);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_wakelock_get_count(struct __actvret_pmcall_wakelock_get_count *__ret)
{
	return actvxactcall_pmcall_wakelock_get_count(false, false, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_wakelock_get_count(rref_t __rref, struct __actvret_pmcall_wakelock_get_count *__ret)
{
	return actvxactcapcall_pmcall_wakelock_get_count(false, false, __rref, __ret);
}

extern int __actvcall_pmcall_wakelock_save_count(unsigned long long __rpc_info, void *__buf, unsigned int count);


extern int __actvcapcall_pmcall_wakelock_save_count(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int count);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_wakelock_save_count(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int count)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_save_count;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_wakelock_save_count(rpc_info, NULL, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_wakelock_save_count(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int count)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_save_count;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_wakelock_save_count(__rref, rpc_info, NULL, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_wakelock_save_count(unsigned int count)
{
	return actvxactcall_pmcall_wakelock_save_count(false, false, count);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_wakelock_save_count(rref_t __rref, unsigned int count)
{
	return actvxactcapcall_pmcall_wakelock_save_count(false, false, __rref, count);
}

extern int __actvcall_pmcall_wakelock_stat(unsigned long long __rpc_info, void *__buf, struct wake_lock_name name, struct bunch_ipc_attr attr);


extern int __actvcapcall_pmcall_wakelock_stat(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct wake_lock_name name, struct bunch_ipc_attr attr);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_wakelock_stat(bool is_xact_fwd, bool is_xact_allow_refwd, struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_stat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_wakelock_stat(rpc_info, NULL, name, attr);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_wakelock_stat(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	const unsigned long __callno = __pwrmgr_method_wakelock_stat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_wakelock_stat(__rref, rpc_info, NULL, name, attr);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_wakelock_stat(struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	return actvxactcall_pmcall_wakelock_stat(false, false, name, attr);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_wakelock_stat(rref_t __rref, struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	return actvxactcapcall_pmcall_wakelock_stat(false, false, __rref, name, attr);
}

extern int __actvcall_pmcall_cpuhp_add_notifier(unsigned long long __rpc_info, void *__buf, struct hm_notifier_cb ops);


extern int __actvcapcall_pmcall_cpuhp_add_notifier(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_notifier_cb ops);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_cpuhp_add_notifier(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_notifier_cb ops)
{
	const unsigned long __callno = __pwrmgr_method_cpuhp_add_notifier;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_cpuhp_add_notifier(rpc_info, NULL, ops);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_cpuhp_add_notifier(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_notifier_cb ops)
{
	const unsigned long __callno = __pwrmgr_method_cpuhp_add_notifier;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_cpuhp_add_notifier(__rref, rpc_info, NULL, ops);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_cpuhp_add_notifier(struct hm_notifier_cb ops)
{
	return actvxactcall_pmcall_cpuhp_add_notifier(false, false, ops);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_cpuhp_add_notifier(rref_t __rref, struct hm_notifier_cb ops)
{
	return actvxactcapcall_pmcall_cpuhp_add_notifier(false, false, __rref, ops);
}

extern int __actvcall_pmcall_cpuhp_remove_notifier(unsigned long long __rpc_info, void *__buf, struct hm_notifier_cb ops);


extern int __actvcapcall_pmcall_cpuhp_remove_notifier(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_notifier_cb ops);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_cpuhp_remove_notifier(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_notifier_cb ops)
{
	const unsigned long __callno = __pwrmgr_method_cpuhp_remove_notifier;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_cpuhp_remove_notifier(rpc_info, NULL, ops);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_cpuhp_remove_notifier(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_notifier_cb ops)
{
	const unsigned long __callno = __pwrmgr_method_cpuhp_remove_notifier;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_cpuhp_remove_notifier(__rref, rpc_info, NULL, ops);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_cpuhp_remove_notifier(struct hm_notifier_cb ops)
{
	return actvxactcall_pmcall_cpuhp_remove_notifier(false, false, ops);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_cpuhp_remove_notifier(rref_t __rref, struct hm_notifier_cb ops)
{
	return actvxactcapcall_pmcall_cpuhp_remove_notifier(false, false, __rref, ops);
}

extern int __actvcall_pmcall_cpuhp_action(unsigned long long __rpc_info, void *__buf, unsigned int cpu, unsigned int event);


extern int __actvcapcall_pmcall_cpuhp_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cpu, unsigned int event);


static inline int __attribute__((always_inline)) actvxactcall_pmcall_cpuhp_action(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cpu, unsigned int event)
{
	const unsigned long __callno = __pwrmgr_method_cpuhp_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_pmcall_cpuhp_action(rpc_info, NULL, cpu, event);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_pmcall_cpuhp_action(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cpu, unsigned int event)
{
	const unsigned long __callno = __pwrmgr_method_cpuhp_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_pmcall_cpuhp_action(__rref, rpc_info, NULL, cpu, event);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_pmcall_cpuhp_action(unsigned int cpu, unsigned int event)
{
	return actvxactcall_pmcall_cpuhp_action(false, false, cpu, event);
}

static inline int __attribute__((always_inline)) actvcapcall_pmcall_cpuhp_action(rref_t __rref, unsigned int cpu, unsigned int event)
{
	return actvxactcapcall_pmcall_cpuhp_action(false, false, __rref, cpu, event);
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

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_shutdown_enter(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_shutdown_enter(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_shutdown_enter(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_pmcall_shutdown_enter(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_shutdown_enter(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_pmcall_shutdown_enter(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_shutdown_reboot_enter(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_shutdown_reboot_enter(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_shutdown_reboot_enter(unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd)
{
	int __ret;
	struct reboot_cmd __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcall_pmcall_shutdown_reboot_enter(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_shutdown_reboot_enter(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd)
{
	int __ret;
	struct reboot_cmd __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcapcall_pmcall_shutdown_reboot_enter(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_suspend_set_state(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_suspend_set_state(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_suspend_set_state(unsigned long long __rpc_info, void *__buf, int state)
{
	int __ret;
	int __maybe_unused __actv_local_var_state = state;
	__ret = ____actvcall_pmcall_suspend_set_state(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(state, __actv_local_var_state));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_suspend_set_state(rref_t __rref, unsigned long long __rpc_info, void *__buf, int state)
{
	int __ret;
	int __maybe_unused __actv_local_var_state = state;
	__ret = ____actvcapcall_pmcall_suspend_set_state(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(state, __actv_local_var_state));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_pmcall_sysfs_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_pmcall_sysfs_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_sysfs_read(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_pmcall_sysfs_read(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_pmcall_sysfs_read(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_pmcall_sysfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_pmcall_sysfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_sysfs_write(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_pmcall_sysfs_write(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_pmcall_sysfs_write(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_wakelock_action(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_wakelock_action(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_wakelock_action(unsigned long long __rpc_info, void *__buf, unsigned int action, struct wake_lock_name name)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_action = action;
	struct wake_lock_name __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcall_pmcall_wakelock_action(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(action, __actv_local_var_action), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_wakelock_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int action, struct wake_lock_name name)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_action = action;
	struct wake_lock_name __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcapcall_pmcall_wakelock_action(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(action, __actv_local_var_action), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_wakelock_acquire_timeout(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_wakelock_acquire_timeout(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_wakelock_acquire_timeout(unsigned long long __rpc_info, void *__buf, struct wake_lock_name wakelock, unsigned long msec)
{
	int __ret;
	struct wake_lock_name __maybe_unused __actv_local_var_wakelock = wakelock;
	unsigned long __maybe_unused __actv_local_var_msec = msec;
	__ret = ____actvcall_pmcall_wakelock_acquire_timeout(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(wakelock, __actv_local_var_wakelock), __ARCH_ACTV_RPC_PASS_ARG(msec, __actv_local_var_msec));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_wakelock_acquire_timeout(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct wake_lock_name wakelock, unsigned long msec)
{
	int __ret;
	struct wake_lock_name __maybe_unused __actv_local_var_wakelock = wakelock;
	unsigned long __maybe_unused __actv_local_var_msec = msec;
	__ret = ____actvcapcall_pmcall_wakelock_acquire_timeout(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(wakelock, __actv_local_var_wakelock), __ARCH_ACTV_RPC_PASS_ARG(msec, __actv_local_var_msec));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_pmcall_wakelock_get_count(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_pmcall_wakelock_get_count(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_wakelock_get_count(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_pmcall_wakelock_get_count(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_wakelock_get_count(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_pmcall_wakelock_get_count(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_wakelock_save_count(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_wakelock_save_count(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_wakelock_save_count(unsigned long long __rpc_info, void *__buf, unsigned int count)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcall_pmcall_wakelock_save_count(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_wakelock_save_count(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int count)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcapcall_pmcall_wakelock_save_count(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_wakelock_stat(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_wakelock_stat(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_wakelock_stat(unsigned long long __rpc_info, void *__buf, struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	int __ret;
	struct wake_lock_name __maybe_unused __actv_local_var_name = name;
	struct bunch_ipc_attr __maybe_unused __actv_local_var_attr = attr;
	__ret = ____actvcall_pmcall_wakelock_stat(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(attr, __actv_local_var_attr));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_wakelock_stat(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	int __ret;
	struct wake_lock_name __maybe_unused __actv_local_var_name = name;
	struct bunch_ipc_attr __maybe_unused __actv_local_var_attr = attr;
	__ret = ____actvcapcall_pmcall_wakelock_stat(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(attr, __actv_local_var_attr));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_cpuhp_add_notifier(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_cpuhp_add_notifier(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_cpuhp_add_notifier(unsigned long long __rpc_info, void *__buf, struct hm_notifier_cb ops)
{
	int __ret;
	struct hm_notifier_cb __maybe_unused __actv_local_var_ops = ops;
	__ret = ____actvcall_pmcall_cpuhp_add_notifier(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_cpuhp_add_notifier(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_notifier_cb ops)
{
	int __ret;
	struct hm_notifier_cb __maybe_unused __actv_local_var_ops = ops;
	__ret = ____actvcapcall_pmcall_cpuhp_add_notifier(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_cpuhp_remove_notifier(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_cpuhp_remove_notifier(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_cpuhp_remove_notifier(unsigned long long __rpc_info, void *__buf, struct hm_notifier_cb ops)
{
	int __ret;
	struct hm_notifier_cb __maybe_unused __actv_local_var_ops = ops;
	__ret = ____actvcall_pmcall_cpuhp_remove_notifier(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_cpuhp_remove_notifier(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_notifier_cb ops)
{
	int __ret;
	struct hm_notifier_cb __maybe_unused __actv_local_var_ops = ops;
	__ret = ____actvcapcall_pmcall_cpuhp_remove_notifier(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_pmcall_cpuhp_action(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_pmcall_cpuhp_action(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_pmcall_cpuhp_action(unsigned long long __rpc_info, void *__buf, unsigned int cpu, unsigned int event)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cpu = cpu;
	unsigned int __maybe_unused __actv_local_var_event = event;
	__ret = ____actvcall_pmcall_cpuhp_action(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cpu, __actv_local_var_cpu), __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_pmcall_cpuhp_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cpu, unsigned int event)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cpu = cpu;
	unsigned int __maybe_unused __actv_local_var_event = event;
	__ret = ____actvcapcall_pmcall_cpuhp_action(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cpu, __actv_local_var_cpu), __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event));
	return __ret;
}

#endif
#endif
