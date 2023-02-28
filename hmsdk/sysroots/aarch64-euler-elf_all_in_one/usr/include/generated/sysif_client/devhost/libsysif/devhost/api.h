/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for devhost
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/devhost/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/devhost/libsysif/devhost/api.h --server-dest ../image/usr/include/generated/sysif_server/devhost/libsysif/devhost/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_DEVHOST_API_H
#define LIBSYSIF_DEVHOST_API_H
#ifndef LIBSYSIF_DEVHOST_COMMON_H
#define LIBSYSIF_DEVHOST_COMMON_H
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
#include <libhmpm/shutdown.h>
#include <libsysif/devmgr/types.h>


#define DEVHOST_ENTROPY_DATA_MAX_LEN	64
struct devhost_entropy_data {
	unsigned char buf[DEVHOST_ENTROPY_DATA_MAX_LEN];
	unsigned int len;
	/* health test fail count */
	unsigned int fail_count;
};



#include <stdint.h>

#include <hmkernel/types.h>
#include <hmkernel/capability.h>

#include <libsysif/devhost/bd_types.h>

raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_core_load_driver_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_core_load_driver_arg_args_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_core_create_device_arg_devname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_core_create_device_arg_dev_compat_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_core_unload_driver_arg_drvname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_core_bind_device_arg_dev_compat_is_too_large);
raw_static_assert(sizeof(rref_t) <= 96,
                    drvcall_devhost_fops_open_arg_tgt_rref_is_too_large);
raw_static_assert(sizeof(uref_t) <= 96,
                    drvcall_devhost_block_register_bio_notify_arg_uref_is_too_large);
raw_static_assert(sizeof(rref_t) <= 96,
                    drvcall_devhost_net_init_arg_tgt_rref_is_too_large);
raw_static_assert(sizeof(struct reboot_cmd) <= 96,
                    drvcall_devhost_pm_prepare_arg_cmd_is_too_large);
raw_static_assert(sizeof(struct reboot_cmd) <= 96,
                    drvcall_devhost_pm_reboot_arg_cmd_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_procfs_read_arg_ubuf_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_procfs_write_arg_ubuf_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_sysfs_read_arg_ubuf_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_sysfs_write_arg_ubuf_is_too_large);
raw_static_assert(sizeof(dev_t) <= 96,
                    drvcall_devhost_transfs_mounted_arg_dev_id_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_mounted_arg_fs_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_mounted_arg_mount_opts_is_too_large);
raw_static_assert(sizeof(mode_t) <= 96,
                    drvcall_devhost_transfs_mkdir_arg_mode_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_mkdir_arg_actv_dname_is_too_large);
raw_static_assert(sizeof(mode_t) <= 96,
                    drvcall_devhost_transfs_create_arg_mode_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_create_arg_actv_dname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_mknod_arg_actv_dname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_link_arg_actv_dname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_symlink_arg_actv_dname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_symlink_arg_actv_path_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_rename_arg_actv_dname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_lookup_arg_actv_dname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_getxattr_arg_actv_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_setxattr_arg_actv_name_is_too_large);
raw_static_assert(sizeof(mode_t) <= 96,
                    drvcall_devhost_transfs_tmpfile_arg_mode_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devhost_transfs_tmpfile_arg_actv_dname_is_too_large);
struct __actvret_drvcall_devhost_core_load_driver {
};

struct __actvret_drvcall_devhost_core_create_device {
	int devid;
};

struct __actvret_drvcall_devhost_core_unload_driver {
};

struct __actvret_drvcall_devhost_core_bind_device {
};

struct __actvret_drvcall_devhost_core_entropy_read {
	struct devhost_entropy_data data;
};

struct __actvret_drvcall_devhost_rpc_export {
	uref_t uref;
};

struct __actvret_drvcall_devhost_rpc_invoke {
	unsigned long long resp_size;
};

struct __actvret_drvcall_devhost_fops_open {
	unsigned long long filp;
};

struct __actvret_drvcall_devhost_fops_close {
};

struct __actvret_drvcall_devhost_fops_read {
	unsigned long long nread;
};

struct __actvret_drvcall_devhost_fops_write {
	unsigned long long nwrite;
};

struct __actvret_drvcall_devhost_fops_ioctl {
};

struct __actvret_drvcall_devhost_fops_llseek {
	long long pos;
};

struct __actvret_drvcall_devhost_fops_mmap {
	unsigned long long rvaddr;
};

struct __actvret_drvcall_devhost_fops_munmap {
};

struct __actvret_drvcall_devhost_fops_sysfs_read {
};

struct __actvret_drvcall_devhost_fops_sysfs_write {
};

struct __actvret_drvcall_devhost_fops_epoll_ctl {
};

struct __actvret_drvcall_devhost_fops_epoll_close {
};

struct __actvret_drvcall_devhost_fops_epoll_et {
	unsigned int revents;
};

struct __actvret_drvcall_devhost_fops_epoll_reinit_add {
};

struct __actvret_drvcall_devhost_block_check_feature {
	unsigned long long supported_features;
};

struct __actvret_drvcall_devhost_block_run_queue {
};

struct __actvret_drvcall_devhost_block_direct_access {
	unsigned long long paddr;
	unsigned long long ret_size;
};

struct __actvret_drvcall_devhost_block_register_bio_notify {
	unsigned long long submit_fd;
	unsigned long long end_fd;
	unsigned long long shm_id;
	unsigned long long obj_cnt;
};

struct __actvret_drvcall_devhost_net_send {
};

struct __actvret_drvcall_devhost_net_ioctl {
};

struct __actvret_drvcall_devhost_net_status {
	struct netdev_status status;
};

struct __actvret_drvcall_devhost_net_prepare {
	unsigned int pool_size;
	unsigned int unit_size;
	unsigned long long shm_id;
	unsigned long long rx_uring_shm_id;
};

struct __actvret_drvcall_devhost_net_init {
};

struct __actvret_drvcall_devhost_net_netlink_recv {
};

struct __actvret_drvcall_devhost_pm_action {
};

struct __actvret_drvcall_devhost_pm_prepare {
};

struct __actvret_drvcall_devhost_pm_power_off {
};

struct __actvret_drvcall_devhost_pm_reboot {
};

struct __actvret_drvcall_devhost_pm_cpuhp_action {
};

struct __actvret_drvcall_devhost_procfs_read {
	unsigned long long rsize;
};

struct __actvret_drvcall_devhost_procfs_write {
	unsigned long long wsize;
};

struct __actvret_drvcall_devhost_sysfs_read {
	unsigned long long rsize;
};

struct __actvret_drvcall_devhost_sysfs_write {
	unsigned long long wsize;
};

struct __actvret_drvcall_devhost_sysfs_poll {
};

struct __actvret_drvcall_devhost_clock_settime {
};

struct __actvret_drvcall_devhost_clock_gettime {
};

struct __actvret_drvcall_devhost_clock_getres {
};

struct __actvret_drvcall_devhost_clock_adjtime {
};

struct __actvret_drvcall_devhost_transfs_mounted {
	struct transfs_m_info_t m_info;
};

struct __actvret_drvcall_devhost_transfs_unmounted {
};

struct __actvret_drvcall_devhost_transfs_drop_caches {
};

struct __actvret_drvcall_devhost_transfs_mkdir {
	struct transfs_dn_info_t dn_info_out;
};

struct __actvret_drvcall_devhost_transfs_rmdir {
};

struct __actvret_drvcall_devhost_transfs_create {
	struct transfs_dn_info_t dn_info_out;
};

struct __actvret_drvcall_devhost_transfs_unlink {
};

struct __actvret_drvcall_devhost_transfs_mknod {
	struct transfs_dn_info_t dn_info_out;
};

struct __actvret_drvcall_devhost_transfs_link {
	struct transfs_dn_info_t dn_info_out;
};

struct __actvret_drvcall_devhost_transfs_symlink {
	struct transfs_dn_info_t dn_info_out;
};

struct __actvret_drvcall_devhost_transfs_statfs {
};

struct __actvret_drvcall_devhost_transfs_rename {
};

struct __actvret_drvcall_devhost_transfs_lookup {
	struct transfs_dn_info_t dn_info_out;
};

struct __actvret_drvcall_devhost_transfs_setattr {
};

struct __actvret_drvcall_devhost_transfs_readlink {
};

struct __actvret_drvcall_devhost_transfs_getattr {
};

struct __actvret_drvcall_devhost_transfs_listxattr {
	long long written;
};

struct __actvret_drvcall_devhost_transfs_getxattr {
	long long nbytes;
};

struct __actvret_drvcall_devhost_transfs_setxattr {
};

struct __actvret_drvcall_devhost_transfs_tmpfile {
	struct transfs_dn_info_t dn_info_out;
};

struct __actvret_drvcall_devhost_transfs_kill_dentry {
};

struct __actvret_drvcall_devhost_transfs_node_put {
};

struct __actvret_drvcall_devhost_transfs_sync {
};

struct __actvret_drvcall_devhost_transfs_write {
	long long nwritten;
};

struct __actvret_drvcall_devhost_transfs_fsync {
};

struct __actvret_drvcall_devhost_transfs_readdir {
};

struct __actvret_drvcall_devhost_transfs_open {
	unsigned int f_index;
};

struct __actvret_drvcall_devhost_transfs_fallocate {
};

struct __actvret_drvcall_devhost_transfs_close {
};

struct __actvret_drvcall_devhost_transfs_ioctl {
};

struct __actvret_drvcall_devhost_transfs_direct_IO {
	long long nbytes;
};

struct __actvret_drvcall_devhost_transfs_update_opts {
};

union __actvret_drvcall_devhost {
	struct __actvret_drvcall_devhost_core_load_driver core_load_driver;
	struct __actvret_drvcall_devhost_core_create_device core_create_device;
	struct __actvret_drvcall_devhost_core_unload_driver core_unload_driver;
	struct __actvret_drvcall_devhost_core_bind_device core_bind_device;
	struct __actvret_drvcall_devhost_core_entropy_read core_entropy_read;
	struct __actvret_drvcall_devhost_rpc_export rpc_export;
	struct __actvret_drvcall_devhost_rpc_invoke rpc_invoke;
	struct __actvret_drvcall_devhost_fops_open fops_open;
	struct __actvret_drvcall_devhost_fops_close fops_close;
	struct __actvret_drvcall_devhost_fops_read fops_read;
	struct __actvret_drvcall_devhost_fops_write fops_write;
	struct __actvret_drvcall_devhost_fops_ioctl fops_ioctl;
	struct __actvret_drvcall_devhost_fops_llseek fops_llseek;
	struct __actvret_drvcall_devhost_fops_mmap fops_mmap;
	struct __actvret_drvcall_devhost_fops_munmap fops_munmap;
	struct __actvret_drvcall_devhost_fops_sysfs_read fops_sysfs_read;
	struct __actvret_drvcall_devhost_fops_sysfs_write fops_sysfs_write;
	struct __actvret_drvcall_devhost_fops_epoll_ctl fops_epoll_ctl;
	struct __actvret_drvcall_devhost_fops_epoll_close fops_epoll_close;
	struct __actvret_drvcall_devhost_fops_epoll_et fops_epoll_et;
	struct __actvret_drvcall_devhost_fops_epoll_reinit_add fops_epoll_reinit_add;
	struct __actvret_drvcall_devhost_block_check_feature block_check_feature;
	struct __actvret_drvcall_devhost_block_run_queue block_run_queue;
	struct __actvret_drvcall_devhost_block_direct_access block_direct_access;
	struct __actvret_drvcall_devhost_block_register_bio_notify block_register_bio_notify;
	struct __actvret_drvcall_devhost_net_send net_send;
	struct __actvret_drvcall_devhost_net_ioctl net_ioctl;
	struct __actvret_drvcall_devhost_net_status net_status;
	struct __actvret_drvcall_devhost_net_prepare net_prepare;
	struct __actvret_drvcall_devhost_net_init net_init;
	struct __actvret_drvcall_devhost_net_netlink_recv net_netlink_recv;
	struct __actvret_drvcall_devhost_pm_action pm_action;
	struct __actvret_drvcall_devhost_pm_prepare pm_prepare;
	struct __actvret_drvcall_devhost_pm_power_off pm_power_off;
	struct __actvret_drvcall_devhost_pm_reboot pm_reboot;
	struct __actvret_drvcall_devhost_pm_cpuhp_action pm_cpuhp_action;
	struct __actvret_drvcall_devhost_procfs_read procfs_read;
	struct __actvret_drvcall_devhost_procfs_write procfs_write;
	struct __actvret_drvcall_devhost_sysfs_read sysfs_read;
	struct __actvret_drvcall_devhost_sysfs_write sysfs_write;
	struct __actvret_drvcall_devhost_sysfs_poll sysfs_poll;
	struct __actvret_drvcall_devhost_clock_settime clock_settime;
	struct __actvret_drvcall_devhost_clock_gettime clock_gettime;
	struct __actvret_drvcall_devhost_clock_getres clock_getres;
	struct __actvret_drvcall_devhost_clock_adjtime clock_adjtime;
	struct __actvret_drvcall_devhost_transfs_mounted transfs_mounted;
	struct __actvret_drvcall_devhost_transfs_unmounted transfs_unmounted;
	struct __actvret_drvcall_devhost_transfs_drop_caches transfs_drop_caches;
	struct __actvret_drvcall_devhost_transfs_mkdir transfs_mkdir;
	struct __actvret_drvcall_devhost_transfs_rmdir transfs_rmdir;
	struct __actvret_drvcall_devhost_transfs_create transfs_create;
	struct __actvret_drvcall_devhost_transfs_unlink transfs_unlink;
	struct __actvret_drvcall_devhost_transfs_mknod transfs_mknod;
	struct __actvret_drvcall_devhost_transfs_link transfs_link;
	struct __actvret_drvcall_devhost_transfs_symlink transfs_symlink;
	struct __actvret_drvcall_devhost_transfs_statfs transfs_statfs;
	struct __actvret_drvcall_devhost_transfs_rename transfs_rename;
	struct __actvret_drvcall_devhost_transfs_lookup transfs_lookup;
	struct __actvret_drvcall_devhost_transfs_setattr transfs_setattr;
	struct __actvret_drvcall_devhost_transfs_readlink transfs_readlink;
	struct __actvret_drvcall_devhost_transfs_getattr transfs_getattr;
	struct __actvret_drvcall_devhost_transfs_listxattr transfs_listxattr;
	struct __actvret_drvcall_devhost_transfs_getxattr transfs_getxattr;
	struct __actvret_drvcall_devhost_transfs_setxattr transfs_setxattr;
	struct __actvret_drvcall_devhost_transfs_tmpfile transfs_tmpfile;
	struct __actvret_drvcall_devhost_transfs_kill_dentry transfs_kill_dentry;
	struct __actvret_drvcall_devhost_transfs_node_put transfs_node_put;
	struct __actvret_drvcall_devhost_transfs_sync transfs_sync;
	struct __actvret_drvcall_devhost_transfs_write transfs_write;
	struct __actvret_drvcall_devhost_transfs_fsync transfs_fsync;
	struct __actvret_drvcall_devhost_transfs_readdir transfs_readdir;
	struct __actvret_drvcall_devhost_transfs_open transfs_open;
	struct __actvret_drvcall_devhost_transfs_fallocate transfs_fallocate;
	struct __actvret_drvcall_devhost_transfs_close transfs_close;
	struct __actvret_drvcall_devhost_transfs_ioctl transfs_ioctl;
	struct __actvret_drvcall_devhost_transfs_direct_IO transfs_direct_IO;
	struct __actvret_drvcall_devhost_transfs_update_opts transfs_update_opts;
};

enum __devhost_mgr {
	__devhost_INVAL_mgr=0,
	__devhost_core_mgr,
	__devhost_rpc_mgr,
	__devhost_fops_mgr,
	__devhost_block_mgr,
	__devhost_net_mgr,
	__devhost_pm_mgr,
	__devhost_procfs_mgr,
	__devhost_sysfs_mgr,
	__devhost_clock_mgr,
	__devhost_transfs_mgr,
	__devhost_MAX_mgr,
};

