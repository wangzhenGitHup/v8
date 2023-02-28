/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: power_reboot.h for uapi
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 28 018:44:43 2021
 */

#ifndef UAPI_HMKERNEL_POWER_REBOOT_H
#define UAPI_HMKERNEL_POWER_REBOOT_H

enum system_reboot_type {
	SYSTEM_REBOOT_BASE = 0xffff0000,
	SYSTEM_REBOOT_KERNEL_PANIC = SYSTEM_REBOOT_BASE,
	SYSTEM_REBOOT_SYSMGR_PANIC,
	SYSTEM_REBOOT_INIT_PANIC,
	SYSTEM_REBOOT_HARDDOG_HUNGRY,
	SYSTEM_REBOOT_LOWDOG_HUNGRY,
	SYSTEM_REBOOT_HIGHDOG_HUNGRY,
	SYSTEM_REBOOT_COLDBOOT,
	SYSTEM_REBOOT_MAX,
};

#define SYSTEM_REBOOT_MAX_NUM	(((unsigned int)(SYSTEM_REBOOT_MAX)) - ((unsigned int)(SYSTEM_REBOOT_BASE)))

#endif
