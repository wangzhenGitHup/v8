/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Futex related definition
 * Author: Huawei OS Kernel Lab
 * Create: Sun Dec 13 17:36:19 2020
 */
#ifndef UAPI_HMKERNEL_FUTEX_H
#define UAPI_HMKERNEL_FUTEX_H

#include <hmkernel/const.h>

#define FUTEX_MASK_TYPE_USER		__UL(0)
#define FUTEX_MASK_TYPE_SIMPLE_NONE	__UL(1)
#define FUTEX_MASK_TYPE_SIMPLE_ALL	__UL(2)
#define FUTEX_MASK_TYPE_SIMPLE_EMRG	__UL(3)

#endif
