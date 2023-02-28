/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: add linux/linux-asm/asm/posix_types.h to compat linux interface
 * Author: Huawei OS Kernel Lab
 * Create: Wed Nov 17 11:31:42 2021
 */

#ifndef LINUX_ASM_POSIX_TYPES_H
#define LINUX_ASM_POSIX_TYPES_H

#ifndef __kernel_long_t
typedef long		__kernel_long_t;
typedef unsigned long	__kernel_ulong_t;
#endif

#ifndef __KERNEL__
typedef __kernel_long_t	__kernel_time_t;
#endif

#endif
