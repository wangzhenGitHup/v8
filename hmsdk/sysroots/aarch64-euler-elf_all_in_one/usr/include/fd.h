/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Implementation of fd
 * Author: Huawei OS Kernel Lab
 * Create: Thu May 23 17:03:05 2019
 */

#ifndef LIBHMSRV_FS_FD_H
#define LIBHMSRV_FS_FD_H

#include <hongmeng/errno.h>
#include <libhmlog/hmlog.h>
#include <hongmeng/types.h>
#include <libhmsync/atomic.h>
#include <libhmsync/raw_scopedptr.h>
#include <fs_mutex.h>
#include <fs_server.h>
#include <vfs.h>

enum {
	NORMAL_FD,
	DEVICE_FD,
	FIFO_FD,
	EVENT_FD,
	EPOLL_FD,
	BINDER_FD,
	VPIPE_FD,
};

struct fd;

struct fd_operations {
	void (*destroy)(struct fd *f);
};

struct fd {
	struct hm_fd hm_fd;
	union {
		/* service info of fs server */
		struct server_info *server;
		/* used by exec */
		rref_t rref;
	};

	int file_type;
	/* file's index that contains in fs server */
	int remote_fd;

	/*
	 * used by VPIPE_FD, vpipe is implemented in uapps side and no server needed.
	 * private is link to vpipe structure.
	 * use padding to make private have certain length in compat condition.
	 */
	union {
		void *private;
		unsigned long long private_padding;
	};

	/* use padding to make ops have certain length in compat condition. */
	union {
		struct fd_operations *ops;
		unsigned long long ops_padding;
	};
};

#define calc_offset(ptr, base)	ptr_to_ulong((ptr) - (base))
struct fsinfo {
	uint32_t spawn_flag;
	uint32_t sinfos_count;
	uint32_t fd_count;
	int fdtable_size;
	unsigned long long cloexec_offset;
	unsigned long long sinfos_offset;
	unsigned long long fds_table_offset;
};

struct fsinfo_size {
	size_t fd_bitmap_size; 	   /* fd table bitmap size */
	size_t fd_table_size; 	   /* table of struct fd size */
	size_t netfd_struct_size;  /* sizeof struct net fd */
	size_t srv_info_size;	   /* table of fs server_info size */
	size_t cloexec_size;	   /* cloexec bitmap size */
	size_t sigmap_size;        /* for sigmap */
	size_t size;		   /* total size */
	unsigned int fsfd_num;
	unsigned int netfd_num;
};

struct fd *fd_get(int fd);
struct fd *fd_get_close(int fd);
void fd_put(struct fd *f);
int fd_new(int start, struct server_info *si, unsigned long flag,
	   struct fd **f_ret);
void fd_set_operations(struct fd *f, struct fd_operations *ops);
void fd_delete(struct fd *f);
#ifdef CONFIG_FSLIB_GFD_TABLE
void fd_delete_closed(struct fd *f);
#endif
void fd_set_server_info(struct fd *f, struct server_info *new);
int fd_dup2(const struct fd *oldf, int fd, unsigned int flags, struct fd **f_ret);

static inline void fd_set_file_type(struct fd *f, int file_type)
{
	BUG_ON(f == NULL);
	f->file_type = file_type;
}

static inline void fd_set_remote_fd(struct fd *f, int remote_fd)
{
	BUG_ON(f == NULL);
	f->remote_fd = remote_fd;
}

#endif	/* !LIBHMSRV_FS_FD_H */
