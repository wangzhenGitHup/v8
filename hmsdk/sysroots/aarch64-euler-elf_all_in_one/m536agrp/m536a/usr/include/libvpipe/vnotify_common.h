/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Vnotify common header defination
 * Author: Huawei OS Kernel Lab
 * Create: Mon Apr 12 16:00:03 2021
 */

#ifndef ULIBS_INCLUDE_LIBVPIPE_VNOTIFY_COMMON_H
#define ULIBS_INCLUDE_LIBVPIPE_VNOTIFY_COMMON_H

/*
 * NOTE: Now the <libvpipe/vnotify_common.h> might be included when
 * compiling a liblinux module. To support this, cannot include any
 * unsupported-for-liblinux-module header files here.
 */

/* block mode */
#define VNOTIFY_NONBLOCK  0x1U

/* vnotify channel create message */
#define VNOTIFY_CREATE_CHANNEL 0x1U
#define VNOTIFY_CREATE_CHANNEL_RESP 0x2U
#define VNOTIFY_DESTROY_CHANNEL 0x3U
#define VNOTIFY_DESTROY_CHANNEL_RESP 0x4U

/* flag of vnotify attach */
#define VNOTIFY_ATTACH_CREATE 0x1U
#define VNOTIFY_ATTACH_SHARED 0x2U
#define VNOTIFY_ATTACH_PRESISTENT 0x4U

#define VNOTIFY_FLAGS_SHARED 0x1U
#define VNOTIFY_FLAGS_ClOSED 0x2U

struct timespec;

struct vnotify_s {
	unsigned int chn_id;
	unsigned int flags;
	int futex;
	int *faddr;
};

struct vnotify_msg_header_s {
	unsigned char modid; /* module ID */
	unsigned char type; /* msg type */
	unsigned short len; /* msg len */
	unsigned int rsvd; /* reserved bits */
};

#endif /* !ULIBS_INCLUDE_LIBVPIPE_VNOTIFY_COMMON_H */
