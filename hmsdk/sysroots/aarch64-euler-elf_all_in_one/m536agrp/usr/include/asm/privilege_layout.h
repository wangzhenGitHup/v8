/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Sun Oct 6 10:29:09 2019
 */
#ifndef UAPI_ASM_PRIVILEGE_LAYOUT
#define UAPI_ASM_PRIVILEGE_LAYOUT

#include <hmkernel/const.h>

#define __PRIVILEGE_NORMAL		0
#define __PRIVILEGE_SYSMGR		1
#define __PRIVILEGE_TMPFS 		2
#define __PRIVILEGE_IDLE		3
#define __NR_PRIVILEGE_SERVICE		4

/* VA Gap between different privilged services, default 50MB */
#define __PRIVILEGE_SERVICE_VA_GAP	(__UL(50) << 20)

/* calculates privileged service start address and vlimit */
#define __privilege_vstart_addr(__va_start, __vs_size, n) ((__va_start) + \
	((unsigned long)(__vs_size) + __PRIVILEGE_SERVICE_VA_GAP) * ((n) - __UL(1)))
#define __privilege_vlimit_addr(__va_start, __vs_size, n) ((__va_start) + \
	((unsigned long)(__vs_size) * (n) + __PRIVILEGE_SERVICE_VA_GAP * ((n) - __UL(1))))
#endif
