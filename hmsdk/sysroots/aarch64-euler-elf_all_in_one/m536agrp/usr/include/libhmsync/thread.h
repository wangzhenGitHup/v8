/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Basic interfaces of all thread models
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jan 24 12:37:33 2019 -0400
 */

#ifndef ULIB_INCLUDE_LIBHMSYNC_THREAD_H
#define ULIB_INCLUDE_LIBHMSYNC_THREAD_H

#include <unistd.h>
#include <stdbool.h>
#include <hmkernel/errno.h>
#include <hongmeng/syscall.h>
#include <hmkernel/rq.h>
#include <libhwsecurec/securec.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int
thread_set_sched_priority(cref_t cref, unsigned int prio);
extern int
thread_user_priority(cref_t cref);

struct hm_clone_req;
void thread_setup_config(struct hm_clone_req *req, const void *stack_vaddr,
			 const void *tls_vaddr, const void *entry,
			 const void *args, unsigned int clone_flags,
			 const void *ptid, const void *ctid,
			 unsigned int hm_flags);

int thread_get_current_tid(void);
cref_t thread_tid2cref(int tid);
cref_t thread_module_sched_ref(void);

#ifdef __cplusplus
}
#endif

#endif
