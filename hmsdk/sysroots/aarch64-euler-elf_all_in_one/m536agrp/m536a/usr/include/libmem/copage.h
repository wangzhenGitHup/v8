/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Copage function declaration
 * Author: Huawei OS Kernel Lab
 * Create: Fri Nov 29 17:46:01 2019
 */
#ifndef ULIBS_INCLUDE_LIBMEM_COPAGE_H
#define ULIBS_INCLUDE_LIBMEM_COPAGE_H

#include <stdint.h>

struct copage_stat_info {
	uint64_t vaddr_start;
	uint64_t ga_mapping;
	uint64_t lu_used_pages;
};

int copage_init(void);
void *copage_alloc(uint32_t nr_pages);
int copage_free(const void *vaddr, uint32_t nr_pages);
int copage_populate(const void *vaddr, uint32_t nr_pages);
int copage_stat(uint32_t cnode_idx, struct copage_stat_info *info);

#endif
