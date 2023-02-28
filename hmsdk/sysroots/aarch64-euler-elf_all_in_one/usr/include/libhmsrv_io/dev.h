/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: I/O service APIs of device fops
 * Author: Huawei OS Kernel Lab
 * Create: Fri Nov 22 13:58:38 2019
 */
#ifndef ULIBS_LIBHMSRV_IO_DEV_H
#define ULIBS_LIBHMSRV_IO_DEV_H

#include <stdlib.h>
#include <libhmsrv_io/type.h>

int hmsrv_io_dev_open(unsigned int devno, int vfs_mode, unsigned int vfs_flags,
		      unsigned int flags, struct hmsrv_io_ctx *ctx /* out */);

int hmsrv_io_dev_close(struct hmsrv_io_ctx *ctx);

int hmsrv_io_dev_read(const struct hmsrv_io_ctx *ctx,
		      unsigned long offset, void *buf, unsigned long size,
		      unsigned long *nread_out);

int hmsrv_io_dev_write(const struct hmsrv_io_ctx *ctx,
		       unsigned long offset,
		       const void *buf, unsigned long size,
		       unsigned long *nwrite_out);

int hmsrv_io_dev_llseek(const struct hmsrv_io_ctx *ctx,
			long long offset, int whence,
			long long *pos);

int hmsrv_io_dev_ioctl(const struct hmsrv_io_ctx *ctx,
		       int request, unsigned long arg, size_t size);

int hmsrv_io_dev_epoll_ctl(const struct hmsrv_io_ctx *ctx, __u32 app_cnode_idx,
			   int fd, int op, const void *reg_info);

int hmsrv_io_dev_epoll_close(const struct hmsrv_io_ctx *ctx,
			     __u32 app_cnode_idx, int fd);

int hmsrv_io_dev_epoll_et(const struct hmsrv_io_ctx *ctx, const void *pre_info,
			  uint32_t *revents);

int hmsrv_io_dev_epoll_reinit_add(const struct hmsrv_io_ctx *ctx,
				  __u32 app_cnode_idx, int fd,
				  const void *pre_reg_info,
				  const void *reg_info);

#endif	/* ULIBS_LIBHMSRV_IO_DEV_H */
