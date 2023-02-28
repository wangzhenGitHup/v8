/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Procfs header file
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jul 20 15:23:30 2020
 */

#ifndef LIBHMSRV_FS_PROCFS_H
#define LIBHMSRV_FS_PROCFS_H

#include <libsysif/fs/api.h>

typedef struct {
	int tagid;
	uint64_t shm_key;
	unsigned long long mpool_size;
	uint64_t ctx;
}__attribute__((packed)) actvcall_procfs_read_args;

typedef struct {
	int tagid;
	uint64_t ctx;
	uint64_t pos;
	unsigned long long size;
}__attribute__((packed)) actvcall_procfs_write_args;

/* name: is name relative to procfs mountpoint, for example: "test/test",
 *       will create /proc/test/test.
 * type: could be dir/file/symlink
 * ops: for file, this is read/write handler, it is MUST. For other types, ignored.
 * linkdata: if type is symlink, this is MUST. For other types, it's ignored.
 */
int procfs_create_data(const char *name, unsigned int type,
		       const struct procfs_ops_cb *ops, const char *linkdata);
int procfs_delete_data(const char *name);

#endif
