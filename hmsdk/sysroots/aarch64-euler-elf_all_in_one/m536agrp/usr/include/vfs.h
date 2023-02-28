/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Implementation of vfs
 * Author: Huawei OS Kernel Lab
 * Create: Sun Jan 13 14:26:43 2019
 */
#ifndef LIBHMSRV_FS_VFS_H
#define LIBHMSRV_FS_VFS_H

#include <unistd.h>
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#include <fcntl.h>
#include <time.h>
#include <limits.h>
#undef _GNU_SOURCE
#else
#include <fcntl.h>
#include <time.h>
#include <limits.h>
#endif

#include <kconfig_fslibs.h>

#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <lib/utils.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <sys/epoll.h>
#include <fs_mutex.h>
#include <libsysif/fs/api.h>
#include <asm/page.h>
#include <fs_server.h>
#include <fsnotify.h>
#include <hongmeng/types.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/statfs.h>

#include <libhwsecurec/securec.h>
#include <libhmucap/ucap.h>
#include <libhmsync/atomic.h>
#include <libhmsync/bitops/generic.h>
#include <libhmsync/raw_scopedptr.h>

#include <libhmsrv_io/type.h>
#include <libhmsrv_sys/hm_select_common.h>

#define FS_NAME_MAXLEN		16
#define MAX_MNTOPTS_LEN		256
#define MAX_FQSN_LEN		128
#define XATTR_NAME_MAX		255
#define XATTR_SIZE_MAX		65536

#define MAX_LINK_COUNT		40

#define POLL_CALL_NUM_WAKEUP (1)

#define SERVER_ROOTFD		(-4096)
#define AT_FDROOT		(-300)

#define FSMGR_PATH_ACTV "fsmgr-actv"

/* vfs_tee have been implemented function point */
#define TEE_F_ALL		(O_NONBLOCK)
#define WALK_NONBLOCK   (O_NONBLOCK)

#define TTY_ENABLE_NONBLOCK	0x1001
#define TTY_DISABLE_NONBLOCK	0x1002

#define TYPE_CWD		0x1
#define TYPE_ROOT		0x2
#define TYPE_EXE		0x3

#define VFS_MIN_REGFILE_NUM	0
#define VFS_STDFILES_NUM	3
#define LDSO_MAX_FD_SUPPORTED	8
#define VFS_MAX_OPEN_FILES	CONFIG_FSLIB_DEFAULT_OPEN_FILES
#define VFS_FDTABLESIZE		CONFIG_FSLIB_DEFAULT_OPEN_FILES
#define VFS_NOFILE_MAX		CONFIG_FSLIB_MAX_OPEN_FILES
#define VFS_MMAP_FID_MIN_NUM	1
#define MAX_SHM_NAME_LEN	64

#define CNODE_IDX_SHIFT 32
#define DATA_XFER_LIMIT		4096u
#define DATA_XFER_SHM_LIMIT	(256 * 1024)

#define MISC_MAJOR	0x0A
#define ASHMFD_MINOR	0x3D

typedef enum {
	KIND_FILE,
	KIND_DIRECTORY,
	KIND_SYMLINK,
} vfs_file_kind_t;

typedef enum {
	MODE_REG = 1,
	MODE_CHR = 2,
	MODE_BLK = 4,
	MODE_FIFO = 8,
} vfs_mode_t;

#define S_IRWXUGO	(S_IRWXU | S_IRWXG | S_IRWXO)
#define S_IALLUGO	(S_ISUID | S_ISGID | S_ISVTX | S_IRWXUGO)
#define S_IRUGO		(S_IRUSR | S_IRGRP | S_IROTH)
#define S_IXUGO		(S_IXUSR | S_IXGRP | S_IXOTH)
#define S_IWUGO		(S_IWUSR | S_IWGRP | S_IWOTH)