#define __devhost_method_MIN __ACTV_HIGHTABLE_START
#define __devhost_method_core_load_driver (__ACTV_HIGHTABLE_START + 1)
#define __devhost_method_core_create_device (__ACTV_HIGHTABLE_START + 2)
#define __devhost_method_core_unload_driver (__ACTV_HIGHTABLE_START + 3)
#define __devhost_method_core_bind_device (__ACTV_HIGHTABLE_START + 4)
#define __devhost_method_core_entropy_read (__ACTV_HIGHTABLE_START + 5)
#define __devhost_method_core_rsvd_3 (__ACTV_HIGHTABLE_START + 6)
#define __devhost_method_core_rsvd_2 (__ACTV_HIGHTABLE_START + 7)
#define __devhost_method_core_rsvd_1 (__ACTV_HIGHTABLE_START + 8)
#define __devhost_method_rpc_export (__ACTV_HIGHTABLE_START + 9)
#define __devhost_method_rpc_invoke (__ACTV_HIGHTABLE_START + 10)
#define __devhost_method_rpc_rsvd_2 (__ACTV_HIGHTABLE_START + 11)
#define __devhost_method_rpc_rsvd_1 (__ACTV_HIGHTABLE_START + 12)
#define __devhost_method_fops_open (__ACTV_HIGHTABLE_START + 13)
#define __devhost_method_fops_close (__ACTV_HIGHTABLE_START + 14)
#define __devhost_method_fops_read (__ACTV_HIGHTABLE_START + 15)
#define __devhost_method_fops_write (__ACTV_HIGHTABLE_START + 16)
#define __devhost_method_fops_ioctl (__ACTV_HIGHTABLE_START + 17)
#define __devhost_method_fops_llseek (__ACTV_HIGHTABLE_START + 18)
#define __devhost_method_fops_mmap (__ACTV_HIGHTABLE_START + 19)
#define __devhost_method_fops_munmap (__ACTV_HIGHTABLE_START + 20)
#define __devhost_method_fops_sysfs_read (__ACTV_HIGHTABLE_START + 21)
#define __devhost_method_fops_sysfs_write (__ACTV_HIGHTABLE_START + 22)
#define __devhost_method_fops_epoll_ctl (__ACTV_HIGHTABLE_START + 23)
#define __devhost_method_fops_epoll_close (__ACTV_HIGHTABLE_START + 24)
#define __devhost_method_fops_epoll_et (__ACTV_HIGHTABLE_START + 25)
#define __devhost_method_fops_epoll_reinit_add (__ACTV_HIGHTABLE_START + 26)
#define __devhost_method_fops_rsvd_2 (__ACTV_HIGHTABLE_START + 27)
#define __devhost_method_fops_rsvd_1 (__ACTV_HIGHTABLE_START + 28)
#define __devhost_method_block_check_feature (__ACTV_HIGHTABLE_START + 29)
#define __devhost_method_block_run_queue (__ACTV_HIGHTABLE_START + 30)
#define __devhost_method_block_direct_access (__ACTV_HIGHTABLE_START + 31)
#define __devhost_method_block_register_bio_notify (__ACTV_HIGHTABLE_START + 32)
#define __devhost_method_block_rsvd_4 (__ACTV_HIGHTABLE_START + 33)
#define __devhost_method_block_rsvd_3 (__ACTV_HIGHTABLE_START + 34)
#define __devhost_method_block_rsvd_2 (__ACTV_HIGHTABLE_START + 35)
#define __devhost_method_block_rsvd_1 (__ACTV_HIGHTABLE_START + 36)
#define __devhost_method_net_send (__ACTV_HIGHTABLE_START + 37)
#define __devhost_method_net_ioctl (__ACTV_HIGHTABLE_START + 38)
#define __devhost_method_net_status (__ACTV_HIGHTABLE_START + 39)
#define __devhost_method_net_prepare (__ACTV_HIGHTABLE_START + 40)
#define __devhost_method_net_init (__ACTV_HIGHTABLE_START + 41)
#define __devhost_method_net_netlink_recv (__ACTV_HIGHTABLE_START + 42)
#define __devhost_method_net_rsvd_2 (__ACTV_HIGHTABLE_START + 43)
#define __devhost_method_net_rsvd_1 (__ACTV_HIGHTABLE_START + 44)
#define __devhost_method_pm_action (__ACTV_HIGHTABLE_START + 45)
#define __devhost_method_pm_prepare (__ACTV_HIGHTABLE_START + 46)
#define __devhost_method_pm_power_off (__ACTV_HIGHTABLE_START + 47)
#define __devhost_method_pm_reboot (__ACTV_HIGHTABLE_START + 48)
#define __devhost_method_pm_cpuhp_action (__ACTV_HIGHTABLE_START + 49)
#define __devhost_method_pm_rsvd_3 (__ACTV_HIGHTABLE_START + 50)
#define __devhost_method_pm_rsvd_2 (__ACTV_HIGHTABLE_START + 51)
#define __devhost_method_pm_rsvd_1 (__ACTV_HIGHTABLE_START + 52)
#define __devhost_method_procfs_read (__ACTV_HIGHTABLE_START + 53)
#define __devhost_method_procfs_write (__ACTV_HIGHTABLE_START + 54)
#define __devhost_method_procfs_rsvd_2 (__ACTV_HIGHTABLE_START + 55)
#define __devhost_method_procfs_rsvd_1 (__ACTV_HIGHTABLE_START + 56)
#define __devhost_method_sysfs_read (__ACTV_HIGHTABLE_START + 57)
#define __devhost_method_sysfs_write (__ACTV_HIGHTABLE_START + 58)
#define __devhost_method_sysfs_poll (__ACTV_HIGHTABLE_START + 59)
#define __devhost_method_sysfs_rsvd_1 (__ACTV_HIGHTABLE_START + 60)
#define __devhost_method_clock_settime (__ACTV_HIGHTABLE_START + 61)
#define __devhost_method_clock_gettime (__ACTV_HIGHTABLE_START + 62)
#define __devhost_method_clock_getres (__ACTV_HIGHTABLE_START + 63)
#define __devhost_method_clock_adjtime (__ACTV_HIGHTABLE_START + 64)
#define __devhost_method_clock_rsvd_4 (__ACTV_HIGHTABLE_START + 65)
#define __devhost_method_clock_rsvd_3 (__ACTV_HIGHTABLE_START + 66)
#define __devhost_method_clock_rsvd_2 (__ACTV_HIGHTABLE_START + 67)
#define __devhost_method_clock_rsvd_1 (__ACTV_HIGHTABLE_START + 68)
#define __devhost_method_transfs_mounted (__ACTV_HIGHTABLE_START + 69)
#define __devhost_method_transfs_unmounted (__ACTV_HIGHTABLE_START + 70)
#define __devhost_method_transfs_drop_caches (__ACTV_HIGHTABLE_START + 71)
#define __devhost_method_transfs_mkdir (__ACTV_HIGHTABLE_START + 72)
#define __devhost_method_transfs_rmdir (__ACTV_HIGHTABLE_START + 73)
#define __devhost_method_transfs_create (__ACTV_HIGHTABLE_START + 74)
#define __devhost_method_transfs_unlink (__ACTV_HIGHTABLE_START + 75)
#define __devhost_method_transfs_mknod (__ACTV_HIGHTABLE_START + 76)
#define __devhost_method_transfs_link (__ACTV_HIGHTABLE_START + 77)
#define __devhost_method_transfs_symlink (__ACTV_HIGHTABLE_START + 78)
#define __devhost_method_transfs_statfs (__ACTV_HIGHTABLE_START + 79)
#define __devhost_method_transfs_rename (__ACTV_HIGHTABLE_START + 80)
#define __devhost_method_transfs_lookup (__ACTV_HIGHTABLE_START + 81)
#define __devhost_method_transfs_setattr (__ACTV_HIGHTABLE_START + 82)
#define __devhost_method_transfs_readlink (__ACTV_HIGHTABLE_START + 83)
#define __devhost_method_transfs_getattr (__ACTV_HIGHTABLE_START + 84)
#define __devhost_method_transfs_listxattr (__ACTV_HIGHTABLE_START + 85)
#define __devhost_method_transfs_getxattr (__ACTV_HIGHTABLE_START + 86)
#define __devhost_method_transfs_setxattr (__ACTV_HIGHTABLE_START + 87)
#define __devhost_method_transfs_tmpfile (__ACTV_HIGHTABLE_START + 88)
#define __devhost_method_transfs_kill_dentry (__ACTV_HIGHTABLE_START + 89)
#define __devhost_method_transfs_node_put (__ACTV_HIGHTABLE_START + 90)
#define __devhost_method_transfs_sync (__ACTV_HIGHTABLE_START + 91)
#define __devhost_method_transfs_write (__ACTV_HIGHTABLE_START + 92)
#define __devhost_method_transfs_fsync (__ACTV_HIGHTABLE_START + 93)
#define __devhost_method_transfs_readdir (__ACTV_HIGHTABLE_START + 94)
#define __devhost_method_transfs_open (__ACTV_HIGHTABLE_START + 95)
#define __devhost_method_transfs_fallocate (__ACTV_HIGHTABLE_START + 96)
#define __devhost_method_transfs_close (__ACTV_HIGHTABLE_START + 97)
#define __devhost_method_transfs_ioctl (__ACTV_HIGHTABLE_START + 98)
#define __devhost_method_transfs_direct_IO (__ACTV_HIGHTABLE_START + 99)
#define __devhost_method_transfs_update_opts (__ACTV_HIGHTABLE_START + 100)
#define __devhost_method_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + 101)
#define __devhost_method_MAX_COMPAT ((__ACTV_HIGHTABLE_START + 101) * 2)
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_core_load_driver) < 512,
                drvcall_devhost_core_load_driver_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_core_create_device) < 512,
                drvcall_devhost_core_create_device_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_core_unload_driver) < 512,
                drvcall_devhost_core_unload_driver_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_core_bind_device) < 512,
                drvcall_devhost_core_bind_device_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_core_entropy_read) < 512,
                drvcall_devhost_core_entropy_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_rpc_export) < 512,
                drvcall_devhost_rpc_export_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_rpc_invoke) < 512,
                drvcall_devhost_rpc_invoke_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_open) < 512,
                drvcall_devhost_fops_open_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_close) < 512,
                drvcall_devhost_fops_close_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_read) < 512,
                drvcall_devhost_fops_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_write) < 512,
                drvcall_devhost_fops_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_ioctl) < 512,
                drvcall_devhost_fops_ioctl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_llseek) < 512,
                drvcall_devhost_fops_llseek_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_mmap) < 512,
                drvcall_devhost_fops_mmap_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_munmap) < 512,
                drvcall_devhost_fops_munmap_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_sysfs_read) < 512,
                drvcall_devhost_fops_sysfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_sysfs_write) < 512,
                drvcall_devhost_fops_sysfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_epoll_ctl) < 512,
                drvcall_devhost_fops_epoll_ctl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_epoll_close) < 512,
                drvcall_devhost_fops_epoll_close_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_epoll_et) < 512,
                drvcall_devhost_fops_epoll_et_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_fops_epoll_reinit_add) < 512,
                drvcall_devhost_fops_epoll_reinit_add_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_block_check_feature) < 512,
                drvcall_devhost_block_check_feature_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_block_run_queue) < 512,
                drvcall_devhost_block_run_queue_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_block_direct_access) < 512,
                drvcall_devhost_block_direct_access_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_block_register_bio_notify) < 512,
                drvcall_devhost_block_register_bio_notify_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_net_send) < 512,
                drvcall_devhost_net_send_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_net_ioctl) < 512,
                drvcall_devhost_net_ioctl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_net_status) < 512,
                drvcall_devhost_net_status_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_net_prepare) < 512,
                drvcall_devhost_net_prepare_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_net_init) < 512,
                drvcall_devhost_net_init_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_net_netlink_recv) < 512,
                drvcall_devhost_net_netlink_recv_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_pm_action) < 512,
                drvcall_devhost_pm_action_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_pm_prepare) < 512,
                drvcall_devhost_pm_prepare_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_pm_power_off) < 512,
                drvcall_devhost_pm_power_off_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_pm_reboot) < 512,
                drvcall_devhost_pm_reboot_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_pm_cpuhp_action) < 512,
                drvcall_devhost_pm_cpuhp_action_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_procfs_read) < 512,
                drvcall_devhost_procfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_procfs_write) < 512,
                drvcall_devhost_procfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_sysfs_read) < 512,
                drvcall_devhost_sysfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_sysfs_write) < 512,
                drvcall_devhost_sysfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_sysfs_poll) < 512,
                drvcall_devhost_sysfs_poll_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_clock_settime) < 512,
                drvcall_devhost_clock_settime_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_clock_gettime) < 512,
                drvcall_devhost_clock_gettime_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_clock_getres) < 512,
                drvcall_devhost_clock_getres_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_clock_adjtime) < 512,
                drvcall_devhost_clock_adjtime_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_mounted) < 512,
                drvcall_devhost_transfs_mounted_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_unmounted) < 512,
                drvcall_devhost_transfs_unmounted_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_drop_caches) < 512,
                drvcall_devhost_transfs_drop_caches_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_mkdir) < 512,
                drvcall_devhost_transfs_mkdir_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_rmdir) < 512,
                drvcall_devhost_transfs_rmdir_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_create) < 512,
                drvcall_devhost_transfs_create_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_unlink) < 512,
                drvcall_devhost_transfs_unlink_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_mknod) < 512,
                drvcall_devhost_transfs_mknod_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_link) < 512,
                drvcall_devhost_transfs_link_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_symlink) < 512,
                drvcall_devhost_transfs_symlink_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_statfs) < 512,
                drvcall_devhost_transfs_statfs_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_rename) < 512,
                drvcall_devhost_transfs_rename_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_lookup) < 512,
                drvcall_devhost_transfs_lookup_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_setattr) < 512,
                drvcall_devhost_transfs_setattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_readlink) < 512,
                drvcall_devhost_transfs_readlink_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_getattr) < 512,
                drvcall_devhost_transfs_getattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_listxattr) < 512,
                drvcall_devhost_transfs_listxattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_getxattr) < 512,
                drvcall_devhost_transfs_getxattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_setxattr) < 512,
                drvcall_devhost_transfs_setxattr_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_tmpfile) < 512,
                drvcall_devhost_transfs_tmpfile_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_kill_dentry) < 512,
                drvcall_devhost_transfs_kill_dentry_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_node_put) < 512,
                drvcall_devhost_transfs_node_put_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_sync) < 512,
                drvcall_devhost_transfs_sync_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_write) < 512,
                drvcall_devhost_transfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_fsync) < 512,
                drvcall_devhost_transfs_fsync_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_readdir) < 512,
                drvcall_devhost_transfs_readdir_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_open) < 512,
                drvcall_devhost_transfs_open_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_fallocate) < 512,
                drvcall_devhost_transfs_fallocate_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_close) < 512,
                drvcall_devhost_transfs_close_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_ioctl) < 512,
                drvcall_devhost_transfs_ioctl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_direct_IO) < 512,
                drvcall_devhost_transfs_direct_IO_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devhost_transfs_update_opts) < 512,
                drvcall_devhost_transfs_update_opts_too_many_actvret_data);
raw_static_assert(sizeof(union __actvret_drvcall_devhost) < 512,
        drvcall_devhost_too_many_actvret_data);
extern int __actvcall_drvcall_devhost_core_load_driver(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, struct hm_actv_buf args, unsigned long long mpool_id, unsigned long size);


