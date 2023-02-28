/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Shlist header file
 * Author: Huawei OS Kernel Lab
 * Create: Fri Oct 25 10:48:42 2019
 */
#ifndef ULIBS_LIBSHLIST_SHLIST_H
#define ULIBS_LIBSHLIST_SHLIST_H
// libc
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
// hongmeng
#include <lib/dlist.h>
#include <hongmeng/errno.h>
#include <libhmsync/raw_mutex.h>

/*
 * Check use-after-free:
 * The release operation only happen in delete, fini and close. And name
 * will be set to NULL after free, so the UAF will not happen. As for the
 * link, properly using dlist's interface prevents pointers in list from UAF.
 */
struct shl_shm_list {
	char			*name;
	uint32_t		shm_idx;
	uint32_t		size;
	uintptr_t		base;
	struct dlist_node	link;
};

/*
 * Check use-after-free:
 * The release operation only happen in delete, fini and insert's error.
 * And all pointer will be set to NULL after free, so the UAF will not happen.
 */
struct shl_list_node {
	struct shl_shm_list	*shm;
	uint32_t		offset;
	uint32_t		size;
	bool			free;
	struct dlist_node	list_link;
	struct dlist_node	free_link;
};

struct shl_config {
	char	*shm_prefix;
	size_t	shm_size;
};

struct shl_ctrl {
	struct dlist_node	list;
	struct dlist_node	free_list;
	struct raw_mutex	list_lock;
	uint32_t		shm_size;
};

struct shlist {
	struct shl_ctrl		*ctrl;
	char			*shm_prefix;
	struct dlist_node	shm_list;
	struct raw_mutex	shm_list_lock;
	uint32_t		shm_count;
};

int shl_init(struct shlist *shl, const struct shl_config *cfg, bool ctrl);
void shl_fini(struct shlist *shl);
struct shl_list_node *shl_alloc(struct shlist *shl, size_t size);
void shl_free(struct shlist *shl, struct shl_list_node *node);
uint32_t shl_shm_size_of(struct shlist *shl, uint32_t shm_idx);
uintptr_t shl_shm_base_of(struct shlist *shl, uint32_t shm_idx);
static inline uintptr_t shl_shm_addr_of(const struct shl_list_node *node)
{
	return (uintptr_t)(node->shm->base + node->offset);
}

#endif /* ifndef ULIBS_LIBSHLIST_SHLIST_H */
