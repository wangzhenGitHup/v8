/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for pwrmgr
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/pwrmgr/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/pwrmgr/libsysif/pwrmgr/api.h --server-dest ../image/usr/include/generated/sysif_server/pwrmgr/libsysif/pwrmgr/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_PWRMGR_SERVER_H
#define LIBSYSIF_PWRMGR_SERVER_H
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
#ifdef __sysif_server_pwrmgr_no_compat32_handlers__
# define __pwrmgr_method_MAX __pwrmgr_method_MAX_NOCOMPAT
#else
# define __pwrmgr_method_MAX __pwrmgr_method_MAX_COMPAT
#endif
#include <libsysif/utils.h>
#include <asm/actv_rpc.h>
#include <asm/types.h>
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
extern int actvhdlr_pmhandler_shutdown_enter(unsigned long long sender, unsigned long credential);


extern int actvhdlr_pmhandler_shutdown_reboot_enter(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);


extern int actvhdlr_pmhandler_suspend_set_state(unsigned long long sender, unsigned long credential, int state);


extern int actvhdlr_pmhandler_sysfs_read(unsigned long long sender, unsigned long credential);


extern int actvhdlr_pmhandler_sysfs_write(unsigned long long sender, unsigned long credential);


extern int actvhdlr_pmhandler_wakelock_action(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name);


extern int actvhdlr_pmhandler_wakelock_acquire_timeout(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec);


extern int actvhdlr_pmhandler_wakelock_get_count(unsigned long long sender, unsigned long credential);


extern int actvhdlr_pmhandler_wakelock_save_count(unsigned long long sender, unsigned long credential, unsigned int count);


extern int actvhdlr_pmhandler_wakelock_stat(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr);


extern int actvhdlr_pmhandler_cpuhp_add_notifier(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);


extern int actvhdlr_pmhandler_cpuhp_remove_notifier(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);


extern int actvhdlr_pmhandler_cpuhp_action(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event);


#else
extern int actvhdlr_pmhandler_shutdown_enter(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_pmhandler_shutdown_enter(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_shutdown_reboot_enter(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);


extern int __actvshadowhdlr_pmhandler_shutdown_reboot_enter(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_suspend_set_state(unsigned long long sender, unsigned long credential, int state);


extern int __actvshadowhdlr_pmhandler_suspend_set_state(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_sysfs_read(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_pmhandler_sysfs_read(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_sysfs_write(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_pmhandler_sysfs_write(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_wakelock_action(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name);


extern int __actvshadowhdlr_pmhandler_wakelock_action(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_wakelock_acquire_timeout(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec);


extern int __actvshadowhdlr_pmhandler_wakelock_acquire_timeout(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_wakelock_get_count(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_pmhandler_wakelock_get_count(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_wakelock_save_count(unsigned long long sender, unsigned long credential, unsigned int count);


extern int __actvshadowhdlr_pmhandler_wakelock_save_count(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_wakelock_stat(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr);


extern int __actvshadowhdlr_pmhandler_wakelock_stat(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_cpuhp_add_notifier(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);


extern int __actvshadowhdlr_pmhandler_cpuhp_add_notifier(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_cpuhp_remove_notifier(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);


extern int __actvshadowhdlr_pmhandler_cpuhp_remove_notifier(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_pmhandler_cpuhp_action(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event);


extern int __actvshadowhdlr_pmhandler_cpuhp_action(unsigned long long sender, unsigned long credential, ...);


#endif
static inline struct __actvret_pmcall_shutdown_enter* actvhdlr_pmhandler_shutdown_enter_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_shutdown_enter));
	return (struct __actvret_pmcall_shutdown_enter*)__ret;
}

static inline struct __actvret_pmcall_shutdown_reboot_enter* actvhdlr_pmhandler_shutdown_reboot_enter_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_shutdown_reboot_enter));
	return (struct __actvret_pmcall_shutdown_reboot_enter*)__ret;
}

static inline struct __actvret_pmcall_suspend_set_state* actvhdlr_pmhandler_suspend_set_state_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_suspend_set_state));
	return (struct __actvret_pmcall_suspend_set_state*)__ret;
}

static inline struct __actvret_pmcall_sysfs_read* actvhdlr_pmhandler_sysfs_read_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_sysfs_read));
	return (struct __actvret_pmcall_sysfs_read*)__ret;
}

static inline struct __actvret_pmcall_sysfs_write* actvhdlr_pmhandler_sysfs_write_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_sysfs_write));
	return (struct __actvret_pmcall_sysfs_write*)__ret;
}

static inline struct __actvret_pmcall_wakelock_action* actvhdlr_pmhandler_wakelock_action_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_wakelock_action));
	return (struct __actvret_pmcall_wakelock_action*)__ret;
}

static inline struct __actvret_pmcall_wakelock_acquire_timeout* actvhdlr_pmhandler_wakelock_acquire_timeout_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_wakelock_acquire_timeout));
	return (struct __actvret_pmcall_wakelock_acquire_timeout*)__ret;
}