typedef struct {
	unsigned int mpool_pages_total;
	unsigned int mpool_pages_free;
	unsigned int mpool_pages_used;
	unsigned int mpool_pages_reclaimed;
	unsigned int cpool_pages_total;
	unsigned int cpool_pages_free;
	unsigned int cpool_pages_used;
	unsigned int cpool_pages_reclaimed;
	unsigned int lru_pages;
	unsigned int lru_slab_size;
	unsigned int pages_dirty_wb;
	unsigned int pages_slabs;
	unsigned int pages_mmap_private;
	unsigned int pages_mmap_cached;
	unsigned int pages_page_metadata;
	unsigned int pages_mapping;
	unsigned int pages_file;
	unsigned int pages_dentry;
	unsigned int pages_vnode;
	unsigned int pages_tmpfs_node;
	unsigned int pages_ext2_node;
	unsigned int pages_ext4_node;
	unsigned int pages_fat_node;
	unsigned int pages_jffs2_node;
	unsigned int pages_overlayfs_node;
	unsigned int pages_transfs_node;
	unsigned int pages_ubifs_node;
	unsigned int pages_procfs_node;
	unsigned int pages_kernfs_node;
	uint64_t huge_page_2m;
	uint64_t huge_page_4m;
	uint64_t huge_page_1g;
	uint64_t pages_mmap;
} vfs_fscache_stat_t;

typedef struct {
	unsigned pages_total;
	unsigned pages_reclaimed;
	unsigned pages_free;
	unsigned pages_used;
} vfs_stat_pool_t;

typedef struct {
	size_t page_metadata_size;
	unsigned pages_free;
	unsigned pages_dirty_wb;
	uint64_t huge_page_2m;
	uint64_t huge_page_4m;
	uint64_t huge_page_1g;
	raw_atomic_long_t pages_mmap;
} vfs_stat_fscache_t;

typedef struct {
	raw_atomic_long_t pages_used_total;
	raw_atomic_long_t mmap_private_total;
	unsigned int mmap_cached_len; /* length of the unallocated memory */
	unsigned int pages_page_metadata;
	unsigned int pages_mapping;
	unsigned int pages_file;
	unsigned int pages_dentry;
	unsigned int pages_vnode;
	unsigned int pages_tmpfs_node;
	unsigned int pages_ext4_node;
	unsigned int pages_ext2_node;
	unsigned int pages_fat_node;
	unsigned int pages_jffs2_node;
	unsigned int pages_overlayfs_node;
	unsigned int pages_transfs_node;
	unsigned int pages_ubifs_node;
	unsigned int pages_procfs_node;
	unsigned int pages_kernfs_node;
} vfs_stat_slab_t;

typedef struct {
	vfs_stat_pool_t mpools;
	vfs_stat_pool_t cpools;
	vfs_stat_fscache_t fscache;
	vfs_stat_slab_t slab;
} vfs_stat_common_t;

struct fs_opts {
	char opts[MAX_MNTOPTS_LEN];
	char fs_name[FS_NAME_MAXLEN];
	char fqsn[MAX_FQSN_LEN];
	char mp_path[PATH_MAX];
	int orig_me_idx;
	int orig_fd;
};

typedef struct {
	bool rw;
	size_t n_byte;
	char name[MAX_SHM_NAME_LEN];
} fs_shm_info;

struct fs_buf_info {
	char *buf;
	size_t len;
};

int vfs_rename(const char *oldname, const char *newname);
int vfs_renameat(int olddfd, const char *oldname,
		 int newdfd, const char *newname);
int vfs_link(const char *old_path, const char *new_path);
int vfs_linkat(int old_fd, const char *old_path,
	       int new_fd, const char *new_path, int flag);
int vfs_symlink(const char *target, const char *linkpath);
int vfs_symlinkat(const char *target, int dfd, const char *linkpath);
int vfs_ftruncate(int fd, uint64_t length);
int vfs_truncate(const char *path, uint64_t length);
int vfs_unlink(const char *filename);
int vfs_unlinkat(int dfd, const char *filename, int flag);
int vfs_rmdir(const char *dirname);
int vfs_mount(const char *src, const char *tgt, const char *fstype,
	      unsigned long flag, const char *opts);
