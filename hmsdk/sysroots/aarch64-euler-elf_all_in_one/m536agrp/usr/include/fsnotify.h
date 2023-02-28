/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Implementation of fsnotify
 * Author: Huawei OS Kernel Lab
 * Create: Fri Sep 10 09:26:43 2021
 */
#ifndef LIBHMSRV_FS_FSNOTIFY_H
#define LIBHMSRV_FS_FSNOTIFY_H
#include <unistd.h>
#include <stdint.h>
#include <lib/dlist.h>
#include <fs_mutex.h>

struct fsnotify_watches {
	unsigned int notify_mask;	   /* notify mask we care */
	struct dlist_node notify_watches; /* watches on this inode */
	unsigned short notify_watch_nr; /* notify_watches's number */
	struct fs_mutex notify_mutex; /* protects the watches list */
};

struct fsnotify_mark_pars {
	int fsnotify_fd;
	uint32_t mask;
	unsigned int flags;
	unsigned int obj_type;
	int wd;
	uint32_t token;
	unsigned int priority;
};
#endif
