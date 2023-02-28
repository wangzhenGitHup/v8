/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Rt futex function declaration
 * Author: Huawei OS Kernel Lab
 * Create: Sat Apr 11 17:36:19 2020
 */
#ifndef UAPI_HMKERNEL_RT_FUTEX_H
#define UAPI_HMKERNEL_RT_FUTEX_H

#define RT_FUTEX_ID_MASK     0x3fffffff
#define RT_FUTEX_OWNER_DEAD  0x40000000
#define RT_FUTEX_HAS_WAITERS 0x80000000U

#define RT_FUTEX_PRIVATE       0x1UL
#define RT_FUTEX_OWNER_IS_ACTV 0x2UL

#endif
