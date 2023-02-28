/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Libdh prototypes for kernfs support
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jul 21 19:42:39 2020
 */

#ifndef ULIBS_LIBDEVHOST_KERNFS_H
#define ULIBS_LIBDEVHOST_KERNFS_H

#include <stdint.h>
#include <stdlib.h>

#define TAG_MASK		0x00FFFFFFU
#define REMOTE_TAG_MASK		0x80000000U
#define LIBDH_KERNFS_TAG_MIN	1
#define LIBDH_KERNFS_TAG_MAX	((int)(TAG_MASK))

#define tag_of(tagid)		\
	(((unsigned int)(tagid)) & TAG_MASK)

static inline int mk_remote_tag(unsigned int tagid)
{
	unsigned int result = tagid | REMOTE_TAG_MASK;
	return (int)result;
}

#define is_remote_tag(tagid)	\
	((((unsigned int)(tagid)) & REMOTE_TAG_MASK) == REMOTE_TAG_MASK)

struct kernfs_entry;

struct libdh_kernfs_rw_args {
	unsigned long long pos;
	unsigned long ubuf;
	unsigned long size;
};

struct libdh_kernfs_ops {
	/* CAUSION: this ops should return POSIX errno */
	int (*read)(const struct kernfs_entry *entry,
		    const struct libdh_kernfs_rw_args *args,
		    unsigned long *rsize);
	int (*write)(const struct kernfs_entry *entry,
		     const struct libdh_kernfs_rw_args *args,
		     unsigned long *wsize);
	int (*poll)(const struct kernfs_entry *entry,
		    bool pollable);
};

#endif	/* ULIBS_LIBDEVHOST_KERNFS_H */
