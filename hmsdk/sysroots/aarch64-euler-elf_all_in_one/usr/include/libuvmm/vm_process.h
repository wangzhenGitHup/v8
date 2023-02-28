/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: headfile for vm_process
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jul 05 10:06:25 2021
 */

#ifndef HM_UVMM_UVMM_VM_PROCESS_H
#define HM_UVMM_UVMM_VM_PROCESS_H

#include <libalgo/rb_htable.h>
#include <libhmsync/raw_mutex.h>
#include <libhmsync/raw_scopedptr.h>
#include <libhmsync/waitqueue.h>
#include <libvpipe/vnotify.h>
#include <libuvmm/sec_ctx.h>
#include <libsysif/uvmm/server.h>

/*
 * Only process who created chn will create a vm_process_s. The struct process_s in
 * kernel is not certain to be associated with a vm_process_s.
 */
struct vm_process_s {
	/* cnode idx of process */
	__u32 cnode_idx;
	/* rbt root for chnds created by this process */
	struct rbt_tree tree;
	/* rbt node for vm_process_s in vm process pool */
	struct rbt_node node;
	struct raw_mutex mutex;
	struct raw_refcnt refcnt;
};

/*
 * channel descriptor, every attach operation will create a chnd.
 * chnd hold one refcnt of process_chn_s
 */
struct process_chnd_s {
	unsigned int chn_id;
	struct process_chn_s *chn;
	/* chnd will be insert to rbt in vm_process which attaches the channel */
	struct rbt_node node;
};

#define PROCESS_CHN_HOST_ATTACHED  0x1U
#define PROCESS_CHN_GUEST_ATTACHED 0x2U
#define PROCESS_CHN_SHARED         0x4U

/*
 * Only host detaches a channel actively,
 * this flag will be set.
 */
#define PROCESS_CHN_HOST_DETACHED  0x8
/*
 * Only guest detaches a channel actively,
 * this flag will be set.
 */
#define PROCESS_CHN_GUEST_DETACHED 0x10U
/*
 * After all host apps detach the channel
 * and tell kernel, this flag will be set.
 */
#define PROCESS_CHN_HOST_CLOSED    0x20U

/*
 * After guest detach the channel and tell
 * kernel, this flag will be set.
 */
#define PROCESS_CHN_GUEST_CLOSED   0x40U

#define PROCESS_CHN_PRESISTENT     0x80U

/* Every chn created will be associated with a process_chn_s */
struct process_chn_s {
	unsigned int chn_id;
	char *name;
	__u32 cnode_idx; /* owner cnode_idx of the chn */
	pid_t owner_pid; /* owner pid of the chn */
	struct sec_ctx_s sec_ctx;
	struct raw_refcnt_nr refcnt;
	unsigned int flags;
	struct raw_mutex mutex;
	struct wait_queue_head wait_list;
	/*
	 * vm chn pool nodes. chn with name is inserted to htable.
	 * chn without name will be insert to anonymous chn rbt.
	 */
	union {
		struct rbt_node node;
		struct rbt_hnode hash_node;
	};
	/* dlist node is inserted to name list */
	struct dlist_node name_entry;
};

static inline int vm_process_get(struct vm_process_s *process)
{
	return raw_refcnt_get(&process->refcnt);
}

static inline void vm_process_put(struct vm_process_s *process)
{
	BUG_ON(process == NULL);
	(void)raw_refcnt_put(&process->refcnt);
}

int process_chn_get(struct process_chn_s *chn);
void process_chn_put(struct process_chn_s *chn);

int register_process_event(bool fwd);
struct vm_process_s *vm_process_search_get(__u32 cnode_idx);
int vm_process_create_chn(__u32 cnode_idx, unsigned int chn_id, unsigned long long faddr);
int vm_process_attach_chn(struct vm_attach_chn_arg_s *args, __u32 cnode_idx);
int vm_process_delete_chn(__u32 cnode_idx, unsigned int chn_id,
			  bool sync, __u64 ts);
void vm_process_put(struct vm_process_s *process);
int vm_process_clean_chns(__u32 cnode_idx);
int vm_process_notify_chn(struct vm_process_s *process, unsigned int chn_id);
int vm_process_inject_chn(struct vm_process_s *process, unsigned int chn_id);
int vm_process_read_chn_status(struct vm_process_s *process, unsigned int chn_id, unsigned int *status);
#endif
