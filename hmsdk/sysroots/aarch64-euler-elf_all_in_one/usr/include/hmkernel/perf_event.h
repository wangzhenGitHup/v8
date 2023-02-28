/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Definition of perf event
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jul 20 10:25:28 2020
 */
#ifndef UAPI_HMKERNEL_PERF_EVENT_H
#define UAPI_HMKERNEL_PERF_EVENT_H

#include <asm/types.h>
#include <hmkernel/capability.h>

enum __perf_pmu_config_cmd {
	__PERF_PMU_CONFIG_INVALID = 0,
	__PERF_PMU_CONFIG_USER_ENABLE,
	__PERF_PMU_CONFIG_USER_DISABLE,
	__PERF_PMU_CONFIG_EVTYPE_SET,
	__PERF_PMU_CONFIG_EVTCNT_GET,
};

enum __perf_event_type {
	__PERF_EVENT_TYPE_INVALID = 0u,
	__PERF_EVENT_TYPE_HARDWARE,
	__PERF_EVENT_TYPE_HARDWARE_ARM_DSU,
	__PERF_EVENT_TYPE_RAW,
};

struct __perf_event_attr_s {
	__u32 type;
	__u32 config;
	__u64 period;
};

#define __PERF_CONFIGURABLE_EVENT_COUNTER_NUM 32UL
struct __perf_event_config_s {
	struct __perf_event_attr_s evts[__PERF_CONFIGURABLE_EVENT_COUNTER_NUM];
};

struct __perf_event_ret_s {
	__u64 counters[__PERF_CONFIGURABLE_EVENT_COUNTER_NUM];
};

#define PMU_SAMPLE_DATA_LEN sizeof(struct __perf_pmu_sample_data)

/*
 * perf report uses cnode_idx to connect the sampled event with the process event.
 * Hence, to display the symbol of the VM, we also need to connect the sampled event
 * in guest's address with the guest image. In perf report, for each vm, we create
 * a new process with a single mmap event to reuse existing symbol parsing & merging
 * mechanism.
 */
#define PMU_SAMPLE_VM_CNODE_IDX_BASE 0x80000000
struct __perf_pmu_sample_data {
	__u64 pc;
	__u32 cnode_idx;
	char name[HMCAP_THREAD_NAME_SIZE];
};
#endif
