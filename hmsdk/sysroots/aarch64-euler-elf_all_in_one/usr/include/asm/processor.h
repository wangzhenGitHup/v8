/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Thu Apr 25 10:52:02 2019
 */
#ifndef AARCH64_UAPI_ASM_PROCESSOR_H
#define AARCH64_UAPI_ASM_PROCESSOR_H

#define PSR_T_BIT	(1UL << 5UL)

#ifndef __ASSEMBLY__

static inline void cpu_relax(void)
{
	asm volatile("yield" ::: "memory");
}

#endif

#endif
