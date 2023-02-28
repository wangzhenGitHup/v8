/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Definition of copage
 * Author: Huawei OS Kernel Lab
 * Create: Sat Oct 12 20:03:34 2019
 */
#ifndef UAPI_HMKERNEL_COPAGE_H
#define UAPI_HMKERNEL_COPAGE_H

#include <asm/page.h>
#include <asm/types.h>
#include <hmkernel/const.h>

#define COPAGE_LV1_SHIFT 9
#define COPAGE_LV1_MASK (((unsigned int)1 << COPAGE_LV1_SHIFT) - 1U)
#define COPAGE_LV2_SHIFT PAGE_SHIFT

#define COPAGE_SIZE_TO_LV2(size) \
	((size) >> __U(COPAGE_LV2_SHIFT))

#define COPAGE_LV2_TO_LV1_ALIGN_DOWN(lv2_off) \
	((lv2_off) >> __U(COPAGE_LV1_SHIFT))

#define COPAGE_LV2_TO_LV1_ALIGN_UP(lv2_off)	\
	(((lv2_off) >> __U(COPAGE_LV1_SHIFT)) +	\
	(((lv2_off) & COPAGE_LV1_MASK) != 0U ? 1U : 0U))

#define COPAGE_LV1_TO_LV2(lv1_off) \
	((lv1_off) << __U(COPAGE_LV1_SHIFT))

struct sysarg_copage_global_info_s {
	__u64 pfn_start;
	__u64 pfn_end;
	__u32 free_pages;
};

struct sysarg_copage_local_info_s {
	__u64 vaddr_start;
	__u64 ga_mapping;
	__u32 used_pages;
};

struct sysarg_copage_range_s {
	__u64 pstart;
	__u64 pend;
};

struct sysarg_copage_add_local_s {
	__u32 cnode_idx;
	__u64 vaddr_start;
	__u64 ga_mapping;
	__u64 pmem_cref;
	__u64 pfn_start;
	__u64 pfn_end;
};

enum __copage_ctrl_cmd {
	__COPAGE_GLOBAL_INIT,
	__COPAGE_ADD_LOCAL,
	__COPAGE_REMOVE_LOCAL,
	__COPAGE_QUERY_LOCAL,
	__COPAGE_QUERY_GLOBAL,
	__COPAGE_NR,
};

#endif