extern int __actvcapcall_drvcall_devhost_core_load_driver(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, struct hm_actv_buf args, unsigned long long mpool_id, unsigned long size);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_core_load_driver(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf name, struct hm_actv_buf args, unsigned long long mpool_id, unsigned long size)
{
	const unsigned long __callno = __devhost_method_core_load_driver;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_core_load_driver(rpc_info, NULL, name, args, mpool_id, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_core_load_driver(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf name, struct hm_actv_buf args, unsigned long long mpool_id, unsigned long size)
{
	const unsigned long __callno = __devhost_method_core_load_driver;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_core_load_driver(__rref, rpc_info, NULL, name, args, mpool_id, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_core_load_driver(struct hm_actv_buf name, struct hm_actv_buf args, unsigned long long mpool_id, unsigned long size)
{
	return actvxactcall_drvcall_devhost_core_load_driver(false, false, name, args, mpool_id, size);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_core_load_driver(rref_t __rref, struct hm_actv_buf name, struct hm_actv_buf args, unsigned long long mpool_id, unsigned long size)
{
	return actvxactcapcall_drvcall_devhost_core_load_driver(false, false, __rref, name, args, mpool_id, size);
}

extern int __actvcall_drvcall_devhost_core_create_device(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, struct hm_actv_buf devname, struct hm_actv_buf dev_compat, int parent_devid, unsigned int resource_count);


extern int __actvcapcall_drvcall_devhost_core_create_device(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, struct hm_actv_buf devname, struct hm_actv_buf dev_compat, int parent_devid, unsigned int resource_count);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_core_create_device(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf devname, struct hm_actv_buf dev_compat, int parent_devid, unsigned int resource_count, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_drvcall_devhost_core_create_device *__ret)
{
	const unsigned long __callno = __devhost_method_core_create_device;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_core_create_device(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, devname, dev_compat, parent_devid, resource_count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_core_create_device(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf devname, struct hm_actv_buf dev_compat, int parent_devid, unsigned int resource_count, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_drvcall_devhost_core_create_device *__ret)
{
	const unsigned long __callno = __devhost_method_core_create_device;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_core_create_device(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, devname, dev_compat, parent_devid, resource_count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_core_create_device(struct hm_actv_buf devname, struct hm_actv_buf dev_compat, int parent_devid, unsigned int resource_count, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_drvcall_devhost_core_create_device *__ret)
{
	return actvxactcall_drvcall_devhost_core_create_device(false, false, devname, dev_compat, parent_devid, resource_count, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_core_create_device(rref_t __rref, struct hm_actv_buf devname, struct hm_actv_buf dev_compat, int parent_devid, unsigned int resource_count, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_drvcall_devhost_core_create_device *__ret)
{
	return actvxactcapcall_drvcall_devhost_core_create_device(false, false, __rref, devname, dev_compat, parent_devid, resource_count, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_drvcall_devhost_core_unload_driver(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf drvname);


extern int __actvcapcall_drvcall_devhost_core_unload_driver(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf drvname);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_core_unload_driver(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf drvname)
{
	const unsigned long __callno = __devhost_method_core_unload_driver;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_core_unload_driver(rpc_info, NULL, drvname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_core_unload_driver(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf drvname)
{
	const unsigned long __callno = __devhost_method_core_unload_driver;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_core_unload_driver(__rref, rpc_info, NULL, drvname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_core_unload_driver(struct hm_actv_buf drvname)
{
	return actvxactcall_drvcall_devhost_core_unload_driver(false, false, drvname);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_core_unload_driver(rref_t __rref, struct hm_actv_buf drvname)
{
	return actvxactcapcall_drvcall_devhost_core_unload_driver(false, false, __rref, drvname);
}

extern int __actvcall_drvcall_devhost_core_bind_device(unsigned long long __rpc_info, void *__buf, int devid, struct hm_actv_buf dev_compat);


extern int __actvcapcall_drvcall_devhost_core_bind_device(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid, struct hm_actv_buf dev_compat);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_core_bind_device(bool is_xact_fwd, bool is_xact_allow_refwd, int devid, struct hm_actv_buf dev_compat)
{
	const unsigned long __callno = __devhost_method_core_bind_device;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_core_bind_device(rpc_info, NULL, devid, dev_compat);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_core_bind_device(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int devid, struct hm_actv_buf dev_compat)
{
	const unsigned long __callno = __devhost_method_core_bind_device;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_core_bind_device(__rref, rpc_info, NULL, devid, dev_compat);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_core_bind_device(int devid, struct hm_actv_buf dev_compat)
{
	return actvxactcall_drvcall_devhost_core_bind_device(false, false, devid, dev_compat);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_core_bind_device(rref_t __rref, int devid, struct hm_actv_buf dev_compat)
{
	return actvxactcapcall_drvcall_devhost_core_bind_device(false, false, __rref, devid, dev_compat);
}

extern int __actvcall_drvcall_devhost_core_entropy_read(unsigned long long __rpc_info, void *__buf, unsigned int num);


extern int __actvcapcall_drvcall_devhost_core_entropy_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int num);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_core_entropy_read(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int num, struct __actvret_drvcall_devhost_core_entropy_read *__ret)
{
	const unsigned long __callno = __devhost_method_core_entropy_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_core_entropy_read(rpc_info, __ret, num);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_core_entropy_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int num, struct __actvret_drvcall_devhost_core_entropy_read *__ret)
{
	const unsigned long __callno = __devhost_method_core_entropy_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_core_entropy_read(__rref, rpc_info, __ret, num);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_core_entropy_read(unsigned int num, struct __actvret_drvcall_devhost_core_entropy_read *__ret)
{
	return actvxactcall_drvcall_devhost_core_entropy_read(false, false, num, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_core_entropy_read(rref_t __rref, unsigned int num, struct __actvret_drvcall_devhost_core_entropy_read *__ret)
{
	return actvxactcapcall_drvcall_devhost_core_entropy_read(false, false, __rref, num, __ret);
}

extern int __actvcall_drvcall_devhost_rpc_export(unsigned long long __rpc_info, void *__buf, int devid, unsigned int cnode_idx);


extern int __actvcapcall_drvcall_devhost_rpc_export(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_rpc_export(bool is_xact_fwd, bool is_xact_allow_refwd, int devid, unsigned int cnode_idx, struct __actvret_drvcall_devhost_rpc_export *__ret)
{
	const unsigned long __callno = __devhost_method_rpc_export;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_rpc_export(rpc_info, __ret, devid, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_rpc_export(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int devid, unsigned int cnode_idx, struct __actvret_drvcall_devhost_rpc_export *__ret)
{
	const unsigned long __callno = __devhost_method_rpc_export;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_rpc_export(__rref, rpc_info, __ret, devid, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_rpc_export(int devid, unsigned int cnode_idx, struct __actvret_drvcall_devhost_rpc_export *__ret)
{
	return actvxactcall_drvcall_devhost_rpc_export(false, false, devid, cnode_idx, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_rpc_export(rref_t __rref, int devid, unsigned int cnode_idx, struct __actvret_drvcall_devhost_rpc_export *__ret)
{
	return actvxactcapcall_drvcall_devhost_rpc_export(false, false, __rref, devid, cnode_idx, __ret);
}

extern int __actvcall_drvcall_devhost_rpc_invoke(unsigned long long __rpc_info, void *__buf, int devid, unsigned long req_ubuf, unsigned long req_size, unsigned long resp_ubuf, unsigned long resp_size);


extern int __actvcapcall_drvcall_devhost_rpc_invoke(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid, unsigned long req_ubuf, unsigned long req_size, unsigned long resp_ubuf, unsigned long resp_size);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_rpc_invoke(bool is_xact_fwd, bool is_xact_allow_refwd, int devid, unsigned long req_ubuf, unsigned long req_size, unsigned long resp_ubuf, unsigned long resp_size, struct __actvret_drvcall_devhost_rpc_invoke *__ret)
{
	const unsigned long __callno = __devhost_method_rpc_invoke;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_rpc_invoke(rpc_info, __ret, devid, req_ubuf, req_size, resp_ubuf, resp_size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_rpc_invoke(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int devid, unsigned long req_ubuf, unsigned long req_size, unsigned long resp_ubuf, unsigned long resp_size, struct __actvret_drvcall_devhost_rpc_invoke *__ret)
{
	const unsigned long __callno = __devhost_method_rpc_invoke;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_rpc_invoke(__rref, rpc_info, __ret, devid, req_ubuf, req_size, resp_ubuf, resp_size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_rpc_invoke(int devid, unsigned long req_ubuf, unsigned long req_size, unsigned long resp_ubuf, unsigned long resp_size, struct __actvret_drvcall_devhost_rpc_invoke *__ret)
{
	return actvxactcall_drvcall_devhost_rpc_invoke(false, false, devid, req_ubuf, req_size, resp_ubuf, resp_size, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_rpc_invoke(rref_t __rref, int devid, unsigned long req_ubuf, unsigned long req_size, unsigned long resp_ubuf, unsigned long resp_size, struct __actvret_drvcall_devhost_rpc_invoke *__ret)
{
	return actvxactcapcall_drvcall_devhost_rpc_invoke(false, false, __rref, devid, req_ubuf, req_size, resp_ubuf, resp_size, __ret);
}

extern int __actvcall_drvcall_devhost_fops_open(unsigned long long __rpc_info, void *__buf, int devid, rref_t tgt_rref, unsigned int vfs_flags);


extern int __actvcapcall_drvcall_devhost_fops_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid, rref_t tgt_rref, unsigned int vfs_flags);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_open(bool is_xact_fwd, bool is_xact_allow_refwd, int devid, rref_t tgt_rref, unsigned int vfs_flags, struct __actvret_drvcall_devhost_fops_open *__ret)
{
	const unsigned long __callno = __devhost_method_fops_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_open(rpc_info, __ret, devid, tgt_rref, vfs_flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_open(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int devid, rref_t tgt_rref, unsigned int vfs_flags, struct __actvret_drvcall_devhost_fops_open *__ret)
{
	const unsigned long __callno = __devhost_method_fops_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_open(__rref, rpc_info, __ret, devid, tgt_rref, vfs_flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_open(int devid, rref_t tgt_rref, unsigned int vfs_flags, struct __actvret_drvcall_devhost_fops_open *__ret)
{
	return actvxactcall_drvcall_devhost_fops_open(false, false, devid, tgt_rref, vfs_flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_open(rref_t __rref, int devid, rref_t tgt_rref, unsigned int vfs_flags, struct __actvret_drvcall_devhost_fops_open *__ret)
{
	return actvxactcapcall_drvcall_devhost_fops_open(false, false, __rref, devid, tgt_rref, vfs_flags, __ret);
}

extern int __actvcall_drvcall_devhost_fops_close(unsigned long long __rpc_info, void *__buf, int padding, unsigned long long file_id);


extern int __actvcapcall_drvcall_devhost_fops_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, int padding, unsigned long long file_id);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_close(bool is_xact_fwd, bool is_xact_allow_refwd, int padding, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_fops_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_close(rpc_info, NULL, padding, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_close(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int padding, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_fops_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_close(__rref, rpc_info, NULL, padding, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_close(int padding, unsigned long long file_id)
{
	return actvxactcall_drvcall_devhost_fops_close(false, false, padding, file_id);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_close(rref_t __rref, int padding, unsigned long long file_id)
{
	return actvxactcapcall_drvcall_devhost_fops_close(false, false, __rref, padding, file_id);
}

extern int __actvcall_drvcall_devhost_fops_read(unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned long long filep, unsigned long long offset, unsigned long count);


extern int __actvcapcall_drvcall_devhost_fops_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned long long filep, unsigned long long offset, unsigned long count);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_read(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long buf, unsigned long long filep, unsigned long long offset, unsigned long count, struct __actvret_drvcall_devhost_fops_read *__ret)
{
	const unsigned long __callno = __devhost_method_fops_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_read(rpc_info, __ret, buf, filep, offset, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long buf, unsigned long long filep, unsigned long long offset, unsigned long count, struct __actvret_drvcall_devhost_fops_read *__ret)
{
	const unsigned long __callno = __devhost_method_fops_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_read(__rref, rpc_info, __ret, buf, filep, offset, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_read(unsigned long buf, unsigned long long filep, unsigned long long offset, unsigned long count, struct __actvret_drvcall_devhost_fops_read *__ret)
{
	return actvxactcall_drvcall_devhost_fops_read(false, false, buf, filep, offset, count, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_read(rref_t __rref, unsigned long buf, unsigned long long filep, unsigned long long offset, unsigned long count, struct __actvret_drvcall_devhost_fops_read *__ret)
{
	return actvxactcapcall_drvcall_devhost_fops_read(false, false, __rref, buf, filep, offset, count, __ret);
}

extern int __actvcall_drvcall_devhost_fops_write(unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned long long file_id, unsigned long long offset, unsigned long count);


extern int __actvcapcall_drvcall_devhost_fops_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned long long file_id, unsigned long long offset, unsigned long count);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_write(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long buf, unsigned long long file_id, unsigned long long offset, unsigned long count, struct __actvret_drvcall_devhost_fops_write *__ret)
{
	const unsigned long __callno = __devhost_method_fops_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_write(rpc_info, __ret, buf, file_id, offset, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long buf, unsigned long long file_id, unsigned long long offset, unsigned long count, struct __actvret_drvcall_devhost_fops_write *__ret)
{
	const unsigned long __callno = __devhost_method_fops_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_write(__rref, rpc_info, __ret, buf, file_id, offset, count);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_write(unsigned long buf, unsigned long long file_id, unsigned long long offset, unsigned long count, struct __actvret_drvcall_devhost_fops_write *__ret)
{
	return actvxactcall_drvcall_devhost_fops_write(false, false, buf, file_id, offset, count, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_write(rref_t __rref, unsigned long buf, unsigned long long file_id, unsigned long long offset, unsigned long count, struct __actvret_drvcall_devhost_fops_write *__ret)
{
	return actvxactcapcall_drvcall_devhost_fops_write(false, false, __rref, buf, file_id, offset, count, __ret);
}

extern int __actvcall_drvcall_devhost_fops_ioctl(unsigned long long __rpc_info, void *__buf, int request, unsigned long long file_id, unsigned long arg);


extern int __actvcapcall_drvcall_devhost_fops_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int request, unsigned long long file_id, unsigned long arg);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, int request, unsigned long long file_id, unsigned long arg)
{
	const unsigned long __callno = __devhost_method_fops_ioctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_ioctl(rpc_info, NULL, request, file_id, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int request, unsigned long long file_id, unsigned long arg)
{
	const unsigned long __callno = __devhost_method_fops_ioctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_ioctl(__rref, rpc_info, NULL, request, file_id, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_ioctl(int request, unsigned long long file_id, unsigned long arg)
{
	return actvxactcall_drvcall_devhost_fops_ioctl(false, false, request, file_id, arg);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_ioctl(rref_t __rref, int request, unsigned long long file_id, unsigned long arg)
{
	return actvxactcapcall_drvcall_devhost_fops_ioctl(false, false, __rref, request, file_id, arg);
}

extern int __actvcall_drvcall_devhost_fops_llseek(unsigned long long __rpc_info, void *__buf, int whence, unsigned long long file_id, long long offset);


extern int __actvcapcall_drvcall_devhost_fops_llseek(rref_t __rref, unsigned long long __rpc_info, void *__buf, int whence, unsigned long long file_id, long long offset);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_llseek(bool is_xact_fwd, bool is_xact_allow_refwd, int whence, unsigned long long file_id, long long offset, struct __actvret_drvcall_devhost_fops_llseek *__ret)
{
	const unsigned long __callno = __devhost_method_fops_llseek;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_llseek(rpc_info, __ret, whence, file_id, offset);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_llseek(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int whence, unsigned long long file_id, long long offset, struct __actvret_drvcall_devhost_fops_llseek *__ret)
{
	const unsigned long __callno = __devhost_method_fops_llseek;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(long long), __arch_actv_rpc_stksz_alignment(long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_llseek(__rref, rpc_info, __ret, whence, file_id, offset);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_llseek(int whence, unsigned long long file_id, long long offset, struct __actvret_drvcall_devhost_fops_llseek *__ret)
{
	return actvxactcall_drvcall_devhost_fops_llseek(false, false, whence, file_id, offset, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_llseek(rref_t __rref, int whence, unsigned long long file_id, long long offset, struct __actvret_drvcall_devhost_fops_llseek *__ret)
{
	return actvxactcapcall_drvcall_devhost_fops_llseek(false, false, __rref, whence, file_id, offset, __ret);
}

extern int __actvcall_drvcall_devhost_fops_mmap(unsigned long long __rpc_info, void *__buf, unsigned long addr, unsigned long long file_id, unsigned long long vspace_rref, unsigned long length, unsigned long prot, unsigned int flags, unsigned long offset);


extern int __actvcapcall_drvcall_devhost_fops_mmap(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long addr, unsigned long long file_id, unsigned long long vspace_rref, unsigned long length, unsigned long prot, unsigned int flags, unsigned long offset);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_mmap(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long addr, unsigned long long file_id, unsigned long long vspace_rref, unsigned long length, unsigned long prot, unsigned int flags, unsigned long offset, struct __actvret_drvcall_devhost_fops_mmap *__ret)
{
	const unsigned long __callno = __devhost_method_fops_mmap;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_mmap(rpc_info, __ret, addr, file_id, vspace_rref, length, prot, flags, offset);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_mmap(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long addr, unsigned long long file_id, unsigned long long vspace_rref, unsigned long length, unsigned long prot, unsigned int flags, unsigned long offset, struct __actvret_drvcall_devhost_fops_mmap *__ret)
{
	const unsigned long __callno = __devhost_method_fops_mmap;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_mmap(__rref, rpc_info, __ret, addr, file_id, vspace_rref, length, prot, flags, offset);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_mmap(unsigned long addr, unsigned long long file_id, unsigned long long vspace_rref, unsigned long length, unsigned long prot, unsigned int flags, unsigned long offset, struct __actvret_drvcall_devhost_fops_mmap *__ret)
{
	return actvxactcall_drvcall_devhost_fops_mmap(false, false, addr, file_id, vspace_rref, length, prot, flags, offset, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_mmap(rref_t __rref, unsigned long addr, unsigned long long file_id, unsigned long long vspace_rref, unsigned long length, unsigned long prot, unsigned int flags, unsigned long offset, struct __actvret_drvcall_devhost_fops_mmap *__ret)
{
	return actvxactcapcall_drvcall_devhost_fops_mmap(false, false, __rref, addr, file_id, vspace_rref, length, prot, flags, offset, __ret);
}

extern int __actvcall_drvcall_devhost_fops_munmap(unsigned long long __rpc_info, void *__buf, unsigned int key, unsigned long len);


extern int __actvcapcall_drvcall_devhost_fops_munmap(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int key, unsigned long len);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_munmap(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int key, unsigned long len)
{
	const unsigned long __callno = __devhost_method_fops_munmap;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_munmap(rpc_info, NULL, key, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_munmap(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int key, unsigned long len)
{
	const unsigned long __callno = __devhost_method_fops_munmap;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_munmap(__rref, rpc_info, NULL, key, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_munmap(unsigned int key, unsigned long len)
{
	return actvxactcall_drvcall_devhost_fops_munmap(false, false, key, len);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_munmap(rref_t __rref, unsigned int key, unsigned long len)
{
	return actvxactcapcall_drvcall_devhost_fops_munmap(false, false, __rref, key, len);
}

extern int __actvcall_drvcall_devhost_fops_sysfs_read(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devhost_fops_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devhost_method_fops_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_sysfs_read(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devhost_method_fops_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_sysfs_read(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_sysfs_read(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_drvcall_devhost_fops_sysfs_read(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_sysfs_read(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_drvcall_devhost_fops_sysfs_read(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_drvcall_devhost_fops_sysfs_write(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devhost_fops_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devhost_method_fops_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_sysfs_write(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devhost_method_fops_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_sysfs_write(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_sysfs_write(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_drvcall_devhost_fops_sysfs_write(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_sysfs_write(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_drvcall_devhost_fops_sysfs_write(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_drvcall_devhost_fops_epoll_ctl(unsigned long long __rpc_info, void *__buf, unsigned long long file_id, int fd, int op, const void *reg_info);


extern int __actvcapcall_drvcall_devhost_fops_epoll_ctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long file_id, int fd, int op, const void *reg_info);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_epoll_ctl(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long long file_id, int fd, int op, const void *reg_info)
{
	const unsigned long __callno = __devhost_method_fops_epoll_ctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_epoll_ctl(rpc_info, NULL, file_id, fd, op, reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_epoll_ctl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long long file_id, int fd, int op, const void *reg_info)
{
	const unsigned long __callno = __devhost_method_fops_epoll_ctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_epoll_ctl(__rref, rpc_info, NULL, file_id, fd, op, reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_epoll_ctl(unsigned long long file_id, int fd, int op, const void *reg_info)
{
	return actvxactcall_drvcall_devhost_fops_epoll_ctl(false, false, file_id, fd, op, reg_info);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_epoll_ctl(rref_t __rref, unsigned long long file_id, int fd, int op, const void *reg_info)
{
	return actvxactcapcall_drvcall_devhost_fops_epoll_ctl(false, false, __rref, file_id, fd, op, reg_info);
}

extern int __actvcall_drvcall_devhost_fops_epoll_close(unsigned long long __rpc_info, void *__buf, unsigned int app_cnode_idx, unsigned long long file_id, int fd);


extern int __actvcapcall_drvcall_devhost_fops_epoll_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int app_cnode_idx, unsigned long long file_id, int fd);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_epoll_close(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int app_cnode_idx, unsigned long long file_id, int fd)
{
	const unsigned long __callno = __devhost_method_fops_epoll_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_epoll_close(rpc_info, NULL, app_cnode_idx, file_id, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_epoll_close(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int app_cnode_idx, unsigned long long file_id, int fd)
{
	const unsigned long __callno = __devhost_method_fops_epoll_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_epoll_close(__rref, rpc_info, NULL, app_cnode_idx, file_id, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_epoll_close(unsigned int app_cnode_idx, unsigned long long file_id, int fd)
{
	return actvxactcall_drvcall_devhost_fops_epoll_close(false, false, app_cnode_idx, file_id, fd);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_epoll_close(rref_t __rref, unsigned int app_cnode_idx, unsigned long long file_id, int fd)
{
	return actvxactcapcall_drvcall_devhost_fops_epoll_close(false, false, __rref, app_cnode_idx, file_id, fd);
}

extern int __actvcall_drvcall_devhost_fops_epoll_et(unsigned long long __rpc_info, void *__buf, unsigned long long file_id, const void *pre_info);


extern int __actvcapcall_drvcall_devhost_fops_epoll_et(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long file_id, const void *pre_info);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_epoll_et(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long long file_id, const void *pre_info, struct __actvret_drvcall_devhost_fops_epoll_et *__ret)
{
	const unsigned long __callno = __devhost_method_fops_epoll_et;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_epoll_et(rpc_info, __ret, file_id, pre_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_epoll_et(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long long file_id, const void *pre_info, struct __actvret_drvcall_devhost_fops_epoll_et *__ret)
{
	const unsigned long __callno = __devhost_method_fops_epoll_et;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_epoll_et(__rref, rpc_info, __ret, file_id, pre_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_epoll_et(unsigned long long file_id, const void *pre_info, struct __actvret_drvcall_devhost_fops_epoll_et *__ret)
{
	return actvxactcall_drvcall_devhost_fops_epoll_et(false, false, file_id, pre_info, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_epoll_et(rref_t __rref, unsigned long long file_id, const void *pre_info, struct __actvret_drvcall_devhost_fops_epoll_et *__ret)
{
	return actvxactcapcall_drvcall_devhost_fops_epoll_et(false, false, __rref, file_id, pre_info, __ret);
}

extern int __actvcall_drvcall_devhost_fops_epoll_reinit_add(unsigned long long __rpc_info, void *__buf, unsigned long long file_id, int fd, const void *pre_reg_info, const void *reg_info);


extern int __actvcapcall_drvcall_devhost_fops_epoll_reinit_add(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long file_id, int fd, const void *pre_reg_info, const void *reg_info);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_fops_epoll_reinit_add(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long long file_id, int fd, const void *pre_reg_info, const void *reg_info)
{
	const unsigned long __callno = __devhost_method_fops_epoll_reinit_add;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_fops_epoll_reinit_add(rpc_info, NULL, file_id, fd, pre_reg_info, reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_fops_epoll_reinit_add(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long long file_id, int fd, const void *pre_reg_info, const void *reg_info)
{
	const unsigned long __callno = __devhost_method_fops_epoll_reinit_add;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_fops_epoll_reinit_add(__rref, rpc_info, NULL, file_id, fd, pre_reg_info, reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_fops_epoll_reinit_add(unsigned long long file_id, int fd, const void *pre_reg_info, const void *reg_info)
{
	return actvxactcall_drvcall_devhost_fops_epoll_reinit_add(false, false, file_id, fd, pre_reg_info, reg_info);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_fops_epoll_reinit_add(rref_t __rref, unsigned long long file_id, int fd, const void *pre_reg_info, const void *reg_info)
{
	return actvxactcapcall_drvcall_devhost_fops_epoll_reinit_add(false, false, __rref, file_id, fd, pre_reg_info, reg_info);
}

extern int __actvcall_drvcall_devhost_block_check_feature(unsigned long long __rpc_info, void *__buf, int idx, unsigned long long file_id, unsigned long long features);


extern int __actvcapcall_drvcall_devhost_block_check_feature(rref_t __rref, unsigned long long __rpc_info, void *__buf, int idx, unsigned long long file_id, unsigned long long features);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_block_check_feature(bool is_xact_fwd, bool is_xact_allow_refwd, int idx, unsigned long long file_id, unsigned long long features, struct __actvret_drvcall_devhost_block_check_feature *__ret)
{
	const unsigned long __callno = __devhost_method_block_check_feature;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_block_check_feature(rpc_info, __ret, idx, file_id, features);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_block_check_feature(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int idx, unsigned long long file_id, unsigned long long features, struct __actvret_drvcall_devhost_block_check_feature *__ret)
{
	const unsigned long __callno = __devhost_method_block_check_feature;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_block_check_feature(__rref, rpc_info, __ret, idx, file_id, features);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_block_check_feature(int idx, unsigned long long file_id, unsigned long long features, struct __actvret_drvcall_devhost_block_check_feature *__ret)
{
	return actvxactcall_drvcall_devhost_block_check_feature(false, false, idx, file_id, features, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_block_check_feature(rref_t __rref, int idx, unsigned long long file_id, unsigned long long features, struct __actvret_drvcall_devhost_block_check_feature *__ret)
{
	return actvxactcapcall_drvcall_devhost_block_check_feature(false, false, __rref, idx, file_id, features, __ret);
}

extern int __actvcall_drvcall_devhost_block_run_queue(unsigned long long __rpc_info, void *__buf, unsigned long file_id, unsigned int flags, unsigned int idx);


extern int __actvcapcall_drvcall_devhost_block_run_queue(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long file_id, unsigned int flags, unsigned int idx);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_block_run_queue(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long file_id, unsigned int flags, unsigned int idx)
{
	const unsigned long __callno = __devhost_method_block_run_queue;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_block_run_queue(rpc_info, NULL, file_id, flags, idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_block_run_queue(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long file_id, unsigned int flags, unsigned int idx)
{
	const unsigned long __callno = __devhost_method_block_run_queue;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_block_run_queue(__rref, rpc_info, NULL, file_id, flags, idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_block_run_queue(unsigned long file_id, unsigned int flags, unsigned int idx)
{
	return actvxactcall_drvcall_devhost_block_run_queue(false, false, file_id, flags, idx);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_block_run_queue(rref_t __rref, unsigned long file_id, unsigned int flags, unsigned int idx)
{
	return actvxactcapcall_drvcall_devhost_block_run_queue(false, false, __rref, file_id, flags, idx);
}

extern int __actvcall_drvcall_devhost_block_direct_access(unsigned long long __rpc_info, void *__buf, unsigned long file_id, unsigned long offset, unsigned long size);


extern int __actvcapcall_drvcall_devhost_block_direct_access(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long file_id, unsigned long offset, unsigned long size);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_block_direct_access(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long file_id, unsigned long offset, unsigned long size, struct __actvret_drvcall_devhost_block_direct_access *__ret)
{
	const unsigned long __callno = __devhost_method_block_direct_access;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_block_direct_access(rpc_info, __ret, file_id, offset, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_block_direct_access(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long file_id, unsigned long offset, unsigned long size, struct __actvret_drvcall_devhost_block_direct_access *__ret)
{
	const unsigned long __callno = __devhost_method_block_direct_access;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_block_direct_access(__rref, rpc_info, __ret, file_id, offset, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_block_direct_access(unsigned long file_id, unsigned long offset, unsigned long size, struct __actvret_drvcall_devhost_block_direct_access *__ret)
{
	return actvxactcall_drvcall_devhost_block_direct_access(false, false, file_id, offset, size, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_block_direct_access(rref_t __rref, unsigned long file_id, unsigned long offset, unsigned long size, struct __actvret_drvcall_devhost_block_direct_access *__ret)
{
	return actvxactcapcall_drvcall_devhost_block_direct_access(false, false, __rref, file_id, offset, size, __ret);
}

extern int __actvcall_drvcall_devhost_block_register_bio_notify(unsigned long long __rpc_info, void *__buf, unsigned long file_id, uref_t uref, unsigned int method, size_t bd_shm_size);


extern int __actvcapcall_drvcall_devhost_block_register_bio_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long file_id, uref_t uref, unsigned int method, size_t bd_shm_size);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_block_register_bio_notify(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long file_id, uref_t uref, unsigned int method, size_t bd_shm_size, struct __actvret_drvcall_devhost_block_register_bio_notify *__ret)
{
	const unsigned long __callno = __devhost_method_block_register_bio_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_block_register_bio_notify(rpc_info, __ret, file_id, uref, method, bd_shm_size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_block_register_bio_notify(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long file_id, uref_t uref, unsigned int method, size_t bd_shm_size, struct __actvret_drvcall_devhost_block_register_bio_notify *__ret)
{
	const unsigned long __callno = __devhost_method_block_register_bio_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_block_register_bio_notify(__rref, rpc_info, __ret, file_id, uref, method, bd_shm_size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_block_register_bio_notify(unsigned long file_id, uref_t uref, unsigned int method, size_t bd_shm_size, struct __actvret_drvcall_devhost_block_register_bio_notify *__ret)
{
	return actvxactcall_drvcall_devhost_block_register_bio_notify(false, false, file_id, uref, method, bd_shm_size, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_block_register_bio_notify(rref_t __rref, unsigned long file_id, uref_t uref, unsigned int method, size_t bd_shm_size, struct __actvret_drvcall_devhost_block_register_bio_notify *__ret)
{
	return actvxactcapcall_drvcall_devhost_block_register_bio_notify(false, false, __rref, file_id, uref, method, bd_shm_size, __ret);
}

extern int __actvcall_drvcall_devhost_net_send(unsigned long long __rpc_info, void *__buf, int ifindex, unsigned int offset, unsigned int size, unsigned int payload_len, unsigned long flags);


extern int __actvcapcall_drvcall_devhost_net_send(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex, unsigned int offset, unsigned int size, unsigned int payload_len, unsigned long flags);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_net_send(bool is_xact_fwd, bool is_xact_allow_refwd, int ifindex, unsigned int offset, unsigned int size, unsigned int payload_len, unsigned long flags)
{
	const unsigned long __callno = __devhost_method_net_send;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_net_send(rpc_info, NULL, ifindex, offset, size, payload_len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_net_send(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int ifindex, unsigned int offset, unsigned int size, unsigned int payload_len, unsigned long flags)
{
	const unsigned long __callno = __devhost_method_net_send;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_net_send(__rref, rpc_info, NULL, ifindex, offset, size, payload_len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_net_send(int ifindex, unsigned int offset, unsigned int size, unsigned int payload_len, unsigned long flags)
{
	return actvxactcall_drvcall_devhost_net_send(false, false, ifindex, offset, size, payload_len, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_net_send(rref_t __rref, int ifindex, unsigned int offset, unsigned int size, unsigned int payload_len, unsigned long flags)
{
	return actvxactcapcall_drvcall_devhost_net_send(false, false, __rref, ifindex, offset, size, payload_len, flags);
}

extern int __actvcall_drvcall_devhost_net_ioctl(unsigned long long __rpc_info, void *__buf, int ifindex, int request, unsigned long args);


extern int __actvcapcall_drvcall_devhost_net_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex, int request, unsigned long args);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_net_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, int ifindex, int request, unsigned long args)
{
	const unsigned long __callno = __devhost_method_net_ioctl;
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
		__res = __actvcall_drvcall_devhost_net_ioctl(rpc_info, NULL, ifindex, request, args);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_net_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int ifindex, int request, unsigned long args)
{
	const unsigned long __callno = __devhost_method_net_ioctl;
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
		__res = __actvcapcall_drvcall_devhost_net_ioctl(__rref, rpc_info, NULL, ifindex, request, args);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_net_ioctl(int ifindex, int request, unsigned long args)
{
	return actvxactcall_drvcall_devhost_net_ioctl(false, false, ifindex, request, args);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_net_ioctl(rref_t __rref, int ifindex, int request, unsigned long args)
{
	return actvxactcapcall_drvcall_devhost_net_ioctl(false, false, __rref, ifindex, request, args);
}

extern int __actvcall_drvcall_devhost_net_status(unsigned long long __rpc_info, void *__buf, int ifindex);


extern int __actvcapcall_drvcall_devhost_net_status(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_net_status(bool is_xact_fwd, bool is_xact_allow_refwd, int ifindex, struct __actvret_drvcall_devhost_net_status *__ret)
{
	const unsigned long __callno = __devhost_method_net_status;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_net_status(rpc_info, __ret, ifindex);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_net_status(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int ifindex, struct __actvret_drvcall_devhost_net_status *__ret)
{
	const unsigned long __callno = __devhost_method_net_status;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_net_status(__rref, rpc_info, __ret, ifindex);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_net_status(int ifindex, struct __actvret_drvcall_devhost_net_status *__ret)
{
	return actvxactcall_drvcall_devhost_net_status(false, false, ifindex, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_net_status(rref_t __rref, int ifindex, struct __actvret_drvcall_devhost_net_status *__ret)
{
	return actvxactcapcall_drvcall_devhost_net_status(false, false, __rref, ifindex, __ret);
}

extern int __actvcall_drvcall_devhost_net_prepare(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devhost_net_prepare(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_net_prepare(bool is_xact_fwd, bool is_xact_allow_refwd, struct __actvret_drvcall_devhost_net_prepare *__ret)
{
	const unsigned long __callno = __devhost_method_net_prepare;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_net_prepare(rpc_info, __ret);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_net_prepare(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct __actvret_drvcall_devhost_net_prepare *__ret)
{
	const unsigned long __callno = __devhost_method_net_prepare;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_net_prepare(__rref, rpc_info, __ret);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_net_prepare(struct __actvret_drvcall_devhost_net_prepare *__ret)
{
	return actvxactcall_drvcall_devhost_net_prepare(false, false, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_net_prepare(rref_t __rref, struct __actvret_drvcall_devhost_net_prepare *__ret)
{
	return actvxactcapcall_drvcall_devhost_net_prepare(false, false, __rref, __ret);
}

extern int __actvcall_drvcall_devhost_net_init(unsigned long long __rpc_info, void *__buf, int ifindex, rref_t tgt_rref);


extern int __actvcapcall_drvcall_devhost_net_init(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex, rref_t tgt_rref);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_net_init(bool is_xact_fwd, bool is_xact_allow_refwd, int ifindex, rref_t tgt_rref)
{
	const unsigned long __callno = __devhost_method_net_init;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_net_init(rpc_info, NULL, ifindex, tgt_rref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_net_init(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int ifindex, rref_t tgt_rref)
{
	const unsigned long __callno = __devhost_method_net_init;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_net_init(__rref, rpc_info, NULL, ifindex, tgt_rref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_net_init(int ifindex, rref_t tgt_rref)
{
	return actvxactcall_drvcall_devhost_net_init(false, false, ifindex, tgt_rref);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_net_init(rref_t __rref, int ifindex, rref_t tgt_rref)
{
	return actvxactcapcall_drvcall_devhost_net_init(false, false, __rref, ifindex, tgt_rref);
}

extern int __actvcall_drvcall_devhost_net_netlink_recv(unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid);


extern int __actvcapcall_drvcall_devhost_net_netlink_recv(rref_t __rref, unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_net_netlink_recv(bool is_xact_fwd, bool is_xact_allow_refwd, int protocol, unsigned int src_portid, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devhost_method_net_netlink_recv;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_net_netlink_recv(rpc_info, ___void_buf, protocol, src_portid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_net_netlink_recv(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int protocol, unsigned int src_portid, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devhost_method_net_netlink_recv;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_net_netlink_recv(__rref, rpc_info, ___void_buf, protocol, src_portid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_net_netlink_recv(int protocol, unsigned int src_portid, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_drvcall_devhost_net_netlink_recv(false, false, protocol, src_portid, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_net_netlink_recv(rref_t __rref, int protocol, unsigned int src_portid, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_drvcall_devhost_net_netlink_recv(false, false, __rref, protocol, src_portid, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_drvcall_devhost_pm_action(unsigned long long __rpc_info, void *__buf, unsigned int action);


extern int __actvcapcall_drvcall_devhost_pm_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int action);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_pm_action(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int action)
{
	const unsigned long __callno = __devhost_method_pm_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_pm_action(rpc_info, NULL, action);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_pm_action(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int action)
{
	const unsigned long __callno = __devhost_method_pm_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_pm_action(__rref, rpc_info, NULL, action);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_pm_action(unsigned int action)
{
	return actvxactcall_drvcall_devhost_pm_action(false, false, action);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_pm_action(rref_t __rref, unsigned int action)
{
	return actvxactcapcall_drvcall_devhost_pm_action(false, false, __rref, action);
}

extern int __actvcall_drvcall_devhost_pm_prepare(unsigned long long __rpc_info, void *__buf, unsigned int type, struct reboot_cmd cmd);


extern int __actvcapcall_drvcall_devhost_pm_prepare(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int type, struct reboot_cmd cmd);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_pm_prepare(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int type, struct reboot_cmd cmd)
{
	const unsigned long __callno = __devhost_method_pm_prepare;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_pm_prepare(rpc_info, NULL, type, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_pm_prepare(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int type, struct reboot_cmd cmd)
{
	const unsigned long __callno = __devhost_method_pm_prepare;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_pm_prepare(__rref, rpc_info, NULL, type, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_pm_prepare(unsigned int type, struct reboot_cmd cmd)
{
	return actvxactcall_drvcall_devhost_pm_prepare(false, false, type, cmd);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_pm_prepare(rref_t __rref, unsigned int type, struct reboot_cmd cmd)
{
	return actvxactcapcall_drvcall_devhost_pm_prepare(false, false, __rref, type, cmd);
}

extern int __actvcall_drvcall_devhost_pm_power_off(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devhost_pm_power_off(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_pm_power_off(bool is_xact_fwd, bool is_xact_allow_refwd)
{
	const unsigned long __callno = __devhost_method_pm_power_off;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_pm_power_off(rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_pm_power_off(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref)
{
	const unsigned long __callno = __devhost_method_pm_power_off;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_pm_power_off(__rref, rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_pm_power_off(void)
{
	return actvxactcall_drvcall_devhost_pm_power_off(false, false);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_pm_power_off(rref_t __rref)
{
	return actvxactcapcall_drvcall_devhost_pm_power_off(false, false, __rref);
}

extern int __actvcall_drvcall_devhost_pm_reboot(unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd);


extern int __actvcapcall_drvcall_devhost_pm_reboot(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_pm_reboot(bool is_xact_fwd, bool is_xact_allow_refwd, struct reboot_cmd cmd)
{
	const unsigned long __callno = __devhost_method_pm_reboot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_pm_reboot(rpc_info, NULL, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_pm_reboot(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct reboot_cmd cmd)
{
	const unsigned long __callno = __devhost_method_pm_reboot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_pm_reboot(__rref, rpc_info, NULL, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_pm_reboot(struct reboot_cmd cmd)
{
	return actvxactcall_drvcall_devhost_pm_reboot(false, false, cmd);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_pm_reboot(rref_t __rref, struct reboot_cmd cmd)
{
	return actvxactcapcall_drvcall_devhost_pm_reboot(false, false, __rref, cmd);
}

extern int __actvcall_drvcall_devhost_pm_cpuhp_action(unsigned long long __rpc_info, void *__buf, unsigned int cpu, unsigned int action);


extern int __actvcapcall_drvcall_devhost_pm_cpuhp_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cpu, unsigned int action);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_pm_cpuhp_action(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cpu, unsigned int action)
{
	const unsigned long __callno = __devhost_method_pm_cpuhp_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_pm_cpuhp_action(rpc_info, NULL, cpu, action);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_pm_cpuhp_action(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cpu, unsigned int action)
{
	const unsigned long __callno = __devhost_method_pm_cpuhp_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_pm_cpuhp_action(__rref, rpc_info, NULL, cpu, action);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_pm_cpuhp_action(unsigned int cpu, unsigned int action)
{
	return actvxactcall_drvcall_devhost_pm_cpuhp_action(false, false, cpu, action);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_pm_cpuhp_action(rref_t __rref, unsigned int cpu, unsigned int action)
{
	return actvxactcapcall_drvcall_devhost_pm_cpuhp_action(false, false, __rref, cpu, action);
}

extern int __actvcall_drvcall_devhost_procfs_read(unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx);


extern int __actvcapcall_drvcall_devhost_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_procfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_procfs_read *__ret)
{
	const unsigned long __callno = __devhost_method_procfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_procfs_read(rpc_info, __ret, tagid, pos, ubuf, ctx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_procfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_procfs_read *__ret)
{
	const unsigned long __callno = __devhost_method_procfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_procfs_read(__rref, rpc_info, __ret, tagid, pos, ubuf, ctx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_procfs_read(unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_procfs_read *__ret)
{
	return actvxactcall_drvcall_devhost_procfs_read(false, false, tagid, pos, ubuf, ctx, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_procfs_read(rref_t __rref, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_procfs_read *__ret)
{
	return actvxactcapcall_drvcall_devhost_procfs_read(false, false, __rref, tagid, pos, ubuf, ctx, __ret);
}

extern int __actvcall_drvcall_devhost_procfs_write(unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx);


extern int __actvcapcall_drvcall_devhost_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_procfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_procfs_write *__ret)
{
	const unsigned long __callno = __devhost_method_procfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_procfs_write(rpc_info, __ret, tagid, pos, ubuf, ctx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_procfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_procfs_write *__ret)
{
	const unsigned long __callno = __devhost_method_procfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_procfs_write(__rref, rpc_info, __ret, tagid, pos, ubuf, ctx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_procfs_write(unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_procfs_write *__ret)
{
	return actvxactcall_drvcall_devhost_procfs_write(false, false, tagid, pos, ubuf, ctx, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_procfs_write(rref_t __rref, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_procfs_write *__ret)
{
	return actvxactcapcall_drvcall_devhost_procfs_write(false, false, __rref, tagid, pos, ubuf, ctx, __ret);
}

extern int __actvcall_drvcall_devhost_sysfs_read(unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx);


extern int __actvcapcall_drvcall_devhost_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_sysfs_read *__ret)
{
	const unsigned long __callno = __devhost_method_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_sysfs_read(rpc_info, __ret, tagid, pos, ubuf, ctx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_sysfs_read *__ret)
{
	const unsigned long __callno = __devhost_method_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_sysfs_read(__rref, rpc_info, __ret, tagid, pos, ubuf, ctx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_sysfs_read(unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_sysfs_read *__ret)
{
	return actvxactcall_drvcall_devhost_sysfs_read(false, false, tagid, pos, ubuf, ctx, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_sysfs_read(rref_t __rref, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_sysfs_read *__ret)
{
	return actvxactcapcall_drvcall_devhost_sysfs_read(false, false, __rref, tagid, pos, ubuf, ctx, __ret);
}

extern int __actvcall_drvcall_devhost_sysfs_write(unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx);


extern int __actvcapcall_drvcall_devhost_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_sysfs_write *__ret)
{
	const unsigned long __callno = __devhost_method_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_sysfs_write(rpc_info, __ret, tagid, pos, ubuf, ctx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_sysfs_write *__ret)
{
	const unsigned long __callno = __devhost_method_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_sysfs_write(__rref, rpc_info, __ret, tagid, pos, ubuf, ctx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_sysfs_write(unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_sysfs_write *__ret)
{
	return actvxactcall_drvcall_devhost_sysfs_write(false, false, tagid, pos, ubuf, ctx, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_sysfs_write(rref_t __rref, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx, struct __actvret_drvcall_devhost_sysfs_write *__ret)
{
	return actvxactcapcall_drvcall_devhost_sysfs_write(false, false, __rref, tagid, pos, ubuf, ctx, __ret);
}

extern int __actvcall_drvcall_devhost_sysfs_poll(unsigned long long __rpc_info, void *__buf, unsigned int tagid, uintptr_t ctx, bool pollable);


extern int __actvcapcall_drvcall_devhost_sysfs_poll(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, uintptr_t ctx, bool pollable);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_sysfs_poll(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int tagid, uintptr_t ctx, bool pollable)
{
	const unsigned long __callno = __devhost_method_sysfs_poll;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(bool), __arch_actv_rpc_stksz_alignment(bool));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_sysfs_poll(rpc_info, NULL, tagid, ctx, pollable);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_sysfs_poll(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int tagid, uintptr_t ctx, bool pollable)
{
	const unsigned long __callno = __devhost_method_sysfs_poll;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(bool), __arch_actv_rpc_stksz_alignment(bool));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_sysfs_poll(__rref, rpc_info, NULL, tagid, ctx, pollable);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_sysfs_poll(unsigned int tagid, uintptr_t ctx, bool pollable)
{
	return actvxactcall_drvcall_devhost_sysfs_poll(false, false, tagid, ctx, pollable);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_sysfs_poll(rref_t __rref, unsigned int tagid, uintptr_t ctx, bool pollable)
{
	return actvxactcapcall_drvcall_devhost_sysfs_poll(false, false, __rref, tagid, ctx, pollable);
}

extern int __actvcall_drvcall_devhost_clock_settime(unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id);


extern int __actvcapcall_drvcall_devhost_clock_settime(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_clock_settime(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long tp, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_clock_settime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_clock_settime(rpc_info, NULL, tp, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_clock_settime(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long tp, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_clock_settime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_clock_settime(__rref, rpc_info, NULL, tp, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_clock_settime(unsigned long tp, unsigned long long file_id)
{
	return actvxactcall_drvcall_devhost_clock_settime(false, false, tp, file_id);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_clock_settime(rref_t __rref, unsigned long tp, unsigned long long file_id)
{
	return actvxactcapcall_drvcall_devhost_clock_settime(false, false, __rref, tp, file_id);
}

extern int __actvcall_drvcall_devhost_clock_gettime(unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id);


extern int __actvcapcall_drvcall_devhost_clock_gettime(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_clock_gettime(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long tp, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_clock_gettime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_clock_gettime(rpc_info, NULL, tp, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_clock_gettime(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long tp, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_clock_gettime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_clock_gettime(__rref, rpc_info, NULL, tp, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_clock_gettime(unsigned long tp, unsigned long long file_id)
{
	return actvxactcall_drvcall_devhost_clock_gettime(false, false, tp, file_id);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_clock_gettime(rref_t __rref, unsigned long tp, unsigned long long file_id)
{
	return actvxactcapcall_drvcall_devhost_clock_gettime(false, false, __rref, tp, file_id);
}

extern int __actvcall_drvcall_devhost_clock_getres(unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id);


extern int __actvcapcall_drvcall_devhost_clock_getres(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_clock_getres(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long tp, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_clock_getres;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_clock_getres(rpc_info, NULL, tp, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_clock_getres(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long tp, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_clock_getres;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_clock_getres(__rref, rpc_info, NULL, tp, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_clock_getres(unsigned long tp, unsigned long long file_id)
{
	return actvxactcall_drvcall_devhost_clock_getres(false, false, tp, file_id);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_clock_getres(rref_t __rref, unsigned long tp, unsigned long long file_id)
{
	return actvxactcapcall_drvcall_devhost_clock_getres(false, false, __rref, tp, file_id);
}

extern int __actvcall_drvcall_devhost_clock_adjtime(unsigned long long __rpc_info, void *__buf, unsigned long tx, unsigned long long file_id);


extern int __actvcapcall_drvcall_devhost_clock_adjtime(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long tx, unsigned long long file_id);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_clock_adjtime(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long tx, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_clock_adjtime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_clock_adjtime(rpc_info, NULL, tx, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_clock_adjtime(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long tx, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_clock_adjtime;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_clock_adjtime(__rref, rpc_info, NULL, tx, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_clock_adjtime(unsigned long tx, unsigned long long file_id)
{
	return actvxactcall_drvcall_devhost_clock_adjtime(false, false, tx, file_id);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_clock_adjtime(rref_t __rref, unsigned long tx, unsigned long long file_id)
{
	return actvxactcapcall_drvcall_devhost_clock_adjtime(false, false, __rref, tx, file_id);
}

extern int __actvcall_drvcall_devhost_transfs_mounted(unsigned long long __rpc_info, void *__buf, dev_t dev_id, int dev_mode, struct hm_actv_buf fs_name, struct hm_actv_buf mount_opts, size_t per_write_size, unsigned int sector_dentry_bits);


extern int __actvcapcall_drvcall_devhost_transfs_mounted(rref_t __rref, unsigned long long __rpc_info, void *__buf, dev_t dev_id, int dev_mode, struct hm_actv_buf fs_name, struct hm_actv_buf mount_opts, size_t per_write_size, unsigned int sector_dentry_bits);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_mounted(bool is_xact_fwd, bool is_xact_allow_refwd, dev_t dev_id, int dev_mode, struct hm_actv_buf fs_name, struct hm_actv_buf mount_opts, size_t per_write_size, unsigned int sector_dentry_bits, struct __actvret_drvcall_devhost_transfs_mounted *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_mounted;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(dev_t), __arch_actv_rpc_stksz_alignment(dev_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_mounted(rpc_info, __ret, dev_id, dev_mode, fs_name, mount_opts, per_write_size, sector_dentry_bits);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_mounted(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, dev_t dev_id, int dev_mode, struct hm_actv_buf fs_name, struct hm_actv_buf mount_opts, size_t per_write_size, unsigned int sector_dentry_bits, struct __actvret_drvcall_devhost_transfs_mounted *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_mounted;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(dev_t), __arch_actv_rpc_stksz_alignment(dev_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_mounted(__rref, rpc_info, __ret, dev_id, dev_mode, fs_name, mount_opts, per_write_size, sector_dentry_bits);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_mounted(dev_t dev_id, int dev_mode, struct hm_actv_buf fs_name, struct hm_actv_buf mount_opts, size_t per_write_size, unsigned int sector_dentry_bits, struct __actvret_drvcall_devhost_transfs_mounted *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_mounted(false, false, dev_id, dev_mode, fs_name, mount_opts, per_write_size, sector_dentry_bits, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_mounted(rref_t __rref, dev_t dev_id, int dev_mode, struct hm_actv_buf fs_name, struct hm_actv_buf mount_opts, size_t per_write_size, unsigned int sector_dentry_bits, struct __actvret_drvcall_devhost_transfs_mounted *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_mounted(false, false, __rref, dev_id, dev_mode, fs_name, mount_opts, per_write_size, sector_dentry_bits, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_unmounted(unsigned long long __rpc_info, void *__buf, unsigned int s_index, int flags, unsigned long long file_id);


extern int __actvcapcall_drvcall_devhost_transfs_unmounted(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, int flags, unsigned long long file_id);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_unmounted(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, int flags, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_transfs_unmounted;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_unmounted(rpc_info, NULL, s_index, flags, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_unmounted(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, int flags, unsigned long long file_id)
{
	const unsigned long __callno = __devhost_method_transfs_unmounted;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_unmounted(__rref, rpc_info, NULL, s_index, flags, file_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_unmounted(unsigned int s_index, int flags, unsigned long long file_id)
{
	return actvxactcall_drvcall_devhost_transfs_unmounted(false, false, s_index, flags, file_id);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_unmounted(rref_t __rref, unsigned int s_index, int flags, unsigned long long file_id)
{
	return actvxactcapcall_drvcall_devhost_transfs_unmounted(false, false, __rref, s_index, flags, file_id);
}

extern int __actvcall_drvcall_devhost_transfs_drop_caches(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int mode, int max_nr);


extern int __actvcapcall_drvcall_devhost_transfs_drop_caches(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int mode, int max_nr);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_drop_caches(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int mode, int max_nr)
{
	const unsigned long __callno = __devhost_method_transfs_drop_caches;
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
		__res = __actvcall_drvcall_devhost_transfs_drop_caches(rpc_info, NULL, s_index, mode, max_nr);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_drop_caches(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int mode, int max_nr)
{
	const unsigned long __callno = __devhost_method_transfs_drop_caches;
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
		__res = __actvcapcall_drvcall_devhost_transfs_drop_caches(__rref, rpc_info, NULL, s_index, mode, max_nr);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_drop_caches(unsigned int s_index, unsigned int mode, int max_nr)
{
	return actvxactcall_drvcall_devhost_transfs_drop_caches(false, false, s_index, mode, max_nr);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_drop_caches(rref_t __rref, unsigned int s_index, unsigned int mode, int max_nr)
{
	return actvxactcapcall_drvcall_devhost_transfs_drop_caches(false, false, __rref, s_index, mode, max_nr);
}

extern int __actvcall_drvcall_devhost_transfs_mkdir(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname);


extern int __actvcapcall_drvcall_devhost_transfs_mkdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_mkdir(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_mkdir *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_mkdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_mkdir(rpc_info, __ret, s_index, pd_index, mode, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_mkdir(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_mkdir *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_mkdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_mkdir(__rref, rpc_info, __ret, s_index, pd_index, mode, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_mkdir(unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_mkdir *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_mkdir(false, false, s_index, pd_index, mode, actv_dname, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_mkdir(rref_t __rref, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_mkdir *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_mkdir(false, false, __rref, s_index, pd_index, mode, actv_dname, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_rmdir(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int d_index);


extern int __actvcapcall_drvcall_devhost_transfs_rmdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int d_index);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_rmdir(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	const unsigned long __callno = __devhost_method_transfs_rmdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_rmdir(rpc_info, NULL, s_index, pd_index, d_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_rmdir(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	const unsigned long __callno = __devhost_method_transfs_rmdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_rmdir(__rref, rpc_info, NULL, s_index, pd_index, d_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_rmdir(unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	return actvxactcall_drvcall_devhost_transfs_rmdir(false, false, s_index, pd_index, d_index);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_rmdir(rref_t __rref, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	return actvxactcapcall_drvcall_devhost_transfs_rmdir(false, false, __rref, s_index, pd_index, d_index);
}

extern int __actvcall_drvcall_devhost_transfs_create(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname);


extern int __actvcapcall_drvcall_devhost_transfs_create(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_create(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_create *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_create;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_create(rpc_info, __ret, s_index, pd_index, mode, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_create(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_create *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_create;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_create(__rref, rpc_info, __ret, s_index, pd_index, mode, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_create(unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_create *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_create(false, false, s_index, pd_index, mode, actv_dname, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_create(rref_t __rref, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_create *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_create(false, false, __rref, s_index, pd_index, mode, actv_dname, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_unlink(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int d_index);


extern int __actvcapcall_drvcall_devhost_transfs_unlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int d_index);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_unlink(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	const unsigned long __callno = __devhost_method_transfs_unlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_unlink(rpc_info, NULL, s_index, pd_index, d_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_unlink(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	const unsigned long __callno = __devhost_method_transfs_unlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_unlink(__rref, rpc_info, NULL, s_index, pd_index, d_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_unlink(unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	return actvxactcall_drvcall_devhost_transfs_unlink(false, false, s_index, pd_index, d_index);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_unlink(rref_t __rref, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	return actvxactcapcall_drvcall_devhost_transfs_unlink(false, false, __rref, s_index, pd_index, d_index);
}

extern int __actvcall_drvcall_devhost_transfs_mknod(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int mode, unsigned long long devno, struct hm_actv_buf actv_dname);


extern int __actvcapcall_drvcall_devhost_transfs_mknod(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int mode, unsigned long long devno, struct hm_actv_buf actv_dname);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_mknod(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int pd_index, unsigned int mode, unsigned long long devno, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_mknod *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_mknod;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_mknod(rpc_info, __ret, s_index, pd_index, mode, devno, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_mknod(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int pd_index, unsigned int mode, unsigned long long devno, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_mknod *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_mknod;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_mknod(__rref, rpc_info, __ret, s_index, pd_index, mode, devno, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_mknod(unsigned int s_index, unsigned int pd_index, unsigned int mode, unsigned long long devno, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_mknod *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_mknod(false, false, s_index, pd_index, mode, devno, actv_dname, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_mknod(rref_t __rref, unsigned int s_index, unsigned int pd_index, unsigned int mode, unsigned long long devno, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_mknod *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_mknod(false, false, __rref, s_index, pd_index, mode, devno, actv_dname, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_link(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname);


extern int __actvcapcall_drvcall_devhost_transfs_link(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_link(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_link *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_link;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_link(rpc_info, __ret, s_index, old_d_index, new_pd_index, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_link(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_link *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_link;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_link(__rref, rpc_info, __ret, s_index, old_d_index, new_pd_index, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_link(unsigned int s_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_link *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_link(false, false, s_index, old_d_index, new_pd_index, actv_dname, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_link(rref_t __rref, unsigned int s_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_link *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_link(false, false, __rref, s_index, old_d_index, new_pd_index, actv_dname, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_symlink(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, struct hm_actv_buf actv_dname, struct hm_actv_buf actv_path);


extern int __actvcapcall_drvcall_devhost_transfs_symlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, struct hm_actv_buf actv_dname, struct hm_actv_buf actv_path);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_symlink(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int pd_index, struct hm_actv_buf actv_dname, struct hm_actv_buf actv_path, struct __actvret_drvcall_devhost_transfs_symlink *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_symlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_symlink(rpc_info, __ret, s_index, pd_index, actv_dname, actv_path);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_symlink(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int pd_index, struct hm_actv_buf actv_dname, struct hm_actv_buf actv_path, struct __actvret_drvcall_devhost_transfs_symlink *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_symlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_symlink(__rref, rpc_info, __ret, s_index, pd_index, actv_dname, actv_path);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_symlink(unsigned int s_index, unsigned int pd_index, struct hm_actv_buf actv_dname, struct hm_actv_buf actv_path, struct __actvret_drvcall_devhost_transfs_symlink *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_symlink(false, false, s_index, pd_index, actv_dname, actv_path, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_symlink(rref_t __rref, unsigned int s_index, unsigned int pd_index, struct hm_actv_buf actv_dname, struct hm_actv_buf actv_path, struct __actvret_drvcall_devhost_transfs_symlink *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_symlink(false, false, __rref, s_index, pd_index, actv_dname, actv_path, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_statfs(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, void *buf);


extern int __actvcapcall_drvcall_devhost_transfs_statfs(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, void *buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_statfs(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int d_index, void *buf)
{
	const unsigned long __callno = __devhost_method_transfs_statfs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_statfs(rpc_info, NULL, s_index, d_index, buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_statfs(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int d_index, void *buf)
{
	const unsigned long __callno = __devhost_method_transfs_statfs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_statfs(__rref, rpc_info, NULL, s_index, d_index, buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_statfs(unsigned int s_index, unsigned int d_index, void *buf)
{
	return actvxactcall_drvcall_devhost_transfs_statfs(false, false, s_index, d_index, buf);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_statfs(rref_t __rref, unsigned int s_index, unsigned int d_index, void *buf)
{
	return actvxactcapcall_drvcall_devhost_transfs_statfs(false, false, __rref, s_index, d_index, buf);
}

extern int __actvcall_drvcall_devhost_transfs_rename(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int old_pd_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname);


extern int __actvcapcall_drvcall_devhost_transfs_rename(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int old_pd_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_rename(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int sb_index, unsigned int old_pd_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname)
{
	const unsigned long __callno = __devhost_method_transfs_rename;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_rename(rpc_info, NULL, sb_index, old_pd_index, old_d_index, new_pd_index, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_rename(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int sb_index, unsigned int old_pd_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname)
{
	const unsigned long __callno = __devhost_method_transfs_rename;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_rename(__rref, rpc_info, NULL, sb_index, old_pd_index, old_d_index, new_pd_index, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_rename(unsigned int sb_index, unsigned int old_pd_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname)
{
	return actvxactcall_drvcall_devhost_transfs_rename(false, false, sb_index, old_pd_index, old_d_index, new_pd_index, actv_dname);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_rename(rref_t __rref, unsigned int sb_index, unsigned int old_pd_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname)
{
	return actvxactcapcall_drvcall_devhost_transfs_rename(false, false, __rref, sb_index, old_pd_index, old_d_index, new_pd_index, actv_dname);
}

extern int __actvcall_drvcall_devhost_transfs_lookup(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int pd_index, struct hm_actv_buf actv_dname, void *meta);


extern int __actvcapcall_drvcall_devhost_transfs_lookup(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int pd_index, struct hm_actv_buf actv_dname, void *meta);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_lookup(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int sb_index, unsigned int pd_index, struct hm_actv_buf actv_dname, void *meta, struct __actvret_drvcall_devhost_transfs_lookup *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_lookup;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_lookup(rpc_info, __ret, sb_index, pd_index, actv_dname, meta);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_lookup(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int sb_index, unsigned int pd_index, struct hm_actv_buf actv_dname, void *meta, struct __actvret_drvcall_devhost_transfs_lookup *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_lookup;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_lookup(__rref, rpc_info, __ret, sb_index, pd_index, actv_dname, meta);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_lookup(unsigned int sb_index, unsigned int pd_index, struct hm_actv_buf actv_dname, void *meta, struct __actvret_drvcall_devhost_transfs_lookup *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_lookup(false, false, sb_index, pd_index, actv_dname, meta, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_lookup(rref_t __rref, unsigned int sb_index, unsigned int pd_index, struct hm_actv_buf actv_dname, void *meta, struct __actvret_drvcall_devhost_transfs_lookup *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_lookup(false, false, __rref, sb_index, pd_index, actv_dname, meta, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_setattr(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, const void *attr, uint64_t size);


extern int __actvcapcall_drvcall_devhost_transfs_setattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, const void *attr, uint64_t size);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_setattr(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int sb_index, unsigned int d_index, const void *attr, uint64_t size)
{
	const unsigned long __callno = __devhost_method_transfs_setattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_setattr(rpc_info, NULL, sb_index, d_index, attr, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_setattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int sb_index, unsigned int d_index, const void *attr, uint64_t size)
{
	const unsigned long __callno = __devhost_method_transfs_setattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_setattr(__rref, rpc_info, NULL, sb_index, d_index, attr, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_setattr(unsigned int sb_index, unsigned int d_index, const void *attr, uint64_t size)
{
	return actvxactcall_drvcall_devhost_transfs_setattr(false, false, sb_index, d_index, attr, size);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_setattr(rref_t __rref, unsigned int sb_index, unsigned int d_index, const void *attr, uint64_t size)
{
	return actvxactcapcall_drvcall_devhost_transfs_setattr(false, false, __rref, sb_index, d_index, attr, size);
}

extern int __actvcall_drvcall_devhost_transfs_readlink(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, char *buf, size_t bufsize);


extern int __actvcapcall_drvcall_devhost_transfs_readlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, char *buf, size_t bufsize);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_readlink(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int sb_index, unsigned int d_index, char *buf, size_t bufsize)
{
	const unsigned long __callno = __devhost_method_transfs_readlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_readlink(rpc_info, NULL, sb_index, d_index, buf, bufsize);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_readlink(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int sb_index, unsigned int d_index, char *buf, size_t bufsize)
{
	const unsigned long __callno = __devhost_method_transfs_readlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_readlink(__rref, rpc_info, NULL, sb_index, d_index, buf, bufsize);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_readlink(unsigned int sb_index, unsigned int d_index, char *buf, size_t bufsize)
{
	return actvxactcall_drvcall_devhost_transfs_readlink(false, false, sb_index, d_index, buf, bufsize);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_readlink(rref_t __rref, unsigned int sb_index, unsigned int d_index, char *buf, size_t bufsize)
{
	return actvxactcapcall_drvcall_devhost_transfs_readlink(false, false, __rref, sb_index, d_index, buf, bufsize);
}

extern int __actvcall_drvcall_devhost_transfs_getattr(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, void *meta);


extern int __actvcapcall_drvcall_devhost_transfs_getattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, void *meta);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_getattr(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int sb_index, unsigned int d_index, void *meta)
{
	const unsigned long __callno = __devhost_method_transfs_getattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_getattr(rpc_info, NULL, sb_index, d_index, meta);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_getattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int sb_index, unsigned int d_index, void *meta)
{
	const unsigned long __callno = __devhost_method_transfs_getattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_getattr(__rref, rpc_info, NULL, sb_index, d_index, meta);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_getattr(unsigned int sb_index, unsigned int d_index, void *meta)
{
	return actvxactcall_drvcall_devhost_transfs_getattr(false, false, sb_index, d_index, meta);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_getattr(rref_t __rref, unsigned int sb_index, unsigned int d_index, void *meta)
{
	return actvxactcapcall_drvcall_devhost_transfs_getattr(false, false, __rref, sb_index, d_index, meta);
}

extern int __actvcall_drvcall_devhost_transfs_listxattr(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, char *buffer, size_t size);


extern int __actvcapcall_drvcall_devhost_transfs_listxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, char *buffer, size_t size);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_listxattr(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int d_index, char *buffer, size_t size, struct __actvret_drvcall_devhost_transfs_listxattr *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_listxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_listxattr(rpc_info, __ret, s_index, d_index, buffer, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_listxattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int d_index, char *buffer, size_t size, struct __actvret_drvcall_devhost_transfs_listxattr *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_listxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_listxattr(__rref, rpc_info, __ret, s_index, d_index, buffer, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_listxattr(unsigned int s_index, unsigned int d_index, char *buffer, size_t size, struct __actvret_drvcall_devhost_transfs_listxattr *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_listxattr(false, false, s_index, d_index, buffer, size, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_listxattr(rref_t __rref, unsigned int s_index, unsigned int d_index, char *buffer, size_t size, struct __actvret_drvcall_devhost_transfs_listxattr *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_listxattr(false, false, __rref, s_index, d_index, buffer, size, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_getxattr(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, char *value, size_t size);


extern int __actvcapcall_drvcall_devhost_transfs_getxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, char *value, size_t size);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_getxattr(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, char *value, size_t size, struct __actvret_drvcall_devhost_transfs_getxattr *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_getxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_getxattr(rpc_info, __ret, s_index, d_index, prefix, actv_name, value, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_getxattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, char *value, size_t size, struct __actvret_drvcall_devhost_transfs_getxattr *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_getxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_getxattr(__rref, rpc_info, __ret, s_index, d_index, prefix, actv_name, value, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_getxattr(unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, char *value, size_t size, struct __actvret_drvcall_devhost_transfs_getxattr *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_getxattr(false, false, s_index, d_index, prefix, actv_name, value, size, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_getxattr(rref_t __rref, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, char *value, size_t size, struct __actvret_drvcall_devhost_transfs_getxattr *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_getxattr(false, false, __rref, s_index, d_index, prefix, actv_name, value, size, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_setxattr(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, const char *value, size_t size, int flags);


extern int __actvcapcall_drvcall_devhost_transfs_setxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, const char *value, size_t size, int flags);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_setxattr(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, const char *value, size_t size, int flags)
{
	const unsigned long __callno = __devhost_method_transfs_setxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_setxattr(rpc_info, NULL, s_index, d_index, prefix, actv_name, value, size, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_setxattr(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, const char *value, size_t size, int flags)
{
	const unsigned long __callno = __devhost_method_transfs_setxattr;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const char*), __arch_actv_rpc_stksz_alignment(const char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_setxattr(__rref, rpc_info, NULL, s_index, d_index, prefix, actv_name, value, size, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_setxattr(unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, const char *value, size_t size, int flags)
{
	return actvxactcall_drvcall_devhost_transfs_setxattr(false, false, s_index, d_index, prefix, actv_name, value, size, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_setxattr(rref_t __rref, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, const char *value, size_t size, int flags)
{
	return actvxactcapcall_drvcall_devhost_transfs_setxattr(false, false, __rref, s_index, d_index, prefix, actv_name, value, size, flags);
}

extern int __actvcall_drvcall_devhost_transfs_tmpfile(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_addr, mode_t mode, struct hm_actv_buf actv_dname);


extern int __actvcapcall_drvcall_devhost_transfs_tmpfile(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_addr, mode_t mode, struct hm_actv_buf actv_dname);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_tmpfile(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int pd_addr, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_tmpfile *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_tmpfile;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_tmpfile(rpc_info, __ret, s_index, pd_addr, mode, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_tmpfile(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int pd_addr, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_tmpfile *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_tmpfile;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(mode_t), __arch_actv_rpc_stksz_alignment(mode_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_tmpfile(__rref, rpc_info, __ret, s_index, pd_addr, mode, actv_dname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_tmpfile(unsigned int s_index, unsigned int pd_addr, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_tmpfile *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_tmpfile(false, false, s_index, pd_addr, mode, actv_dname, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_tmpfile(rref_t __rref, unsigned int s_index, unsigned int pd_addr, mode_t mode, struct hm_actv_buf actv_dname, struct __actvret_drvcall_devhost_transfs_tmpfile *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_tmpfile(false, false, __rref, s_index, pd_addr, mode, actv_dname, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_kill_dentry(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index);


extern int __actvcapcall_drvcall_devhost_transfs_kill_dentry(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_kill_dentry(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int d_index)
{
	const unsigned long __callno = __devhost_method_transfs_kill_dentry;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_kill_dentry(rpc_info, NULL, s_index, d_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_kill_dentry(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int d_index)
{
	const unsigned long __callno = __devhost_method_transfs_kill_dentry;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_kill_dentry(__rref, rpc_info, NULL, s_index, d_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_kill_dentry(unsigned int s_index, unsigned int d_index)
{
	return actvxactcall_drvcall_devhost_transfs_kill_dentry(false, false, s_index, d_index);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_kill_dentry(rref_t __rref, unsigned int s_index, unsigned int d_index)
{
	return actvxactcapcall_drvcall_devhost_transfs_kill_dentry(false, false, __rref, s_index, d_index);
}

extern int __actvcall_drvcall_devhost_transfs_node_put(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int v_index);


extern int __actvcapcall_drvcall_devhost_transfs_node_put(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int v_index);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_node_put(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int v_index)
{
	const unsigned long __callno = __devhost_method_transfs_node_put;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_node_put(rpc_info, NULL, s_index, v_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_node_put(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int v_index)
{
	const unsigned long __callno = __devhost_method_transfs_node_put;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_node_put(__rref, rpc_info, NULL, s_index, v_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_node_put(unsigned int s_index, unsigned int v_index)
{
	return actvxactcall_drvcall_devhost_transfs_node_put(false, false, s_index, v_index);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_node_put(rref_t __rref, unsigned int s_index, unsigned int v_index)
{
	return actvxactcapcall_drvcall_devhost_transfs_node_put(false, false, __rref, s_index, v_index);
}

extern int __actvcall_drvcall_devhost_transfs_sync(unsigned long long __rpc_info, void *__buf, unsigned int s_index);


extern int __actvcapcall_drvcall_devhost_transfs_sync(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_sync(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index)
{
	const unsigned long __callno = __devhost_method_transfs_sync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_sync(rpc_info, NULL, s_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_sync(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index)
{
	const unsigned long __callno = __devhost_method_transfs_sync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_sync(__rref, rpc_info, NULL, s_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_sync(unsigned int s_index)
{
	return actvxactcall_drvcall_devhost_transfs_sync(false, false, s_index);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_sync(rref_t __rref, unsigned int s_index)
{
	return actvxactcapcall_drvcall_devhost_transfs_sync(false, false, __rref, s_index);
}

extern int __actvcall_drvcall_devhost_transfs_write(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, uint64_t pos, const void *src, size_t len);


extern int __actvcapcall_drvcall_devhost_transfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, uint64_t pos, const void *src, size_t len);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int f_index, uint64_t pos, const void *src, size_t len, struct __actvret_drvcall_devhost_transfs_write *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_write(rpc_info, __ret, s_index, f_index, pos, src, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int f_index, uint64_t pos, const void *src, size_t len, struct __actvret_drvcall_devhost_transfs_write *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_write(__rref, rpc_info, __ret, s_index, f_index, pos, src, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_write(unsigned int s_index, unsigned int f_index, uint64_t pos, const void *src, size_t len, struct __actvret_drvcall_devhost_transfs_write *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_write(false, false, s_index, f_index, pos, src, len, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_write(rref_t __rref, unsigned int s_index, unsigned int f_index, uint64_t pos, const void *src, size_t len, struct __actvret_drvcall_devhost_transfs_write *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_write(false, false, __rref, s_index, f_index, pos, src, len, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_fsync(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index);


extern int __actvcapcall_drvcall_devhost_transfs_fsync(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_fsync(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int f_index)
{
	const unsigned long __callno = __devhost_method_transfs_fsync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_fsync(rpc_info, NULL, s_index, f_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_fsync(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int f_index)
{
	const unsigned long __callno = __devhost_method_transfs_fsync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_fsync(__rref, rpc_info, NULL, s_index, f_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_fsync(unsigned int s_index, unsigned int f_index)
{
	return actvxactcall_drvcall_devhost_transfs_fsync(false, false, s_index, f_index);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_fsync(rref_t __rref, unsigned int s_index, unsigned int f_index)
{
	return actvxactcapcall_drvcall_devhost_transfs_fsync(false, false, __rref, s_index, f_index);
}

extern int __actvcall_drvcall_devhost_transfs_readdir(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int f_index, uint64_t pos, void *buf, size_t size);


extern int __actvcapcall_drvcall_devhost_transfs_readdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int f_index, uint64_t pos, void *buf, size_t size);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_readdir(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int sb_index, unsigned int f_index, uint64_t pos, void *buf, size_t size)
{
	const unsigned long __callno = __devhost_method_transfs_readdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_readdir(rpc_info, NULL, sb_index, f_index, pos, buf, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_readdir(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int sb_index, unsigned int f_index, uint64_t pos, void *buf, size_t size)
{
	const unsigned long __callno = __devhost_method_transfs_readdir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_readdir(__rref, rpc_info, NULL, sb_index, f_index, pos, buf, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_readdir(unsigned int sb_index, unsigned int f_index, uint64_t pos, void *buf, size_t size)
{
	return actvxactcall_drvcall_devhost_transfs_readdir(false, false, sb_index, f_index, pos, buf, size);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_readdir(rref_t __rref, unsigned int sb_index, unsigned int f_index, uint64_t pos, void *buf, size_t size)
{
	return actvxactcapcall_drvcall_devhost_transfs_readdir(false, false, __rref, sb_index, f_index, pos, buf, size);
}

extern int __actvcall_drvcall_devhost_transfs_open(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, unsigned int f_modes, unsigned int f_flags);


extern int __actvcapcall_drvcall_devhost_transfs_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, unsigned int f_modes, unsigned int f_flags);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_open(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int sb_index, unsigned int d_index, unsigned int f_modes, unsigned int f_flags, struct __actvret_drvcall_devhost_transfs_open *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_open(rpc_info, __ret, sb_index, d_index, f_modes, f_flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_open(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int sb_index, unsigned int d_index, unsigned int f_modes, unsigned int f_flags, struct __actvret_drvcall_devhost_transfs_open *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_open(__rref, rpc_info, __ret, sb_index, d_index, f_modes, f_flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_open(unsigned int sb_index, unsigned int d_index, unsigned int f_modes, unsigned int f_flags, struct __actvret_drvcall_devhost_transfs_open *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_open(false, false, sb_index, d_index, f_modes, f_flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_open(rref_t __rref, unsigned int sb_index, unsigned int d_index, unsigned int f_modes, unsigned int f_flags, struct __actvret_drvcall_devhost_transfs_open *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_open(false, false, __rref, sb_index, d_index, f_modes, f_flags, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_fallocate(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int f_index, unsigned int mode, uint64_t pos, uint64_t len);


extern int __actvcapcall_drvcall_devhost_transfs_fallocate(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int f_index, unsigned int mode, uint64_t pos, uint64_t len);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_fallocate(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int sb_index, unsigned int f_index, unsigned int mode, uint64_t pos, uint64_t len)
{
	const unsigned long __callno = __devhost_method_transfs_fallocate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_fallocate(rpc_info, NULL, sb_index, f_index, mode, pos, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_fallocate(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int sb_index, unsigned int f_index, unsigned int mode, uint64_t pos, uint64_t len)
{
	const unsigned long __callno = __devhost_method_transfs_fallocate;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_fallocate(__rref, rpc_info, NULL, sb_index, f_index, mode, pos, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_fallocate(unsigned int sb_index, unsigned int f_index, unsigned int mode, uint64_t pos, uint64_t len)
{
	return actvxactcall_drvcall_devhost_transfs_fallocate(false, false, sb_index, f_index, mode, pos, len);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_fallocate(rref_t __rref, unsigned int sb_index, unsigned int f_index, unsigned int mode, uint64_t pos, uint64_t len)
{
	return actvxactcapcall_drvcall_devhost_transfs_fallocate(false, false, __rref, sb_index, f_index, mode, pos, len);
}

extern int __actvcall_drvcall_devhost_transfs_close(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index);


extern int __actvcapcall_drvcall_devhost_transfs_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_close(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int f_index)
{
	const unsigned long __callno = __devhost_method_transfs_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_close(rpc_info, NULL, s_index, f_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_close(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int f_index)
{
	const unsigned long __callno = __devhost_method_transfs_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_close(__rref, rpc_info, NULL, s_index, f_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_close(unsigned int s_index, unsigned int f_index)
{
	return actvxactcall_drvcall_devhost_transfs_close(false, false, s_index, f_index);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_close(rref_t __rref, unsigned int s_index, unsigned int f_index)
{
	return actvxactcapcall_drvcall_devhost_transfs_close(false, false, __rref, s_index, f_index);
}

extern int __actvcall_drvcall_devhost_transfs_ioctl(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, unsigned int cmd, unsigned long arg);


extern int __actvcapcall_drvcall_devhost_transfs_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, unsigned int cmd, unsigned long arg);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int f_index, unsigned int cmd, unsigned long arg)
{
	const unsigned long __callno = __devhost_method_transfs_ioctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_ioctl(rpc_info, NULL, s_index, f_index, cmd, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int f_index, unsigned int cmd, unsigned long arg)
{
	const unsigned long __callno = __devhost_method_transfs_ioctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_ioctl(__rref, rpc_info, NULL, s_index, f_index, cmd, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_ioctl(unsigned int s_index, unsigned int f_index, unsigned int cmd, unsigned long arg)
{
	return actvxactcall_drvcall_devhost_transfs_ioctl(false, false, s_index, f_index, cmd, arg);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_ioctl(rref_t __rref, unsigned int s_index, unsigned int f_index, unsigned int cmd, unsigned long arg)
{
	return actvxactcapcall_drvcall_devhost_transfs_ioctl(false, false, __rref, s_index, f_index, cmd, arg);
}

extern int __actvcall_drvcall_devhost_transfs_direct_IO(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, uint64_t offset, void *buf, size_t len, unsigned int type);


extern int __actvcapcall_drvcall_devhost_transfs_direct_IO(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, uint64_t offset, void *buf, size_t len, unsigned int type);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_direct_IO(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, unsigned int f_index, uint64_t offset, void *buf, size_t len, unsigned int type, struct __actvret_drvcall_devhost_transfs_direct_IO *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_direct_IO;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_direct_IO(rpc_info, __ret, s_index, f_index, offset, buf, len, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_direct_IO(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, unsigned int f_index, uint64_t offset, void *buf, size_t len, unsigned int type, struct __actvret_drvcall_devhost_transfs_direct_IO *__ret)
{
	const unsigned long __callno = __devhost_method_transfs_direct_IO;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uint64_t), __arch_actv_rpc_stksz_alignment(uint64_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_direct_IO(__rref, rpc_info, __ret, s_index, f_index, offset, buf, len, type);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_direct_IO(unsigned int s_index, unsigned int f_index, uint64_t offset, void *buf, size_t len, unsigned int type, struct __actvret_drvcall_devhost_transfs_direct_IO *__ret)
{
	return actvxactcall_drvcall_devhost_transfs_direct_IO(false, false, s_index, f_index, offset, buf, len, type, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_direct_IO(rref_t __rref, unsigned int s_index, unsigned int f_index, uint64_t offset, void *buf, size_t len, unsigned int type, struct __actvret_drvcall_devhost_transfs_direct_IO *__ret)
{
	return actvxactcapcall_drvcall_devhost_transfs_direct_IO(false, false, __rref, s_index, f_index, offset, buf, len, type, __ret);
}

extern int __actvcall_drvcall_devhost_transfs_update_opts(unsigned long long __rpc_info, void *__buf, unsigned int s_index, char *ubuf, size_t buflen);


extern int __actvcapcall_drvcall_devhost_transfs_update_opts(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, char *ubuf, size_t buflen);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devhost_transfs_update_opts(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int s_index, char *ubuf, size_t buflen)
{
	const unsigned long __callno = __devhost_method_transfs_update_opts;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devhost_transfs_update_opts(rpc_info, NULL, s_index, ubuf, buflen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devhost_transfs_update_opts(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int s_index, char *ubuf, size_t buflen)
{
	const unsigned long __callno = __devhost_method_transfs_update_opts;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(char*), __arch_actv_rpc_stksz_alignment(char*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devhost_transfs_update_opts(__rref, rpc_info, NULL, s_index, ubuf, buflen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devhost_transfs_update_opts(unsigned int s_index, char *ubuf, size_t buflen)
{
	return actvxactcall_drvcall_devhost_transfs_update_opts(false, false, s_index, ubuf, buflen);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devhost_transfs_update_opts(rref_t __rref, unsigned int s_index, char *ubuf, size_t buflen)
{
	return actvxactcapcall_drvcall_devhost_transfs_update_opts(false, false, __rref, s_index, ubuf, buflen);
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
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_buf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_retbuf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_fallback(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
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

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_core_load_driver(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_core_load_driver(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_core_load_driver(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, struct hm_actv_buf args, unsigned long long mpool_id, unsigned long size)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	struct hm_actv_buf __maybe_unused __actv_local_var_args = args;
	unsigned long long __maybe_unused __actv_local_var_mpool_id = mpool_id;
	unsigned long __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_drvcall_devhost_core_load_driver(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args), __ARCH_ACTV_RPC_PASS_ARG(mpool_id, __actv_local_var_mpool_id), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_core_load_driver(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, struct hm_actv_buf args, unsigned long long mpool_id, unsigned long size)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	struct hm_actv_buf __maybe_unused __actv_local_var_args = args;
	unsigned long long __maybe_unused __actv_local_var_mpool_id = mpool_id;
	unsigned long __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_drvcall_devhost_core_load_driver(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args), __ARCH_ACTV_RPC_PASS_ARG(mpool_id, __actv_local_var_mpool_id), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_drvcall_devhost_core_create_device(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_drvcall_devhost_core_create_device(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_core_create_device(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, struct hm_actv_buf devname, struct hm_actv_buf dev_compat, int parent_devid, unsigned int resource_count)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_devname = devname;
	struct hm_actv_buf __maybe_unused __actv_local_var_dev_compat = dev_compat;
	int __maybe_unused __actv_local_var_parent_devid = parent_devid;
	unsigned int __maybe_unused __actv_local_var_resource_count = resource_count;
	__ret = ____actvcall_drvcall_devhost_core_create_device(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(devname, __actv_local_var_devname), __ARCH_ACTV_RPC_PASS_ARG(dev_compat, __actv_local_var_dev_compat), __ARCH_ACTV_RPC_PASS_ARG(parent_devid, __actv_local_var_parent_devid), __ARCH_ACTV_RPC_PASS_ARG(resource_count, __actv_local_var_resource_count));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_core_create_device(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, struct hm_actv_buf devname, struct hm_actv_buf dev_compat, int parent_devid, unsigned int resource_count)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_devname = devname;
	struct hm_actv_buf __maybe_unused __actv_local_var_dev_compat = dev_compat;
	int __maybe_unused __actv_local_var_parent_devid = parent_devid;
	unsigned int __maybe_unused __actv_local_var_resource_count = resource_count;
	__ret = ____actvcapcall_drvcall_devhost_core_create_device(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(devname, __actv_local_var_devname), __ARCH_ACTV_RPC_PASS_ARG(dev_compat, __actv_local_var_dev_compat), __ARCH_ACTV_RPC_PASS_ARG(parent_devid, __actv_local_var_parent_devid), __ARCH_ACTV_RPC_PASS_ARG(resource_count, __actv_local_var_resource_count));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_core_unload_driver(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_core_unload_driver(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_core_unload_driver(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf drvname)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_drvname = drvname;
	__ret = ____actvcall_drvcall_devhost_core_unload_driver(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(drvname, __actv_local_var_drvname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_core_unload_driver(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf drvname)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_drvname = drvname;
	__ret = ____actvcapcall_drvcall_devhost_core_unload_driver(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(drvname, __actv_local_var_drvname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_core_bind_device(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_core_bind_device(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_core_bind_device(unsigned long long __rpc_info, void *__buf, int devid, struct hm_actv_buf dev_compat)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	struct hm_actv_buf __maybe_unused __actv_local_var_dev_compat = dev_compat;
	__ret = ____actvcall_drvcall_devhost_core_bind_device(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid), __ARCH_ACTV_RPC_PASS_ARG(dev_compat, __actv_local_var_dev_compat));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_core_bind_device(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid, struct hm_actv_buf dev_compat)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	struct hm_actv_buf __maybe_unused __actv_local_var_dev_compat = dev_compat;
	__ret = ____actvcapcall_drvcall_devhost_core_bind_device(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid), __ARCH_ACTV_RPC_PASS_ARG(dev_compat, __actv_local_var_dev_compat));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_core_entropy_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_core_entropy_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_core_entropy_read(unsigned long long __rpc_info, void *__buf, unsigned int num)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_num = num;
	__ret = ____actvcall_drvcall_devhost_core_entropy_read(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(num, __actv_local_var_num));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_core_entropy_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int num)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_num = num;
	__ret = ____actvcapcall_drvcall_devhost_core_entropy_read(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(num, __actv_local_var_num));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_rpc_export(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_rpc_export(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_rpc_export(unsigned long long __rpc_info, void *__buf, int devid, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_drvcall_devhost_rpc_export(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_rpc_export(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid, unsigned int cnode_idx)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_drvcall_devhost_rpc_export(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_rpc_invoke(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_rpc_invoke(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_rpc_invoke(unsigned long long __rpc_info, void *__buf, int devid, unsigned long req_ubuf, unsigned long req_size, unsigned long resp_ubuf, unsigned long resp_size)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	unsigned long __maybe_unused __actv_local_var_req_ubuf = req_ubuf;
	unsigned long __maybe_unused __actv_local_var_req_size = req_size;
	unsigned long __maybe_unused __actv_local_var_resp_ubuf = resp_ubuf;
	unsigned long __maybe_unused __actv_local_var_resp_size = resp_size;
	__ret = ____actvcall_drvcall_devhost_rpc_invoke(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid), __ARCH_ACTV_RPC_PASS_ARG(req_ubuf, __actv_local_var_req_ubuf), __ARCH_ACTV_RPC_PASS_ARG(req_size, __actv_local_var_req_size), __ARCH_ACTV_RPC_PASS_ARG(resp_ubuf, __actv_local_var_resp_ubuf), __ARCH_ACTV_RPC_PASS_ARG(resp_size, __actv_local_var_resp_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_rpc_invoke(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid, unsigned long req_ubuf, unsigned long req_size, unsigned long resp_ubuf, unsigned long resp_size)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	unsigned long __maybe_unused __actv_local_var_req_ubuf = req_ubuf;
	unsigned long __maybe_unused __actv_local_var_req_size = req_size;
	unsigned long __maybe_unused __actv_local_var_resp_ubuf = resp_ubuf;
	unsigned long __maybe_unused __actv_local_var_resp_size = resp_size;
	__ret = ____actvcapcall_drvcall_devhost_rpc_invoke(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid), __ARCH_ACTV_RPC_PASS_ARG(req_ubuf, __actv_local_var_req_ubuf), __ARCH_ACTV_RPC_PASS_ARG(req_size, __actv_local_var_req_size), __ARCH_ACTV_RPC_PASS_ARG(resp_ubuf, __actv_local_var_resp_ubuf), __ARCH_ACTV_RPC_PASS_ARG(resp_size, __actv_local_var_resp_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_fops_open(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_fops_open(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_open(unsigned long long __rpc_info, void *__buf, int devid, rref_t tgt_rref, unsigned int vfs_flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	rref_t __maybe_unused __actv_local_var_tgt_rref = tgt_rref;
	unsigned int __maybe_unused __actv_local_var_vfs_flags = vfs_flags;
	__ret = ____actvcall_drvcall_devhost_fops_open(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid), __ARCH_ACTV_RPC_PASS_ARG(tgt_rref, __actv_local_var_tgt_rref), __ARCH_ACTV_RPC_PASS_ARG(vfs_flags, __actv_local_var_vfs_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid, rref_t tgt_rref, unsigned int vfs_flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	rref_t __maybe_unused __actv_local_var_tgt_rref = tgt_rref;
	unsigned int __maybe_unused __actv_local_var_vfs_flags = vfs_flags;
	__ret = ____actvcapcall_drvcall_devhost_fops_open(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid), __ARCH_ACTV_RPC_PASS_ARG(tgt_rref, __actv_local_var_tgt_rref), __ARCH_ACTV_RPC_PASS_ARG(vfs_flags, __actv_local_var_vfs_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_fops_close(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_fops_close(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_close(unsigned long long __rpc_info, void *__buf, int padding, unsigned long long file_id)
{
	int __ret;
	int __maybe_unused __actv_local_var_padding = padding;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcall_drvcall_devhost_fops_close(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(padding, __actv_local_var_padding), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, int padding, unsigned long long file_id)
{
	int __ret;
	int __maybe_unused __actv_local_var_padding = padding;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcapcall_drvcall_devhost_fops_close(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(padding, __actv_local_var_padding), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_fops_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_fops_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_read(unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned long long filep, unsigned long long offset, unsigned long count)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_buf = buf;
	unsigned long long __maybe_unused __actv_local_var_filep = filep;
	unsigned long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcall_drvcall_devhost_fops_read(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(filep, __actv_local_var_filep), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned long long filep, unsigned long long offset, unsigned long count)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_buf = buf;
	unsigned long long __maybe_unused __actv_local_var_filep = filep;
	unsigned long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcapcall_drvcall_devhost_fops_read(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(filep, __actv_local_var_filep), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_fops_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_fops_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_write(unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned long long file_id, unsigned long long offset, unsigned long count)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_buf = buf;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcall_drvcall_devhost_fops_write(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned long long file_id, unsigned long long offset, unsigned long count)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_buf = buf;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long long __maybe_unused __actv_local_var_offset = offset;
	unsigned long __maybe_unused __actv_local_var_count = count;
	__ret = ____actvcapcall_drvcall_devhost_fops_write(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(count, __actv_local_var_count));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_fops_ioctl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_fops_ioctl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_ioctl(unsigned long long __rpc_info, void *__buf, int request, unsigned long long file_id, unsigned long arg)
{
	int __ret;
	int __maybe_unused __actv_local_var_request = request;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcall_drvcall_devhost_fops_ioctl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(request, __actv_local_var_request), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int request, unsigned long long file_id, unsigned long arg)
{
	int __ret;
	int __maybe_unused __actv_local_var_request = request;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcapcall_drvcall_devhost_fops_ioctl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(request, __actv_local_var_request), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_fops_llseek(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_fops_llseek(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_llseek(unsigned long long __rpc_info, void *__buf, int whence, unsigned long long file_id, long long offset)
{
	int __ret;
	int __maybe_unused __actv_local_var_whence = whence;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	long long __maybe_unused __actv_local_var_offset = offset;
	__ret = ____actvcall_drvcall_devhost_fops_llseek(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(whence, __actv_local_var_whence), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_llseek(rref_t __rref, unsigned long long __rpc_info, void *__buf, int whence, unsigned long long file_id, long long offset)
{
	int __ret;
	int __maybe_unused __actv_local_var_whence = whence;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	long long __maybe_unused __actv_local_var_offset = offset;
	__ret = ____actvcapcall_drvcall_devhost_fops_llseek(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(whence, __actv_local_var_whence), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_fops_mmap(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_fops_mmap(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_mmap(unsigned long long __rpc_info, void *__buf, unsigned long addr, unsigned long long file_id, unsigned long long vspace_rref, unsigned long length, unsigned long prot, unsigned int flags, unsigned long offset)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_addr = addr;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long long __maybe_unused __actv_local_var_vspace_rref = vspace_rref;
	unsigned long __maybe_unused __actv_local_var_length = length;
	unsigned long __maybe_unused __actv_local_var_prot = prot;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned long __maybe_unused __actv_local_var_offset = offset;
	__ret = ____actvcall_drvcall_devhost_fops_mmap(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(vspace_rref, __actv_local_var_vspace_rref), __ARCH_ACTV_RPC_PASS_ARG(length, __actv_local_var_length), __ARCH_ACTV_RPC_PASS_ARG(prot, __actv_local_var_prot), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_mmap(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long addr, unsigned long long file_id, unsigned long long vspace_rref, unsigned long length, unsigned long prot, unsigned int flags, unsigned long offset)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_addr = addr;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long long __maybe_unused __actv_local_var_vspace_rref = vspace_rref;
	unsigned long __maybe_unused __actv_local_var_length = length;
	unsigned long __maybe_unused __actv_local_var_prot = prot;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned long __maybe_unused __actv_local_var_offset = offset;
	__ret = ____actvcapcall_drvcall_devhost_fops_mmap(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(vspace_rref, __actv_local_var_vspace_rref), __ARCH_ACTV_RPC_PASS_ARG(length, __actv_local_var_length), __ARCH_ACTV_RPC_PASS_ARG(prot, __actv_local_var_prot), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_fops_munmap(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_fops_munmap(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_munmap(unsigned long long __rpc_info, void *__buf, unsigned int key, unsigned long len)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_key = key;
	unsigned long __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcall_drvcall_devhost_fops_munmap(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(key, __actv_local_var_key), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_munmap(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int key, unsigned long len)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_key = key;
	unsigned long __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcapcall_drvcall_devhost_fops_munmap(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(key, __actv_local_var_key), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_drvcall_devhost_fops_sysfs_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_drvcall_devhost_fops_sysfs_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_sysfs_read(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devhost_fops_sysfs_read(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devhost_fops_sysfs_read(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_drvcall_devhost_fops_sysfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_drvcall_devhost_fops_sysfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_sysfs_write(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devhost_fops_sysfs_write(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devhost_fops_sysfs_write(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_fops_epoll_ctl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_fops_epoll_ctl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_epoll_ctl(unsigned long long __rpc_info, void *__buf, unsigned long long file_id, int fd, int op, const void *reg_info)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_op = op;
	__maybe_unused const void *__actv_local_var_reg_info = reg_info;
	__ret = ____actvcall_drvcall_devhost_fops_epoll_ctl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(op, __actv_local_var_op), __ARCH_ACTV_RPC_PASS_ARG(reg_info, __actv_local_var_reg_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_epoll_ctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long file_id, int fd, int op, const void *reg_info)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_op = op;
	__maybe_unused const void *__actv_local_var_reg_info = reg_info;
	__ret = ____actvcapcall_drvcall_devhost_fops_epoll_ctl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(op, __actv_local_var_op), __ARCH_ACTV_RPC_PASS_ARG(reg_info, __actv_local_var_reg_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_fops_epoll_close(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_fops_epoll_close(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_epoll_close(unsigned long long __rpc_info, void *__buf, unsigned int app_cnode_idx, unsigned long long file_id, int fd)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_app_cnode_idx = app_cnode_idx;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_drvcall_devhost_fops_epoll_close(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(app_cnode_idx, __actv_local_var_app_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_epoll_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int app_cnode_idx, unsigned long long file_id, int fd)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_app_cnode_idx = app_cnode_idx;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_drvcall_devhost_fops_epoll_close(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(app_cnode_idx, __actv_local_var_app_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_fops_epoll_et(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_fops_epoll_et(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_epoll_et(unsigned long long __rpc_info, void *__buf, unsigned long long file_id, const void *pre_info)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__maybe_unused const void *__actv_local_var_pre_info = pre_info;
	__ret = ____actvcall_drvcall_devhost_fops_epoll_et(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(pre_info, __actv_local_var_pre_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_epoll_et(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long file_id, const void *pre_info)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__maybe_unused const void *__actv_local_var_pre_info = pre_info;
	__ret = ____actvcapcall_drvcall_devhost_fops_epoll_et(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(pre_info, __actv_local_var_pre_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_fops_epoll_reinit_add(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_fops_epoll_reinit_add(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_fops_epoll_reinit_add(unsigned long long __rpc_info, void *__buf, unsigned long long file_id, int fd, const void *pre_reg_info, const void *reg_info)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_pre_reg_info = pre_reg_info;
	__maybe_unused const void *__actv_local_var_reg_info = reg_info;
	__ret = ____actvcall_drvcall_devhost_fops_epoll_reinit_add(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pre_reg_info, __actv_local_var_pre_reg_info), __ARCH_ACTV_RPC_PASS_ARG(reg_info, __actv_local_var_reg_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_fops_epoll_reinit_add(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long file_id, int fd, const void *pre_reg_info, const void *reg_info)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_pre_reg_info = pre_reg_info;
	__maybe_unused const void *__actv_local_var_reg_info = reg_info;
	__ret = ____actvcapcall_drvcall_devhost_fops_epoll_reinit_add(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(pre_reg_info, __actv_local_var_pre_reg_info), __ARCH_ACTV_RPC_PASS_ARG(reg_info, __actv_local_var_reg_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_block_check_feature(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_block_check_feature(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_block_check_feature(unsigned long long __rpc_info, void *__buf, int idx, unsigned long long file_id, unsigned long long features)
{
	int __ret;
	int __maybe_unused __actv_local_var_idx = idx;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long long __maybe_unused __actv_local_var_features = features;
	__ret = ____actvcall_drvcall_devhost_block_check_feature(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(idx, __actv_local_var_idx), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(features, __actv_local_var_features));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_block_check_feature(rref_t __rref, unsigned long long __rpc_info, void *__buf, int idx, unsigned long long file_id, unsigned long long features)
{
	int __ret;
	int __maybe_unused __actv_local_var_idx = idx;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long long __maybe_unused __actv_local_var_features = features;
	__ret = ____actvcapcall_drvcall_devhost_block_check_feature(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(idx, __actv_local_var_idx), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(features, __actv_local_var_features));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_block_run_queue(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_block_run_queue(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_block_run_queue(unsigned long long __rpc_info, void *__buf, unsigned long file_id, unsigned int flags, unsigned int idx)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_idx = idx;
	__ret = ____actvcall_drvcall_devhost_block_run_queue(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(idx, __actv_local_var_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_block_run_queue(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long file_id, unsigned int flags, unsigned int idx)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_idx = idx;
	__ret = ____actvcapcall_drvcall_devhost_block_run_queue(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(idx, __actv_local_var_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_block_direct_access(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_block_direct_access(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_block_direct_access(unsigned long long __rpc_info, void *__buf, unsigned long file_id, unsigned long offset, unsigned long size)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long __maybe_unused __actv_local_var_offset = offset;
	unsigned long __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_drvcall_devhost_block_direct_access(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_block_direct_access(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long file_id, unsigned long offset, unsigned long size)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_file_id = file_id;
	unsigned long __maybe_unused __actv_local_var_offset = offset;
	unsigned long __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_drvcall_devhost_block_direct_access(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_block_register_bio_notify(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_block_register_bio_notify(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_block_register_bio_notify(unsigned long long __rpc_info, void *__buf, unsigned long file_id, uref_t uref, unsigned int method, size_t bd_shm_size)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_file_id = file_id;
	uref_t __maybe_unused __actv_local_var_uref = uref;
	unsigned int __maybe_unused __actv_local_var_method = method;
	size_t __maybe_unused __actv_local_var_bd_shm_size = bd_shm_size;
	__ret = ____actvcall_drvcall_devhost_block_register_bio_notify(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(uref, __actv_local_var_uref), __ARCH_ACTV_RPC_PASS_ARG(method, __actv_local_var_method), __ARCH_ACTV_RPC_PASS_ARG(bd_shm_size, __actv_local_var_bd_shm_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_block_register_bio_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long file_id, uref_t uref, unsigned int method, size_t bd_shm_size)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_file_id = file_id;
	uref_t __maybe_unused __actv_local_var_uref = uref;
	unsigned int __maybe_unused __actv_local_var_method = method;
	size_t __maybe_unused __actv_local_var_bd_shm_size = bd_shm_size;
	__ret = ____actvcapcall_drvcall_devhost_block_register_bio_notify(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id), __ARCH_ACTV_RPC_PASS_ARG(uref, __actv_local_var_uref), __ARCH_ACTV_RPC_PASS_ARG(method, __actv_local_var_method), __ARCH_ACTV_RPC_PASS_ARG(bd_shm_size, __actv_local_var_bd_shm_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_net_send(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_net_send(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_net_send(unsigned long long __rpc_info, void *__buf, int ifindex, unsigned int offset, unsigned int size, unsigned int payload_len, unsigned long flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	unsigned int __maybe_unused __actv_local_var_offset = offset;
	unsigned int __maybe_unused __actv_local_var_size = size;
	unsigned int __maybe_unused __actv_local_var_payload_len = payload_len;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_drvcall_devhost_net_send(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(payload_len, __actv_local_var_payload_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_net_send(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex, unsigned int offset, unsigned int size, unsigned int payload_len, unsigned long flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	unsigned int __maybe_unused __actv_local_var_offset = offset;
	unsigned int __maybe_unused __actv_local_var_size = size;
	unsigned int __maybe_unused __actv_local_var_payload_len = payload_len;
	unsigned long __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_drvcall_devhost_net_send(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(payload_len, __actv_local_var_payload_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_net_ioctl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_net_ioctl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_net_ioctl(unsigned long long __rpc_info, void *__buf, int ifindex, int request, unsigned long args)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	int __maybe_unused __actv_local_var_request = request;
	unsigned long __maybe_unused __actv_local_var_args = args;
	__ret = ____actvcall_drvcall_devhost_net_ioctl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(request, __actv_local_var_request), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_net_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex, int request, unsigned long args)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	int __maybe_unused __actv_local_var_request = request;
	unsigned long __maybe_unused __actv_local_var_args = args;
	__ret = ____actvcapcall_drvcall_devhost_net_ioctl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(request, __actv_local_var_request), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_net_status(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_net_status(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_net_status(unsigned long long __rpc_info, void *__buf, int ifindex)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	__ret = ____actvcall_drvcall_devhost_net_status(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_net_status(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	__ret = ____actvcapcall_drvcall_devhost_net_status(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_net_prepare(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_net_prepare(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_net_prepare(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devhost_net_prepare(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_net_prepare(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devhost_net_prepare(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_net_init(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_net_init(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_net_init(unsigned long long __rpc_info, void *__buf, int ifindex, rref_t tgt_rref)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	rref_t __maybe_unused __actv_local_var_tgt_rref = tgt_rref;
	__ret = ____actvcall_drvcall_devhost_net_init(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(tgt_rref, __actv_local_var_tgt_rref));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_net_init(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex, rref_t tgt_rref)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	rref_t __maybe_unused __actv_local_var_tgt_rref = tgt_rref;
	__ret = ____actvcapcall_drvcall_devhost_net_init(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(tgt_rref, __actv_local_var_tgt_rref));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_drvcall_devhost_net_netlink_recv(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_drvcall_devhost_net_netlink_recv(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_net_netlink_recv(unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid)
{
	int __ret;
	int __maybe_unused __actv_local_var_protocol = protocol;
	unsigned int __maybe_unused __actv_local_var_src_portid = src_portid;
	__ret = ____actvcall_drvcall_devhost_net_netlink_recv(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(src_portid, __actv_local_var_src_portid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_net_netlink_recv(rref_t __rref, unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid)
{
	int __ret;
	int __maybe_unused __actv_local_var_protocol = protocol;
	unsigned int __maybe_unused __actv_local_var_src_portid = src_portid;
	__ret = ____actvcapcall_drvcall_devhost_net_netlink_recv(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(src_portid, __actv_local_var_src_portid));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_pm_action(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_pm_action(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_pm_action(unsigned long long __rpc_info, void *__buf, unsigned int action)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_action = action;
	__ret = ____actvcall_drvcall_devhost_pm_action(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(action, __actv_local_var_action));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_pm_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int action)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_action = action;
	__ret = ____actvcapcall_drvcall_devhost_pm_action(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(action, __actv_local_var_action));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_pm_prepare(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_pm_prepare(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_pm_prepare(unsigned long long __rpc_info, void *__buf, unsigned int type, struct reboot_cmd cmd)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_type = type;
	struct reboot_cmd __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcall_drvcall_devhost_pm_prepare(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_pm_prepare(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int type, struct reboot_cmd cmd)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_type = type;
	struct reboot_cmd __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcapcall_drvcall_devhost_pm_prepare(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_pm_power_off(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_pm_power_off(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_pm_power_off(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devhost_pm_power_off(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_pm_power_off(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devhost_pm_power_off(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_pm_reboot(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_pm_reboot(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_pm_reboot(unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd)
{
	int __ret;
	struct reboot_cmd __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcall_drvcall_devhost_pm_reboot(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_pm_reboot(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd)
{
	int __ret;
	struct reboot_cmd __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcapcall_drvcall_devhost_pm_reboot(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_pm_cpuhp_action(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_pm_cpuhp_action(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_pm_cpuhp_action(unsigned long long __rpc_info, void *__buf, unsigned int cpu, unsigned int action)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cpu = cpu;
	unsigned int __maybe_unused __actv_local_var_action = action;
	__ret = ____actvcall_drvcall_devhost_pm_cpuhp_action(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cpu, __actv_local_var_cpu), __ARCH_ACTV_RPC_PASS_ARG(action, __actv_local_var_action));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_pm_cpuhp_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cpu, unsigned int action)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cpu = cpu;
	unsigned int __maybe_unused __actv_local_var_action = action;
	__ret = ____actvcapcall_drvcall_devhost_pm_cpuhp_action(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cpu, __actv_local_var_cpu), __ARCH_ACTV_RPC_PASS_ARG(action, __actv_local_var_action));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_procfs_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_procfs_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_procfs_read(unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_ubuf = ubuf;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	__ret = ____actvcall_drvcall_devhost_procfs_read(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_ubuf = ubuf;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	__ret = ____actvcapcall_drvcall_devhost_procfs_read(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_procfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_procfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_procfs_write(unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_ubuf = ubuf;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	__ret = ____actvcall_drvcall_devhost_procfs_write(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_ubuf = ubuf;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	__ret = ____actvcapcall_drvcall_devhost_procfs_write(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_sysfs_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_sysfs_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_sysfs_read(unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_ubuf = ubuf;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	__ret = ____actvcall_drvcall_devhost_sysfs_read(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_ubuf = ubuf;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	__ret = ____actvcapcall_drvcall_devhost_sysfs_read(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_sysfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_sysfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_sysfs_write(unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_ubuf = ubuf;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	__ret = ____actvcall_drvcall_devhost_sysfs_write(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, unsigned long long pos, struct hm_actv_buf ubuf, uintptr_t ctx)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_ubuf = ubuf;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	__ret = ____actvcapcall_drvcall_devhost_sysfs_write(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_sysfs_poll(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_sysfs_poll(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_sysfs_poll(unsigned long long __rpc_info, void *__buf, unsigned int tagid, uintptr_t ctx, bool pollable)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	bool __maybe_unused __actv_local_var_pollable = pollable;
	__ret = ____actvcall_drvcall_devhost_sysfs_poll(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx), __ARCH_ACTV_RPC_PASS_ARG(pollable, __actv_local_var_pollable));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_sysfs_poll(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int tagid, uintptr_t ctx, bool pollable)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_tagid = tagid;
	uintptr_t __maybe_unused __actv_local_var_ctx = ctx;
	bool __maybe_unused __actv_local_var_pollable = pollable;
	__ret = ____actvcapcall_drvcall_devhost_sysfs_poll(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx), __ARCH_ACTV_RPC_PASS_ARG(pollable, __actv_local_var_pollable));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_clock_settime(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_clock_settime(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_clock_settime(unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcall_drvcall_devhost_clock_settime(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_clock_settime(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcapcall_drvcall_devhost_clock_settime(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_clock_gettime(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_clock_gettime(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_clock_gettime(unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcall_drvcall_devhost_clock_gettime(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_clock_gettime(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcapcall_drvcall_devhost_clock_gettime(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_clock_getres(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_clock_getres(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_clock_getres(unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcall_drvcall_devhost_clock_getres(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_clock_getres(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long tp, unsigned long long file_id)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_tp = tp;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcapcall_drvcall_devhost_clock_getres(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tp, __actv_local_var_tp), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_clock_adjtime(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_clock_adjtime(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_clock_adjtime(unsigned long long __rpc_info, void *__buf, unsigned long tx, unsigned long long file_id)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_tx = tx;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcall_drvcall_devhost_clock_adjtime(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tx, __actv_local_var_tx), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_clock_adjtime(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long tx, unsigned long long file_id)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_tx = tx;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcapcall_drvcall_devhost_clock_adjtime(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tx, __actv_local_var_tx), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_mounted(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_mounted(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_mounted(unsigned long long __rpc_info, void *__buf, dev_t dev_id, int dev_mode, struct hm_actv_buf fs_name, struct hm_actv_buf mount_opts, size_t per_write_size, unsigned int sector_dentry_bits)
{
	int __ret;
	dev_t __maybe_unused __actv_local_var_dev_id = dev_id;
	int __maybe_unused __actv_local_var_dev_mode = dev_mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_fs_name = fs_name;
	struct hm_actv_buf __maybe_unused __actv_local_var_mount_opts = mount_opts;
	size_t __maybe_unused __actv_local_var_per_write_size = per_write_size;
	unsigned int __maybe_unused __actv_local_var_sector_dentry_bits = sector_dentry_bits;
	__ret = ____actvcall_drvcall_devhost_transfs_mounted(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(dev_mode, __actv_local_var_dev_mode), __ARCH_ACTV_RPC_PASS_ARG(fs_name, __actv_local_var_fs_name), __ARCH_ACTV_RPC_PASS_ARG(mount_opts, __actv_local_var_mount_opts), __ARCH_ACTV_RPC_PASS_ARG(per_write_size, __actv_local_var_per_write_size), __ARCH_ACTV_RPC_PASS_ARG(sector_dentry_bits, __actv_local_var_sector_dentry_bits));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_mounted(rref_t __rref, unsigned long long __rpc_info, void *__buf, dev_t dev_id, int dev_mode, struct hm_actv_buf fs_name, struct hm_actv_buf mount_opts, size_t per_write_size, unsigned int sector_dentry_bits)
{
	int __ret;
	dev_t __maybe_unused __actv_local_var_dev_id = dev_id;
	int __maybe_unused __actv_local_var_dev_mode = dev_mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_fs_name = fs_name;
	struct hm_actv_buf __maybe_unused __actv_local_var_mount_opts = mount_opts;
	size_t __maybe_unused __actv_local_var_per_write_size = per_write_size;
	unsigned int __maybe_unused __actv_local_var_sector_dentry_bits = sector_dentry_bits;
	__ret = ____actvcapcall_drvcall_devhost_transfs_mounted(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(dev_id, __actv_local_var_dev_id), __ARCH_ACTV_RPC_PASS_ARG(dev_mode, __actv_local_var_dev_mode), __ARCH_ACTV_RPC_PASS_ARG(fs_name, __actv_local_var_fs_name), __ARCH_ACTV_RPC_PASS_ARG(mount_opts, __actv_local_var_mount_opts), __ARCH_ACTV_RPC_PASS_ARG(per_write_size, __actv_local_var_per_write_size), __ARCH_ACTV_RPC_PASS_ARG(sector_dentry_bits, __actv_local_var_sector_dentry_bits));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_unmounted(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_unmounted(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_unmounted(unsigned long long __rpc_info, void *__buf, unsigned int s_index, int flags, unsigned long long file_id)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	int __maybe_unused __actv_local_var_flags = flags;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcall_drvcall_devhost_transfs_unmounted(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_unmounted(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, int flags, unsigned long long file_id)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	int __maybe_unused __actv_local_var_flags = flags;
	unsigned long long __maybe_unused __actv_local_var_file_id = file_id;
	__ret = ____actvcapcall_drvcall_devhost_transfs_unmounted(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(file_id, __actv_local_var_file_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_drop_caches(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_drop_caches(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_drop_caches(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int mode, int max_nr)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	int __maybe_unused __actv_local_var_max_nr = max_nr;
	__ret = ____actvcall_drvcall_devhost_transfs_drop_caches(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(max_nr, __actv_local_var_max_nr));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_drop_caches(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int mode, int max_nr)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	int __maybe_unused __actv_local_var_max_nr = max_nr;
	__ret = ____actvcapcall_drvcall_devhost_transfs_drop_caches(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(max_nr, __actv_local_var_max_nr));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_mkdir(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_mkdir(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_mkdir(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcall_drvcall_devhost_transfs_mkdir(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_mkdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcapcall_drvcall_devhost_transfs_mkdir(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_rmdir(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_rmdir(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_rmdir(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__ret = ____actvcall_drvcall_devhost_transfs_rmdir(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_rmdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__ret = ____actvcapcall_drvcall_devhost_transfs_rmdir(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_create(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_create(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_create(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcall_drvcall_devhost_transfs_create(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_create(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, mode_t mode, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcapcall_drvcall_devhost_transfs_create(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_unlink(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_unlink(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_unlink(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__ret = ____actvcall_drvcall_devhost_transfs_unlink(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_unlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int d_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__ret = ____actvcapcall_drvcall_devhost_transfs_unlink(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_mknod(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_mknod(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_mknod(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int mode, unsigned long long devno, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	unsigned long long __maybe_unused __actv_local_var_devno = devno;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcall_drvcall_devhost_transfs_mknod(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_mknod(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, unsigned int mode, unsigned long long devno, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	unsigned long long __maybe_unused __actv_local_var_devno = devno;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcapcall_drvcall_devhost_transfs_mknod(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_link(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_link(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_link(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_old_d_index = old_d_index;
	unsigned int __maybe_unused __actv_local_var_new_pd_index = new_pd_index;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcall_drvcall_devhost_transfs_link(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(old_d_index, __actv_local_var_old_d_index), __ARCH_ACTV_RPC_PASS_ARG(new_pd_index, __actv_local_var_new_pd_index), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_link(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_old_d_index = old_d_index;
	unsigned int __maybe_unused __actv_local_var_new_pd_index = new_pd_index;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcapcall_drvcall_devhost_transfs_link(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(old_d_index, __actv_local_var_old_d_index), __ARCH_ACTV_RPC_PASS_ARG(new_pd_index, __actv_local_var_new_pd_index), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_symlink(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_symlink(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_symlink(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, struct hm_actv_buf actv_dname, struct hm_actv_buf actv_path)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_path = actv_path;
	__ret = ____actvcall_drvcall_devhost_transfs_symlink(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname), __ARCH_ACTV_RPC_PASS_ARG(actv_path, __actv_local_var_actv_path));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_symlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_index, struct hm_actv_buf actv_dname, struct hm_actv_buf actv_path)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_path = actv_path;
	__ret = ____actvcapcall_drvcall_devhost_transfs_symlink(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname), __ARCH_ACTV_RPC_PASS_ARG(actv_path, __actv_local_var_actv_path));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_statfs(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_statfs(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_statfs(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, void *buf)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused void *__actv_local_var_buf = buf;
	__ret = ____actvcall_drvcall_devhost_transfs_statfs(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_statfs(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, void *buf)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused void *__actv_local_var_buf = buf;
	__ret = ____actvcapcall_drvcall_devhost_transfs_statfs(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_rename(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_rename(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_rename(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int old_pd_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_old_pd_index = old_pd_index;
	unsigned int __maybe_unused __actv_local_var_old_d_index = old_d_index;
	unsigned int __maybe_unused __actv_local_var_new_pd_index = new_pd_index;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcall_drvcall_devhost_transfs_rename(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(old_pd_index, __actv_local_var_old_pd_index), __ARCH_ACTV_RPC_PASS_ARG(old_d_index, __actv_local_var_old_d_index), __ARCH_ACTV_RPC_PASS_ARG(new_pd_index, __actv_local_var_new_pd_index), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_rename(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int old_pd_index, unsigned int old_d_index, unsigned int new_pd_index, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_old_pd_index = old_pd_index;
	unsigned int __maybe_unused __actv_local_var_old_d_index = old_d_index;
	unsigned int __maybe_unused __actv_local_var_new_pd_index = new_pd_index;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcapcall_drvcall_devhost_transfs_rename(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(old_pd_index, __actv_local_var_old_pd_index), __ARCH_ACTV_RPC_PASS_ARG(old_d_index, __actv_local_var_old_d_index), __ARCH_ACTV_RPC_PASS_ARG(new_pd_index, __actv_local_var_new_pd_index), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_lookup(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_lookup(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_lookup(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int pd_index, struct hm_actv_buf actv_dname, void *meta)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__maybe_unused void *__actv_local_var_meta = meta;
	__ret = ____actvcall_drvcall_devhost_transfs_lookup(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname), __ARCH_ACTV_RPC_PASS_ARG(meta, __actv_local_var_meta));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_lookup(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int pd_index, struct hm_actv_buf actv_dname, void *meta)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_pd_index = pd_index;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__maybe_unused void *__actv_local_var_meta = meta;
	__ret = ____actvcapcall_drvcall_devhost_transfs_lookup(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(pd_index, __actv_local_var_pd_index), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname), __ARCH_ACTV_RPC_PASS_ARG(meta, __actv_local_var_meta));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_setattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_setattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_setattr(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, const void *attr, uint64_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused const void *__actv_local_var_attr = attr;
	uint64_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_drvcall_devhost_transfs_setattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(attr, __actv_local_var_attr), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_setattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, const void *attr, uint64_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused const void *__actv_local_var_attr = attr;
	uint64_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_drvcall_devhost_transfs_setattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(attr, __actv_local_var_attr), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_readlink(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_readlink(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_readlink(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, char *buf, size_t bufsize)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused char *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_bufsize = bufsize;
	__ret = ____actvcall_drvcall_devhost_transfs_readlink(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(bufsize, __actv_local_var_bufsize));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_readlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, char *buf, size_t bufsize)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused char *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_bufsize = bufsize;
	__ret = ____actvcapcall_drvcall_devhost_transfs_readlink(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(bufsize, __actv_local_var_bufsize));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_getattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_getattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_getattr(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, void *meta)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused void *__actv_local_var_meta = meta;
	__ret = ____actvcall_drvcall_devhost_transfs_getattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(meta, __actv_local_var_meta));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_getattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, void *meta)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused void *__actv_local_var_meta = meta;
	__ret = ____actvcapcall_drvcall_devhost_transfs_getattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(meta, __actv_local_var_meta));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_listxattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_listxattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_listxattr(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, char *buffer, size_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused char *__actv_local_var_buffer = buffer;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_drvcall_devhost_transfs_listxattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(buffer, __actv_local_var_buffer), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_listxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, char *buffer, size_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__maybe_unused char *__actv_local_var_buffer = buffer;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_drvcall_devhost_transfs_listxattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(buffer, __actv_local_var_buffer), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_getxattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_getxattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_getxattr(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, char *value, size_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	int __maybe_unused __actv_local_var_prefix = prefix;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_name = actv_name;
	__maybe_unused char *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_drvcall_devhost_transfs_getxattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(prefix, __actv_local_var_prefix), __ARCH_ACTV_RPC_PASS_ARG(actv_name, __actv_local_var_actv_name), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_getxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, char *value, size_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	int __maybe_unused __actv_local_var_prefix = prefix;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_name = actv_name;
	__maybe_unused char *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_drvcall_devhost_transfs_getxattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(prefix, __actv_local_var_prefix), __ARCH_ACTV_RPC_PASS_ARG(actv_name, __actv_local_var_actv_name), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_setxattr(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_setxattr(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_setxattr(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, const char *value, size_t size, int flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	int __maybe_unused __actv_local_var_prefix = prefix;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_name = actv_name;
	__maybe_unused const char *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_drvcall_devhost_transfs_setxattr(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(prefix, __actv_local_var_prefix), __ARCH_ACTV_RPC_PASS_ARG(actv_name, __actv_local_var_actv_name), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_setxattr(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index, int prefix, struct hm_actv_buf actv_name, const char *value, size_t size, int flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	int __maybe_unused __actv_local_var_prefix = prefix;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_name = actv_name;
	__maybe_unused const char *__actv_local_var_value = value;
	size_t __maybe_unused __actv_local_var_size = size;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_drvcall_devhost_transfs_setxattr(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(prefix, __actv_local_var_prefix), __ARCH_ACTV_RPC_PASS_ARG(actv_name, __actv_local_var_actv_name), __ARCH_ACTV_RPC_PASS_ARG(value, __actv_local_var_value), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_tmpfile(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_tmpfile(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_tmpfile(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_addr, mode_t mode, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_addr = pd_addr;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcall_drvcall_devhost_transfs_tmpfile(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_addr, __actv_local_var_pd_addr), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_tmpfile(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int pd_addr, mode_t mode, struct hm_actv_buf actv_dname)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_pd_addr = pd_addr;
	mode_t __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_dname = actv_dname;
	__ret = ____actvcapcall_drvcall_devhost_transfs_tmpfile(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(pd_addr, __actv_local_var_pd_addr), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(actv_dname, __actv_local_var_actv_dname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_kill_dentry(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_kill_dentry(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_kill_dentry(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__ret = ____actvcall_drvcall_devhost_transfs_kill_dentry(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_kill_dentry(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int d_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	__ret = ____actvcapcall_drvcall_devhost_transfs_kill_dentry(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_node_put(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_node_put(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_node_put(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int v_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_v_index = v_index;
	__ret = ____actvcall_drvcall_devhost_transfs_node_put(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(v_index, __actv_local_var_v_index));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_node_put(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int v_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_v_index = v_index;
	__ret = ____actvcapcall_drvcall_devhost_transfs_node_put(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(v_index, __actv_local_var_v_index));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_sync(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_sync(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_sync(unsigned long long __rpc_info, void *__buf, unsigned int s_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	__ret = ____actvcall_drvcall_devhost_transfs_sync(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_sync(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	__ret = ____actvcapcall_drvcall_devhost_transfs_sync(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_write(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, uint64_t pos, const void *src, size_t len)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	uint64_t __maybe_unused __actv_local_var_pos = pos;
	__maybe_unused const void *__actv_local_var_src = src;
	size_t __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcall_drvcall_devhost_transfs_write(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(src, __actv_local_var_src), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, uint64_t pos, const void *src, size_t len)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	uint64_t __maybe_unused __actv_local_var_pos = pos;
	__maybe_unused const void *__actv_local_var_src = src;
	size_t __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcapcall_drvcall_devhost_transfs_write(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(src, __actv_local_var_src), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_fsync(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_fsync(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_fsync(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	__ret = ____actvcall_drvcall_devhost_transfs_fsync(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_fsync(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	__ret = ____actvcapcall_drvcall_devhost_transfs_fsync(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_readdir(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_readdir(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_readdir(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int f_index, uint64_t pos, void *buf, size_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	uint64_t __maybe_unused __actv_local_var_pos = pos;
	__maybe_unused void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_drvcall_devhost_transfs_readdir(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_readdir(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int f_index, uint64_t pos, void *buf, size_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	uint64_t __maybe_unused __actv_local_var_pos = pos;
	__maybe_unused void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_drvcall_devhost_transfs_readdir(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_open(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_open(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_open(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, unsigned int f_modes, unsigned int f_flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	unsigned int __maybe_unused __actv_local_var_f_modes = f_modes;
	unsigned int __maybe_unused __actv_local_var_f_flags = f_flags;
	__ret = ____actvcall_drvcall_devhost_transfs_open(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(f_modes, __actv_local_var_f_modes), __ARCH_ACTV_RPC_PASS_ARG(f_flags, __actv_local_var_f_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int d_index, unsigned int f_modes, unsigned int f_flags)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_d_index = d_index;
	unsigned int __maybe_unused __actv_local_var_f_modes = f_modes;
	unsigned int __maybe_unused __actv_local_var_f_flags = f_flags;
	__ret = ____actvcapcall_drvcall_devhost_transfs_open(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(d_index, __actv_local_var_d_index), __ARCH_ACTV_RPC_PASS_ARG(f_modes, __actv_local_var_f_modes), __ARCH_ACTV_RPC_PASS_ARG(f_flags, __actv_local_var_f_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_fallocate(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_fallocate(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_fallocate(unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int f_index, unsigned int mode, uint64_t pos, uint64_t len)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	uint64_t __maybe_unused __actv_local_var_pos = pos;
	uint64_t __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcall_drvcall_devhost_transfs_fallocate(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_fallocate(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int sb_index, unsigned int f_index, unsigned int mode, uint64_t pos, uint64_t len)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_sb_index = sb_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	uint64_t __maybe_unused __actv_local_var_pos = pos;
	uint64_t __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcapcall_drvcall_devhost_transfs_fallocate(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sb_index, __actv_local_var_sb_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_close(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_close(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_close(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	__ret = ____actvcall_drvcall_devhost_transfs_close(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	__ret = ____actvcapcall_drvcall_devhost_transfs_close(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_ioctl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_ioctl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_ioctl(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, unsigned int cmd, unsigned long arg)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	unsigned int __maybe_unused __actv_local_var_cmd = cmd;
	unsigned long __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcall_drvcall_devhost_transfs_ioctl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, unsigned int cmd, unsigned long arg)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	unsigned int __maybe_unused __actv_local_var_cmd = cmd;
	unsigned long __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcapcall_drvcall_devhost_transfs_ioctl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devhost_transfs_direct_IO(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devhost_transfs_direct_IO(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_direct_IO(unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, uint64_t offset, void *buf, size_t len, unsigned int type)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	uint64_t __maybe_unused __actv_local_var_offset = offset;
	__maybe_unused void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcall_drvcall_devhost_transfs_direct_IO(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_direct_IO(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, unsigned int f_index, uint64_t offset, void *buf, size_t len, unsigned int type)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	unsigned int __maybe_unused __actv_local_var_f_index = f_index;
	uint64_t __maybe_unused __actv_local_var_offset = offset;
	__maybe_unused void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_len = len;
	unsigned int __maybe_unused __actv_local_var_type = type;
	__ret = ____actvcapcall_drvcall_devhost_transfs_direct_IO(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(f_index, __actv_local_var_f_index), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devhost_transfs_update_opts(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devhost_transfs_update_opts(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devhost_transfs_update_opts(unsigned long long __rpc_info, void *__buf, unsigned int s_index, char *ubuf, size_t buflen)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	__maybe_unused char *__actv_local_var_ubuf = ubuf;
	size_t __maybe_unused __actv_local_var_buflen = buflen;
	__ret = ____actvcall_drvcall_devhost_transfs_update_opts(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(buflen, __actv_local_var_buflen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devhost_transfs_update_opts(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int s_index, char *ubuf, size_t buflen)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_s_index = s_index;
	__maybe_unused char *__actv_local_var_ubuf = ubuf;
	size_t __maybe_unused __actv_local_var_buflen = buflen;
	__ret = ____actvcapcall_drvcall_devhost_transfs_update_opts(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(s_index, __actv_local_var_s_index), __ARCH_ACTV_RPC_PASS_ARG(ubuf, __actv_local_var_ubuf), __ARCH_ACTV_RPC_PASS_ARG(buflen, __actv_local_var_buflen));
	return __ret;
}

#endif
#endif
