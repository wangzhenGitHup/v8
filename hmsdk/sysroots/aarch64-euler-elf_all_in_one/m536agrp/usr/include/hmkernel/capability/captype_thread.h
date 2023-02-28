/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Captype thread
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jul 19 05:24:19 2018
 */
/*
 * Must choose one GRANT type from ALL/NO/COARSE/FINE
 * Must choose one GRANTMOVE type from ALL/NO/COARSE
 */
CAPTYPE(Thread, 2, CAPCOARSEGRANT(Thread)
		   CAPNOGRANTMOVE(Thread)
		   CAPDEFAULTSIZE(Thread),
	/* Methods that only have capcall (called by other threads) */
	CAPMETHOD(Thread, Join)
	CAPMETHOD(Thread, Resume)
	CAPMETHOD(Thread, HMSignalKill)
	/* Methods that have both capcall and fastcall */
	CAPMETHOD(Thread, VSpaceOf)
	CAPMETHOD(Thread, SetCpu)
	CAPMETHOD(Thread, GetCpu)
	CAPMETHOD(Thread, Suspend)
	CAPMETHOD(Thread, AttachCpuContext)
	CAPMETHOD(Thread, DetachCpuContext)
	CAPMETHOD(Thread, Stat)
	CAPMETHOD(Thread, SetName)
	CAPMETHOD(Thread, TriggerDetachOne)
	/* Methods that only have fastcall (called by itself) */
	/* thread_cref
	 * thread_hmsignal_mask
	 * thread_hmsignal_unset
	 * thread_hmsignal_pending
	 */
	/*
	 * thread own miscdata accessor
	 */
	CAPMETHOD(Thread, MiscdataRead)
	CAPMETHOD(Thread, MiscdataWrite)
	CAPMETHOD(Thread, MiscdataReadv)
	CAPMETHOD(Thread, MiscdataWritev)
	CAPMETHOD(Thread, MiscdataReadvCas)
	CAPMETHOD(Thread, MiscdataWritevCas)
	CAPMETHOD(Thread, ExtFastcallBind)
	CAPMETHOD(Thread, ExtFastcallUnbind)
	CAPMETHOD(Thread, AvailableExtFastcall)

	/* Methods that only have capcall */
	CAPMETHOD(Thread, SetRq)
	CAPMETHOD(Thread, SetTickLess)
	CAPMETHOD(Thread, KvicSourceBind)
	CAPMETHOD(Thread, KvicSourceUnbind)
	CAPMETHOD(Thread, KvicKevSourceBind)
	CAPMETHOD(Thread, KvicKevSourceUnbind)

	CAPERRNO(Thread, EHMERROR, THREAD_STATE,		"E_HM_THREAD_STATE")
	CAPERRNO(Thread, EHMERROR, THREAD_NOEXSP,		"E_HM_THREAD_NOEXSP")
	CAPERRNO(Thread, EHMERROR, THREAD_HMSIGNAL_PENDING,	"E_HM_THREAD_HMSIGNAL_PENDING")
	)

#ifdef CAP_EXPORT_API
#ifndef CAP_THREAD_API_EXPORTED
#define CAP_THREAD_API_EXPORTED

#include <hmkernel/cpuset.h>
#include <hmkernel/types.h>
#include <hmkernel/capability.h>
#include <hmkernel/ipc/hmsignal.h>
#include <asm/ucontext.h>

#define HMCAP_THREAD_NAME_SIZE	16
#define THREAD_STATE_ATTR_SIZE  10

#define __CAP_TCB_OBJ_SIZE  4096u

/* the target tcb is created with a vspace in caller cnode of the syscall */
#define THREAD_CONFIG_FLAGS_MASK_CALLER_VSPACE 0x1U
/* the target tcb is created with a suspend state */
#define THREAD_CONFIG_FLAGS_MASK_IS_SUSPEND    0x2U
#define THREAD_CONFIG_FLAGS_MASK_IS_CLONE_UCTX 0x4U

#define thread_config_flags_caller_vspace(f)	(((f) & THREAD_CONFIG_FLAGS_MASK_CALLER_VSPACE) != (typeof(f))0)
#define thread_config_flags_is_suspend(f)       (((f) & THREAD_CONFIG_FLAGS_MASK_IS_SUSPEND) != (typeof(f))0)
#define thread_config_flags_is_clone_uctx(f)    (((f) & THREAD_CONFIG_FLAGS_MASK_IS_CLONE_UCTX) != (typeof(f))0)