static inline struct __actvret_pmcall_wakelock_get_count* actvhdlr_pmhandler_wakelock_get_count_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_wakelock_get_count));
	return (struct __actvret_pmcall_wakelock_get_count*)__ret;
}

static inline struct __actvret_pmcall_wakelock_save_count* actvhdlr_pmhandler_wakelock_save_count_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_wakelock_save_count));
	return (struct __actvret_pmcall_wakelock_save_count*)__ret;
}

static inline struct __actvret_pmcall_wakelock_stat* actvhdlr_pmhandler_wakelock_stat_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_wakelock_stat));
	return (struct __actvret_pmcall_wakelock_stat*)__ret;
}

static inline struct __actvret_pmcall_cpuhp_add_notifier* actvhdlr_pmhandler_cpuhp_add_notifier_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_cpuhp_add_notifier));
	return (struct __actvret_pmcall_cpuhp_add_notifier*)__ret;
}

static inline struct __actvret_pmcall_cpuhp_remove_notifier* actvhdlr_pmhandler_cpuhp_remove_notifier_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_cpuhp_remove_notifier));
	return (struct __actvret_pmcall_cpuhp_remove_notifier*)__ret;
}

static inline struct __actvret_pmcall_cpuhp_action* actvhdlr_pmhandler_cpuhp_action_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_pmcall_cpuhp_action));
	return (struct __actvret_pmcall_cpuhp_action*)__ret;
}

#ifdef __sysif_server_pwrmgr_no_compat32_handlers__
#ifdef __HOST_LLT__
union pwrmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, int state);
	int (*p__actvbridgecapcallhdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int state);
	int (*p__actvbridgehdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgehdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgehdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned int count);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int count);
	int (*p__actvbridgehdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cpu, unsigned int event);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union pwrmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, int state);
	int (*p__actvbridgecapcallhdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int state);
	int (*p__actvbridgehdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgehdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgehdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned int count);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int count);
	int (*p__actvbridgehdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cpu, unsigned int event);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union pwrmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, int state);
	int (*p__actvbridgecapcallhdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int state);
	int (*p__actvbridgehdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgehdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgehdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned int count);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int count);
	int (*p__actvbridgehdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cpu, unsigned int event);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
#ifdef __HOST_LLT__
union pwrmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, int state);
	int (*p__actvbridgecapcallhdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int state);
	int (*p__actvbridgehdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgehdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgehdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned int count);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int count);
	int (*p__actvbridgehdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cpu, unsigned int event);
	int (*p__actvbridgehdlr_pmhandler_compat_shutdown_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_shutdown_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_suspend_set_state)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_suspend_set_state)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_get_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_get_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_stat)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_stat)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union pwrmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, int state);
	int (*p__actvbridgecapcallhdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int state);
	int (*p__actvbridgehdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgehdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgehdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned int count);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int count);
	int (*p__actvbridgehdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cpu, unsigned int event);
	int (*p__actvbridgehdlr_pmhandler_compat_shutdown_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_shutdown_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_suspend_set_state)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_suspend_set_state)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_get_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_get_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_stat)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_stat)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union pwrmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, int state);
	int (*p__actvbridgecapcallhdlr_pmhandler_suspend_set_state)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int state);
	int (*p__actvbridgehdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action, struct wake_lock_name name);
	int (*p__actvbridgehdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name wakelock, unsigned long msec);
	int (*p__actvbridgehdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_get_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned int count);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_save_count)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int count);
	int (*p__actvbridgehdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_pmhandler_wakelock_stat)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name name, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops);
	int (*p__actvbridgehdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event);
	int (*p__actvbridgecapcallhdlr_pmhandler_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cpu, unsigned int event);
	int (*p__actvbridgehdlr_pmhandler_compat_shutdown_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_shutdown_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_shutdown_reboot_enter)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_suspend_set_state)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_suspend_set_state)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_acquire_timeout)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_get_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_get_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_save_count)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_wakelock_stat)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_stat)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_add_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_remove_notifier)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_pmhandler_compat_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#endif
#endif
extern union pwrmgr_hdlrs_union sysif_pwrmgr_actvhdlr_table[__pwrmgr_method_MAX];

extern union pwrmgr_hdlrs_union sysif_pwrmgr_actvcapcallhdlr_table[__pwrmgr_method_MAX];

