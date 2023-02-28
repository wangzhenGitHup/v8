/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Definition of ulibs page type
 * Author: Huawei OS Kernel Lab
 * Create: Fri May 08 10:21:59 2020
 */
#ifndef ULIBS_INCLUDE_LIBMEM_PAGE_TYPE_H
#define ULIBS_INCLUDE_LIBMEM_PAGE_TYPE_H

enum page_type {
	PAGE_T_NONE,
	PAGE_T_VOID,
	PAGE_T_PMEM,
	PAGE_T_PGTABLE,
	PAGE_T_FILE,
	PAGE_T_ANON,
	PAGE_T_IOMM,
	PAGE_T_BUDDY,
	PAGE_T_SLAB,
	PAGE_T_KSHARE,
	PAGE_T_ELF,
	PAGE_T_RSV,
	PAGE_T_BOOT,
	PAGE_T_COPAGE,
	PAGE_T_TASKGRP,
	PAGE_T_HGTLB,
	NR_MEM_PAGE_TYPE,
};

#endif
