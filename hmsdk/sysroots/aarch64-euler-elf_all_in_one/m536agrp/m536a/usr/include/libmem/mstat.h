/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Memory status
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jan 02 11:19:25 2020
 */
#ifndef ULIBS_INCLUDE_LIBMEM_MSTAT_H
#define ULIBS_INCLUDE_LIBMEM_MSTAT_H

#include <libmem/buddy.h>
#include <libmem/memm_slab.h>
#include <libmem/page_type.h>

#define MEMSTAT_PAGE_TYPE_MAX_NUMBER	(uint32_t)NR_MEM_PAGE_TYPE

struct memstat_fs_stat_s {
	uint64_t free_cache;
	uint64_t used_cache;
	uint64_t lru_slab_size;
	uint64_t dirty_wb_size;
	uint64_t slabs_total;
	uint64_t pages_mmap;
	uint64_t mmap_private;
	uint64_t page_metadata;
	uint64_t mapping;
	uint64_t file;
	uint64_t dentry;
	uint64_t fat_node;
	uint64_t tmpfs_node;
	uint64_t ext2_node;
	uint64_t jffs2_node;
	uint64_t fs_hpage_2m;
	uint64_t fs_hpage_4m;
	uint64_t fs_hpage_1g;
};

struct memstat_hgtlb_all_s {
	uint64_t huge_pages_total_size;
	uint64_t huge_pages_free_size;
	uint64_t huge_pages_rsvd_size;
	uint64_t huge_pages_surp_size;
};

struct memstat_summary_stat_s {
	uint64_t total;
	uint64_t free;
	uint64_t cache;
	uint64_t total_elf;
	uint64_t shm_unused;
	uint64_t kobj_size;
	uint64_t cp_bitmap_size;
	struct memstat_fs_stat_s fs_stat;
	struct memstat_hgtlb_all_s hgtlb_stat;
};

struct memstat_high_zone_stat_s {
	uint64_t total;
	uint64_t free;
	uint64_t zero;
	uint64_t total_elf;
	uint64_t page_count_by_order[BUDDY_ORDER_CNT];
	uint64_t page_count_by_type[MEMSTAT_PAGE_TYPE_MAX_NUMBER];
};

struct memstat_normal_zone_stat_s {
	uint64_t total;
	uint64_t free;
	uint64_t zero;
	uint64_t total_elf;
	uint64_t page_count_by_order[BUDDY_ORDER_CNT];
	uint64_t page_count_by_type[MEMSTAT_PAGE_TYPE_MAX_NUMBER];
};

struct memstat_contig_zone_stat_s {
	uint64_t total;
	uint64_t free;
	uint64_t zero;
	uint64_t total_elf;
	uint64_t page_count_by_order[BUDDY_ORDER_CNT];
	uint64_t page_count_by_type[MEMSTAT_PAGE_TYPE_MAX_NUMBER];
};

struct memstat_copage_zone_stat_s {
	uint64_t total;
	uint64_t free;
	uint64_t cache;
	uint64_t total_elf;
	uint64_t page_count_by_order[BUDDY_ORDER_CNT];
	uint64_t page_count_by_type[MEMSTAT_PAGE_TYPE_MAX_NUMBER];
};

struct mem_summary_s {
	uint64_t total;
	uint64_t free;
	uint64_t cache;
	uint64_t total_elf;
};

struct memstat_all_proc_info {
	struct mem_size_info all_proc_mem;
	unsigned int all_process_cnt;
	unsigned int all_thread_cnt;
};

struct memstat_deviation {
	int64_t div_zone;
};

#endif
