/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Klib atomic wrapper for libvsync
 * Author: Huawei OS Kernel Lab
 * Create: Jul 28 09:58 2021
 */

#ifndef KLIBS_VSYNC_ATOMIC_H
#define KLIBS_VSYNC_ATOMIC_H

#if defined(__HOST_LLT__) && defined(__clang__)
#define VSYNC_STDATOMIC
#endif

/* Userspace and stdatomic comes with their own stdint */
#if !defined(VSYNC_STDATOMIC)
#define VSYNC_FREESTANDING
#endif

/* Libvsync's WFE maybe can't wake up in time, close it */
#define VSYNC_NO_WFE

#include <vsync/atomic.h>
#endif /* !KLIBS_VSYNC_ATOMIC_H */
