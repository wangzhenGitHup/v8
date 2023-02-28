/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Common layer of arm pmu in libperf
 * Author: Huawei OS Kernel Lab
 * Create: Tue Dec 25 17:05:22 2018
 */
#ifndef ULIBS_LIBPERF_ARM_PMU_COMMON_H
#define ULIBS_LIBPERF_ARM_PMU_COMMON_H

#include "perf.h"

#define HW_MAX_COUNTER_NUM		7U

/* Perf Event counter' index */
#define	ARM_PMU_IDX_COUNTER_START	0U

/*
 * PMU HW is implemented with one default Cycle Counter,
 * and sereval Event Counters PMEVCNTR<n>, n=[0-5]
 */
#define	ARM_PMU_IDX_EVENT_COUNTER0	1U

#define ARM_PMU_MAX_COUNTERS	32U
#define ARM_PMU_COUNTER_MASK	(ARM_PMU_MAX_COUNTERS - 1U)

/*
 * Perf Event to low level counters mapping
 * Cycle Counter idx is C=bit[31], 0x1F=ARMV8_COUNTER_MASK
 */
#define	ARM_PMU_IDX_TO_COUNTER(x)	\
	(((x) - ARM_PMU_IDX_EVENT_COUNTER0) & ARM_PMU_COUNTER_MASK)

/* common pmu init functions. */
int hw_pmu_init(struct generic_pmu *pmu, const struct perf_evset_attr *attr);
int sw_pmu_init(struct generic_pmu *pmu, const struct perf_evset_attr *attr);

/* function(s) in pmuv(1,2,3...).c */
unsigned int pmu_event_counters_num(void);
int check_implemented_event(unsigned int idx, unsigned int *eventid);
int check_implemented_dsu_event(unsigned int idx, unsigned int *eventid);

#endif
