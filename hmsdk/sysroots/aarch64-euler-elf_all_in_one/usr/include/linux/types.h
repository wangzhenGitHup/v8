/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: add linux/types.h to compat linux interface
 * Author: Huawei OS Kernel Lab
 * Create: Sat Sep 11 18:10:40 2021
 */

#ifndef _LINUX_TYPES_H_
#define _LINUX_TYPES_H_

#include <linux/uapi/types.h>

typedef long long	__kernel_loff_t;

typedef unsigned int	uint;

#endif
