/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Header file for vm chn pool
 * Author: Huawei OS Kernel Lab
 * Create: Mon Aug 09 15:26:28 2021
 */
#ifndef HM_UVMM_UVMM_VM_CHN_POOL_H
#define HM_UVMM_UVMM_VM_CHN_POOL_H

#include <libuvmm/vm_process.h>

#define CHN_POOL_BUCKET_SIZE 256
#define CHN_POOL_ELEMENT_MAX 256

struct named_chns_info {
	unsigned int ch_id;
	char *name;
	pid_t owner_pid;
	bool owner_exit;
	unsigned int flags;
	unsigned int attached_count;
	struct dlist_node entry;
};

struct anonymous_chns_info {
	unsigned int ch_id;
	pid_t owner_pid;
	bool owner_exit;
	unsigned int flags;
	struct dlist_node entry;
};

struct vnotify_chns_info {
	unsigned int named_count;
	struct dlist_node named_chns;

	unsigned int annonymous_count;
	struct dlist_node anon_chns;
};

typedef void (*vm_chn_pool_op)(struct process_chn_s *chn, void *data);
int vm_chn_pool_init(void);
int vm_chn_pool_insert_name(struct process_chn_s *chn);
int vm_chn_pool_delete_name(struct process_chn_s *chn);
struct process_chn_s *vm_chn_pool_search_get_name(const char *name);
void vm_chn_pool_operate_name(const char *name, vm_chn_pool_op op, void *data);
void vm_chn_pool_operate_anonymous(unsigned chn_id, vm_chn_pool_op op, void *data);
int vm_chn_pool_insert_anonymous(struct process_chn_s *chn);
void vm_chn_pool_delete_anonymous(struct process_chn_s *chn);
struct vnotify_chns_info *vm_chn_pool_get_all_chns_info(void);
void free_vnotify_chns_info(struct vnotify_chns_info *chn_info);
#endif
