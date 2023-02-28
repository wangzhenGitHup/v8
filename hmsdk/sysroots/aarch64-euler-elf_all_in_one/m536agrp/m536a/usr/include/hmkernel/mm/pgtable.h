/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Pgtable
 * Author: Huawei OS Kernel Lab
 * Create: Fri Aug 24 21:51:08 2018
 */
#ifndef UAPI_HMKERNEL_PGTABLE_H
#define UAPI_HMKERNEL_PGTABLE_H

#include <asm/types.h>

#define PGTABLE_HINT_OFFLINE	(__u64)(1UL)
#define PGTABLE_HINT_BIG	(__u64)(1UL << 1U)
#define PGTABLE_HINT_LARGE	(__u64)(1UL << 2U)
#define PGTABLE_HINT_BEST	(__u64)(1UL << 3U)
#define PGTABLE_ATTR_KOBJ	(__u64)(1UL << 9U)
#define PGTABLE_ATTR_DEVICE	(__u64)(1UL << 10U)
#define PGTABLE_ATTR_UREAD	(__u64)(1UL << 11U)
#define PGTABLE_ATTR_UWRITE	(__u64)(1UL << 12U)
#define PGTABLE_ATTR_UEXEC	(__u64)(1UL << 13U)
#define PGTABLE_ATTR_KREAD	(__u64)(1UL << 14U)
#define PGTABLE_ATTR_KWRITE	(__u64)(1UL << 15U)
#define PGTABLE_ATTR_KEXEC	(__u64)(1UL << 16U)
#define PGTABLE_ATTR_NOCACHE	(__u64)(1UL << 17U)
#define PGTABLE_ATTR_KMAP	(__u64)(1UL << 18U)
#define PGTABLE_ATTR_PSMAP	(__u64)(1UL << 19U)
#define PGTABLE_ATTR_HYPMAP	(__u64)(1UL << 20U)
#define PGTABLE_ATTR_MASTER	(__u64)(1UL << 21U)
#define PGTABLE_ATTR_INVAL	(__u64)(1UL << 22U)

#define PGTABLE_ATTR_DOMAIN_SHIFT 24U
#define PGTABLE_ATTR_DOMAIN_BITS 4U

#endif