extern void sysif_show_pwrmgr_methods(void);


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
static int __opt_nonoframe __actvbridgehdlr_pmhandler_shutdown_enter(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_pmhandler_shutdown_enter(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_shutdown_enter(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_pmhandler_shutdown_enter(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_shutdown_reboot_enter(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_shutdown_reboot_enter(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_cmd, cmd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_shutdown_reboot_enter(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_cmd, cmd));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_suspend_set_state(unsigned long long sender, unsigned long credential, int state)
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
	return __actvshadowhdlr_pmhandler_suspend_set_state(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, state));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_suspend_set_state(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int state)
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
	return __actvshadowhdlr_pmhandler_suspend_set_state(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, state));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_sysfs_read(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_pmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_sysfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_pmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_sysfs_write(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_pmhandler_sysfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_sysfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_pmhandler_sysfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_action(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_wakelock_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, action), __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_action(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action, struct wake_lock_name name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_wakelock_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, action), __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, name));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_acquire_timeout(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_wakelock_acquire_timeout(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, wakelock), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, msec));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name wakelock, unsigned long msec)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_wakelock_acquire_timeout(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, wakelock), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, msec));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_get_count(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_pmhandler_wakelock_get_count(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_get_count(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_pmhandler_wakelock_get_count(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_save_count(unsigned long long sender, unsigned long credential, unsigned int count)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_wakelock_save_count(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, count));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_save_count(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int count)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_wakelock_save_count(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, count));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_stat(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_wakelock_stat(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, name), __ARCH_ACTV_RPC_RECV_ARG(struct bunch_ipc_attr, attr));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_stat(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_wakelock_stat(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, name), __ARCH_ACTV_RPC_RECV_ARG(struct bunch_ipc_attr, attr));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_cpuhp_add_notifier(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_cpuhp_add_notifier(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_notifier_cb, ops));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_cpuhp_add_notifier(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_notifier_cb, ops));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_cpuhp_remove_notifier(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_cpuhp_remove_notifier(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_notifier_cb, ops));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_cpuhp_remove_notifier(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_notifier_cb, ops));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_cpuhp_action(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_cpuhp_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cpu), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, event));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_cpuhp_action(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cpu, unsigned int event)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_pmhandler_cpuhp_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cpu), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, event));
}