int vfs_umount2(const char *mp, int flags);

int vfs_mknod(const char *name, mode_t mode, dev_t devno);
int vfs_mknodat(int dfd, const char *name, mode_t mode, dev_t devno);
int vfs_lseek(int fd, int64_t offset, int whence, int64_t *pos);
int vfs_trans(int fd, const char *buf, int pos, size_t nbyte);

int vfs_quotactl(unsigned int cmd, const char *special,
		 unsigned int id, char *buffer);

#define MPOOL_SUMVEC_PER_PAGE		(PAGE_SIZE / sizeof(vfs_mmap_mpool_sumvec_t))
#define FILL_NODE_SUMVEC_PER_PAGE	(PAGE_SIZE / sizeof(vfs_mmap_fill_node_sumvec_t))
#define CHANGE_NODE_SUMVEC_PER_PAGE	(PAGE_SIZE / sizeof(vfs_mmap_change_node_sumvec_t))

enum mmap_flag_bits {
	__MMAP_FL_PAGE_MAPPED,
	__MMAP_FL_PAGE_UNMAPPED,
	__MMAP_FL_PAGE_DIRTIED,
	__MMAP_FL_PAGE_CLEANED,
	__MMAP_FL_PAGE_ASYNCED,
	__MMAP_FL_PAGE_SYNCED,
	__MMAP_FL_PAGE_INVALIDATED,
	__MMAP_FL_PAGE_MLOCK,
	__MMAP_FL_PAGE_MUNLOCK,
	__NR_MMAP_FLAGS,
};

#define MMAP_FL_NONE 0
#define MMAP_FL_PAGE_MAPPED (1U << (uint32_t)__MMAP_FL_PAGE_MAPPED)
#define MMAP_FL_PAGE_UNMAPPED (1U << (uint32_t)__MMAP_FL_PAGE_UNMAPPED)
#define MMAP_FL_PAGE_DIRTIED (1U << (uint32_t)__MMAP_FL_PAGE_DIRTIED)
#define MMAP_FL_PAGE_CLEANED (1U << (uint32_t)__MMAP_FL_PAGE_CLEANED)
#define MMAP_FL_PAGE_ASYNCED (1U << (uint32_t)__MMAP_FL_PAGE_ASYNCED)
#define MMAP_FL_PAGE_SYNCED (1U << (uint32_t)__MMAP_FL_PAGE_SYNCED)
#define MMAP_FL_PAGE_INVALIDATED (1U << (uint32_t)__MMAP_FL_PAGE_INVALIDATED)
#define MMAP_FL_PAGE_MLOCK (1U << (uint32_t)__MMAP_FL_PAGE_MLOCK)
#define MMAP_FL_PAGE_MUNLOCK (1U << (uint32_t)__MMAP_FL_PAGE_MUNLOCK)

typedef struct {
	uint32_t index;
	uint64_t dev_id;
} vfs_mmap_node_t;

typedef struct {
	int32_t mpool_id;
	uint64_t mpool_page_idx;
	uint32_t nr_pages;
} __attribute__((packed)) vfs_mmap_mpool_sumvec_t;

typedef struct {
	vfs_mmap_mpool_sumvec_t vec[MPOOL_SUMVEC_PER_PAGE];
} __attribute__((packed)) vfs_mmap_mpool_summary_t;

typedef struct {
	uint64_t node_page_idx;
	uint32_t nr_pages;
} __attribute__((packed)) vfs_mmap_fill_node_sumvec_t;

typedef struct {
	uint64_t node_page_idx;
	uint32_t nr_pages;
	uint32_t flag;
} __attribute__((packed)) vfs_mmap_change_node_sumvec_t;

