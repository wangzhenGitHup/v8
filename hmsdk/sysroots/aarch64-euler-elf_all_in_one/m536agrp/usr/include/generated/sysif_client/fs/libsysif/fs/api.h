/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for fs
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-filesystems/git/fslibs/libhmsrv_fs/include/libsysif/fs/api.sysif -I ../../../../../work-shared/hm-filesystems/git/fslibs/libhmsrv_fs/include --api-dest ../image/usr/include/generated/sysif_client/fs/libsysif/fs/api.h --server-dest ../image/usr/include/generated/sysif_server/fs/libsysif/fs/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_FS_API_H
#define LIBSYSIF_FS_API_H
#ifndef LIBSYSIF_FS_COMMON_H
#define LIBSYSIF_FS_COMMON_H
#include <libsysif/utils_common.h>
#include <hongmeng/compiler.h>
#include <hongmeng/types.h>
#include <asm/actv_rpc.h>
#ifndef LIBSYSIF_BASE_API_COMMON_H
#define LIBSYSIF_BASE_API_COMMON_H
#include <stddef.h>
#include <stdint.h>
#include <hmkernel/capability.h>
struct sysif_reply_header {
	int32_t retval;
	uint32_t msgsz;
};

#define SYSIF_REPLY_LEN_MAX 256UL
extern void* hm_actvpool_prepare_ret(unsigned long long sender, unsigned long credential, unsigned long size);


extern struct arch_actv_local* hm_actv_current_arch_actv_local(void);


#endif
#include <fs/version.h>


#define PROCFS_PATH_NAME_MAX 256
#define SVP_NAME_MAX 32

struct procfs_ops_cb {
	char svpname[SVP_NAME_MAX];
	unsigned int read_method_id;
	unsigned int write_method_id;
	int tagid;
	uint64_t ctx;
};



#define SYSFS_PATH_NAME_MAX 256
#define SVP_NAME_MAX 32

struct sysfs_ops_cb {
	char svpname[SVP_NAME_MAX];
	unsigned int read_method_id;
	unsigned int write_method_id;
	unsigned int poll_method_id;
	int tagid;
	uint64_t ctx;
};


#include <fsnotify.h>


#include <fsnotify.h>


#include <fs_ioaccount.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <unistd.h>

#define VFS_FILE_CRED_DATA_LEN 64
struct vfs_file_cred {
	char data[VFS_FILE_CRED_DATA_LEN];
};

struct sysif_getxattr_args {
	unsigned long long name;
	unsigned long long value;
	unsigned int namelen;
	unsigned int size;
};


raw_static_assert(sizeof(struct procfs_ops_cb) <= 96,
                    fscall_procfs_create_data_arg_ops_is_too_large);
raw_static_assert(sizeof(struct sysfs_ops_cb) <= 96,
                    fscall_sysfs_create_file_arg_ops_is_too_large);
raw_static_assert(sizeof(struct fsnotify_mark_pars) <= 96,
                    fscall_inotify_add_watch_internal_arg_pars_is_too_large);
raw_static_assert(sizeof(struct fsnotify_mark_pars) <= 96,
                    fscall_fanotify_mark_internal_arg_pars_is_too_large);
raw_static_assert(sizeof(uref_t) <= 96,
                    fscall_vfs_client_init_arg_uref_is_too_large);
raw_static_assert(sizeof(uref_t) <= 96,
                    fscall_vfs_bind_update_arg_uref1_is_too_large);
raw_static_assert(sizeof(uref_t) <= 96,
                    fscall_vfs_bind_update_arg_uref2_is_too_large);
raw_static_assert(sizeof(time_t) <= 96,
                    fscall_vfs_timerfd_settime_arg_it_inval_sec_is_too_large);
raw_static_assert(sizeof(time_t) <= 96,
                    fscall_vfs_timerfd_settime_arg_it_val_sec_is_too_large);
raw_static_assert(sizeof(mode_t) <= 96,
                    fscall_vfs_fchmodat_arg_mode_is_too_large);
raw_static_assert(sizeof(mode_t) <= 96,
                    fscall_vfs_fchmod_arg_mode_is_too_large);
raw_static_assert(sizeof(uid_t) <= 96,
                    fscall_vfs_fchownat_arg_uid_is_too_large);
raw_static_assert(sizeof(gid_t) <= 96,
                    fscall_vfs_fchownat_arg_gid_is_too_large);
raw_static_assert(sizeof(uid_t) <= 96,
                    fscall_vfs_fchown_arg_uid_is_too_large);
raw_static_assert(sizeof(gid_t) <= 96,
                    fscall_vfs_fchown_arg_gid_is_too_large);
raw_static_assert(sizeof(mode_t) <= 96,
                    fscall_vfs_mkdirat_arg_mode_is_too_large);
raw_static_assert(sizeof(struct sysif_getxattr_args) <= 96,
                    fscall_vfs_getxattr_arg_sga_is_too_large);
raw_static_assert(sizeof(rref_t) <= 96,
                    fscall_vfs_iommap_arg_vs_rref_is_too_large);
raw_static_assert(sizeof(uref_t) <= 96,
                    fscall_vfs_anon_register_devhost_arg_dh_ap_uref_is_too_large);
struct __actvret_fscall_procfs_create_data {
};

struct __actvret_fscall_procfs_delete_data {
};

struct __actvret_fscall_procfs_get_process_fds {
};

struct __actvret_fscall_procfs_get_fd_mode {
	mode_t mode;
};

struct __actvret_fscall_sysfs_create_file {
};

struct __actvret_fscall_sysfs_create_dir {
};

struct __actvret_fscall_sysfs_create_symlink {
};

struct __actvret_fscall_sysfs_delete {
	int tagid;
};

struct __actvret_fscall_sysfs_notify {
};

struct __actvret_fscall_clock_settime {
};

struct __actvret_fscall_clock_gettime {
};

struct __actvret_fscall_clock_getres {
};

struct __actvret_fscall_clock_adjtime {
};

struct __actvret_fscall_inotify_init1 {
};

struct __actvret_fscall_inotify_add_watch {
	int wd;
};

struct __actvret_fscall_inotify_rm_watch {
};

struct __actvret_fscall_inotify_add_watch_internal {
	unsigned int index;
	unsigned long long dev_id;
};

struct __actvret_fscall_inotify_rm_watch_internal {
};

struct __actvret_fscall_inotify_notify {
};

struct __actvret_fscall_inotify_inode_destroyed {
};

struct __actvret_fscall_fanotify_init {
};

struct __actvret_fscall_fanotify_mark {
};

struct __actvret_fscall_fanotify_mark_internal {
	unsigned int index;
	unsigned long long dev_id;
};

struct __actvret_fscall_fanotify_rm_watch_internal {
};

struct __actvret_fscall_fanotify_notify {
};

struct __actvret_fscall_fanotify_destroyed {
};

struct __actvret_fscall_fanotify_open {
	int type;
	int has_buf;
	unsigned int nread;
};

struct __actvret_fscall_endio_io_done {
};

struct __actvret_fscall_vfs_set_label {
};

struct __actvret_fscall_vfs_set_label_by_path {
};

struct __actvret_fscall_vfs_get_label {
	unsigned long long label;
};

struct __actvret_fscall_vfs_init_audit {
};

struct __actvret_fscall_vfs_add_audit_rule {
};

struct __actvret_fscall_vfs_del_audit_rule {
};

struct __actvret_fscall_vfs_match_audit_watch_file {
};

struct __actvret_fscall_vfs_match_audit_watch_dir {
};

struct __actvret_fscall_vfs_client_init {
};

struct __actvret_fscall_vfs_bind_update {
};

struct __actvret_fscall_vfs_clone {
};

struct __actvret_fscall_vfs_close {
};

struct __actvret_fscall_vfs_mount {
};

struct __actvret_fscall_vfs_clone_mount_entry {
};

struct __actvret_fscall_vfs_clone_mount_entry_from_orig_parent {
};

struct __actvret_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent {
};

struct __actvret_fscall_vfs_destroy_cloned_mount_entry {
};

struct __actvret_fscall_vfs_check_mount {
};

struct __actvret_fscall_vfs_mountpoint_del_mount {
};

struct __actvret_fscall_vfs_open {
	int type;
	int has_buf;
	unsigned int nread;
};

struct __actvret_fscall_vfs_ftruncate {
};

struct __actvret_fscall_vfs_fstat {
};

struct __actvret_fscall_vfs_stat {
};

struct __actvret_fscall_vfs_statfs {
};

struct __actvret_fscall_vfs_fstatfs {
};

struct __actvret_fscall_vfs_fsync {
};

struct __actvret_fscall_vfs_unmount {
};

struct __actvret_fscall_vfs_unmount_from_server {
};

struct __actvret_fscall_vfs_unmount_child {
};

struct __actvret_fscall_vfs_truncate {
};

struct __actvret_fscall_vfs_fs_fork {
};

struct __actvret_fscall_vfs_query_info {
	rref_t rref;
	unsigned long long filep;
	unsigned long long file_idx;
};

struct __actvret_fscall_vfs_lseek {
	long long new_pos;
};

struct __actvret_fscall_vfs_trans {
};

struct __actvret_fscall_vfs_pipe2 {
	int remote_read_fd;
	int remote_write_fd;
};

struct __actvret_fscall_vfs_tee {
};

struct __actvret_fscall_vfs_splice {
	long long spliced_bytes;
};

struct __actvret_fscall_vfs_do_splice_srvs {
	long long nwritten;
};

struct __actvret_fscall_vfs_revoke_process {
};

struct __actvret_fscall_vfs_setrlimit {
};

struct __actvret_fscall_vfs_get_ns {
	unsigned int curr_nsid;
};

struct __actvret_fscall_vfs_put_ns {
};

struct __actvret_fscall_vfs_init_eventfd {
};

struct __actvret_fscall_vfs_write_eventfd {
};

struct __actvret_fscall_vfs_timerfd_create {
};

struct __actvret_fscall_vfs_timerfd_settime {
	long long od_it_inval_sec;
	long long od_it_inval_nsec;
	long long od_it_val_sec;
	long long od_it_val_nsec;
};

struct __actvret_fscall_vfs_timerfd_gettime {
	long long cur_it_inval_sec;
	long long cur_it_inval_nsec;
	long long cur_it_val_sec;
	long long cur_it_val_nsec;
};

struct __actvret_fscall_vfs_open_exec {
	int uapp_rfd;
	int sys_rfd;
	unsigned int type;
	struct vfs_file_cred file_cred;
};

struct __actvret_fscall_vfs_close_exec {
};

struct __actvret_fscall_vfs_set_elf_file {
};

struct __actvret_fscall_vfs_ioctl {
};

struct __actvret_fscall_vfs_read {
	long long nread;
};

struct __actvret_fscall_vfs_readv {
	long long nread;
};

struct __actvret_fscall_vfs_getcwd {
};

struct __actvret_fscall_vfs_get_process_cwdrootexe {
};

struct __actvret_fscall_vfs_readdir {
};

struct __actvret_fscall_vfs_write {
	long long nwritten;
};

struct __actvret_fscall_vfs_writev {
	long long nwritten;
};

struct __actvret_fscall_vfs_sync {
};

struct __actvret_fscall_vfs_do_sync {
};

struct __actvret_fscall_vfs_utimensat {
};

struct __actvret_fscall_vfs_futimens {
};

struct __actvret_fscall_vfs_fchmodat {
};

struct __actvret_fscall_vfs_fchmod {
};

struct __actvret_fscall_vfs_drop_caches {
};

struct __actvret_fscall_vfs_do_drop_caches {
};

struct __actvret_fscall_vfs_fadvise {
};

struct __actvret_fscall_vfs_readahead {
};

struct __actvret_fscall_vfs_get_fd_path {
};

struct __actvret_fscall_vfs_sysmgr_get_fd_path {
};

struct __actvret_fscall_vfs_fcntl {
};

struct __actvret_fscall_vfs_device_mounted {
};

struct __actvret_fscall_vfs_quotactl {
};

struct __actvret_fscall_vfs_copy_file_range {
	long long ncopy;
	long long off_in;
	long long off_out;
};

struct __actvret_fscall_vfs_same_file {
};

struct __actvret_fscall_vfs_access {
};

struct __actvret_fscall_vfs_flock {
};

struct __actvret_fscall_vfs_fchownat {
};

struct __actvret_fscall_vfs_fchown {
};

struct __actvret_fscall_vfs_binderfs_mmap {
};

struct __actvret_fscall_vfs_init_signalfd {
};

struct __actvret_fscall_vfs_epoll_ctl {
};

struct __actvret_fscall_vfs_epoll_et_revents {
	unsigned int revents;
};

struct __actvret_fscall_vfs_epoll_reinit {
};

struct __actvret_fscall_vfs_signalfd_notify {
};

struct __actvret_fscall_vfs_pid_io_stats {
	struct io_account io_ac;
};

struct __actvret_fscall_vfs_fallocate {
};

struct __actvret_fscall_vfs_set_cwdroot {
};

struct __actvret_fscall_vfs_fchdir {
};

struct __actvret_fscall_vfs_disable_cwdroot {
};

struct __actvret_fscall_vfs_update_cwdroot {
};

struct __actvret_fscall_vfs_handle_global_locks {
	unsigned long long lock_id;
};

struct __actvret_fscall_vfs_send_fd {
};

struct __actvret_fscall_vfs_recv_fd {
	int type;
};

struct __actvret_fscall_vfs_get_buffer_wrapper {
	unsigned long long vaddr_start;
	unsigned long long vaddr_end;
	unsigned long long data_size;
	unsigned long long offsets_buffer_size;
};

struct __actvret_fscall_vfs_get_pathname_by_me_idx {
};

struct __actvret_fscall_vfs_sfile_put {
};

struct __actvret_fscall_vfs_readlinkat {
	int retry;
};

struct __actvret_fscall_vfs_get_slabinfo {
};

struct __actvret_fscall_vfs_do_get_slabinfo {
};

struct __actvret_fscall_vfs_fscache_print_info {
};

struct __actvret_fscall_vfs_alloc_fs_handle_for_same_device {
	unsigned int fs_handle;
};

struct __actvret_fscall_vfs_free_fs_handle_for_same_device {
};

struct __actvret_fscall_vfs_memfd_create {
};

struct __actvret_fscall_vfs_mknod {
};

struct __actvret_fscall_vfs_rename {
};

struct __actvret_fscall_vfs_mkdirat {
};

struct __actvret_fscall_vfs_link {
};

struct __actvret_fscall_vfs_unlink {
};

struct __actvret_fscall_vfs_symlink {
};

struct __actvret_fscall_vfs_getxattr {
	long long nbyte;
};

struct __actvret_fscall_vfs_fgetxattr {
	long long nbyte;
};

struct __actvret_fscall_vfs_setxattr {
};

struct __actvret_fscall_vfs_fsetxattr {
};

struct __actvret_fscall_vfs_listxattr {
	long long nbyte;
};

struct __actvret_fscall_vfs_flistxattr {
	long long nbyte;
};

struct __actvret_fscall_vfs_removexattr {
};

struct __actvret_fscall_vfs_fremovexattr {
};

struct __actvret_fscall_vfs_iommap {
	unsigned long long rvaddr;
};

struct __actvret_fscall_vfs_mmap_create {
	unsigned int index;
	unsigned long long dev_id;
	int fid;
	unsigned int pagesize;
	unsigned long long magic;
};

struct __actvret_fscall_vfs_mmap_release_file {
};

struct __actvret_fscall_vfs_mmap_change {
};

struct __actvret_fscall_vfs_mmap_fill_page {
	unsigned long long vaddr;
};

struct __actvret_fscall_vfs_mmap_fetch_page {
	unsigned long long vaddr;
};

struct __actvret_fscall_vfs_mmap_change_page {
};

struct __actvret_fscall_vfs_mmap_fallocate {
};

struct __actvret_fscall_vfs_gfd_table_update {
};

struct __actvret_fscall_vfs_gfd_table_remove {
};

struct __actvret_fscall_vfs_gfd_table_expand {
};

struct __actvret_fscall_vfs_gfd_table_acquire {
};

struct __actvret_fscall_vfs_gfd_table_release {
};

struct __actvret_fscall_vfs_gfd_table_replace {
};

struct __actvret_fscall_vfs_gfd_table_fault {
};

struct __actvret_fscall_vfs_anon_register_devhost {
};

struct __actvret_fscall_vfs_get_unused_fd {
};

struct __actvret_fscall_vfs_put_unused_fd {
};

struct __actvret_fscall_vfs_fd_info_update {
};

struct __actvret_fscall_vfs_get_root_path {
};

struct __actvret_fscall_vfs_transfs_fget {
	unsigned int sb_index;
	unsigned int f_index;
	unsigned long long hm_filp;
	unsigned int me_index;
};

struct __actvret_fscall_vfs_do_trans_fget {
	unsigned int sb_index;
	unsigned int f_index;
	unsigned long long hm_filp;
};

struct __actvret_fscall_vfs_transfs_fput {
};

struct __actvret_fscall_vfs_do_trans_fput {
};

struct __actvret_fscall_vfs_read_mounts {
	size_t offset;
};

union __actvret_fscall {
	struct __actvret_fscall_procfs_create_data procfs_create_data;
	struct __actvret_fscall_procfs_delete_data procfs_delete_data;
	struct __actvret_fscall_procfs_get_process_fds procfs_get_process_fds;
	struct __actvret_fscall_procfs_get_fd_mode procfs_get_fd_mode;
	struct __actvret_fscall_sysfs_create_file sysfs_create_file;
	struct __actvret_fscall_sysfs_create_dir sysfs_create_dir;
	struct __actvret_fscall_sysfs_create_symlink sysfs_create_symlink;
	struct __actvret_fscall_sysfs_delete sysfs_delete;
	struct __actvret_fscall_sysfs_notify sysfs_notify;
	struct __actvret_fscall_clock_settime clock_settime;
	struct __actvret_fscall_clock_gettime clock_gettime;
	struct __actvret_fscall_clock_getres clock_getres;
	struct __actvret_fscall_clock_adjtime clock_adjtime;
	struct __actvret_fscall_inotify_init1 inotify_init1;
	struct __actvret_fscall_inotify_add_watch inotify_add_watch;
	struct __actvret_fscall_inotify_rm_watch inotify_rm_watch;
	struct __actvret_fscall_inotify_add_watch_internal inotify_add_watch_internal;
	struct __actvret_fscall_inotify_rm_watch_internal inotify_rm_watch_internal;
	struct __actvret_fscall_inotify_notify inotify_notify;
	struct __actvret_fscall_inotify_inode_destroyed inotify_inode_destroyed;
	struct __actvret_fscall_fanotify_init fanotify_init;
	struct __actvret_fscall_fanotify_mark fanotify_mark;
	struct __actvret_fscall_fanotify_mark_internal fanotify_mark_internal;
	struct __actvret_fscall_fanotify_rm_watch_internal fanotify_rm_watch_internal;
	struct __actvret_fscall_fanotify_notify fanotify_notify;
	struct __actvret_fscall_fanotify_destroyed fanotify_destroyed;
	struct __actvret_fscall_fanotify_open fanotify_open;
	struct __actvret_fscall_endio_io_done endio_io_done;
	struct __actvret_fscall_vfs_set_label vfs_set_label;
	struct __actvret_fscall_vfs_set_label_by_path vfs_set_label_by_path;
	struct __actvret_fscall_vfs_get_label vfs_get_label;
	struct __actvret_fscall_vfs_init_audit vfs_init_audit;
	struct __actvret_fscall_vfs_add_audit_rule vfs_add_audit_rule;
	struct __actvret_fscall_vfs_del_audit_rule vfs_del_audit_rule;
	struct __actvret_fscall_vfs_match_audit_watch_file vfs_match_audit_watch_file;
	struct __actvret_fscall_vfs_match_audit_watch_dir vfs_match_audit_watch_dir;
	struct __actvret_fscall_vfs_client_init vfs_client_init;
	struct __actvret_fscall_vfs_bind_update vfs_bind_update;
	struct __actvret_fscall_vfs_clone vfs_clone;
	struct __actvret_fscall_vfs_close vfs_close;
	struct __actvret_fscall_vfs_mount vfs_mount;
	struct __actvret_fscall_vfs_clone_mount_entry vfs_clone_mount_entry;
	struct __actvret_fscall_vfs_clone_mount_entry_from_orig_parent vfs_clone_mount_entry_from_orig_parent;
	struct __actvret_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent vfs_destroy_cloned_mount_entry_from_orig_parent;
	struct __actvret_fscall_vfs_destroy_cloned_mount_entry vfs_destroy_cloned_mount_entry;
	struct __actvret_fscall_vfs_check_mount vfs_check_mount;
	struct __actvret_fscall_vfs_mountpoint_del_mount vfs_mountpoint_del_mount;
	struct __actvret_fscall_vfs_open vfs_open;
	struct __actvret_fscall_vfs_ftruncate vfs_ftruncate;
	struct __actvret_fscall_vfs_fstat vfs_fstat;
	struct __actvret_fscall_vfs_stat vfs_stat;
	struct __actvret_fscall_vfs_statfs vfs_statfs;
	struct __actvret_fscall_vfs_fstatfs vfs_fstatfs;
	struct __actvret_fscall_vfs_fsync vfs_fsync;
	struct __actvret_fscall_vfs_unmount vfs_unmount;
	struct __actvret_fscall_vfs_unmount_from_server vfs_unmount_from_server;
	struct __actvret_fscall_vfs_unmount_child vfs_unmount_child;
	struct __actvret_fscall_vfs_truncate vfs_truncate;
	struct __actvret_fscall_vfs_fs_fork vfs_fs_fork;
	struct __actvret_fscall_vfs_query_info vfs_query_info;
	struct __actvret_fscall_vfs_lseek vfs_lseek;
	struct __actvret_fscall_vfs_trans vfs_trans;
	struct __actvret_fscall_vfs_pipe2 vfs_pipe2;
	struct __actvret_fscall_vfs_tee vfs_tee;
	struct __actvret_fscall_vfs_splice vfs_splice;
	struct __actvret_fscall_vfs_do_splice_srvs vfs_do_splice_srvs;
	struct __actvret_fscall_vfs_revoke_process vfs_revoke_process;
	struct __actvret_fscall_vfs_setrlimit vfs_setrlimit;
	struct __actvret_fscall_vfs_get_ns vfs_get_ns;
	struct __actvret_fscall_vfs_put_ns vfs_put_ns;
	struct __actvret_fscall_vfs_init_eventfd vfs_init_eventfd;
	struct __actvret_fscall_vfs_write_eventfd vfs_write_eventfd;
	struct __actvret_fscall_vfs_timerfd_create vfs_timerfd_create;
	struct __actvret_fscall_vfs_timerfd_settime vfs_timerfd_settime;
	struct __actvret_fscall_vfs_timerfd_gettime vfs_timerfd_gettime;
	struct __actvret_fscall_vfs_open_exec vfs_open_exec;
	struct __actvret_fscall_vfs_close_exec vfs_close_exec;
	struct __actvret_fscall_vfs_set_elf_file vfs_set_elf_file;
	struct __actvret_fscall_vfs_ioctl vfs_ioctl;
	struct __actvret_fscall_vfs_read vfs_read;
	struct __actvret_fscall_vfs_readv vfs_readv;
	struct __actvret_fscall_vfs_getcwd vfs_getcwd;
	struct __actvret_fscall_vfs_get_process_cwdrootexe vfs_get_process_cwdrootexe;
	struct __actvret_fscall_vfs_readdir vfs_readdir;
	struct __actvret_fscall_vfs_write vfs_write;
	struct __actvret_fscall_vfs_writev vfs_writev;
	struct __actvret_fscall_vfs_sync vfs_sync;
	struct __actvret_fscall_vfs_do_sync vfs_do_sync;
	struct __actvret_fscall_vfs_utimensat vfs_utimensat;
	struct __actvret_fscall_vfs_futimens vfs_futimens;
	struct __actvret_fscall_vfs_fchmodat vfs_fchmodat;
	struct __actvret_fscall_vfs_fchmod vfs_fchmod;
	struct __actvret_fscall_vfs_drop_caches vfs_drop_caches;
	struct __actvret_fscall_vfs_do_drop_caches vfs_do_drop_caches;
	struct __actvret_fscall_vfs_fadvise vfs_fadvise;
	struct __actvret_fscall_vfs_readahead vfs_readahead;
	struct __actvret_fscall_vfs_get_fd_path vfs_get_fd_path;
	struct __actvret_fscall_vfs_sysmgr_get_fd_path vfs_sysmgr_get_fd_path;
	struct __actvret_fscall_vfs_fcntl vfs_fcntl;
	struct __actvret_fscall_vfs_device_mounted vfs_device_mounted;
	struct __actvret_fscall_vfs_quotactl vfs_quotactl;
	struct __actvret_fscall_vfs_copy_file_range vfs_copy_file_range;
	struct __actvret_fscall_vfs_same_file vfs_same_file;
	struct __actvret_fscall_vfs_access vfs_access;
	struct __actvret_fscall_vfs_flock vfs_flock;
	struct __actvret_fscall_vfs_fchownat vfs_fchownat;
	struct __actvret_fscall_vfs_fchown vfs_fchown;
	struct __actvret_fscall_vfs_binderfs_mmap vfs_binderfs_mmap;
	struct __actvret_fscall_vfs_init_signalfd vfs_init_signalfd;
	struct __actvret_fscall_vfs_epoll_ctl vfs_epoll_ctl;
	struct __actvret_fscall_vfs_epoll_et_revents vfs_epoll_et_revents;
	struct __actvret_fscall_vfs_epoll_reinit vfs_epoll_reinit;
	struct __actvret_fscall_vfs_signalfd_notify vfs_signalfd_notify;
	struct __actvret_fscall_vfs_pid_io_stats vfs_pid_io_stats;
	struct __actvret_fscall_vfs_fallocate vfs_fallocate;
	struct __actvret_fscall_vfs_set_cwdroot vfs_set_cwdroot;
	struct __actvret_fscall_vfs_fchdir vfs_fchdir;
	struct __actvret_fscall_vfs_disable_cwdroot vfs_disable_cwdroot;
	struct __actvret_fscall_vfs_update_cwdroot vfs_update_cwdroot;
	struct __actvret_fscall_vfs_handle_global_locks vfs_handle_global_locks;
	struct __actvret_fscall_vfs_send_fd vfs_send_fd;
	struct __actvret_fscall_vfs_recv_fd vfs_recv_fd;
	struct __actvret_fscall_vfs_get_buffer_wrapper vfs_get_buffer_wrapper;
	struct __actvret_fscall_vfs_get_pathname_by_me_idx vfs_get_pathname_by_me_idx;
	struct __actvret_fscall_vfs_sfile_put vfs_sfile_put;
	struct __actvret_fscall_vfs_readlinkat vfs_readlinkat;
	struct __actvret_fscall_vfs_get_slabinfo vfs_get_slabinfo;
	struct __actvret_fscall_vfs_do_get_slabinfo vfs_do_get_slabinfo;
	struct __actvret_fscall_vfs_fscache_print_info vfs_fscache_print_info;
	struct __actvret_fscall_vfs_alloc_fs_handle_for_same_device vfs_alloc_fs_handle_for_same_device;
	struct __actvret_fscall_vfs_free_fs_handle_for_same_device vfs_free_fs_handle_for_same_device;
	struct __actvret_fscall_vfs_memfd_create vfs_memfd_create;
	struct __actvret_fscall_vfs_mknod vfs_mknod;
	struct __actvret_fscall_vfs_rename vfs_rename;
	struct __actvret_fscall_vfs_mkdirat vfs_mkdirat;
	struct __actvret_fscall_vfs_link vfs_link;
	struct __actvret_fscall_vfs_unlink vfs_unlink;
	struct __actvret_fscall_vfs_symlink vfs_symlink;
	struct __actvret_fscall_vfs_getxattr vfs_getxattr;
	struct __actvret_fscall_vfs_fgetxattr vfs_fgetxattr;
	struct __actvret_fscall_vfs_setxattr vfs_setxattr;
	struct __actvret_fscall_vfs_fsetxattr vfs_fsetxattr;
	struct __actvret_fscall_vfs_listxattr vfs_listxattr;
	struct __actvret_fscall_vfs_flistxattr vfs_flistxattr;
	struct __actvret_fscall_vfs_removexattr vfs_removexattr;
	struct __actvret_fscall_vfs_fremovexattr vfs_fremovexattr;
	struct __actvret_fscall_vfs_iommap vfs_iommap;
	struct __actvret_fscall_vfs_mmap_create vfs_mmap_create;
	struct __actvret_fscall_vfs_mmap_release_file vfs_mmap_release_file;
	struct __actvret_fscall_vfs_mmap_change vfs_mmap_change;
	struct __actvret_fscall_vfs_mmap_fill_page vfs_mmap_fill_page;
	struct __actvret_fscall_vfs_mmap_fetch_page vfs_mmap_fetch_page;
	struct __actvret_fscall_vfs_mmap_change_page vfs_mmap_change_page;
	struct __actvret_fscall_vfs_mmap_fallocate vfs_mmap_fallocate;
	struct __actvret_fscall_vfs_gfd_table_update vfs_gfd_table_update;
	struct __actvret_fscall_vfs_gfd_table_remove vfs_gfd_table_remove;
	struct __actvret_fscall_vfs_gfd_table_expand vfs_gfd_table_expand;
	struct __actvret_fscall_vfs_gfd_table_acquire vfs_gfd_table_acquire;
	struct __actvret_fscall_vfs_gfd_table_release vfs_gfd_table_release;
	struct __actvret_fscall_vfs_gfd_table_replace vfs_gfd_table_replace;
	struct __actvret_fscall_vfs_gfd_table_fault vfs_gfd_table_fault;
	struct __actvret_fscall_vfs_anon_register_devhost vfs_anon_register_devhost;
	struct __actvret_fscall_vfs_get_unused_fd vfs_get_unused_fd;
	struct __actvret_fscall_vfs_put_unused_fd vfs_put_unused_fd;
	struct __actvret_fscall_vfs_fd_info_update vfs_fd_info_update;
	struct __actvret_fscall_vfs_get_root_path vfs_get_root_path;
	struct __actvret_fscall_vfs_transfs_fget vfs_transfs_fget;
	struct __actvret_fscall_vfs_do_trans_fget vfs_do_trans_fget;
	struct __actvret_fscall_vfs_transfs_fput vfs_transfs_fput;
	struct __actvret_fscall_vfs_do_trans_fput vfs_do_trans_fput;
	struct __actvret_fscall_vfs_read_mounts vfs_read_mounts;
};

enum __fs_mgr {
	__fs_INVAL_mgr=0,
	__fs_procfs_mgr,
	__fs_sysfs_mgr,
	__fs_clock_mgr,
	__fs_inotify_mgr,
	__fs_fanotify_mgr,
	__fs_endio_mgr,
	__fs_sec_mgr,
	__fs_vfs_mgr,
	__fs_MAX_mgr,
};

#define __fs_method_MIN __ACTV_HIGHTABLE_START
#define __fs_method_procfs_create_data (__ACTV_HIGHTABLE_START + 1)
#define __fs_method_procfs_delete_data (__ACTV_HIGHTABLE_START + 2)
#define __fs_method_procfs_get_process_fds (__ACTV_HIGHTABLE_START + 3)
#define __fs_method_procfs_get_fd_mode (__ACTV_HIGHTABLE_START + 4)
#define __fs_method_procfs_rsvd_4 (__ACTV_HIGHTABLE_START + 5)
#define __fs_method_procfs_rsvd_3 (__ACTV_HIGHTABLE_START + 6)
#define __fs_method_procfs_rsvd_2 (__ACTV_HIGHTABLE_START + 7)
#define __fs_method_procfs_rsvd_1 (__ACTV_HIGHTABLE_START + 8)
#define __fs_method_sysfs_create_file (__ACTV_HIGHTABLE_START + 9)
#define __fs_method_sysfs_create_dir (__ACTV_HIGHTABLE_START + 10)
#define __fs_method_sysfs_create_symlink (__ACTV_HIGHTABLE_START + 11)
#define __fs_method_sysfs_delete (__ACTV_HIGHTABLE_START + 12)
#define __fs_method_sysfs_notify (__ACTV_HIGHTABLE_START + 13)
#define __fs_method_sysfs_rsvd_3 (__ACTV_HIGHTABLE_START + 14)
#define __fs_method_sysfs_rsvd_2 (__ACTV_HIGHTABLE_START + 15)
#define __fs_method_sysfs_rsvd_1 (__ACTV_HIGHTABLE_START + 16)
#define __fs_method_clock_settime (__ACTV_HIGHTABLE_START + 17)
#define __fs_method_clock_gettime (__ACTV_HIGHTABLE_START + 18)
#define __fs_method_clock_getres (__ACTV_HIGHTABLE_START + 19)
#define __fs_method_clock_adjtime (__ACTV_HIGHTABLE_START + 20)
#define __fs_method_clock_rsvd_4 (__ACTV_HIGHTABLE_START + 21)
#define __fs_method_clock_rsvd_3 (__ACTV_HIGHTABLE_START + 22)
#define __fs_method_clock_rsvd_2 (__ACTV_HIGHTABLE_START + 23)
#define __fs_method_clock_rsvd_1 (__ACTV_HIGHTABLE_START + 24)
#define __fs_method_inotify_init1 (__ACTV_HIGHTABLE_START + 25)
#define __fs_method_inotify_add_watch (__ACTV_HIGHTABLE_START + 26)
#define __fs_method_inotify_rm_watch (__ACTV_HIGHTABLE_START + 27)
#define __fs_method_inotify_add_watch_internal (__ACTV_HIGHTABLE_START + 28)
#define __fs_method_inotify_rm_watch_internal (__ACTV_HIGHTABLE_START + 29)
#define __fs_method_inotify_notify (__ACTV_HIGHTABLE_START + 30)
#define __fs_method_inotify_inode_destroyed (__ACTV_HIGHTABLE_START + 31)
#define __fs_method_inotify_rsvd_9 (__ACTV_HIGHTABLE_START + 32)
#define __fs_method_inotify_rsvd_8 (__ACTV_HIGHTABLE_START + 33)
#define __fs_method_inotify_rsvd_7 (__ACTV_HIGHTABLE_START + 34)
#define __fs_method_inotify_rsvd_6 (__ACTV_HIGHTABLE_START + 35)
#define __fs_method_inotify_rsvd_5 (__ACTV_HIGHTABLE_START + 36)
#define __fs_method_inotify_rsvd_4 (__ACTV_HIGHTABLE_START + 37)
#define __fs_method_inotify_rsvd_3 (__ACTV_HIGHTABLE_START + 38)
#define __fs_method_inotify_rsvd_2 (__ACTV_HIGHTABLE_START + 39)
#define __fs_method_inotify_rsvd_1 (__ACTV_HIGHTABLE_START + 40)
#define __fs_method_fanotify_init (__ACTV_HIGHTABLE_START + 41)
#define __fs_method_fanotify_mark (__ACTV_HIGHTABLE_START + 42)
#define __fs_method_fanotify_mark_internal (__ACTV_HIGHTABLE_START + 43)
#define __fs_method_fanotify_rm_watch_internal (__ACTV_HIGHTABLE_START + 44)
#define __fs_method_fanotify_notify (__ACTV_HIGHTABLE_START + 45)
#define __fs_method_fanotify_destroyed (__ACTV_HIGHTABLE_START + 46)
#define __fs_method_fanotify_open (__ACTV_HIGHTABLE_START + 47)
#define __fs_method_fanotify_rsvd_9 (__ACTV_HIGHTABLE_START + 48)
#define __fs_method_fanotify_rsvd_8 (__ACTV_HIGHTABLE_START + 49)
#define __fs_method_fanotify_rsvd_7 (__ACTV_HIGHTABLE_START + 50)
#define __fs_method_fanotify_rsvd_6 (__ACTV_HIGHTABLE_START + 51)
#define __fs_method_fanotify_rsvd_5 (__ACTV_HIGHTABLE_START + 52)
#define __fs_method_fanotify_rsvd_4 (__ACTV_HIGHTABLE_START + 53)
#define __fs_method_fanotify_rsvd_3 (__ACTV_HIGHTABLE_START + 54)
#define __fs_method_fanotify_rsvd_2 (__ACTV_HIGHTABLE_START + 55)
#define __fs_method_fanotify_rsvd_1 (__ACTV_HIGHTABLE_START + 56)
#define __fs_method_endio_io_done (__ACTV_HIGHTABLE_START + 57)
#define __fs_method_endio_rsvd_7 (__ACTV_HIGHTABLE_START + 58)
#define __fs_method_endio_rsvd_6 (__ACTV_HIGHTABLE_START + 59)
#define __fs_method_endio_rsvd_5 (__ACTV_HIGHTABLE_START + 60)
#define __fs_method_endio_rsvd_4 (__ACTV_HIGHTABLE_START + 61)
#define __fs_method_endio_rsvd_3 (__ACTV_HIGHTABLE_START + 62)
#define __fs_method_endio_rsvd_2 (__ACTV_HIGHTABLE_START + 63)
#define __fs_method_endio_rsvd_1 (__ACTV_HIGHTABLE_START + 64)
#define __fs_method_vfs_set_label (__ACTV_HIGHTABLE_START + 65)
#define __fs_method_vfs_set_label_by_path (__ACTV_HIGHTABLE_START + 66)
#define __fs_method_vfs_get_label (__ACTV_HIGHTABLE_START + 67)
#define __fs_method_vfs_init_audit (__ACTV_HIGHTABLE_START + 68)
#define __fs_method_vfs_add_audit_rule (__ACTV_HIGHTABLE_START + 69)
#define __fs_method_vfs_del_audit_rule (__ACTV_HIGHTABLE_START + 70)
#define __fs_method_vfs_match_audit_watch_file (__ACTV_HIGHTABLE_START + 71)
#define __fs_method_vfs_match_audit_watch_dir (__ACTV_HIGHTABLE_START + 72)
#define __fs_method_sec_rsvd_8 (__ACTV_HIGHTABLE_START + 73)
#define __fs_method_sec_rsvd_7 (__ACTV_HIGHTABLE_START + 74)
#define __fs_method_sec_rsvd_6 (__ACTV_HIGHTABLE_START + 75)
#define __fs_method_sec_rsvd_5 (__ACTV_HIGHTABLE_START + 76)
#define __fs_method_sec_rsvd_4 (__ACTV_HIGHTABLE_START + 77)
#define __fs_method_sec_rsvd_3 (__ACTV_HIGHTABLE_START + 78)
#define __fs_method_sec_rsvd_2 (__ACTV_HIGHTABLE_START + 79)
#define __fs_method_sec_rsvd_1 (__ACTV_HIGHTABLE_START + 80)
#define __fs_method_vfs_client_init (__ACTV_HIGHTABLE_START + 81)
#define __fs_method_vfs_bind_update (__ACTV_HIGHTABLE_START + 82)
#define __fs_method_vfs_clone (__ACTV_HIGHTABLE_START + 83)
#define __fs_method_vfs_close (__ACTV_HIGHTABLE_START + 84)
#define __fs_method_vfs_mount (__ACTV_HIGHTABLE_START + 85)
#define __fs_method_vfs_clone_mount_entry (__ACTV_HIGHTABLE_START + 86)
#define __fs_method_vfs_clone_mount_entry_from_orig_parent (__ACTV_HIGHTABLE_START + 87)
#define __fs_method_vfs_destroy_cloned_mount_entry_from_orig_parent (__ACTV_HIGHTABLE_START + 88)
#define __fs_method_vfs_destroy_cloned_mount_entry (__ACTV_HIGHTABLE_START + 89)
#define __fs_method_vfs_check_mount (__ACTV_HIGHTABLE_START + 90)
#define __fs_method_vfs_mountpoint_del_mount (__ACTV_HIGHTABLE_START + 91)
#define __fs_method_vfs_open (__ACTV_HIGHTABLE_START + 92)
#define __fs_method_vfs_ftruncate (__ACTV_HIGHTABLE_START + 93)
#define __fs_method_vfs_fstat (__ACTV_HIGHTABLE_START + 94)
#define __fs_method_vfs_stat (__ACTV_HIGHTABLE_START + 95)
#define __fs_method_vfs_statfs (__ACTV_HIGHTABLE_START + 96)
#define __fs_method_vfs_fstatfs (__ACTV_HIGHTABLE_START + 97)
#define __fs_method_vfs_fsync (__ACTV_HIGHTABLE_START + 98)
#define __fs_method_vfs_unmount (__ACTV_HIGHTABLE_START + 99)
#define __fs_method_vfs_unmount_from_server (__ACTV_HIGHTABLE_START + 100)
#define __fs_method_vfs_unmount_child (__ACTV_HIGHTABLE_START + 101)
#define __fs_method_vfs_truncate (__ACTV_HIGHTABLE_START + 102)
#define __fs_method_vfs_fs_fork (__ACTV_HIGHTABLE_START + 103)
#define __fs_method_vfs_query_info (__ACTV_HIGHTABLE_START + 104)
#define __fs_method_vfs_lseek (__ACTV_HIGHTABLE_START + 105)
#define __fs_method_vfs_trans (__ACTV_HIGHTABLE_START + 106)
#define __fs_method_vfs_pipe2 (__ACTV_HIGHTABLE_START + 107)
#define __fs_method_vfs_tee (__ACTV_HIGHTABLE_START + 108)
#define __fs_method_vfs_splice (__ACTV_HIGHTABLE_START + 109)
#define __fs_method_vfs_do_splice_srvs (__ACTV_HIGHTABLE_START + 110)
#define __fs_method_vfs_revoke_process (__ACTV_HIGHTABLE_START + 111)
#define __fs_method_vfs_setrlimit (__ACTV_HIGHTABLE_START + 112)
#define __fs_method_vfs_get_ns (__ACTV_HIGHTABLE_START + 113)
#define __fs_method_vfs_put_ns (__ACTV_HIGHTABLE_START + 114)
#define __fs_method_vfs_init_eventfd (__ACTV_HIGHTABLE_START + 115)
#define __fs_method_vfs_write_eventfd (__ACTV_HIGHTABLE_START + 116)
#define __fs_method_vfs_timerfd_create (__ACTV_HIGHTABLE_START + 117)
#define __fs_method_vfs_timerfd_settime (__ACTV_HIGHTABLE_START + 118)
#define __fs_method_vfs_timerfd_gettime (__ACTV_HIGHTABLE_START + 119)
#define __fs_method_vfs_open_exec (__ACTV_HIGHTABLE_START + 120)
#define __fs_method_vfs_close_exec (__ACTV_HIGHTABLE_START + 121)
#define __fs_method_vfs_set_elf_file (__ACTV_HIGHTABLE_START + 122)
#define __fs_method_vfs_ioctl (__ACTV_HIGHTABLE_START + 123)
#define __fs_method_vfs_read (__ACTV_HIGHTABLE_START + 124)
#define __fs_method_vfs_readv (__ACTV_HIGHTABLE_START + 125)
#define __fs_method_vfs_getcwd (__ACTV_HIGHTABLE_START + 126)
#define __fs_method_vfs_get_process_cwdrootexe (__ACTV_HIGHTABLE_START + 127)
#define __fs_method_vfs_readdir (__ACTV_HIGHTABLE_START + 128)
#define __fs_method_vfs_write (__ACTV_HIGHTABLE_START + 129)
#define __fs_method_vfs_writev (__ACTV_HIGHTABLE_START + 130)
#define __fs_method_vfs_sync (__ACTV_HIGHTABLE_START + 131)
#define __fs_method_vfs_do_sync (__ACTV_HIGHTABLE_START + 132)
#define __fs_method_vfs_utimensat (__ACTV_HIGHTABLE_START + 133)
#define __fs_method_vfs_futimens (__ACTV_HIGHTABLE_START + 134)
#define __fs_method_vfs_fchmodat (__ACTV_HIGHTABLE_START + 135)
#define __fs_method_vfs_fchmod (__ACTV_HIGHTABLE_START + 136)
#define __fs_method_vfs_drop_caches (__ACTV_HIGHTABLE_START + 137)
#define __fs_method_vfs_do_drop_caches (__ACTV_HIGHTABLE_START + 138)
#define __fs_method_vfs_fadvise (__ACTV_HIGHTABLE_START + 139)
#define __fs_method_vfs_readahead (__ACTV_HIGHTABLE_START + 140)
#define __fs_method_vfs_get_fd_path (__ACTV_HIGHTABLE_START + 141)
#define __fs_method_vfs_sysmgr_get_fd_path (__ACTV_HIGHTABLE_START + 142)
#define __fs_method_vfs_fcntl (__ACTV_HIGHTABLE_START + 143)
#define __fs_method_vfs_device_mounted (__ACTV_HIGHTABLE_START + 144)
#define __fs_method_vfs_quotactl (__ACTV_HIGHTABLE_START + 145)
#define __fs_method_vfs_copy_file_range (__ACTV_HIGHTABLE_START + 146)
#define __fs_method_vfs_same_file (__ACTV_HIGHTABLE_START + 147)
#define __fs_method_vfs_access (__ACTV_HIGHTABLE_START + 148)
#define __fs_method_vfs_flock (__ACTV_HIGHTABLE_START + 149)
#define __fs_method_vfs_fchownat (__ACTV_HIGHTABLE_START + 150)
#define __fs_method_vfs_fchown (__ACTV_HIGHTABLE_START + 151)
#define __fs_method_vfs_binderfs_mmap (__ACTV_HIGHTABLE_START + 152)
#define __fs_method_vfs_init_signalfd (__ACTV_HIGHTABLE_START + 153)
#define __fs_method_vfs_epoll_ctl (__ACTV_HIGHTABLE_START + 154)
#define __fs_method_vfs_epoll_et_revents (__ACTV_HIGHTABLE_START + 155)
#define __fs_method_vfs_epoll_reinit (__ACTV_HIGHTABLE_START + 156)
#define __fs_method_vfs_signalfd_notify (__ACTV_HIGHTABLE_START + 157)
#define __fs_method_vfs_pid_io_stats (__ACTV_HIGHTABLE_START + 158)
#define __fs_method_vfs_fallocate (__ACTV_HIGHTABLE_START + 159)
#define __fs_method_vfs_set_cwdroot (__ACTV_HIGHTABLE_START + 160)
#define __fs_method_vfs_fchdir (__ACTV_HIGHTABLE_START + 161)
#define __fs_method_vfs_disable_cwdroot (__ACTV_HIGHTABLE_START + 162)
#define __fs_method_vfs_update_cwdroot (__ACTV_HIGHTABLE_START + 163)
#define __fs_method_vfs_handle_global_locks (__ACTV_HIGHTABLE_START + 164)
#define __fs_method_vfs_send_fd (__ACTV_HIGHTABLE_START + 165)
#define __fs_method_vfs_recv_fd (__ACTV_HIGHTABLE_START + 166)
#define __fs_method_vfs_get_buffer_wrapper (__ACTV_HIGHTABLE_START + 167)
#define __fs_method_vfs_get_pathname_by_me_idx (__ACTV_HIGHTABLE_START + 168)
#define __fs_method_vfs_sfile_put (__ACTV_HIGHTABLE_START + 169)
#define __fs_method_vfs_readlinkat (__ACTV_HIGHTABLE_START + 170)
#define __fs_method_vfs_get_slabinfo (__ACTV_HIGHTABLE_START + 171)
#define __fs_method_vfs_do_get_slabinfo (__ACTV_HIGHTABLE_START + 172)
#define __fs_method_vfs_fscache_print_info (__ACTV_HIGHTABLE_START + 173)
#define __fs_method_vfs_alloc_fs_handle_for_same_device (__ACTV_HIGHTABLE_START + 174)
#define __fs_method_vfs_free_fs_handle_for_same_device (__ACTV_HIGHTABLE_START + 175)
#define __fs_method_vfs_memfd_create (__ACTV_HIGHTABLE_START + 176)
#define __fs_method_vfs_mknod (__ACTV_HIGHTABLE_START + 177)
#define __fs_method_vfs_rename (__ACTV_HIGHTABLE_START + 178)
#define __fs_method_vfs_mkdirat (__ACTV_HIGHTABLE_START + 179)
#define __fs_method_vfs_link (__ACTV_HIGHTABLE_START + 180)
#define __fs_method_vfs_unlink (__ACTV_HIGHTABLE_START + 181)
#define __fs_method_vfs_symlink (__ACTV_HIGHTABLE_START + 182)
#define __fs_method_vfs_getxattr (__ACTV_HIGHTABLE_START + 183)
#define __fs_method_vfs_fgetxattr (__ACTV_HIGHTABLE_START + 184)
#define __fs_method_vfs_setxattr (__ACTV_HIGHTABLE_START + 185)
#define __fs_method_vfs_fsetxattr (__ACTV_HIGHTABLE_START + 186)
#define __fs_method_vfs_listxattr (__ACTV_HIGHTABLE_START + 187)
#define __fs_method_vfs_flistxattr (__ACTV_HIGHTABLE_START + 188)
#define __fs_method_vfs_removexattr (__ACTV_HIGHTABLE_START + 189)
#define __fs_method_vfs_fremovexattr (__ACTV_HIGHTABLE_START + 190)
#define __fs_method_vfs_iommap (__ACTV_HIGHTABLE_START + 191)
#define __fs_method_vfs_mmap_create (__ACTV_HIGHTABLE_START + 192)
#define __fs_method_vfs_mmap_release_file (__ACTV_HIGHTABLE_START + 193)
#define __fs_method_vfs_mmap_change (__ACTV_HIGHTABLE_START + 194)
#define __fs_method_vfs_mmap_fill_page (__ACTV_HIGHTABLE_START + 195)
#define __fs_method_vfs_mmap_fetch_page (__ACTV_HIGHTABLE_START + 196)
#define __fs_method_vfs_mmap_change_page (__ACTV_HIGHTABLE_START + 197)
#define __fs_method_vfs_mmap_fallocate (__ACTV_HIGHTABLE_START + 198)
#define __fs_method_vfs_gfd_table_update (__ACTV_HIGHTABLE_START + 199)
#define __fs_method_vfs_gfd_table_remove (__ACTV_HIGHTABLE_START + 200)
#define __fs_method_vfs_gfd_table_expand (__ACTV_HIGHTABLE_START + 201)
#define __fs_method_vfs_gfd_table_acquire (__ACTV_HIGHTABLE_START + 202)
#define __fs_method_vfs_gfd_table_release (__ACTV_HIGHTABLE_START + 203)
#define __fs_method_vfs_gfd_table_replace (__ACTV_HIGHTABLE_START + 204)
#define __fs_method_vfs_gfd_table_fault (__ACTV_HIGHTABLE_START + 205)
#define __fs_method_vfs_anon_register_devhost (__ACTV_HIGHTABLE_START + 206)
#define __fs_method_vfs_get_unused_fd (__ACTV_HIGHTABLE_START + 207)
#define __fs_method_vfs_put_unused_fd (__ACTV_HIGHTABLE_START + 208)
#define __fs_method_vfs_fd_info_update (__ACTV_HIGHTABLE_START + 209)
#define __fs_method_vfs_get_root_path (__ACTV_HIGHTABLE_START + 210)
#define __fs_method_vfs_transfs_fget (__ACTV_HIGHTABLE_START + 211)
#define __fs_method_vfs_do_trans_fget (__ACTV_HIGHTABLE_START + 212)
#define __fs_method_vfs_transfs_fput (__ACTV_HIGHTABLE_START + 213)
#define __fs_method_vfs_do_trans_fput (__ACTV_HIGHTABLE_START + 214)
#define __fs_method_vfs_read_mounts (__ACTV_HIGHTABLE_START + 215)
#define __fs_method_vfs_rsvd_121 (__ACTV_HIGHTABLE_START + 216)
#define __fs_method_vfs_rsvd_120 (__ACTV_HIGHTABLE_START + 217)
#define __fs_method_vfs_rsvd_119 (__ACTV_HIGHTABLE_START + 218)
#define __fs_method_vfs_rsvd_118 (__ACTV_HIGHTABLE_START + 219)
#define __fs_method_vfs_rsvd_117 (__ACTV_HIGHTABLE_START + 220)
#define __fs_method_vfs_rsvd_116 (__ACTV_HIGHTABLE_START + 221)
#define __fs_method_vfs_rsvd_115 (__ACTV_HIGHTABLE_START + 222)
#define __fs_method_vfs_rsvd_114 (__ACTV_HIGHTABLE_START + 223)
#define __fs_method_vfs_rsvd_113 (__ACTV_HIGHTABLE_START + 224)
#define __fs_method_vfs_rsvd_112 (__ACTV_HIGHTABLE_START + 225)
#define __fs_method_vfs_rsvd_111 (__ACTV_HIGHTABLE_START + 226)
#define __fs_method_vfs_rsvd_110 (__ACTV_HIGHTABLE_START + 227)
#define __fs_method_vfs_rsvd_109 (__ACTV_HIGHTABLE_START + 228)
#define __fs_method_vfs_rsvd_108 (__ACTV_HIGHTABLE_START + 229)
#define __fs_method_vfs_rsvd_107 (__ACTV_HIGHTABLE_START + 230)
#define __fs_method_vfs_rsvd_106 (__ACTV_HIGHTABLE_START + 231)
#define __fs_method_vfs_rsvd_105 (__ACTV_HIGHTABLE_START + 232)
#define __fs_method_vfs_rsvd_104 (__ACTV_HIGHTABLE_START + 233)
#define __fs_method_vfs_rsvd_103 (__ACTV_HIGHTABLE_START + 234)
#define __fs_method_vfs_rsvd_102 (__ACTV_HIGHTABLE_START + 235)
#define __fs_method_vfs_rsvd_101 (__ACTV_HIGHTABLE_START + 236)
#define __fs_method_vfs_rsvd_100 (__ACTV_HIGHTABLE_START + 237)
#define __fs_method_vfs_rsvd_99 (__ACTV_HIGHTABLE_START + 238)
#define __fs_method_vfs_rsvd_98 (__ACTV_HIGHTABLE_START + 239)
#define __fs_method_vfs_rsvd_97 (__ACTV_HIGHTABLE_START + 240)
#define __fs_method_vfs_rsvd_96 (__ACTV_HIGHTABLE_START + 241)
#define __fs_method_vfs_rsvd_95 (__ACTV_HIGHTABLE_START + 242)
#define __fs_method_vfs_rsvd_94 (__ACTV_HIGHTABLE_START + 243)
#define __fs_method_vfs_rsvd_93 (__ACTV_HIGHTABLE_START + 244)
#define __fs_method_vfs_rsvd_92 (__ACTV_HIGHTABLE_START + 245)
#define __fs_method_vfs_rsvd_91 (__ACTV_HIGHTABLE_START + 246)
#define __fs_method_vfs_rsvd_90 (__ACTV_HIGHTABLE_START + 247)
#define __fs_method_vfs_rsvd_89 (__ACTV_HIGHTABLE_START + 248)
#define __fs_method_vfs_rsvd_88 (__ACTV_HIGHTABLE_START + 249)
#define __fs_method_vfs_rsvd_87 (__ACTV_HIGHTABLE_START + 250)
#define __fs_method_vfs_rsvd_86 (__ACTV_HIGHTABLE_START + 251)
#define __fs_method_vfs_rsvd_85 (__ACTV_HIGHTABLE_START + 252)
#define __fs_method_vfs_rsvd_84 (__ACTV_HIGHTABLE_START + 253)
#define __fs_method_vfs_rsvd_83 (__ACTV_HIGHTABLE_START + 254)
#define __fs_method_vfs_rsvd_82 (__ACTV_HIGHTABLE_START + 255)
#define __fs_method_vfs_rsvd_81 (__ACTV_HIGHTABLE_START + 256)
#define __fs_method_vfs_rsvd_80 (__ACTV_HIGHTABLE_START + 257)
#define __fs_method_vfs_rsvd_79 (__ACTV_HIGHTABLE_START + 258)
#define __fs_method_vfs_rsvd_78 (__ACTV_HIGHTABLE_START + 259)
#define __fs_method_vfs_rsvd_77 (__ACTV_HIGHTABLE_START + 260)
#define __fs_method_vfs_rsvd_76 (__ACTV_HIGHTABLE_START + 261)
#define __fs_method_vfs_rsvd_75 (__ACTV_HIGHTABLE_START + 262)
#define __fs_method_vfs_rsvd_74 (__ACTV_HIGHTABLE_START + 263)
#define __fs_method_vfs_rsvd_73 (__ACTV_HIGHTABLE_START + 264)
#define __fs_method_vfs_rsvd_72 (__ACTV_HIGHTABLE_START + 265)
#define __fs_method_vfs_rsvd_71 (__ACTV_HIGHTABLE_START + 266)
#define __fs_method_vfs_rsvd_70 (__ACTV_HIGHTABLE_START + 267)
#define __fs_method_vfs_rsvd_69 (__ACTV_HIGHTABLE_START + 268)
#define __fs_method_vfs_rsvd_68 (__ACTV_HIGHTABLE_START + 269)
#define __fs_method_vfs_rsvd_67 (__ACTV_HIGHTABLE_START + 270)
#define __fs_method_vfs_rsvd_66 (__ACTV_HIGHTABLE_START + 271)
#define __fs_method_vfs_rsvd_65 (__ACTV_HIGHTABLE_START + 272)
#define __fs_method_vfs_rsvd_64 (__ACTV_HIGHTABLE_START + 273)
#define __fs_method_vfs_rsvd_63 (__ACTV_HIGHTABLE_START + 274)
#define __fs_method_vfs_rsvd_62 (__ACTV_HIGHTABLE_START + 275)
#define __fs_method_vfs_rsvd_61 (__ACTV_HIGHTABLE_START + 276)
#define __fs_method_vfs_rsvd_60 (__ACTV_HIGHTABLE_START + 277)
#define __fs_method_vfs_rsvd_59 (__ACTV_HIGHTABLE_START + 278)
#define __fs_method_vfs_rsvd_58 (__ACTV_HIGHTABLE_START + 279)
#define __fs_method_vfs_rsvd_57 (__ACTV_HIGHTABLE_START + 280)
#define __fs_method_vfs_rsvd_56 (__ACTV_HIGHTABLE_START + 281)
#define __fs_method_vfs_rsvd_55 (__ACTV_HIGHTABLE_START + 282)
#define __fs_method_vfs_rsvd_54 (__ACTV_HIGHTABLE_START + 283)
#define __fs_method_vfs_rsvd_53 (__ACTV_HIGHTABLE_START + 284)
#define __fs_method_vfs_rsvd_52 (__ACTV_HIGHTABLE_START + 285)
#define __fs_method_vfs_rsvd_51 (__ACTV_HIGHTABLE_START + 286)
#define __fs_method_vfs_rsvd_50 (__ACTV_HIGHTABLE_START + 287)
#define __fs_method_vfs_rsvd_49 (__ACTV_HIGHTABLE_START + 288)
#define __fs_method_vfs_rsvd_48 (__ACTV_HIGHTABLE_START + 289)
#define __fs_method_vfs_rsvd_47 (__ACTV_HIGHTABLE_START + 290)
#define __fs_method_vfs_rsvd_46 (__ACTV_HIGHTABLE_START + 291)
#define __fs_method_vfs_rsvd_45 (__ACTV_HIGHTABLE_START + 292)
#define __fs_method_vfs_rsvd_44 (__ACTV_HIGHTABLE_START + 293)
#define __fs_method_vfs_rsvd_43 (__ACTV_HIGHTABLE_START + 294)
#define __fs_method_vfs_rsvd_42 (__ACTV_HIGHTABLE_START + 295)
#define __fs_method_vfs_rsvd_41 (__ACTV_HIGHTABLE_START + 296)
#define __fs_method_vfs_rsvd_40 (__ACTV_HIGHTABLE_START + 297)
#define __fs_method_vfs_rsvd_39 (__ACTV_HIGHTABLE_START + 298)
#define __fs_method_vfs_rsvd_38 (__ACTV_HIGHTABLE_START + 299)
#define __fs_method_vfs_rsvd_37 (__ACTV_HIGHTABLE_START + 300)
#define __fs_method_vfs_rsvd_36 (__ACTV_HIGHTABLE_START + 301)
#define __fs_method_vfs_rsvd_35 (__ACTV_HIGHTABLE_START + 302)
#define __fs_method_vfs_rsvd_34 (__ACTV_HIGHTABLE_START + 303)
#define __fs_method_vfs_rsvd_33 (__ACTV_HIGHTABLE_START + 304)
#define __fs_method_vfs_rsvd_32 (__ACTV_HIGHTABLE_START + 305)
#define __fs_method_vfs_rsvd_31 (__ACTV_HIGHTABLE_START + 306)
#define __fs_method_vfs_rsvd_30 (__ACTV_HIGHTABLE_START + 307)
#define __fs_method_vfs_rsvd_29 (__ACTV_HIGHTABLE_START + 308)
#define __fs_method_vfs_rsvd_28 (__ACTV_HIGHTABLE_START + 309)
#define __fs_method_vfs_rsvd_27 (__ACTV_HIGHTABLE_START + 310)
#define __fs_method_vfs_rsvd_26 (__ACTV_HIGHTABLE_START + 311)
#define __fs_method_vfs_rsvd_25 (__ACTV_HIGHTABLE_START + 312)
#define __fs_method_vfs_rsvd_24 (__ACTV_HIGHTABLE_START + 313)
#define __fs_method_vfs_rsvd_23 (__ACTV_HIGHTABLE_START + 314)
#define __fs_method_vfs_rsvd_22 (__ACTV_HIGHTABLE_START + 315)
#define __fs_method_vfs_rsvd_21 (__ACTV_HIGHTABLE_START + 316)
#define __fs_method_vfs_rsvd_20 (__ACTV_HIGHTABLE_START + 317)
#define __fs_method_vfs_rsvd_19 (__ACTV_HIGHTABLE_START + 318)
#define __fs_method_vfs_rsvd_18 (__ACTV_HIGHTABLE_START + 319)
#define __fs_method_vfs_rsvd_17 (__ACTV_HIGHTABLE_START + 320)
#define __fs_method_vfs_rsvd_16 (__ACTV_HIGHTABLE_START + 321)
#define __fs_method_vfs_rsvd_15 (__ACTV_HIGHTABLE_START + 322)
#define __fs_method_vfs_rsvd_14 (__ACTV_HIGHTABLE_START + 323)
#define __fs_method_vfs_rsvd_13 (__ACTV_HIGHTABLE_START + 324)
#define __fs_method_vfs_rsvd_12 (__ACTV_HIGHTABLE_START + 325)
#define __fs_method_vfs_rsvd_11 (__ACTV_HIGHTABLE_START + 326)
#define __fs_method_vfs_rsvd_10 (__ACTV_HIGHTABLE_START + 327)
#define __fs_method_vfs_rsvd_9 (__ACTV_HIGHTABLE_START + 328)
#define __fs_method_vfs_rsvd_8 (__ACTV_HIGHTABLE_START + 329)
#define __fs_method_vfs_rsvd_7 (__ACTV_HIGHTABLE_START + 330)
#define __fs_method_vfs_rsvd_6 (__ACTV_HIGHTABLE_START + 331)
#define __fs_method_vfs_rsvd_5 (__ACTV_HIGHTABLE_START + 332)
#define __fs_method_vfs_rsvd_4 (__ACTV_HIGHTABLE_START + 333)
#define __fs_method_vfs_rsvd_3 (__ACTV_HIGHTABLE_START + 334)
#define __fs_method_vfs_rsvd_2 (__ACTV_HIGHTABLE_START + 335)
#define __fs_method_vfs_rsvd_1 (__ACTV_HIGHTABLE_START + 336)
#define __fs_method_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + 337)
#define __fs_method_MAX_COMPAT ((__ACTV_HIGHTABLE_START + 337) * 2)
raw_static_assert(sizeof(struct __actvret_fscall_procfs_create_data) < 512,
                fscall_procfs_create_data_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_procfs_delete_data) < 512,
                fscall_procfs_delete_data_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_procfs_get_process_fds) < 512,
                fscall_procfs_get_process_fds_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_procfs_get_fd_mode) < 512,
                fscall_procfs_get_fd_mode_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_sysfs_create_file) < 512,
                fscall_sysfs_create_file_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_sysfs_create_dir) < 512,
                fscall_sysfs_create_dir_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_sysfs_create_symlink) < 512,
                fscall_sysfs_create_symlink_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_sysfs_delete) < 512,
                fscall_sysfs_delete_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_sysfs_notify) < 512,
                fscall_sysfs_notify_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_clock_settime) < 512,
                fscall_clock_settime_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_clock_gettime) < 512,
                fscall_clock_gettime_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_clock_getres) < 512,
                fscall_clock_getres_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_clock_adjtime) < 512,
                fscall_clock_adjtime_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_inotify_init1) < 512,
                fscall_inotify_init1_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_inotify_add_watch) < 512,
                fscall_inotify_add_watch_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_inotify_rm_watch) < 512,
                fscall_inotify_rm_watch_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_inotify_add_watch_internal) < 512,
                fscall_inotify_add_watch_internal_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_inotify_rm_watch_internal) < 512,
                fscall_inotify_rm_watch_internal_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_inotify_notify) < 512,
                fscall_inotify_notify_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_inotify_inode_destroyed) < 512,
                fscall_inotify_inode_destroyed_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_fanotify_init) < 512,
                fscall_fanotify_init_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_fanotify_mark) < 512,
                fscall_fanotify_mark_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_fanotify_mark_internal) < 512,
                fscall_fanotify_mark_internal_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_fanotify_rm_watch_internal) < 512,
                fscall_fanotify_rm_watch_internal_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_fanotify_notify) < 512,
                fscall_fanotify_notify_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_fanotify_destroyed) < 512,
                fscall_fanotify_destroyed_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_fanotify_open) < 512,
                fscall_fanotify_open_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_endio_io_done) < 512,
                fscall_endio_io_done_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_set_label) < 512,
                fscall_vfs_set_label_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_set_label_by_path) < 512,
                fscall_vfs_set_label_by_path_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_get_label) < 512,
                fscall_vfs_get_label_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_init_audit) < 512,
                fscall_vfs_init_audit_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_add_audit_rule) < 512,
                fscall_vfs_add_audit_rule_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_del_audit_rule) < 512,
                fscall_vfs_del_audit_rule_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_match_audit_watch_file) < 512,
                fscall_vfs_match_audit_watch_file_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_match_audit_watch_dir) < 512,
                fscall_vfs_match_audit_watch_dir_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_client_init) < 512,
                fscall_vfs_client_init_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_bind_update) < 512,
                fscall_vfs_bind_update_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_clone) < 512,
                fscall_vfs_clone_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_close) < 512,
                fscall_vfs_close_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mount) < 512,
                fscall_vfs_mount_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_clone_mount_entry) < 512,
                fscall_vfs_clone_mount_entry_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_clone_mount_entry_from_orig_parent) < 512,
                fscall_vfs_clone_mount_entry_from_orig_parent_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent) < 512,
                fscall_vfs_destroy_cloned_mount_entry_from_orig_parent_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_destroy_cloned_mount_entry) < 512,
                fscall_vfs_destroy_cloned_mount_entry_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_check_mount) < 512,
                fscall_vfs_check_mount_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mountpoint_del_mount) < 512,
                fscall_vfs_mountpoint_del_mount_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_open) < 512,
                fscall_vfs_open_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_ftruncate) < 512,
                fscall_vfs_ftruncate_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fstat) < 512,
                fscall_vfs_fstat_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_stat) < 512,
                fscall_vfs_stat_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_statfs) < 512,
                fscall_vfs_statfs_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fstatfs) < 512,
                fscall_vfs_fstatfs_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fsync) < 512,
                fscall_vfs_fsync_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_unmount) < 512,
                fscall_vfs_unmount_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_unmount_from_server) < 512,
                fscall_vfs_unmount_from_server_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_unmount_child) < 512,
                fscall_vfs_unmount_child_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_truncate) < 512,
                fscall_vfs_truncate_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fs_fork) < 512,
                fscall_vfs_fs_fork_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_query_info) < 512,
                fscall_vfs_query_info_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_lseek) < 512,
                fscall_vfs_lseek_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_trans) < 512,
                fscall_vfs_trans_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_pipe2) < 512,
                fscall_vfs_pipe2_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_tee) < 512,
                fscall_vfs_tee_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_splice) < 512,
                fscall_vfs_splice_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_do_splice_srvs) < 512,
                fscall_vfs_do_splice_srvs_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_revoke_process) < 512,
                fscall_vfs_revoke_process_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_setrlimit) < 512,
                fscall_vfs_setrlimit_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_get_ns) < 512,
                fscall_vfs_get_ns_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_put_ns) < 512,
                fscall_vfs_put_ns_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_init_eventfd) < 512,
                fscall_vfs_init_eventfd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_write_eventfd) < 512,
                fscall_vfs_write_eventfd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_timerfd_create) < 512,
                fscall_vfs_timerfd_create_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_timerfd_settime) < 512,
                fscall_vfs_timerfd_settime_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_timerfd_gettime) < 512,
                fscall_vfs_timerfd_gettime_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_open_exec) < 512,
                fscall_vfs_open_exec_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_close_exec) < 512,
                fscall_vfs_close_exec_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_set_elf_file) < 512,
                fscall_vfs_set_elf_file_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_ioctl) < 512,
                fscall_vfs_ioctl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_read) < 512,
                fscall_vfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_readv) < 512,
                fscall_vfs_readv_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_getcwd) < 512,
                fscall_vfs_getcwd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_get_process_cwdrootexe) < 512,
                fscall_vfs_get_process_cwdrootexe_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_readdir) < 512,
                fscall_vfs_readdir_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_write) < 512,
                fscall_vfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_writev) < 512,
                fscall_vfs_writev_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_sync) < 512,
                fscall_vfs_sync_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_do_sync) < 512,
                fscall_vfs_do_sync_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_utimensat) < 512,
                fscall_vfs_utimensat_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_futimens) < 512,
                fscall_vfs_futimens_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fchmodat) < 512,
                fscall_vfs_fchmodat_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fchmod) < 512,
                fscall_vfs_fchmod_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_drop_caches) < 512,
                fscall_vfs_drop_caches_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_do_drop_caches) < 512,
                fscall_vfs_do_drop_caches_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fadvise) < 512,
                fscall_vfs_fadvise_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_readahead) < 512,
                fscall_vfs_readahead_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_get_fd_path) < 512,
                fscall_vfs_get_fd_path_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_sysmgr_get_fd_path) < 512,
                fscall_vfs_sysmgr_get_fd_path_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fcntl) < 512,
                fscall_vfs_fcntl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_device_mounted) < 512,
                fscall_vfs_device_mounted_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_quotactl) < 512,
                fscall_vfs_quotactl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_copy_file_range) < 512,
                fscall_vfs_copy_file_range_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_same_file) < 512,
                fscall_vfs_same_file_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_access) < 512,
                fscall_vfs_access_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_flock) < 512,
                fscall_vfs_flock_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fchownat) < 512,
                fscall_vfs_fchownat_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fchown) < 512,
                fscall_vfs_fchown_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_binderfs_mmap) < 512,
                fscall_vfs_binderfs_mmap_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_init_signalfd) < 512,
                fscall_vfs_init_signalfd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_epoll_ctl) < 512,
                fscall_vfs_epoll_ctl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_epoll_et_revents) < 512,
                fscall_vfs_epoll_et_revents_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_epoll_reinit) < 512,
                fscall_vfs_epoll_reinit_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_signalfd_notify) < 512,
                fscall_vfs_signalfd_notify_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_pid_io_stats) < 512,
                fscall_vfs_pid_io_stats_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fallocate) < 512,
                fscall_vfs_fallocate_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_set_cwdroot) < 512,
                fscall_vfs_set_cwdroot_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fchdir) < 512,
                fscall_vfs_fchdir_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_disable_cwdroot) < 512,
                fscall_vfs_disable_cwdroot_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_update_cwdroot) < 512,
                fscall_vfs_update_cwdroot_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_handle_global_locks) < 512,
                fscall_vfs_handle_global_locks_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_send_fd) < 512,
                fscall_vfs_send_fd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_recv_fd) < 512,
                fscall_vfs_recv_fd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_get_buffer_wrapper) < 512,
                fscall_vfs_get_buffer_wrapper_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_get_pathname_by_me_idx) < 512,
                fscall_vfs_get_pathname_by_me_idx_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_sfile_put) < 512,
                fscall_vfs_sfile_put_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_readlinkat) < 512,
                fscall_vfs_readlinkat_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_get_slabinfo) < 512,
                fscall_vfs_get_slabinfo_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_do_get_slabinfo) < 512,
                fscall_vfs_do_get_slabinfo_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fscache_print_info) < 512,
                fscall_vfs_fscache_print_info_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_alloc_fs_handle_for_same_device) < 512,
                fscall_vfs_alloc_fs_handle_for_same_device_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_free_fs_handle_for_same_device) < 512,
                fscall_vfs_free_fs_handle_for_same_device_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_memfd_create) < 512,
                fscall_vfs_memfd_create_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mknod) < 512,
                fscall_vfs_mknod_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_rename) < 512,
                fscall_vfs_rename_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mkdirat) < 512,
                fscall_vfs_mkdirat_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_link) < 512,
                fscall_vfs_link_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_unlink) < 512,
                fscall_vfs_unlink_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_symlink) < 512,
                fscall_vfs_symlink_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_getxattr) < 512,
                fscall_vfs_getxattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fgetxattr) < 512,
                fscall_vfs_fgetxattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_setxattr) < 512,
                fscall_vfs_setxattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fsetxattr) < 512,
                fscall_vfs_fsetxattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_listxattr) < 512,
                fscall_vfs_listxattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_flistxattr) < 512,
                fscall_vfs_flistxattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_removexattr) < 512,
                fscall_vfs_removexattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fremovexattr) < 512,
                fscall_vfs_fremovexattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_iommap) < 512,
                fscall_vfs_iommap_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mmap_create) < 512,
                fscall_vfs_mmap_create_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mmap_release_file) < 512,
                fscall_vfs_mmap_release_file_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mmap_change) < 512,
                fscall_vfs_mmap_change_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mmap_fill_page) < 512,
                fscall_vfs_mmap_fill_page_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mmap_fetch_page) < 512,
                fscall_vfs_mmap_fetch_page_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mmap_change_page) < 512,
                fscall_vfs_mmap_change_page_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_mmap_fallocate) < 512,
                fscall_vfs_mmap_fallocate_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_gfd_table_update) < 512,
                fscall_vfs_gfd_table_update_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_gfd_table_remove) < 512,
                fscall_vfs_gfd_table_remove_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_gfd_table_expand) < 512,
                fscall_vfs_gfd_table_expand_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_gfd_table_acquire) < 512,
                fscall_vfs_gfd_table_acquire_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_gfd_table_release) < 512,
                fscall_vfs_gfd_table_release_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_gfd_table_replace) < 512,
                fscall_vfs_gfd_table_replace_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_gfd_table_fault) < 512,
                fscall_vfs_gfd_table_fault_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_anon_register_devhost) < 512,
                fscall_vfs_anon_register_devhost_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_get_unused_fd) < 512,
                fscall_vfs_get_unused_fd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_put_unused_fd) < 512,
                fscall_vfs_put_unused_fd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_fd_info_update) < 512,
                fscall_vfs_fd_info_update_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_get_root_path) < 512,
                fscall_vfs_get_root_path_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_transfs_fget) < 512,
                fscall_vfs_transfs_fget_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_do_trans_fget) < 512,
                fscall_vfs_do_trans_fget_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_transfs_fput) < 512,
                fscall_vfs_transfs_fput_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_do_trans_fput) < 512,
                fscall_vfs_do_trans_fput_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_fscall_vfs_read_mounts) < 512,
                fscall_vfs_read_mounts_too_many_actvret_data);
raw_static_assert(sizeof(union __actvret_fscall) < 512,
        fscall_too_many_actvret_data);
extern int __actvcall_fscall_procfs_create_data(unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode, struct procfs_ops_cb ops);


extern int __actvcapcall_fscall_procfs_create_data(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode, struct procfs_ops_cb ops);


static inline int __attribute__((always_inline)) actvxactcall_fscall_procfs_create_data(bool is_xact_fwd, bool is_xact_allow_refwd, const char *pathname, unsigned int mode, struct procfs_ops_cb ops, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_procfs_create_data;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct procfs_ops_cb), __arch_actv_rpc_stksz_alignment(struct procfs_ops_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_procfs_create_data(rpc_info, ___void_buf, pathname, mode, ops);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_procfs_create_data(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, const char *pathname, unsigned int mode, struct procfs_ops_cb ops, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_procfs_create_data;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct procfs_ops_cb), __arch_actv_rpc_stksz_alignment(struct procfs_ops_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_procfs_create_data(__rref, rpc_info, ___void_buf, pathname, mode, ops);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_procfs_create_data(const char *pathname, unsigned int mode, struct procfs_ops_cb ops, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_procfs_create_data(false, false, pathname, mode, ops, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_procfs_create_data(rref_t __rref, const char *pathname, unsigned int mode, struct procfs_ops_cb ops, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_procfs_create_data(false, false, __rref, pathname, mode, ops, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_procfs_delete_data(unsigned long long __rpc_info, void *__buf, const char *pathname);


extern int __actvcapcall_fscall_procfs_delete_data(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname);


static inline int __attribute__((always_inline)) actvxactcall_fscall_procfs_delete_data(bool is_xact_fwd, bool is_xact_allow_refwd, const char *pathname)
{
	const unsigned long __callno = __fs_method_procfs_delete_data;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_procfs_delete_data(rpc_info, NULL, pathname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_procfs_delete_data(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, const char *pathname)
{
	const unsigned long __callno = __fs_method_procfs_delete_data;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_procfs_delete_data(__rref, rpc_info, NULL, pathname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_procfs_delete_data(const char *pathname)
{
	return actvxactcall_fscall_procfs_delete_data(false, false, pathname);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_procfs_delete_data(rref_t __rref, const char *pathname)
{
	return actvxactcapcall_fscall_procfs_delete_data(false, false, __rref, pathname);
}

extern int __actvcall_fscall_procfs_get_process_fds(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long *bitmap, unsigned int max_files);


extern int __actvcapcall_fscall_procfs_get_process_fds(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long *bitmap, unsigned int max_files);


static inline int __attribute__((always_inline)) actvxactcall_fscall_procfs_get_process_fds(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, unsigned long long *bitmap, unsigned int max_files)
{
	const unsigned long __callno = __fs_method_procfs_get_process_fds;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long*), __arch_actv_rpc_stksz_alignment(unsigned long long*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_procfs_get_process_fds(rpc_info, NULL, cnode_idx, bitmap, max_files);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_procfs_get_process_fds(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, unsigned long long *bitmap, unsigned int max_files)
{
	const unsigned long __callno = __fs_method_procfs_get_process_fds;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long*), __arch_actv_rpc_stksz_alignment(unsigned long long*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_procfs_get_process_fds(__rref, rpc_info, NULL, cnode_idx, bitmap, max_files);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_procfs_get_process_fds(unsigned int cnode_idx, unsigned long long *bitmap, unsigned int max_files)
{
	return actvxactcall_fscall_procfs_get_process_fds(false, false, cnode_idx, bitmap, max_files);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_procfs_get_process_fds(rref_t __rref, unsigned int cnode_idx, unsigned long long *bitmap, unsigned int max_files)
{
	return actvxactcapcall_fscall_procfs_get_process_fds(false, false, __rref, cnode_idx, bitmap, max_files);
}

extern int __actvcall_fscall_procfs_get_fd_mode(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx);


extern int __actvcapcall_fscall_procfs_get_fd_mode(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_procfs_get_fd_mode(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int cnode_idx, struct __actvret_fscall_procfs_get_fd_mode *__ret)
{
	const unsigned long __callno = __fs_method_procfs_get_fd_mode;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_procfs_get_fd_mode(rpc_info, __ret, fd, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_procfs_get_fd_mode(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int cnode_idx, struct __actvret_fscall_procfs_get_fd_mode *__ret)
{
	const unsigned long __callno = __fs_method_procfs_get_fd_mode;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_procfs_get_fd_mode(__rref, rpc_info, __ret, fd, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_procfs_get_fd_mode(int fd, unsigned int cnode_idx, struct __actvret_fscall_procfs_get_fd_mode *__ret)
{
	return actvxactcall_fscall_procfs_get_fd_mode(false, false, fd, cnode_idx, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_procfs_get_fd_mode(rref_t __rref, int fd, unsigned int cnode_idx, struct __actvret_fscall_procfs_get_fd_mode *__ret)
{
	return actvxactcapcall_fscall_procfs_get_fd_mode(false, false, __rref, fd, cnode_idx, __ret);
}

extern int __actvcall_fscall_sysfs_create_file(unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode, struct sysfs_ops_cb ops);


extern int __actvcapcall_fscall_sysfs_create_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode, struct sysfs_ops_cb ops);


static inline int __attribute__((always_inline)) actvxactcall_fscall_sysfs_create_file(bool is_xact_fwd, bool is_xact_allow_refwd, const char *pathname, unsigned int mode, struct sysfs_ops_cb ops)
{
	const unsigned long __callno = __fs_method_sysfs_create_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysfs_ops_cb), __arch_actv_rpc_stksz_alignment(struct sysfs_ops_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_sysfs_create_file(rpc_info, NULL, pathname, mode, ops);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_sysfs_create_file(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, const char *pathname, unsigned int mode, struct sysfs_ops_cb ops)
{
	const unsigned long __callno = __fs_method_sysfs_create_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysfs_ops_cb), __arch_actv_rpc_stksz_alignment(struct sysfs_ops_cb));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_sysfs_create_file(__rref, rpc_info, NULL, pathname, mode, ops);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_sysfs_create_file(const char *pathname, unsigned int mode, struct sysfs_ops_cb ops)
{
	return actvxactcall_fscall_sysfs_create_file(false, false, pathname, mode, ops);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_sysfs_create_file(rref_t __rref, const char *pathname, unsigned int mode, struct sysfs_ops_cb ops)
{
	return actvxactcapcall_fscall_sysfs_create_file(false, false, __rref, pathname, mode, ops);
}

extern int __actvcall_fscall_sysfs_create_dir(unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode);


extern int __actvcapcall_fscall_sysfs_create_dir(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode);


static inline int __attribute__((always_inline)) actvxactcall_fscall_sysfs_create_dir(bool is_xact_fwd, bool is_xact_allow_refwd, const char *pathname, unsigned int mode)
{
	const unsigned long __callno = __fs_method_sysfs_create_dir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_sysfs_create_dir(rpc_info, NULL, pathname, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_sysfs_create_dir(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, const char *pathname, unsigned int mode)
{
	const unsigned long __callno = __fs_method_sysfs_create_dir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_sysfs_create_dir(__rref, rpc_info, NULL, pathname, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_sysfs_create_dir(const char *pathname, unsigned int mode)
{
	return actvxactcall_fscall_sysfs_create_dir(false, false, pathname, mode);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_sysfs_create_dir(rref_t __rref, const char *pathname, unsigned int mode)
{
	return actvxactcapcall_fscall_sysfs_create_dir(false, false, __rref, pathname, mode);
}

extern int __actvcall_fscall_sysfs_create_symlink(unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode);


extern int __actvcapcall_fscall_sysfs_create_symlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode);


static inline int __attribute__((always_inline)) actvxactcall_fscall_sysfs_create_symlink(bool is_xact_fwd, bool is_xact_allow_refwd, const char *pathname, unsigned int mode, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_sysfs_create_symlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_sysfs_create_symlink(rpc_info, ___void_buf, pathname, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_sysfs_create_symlink(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, const char *pathname, unsigned int mode, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_sysfs_create_symlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_sysfs_create_symlink(__rref, rpc_info, ___void_buf, pathname, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_sysfs_create_symlink(const char *pathname, unsigned int mode, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_sysfs_create_symlink(false, false, pathname, mode, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_sysfs_create_symlink(rref_t __rref, const char *pathname, unsigned int mode, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_sysfs_create_symlink(false, false, __rref, pathname, mode, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_sysfs_delete(unsigned long long __rpc_info, void *__buf, const char *pathname);


extern int __actvcapcall_fscall_sysfs_delete(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname);


static inline int __attribute__((always_inline)) actvxactcall_fscall_sysfs_delete(bool is_xact_fwd, bool is_xact_allow_refwd, const char *pathname, struct __actvret_fscall_sysfs_delete *__ret)
{
	const unsigned long __callno = __fs_method_sysfs_delete;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_sysfs_delete(rpc_info, __ret, pathname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_sysfs_delete(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, const char *pathname, struct __actvret_fscall_sysfs_delete *__ret)
{
	const unsigned long __callno = __fs_method_sysfs_delete;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_sysfs_delete(__rref, rpc_info, __ret, pathname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_sysfs_delete(const char *pathname, struct __actvret_fscall_sysfs_delete *__ret)
{
	return actvxactcall_fscall_sysfs_delete(false, false, pathname, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_sysfs_delete(rref_t __rref, const char *pathname, struct __actvret_fscall_sysfs_delete *__ret)
{
	return actvxactcapcall_fscall_sysfs_delete(false, false, __rref, pathname, __ret);
}

extern int __actvcall_fscall_sysfs_notify(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_fscall_sysfs_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_fscall_sysfs_notify(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_sysfs_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_sysfs_notify(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_sysfs_notify(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_sysfs_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_sysfs_notify(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_sysfs_notify(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_sysfs_notify(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_sysfs_notify(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_sysfs_notify(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_clock_settime(unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp);


extern int __actvcapcall_fscall_clock_settime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp);


static inline int __attribute__((always_inline)) actvxactcall_fscall_clock_settime(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long tp)
{
	const unsigned long __callno = __fs_method_clock_settime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_clock_settime(rpc_info, NULL, fd, tp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_clock_settime(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long tp)
{
	const unsigned long __callno = __fs_method_clock_settime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_clock_settime(__rref, rpc_info, NULL, fd, tp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_clock_settime(int fd, unsigned long tp)
{
	return actvxactcall_fscall_clock_settime(false, false, fd, tp);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_clock_settime(rref_t __rref, int fd, unsigned long tp)
{
	return actvxactcapcall_fscall_clock_settime(false, false, __rref, fd, tp);
}

extern int __actvcall_fscall_clock_gettime(unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp);


extern int __actvcapcall_fscall_clock_gettime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp);


static inline int __attribute__((always_inline)) actvxactcall_fscall_clock_gettime(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long tp)
{
	const unsigned long __callno = __fs_method_clock_gettime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_clock_gettime(rpc_info, NULL, fd, tp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_clock_gettime(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long tp)
{
	const unsigned long __callno = __fs_method_clock_gettime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_clock_gettime(__rref, rpc_info, NULL, fd, tp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_clock_gettime(int fd, unsigned long tp)
{
	return actvxactcall_fscall_clock_gettime(false, false, fd, tp);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_clock_gettime(rref_t __rref, int fd, unsigned long tp)
{
	return actvxactcapcall_fscall_clock_gettime(false, false, __rref, fd, tp);
}

extern int __actvcall_fscall_clock_getres(unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp);


extern int __actvcapcall_fscall_clock_getres(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp);


static inline int __attribute__((always_inline)) actvxactcall_fscall_clock_getres(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long tp)
{
	const unsigned long __callno = __fs_method_clock_getres;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_clock_getres(rpc_info, NULL, fd, tp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_clock_getres(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long tp)
{
	const unsigned long __callno = __fs_method_clock_getres;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_clock_getres(__rref, rpc_info, NULL, fd, tp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_clock_getres(int fd, unsigned long tp)
{
	return actvxactcall_fscall_clock_getres(false, false, fd, tp);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_clock_getres(rref_t __rref, int fd, unsigned long tp)
{
	return actvxactcapcall_fscall_clock_getres(false, false, __rref, fd, tp);
}

extern int __actvcall_fscall_clock_adjtime(unsigned long long __rpc_info, void *__buf, int fd, unsigned long tx);


extern int __actvcapcall_fscall_clock_adjtime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long tx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_clock_adjtime(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long tx)
{
	const unsigned long __callno = __fs_method_clock_adjtime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_clock_adjtime(rpc_info, NULL, fd, tx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_clock_adjtime(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long tx)
{
	const unsigned long __callno = __fs_method_clock_adjtime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_clock_adjtime(__rref, rpc_info, NULL, fd, tx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_clock_adjtime(int fd, unsigned long tx)
{
	return actvxactcall_fscall_clock_adjtime(false, false, fd, tx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_clock_adjtime(rref_t __rref, int fd, unsigned long tx)
{
	return actvxactcapcall_fscall_clock_adjtime(false, false, __rref, fd, tx);
}

extern int __actvcall_fscall_inotify_init1(unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags);


extern int __actvcapcall_fscall_inotify_init1(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_inotify_init1(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int flags)
{
	const unsigned long __callno = __fs_method_inotify_init1;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_inotify_init1(rpc_info, NULL, fd, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_inotify_init1(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int flags)
{
	const unsigned long __callno = __fs_method_inotify_init1;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_inotify_init1(__rref, rpc_info, NULL, fd, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_inotify_init1(int fd, unsigned int flags)
{
	return actvxactcall_fscall_inotify_init1(false, false, fd, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_inotify_init1(rref_t __rref, int fd, unsigned int flags)
{
	return actvxactcapcall_fscall_inotify_init1(false, false, __rref, fd, flags);
}

extern int __actvcall_fscall_inotify_add_watch(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int fd, unsigned int mask, int me_idx);


extern int __actvcapcall_fscall_inotify_add_watch(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int fd, unsigned int mask, int me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_inotify_add_watch(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int mask, int me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_inotify_add_watch *__ret)
{
	const unsigned long __callno = __fs_method_inotify_add_watch;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_inotify_add_watch(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, fd, mask, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_inotify_add_watch(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int mask, int me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_inotify_add_watch *__ret)
{
	const unsigned long __callno = __fs_method_inotify_add_watch;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_inotify_add_watch(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, fd, mask, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_inotify_add_watch(int fd, unsigned int mask, int me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_inotify_add_watch *__ret)
{
	return actvxactcall_fscall_inotify_add_watch(false, false, fd, mask, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_inotify_add_watch(rref_t __rref, int fd, unsigned int mask, int me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_inotify_add_watch *__ret)
{
	return actvxactcapcall_fscall_inotify_add_watch(false, false, __rref, fd, mask, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_fscall_inotify_rm_watch(unsigned long long __rpc_info, void *__buf, int fd, int wd);


extern int __actvcapcall_fscall_inotify_rm_watch(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int wd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_inotify_rm_watch(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int wd)
{
	const unsigned long __callno = __fs_method_inotify_rm_watch;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_inotify_rm_watch(rpc_info, NULL, fd, wd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_inotify_rm_watch(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int wd)
{
	const unsigned long __callno = __fs_method_inotify_rm_watch;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_inotify_rm_watch(__rref, rpc_info, NULL, fd, wd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_inotify_rm_watch(int fd, int wd)
{
	return actvxactcall_fscall_inotify_rm_watch(false, false, fd, wd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_inotify_rm_watch(rref_t __rref, int fd, int wd)
{
	return actvxactcapcall_fscall_inotify_rm_watch(false, false, __rref, fd, wd);
}

extern int __actvcall_fscall_inotify_add_watch_internal(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname);


extern int __actvcapcall_fscall_inotify_add_watch_internal(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname);


static inline int __attribute__((always_inline)) actvxactcall_fscall_inotify_add_watch_internal(bool is_xact_fwd, bool is_xact_allow_refwd, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_inotify_add_watch_internal *__ret)
{
	const unsigned long __callno = __fs_method_inotify_add_watch_internal;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct fsnotify_mark_pars), __arch_actv_rpc_stksz_alignment(struct fsnotify_mark_pars));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_inotify_add_watch_internal(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, me_idx, cnode_idx, nsid, pars, new_path, srvname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_inotify_add_watch_internal(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_inotify_add_watch_internal *__ret)
{
	const unsigned long __callno = __fs_method_inotify_add_watch_internal;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct fsnotify_mark_pars), __arch_actv_rpc_stksz_alignment(struct fsnotify_mark_pars));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_inotify_add_watch_internal(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, me_idx, cnode_idx, nsid, pars, new_path, srvname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_inotify_add_watch_internal(int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_inotify_add_watch_internal *__ret)
{
	return actvxactcall_fscall_inotify_add_watch_internal(false, false, me_idx, cnode_idx, nsid, pars, new_path, srvname, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_inotify_add_watch_internal(rref_t __rref, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_inotify_add_watch_internal *__ret)
{
	return actvxactcapcall_fscall_inotify_add_watch_internal(false, false, __rref, me_idx, cnode_idx, nsid, pars, new_path, srvname, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_fscall_inotify_rm_watch_internal(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id);


extern int __actvcapcall_fscall_inotify_rm_watch_internal(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id);


static inline int __attribute__((always_inline)) actvxactcall_fscall_inotify_rm_watch_internal(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id)
{
	const unsigned long __callno = __fs_method_inotify_rm_watch_internal;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_inotify_rm_watch_internal(rpc_info, NULL, cnode_idx, inotify_fd, wd, nsid, index, dev_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_inotify_rm_watch_internal(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id)
{
	const unsigned long __callno = __fs_method_inotify_rm_watch_internal;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_inotify_rm_watch_internal(__rref, rpc_info, NULL, cnode_idx, inotify_fd, wd, nsid, index, dev_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_inotify_rm_watch_internal(unsigned int cnode_idx, int inotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id)
{
	return actvxactcall_fscall_inotify_rm_watch_internal(false, false, cnode_idx, inotify_fd, wd, nsid, index, dev_id);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_inotify_rm_watch_internal(rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id)
{
	return actvxactcapcall_fscall_inotify_rm_watch_internal(false, false, __rref, cnode_idx, inotify_fd, wd, nsid, index, dev_id);
}

extern int __actvcall_fscall_inotify_notify(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token);


extern int __actvcapcall_fscall_inotify_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token);


static inline int __attribute__((always_inline)) actvxactcall_fscall_inotify_notify(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_inotify_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_inotify_notify(rpc_info, ___void_buf, cnode_idx, inotify_fd, wd, event, cookie, token);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_inotify_notify(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_inotify_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_inotify_notify(__rref, rpc_info, ___void_buf, cnode_idx, inotify_fd, wd, event, cookie, token);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_inotify_notify(unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_inotify_notify(false, false, cnode_idx, inotify_fd, wd, event, cookie, token, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_inotify_notify(rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_inotify_notify(false, false, __rref, cnode_idx, inotify_fd, wd, event, cookie, token, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_inotify_inode_destroyed(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token);


extern int __actvcapcall_fscall_inotify_inode_destroyed(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token);


static inline int __attribute__((always_inline)) actvxactcall_fscall_inotify_inode_destroyed(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	const unsigned long __callno = __fs_method_inotify_inode_destroyed;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_inotify_inode_destroyed(rpc_info, NULL, cnode_idx, inotify_fd, wd, token);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_inotify_inode_destroyed(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	const unsigned long __callno = __fs_method_inotify_inode_destroyed;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_inotify_inode_destroyed(__rref, rpc_info, NULL, cnode_idx, inotify_fd, wd, token);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_inotify_inode_destroyed(unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	return actvxactcall_fscall_inotify_inode_destroyed(false, false, cnode_idx, inotify_fd, wd, token);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_inotify_inode_destroyed(rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	return actvxactcapcall_fscall_inotify_inode_destroyed(false, false, __rref, cnode_idx, inotify_fd, wd, token);
}

extern int __actvcall_fscall_fanotify_init(unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags);


extern int __actvcapcall_fscall_fanotify_init(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_fanotify_init(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int flags)
{
	const unsigned long __callno = __fs_method_fanotify_init;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_fanotify_init(rpc_info, NULL, fd, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_fanotify_init(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int flags)
{
	const unsigned long __callno = __fs_method_fanotify_init;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_fanotify_init(__rref, rpc_info, NULL, fd, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_fanotify_init(int fd, unsigned int flags)
{
	return actvxactcall_fscall_fanotify_init(false, false, fd, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_fanotify_init(rref_t __rref, int fd, unsigned int flags)
{
	return actvxactcapcall_fscall_fanotify_init(false, false, __rref, fd, flags);
}

extern int __actvcall_fscall_fanotify_mark(unsigned long long __rpc_info, void *__buf, int fanotify_fd, unsigned int flags, uint64_t mask, int me_idx);


extern int __actvcapcall_fscall_fanotify_mark(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fanotify_fd, unsigned int flags, uint64_t mask, int me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_fanotify_mark(bool is_xact_fwd, bool is_xact_allow_refwd, int fanotify_fd, unsigned int flags, uint64_t mask, int me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_fanotify_mark;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_fanotify_mark(rpc_info, ___void_buf, fanotify_fd, flags, mask, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_fanotify_mark(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fanotify_fd, unsigned int flags, uint64_t mask, int me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_fanotify_mark;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_fanotify_mark(__rref, rpc_info, ___void_buf, fanotify_fd, flags, mask, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_fanotify_mark(int fanotify_fd, unsigned int flags, uint64_t mask, int me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_fanotify_mark(false, false, fanotify_fd, flags, mask, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_fanotify_mark(rref_t __rref, int fanotify_fd, unsigned int flags, uint64_t mask, int me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_fanotify_mark(false, false, __rref, fanotify_fd, flags, mask, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_fanotify_mark_internal(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname);


extern int __actvcapcall_fscall_fanotify_mark_internal(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname);


static inline int __attribute__((always_inline)) actvxactcall_fscall_fanotify_mark_internal(bool is_xact_fwd, bool is_xact_allow_refwd, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_fanotify_mark_internal *__ret)
{
	const unsigned long __callno = __fs_method_fanotify_mark_internal;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct fsnotify_mark_pars), __arch_actv_rpc_stksz_alignment(struct fsnotify_mark_pars));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_fanotify_mark_internal(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, me_idx, cnode_idx, nsid, pars, new_path, srvname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_fanotify_mark_internal(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_fanotify_mark_internal *__ret)
{
	const unsigned long __callno = __fs_method_fanotify_mark_internal;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct fsnotify_mark_pars), __arch_actv_rpc_stksz_alignment(struct fsnotify_mark_pars));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_fanotify_mark_internal(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, me_idx, cnode_idx, nsid, pars, new_path, srvname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_fanotify_mark_internal(int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_fanotify_mark_internal *__ret)
{
	return actvxactcall_fscall_fanotify_mark_internal(false, false, me_idx, cnode_idx, nsid, pars, new_path, srvname, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_fanotify_mark_internal(rref_t __rref, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_fanotify_mark_internal *__ret)
{
	return actvxactcapcall_fscall_fanotify_mark_internal(false, false, __rref, me_idx, cnode_idx, nsid, pars, new_path, srvname, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_fscall_fanotify_rm_watch_internal(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fanotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id, unsigned int obj_type);


extern int __actvcapcall_fscall_fanotify_rm_watch_internal(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fanotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id, unsigned int obj_type);


static inline int __attribute__((always_inline)) actvxactcall_fscall_fanotify_rm_watch_internal(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int fanotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id, unsigned int obj_type)
{
	const unsigned long __callno = __fs_method_fanotify_rm_watch_internal;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_fanotify_rm_watch_internal(rpc_info, NULL, cnode_idx, fanotify_fd, wd, nsid, index, dev_id, obj_type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_fanotify_rm_watch_internal(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int fanotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id, unsigned int obj_type)
{
	const unsigned long __callno = __fs_method_fanotify_rm_watch_internal;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_fanotify_rm_watch_internal(__rref, rpc_info, NULL, cnode_idx, fanotify_fd, wd, nsid, index, dev_id, obj_type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_fanotify_rm_watch_internal(unsigned int cnode_idx, int fanotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id, unsigned int obj_type)
{
	return actvxactcall_fscall_fanotify_rm_watch_internal(false, false, cnode_idx, fanotify_fd, wd, nsid, index, dev_id, obj_type);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_fanotify_rm_watch_internal(rref_t __rref, unsigned int cnode_idx, int fanotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id, unsigned int obj_type)
{
	return actvxactcapcall_fscall_fanotify_rm_watch_internal(false, false, __rref, cnode_idx, fanotify_fd, wd, nsid, index, dev_id, obj_type);
}

extern int __actvcall_fscall_fanotify_notify(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, int pid);


extern int __actvcapcall_fscall_fanotify_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, int pid);


static inline int __attribute__((always_inline)) actvxactcall_fscall_fanotify_notify(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, int pid, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_fanotify_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_fanotify_notify(rpc_info, ___void_buf, cnode_idx, inotify_fd, wd, event, cookie, token, pid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_fanotify_notify(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, int pid, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_fanotify_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_fanotify_notify(__rref, rpc_info, ___void_buf, cnode_idx, inotify_fd, wd, event, cookie, token, pid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_fanotify_notify(unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, int pid, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_fanotify_notify(false, false, cnode_idx, inotify_fd, wd, event, cookie, token, pid, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_fanotify_notify(rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, int pid, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_fanotify_notify(false, false, __rref, cnode_idx, inotify_fd, wd, event, cookie, token, pid, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_fanotify_destroyed(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token);


extern int __actvcapcall_fscall_fanotify_destroyed(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token);


static inline int __attribute__((always_inline)) actvxactcall_fscall_fanotify_destroyed(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	const unsigned long __callno = __fs_method_fanotify_destroyed;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_fanotify_destroyed(rpc_info, NULL, cnode_idx, inotify_fd, wd, token);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_fanotify_destroyed(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	const unsigned long __callno = __fs_method_fanotify_destroyed;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_fanotify_destroyed(__rref, rpc_info, NULL, cnode_idx, inotify_fd, wd, token);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_fanotify_destroyed(unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	return actvxactcall_fscall_fanotify_destroyed(false, false, cnode_idx, inotify_fd, wd, token);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_fanotify_destroyed(rref_t __rref, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	return actvxactcapcall_fscall_fanotify_destroyed(false, false, __rref, cnode_idx, inotify_fd, wd, token);
}

extern int __actvcall_fscall_fanotify_open(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, int fd, unsigned int flags, unsigned int mode, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_fanotify_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, int fd, unsigned int flags, unsigned int mode, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_fanotify_open(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, int fd, unsigned int flags, unsigned int mode, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_fanotify_open *__ret)
{
	const unsigned long __callno = __fs_method_fanotify_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_fanotify_open(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dfd, fd, flags, mode, cnode_idx, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_fanotify_open(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, int fd, unsigned int flags, unsigned int mode, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_fanotify_open *__ret)
{
	const unsigned long __callno = __fs_method_fanotify_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_fanotify_open(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dfd, fd, flags, mode, cnode_idx, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_fanotify_open(int dfd, int fd, unsigned int flags, unsigned int mode, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_fanotify_open *__ret)
{
	return actvxactcall_fscall_fanotify_open(false, false, dfd, fd, flags, mode, cnode_idx, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_fanotify_open(rref_t __rref, int dfd, int fd, unsigned int flags, unsigned int mode, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_fanotify_open *__ret)
{
	return actvxactcapcall_fscall_fanotify_open(false, false, __rref, dfd, fd, flags, mode, cnode_idx, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_fscall_endio_io_done(unsigned long long __rpc_info, void *__buf, unsigned long long dev_id);


extern int __actvcapcall_fscall_endio_io_done(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long dev_id);


static inline int __attribute__((always_inline)) actvxactcall_fscall_endio_io_done(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long long dev_id)
{
	const unsigned long __callno = __fs_method_endio_io_done;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_endio_io_done(rpc_info, NULL, dev_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_endio_io_done(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long long dev_id)
{
	const unsigned long __callno = __fs_method_endio_io_done;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_endio_io_done(__rref, rpc_info, NULL, dev_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_endio_io_done(unsigned long long dev_id)
{
	return actvxactcall_fscall_endio_io_done(false, false, dev_id);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_endio_io_done(rref_t __rref, unsigned long long dev_id)
{
	return actvxactcapcall_fscall_endio_io_done(false, false, __rref, dev_id);
}

extern int __actvcall_fscall_vfs_set_label(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long label);


extern int __actvcapcall_fscall_vfs_set_label(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long label);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_set_label(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long long label)
{
	const unsigned long __callno = __fs_method_vfs_set_label;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_set_label(rpc_info, NULL, fd, label);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_set_label(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long long label)
{
	const unsigned long __callno = __fs_method_vfs_set_label;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_set_label(__rref, rpc_info, NULL, fd, label);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_set_label(int fd, unsigned long long label)
{
	return actvxactcall_fscall_vfs_set_label(false, false, fd, label);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_set_label(rref_t __rref, int fd, unsigned long long label)
{
	return actvxactcapcall_fscall_vfs_set_label(false, false, __rref, fd, label);
}

extern int __actvcall_fscall_vfs_set_label_by_path(unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long label, int flag, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_set_label_by_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long label, int flag, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_set_label_by_path(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, unsigned long long label, int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_set_label_by_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_set_label_by_path(rpc_info, ___void_buf, dfd, label, flag, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_set_label_by_path(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, unsigned long long label, int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_set_label_by_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_set_label_by_path(__rref, rpc_info, ___void_buf, dfd, label, flag, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_set_label_by_path(int dfd, unsigned long long label, int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_set_label_by_path(false, false, dfd, label, flag, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_set_label_by_path(rref_t __rref, int dfd, unsigned long long label, int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_set_label_by_path(false, false, __rref, dfd, label, flag, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_get_label(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_fscall_vfs_get_label(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_get_label(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, struct __actvret_fscall_vfs_get_label *__ret)
{
	const unsigned long __callno = __fs_method_vfs_get_label;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_get_label(rpc_info, __ret, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_get_label(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, struct __actvret_fscall_vfs_get_label *__ret)
{
	const unsigned long __callno = __fs_method_vfs_get_label;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_get_label(__rref, rpc_info, __ret, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_get_label(int fd, struct __actvret_fscall_vfs_get_label *__ret)
{
	return actvxactcall_fscall_vfs_get_label(false, false, fd, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_get_label(rref_t __rref, int fd, struct __actvret_fscall_vfs_get_label *__ret)
{
	return actvxactcapcall_fscall_vfs_get_label(false, false, __rref, fd, __ret);
}

extern int __actvcall_fscall_vfs_init_audit(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_fscall_vfs_init_audit(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_init_audit(bool is_xact_fwd, bool is_xact_allow_refwd)
{
	const unsigned long __callno = __fs_method_vfs_init_audit;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_init_audit(rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_init_audit(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref)
{
	const unsigned long __callno = __fs_method_vfs_init_audit;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_init_audit(__rref, rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_init_audit(void)
{
	return actvxactcall_fscall_vfs_init_audit(false, false);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_init_audit(rref_t __rref)
{
	return actvxactcapcall_fscall_vfs_init_audit(false, false, __rref);
}

extern int __actvcall_fscall_vfs_add_audit_rule(unsigned long long __rpc_info, void *__buf, int dfd, unsigned short shm_rule_id, unsigned short shm_rule_num, unsigned int flags, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_add_audit_rule(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned short shm_rule_id, unsigned short shm_rule_num, unsigned int flags, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_add_audit_rule(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, unsigned short shm_rule_id, unsigned short shm_rule_num, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_add_audit_rule;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_add_audit_rule(rpc_info, ___void_buf, dfd, shm_rule_id, shm_rule_num, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_add_audit_rule(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, unsigned short shm_rule_id, unsigned short shm_rule_num, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_add_audit_rule;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_add_audit_rule(__rref, rpc_info, ___void_buf, dfd, shm_rule_id, shm_rule_num, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_add_audit_rule(int dfd, unsigned short shm_rule_id, unsigned short shm_rule_num, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_add_audit_rule(false, false, dfd, shm_rule_id, shm_rule_num, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_add_audit_rule(rref_t __rref, int dfd, unsigned short shm_rule_id, unsigned short shm_rule_num, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_add_audit_rule(false, false, __rref, dfd, shm_rule_id, shm_rule_num, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_del_audit_rule(unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long rule_id, unsigned int flags, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_del_audit_rule(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long rule_id, unsigned int flags, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_del_audit_rule(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, unsigned long long rule_id, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_del_audit_rule;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_del_audit_rule(rpc_info, ___void_buf, dfd, rule_id, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_del_audit_rule(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, unsigned long long rule_id, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_del_audit_rule;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_del_audit_rule(__rref, rpc_info, ___void_buf, dfd, rule_id, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_del_audit_rule(int dfd, unsigned long long rule_id, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_del_audit_rule(false, false, dfd, rule_id, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_del_audit_rule(rref_t __rref, int dfd, unsigned long long rule_id, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_del_audit_rule(false, false, __rref, dfd, rule_id, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_match_audit_watch_file(unsigned long long __rpc_info, void *__buf, unsigned long long rule_id, unsigned long long dev_id, unsigned int index);


extern int __actvcapcall_fscall_vfs_match_audit_watch_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long rule_id, unsigned long long dev_id, unsigned int index);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_match_audit_watch_file(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long long rule_id, unsigned long long dev_id, unsigned int index)
{
	const unsigned long __callno = __fs_method_vfs_match_audit_watch_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_match_audit_watch_file(rpc_info, NULL, rule_id, dev_id, index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_match_audit_watch_file(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long long rule_id, unsigned long long dev_id, unsigned int index)
{
	const unsigned long __callno = __fs_method_vfs_match_audit_watch_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_match_audit_watch_file(__rref, rpc_info, NULL, rule_id, dev_id, index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_match_audit_watch_file(unsigned long long rule_id, unsigned long long dev_id, unsigned int index)
{
	return actvxactcall_fscall_vfs_match_audit_watch_file(false, false, rule_id, dev_id, index);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_match_audit_watch_file(rref_t __rref, unsigned long long rule_id, unsigned long long dev_id, unsigned int index)
{
	return actvxactcapcall_fscall_vfs_match_audit_watch_file(false, false, __rref, rule_id, dev_id, index);
}

extern int __actvcall_fscall_vfs_match_audit_watch_dir(unsigned long long __rpc_info, void *__buf, unsigned long long rule_id, int audit_me_idx);


extern int __actvcapcall_fscall_vfs_match_audit_watch_dir(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long rule_id, int audit_me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_match_audit_watch_dir(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long long rule_id, int audit_me_idx)
{
	const unsigned long __callno = __fs_method_vfs_match_audit_watch_dir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_match_audit_watch_dir(rpc_info, NULL, rule_id, audit_me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_match_audit_watch_dir(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long long rule_id, int audit_me_idx)
{
	const unsigned long __callno = __fs_method_vfs_match_audit_watch_dir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_match_audit_watch_dir(__rref, rpc_info, NULL, rule_id, audit_me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_match_audit_watch_dir(unsigned long long rule_id, int audit_me_idx)
{
	return actvxactcall_fscall_vfs_match_audit_watch_dir(false, false, rule_id, audit_me_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_match_audit_watch_dir(rref_t __rref, unsigned long long rule_id, int audit_me_idx)
{
	return actvxactcapcall_fscall_vfs_match_audit_watch_dir(false, false, __rref, rule_id, audit_me_idx);
}

extern int __actvcall_fscall_vfs_client_init(unsigned long long __rpc_info, void *__buf, uref_t uref, char *root_srvname, int buflen);


extern int __actvcapcall_fscall_vfs_client_init(rref_t __rref, unsigned long long __rpc_info, void *__buf, uref_t uref, char *root_srvname, int buflen);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_client_init(bool is_xact_fwd, bool is_xact_allow_refwd, uref_t uref, char *root_srvname, int buflen)
{
	const unsigned long __callno = __fs_method_vfs_client_init;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_client_init(rpc_info, NULL, uref, root_srvname, buflen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_client_init(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, uref_t uref, char *root_srvname, int buflen)
{
	const unsigned long __callno = __fs_method_vfs_client_init;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_client_init(__rref, rpc_info, NULL, uref, root_srvname, buflen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_client_init(uref_t uref, char *root_srvname, int buflen)
{
	return actvxactcall_fscall_vfs_client_init(false, false, uref, root_srvname, buflen);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_client_init(rref_t __rref, uref_t uref, char *root_srvname, int buflen)
{
	return actvxactcapcall_fscall_vfs_client_init(false, false, __rref, uref, root_srvname, buflen);
}

extern int __actvcall_fscall_vfs_bind_update(unsigned long long __rpc_info, void *__buf, uref_t uref1, uref_t uref2);


extern int __actvcapcall_fscall_vfs_bind_update(rref_t __rref, unsigned long long __rpc_info, void *__buf, uref_t uref1, uref_t uref2);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_bind_update(bool is_xact_fwd, bool is_xact_allow_refwd, uref_t uref1, uref_t uref2)
{
	const unsigned long __callno = __fs_method_vfs_bind_update;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_bind_update(rpc_info, NULL, uref1, uref2);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_bind_update(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, uref_t uref1, uref_t uref2)
{
	const unsigned long __callno = __fs_method_vfs_bind_update;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_bind_update(__rref, rpc_info, NULL, uref1, uref2);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_bind_update(uref_t uref1, uref_t uref2)
{
	return actvxactcall_fscall_vfs_bind_update(false, false, uref1, uref2);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_bind_update(rref_t __rref, uref_t uref1, uref_t uref2)
{
	return actvxactcapcall_fscall_vfs_bind_update(false, false, __rref, uref1, uref2);
}

extern int __actvcall_fscall_vfs_clone(unsigned long long __rpc_info, void *__buf, int old_fd, int new_fd);


extern int __actvcapcall_fscall_vfs_clone(rref_t __rref, unsigned long long __rpc_info, void *__buf, int old_fd, int new_fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_clone(bool is_xact_fwd, bool is_xact_allow_refwd, int old_fd, int new_fd)
{
	const unsigned long __callno = __fs_method_vfs_clone;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_clone(rpc_info, NULL, old_fd, new_fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_clone(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int old_fd, int new_fd)
{
	const unsigned long __callno = __fs_method_vfs_clone;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_clone(__rref, rpc_info, NULL, old_fd, new_fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_clone(int old_fd, int new_fd)
{
	return actvxactcall_fscall_vfs_clone(false, false, old_fd, new_fd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_clone(rref_t __rref, int old_fd, int new_fd)
{
	return actvxactcapcall_fscall_vfs_clone(false, false, __rref, old_fd, new_fd);
}

extern int __actvcall_fscall_vfs_close(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_fscall_vfs_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_close(bool is_xact_fwd, bool is_xact_allow_refwd, int fd)
{
	const unsigned long __callno = __fs_method_vfs_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_close(rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_close(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd)
{
	const unsigned long __callno = __fs_method_vfs_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_close(__rref, rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_close(int fd)
{
	return actvxactcall_fscall_vfs_close(false, false, fd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_close(rref_t __rref, int fd)
{
	return actvxactcapcall_fscall_vfs_close(false, false, __rref, fd);
}

extern int __actvcall_fscall_vfs_mount(unsigned long long __rpc_info, void *__buf, int parent_fd, unsigned long long dev_id, unsigned long flags, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_mount(rref_t __rref, unsigned long long __rpc_info, void *__buf, int parent_fd, unsigned long long dev_id, unsigned long flags, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mount(bool is_xact_fwd, bool is_xact_allow_refwd, int parent_fd, unsigned long long dev_id, unsigned long flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_mount;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mount(rpc_info, ___void_buf, parent_fd, dev_id, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mount(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int parent_fd, unsigned long long dev_id, unsigned long flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_mount;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mount(__rref, rpc_info, ___void_buf, parent_fd, dev_id, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mount(int parent_fd, unsigned long long dev_id, unsigned long flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_mount(false, false, parent_fd, dev_id, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mount(rref_t __rref, int parent_fd, unsigned long long dev_id, unsigned long flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_mount(false, false, __rref, parent_fd, dev_id, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_clone_mount_entry(unsigned long long __rpc_info, void *__buf, const char *dst, unsigned int dst_len, unsigned long flags, unsigned int cnode_idx, int child_me_idx, int orig_me_idx, int orig_fd, int recurse);


extern int __actvcapcall_fscall_vfs_clone_mount_entry(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *dst, unsigned int dst_len, unsigned long flags, unsigned int cnode_idx, int child_me_idx, int orig_me_idx, int orig_fd, int recurse);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_clone_mount_entry(bool is_xact_fwd, bool is_xact_allow_refwd, const char *dst, unsigned int dst_len, unsigned long flags, unsigned int cnode_idx, int child_me_idx, int orig_me_idx, int orig_fd, int recurse)
{
	const unsigned long __callno = __fs_method_vfs_clone_mount_entry;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_clone_mount_entry(rpc_info, NULL, dst, dst_len, flags, cnode_idx, child_me_idx, orig_me_idx, orig_fd, recurse);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_clone_mount_entry(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, const char *dst, unsigned int dst_len, unsigned long flags, unsigned int cnode_idx, int child_me_idx, int orig_me_idx, int orig_fd, int recurse)
{
	const unsigned long __callno = __fs_method_vfs_clone_mount_entry;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_clone_mount_entry(__rref, rpc_info, NULL, dst, dst_len, flags, cnode_idx, child_me_idx, orig_me_idx, orig_fd, recurse);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_clone_mount_entry(const char *dst, unsigned int dst_len, unsigned long flags, unsigned int cnode_idx, int child_me_idx, int orig_me_idx, int orig_fd, int recurse)
{
	return actvxactcall_fscall_vfs_clone_mount_entry(false, false, dst, dst_len, flags, cnode_idx, child_me_idx, orig_me_idx, orig_fd, recurse);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_clone_mount_entry(rref_t __rref, const char *dst, unsigned int dst_len, unsigned long flags, unsigned int cnode_idx, int child_me_idx, int orig_me_idx, int orig_fd, int recurse)
{
	return actvxactcapcall_fscall_vfs_clone_mount_entry(false, false, __rref, dst, dst_len, flags, cnode_idx, child_me_idx, orig_me_idx, orig_fd, recurse);
}

extern int __actvcall_fscall_vfs_clone_mount_entry_from_orig_parent(unsigned long long __rpc_info, void *__buf, unsigned int nsid, int parent_me_idx, int orig_me_idx, unsigned long long dev_id, unsigned long flags);


extern int __actvcapcall_fscall_vfs_clone_mount_entry_from_orig_parent(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int nsid, int parent_me_idx, int orig_me_idx, unsigned long long dev_id, unsigned long flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_clone_mount_entry_from_orig_parent(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int nsid, int parent_me_idx, int orig_me_idx, unsigned long long dev_id, unsigned long flags, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_clone_mount_entry_from_orig_parent;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_clone_mount_entry_from_orig_parent(rpc_info, ___void_buf, nsid, parent_me_idx, orig_me_idx, dev_id, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_clone_mount_entry_from_orig_parent(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int nsid, int parent_me_idx, int orig_me_idx, unsigned long long dev_id, unsigned long flags, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_clone_mount_entry_from_orig_parent;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_clone_mount_entry_from_orig_parent(__rref, rpc_info, ___void_buf, nsid, parent_me_idx, orig_me_idx, dev_id, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_clone_mount_entry_from_orig_parent(unsigned int nsid, int parent_me_idx, int orig_me_idx, unsigned long long dev_id, unsigned long flags, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_clone_mount_entry_from_orig_parent(false, false, nsid, parent_me_idx, orig_me_idx, dev_id, flags, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_clone_mount_entry_from_orig_parent(rref_t __rref, unsigned int nsid, int parent_me_idx, int orig_me_idx, unsigned long long dev_id, unsigned long flags, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_clone_mount_entry_from_orig_parent(false, false, __rref, nsid, parent_me_idx, orig_me_idx, dev_id, flags, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(unsigned long long __rpc_info, void *__buf, unsigned int nsid, int orig_parent_me_idx, int child_me_idx);


extern int __actvcapcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int nsid, int orig_parent_me_idx, int child_me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int nsid, int orig_parent_me_idx, int child_me_idx)
{
	const unsigned long __callno = __fs_method_vfs_destroy_cloned_mount_entry_from_orig_parent;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(rpc_info, NULL, nsid, orig_parent_me_idx, child_me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int nsid, int orig_parent_me_idx, int child_me_idx)
{
	const unsigned long __callno = __fs_method_vfs_destroy_cloned_mount_entry_from_orig_parent;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(__rref, rpc_info, NULL, nsid, orig_parent_me_idx, child_me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(unsigned int nsid, int orig_parent_me_idx, int child_me_idx)
{
	return actvxactcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(false, false, nsid, orig_parent_me_idx, child_me_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(rref_t __rref, unsigned int nsid, int orig_parent_me_idx, int child_me_idx)
{
	return actvxactcapcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(false, false, __rref, nsid, orig_parent_me_idx, child_me_idx);
}

extern int __actvcall_fscall_vfs_destroy_cloned_mount_entry(unsigned long long __rpc_info, void *__buf, int me_idx);


extern int __actvcapcall_fscall_vfs_destroy_cloned_mount_entry(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_destroy_cloned_mount_entry(bool is_xact_fwd, bool is_xact_allow_refwd, int me_idx)
{
	const unsigned long __callno = __fs_method_vfs_destroy_cloned_mount_entry;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_destroy_cloned_mount_entry(rpc_info, NULL, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_destroy_cloned_mount_entry(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int me_idx)
{
	const unsigned long __callno = __fs_method_vfs_destroy_cloned_mount_entry;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_destroy_cloned_mount_entry(__rref, rpc_info, NULL, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_destroy_cloned_mount_entry(int me_idx)
{
	return actvxactcall_fscall_vfs_destroy_cloned_mount_entry(false, false, me_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_destroy_cloned_mount_entry(rref_t __rref, int me_idx)
{
	return actvxactcapcall_fscall_vfs_destroy_cloned_mount_entry(false, false, __rref, me_idx);
}

extern int __actvcall_fscall_vfs_check_mount(unsigned long long __rpc_info, void *__buf, int me_idx, int fd, int is_dir);


extern int __actvcapcall_fscall_vfs_check_mount(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, int fd, int is_dir);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_check_mount(bool is_xact_fwd, bool is_xact_allow_refwd, int me_idx, int fd, int is_dir)
{
	const unsigned long __callno = __fs_method_vfs_check_mount;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_check_mount(rpc_info, NULL, me_idx, fd, is_dir);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_check_mount(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int me_idx, int fd, int is_dir)
{
	const unsigned long __callno = __fs_method_vfs_check_mount;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_check_mount(__rref, rpc_info, NULL, me_idx, fd, is_dir);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_check_mount(int me_idx, int fd, int is_dir)
{
	return actvxactcall_fscall_vfs_check_mount(false, false, me_idx, fd, is_dir);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_check_mount(rref_t __rref, int me_idx, int fd, int is_dir)
{
	return actvxactcapcall_fscall_vfs_check_mount(false, false, __rref, me_idx, fd, is_dir);
}

extern int __actvcall_fscall_vfs_mountpoint_del_mount(unsigned long long __rpc_info, void *__buf, void *mp, int me_idx, unsigned int nsid);


extern int __actvcapcall_fscall_vfs_mountpoint_del_mount(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *mp, int me_idx, unsigned int nsid);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mountpoint_del_mount(bool is_xact_fwd, bool is_xact_allow_refwd, void *mp, int me_idx, unsigned int nsid)
{
	const unsigned long __callno = __fs_method_vfs_mountpoint_del_mount;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mountpoint_del_mount(rpc_info, NULL, mp, me_idx, nsid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mountpoint_del_mount(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *mp, int me_idx, unsigned int nsid)
{
	const unsigned long __callno = __fs_method_vfs_mountpoint_del_mount;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mountpoint_del_mount(__rref, rpc_info, NULL, mp, me_idx, nsid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mountpoint_del_mount(void *mp, int me_idx, unsigned int nsid)
{
	return actvxactcall_fscall_vfs_mountpoint_del_mount(false, false, mp, me_idx, nsid);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mountpoint_del_mount(rref_t __rref, void *mp, int me_idx, unsigned int nsid)
{
	return actvxactcapcall_fscall_vfs_mountpoint_del_mount(false, false, __rref, mp, me_idx, nsid);
}

extern int __actvcall_fscall_vfs_open(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned int cnode_idx, int dfd, int fd, unsigned int flags, unsigned int mode, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned int cnode_idx, int dfd, int fd, unsigned int flags, unsigned int mode, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_open(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int dfd, int fd, unsigned int flags, unsigned int mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_open *__ret)
{
	const unsigned long __callno = __fs_method_vfs_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_open(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, cnode_idx, dfd, fd, flags, mode, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_open(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int dfd, int fd, unsigned int flags, unsigned int mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_open *__ret)
{
	const unsigned long __callno = __fs_method_vfs_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_open(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, cnode_idx, dfd, fd, flags, mode, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_open(unsigned int cnode_idx, int dfd, int fd, unsigned int flags, unsigned int mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_open *__ret)
{
	return actvxactcall_fscall_vfs_open(false, false, cnode_idx, dfd, fd, flags, mode, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_open(rref_t __rref, unsigned int cnode_idx, int dfd, int fd, unsigned int flags, unsigned int mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_open *__ret)
{
	return actvxactcapcall_fscall_vfs_open(false, false, __rref, cnode_idx, dfd, fd, flags, mode, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_fscall_vfs_ftruncate(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long length);


extern int __actvcapcall_fscall_vfs_ftruncate(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long length);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_ftruncate(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long long length)
{
	const unsigned long __callno = __fs_method_vfs_ftruncate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_ftruncate(rpc_info, NULL, fd, length);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_ftruncate(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long long length)
{
	const unsigned long __callno = __fs_method_vfs_ftruncate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_ftruncate(__rref, rpc_info, NULL, fd, length);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_ftruncate(int fd, unsigned long long length)
{
	return actvxactcall_fscall_vfs_ftruncate(false, false, fd, length);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_ftruncate(rref_t __rref, int fd, unsigned long long length)
{
	return actvxactcapcall_fscall_vfs_ftruncate(false, false, __rref, fd, length);
}

extern int __actvcall_fscall_vfs_fstat(unsigned long long __rpc_info, void *__buf, int fd, void *st);


extern int __actvcapcall_fscall_vfs_fstat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *st);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fstat(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, void *st)
{
	const unsigned long __callno = __fs_method_vfs_fstat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fstat(rpc_info, NULL, fd, st);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fstat(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, void *st)
{
	const unsigned long __callno = __fs_method_vfs_fstat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fstat(__rref, rpc_info, NULL, fd, st);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fstat(int fd, void *st)
{
	return actvxactcall_fscall_vfs_fstat(false, false, fd, st);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fstat(rref_t __rref, int fd, void *st)
{
	return actvxactcapcall_fscall_vfs_fstat(false, false, __rref, fd, st);
}

extern int __actvcall_fscall_vfs_stat(unsigned long long __rpc_info, void *__buf, int dfd, unsigned int flag, void *st, void *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_stat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned int flag, void *st, void *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_stat(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, unsigned int flag, void *st, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_stat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_stat(rpc_info, ___void_buf, dfd, flag, st, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_stat(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, unsigned int flag, void *st, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_stat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_stat(__rref, rpc_info, ___void_buf, dfd, flag, st, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_stat(int dfd, unsigned int flag, void *st, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_stat(false, false, dfd, flag, st, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_stat(rref_t __rref, int dfd, unsigned int flag, void *st, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_stat(false, false, __rref, dfd, flag, st, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_statfs(unsigned long long __rpc_info, void *__buf, int dfd, void *stfs, void *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_statfs(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, void *stfs, void *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_statfs(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, void *stfs, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_statfs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_statfs(rpc_info, ___void_buf, dfd, stfs, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_statfs(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, void *stfs, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_statfs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_statfs(__rref, rpc_info, ___void_buf, dfd, stfs, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_statfs(int dfd, void *stfs, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_statfs(false, false, dfd, stfs, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_statfs(rref_t __rref, int dfd, void *stfs, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_statfs(false, false, __rref, dfd, stfs, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_fstatfs(unsigned long long __rpc_info, void *__buf, int fd, void *msg);


extern int __actvcapcall_fscall_vfs_fstatfs(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *msg);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fstatfs(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, void *msg)
{
	const unsigned long __callno = __fs_method_vfs_fstatfs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fstatfs(rpc_info, NULL, fd, msg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fstatfs(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, void *msg)
{
	const unsigned long __callno = __fs_method_vfs_fstatfs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fstatfs(__rref, rpc_info, NULL, fd, msg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fstatfs(int fd, void *msg)
{
	return actvxactcall_fscall_vfs_fstatfs(false, false, fd, msg);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fstatfs(rref_t __rref, int fd, void *msg)
{
	return actvxactcapcall_fscall_vfs_fstatfs(false, false, __rref, fd, msg);
}

extern int __actvcall_fscall_vfs_fsync(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_fscall_vfs_fsync(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fsync(bool is_xact_fwd, bool is_xact_allow_refwd, int fd)
{
	const unsigned long __callno = __fs_method_vfs_fsync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fsync(rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fsync(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd)
{
	const unsigned long __callno = __fs_method_vfs_fsync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fsync(__rref, rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fsync(int fd)
{
	return actvxactcall_fscall_vfs_fsync(false, false, fd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fsync(rref_t __rref, int fd)
{
	return actvxactcapcall_fscall_vfs_fsync(false, false, __rref, fd);
}

extern int __actvcall_fscall_vfs_unmount(unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags, char *msg, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_unmount(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags, char *msg, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_unmount(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int flags, char *msg, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_unmount;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_unmount(rpc_info, ___void_buf, fd, flags, msg, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_unmount(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int flags, char *msg, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_unmount;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_unmount(__rref, rpc_info, ___void_buf, fd, flags, msg, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_unmount(int fd, unsigned int flags, char *msg, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_unmount(false, false, fd, flags, msg, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_unmount(rref_t __rref, int fd, unsigned int flags, char *msg, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_unmount(false, false, __rref, fd, flags, msg, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_unmount_from_server(unsigned long long __rpc_info, void *__buf, int me_idx, uint32_t nsid, unsigned int flags);


extern int __actvcapcall_fscall_vfs_unmount_from_server(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, uint32_t nsid, unsigned int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_unmount_from_server(bool is_xact_fwd, bool is_xact_allow_refwd, int me_idx, uint32_t nsid, unsigned int flags)
{
	const unsigned long __callno = __fs_method_vfs_unmount_from_server;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint32_t), __arch_actv_rpc_stksz_alignment(uint32_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_unmount_from_server(rpc_info, NULL, me_idx, nsid, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_unmount_from_server(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int me_idx, uint32_t nsid, unsigned int flags)
{
	const unsigned long __callno = __fs_method_vfs_unmount_from_server;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint32_t), __arch_actv_rpc_stksz_alignment(uint32_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_unmount_from_server(__rref, rpc_info, NULL, me_idx, nsid, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_unmount_from_server(int me_idx, uint32_t nsid, unsigned int flags)
{
	return actvxactcall_fscall_vfs_unmount_from_server(false, false, me_idx, nsid, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_unmount_from_server(rref_t __rref, int me_idx, uint32_t nsid, unsigned int flags)
{
	return actvxactcapcall_fscall_vfs_unmount_from_server(false, false, __rref, me_idx, nsid, flags);
}

extern int __actvcall_fscall_vfs_unmount_child(unsigned long long __rpc_info, void *__buf, int me_idx, uint32_t nsid, unsigned int flags);


extern int __actvcapcall_fscall_vfs_unmount_child(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, uint32_t nsid, unsigned int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_unmount_child(bool is_xact_fwd, bool is_xact_allow_refwd, int me_idx, uint32_t nsid, unsigned int flags)
{
	const unsigned long __callno = __fs_method_vfs_unmount_child;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint32_t), __arch_actv_rpc_stksz_alignment(uint32_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_unmount_child(rpc_info, NULL, me_idx, nsid, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_unmount_child(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int me_idx, uint32_t nsid, unsigned int flags)
{
	const unsigned long __callno = __fs_method_vfs_unmount_child;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint32_t), __arch_actv_rpc_stksz_alignment(uint32_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_unmount_child(__rref, rpc_info, NULL, me_idx, nsid, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_unmount_child(int me_idx, uint32_t nsid, unsigned int flags)
{
	return actvxactcall_fscall_vfs_unmount_child(false, false, me_idx, nsid, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_unmount_child(rref_t __rref, int me_idx, uint32_t nsid, unsigned int flags)
{
	return actvxactcapcall_fscall_vfs_unmount_child(false, false, __rref, me_idx, nsid, flags);
}

extern int __actvcall_fscall_vfs_truncate(unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long length, void *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_truncate(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long length, void *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_truncate(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, unsigned long long length, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_truncate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_truncate(rpc_info, ___void_buf, dfd, length, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_truncate(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, unsigned long long length, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_truncate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_truncate(__rref, rpc_info, ___void_buf, dfd, length, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_truncate(int dfd, unsigned long long length, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_truncate(false, false, dfd, length, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_truncate(rref_t __rref, int dfd, unsigned long long length, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_truncate(false, false, __rref, dfd, length, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_fs_fork(unsigned long long __rpc_info, void *__buf, int fd, unsigned int idx_src, unsigned int idx_dst);


extern int __actvcapcall_fscall_vfs_fs_fork(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int idx_src, unsigned int idx_dst);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fs_fork(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int idx_src, unsigned int idx_dst)
{
	const unsigned long __callno = __fs_method_vfs_fs_fork;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fs_fork(rpc_info, NULL, fd, idx_src, idx_dst);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fs_fork(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int idx_src, unsigned int idx_dst)
{
	const unsigned long __callno = __fs_method_vfs_fs_fork;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fs_fork(__rref, rpc_info, NULL, fd, idx_src, idx_dst);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fs_fork(int fd, unsigned int idx_src, unsigned int idx_dst)
{
	return actvxactcall_fscall_vfs_fs_fork(false, false, fd, idx_src, idx_dst);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fs_fork(rref_t __rref, int fd, unsigned int idx_src, unsigned int idx_dst)
{
	return actvxactcapcall_fscall_vfs_fs_fork(false, false, __rref, fd, idx_src, idx_dst);
}

extern int __actvcall_fscall_vfs_query_info(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx);


extern int __actvcapcall_fscall_vfs_query_info(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_query_info(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int cnode_idx, struct __actvret_fscall_vfs_query_info *__ret)
{
	const unsigned long __callno = __fs_method_vfs_query_info;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_query_info(rpc_info, __ret, fd, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_query_info(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int cnode_idx, struct __actvret_fscall_vfs_query_info *__ret)
{
	const unsigned long __callno = __fs_method_vfs_query_info;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_query_info(__rref, rpc_info, __ret, fd, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_query_info(int fd, unsigned int cnode_idx, struct __actvret_fscall_vfs_query_info *__ret)
{
	return actvxactcall_fscall_vfs_query_info(false, false, fd, cnode_idx, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_query_info(rref_t __rref, int fd, unsigned int cnode_idx, struct __actvret_fscall_vfs_query_info *__ret)
{
	return actvxactcapcall_fscall_vfs_query_info(false, false, __rref, fd, cnode_idx, __ret);
}

extern int __actvcall_fscall_vfs_lseek(unsigned long long __rpc_info, void *__buf, int fd, long long offset, int whence);


extern int __actvcapcall_fscall_vfs_lseek(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long offset, int whence);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_lseek(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, long long offset, int whence, struct __actvret_fscall_vfs_lseek *__ret)
{
	const unsigned long __callno = __fs_method_vfs_lseek;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_lseek(rpc_info, __ret, fd, offset, whence);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_lseek(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, long long offset, int whence, struct __actvret_fscall_vfs_lseek *__ret)
{
	const unsigned long __callno = __fs_method_vfs_lseek;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_lseek(__rref, rpc_info, __ret, fd, offset, whence);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_lseek(int fd, long long offset, int whence, struct __actvret_fscall_vfs_lseek *__ret)
{
	return actvxactcall_fscall_vfs_lseek(false, false, fd, offset, whence, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_lseek(rref_t __rref, int fd, long long offset, int whence, struct __actvret_fscall_vfs_lseek *__ret)
{
	return actvxactcapcall_fscall_vfs_lseek(false, false, __rref, fd, offset, whence, __ret);
}

extern int __actvcall_fscall_vfs_trans(unsigned long long __rpc_info, void *__buf, int fd, const char *data, int pos, size_t nbyte);


extern int __actvcapcall_fscall_vfs_trans(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const char *data, int pos, size_t nbyte);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_trans(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const char *data, int pos, size_t nbyte)
{
	const unsigned long __callno = __fs_method_vfs_trans;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_trans(rpc_info, NULL, fd, data, pos, nbyte);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_trans(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const char *data, int pos, size_t nbyte)
{
	const unsigned long __callno = __fs_method_vfs_trans;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_trans(__rref, rpc_info, NULL, fd, data, pos, nbyte);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_trans(int fd, const char *data, int pos, size_t nbyte)
{
	return actvxactcall_fscall_vfs_trans(false, false, fd, data, pos, nbyte);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_trans(rref_t __rref, int fd, const char *data, int pos, size_t nbyte)
{
	return actvxactcapcall_fscall_vfs_trans(false, false, __rref, fd, data, pos, nbyte);
}

extern int __actvcall_fscall_vfs_pipe2(unsigned long long __rpc_info, void *__buf, int read_fd, int write_fd, int flags);


extern int __actvcapcall_fscall_vfs_pipe2(rref_t __rref, unsigned long long __rpc_info, void *__buf, int read_fd, int write_fd, int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_pipe2(bool is_xact_fwd, bool is_xact_allow_refwd, int read_fd, int write_fd, int flags, struct __actvret_fscall_vfs_pipe2 *__ret)
{
	const unsigned long __callno = __fs_method_vfs_pipe2;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_pipe2(rpc_info, __ret, read_fd, write_fd, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_pipe2(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int read_fd, int write_fd, int flags, struct __actvret_fscall_vfs_pipe2 *__ret)
{
	const unsigned long __callno = __fs_method_vfs_pipe2;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_pipe2(__rref, rpc_info, __ret, read_fd, write_fd, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_pipe2(int read_fd, int write_fd, int flags, struct __actvret_fscall_vfs_pipe2 *__ret)
{
	return actvxactcall_fscall_vfs_pipe2(false, false, read_fd, write_fd, flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_pipe2(rref_t __rref, int read_fd, int write_fd, int flags, struct __actvret_fscall_vfs_pipe2 *__ret)
{
	return actvxactcapcall_fscall_vfs_pipe2(false, false, __rref, read_fd, write_fd, flags, __ret);
}

extern int __actvcall_fscall_vfs_tee(unsigned long long __rpc_info, void *__buf, int fd_in, int fd_out, unsigned int len, unsigned int flags);


extern int __actvcapcall_fscall_vfs_tee(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd_in, int fd_out, unsigned int len, unsigned int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_tee(bool is_xact_fwd, bool is_xact_allow_refwd, int fd_in, int fd_out, unsigned int len, unsigned int flags)
{
	const unsigned long __callno = __fs_method_vfs_tee;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_tee(rpc_info, NULL, fd_in, fd_out, len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_tee(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd_in, int fd_out, unsigned int len, unsigned int flags)
{
	const unsigned long __callno = __fs_method_vfs_tee;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_tee(__rref, rpc_info, NULL, fd_in, fd_out, len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_tee(int fd_in, int fd_out, unsigned int len, unsigned int flags)
{
	return actvxactcall_fscall_vfs_tee(false, false, fd_in, fd_out, len, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_tee(rref_t __rref, int fd_in, int fd_out, unsigned int len, unsigned int flags)
{
	return actvxactcapcall_fscall_vfs_tee(false, false, __rref, fd_in, fd_out, len, flags);
}

extern int __actvcall_fscall_vfs_splice(unsigned long long __rpc_info, void *__buf, int fd_in, long long *offset_in, int fd_out, const char *pathname, int multi_srvs, long long *offset_out, unsigned long len, unsigned int flags);


extern int __actvcapcall_fscall_vfs_splice(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd_in, long long *offset_in, int fd_out, const char *pathname, int multi_srvs, long long *offset_out, unsigned long len, unsigned int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_splice(bool is_xact_fwd, bool is_xact_allow_refwd, int fd_in, long long *offset_in, int fd_out, const char *pathname, int multi_srvs, long long *offset_out, unsigned long len, unsigned int flags, struct __actvret_fscall_vfs_splice *__ret)
{
	const unsigned long __callno = __fs_method_vfs_splice;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long*), __arch_actv_rpc_stksz_alignment(long long*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long*), __arch_actv_rpc_stksz_alignment(long long*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_splice(rpc_info, __ret, fd_in, offset_in, fd_out, pathname, multi_srvs, offset_out, len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_splice(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd_in, long long *offset_in, int fd_out, const char *pathname, int multi_srvs, long long *offset_out, unsigned long len, unsigned int flags, struct __actvret_fscall_vfs_splice *__ret)
{
	const unsigned long __callno = __fs_method_vfs_splice;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long*), __arch_actv_rpc_stksz_alignment(long long*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long*), __arch_actv_rpc_stksz_alignment(long long*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_splice(__rref, rpc_info, __ret, fd_in, offset_in, fd_out, pathname, multi_srvs, offset_out, len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_splice(int fd_in, long long *offset_in, int fd_out, const char *pathname, int multi_srvs, long long *offset_out, unsigned long len, unsigned int flags, struct __actvret_fscall_vfs_splice *__ret)
{
	return actvxactcall_fscall_vfs_splice(false, false, fd_in, offset_in, fd_out, pathname, multi_srvs, offset_out, len, flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_splice(rref_t __rref, int fd_in, long long *offset_in, int fd_out, const char *pathname, int multi_srvs, long long *offset_out, unsigned long len, unsigned int flags, struct __actvret_fscall_vfs_splice *__ret)
{
	return actvxactcapcall_fscall_vfs_splice(false, false, __rref, fd_in, offset_in, fd_out, pathname, multi_srvs, offset_out, len, flags, __ret);
}

extern int __actvcall_fscall_vfs_do_splice_srvs(unsigned long long __rpc_info, void *__buf, int fd, long long pos, const char *buf, unsigned long len);


extern int __actvcapcall_fscall_vfs_do_splice_srvs(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long pos, const char *buf, unsigned long len);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_do_splice_srvs(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, long long pos, const char *buf, unsigned long len, struct __actvret_fscall_vfs_do_splice_srvs *__ret)
{
	const unsigned long __callno = __fs_method_vfs_do_splice_srvs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_do_splice_srvs(rpc_info, __ret, fd, pos, buf, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_do_splice_srvs(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, long long pos, const char *buf, unsigned long len, struct __actvret_fscall_vfs_do_splice_srvs *__ret)
{
	const unsigned long __callno = __fs_method_vfs_do_splice_srvs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_do_splice_srvs(__rref, rpc_info, __ret, fd, pos, buf, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_do_splice_srvs(int fd, long long pos, const char *buf, unsigned long len, struct __actvret_fscall_vfs_do_splice_srvs *__ret)
{
	return actvxactcall_fscall_vfs_do_splice_srvs(false, false, fd, pos, buf, len, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_do_splice_srvs(rref_t __rref, int fd, long long pos, const char *buf, unsigned long len, struct __actvret_fscall_vfs_do_splice_srvs *__ret)
{
	return actvxactcapcall_fscall_vfs_do_splice_srvs(false, false, __rref, fd, pos, buf, len, __ret);
}

extern int __actvcall_fscall_vfs_revoke_process(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx);


extern int __actvcapcall_fscall_vfs_revoke_process(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_revoke_process(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_revoke_process;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_revoke_process(rpc_info, NULL, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_revoke_process(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_revoke_process;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_revoke_process(__rref, rpc_info, NULL, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_revoke_process(unsigned int cnode_idx)
{
	return actvxactcall_fscall_vfs_revoke_process(false, false, cnode_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_revoke_process(rref_t __rref, unsigned int cnode_idx)
{
	return actvxactcapcall_fscall_vfs_revoke_process(false, false, __rref, cnode_idx);
}

extern int __actvcall_fscall_vfs_setrlimit(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long rlim_cur, unsigned long long rlim_max, unsigned int type);


extern int __actvcapcall_fscall_vfs_setrlimit(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long rlim_cur, unsigned long long rlim_max, unsigned int type);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_setrlimit(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, unsigned long long rlim_cur, unsigned long long rlim_max, unsigned int type)
{
	const unsigned long __callno = __fs_method_vfs_setrlimit;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_setrlimit(rpc_info, NULL, cnode_idx, rlim_cur, rlim_max, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_setrlimit(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, unsigned long long rlim_cur, unsigned long long rlim_max, unsigned int type)
{
	const unsigned long __callno = __fs_method_vfs_setrlimit;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_setrlimit(__rref, rpc_info, NULL, cnode_idx, rlim_cur, rlim_max, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_setrlimit(unsigned int cnode_idx, unsigned long long rlim_cur, unsigned long long rlim_max, unsigned int type)
{
	return actvxactcall_fscall_vfs_setrlimit(false, false, cnode_idx, rlim_cur, rlim_max, type);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_setrlimit(rref_t __rref, unsigned int cnode_idx, unsigned long long rlim_cur, unsigned long long rlim_max, unsigned int type)
{
	return actvxactcapcall_fscall_vfs_setrlimit(false, false, __rref, cnode_idx, rlim_cur, rlim_max, type);
}

extern int __actvcall_fscall_vfs_get_ns(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned int oldid, unsigned int newid, int flags);


extern int __actvcapcall_fscall_vfs_get_ns(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned int oldid, unsigned int newid, int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_get_ns(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, unsigned int oldid, unsigned int newid, int flags, struct __actvret_fscall_vfs_get_ns *__ret)
{
	const unsigned long __callno = __fs_method_vfs_get_ns;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_get_ns(rpc_info, __ret, cnode_idx, oldid, newid, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_get_ns(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, unsigned int oldid, unsigned int newid, int flags, struct __actvret_fscall_vfs_get_ns *__ret)
{
	const unsigned long __callno = __fs_method_vfs_get_ns;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_get_ns(__rref, rpc_info, __ret, cnode_idx, oldid, newid, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_get_ns(unsigned int cnode_idx, unsigned int oldid, unsigned int newid, int flags, struct __actvret_fscall_vfs_get_ns *__ret)
{
	return actvxactcall_fscall_vfs_get_ns(false, false, cnode_idx, oldid, newid, flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_get_ns(rref_t __rref, unsigned int cnode_idx, unsigned int oldid, unsigned int newid, int flags, struct __actvret_fscall_vfs_get_ns *__ret)
{
	return actvxactcapcall_fscall_vfs_get_ns(false, false, __rref, cnode_idx, oldid, newid, flags, __ret);
}

extern int __actvcall_fscall_vfs_put_ns(unsigned long long __rpc_info, void *__buf, unsigned int nsid, int me_idx, int flags);


extern int __actvcapcall_fscall_vfs_put_ns(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int nsid, int me_idx, int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_put_ns(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int nsid, int me_idx, int flags)
{
	const unsigned long __callno = __fs_method_vfs_put_ns;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_put_ns(rpc_info, NULL, nsid, me_idx, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_put_ns(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int nsid, int me_idx, int flags)
{
	const unsigned long __callno = __fs_method_vfs_put_ns;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_put_ns(__rref, rpc_info, NULL, nsid, me_idx, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_put_ns(unsigned int nsid, int me_idx, int flags)
{
	return actvxactcall_fscall_vfs_put_ns(false, false, nsid, me_idx, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_put_ns(rref_t __rref, unsigned int nsid, int me_idx, int flags)
{
	return actvxactcapcall_fscall_vfs_put_ns(false, false, __rref, nsid, me_idx, flags);
}

extern int __actvcall_fscall_vfs_init_eventfd(unsigned long long __rpc_info, void *__buf, int fd, unsigned int count, int flags);


extern int __actvcapcall_fscall_vfs_init_eventfd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int count, int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_init_eventfd(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int count, int flags)
{
	const unsigned long __callno = __fs_method_vfs_init_eventfd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_init_eventfd(rpc_info, NULL, fd, count, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_init_eventfd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int count, int flags)
{
	const unsigned long __callno = __fs_method_vfs_init_eventfd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_init_eventfd(__rref, rpc_info, NULL, fd, count, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_init_eventfd(int fd, unsigned int count, int flags)
{
	return actvxactcall_fscall_vfs_init_eventfd(false, false, fd, count, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_init_eventfd(rref_t __rref, int fd, unsigned int count, int flags)
{
	return actvxactcapcall_fscall_vfs_init_eventfd(false, false, __rref, fd, count, flags);
}

extern int __actvcall_fscall_vfs_write_eventfd(unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t buf_len, unsigned int cnode_idx);


extern int __actvcapcall_fscall_vfs_write_eventfd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t buf_len, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_write_eventfd(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *buf, size_t buf_len, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_write_eventfd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_write_eventfd(rpc_info, NULL, fd, buf, buf_len, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_write_eventfd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *buf, size_t buf_len, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_write_eventfd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_write_eventfd(__rref, rpc_info, NULL, fd, buf, buf_len, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_write_eventfd(int fd, const void *buf, size_t buf_len, unsigned int cnode_idx)
{
	return actvxactcall_fscall_vfs_write_eventfd(false, false, fd, buf, buf_len, cnode_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_write_eventfd(rref_t __rref, int fd, const void *buf, size_t buf_len, unsigned int cnode_idx)
{
	return actvxactcapcall_fscall_vfs_write_eventfd(false, false, __rref, fd, buf, buf_len, cnode_idx);
}

extern int __actvcall_fscall_vfs_timerfd_create(unsigned long long __rpc_info, void *__buf, int fd, int clockid, int flags);


extern int __actvcapcall_fscall_vfs_timerfd_create(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int clockid, int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_timerfd_create(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int clockid, int flags)
{
	const unsigned long __callno = __fs_method_vfs_timerfd_create;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_timerfd_create(rpc_info, NULL, fd, clockid, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_timerfd_create(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int clockid, int flags)
{
	const unsigned long __callno = __fs_method_vfs_timerfd_create;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_timerfd_create(__rref, rpc_info, NULL, fd, clockid, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_timerfd_create(int fd, int clockid, int flags)
{
	return actvxactcall_fscall_vfs_timerfd_create(false, false, fd, clockid, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_timerfd_create(rref_t __rref, int fd, int clockid, int flags)
{
	return actvxactcapcall_fscall_vfs_timerfd_create(false, false, __rref, fd, clockid, flags);
}

extern int __actvcall_fscall_vfs_timerfd_settime(unsigned long long __rpc_info, void *__buf, int fd, int flags, time_t it_inval_sec, long it_inval_nsec, time_t it_val_sec, long it_val_nsec);


extern int __actvcapcall_fscall_vfs_timerfd_settime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int flags, time_t it_inval_sec, long it_inval_nsec, time_t it_val_sec, long it_val_nsec);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_timerfd_settime(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int flags, time_t it_inval_sec, long it_inval_nsec, time_t it_val_sec, long it_val_nsec, struct __actvret_fscall_vfs_timerfd_settime *__ret)
{
	const unsigned long __callno = __fs_method_vfs_timerfd_settime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(time_t), __arch_actv_rpc_stksz_alignment(time_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long), __arch_actv_rpc_stksz_alignment(long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(time_t), __arch_actv_rpc_stksz_alignment(time_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long), __arch_actv_rpc_stksz_alignment(long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_timerfd_settime(rpc_info, __ret, fd, flags, it_inval_sec, it_inval_nsec, it_val_sec, it_val_nsec);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_timerfd_settime(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int flags, time_t it_inval_sec, long it_inval_nsec, time_t it_val_sec, long it_val_nsec, struct __actvret_fscall_vfs_timerfd_settime *__ret)
{
	const unsigned long __callno = __fs_method_vfs_timerfd_settime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(time_t), __arch_actv_rpc_stksz_alignment(time_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long), __arch_actv_rpc_stksz_alignment(long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(time_t), __arch_actv_rpc_stksz_alignment(time_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long), __arch_actv_rpc_stksz_alignment(long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_timerfd_settime(__rref, rpc_info, __ret, fd, flags, it_inval_sec, it_inval_nsec, it_val_sec, it_val_nsec);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_timerfd_settime(int fd, int flags, time_t it_inval_sec, long it_inval_nsec, time_t it_val_sec, long it_val_nsec, struct __actvret_fscall_vfs_timerfd_settime *__ret)
{
	return actvxactcall_fscall_vfs_timerfd_settime(false, false, fd, flags, it_inval_sec, it_inval_nsec, it_val_sec, it_val_nsec, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_timerfd_settime(rref_t __rref, int fd, int flags, time_t it_inval_sec, long it_inval_nsec, time_t it_val_sec, long it_val_nsec, struct __actvret_fscall_vfs_timerfd_settime *__ret)
{
	return actvxactcapcall_fscall_vfs_timerfd_settime(false, false, __rref, fd, flags, it_inval_sec, it_inval_nsec, it_val_sec, it_val_nsec, __ret);
}

extern int __actvcall_fscall_vfs_timerfd_gettime(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_fscall_vfs_timerfd_gettime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_timerfd_gettime(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, struct __actvret_fscall_vfs_timerfd_gettime *__ret)
{
	const unsigned long __callno = __fs_method_vfs_timerfd_gettime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_timerfd_gettime(rpc_info, __ret, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_timerfd_gettime(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, struct __actvret_fscall_vfs_timerfd_gettime *__ret)
{
	const unsigned long __callno = __fs_method_vfs_timerfd_gettime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_timerfd_gettime(__rref, rpc_info, __ret, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_timerfd_gettime(int fd, struct __actvret_fscall_vfs_timerfd_gettime *__ret)
{
	return actvxactcall_fscall_vfs_timerfd_gettime(false, false, fd, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_timerfd_gettime(rref_t __rref, int fd, struct __actvret_fscall_vfs_timerfd_gettime *__ret)
{
	return actvxactcapcall_fscall_vfs_timerfd_gettime(false, false, __rref, fd, __ret);
}

extern int __actvcall_fscall_vfs_open_exec(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, int sys_fd, unsigned int flags, unsigned int pcnode_idx, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_open_exec(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, int sys_fd, unsigned int flags, unsigned int pcnode_idx, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_open_exec(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, int sys_fd, unsigned int flags, unsigned int pcnode_idx, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_open_exec *__ret)
{
	const unsigned long __callno = __fs_method_vfs_open_exec;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_open_exec(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dfd, sys_fd, flags, pcnode_idx, cnode_idx, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_open_exec(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, int sys_fd, unsigned int flags, unsigned int pcnode_idx, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_open_exec *__ret)
{
	const unsigned long __callno = __fs_method_vfs_open_exec;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_open_exec(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dfd, sys_fd, flags, pcnode_idx, cnode_idx, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_open_exec(int dfd, int sys_fd, unsigned int flags, unsigned int pcnode_idx, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_open_exec *__ret)
{
	return actvxactcall_fscall_vfs_open_exec(false, false, dfd, sys_fd, flags, pcnode_idx, cnode_idx, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_open_exec(rref_t __rref, int dfd, int sys_fd, unsigned int flags, unsigned int pcnode_idx, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_open_exec *__ret)
{
	return actvxactcapcall_fscall_vfs_open_exec(false, false, __rref, dfd, sys_fd, flags, pcnode_idx, cnode_idx, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_fscall_vfs_close_exec(unsigned long long __rpc_info, void *__buf, int sys_rfd, unsigned int cnode_idx, int uapp_rfd);


extern int __actvcapcall_fscall_vfs_close_exec(rref_t __rref, unsigned long long __rpc_info, void *__buf, int sys_rfd, unsigned int cnode_idx, int uapp_rfd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_close_exec(bool is_xact_fwd, bool is_xact_allow_refwd, int sys_rfd, unsigned int cnode_idx, int uapp_rfd)
{
	const unsigned long __callno = __fs_method_vfs_close_exec;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_close_exec(rpc_info, NULL, sys_rfd, cnode_idx, uapp_rfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_close_exec(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int sys_rfd, unsigned int cnode_idx, int uapp_rfd)
{
	const unsigned long __callno = __fs_method_vfs_close_exec;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_close_exec(__rref, rpc_info, NULL, sys_rfd, cnode_idx, uapp_rfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_close_exec(int sys_rfd, unsigned int cnode_idx, int uapp_rfd)
{
	return actvxactcall_fscall_vfs_close_exec(false, false, sys_rfd, cnode_idx, uapp_rfd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_close_exec(rref_t __rref, int sys_rfd, unsigned int cnode_idx, int uapp_rfd)
{
	return actvxactcapcall_fscall_vfs_close_exec(false, false, __rref, sys_rfd, cnode_idx, uapp_rfd);
}

extern int __actvcall_fscall_vfs_set_elf_file(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int sys_rfd);


extern int __actvcapcall_fscall_vfs_set_elf_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int sys_rfd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_set_elf_file(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int sys_rfd)
{
	const unsigned long __callno = __fs_method_vfs_set_elf_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_set_elf_file(rpc_info, NULL, cnode_idx, sys_rfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_set_elf_file(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int sys_rfd)
{
	const unsigned long __callno = __fs_method_vfs_set_elf_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_set_elf_file(__rref, rpc_info, NULL, cnode_idx, sys_rfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_set_elf_file(unsigned int cnode_idx, int sys_rfd)
{
	return actvxactcall_fscall_vfs_set_elf_file(false, false, cnode_idx, sys_rfd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_set_elf_file(rref_t __rref, unsigned int cnode_idx, int sys_rfd)
{
	return actvxactcapcall_fscall_vfs_set_elf_file(false, false, __rref, cnode_idx, sys_rfd);
}

extern int __actvcall_fscall_vfs_ioctl(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cmd, unsigned long arg);


extern int __actvcapcall_fscall_vfs_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cmd, unsigned long arg);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int cmd, unsigned long arg)
{
	const unsigned long __callno = __fs_method_vfs_ioctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_ioctl(rpc_info, NULL, fd, cmd, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int cmd, unsigned long arg)
{
	const unsigned long __callno = __fs_method_vfs_ioctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_ioctl(__rref, rpc_info, NULL, fd, cmd, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_ioctl(int fd, unsigned int cmd, unsigned long arg)
{
	return actvxactcall_fscall_vfs_ioctl(false, false, fd, cmd, arg);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_ioctl(rref_t __rref, int fd, unsigned int cmd, unsigned long arg)
{
	return actvxactcapcall_fscall_vfs_ioctl(false, false, __rref, fd, cmd, arg);
}

extern int __actvcall_fscall_vfs_read(unsigned long long __rpc_info, void *__buf, int fd, long long pos, size_t msg_len, void *buf);


extern int __actvcapcall_fscall_vfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long pos, size_t msg_len, void *buf);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, long long pos, size_t msg_len, void *buf, struct __actvret_fscall_vfs_read *__ret)
{
	const unsigned long __callno = __fs_method_vfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_read(rpc_info, __ret, fd, pos, msg_len, buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, long long pos, size_t msg_len, void *buf, struct __actvret_fscall_vfs_read *__ret)
{
	const unsigned long __callno = __fs_method_vfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_read(__rref, rpc_info, __ret, fd, pos, msg_len, buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_read(int fd, long long pos, size_t msg_len, void *buf, struct __actvret_fscall_vfs_read *__ret)
{
	return actvxactcall_fscall_vfs_read(false, false, fd, pos, msg_len, buf, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_read(rref_t __rref, int fd, long long pos, size_t msg_len, void *buf, struct __actvret_fscall_vfs_read *__ret)
{
	return actvxactcapcall_fscall_vfs_read(false, false, __rref, fd, pos, msg_len, buf, __ret);
}

extern int __actvcall_fscall_vfs_readv(unsigned long long __rpc_info, void *__buf, int fd, const void *vec, int vlen, long long pos);


extern int __actvcapcall_fscall_vfs_readv(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *vec, int vlen, long long pos);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_readv(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *vec, int vlen, long long pos, struct __actvret_fscall_vfs_readv *__ret)
{
	const unsigned long __callno = __fs_method_vfs_readv;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_readv(rpc_info, __ret, fd, vec, vlen, pos);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_readv(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *vec, int vlen, long long pos, struct __actvret_fscall_vfs_readv *__ret)
{
	const unsigned long __callno = __fs_method_vfs_readv;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_readv(__rref, rpc_info, __ret, fd, vec, vlen, pos);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_readv(int fd, const void *vec, int vlen, long long pos, struct __actvret_fscall_vfs_readv *__ret)
{
	return actvxactcall_fscall_vfs_readv(false, false, fd, vec, vlen, pos, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_readv(rref_t __rref, int fd, const void *vec, int vlen, long long pos, struct __actvret_fscall_vfs_readv *__ret)
{
	return actvxactcapcall_fscall_vfs_readv(false, false, __rref, fd, vec, vlen, pos, __ret);
}

extern int __actvcall_fscall_vfs_getcwd(unsigned long long __rpc_info, void *__buf, char *buf, size_t size);


extern int __actvcapcall_fscall_vfs_getcwd(rref_t __rref, unsigned long long __rpc_info, void *__buf, char *buf, size_t size);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_getcwd(bool is_xact_fwd, bool is_xact_allow_refwd, char *buf, size_t size)
{
	const unsigned long __callno = __fs_method_vfs_getcwd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_getcwd(rpc_info, NULL, buf, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_getcwd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, char *buf, size_t size)
{
	const unsigned long __callno = __fs_method_vfs_getcwd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_getcwd(__rref, rpc_info, NULL, buf, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_getcwd(char *buf, size_t size)
{
	return actvxactcall_fscall_vfs_getcwd(false, false, buf, size);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_getcwd(rref_t __rref, char *buf, size_t size)
{
	return actvxactcapcall_fscall_vfs_getcwd(false, false, __rref, buf, size);
}

extern int __actvcall_fscall_vfs_get_process_cwdrootexe(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned int root_cnode, int type, char *buf);


extern int __actvcapcall_fscall_vfs_get_process_cwdrootexe(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned int root_cnode, int type, char *buf);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_get_process_cwdrootexe(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, unsigned int root_cnode, int type, char *buf)
{
	const unsigned long __callno = __fs_method_vfs_get_process_cwdrootexe;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_get_process_cwdrootexe(rpc_info, NULL, cnode_idx, root_cnode, type, buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_get_process_cwdrootexe(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, unsigned int root_cnode, int type, char *buf)
{
	const unsigned long __callno = __fs_method_vfs_get_process_cwdrootexe;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_get_process_cwdrootexe(__rref, rpc_info, NULL, cnode_idx, root_cnode, type, buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_get_process_cwdrootexe(unsigned int cnode_idx, unsigned int root_cnode, int type, char *buf)
{
	return actvxactcall_fscall_vfs_get_process_cwdrootexe(false, false, cnode_idx, root_cnode, type, buf);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_get_process_cwdrootexe(rref_t __rref, unsigned int cnode_idx, unsigned int root_cnode, int type, char *buf)
{
	return actvxactcapcall_fscall_vfs_get_process_cwdrootexe(false, false, __rref, cnode_idx, root_cnode, type, buf);
}

extern int __actvcall_fscall_vfs_readdir(unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t size);


extern int __actvcapcall_fscall_vfs_readdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t size);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_readdir(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, void *buf, size_t size)
{
	const unsigned long __callno = __fs_method_vfs_readdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_readdir(rpc_info, NULL, fd, buf, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_readdir(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, void *buf, size_t size)
{
	const unsigned long __callno = __fs_method_vfs_readdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_readdir(__rref, rpc_info, NULL, fd, buf, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_readdir(int fd, void *buf, size_t size)
{
	return actvxactcall_fscall_vfs_readdir(false, false, fd, buf, size);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_readdir(rref_t __rref, int fd, void *buf, size_t size)
{
	return actvxactcapcall_fscall_vfs_readdir(false, false, __rref, fd, buf, size);
}

extern int __actvcall_fscall_vfs_write(unsigned long long __rpc_info, void *__buf, int fd, long long pos, const void *buf, size_t buf_len);


extern int __actvcapcall_fscall_vfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long pos, const void *buf, size_t buf_len);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, long long pos, const void *buf, size_t buf_len, struct __actvret_fscall_vfs_write *__ret)
{
	const unsigned long __callno = __fs_method_vfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_write(rpc_info, __ret, fd, pos, buf, buf_len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, long long pos, const void *buf, size_t buf_len, struct __actvret_fscall_vfs_write *__ret)
{
	const unsigned long __callno = __fs_method_vfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_write(__rref, rpc_info, __ret, fd, pos, buf, buf_len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_write(int fd, long long pos, const void *buf, size_t buf_len, struct __actvret_fscall_vfs_write *__ret)
{
	return actvxactcall_fscall_vfs_write(false, false, fd, pos, buf, buf_len, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_write(rref_t __rref, int fd, long long pos, const void *buf, size_t buf_len, struct __actvret_fscall_vfs_write *__ret)
{
	return actvxactcapcall_fscall_vfs_write(false, false, __rref, fd, pos, buf, buf_len, __ret);
}

extern int __actvcall_fscall_vfs_writev(unsigned long long __rpc_info, void *__buf, int fd, const void *vec, int vlen, long long pos);


extern int __actvcapcall_fscall_vfs_writev(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *vec, int vlen, long long pos);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_writev(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *vec, int vlen, long long pos, struct __actvret_fscall_vfs_writev *__ret)
{
	const unsigned long __callno = __fs_method_vfs_writev;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_writev(rpc_info, __ret, fd, vec, vlen, pos);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_writev(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *vec, int vlen, long long pos, struct __actvret_fscall_vfs_writev *__ret)
{
	const unsigned long __callno = __fs_method_vfs_writev;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_writev(__rref, rpc_info, __ret, fd, vec, vlen, pos);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_writev(int fd, const void *vec, int vlen, long long pos, struct __actvret_fscall_vfs_writev *__ret)
{
	return actvxactcall_fscall_vfs_writev(false, false, fd, vec, vlen, pos, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_writev(rref_t __rref, int fd, const void *vec, int vlen, long long pos, struct __actvret_fscall_vfs_writev *__ret)
{
	return actvxactcapcall_fscall_vfs_writev(false, false, __rref, fd, vec, vlen, pos, __ret);
}

extern int __actvcall_fscall_vfs_sync(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_fscall_vfs_sync(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_sync(bool is_xact_fwd, bool is_xact_allow_refwd)
{
	const unsigned long __callno = __fs_method_vfs_sync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_sync(rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_sync(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref)
{
	const unsigned long __callno = __fs_method_vfs_sync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_sync(__rref, rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_sync(void)
{
	return actvxactcall_fscall_vfs_sync(false, false);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_sync(rref_t __rref)
{
	return actvxactcapcall_fscall_vfs_sync(false, false, __rref);
}

extern int __actvcall_fscall_vfs_do_sync(unsigned long long __rpc_info, void *__buf, int me_idx);


extern int __actvcapcall_fscall_vfs_do_sync(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_do_sync(bool is_xact_fwd, bool is_xact_allow_refwd, int me_idx)
{
	const unsigned long __callno = __fs_method_vfs_do_sync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_do_sync(rpc_info, NULL, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_do_sync(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int me_idx)
{
	const unsigned long __callno = __fs_method_vfs_do_sync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_do_sync(__rref, rpc_info, NULL, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_do_sync(int me_idx)
{
	return actvxactcall_fscall_vfs_do_sync(false, false, me_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_do_sync(rref_t __rref, int me_idx)
{
	return actvxactcapcall_fscall_vfs_do_sync(false, false, __rref, me_idx);
}

extern int __actvcall_fscall_vfs_utimensat(unsigned long long __rpc_info, void *__buf, int dfd, const void *tsp, unsigned int flag, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_utimensat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, const void *tsp, unsigned int flag, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_utimensat(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, const void *tsp, unsigned int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_utimensat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_utimensat(rpc_info, ___void_buf, dfd, tsp, flag, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_utimensat(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, const void *tsp, unsigned int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_utimensat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_utimensat(__rref, rpc_info, ___void_buf, dfd, tsp, flag, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_utimensat(int dfd, const void *tsp, unsigned int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_utimensat(false, false, dfd, tsp, flag, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_utimensat(rref_t __rref, int dfd, const void *tsp, unsigned int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_utimensat(false, false, __rref, dfd, tsp, flag, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_futimens(unsigned long long __rpc_info, void *__buf, int fd, const void *tsp);


extern int __actvcapcall_fscall_vfs_futimens(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *tsp);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_futimens(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *tsp)
{
	const unsigned long __callno = __fs_method_vfs_futimens;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_futimens(rpc_info, NULL, fd, tsp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_futimens(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *tsp)
{
	const unsigned long __callno = __fs_method_vfs_futimens;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_futimens(__rref, rpc_info, NULL, fd, tsp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_futimens(int fd, const void *tsp)
{
	return actvxactcall_fscall_vfs_futimens(false, false, fd, tsp);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_futimens(rref_t __rref, int fd, const void *tsp)
{
	return actvxactcapcall_fscall_vfs_futimens(false, false, __rref, fd, tsp);
}

extern int __actvcall_fscall_vfs_fchmodat(unsigned long long __rpc_info, void *__buf, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_fchmodat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fchmodat(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_fchmodat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fchmodat(rpc_info, ___void_buf, dfd, mode, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fchmodat(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_fchmodat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fchmodat(__rref, rpc_info, ___void_buf, dfd, mode, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fchmodat(int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_fchmodat(false, false, dfd, mode, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fchmodat(rref_t __rref, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_fchmodat(false, false, __rref, dfd, mode, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_fchmod(unsigned long long __rpc_info, void *__buf, int fd, mode_t mode);


extern int __actvcapcall_fscall_vfs_fchmod(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, mode_t mode);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fchmod(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, mode_t mode)
{
	const unsigned long __callno = __fs_method_vfs_fchmod;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fchmod(rpc_info, NULL, fd, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fchmod(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, mode_t mode)
{
	const unsigned long __callno = __fs_method_vfs_fchmod;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fchmod(__rref, rpc_info, NULL, fd, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fchmod(int fd, mode_t mode)
{
	return actvxactcall_fscall_vfs_fchmod(false, false, fd, mode);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fchmod(rref_t __rref, int fd, mode_t mode)
{
	return actvxactcapcall_fscall_vfs_fchmod(false, false, __rref, fd, mode);
}

extern int __actvcall_fscall_vfs_drop_caches(unsigned long long __rpc_info, void *__buf, unsigned int mode, int max, int reason);


extern int __actvcapcall_fscall_vfs_drop_caches(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int mode, int max, int reason);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_drop_caches(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int mode, int max, int reason)
{
	const unsigned long __callno = __fs_method_vfs_drop_caches;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_drop_caches(rpc_info, NULL, mode, max, reason);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_drop_caches(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int mode, int max, int reason)
{
	const unsigned long __callno = __fs_method_vfs_drop_caches;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_drop_caches(__rref, rpc_info, NULL, mode, max, reason);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_drop_caches(unsigned int mode, int max, int reason)
{
	return actvxactcall_fscall_vfs_drop_caches(false, false, mode, max, reason);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_drop_caches(rref_t __rref, unsigned int mode, int max, int reason)
{
	return actvxactcapcall_fscall_vfs_drop_caches(false, false, __rref, mode, max, reason);
}

extern int __actvcall_fscall_vfs_do_drop_caches(unsigned long long __rpc_info, void *__buf, unsigned int mode, int max, int reason);


extern int __actvcapcall_fscall_vfs_do_drop_caches(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int mode, int max, int reason);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_do_drop_caches(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int mode, int max, int reason)
{
	const unsigned long __callno = __fs_method_vfs_do_drop_caches;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_do_drop_caches(rpc_info, NULL, mode, max, reason);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_do_drop_caches(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int mode, int max, int reason)
{
	const unsigned long __callno = __fs_method_vfs_do_drop_caches;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_do_drop_caches(__rref, rpc_info, NULL, mode, max, reason);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_do_drop_caches(unsigned int mode, int max, int reason)
{
	return actvxactcall_fscall_vfs_do_drop_caches(false, false, mode, max, reason);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_do_drop_caches(rref_t __rref, unsigned int mode, int max, int reason)
{
	return actvxactcapcall_fscall_vfs_do_drop_caches(false, false, __rref, mode, max, reason);
}

extern int __actvcall_fscall_vfs_fadvise(unsigned long long __rpc_info, void *__buf, int fd, long long offset, long long len, int advice);


extern int __actvcapcall_fscall_vfs_fadvise(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long offset, long long len, int advice);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fadvise(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, long long offset, long long len, int advice)
{
	const unsigned long __callno = __fs_method_vfs_fadvise;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fadvise(rpc_info, NULL, fd, offset, len, advice);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fadvise(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, long long offset, long long len, int advice)
{
	const unsigned long __callno = __fs_method_vfs_fadvise;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fadvise(__rref, rpc_info, NULL, fd, offset, len, advice);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fadvise(int fd, long long offset, long long len, int advice)
{
	return actvxactcall_fscall_vfs_fadvise(false, false, fd, offset, len, advice);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fadvise(rref_t __rref, int fd, long long offset, long long len, int advice)
{
	return actvxactcapcall_fscall_vfs_fadvise(false, false, __rref, fd, offset, len, advice);
}

extern int __actvcall_fscall_vfs_readahead(unsigned long long __rpc_info, void *__buf, int fd, long long offset, size_t count);


extern int __actvcapcall_fscall_vfs_readahead(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long offset, size_t count);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_readahead(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, long long offset, size_t count)
{
	const unsigned long __callno = __fs_method_vfs_readahead;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_readahead(rpc_info, NULL, fd, offset, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_readahead(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, long long offset, size_t count)
{
	const unsigned long __callno = __fs_method_vfs_readahead;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_readahead(__rref, rpc_info, NULL, fd, offset, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_readahead(int fd, long long offset, size_t count)
{
	return actvxactcall_fscall_vfs_readahead(false, false, fd, offset, count);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_readahead(rref_t __rref, int fd, long long offset, size_t count)
{
	return actvxactcapcall_fscall_vfs_readahead(false, false, __rref, fd, offset, count);
}

extern int __actvcall_fscall_vfs_get_fd_path(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx, char *path, int pathlen);


extern int __actvcapcall_fscall_vfs_get_fd_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx, char *path, int pathlen);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_get_fd_path(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int cnode_idx, char *path, int pathlen)
{
	const unsigned long __callno = __fs_method_vfs_get_fd_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_get_fd_path(rpc_info, NULL, fd, cnode_idx, path, pathlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_get_fd_path(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int cnode_idx, char *path, int pathlen)
{
	const unsigned long __callno = __fs_method_vfs_get_fd_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_get_fd_path(__rref, rpc_info, NULL, fd, cnode_idx, path, pathlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_get_fd_path(int fd, unsigned int cnode_idx, char *path, int pathlen)
{
	return actvxactcall_fscall_vfs_get_fd_path(false, false, fd, cnode_idx, path, pathlen);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_get_fd_path(rref_t __rref, int fd, unsigned int cnode_idx, char *path, int pathlen)
{
	return actvxactcapcall_fscall_vfs_get_fd_path(false, false, __rref, fd, cnode_idx, path, pathlen);
}

extern int __actvcall_fscall_vfs_sysmgr_get_fd_path(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx, char *path);


extern int __actvcapcall_fscall_vfs_sysmgr_get_fd_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx, char *path);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_sysmgr_get_fd_path(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int cnode_idx, char *path)
{
	const unsigned long __callno = __fs_method_vfs_sysmgr_get_fd_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_sysmgr_get_fd_path(rpc_info, NULL, fd, cnode_idx, path);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_sysmgr_get_fd_path(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int cnode_idx, char *path)
{
	const unsigned long __callno = __fs_method_vfs_sysmgr_get_fd_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_sysmgr_get_fd_path(__rref, rpc_info, NULL, fd, cnode_idx, path);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_sysmgr_get_fd_path(int fd, unsigned int cnode_idx, char *path)
{
	return actvxactcall_fscall_vfs_sysmgr_get_fd_path(false, false, fd, cnode_idx, path);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_sysmgr_get_fd_path(rref_t __rref, int fd, unsigned int cnode_idx, char *path)
{
	return actvxactcapcall_fscall_vfs_sysmgr_get_fd_path(false, false, __rref, fd, cnode_idx, path);
}

extern int __actvcall_fscall_vfs_fcntl(unsigned long long __rpc_info, void *__buf, int fd, int cmd, unsigned long arg);


extern int __actvcapcall_fscall_vfs_fcntl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int cmd, unsigned long arg);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fcntl(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int cmd, unsigned long arg)
{
	const unsigned long __callno = __fs_method_vfs_fcntl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fcntl(rpc_info, NULL, fd, cmd, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fcntl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int cmd, unsigned long arg)
{
	const unsigned long __callno = __fs_method_vfs_fcntl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fcntl(__rref, rpc_info, NULL, fd, cmd, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fcntl(int fd, int cmd, unsigned long arg)
{
	return actvxactcall_fscall_vfs_fcntl(false, false, fd, cmd, arg);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fcntl(rref_t __rref, int fd, int cmd, unsigned long arg)
{
	return actvxactcapcall_fscall_vfs_fcntl(false, false, __rref, fd, cmd, arg);
}

extern int __actvcall_fscall_vfs_device_mounted(unsigned long long __rpc_info, void *__buf, const char *special, unsigned long long len, char *srvname, int srvlen);


extern int __actvcapcall_fscall_vfs_device_mounted(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *special, unsigned long long len, char *srvname, int srvlen);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_device_mounted(bool is_xact_fwd, bool is_xact_allow_refwd, const char *special, unsigned long long len, char *srvname, int srvlen)
{
	const unsigned long __callno = __fs_method_vfs_device_mounted;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_device_mounted(rpc_info, NULL, special, len, srvname, srvlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_device_mounted(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, const char *special, unsigned long long len, char *srvname, int srvlen)
{
	const unsigned long __callno = __fs_method_vfs_device_mounted;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_device_mounted(__rref, rpc_info, NULL, special, len, srvname, srvlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_device_mounted(const char *special, unsigned long long len, char *srvname, int srvlen)
{
	return actvxactcall_fscall_vfs_device_mounted(false, false, special, len, srvname, srvlen);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_device_mounted(rref_t __rref, const char *special, unsigned long long len, char *srvname, int srvlen)
{
	return actvxactcapcall_fscall_vfs_device_mounted(false, false, __rref, special, len, srvname, srvlen);
}

extern int __actvcall_fscall_vfs_quotactl(unsigned long long __rpc_info, void *__buf, int cmd, int type, unsigned int id, char *buffer, unsigned int buffer_size, int fs_handle);


extern int __actvcapcall_fscall_vfs_quotactl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int cmd, int type, unsigned int id, char *buffer, unsigned int buffer_size, int fs_handle);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_quotactl(bool is_xact_fwd, bool is_xact_allow_refwd, int cmd, int type, unsigned int id, char *buffer, unsigned int buffer_size, int fs_handle)
{
	const unsigned long __callno = __fs_method_vfs_quotactl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_quotactl(rpc_info, NULL, cmd, type, id, buffer, buffer_size, fs_handle);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_quotactl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int cmd, int type, unsigned int id, char *buffer, unsigned int buffer_size, int fs_handle)
{
	const unsigned long __callno = __fs_method_vfs_quotactl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_quotactl(__rref, rpc_info, NULL, cmd, type, id, buffer, buffer_size, fs_handle);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_quotactl(int cmd, int type, unsigned int id, char *buffer, unsigned int buffer_size, int fs_handle)
{
	return actvxactcall_fscall_vfs_quotactl(false, false, cmd, type, id, buffer, buffer_size, fs_handle);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_quotactl(rref_t __rref, int cmd, int type, unsigned int id, char *buffer, unsigned int buffer_size, int fs_handle)
{
	return actvxactcapcall_fscall_vfs_quotactl(false, false, __rref, cmd, type, id, buffer, buffer_size, fs_handle);
}

extern int __actvcall_fscall_vfs_copy_file_range(unsigned long long __rpc_info, void *__buf, int fd_in, long long off_in, int fd_out, long long off_out, size_t len);


extern int __actvcapcall_fscall_vfs_copy_file_range(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd_in, long long off_in, int fd_out, long long off_out, size_t len);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_copy_file_range(bool is_xact_fwd, bool is_xact_allow_refwd, int fd_in, long long off_in, int fd_out, long long off_out, size_t len, struct __actvret_fscall_vfs_copy_file_range *__ret)
{
	const unsigned long __callno = __fs_method_vfs_copy_file_range;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_copy_file_range(rpc_info, __ret, fd_in, off_in, fd_out, off_out, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_copy_file_range(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd_in, long long off_in, int fd_out, long long off_out, size_t len, struct __actvret_fscall_vfs_copy_file_range *__ret)
{
	const unsigned long __callno = __fs_method_vfs_copy_file_range;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_copy_file_range(__rref, rpc_info, __ret, fd_in, off_in, fd_out, off_out, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_copy_file_range(int fd_in, long long off_in, int fd_out, long long off_out, size_t len, struct __actvret_fscall_vfs_copy_file_range *__ret)
{
	return actvxactcall_fscall_vfs_copy_file_range(false, false, fd_in, off_in, fd_out, off_out, len, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_copy_file_range(rref_t __rref, int fd_in, long long off_in, int fd_out, long long off_out, size_t len, struct __actvret_fscall_vfs_copy_file_range *__ret)
{
	return actvxactcapcall_fscall_vfs_copy_file_range(false, false, __rref, fd_in, off_in, fd_out, off_out, len, __ret);
}

extern int __actvcall_fscall_vfs_same_file(unsigned long long __rpc_info, void *__buf, int fd1, int fd2);


extern int __actvcapcall_fscall_vfs_same_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd1, int fd2);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_same_file(bool is_xact_fwd, bool is_xact_allow_refwd, int fd1, int fd2)
{
	const unsigned long __callno = __fs_method_vfs_same_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_same_file(rpc_info, NULL, fd1, fd2);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_same_file(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd1, int fd2)
{
	const unsigned long __callno = __fs_method_vfs_same_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_same_file(__rref, rpc_info, NULL, fd1, fd2);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_same_file(int fd1, int fd2)
{
	return actvxactcall_fscall_vfs_same_file(false, false, fd1, fd2);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_same_file(rref_t __rref, int fd1, int fd2)
{
	return actvxactcapcall_fscall_vfs_same_file(false, false, __rref, fd1, fd2);
}

extern int __actvcall_fscall_vfs_access(unsigned long long __rpc_info, void *__buf, int dfd, unsigned int mode, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_access(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned int mode, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_access(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, unsigned int mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_access;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_access(rpc_info, ___void_buf, dfd, mode, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_access(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, unsigned int mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_access;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_access(__rref, rpc_info, ___void_buf, dfd, mode, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_access(int dfd, unsigned int mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_access(false, false, dfd, mode, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_access(rref_t __rref, int dfd, unsigned int mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_access(false, false, __rref, dfd, mode, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_flock(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cmd);


extern int __actvcapcall_fscall_vfs_flock(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cmd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_flock(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int cmd)
{
	const unsigned long __callno = __fs_method_vfs_flock;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_flock(rpc_info, NULL, fd, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_flock(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int cmd)
{
	const unsigned long __callno = __fs_method_vfs_flock;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_flock(__rref, rpc_info, NULL, fd, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_flock(int fd, unsigned int cmd)
{
	return actvxactcall_fscall_vfs_flock(false, false, fd, cmd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_flock(rref_t __rref, int fd, unsigned int cmd)
{
	return actvxactcapcall_fscall_vfs_flock(false, false, __rref, fd, cmd);
}

extern int __actvcall_fscall_vfs_fchownat(unsigned long long __rpc_info, void *__buf, int dfd, uid_t uid, gid_t gid, unsigned int flag, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_fchownat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, uid_t uid, gid_t gid, unsigned int flag, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fchownat(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, uid_t uid, gid_t gid, unsigned int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_fchownat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uid_t), __arch_actv_rpc_stksz_alignment(uid_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(gid_t), __arch_actv_rpc_stksz_alignment(gid_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fchownat(rpc_info, ___void_buf, dfd, uid, gid, flag, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fchownat(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, uid_t uid, gid_t gid, unsigned int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_fchownat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uid_t), __arch_actv_rpc_stksz_alignment(uid_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(gid_t), __arch_actv_rpc_stksz_alignment(gid_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fchownat(__rref, rpc_info, ___void_buf, dfd, uid, gid, flag, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fchownat(int dfd, uid_t uid, gid_t gid, unsigned int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_fchownat(false, false, dfd, uid, gid, flag, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fchownat(rref_t __rref, int dfd, uid_t uid, gid_t gid, unsigned int flag, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_fchownat(false, false, __rref, dfd, uid, gid, flag, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_fchown(unsigned long long __rpc_info, void *__buf, int fd, uid_t uid, gid_t gid);


extern int __actvcapcall_fscall_vfs_fchown(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, uid_t uid, gid_t gid);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fchown(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, uid_t uid, gid_t gid)
{
	const unsigned long __callno = __fs_method_vfs_fchown;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uid_t), __arch_actv_rpc_stksz_alignment(uid_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(gid_t), __arch_actv_rpc_stksz_alignment(gid_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fchown(rpc_info, NULL, fd, uid, gid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fchown(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, uid_t uid, gid_t gid)
{
	const unsigned long __callno = __fs_method_vfs_fchown;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uid_t), __arch_actv_rpc_stksz_alignment(uid_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(gid_t), __arch_actv_rpc_stksz_alignment(gid_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fchown(__rref, rpc_info, NULL, fd, uid, gid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fchown(int fd, uid_t uid, gid_t gid)
{
	return actvxactcall_fscall_vfs_fchown(false, false, fd, uid, gid);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fchown(rref_t __rref, int fd, uid_t uid, gid_t gid)
{
	return actvxactcapcall_fscall_vfs_fchown(false, false, __rref, fd, uid, gid);
}

extern int __actvcall_fscall_vfs_binderfs_mmap(unsigned long long __rpc_info, void *__buf, void *addr, size_t len, int fd, unsigned long long shm_key);


extern int __actvcapcall_fscall_vfs_binderfs_mmap(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *addr, size_t len, int fd, unsigned long long shm_key);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_binderfs_mmap(bool is_xact_fwd, bool is_xact_allow_refwd, void *addr, size_t len, int fd, unsigned long long shm_key)
{
	const unsigned long __callno = __fs_method_vfs_binderfs_mmap;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_binderfs_mmap(rpc_info, NULL, addr, len, fd, shm_key);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_binderfs_mmap(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *addr, size_t len, int fd, unsigned long long shm_key)
{
	const unsigned long __callno = __fs_method_vfs_binderfs_mmap;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_binderfs_mmap(__rref, rpc_info, NULL, addr, len, fd, shm_key);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_binderfs_mmap(void *addr, size_t len, int fd, unsigned long long shm_key)
{
	return actvxactcall_fscall_vfs_binderfs_mmap(false, false, addr, len, fd, shm_key);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_binderfs_mmap(rref_t __rref, void *addr, size_t len, int fd, unsigned long long shm_key)
{
	return actvxactcapcall_fscall_vfs_binderfs_mmap(false, false, __rref, addr, len, fd, shm_key);
}

extern int __actvcall_fscall_vfs_init_signalfd(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long sigmask, int flags);


extern int __actvcapcall_fscall_vfs_init_signalfd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long sigmask, int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_init_signalfd(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long long sigmask, int flags)
{
	const unsigned long __callno = __fs_method_vfs_init_signalfd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_init_signalfd(rpc_info, NULL, fd, sigmask, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_init_signalfd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long long sigmask, int flags)
{
	const unsigned long __callno = __fs_method_vfs_init_signalfd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_init_signalfd(__rref, rpc_info, NULL, fd, sigmask, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_init_signalfd(int fd, unsigned long long sigmask, int flags)
{
	return actvxactcall_fscall_vfs_init_signalfd(false, false, fd, sigmask, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_init_signalfd(rref_t __rref, int fd, unsigned long long sigmask, int flags)
{
	return actvxactcapcall_fscall_vfs_init_signalfd(false, false, __rref, fd, sigmask, flags);
}

extern int __actvcall_fscall_vfs_epoll_ctl(unsigned long long __rpc_info, void *__buf, int fd, int op, int is_epoll, const void *epoll_reg_info);


extern int __actvcapcall_fscall_vfs_epoll_ctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int op, int is_epoll, const void *epoll_reg_info);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_epoll_ctl(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int op, int is_epoll, const void *epoll_reg_info)
{
	const unsigned long __callno = __fs_method_vfs_epoll_ctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_epoll_ctl(rpc_info, NULL, fd, op, is_epoll, epoll_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_epoll_ctl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int op, int is_epoll, const void *epoll_reg_info)
{
	const unsigned long __callno = __fs_method_vfs_epoll_ctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_epoll_ctl(__rref, rpc_info, NULL, fd, op, is_epoll, epoll_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_epoll_ctl(int fd, int op, int is_epoll, const void *epoll_reg_info)
{
	return actvxactcall_fscall_vfs_epoll_ctl(false, false, fd, op, is_epoll, epoll_reg_info);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_epoll_ctl(rref_t __rref, int fd, int op, int is_epoll, const void *epoll_reg_info)
{
	return actvxactcapcall_fscall_vfs_epoll_ctl(false, false, __rref, fd, op, is_epoll, epoll_reg_info);
}

extern int __actvcall_fscall_vfs_epoll_et_revents(unsigned long long __rpc_info, void *__buf, int fd, const void *epoll_pre_reg_info);


extern int __actvcapcall_fscall_vfs_epoll_et_revents(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *epoll_pre_reg_info);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_epoll_et_revents(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *epoll_pre_reg_info, struct __actvret_fscall_vfs_epoll_et_revents *__ret)
{
	const unsigned long __callno = __fs_method_vfs_epoll_et_revents;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_epoll_et_revents(rpc_info, __ret, fd, epoll_pre_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_epoll_et_revents(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *epoll_pre_reg_info, struct __actvret_fscall_vfs_epoll_et_revents *__ret)
{
	const unsigned long __callno = __fs_method_vfs_epoll_et_revents;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_epoll_et_revents(__rref, rpc_info, __ret, fd, epoll_pre_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_epoll_et_revents(int fd, const void *epoll_pre_reg_info, struct __actvret_fscall_vfs_epoll_et_revents *__ret)
{
	return actvxactcall_fscall_vfs_epoll_et_revents(false, false, fd, epoll_pre_reg_info, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_epoll_et_revents(rref_t __rref, int fd, const void *epoll_pre_reg_info, struct __actvret_fscall_vfs_epoll_et_revents *__ret)
{
	return actvxactcapcall_fscall_vfs_epoll_et_revents(false, false, __rref, fd, epoll_pre_reg_info, __ret);
}

extern int __actvcall_fscall_vfs_epoll_reinit(unsigned long long __rpc_info, void *__buf, int fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);


extern int __actvcapcall_fscall_vfs_epoll_reinit(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_epoll_reinit(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	const unsigned long __callno = __fs_method_vfs_epoll_reinit;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_epoll_reinit(rpc_info, NULL, fd, epoll_pre_reg_info, epoll_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_epoll_reinit(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	const unsigned long __callno = __fs_method_vfs_epoll_reinit;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_epoll_reinit(__rref, rpc_info, NULL, fd, epoll_pre_reg_info, epoll_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_epoll_reinit(int fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	return actvxactcall_fscall_vfs_epoll_reinit(false, false, fd, epoll_pre_reg_info, epoll_reg_info);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_epoll_reinit(rref_t __rref, int fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	return actvxactcapcall_fscall_vfs_epoll_reinit(false, false, __rref, fd, epoll_pre_reg_info, epoll_reg_info);
}

extern int __actvcall_fscall_vfs_signalfd_notify(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, const void *buf, int fdcnt);


extern int __actvcapcall_fscall_vfs_signalfd_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, const void *buf, int fdcnt);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_signalfd_notify(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, const void *buf, int fdcnt)
{
	const unsigned long __callno = __fs_method_vfs_signalfd_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_signalfd_notify(rpc_info, NULL, cnode_idx, buf, fdcnt);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_signalfd_notify(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, const void *buf, int fdcnt)
{
	const unsigned long __callno = __fs_method_vfs_signalfd_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_signalfd_notify(__rref, rpc_info, NULL, cnode_idx, buf, fdcnt);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_signalfd_notify(unsigned int cnode_idx, const void *buf, int fdcnt)
{
	return actvxactcall_fscall_vfs_signalfd_notify(false, false, cnode_idx, buf, fdcnt);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_signalfd_notify(rref_t __rref, unsigned int cnode_idx, const void *buf, int fdcnt)
{
	return actvxactcapcall_fscall_vfs_signalfd_notify(false, false, __rref, cnode_idx, buf, fdcnt);
}

extern int __actvcall_fscall_vfs_pid_io_stats(unsigned long long __rpc_info, void *__buf, unsigned int pid);


extern int __actvcapcall_fscall_vfs_pid_io_stats(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int pid);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_pid_io_stats(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int pid, struct __actvret_fscall_vfs_pid_io_stats *__ret)
{
	const unsigned long __callno = __fs_method_vfs_pid_io_stats;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_pid_io_stats(rpc_info, __ret, pid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_pid_io_stats(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int pid, struct __actvret_fscall_vfs_pid_io_stats *__ret)
{
	const unsigned long __callno = __fs_method_vfs_pid_io_stats;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_pid_io_stats(__rref, rpc_info, __ret, pid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_pid_io_stats(unsigned int pid, struct __actvret_fscall_vfs_pid_io_stats *__ret)
{
	return actvxactcall_fscall_vfs_pid_io_stats(false, false, pid, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_pid_io_stats(rref_t __rref, unsigned int pid, struct __actvret_fscall_vfs_pid_io_stats *__ret)
{
	return actvxactcapcall_fscall_vfs_pid_io_stats(false, false, __rref, pid, __ret);
}

extern int __actvcall_fscall_vfs_fallocate(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long offset, unsigned long long len, int mode);


extern int __actvcapcall_fscall_vfs_fallocate(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long offset, unsigned long long len, int mode);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fallocate(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long long offset, unsigned long long len, int mode)
{
	const unsigned long __callno = __fs_method_vfs_fallocate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fallocate(rpc_info, NULL, fd, offset, len, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fallocate(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long long offset, unsigned long long len, int mode)
{
	const unsigned long __callno = __fs_method_vfs_fallocate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fallocate(__rref, rpc_info, NULL, fd, offset, len, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fallocate(int fd, unsigned long long offset, unsigned long long len, int mode)
{
	return actvxactcall_fscall_vfs_fallocate(false, false, fd, offset, len, mode);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fallocate(rref_t __rref, int fd, unsigned long long offset, unsigned long long len, int mode)
{
	return actvxactcapcall_fscall_vfs_fallocate(false, false, __rref, fd, offset, len, mode);
}

extern int __actvcall_fscall_vfs_set_cwdroot(unsigned long long __rpc_info, void *__buf, int dfd, int type, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_set_cwdroot(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, int type, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_set_cwdroot(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, int type, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_set_cwdroot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_set_cwdroot(rpc_info, ___void_buf, dfd, type, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_set_cwdroot(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, int type, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_set_cwdroot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_set_cwdroot(__rref, rpc_info, ___void_buf, dfd, type, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_set_cwdroot(int dfd, int type, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_set_cwdroot(false, false, dfd, type, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_set_cwdroot(rref_t __rref, int dfd, int type, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_set_cwdroot(false, false, __rref, dfd, type, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_fchdir(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_fscall_vfs_fchdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fchdir(bool is_xact_fwd, bool is_xact_allow_refwd, int fd)
{
	const unsigned long __callno = __fs_method_vfs_fchdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fchdir(rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fchdir(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd)
{
	const unsigned long __callno = __fs_method_vfs_fchdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fchdir(__rref, rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fchdir(int fd)
{
	return actvxactcall_fscall_vfs_fchdir(false, false, fd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fchdir(rref_t __rref, int fd)
{
	return actvxactcapcall_fscall_vfs_fchdir(false, false, __rref, fd);
}

extern int __actvcall_fscall_vfs_disable_cwdroot(unsigned long long __rpc_info, void *__buf, int type);


extern int __actvcapcall_fscall_vfs_disable_cwdroot(rref_t __rref, unsigned long long __rpc_info, void *__buf, int type);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_disable_cwdroot(bool is_xact_fwd, bool is_xact_allow_refwd, int type, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_disable_cwdroot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_disable_cwdroot(rpc_info, ___void_buf, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_disable_cwdroot(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int type, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_disable_cwdroot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_disable_cwdroot(__rref, rpc_info, ___void_buf, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_disable_cwdroot(int type, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_disable_cwdroot(false, false, type, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_disable_cwdroot(rref_t __rref, int type, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_disable_cwdroot(false, false, __rref, type, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_update_cwdroot(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int type);


extern int __actvcapcall_fscall_vfs_update_cwdroot(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int type);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_update_cwdroot(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int type, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_update_cwdroot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_update_cwdroot(rpc_info, ___void_buf, cnode_idx, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_update_cwdroot(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int type, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_update_cwdroot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_update_cwdroot(__rref, rpc_info, ___void_buf, cnode_idx, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_update_cwdroot(unsigned int cnode_idx, int type, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_update_cwdroot(false, false, cnode_idx, type, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_update_cwdroot(rref_t __rref, unsigned int cnode_idx, int type, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_update_cwdroot(false, false, __rref, cnode_idx, type, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_handle_global_locks(unsigned long long __rpc_info, void *__buf, unsigned int cmd, unsigned int cnode_idx, unsigned long lock_id);


extern int __actvcapcall_fscall_vfs_handle_global_locks(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cmd, unsigned int cnode_idx, unsigned long lock_id);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_handle_global_locks(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cmd, unsigned int cnode_idx, unsigned long lock_id, struct __actvret_fscall_vfs_handle_global_locks *__ret)
{
	const unsigned long __callno = __fs_method_vfs_handle_global_locks;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_handle_global_locks(rpc_info, __ret, cmd, cnode_idx, lock_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_handle_global_locks(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cmd, unsigned int cnode_idx, unsigned long lock_id, struct __actvret_fscall_vfs_handle_global_locks *__ret)
{
	const unsigned long __callno = __fs_method_vfs_handle_global_locks;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_handle_global_locks(__rref, rpc_info, __ret, cmd, cnode_idx, lock_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_handle_global_locks(unsigned int cmd, unsigned int cnode_idx, unsigned long lock_id, struct __actvret_fscall_vfs_handle_global_locks *__ret)
{
	return actvxactcall_fscall_vfs_handle_global_locks(false, false, cmd, cnode_idx, lock_id, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_handle_global_locks(rref_t __rref, unsigned int cmd, unsigned int cnode_idx, unsigned long lock_id, struct __actvret_fscall_vfs_handle_global_locks *__ret)
{
	return actvxactcapcall_fscall_vfs_handle_global_locks(false, false, __rref, cmd, cnode_idx, lock_id, __ret);
}

extern int __actvcall_fscall_vfs_send_fd(unsigned long long __rpc_info, void *__buf, int send_fd, unsigned int send_cidx, unsigned int recv_cidx);


extern int __actvcapcall_fscall_vfs_send_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int send_fd, unsigned int send_cidx, unsigned int recv_cidx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_send_fd(bool is_xact_fwd, bool is_xact_allow_refwd, int send_fd, unsigned int send_cidx, unsigned int recv_cidx)
{
	const unsigned long __callno = __fs_method_vfs_send_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_send_fd(rpc_info, NULL, send_fd, send_cidx, recv_cidx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_send_fd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int send_fd, unsigned int send_cidx, unsigned int recv_cidx)
{
	const unsigned long __callno = __fs_method_vfs_send_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_send_fd(__rref, rpc_info, NULL, send_fd, send_cidx, recv_cidx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_send_fd(int send_fd, unsigned int send_cidx, unsigned int recv_cidx)
{
	return actvxactcall_fscall_vfs_send_fd(false, false, send_fd, send_cidx, recv_cidx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_send_fd(rref_t __rref, int send_fd, unsigned int send_cidx, unsigned int recv_cidx)
{
	return actvxactcapcall_fscall_vfs_send_fd(false, false, __rref, send_fd, send_cidx, recv_cidx);
}

extern int __actvcall_fscall_vfs_recv_fd(unsigned long long __rpc_info, void *__buf, int sfiles_idx, unsigned int send_cidx, int recv_fd, unsigned int recv_cidx);


extern int __actvcapcall_fscall_vfs_recv_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int sfiles_idx, unsigned int send_cidx, int recv_fd, unsigned int recv_cidx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_recv_fd(bool is_xact_fwd, bool is_xact_allow_refwd, int sfiles_idx, unsigned int send_cidx, int recv_fd, unsigned int recv_cidx, struct __actvret_fscall_vfs_recv_fd *__ret)
{
	const unsigned long __callno = __fs_method_vfs_recv_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_recv_fd(rpc_info, __ret, sfiles_idx, send_cidx, recv_fd, recv_cidx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_recv_fd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int sfiles_idx, unsigned int send_cidx, int recv_fd, unsigned int recv_cidx, struct __actvret_fscall_vfs_recv_fd *__ret)
{
	const unsigned long __callno = __fs_method_vfs_recv_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_recv_fd(__rref, rpc_info, __ret, sfiles_idx, send_cidx, recv_fd, recv_cidx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_recv_fd(int sfiles_idx, unsigned int send_cidx, int recv_fd, unsigned int recv_cidx, struct __actvret_fscall_vfs_recv_fd *__ret)
{
	return actvxactcall_fscall_vfs_recv_fd(false, false, sfiles_idx, send_cidx, recv_fd, recv_cidx, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_recv_fd(rref_t __rref, int sfiles_idx, unsigned int send_cidx, int recv_fd, unsigned int recv_cidx, struct __actvret_fscall_vfs_recv_fd *__ret)
{
	return actvxactcapcall_fscall_vfs_recv_fd(false, false, __rref, sfiles_idx, send_cidx, recv_fd, recv_cidx, __ret);
}

extern int __actvcall_fscall_vfs_get_buffer_wrapper(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long ptr);


extern int __actvcapcall_fscall_vfs_get_buffer_wrapper(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long ptr);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_get_buffer_wrapper(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long long ptr, struct __actvret_fscall_vfs_get_buffer_wrapper *__ret)
{
	const unsigned long __callno = __fs_method_vfs_get_buffer_wrapper;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_get_buffer_wrapper(rpc_info, __ret, fd, ptr);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_get_buffer_wrapper(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long long ptr, struct __actvret_fscall_vfs_get_buffer_wrapper *__ret)
{
	const unsigned long __callno = __fs_method_vfs_get_buffer_wrapper;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_get_buffer_wrapper(__rref, rpc_info, __ret, fd, ptr);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_get_buffer_wrapper(int fd, unsigned long long ptr, struct __actvret_fscall_vfs_get_buffer_wrapper *__ret)
{
	return actvxactcall_fscall_vfs_get_buffer_wrapper(false, false, fd, ptr, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_get_buffer_wrapper(rref_t __rref, int fd, unsigned long long ptr, struct __actvret_fscall_vfs_get_buffer_wrapper *__ret)
{
	return actvxactcapcall_fscall_vfs_get_buffer_wrapper(false, false, __rref, fd, ptr, __ret);
}

extern int __actvcall_fscall_vfs_get_pathname_by_me_idx(unsigned long long __rpc_info, void *__buf, int fd, int me_idx, uintptr_t pathname);


extern int __actvcapcall_fscall_vfs_get_pathname_by_me_idx(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int me_idx, uintptr_t pathname);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_get_pathname_by_me_idx(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int me_idx, uintptr_t pathname)
{
	const unsigned long __callno = __fs_method_vfs_get_pathname_by_me_idx;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_get_pathname_by_me_idx(rpc_info, NULL, fd, me_idx, pathname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_get_pathname_by_me_idx(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int me_idx, uintptr_t pathname)
{
	const unsigned long __callno = __fs_method_vfs_get_pathname_by_me_idx;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_get_pathname_by_me_idx(__rref, rpc_info, NULL, fd, me_idx, pathname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_get_pathname_by_me_idx(int fd, int me_idx, uintptr_t pathname)
{
	return actvxactcall_fscall_vfs_get_pathname_by_me_idx(false, false, fd, me_idx, pathname);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_get_pathname_by_me_idx(rref_t __rref, int fd, int me_idx, uintptr_t pathname)
{
	return actvxactcapcall_fscall_vfs_get_pathname_by_me_idx(false, false, __rref, fd, me_idx, pathname);
}

extern int __actvcall_fscall_vfs_sfile_put(unsigned long long __rpc_info, void *__buf, unsigned int send_cidx, unsigned int recv_cidx, int sfiles_idx);


extern int __actvcapcall_fscall_vfs_sfile_put(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int send_cidx, unsigned int recv_cidx, int sfiles_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_sfile_put(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int send_cidx, unsigned int recv_cidx, int sfiles_idx)
{
	const unsigned long __callno = __fs_method_vfs_sfile_put;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_sfile_put(rpc_info, NULL, send_cidx, recv_cidx, sfiles_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_sfile_put(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int send_cidx, unsigned int recv_cidx, int sfiles_idx)
{
	const unsigned long __callno = __fs_method_vfs_sfile_put;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_sfile_put(__rref, rpc_info, NULL, send_cidx, recv_cidx, sfiles_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_sfile_put(unsigned int send_cidx, unsigned int recv_cidx, int sfiles_idx)
{
	return actvxactcall_fscall_vfs_sfile_put(false, false, send_cidx, recv_cidx, sfiles_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_sfile_put(rref_t __rref, unsigned int send_cidx, unsigned int recv_cidx, int sfiles_idx)
{
	return actvxactcapcall_fscall_vfs_sfile_put(false, false, __rref, send_cidx, recv_cidx, sfiles_idx);
}

extern int __actvcall_fscall_vfs_readlinkat(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, char *buf, unsigned long long bufsize, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_readlinkat(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, char *buf, unsigned long long bufsize, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_readlinkat(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, char *buf, unsigned long long bufsize, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_readlinkat *__ret)
{
	const unsigned long __callno = __fs_method_vfs_readlinkat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_readlinkat(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dfd, buf, bufsize, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_readlinkat(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, char *buf, unsigned long long bufsize, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_readlinkat *__ret)
{
	const unsigned long __callno = __fs_method_vfs_readlinkat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_readlinkat(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dfd, buf, bufsize, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_readlinkat(int dfd, char *buf, unsigned long long bufsize, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_readlinkat *__ret)
{
	return actvxactcall_fscall_vfs_readlinkat(false, false, dfd, buf, bufsize, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_readlinkat(rref_t __rref, int dfd, char *buf, unsigned long long bufsize, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_readlinkat *__ret)
{
	return actvxactcapcall_fscall_vfs_readlinkat(false, false, __rref, dfd, buf, bufsize, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_fscall_vfs_get_slabinfo(unsigned long long __rpc_info, void *__buf, char *msg, unsigned int msg_len);


extern int __actvcapcall_fscall_vfs_get_slabinfo(rref_t __rref, unsigned long long __rpc_info, void *__buf, char *msg, unsigned int msg_len);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_get_slabinfo(bool is_xact_fwd, bool is_xact_allow_refwd, char *msg, unsigned int msg_len)
{
	const unsigned long __callno = __fs_method_vfs_get_slabinfo;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_get_slabinfo(rpc_info, NULL, msg, msg_len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_get_slabinfo(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, char *msg, unsigned int msg_len)
{
	const unsigned long __callno = __fs_method_vfs_get_slabinfo;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_get_slabinfo(__rref, rpc_info, NULL, msg, msg_len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_get_slabinfo(char *msg, unsigned int msg_len)
{
	return actvxactcall_fscall_vfs_get_slabinfo(false, false, msg, msg_len);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_get_slabinfo(rref_t __rref, char *msg, unsigned int msg_len)
{
	return actvxactcapcall_fscall_vfs_get_slabinfo(false, false, __rref, msg, msg_len);
}

extern int __actvcall_fscall_vfs_do_get_slabinfo(unsigned long long __rpc_info, void *__buf, char *msg, unsigned int msg_len);


extern int __actvcapcall_fscall_vfs_do_get_slabinfo(rref_t __rref, unsigned long long __rpc_info, void *__buf, char *msg, unsigned int msg_len);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_do_get_slabinfo(bool is_xact_fwd, bool is_xact_allow_refwd, char *msg, unsigned int msg_len)
{
	const unsigned long __callno = __fs_method_vfs_do_get_slabinfo;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_do_get_slabinfo(rpc_info, NULL, msg, msg_len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_do_get_slabinfo(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, char *msg, unsigned int msg_len)
{
	const unsigned long __callno = __fs_method_vfs_do_get_slabinfo;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_do_get_slabinfo(__rref, rpc_info, NULL, msg, msg_len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_do_get_slabinfo(char *msg, unsigned int msg_len)
{
	return actvxactcall_fscall_vfs_do_get_slabinfo(false, false, msg, msg_len);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_do_get_slabinfo(rref_t __rref, char *msg, unsigned int msg_len)
{
	return actvxactcapcall_fscall_vfs_do_get_slabinfo(false, false, __rref, msg, msg_len);
}

extern int __actvcall_fscall_vfs_fscache_print_info(unsigned long long __rpc_info, void *__buf, int count);


extern int __actvcapcall_fscall_vfs_fscache_print_info(rref_t __rref, unsigned long long __rpc_info, void *__buf, int count);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fscache_print_info(bool is_xact_fwd, bool is_xact_allow_refwd, int count)
{
	const unsigned long __callno = __fs_method_vfs_fscache_print_info;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fscache_print_info(rpc_info, NULL, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fscache_print_info(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int count)
{
	const unsigned long __callno = __fs_method_vfs_fscache_print_info;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fscache_print_info(__rref, rpc_info, NULL, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fscache_print_info(int count)
{
	return actvxactcall_fscall_vfs_fscache_print_info(false, false, count);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fscache_print_info(rref_t __rref, int count)
{
	return actvxactcapcall_fscall_vfs_fscache_print_info(false, false, __rref, count);
}

extern int __actvcall_fscall_vfs_alloc_fs_handle_for_same_device(unsigned long long __rpc_info, void *__buf, int me_idx, int new_me_idx, unsigned long flags);


extern int __actvcapcall_fscall_vfs_alloc_fs_handle_for_same_device(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, int new_me_idx, unsigned long flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_alloc_fs_handle_for_same_device(bool is_xact_fwd, bool is_xact_allow_refwd, int me_idx, int new_me_idx, unsigned long flags, struct __actvret_fscall_vfs_alloc_fs_handle_for_same_device *__ret)
{
	const unsigned long __callno = __fs_method_vfs_alloc_fs_handle_for_same_device;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_alloc_fs_handle_for_same_device(rpc_info, __ret, me_idx, new_me_idx, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_alloc_fs_handle_for_same_device(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int me_idx, int new_me_idx, unsigned long flags, struct __actvret_fscall_vfs_alloc_fs_handle_for_same_device *__ret)
{
	const unsigned long __callno = __fs_method_vfs_alloc_fs_handle_for_same_device;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_alloc_fs_handle_for_same_device(__rref, rpc_info, __ret, me_idx, new_me_idx, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_alloc_fs_handle_for_same_device(int me_idx, int new_me_idx, unsigned long flags, struct __actvret_fscall_vfs_alloc_fs_handle_for_same_device *__ret)
{
	return actvxactcall_fscall_vfs_alloc_fs_handle_for_same_device(false, false, me_idx, new_me_idx, flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_alloc_fs_handle_for_same_device(rref_t __rref, int me_idx, int new_me_idx, unsigned long flags, struct __actvret_fscall_vfs_alloc_fs_handle_for_same_device *__ret)
{
	return actvxactcapcall_fscall_vfs_alloc_fs_handle_for_same_device(false, false, __rref, me_idx, new_me_idx, flags, __ret);
}

extern int __actvcall_fscall_vfs_free_fs_handle_for_same_device(unsigned long long __rpc_info, void *__buf, int me_idx, unsigned int fs_handle);


extern int __actvcapcall_fscall_vfs_free_fs_handle_for_same_device(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, unsigned int fs_handle);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_free_fs_handle_for_same_device(bool is_xact_fwd, bool is_xact_allow_refwd, int me_idx, unsigned int fs_handle)
{
	const unsigned long __callno = __fs_method_vfs_free_fs_handle_for_same_device;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_free_fs_handle_for_same_device(rpc_info, NULL, me_idx, fs_handle);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_free_fs_handle_for_same_device(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int me_idx, unsigned int fs_handle)
{
	const unsigned long __callno = __fs_method_vfs_free_fs_handle_for_same_device;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_free_fs_handle_for_same_device(__rref, rpc_info, NULL, me_idx, fs_handle);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_free_fs_handle_for_same_device(int me_idx, unsigned int fs_handle)
{
	return actvxactcall_fscall_vfs_free_fs_handle_for_same_device(false, false, me_idx, fs_handle);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_free_fs_handle_for_same_device(rref_t __rref, int me_idx, unsigned int fs_handle)
{
	return actvxactcapcall_fscall_vfs_free_fs_handle_for_same_device(false, false, __rref, me_idx, fs_handle);
}

extern int __actvcall_fscall_vfs_memfd_create(unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags);


extern int __actvcapcall_fscall_vfs_memfd_create(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_memfd_create(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int flags, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_memfd_create;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_memfd_create(rpc_info, ___void_buf, fd, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_memfd_create(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int flags, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_memfd_create;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_memfd_create(__rref, rpc_info, ___void_buf, fd, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_memfd_create(int fd, unsigned int flags, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_memfd_create(false, false, fd, flags, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_memfd_create(rref_t __rref, int fd, unsigned int flags, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_memfd_create(false, false, __rref, fd, flags, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_mknod(unsigned long long __rpc_info, void *__buf, int parent_fd, unsigned long long devno, unsigned int mode, void *msg, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_mknod(rref_t __rref, unsigned long long __rpc_info, void *__buf, int parent_fd, unsigned long long devno, unsigned int mode, void *msg, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mknod(bool is_xact_fwd, bool is_xact_allow_refwd, int parent_fd, unsigned long long devno, unsigned int mode, void *msg, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_mknod;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mknod(rpc_info, ___void_buf, parent_fd, devno, mode, msg, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mknod(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int parent_fd, unsigned long long devno, unsigned int mode, void *msg, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_mknod;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mknod(__rref, rpc_info, ___void_buf, parent_fd, devno, mode, msg, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mknod(int parent_fd, unsigned long long devno, unsigned int mode, void *msg, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_mknod(false, false, parent_fd, devno, mode, msg, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mknod(rref_t __rref, int parent_fd, unsigned long long devno, unsigned int mode, void *msg, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_mknod(false, false, __rref, parent_fd, devno, mode, msg, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_rename(unsigned long long __rpc_info, void *__buf, int old_pfd, int new_pfd);


extern int __actvcapcall_fscall_vfs_rename(rref_t __rref, unsigned long long __rpc_info, void *__buf, int old_pfd, int new_pfd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_rename(bool is_xact_fwd, bool is_xact_allow_refwd, int old_pfd, int new_pfd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_rename;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_rename(rpc_info, ___void_buf, old_pfd, new_pfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_rename(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int old_pfd, int new_pfd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_rename;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_rename(__rref, rpc_info, ___void_buf, old_pfd, new_pfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_rename(int old_pfd, int new_pfd, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_rename(false, false, old_pfd, new_pfd, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_rename(rref_t __rref, int old_pfd, int new_pfd, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_rename(false, false, __rref, old_pfd, new_pfd, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_mkdirat(unsigned long long __rpc_info, void *__buf, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_mkdirat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mkdirat(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_mkdirat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mkdirat(rpc_info, ___void_buf, dfd, mode, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mkdirat(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_mkdirat;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mkdirat(__rref, rpc_info, ___void_buf, dfd, mode, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mkdirat(int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_mkdirat(false, false, dfd, mode, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mkdirat(rref_t __rref, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_mkdirat(false, false, __rref, dfd, mode, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_link(unsigned long long __rpc_info, void *__buf, int old_pfd, int new_pfd);


extern int __actvcapcall_fscall_vfs_link(rref_t __rref, unsigned long long __rpc_info, void *__buf, int old_pfd, int new_pfd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_link(bool is_xact_fwd, bool is_xact_allow_refwd, int old_pfd, int new_pfd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_link;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_link(rpc_info, ___void_buf, old_pfd, new_pfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_link(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int old_pfd, int new_pfd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_link;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_link(__rref, rpc_info, ___void_buf, old_pfd, new_pfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_link(int old_pfd, int new_pfd, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_link(false, false, old_pfd, new_pfd, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_link(rref_t __rref, int old_pfd, int new_pfd, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_link(false, false, __rref, old_pfd, new_pfd, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_unlink(unsigned long long __rpc_info, void *__buf, int dfd, unsigned int flag, void *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_unlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned int flag, void *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_unlink(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, unsigned int flag, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_unlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_unlink(rpc_info, ___void_buf, dfd, flag, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_unlink(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, unsigned int flag, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_unlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_unlink(__rref, rpc_info, ___void_buf, dfd, flag, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_unlink(int dfd, unsigned int flag, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_unlink(false, false, dfd, flag, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_unlink(rref_t __rref, int dfd, unsigned int flag, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_unlink(false, false, __rref, dfd, flag, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_symlink(unsigned long long __rpc_info, void *__buf, int dfd, const void *target, unsigned int tarlen, void *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_symlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, const void *target, unsigned int tarlen, void *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_symlink(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, const void *target, unsigned int tarlen, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_symlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_symlink(rpc_info, ___void_buf, dfd, target, tarlen, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_symlink(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, const void *target, unsigned int tarlen, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_symlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_symlink(__rref, rpc_info, ___void_buf, dfd, target, tarlen, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_symlink(int dfd, const void *target, unsigned int tarlen, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_symlink(false, false, dfd, target, tarlen, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_symlink(rref_t __rref, int dfd, const void *target, unsigned int tarlen, void *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_symlink(false, false, __rref, dfd, target, tarlen, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_getxattr(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned int pcnode_idx, unsigned int cnode_idx, int dfd, struct sysif_getxattr_args sga, unsigned int flags, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_getxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned int pcnode_idx, unsigned int cnode_idx, int dfd, struct sysif_getxattr_args sga, unsigned int flags, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_getxattr(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int pcnode_idx, unsigned int cnode_idx, int dfd, struct sysif_getxattr_args sga, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_getxattr *__ret)
{
	const unsigned long __callno = __fs_method_vfs_getxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysif_getxattr_args), __arch_actv_rpc_stksz_alignment(struct sysif_getxattr_args));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_getxattr(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, pcnode_idx, cnode_idx, dfd, sga, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_getxattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int pcnode_idx, unsigned int cnode_idx, int dfd, struct sysif_getxattr_args sga, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_getxattr *__ret)
{
	const unsigned long __callno = __fs_method_vfs_getxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysif_getxattr_args), __arch_actv_rpc_stksz_alignment(struct sysif_getxattr_args));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_getxattr(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, pcnode_idx, cnode_idx, dfd, sga, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_getxattr(unsigned int pcnode_idx, unsigned int cnode_idx, int dfd, struct sysif_getxattr_args sga, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_getxattr *__ret)
{
	return actvxactcall_fscall_vfs_getxattr(false, false, pcnode_idx, cnode_idx, dfd, sga, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_getxattr(rref_t __rref, unsigned int pcnode_idx, unsigned int cnode_idx, int dfd, struct sysif_getxattr_args sga, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_getxattr *__ret)
{
	return actvxactcapcall_fscall_vfs_getxattr(false, false, __rref, pcnode_idx, cnode_idx, dfd, sga, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_fscall_vfs_fgetxattr(unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen, void *value, size_t size);


extern int __actvcapcall_fscall_vfs_fgetxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen, void *value, size_t size);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fgetxattr(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const char *name, size_t namelen, void *value, size_t size, struct __actvret_fscall_vfs_fgetxattr *__ret)
{
	const unsigned long __callno = __fs_method_vfs_fgetxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fgetxattr(rpc_info, __ret, fd, name, namelen, value, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fgetxattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const char *name, size_t namelen, void *value, size_t size, struct __actvret_fscall_vfs_fgetxattr *__ret)
{
	const unsigned long __callno = __fs_method_vfs_fgetxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fgetxattr(__rref, rpc_info, __ret, fd, name, namelen, value, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fgetxattr(int fd, const char *name, size_t namelen, void *value, size_t size, struct __actvret_fscall_vfs_fgetxattr *__ret)
{
	return actvxactcall_fscall_vfs_fgetxattr(false, false, fd, name, namelen, value, size, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fgetxattr(rref_t __rref, int fd, const char *name, size_t namelen, void *value, size_t size, struct __actvret_fscall_vfs_fgetxattr *__ret)
{
	return actvxactcapcall_fscall_vfs_fgetxattr(false, false, __rref, fd, name, namelen, value, size, __ret);
}

extern int __actvcall_fscall_vfs_setxattr(unsigned long long __rpc_info, void *__buf, int dfd, const char *name, size_t namelen, const char *value, size_t size, int flags, unsigned int walk_flags, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_setxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, const char *name, size_t namelen, const char *value, size_t size, int flags, unsigned int walk_flags, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_setxattr(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, const char *name, size_t namelen, const char *value, size_t size, int flags, unsigned int walk_flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_setxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_setxattr(rpc_info, ___void_buf, dfd, name, namelen, value, size, flags, walk_flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_setxattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, const char *name, size_t namelen, const char *value, size_t size, int flags, unsigned int walk_flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_setxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_setxattr(__rref, rpc_info, ___void_buf, dfd, name, namelen, value, size, flags, walk_flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_setxattr(int dfd, const char *name, size_t namelen, const char *value, size_t size, int flags, unsigned int walk_flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_setxattr(false, false, dfd, name, namelen, value, size, flags, walk_flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_setxattr(rref_t __rref, int dfd, const char *name, size_t namelen, const char *value, size_t size, int flags, unsigned int walk_flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_setxattr(false, false, __rref, dfd, name, namelen, value, size, flags, walk_flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_fsetxattr(unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen, const char *value, size_t size, int flags);


extern int __actvcapcall_fscall_vfs_fsetxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen, const char *value, size_t size, int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fsetxattr(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const char *name, size_t namelen, const char *value, size_t size, int flags)
{
	const unsigned long __callno = __fs_method_vfs_fsetxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fsetxattr(rpc_info, NULL, fd, name, namelen, value, size, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fsetxattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const char *name, size_t namelen, const char *value, size_t size, int flags)
{
	const unsigned long __callno = __fs_method_vfs_fsetxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fsetxattr(__rref, rpc_info, NULL, fd, name, namelen, value, size, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fsetxattr(int fd, const char *name, size_t namelen, const char *value, size_t size, int flags)
{
	return actvxactcall_fscall_vfs_fsetxattr(false, false, fd, name, namelen, value, size, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fsetxattr(rref_t __rref, int fd, const char *name, size_t namelen, const char *value, size_t size, int flags)
{
	return actvxactcapcall_fscall_vfs_fsetxattr(false, false, __rref, fd, name, namelen, value, size, flags);
}

extern int __actvcall_fscall_vfs_listxattr(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, char *list, size_t size, unsigned int flags, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_listxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, char *list, size_t size, unsigned int flags, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_listxattr(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, char *list, size_t size, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_listxattr *__ret)
{
	const unsigned long __callno = __fs_method_vfs_listxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_listxattr(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dfd, list, size, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_listxattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, char *list, size_t size, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_listxattr *__ret)
{
	const unsigned long __callno = __fs_method_vfs_listxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_listxattr(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dfd, list, size, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_listxattr(int dfd, char *list, size_t size, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_listxattr *__ret)
{
	return actvxactcall_fscall_vfs_listxattr(false, false, dfd, list, size, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_listxattr(rref_t __rref, int dfd, char *list, size_t size, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_fscall_vfs_listxattr *__ret)
{
	return actvxactcapcall_fscall_vfs_listxattr(false, false, __rref, dfd, list, size, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_fscall_vfs_flistxattr(unsigned long long __rpc_info, void *__buf, int fd, char *list, size_t size);


extern int __actvcapcall_fscall_vfs_flistxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, char *list, size_t size);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_flistxattr(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, char *list, size_t size, struct __actvret_fscall_vfs_flistxattr *__ret)
{
	const unsigned long __callno = __fs_method_vfs_flistxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_flistxattr(rpc_info, __ret, fd, list, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_flistxattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, char *list, size_t size, struct __actvret_fscall_vfs_flistxattr *__ret)
{
	const unsigned long __callno = __fs_method_vfs_flistxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_flistxattr(__rref, rpc_info, __ret, fd, list, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_flistxattr(int fd, char *list, size_t size, struct __actvret_fscall_vfs_flistxattr *__ret)
{
	return actvxactcall_fscall_vfs_flistxattr(false, false, fd, list, size, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_flistxattr(rref_t __rref, int fd, char *list, size_t size, struct __actvret_fscall_vfs_flistxattr *__ret)
{
	return actvxactcapcall_fscall_vfs_flistxattr(false, false, __rref, fd, list, size, __ret);
}

extern int __actvcall_fscall_vfs_removexattr(unsigned long long __rpc_info, void *__buf, int dfd, const char *name, size_t namelen, unsigned int flags, char *newpath, char *new_server, int *me_idx);


extern int __actvcapcall_fscall_vfs_removexattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, const char *name, size_t namelen, unsigned int flags, char *newpath, char *new_server, int *me_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_removexattr(bool is_xact_fwd, bool is_xact_allow_refwd, int dfd, const char *name, size_t namelen, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_removexattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_removexattr(rpc_info, ___void_buf, dfd, name, namelen, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_removexattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int dfd, const char *name, size_t namelen, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_removexattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int*), __arch_actv_rpc_stksz_alignment(int*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_removexattr(__rref, rpc_info, ___void_buf, dfd, name, namelen, flags, newpath, new_server, me_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_removexattr(int dfd, const char *name, size_t namelen, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_removexattr(false, false, dfd, name, namelen, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_removexattr(rref_t __rref, int dfd, const char *name, size_t namelen, unsigned int flags, char *newpath, char *new_server, int *me_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_removexattr(false, false, __rref, dfd, name, namelen, flags, newpath, new_server, me_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_fremovexattr(unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen);


extern int __actvcapcall_fscall_vfs_fremovexattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fremovexattr(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const char *name, size_t namelen)
{
	const unsigned long __callno = __fs_method_vfs_fremovexattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fremovexattr(rpc_info, NULL, fd, name, namelen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fremovexattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const char *name, size_t namelen)
{
	const unsigned long __callno = __fs_method_vfs_fremovexattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fremovexattr(__rref, rpc_info, NULL, fd, name, namelen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fremovexattr(int fd, const char *name, size_t namelen)
{
	return actvxactcall_fscall_vfs_fremovexattr(false, false, fd, name, namelen);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fremovexattr(rref_t __rref, int fd, const char *name, size_t namelen)
{
	return actvxactcapcall_fscall_vfs_fremovexattr(false, false, __rref, fd, name, namelen);
}

extern int __actvcall_fscall_vfs_iommap(unsigned long long __rpc_info, void *__buf, int fd, rref_t vs_rref, unsigned int vs_cnode_idx, uintptr_t vaddr, size_t aligned_len, unsigned int prot, unsigned int flags, long long offset);


extern int __actvcapcall_fscall_vfs_iommap(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, rref_t vs_rref, unsigned int vs_cnode_idx, uintptr_t vaddr, size_t aligned_len, unsigned int prot, unsigned int flags, long long offset);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_iommap(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, rref_t vs_rref, unsigned int vs_cnode_idx, uintptr_t vaddr, size_t aligned_len, unsigned int prot, unsigned int flags, long long offset, struct __actvret_fscall_vfs_iommap *__ret)
{
	const unsigned long __callno = __fs_method_vfs_iommap;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_iommap(rpc_info, __ret, fd, vs_rref, vs_cnode_idx, vaddr, aligned_len, prot, flags, offset);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_iommap(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, rref_t vs_rref, unsigned int vs_cnode_idx, uintptr_t vaddr, size_t aligned_len, unsigned int prot, unsigned int flags, long long offset, struct __actvret_fscall_vfs_iommap *__ret)
{
	const unsigned long __callno = __fs_method_vfs_iommap;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_iommap(__rref, rpc_info, __ret, fd, vs_rref, vs_cnode_idx, vaddr, aligned_len, prot, flags, offset);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_iommap(int fd, rref_t vs_rref, unsigned int vs_cnode_idx, uintptr_t vaddr, size_t aligned_len, unsigned int prot, unsigned int flags, long long offset, struct __actvret_fscall_vfs_iommap *__ret)
{
	return actvxactcall_fscall_vfs_iommap(false, false, fd, vs_rref, vs_cnode_idx, vaddr, aligned_len, prot, flags, offset, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_iommap(rref_t __rref, int fd, rref_t vs_rref, unsigned int vs_cnode_idx, uintptr_t vaddr, size_t aligned_len, unsigned int prot, unsigned int flags, long long offset, struct __actvret_fscall_vfs_iommap *__ret)
{
	return actvxactcapcall_fscall_vfs_iommap(false, false, __rref, fd, vs_rref, vs_cnode_idx, vaddr, aligned_len, prot, flags, offset, __ret);
}

extern int __actvcall_fscall_vfs_mmap_create(unsigned long long __rpc_info, void *__buf, int fd, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot, unsigned int flags);


extern int __actvcapcall_fscall_vfs_mmap_create(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot, unsigned int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mmap_create(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot, unsigned int flags, struct __actvret_fscall_vfs_mmap_create *__ret)
{
	const unsigned long __callno = __fs_method_vfs_mmap_create;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mmap_create(rpc_info, __ret, fd, offset, len, cnode_idx, prot, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mmap_create(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot, unsigned int flags, struct __actvret_fscall_vfs_mmap_create *__ret)
{
	const unsigned long __callno = __fs_method_vfs_mmap_create;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mmap_create(__rref, rpc_info, __ret, fd, offset, len, cnode_idx, prot, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mmap_create(int fd, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot, unsigned int flags, struct __actvret_fscall_vfs_mmap_create *__ret)
{
	return actvxactcall_fscall_vfs_mmap_create(false, false, fd, offset, len, cnode_idx, prot, flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mmap_create(rref_t __rref, int fd, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot, unsigned int flags, struct __actvret_fscall_vfs_mmap_create *__ret)
{
	return actvxactcapcall_fscall_vfs_mmap_create(false, false, __rref, fd, offset, len, cnode_idx, prot, flags, __ret);
}

extern int __actvcall_fscall_vfs_mmap_release_file(unsigned long long __rpc_info, void *__buf, int fid, unsigned int cnode_idx);


extern int __actvcapcall_fscall_vfs_mmap_release_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mmap_release_file(bool is_xact_fwd, bool is_xact_allow_refwd, int fid, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_mmap_release_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mmap_release_file(rpc_info, NULL, fid, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mmap_release_file(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fid, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_mmap_release_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mmap_release_file(__rref, rpc_info, NULL, fid, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mmap_release_file(int fid, unsigned int cnode_idx)
{
	return actvxactcall_fscall_vfs_mmap_release_file(false, false, fid, cnode_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mmap_release_file(rref_t __rref, int fid, unsigned int cnode_idx)
{
	return actvxactcapcall_fscall_vfs_mmap_release_file(false, false, __rref, fid, cnode_idx);
}

extern int __actvcall_fscall_vfs_mmap_change(unsigned long long __rpc_info, void *__buf, int fid, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot);


extern int __actvcapcall_fscall_vfs_mmap_change(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mmap_change(bool is_xact_fwd, bool is_xact_allow_refwd, int fid, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot)
{
	const unsigned long __callno = __fs_method_vfs_mmap_change;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mmap_change(rpc_info, NULL, fid, offset, len, cnode_idx, prot);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mmap_change(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fid, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot)
{
	const unsigned long __callno = __fs_method_vfs_mmap_change;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mmap_change(__rref, rpc_info, NULL, fid, offset, len, cnode_idx, prot);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mmap_change(int fid, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot)
{
	return actvxactcall_fscall_vfs_mmap_change(false, false, fid, offset, len, cnode_idx, prot);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mmap_change(rref_t __rref, int fid, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot)
{
	return actvxactcapcall_fscall_vfs_mmap_change(false, false, __rref, fid, offset, len, cnode_idx, prot);
}

extern int __actvcall_fscall_vfs_mmap_fill_page(unsigned long long __rpc_info, void *__buf, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, unsigned long long flags);


extern int __actvcapcall_fscall_vfs_mmap_fill_page(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, unsigned long long flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mmap_fill_page(bool is_xact_fwd, bool is_xact_allow_refwd, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, unsigned long long flags, struct __actvret_fscall_vfs_mmap_fill_page *__ret)
{
	const unsigned long __callno = __fs_method_vfs_mmap_fill_page;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mmap_fill_page(rpc_info, __ret, fid, node_page_idx, cnode_idx, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mmap_fill_page(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, unsigned long long flags, struct __actvret_fscall_vfs_mmap_fill_page *__ret)
{
	const unsigned long __callno = __fs_method_vfs_mmap_fill_page;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mmap_fill_page(__rref, rpc_info, __ret, fid, node_page_idx, cnode_idx, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mmap_fill_page(int fid, unsigned long long node_page_idx, unsigned int cnode_idx, unsigned long long flags, struct __actvret_fscall_vfs_mmap_fill_page *__ret)
{
	return actvxactcall_fscall_vfs_mmap_fill_page(false, false, fid, node_page_idx, cnode_idx, flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mmap_fill_page(rref_t __rref, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, unsigned long long flags, struct __actvret_fscall_vfs_mmap_fill_page *__ret)
{
	return actvxactcapcall_fscall_vfs_mmap_fill_page(false, false, __rref, fid, node_page_idx, cnode_idx, flags, __ret);
}

extern int __actvcall_fscall_vfs_mmap_fetch_page(unsigned long long __rpc_info, void *__buf, int fid, unsigned long long node_page_idx, unsigned int cnode_idx);


extern int __actvcapcall_fscall_vfs_mmap_fetch_page(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, unsigned long long node_page_idx, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mmap_fetch_page(bool is_xact_fwd, bool is_xact_allow_refwd, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, struct __actvret_fscall_vfs_mmap_fetch_page *__ret)
{
	const unsigned long __callno = __fs_method_vfs_mmap_fetch_page;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mmap_fetch_page(rpc_info, __ret, fid, node_page_idx, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mmap_fetch_page(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, struct __actvret_fscall_vfs_mmap_fetch_page *__ret)
{
	const unsigned long __callno = __fs_method_vfs_mmap_fetch_page;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mmap_fetch_page(__rref, rpc_info, __ret, fid, node_page_idx, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mmap_fetch_page(int fid, unsigned long long node_page_idx, unsigned int cnode_idx, struct __actvret_fscall_vfs_mmap_fetch_page *__ret)
{
	return actvxactcall_fscall_vfs_mmap_fetch_page(false, false, fid, node_page_idx, cnode_idx, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mmap_fetch_page(rref_t __rref, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, struct __actvret_fscall_vfs_mmap_fetch_page *__ret)
{
	return actvxactcapcall_fscall_vfs_mmap_fetch_page(false, false, __rref, fid, node_page_idx, cnode_idx, __ret);
}

extern int __actvcall_fscall_vfs_mmap_change_page(unsigned long long __rpc_info, void *__buf, unsigned int index, unsigned long long dev_id, unsigned long long node_page_idx, unsigned int flag);


extern int __actvcapcall_fscall_vfs_mmap_change_page(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int index, unsigned long long dev_id, unsigned long long node_page_idx, unsigned int flag);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mmap_change_page(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int index, unsigned long long dev_id, unsigned long long node_page_idx, unsigned int flag)
{
	const unsigned long __callno = __fs_method_vfs_mmap_change_page;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mmap_change_page(rpc_info, NULL, index, dev_id, node_page_idx, flag);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mmap_change_page(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int index, unsigned long long dev_id, unsigned long long node_page_idx, unsigned int flag)
{
	const unsigned long __callno = __fs_method_vfs_mmap_change_page;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mmap_change_page(__rref, rpc_info, NULL, index, dev_id, node_page_idx, flag);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mmap_change_page(unsigned int index, unsigned long long dev_id, unsigned long long node_page_idx, unsigned int flag)
{
	return actvxactcall_fscall_vfs_mmap_change_page(false, false, index, dev_id, node_page_idx, flag);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mmap_change_page(rref_t __rref, unsigned int index, unsigned long long dev_id, unsigned long long node_page_idx, unsigned int flag)
{
	return actvxactcapcall_fscall_vfs_mmap_change_page(false, false, __rref, index, dev_id, node_page_idx, flag);
}

extern int __actvcall_fscall_vfs_mmap_fallocate(unsigned long long __rpc_info, void *__buf, int fid, unsigned long long offset, unsigned long long length, int mode, unsigned int cnode_idx);


extern int __actvcapcall_fscall_vfs_mmap_fallocate(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, unsigned long long offset, unsigned long long length, int mode, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_mmap_fallocate(bool is_xact_fwd, bool is_xact_allow_refwd, int fid, unsigned long long offset, unsigned long long length, int mode, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_mmap_fallocate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_mmap_fallocate(rpc_info, NULL, fid, offset, length, mode, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_mmap_fallocate(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fid, unsigned long long offset, unsigned long long length, int mode, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_mmap_fallocate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_mmap_fallocate(__rref, rpc_info, NULL, fid, offset, length, mode, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_mmap_fallocate(int fid, unsigned long long offset, unsigned long long length, int mode, unsigned int cnode_idx)
{
	return actvxactcall_fscall_vfs_mmap_fallocate(false, false, fid, offset, length, mode, cnode_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_mmap_fallocate(rref_t __rref, int fid, unsigned long long offset, unsigned long long length, int mode, unsigned int cnode_idx)
{
	return actvxactcapcall_fscall_vfs_mmap_fallocate(false, false, __rref, fid, offset, length, mode, cnode_idx);
}

extern int __actvcall_fscall_vfs_gfd_table_update(unsigned long long __rpc_info, void *__buf, int fd, int remote_index, unsigned int cnode_idx);


extern int __actvcapcall_fscall_vfs_gfd_table_update(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int remote_index, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_gfd_table_update(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int remote_index, unsigned int cnode_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_update;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_gfd_table_update(rpc_info, ___void_buf, fd, remote_index, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_gfd_table_update(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int remote_index, unsigned int cnode_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_update;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_gfd_table_update(__rref, rpc_info, ___void_buf, fd, remote_index, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_gfd_table_update(int fd, int remote_index, unsigned int cnode_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_fscall_vfs_gfd_table_update(false, false, fd, remote_index, cnode_idx, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_gfd_table_update(rref_t __rref, int fd, int remote_index, unsigned int cnode_idx, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_fscall_vfs_gfd_table_update(false, false, __rref, fd, remote_index, cnode_idx, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_fscall_vfs_gfd_table_remove(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx);


extern int __actvcapcall_fscall_vfs_gfd_table_remove(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_gfd_table_remove(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_remove;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_gfd_table_remove(rpc_info, NULL, fd, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_gfd_table_remove(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_remove;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_gfd_table_remove(__rref, rpc_info, NULL, fd, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_gfd_table_remove(int fd, unsigned int cnode_idx)
{
	return actvxactcall_fscall_vfs_gfd_table_remove(false, false, fd, cnode_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_gfd_table_remove(rref_t __rref, int fd, unsigned int cnode_idx)
{
	return actvxactcapcall_fscall_vfs_gfd_table_remove(false, false, __rref, fd, cnode_idx);
}

extern int __actvcall_fscall_vfs_gfd_table_expand(unsigned long long __rpc_info, void *__buf, unsigned int new_size);


extern int __actvcapcall_fscall_vfs_gfd_table_expand(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int new_size);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_gfd_table_expand(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int new_size)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_expand;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_gfd_table_expand(rpc_info, NULL, new_size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_gfd_table_expand(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int new_size)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_expand;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_gfd_table_expand(__rref, rpc_info, NULL, new_size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_gfd_table_expand(unsigned int new_size)
{
	return actvxactcall_fscall_vfs_gfd_table_expand(false, false, new_size);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_gfd_table_expand(rref_t __rref, unsigned int new_size)
{
	return actvxactcapcall_fscall_vfs_gfd_table_expand(false, false, __rref, new_size);
}

extern int __actvcall_fscall_vfs_gfd_table_acquire(unsigned long long __rpc_info, void *__buf, int start, int type, unsigned int cnode_idx);


extern int __actvcapcall_fscall_vfs_gfd_table_acquire(rref_t __rref, unsigned long long __rpc_info, void *__buf, int start, int type, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_gfd_table_acquire(bool is_xact_fwd, bool is_xact_allow_refwd, int start, int type, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_acquire;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_gfd_table_acquire(rpc_info, NULL, start, type, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_gfd_table_acquire(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int start, int type, unsigned int cnode_idx)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_acquire;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_gfd_table_acquire(__rref, rpc_info, NULL, start, type, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_gfd_table_acquire(int start, int type, unsigned int cnode_idx)
{
	return actvxactcall_fscall_vfs_gfd_table_acquire(false, false, start, type, cnode_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_gfd_table_acquire(rref_t __rref, int start, int type, unsigned int cnode_idx)
{
	return actvxactcapcall_fscall_vfs_gfd_table_acquire(false, false, __rref, start, type, cnode_idx);
}

extern int __actvcall_fscall_vfs_gfd_table_release(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_fscall_vfs_gfd_table_release(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_gfd_table_release(bool is_xact_fwd, bool is_xact_allow_refwd, int fd)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_release;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_gfd_table_release(rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_gfd_table_release(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_release;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_gfd_table_release(__rref, rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_gfd_table_release(int fd)
{
	return actvxactcall_fscall_vfs_gfd_table_release(false, false, fd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_gfd_table_release(rref_t __rref, int fd)
{
	return actvxactcapcall_fscall_vfs_gfd_table_release(false, false, __rref, fd);
}

extern int __actvcall_fscall_vfs_gfd_table_replace(unsigned long long __rpc_info, void *__buf, int fd, int type);


extern int __actvcapcall_fscall_vfs_gfd_table_replace(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int type);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_gfd_table_replace(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int type)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_replace;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_gfd_table_replace(rpc_info, NULL, fd, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_gfd_table_replace(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int type)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_replace;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_gfd_table_replace(__rref, rpc_info, NULL, fd, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_gfd_table_replace(int fd, int type)
{
	return actvxactcall_fscall_vfs_gfd_table_replace(false, false, fd, type);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_gfd_table_replace(rref_t __rref, int fd, int type)
{
	return actvxactcapcall_fscall_vfs_gfd_table_replace(false, false, __rref, fd, type);
}

extern int __actvcall_fscall_vfs_gfd_table_fault(unsigned long long __rpc_info, void *__buf, int fd, char *pathname, int pathlen);


extern int __actvcapcall_fscall_vfs_gfd_table_fault(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, char *pathname, int pathlen);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_gfd_table_fault(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, char *pathname, int pathlen)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_fault;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_gfd_table_fault(rpc_info, NULL, fd, pathname, pathlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_gfd_table_fault(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, char *pathname, int pathlen)
{
	const unsigned long __callno = __fs_method_vfs_gfd_table_fault;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_gfd_table_fault(__rref, rpc_info, NULL, fd, pathname, pathlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_gfd_table_fault(int fd, char *pathname, int pathlen)
{
	return actvxactcall_fscall_vfs_gfd_table_fault(false, false, fd, pathname, pathlen);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_gfd_table_fault(rref_t __rref, int fd, char *pathname, int pathlen)
{
	return actvxactcapcall_fscall_vfs_gfd_table_fault(false, false, __rref, fd, pathname, pathlen);
}

extern int __actvcall_fscall_vfs_anon_register_devhost(unsigned long long __rpc_info, void *__buf, uref_t dh_ap_uref);


extern int __actvcapcall_fscall_vfs_anon_register_devhost(rref_t __rref, unsigned long long __rpc_info, void *__buf, uref_t dh_ap_uref);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_anon_register_devhost(bool is_xact_fwd, bool is_xact_allow_refwd, uref_t dh_ap_uref)
{
	const unsigned long __callno = __fs_method_vfs_anon_register_devhost;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_anon_register_devhost(rpc_info, NULL, dh_ap_uref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_anon_register_devhost(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, uref_t dh_ap_uref)
{
	const unsigned long __callno = __fs_method_vfs_anon_register_devhost;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_anon_register_devhost(__rref, rpc_info, NULL, dh_ap_uref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_anon_register_devhost(uref_t dh_ap_uref)
{
	return actvxactcall_fscall_vfs_anon_register_devhost(false, false, dh_ap_uref);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_anon_register_devhost(rref_t __rref, uref_t dh_ap_uref)
{
	return actvxactcapcall_fscall_vfs_anon_register_devhost(false, false, __rref, dh_ap_uref);
}

extern int __actvcall_fscall_vfs_get_unused_fd(unsigned long long __rpc_info, void *__buf, unsigned int flags);


extern int __actvcapcall_fscall_vfs_get_unused_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int flags);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_get_unused_fd(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int flags)
{
	const unsigned long __callno = __fs_method_vfs_get_unused_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_get_unused_fd(rpc_info, NULL, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_get_unused_fd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int flags)
{
	const unsigned long __callno = __fs_method_vfs_get_unused_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_get_unused_fd(__rref, rpc_info, NULL, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_get_unused_fd(unsigned int flags)
{
	return actvxactcall_fscall_vfs_get_unused_fd(false, false, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_get_unused_fd(rref_t __rref, unsigned int flags)
{
	return actvxactcapcall_fscall_vfs_get_unused_fd(false, false, __rref, flags);
}

extern int __actvcall_fscall_vfs_put_unused_fd(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_fscall_vfs_put_unused_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_put_unused_fd(bool is_xact_fwd, bool is_xact_allow_refwd, int fd)
{
	const unsigned long __callno = __fs_method_vfs_put_unused_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_put_unused_fd(rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_put_unused_fd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd)
{
	const unsigned long __callno = __fs_method_vfs_put_unused_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_put_unused_fd(__rref, rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_put_unused_fd(int fd)
{
	return actvxactcall_fscall_vfs_put_unused_fd(false, false, fd);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_put_unused_fd(rref_t __rref, int fd)
{
	return actvxactcapcall_fscall_vfs_put_unused_fd(false, false, __rref, fd);
}

extern int __actvcall_fscall_vfs_fd_info_update(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long file_id);


extern int __actvcapcall_fscall_vfs_fd_info_update(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long file_id);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_fd_info_update(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, unsigned long long file_id)
{
	const unsigned long __callno = __fs_method_vfs_fd_info_update;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_fd_info_update(rpc_info, NULL, fd, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_fd_info_update(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, unsigned long long file_id)
{
	const unsigned long __callno = __fs_method_vfs_fd_info_update;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_fd_info_update(__rref, rpc_info, NULL, fd, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_fd_info_update(int fd, unsigned long long file_id)
{
	return actvxactcall_fscall_vfs_fd_info_update(false, false, fd, file_id);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_fd_info_update(rref_t __rref, int fd, unsigned long long file_id)
{
	return actvxactcapcall_fscall_vfs_fd_info_update(false, false, __rref, fd, file_id);
}

extern int __actvcall_fscall_vfs_get_root_path(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, char *buf, int buflen);


extern int __actvcapcall_fscall_vfs_get_root_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, char *buf, int buflen);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_get_root_path(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, char *buf, int buflen)
{
	const unsigned long __callno = __fs_method_vfs_get_root_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_get_root_path(rpc_info, NULL, cnode_idx, buf, buflen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_get_root_path(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, char *buf, int buflen)
{
	const unsigned long __callno = __fs_method_vfs_get_root_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_get_root_path(__rref, rpc_info, NULL, cnode_idx, buf, buflen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_get_root_path(unsigned int cnode_idx, char *buf, int buflen)
{
	return actvxactcall_fscall_vfs_get_root_path(false, false, cnode_idx, buf, buflen);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_get_root_path(rref_t __rref, unsigned int cnode_idx, char *buf, int buflen)
{
	return actvxactcapcall_fscall_vfs_get_root_path(false, false, __rref, cnode_idx, buf, buflen);
}

extern int __actvcall_fscall_vfs_transfs_fget(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_fscall_vfs_transfs_fget(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_transfs_fget(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, struct __actvret_fscall_vfs_transfs_fget *__ret)
{
	const unsigned long __callno = __fs_method_vfs_transfs_fget;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_transfs_fget(rpc_info, __ret, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_transfs_fget(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, struct __actvret_fscall_vfs_transfs_fget *__ret)
{
	const unsigned long __callno = __fs_method_vfs_transfs_fget;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_transfs_fget(__rref, rpc_info, __ret, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_transfs_fget(int fd, struct __actvret_fscall_vfs_transfs_fget *__ret)
{
	return actvxactcall_fscall_vfs_transfs_fget(false, false, fd, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_transfs_fget(rref_t __rref, int fd, struct __actvret_fscall_vfs_transfs_fget *__ret)
{
	return actvxactcapcall_fscall_vfs_transfs_fget(false, false, __rref, fd, __ret);
}

extern int __actvcall_fscall_vfs_do_trans_fget(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_fscall_vfs_do_trans_fget(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_do_trans_fget(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, struct __actvret_fscall_vfs_do_trans_fget *__ret)
{
	const unsigned long __callno = __fs_method_vfs_do_trans_fget;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_do_trans_fget(rpc_info, __ret, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_do_trans_fget(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, struct __actvret_fscall_vfs_do_trans_fget *__ret)
{
	const unsigned long __callno = __fs_method_vfs_do_trans_fget;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_do_trans_fget(__rref, rpc_info, __ret, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_do_trans_fget(int fd, struct __actvret_fscall_vfs_do_trans_fget *__ret)
{
	return actvxactcall_fscall_vfs_do_trans_fget(false, false, fd, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_do_trans_fget(rref_t __rref, int fd, struct __actvret_fscall_vfs_do_trans_fget *__ret)
{
	return actvxactcapcall_fscall_vfs_do_trans_fget(false, false, __rref, fd, __ret);
}

extern int __actvcall_fscall_vfs_transfs_fput(unsigned long long __rpc_info, void *__buf, unsigned int me_index, unsigned long long hm_filp);


extern int __actvcapcall_fscall_vfs_transfs_fput(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int me_index, unsigned long long hm_filp);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_transfs_fput(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int me_index, unsigned long long hm_filp)
{
	const unsigned long __callno = __fs_method_vfs_transfs_fput;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_transfs_fput(rpc_info, NULL, me_index, hm_filp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_transfs_fput(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int me_index, unsigned long long hm_filp)
{
	const unsigned long __callno = __fs_method_vfs_transfs_fput;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_transfs_fput(__rref, rpc_info, NULL, me_index, hm_filp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_transfs_fput(unsigned int me_index, unsigned long long hm_filp)
{
	return actvxactcall_fscall_vfs_transfs_fput(false, false, me_index, hm_filp);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_transfs_fput(rref_t __rref, unsigned int me_index, unsigned long long hm_filp)
{
	return actvxactcapcall_fscall_vfs_transfs_fput(false, false, __rref, me_index, hm_filp);
}

extern int __actvcall_fscall_vfs_do_trans_fput(unsigned long long __rpc_info, void *__buf, unsigned long long hm_filp);


extern int __actvcapcall_fscall_vfs_do_trans_fput(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long hm_filp);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_do_trans_fput(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long long hm_filp)
{
	const unsigned long __callno = __fs_method_vfs_do_trans_fput;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_do_trans_fput(rpc_info, NULL, hm_filp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_do_trans_fput(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long long hm_filp)
{
	const unsigned long __callno = __fs_method_vfs_do_trans_fput;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_do_trans_fput(__rref, rpc_info, NULL, hm_filp);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_do_trans_fput(unsigned long long hm_filp)
{
	return actvxactcall_fscall_vfs_do_trans_fput(false, false, hm_filp);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_do_trans_fput(rref_t __rref, unsigned long long hm_filp)
{
	return actvxactcapcall_fscall_vfs_do_trans_fput(false, false, __rref, hm_filp);
}

extern int __actvcall_fscall_vfs_read_mounts(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, char *buf, size_t buflen, char *srvname);


extern int __actvcapcall_fscall_vfs_read_mounts(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, char *buf, size_t buflen, char *srvname);


static inline int __attribute__((always_inline)) actvxactcall_fscall_vfs_read_mounts(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, char *buf, size_t buflen, char *srvname, struct __actvret_fscall_vfs_read_mounts *__ret)
{
	const unsigned long __callno = __fs_method_vfs_read_mounts;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_fscall_vfs_read_mounts(rpc_info, __ret, cnode_idx, buf, buflen, srvname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_fscall_vfs_read_mounts(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, char *buf, size_t buflen, char *srvname, struct __actvret_fscall_vfs_read_mounts *__ret)
{
	const unsigned long __callno = __fs_method_vfs_read_mounts;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_fscall_vfs_read_mounts(__rref, rpc_info, __ret, cnode_idx, buf, buflen, srvname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_fscall_vfs_read_mounts(unsigned int cnode_idx, char *buf, size_t buflen, char *srvname, struct __actvret_fscall_vfs_read_mounts *__ret)
{
	return actvxactcall_fscall_vfs_read_mounts(false, false, cnode_idx, buf, buflen, srvname, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_fscall_vfs_read_mounts(rref_t __rref, unsigned int cnode_idx, char *buf, size_t buflen, char *srvname, struct __actvret_fscall_vfs_read_mounts *__ret)
{
	return actvxactcapcall_fscall_vfs_read_mounts(false, false, __rref, cnode_idx, buf, buflen, srvname, __ret);
}

#endif
#ifdef SYSIF_GEN_IFACE
#include <hmkernel/compiler.h>
#include <asm/actv_rpc.h>
#include <hongmeng/errno.h>
#include <hongmeng/syscall.h>
#include <hongmeng/panic.h>
#include <libstrict/strict.h>
static int __used __noinline __opt_noframe __internal_rpccall_nobuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_FAST_SYSCALL(2, NOBUF, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccall_buf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_FAST_SYSCALL(2, SENDBUF, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccall_retbuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_FAST_SYSCALL(2, RETBUF, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccall_fallback(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_FAST_SYSCALL(2, FALLBACK, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_nobuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(NoBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_buf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(SendBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_retbuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(RetBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_fallback(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(, ret);
	return ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_procfs_create_data(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_procfs_create_data(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_procfs_create_data(unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode, struct procfs_ops_cb ops)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	struct procfs_ops_cb __maybe_unused __actv_local_var_ops = ops;
	__ret = ____actvcall_fscall_procfs_create_data(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_procfs_create_data(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode, struct procfs_ops_cb ops)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	struct procfs_ops_cb __maybe_unused __actv_local_var_ops = ops;
	__ret = ____actvcapcall_fscall_procfs_create_data(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_procfs_delete_data(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_procfs_delete_data(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_procfs_delete_data(unsigned long long __rpc_info, void *__buf, const char *pathname)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	__ret = ____actvcall_fscall_procfs_delete_data(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_procfs_delete_data(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	__ret = ____actvcapcall_fscall_procfs_delete_data(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_procfs_get_process_fds(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_procfs_get_process_fds(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_procfs_get_process_fds(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long *bitmap, unsigned int max_files)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused unsigned long long *__actv_local_var_bitmap = bitmap;
	unsigned int __maybe_unused __actv_local_var_max_files = max_files;
	__ret = ____actvcall_fscall_procfs_get_process_fds(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(bitmap, __actv_local_var_bitmap), __ARCH_ACTV_RPC_PASS_ARG(max_files, __actv_local_var_max_files));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_procfs_get_process_fds(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long *bitmap, unsigned int max_files)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused unsigned long long *__actv_local_var_bitmap = bitmap;
	unsigned int __maybe_unused __actv_local_var_max_files = max_files;
	__ret = ____actvcapcall_fscall_procfs_get_process_fds(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(bitmap, __actv_local_var_bitmap), __ARCH_ACTV_RPC_PASS_ARG(max_files, __actv_local_var_max_files));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_procfs_get_fd_mode(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_procfs_get_fd_mode(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_procfs_get_fd_mode(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_procfs_get_fd_mode(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_procfs_get_fd_mode(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_procfs_get_fd_mode(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_sysfs_create_file(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_sysfs_create_file(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_sysfs_create_file(unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode, struct sysfs_ops_cb ops)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	struct sysfs_ops_cb __maybe_unused __actv_local_var_ops = ops;
	__ret = ____actvcall_fscall_sysfs_create_file(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_sysfs_create_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode, struct sysfs_ops_cb ops)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	struct sysfs_ops_cb __maybe_unused __actv_local_var_ops = ops;
	__ret = ____actvcapcall_fscall_sysfs_create_file(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_sysfs_create_dir(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_sysfs_create_dir(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_sysfs_create_dir(unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcall_fscall_sysfs_create_dir(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_sysfs_create_dir(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcapcall_fscall_sysfs_create_dir(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_sysfs_create_symlink(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_sysfs_create_symlink(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_sysfs_create_symlink(unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcall_fscall_sysfs_create_symlink(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_sysfs_create_symlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname, unsigned int mode)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcapcall_fscall_sysfs_create_symlink(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_sysfs_delete(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_sysfs_delete(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_sysfs_delete(unsigned long long __rpc_info, void *__buf, const char *pathname)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	__ret = ____actvcall_fscall_sysfs_delete(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_sysfs_delete(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *pathname)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	__ret = ____actvcapcall_fscall_sysfs_delete(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_sysfs_notify(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_sysfs_notify(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_sysfs_notify(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_fscall_sysfs_notify(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_sysfs_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_fscall_sysfs_notify(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_clock_settime(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_clock_settime(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_clock_settime(unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	__ret = ____actvcall_fscall_clock_settime(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_clock_settime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	__ret = ____actvcapcall_fscall_clock_settime(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_clock_gettime(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_clock_gettime(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_clock_gettime(unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	__ret = ____actvcall_fscall_clock_gettime(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_clock_gettime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	__ret = ____actvcapcall_fscall_clock_gettime(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_clock_getres(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_clock_getres(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_clock_getres(unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	__ret = ____actvcall_fscall_clock_getres(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_clock_getres(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long tp)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	__ret = ____actvcapcall_fscall_clock_getres(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_clock_adjtime(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_clock_adjtime(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_clock_adjtime(unsigned long long __rpc_info, void *__buf, int fd, unsigned long tx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long __maybe_unused __actv_local_var_tx = tx;
	__ret = ____actvcall_fscall_clock_adjtime(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tx, __actv_local_var_tx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_clock_adjtime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long tx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long __maybe_unused __actv_local_var_tx = tx;
	__ret = ____actvcapcall_fscall_clock_adjtime(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tx, __actv_local_var_tx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_inotify_init1(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_inotify_init1(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_inotify_init1(unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_inotify_init1(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_inotify_init1(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_inotify_init1(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_fscall_inotify_add_watch(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_fscall_inotify_add_watch(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_inotify_add_watch(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int fd, unsigned int mask, int me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_mask = mask;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_inotify_add_watch(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(mask, __actv_local_var_mask), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_inotify_add_watch(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int fd, unsigned int mask, int me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_mask = mask;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_inotify_add_watch(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(mask, __actv_local_var_mask), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_inotify_rm_watch(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_inotify_rm_watch(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_inotify_rm_watch(unsigned long long __rpc_info, void *__buf, int fd, int wd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_wd = wd;
	__ret = ____actvcall_fscall_inotify_rm_watch(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_inotify_rm_watch(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int wd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_wd = wd;
	__ret = ____actvcapcall_fscall_inotify_rm_watch(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_fscall_inotify_add_watch_internal(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_fscall_inotify_add_watch_internal(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_inotify_add_watch_internal(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname)
{
	int __ret;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	struct fsnotify_mark_pars __maybe_unused __actv_local_var_pars = pars;
	__maybe_unused char *__actv_local_var_new_path = new_path;
	__maybe_unused char *__actv_local_var_srvname = srvname;
	__ret = ____actvcall_fscall_inotify_add_watch_internal(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(pars, __actv_local_var_pars), __ARCH_ACTV_RPC_PASS_ARG(new_path, __actv_local_var_new_path), __ARCH_ACTV_RPC_PASS_ARG(srvname, __actv_local_var_srvname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_inotify_add_watch_internal(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname)
{
	int __ret;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	struct fsnotify_mark_pars __maybe_unused __actv_local_var_pars = pars;
	__maybe_unused char *__actv_local_var_new_path = new_path;
	__maybe_unused char *__actv_local_var_srvname = srvname;
	__ret = ____actvcapcall_fscall_inotify_add_watch_internal(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(pars, __actv_local_var_pars), __ARCH_ACTV_RPC_PASS_ARG(new_path, __actv_local_var_new_path), __ARCH_ACTV_RPC_PASS_ARG(srvname, __actv_local_var_srvname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_inotify_rm_watch_internal(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_inotify_rm_watch_internal(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_inotify_rm_watch_internal(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	unsigned int __maybe_unused __actv_local_var_index = index;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	__ret = ____actvcall_fscall_inotify_rm_watch_internal(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(index, __actv_local_var_index), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_inotify_rm_watch_internal(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	unsigned int __maybe_unused __actv_local_var_index = index;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	__ret = ____actvcapcall_fscall_inotify_rm_watch_internal(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(index, __actv_local_var_index), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_inotify_notify(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_inotify_notify(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_inotify_notify(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_event = event;
	unsigned int __maybe_unused __actv_local_var_cookie = cookie;
	unsigned int __maybe_unused __actv_local_var_token = token;
	__ret = ____actvcall_fscall_inotify_notify(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event), __ARCH_ACTV_RPC_PASS_ARG(cookie, __actv_local_var_cookie), __ARCH_ACTV_RPC_PASS_ARG(token, __actv_local_var_token));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_inotify_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_event = event;
	unsigned int __maybe_unused __actv_local_var_cookie = cookie;
	unsigned int __maybe_unused __actv_local_var_token = token;
	__ret = ____actvcapcall_fscall_inotify_notify(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event), __ARCH_ACTV_RPC_PASS_ARG(cookie, __actv_local_var_cookie), __ARCH_ACTV_RPC_PASS_ARG(token, __actv_local_var_token));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_inotify_inode_destroyed(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_inotify_inode_destroyed(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_inotify_inode_destroyed(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_token = token;
	__ret = ____actvcall_fscall_inotify_inode_destroyed(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(token, __actv_local_var_token));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_inotify_inode_destroyed(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_token = token;
	__ret = ____actvcapcall_fscall_inotify_inode_destroyed(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(token, __actv_local_var_token));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_fanotify_init(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_fanotify_init(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_fanotify_init(unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_fanotify_init(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_fanotify_init(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_fanotify_init(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_fanotify_mark(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_fanotify_mark(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_fanotify_mark(unsigned long long __rpc_info, void *__buf, int fanotify_fd, unsigned int flags, uint64_t mask, int me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fanotify_fd = fanotify_fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	uint64_t __maybe_unused __actv_local_var_mask = mask;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_fanotify_mark(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fanotify_fd, __actv_local_var_fanotify_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(mask, __actv_local_var_mask), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_fanotify_mark(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fanotify_fd, unsigned int flags, uint64_t mask, int me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fanotify_fd = fanotify_fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	uint64_t __maybe_unused __actv_local_var_mask = mask;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_fanotify_mark(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fanotify_fd, __actv_local_var_fanotify_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(mask, __actv_local_var_mask), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_fscall_fanotify_mark_internal(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_fscall_fanotify_mark_internal(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_fanotify_mark_internal(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname)
{
	int __ret;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	struct fsnotify_mark_pars __maybe_unused __actv_local_var_pars = pars;
	__maybe_unused char *__actv_local_var_new_path = new_path;
	__maybe_unused char *__actv_local_var_srvname = srvname;
	__ret = ____actvcall_fscall_fanotify_mark_internal(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(pars, __actv_local_var_pars), __ARCH_ACTV_RPC_PASS_ARG(new_path, __actv_local_var_new_path), __ARCH_ACTV_RPC_PASS_ARG(srvname, __actv_local_var_srvname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_fanotify_mark_internal(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int *me_idx, unsigned int cnode_idx, unsigned int nsid, struct fsnotify_mark_pars pars, char *new_path, char *srvname)
{
	int __ret;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	struct fsnotify_mark_pars __maybe_unused __actv_local_var_pars = pars;
	__maybe_unused char *__actv_local_var_new_path = new_path;
	__maybe_unused char *__actv_local_var_srvname = srvname;
	__ret = ____actvcapcall_fscall_fanotify_mark_internal(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(pars, __actv_local_var_pars), __ARCH_ACTV_RPC_PASS_ARG(new_path, __actv_local_var_new_path), __ARCH_ACTV_RPC_PASS_ARG(srvname, __actv_local_var_srvname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_fanotify_rm_watch_internal(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_fanotify_rm_watch_internal(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_fanotify_rm_watch_internal(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fanotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id, unsigned int obj_type)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_fanotify_fd = fanotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	unsigned int __maybe_unused __actv_local_var_index = index;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned int __maybe_unused __actv_local_var_obj_type = obj_type;
	__ret = ____actvcall_fscall_fanotify_rm_watch_internal(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(fanotify_fd, __actv_local_var_fanotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(index, __actv_local_var_index), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(obj_type, __actv_local_var_obj_type));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_fanotify_rm_watch_internal(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fanotify_fd, int wd, unsigned int nsid, unsigned int index, unsigned long long dev_id, unsigned int obj_type)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_fanotify_fd = fanotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	unsigned int __maybe_unused __actv_local_var_index = index;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned int __maybe_unused __actv_local_var_obj_type = obj_type;
	__ret = ____actvcapcall_fscall_fanotify_rm_watch_internal(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(fanotify_fd, __actv_local_var_fanotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(index, __actv_local_var_index), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(obj_type, __actv_local_var_obj_type));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_fanotify_notify(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_fanotify_notify(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_fanotify_notify(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, int pid)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_event = event;
	unsigned int __maybe_unused __actv_local_var_cookie = cookie;
	unsigned int __maybe_unused __actv_local_var_token = token;
	int __maybe_unused __actv_local_var_pid = pid;
	__ret = ____actvcall_fscall_fanotify_notify(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event), __ARCH_ACTV_RPC_PASS_ARG(cookie, __actv_local_var_cookie), __ARCH_ACTV_RPC_PASS_ARG(token, __actv_local_var_token), __ARCH_ACTV_RPC_PASS_ARG(pid, __actv_local_var_pid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_fanotify_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int event, unsigned int cookie, unsigned int token, int pid)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_event = event;
	unsigned int __maybe_unused __actv_local_var_cookie = cookie;
	unsigned int __maybe_unused __actv_local_var_token = token;
	int __maybe_unused __actv_local_var_pid = pid;
	__ret = ____actvcapcall_fscall_fanotify_notify(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event), __ARCH_ACTV_RPC_PASS_ARG(cookie, __actv_local_var_cookie), __ARCH_ACTV_RPC_PASS_ARG(token, __actv_local_var_token), __ARCH_ACTV_RPC_PASS_ARG(pid, __actv_local_var_pid));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_fanotify_destroyed(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_fanotify_destroyed(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_fanotify_destroyed(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_token = token;
	__ret = ____actvcall_fscall_fanotify_destroyed(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(token, __actv_local_var_token));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_fanotify_destroyed(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int inotify_fd, int wd, unsigned int token)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_inotify_fd = inotify_fd;
	int __maybe_unused __actv_local_var_wd = wd;
	unsigned int __maybe_unused __actv_local_var_token = token;
	__ret = ____actvcapcall_fscall_fanotify_destroyed(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(inotify_fd, __actv_local_var_inotify_fd), __ARCH_ACTV_RPC_PASS_ARG(wd, __actv_local_var_wd), __ARCH_ACTV_RPC_PASS_ARG(token, __actv_local_var_token));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_fscall_fanotify_open(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_fscall_fanotify_open(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_fanotify_open(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, int fd, unsigned int flags, unsigned int mode, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_fanotify_open(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_fanotify_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, int fd, unsigned int flags, unsigned int mode, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_fanotify_open(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_endio_io_done(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_endio_io_done(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_endio_io_done(unsigned long long __rpc_info, void *__buf, unsigned long long dev_id)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	__ret = ____actvcall_fscall_endio_io_done(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_endio_io_done(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long dev_id)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	__ret = ____actvcapcall_fscall_endio_io_done(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_set_label(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_set_label(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_set_label(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long label)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_label = label;
	__ret = ____actvcall_fscall_vfs_set_label(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(label, __actv_local_var_label));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_set_label(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long label)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_label = label;
	__ret = ____actvcapcall_fscall_vfs_set_label(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(label, __actv_local_var_label));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_set_label_by_path(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_set_label_by_path(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_set_label_by_path(unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long label, int flag, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned long long __maybe_unused __actv_local_var_label = label;
	int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_set_label_by_path(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(label, __actv_local_var_label), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_set_label_by_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long label, int flag, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned long long __maybe_unused __actv_local_var_label = label;
	int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_set_label_by_path(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(label, __actv_local_var_label), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_get_label(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_get_label(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_get_label(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_fscall_vfs_get_label(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_get_label(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_fscall_vfs_get_label(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_init_audit(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_init_audit(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_init_audit(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_fscall_vfs_init_audit(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_init_audit(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_fscall_vfs_init_audit(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_add_audit_rule(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_add_audit_rule(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_add_audit_rule(unsigned long long __rpc_info, void *__buf, int dfd, unsigned short shm_rule_id, unsigned short shm_rule_num, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned short __maybe_unused __actv_local_var_shm_rule_id = shm_rule_id;
	unsigned short __maybe_unused __actv_local_var_shm_rule_num = shm_rule_num;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_add_audit_rule(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(shm_rule_id, __actv_local_var_shm_rule_id), __ARCH_ACTV_RPC_PASS_ARG(shm_rule_num, __actv_local_var_shm_rule_num), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_add_audit_rule(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned short shm_rule_id, unsigned short shm_rule_num, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned short __maybe_unused __actv_local_var_shm_rule_id = shm_rule_id;
	unsigned short __maybe_unused __actv_local_var_shm_rule_num = shm_rule_num;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_add_audit_rule(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(shm_rule_id, __actv_local_var_shm_rule_id), __ARCH_ACTV_RPC_PASS_ARG(shm_rule_num, __actv_local_var_shm_rule_num), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_del_audit_rule(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_del_audit_rule(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_del_audit_rule(unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long rule_id, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned long long __maybe_unused __actv_local_var_rule_id = rule_id;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_del_audit_rule(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(rule_id, __actv_local_var_rule_id), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_del_audit_rule(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long rule_id, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned long long __maybe_unused __actv_local_var_rule_id = rule_id;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_del_audit_rule(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(rule_id, __actv_local_var_rule_id), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_match_audit_watch_file(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_match_audit_watch_file(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_match_audit_watch_file(unsigned long long __rpc_info, void *__buf, unsigned long long rule_id, unsigned long long dev_id, unsigned int index)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_rule_id = rule_id;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned int __maybe_unused __actv_local_var_index = index;
	__ret = ____actvcall_fscall_vfs_match_audit_watch_file(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(rule_id, __actv_local_var_rule_id), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(index, __actv_local_var_index));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_match_audit_watch_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long rule_id, unsigned long long dev_id, unsigned int index)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_rule_id = rule_id;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned int __maybe_unused __actv_local_var_index = index;
	__ret = ____actvcapcall_fscall_vfs_match_audit_watch_file(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(rule_id, __actv_local_var_rule_id), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(index, __actv_local_var_index));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_match_audit_watch_dir(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_match_audit_watch_dir(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_match_audit_watch_dir(unsigned long long __rpc_info, void *__buf, unsigned long long rule_id, int audit_me_idx)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_rule_id = rule_id;
	int __maybe_unused __actv_local_var_audit_me_idx = audit_me_idx;
	__ret = ____actvcall_fscall_vfs_match_audit_watch_dir(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(rule_id, __actv_local_var_rule_id), __ARCH_ACTV_RPC_PASS_ARG(audit_me_idx, __actv_local_var_audit_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_match_audit_watch_dir(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long rule_id, int audit_me_idx)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_rule_id = rule_id;
	int __maybe_unused __actv_local_var_audit_me_idx = audit_me_idx;
	__ret = ____actvcapcall_fscall_vfs_match_audit_watch_dir(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(rule_id, __actv_local_var_rule_id), __ARCH_ACTV_RPC_PASS_ARG(audit_me_idx, __actv_local_var_audit_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_client_init(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_client_init(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_client_init(unsigned long long __rpc_info, void *__buf, uref_t uref, char *root_srvname, int buflen)
{
	int __ret;
	uref_t __maybe_unused __actv_local_var_uref = uref;
	__maybe_unused char *__actv_local_var_root_srvname = root_srvname;
	int __maybe_unused __actv_local_var_buflen = buflen;
	__ret = ____actvcall_fscall_vfs_client_init(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(uref, __actv_local_var_uref), __ARCH_ACTV_RPC_PASS_ARG(root_srvname, __actv_local_var_root_srvname), __ARCH_ACTV_RPC_PASS_ARG(buflen, __actv_local_var_buflen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_client_init(rref_t __rref, unsigned long long __rpc_info, void *__buf, uref_t uref, char *root_srvname, int buflen)
{
	int __ret;
	uref_t __maybe_unused __actv_local_var_uref = uref;
	__maybe_unused char *__actv_local_var_root_srvname = root_srvname;
	int __maybe_unused __actv_local_var_buflen = buflen;
	__ret = ____actvcapcall_fscall_vfs_client_init(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(uref, __actv_local_var_uref), __ARCH_ACTV_RPC_PASS_ARG(root_srvname, __actv_local_var_root_srvname), __ARCH_ACTV_RPC_PASS_ARG(buflen, __actv_local_var_buflen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_bind_update(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_bind_update(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_bind_update(unsigned long long __rpc_info, void *__buf, uref_t uref1, uref_t uref2)
{
	int __ret;
	uref_t __maybe_unused __actv_local_var_uref1 = uref1;
	uref_t __maybe_unused __actv_local_var_uref2 = uref2;
	__ret = ____actvcall_fscall_vfs_bind_update(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(uref1, __actv_local_var_uref1), __ARCH_ACTV_RPC_PASS_ARG(uref2, __actv_local_var_uref2));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_bind_update(rref_t __rref, unsigned long long __rpc_info, void *__buf, uref_t uref1, uref_t uref2)
{
	int __ret;
	uref_t __maybe_unused __actv_local_var_uref1 = uref1;
	uref_t __maybe_unused __actv_local_var_uref2 = uref2;
	__ret = ____actvcapcall_fscall_vfs_bind_update(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(uref1, __actv_local_var_uref1), __ARCH_ACTV_RPC_PASS_ARG(uref2, __actv_local_var_uref2));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_clone(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_clone(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_clone(unsigned long long __rpc_info, void *__buf, int old_fd, int new_fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_old_fd = old_fd;
	int __maybe_unused __actv_local_var_new_fd = new_fd;
	__ret = ____actvcall_fscall_vfs_clone(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(old_fd, __actv_local_var_old_fd), __ARCH_ACTV_RPC_PASS_ARG(new_fd, __actv_local_var_new_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_clone(rref_t __rref, unsigned long long __rpc_info, void *__buf, int old_fd, int new_fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_old_fd = old_fd;
	int __maybe_unused __actv_local_var_new_fd = new_fd;
	__ret = ____actvcapcall_fscall_vfs_clone(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(old_fd, __actv_local_var_old_fd), __ARCH_ACTV_RPC_PASS_ARG(new_fd, __actv_local_var_new_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_close(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_close(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_close(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_fscall_vfs_close(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_fscall_vfs_close(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_mount(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_mount(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mount(unsigned long long __rpc_info, void *__buf, int parent_fd, unsigned long long dev_id, unsigned long flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_parent_fd = parent_fd;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_mount(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(parent_fd, __actv_local_var_parent_fd), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mount(rref_t __rref, unsigned long long __rpc_info, void *__buf, int parent_fd, unsigned long long dev_id, unsigned long flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_parent_fd = parent_fd;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_mount(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(parent_fd, __actv_local_var_parent_fd), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_clone_mount_entry(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_clone_mount_entry(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_clone_mount_entry(unsigned long long __rpc_info, void *__buf, const char *dst, unsigned int dst_len, unsigned long flags, unsigned int cnode_idx, int child_me_idx, int orig_me_idx, int orig_fd, int recurse)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_dst = dst;
	unsigned int __maybe_unused __actv_local_var_dst_len = dst_len;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_child_me_idx = child_me_idx;
	int __maybe_unused __actv_local_var_orig_me_idx = orig_me_idx;
	int __maybe_unused __actv_local_var_orig_fd = orig_fd;
	int __maybe_unused __actv_local_var_recurse = recurse;
	__ret = ____actvcall_fscall_vfs_clone_mount_entry(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dst, __actv_local_var_dst), __ARCH_ACTV_RPC_PASS_ARG(dst_len, __actv_local_var_dst_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(child_me_idx, __actv_local_var_child_me_idx), __ARCH_ACTV_RPC_PASS_ARG(orig_me_idx, __actv_local_var_orig_me_idx), __ARCH_ACTV_RPC_PASS_ARG(orig_fd, __actv_local_var_orig_fd), __ARCH_ACTV_RPC_PASS_ARG(recurse, __actv_local_var_recurse));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_clone_mount_entry(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *dst, unsigned int dst_len, unsigned long flags, unsigned int cnode_idx, int child_me_idx, int orig_me_idx, int orig_fd, int recurse)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_dst = dst;
	unsigned int __maybe_unused __actv_local_var_dst_len = dst_len;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_child_me_idx = child_me_idx;
	int __maybe_unused __actv_local_var_orig_me_idx = orig_me_idx;
	int __maybe_unused __actv_local_var_orig_fd = orig_fd;
	int __maybe_unused __actv_local_var_recurse = recurse;
	__ret = ____actvcapcall_fscall_vfs_clone_mount_entry(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dst, __actv_local_var_dst), __ARCH_ACTV_RPC_PASS_ARG(dst_len, __actv_local_var_dst_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(child_me_idx, __actv_local_var_child_me_idx), __ARCH_ACTV_RPC_PASS_ARG(orig_me_idx, __actv_local_var_orig_me_idx), __ARCH_ACTV_RPC_PASS_ARG(orig_fd, __actv_local_var_orig_fd), __ARCH_ACTV_RPC_PASS_ARG(recurse, __actv_local_var_recurse));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_clone_mount_entry_from_orig_parent(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_clone_mount_entry_from_orig_parent(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_clone_mount_entry_from_orig_parent(unsigned long long __rpc_info, void *__buf, unsigned int nsid, int parent_me_idx, int orig_me_idx, unsigned long long dev_id, unsigned long flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	int __maybe_unused __actv_local_var_parent_me_idx = parent_me_idx;
	int __maybe_unused __actv_local_var_orig_me_idx = orig_me_idx;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_clone_mount_entry_from_orig_parent(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(parent_me_idx, __actv_local_var_parent_me_idx), __ARCH_ACTV_RPC_PASS_ARG(orig_me_idx, __actv_local_var_orig_me_idx), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_clone_mount_entry_from_orig_parent(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int nsid, int parent_me_idx, int orig_me_idx, unsigned long long dev_id, unsigned long flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	int __maybe_unused __actv_local_var_parent_me_idx = parent_me_idx;
	int __maybe_unused __actv_local_var_orig_me_idx = orig_me_idx;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_clone_mount_entry_from_orig_parent(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(parent_me_idx, __actv_local_var_parent_me_idx), __ARCH_ACTV_RPC_PASS_ARG(orig_me_idx, __actv_local_var_orig_me_idx), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(unsigned long long __rpc_info, void *__buf, unsigned int nsid, int orig_parent_me_idx, int child_me_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	int __maybe_unused __actv_local_var_orig_parent_me_idx = orig_parent_me_idx;
	int __maybe_unused __actv_local_var_child_me_idx = child_me_idx;
	__ret = ____actvcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(orig_parent_me_idx, __actv_local_var_orig_parent_me_idx), __ARCH_ACTV_RPC_PASS_ARG(child_me_idx, __actv_local_var_child_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int nsid, int orig_parent_me_idx, int child_me_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	int __maybe_unused __actv_local_var_orig_parent_me_idx = orig_parent_me_idx;
	int __maybe_unused __actv_local_var_child_me_idx = child_me_idx;
	__ret = ____actvcapcall_fscall_vfs_destroy_cloned_mount_entry_from_orig_parent(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(orig_parent_me_idx, __actv_local_var_orig_parent_me_idx), __ARCH_ACTV_RPC_PASS_ARG(child_me_idx, __actv_local_var_child_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_destroy_cloned_mount_entry(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_destroy_cloned_mount_entry(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_destroy_cloned_mount_entry(unsigned long long __rpc_info, void *__buf, int me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_destroy_cloned_mount_entry(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_destroy_cloned_mount_entry(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_destroy_cloned_mount_entry(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_check_mount(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_check_mount(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_check_mount(unsigned long long __rpc_info, void *__buf, int me_idx, int fd, int is_dir)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_is_dir = is_dir;
	__ret = ____actvcall_fscall_vfs_check_mount(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(is_dir, __actv_local_var_is_dir));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_check_mount(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, int fd, int is_dir)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_is_dir = is_dir;
	__ret = ____actvcapcall_fscall_vfs_check_mount(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(is_dir, __actv_local_var_is_dir));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_mountpoint_del_mount(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_mountpoint_del_mount(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mountpoint_del_mount(unsigned long long __rpc_info, void *__buf, void *mp, int me_idx, unsigned int nsid)
{
	int __ret;
	__maybe_unused void *__actv_local_var_mp = mp;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	__ret = ____actvcall_fscall_vfs_mountpoint_del_mount(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(mp, __actv_local_var_mp), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mountpoint_del_mount(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *mp, int me_idx, unsigned int nsid)
{
	int __ret;
	__maybe_unused void *__actv_local_var_mp = mp;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	__ret = ____actvcapcall_fscall_vfs_mountpoint_del_mount(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(mp, __actv_local_var_mp), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_fscall_vfs_open(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_fscall_vfs_open(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_open(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned int cnode_idx, int dfd, int fd, unsigned int flags, unsigned int mode, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_dfd = dfd;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_open(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned int cnode_idx, int dfd, int fd, unsigned int flags, unsigned int mode, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_dfd = dfd;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_open(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_ftruncate(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_ftruncate(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_ftruncate(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long length)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_length = length;
	__ret = ____actvcall_fscall_vfs_ftruncate(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(length, __actv_local_var_length));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_ftruncate(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long length)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_length = length;
	__ret = ____actvcapcall_fscall_vfs_ftruncate(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(length, __actv_local_var_length));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fstat(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fstat(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fstat(unsigned long long __rpc_info, void *__buf, int fd, void *st)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_st = st;
	__ret = ____actvcall_fscall_vfs_fstat(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(st, __actv_local_var_st));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fstat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *st)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_st = st;
	__ret = ____actvcapcall_fscall_vfs_fstat(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(st, __actv_local_var_st));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_stat(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_stat(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_stat(unsigned long long __rpc_info, void *__buf, int dfd, unsigned int flag, void *st, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused void *__actv_local_var_st = st;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_stat(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(st, __actv_local_var_st), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_stat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned int flag, void *st, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused void *__actv_local_var_st = st;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_stat(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(st, __actv_local_var_st), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_statfs(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_statfs(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_statfs(unsigned long long __rpc_info, void *__buf, int dfd, void *stfs, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused void *__actv_local_var_stfs = stfs;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_statfs(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(stfs, __actv_local_var_stfs), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_statfs(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, void *stfs, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused void *__actv_local_var_stfs = stfs;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_statfs(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(stfs, __actv_local_var_stfs), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fstatfs(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fstatfs(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fstatfs(unsigned long long __rpc_info, void *__buf, int fd, void *msg)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_msg = msg;
	__ret = ____actvcall_fscall_vfs_fstatfs(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fstatfs(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *msg)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_msg = msg;
	__ret = ____actvcapcall_fscall_vfs_fstatfs(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fsync(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fsync(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fsync(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_fscall_vfs_fsync(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fsync(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_fscall_vfs_fsync(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_unmount(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_unmount(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_unmount(unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags, char *msg, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_msg = msg;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_unmount(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_unmount(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags, char *msg, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_msg = msg;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_unmount(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_unmount_from_server(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_unmount_from_server(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_unmount_from_server(unsigned long long __rpc_info, void *__buf, int me_idx, uint32_t nsid, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	uint32_t __maybe_unused __actv_local_var_nsid = nsid;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_unmount_from_server(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_unmount_from_server(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, uint32_t nsid, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	uint32_t __maybe_unused __actv_local_var_nsid = nsid;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_unmount_from_server(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_unmount_child(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_unmount_child(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_unmount_child(unsigned long long __rpc_info, void *__buf, int me_idx, uint32_t nsid, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	uint32_t __maybe_unused __actv_local_var_nsid = nsid;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_unmount_child(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_unmount_child(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, uint32_t nsid, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	uint32_t __maybe_unused __actv_local_var_nsid = nsid;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_unmount_child(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_truncate(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_truncate(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_truncate(unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long length, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned long long __maybe_unused __actv_local_var_length = length;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_truncate(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(length, __actv_local_var_length), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_truncate(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned long long length, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned long long __maybe_unused __actv_local_var_length = length;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_truncate(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(length, __actv_local_var_length), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fs_fork(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fs_fork(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fs_fork(unsigned long long __rpc_info, void *__buf, int fd, unsigned int idx_src, unsigned int idx_dst)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_idx_src = idx_src;
	unsigned int __maybe_unused __actv_local_var_idx_dst = idx_dst;
	__ret = ____actvcall_fscall_vfs_fs_fork(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(idx_src, __actv_local_var_idx_src), __ARCH_ACTV_RPC_PASS_ARG(idx_dst, __actv_local_var_idx_dst));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fs_fork(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int idx_src, unsigned int idx_dst)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_idx_src = idx_src;
	unsigned int __maybe_unused __actv_local_var_idx_dst = idx_dst;
	__ret = ____actvcapcall_fscall_vfs_fs_fork(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(idx_src, __actv_local_var_idx_src), __ARCH_ACTV_RPC_PASS_ARG(idx_dst, __actv_local_var_idx_dst));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_query_info(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_query_info(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_query_info(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_vfs_query_info(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_query_info(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_vfs_query_info(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_lseek(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_lseek(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_lseek(unsigned long long __rpc_info, void *__buf, int fd, long long offset, int whence)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_offset = offset;
	int __maybe_unused __actv_local_var_whence = whence;
	__ret = ____actvcall_fscall_vfs_lseek(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(whence, __actv_local_var_whence));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_lseek(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long offset, int whence)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_offset = offset;
	int __maybe_unused __actv_local_var_whence = whence;
	__ret = ____actvcapcall_fscall_vfs_lseek(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(whence, __actv_local_var_whence));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_trans(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_trans(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_trans(unsigned long long __rpc_info, void *__buf, int fd, const char *data, int pos, size_t nbyte)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const char *__actv_local_var_data = data;
	int __maybe_unused __actv_local_var_pos = pos;
	size_t __maybe_unused __actv_local_var_nbyte = nbyte;
	__ret = ____actvcall_fscall_vfs_trans(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(data, __actv_local_var_data), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(nbyte, __actv_local_var_nbyte));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_trans(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const char *data, int pos, size_t nbyte)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const char *__actv_local_var_data = data;
	int __maybe_unused __actv_local_var_pos = pos;
	size_t __maybe_unused __actv_local_var_nbyte = nbyte;
	__ret = ____actvcapcall_fscall_vfs_trans(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(data, __actv_local_var_data), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(nbyte, __actv_local_var_nbyte));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_pipe2(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_pipe2(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_pipe2(unsigned long long __rpc_info, void *__buf, int read_fd, int write_fd, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_read_fd = read_fd;
	int __maybe_unused __actv_local_var_write_fd = write_fd;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_pipe2(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(read_fd, __actv_local_var_read_fd), __ARCH_ACTV_RPC_PASS_ARG(write_fd, __actv_local_var_write_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_pipe2(rref_t __rref, unsigned long long __rpc_info, void *__buf, int read_fd, int write_fd, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_read_fd = read_fd;
	int __maybe_unused __actv_local_var_write_fd = write_fd;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_pipe2(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(read_fd, __actv_local_var_read_fd), __ARCH_ACTV_RPC_PASS_ARG(write_fd, __actv_local_var_write_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_tee(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_tee(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_tee(unsigned long long __rpc_info, void *__buf, int fd_in, int fd_out, unsigned int len, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd_in = fd_in;
	int __maybe_unused __actv_local_var_fd_out = fd_out;
	unsigned int __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_tee(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd_in, __actv_local_var_fd_in), __ARCH_ACTV_RPC_PASS_ARG(fd_out, __actv_local_var_fd_out), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_tee(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd_in, int fd_out, unsigned int len, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd_in = fd_in;
	int __maybe_unused __actv_local_var_fd_out = fd_out;
	unsigned int __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_tee(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd_in, __actv_local_var_fd_in), __ARCH_ACTV_RPC_PASS_ARG(fd_out, __actv_local_var_fd_out), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_splice(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_splice(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_splice(unsigned long long __rpc_info, void *__buf, int fd_in, long long *offset_in, int fd_out, const char *pathname, int multi_srvs, long long *offset_out, unsigned long len, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd_in = fd_in;
	__maybe_unused long long *__actv_local_var_offset_in = offset_in;
	int __maybe_unused __actv_local_var_fd_out = fd_out;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	int __maybe_unused __actv_local_var_multi_srvs = multi_srvs;
	__maybe_unused long long *__actv_local_var_offset_out = offset_out;
	unsigned long __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_splice(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd_in, __actv_local_var_fd_in), __ARCH_ACTV_RPC_PASS_ARG(offset_in, __actv_local_var_offset_in), __ARCH_ACTV_RPC_PASS_ARG(fd_out, __actv_local_var_fd_out), __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(multi_srvs, __actv_local_var_multi_srvs), __ARCH_ACTV_RPC_PASS_ARG(offset_out, __actv_local_var_offset_out), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_splice(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd_in, long long *offset_in, int fd_out, const char *pathname, int multi_srvs, long long *offset_out, unsigned long len, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd_in = fd_in;
	__maybe_unused long long *__actv_local_var_offset_in = offset_in;
	int __maybe_unused __actv_local_var_fd_out = fd_out;
	__maybe_unused const char *__actv_local_var_pathname = pathname;
	int __maybe_unused __actv_local_var_multi_srvs = multi_srvs;
	__maybe_unused long long *__actv_local_var_offset_out = offset_out;
	unsigned long __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_splice(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd_in, __actv_local_var_fd_in), __ARCH_ACTV_RPC_PASS_ARG(offset_in, __actv_local_var_offset_in), __ARCH_ACTV_RPC_PASS_ARG(fd_out, __actv_local_var_fd_out), __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(multi_srvs, __actv_local_var_multi_srvs), __ARCH_ACTV_RPC_PASS_ARG(offset_out, __actv_local_var_offset_out), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_do_splice_srvs(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_do_splice_srvs(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_do_splice_srvs(unsigned long long __rpc_info, void *__buf, int fd, long long pos, const char *buf, unsigned long len)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_pos = pos;
	__maybe_unused const char *__actv_local_var_buf = buf;
	unsigned long __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcall_fscall_vfs_do_splice_srvs(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_do_splice_srvs(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long pos, const char *buf, unsigned long len)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_pos = pos;
	__maybe_unused const char *__actv_local_var_buf = buf;
	unsigned long __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcapcall_fscall_vfs_do_splice_srvs(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_revoke_process(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_revoke_process(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_revoke_process(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_vfs_revoke_process(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_revoke_process(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_vfs_revoke_process(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_setrlimit(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_setrlimit(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_setrlimit(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long rlim_cur, unsigned long long rlim_max, unsigned int type)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned long long __maybe_unused __actv_local_var_rlim_cur = rlim_cur;
	unsigned long long __maybe_unused __actv_local_var_rlim_max = rlim_max;
	unsigned int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcall_fscall_vfs_setrlimit(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(rlim_cur, __actv_local_var_rlim_cur), __ARCH_ACTV_RPC_PASS_ARG(rlim_max, __actv_local_var_rlim_max), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_setrlimit(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long rlim_cur, unsigned long long rlim_max, unsigned int type)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned long long __maybe_unused __actv_local_var_rlim_cur = rlim_cur;
	unsigned long long __maybe_unused __actv_local_var_rlim_max = rlim_max;
	unsigned int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcapcall_fscall_vfs_setrlimit(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(rlim_cur, __actv_local_var_rlim_cur), __ARCH_ACTV_RPC_PASS_ARG(rlim_max, __actv_local_var_rlim_max), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_get_ns(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_get_ns(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_get_ns(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned int oldid, unsigned int newid, int flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_oldid = oldid;
	unsigned int __maybe_unused __actv_local_var_newid = newid;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_get_ns(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(oldid, __actv_local_var_oldid), __ARCH_ACTV_RPC_PASS_ARG(newid, __actv_local_var_newid), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_get_ns(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned int oldid, unsigned int newid, int flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_oldid = oldid;
	unsigned int __maybe_unused __actv_local_var_newid = newid;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_get_ns(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(oldid, __actv_local_var_oldid), __ARCH_ACTV_RPC_PASS_ARG(newid, __actv_local_var_newid), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_put_ns(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_put_ns(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_put_ns(unsigned long long __rpc_info, void *__buf, unsigned int nsid, int me_idx, int flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_put_ns(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_put_ns(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int nsid, int me_idx, int flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_nsid = nsid;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_put_ns(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(nsid, __actv_local_var_nsid), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_init_eventfd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_init_eventfd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_init_eventfd(unsigned long long __rpc_info, void *__buf, int fd, unsigned int count, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_count = count;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_init_eventfd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_init_eventfd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int count, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_count = count;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_init_eventfd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_write_eventfd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_write_eventfd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_write_eventfd(unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t buf_len, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_buf_len = buf_len;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_vfs_write_eventfd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(buf_len, __actv_local_var_buf_len), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_write_eventfd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t buf_len, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_buf_len = buf_len;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_vfs_write_eventfd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(buf_len, __actv_local_var_buf_len), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_timerfd_create(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_timerfd_create(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_timerfd_create(unsigned long long __rpc_info, void *__buf, int fd, int clockid, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_clockid = clockid;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_timerfd_create(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(clockid, __actv_local_var_clockid), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_timerfd_create(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int clockid, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_clockid = clockid;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_timerfd_create(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(clockid, __actv_local_var_clockid), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_timerfd_settime(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_timerfd_settime(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_timerfd_settime(unsigned long long __rpc_info, void *__buf, int fd, int flags, time_t it_inval_sec, long it_inval_nsec, time_t it_val_sec, long it_val_nsec)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_flags = flags;
	time_t __maybe_unused __actv_local_var_it_inval_sec = it_inval_sec;
	long __maybe_unused __actv_local_var_it_inval_nsec = it_inval_nsec;
	time_t __maybe_unused __actv_local_var_it_val_sec = it_val_sec;
	long __maybe_unused __actv_local_var_it_val_nsec = it_val_nsec;
	__ret = ____actvcall_fscall_vfs_timerfd_settime(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(it_inval_sec, __actv_local_var_it_inval_sec), __ARCH_ACTV_RPC_PASS_ARG(it_inval_nsec, __actv_local_var_it_inval_nsec), __ARCH_ACTV_RPC_PASS_ARG(it_val_sec, __actv_local_var_it_val_sec), __ARCH_ACTV_RPC_PASS_ARG(it_val_nsec, __actv_local_var_it_val_nsec));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_timerfd_settime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int flags, time_t it_inval_sec, long it_inval_nsec, time_t it_val_sec, long it_val_nsec)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_flags = flags;
	time_t __maybe_unused __actv_local_var_it_inval_sec = it_inval_sec;
	long __maybe_unused __actv_local_var_it_inval_nsec = it_inval_nsec;
	time_t __maybe_unused __actv_local_var_it_val_sec = it_val_sec;
	long __maybe_unused __actv_local_var_it_val_nsec = it_val_nsec;
	__ret = ____actvcapcall_fscall_vfs_timerfd_settime(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(it_inval_sec, __actv_local_var_it_inval_sec), __ARCH_ACTV_RPC_PASS_ARG(it_inval_nsec, __actv_local_var_it_inval_nsec), __ARCH_ACTV_RPC_PASS_ARG(it_val_sec, __actv_local_var_it_val_sec), __ARCH_ACTV_RPC_PASS_ARG(it_val_nsec, __actv_local_var_it_val_nsec));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_timerfd_gettime(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_timerfd_gettime(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_timerfd_gettime(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_fscall_vfs_timerfd_gettime(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_timerfd_gettime(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_fscall_vfs_timerfd_gettime(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_fscall_vfs_open_exec(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_fscall_vfs_open_exec(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_open_exec(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, int sys_fd, unsigned int flags, unsigned int pcnode_idx, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	int __maybe_unused __actv_local_var_sys_fd = sys_fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_pcnode_idx = pcnode_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_open_exec(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(sys_fd, __actv_local_var_sys_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(pcnode_idx, __actv_local_var_pcnode_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_open_exec(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, int sys_fd, unsigned int flags, unsigned int pcnode_idx, unsigned int cnode_idx, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	int __maybe_unused __actv_local_var_sys_fd = sys_fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_pcnode_idx = pcnode_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_open_exec(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(sys_fd, __actv_local_var_sys_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(pcnode_idx, __actv_local_var_pcnode_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_close_exec(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_close_exec(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_close_exec(unsigned long long __rpc_info, void *__buf, int sys_rfd, unsigned int cnode_idx, int uapp_rfd)
{
	int __ret;
	int __maybe_unused __actv_local_var_sys_rfd = sys_rfd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_uapp_rfd = uapp_rfd;
	__ret = ____actvcall_fscall_vfs_close_exec(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sys_rfd, __actv_local_var_sys_rfd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(uapp_rfd, __actv_local_var_uapp_rfd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_close_exec(rref_t __rref, unsigned long long __rpc_info, void *__buf, int sys_rfd, unsigned int cnode_idx, int uapp_rfd)
{
	int __ret;
	int __maybe_unused __actv_local_var_sys_rfd = sys_rfd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_uapp_rfd = uapp_rfd;
	__ret = ____actvcapcall_fscall_vfs_close_exec(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sys_rfd, __actv_local_var_sys_rfd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(uapp_rfd, __actv_local_var_uapp_rfd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_set_elf_file(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_set_elf_file(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_set_elf_file(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int sys_rfd)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_sys_rfd = sys_rfd;
	__ret = ____actvcall_fscall_vfs_set_elf_file(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(sys_rfd, __actv_local_var_sys_rfd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_set_elf_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int sys_rfd)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_sys_rfd = sys_rfd;
	__ret = ____actvcapcall_fscall_vfs_set_elf_file(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(sys_rfd, __actv_local_var_sys_rfd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_ioctl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_ioctl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_ioctl(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cmd, unsigned long arg)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cmd = cmd;
	unsigned long __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcall_fscall_vfs_ioctl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cmd, unsigned long arg)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cmd = cmd;
	unsigned long __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcapcall_fscall_vfs_ioctl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_read(unsigned long long __rpc_info, void *__buf, int fd, long long pos, size_t msg_len, void *buf)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_pos = pos;
	size_t __maybe_unused __actv_local_var_msg_len = msg_len;
	__maybe_unused void *__actv_local_var_buf = buf;
	__ret = ____actvcall_fscall_vfs_read(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(msg_len, __actv_local_var_msg_len), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long pos, size_t msg_len, void *buf)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_pos = pos;
	size_t __maybe_unused __actv_local_var_msg_len = msg_len;
	__maybe_unused void *__actv_local_var_buf = buf;
	__ret = ____actvcapcall_fscall_vfs_read(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(msg_len, __actv_local_var_msg_len), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_readv(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_readv(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_readv(unsigned long long __rpc_info, void *__buf, int fd, const void *vec, int vlen, long long pos)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_vec = vec;
	int __maybe_unused __actv_local_var_vlen = vlen;
	long long __maybe_unused __actv_local_var_pos = pos;
	__ret = ____actvcall_fscall_vfs_readv(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(vec, __actv_local_var_vec), __ARCH_ACTV_RPC_PASS_ARG(vlen, __actv_local_var_vlen), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_readv(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *vec, int vlen, long long pos)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_vec = vec;
	int __maybe_unused __actv_local_var_vlen = vlen;
	long long __maybe_unused __actv_local_var_pos = pos;
	__ret = ____actvcapcall_fscall_vfs_readv(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(vec, __actv_local_var_vec), __ARCH_ACTV_RPC_PASS_ARG(vlen, __actv_local_var_vlen), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_getcwd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_getcwd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_getcwd(unsigned long long __rpc_info, void *__buf, char *buf, size_t size)
{
	int __ret;
	__maybe_unused char *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_fscall_vfs_getcwd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_getcwd(rref_t __rref, unsigned long long __rpc_info, void *__buf, char *buf, size_t size)
{
	int __ret;
	__maybe_unused char *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_fscall_vfs_getcwd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_get_process_cwdrootexe(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_get_process_cwdrootexe(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_get_process_cwdrootexe(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned int root_cnode, int type, char *buf)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_root_cnode = root_cnode;
	int __maybe_unused __actv_local_var_type = type;
	__maybe_unused char *__actv_local_var_buf = buf;
	__ret = ____actvcall_fscall_vfs_get_process_cwdrootexe(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(root_cnode, __actv_local_var_root_cnode), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_get_process_cwdrootexe(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned int root_cnode, int type, char *buf)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_root_cnode = root_cnode;
	int __maybe_unused __actv_local_var_type = type;
	__maybe_unused char *__actv_local_var_buf = buf;
	__ret = ____actvcapcall_fscall_vfs_get_process_cwdrootexe(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(root_cnode, __actv_local_var_root_cnode), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_readdir(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_readdir(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_readdir(unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t size)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_fscall_vfs_readdir(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_readdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t size)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_fscall_vfs_readdir(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_write(unsigned long long __rpc_info, void *__buf, int fd, long long pos, const void *buf, size_t buf_len)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_pos = pos;
	__maybe_unused const void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_buf_len = buf_len;
	__ret = ____actvcall_fscall_vfs_write(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(buf_len, __actv_local_var_buf_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long pos, const void *buf, size_t buf_len)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_pos = pos;
	__maybe_unused const void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_buf_len = buf_len;
	__ret = ____actvcapcall_fscall_vfs_write(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(buf_len, __actv_local_var_buf_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_writev(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_writev(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_writev(unsigned long long __rpc_info, void *__buf, int fd, const void *vec, int vlen, long long pos)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_vec = vec;
	int __maybe_unused __actv_local_var_vlen = vlen;
	long long __maybe_unused __actv_local_var_pos = pos;
	__ret = ____actvcall_fscall_vfs_writev(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(vec, __actv_local_var_vec), __ARCH_ACTV_RPC_PASS_ARG(vlen, __actv_local_var_vlen), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_writev(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *vec, int vlen, long long pos)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_vec = vec;
	int __maybe_unused __actv_local_var_vlen = vlen;
	long long __maybe_unused __actv_local_var_pos = pos;
	__ret = ____actvcapcall_fscall_vfs_writev(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(vec, __actv_local_var_vec), __ARCH_ACTV_RPC_PASS_ARG(vlen, __actv_local_var_vlen), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_sync(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_sync(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_sync(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_fscall_vfs_sync(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_sync(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_fscall_vfs_sync(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_do_sync(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_do_sync(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_do_sync(unsigned long long __rpc_info, void *__buf, int me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_do_sync(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_do_sync(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_do_sync(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_utimensat(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_utimensat(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_utimensat(unsigned long long __rpc_info, void *__buf, int dfd, const void *tsp, unsigned int flag, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused const void *__actv_local_var_tsp = tsp;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_utimensat(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(tsp, __actv_local_var_tsp), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_utimensat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, const void *tsp, unsigned int flag, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused const void *__actv_local_var_tsp = tsp;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_utimensat(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(tsp, __actv_local_var_tsp), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_futimens(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_futimens(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_futimens(unsigned long long __rpc_info, void *__buf, int fd, const void *tsp)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_tsp = tsp;
	__ret = ____actvcall_fscall_vfs_futimens(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tsp, __actv_local_var_tsp));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_futimens(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *tsp)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_tsp = tsp;
	__ret = ____actvcapcall_fscall_vfs_futimens(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(tsp, __actv_local_var_tsp));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_fchmodat(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_fchmodat(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fchmodat(unsigned long long __rpc_info, void *__buf, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_fchmodat(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fchmodat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_fchmodat(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fchmod(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fchmod(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fchmod(unsigned long long __rpc_info, void *__buf, int fd, mode_t mode)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcall_fscall_vfs_fchmod(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fchmod(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, mode_t mode)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcapcall_fscall_vfs_fchmod(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_drop_caches(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_drop_caches(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_drop_caches(unsigned long long __rpc_info, void *__buf, unsigned int mode, int max, int reason)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	int __maybe_unused __actv_local_var_max = max;
	int __maybe_unused __actv_local_var_reason = reason;
	__ret = ____actvcall_fscall_vfs_drop_caches(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(max, __actv_local_var_max), __ARCH_ACTV_RPC_PASS_ARG(reason, __actv_local_var_reason));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_drop_caches(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int mode, int max, int reason)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	int __maybe_unused __actv_local_var_max = max;
	int __maybe_unused __actv_local_var_reason = reason;
	__ret = ____actvcapcall_fscall_vfs_drop_caches(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(max, __actv_local_var_max), __ARCH_ACTV_RPC_PASS_ARG(reason, __actv_local_var_reason));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_do_drop_caches(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_do_drop_caches(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_do_drop_caches(unsigned long long __rpc_info, void *__buf, unsigned int mode, int max, int reason)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	int __maybe_unused __actv_local_var_max = max;
	int __maybe_unused __actv_local_var_reason = reason;
	__ret = ____actvcall_fscall_vfs_do_drop_caches(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(max, __actv_local_var_max), __ARCH_ACTV_RPC_PASS_ARG(reason, __actv_local_var_reason));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_do_drop_caches(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int mode, int max, int reason)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	int __maybe_unused __actv_local_var_max = max;
	int __maybe_unused __actv_local_var_reason = reason;
	__ret = ____actvcapcall_fscall_vfs_do_drop_caches(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(max, __actv_local_var_max), __ARCH_ACTV_RPC_PASS_ARG(reason, __actv_local_var_reason));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fadvise(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fadvise(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fadvise(unsigned long long __rpc_info, void *__buf, int fd, long long offset, long long len, int advice)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_offset = offset;
	long long __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_advice = advice;
	__ret = ____actvcall_fscall_vfs_fadvise(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(advice, __actv_local_var_advice));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fadvise(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long offset, long long len, int advice)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_offset = offset;
	long long __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_advice = advice;
	__ret = ____actvcapcall_fscall_vfs_fadvise(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(advice, __actv_local_var_advice));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_readahead(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_readahead(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_readahead(unsigned long long __rpc_info, void *__buf, int fd, long long offset, size_t count)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_offset = offset;
	size_t __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcall_fscall_vfs_readahead(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_readahead(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long offset, size_t count)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_offset = offset;
	size_t __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcapcall_fscall_vfs_readahead(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_get_fd_path(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_get_fd_path(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_get_fd_path(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx, char *path, int pathlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_path = path;
	int __maybe_unused __actv_local_var_pathlen = pathlen;
	__ret = ____actvcall_fscall_vfs_get_fd_path(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(path, __actv_local_var_path), __ARCH_ACTV_RPC_PASS_ARG(pathlen, __actv_local_var_pathlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_get_fd_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx, char *path, int pathlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_path = path;
	int __maybe_unused __actv_local_var_pathlen = pathlen;
	__ret = ____actvcapcall_fscall_vfs_get_fd_path(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(path, __actv_local_var_path), __ARCH_ACTV_RPC_PASS_ARG(pathlen, __actv_local_var_pathlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_sysmgr_get_fd_path(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_sysmgr_get_fd_path(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_sysmgr_get_fd_path(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx, char *path)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_path = path;
	__ret = ____actvcall_fscall_vfs_sysmgr_get_fd_path(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(path, __actv_local_var_path));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_sysmgr_get_fd_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx, char *path)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_path = path;
	__ret = ____actvcapcall_fscall_vfs_sysmgr_get_fd_path(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(path, __actv_local_var_path));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fcntl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fcntl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fcntl(unsigned long long __rpc_info, void *__buf, int fd, int cmd, unsigned long arg)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_cmd = cmd;
	unsigned long __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcall_fscall_vfs_fcntl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fcntl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int cmd, unsigned long arg)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_cmd = cmd;
	unsigned long __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcapcall_fscall_vfs_fcntl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_device_mounted(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_device_mounted(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_device_mounted(unsigned long long __rpc_info, void *__buf, const char *special, unsigned long long len, char *srvname, int srvlen)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_special = special;
	unsigned long long __maybe_unused __actv_local_var_len = len;
	__maybe_unused char *__actv_local_var_srvname = srvname;
	int __maybe_unused __actv_local_var_srvlen = srvlen;
	__ret = ____actvcall_fscall_vfs_device_mounted(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(special, __actv_local_var_special), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(srvname, __actv_local_var_srvname), __ARCH_ACTV_RPC_PASS_ARG(srvlen, __actv_local_var_srvlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_device_mounted(rref_t __rref, unsigned long long __rpc_info, void *__buf, const char *special, unsigned long long len, char *srvname, int srvlen)
{
	int __ret;
	__maybe_unused const char *__actv_local_var_special = special;
	unsigned long long __maybe_unused __actv_local_var_len = len;
	__maybe_unused char *__actv_local_var_srvname = srvname;
	int __maybe_unused __actv_local_var_srvlen = srvlen;
	__ret = ____actvcapcall_fscall_vfs_device_mounted(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(special, __actv_local_var_special), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(srvname, __actv_local_var_srvname), __ARCH_ACTV_RPC_PASS_ARG(srvlen, __actv_local_var_srvlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_quotactl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_quotactl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_quotactl(unsigned long long __rpc_info, void *__buf, int cmd, int type, unsigned int id, char *buffer, unsigned int buffer_size, int fs_handle)
{
	int __ret;
	int __maybe_unused __actv_local_var_cmd = cmd;
	int __maybe_unused __actv_local_var_type = type;
	unsigned int __maybe_unused __actv_local_var_id = id;
	__maybe_unused char *__actv_local_var_buffer = buffer;
	unsigned int __maybe_unused __actv_local_var_buffer_size = buffer_size;
	int __maybe_unused __actv_local_var_fs_handle = fs_handle;
	__ret = ____actvcall_fscall_vfs_quotactl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(id, __actv_local_var_id), __ARCH_ACTV_RPC_PASS_ARG(buffer, __actv_local_var_buffer), __ARCH_ACTV_RPC_PASS_ARG(buffer_size, __actv_local_var_buffer_size), __ARCH_ACTV_RPC_PASS_ARG(fs_handle, __actv_local_var_fs_handle));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_quotactl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int cmd, int type, unsigned int id, char *buffer, unsigned int buffer_size, int fs_handle)
{
	int __ret;
	int __maybe_unused __actv_local_var_cmd = cmd;
	int __maybe_unused __actv_local_var_type = type;
	unsigned int __maybe_unused __actv_local_var_id = id;
	__maybe_unused char *__actv_local_var_buffer = buffer;
	unsigned int __maybe_unused __actv_local_var_buffer_size = buffer_size;
	int __maybe_unused __actv_local_var_fs_handle = fs_handle;
	__ret = ____actvcapcall_fscall_vfs_quotactl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(id, __actv_local_var_id), __ARCH_ACTV_RPC_PASS_ARG(buffer, __actv_local_var_buffer), __ARCH_ACTV_RPC_PASS_ARG(buffer_size, __actv_local_var_buffer_size), __ARCH_ACTV_RPC_PASS_ARG(fs_handle, __actv_local_var_fs_handle));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_copy_file_range(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_copy_file_range(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_copy_file_range(unsigned long long __rpc_info, void *__buf, int fd_in, long long off_in, int fd_out, long long off_out, size_t len)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd_in = fd_in;
	long long __maybe_unused __actv_local_var_off_in = off_in;
	int __maybe_unused __actv_local_var_fd_out = fd_out;
	long long __maybe_unused __actv_local_var_off_out = off_out;
	size_t __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcall_fscall_vfs_copy_file_range(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd_in, __actv_local_var_fd_in), __ARCH_ACTV_RPC_PASS_ARG(off_in, __actv_local_var_off_in), __ARCH_ACTV_RPC_PASS_ARG(fd_out, __actv_local_var_fd_out), __ARCH_ACTV_RPC_PASS_ARG(off_out, __actv_local_var_off_out), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_copy_file_range(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd_in, long long off_in, int fd_out, long long off_out, size_t len)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd_in = fd_in;
	long long __maybe_unused __actv_local_var_off_in = off_in;
	int __maybe_unused __actv_local_var_fd_out = fd_out;
	long long __maybe_unused __actv_local_var_off_out = off_out;
	size_t __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcapcall_fscall_vfs_copy_file_range(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd_in, __actv_local_var_fd_in), __ARCH_ACTV_RPC_PASS_ARG(off_in, __actv_local_var_off_in), __ARCH_ACTV_RPC_PASS_ARG(fd_out, __actv_local_var_fd_out), __ARCH_ACTV_RPC_PASS_ARG(off_out, __actv_local_var_off_out), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_same_file(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_same_file(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_same_file(unsigned long long __rpc_info, void *__buf, int fd1, int fd2)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd1 = fd1;
	int __maybe_unused __actv_local_var_fd2 = fd2;
	__ret = ____actvcall_fscall_vfs_same_file(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd1, __actv_local_var_fd1), __ARCH_ACTV_RPC_PASS_ARG(fd2, __actv_local_var_fd2));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_same_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd1, int fd2)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd1 = fd1;
	int __maybe_unused __actv_local_var_fd2 = fd2;
	__ret = ____actvcapcall_fscall_vfs_same_file(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd1, __actv_local_var_fd1), __ARCH_ACTV_RPC_PASS_ARG(fd2, __actv_local_var_fd2));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_access(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_access(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_access(unsigned long long __rpc_info, void *__buf, int dfd, unsigned int mode, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_access(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_access(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned int mode, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_access(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_flock(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_flock(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_flock(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cmd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcall_fscall_vfs_flock(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_flock(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cmd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcapcall_fscall_vfs_flock(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_fchownat(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_fchownat(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fchownat(unsigned long long __rpc_info, void *__buf, int dfd, uid_t uid, gid_t gid, unsigned int flag, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	uid_t __maybe_unused __actv_local_var_uid = uid;
	gid_t __maybe_unused __actv_local_var_gid = gid;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_fchownat(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(uid, __actv_local_var_uid), __ARCH_ACTV_RPC_PASS_ARG(gid, __actv_local_var_gid), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fchownat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, uid_t uid, gid_t gid, unsigned int flag, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	uid_t __maybe_unused __actv_local_var_uid = uid;
	gid_t __maybe_unused __actv_local_var_gid = gid;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_fchownat(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(uid, __actv_local_var_uid), __ARCH_ACTV_RPC_PASS_ARG(gid, __actv_local_var_gid), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fchown(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fchown(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fchown(unsigned long long __rpc_info, void *__buf, int fd, uid_t uid, gid_t gid)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	uid_t __maybe_unused __actv_local_var_uid = uid;
	gid_t __maybe_unused __actv_local_var_gid = gid;
	__ret = ____actvcall_fscall_vfs_fchown(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(uid, __actv_local_var_uid), __ARCH_ACTV_RPC_PASS_ARG(gid, __actv_local_var_gid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fchown(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, uid_t uid, gid_t gid)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	uid_t __maybe_unused __actv_local_var_uid = uid;
	gid_t __maybe_unused __actv_local_var_gid = gid;
	__ret = ____actvcapcall_fscall_vfs_fchown(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(uid, __actv_local_var_uid), __ARCH_ACTV_RPC_PASS_ARG(gid, __actv_local_var_gid));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_binderfs_mmap(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_binderfs_mmap(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_binderfs_mmap(unsigned long long __rpc_info, void *__buf, void *addr, size_t len, int fd, unsigned long long shm_key)
{
	int __ret;
	__maybe_unused void *__actv_local_var_addr = addr;
	size_t __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_shm_key = shm_key;
	__ret = ____actvcall_fscall_vfs_binderfs_mmap(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(shm_key, __actv_local_var_shm_key));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_binderfs_mmap(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *addr, size_t len, int fd, unsigned long long shm_key)
{
	int __ret;
	__maybe_unused void *__actv_local_var_addr = addr;
	size_t __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_shm_key = shm_key;
	__ret = ____actvcapcall_fscall_vfs_binderfs_mmap(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(shm_key, __actv_local_var_shm_key));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_init_signalfd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_init_signalfd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_init_signalfd(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long sigmask, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_sigmask = sigmask;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_init_signalfd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(sigmask, __actv_local_var_sigmask), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_init_signalfd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long sigmask, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_sigmask = sigmask;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_init_signalfd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(sigmask, __actv_local_var_sigmask), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_epoll_ctl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_epoll_ctl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_epoll_ctl(unsigned long long __rpc_info, void *__buf, int fd, int op, int is_epoll, const void *epoll_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_op = op;
	int __maybe_unused __actv_local_var_is_epoll = is_epoll;
	__maybe_unused const void *__actv_local_var_epoll_reg_info = epoll_reg_info;
	__ret = ____actvcall_fscall_vfs_epoll_ctl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(op, __actv_local_var_op), __ARCH_ACTV_RPC_PASS_ARG(is_epoll, __actv_local_var_is_epoll), __ARCH_ACTV_RPC_PASS_ARG(epoll_reg_info, __actv_local_var_epoll_reg_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_epoll_ctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int op, int is_epoll, const void *epoll_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_op = op;
	int __maybe_unused __actv_local_var_is_epoll = is_epoll;
	__maybe_unused const void *__actv_local_var_epoll_reg_info = epoll_reg_info;
	__ret = ____actvcapcall_fscall_vfs_epoll_ctl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(op, __actv_local_var_op), __ARCH_ACTV_RPC_PASS_ARG(is_epoll, __actv_local_var_is_epoll), __ARCH_ACTV_RPC_PASS_ARG(epoll_reg_info, __actv_local_var_epoll_reg_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_epoll_et_revents(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_epoll_et_revents(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_epoll_et_revents(unsigned long long __rpc_info, void *__buf, int fd, const void *epoll_pre_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_epoll_pre_reg_info = epoll_pre_reg_info;
	__ret = ____actvcall_fscall_vfs_epoll_et_revents(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(epoll_pre_reg_info, __actv_local_var_epoll_pre_reg_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_epoll_et_revents(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *epoll_pre_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_epoll_pre_reg_info = epoll_pre_reg_info;
	__ret = ____actvcapcall_fscall_vfs_epoll_et_revents(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(epoll_pre_reg_info, __actv_local_var_epoll_pre_reg_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_epoll_reinit(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_epoll_reinit(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_epoll_reinit(unsigned long long __rpc_info, void *__buf, int fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_epoll_pre_reg_info = epoll_pre_reg_info;
	__maybe_unused const void *__actv_local_var_epoll_reg_info = epoll_reg_info;
	__ret = ____actvcall_fscall_vfs_epoll_reinit(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(epoll_pre_reg_info, __actv_local_var_epoll_pre_reg_info), __ARCH_ACTV_RPC_PASS_ARG(epoll_reg_info, __actv_local_var_epoll_reg_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_epoll_reinit(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_epoll_pre_reg_info = epoll_pre_reg_info;
	__maybe_unused const void *__actv_local_var_epoll_reg_info = epoll_reg_info;
	__ret = ____actvcapcall_fscall_vfs_epoll_reinit(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(epoll_pre_reg_info, __actv_local_var_epoll_pre_reg_info), __ARCH_ACTV_RPC_PASS_ARG(epoll_reg_info, __actv_local_var_epoll_reg_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_signalfd_notify(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_signalfd_notify(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_signalfd_notify(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, const void *buf, int fdcnt)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused const void *__actv_local_var_buf = buf;
	int __maybe_unused __actv_local_var_fdcnt = fdcnt;
	__ret = ____actvcall_fscall_vfs_signalfd_notify(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(fdcnt, __actv_local_var_fdcnt));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_signalfd_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, const void *buf, int fdcnt)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused const void *__actv_local_var_buf = buf;
	int __maybe_unused __actv_local_var_fdcnt = fdcnt;
	__ret = ____actvcapcall_fscall_vfs_signalfd_notify(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(fdcnt, __actv_local_var_fdcnt));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_pid_io_stats(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_pid_io_stats(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_pid_io_stats(unsigned long long __rpc_info, void *__buf, unsigned int pid)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_pid = pid;
	__ret = ____actvcall_fscall_vfs_pid_io_stats(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pid, __actv_local_var_pid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_pid_io_stats(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int pid)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_pid = pid;
	__ret = ____actvcapcall_fscall_vfs_pid_io_stats(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(pid, __actv_local_var_pid));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fallocate(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fallocate(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fallocate(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long offset, unsigned long long len, int mode)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long long __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcall_fscall_vfs_fallocate(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fallocate(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long offset, unsigned long long len, int mode)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long long __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcapcall_fscall_vfs_fallocate(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_set_cwdroot(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_set_cwdroot(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_set_cwdroot(unsigned long long __rpc_info, void *__buf, int dfd, int type, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	int __maybe_unused __actv_local_var_type = type;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_set_cwdroot(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_set_cwdroot(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, int type, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	int __maybe_unused __actv_local_var_type = type;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_set_cwdroot(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fchdir(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fchdir(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fchdir(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_fscall_vfs_fchdir(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fchdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_fscall_vfs_fchdir(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_disable_cwdroot(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_disable_cwdroot(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_disable_cwdroot(unsigned long long __rpc_info, void *__buf, int type)
{
	int __ret;
	int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcall_fscall_vfs_disable_cwdroot(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_disable_cwdroot(rref_t __rref, unsigned long long __rpc_info, void *__buf, int type)
{
	int __ret;
	int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcapcall_fscall_vfs_disable_cwdroot(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_update_cwdroot(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_update_cwdroot(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_update_cwdroot(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int type)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcall_fscall_vfs_update_cwdroot(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_update_cwdroot(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int type)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcapcall_fscall_vfs_update_cwdroot(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_handle_global_locks(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_handle_global_locks(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_handle_global_locks(unsigned long long __rpc_info, void *__buf, unsigned int cmd, unsigned int cnode_idx, unsigned long lock_id)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cmd = cmd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned long __maybe_unused __actv_local_var_lock_id = lock_id;
	__ret = ____actvcall_fscall_vfs_handle_global_locks(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(lock_id, __actv_local_var_lock_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_handle_global_locks(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cmd, unsigned int cnode_idx, unsigned long lock_id)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cmd = cmd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned long __maybe_unused __actv_local_var_lock_id = lock_id;
	__ret = ____actvcapcall_fscall_vfs_handle_global_locks(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(lock_id, __actv_local_var_lock_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_send_fd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_send_fd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_send_fd(unsigned long long __rpc_info, void *__buf, int send_fd, unsigned int send_cidx, unsigned int recv_cidx)
{
	int __ret;
	int __maybe_unused __actv_local_var_send_fd = send_fd;
	unsigned int __maybe_unused __actv_local_var_send_cidx = send_cidx;
	unsigned int __maybe_unused __actv_local_var_recv_cidx = recv_cidx;
	__ret = ____actvcall_fscall_vfs_send_fd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(send_fd, __actv_local_var_send_fd), __ARCH_ACTV_RPC_PASS_ARG(send_cidx, __actv_local_var_send_cidx), __ARCH_ACTV_RPC_PASS_ARG(recv_cidx, __actv_local_var_recv_cidx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_send_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int send_fd, unsigned int send_cidx, unsigned int recv_cidx)
{
	int __ret;
	int __maybe_unused __actv_local_var_send_fd = send_fd;
	unsigned int __maybe_unused __actv_local_var_send_cidx = send_cidx;
	unsigned int __maybe_unused __actv_local_var_recv_cidx = recv_cidx;
	__ret = ____actvcapcall_fscall_vfs_send_fd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(send_fd, __actv_local_var_send_fd), __ARCH_ACTV_RPC_PASS_ARG(send_cidx, __actv_local_var_send_cidx), __ARCH_ACTV_RPC_PASS_ARG(recv_cidx, __actv_local_var_recv_cidx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_recv_fd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_recv_fd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_recv_fd(unsigned long long __rpc_info, void *__buf, int sfiles_idx, unsigned int send_cidx, int recv_fd, unsigned int recv_cidx)
{
	int __ret;
	int __maybe_unused __actv_local_var_sfiles_idx = sfiles_idx;
	unsigned int __maybe_unused __actv_local_var_send_cidx = send_cidx;
	int __maybe_unused __actv_local_var_recv_fd = recv_fd;
	unsigned int __maybe_unused __actv_local_var_recv_cidx = recv_cidx;
	__ret = ____actvcall_fscall_vfs_recv_fd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sfiles_idx, __actv_local_var_sfiles_idx), __ARCH_ACTV_RPC_PASS_ARG(send_cidx, __actv_local_var_send_cidx), __ARCH_ACTV_RPC_PASS_ARG(recv_fd, __actv_local_var_recv_fd), __ARCH_ACTV_RPC_PASS_ARG(recv_cidx, __actv_local_var_recv_cidx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_recv_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int sfiles_idx, unsigned int send_cidx, int recv_fd, unsigned int recv_cidx)
{
	int __ret;
	int __maybe_unused __actv_local_var_sfiles_idx = sfiles_idx;
	unsigned int __maybe_unused __actv_local_var_send_cidx = send_cidx;
	int __maybe_unused __actv_local_var_recv_fd = recv_fd;
	unsigned int __maybe_unused __actv_local_var_recv_cidx = recv_cidx;
	__ret = ____actvcapcall_fscall_vfs_recv_fd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sfiles_idx, __actv_local_var_sfiles_idx), __ARCH_ACTV_RPC_PASS_ARG(send_cidx, __actv_local_var_send_cidx), __ARCH_ACTV_RPC_PASS_ARG(recv_fd, __actv_local_var_recv_fd), __ARCH_ACTV_RPC_PASS_ARG(recv_cidx, __actv_local_var_recv_cidx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_get_buffer_wrapper(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_get_buffer_wrapper(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_get_buffer_wrapper(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long ptr)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_ptr = ptr;
	__ret = ____actvcall_fscall_vfs_get_buffer_wrapper(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(ptr, __actv_local_var_ptr));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_get_buffer_wrapper(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long ptr)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_ptr = ptr;
	__ret = ____actvcapcall_fscall_vfs_get_buffer_wrapper(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(ptr, __actv_local_var_ptr));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_get_pathname_by_me_idx(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_get_pathname_by_me_idx(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_get_pathname_by_me_idx(unsigned long long __rpc_info, void *__buf, int fd, int me_idx, uintptr_t pathname)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	uintptr_t __maybe_unused __actv_local_var_pathname = pathname;
	__ret = ____actvcall_fscall_vfs_get_pathname_by_me_idx(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_get_pathname_by_me_idx(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int me_idx, uintptr_t pathname)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	uintptr_t __maybe_unused __actv_local_var_pathname = pathname;
	__ret = ____actvcapcall_fscall_vfs_get_pathname_by_me_idx(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_sfile_put(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_sfile_put(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_sfile_put(unsigned long long __rpc_info, void *__buf, unsigned int send_cidx, unsigned int recv_cidx, int sfiles_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_send_cidx = send_cidx;
	unsigned int __maybe_unused __actv_local_var_recv_cidx = recv_cidx;
	int __maybe_unused __actv_local_var_sfiles_idx = sfiles_idx;
	__ret = ____actvcall_fscall_vfs_sfile_put(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(send_cidx, __actv_local_var_send_cidx), __ARCH_ACTV_RPC_PASS_ARG(recv_cidx, __actv_local_var_recv_cidx), __ARCH_ACTV_RPC_PASS_ARG(sfiles_idx, __actv_local_var_sfiles_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_sfile_put(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int send_cidx, unsigned int recv_cidx, int sfiles_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_send_cidx = send_cidx;
	unsigned int __maybe_unused __actv_local_var_recv_cidx = recv_cidx;
	int __maybe_unused __actv_local_var_sfiles_idx = sfiles_idx;
	__ret = ____actvcapcall_fscall_vfs_sfile_put(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(send_cidx, __actv_local_var_send_cidx), __ARCH_ACTV_RPC_PASS_ARG(recv_cidx, __actv_local_var_recv_cidx), __ARCH_ACTV_RPC_PASS_ARG(sfiles_idx, __actv_local_var_sfiles_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_fscall_vfs_readlinkat(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_fscall_vfs_readlinkat(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_readlinkat(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, char *buf, unsigned long long bufsize, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused char *__actv_local_var_buf = buf;
	unsigned long long __maybe_unused __actv_local_var_bufsize = bufsize;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_readlinkat(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(bufsize, __actv_local_var_bufsize), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_readlinkat(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, char *buf, unsigned long long bufsize, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused char *__actv_local_var_buf = buf;
	unsigned long long __maybe_unused __actv_local_var_bufsize = bufsize;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_readlinkat(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(bufsize, __actv_local_var_bufsize), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_get_slabinfo(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_get_slabinfo(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_get_slabinfo(unsigned long long __rpc_info, void *__buf, char *msg, unsigned int msg_len)
{
	int __ret;
	__maybe_unused char *__actv_local_var_msg = msg;
	unsigned int __maybe_unused __actv_local_var_msg_len = msg_len;
	__ret = ____actvcall_fscall_vfs_get_slabinfo(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(msg_len, __actv_local_var_msg_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_get_slabinfo(rref_t __rref, unsigned long long __rpc_info, void *__buf, char *msg, unsigned int msg_len)
{
	int __ret;
	__maybe_unused char *__actv_local_var_msg = msg;
	unsigned int __maybe_unused __actv_local_var_msg_len = msg_len;
	__ret = ____actvcapcall_fscall_vfs_get_slabinfo(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(msg_len, __actv_local_var_msg_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_do_get_slabinfo(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_do_get_slabinfo(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_do_get_slabinfo(unsigned long long __rpc_info, void *__buf, char *msg, unsigned int msg_len)
{
	int __ret;
	__maybe_unused char *__actv_local_var_msg = msg;
	unsigned int __maybe_unused __actv_local_var_msg_len = msg_len;
	__ret = ____actvcall_fscall_vfs_do_get_slabinfo(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(msg_len, __actv_local_var_msg_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_do_get_slabinfo(rref_t __rref, unsigned long long __rpc_info, void *__buf, char *msg, unsigned int msg_len)
{
	int __ret;
	__maybe_unused char *__actv_local_var_msg = msg;
	unsigned int __maybe_unused __actv_local_var_msg_len = msg_len;
	__ret = ____actvcapcall_fscall_vfs_do_get_slabinfo(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(msg_len, __actv_local_var_msg_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fscache_print_info(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fscache_print_info(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fscache_print_info(unsigned long long __rpc_info, void *__buf, int count)
{
	int __ret;
	int __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcall_fscall_vfs_fscache_print_info(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fscache_print_info(rref_t __rref, unsigned long long __rpc_info, void *__buf, int count)
{
	int __ret;
	int __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcapcall_fscall_vfs_fscache_print_info(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_alloc_fs_handle_for_same_device(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_alloc_fs_handle_for_same_device(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_alloc_fs_handle_for_same_device(unsigned long long __rpc_info, void *__buf, int me_idx, int new_me_idx, unsigned long flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	int __maybe_unused __actv_local_var_new_me_idx = new_me_idx;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_alloc_fs_handle_for_same_device(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(new_me_idx, __actv_local_var_new_me_idx), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_alloc_fs_handle_for_same_device(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, int new_me_idx, unsigned long flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	int __maybe_unused __actv_local_var_new_me_idx = new_me_idx;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_alloc_fs_handle_for_same_device(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(new_me_idx, __actv_local_var_new_me_idx), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_free_fs_handle_for_same_device(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_free_fs_handle_for_same_device(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_free_fs_handle_for_same_device(unsigned long long __rpc_info, void *__buf, int me_idx, unsigned int fs_handle)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	unsigned int __maybe_unused __actv_local_var_fs_handle = fs_handle;
	__ret = ____actvcall_fscall_vfs_free_fs_handle_for_same_device(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(fs_handle, __actv_local_var_fs_handle));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_free_fs_handle_for_same_device(rref_t __rref, unsigned long long __rpc_info, void *__buf, int me_idx, unsigned int fs_handle)
{
	int __ret;
	int __maybe_unused __actv_local_var_me_idx = me_idx;
	unsigned int __maybe_unused __actv_local_var_fs_handle = fs_handle;
	__ret = ____actvcapcall_fscall_vfs_free_fs_handle_for_same_device(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx), __ARCH_ACTV_RPC_PASS_ARG(fs_handle, __actv_local_var_fs_handle));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_memfd_create(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_memfd_create(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_memfd_create(unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_memfd_create(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_memfd_create(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_memfd_create(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_mknod(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_mknod(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mknod(unsigned long long __rpc_info, void *__buf, int parent_fd, unsigned long long devno, unsigned int mode, void *msg, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_parent_fd = parent_fd;
	unsigned long long __maybe_unused __actv_local_var_devno = devno;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused void *__actv_local_var_msg = msg;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_mknod(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(parent_fd, __actv_local_var_parent_fd), __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mknod(rref_t __rref, unsigned long long __rpc_info, void *__buf, int parent_fd, unsigned long long devno, unsigned int mode, void *msg, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_parent_fd = parent_fd;
	unsigned long long __maybe_unused __actv_local_var_devno = devno;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused void *__actv_local_var_msg = msg;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_mknod(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(parent_fd, __actv_local_var_parent_fd), __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_rename(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_rename(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_rename(unsigned long long __rpc_info, void *__buf, int old_pfd, int new_pfd)
{
	int __ret;
	int __maybe_unused __actv_local_var_old_pfd = old_pfd;
	int __maybe_unused __actv_local_var_new_pfd = new_pfd;
	__ret = ____actvcall_fscall_vfs_rename(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(old_pfd, __actv_local_var_old_pfd), __ARCH_ACTV_RPC_PASS_ARG(new_pfd, __actv_local_var_new_pfd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_rename(rref_t __rref, unsigned long long __rpc_info, void *__buf, int old_pfd, int new_pfd)
{
	int __ret;
	int __maybe_unused __actv_local_var_old_pfd = old_pfd;
	int __maybe_unused __actv_local_var_new_pfd = new_pfd;
	__ret = ____actvcapcall_fscall_vfs_rename(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(old_pfd, __actv_local_var_old_pfd), __ARCH_ACTV_RPC_PASS_ARG(new_pfd, __actv_local_var_new_pfd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_mkdirat(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_mkdirat(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mkdirat(unsigned long long __rpc_info, void *__buf, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_mkdirat(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mkdirat(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, mode_t mode, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_mkdirat(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_link(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_link(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_link(unsigned long long __rpc_info, void *__buf, int old_pfd, int new_pfd)
{
	int __ret;
	int __maybe_unused __actv_local_var_old_pfd = old_pfd;
	int __maybe_unused __actv_local_var_new_pfd = new_pfd;
	__ret = ____actvcall_fscall_vfs_link(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(old_pfd, __actv_local_var_old_pfd), __ARCH_ACTV_RPC_PASS_ARG(new_pfd, __actv_local_var_new_pfd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_link(rref_t __rref, unsigned long long __rpc_info, void *__buf, int old_pfd, int new_pfd)
{
	int __ret;
	int __maybe_unused __actv_local_var_old_pfd = old_pfd;
	int __maybe_unused __actv_local_var_new_pfd = new_pfd;
	__ret = ____actvcapcall_fscall_vfs_link(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(old_pfd, __actv_local_var_old_pfd), __ARCH_ACTV_RPC_PASS_ARG(new_pfd, __actv_local_var_new_pfd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_unlink(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_unlink(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_unlink(unsigned long long __rpc_info, void *__buf, int dfd, unsigned int flag, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_unlink(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_unlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, unsigned int flag, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_unlink(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_symlink(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_symlink(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_symlink(unsigned long long __rpc_info, void *__buf, int dfd, const void *target, unsigned int tarlen, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused const void *__actv_local_var_target = target;
	unsigned int __maybe_unused __actv_local_var_tarlen = tarlen;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_symlink(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(target, __actv_local_var_target), __ARCH_ACTV_RPC_PASS_ARG(tarlen, __actv_local_var_tarlen), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_symlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, const void *target, unsigned int tarlen, void *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused const void *__actv_local_var_target = target;
	unsigned int __maybe_unused __actv_local_var_tarlen = tarlen;
	__maybe_unused void *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_symlink(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(target, __actv_local_var_target), __ARCH_ACTV_RPC_PASS_ARG(tarlen, __actv_local_var_tarlen), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_fscall_vfs_getxattr(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_fscall_vfs_getxattr(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_getxattr(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned int pcnode_idx, unsigned int cnode_idx, int dfd, struct sysif_getxattr_args sga, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_pcnode_idx = pcnode_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_dfd = dfd;
	struct sysif_getxattr_args __maybe_unused __actv_local_var_sga = sga;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_getxattr(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(pcnode_idx, __actv_local_var_pcnode_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(sga, __actv_local_var_sga), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_getxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned int pcnode_idx, unsigned int cnode_idx, int dfd, struct sysif_getxattr_args sga, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_pcnode_idx = pcnode_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_dfd = dfd;
	struct sysif_getxattr_args __maybe_unused __actv_local_var_sga = sga;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_getxattr(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(pcnode_idx, __actv_local_var_pcnode_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(sga, __actv_local_var_sga), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_fgetxattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_fgetxattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fgetxattr(unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen, void *value, size_t size)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	__maybe_unused void *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_fscall_vfs_fgetxattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fgetxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen, void *value, size_t size)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	__maybe_unused void *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_fscall_vfs_fgetxattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_setxattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_setxattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_setxattr(unsigned long long __rpc_info, void *__buf, int dfd, const char *name, size_t namelen, const char *value, size_t size, int flags, unsigned int walk_flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	__maybe_unused const char *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_walk_flags = walk_flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_setxattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(walk_flags, __actv_local_var_walk_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_setxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, const char *name, size_t namelen, const char *value, size_t size, int flags, unsigned int walk_flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	__maybe_unused const char *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_walk_flags = walk_flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_setxattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(walk_flags, __actv_local_var_walk_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fsetxattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fsetxattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fsetxattr(unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen, const char *value, size_t size, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	__maybe_unused const char *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_fsetxattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fsetxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen, const char *value, size_t size, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	__maybe_unused const char *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_fsetxattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_fscall_vfs_listxattr(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_fscall_vfs_listxattr(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_listxattr(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, char *list, size_t size, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused char *__actv_local_var_list = list;
	size_t __maybe_unused __actv_local_var_size = size;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_listxattr(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(list, __actv_local_var_list), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_listxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, int dfd, char *list, size_t size, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused char *__actv_local_var_list = list;
	size_t __maybe_unused __actv_local_var_size = size;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_listxattr(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(list, __actv_local_var_list), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_flistxattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_flistxattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_flistxattr(unsigned long long __rpc_info, void *__buf, int fd, char *list, size_t size)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused char *__actv_local_var_list = list;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_fscall_vfs_flistxattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(list, __actv_local_var_list), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_flistxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, char *list, size_t size)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused char *__actv_local_var_list = list;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_fscall_vfs_flistxattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(list, __actv_local_var_list), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_removexattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_removexattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_removexattr(unsigned long long __rpc_info, void *__buf, int dfd, const char *name, size_t namelen, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcall_fscall_vfs_removexattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_removexattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int dfd, const char *name, size_t namelen, unsigned int flags, char *newpath, char *new_server, int *me_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_dfd = dfd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused char *__actv_local_var_newpath = newpath;
	__maybe_unused char *__actv_local_var_new_server = new_server;
	__maybe_unused int *__actv_local_var_me_idx = me_idx;
	__ret = ____actvcapcall_fscall_vfs_removexattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dfd, __actv_local_var_dfd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(newpath, __actv_local_var_newpath), __ARCH_ACTV_RPC_PASS_ARG(new_server, __actv_local_var_new_server), __ARCH_ACTV_RPC_PASS_ARG(me_idx, __actv_local_var_me_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fremovexattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fremovexattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fremovexattr(unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	__ret = ____actvcall_fscall_vfs_fremovexattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fremovexattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const char *name, size_t namelen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const char *__actv_local_var_name = name;
	size_t __maybe_unused __actv_local_var_namelen = namelen;
	__ret = ____actvcapcall_fscall_vfs_fremovexattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_iommap(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_iommap(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_iommap(unsigned long long __rpc_info, void *__buf, int fd, rref_t vs_rref, unsigned int vs_cnode_idx, uintptr_t vaddr, size_t aligned_len, unsigned int prot, unsigned int flags, long long offset)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	rref_t __maybe_unused __actv_local_var_vs_rref = vs_rref;
	unsigned int __maybe_unused __actv_local_var_vs_cnode_idx = vs_cnode_idx;
	uintptr_t __maybe_unused __actv_local_var_vaddr = vaddr;
	size_t __maybe_unused __actv_local_var_aligned_len = aligned_len;
	unsigned int __maybe_unused __actv_local_var_prot = prot;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	long long __maybe_unused __actv_local_var_offset = offset;
	__ret = ____actvcall_fscall_vfs_iommap(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(vs_rref, __actv_local_var_vs_rref), __ARCH_ACTV_RPC_PASS_ARG(vs_cnode_idx, __actv_local_var_vs_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(vaddr, __actv_local_var_vaddr), __ARCH_ACTV_RPC_PASS_ARG(aligned_len, __actv_local_var_aligned_len), __ARCH_ACTV_RPC_PASS_ARG(prot, __actv_local_var_prot), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_iommap(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, rref_t vs_rref, unsigned int vs_cnode_idx, uintptr_t vaddr, size_t aligned_len, unsigned int prot, unsigned int flags, long long offset)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	rref_t __maybe_unused __actv_local_var_vs_rref = vs_rref;
	unsigned int __maybe_unused __actv_local_var_vs_cnode_idx = vs_cnode_idx;
	uintptr_t __maybe_unused __actv_local_var_vaddr = vaddr;
	size_t __maybe_unused __actv_local_var_aligned_len = aligned_len;
	unsigned int __maybe_unused __actv_local_var_prot = prot;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	long long __maybe_unused __actv_local_var_offset = offset;
	__ret = ____actvcapcall_fscall_vfs_iommap(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(vs_rref, __actv_local_var_vs_rref), __ARCH_ACTV_RPC_PASS_ARG(vs_cnode_idx, __actv_local_var_vs_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(vaddr, __actv_local_var_vaddr), __ARCH_ACTV_RPC_PASS_ARG(aligned_len, __actv_local_var_aligned_len), __ARCH_ACTV_RPC_PASS_ARG(prot, __actv_local_var_prot), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_mmap_create(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_mmap_create(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mmap_create(unsigned long long __rpc_info, void *__buf, int fd, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long long __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_prot = prot;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_mmap_create(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(prot, __actv_local_var_prot), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mmap_create(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot, unsigned int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long long __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_prot = prot;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_mmap_create(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(prot, __actv_local_var_prot), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_mmap_release_file(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_mmap_release_file(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mmap_release_file(unsigned long long __rpc_info, void *__buf, int fid, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_vfs_mmap_release_file(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mmap_release_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_vfs_mmap_release_file(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_mmap_change(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_mmap_change(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mmap_change(unsigned long long __rpc_info, void *__buf, int fid, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long long __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_prot = prot;
	__ret = ____actvcall_fscall_vfs_mmap_change(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(prot, __actv_local_var_prot));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mmap_change(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, long long offset, unsigned long long len, unsigned int cnode_idx, unsigned int prot)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long long __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned int __maybe_unused __actv_local_var_prot = prot;
	__ret = ____actvcapcall_fscall_vfs_mmap_change(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(prot, __actv_local_var_prot));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_mmap_fill_page(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_mmap_fill_page(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mmap_fill_page(unsigned long long __rpc_info, void *__buf, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, unsigned long long flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	unsigned long long __maybe_unused __actv_local_var_node_page_idx = node_page_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned long long __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_mmap_fill_page(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(node_page_idx, __actv_local_var_node_page_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mmap_fill_page(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, unsigned long long node_page_idx, unsigned int cnode_idx, unsigned long long flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	unsigned long long __maybe_unused __actv_local_var_node_page_idx = node_page_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned long long __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_mmap_fill_page(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(node_page_idx, __actv_local_var_node_page_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_mmap_fetch_page(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_mmap_fetch_page(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mmap_fetch_page(unsigned long long __rpc_info, void *__buf, int fid, unsigned long long node_page_idx, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	unsigned long long __maybe_unused __actv_local_var_node_page_idx = node_page_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_vfs_mmap_fetch_page(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(node_page_idx, __actv_local_var_node_page_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mmap_fetch_page(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, unsigned long long node_page_idx, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	unsigned long long __maybe_unused __actv_local_var_node_page_idx = node_page_idx;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_vfs_mmap_fetch_page(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(node_page_idx, __actv_local_var_node_page_idx), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_mmap_change_page(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_mmap_change_page(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mmap_change_page(unsigned long long __rpc_info, void *__buf, unsigned int index, unsigned long long dev_id, unsigned long long node_page_idx, unsigned int flag)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_index = index;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned long long __maybe_unused __actv_local_var_node_page_idx = node_page_idx;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__ret = ____actvcall_fscall_vfs_mmap_change_page(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(index, __actv_local_var_index), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(node_page_idx, __actv_local_var_node_page_idx), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mmap_change_page(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int index, unsigned long long dev_id, unsigned long long node_page_idx, unsigned int flag)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_index = index;
	unsigned long long __maybe_unused __actv_local_var_dev_id = dev_id;
	unsigned long long __maybe_unused __actv_local_var_node_page_idx = node_page_idx;
	unsigned int __maybe_unused __actv_local_var_flag = flag;
	__ret = ____actvcapcall_fscall_vfs_mmap_change_page(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(index, __actv_local_var_index), __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(node_page_idx, __actv_local_var_node_page_idx), __ARCH_ACTV_RPC_PASS_ARG(flag, __actv_local_var_flag));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_mmap_fallocate(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_mmap_fallocate(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_mmap_fallocate(unsigned long long __rpc_info, void *__buf, int fid, unsigned long long offset, unsigned long long length, int mode, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	unsigned long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long long __maybe_unused __actv_local_var_length = length;
	int __maybe_unused __actv_local_var_mode = mode;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_vfs_mmap_fallocate(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(length, __actv_local_var_length), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_mmap_fallocate(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fid, unsigned long long offset, unsigned long long length, int mode, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fid = fid;
	unsigned long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long long __maybe_unused __actv_local_var_length = length;
	int __maybe_unused __actv_local_var_mode = mode;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_vfs_mmap_fallocate(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fid, __actv_local_var_fid), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(length, __actv_local_var_length), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_fscall_vfs_gfd_table_update(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_fscall_vfs_gfd_table_update(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_gfd_table_update(unsigned long long __rpc_info, void *__buf, int fd, int remote_index, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_remote_index = remote_index;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_vfs_gfd_table_update(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(remote_index, __actv_local_var_remote_index), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_gfd_table_update(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int remote_index, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_remote_index = remote_index;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_vfs_gfd_table_update(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(remote_index, __actv_local_var_remote_index), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_gfd_table_remove(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_gfd_table_remove(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_gfd_table_remove(unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_vfs_gfd_table_remove(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_gfd_table_remove(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_vfs_gfd_table_remove(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_gfd_table_expand(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_gfd_table_expand(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_gfd_table_expand(unsigned long long __rpc_info, void *__buf, unsigned int new_size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_new_size = new_size;
	__ret = ____actvcall_fscall_vfs_gfd_table_expand(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(new_size, __actv_local_var_new_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_gfd_table_expand(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int new_size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_new_size = new_size;
	__ret = ____actvcapcall_fscall_vfs_gfd_table_expand(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(new_size, __actv_local_var_new_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_gfd_table_acquire(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_gfd_table_acquire(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_gfd_table_acquire(unsigned long long __rpc_info, void *__buf, int start, int type, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_start = start;
	int __maybe_unused __actv_local_var_type = type;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_fscall_vfs_gfd_table_acquire(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(start, __actv_local_var_start), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_gfd_table_acquire(rref_t __rref, unsigned long long __rpc_info, void *__buf, int start, int type, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_start = start;
	int __maybe_unused __actv_local_var_type = type;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_fscall_vfs_gfd_table_acquire(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(start, __actv_local_var_start), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_gfd_table_release(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_gfd_table_release(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_gfd_table_release(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_fscall_vfs_gfd_table_release(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_gfd_table_release(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_fscall_vfs_gfd_table_release(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_gfd_table_replace(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_gfd_table_replace(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_gfd_table_replace(unsigned long long __rpc_info, void *__buf, int fd, int type)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcall_fscall_vfs_gfd_table_replace(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_gfd_table_replace(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int type)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcapcall_fscall_vfs_gfd_table_replace(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_gfd_table_fault(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_gfd_table_fault(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_gfd_table_fault(unsigned long long __rpc_info, void *__buf, int fd, char *pathname, int pathlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused char *__actv_local_var_pathname = pathname;
	int __maybe_unused __actv_local_var_pathlen = pathlen;
	__ret = ____actvcall_fscall_vfs_gfd_table_fault(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(pathlen, __actv_local_var_pathlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_gfd_table_fault(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, char *pathname, int pathlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused char *__actv_local_var_pathname = pathname;
	int __maybe_unused __actv_local_var_pathlen = pathlen;
	__ret = ____actvcapcall_fscall_vfs_gfd_table_fault(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pathname, __actv_local_var_pathname), __ARCH_ACTV_RPC_PASS_ARG(pathlen, __actv_local_var_pathlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_anon_register_devhost(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_anon_register_devhost(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_anon_register_devhost(unsigned long long __rpc_info, void *__buf, uref_t dh_ap_uref)
{
	int __ret;
	uref_t __maybe_unused __actv_local_var_dh_ap_uref = dh_ap_uref;
	__ret = ____actvcall_fscall_vfs_anon_register_devhost(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dh_ap_uref, __actv_local_var_dh_ap_uref));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_anon_register_devhost(rref_t __rref, unsigned long long __rpc_info, void *__buf, uref_t dh_ap_uref)
{
	int __ret;
	uref_t __maybe_unused __actv_local_var_dh_ap_uref = dh_ap_uref;
	__ret = ____actvcapcall_fscall_vfs_anon_register_devhost(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dh_ap_uref, __actv_local_var_dh_ap_uref));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_get_unused_fd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_get_unused_fd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_get_unused_fd(unsigned long long __rpc_info, void *__buf, unsigned int flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_fscall_vfs_get_unused_fd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_get_unused_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_fscall_vfs_get_unused_fd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_put_unused_fd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_put_unused_fd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_put_unused_fd(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_fscall_vfs_put_unused_fd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_put_unused_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_fscall_vfs_put_unused_fd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_fd_info_update(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_fd_info_update(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_fd_info_update(unsigned long long __rpc_info, void *__buf, int fd, unsigned long long file_id)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcall_fscall_vfs_fd_info_update(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_fd_info_update(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, unsigned long long file_id)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcapcall_fscall_vfs_fd_info_update(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_get_root_path(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_get_root_path(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_get_root_path(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, char *buf, int buflen)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_buf = buf;
	int __maybe_unused __actv_local_var_buflen = buflen;
	__ret = ____actvcall_fscall_vfs_get_root_path(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(buflen, __actv_local_var_buflen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_get_root_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, char *buf, int buflen)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_buf = buf;
	int __maybe_unused __actv_local_var_buflen = buflen;
	__ret = ____actvcapcall_fscall_vfs_get_root_path(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(buflen, __actv_local_var_buflen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_transfs_fget(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_transfs_fget(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_transfs_fget(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_fscall_vfs_transfs_fget(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_transfs_fget(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_fscall_vfs_transfs_fget(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_do_trans_fget(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_do_trans_fget(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_do_trans_fget(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_fscall_vfs_do_trans_fget(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_do_trans_fget(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_fscall_vfs_do_trans_fget(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_transfs_fput(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_transfs_fput(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_transfs_fput(unsigned long long __rpc_info, void *__buf, unsigned int me_index, unsigned long long hm_filp)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_me_index = me_index;
	unsigned long long __maybe_unused __actv_local_var_hm_filp = hm_filp;
	__ret = ____actvcall_fscall_vfs_transfs_fput(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_index, __actv_local_var_me_index), __ARCH_ACTV_RPC_PASS_ARG(hm_filp, __actv_local_var_hm_filp));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_transfs_fput(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int me_index, unsigned long long hm_filp)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_me_index = me_index;
	unsigned long long __maybe_unused __actv_local_var_hm_filp = hm_filp;
	__ret = ____actvcapcall_fscall_vfs_transfs_fput(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(me_index, __actv_local_var_me_index), __ARCH_ACTV_RPC_PASS_ARG(hm_filp, __actv_local_var_hm_filp));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_fscall_vfs_do_trans_fput(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_fscall_vfs_do_trans_fput(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_do_trans_fput(unsigned long long __rpc_info, void *__buf, unsigned long long hm_filp)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_hm_filp = hm_filp;
	__ret = ____actvcall_fscall_vfs_do_trans_fput(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(hm_filp, __actv_local_var_hm_filp));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_do_trans_fput(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long hm_filp)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_hm_filp = hm_filp;
	__ret = ____actvcapcall_fscall_vfs_do_trans_fput(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(hm_filp, __actv_local_var_hm_filp));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_fscall_vfs_read_mounts(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_fscall_vfs_read_mounts(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_fscall_vfs_read_mounts(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, char *buf, size_t buflen, char *srvname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_buflen = buflen;
	__maybe_unused char *__actv_local_var_srvname = srvname;
	__ret = ____actvcall_fscall_vfs_read_mounts(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(buflen, __actv_local_var_buflen), __ARCH_ACTV_RPC_PASS_ARG(srvname, __actv_local_var_srvname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_fscall_vfs_read_mounts(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, char *buf, size_t buflen, char *srvname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__maybe_unused char *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_buflen = buflen;
	__maybe_unused char *__actv_local_var_srvname = srvname;
	__ret = ____actvcapcall_fscall_vfs_read_mounts(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(buflen, __actv_local_var_buflen), __ARCH_ACTV_RPC_PASS_ARG(srvname, __actv_local_var_srvname));
	return __ret;
}

#endif
#endif
