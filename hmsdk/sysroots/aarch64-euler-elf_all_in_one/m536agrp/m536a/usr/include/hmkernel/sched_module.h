/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Declaration of sched module for uapi
 * Author: Huawei OS Kernel Lab
 * Create: Mon Nov 25 11:03:00 2019
 */
#ifndef UAPI_MODULE_SCHED_MODULE_H
#define UAPI_MODULE_SCHED_MODULE_H

#include <hmkernel/capability.h>
#include <hmkernel/cpuset.h>

#define SCHED_TIMESLICE_MS_MAX_SIZE	5

/* Thread(tcb) operaiton */
#define __SCHED_SET_CONF 0UL
#define __SCHED_GET_CONF 1UL
#define __SCHED_TCB_SET_ATTR 2UL
#define __SCHED_TCB_GET_ATTR 3UL
/* Sched operation */
#define __SCHED_LOAD_BALANCER_SWITCH 100UL
#define __SCHED_GET_SCHED_DEBUG_ATTR 101UL
#define __SCHED_GET_LOADAVG 102UL
/* Preempt operation */
#define __SCHED_PREEMPT_CONF 203UL
#define __SCHED_PREEMPT_PROCESS_EXIT 204UL
#define __SCHED_PREEMPT_SET_SLV 205UL
/* Bandwidth operation */
#define __SCHED_BANDWIDTH_SET_CONF 301UL
#define __SCHED_BANDWIDTH_GET_CONF 302UL
/* Stat operation */
#define __SCHED_GET_STAT_CONF 401UL

struct sched_param_s {
	cref_t thread_cref;
	int nice;
	int policy;
	int priority;
	int max_available_priority;
	__cpuset_t affinity;
	cref_t prev_tcb_cref;
	cref_t preempt_tcb_cref;
};

struct sched_config_s {
	/* SCHED_RT */
	unsigned int sched_timeslice_ms;
};

#define LOADAVG_NR 3U
/* 3 items of loadavg summary */
#define LOADAVG_1MIN_IDX 0U
#define LOADAVG_5MIN_IDX 1U
#define LOADAVG_15MIN_IDX 2U

/* loadavg = sum / div */
struct loadavg_s {
	__u64 load_sum[LOADAVG_NR];
	__u64 load_scale[LOADAVG_NR];
};

#define SCHED_RT_BANDWIDTH_RUNTIME 0U
#define SCHED_RT_BANDWIDTH_PERIOD 1U
#define SCHED_OTHER_BANDWIDTH_QUOTA 2U
#define SCHED_OTHER_BANDWIDTH_PERIOD 3U
#define SCHED_OTHER_BANDWIDTH_CPU_MAX 4U

struct sched_bandwidth_args_s {
	unsigned int opt;

	unsigned int period;
	unsigned int max_runtime;
	cref_t scheduler; 	/* for ices ml sched only */
};

#define SCHED_CPU_STAT 0U

struct sched_cpu_stat_s {
	__u64 run_usec;
	cref_t scheduler;
};

struct sched_stat_args_s {
	__u32 opt;
	struct sched_cpu_stat_s cpu_stat;
};

struct sched_module_args_s {
	struct sched_config_s sched_conf;
	struct sched_param_s tcb_param;
	__u32 flag;
};

enum sched_load_balancer_cmd_e {
	__LOAD_BALANCER_SWITCH_ON,
	__LOAD_BALANCER_SWITCH_OFF,
	__LOAD_BALANCER_STAT,
};

struct sched_load_balancer_args_s {
	enum sched_load_balancer_cmd_e cmd;
	_Bool stat;
};

/* Used by tcb SET/GET attr operation */
#define SCHED_TCB_FLAG_PARAM				1U
#define SCHED_TCB_FLAG_AFFINITY				(1U << 1)
#define SCHED_TCB_FLAG_SCHEDULER			(1U << 2)
#define SCHED_TCB_FLAG_NICE				(1U << 3)
#define SCHED_TCB_FLAG_GET_AVAILABLE_PRIORITY_MAX	(1U << 4)
#define SCHED_TCB_FLAG_RESET_ON_FORK			(1U << 5)

/* sched preempt state */
#define PREEMPT_ENABLE			0U /* enable reschedule (default) */
#define PREEMPT_DISABLE			1U /* disable reschedule in module */
#define PREEMPT_DISABLE_PASSIVE		2U /* disable passive reschedule triggered by timer */
#define PREEMPT_CLEAR_TCB_EXCEPTION	3U /* preempt exception handler is ready, tcb can be scheduled */
#define PREEMPT_CLEAR_SYS_EXCEPTION	4U /* preempt exception handling is completed */
#define PREEMPT_PROCESS_REGISTER	5U /* register process preempt */
#define PREEMPT_PROCESS_UNREGISTER	6U /* unregister process preempt */
#define PREEMPT_PROCESS_STAT_QUERY	7U /* query if preempt process feature is enabled or not */

/*
 * process sched level setting
 *
 * sched level is a per-process sched control.
 * Normally, only threads having >= current sched level of process at current cpu
 * level can run, that is: thread.slv >= process.slv(cpu)
 * Specially, when a lower sched level thread disable process preempt, it will be allowed to
 * run and throttled as long as preempt is enabled again.
 *
 * Some default config:
 * 1. all processes start with sched level 0 at all available cpus
 * 2. by default, all process's threads are at sched level 0, and CAN be adjusted;
 * 3. all actvs run with sched level 0, and CANNOT be adjusted.
 */
#define PREEMPT_SLV_SET_PROCESS                100U
#define PREEMPT_SLV_SET_THREAD         101U

struct sched_preempt_args_s {
	cref_t thread_cref;
	unsigned int type;
};

struct sched_preempt_slv_args_s {
	__u32 cmd;
	__u32 cpu;
	__u32 slv;
	cref_t thread_cref;
};
#endif