typedef struct {
	vfs_mmap_fill_node_sumvec_t vec[FILL_NODE_SUMVEC_PER_PAGE];
} __attribute__((packed)) vfs_mmap_fill_node_summary_t;

typedef struct {
	vfs_mmap_change_node_sumvec_t vec[CHANGE_NODE_SUMVEC_PER_PAGE];
} __attribute__((packed)) vfs_mmap_change_node_summary_t;

extern ssize_t vfs_splice(int fd_in, int64_t *offset_in, int fd_out,
			  int64_t *offset_out, size_t len, unsigned int flags);
extern int vfs_pipe2(int *fd, int flags);
extern int vfs_tee(int fd_in, int fd_out, size_t len,
		   unsigned int flags, ssize_t *nduped);
extern void vfs_init_stdio(void);
extern int vfs_setrlimit(__u32 cnode_idx, unsigned int type, rlim_t rlim_cur, rlim_t rlim_max);
extern int vfs_set_label(int fd, uint64_t label);
extern int vfs_get_label(int fd, uint64_t *label);
int vfs_set_label_by_path(const char *path, int flag, uint64_t label);

#ifdef CONFIG_FSLIB_AUDIT
typedef void (*audit_wp_start_hook_func_t)(void);
typedef void (*audit_wp_end_hook_func_t)(bool is_exec, const char *path, const char *srv_name);
struct audit_watch_field;

int vfs_audit_init(void);
int vfs_add_audit_rule(const char *path, uint16_t rule_id, uint16_t rule_num, uint32_t flags);
int vfs_del_audit_rule(const char *path, uint64_t rule_id, uint32_t flags);
int vfs_match_audit_watch_file(uint64_t rule_id, const struct audit_watch_field *field);
int vfs_match_audit_watch_dir(uint64_t rule_id, int me_idx, const struct audit_watch_field *field);
void vfs_set_audit_wp_hook(audit_wp_start_hook_func_t start, audit_wp_end_hook_func_t end);
void vfs_audit_watch_point_start(void);
void vfs_audit_watch_point_end(bool is_exec, const char *path, const char *srv_name);
#else
#define vfs_set_audit_wp_hook(start, end)
#define vfs_audit_watch_point_start()
#define vfs_audit_watch_point_end(is_exec, path, srv_name)
#endif

extern int vfs_inotify_init1(unsigned int flags);
extern int vfs_inotify_add_watch(int fd, const char *pathname, uint32_t mask);
extern int vfs_inotify_rm_watch(int fd, int wd);

int vfs_fanotify_init(unsigned int flags);
int vfs_fanotify_mark(int fanotify_fd, unsigned int flags,
		      uint64_t mask, int dirfd, const char *pathname);

#define FD_FS  0
#define FD_NET 1

#define HMFD_STATE_NEW   0
#define HMFD_STATE_OPEN  1
#define HMFD_STATE_CLOSE 2

#define USE_SYSMGR_CNODE_IDX 1U
#define USE_CHILD_CNODE_IDX  2U
#define USE_PARENT_CNODE_IDX 4U

struct hm_fd {
	int fd_type;
	int fd;
	int state;
	struct raw_refcnt_nr refcnt;
};

struct splice_libinfo {
	int fd_in;
	int64_t *offset_in;
	int fd_out;
	int64_t *offset_out;
	size_t len;
	unsigned int flags;
	ssize_t spliced_bytes;
};

int vfs_cleanup_server_info(void);
int vfs_fscache_local_stat(vfs_stat_common_t *stat,
			   vfs_fscache_stat_t *fscache_stat);
int vfs_fchmod(int fd, mode_t mode);
int vfs_chmod(const char *pathname, mode_t mode);
int vfs_fchmodat(int dfd, const char *pathname, mode_t mode);

ssize_t vfs_copy_file_range(int fd_in, int64_t *off_in, int fd_out,
			    int64_t *off_out, size_t len, unsigned int flags);
