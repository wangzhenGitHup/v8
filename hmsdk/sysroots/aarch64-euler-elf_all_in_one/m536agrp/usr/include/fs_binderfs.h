/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: State hongmeng binder ulib interface
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jan 13 19:07:54 2020
 */

#ifndef LIBHMSRV_FS_BINDERFS_H
#define LIBHMSRV_FS_BINDERFS_H

#ifdef CONFIG_FSLIB_HM_BINDER
#include <stdint.h>
#include <hongmeng/errno.h>
#include <hongmeng/types.h>

#define HM_FD_TYPE_SHIFT		16
#define HM_FD_TYPE_MASK			((1 << HM_FD_TYPE_SHIFT) - 1)
#define BINDERFS_SHM_NAME_LEN	64
struct fd;
int do_binderfs_ioctl(struct fd *f, unsigned int cmd, unsigned long arg);
int vfs_binderfs_ioctl(int fd, unsigned int cmd, unsigned long arg);
void *vfs_binderfs_mmap(size_t len, int32_t fd, int *ret_err);
#else
struct fd;
static inline int do_binderfs_ioctl(struct fd *f, unsigned int cmd, unsigned long arg)
{
	return E_HM_OK;
}
static inline int vfs_binderfs_ioctl(int fd, unsigned int cmd, unsigned long arg)
{
	return E_HM_OK;
}
static inline void *vfs_binderfs_mmap(size_t len, int32_t fd, int *ret_err)
{
	return NULL;
}
#endif
#endif
