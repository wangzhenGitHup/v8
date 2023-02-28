/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: sysreg utilties
 * Author: Huawei OS Kernel Lab
 * Create: Wed Aug 19 19:53:03 CST 2021
 */

#ifndef AARCH64_MAPI_UAPI_ASM_SYSREG_UTILS_H
#define AARCH64_MAPI_UAPI_ASM_SYSREG_UTILS_H

#include <asm/types.h>

#define __aarch64_read_sysreg(name)				\
({								\
	__u64 __v;						\
	asm volatile ("mrs %0, " name "\n" : "=r" (__v));	\
	__v;							\
})

#define __aarch64_write_sysreg(name, v)				\
({								\
	__u64 __v = (v);					\
	asm volatile ("msr " name ", %0\n" :: "r" (__v));	\
})

#define __AARCH64_DEFINE_sysreg_rd(prefix, name, el)		\
static inline __u64						\
prefix##_##name##_##el(void)					\
{								\
	return __aarch64_read_sysreg(#name "_" #el);		\
}

#define __AARCH64_DEFINE_sysreg_wr(prefix, name, el)		\
static inline void						\
prefix##_##name##_##el(__u64 v)					\
{								\
	__aarch64_write_sysreg(#name "_" #el, v);		\
}

#define __AARCH64_DEFINE_sysreg_rd32(prefix, name, el)		\
static inline __u32						\
prefix##_##name##_##el(void)					\
{								\
	return (__u32)__aarch64_read_sysreg(#name "_" #el);	\
}

#define __AARCH64_DEFINE_sysreg_wr32(prefix, name, el)		\
static inline void						\
prefix##_##name##_##el(__u32 v)					\
{								\
	__aarch64_write_sysreg(#name "_" #el, v);		\
}

#endif
