/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: add linux/watchdog.h to compat linux interface
 * Author: Huawei OS Kernel Lab
 * Create: Wed Nov 17 19:25:26 2021
 */
#ifndef LINUX_WATCHDOG_H
#define LINUX_WATCHDOG_H

#include <linux/ioctl.h>
#include <linux/types.h>

#define	WATCHDOG_IOCTL_BASE	'W'

struct watchdog_info {
	__u32 options;
	__u32 firmware_version;
	__u8  identity[32];
};

#define WDIOC_GETSUPPORT	_IOR(WATCHDOG_IOCTL_BASE, 0, struct watchdog_info)
#define WDIOC_GETSTATUS		_IOR(WATCHDOG_IOCTL_BASE, 1, int)
#define WDIOC_GETBOOTSTATUS	_IOR(WATCHDOG_IOCTL_BASE, 2, int)
#define WDIOC_SETTIMEOUT	_IOWR(WATCHDOG_IOCTL_BASE, 6, int)
#define WDIOC_GETTIMEOUT	_IOR(WATCHDOG_IOCTL_BASE, 7, int)
#define WDIOC_SETPRETIMEOUT	_IOWR(WATCHDOG_IOCTL_BASE, 8, int)
#define WDIOC_GETPRETIMEOUT	_IOR(WATCHDOG_IOCTL_BASE, 9, int)
#define WDIOC_GETTIMELEFT	_IOR(WATCHDOG_IOCTL_BASE, 10, int)

#define WDIOF_OVERHEAT		0x0001
#define WDIOF_FANFAULT		0x0002
#define WDIOF_EXTERN1		0x0004
#define WDIOF_EXTERN2		0x0008
#define WDIOF_POWERUNDER	0x0010
#define WDIOF_CARDRESET		0x0020
#define WDIOF_POWEROVER		0x0040
#define WDIOF_SETTIMEOUT	0x0080
#define WDIOF_MAGICCLOSE	0x0100
#define WDIOF_PRETIMEOUT	0x0200
#define WDIOF_ALARMONLY		0x0400
#define WDIOF_KEEPALIVEPING	0x8000

#endif
