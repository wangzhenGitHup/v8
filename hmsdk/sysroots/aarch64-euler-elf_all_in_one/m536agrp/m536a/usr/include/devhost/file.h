/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Prototypes for file table management
 * Author: Huawei OS Kernel Lab
 * Create: Thu May 23 14:17:03 2019
 */

#ifndef __DEVHOST_API_FILE_H__
#define __DEVHOST_API_FILE_H__

#include <lib/utils.h>
#include <devhost/device.h>
#include <hmkernel/capability.h>
#include <libhmsync/raw_mutex.h>
#include <librb/shm_ring_buffer.h>
#include <libhmsync/raw_scopedptr.h>

struct block_ctx {
	uint64_t rref_notify;
	uint64_t service_id;
	unsigned int method;
	struct sring_buf *end_srbuf;
};

struct filp_node {
	__u32 cnode_idx;
	struct raw_refcnt refcnt;
	struct device_info *devinfo;
	void *filp;
	struct raw_mutex ctx_lock;
	union {
		void *private_ctx;
		struct block_ctx *blk_ctx; /* `devinfo->vfs_mode & MODE_BLK` */
	};
};

static inline struct filp_node *refcnt_to_filp_node(struct raw_refcnt *refcnt)
{
	return container_of(refcnt, struct filp_node, refcnt);
}

static inline void devhost_put_file(struct filp_node *node)
{
	if (node == NULL) {
		return;
	}
	(void)raw_refcnt_put(&node->refcnt);
}

static inline int devhost_get_file(struct filp_node *node)
{
	if (node == NULL) {
		return E_HM_INVAL;
	}
	return raw_refcnt_get(&node->refcnt);
}

int devhost_register_file(struct filp_node *node, unsigned int *file_id);
int devhost_unregister_file(uint64_t cnode_idx, unsigned int file_id);
struct filp_node *devhost_alloc_filp_node(struct device_info *devinfo,
					  __u32 cnode_idx);

/* The function is called by 'acquire_devhost_filp_node'.
 * The function name is defined according to a certain rules which
 * can be known in 'acquire_scopedptr'.
*/
struct filp_node *acquire_filp_node_ptr_ref(__u32 cnode_idx,
					    unsigned int file_id);
declare_scopedptr_type(filp_node)
define_scopedptr_release(filp_node, NULL)
#define acquire_devhost_filp_node(node, cnode_idx, file_id) \
	acquire_scopedptr(filp_node, node, \
			  offset_of(struct filp_node, refcnt), \
			  cnode_idx, file_id)

#endif /* __DEVHOST_API_FILE_H__ */