#ifndef __sysif_server_pwrmgr_no_compat32_handlers__
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
static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_shutdown_enter(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_pmhandler_shutdown_enter(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_shutdown_enter(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_pmhandler_shutdown_enter(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_shutdown_reboot_enter(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct reboot_cmd __maybe_unused _cmd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct reboot_cmd);
		type = __type_of(struct reboot_cmd);
		__fetch_one_arg((void*)&_cmd, data, 0, arg_sz, model, type, struct reboot_cmd, _cmd)
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
	return __actvshadowhdlr_pmhandler_shutdown_reboot_enter(sender, credential, _cmd);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_shutdown_reboot_enter(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct reboot_cmd __maybe_unused _cmd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct reboot_cmd);
		type = __type_of(struct reboot_cmd);
		__fetch_one_arg((void*)&_cmd, data, 0, arg_sz, model, type, struct reboot_cmd, _cmd)
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
	return __actvshadowhdlr_pmhandler_shutdown_reboot_enter(sender, credential, _cmd);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_suspend_set_state(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	int __maybe_unused _state;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_state, data, 0, arg_sz, model, type, int, _state)
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
	return __actvshadowhdlr_pmhandler_suspend_set_state(sender, credential, _state);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_suspend_set_state(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	int __maybe_unused _state;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_state, data, 0, arg_sz, model, type, int, _state)
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
	return __actvshadowhdlr_pmhandler_suspend_set_state(sender, credential, _state);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_sysfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_pmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_sysfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_pmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_sysfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_pmhandler_sysfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_sysfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_pmhandler_sysfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_wakelock_action(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	unsigned int __maybe_unused _action;
	struct wake_lock_name __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_action, data, 0, arg_sz, model, type, unsigned int, _action)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct wake_lock_name);
		type = __type_of(struct wake_lock_name);
		__fetch_one_arg((void*)&_name, data, 1, arg_sz, model, type, struct wake_lock_name, _name)
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
	return __actvshadowhdlr_pmhandler_wakelock_action(sender, credential, _action, _name);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_wakelock_action(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	unsigned int __maybe_unused _action;
	struct wake_lock_name __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_action, data, 0, arg_sz, model, type, unsigned int, _action)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct wake_lock_name);
		type = __type_of(struct wake_lock_name);
		__fetch_one_arg((void*)&_name, data, 1, arg_sz, model, type, struct wake_lock_name, _name)
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
	return __actvshadowhdlr_pmhandler_wakelock_action(sender, credential, _action, _name);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_wakelock_acquire_timeout(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct wake_lock_name __maybe_unused _wakelock;
	unsigned long __maybe_unused _msec;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct wake_lock_name);
		type = __type_of(struct wake_lock_name);
		__fetch_one_arg((void*)&_wakelock, data, 0, arg_sz, model, type, struct wake_lock_name, _wakelock)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_msec, data, 1, arg_sz, model, type, unsigned long, _msec)
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
	return __actvshadowhdlr_pmhandler_wakelock_acquire_timeout(sender, credential, _wakelock, _msec);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_wakelock_acquire_timeout(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct wake_lock_name __maybe_unused _wakelock;
	unsigned long __maybe_unused _msec;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct wake_lock_name);
		type = __type_of(struct wake_lock_name);
		__fetch_one_arg((void*)&_wakelock, data, 0, arg_sz, model, type, struct wake_lock_name, _wakelock)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_msec, data, 1, arg_sz, model, type, unsigned long, _msec)
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
	return __actvshadowhdlr_pmhandler_wakelock_acquire_timeout(sender, credential, _wakelock, _msec);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_wakelock_get_count(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_pmhandler_wakelock_get_count(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_wakelock_get_count(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	return __actvshadowhdlr_pmhandler_wakelock_get_count(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_wakelock_save_count(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	unsigned int __maybe_unused _count;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_count, data, 0, arg_sz, model, type, unsigned int, _count)
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
	return __actvshadowhdlr_pmhandler_wakelock_save_count(sender, credential, _count);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_wakelock_save_count(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	unsigned int __maybe_unused _count;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_count, data, 0, arg_sz, model, type, unsigned int, _count)
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
	return __actvshadowhdlr_pmhandler_wakelock_save_count(sender, credential, _count);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_wakelock_stat(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct wake_lock_name __maybe_unused _name;
	struct bunch_ipc_attr __maybe_unused _attr;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct wake_lock_name);
		type = __type_of(struct wake_lock_name);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct wake_lock_name, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct bunch_ipc_attr);
		type = __type_of(struct bunch_ipc_attr);
		__fetch_one_arg((void*)&_attr, data, 1, arg_sz, model, type, struct bunch_ipc_attr, _attr)
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
	return __actvshadowhdlr_pmhandler_wakelock_stat(sender, credential, _name, _attr);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_wakelock_stat(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct wake_lock_name __maybe_unused _name;
	struct bunch_ipc_attr __maybe_unused _attr;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct wake_lock_name);
		type = __type_of(struct wake_lock_name);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct wake_lock_name, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct bunch_ipc_attr);
		type = __type_of(struct bunch_ipc_attr);
		__fetch_one_arg((void*)&_attr, data, 1, arg_sz, model, type, struct bunch_ipc_attr, _attr)
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
	return __actvshadowhdlr_pmhandler_wakelock_stat(sender, credential, _name, _attr);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_cpuhp_add_notifier(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct hm_notifier_cb __maybe_unused _ops;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_notifier_cb);
		type = __type_of(struct hm_notifier_cb);
		__fetch_one_arg((void*)&_ops, data, 0, arg_sz, model, type, struct hm_notifier_cb, _ops)
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
	return __actvshadowhdlr_pmhandler_cpuhp_add_notifier(sender, credential, _ops);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_cpuhp_add_notifier(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct hm_notifier_cb __maybe_unused _ops;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_notifier_cb);
		type = __type_of(struct hm_notifier_cb);
		__fetch_one_arg((void*)&_ops, data, 0, arg_sz, model, type, struct hm_notifier_cb, _ops)
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
	return __actvshadowhdlr_pmhandler_cpuhp_add_notifier(sender, credential, _ops);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_cpuhp_remove_notifier(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct hm_notifier_cb __maybe_unused _ops;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_notifier_cb);
		type = __type_of(struct hm_notifier_cb);
		__fetch_one_arg((void*)&_ops, data, 0, arg_sz, model, type, struct hm_notifier_cb, _ops)
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
	return __actvshadowhdlr_pmhandler_cpuhp_remove_notifier(sender, credential, _ops);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_cpuhp_remove_notifier(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	struct hm_notifier_cb __maybe_unused _ops;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_notifier_cb);
		type = __type_of(struct hm_notifier_cb);
		__fetch_one_arg((void*)&_ops, data, 0, arg_sz, model, type, struct hm_notifier_cb, _ops)
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
	return __actvshadowhdlr_pmhandler_cpuhp_remove_notifier(sender, credential, _ops);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_compat_cpuhp_action(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	unsigned int __maybe_unused _cpu;
	unsigned int __maybe_unused _event;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cpu, data, 0, arg_sz, model, type, unsigned int, _cpu)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_event, data, 1, arg_sz, model, type, unsigned int, _event)
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
	return __actvshadowhdlr_pmhandler_cpuhp_action(sender, credential, _cpu, _event);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_compat_cpuhp_action(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
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
	unsigned int __maybe_unused _cpu;
	unsigned int __maybe_unused _event;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cpu, data, 0, arg_sz, model, type, unsigned int, _cpu)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_event, data, 1, arg_sz, model, type, unsigned int, _event)
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
	return __actvshadowhdlr_pmhandler_cpuhp_action(sender, credential, _cpu, _event);
}

