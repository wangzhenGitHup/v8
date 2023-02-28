/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Inject fault into kernel
 * Author: Huawei OS Kernel Lab
 * Create: Mon Mar 30 10:17:33 CST 2020
 */

#ifndef __UAPI_HMKERNEL_FAULT_INJECT_H
#define __UAPI_HMKERNEL_FAULT_INJECT_H
#include <asm/types.h>

struct __fault_inject {
	__u32 type;
	__u32 sub_type;
	union {
		void *data_addr;
		int (*code_addr)(void);
	} extra;
};

struct __fault_inject_range {
	void *addr;
	__u32 len;
};

enum __fault_inject_type {
	__FAULT_INJECT_CRASH = 0,
	__FAULT_INJECT_MEM,
	__FAULT_INJECT_SCHED,
	/* privilege access */
	__FAULT_INJECT_PRI_ACCESS,
	__FAULT_INJECT_UCOPY,
	__FAULT_INJECT_UNKNOWN,
};

enum __fault_inject_crash_type {
	__FAULT_INJECT_CRASH_PANIC = 0,
	__FAULT_INJECT_CRASH_BUGON,
	__FAULT_INJECT_CRASH_DIVIDE_ZERO,
	__FAULT_INJECT_CRASH_UNKNOWN,
};

enum __fault_inject_mem_type {
	__FAULT_INJECT_MEM_BIG_ARRAY = 0,
	__FAULT_INJECT_MEM_ACCESS_NULL,
	__FAULT_INJECT_MEM_UNKNOWN,
};

enum __fault_inject_sched_type {
	__FAULT_INJECT_SCHED_LOOP_DEAD = 0,
	__FAULT_INJECT_SCHED_UNKNOWN,
};

/* privilege access subtype */
enum __fault_inject_pri_access_type {
	__FAULT_INJECT_PRI_ACCESS_PAN = 0,
	__FAULT_INJECT_PRI_ACCESS_PXN,
	__FAULT_INJECT_RRI_ACCESS_UNKNOWN,
};

enum __fault_inject_ucopy_type {
	__FAULT_INJECT_UCOPY_TO_TEXT = 0,
	__FAULT_INJECT_UCOPY_TO_STACK_FRAME,
	__FAULT_INJECT_UCOPY_FROM_STACK_FRAME,
	__FAULT_INJECT_UCOPY_UNKNOWN,
};

#endif
