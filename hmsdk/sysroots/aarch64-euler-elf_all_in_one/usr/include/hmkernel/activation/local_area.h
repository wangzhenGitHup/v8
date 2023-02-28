/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Local area
 * Author: Huawei OS Kernel Lab
 * Create: Fri May 08 01:04:39 2020
 */
#ifndef MAPI_UAPI_HMKERNEL_ACTIVATION_LOCAL_AREA_H
#define MAPI_UAPI_HMKERNEL_ACTIVATION_LOCAL_AREA_H

#include <hmkernel/ipc/hmsignal.h>
#include <asm/ucontext.h>

struct __sched_info_s {
	/* sched info is inited or not */
	__u32 inited;
	/* sched state of current cpu */
	__u32 state;
	/* current cpu id */
	__u32 cpu;
	/* need to do reschedule immediately */
	__u32 resched;
};

/*
 * __actv_local_area_k contains some kernel information local to one activation
 * actv, which are delivered by kernel to actv stack in user space.
 */
struct __actv_local_area_k {
	/*
	 * Synchronize the raising_hmsignals of the base actv.
	 * The actv handler can read it and decide how to react.
	 * For example, handler may choose to pop itself immediately
	 * when finding the HMSIGNAL_KILL is base raising.
	 */
	struct __hmsigmask raising_hmsignals;
	/*
	 * Synchronize the sched info of actv.
	 * The scheduler may change strategy based on the sched info or
	 * sync sched info to user so that user can read it faster.
	 * For example, user can tell kernel to disable process preempt in
	 * current cpu and acquire cpu id without entering kernel.
	 */
	struct __sched_info_s sched_info;
};

#define __ACTV_LOCAL_AREA_OFFSET_INVALID	__ARCH_UCTX_TLS_MINIMAL_SIZE

#endif
