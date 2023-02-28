/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Tue May 19 10:03:24 2020
 */
#ifndef HM_INCLUDE_HMSCHED_H
#define HM_INCLUDE_HMSCHED_H

#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>

struct sched_attr {
	uint32_t size;

	uint32_t sched_policy;
	uint64_t sched_flags;

	/* SCHED_OTHER*/
	int32_t sched_nice;

	/* SCHED_FIFO, SCHED_RR */
	uint32_t sched_priority;

	/* SCHED_DEADLINE */
	uint64_t sched_runtime;
	uint64_t sched_deadline;
	uint64_t sched_period;
};

int sched_get_available_priority_max(void);
int sched_setattr(pid_t pid, const struct sched_attr *attr,
		  unsigned int flags);

#endif