int vfs_drop_caches(unsigned int mode, int max, int reason);
int vfs_fadvise(int fd, int64_t offset, int64_t len, int advise);
int vfs_readahead(int fd, int64_t offset, size_t count);
int vfs_fd_get_path(int fd, __u32 cnode_idx, char *path_buf, unsigned int path_len);
int vfs_sysmgr_get_fd_path(int fd, __u32 cnode_idx, char *path_buf);
int vfs_is_normal_fd(int fd, bool *is_normal_fd);

/* src/proc.c */
int vfs_chroot(const char *pathname);
int vfs_getcwd(char *buf, size_t size);
int vfs_chdir(const char *path);
int vfs_fchdir(int fd);
int vfs_revoke_process(rref_t rref, uint32_t cnode_idx);
int vfs_setrlimit(uint32_t cnode_idx, unsigned int type,
		  rlim_t rlim_cur, rlim_t rlim_max);

struct vfs_mmap_create_info {
	int32_t fd;
	int64_t offset;
	uint64_t len;
	uint32_t cnode_idx;
	uint32_t prot;
	uint32_t flags;
};

/* src/mmap.c */
int vfs_mmap_query(int fd, __u32 cnode_idx, char *service,
		   uint32_t len, unsigned int *file_type);
int vfs_mmap_create(rref_t rref, const struct vfs_mmap_create_info *info,
		    vfs_mmap_node_t *node, int *fid,
		    unsigned int *pagesize);
int vfs_mmap_release_file(rref_t rref, int fid, __u32 cnode_idx);
int vfs_mmap_change(rref_t rref, int fid, __u32 cnode_idx,
		    int64_t offset, uint64_t len, uint32_t prot);
int vfs_mmap_fill_page(rref_t rref, int fid, __u32 cnode_idx,
		       uint64_t node_page_idx, uint64_t flags,
		       uintptr_t *vaddr);
int vfs_mmap_fetch_page(rref_t rref, int fid, __u32 cnode_idx,
			uint64_t node_page_idx, uintptr_t *vaddr);
int vfs_mmap_change_page(rref_t rref, const vfs_mmap_node_t *node,
			 uint64_t node_page_idx, uint32_t flag);

/* src/ioctl.c */
int vfs_ioctl(int, unsigned int, unsigned long, int);

/* src/locks.c */
int vfs_flock(int fd, unsigned int cmd);

/* src/stat.c */
int vfs_fstat(int fd, struct stat *st);
int vfs_lstat(const char *pathname, struct stat *st);
int vfs_stat(const char *pathname, struct stat *st);
int vfs_fstatat(int dfd, const char *pathname, struct stat *st, int flag);

/* src/sync.c */
int vfs_sync_file_range(int fd, int64_t offset, int64_t nbytes,
			unsigned int flags);
int vfs_fsync(int file);
void vfs_sync(void);

/* src/xattr.c */
ssize_t vfs_sys_getxattr(uint32_t pcnode_idx, uint32_t cnode_idx,
			 const char *path, struct sysif_getxattr_args sga,
			 unsigned int flags);
int vfs_getxattr(const char *path, const char *name, char *value, size_t size, ssize_t *nbyte);
int vfs_lgetxattr(const char *path, const char *name, char *value, size_t size, ssize_t *nbyte);
int vfs_fgetxattr(int fd, const char *name, char *value, size_t size, ssize_t *nbyte);
int vfs_listxattr(const char *path, char *list, size_t size, ssize_t *nbyte);
int vfs_llistxattr(const char *path, char *list, size_t size, ssize_t *nbyte);
int vfs_flistxattr(int fd, char *list, size_t size, ssize_t *nbyte);
int vfs_setxattr(const char *path, const char *name, const char *value, size_t size, int flags);
int vfs_lsetxattr(const char *path, const char *name, const char *value, size_t size, int flags);
int vfs_fsetxattr(int fd, const char *name, const char *value, size_t size, int flags);
int vfs_removexattr(const char *path, const char *name);
int vfs_lremovexattr(const char *path, const char *name);
int vfs_fremovexattr(int fd, const char *name);

