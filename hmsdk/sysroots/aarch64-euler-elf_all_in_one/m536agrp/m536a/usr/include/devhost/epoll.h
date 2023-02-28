/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Prototypes for devhost epoll APIs
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jan 11 10:45:12 2019
 */
#ifndef __DEVHOST_API_EPOLL_H__
#define __DEVHOST_API_EPOLL_H__

/*
 * CAUSION: This file will be used in linux source,
 *          **DO NOT** include any HMOS headers.
 */

#include <devhost/device.h>

/* for epoll */
int devhost_epoll_clean_revents(struct device_info *devinfo,
				uint32_t revents,
				uint64_t key /* void *filp */);
int devhost_epoll_wakeup(struct device_info *devinfo,
			 uint32_t revents,
			 uint64_t key /* void *filp */);
void *devhost_epoll_setup(struct device_info *devinfo,
			  const struct devhost_pt_info *info,
			  unsigned int ctx_len,
			  void (*epoll_ctx_cleanup)(void *));
int devhost_epoll_set_recheck(uint32_t *revents);

#endif /* __DEVHOST_API_EPOLL_H__ */
