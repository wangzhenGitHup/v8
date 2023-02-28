/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Definition of barrier
 * Author: Huawei OS Kernel Lab
 * Create: Tue Aug 7 11:06:49 2018
 */
#ifndef UAPI_HMKERNEL_BARRIER_H
#define UAPI_HMKERNEL_BARRIER_H

#include <hmkernel/compiler.h>
#include <asm/barrier.h>

#ifdef CONFIG_SMP

#define smp_mb()  __smp_mb()
#define smp_rmb() __smp_rmb()
#define smp_wmb() __smp_wmb()

#else
/* if no smp support */
#define smp_mb()  barrier()
#define smp_rmb() barrier()
#define smp_wmb() barrier()

#endif
#endif