#define THREAD_STAT_STATE		0x01UL
#define THREAD_STAT_SCHED		0x02UL
#define THREAD_STAT_UCTX		0x04UL
#define THREAD_STAT_PENDING_SIGNALS	0x08UL
#define THREAD_STAT_TIME		0x10UL
#define THREAD_STAT_RQ			0x20UL
#define THREAD_STAT_BLOCK		0x40UL
#define THREAD_STAT_CPU 		0x80UL
#define THREAD_STAT_SIGNAL_MASK 	0x100UL
#define THREAD_STAT_NVCSW		0x200UL
#define THREAD_STAT_NIVCSW		0x400UL
#define THREAD_STAT_CUR_UCTX		0x800UL
#define THREAD_STAT_HMSIGNAL 		0x1000UL
#define THREAD_STAT_MIGRATING		0x2000UL
#define THREAD_STAT_TIMER_CREF		0x4000UL

enum {
	CRIGHT_THREAD_STAT_BIT,
	CRIGHT_THREAD_SET_EX_SP_BIT,
	CRIGHT_THREAD_MISCDATA_BIT,
	CRIGHT_THREAD_MAX
};

#define CRIGHT_THREAD_STAT		(1U << CRIGHT_THREAD_STAT_BIT)
#define CRIGHT_THREAD_SET_EX_SP		(1U << CRIGHT_THREAD_SET_EX_SP_BIT)
#define CRIGHT_THREAD_MISCDATA		(1U << CRIGHT_THREAD_MISCDATA_BIT)

 /* flags in sysarg_thread_config are only used when creating thread */
struct sysarg_thread_config {
	char name[HMCAP_THREAD_NAME_SIZE];
	cref_t vspace_cref;
	cref_t scheduler_cref;  /* 0 for root scheduler */
	__u32 flags;
	int retval;

	/* TODO:
	 * Although pointer type is incompatible on 32/64,
	 * we temporarily use it for two reasons:
	 * 1. Only sysmgr use this to create a tcb cap;
	 * 2. We plan to delete it after fully support actv clone in userspace. */
	struct arch_uctx *uctx;
	struct __hmsigmask mask;
};

enum {
	TCB_RQ_TYPE_CUR,
	TCB_RQ_TYPE_USER,
	TCB_RQ_TYPE_NR,
};

struct __tcb_time {
	__u64 total;
	__u64 run;
	__u64 ready;
	__u64 suspend;
	__u64 sctime; /* state change time */
};

struct __tcb_hmsignal_info {
	struct __hmsigmask curr_actv_hmsigmask;
	struct __hmsigmask base_actv_hmsigmask;
	struct __hmsigmask pending_hmsignals;
};

struct sysarg_thread_stat {
	__u32 tcb_state;
	__u32 tcb_rq[TCB_RQ_TYPE_NR];
	__u32 tcb_block;
	__u32 tcb_futex_flags;
	__u32 tcb_running_cpu;
	__u32 tcb_cnode_idx;
	__u32 tcb_is_migrating;
	__u64 tcb_pending_signals;
	__u64 tcb_signal_mask;
	__u64 tcb_sched;
	__u64 tcb_nvcsw;
	__u64 tcb_nivcsw;
	__s32 tcb_attr[THREAD_STATE_ATTR_SIZE];
	/* thread time, unit: tock */
	struct __tcb_time tcb_time;
	struct __tcb_hmsignal_info hmsiginfo;
	cref_t prev_tcb_cref;
	cref_t preempt_tcb_cref;
	/* timer which has sent HMSIGNAL_ALARM */
	cref_t tcb_timer_cref;
	/*
	 * 1. the size of struct arch_uctx is not fixed while 32bit-uapp
	 * calls 64bit-kernel, so the uctx should be the last variable of
	 * the struct.
	 * 2. the size of all the other variables above should be fixed.
	 * 3. In aarch64 with compat opened, arch_uctx in kernel is 16 bytes
	 * aligned. However, it's aligned to 8 bytes for 32-bit uapp, so it
	 * need be aligned to 16 bytes here so that the 32-bit uapp can get
	 * correct offset.
	 */
	struct arch_uctx uctx __aligned(16);
};

struct sysarg_execve_config {
	char name[HMCAP_THREAD_NAME_SIZE];
	cref_t vspace_cref;
	struct arch_uctx uctx;
	int retval;
};
#endif
#endif
