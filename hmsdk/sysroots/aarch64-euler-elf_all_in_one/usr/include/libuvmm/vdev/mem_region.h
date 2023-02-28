/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Sat Aug 3 15:38:47 2019
 */
#ifndef HM_UVMM_MEMREGION_H
#define HM_UVMM_MEMREGION_H

#include <lib/dlist.h>
#include <libhmsync/raw_scopedptr.h>

#include "hyptrace_stats.h"

typedef struct mem_region_ops {
	int (*read)(void *opaque, __u64 addr, __u32 size, unsigned long *data);
	int (*write)(void *opaque, __u64 addr, __u32 size, unsigned long data);
} mem_region_ops_t;

enum mem_region_type {
	REGION_TYPE_IO,
	REGION_TYPE_NORMAL,
	REGION_TYPE_INVAL,
};

typedef struct mem_region {
	__u64 addr;
	__u64 size;
	struct dlist_node node;
	struct raw_refcnt refcnt;
	enum mem_region_type type;
	void *private;

#ifdef CONFIG_HMUEV
	struct hyptrace_stats mmio_stats[MAX_VCPUS];
#endif
} mem_region_t;

typedef struct mem_map_node {
	__u64 addr;
	__u64 size;
	unsigned int num;
} mem_map_node_t;

struct mem_region_init_args {
	enum mem_region_type type;
	void *private;
	__u64 gpa;
	__u64 size;
};

const mem_map_node_t *mem_region_map_get(unsigned int dev_id);
int mem_region_init(mem_region_t *mr, struct mem_region_init_args *args,
		    release_func release_func);
mem_region_t *mem_region_search_get(__u64 start_addr, __u64 end_addr);
void mem_region_remove(mem_region_t *mr);

#ifdef CONFIG_HMUEV
void show_mmio_trace_stats(unsigned int num_vcpus);
void clear_mmio_trace_stats(void);
#endif

static inline int mem_region_get(mem_region_t *mr)
{
	return raw_refcnt_get(&mr->refcnt);
}

static inline void mem_region_put(mem_region_t *mr)
{
	(void)raw_refcnt_put(&mr->refcnt);
}

static inline mem_region_t *refcnt_to_region(const struct raw_refcnt *ref)
{
	return container_of(ref, mem_region_t, refcnt);
}

#endif