#endif
#else
static int __opt_nonoframe __actvbridgehdlr_pmhandler_shutdown_enter(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_pmhandler_shutdown_enter(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_shutdown_enter(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_pmhandler_shutdown_enter(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_shutdown_reboot_enter(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_shutdown_reboot_enter(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_cmd, cmd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_shutdown_reboot_enter(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_cmd, cmd));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_suspend_set_state(unsigned long long sender, unsigned long credential, int state)
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
	return actvhdlr_pmhandler_suspend_set_state(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, state));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_suspend_set_state(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int state)
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
	return actvhdlr_pmhandler_suspend_set_state(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, state));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_sysfs_read(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_pmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_sysfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_pmhandler_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_sysfs_write(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_pmhandler_sysfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_sysfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_pmhandler_sysfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_action(unsigned long long sender, unsigned long credential, unsigned int action, struct wake_lock_name name)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_wakelock_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, action), __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_action(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action, struct wake_lock_name name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_wakelock_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, action), __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, name));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_acquire_timeout(unsigned long long sender, unsigned long credential, struct wake_lock_name wakelock, unsigned long msec)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_wakelock_acquire_timeout(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, wakelock), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, msec));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name wakelock, unsigned long msec)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_wakelock_acquire_timeout(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, wakelock), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, msec));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_get_count(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_pmhandler_wakelock_get_count(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_get_count(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_pmhandler_wakelock_get_count(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_save_count(unsigned long long sender, unsigned long credential, unsigned int count)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_wakelock_save_count(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, count));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_save_count(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int count)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_wakelock_save_count(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, count));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_wakelock_stat(unsigned long long sender, unsigned long credential, struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_wakelock_stat(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, name), __ARCH_ACTV_RPC_RECV_ARG(struct bunch_ipc_attr, attr));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_wakelock_stat(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct wake_lock_name name, struct bunch_ipc_attr attr)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct wake_lock_name), __arch_actv_rpc_stksz_alignment(struct wake_lock_name));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_wakelock_stat(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct wake_lock_name, name), __ARCH_ACTV_RPC_RECV_ARG(struct bunch_ipc_attr, attr));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_cpuhp_add_notifier(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_cpuhp_add_notifier(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_notifier_cb, ops));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_cpuhp_add_notifier(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_notifier_cb, ops));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_cpuhp_remove_notifier(unsigned long long sender, unsigned long credential, struct hm_notifier_cb ops)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_cpuhp_remove_notifier(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_notifier_cb, ops));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_notifier_cb ops)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_notifier_cb), __arch_actv_rpc_stksz_alignment(struct hm_notifier_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_cpuhp_remove_notifier(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_notifier_cb, ops));
}

static int __opt_nonoframe __actvbridgehdlr_pmhandler_cpuhp_action(unsigned long long sender, unsigned long credential, unsigned int cpu, unsigned int event)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_cpuhp_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cpu), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, event));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_pmhandler_cpuhp_action(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cpu, unsigned int event)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_pmhandler_cpuhp_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cpu), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, event));
}

#endif
#ifdef __sysif_server_pwrmgr_no_compat32_handlers__
union pwrmgr_hdlrs_union sysif_pwrmgr_actvhdlr_table[__pwrmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __pwrmgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_enter] = {
		.p__actvbridgehdlr_pmhandler_shutdown_enter = (&__actvbridgehdlr_pmhandler_shutdown_enter)
	},
	[__pwrmgr_method_shutdown_reboot_enter] = {
		.p__actvbridgehdlr_pmhandler_shutdown_reboot_enter = (&__actvbridgehdlr_pmhandler_shutdown_reboot_enter)
	},
	[__pwrmgr_method_suspend_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_suspend_set_state] = {
		.p__actvbridgehdlr_pmhandler_suspend_set_state = (&__actvbridgehdlr_pmhandler_suspend_set_state)
	},
	[__pwrmgr_method_sysfs_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_read] = {
		.p__actvbridgehdlr_pmhandler_sysfs_read = (&__actvbridgehdlr_pmhandler_sysfs_read)
	},
	[__pwrmgr_method_sysfs_write] = {
		.p__actvbridgehdlr_pmhandler_sysfs_write = (&__actvbridgehdlr_pmhandler_sysfs_write)
	},
	[__pwrmgr_method_wakelock_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_action] = {
		.p__actvbridgehdlr_pmhandler_wakelock_action = (&__actvbridgehdlr_pmhandler_wakelock_action)
	},
	[__pwrmgr_method_wakelock_acquire_timeout] = {
		.p__actvbridgehdlr_pmhandler_wakelock_acquire_timeout = (&__actvbridgehdlr_pmhandler_wakelock_acquire_timeout)
	},
	[__pwrmgr_method_wakelock_get_count] = {
		.p__actvbridgehdlr_pmhandler_wakelock_get_count = (&__actvbridgehdlr_pmhandler_wakelock_get_count)
	},
	[__pwrmgr_method_wakelock_save_count] = {
		.p__actvbridgehdlr_pmhandler_wakelock_save_count = (&__actvbridgehdlr_pmhandler_wakelock_save_count)
	},
	[__pwrmgr_method_wakelock_stat] = {
		.p__actvbridgehdlr_pmhandler_wakelock_stat = (&__actvbridgehdlr_pmhandler_wakelock_stat)
	},
	[__pwrmgr_method_cpuhp_rsvd_5] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_4] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_add_notifier] = {
		.p__actvbridgehdlr_pmhandler_cpuhp_add_notifier = (&__actvbridgehdlr_pmhandler_cpuhp_add_notifier)
	},
	[__pwrmgr_method_cpuhp_remove_notifier] = {
		.p__actvbridgehdlr_pmhandler_cpuhp_remove_notifier = (&__actvbridgehdlr_pmhandler_cpuhp_remove_notifier)
	},
	[__pwrmgr_method_cpuhp_action] = {
		.p__actvbridgehdlr_pmhandler_cpuhp_action = (&__actvbridgehdlr_pmhandler_cpuhp_action)
	}
};

