/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: vnotify uapi header file
 * Author: Huawei OS Kernel Lab
 * Create: Thu Apr 08 15:59:15 2021
 */

#ifndef HMAPI_HMKERNEL_VNOTIFY_COMMON_H
#define HMAPI_HMKERNEL_VNOTIFY_COMMON_H

#include <hmkernel/types.h>

/* sysfast_read_status masks and bits */
#define __VNOTIFY_STATUS_MASK 2U

/* intr bit: receive msg bit */
#define __VNOTIFY_INTR 0x1U

/* pending bit: user space read clear bit */
#define __VNOTIFY_PENDING   0x2U

/* closed bit: vnotify closed bit */
#define __VNOTIFY_CLOSED 0x4U

#define __VNOTIFY_CHN_MSG_SIZE 1024
#define __VNOTIFY_CHN_MSG_PAYLOAD 1016

#define VNOTIFY_HOST_CTRL_CHANNEL 0
#define VNOTIFY_GUEST_CTRL_CHANNEL 1
#define VNOTIFY_RESERVED_CHANNEL 2

#define VNOTIFY_MAX_CHN 250
#define VNOTIFY_RESERVE_CHN 6

#define VNOTIFY_CONFIG_BIND_CHANNEL 	0U
#define VNOTIFY_CONFIG_UNBIND_CHANNEL 	1U
#define VNOTIFY_CONFIG_HOST_CLOSED	2U
#define VNOTIFY_CONFIG_GUEST_CLOSED	4U

struct __vnotify_args_s {
	__u32 *__futex;
	__u32  __id;
};

struct __vnotify_config_bind_s {
	__u32 __id;
	__u32 __binder_idx;
};

struct __vnotify_config_unbind_s {
	__u32 __id;
};

struct __vnotify_chn_msg_s {
	__u8 __modid; /* module ID */
	__u8 __type; /* msg type */
	__u16 __len;  /* msg len */
	__u32 __rsvd;  /* rsvd bits */
	__u8  __msg[__VNOTIFY_CHN_MSG_PAYLOAD];
};

#endif
