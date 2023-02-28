/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Sysfs libs header file
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jul 20 15:25:09 2020
 */

#ifndef LIBHMSRV_FS_SYSFS_H
#define LIBHMSRV_FS_SYSFS_H

#include <libsysif/fs/api.h>

struct sysfs_method_info {
	unsigned int read_method_id;
	unsigned int write_method_id;
};

typedef struct {
	 /* ctx: private data */
	int (*read)(void *ctx, void *dst, size_t pos, size_t size, size_t *rsize);
	int (*write)(void *ctx, void *src, size_t pos, size_t size, size_t *wsize);
} sysfs_file_ops;

typedef struct {
	int tagid;
	uint64_t shm_key;
	unsigned long long mpool_size;
	uint64_t ctx;
}__attribute__((packed)) actvcall_sysfs_read_args;

typedef struct {
	int tagid;
	uint64_t ctx;
	uint64_t pos;
	unsigned long long size;
}__attribute__((packed)) actvcall_sysfs_write_args;

typedef struct {
	int tagid;
	bool pollable;
	uint64_t ctx;
}__attribute__((packed)) actvcall_sysfs_poll_args;

/*
 * General APIs.
 *
 * name: path name relative to sysfs mount point, for example: "test/test",
 *       will create /sys/test/test.
 */
int sysfs_create_dir(const char *name, mode_t mode);
int sysfs_create_file(const char *name, mode_t mode, const struct sysfs_ops_cb *ops);
int sysfs_create_symlink(const char *name, mode_t mode, const char *linkdata);
int sysfs_delete(const char *name, int *tagid);
int sysfs_notify(const char *name, size_t name_size);

struct sysfs_svp_info {
	const char *svpname;
	unsigned int read_method_id;
	unsigned int write_method_id;
};

/*
 * Helper APIs.
 *
 * Helper functions for easier usage when create/read/write/delete sysfs files.
 * They will help to manage ops,ctx -> tagid convesion and read/write auto dispatch.
 */
int sysfs_create_file_helper(const char *name, mode_t mode, sysfs_file_ops *fops, void *ctx,
			     const struct sysfs_svp_info *svp_info);
int sysfs_read_dispatch(const actvcall_sysfs_read_args *read_args);
int sysfs_write_dispatch(const actvcall_sysfs_write_args *write_args,  size_t len);
int sysfs_delete_helper(const char *name);

#endif
