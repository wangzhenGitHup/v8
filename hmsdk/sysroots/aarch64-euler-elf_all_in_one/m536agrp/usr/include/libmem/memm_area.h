/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Memm area management
 * Author: Huawei OS Kernel Lab
 * Create: Tue Apr 28 21:48:34 2020
 */
#ifndef ULIBS_INCLUDE_LIBMEM_MEMM_AREA_H
#define ULIBS_INCLUDE_LIBMEM_MEMM_AREA_H

#include <stdint.h>
#include <stdbool.h>

void *memm_area_init(uint32_t nr_slots, uint32_t slot_sz);
void *memm_area_alloc_slot(const void *area_vaddr);
void memm_area_free_slot_ex(const void *area_vaddr,
			    const void *slot_vaddr,
			    bool has_populated);
static inline void
memm_area_free_slot(const void *area_vaddr, const void *slot_addr)
{
	memm_area_free_slot_ex(area_vaddr, slot_addr, true);
}

#endif
