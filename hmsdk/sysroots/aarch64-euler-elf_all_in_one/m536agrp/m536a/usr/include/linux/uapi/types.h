/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: add linux/uapi/types.h to compat linux interface
 * Author: Huawei OS Kernel Lab
 * Create: Sat Sep 11 17:40:09 2021
 */

#ifndef _UAPI_LINUX_TYPES_H
#define _UAPI_LINUX_TYPES_H

#include <asm/types.h>

#ifndef __kernel_uid21_t
typedef unsigned int	__kernel_uid32_t;
#endif

#ifndef __ASSEMBLY__

#ifdef __CHECKER__
#define __bitwise__ __attribute__((bitwise))
#else
#define __bitwise__
#endif
#define __bitwise __bitwise__

typedef __u16 __bitwise __le16;
typedef __u16 __bitwise __be16;
typedef __u32 __bitwise __le32;
typedef __u32 __bitwise __be32;
typedef __u64 __bitwise __le64;
typedef __u64 __bitwise __be64;

#endif /*  __ASSEMBLY__ */
#endif /* _UAPI_LINUX_TYPES_H */