union pwrmgr_hdlrs_union sysif_pwrmgr_actvcapcallhdlr_table[__pwrmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __pwrmgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_enter] = {
		.p__actvbridgecapcallhdlr_pmhandler_shutdown_enter = (&__actvbridgecapcallhdlr_pmhandler_shutdown_enter)
	},
	[__pwrmgr_method_shutdown_reboot_enter] = {
		.p__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter = (&__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter)
	},
	[__pwrmgr_method_suspend_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_suspend_set_state] = {
		.p__actvbridgecapcallhdlr_pmhandler_suspend_set_state = (&__actvbridgecapcallhdlr_pmhandler_suspend_set_state)
	},
	[__pwrmgr_method_sysfs_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_read] = {
		.p__actvbridgecapcallhdlr_pmhandler_sysfs_read = (&__actvbridgecapcallhdlr_pmhandler_sysfs_read)
	},
	[__pwrmgr_method_sysfs_write] = {
		.p__actvbridgecapcallhdlr_pmhandler_sysfs_write = (&__actvbridgecapcallhdlr_pmhandler_sysfs_write)
	},
	[__pwrmgr_method_wakelock_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_action] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_action = (&__actvbridgecapcallhdlr_pmhandler_wakelock_action)
	},
	[__pwrmgr_method_wakelock_acquire_timeout] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout = (&__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout)
	},
	[__pwrmgr_method_wakelock_get_count] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_get_count = (&__actvbridgecapcallhdlr_pmhandler_wakelock_get_count)
	},
	[__pwrmgr_method_wakelock_save_count] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_save_count = (&__actvbridgecapcallhdlr_pmhandler_wakelock_save_count)
	},
	[__pwrmgr_method_wakelock_stat] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_stat = (&__actvbridgecapcallhdlr_pmhandler_wakelock_stat)
	},
	[__pwrmgr_method_cpuhp_rsvd_5] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_4] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_add_notifier] = {
		.p__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier = (&__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier)
	},
	[__pwrmgr_method_cpuhp_remove_notifier] = {
		.p__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier = (&__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier)
	},
	[__pwrmgr_method_cpuhp_action] = {
		.p__actvbridgecapcallhdlr_pmhandler_cpuhp_action = (&__actvbridgecapcallhdlr_pmhandler_cpuhp_action)
	}
};

