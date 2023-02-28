/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: vnotify extension call declaration.
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jun 11 16:04:10 2021
 */

#ifndef ULIBS_LIBVPIPE_VNOTIFY_IMPL_H
#define ULIBS_LIBVPIPE_VNOTIFY_IMPL_H

#include <hmkernel/vnotify.h>
#include <hongmeng/ext_fast_syscall.h>

__EXT_FASTCALL_GLOBAL(2, vnotify_notify_channel, __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_CHANNEL,
			 unsigned int, chn_id,
			 struct __vnotify_chn_msg_s *, msg)

__EXT_FASTCALL_GLOBAL(2, vnotify_notify_ctrl_channel, __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_CTRL_CHANNEL,
			 unsigned int, chn_id,
			 struct __vnotify_chn_msg_s *, msg)

__EXT_FASTCALL_GLOBAL(2, vnotify_read_chn_msg, __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_READ_CHN_MSG,
			 unsigned int, chn_id,
			 struct __vnotify_chn_msg_s *, msg)

__EXT_FASTCALL_GLOBAL(2, vnotify_update_futex, __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_UPDATE_FUTEX,
			 unsigned int, chn_id,
			 int *, futex)

__EXT_FASTCALL_GLOBAL(2, vnotify_read_status, __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_READ_STATUS,
			 unsigned int, chn_id,
			 unsigned int *, status)

__EXT_FASTCALL_GLOBAL(1, vnotify_inject_event, __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_INJECT_EVENT,
			 unsigned int, chn_id)

__EXT_FASTCALL_GLOBAL(1, vnotify_clear_vspace, __EXT_FASTCALL_GLOBAL_VNOTIFY_NOTIFY_CLEAR_VSPACE,
			 cref_t *, vspace_cref)
#endif
