/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
 * Description: Definition of ulibs buddy
 * Author: Huawei OS Kernel Lab
 * Create: Sat Sep 15 15:57:52 2018
 */
#ifndef ULIBS_INCLUDE_LIBMEM_BUDDY_H
#define ULIBS_INCLUDE_LIBMEM_BUDDY_H

/*
 * In order to share the formatted memory information
 * print function in `libmem/mprint.c` between sysmgr
 * and uapps, we define `BUDDY_MAX_ORDER` in ulibs,
 * and it should be same as Kconfig in sysmgr.
 */
#ifndef BUDDY_MAX_ORDER
#ifdef CONFIG_SYSMGR_BUDDY_MAX_ORDER
#define BUDDY_MAX_ORDER		(unsigned)CONFIG_SYSMGR_BUDDY_MAX_ORDER
#else
#define BUDDY_MAX_ORDER		20U
#endif
#endif

/*
 * The reachable maximum buddy order is no more than BUDDY_MAX_ORDER,
 * so here defines BUDDY_ORDER_CNT to initialize the buddy page lists
 * and stat arraies in which each order page is calculated repectively.
 */
#define BUDDY_ORDER_CNT		(BUDDY_MAX_ORDER + 1U)

#endif