#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
union pwrmgr_hdlrs_union sysif_pwrmgr_actvhdlr_table[__pwrmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __pwrmgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_enter * 2] = {
		.p__actvbridgehdlr_pmhandler_shutdown_enter = (&__actvbridgehdlr_pmhandler_shutdown_enter)
	},
	[__pwrmgr_method_shutdown_enter * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_shutdown_enter = (&__actvbridgehdlr_pmhandler_compat_shutdown_enter)
	},
	[__pwrmgr_method_shutdown_reboot_enter * 2] = {
		.p__actvbridgehdlr_pmhandler_shutdown_reboot_enter = (&__actvbridgehdlr_pmhandler_shutdown_reboot_enter)
	},
	[__pwrmgr_method_shutdown_reboot_enter * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_shutdown_reboot_enter = (&__actvbridgehdlr_pmhandler_compat_shutdown_reboot_enter)
	},
	[__pwrmgr_method_suspend_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_suspend_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_suspend_set_state * 2] = {
		.p__actvbridgehdlr_pmhandler_suspend_set_state = (&__actvbridgehdlr_pmhandler_suspend_set_state)
	},
	[__pwrmgr_method_suspend_set_state * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_suspend_set_state = (&__actvbridgehdlr_pmhandler_compat_suspend_set_state)
	},
	[__pwrmgr_method_sysfs_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_read * 2] = {
		.p__actvbridgehdlr_pmhandler_sysfs_read = (&__actvbridgehdlr_pmhandler_sysfs_read)
	},
	[__pwrmgr_method_sysfs_read * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_sysfs_read = (&__actvbridgehdlr_pmhandler_compat_sysfs_read)
	},
	[__pwrmgr_method_sysfs_write * 2] = {
		.p__actvbridgehdlr_pmhandler_sysfs_write = (&__actvbridgehdlr_pmhandler_sysfs_write)
	},
	[__pwrmgr_method_sysfs_write * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_sysfs_write = (&__actvbridgehdlr_pmhandler_compat_sysfs_write)
	},
	[__pwrmgr_method_wakelock_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_action * 2] = {
		.p__actvbridgehdlr_pmhandler_wakelock_action = (&__actvbridgehdlr_pmhandler_wakelock_action)
	},
	[__pwrmgr_method_wakelock_action * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_wakelock_action = (&__actvbridgehdlr_pmhandler_compat_wakelock_action)
	},
	[__pwrmgr_method_wakelock_acquire_timeout * 2] = {
		.p__actvbridgehdlr_pmhandler_wakelock_acquire_timeout = (&__actvbridgehdlr_pmhandler_wakelock_acquire_timeout)
	},
	[__pwrmgr_method_wakelock_acquire_timeout * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_wakelock_acquire_timeout = (&__actvbridgehdlr_pmhandler_compat_wakelock_acquire_timeout)
	},
	[__pwrmgr_method_wakelock_get_count * 2] = {
		.p__actvbridgehdlr_pmhandler_wakelock_get_count = (&__actvbridgehdlr_pmhandler_wakelock_get_count)
	},
	[__pwrmgr_method_wakelock_get_count * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_wakelock_get_count = (&__actvbridgehdlr_pmhandler_compat_wakelock_get_count)
	},
	[__pwrmgr_method_wakelock_save_count * 2] = {
		.p__actvbridgehdlr_pmhandler_wakelock_save_count = (&__actvbridgehdlr_pmhandler_wakelock_save_count)
	},
	[__pwrmgr_method_wakelock_save_count * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_wakelock_save_count = (&__actvbridgehdlr_pmhandler_compat_wakelock_save_count)
	},
	[__pwrmgr_method_wakelock_stat * 2] = {
		.p__actvbridgehdlr_pmhandler_wakelock_stat = (&__actvbridgehdlr_pmhandler_wakelock_stat)
	},
	[__pwrmgr_method_wakelock_stat * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_wakelock_stat = (&__actvbridgehdlr_pmhandler_compat_wakelock_stat)
	},
	[__pwrmgr_method_cpuhp_rsvd_5 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_4 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_5 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_4 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_add_notifier * 2] = {
		.p__actvbridgehdlr_pmhandler_cpuhp_add_notifier = (&__actvbridgehdlr_pmhandler_cpuhp_add_notifier)
	},
	[__pwrmgr_method_cpuhp_add_notifier * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_cpuhp_add_notifier = (&__actvbridgehdlr_pmhandler_compat_cpuhp_add_notifier)
	},
	[__pwrmgr_method_cpuhp_remove_notifier * 2] = {
		.p__actvbridgehdlr_pmhandler_cpuhp_remove_notifier = (&__actvbridgehdlr_pmhandler_cpuhp_remove_notifier)
	},
	[__pwrmgr_method_cpuhp_remove_notifier * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_cpuhp_remove_notifier = (&__actvbridgehdlr_pmhandler_compat_cpuhp_remove_notifier)
	},
	[__pwrmgr_method_cpuhp_action * 2] = {
		.p__actvbridgehdlr_pmhandler_cpuhp_action = (&__actvbridgehdlr_pmhandler_cpuhp_action)
	},
	[__pwrmgr_method_cpuhp_action * 2 + 1] = {
		.p__actvbridgehdlr_pmhandler_compat_cpuhp_action = (&__actvbridgehdlr_pmhandler_compat_cpuhp_action)
	}
};