/* src/open.c */
int vfs_chown(const char *filename, uid_t uid, gid_t gid);
int vfs_lchown(const char *filename, uid_t uid, gid_t gid);
int vfs_fchownat(int dfd, const char *filename, uid_t uid, gid_t gid, int flag);
int vfs_fchown(int fd, uid_t uid, gid_t gid);
int vfs_dup(int oldfd);
int vfs_dup2(int oldfd, int newfd);
int vfs_dup3(int oldfd, int newfd, int flag);
int vfs_fcntl(int fd, int cmd, unsigned long arg);
int vfs_mkdir(const char *pathname, mode_t mode);
int vfs_mkdirat(int dfd, const char *pathname, mode_t mode);
int vfs_access(const char *pathname, int mode);
int vfs_fwd_access(const char *pathname, int mode);
int vfs_faccessat(int dfd, const char *pathname, int mode);
ssize_t vfs_readlink(const char *path, char *buf, size_t bufsize);
ssize_t vfs_readlinkat(int dfd, const char *path, char *buf, size_t bufsize);
int vfs_sys_open(const char *filename, unsigned int flag, mode_t mode);
int vfs_fwd_openat(int dfd, const char *filename, unsigned int flag, mode_t modes);
int vfs_fwd_open(const char *filename, unsigned int flag, mode_t mode);
int vfs_open(const char *filename, unsigned int flag, mode_t mode);
int vfs_openat(int dfd, const char *filename, unsigned int flag, mode_t modes);
int vfs_openat_with_me(int dfd, const char *filename, unsigned int flag, mode_t mode,
		       int *me_idx);
int vfs_open_exec(const char *path, unsigned int flags, uint64_t node_wrapper,
		  int *fd, struct vfs_file_cred *file_cred);
int vfs_close_exec(int sys_fd, uint32_t cnode_idx, int uapp_rfd);
int vfs_set_elf_file(uint32_t cnode_idx, int sys_fd);
int vfs_utimes(const char *pathname, const struct timeval *time);
int vfs_futimesat(int dfd, const char *pathname, const struct timeval *time);
int vfs_utimensat(int dfd, const char *pathname, const struct timespec *tsp, int flag);
int vfs_close(int fd);
void hm_fd_close_fs(const struct hm_fd *hf);
int vfs_fallocate(int fd, int mode, uint64_t offset, uint64_t length);

/* src/statfs.c */
int vfs_statfs(const char *path, struct statfs *stfs);
int vfs_statfs64(const char *path, size_t size, struct statfs *stfs);
int vfs_fstatfs(int fd, struct statfs *stfs);
int vfs_fstatfs64(int fd, size_t size, struct statfs *stfs);

/* src/read_write.c */
ssize_t vfs_read(int fd, void *buf, size_t nbyte);
ssize_t vfs_write(int fd, const void *buf, size_t nbyte);
ssize_t vfs_pread(int fd, int64_t pos, void *buf, size_t nbyte);
ssize_t vfs_pwrite(int fd, int64_t pos, const void *buf, size_t nbyte);
ssize_t vfs_readv(int fd, const struct iovec *vec, int vlen);
ssize_t vfs_writev(int fd, const struct iovec *vec, int vlen);
ssize_t vfs_preadv(int fd, const struct iovec *vec, int vlen, int64_t pos);
ssize_t vfs_pwritev(int fd, const struct iovec *vec, int vlen, int64_t pos);
ssize_t vfs_readdir(int fd, void *buf, size_t size);

/* posix-clock support */
struct timex;
int vfs_clock_settime(clockid_t clk_id, const struct timespec *tp);
int vfs_clock_gettime(clockid_t clk_id, struct timespec *tp);
int vfs_clock_getres(clockid_t clk_id, struct timespec *tp);
int vfs_clock_adjtime(clockid_t clk_id, struct timex *tx);

