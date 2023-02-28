/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Common utilities for performance infrastructure event
 * Author: Huawei OS Kernel Lab
 * Create: Thu Aug 5 16:52:49 2021
 */
#ifndef KLIBS_PERFRA_PFEV_UTILS_H
#define KLIBS_PERFRA_PFEV_UTILS_H

#include <asm/types.h>
#include <hmkernel/errno.h>

#include <string.h>

#define __pfev_atomic_add_fetch(ptr, v)	__atomic_add_fetch(ptr, v, __ATOMIC_SEQ_CST)
#define __pfev_atomic_load(ptr)		__atomic_load_n(ptr, __ATOMIC_SEQ_CST)
#define __pfev_atomic_store(ptr, v)	__atomic_store_n(ptr, v, __ATOMIC_SEQ_CST)
#define __pfev_atomic_cas(ptr, pcmp, v)	\
	__atomic_compare_exchange_n(ptr, pcmp, v, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#define __PFEV_CHUNK_SIZE_ORDER_MIN	4
#define __pfev_init_check_param(pfev_, desc_, chunk_, chunk_size_order_) \
	(((pfev_) == NULL) || ((desc_) == NULL) || \
	 ((chunk_) == NULL) || ((chunk_size_order_) <= __PFEV_CHUNK_SIZE_ORDER_MIN))
#define __pfev_init_mark_inval(err_) \
	do { \
		(*(err_)) = E_HM_INVAL; \
	} while (0)
#define __pfev_init_mark_param(pfev_, desc_, chunk_, chunk_size_order_) \
	do {\
		typeof(pfev) __pfev = (pfev_); \
		__pfev->desc = (desc_); \
		__pfev->chunk = (chunk_); \
		__pfev->chunk_size_order = (chunk_size_order_); \
		__pfev_atomic_store(&__pfev->desc->cursor, 0); \
	} while (0)

#endif