#endif
union pwrmgr_hdlrs_union sysif_pwrmgr_actvcapcallhdlr_table[__pwrmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __pwrmgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_shutdown_enter * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_shutdown_enter = (&__actvbridgecapcallhdlr_pmhandler_shutdown_enter)
	},
	[__pwrmgr_method_shutdown_enter * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_shutdown_enter = (&__actvbridgecapcallhdlr_pmhandler_compat_shutdown_enter)
	},
	[__pwrmgr_method_shutdown_reboot_enter * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter = (&__actvbridgecapcallhdlr_pmhandler_shutdown_reboot_enter)
	},
	[__pwrmgr_method_shutdown_reboot_enter * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_shutdown_reboot_enter = (&__actvbridgecapcallhdlr_pmhandler_compat_shutdown_reboot_enter)
	},
	[__pwrmgr_method_suspend_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_suspend_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_suspend_set_state * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_suspend_set_state = (&__actvbridgecapcallhdlr_pmhandler_suspend_set_state)
	},
	[__pwrmgr_method_suspend_set_state * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_suspend_set_state = (&__actvbridgecapcallhdlr_pmhandler_compat_suspend_set_state)
	},
	[__pwrmgr_method_sysfs_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_sysfs_read * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_sysfs_read = (&__actvbridgecapcallhdlr_pmhandler_sysfs_read)
	},
	[__pwrmgr_method_sysfs_read * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_sysfs_read = (&__actvbridgecapcallhdlr_pmhandler_compat_sysfs_read)
	},
	[__pwrmgr_method_sysfs_write * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_sysfs_write = (&__actvbridgecapcallhdlr_pmhandler_sysfs_write)
	},
	[__pwrmgr_method_sysfs_write * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_sysfs_write = (&__actvbridgecapcallhdlr_pmhandler_compat_sysfs_write)
	},
	[__pwrmgr_method_wakelock_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_wakelock_action * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_action = (&__actvbridgecapcallhdlr_pmhandler_wakelock_action)
	},
	[__pwrmgr_method_wakelock_action * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_action = (&__actvbridgecapcallhdlr_pmhandler_compat_wakelock_action)
	},
	[__pwrmgr_method_wakelock_acquire_timeout * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout = (&__actvbridgecapcallhdlr_pmhandler_wakelock_acquire_timeout)
	},
	[__pwrmgr_method_wakelock_acquire_timeout * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_acquire_timeout = (&__actvbridgecapcallhdlr_pmhandler_compat_wakelock_acquire_timeout)
	},
	[__pwrmgr_method_wakelock_get_count * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_get_count = (&__actvbridgecapcallhdlr_pmhandler_wakelock_get_count)
	},
	[__pwrmgr_method_wakelock_get_count * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_get_count = (&__actvbridgecapcallhdlr_pmhandler_compat_wakelock_get_count)
	},
	[__pwrmgr_method_wakelock_save_count * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_save_count = (&__actvbridgecapcallhdlr_pmhandler_wakelock_save_count)
	},
	[__pwrmgr_method_wakelock_save_count * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_save_count = (&__actvbridgecapcallhdlr_pmhandler_compat_wakelock_save_count)
	},
	[__pwrmgr_method_wakelock_stat * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_wakelock_stat = (&__actvbridgecapcallhdlr_pmhandler_wakelock_stat)
	},
	[__pwrmgr_method_wakelock_stat * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_wakelock_stat = (&__actvbridgecapcallhdlr_pmhandler_compat_wakelock_stat)
	},
	[__pwrmgr_method_cpuhp_rsvd_5 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_4 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_5 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_4 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__pwrmgr_method_cpuhp_add_notifier * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier = (&__actvbridgecapcallhdlr_pmhandler_cpuhp_add_notifier)
	},
	[__pwrmgr_method_cpuhp_add_notifier * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_add_notifier = (&__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_add_notifier)
	},
	[__pwrmgr_method_cpuhp_remove_notifier * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier = (&__actvbridgecapcallhdlr_pmhandler_cpuhp_remove_notifier)
	},
	[__pwrmgr_method_cpuhp_remove_notifier * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_remove_notifier = (&__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_remove_notifier)
	},
	[__pwrmgr_method_cpuhp_action * 2] = {
		.p__actvbridgecapcallhdlr_pmhandler_cpuhp_action = (&__actvbridgecapcallhdlr_pmhandler_cpuhp_action)
	},
	[__pwrmgr_method_cpuhp_action * 2 + 1] = {
		.p__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_action = (&__actvbridgecapcallhdlr_pmhandler_compat_cpuhp_action)
	}
};

#endif
void sysif_show_pwrmgr_methods(void)
{
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "shutdown", "enter", __pwrmgr_method_shutdown_enter);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "shutdown", "enter", __pwrmgr_method_shutdown_enter);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "shutdown", "reboot_enter", __pwrmgr_method_shutdown_reboot_enter);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "shutdown", "reboot_enter", __pwrmgr_method_shutdown_reboot_enter);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "suspend", "set_state", __pwrmgr_method_suspend_set_state);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "suspend", "set_state", __pwrmgr_method_suspend_set_state);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "sysfs", "read", __pwrmgr_method_sysfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "sysfs", "read", __pwrmgr_method_sysfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "sysfs", "write", __pwrmgr_method_sysfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "sysfs", "write", __pwrmgr_method_sysfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "wakelock", "action", __pwrmgr_method_wakelock_action);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "wakelock", "action", __pwrmgr_method_wakelock_action);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "wakelock", "acquire_timeout", __pwrmgr_method_wakelock_acquire_timeout);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "wakelock", "acquire_timeout", __pwrmgr_method_wakelock_acquire_timeout);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "wakelock", "get_count", __pwrmgr_method_wakelock_get_count);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "wakelock", "get_count", __pwrmgr_method_wakelock_get_count);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "wakelock", "save_count", __pwrmgr_method_wakelock_save_count);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "wakelock", "save_count", __pwrmgr_method_wakelock_save_count);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "wakelock", "stat", __pwrmgr_method_wakelock_stat);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "wakelock", "stat", __pwrmgr_method_wakelock_stat);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "cpuhp", "add_notifier", __pwrmgr_method_cpuhp_add_notifier);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "cpuhp", "add_notifier", __pwrmgr_method_cpuhp_add_notifier);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "cpuhp", "remove_notifier", __pwrmgr_method_cpuhp_remove_notifier);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "cpuhp", "remove_notifier", __pwrmgr_method_cpuhp_remove_notifier);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "pmcall", "cpuhp", "action", __pwrmgr_method_cpuhp_action);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "pmhandler", "cpuhp", "action", __pwrmgr_method_cpuhp_action);
	hm_info("%s_%s, max method num: %d\n", "pwrmgr", "method", __pwrmgr_method_MAX);
}

#endif
#endif