/* src/fd.c */
void hm_fd_init(struct hm_fd *hf, int type);
struct hm_fd *hm_fd_get(int fd);
struct hm_fd *hm_fd_get_close(int fd);
int hm_fd_put(struct hm_fd *hf);
void hm_fd_install(struct hm_fd *hf, int fd);
void hm_fd_state_next(struct hm_fd *hf);
void hm_fd_close(const struct hm_fd *hf, int check);

void hm_fdtable_init(void);
bool hm_fdtable_alloc(void);
void hm_fdtable_init_lock(void);
void hm_fdtable_wrlock(void);
void hm_fdtable_rdlock(void);
void hm_fdtable_unlock(void);
unsigned int hm_fdtable_size(void);

void hm_fdtable_net_close(void);
void hm_fdtable_net_init_clean_handle(void (func)(struct hm_fd *hf));
int hm_fdtable_net_replace(int fd, struct hm_fd *hf);
int hm_fdtable_net_post_fork(uintptr_t buf_start, int (func)(
			     const struct hm_fd *hf, uintptr_t buf, int cnt));
void *hm_fdtable_start(void);

int hm_get_fd_type(int fd);
bool hm_fd_is_valid(int fd);
int hm_fd_set_cloexec(int fd, unsigned long flag);
int hm_fd_get_cloexec(int fd);

int hm_fdtable_install(int start, struct hm_fd *hf, unsigned long flag);
void hm_fdtable_uninstall(struct hm_fd *hf);
int hm_fdtable_replace(int fd, struct hm_fd *hf, unsigned int flags);
int hm_fdtable_install_net_clone(int start, struct hm_fd *hf, unsigned long flag);
int hm_fdtable_install_net(int start, struct hm_fd *hf, unsigned long flag);

int pre_copy_fsinfo(void);
void post_copy_fsinfo(int saved_stdio_ready);
int prepare_fsinfo(void **buf, size_t *bufsize, int flags);

int get_stdio_ready(void);
void set_stdio_ready(int v);
unsigned int hm_spawn_clone_flags(void);
void hm_set_spawn_clone_flags(unsigned int flags);
const char *hm_fs_fd_info(void);
size_t hm_fs_fd_size(void);
void hm_fs_set_fd_info(const char *buf);
void hm_fs_set_fd_size(size_t size);

/* src/eventfd.c */
int vfs_init_eventfd(int *fd, unsigned int count, int flags);
int vfs_write_eventfd(int fd, const void *buf, size_t len,
		      __u32 cnode_idx);

/* src/signalfd.c */
int vfs_init_signalfd(int fd, __u64 sigmask, int flags);
int vfs_signalfd_notify(__u32 cnode_idx, const void *buf, int fdcnt);

/* src/timerfd.c */
int vfs_timerfd_create(int clockid, int flags);
int vfs_timerfd_settime(int fd, int flags,
			const struct itimerspec *new_value,
			struct itimerspec *old_value);
int vfs_timerfd_gettime(int fd, struct itimerspec *curr_value);

/* for fork */
static inline void fs_fork_lock(void)
{
	hm_fdtable_wrlock();
}

static inline void fs_fork_unlock(void)
{
	hm_fdtable_unlock();
}

static inline void fs_fork_reinit(void)
{
	hm_fdtable_init_lock();
	init_g_sil_lock();
}

void set_fs_relocated(int relocated);
int get_fs_relocated(void);
int vfs_transfs_fget(int fd, unsigned int *sb_index, unsigned int *f_index,
		     unsigned int *me_index, unsigned long long *filp);
int vfs_transfs_fput(unsigned int me_idx, unsigned long long hm_filp);
int fqsn_to_dev_id(const char *fqsn, dev_t *dev_id);
#endif	/* LIBHMSRV_FS_VFS_H */
