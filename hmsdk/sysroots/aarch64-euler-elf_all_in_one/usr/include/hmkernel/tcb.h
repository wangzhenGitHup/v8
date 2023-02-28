/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Definition for tcb uapi
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jan 24 13:36:28 2019
 */
#ifndef UAPI_TCB_H
#define UAPI_TCB_H

enum __tcb_state {
	__TCB_STATE_READY,
	__TCB_STATE_RUNNING,
	__TCB_STATE_BLOCKED,
	__TCB_STATE_WTD,  // TCB is waiting to die
	__TCB_STATE_DEAD, // TCB is dead for resource deallocation
	__TCB_STATE_UNKNOWN,
};

enum __tcb_block_reason {
	__TCB_BLOCK_FUTEX,
	__TCB_BLOCK_LOCK,
	__TCB_BLOCK_JOIN,
	__TCB_BLOCK_RECV,
	__TCB_BLOCK_TRIGGER,
	__TCB_NO_BLOCK,
};

enum __tcb_attach_type {
	__TCB_ATTACH_TYPE_THREAD,
	__TCB_DETACH_TYPE_THREAD,
	__TCB_ATTACH_TYPE_ACTV,
	__TCB_DETACH_TYPE_ACTV,
	__TCB_DETACH_TYPE_UNKONWN,
};

#endif
