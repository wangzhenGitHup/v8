/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: vpipe header file
 * Author: Huawei OS Kernel Lab
 * Create: Sat May 08 15:10:22 2021
 */

#ifndef LIBVNOTIFY_VPIPE_H
#define LIBVNOTIFY_VPIPE_H

#include <fd.h>
#include <vfs_epoll.h>
#include <hongmeng/errno.h>
#include <libvpipe/vnotify.h>

int hm_vpipe_create(void);
int hm_vpipe_destroy(int vpfd);

int hm_vpipe_notify(int vpfd);
int hm_vpipe_receive(int vpfd, const struct timespec *ts,
		     unsigned int flags);
int hm_vpipe_inject_event(int vpfd);
int hm_vpipe_chnid_of(int vpfd);
void hm_vpipe_free(struct fd *fds);
int hm_vpipe_attach_chn(const char *name, unsigned int flags);
int hm_vpipe_detach_chn(int vpfd);

/* epoll callbacks */
int epoll_vpipe(const struct epitem *_epitem,
		const struct eventpoll *eventpoll,
		int op);
int epoll_et_revents_vpipe(const struct epitem *epitem);

#endif
