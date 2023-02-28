/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Headerfile for radix_tree
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 03 22:21:06 2019
 */
#ifndef ULIBS_LIBALGO_RADIX_TREE_H
#define ULIBS_LIBALGO_RADIX_TREE_H

#include <stdbool.h>
#include <hongmeng/types.h>
#include <libhmlog/hmlog.h>
#include <libhmsync/raw_mutex.h>
#include <libhmsync/bitops/generic.h>

#define RADIX_TREE_SHIFT_SIZE 4U
#define RADIX_TREE_SLOTS_SIZE (1U << RADIX_TREE_SHIFT_SIZE)
#define RADIX_TREE_MASK (RADIX_TREE_SLOTS_SIZE - 1U)

#define RADIX_TREE_INIT {		\
	.rnode = NULL,			\
	.has_free = __true		\
}

#define __NR_TAGS	2U

struct radix_tree_root {
	struct radix_tree_node *rnode;
	bool has_free;
};

/*
 * struct radix_tree_node
 * @height: Height of the node.
 * @offset: Offset in parent slots array.
 * @count:  Count of child.
 * @parent: Parent node.
 * @bitmap: To describe the slot array.
 *	    If node is a leaf(height equals to 0), it indicates whether there
 *	    is an item, else it indicates whether the child node is full.
 * @tags:   Bitmaps of tags.
 * slots:   Slot to store child node or item.
 */
struct radix_tree_node {
	unsigned int height;
	unsigned int offset;
	unsigned int count;
	struct radix_tree_node *parent;
	DEFINE_RAW_BITMAP(bitmap, RADIX_TREE_SLOTS_SIZE);
	unsigned long long tags[__NR_TAGS][BITS_TO_LONGLONGS(RADIX_TREE_SLOTS_SIZE)];
	void *slots[RADIX_TREE_SLOTS_SIZE];
};

static inline void radix_tree_init(struct radix_tree_root *root)
{
	if (root != NULL) {
		root->rnode = NULL;
		root->has_free = __true;
	}
}

bool radix_tree_is_empty(const struct radix_tree_root *root);
int radix_tree_alloc_slot(struct radix_tree_root *root, unsigned long *startp, unsigned long end, void *item);
int radix_tree_insert_item(struct radix_tree_root *root, unsigned long index, void *item);
void *radix_tree_find_item(const struct radix_tree_root *root, unsigned long index);
void *radix_tree_delete_item(struct radix_tree_root *root, unsigned long index);
void radix_tree_destroy(struct radix_tree_root *root);
void *radix_tree_replace_item(struct radix_tree_root *root, void *item, unsigned long index);
int radix_tree_apply(struct radix_tree_root *root,
		     int (*callback)(unsigned long index, void *item, void *data),
		     void *data);
void *radix_tree_get_next(const struct radix_tree_root *root, unsigned long *index);
int radix_tree_find_items(const struct radix_tree_root *root,
			  unsigned long *start, int nr, void **items);

bool radix_tree_tagged(const struct radix_tree_root *root, unsigned int tag);
void *radix_tree_tag_set(const struct radix_tree_root *root,
			 unsigned long index, unsigned int tag);
void *radix_tree_tag_clear(const struct radix_tree_root *root,
			   unsigned long index, unsigned int tag);
int radix_tree_tag_test(const struct radix_tree_root *root,
			unsigned long index, unsigned int tag);
int radix_tree_find_tagged_items(const struct radix_tree_root *root,
				 unsigned long *start, unsigned int tag,
				 int nr, void **items);

#endif
