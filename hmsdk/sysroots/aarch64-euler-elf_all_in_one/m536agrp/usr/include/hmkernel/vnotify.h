/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: vnotify uapi for dfx header file
 * Author: Huawei OS Kernel Lab
 * Create: Tue Oct 19 16:11:24 2021
 */
#ifndef HMAPI_HMKERNEL_VNOTIFY_H
#define HMAPI_HMKERNEL_VNOTIFY_H

#include <vsync/atomic.h>
#include <hmkernel/vnotify_common.h>

#define __NR_EXT_FASTCALL_VNOTIFY				7
#define __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_CHANNEL		5
#define __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_CTRL_CHANNEL	6
#define __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_READ_CHN_MSG	7
#define __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_UPDATE_FUTEX	8
#define __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_READ_STATUS	9
#define __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_INJECT_EVENT	10
#define __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_CLEAR_VSPACE	11

struct __chn_s {
	atomic_t flags;
	atomic_t status;
};

struct vnotify_mem_s {
	struct __chn_s chns[ VNOTIFY_MAX_CHN + VNOTIFY_RESERVE_CHN ];
	struct __vnotify_chn_msg_s host_msg;
	struct __vnotify_chn_msg_s guest_msg;
};

#endif
