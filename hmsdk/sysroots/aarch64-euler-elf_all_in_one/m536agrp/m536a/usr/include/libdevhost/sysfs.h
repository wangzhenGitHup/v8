/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Prototypes of sysfs
 * Author: Huawei OS Kernel Lab
 * Create: Fri Oct 9 09:45:52 2020
 */

#ifndef ULIBS_LIBDEVHOST_SYSFS_H
#define ULIBS_LIBDEVHOST_SYSFS_H

#include <sys/stat.h>
#include <libhmactv/actv.h>
#include <libdevhost/kernfs.h>

struct libdh_sysfs_args {
	void *ops;
	void *ctx;
	mode_t mode;
};

int libdh_sysfs_init(void);

int libdh_sysfs_create_dir(const char *name, unsigned int mode);

int libdh_sysfs_create_file(const char *name, struct libdh_kernfs_ops *fops,
			    const struct libdh_sysfs_args *create_args,
			    int *tag_out);

int libdh_sysfs_create_symlink(const char *name, mode_t mode,
			       const char *linkdata);

int libdh_sysfs_delete(const char *name);

int libdh_sysfs_notify(uintptr_t kernfs_node_ctx, const char *name);

int libdh_sysfs_read(unsigned int tagid, unsigned long long pos,
		     const struct hm_actv_buf *ubuf, uintptr_t ctx,
		     size_t *rsize);

int libdh_sysfs_write(unsigned int tagid, unsigned long long pos,
		      const struct hm_actv_buf *ubuf, uintptr_t ctx,
		      size_t *wsize);

int libdh_sysfs_poll(unsigned int tagid, uintptr_t ctx, bool pollable);

int libdh_sysfs_notify_insert(uintptr_t kernfs_node_ctx);

void libdh_sysfs_notify_remove(uintptr_t kernfs_node_ctx);

const struct libdh_sysfs_args *
libdh_sysfs_acquire_args(const struct kernfs_entry *_entry);
#endif /* ULIBS_LIBDEVHOST_SYSFS_H */
