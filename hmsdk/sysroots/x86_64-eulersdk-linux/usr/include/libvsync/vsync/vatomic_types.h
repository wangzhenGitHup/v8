/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Oct 14 11:07 2021
 */

#ifndef VSYNC_VATOMIC_TYPES_H
#define VSYNC_VATOMIC_TYPES_H

#define __ALIGNED_32__ __attribute__((aligned(4)))
#define __ALIGNED_64__ __attribute__((aligned(8)))

struct vatomic32_s {
	vuint32_t __v;
} __ALIGNED_32__;
typedef struct vatomic32_s vatomic32_t;

struct vatomic64_s {
	vuint64_t __v;
} __ALIGNED_64__;
typedef struct vatomic64_s vatomic64_t;

struct vatomicptr_s {
	void *__v;
} __ALIGNED_64__;
typedef struct vatomicptr_s vatomicptr_t;

typedef unsigned long vuintptr_t;

#define __FENCE(mo) __ATOMIC_EXPANDER(map_dmb_, mo)

#define DEFINE_ATOMIC_FENCE_TYPE(mo)             \
	static inline void                       \
	__ATOMIC_ENAME(vatomic_fence, mo)(void)  \
	{                                        \
		__asm__ volatile(                \
			__FENCE(mo)              \
			::: "memory"             \
		);                               \
	}
#define DEFINE_ATOMIC_FENCE(mo) DEFINE_ATOMIC_FENCE_TYPE(mo)

#endif /* !VSYNC_VATOMIC_TYPES_H */
