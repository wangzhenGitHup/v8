/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Udata
 * Author: Huawei OS Kernel Lab
 * Create: Sat Oct 12 20:03:34 2019
 */
#ifndef UAPI_HMKERNEL_UDATA_H
#define UAPI_HMKERNEL_UDATA_H

#include <asm/page.h>
#include <asm/types.h>
#include <hmkernel/errno.h>
#include <hmkernel/seqlock.h>
#include <hmkernel/compiler.h>

#define UDATA_PMEM_SIZE PAGE_SIZE

#define __MSEC_PER_SEC	1000U

#define __USEC_PER_MSEC	1000U

#define __USEC_PER_SEC	(__USEC_PER_MSEC * __MSEC_PER_SEC)

#define __NSEC_PER_USEC	1000U

#define __NSEC_PER_MSEC	(__NSEC_PER_USEC * __USEC_PER_MSEC)

#define __NSEC_PER_SEC	(__NSEC_PER_USEC * __USEC_PER_SEC)

struct kshare_udata_s {
	struct __seqcnt_s tock_seq;
	__u32 freq;
	__s64 tock_offset;
	__u64 tock_last;
	__u64 tock_mono_nsec;
	__u64 tock_mono_sec;
	__u32 tock_base_nsec;
	__s64 tock_base_sec;
	__u32 mul;
	__u32 mov;
	__u64 sec_length;
	__u64 tock_mono_last;
};

#endif
