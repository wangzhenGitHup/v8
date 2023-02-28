/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Register pre and post fork hook
 * Author: Huawei OS Kernel Lab
 * Create: Wed Apr 08 20:17:42 2020
 */

#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_ATFORK_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_ATFORK_H

#include <unistd.h>
#include <lib/dlist.h>

struct hm_atfork_hook {
	void (*prepare)(void);
	void (*parent)(void);
	void (*child)(void);
	struct dlist_node node;
};

void pre_fork_handler(void);
void post_fork_handler(pid_t pid);
void hm_atfork(struct hm_atfork_hook *hook);

#endif
