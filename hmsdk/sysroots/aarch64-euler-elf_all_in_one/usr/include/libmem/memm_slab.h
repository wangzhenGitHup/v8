/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Memm slab function declaration
 * Author: Huawei OS Kernel Lab
 * Create: Sun May 26 22:33:34 2019
 */
#ifndef ULIBS_INCLUDE_LIBMEM_MEMM_SLAB_H
#define ULIBS_INCLUDE_LIBMEM_MEMM_SLAB_H

#include <stddef.h>
#include <stdint.h>
#include <libmem/types.h>
#include <libstrict/strict.h>

#define SLAB_PAGE_SIZE	((unsigned int)1 << PAGE_SHIFT)

/*  SLAB_PAGE is 2 PAGE_SIZE */
#define MEMM_SLAB_LOWER_MARK	(0U * SLAB_PAGE_SIZE)
/* extend number of SLAB PAGE */
#define MEMM_SLAB_EXTEND_MARK	(8U * SLAB_PAGE_SIZE)
/* shrink number of SLAB PAGE */
#define MEMM_SLAB_SHRINK_MARK	(16U * SLAB_PAGE_SIZE)

/* first two PAGE_SIZE will be in_used to initial
 * g_sized_slab_ator and g_size_to_ator_table
 */
#define MEMM_SLAB_META_DATA ((unsigned int)2 << PAGE_SHIFT)

/*
 * number of max supported slab allocator index
 * the index of number is used to g_size_to_ator_table
 */
#define MEMM_ROOT_SLAB_ATOR_NUM 27U

/* NOTE: This is the used for sysdump */
#define MEMM_SLAB_ALL_ATOR_INFO_NUM	MEMM_ROOT_SLAB_ATOR_NUM

struct memm_slab_ator_info {
	int in_use; /* if in_use is 0 which means this allocator is not used */
	uint32_t slab_page_size;
	uint32_t obj_size;
	uint32_t max_slot_count;
	unsigned int slab_page_hold;
	uint32_t slot_used;
	uint32_t slot_free;
	unsigned int empty_num;
	unsigned int partial_num;
	unsigned int full_num;
};

struct memm_slab_slot_info {
	size_t all_slot_size;
	size_t free_slot_size;
	size_t used_slot_size;
};

struct memm_slab_info {
	size_t total_slab_size;
	size_t free_slab_size;
	size_t grown_slab_size;
	size_t real_total_slab_size;
	struct memm_slab_slot_info slot_info;
	struct memm_slab_ator_info sized_ator_info[MEMM_SLAB_ALL_ATOR_INFO_NUM];
};

void memm_slab_init(uintptr_t start, size_t size);
#ifdef CONFIG_SLAB_FREELIST_RANDOM
void memm_slab_update_random(unsigned long random_value);
#else
static inline void memm_slab_update_random(unsigned long random_value)
{
	UNUSED(random_value);
}
#endif
void *memm_slab_alloc(size_t size);
void memm_slab_free(const void *obj);

size_t memm_slab_max_malloc(void);

size_t memm_slab_alloc_usable_size(const void *obj);
size_t memm_slab_remain_size(void);
size_t memm_slab_remain_size_nolock(void);
size_t memm_slab_grown_size(void);

int memm_slab_extend(uintptr_t start, size_t size);
uintptr_t memm_slab_shrink(void);

void memm_slab_dump(struct memm_slab_info *info);
void memm_slab_dump_nolock(struct memm_slab_info *info);

#endif	/* ULIBS_INCLUDE_LIBMEM_MEMM_SLAB_H */
