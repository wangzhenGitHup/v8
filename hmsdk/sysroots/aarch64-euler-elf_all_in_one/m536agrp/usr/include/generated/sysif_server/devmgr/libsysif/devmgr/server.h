/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for devmgr
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/devmgr/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/devmgr/libsysif/devmgr/api.h --server-dest ../image/usr/include/generated/sysif_server/devmgr/libsysif/devmgr/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_DEVMGR_SERVER_H
#define LIBSYSIF_DEVMGR_SERVER_H
#ifndef LIBSYSIF_DEVMGR_COMMON_H
#define LIBSYSIF_DEVMGR_COMMON_H
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
#include <libbunch/bunch_ipc.h>
#include <libsysif/devmgr/types.h>

#define DEVMGR_PATH	"devmgr.actv"

#define RESOURCE_COUNT_MAX    128

raw_static_assert(sizeof(uref_t) <= 96,
                    drvcall_devmgr_core_register_devhost_arg_ap_uref_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_core_register_devhost_arg_group_is_too_large);
raw_static_assert(sizeof(uref_t) <= 96,
                    drvcall_devmgr_core_register_devhost_arg_devmgr_ap_uref_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_core_device_add_arg_devname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_core_device_add_arg_devnode_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_core_device_add_arg_group_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_core_request_module_arg_modname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_core_request_module_arg_args_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_chrdev_register_region_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_blkdev_register_region_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_blkdev_unregister_region_arg_name_is_too_large);
raw_static_assert(sizeof(rref_t) <= 96,
                    drvcall_devmgr_fops_open_arg_tgt_rref_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_mgmt_load_module_arg_modname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_mgmt_load_module_arg_modargs_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_mgmt_unload_module_arg_modname_is_too_large);
raw_static_assert(sizeof(struct bunch_ipc_attr) <= 96,
                    drvcall_devmgr_mgmt_dump_arg_attr_is_too_large);
raw_static_assert(sizeof(struct drvcall_devmgr_irq_map_arg) <= 96,
                    drvcall_devmgr_irq_map_arg_arg_is_too_large);
raw_static_assert(sizeof(struct drvcall_devmgr_irq_fetch_arg) <= 96,
                    drvcall_devmgr_irq_fetch_arg_arg_is_too_large);
raw_static_assert(sizeof(struct drvcall_devmgr_irq_return_arg) <= 96,
                    drvcall_devmgr_irq_return_arg_arg_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_net_register_arg_name_is_too_large);
raw_static_assert(sizeof(rref_t) <= 96,
                    drvcall_devmgr_net_open_arg_tgt_rref_is_too_large);
raw_static_assert(sizeof(struct reboot_cmd) <= 96,
                    drvcall_devmgr_pm_reboot_arg_cmd_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_procfs_create_data_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_procfs_create_data_arg_ops_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_procfs_create_data_arg_linkname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_procfs_unlink_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_sysfs_create_dir_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_sysfs_create_file_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_sysfs_create_symlink_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_sysfs_create_symlink_arg_linkname_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_sysfs_delete_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_sysfs_notify_arg_name_is_too_large);
raw_static_assert(sizeof(struct hm_actv_buf) <= 96,
                    drvcall_devmgr_sysfs_write_arg_actv_buf_is_too_large);
struct __actvret_drvcall_devmgr_core_register_devhost {
};

struct __actvret_drvcall_devmgr_core_devhost_init_done {
};

struct __actvret_drvcall_devmgr_core_device_add {
	int devid;
};

struct __actvret_drvcall_devmgr_core_device_del {
};

struct __actvret_drvcall_devmgr_core_request_module {
};

struct __actvret_drvcall_devmgr_chrdev_register_region {
	unsigned int major;
};

struct __actvret_drvcall_devmgr_chrdev_unregister_region {
};

struct __actvret_drvcall_devmgr_blkdev_register_region {
	unsigned int major;
};

struct __actvret_drvcall_devmgr_blkdev_unregister_region {
};

struct __actvret_drvcall_devmgr_fops_open {
	unsigned long long filp;
};

struct __actvret_drvcall_devmgr_mgmt_load_module {
};

struct __actvret_drvcall_devmgr_mgmt_unload_module {
};

struct __actvret_drvcall_devmgr_mgmt_sync {
};

struct __actvret_drvcall_devmgr_mgmt_dump {
	unsigned int pos_end;
};

struct __actvret_drvcall_devmgr_irq_map {
	unsigned int virt_irq;
};

struct __actvret_drvcall_devmgr_irq_fetch {
	struct drvcall_devmgr_irq_fetch_rlt rlt;
};

struct __actvret_drvcall_devmgr_irq_return {
};

struct __actvret_drvcall_devmgr_net_alloc_ifindex {
	int ifindex;
};

struct __actvret_drvcall_devmgr_net_register {
	int ifindex;
};

struct __actvret_drvcall_devmgr_net_unregister {
};

struct __actvret_drvcall_devmgr_net_hmnetd_ready {
};

struct __actvret_drvcall_devmgr_net_open {
};

struct __actvret_drvcall_devmgr_pm_action {
};

struct __actvret_drvcall_devmgr_pm_power_off {
};

struct __actvret_drvcall_devmgr_pm_reboot {
};

struct __actvret_drvcall_devmgr_pm_cpuhp_action {
};

struct __actvret_drvcall_devmgr_procfs_create_data {
};

struct __actvret_drvcall_devmgr_procfs_unlink {
};

struct __actvret_drvcall_devmgr_procfs_read {
};

struct __actvret_drvcall_devmgr_procfs_write {
};

struct __actvret_drvcall_devmgr_sysfs_create_dir {
};

struct __actvret_drvcall_devmgr_sysfs_create_file {
};

struct __actvret_drvcall_devmgr_sysfs_create_symlink {
};

struct __actvret_drvcall_devmgr_sysfs_delete {
	int tagid;
};

struct __actvret_drvcall_devmgr_sysfs_notify {
};

struct __actvret_drvcall_devmgr_sysfs_read {
};

struct __actvret_drvcall_devmgr_sysfs_write {
};

struct __actvret_drvcall_devmgr_sysfs_poll {
};

struct __actvret_drvcall_devmgr_fw_acquire_contents {
	unsigned int rsize;
};

union __actvret_drvcall_devmgr {
	struct __actvret_drvcall_devmgr_core_register_devhost core_register_devhost;
	struct __actvret_drvcall_devmgr_core_devhost_init_done core_devhost_init_done;
	struct __actvret_drvcall_devmgr_core_device_add core_device_add;
	struct __actvret_drvcall_devmgr_core_device_del core_device_del;
	struct __actvret_drvcall_devmgr_core_request_module core_request_module;
	struct __actvret_drvcall_devmgr_chrdev_register_region chrdev_register_region;
	struct __actvret_drvcall_devmgr_chrdev_unregister_region chrdev_unregister_region;
	struct __actvret_drvcall_devmgr_blkdev_register_region blkdev_register_region;
	struct __actvret_drvcall_devmgr_blkdev_unregister_region blkdev_unregister_region;
	struct __actvret_drvcall_devmgr_fops_open fops_open;
	struct __actvret_drvcall_devmgr_mgmt_load_module mgmt_load_module;
	struct __actvret_drvcall_devmgr_mgmt_unload_module mgmt_unload_module;
	struct __actvret_drvcall_devmgr_mgmt_sync mgmt_sync;
	struct __actvret_drvcall_devmgr_mgmt_dump mgmt_dump;
	struct __actvret_drvcall_devmgr_irq_map irq_map;
	struct __actvret_drvcall_devmgr_irq_fetch irq_fetch;
	struct __actvret_drvcall_devmgr_irq_return irq_return;
	struct __actvret_drvcall_devmgr_net_alloc_ifindex net_alloc_ifindex;
	struct __actvret_drvcall_devmgr_net_register net_register;
	struct __actvret_drvcall_devmgr_net_unregister net_unregister;
	struct __actvret_drvcall_devmgr_net_hmnetd_ready net_hmnetd_ready;
	struct __actvret_drvcall_devmgr_net_open net_open;
	struct __actvret_drvcall_devmgr_pm_action pm_action;
	struct __actvret_drvcall_devmgr_pm_power_off pm_power_off;
	struct __actvret_drvcall_devmgr_pm_reboot pm_reboot;
	struct __actvret_drvcall_devmgr_pm_cpuhp_action pm_cpuhp_action;
	struct __actvret_drvcall_devmgr_procfs_create_data procfs_create_data;
	struct __actvret_drvcall_devmgr_procfs_unlink procfs_unlink;
	struct __actvret_drvcall_devmgr_procfs_read procfs_read;
	struct __actvret_drvcall_devmgr_procfs_write procfs_write;
	struct __actvret_drvcall_devmgr_sysfs_create_dir sysfs_create_dir;
	struct __actvret_drvcall_devmgr_sysfs_create_file sysfs_create_file;
	struct __actvret_drvcall_devmgr_sysfs_create_symlink sysfs_create_symlink;
	struct __actvret_drvcall_devmgr_sysfs_delete sysfs_delete;
	struct __actvret_drvcall_devmgr_sysfs_notify sysfs_notify;
	struct __actvret_drvcall_devmgr_sysfs_read sysfs_read;
	struct __actvret_drvcall_devmgr_sysfs_write sysfs_write;
	struct __actvret_drvcall_devmgr_sysfs_poll sysfs_poll;
	struct __actvret_drvcall_devmgr_fw_acquire_contents fw_acquire_contents;
};

enum __devmgr_mgr {
	__devmgr_INVAL_mgr=0,
	__devmgr_core_mgr,
	__devmgr_chrdev_mgr,
	__devmgr_blkdev_mgr,
	__devmgr_fops_mgr,
	__devmgr_mgmt_mgr,
	__devmgr_irq_mgr,
	__devmgr_net_mgr,
	__devmgr_pm_mgr,
	__devmgr_procfs_mgr,
	__devmgr_sysfs_mgr,
	__devmgr_fw_mgr,
	__devmgr_MAX_mgr,
};

#define __devmgr_method_MIN __ACTV_HIGHTABLE_START
#define __devmgr_method_core_register_devhost (__ACTV_HIGHTABLE_START + 1)
#define __devmgr_method_core_devhost_init_done (__ACTV_HIGHTABLE_START + 2)
#define __devmgr_method_core_device_add (__ACTV_HIGHTABLE_START + 3)
#define __devmgr_method_core_device_del (__ACTV_HIGHTABLE_START + 4)
#define __devmgr_method_core_request_module (__ACTV_HIGHTABLE_START + 5)
#define __devmgr_method_core_rsvd_3 (__ACTV_HIGHTABLE_START + 6)
#define __devmgr_method_core_rsvd_2 (__ACTV_HIGHTABLE_START + 7)
#define __devmgr_method_core_rsvd_1 (__ACTV_HIGHTABLE_START + 8)
#define __devmgr_method_chrdev_register_region (__ACTV_HIGHTABLE_START + 9)
#define __devmgr_method_chrdev_unregister_region (__ACTV_HIGHTABLE_START + 10)
#define __devmgr_method_chrdev_rsvd_2 (__ACTV_HIGHTABLE_START + 11)
#define __devmgr_method_chrdev_rsvd_1 (__ACTV_HIGHTABLE_START + 12)
#define __devmgr_method_blkdev_register_region (__ACTV_HIGHTABLE_START + 13)
#define __devmgr_method_blkdev_unregister_region (__ACTV_HIGHTABLE_START + 14)
#define __devmgr_method_blkdev_rsvd_2 (__ACTV_HIGHTABLE_START + 15)
#define __devmgr_method_blkdev_rsvd_1 (__ACTV_HIGHTABLE_START + 16)
#define __devmgr_method_fops_open (__ACTV_HIGHTABLE_START + 17)
#define __devmgr_method_fops_rsvd_1 (__ACTV_HIGHTABLE_START + 18)
#define __devmgr_method_mgmt_load_module (__ACTV_HIGHTABLE_START + 19)
#define __devmgr_method_mgmt_unload_module (__ACTV_HIGHTABLE_START + 20)
#define __devmgr_method_mgmt_sync (__ACTV_HIGHTABLE_START + 21)
#define __devmgr_method_mgmt_dump (__ACTV_HIGHTABLE_START + 22)
#define __devmgr_method_mgmt_rsvd_4 (__ACTV_HIGHTABLE_START + 23)
#define __devmgr_method_mgmt_rsvd_3 (__ACTV_HIGHTABLE_START + 24)
#define __devmgr_method_mgmt_rsvd_2 (__ACTV_HIGHTABLE_START + 25)
#define __devmgr_method_mgmt_rsvd_1 (__ACTV_HIGHTABLE_START + 26)
#define __devmgr_method_irq_map (__ACTV_HIGHTABLE_START + 27)
#define __devmgr_method_irq_fetch (__ACTV_HIGHTABLE_START + 28)
#define __devmgr_method_irq_return (__ACTV_HIGHTABLE_START + 29)
#define __devmgr_method_irq_rsvd_1 (__ACTV_HIGHTABLE_START + 30)
#define __devmgr_method_net_alloc_ifindex (__ACTV_HIGHTABLE_START + 31)
#define __devmgr_method_net_register (__ACTV_HIGHTABLE_START + 32)
#define __devmgr_method_net_unregister (__ACTV_HIGHTABLE_START + 33)
#define __devmgr_method_net_hmnetd_ready (__ACTV_HIGHTABLE_START + 34)
#define __devmgr_method_net_open (__ACTV_HIGHTABLE_START + 35)
#define __devmgr_method_net_rsvd_3 (__ACTV_HIGHTABLE_START + 36)
#define __devmgr_method_net_rsvd_2 (__ACTV_HIGHTABLE_START + 37)
#define __devmgr_method_net_rsvd_1 (__ACTV_HIGHTABLE_START + 38)
#define __devmgr_method_pm_action (__ACTV_HIGHTABLE_START + 39)
#define __devmgr_method_pm_power_off (__ACTV_HIGHTABLE_START + 40)
#define __devmgr_method_pm_reboot (__ACTV_HIGHTABLE_START + 41)
#define __devmgr_method_pm_cpuhp_action (__ACTV_HIGHTABLE_START + 42)
#define __devmgr_method_procfs_create_data (__ACTV_HIGHTABLE_START + 43)
#define __devmgr_method_procfs_unlink (__ACTV_HIGHTABLE_START + 44)
#define __devmgr_method_procfs_read (__ACTV_HIGHTABLE_START + 45)
#define __devmgr_method_procfs_write (__ACTV_HIGHTABLE_START + 46)
#define __devmgr_method_sysfs_create_dir (__ACTV_HIGHTABLE_START + 47)
#define __devmgr_method_sysfs_create_file (__ACTV_HIGHTABLE_START + 48)
#define __devmgr_method_sysfs_create_symlink (__ACTV_HIGHTABLE_START + 49)
#define __devmgr_method_sysfs_delete (__ACTV_HIGHTABLE_START + 50)
#define __devmgr_method_sysfs_notify (__ACTV_HIGHTABLE_START + 51)
#define __devmgr_method_sysfs_read (__ACTV_HIGHTABLE_START + 52)
#define __devmgr_method_sysfs_write (__ACTV_HIGHTABLE_START + 53)
#define __devmgr_method_sysfs_poll (__ACTV_HIGHTABLE_START + 54)
#define __devmgr_method_fw_acquire_contents (__ACTV_HIGHTABLE_START + 55)
#define __devmgr_method_fw_rsvd_1 (__ACTV_HIGHTABLE_START + 56)
#define __devmgr_method_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + 57)
#define __devmgr_method_MAX_COMPAT ((__ACTV_HIGHTABLE_START + 57) * 2)
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_core_register_devhost) < 512,
                drvcall_devmgr_core_register_devhost_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_core_devhost_init_done) < 512,
                drvcall_devmgr_core_devhost_init_done_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_core_device_add) < 512,
                drvcall_devmgr_core_device_add_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_core_device_del) < 512,
                drvcall_devmgr_core_device_del_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_core_request_module) < 512,
                drvcall_devmgr_core_request_module_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_chrdev_register_region) < 512,
                drvcall_devmgr_chrdev_register_region_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_chrdev_unregister_region) < 512,
                drvcall_devmgr_chrdev_unregister_region_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_blkdev_register_region) < 512,
                drvcall_devmgr_blkdev_register_region_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_blkdev_unregister_region) < 512,
                drvcall_devmgr_blkdev_unregister_region_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_fops_open) < 512,
                drvcall_devmgr_fops_open_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_mgmt_load_module) < 512,
                drvcall_devmgr_mgmt_load_module_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_mgmt_unload_module) < 512,
                drvcall_devmgr_mgmt_unload_module_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_mgmt_sync) < 512,
                drvcall_devmgr_mgmt_sync_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_mgmt_dump) < 512,
                drvcall_devmgr_mgmt_dump_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_irq_map) < 512,
                drvcall_devmgr_irq_map_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_irq_fetch) < 512,
                drvcall_devmgr_irq_fetch_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_irq_return) < 512,
                drvcall_devmgr_irq_return_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_net_alloc_ifindex) < 512,
                drvcall_devmgr_net_alloc_ifindex_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_net_register) < 512,
                drvcall_devmgr_net_register_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_net_unregister) < 512,
                drvcall_devmgr_net_unregister_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_net_hmnetd_ready) < 512,
                drvcall_devmgr_net_hmnetd_ready_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_net_open) < 512,
                drvcall_devmgr_net_open_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_pm_action) < 512,
                drvcall_devmgr_pm_action_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_pm_power_off) < 512,
                drvcall_devmgr_pm_power_off_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_pm_reboot) < 512,
                drvcall_devmgr_pm_reboot_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_pm_cpuhp_action) < 512,
                drvcall_devmgr_pm_cpuhp_action_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_procfs_create_data) < 512,
                drvcall_devmgr_procfs_create_data_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_procfs_unlink) < 512,
                drvcall_devmgr_procfs_unlink_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_procfs_read) < 512,
                drvcall_devmgr_procfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_procfs_write) < 512,
                drvcall_devmgr_procfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_sysfs_create_dir) < 512,
                drvcall_devmgr_sysfs_create_dir_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_sysfs_create_file) < 512,
                drvcall_devmgr_sysfs_create_file_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_sysfs_create_symlink) < 512,
                drvcall_devmgr_sysfs_create_symlink_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_sysfs_delete) < 512,
                drvcall_devmgr_sysfs_delete_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_sysfs_notify) < 512,
                drvcall_devmgr_sysfs_notify_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_sysfs_read) < 512,
                drvcall_devmgr_sysfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_sysfs_write) < 512,
                drvcall_devmgr_sysfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_sysfs_poll) < 512,
                drvcall_devmgr_sysfs_poll_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_drvcall_devmgr_fw_acquire_contents) < 512,
                drvcall_devmgr_fw_acquire_contents_too_many_actvret_data);
raw_static_assert(sizeof(union __actvret_drvcall_devmgr) < 512,
        drvcall_devmgr_too_many_actvret_data);
extern int __actvcall_drvcall_devmgr_core_register_devhost(unsigned long long __rpc_info, void *__buf, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);


extern int __actvcapcall_drvcall_devmgr_core_register_devhost(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_core_register_devhost(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	const unsigned long __callno = __devmgr_method_core_register_devhost;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_core_register_devhost(rpc_info, NULL, flags, ap_uref, group, devmgr_ap_uref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_core_register_devhost(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	const unsigned long __callno = __devmgr_method_core_register_devhost;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_core_register_devhost(__rref, rpc_info, NULL, flags, ap_uref, group, devmgr_ap_uref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_core_register_devhost(unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	return actvxactcall_drvcall_devmgr_core_register_devhost(false, false, flags, ap_uref, group, devmgr_ap_uref);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_core_register_devhost(rref_t __rref, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	return actvxactcapcall_drvcall_devmgr_core_register_devhost(false, false, __rref, flags, ap_uref, group, devmgr_ap_uref);
}

extern int __actvcall_drvcall_devmgr_core_devhost_init_done(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devmgr_core_devhost_init_done(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_core_devhost_init_done(bool is_xact_fwd, bool is_xact_allow_refwd)
{
	const unsigned long __callno = __devmgr_method_core_devhost_init_done;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_core_devhost_init_done(rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_core_devhost_init_done(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref)
{
	const unsigned long __callno = __devmgr_method_core_devhost_init_done;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_core_devhost_init_done(__rref, rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_core_devhost_init_done(void)
{
	return actvxactcall_drvcall_devmgr_core_devhost_init_done(false, false);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_core_devhost_init_done(rref_t __rref)
{
	return actvxactcapcall_drvcall_devmgr_core_devhost_init_done(false, false, __rref);
}

extern int __actvcall_drvcall_devmgr_core_device_add(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);


extern int __actvcapcall_drvcall_devmgr_core_device_add(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_core_device_add(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_drvcall_devmgr_core_device_add *__ret)
{
	const unsigned long __callno = __devmgr_method_core_device_add;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_core_device_add(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, devname, devnode_name, parent, flags, devt, vfs_mode, group);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_core_device_add(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_drvcall_devmgr_core_device_add *__ret)
{
	const unsigned long __callno = __devmgr_method_core_device_add;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_core_device_add(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, devname, devnode_name, parent, flags, devt, vfs_mode, group);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_core_device_add(struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_drvcall_devmgr_core_device_add *__ret)
{
	return actvxactcall_drvcall_devmgr_core_device_add(false, false, devname, devnode_name, parent, flags, devt, vfs_mode, group, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_core_device_add(rref_t __rref, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_drvcall_devmgr_core_device_add *__ret)
{
	return actvxactcapcall_drvcall_devmgr_core_device_add(false, false, __rref, devname, devnode_name, parent, flags, devt, vfs_mode, group, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_drvcall_devmgr_core_device_del(unsigned long long __rpc_info, void *__buf, int devid);


extern int __actvcapcall_drvcall_devmgr_core_device_del(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_core_device_del(bool is_xact_fwd, bool is_xact_allow_refwd, int devid)
{
	const unsigned long __callno = __devmgr_method_core_device_del;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_core_device_del(rpc_info, NULL, devid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_core_device_del(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int devid)
{
	const unsigned long __callno = __devmgr_method_core_device_del;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_core_device_del(__rref, rpc_info, NULL, devid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_core_device_del(int devid)
{
	return actvxactcall_drvcall_devmgr_core_device_del(false, false, devid);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_core_device_del(rref_t __rref, int devid)
{
	return actvxactcapcall_drvcall_devmgr_core_device_del(false, false, __rref, devid);
}

extern int __actvcall_drvcall_devmgr_core_request_module(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf modname, struct hm_actv_buf args);


extern int __actvcapcall_drvcall_devmgr_core_request_module(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf modname, struct hm_actv_buf args);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_core_request_module(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf modname, struct hm_actv_buf args)
{
	const unsigned long __callno = __devmgr_method_core_request_module;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_core_request_module(rpc_info, NULL, modname, args);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_core_request_module(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf modname, struct hm_actv_buf args)
{
	const unsigned long __callno = __devmgr_method_core_request_module;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_core_request_module(__rref, rpc_info, NULL, modname, args);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_core_request_module(struct hm_actv_buf modname, struct hm_actv_buf args)
{
	return actvxactcall_drvcall_devmgr_core_request_module(false, false, modname, args);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_core_request_module(rref_t __rref, struct hm_actv_buf modname, struct hm_actv_buf args)
{
	return actvxactcapcall_drvcall_devmgr_core_request_module(false, false, __rref, modname, args);
}

extern int __actvcall_drvcall_devmgr_chrdev_register_region(unsigned long long __rpc_info, void *__buf, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);


extern int __actvcapcall_drvcall_devmgr_chrdev_register_region(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_chrdev_register_region(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_chrdev_register_region *__ret)
{
	const unsigned long __callno = __devmgr_method_chrdev_register_region;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_chrdev_register_region(rpc_info, __ret, major, baseminor, minorct, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_chrdev_register_region(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_chrdev_register_region *__ret)
{
	const unsigned long __callno = __devmgr_method_chrdev_register_region;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_chrdev_register_region(__rref, rpc_info, __ret, major, baseminor, minorct, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_chrdev_register_region(unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_chrdev_register_region *__ret)
{
	return actvxactcall_drvcall_devmgr_chrdev_register_region(false, false, major, baseminor, minorct, name, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_chrdev_register_region(rref_t __rref, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_chrdev_register_region *__ret)
{
	return actvxactcapcall_drvcall_devmgr_chrdev_register_region(false, false, __rref, major, baseminor, minorct, name, __ret);
}

extern int __actvcall_drvcall_devmgr_chrdev_unregister_region(unsigned long long __rpc_info, void *__buf, unsigned int major, unsigned int baseminor, int minorct);


extern int __actvcapcall_drvcall_devmgr_chrdev_unregister_region(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int major, unsigned int baseminor, int minorct);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_chrdev_unregister_region(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int major, unsigned int baseminor, int minorct)
{
	const unsigned long __callno = __devmgr_method_chrdev_unregister_region;
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
		__res = __actvcall_drvcall_devmgr_chrdev_unregister_region(rpc_info, NULL, major, baseminor, minorct);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_chrdev_unregister_region(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int major, unsigned int baseminor, int minorct)
{
	const unsigned long __callno = __devmgr_method_chrdev_unregister_region;
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
		__res = __actvcapcall_drvcall_devmgr_chrdev_unregister_region(__rref, rpc_info, NULL, major, baseminor, minorct);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_chrdev_unregister_region(unsigned int major, unsigned int baseminor, int minorct)
{
	return actvxactcall_drvcall_devmgr_chrdev_unregister_region(false, false, major, baseminor, minorct);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_chrdev_unregister_region(rref_t __rref, unsigned int major, unsigned int baseminor, int minorct)
{
	return actvxactcapcall_drvcall_devmgr_chrdev_unregister_region(false, false, __rref, major, baseminor, minorct);
}

extern int __actvcall_drvcall_devmgr_blkdev_register_region(unsigned long long __rpc_info, void *__buf, unsigned int major, struct hm_actv_buf name);


extern int __actvcapcall_drvcall_devmgr_blkdev_register_region(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int major, struct hm_actv_buf name);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_blkdev_register_region(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int major, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_blkdev_register_region *__ret)
{
	const unsigned long __callno = __devmgr_method_blkdev_register_region;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_blkdev_register_region(rpc_info, __ret, major, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_blkdev_register_region(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int major, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_blkdev_register_region *__ret)
{
	const unsigned long __callno = __devmgr_method_blkdev_register_region;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_blkdev_register_region(__rref, rpc_info, __ret, major, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_blkdev_register_region(unsigned int major, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_blkdev_register_region *__ret)
{
	return actvxactcall_drvcall_devmgr_blkdev_register_region(false, false, major, name, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_blkdev_register_region(rref_t __rref, unsigned int major, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_blkdev_register_region *__ret)
{
	return actvxactcapcall_drvcall_devmgr_blkdev_register_region(false, false, __rref, major, name, __ret);
}

extern int __actvcall_drvcall_devmgr_blkdev_unregister_region(unsigned long long __rpc_info, void *__buf, unsigned int major, struct hm_actv_buf name);


extern int __actvcapcall_drvcall_devmgr_blkdev_unregister_region(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int major, struct hm_actv_buf name);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_blkdev_unregister_region(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int major, struct hm_actv_buf name)
{
	const unsigned long __callno = __devmgr_method_blkdev_unregister_region;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_blkdev_unregister_region(rpc_info, NULL, major, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_blkdev_unregister_region(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int major, struct hm_actv_buf name)
{
	const unsigned long __callno = __devmgr_method_blkdev_unregister_region;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_blkdev_unregister_region(__rref, rpc_info, NULL, major, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_blkdev_unregister_region(unsigned int major, struct hm_actv_buf name)
{
	return actvxactcall_drvcall_devmgr_blkdev_unregister_region(false, false, major, name);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_blkdev_unregister_region(rref_t __rref, unsigned int major, struct hm_actv_buf name)
{
	return actvxactcapcall_drvcall_devmgr_blkdev_unregister_region(false, false, __rref, major, name);
}

extern int __actvcall_drvcall_devmgr_fops_open(unsigned long long __rpc_info, void *__buf, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);


extern int __actvcapcall_drvcall_devmgr_fops_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_fops_open(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref, struct __actvret_drvcall_devmgr_fops_open *__ret)
{
	const unsigned long __callno = __devmgr_method_fops_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_fops_open(rpc_info, __ret, devno, vfs_flags, vfs_mode, tgt_rref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_fops_open(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref, struct __actvret_drvcall_devmgr_fops_open *__ret)
{
	const unsigned long __callno = __devmgr_method_fops_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_fops_open(__rref, rpc_info, __ret, devno, vfs_flags, vfs_mode, tgt_rref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_fops_open(unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref, struct __actvret_drvcall_devmgr_fops_open *__ret)
{
	return actvxactcall_drvcall_devmgr_fops_open(false, false, devno, vfs_flags, vfs_mode, tgt_rref, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_fops_open(rref_t __rref, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref, struct __actvret_drvcall_devmgr_fops_open *__ret)
{
	return actvxactcapcall_drvcall_devmgr_fops_open(false, false, __rref, devno, vfs_flags, vfs_mode, tgt_rref, __ret);
}

extern int __actvcall_drvcall_devmgr_mgmt_load_module(unsigned long long __rpc_info, void *__buf, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);


extern int __actvcapcall_drvcall_devmgr_mgmt_load_module(rref_t __rref, unsigned long long __rpc_info, void *__buf, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_mgmt_load_module(bool is_xact_fwd, bool is_xact_allow_refwd, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_mgmt_load_module;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_mgmt_load_module(rpc_info, ___void_buf, load_type, modname, modargs, devid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_mgmt_load_module(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_mgmt_load_module;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_mgmt_load_module(__rref, rpc_info, ___void_buf, load_type, modname, modargs, devid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_mgmt_load_module(int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_drvcall_devmgr_mgmt_load_module(false, false, load_type, modname, modargs, devid, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_mgmt_load_module(rref_t __rref, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_drvcall_devmgr_mgmt_load_module(false, false, __rref, load_type, modname, modargs, devid, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_drvcall_devmgr_mgmt_unload_module(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf modname, unsigned int cnode_idx);


extern int __actvcapcall_drvcall_devmgr_mgmt_unload_module(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf modname, unsigned int cnode_idx);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_mgmt_unload_module(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf modname, unsigned int cnode_idx)
{
	const unsigned long __callno = __devmgr_method_mgmt_unload_module;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_mgmt_unload_module(rpc_info, NULL, modname, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_mgmt_unload_module(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf modname, unsigned int cnode_idx)
{
	const unsigned long __callno = __devmgr_method_mgmt_unload_module;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_mgmt_unload_module(__rref, rpc_info, NULL, modname, cnode_idx);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_mgmt_unload_module(struct hm_actv_buf modname, unsigned int cnode_idx)
{
	return actvxactcall_drvcall_devmgr_mgmt_unload_module(false, false, modname, cnode_idx);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_mgmt_unload_module(rref_t __rref, struct hm_actv_buf modname, unsigned int cnode_idx)
{
	return actvxactcapcall_drvcall_devmgr_mgmt_unload_module(false, false, __rref, modname, cnode_idx);
}

extern int __actvcall_drvcall_devmgr_mgmt_sync(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devmgr_mgmt_sync(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_mgmt_sync(bool is_xact_fwd, bool is_xact_allow_refwd)
{
	const unsigned long __callno = __devmgr_method_mgmt_sync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_mgmt_sync(rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_mgmt_sync(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref)
{
	const unsigned long __callno = __devmgr_method_mgmt_sync;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_mgmt_sync(__rref, rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_mgmt_sync(void)
{
	return actvxactcall_drvcall_devmgr_mgmt_sync(false, false);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_mgmt_sync(rref_t __rref)
{
	return actvxactcapcall_drvcall_devmgr_mgmt_sync(false, false, __rref);
}

extern int __actvcall_drvcall_devmgr_mgmt_dump(unsigned long long __rpc_info, void *__buf, struct bunch_ipc_attr attr);


extern int __actvcapcall_drvcall_devmgr_mgmt_dump(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct bunch_ipc_attr attr);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_mgmt_dump(bool is_xact_fwd, bool is_xact_allow_refwd, struct bunch_ipc_attr attr, struct __actvret_drvcall_devmgr_mgmt_dump *__ret)
{
	const unsigned long __callno = __devmgr_method_mgmt_dump;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_mgmt_dump(rpc_info, __ret, attr);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_mgmt_dump(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct bunch_ipc_attr attr, struct __actvret_drvcall_devmgr_mgmt_dump *__ret)
{
	const unsigned long __callno = __devmgr_method_mgmt_dump;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_mgmt_dump(__rref, rpc_info, __ret, attr);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_mgmt_dump(struct bunch_ipc_attr attr, struct __actvret_drvcall_devmgr_mgmt_dump *__ret)
{
	return actvxactcall_drvcall_devmgr_mgmt_dump(false, false, attr, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_mgmt_dump(rref_t __rref, struct bunch_ipc_attr attr, struct __actvret_drvcall_devmgr_mgmt_dump *__ret)
{
	return actvxactcapcall_drvcall_devmgr_mgmt_dump(false, false, __rref, attr, __ret);
}

extern int __actvcall_drvcall_devmgr_irq_map(unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_map_arg arg);


extern int __actvcapcall_drvcall_devmgr_irq_map(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_map_arg arg);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_irq_map(bool is_xact_fwd, bool is_xact_allow_refwd, struct drvcall_devmgr_irq_map_arg arg, struct __actvret_drvcall_devmgr_irq_map *__ret)
{
	const unsigned long __callno = __devmgr_method_irq_map;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_map_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_map_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_irq_map(rpc_info, __ret, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_irq_map(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct drvcall_devmgr_irq_map_arg arg, struct __actvret_drvcall_devmgr_irq_map *__ret)
{
	const unsigned long __callno = __devmgr_method_irq_map;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_map_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_map_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_irq_map(__rref, rpc_info, __ret, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_irq_map(struct drvcall_devmgr_irq_map_arg arg, struct __actvret_drvcall_devmgr_irq_map *__ret)
{
	return actvxactcall_drvcall_devmgr_irq_map(false, false, arg, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_irq_map(rref_t __rref, struct drvcall_devmgr_irq_map_arg arg, struct __actvret_drvcall_devmgr_irq_map *__ret)
{
	return actvxactcapcall_drvcall_devmgr_irq_map(false, false, __rref, arg, __ret);
}

extern int __actvcall_drvcall_devmgr_irq_fetch(unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_fetch_arg arg);


extern int __actvcapcall_drvcall_devmgr_irq_fetch(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_fetch_arg arg);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_irq_fetch(bool is_xact_fwd, bool is_xact_allow_refwd, struct drvcall_devmgr_irq_fetch_arg arg, struct __actvret_drvcall_devmgr_irq_fetch *__ret)
{
	const unsigned long __callno = __devmgr_method_irq_fetch;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_fetch_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_fetch_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_irq_fetch(rpc_info, __ret, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_irq_fetch(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct drvcall_devmgr_irq_fetch_arg arg, struct __actvret_drvcall_devmgr_irq_fetch *__ret)
{
	const unsigned long __callno = __devmgr_method_irq_fetch;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_fetch_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_fetch_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_irq_fetch(__rref, rpc_info, __ret, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_irq_fetch(struct drvcall_devmgr_irq_fetch_arg arg, struct __actvret_drvcall_devmgr_irq_fetch *__ret)
{
	return actvxactcall_drvcall_devmgr_irq_fetch(false, false, arg, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_irq_fetch(rref_t __rref, struct drvcall_devmgr_irq_fetch_arg arg, struct __actvret_drvcall_devmgr_irq_fetch *__ret)
{
	return actvxactcapcall_drvcall_devmgr_irq_fetch(false, false, __rref, arg, __ret);
}

extern int __actvcall_drvcall_devmgr_irq_return(unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_return_arg arg);


extern int __actvcapcall_drvcall_devmgr_irq_return(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_return_arg arg);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_irq_return(bool is_xact_fwd, bool is_xact_allow_refwd, struct drvcall_devmgr_irq_return_arg arg)
{
	const unsigned long __callno = __devmgr_method_irq_return;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_return_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_return_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_irq_return(rpc_info, NULL, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_irq_return(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct drvcall_devmgr_irq_return_arg arg)
{
	const unsigned long __callno = __devmgr_method_irq_return;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_return_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_return_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_irq_return(__rref, rpc_info, NULL, arg);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_irq_return(struct drvcall_devmgr_irq_return_arg arg)
{
	return actvxactcall_drvcall_devmgr_irq_return(false, false, arg);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_irq_return(rref_t __rref, struct drvcall_devmgr_irq_return_arg arg)
{
	return actvxactcapcall_drvcall_devmgr_irq_return(false, false, __rref, arg);
}

extern int __actvcall_drvcall_devmgr_net_alloc_ifindex(unsigned long long __rpc_info, void *__buf, int ifindex);


extern int __actvcapcall_drvcall_devmgr_net_alloc_ifindex(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_net_alloc_ifindex(bool is_xact_fwd, bool is_xact_allow_refwd, int ifindex, struct __actvret_drvcall_devmgr_net_alloc_ifindex *__ret)
{
	const unsigned long __callno = __devmgr_method_net_alloc_ifindex;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_net_alloc_ifindex(rpc_info, __ret, ifindex);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_net_alloc_ifindex(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int ifindex, struct __actvret_drvcall_devmgr_net_alloc_ifindex *__ret)
{
	const unsigned long __callno = __devmgr_method_net_alloc_ifindex;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_net_alloc_ifindex(__rref, rpc_info, __ret, ifindex);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_net_alloc_ifindex(int ifindex, struct __actvret_drvcall_devmgr_net_alloc_ifindex *__ret)
{
	return actvxactcall_drvcall_devmgr_net_alloc_ifindex(false, false, ifindex, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_net_alloc_ifindex(rref_t __rref, int ifindex, struct __actvret_drvcall_devmgr_net_alloc_ifindex *__ret)
{
	return actvxactcapcall_drvcall_devmgr_net_alloc_ifindex(false, false, __rref, ifindex, __ret);
}

extern int __actvcall_drvcall_devmgr_net_register(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, int ifindex, unsigned long long features);


extern int __actvcapcall_drvcall_devmgr_net_register(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, int ifindex, unsigned long long features);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_net_register(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf name, int ifindex, unsigned long long features, struct __actvret_drvcall_devmgr_net_register *__ret)
{
	const unsigned long __callno = __devmgr_method_net_register;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_net_register(rpc_info, __ret, name, ifindex, features);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_net_register(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf name, int ifindex, unsigned long long features, struct __actvret_drvcall_devmgr_net_register *__ret)
{
	const unsigned long __callno = __devmgr_method_net_register;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_net_register(__rref, rpc_info, __ret, name, ifindex, features);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_net_register(struct hm_actv_buf name, int ifindex, unsigned long long features, struct __actvret_drvcall_devmgr_net_register *__ret)
{
	return actvxactcall_drvcall_devmgr_net_register(false, false, name, ifindex, features, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_net_register(rref_t __rref, struct hm_actv_buf name, int ifindex, unsigned long long features, struct __actvret_drvcall_devmgr_net_register *__ret)
{
	return actvxactcapcall_drvcall_devmgr_net_register(false, false, __rref, name, ifindex, features, __ret);
}

extern int __actvcall_drvcall_devmgr_net_unregister(unsigned long long __rpc_info, void *__buf, int ifindex);


extern int __actvcapcall_drvcall_devmgr_net_unregister(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_net_unregister(bool is_xact_fwd, bool is_xact_allow_refwd, int ifindex)
{
	const unsigned long __callno = __devmgr_method_net_unregister;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_net_unregister(rpc_info, NULL, ifindex);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_net_unregister(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int ifindex)
{
	const unsigned long __callno = __devmgr_method_net_unregister;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_net_unregister(__rref, rpc_info, NULL, ifindex);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_net_unregister(int ifindex)
{
	return actvxactcall_drvcall_devmgr_net_unregister(false, false, ifindex);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_net_unregister(rref_t __rref, int ifindex)
{
	return actvxactcapcall_drvcall_devmgr_net_unregister(false, false, __rref, ifindex);
}

extern int __actvcall_drvcall_devmgr_net_hmnetd_ready(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devmgr_net_hmnetd_ready(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_net_hmnetd_ready(bool is_xact_fwd, bool is_xact_allow_refwd)
{
	const unsigned long __callno = __devmgr_method_net_hmnetd_ready;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_net_hmnetd_ready(rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_net_hmnetd_ready(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref)
{
	const unsigned long __callno = __devmgr_method_net_hmnetd_ready;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_net_hmnetd_ready(__rref, rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_net_hmnetd_ready(void)
{
	return actvxactcall_drvcall_devmgr_net_hmnetd_ready(false, false);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_net_hmnetd_ready(rref_t __rref)
{
	return actvxactcapcall_drvcall_devmgr_net_hmnetd_ready(false, false, __rref);
}

extern int __actvcall_drvcall_devmgr_net_open(unsigned long long __rpc_info, void *__buf, int ifindex, rref_t tgt_rref);


extern int __actvcapcall_drvcall_devmgr_net_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex, rref_t tgt_rref);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_net_open(bool is_xact_fwd, bool is_xact_allow_refwd, int ifindex, rref_t tgt_rref)
{
	const unsigned long __callno = __devmgr_method_net_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_net_open(rpc_info, NULL, ifindex, tgt_rref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_net_open(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int ifindex, rref_t tgt_rref)
{
	const unsigned long __callno = __devmgr_method_net_open;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_net_open(__rref, rpc_info, NULL, ifindex, tgt_rref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_net_open(int ifindex, rref_t tgt_rref)
{
	return actvxactcall_drvcall_devmgr_net_open(false, false, ifindex, tgt_rref);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_net_open(rref_t __rref, int ifindex, rref_t tgt_rref)
{
	return actvxactcapcall_drvcall_devmgr_net_open(false, false, __rref, ifindex, tgt_rref);
}

extern int __actvcall_drvcall_devmgr_pm_action(unsigned long long __rpc_info, void *__buf, unsigned int action);


extern int __actvcapcall_drvcall_devmgr_pm_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int action);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_pm_action(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int action)
{
	const unsigned long __callno = __devmgr_method_pm_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_pm_action(rpc_info, NULL, action);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_pm_action(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int action)
{
	const unsigned long __callno = __devmgr_method_pm_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_pm_action(__rref, rpc_info, NULL, action);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_pm_action(unsigned int action)
{
	return actvxactcall_drvcall_devmgr_pm_action(false, false, action);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_pm_action(rref_t __rref, unsigned int action)
{
	return actvxactcapcall_drvcall_devmgr_pm_action(false, false, __rref, action);
}

extern int __actvcall_drvcall_devmgr_pm_power_off(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devmgr_pm_power_off(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_pm_power_off(bool is_xact_fwd, bool is_xact_allow_refwd)
{
	const unsigned long __callno = __devmgr_method_pm_power_off;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_pm_power_off(rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_pm_power_off(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref)
{
	const unsigned long __callno = __devmgr_method_pm_power_off;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_pm_power_off(__rref, rpc_info, NULL);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_pm_power_off(void)
{
	return actvxactcall_drvcall_devmgr_pm_power_off(false, false);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_pm_power_off(rref_t __rref)
{
	return actvxactcapcall_drvcall_devmgr_pm_power_off(false, false, __rref);
}

extern int __actvcall_drvcall_devmgr_pm_reboot(unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd);


extern int __actvcapcall_drvcall_devmgr_pm_reboot(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_pm_reboot(bool is_xact_fwd, bool is_xact_allow_refwd, struct reboot_cmd cmd)
{
	const unsigned long __callno = __devmgr_method_pm_reboot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_pm_reboot(rpc_info, NULL, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_pm_reboot(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct reboot_cmd cmd)
{
	const unsigned long __callno = __devmgr_method_pm_reboot;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_pm_reboot(__rref, rpc_info, NULL, cmd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_pm_reboot(struct reboot_cmd cmd)
{
	return actvxactcall_drvcall_devmgr_pm_reboot(false, false, cmd);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_pm_reboot(rref_t __rref, struct reboot_cmd cmd)
{
	return actvxactcapcall_drvcall_devmgr_pm_reboot(false, false, __rref, cmd);
}

extern int __actvcall_drvcall_devmgr_pm_cpuhp_action(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devmgr_pm_cpuhp_action(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_pm_cpuhp_action(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_pm_cpuhp_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_pm_cpuhp_action(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_pm_cpuhp_action(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_pm_cpuhp_action;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_pm_cpuhp_action(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_pm_cpuhp_action(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_drvcall_devmgr_pm_cpuhp_action(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_pm_cpuhp_action(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_drvcall_devmgr_pm_cpuhp_action(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_drvcall_devmgr_procfs_create_data(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);


extern int __actvcapcall_drvcall_devmgr_procfs_create_data(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_procfs_create_data(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	const unsigned long __callno = __devmgr_method_procfs_create_data;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_procfs_create_data(rpc_info, NULL, name, mode, ops, linkname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_procfs_create_data(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	const unsigned long __callno = __devmgr_method_procfs_create_data;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_procfs_create_data(__rref, rpc_info, NULL, name, mode, ops, linkname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_procfs_create_data(struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	return actvxactcall_drvcall_devmgr_procfs_create_data(false, false, name, mode, ops, linkname);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_procfs_create_data(rref_t __rref, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	return actvxactcapcall_drvcall_devmgr_procfs_create_data(false, false, __rref, name, mode, ops, linkname);
}

extern int __actvcall_drvcall_devmgr_procfs_unlink(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name);


extern int __actvcapcall_drvcall_devmgr_procfs_unlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_procfs_unlink(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf name)
{
	const unsigned long __callno = __devmgr_method_procfs_unlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_procfs_unlink(rpc_info, NULL, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_procfs_unlink(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf name)
{
	const unsigned long __callno = __devmgr_method_procfs_unlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_procfs_unlink(__rref, rpc_info, NULL, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_procfs_unlink(struct hm_actv_buf name)
{
	return actvxactcall_drvcall_devmgr_procfs_unlink(false, false, name);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_procfs_unlink(rref_t __rref, struct hm_actv_buf name)
{
	return actvxactcapcall_drvcall_devmgr_procfs_unlink(false, false, __rref, name);
}

extern int __actvcall_drvcall_devmgr_procfs_read(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devmgr_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_procfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_procfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_procfs_read(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_procfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_procfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_procfs_read(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_procfs_read(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_drvcall_devmgr_procfs_read(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_procfs_read(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_drvcall_devmgr_procfs_read(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_drvcall_devmgr_procfs_write(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devmgr_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_procfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_procfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_procfs_write(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_procfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_procfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_procfs_write(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_procfs_write(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_drvcall_devmgr_procfs_write(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_procfs_write(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_drvcall_devmgr_procfs_write(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_drvcall_devmgr_sysfs_create_dir(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode);


extern int __actvcapcall_drvcall_devmgr_sysfs_create_dir(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_sysfs_create_dir(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf name, unsigned int mode)
{
	const unsigned long __callno = __devmgr_method_sysfs_create_dir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_sysfs_create_dir(rpc_info, NULL, name, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_sysfs_create_dir(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf name, unsigned int mode)
{
	const unsigned long __callno = __devmgr_method_sysfs_create_dir;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_sysfs_create_dir(__rref, rpc_info, NULL, name, mode);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_sysfs_create_dir(struct hm_actv_buf name, unsigned int mode)
{
	return actvxactcall_drvcall_devmgr_sysfs_create_dir(false, false, name, mode);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_sysfs_create_dir(rref_t __rref, struct hm_actv_buf name, unsigned int mode)
{
	return actvxactcapcall_drvcall_devmgr_sysfs_create_dir(false, false, __rref, name, mode);
}

extern int __actvcall_drvcall_devmgr_sysfs_create_file(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, int tagid);


extern int __actvcapcall_drvcall_devmgr_sysfs_create_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, int tagid);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_sysfs_create_file(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf name, unsigned int mode, int tagid)
{
	const unsigned long __callno = __devmgr_method_sysfs_create_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_sysfs_create_file(rpc_info, NULL, name, mode, tagid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_sysfs_create_file(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf name, unsigned int mode, int tagid)
{
	const unsigned long __callno = __devmgr_method_sysfs_create_file;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_sysfs_create_file(__rref, rpc_info, NULL, name, mode, tagid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_sysfs_create_file(struct hm_actv_buf name, unsigned int mode, int tagid)
{
	return actvxactcall_drvcall_devmgr_sysfs_create_file(false, false, name, mode, tagid);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_sysfs_create_file(rref_t __rref, struct hm_actv_buf name, unsigned int mode, int tagid)
{
	return actvxactcapcall_drvcall_devmgr_sysfs_create_file(false, false, __rref, name, mode, tagid);
}

extern int __actvcall_drvcall_devmgr_sysfs_create_symlink(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);


extern int __actvcapcall_drvcall_devmgr_sysfs_create_symlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_sysfs_create_symlink(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	const unsigned long __callno = __devmgr_method_sysfs_create_symlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_sysfs_create_symlink(rpc_info, NULL, name, mode, linkname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_sysfs_create_symlink(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	const unsigned long __callno = __devmgr_method_sysfs_create_symlink;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_sysfs_create_symlink(__rref, rpc_info, NULL, name, mode, linkname);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_sysfs_create_symlink(struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	return actvxactcall_drvcall_devmgr_sysfs_create_symlink(false, false, name, mode, linkname);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_sysfs_create_symlink(rref_t __rref, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	return actvxactcapcall_drvcall_devmgr_sysfs_create_symlink(false, false, __rref, name, mode, linkname);
}

extern int __actvcall_drvcall_devmgr_sysfs_delete(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name);


extern int __actvcapcall_drvcall_devmgr_sysfs_delete(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_sysfs_delete(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_sysfs_delete *__ret)
{
	const unsigned long __callno = __devmgr_method_sysfs_delete;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_sysfs_delete(rpc_info, __ret, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_sysfs_delete(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_sysfs_delete *__ret)
{
	const unsigned long __callno = __devmgr_method_sysfs_delete;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_sysfs_delete(__rref, rpc_info, __ret, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_sysfs_delete(struct hm_actv_buf name, struct __actvret_drvcall_devmgr_sysfs_delete *__ret)
{
	return actvxactcall_drvcall_devmgr_sysfs_delete(false, false, name, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_sysfs_delete(rref_t __rref, struct hm_actv_buf name, struct __actvret_drvcall_devmgr_sysfs_delete *__ret)
{
	return actvxactcapcall_drvcall_devmgr_sysfs_delete(false, false, __rref, name, __ret);
}

extern int __actvcall_drvcall_devmgr_sysfs_notify(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name);


extern int __actvcapcall_drvcall_devmgr_sysfs_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_sysfs_notify(bool is_xact_fwd, bool is_xact_allow_refwd, struct hm_actv_buf name)
{
	const unsigned long __callno = __devmgr_method_sysfs_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_sysfs_notify(rpc_info, NULL, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_sysfs_notify(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct hm_actv_buf name)
{
	const unsigned long __callno = __devmgr_method_sysfs_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_sysfs_notify(__rref, rpc_info, NULL, name);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_sysfs_notify(struct hm_actv_buf name)
{
	return actvxactcall_drvcall_devmgr_sysfs_notify(false, false, name);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_sysfs_notify(rref_t __rref, struct hm_actv_buf name)
{
	return actvxactcapcall_drvcall_devmgr_sysfs_notify(false, false, __rref, name);
}

extern int __actvcall_drvcall_devmgr_sysfs_read(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devmgr_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_sysfs_read(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_sysfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_sysfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_sysfs_read(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_sysfs_read(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_drvcall_devmgr_sysfs_read(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_sysfs_read(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_drvcall_devmgr_sysfs_read(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_drvcall_devmgr_sysfs_write(unsigned long long __rpc_info, void *__buf, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);


extern int __actvcapcall_drvcall_devmgr_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	const unsigned long __callno = __devmgr_method_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_sysfs_write(rpc_info, NULL, tagid, ctx, pos, actv_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_sysfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	const unsigned long __callno = __devmgr_method_sysfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_sysfs_write(__rref, rpc_info, NULL, tagid, ctx, pos, actv_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_sysfs_write(int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	return actvxactcall_drvcall_devmgr_sysfs_write(false, false, tagid, ctx, pos, actv_buf);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_sysfs_write(rref_t __rref, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	return actvxactcapcall_drvcall_devmgr_sysfs_write(false, false, __rref, tagid, ctx, pos, actv_buf);
}

extern int __actvcall_drvcall_devmgr_sysfs_poll(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_drvcall_devmgr_sysfs_poll(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_sysfs_poll(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_sysfs_poll;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_sysfs_poll(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_sysfs_poll(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __devmgr_method_sysfs_poll;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_sysfs_poll(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_sysfs_poll(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_drvcall_devmgr_sysfs_poll(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_sysfs_poll(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_drvcall_devmgr_sysfs_poll(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_drvcall_devmgr_fw_acquire_contents(unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);


extern int __actvcapcall_drvcall_devmgr_fw_acquire_contents(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);


static inline int __attribute__((always_inline)) actvxactcall_drvcall_devmgr_fw_acquire_contents(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen, struct __actvret_drvcall_devmgr_fw_acquire_contents *__ret)
{
	const unsigned long __callno = __devmgr_method_fw_acquire_contents;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_drvcall_devmgr_fw_acquire_contents(rpc_info, __ret, buf, size, name, namelen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_drvcall_devmgr_fw_acquire_contents(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen, struct __actvret_drvcall_devmgr_fw_acquire_contents *__ret)
{
	const unsigned long __callno = __devmgr_method_fw_acquire_contents;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_drvcall_devmgr_fw_acquire_contents(__rref, rpc_info, __ret, buf, size, name, namelen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_drvcall_devmgr_fw_acquire_contents(unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen, struct __actvret_drvcall_devmgr_fw_acquire_contents *__ret)
{
	return actvxactcall_drvcall_devmgr_fw_acquire_contents(false, false, buf, size, name, namelen, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_drvcall_devmgr_fw_acquire_contents(rref_t __rref, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen, struct __actvret_drvcall_devmgr_fw_acquire_contents *__ret)
{
	return actvxactcapcall_drvcall_devmgr_fw_acquire_contents(false, false, __rref, buf, size, name, namelen, __ret);
}

#endif
#ifdef __sysif_server_devmgr_no_compat32_handlers__
# define __devmgr_method_MAX __devmgr_method_MAX_NOCOMPAT
#else
# define __devmgr_method_MAX __devmgr_method_MAX_COMPAT
#endif
#include <libsysif/utils.h>
#include <asm/actv_rpc.h>
#include <asm/types.h>
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
extern int actvhdlr_drvhandler_devmgr_core_register_devhost(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);


extern int actvhdlr_drvhandler_devmgr_core_devhost_init_done(unsigned long long sender, unsigned long credential);


extern int actvhdlr_drvhandler_devmgr_core_device_add(unsigned long long sender, unsigned long credential, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);


extern int actvhdlr_drvhandler_devmgr_core_device_del(unsigned long long sender, unsigned long credential, int devid);


extern int actvhdlr_drvhandler_devmgr_core_request_module(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args);


extern int actvhdlr_drvhandler_devmgr_chrdev_register_region(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);


extern int actvhdlr_drvhandler_devmgr_chrdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct);


extern int actvhdlr_drvhandler_devmgr_blkdev_register_region(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);


extern int actvhdlr_drvhandler_devmgr_blkdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);


extern int actvhdlr_drvhandler_devmgr_fops_open(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);


extern int actvhdlr_drvhandler_devmgr_mgmt_load_module(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);


extern int actvhdlr_drvhandler_devmgr_mgmt_unload_module(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx);


extern int actvhdlr_drvhandler_devmgr_mgmt_sync(unsigned long long sender, unsigned long credential);


extern int actvhdlr_drvhandler_devmgr_mgmt_dump(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr);


extern int actvhdlr_drvhandler_devmgr_irq_map(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg);


extern int actvhdlr_drvhandler_devmgr_irq_fetch(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg);


extern int actvhdlr_drvhandler_devmgr_irq_return(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg);


extern int actvhdlr_drvhandler_devmgr_net_alloc_ifindex(unsigned long long sender, unsigned long credential, int ifindex);


extern int actvhdlr_drvhandler_devmgr_net_register(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features);


extern int actvhdlr_drvhandler_devmgr_net_unregister(unsigned long long sender, unsigned long credential, int ifindex);


extern int actvhdlr_drvhandler_devmgr_net_hmnetd_ready(unsigned long long sender, unsigned long credential);


extern int actvhdlr_drvhandler_devmgr_net_open(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref);


extern int actvhdlr_drvhandler_devmgr_pm_action(unsigned long long sender, unsigned long credential, unsigned int action);


extern int actvhdlr_drvhandler_devmgr_pm_power_off(unsigned long long sender, unsigned long credential);


extern int actvhdlr_drvhandler_devmgr_pm_reboot(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);


extern int actvhdlr_drvhandler_devmgr_pm_cpuhp_action(unsigned long long sender, unsigned long credential);


extern int actvhdlr_drvhandler_devmgr_procfs_create_data(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);


extern int actvhdlr_drvhandler_devmgr_procfs_unlink(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);


extern int actvhdlr_drvhandler_devmgr_procfs_read(unsigned long long sender, unsigned long credential);


extern int actvhdlr_drvhandler_devmgr_procfs_write(unsigned long long sender, unsigned long credential);


extern int actvhdlr_drvhandler_devmgr_sysfs_create_dir(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode);


extern int actvhdlr_drvhandler_devmgr_sysfs_create_file(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid);


extern int actvhdlr_drvhandler_devmgr_sysfs_create_symlink(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);


extern int actvhdlr_drvhandler_devmgr_sysfs_delete(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);


extern int actvhdlr_drvhandler_devmgr_sysfs_notify(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);


extern int actvhdlr_drvhandler_devmgr_sysfs_read(unsigned long long sender, unsigned long credential);


extern int actvhdlr_drvhandler_devmgr_sysfs_write(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);


extern int actvhdlr_drvhandler_devmgr_sysfs_poll(unsigned long long sender, unsigned long credential);


extern int actvhdlr_drvhandler_devmgr_fw_acquire_contents(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);


#else
extern int actvhdlr_drvhandler_devmgr_core_register_devhost(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);


extern int __actvshadowhdlr_drvhandler_devmgr_core_register_devhost(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_core_devhost_init_done(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_drvhandler_devmgr_core_devhost_init_done(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_core_device_add(unsigned long long sender, unsigned long credential, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);


extern int __actvshadowhdlr_drvhandler_devmgr_core_device_add(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_core_device_del(unsigned long long sender, unsigned long credential, int devid);


extern int __actvshadowhdlr_drvhandler_devmgr_core_device_del(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_core_request_module(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args);


extern int __actvshadowhdlr_drvhandler_devmgr_core_request_module(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_chrdev_register_region(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);


extern int __actvshadowhdlr_drvhandler_devmgr_chrdev_register_region(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_chrdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct);


extern int __actvshadowhdlr_drvhandler_devmgr_chrdev_unregister_region(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_blkdev_register_region(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);


extern int __actvshadowhdlr_drvhandler_devmgr_blkdev_register_region(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_blkdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);


extern int __actvshadowhdlr_drvhandler_devmgr_blkdev_unregister_region(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_fops_open(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);


extern int __actvshadowhdlr_drvhandler_devmgr_fops_open(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_mgmt_load_module(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);


extern int __actvshadowhdlr_drvhandler_devmgr_mgmt_load_module(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_mgmt_unload_module(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx);


extern int __actvshadowhdlr_drvhandler_devmgr_mgmt_unload_module(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_mgmt_sync(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_drvhandler_devmgr_mgmt_sync(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_mgmt_dump(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr);


extern int __actvshadowhdlr_drvhandler_devmgr_mgmt_dump(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_irq_map(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg);


extern int __actvshadowhdlr_drvhandler_devmgr_irq_map(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_irq_fetch(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg);


extern int __actvshadowhdlr_drvhandler_devmgr_irq_fetch(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_irq_return(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg);


extern int __actvshadowhdlr_drvhandler_devmgr_irq_return(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_net_alloc_ifindex(unsigned long long sender, unsigned long credential, int ifindex);


extern int __actvshadowhdlr_drvhandler_devmgr_net_alloc_ifindex(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_net_register(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features);


extern int __actvshadowhdlr_drvhandler_devmgr_net_register(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_net_unregister(unsigned long long sender, unsigned long credential, int ifindex);


extern int __actvshadowhdlr_drvhandler_devmgr_net_unregister(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_net_hmnetd_ready(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_drvhandler_devmgr_net_hmnetd_ready(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_net_open(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref);


extern int __actvshadowhdlr_drvhandler_devmgr_net_open(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_pm_action(unsigned long long sender, unsigned long credential, unsigned int action);


extern int __actvshadowhdlr_drvhandler_devmgr_pm_action(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_pm_power_off(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_drvhandler_devmgr_pm_power_off(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_pm_reboot(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);


extern int __actvshadowhdlr_drvhandler_devmgr_pm_reboot(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_pm_cpuhp_action(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_drvhandler_devmgr_pm_cpuhp_action(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_procfs_create_data(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);


extern int __actvshadowhdlr_drvhandler_devmgr_procfs_create_data(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_procfs_unlink(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);


extern int __actvshadowhdlr_drvhandler_devmgr_procfs_unlink(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_procfs_read(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_drvhandler_devmgr_procfs_read(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_procfs_write(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_drvhandler_devmgr_procfs_write(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_sysfs_create_dir(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode);


extern int __actvshadowhdlr_drvhandler_devmgr_sysfs_create_dir(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_sysfs_create_file(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid);


extern int __actvshadowhdlr_drvhandler_devmgr_sysfs_create_file(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_sysfs_create_symlink(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);


extern int __actvshadowhdlr_drvhandler_devmgr_sysfs_create_symlink(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_sysfs_delete(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);


extern int __actvshadowhdlr_drvhandler_devmgr_sysfs_delete(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_sysfs_notify(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);


extern int __actvshadowhdlr_drvhandler_devmgr_sysfs_notify(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_sysfs_read(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_drvhandler_devmgr_sysfs_read(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_sysfs_write(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);


extern int __actvshadowhdlr_drvhandler_devmgr_sysfs_write(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_sysfs_poll(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_drvhandler_devmgr_sysfs_poll(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_drvhandler_devmgr_fw_acquire_contents(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);


extern int __actvshadowhdlr_drvhandler_devmgr_fw_acquire_contents(unsigned long long sender, unsigned long credential, ...);


#endif
static inline struct __actvret_drvcall_devmgr_core_register_devhost* actvhdlr_drvhandler_devmgr_core_register_devhost_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_core_register_devhost));
	return (struct __actvret_drvcall_devmgr_core_register_devhost*)__ret;
}

static inline struct __actvret_drvcall_devmgr_core_devhost_init_done* actvhdlr_drvhandler_devmgr_core_devhost_init_done_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_core_devhost_init_done));
	return (struct __actvret_drvcall_devmgr_core_devhost_init_done*)__ret;
}

static inline struct __actvret_drvcall_devmgr_core_device_add* actvhdlr_drvhandler_devmgr_core_device_add_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_core_device_add));
	return (struct __actvret_drvcall_devmgr_core_device_add*)__ret;
}

static inline struct __actvret_drvcall_devmgr_core_device_del* actvhdlr_drvhandler_devmgr_core_device_del_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_core_device_del));
	return (struct __actvret_drvcall_devmgr_core_device_del*)__ret;
}

static inline struct __actvret_drvcall_devmgr_core_request_module* actvhdlr_drvhandler_devmgr_core_request_module_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_core_request_module));
	return (struct __actvret_drvcall_devmgr_core_request_module*)__ret;
}

static inline struct __actvret_drvcall_devmgr_chrdev_register_region* actvhdlr_drvhandler_devmgr_chrdev_register_region_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_chrdev_register_region));
	return (struct __actvret_drvcall_devmgr_chrdev_register_region*)__ret;
}

static inline struct __actvret_drvcall_devmgr_chrdev_unregister_region* actvhdlr_drvhandler_devmgr_chrdev_unregister_region_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_chrdev_unregister_region));
	return (struct __actvret_drvcall_devmgr_chrdev_unregister_region*)__ret;
}

static inline struct __actvret_drvcall_devmgr_blkdev_register_region* actvhdlr_drvhandler_devmgr_blkdev_register_region_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_blkdev_register_region));
	return (struct __actvret_drvcall_devmgr_blkdev_register_region*)__ret;
}

static inline struct __actvret_drvcall_devmgr_blkdev_unregister_region* actvhdlr_drvhandler_devmgr_blkdev_unregister_region_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_blkdev_unregister_region));
	return (struct __actvret_drvcall_devmgr_blkdev_unregister_region*)__ret;
}

static inline struct __actvret_drvcall_devmgr_fops_open* actvhdlr_drvhandler_devmgr_fops_open_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_fops_open));
	return (struct __actvret_drvcall_devmgr_fops_open*)__ret;
}

static inline struct __actvret_drvcall_devmgr_mgmt_load_module* actvhdlr_drvhandler_devmgr_mgmt_load_module_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_mgmt_load_module));
	return (struct __actvret_drvcall_devmgr_mgmt_load_module*)__ret;
}

static inline struct __actvret_drvcall_devmgr_mgmt_unload_module* actvhdlr_drvhandler_devmgr_mgmt_unload_module_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_mgmt_unload_module));
	return (struct __actvret_drvcall_devmgr_mgmt_unload_module*)__ret;
}

static inline struct __actvret_drvcall_devmgr_mgmt_sync* actvhdlr_drvhandler_devmgr_mgmt_sync_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_mgmt_sync));
	return (struct __actvret_drvcall_devmgr_mgmt_sync*)__ret;
}

static inline struct __actvret_drvcall_devmgr_mgmt_dump* actvhdlr_drvhandler_devmgr_mgmt_dump_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_mgmt_dump));
	return (struct __actvret_drvcall_devmgr_mgmt_dump*)__ret;
}

static inline struct __actvret_drvcall_devmgr_irq_map* actvhdlr_drvhandler_devmgr_irq_map_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_irq_map));
	return (struct __actvret_drvcall_devmgr_irq_map*)__ret;
}

static inline struct __actvret_drvcall_devmgr_irq_fetch* actvhdlr_drvhandler_devmgr_irq_fetch_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_irq_fetch));
	return (struct __actvret_drvcall_devmgr_irq_fetch*)__ret;
}

static inline struct __actvret_drvcall_devmgr_irq_return* actvhdlr_drvhandler_devmgr_irq_return_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_irq_return));
	return (struct __actvret_drvcall_devmgr_irq_return*)__ret;
}

static inline struct __actvret_drvcall_devmgr_net_alloc_ifindex* actvhdlr_drvhandler_devmgr_net_alloc_ifindex_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_net_alloc_ifindex));
	return (struct __actvret_drvcall_devmgr_net_alloc_ifindex*)__ret;
}

static inline struct __actvret_drvcall_devmgr_net_register* actvhdlr_drvhandler_devmgr_net_register_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_net_register));
	return (struct __actvret_drvcall_devmgr_net_register*)__ret;
}

static inline struct __actvret_drvcall_devmgr_net_unregister* actvhdlr_drvhandler_devmgr_net_unregister_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_net_unregister));
	return (struct __actvret_drvcall_devmgr_net_unregister*)__ret;
}

static inline struct __actvret_drvcall_devmgr_net_hmnetd_ready* actvhdlr_drvhandler_devmgr_net_hmnetd_ready_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_net_hmnetd_ready));
	return (struct __actvret_drvcall_devmgr_net_hmnetd_ready*)__ret;
}

static inline struct __actvret_drvcall_devmgr_net_open* actvhdlr_drvhandler_devmgr_net_open_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_net_open));
	return (struct __actvret_drvcall_devmgr_net_open*)__ret;
}

static inline struct __actvret_drvcall_devmgr_pm_action* actvhdlr_drvhandler_devmgr_pm_action_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_pm_action));
	return (struct __actvret_drvcall_devmgr_pm_action*)__ret;
}

static inline struct __actvret_drvcall_devmgr_pm_power_off* actvhdlr_drvhandler_devmgr_pm_power_off_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_pm_power_off));
	return (struct __actvret_drvcall_devmgr_pm_power_off*)__ret;
}

static inline struct __actvret_drvcall_devmgr_pm_reboot* actvhdlr_drvhandler_devmgr_pm_reboot_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_pm_reboot));
	return (struct __actvret_drvcall_devmgr_pm_reboot*)__ret;
}

static inline struct __actvret_drvcall_devmgr_pm_cpuhp_action* actvhdlr_drvhandler_devmgr_pm_cpuhp_action_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_pm_cpuhp_action));
	return (struct __actvret_drvcall_devmgr_pm_cpuhp_action*)__ret;
}

static inline struct __actvret_drvcall_devmgr_procfs_create_data* actvhdlr_drvhandler_devmgr_procfs_create_data_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_procfs_create_data));
	return (struct __actvret_drvcall_devmgr_procfs_create_data*)__ret;
}

static inline struct __actvret_drvcall_devmgr_procfs_unlink* actvhdlr_drvhandler_devmgr_procfs_unlink_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_procfs_unlink));
	return (struct __actvret_drvcall_devmgr_procfs_unlink*)__ret;
}

static inline struct __actvret_drvcall_devmgr_procfs_read* actvhdlr_drvhandler_devmgr_procfs_read_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_procfs_read));
	return (struct __actvret_drvcall_devmgr_procfs_read*)__ret;
}

static inline struct __actvret_drvcall_devmgr_procfs_write* actvhdlr_drvhandler_devmgr_procfs_write_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_procfs_write));
	return (struct __actvret_drvcall_devmgr_procfs_write*)__ret;
}

static inline struct __actvret_drvcall_devmgr_sysfs_create_dir* actvhdlr_drvhandler_devmgr_sysfs_create_dir_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_sysfs_create_dir));
	return (struct __actvret_drvcall_devmgr_sysfs_create_dir*)__ret;
}

static inline struct __actvret_drvcall_devmgr_sysfs_create_file* actvhdlr_drvhandler_devmgr_sysfs_create_file_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_sysfs_create_file));
	return (struct __actvret_drvcall_devmgr_sysfs_create_file*)__ret;
}

static inline struct __actvret_drvcall_devmgr_sysfs_create_symlink* actvhdlr_drvhandler_devmgr_sysfs_create_symlink_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_sysfs_create_symlink));
	return (struct __actvret_drvcall_devmgr_sysfs_create_symlink*)__ret;
}

static inline struct __actvret_drvcall_devmgr_sysfs_delete* actvhdlr_drvhandler_devmgr_sysfs_delete_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_sysfs_delete));
	return (struct __actvret_drvcall_devmgr_sysfs_delete*)__ret;
}

static inline struct __actvret_drvcall_devmgr_sysfs_notify* actvhdlr_drvhandler_devmgr_sysfs_notify_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_sysfs_notify));
	return (struct __actvret_drvcall_devmgr_sysfs_notify*)__ret;
}

static inline struct __actvret_drvcall_devmgr_sysfs_read* actvhdlr_drvhandler_devmgr_sysfs_read_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_sysfs_read));
	return (struct __actvret_drvcall_devmgr_sysfs_read*)__ret;
}

static inline struct __actvret_drvcall_devmgr_sysfs_write* actvhdlr_drvhandler_devmgr_sysfs_write_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_sysfs_write));
	return (struct __actvret_drvcall_devmgr_sysfs_write*)__ret;
}

static inline struct __actvret_drvcall_devmgr_sysfs_poll* actvhdlr_drvhandler_devmgr_sysfs_poll_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_sysfs_poll));
	return (struct __actvret_drvcall_devmgr_sysfs_poll*)__ret;
}

static inline struct __actvret_drvcall_devmgr_fw_acquire_contents* actvhdlr_drvhandler_devmgr_fw_acquire_contents_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_drvcall_devmgr_fw_acquire_contents));
	return (struct __actvret_drvcall_devmgr_fw_acquire_contents*)__ret;
}

#ifdef __sysif_server_devmgr_no_compat32_handlers__
#ifdef __HOST_LLT__
union devmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, unsigned int action);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union devmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, unsigned int action);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union devmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, unsigned int action);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
#ifdef __HOST_LLT__
union devmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, unsigned int action);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_devhost_init_done)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_devhost_init_done)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_device_del)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_del)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_request_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_request_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_fops_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fops_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_load_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_load_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_unload_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_unload_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_sync)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_sync)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_dump)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_dump)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_irq_map)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_map)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_irq_fetch)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_fetch)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_irq_return)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_return)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_unregister)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_unregister)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_power_off)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_power_off)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_create_data)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_create_data)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_unlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_unlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_dir)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_dir)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_file)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_file)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_delete)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_delete)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_poll)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_poll)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union devmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, unsigned int action);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_devhost_init_done)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_devhost_init_done)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_device_del)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_del)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_request_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_request_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_fops_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fops_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_load_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_load_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_unload_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_unload_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_sync)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_sync)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_dump)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_dump)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_irq_map)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_map)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_irq_fetch)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_fetch)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_irq_return)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_return)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_unregister)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_unregister)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_power_off)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_power_off)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_create_data)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_create_data)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_unlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_unlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_dir)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_dir)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_file)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_file)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_delete)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_delete)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_poll)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_poll)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union devmgr_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, struct hm_actv_buf args);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, unsigned int cnode_idx);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct bunch_ipc_attr attr);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_map_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_fetch_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_return_arg arg);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, int ifindex, unsigned long long features);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, int ifindex);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_net_open)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex, rref_t tgt_rref);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, unsigned int action);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd);
	int (*p__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, int tagid);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, struct hm_actv_buf name);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf);
	int (*p__actvbridgehdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_register_devhost)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_devhost_init_done)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_devhost_init_done)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_device_del)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_del)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_core_request_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_request_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_register_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_unregister_region)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_fops_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fops_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_load_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_load_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_unload_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_unload_module)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_sync)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_sync)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_dump)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_dump)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_irq_map)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_map)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_irq_fetch)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_fetch)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_irq_return)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_return)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_alloc_ifindex)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_unregister)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_unregister)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_hmnetd_ready)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_net_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_open)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_power_off)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_power_off)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_reboot)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_cpuhp_action)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_create_data)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_create_data)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_unlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_unlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_dir)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_dir)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_file)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_file)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_symlink)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_delete)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_delete)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_poll)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_poll)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_drvhandler_devmgr_compat_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fw_acquire_contents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#endif
#endif
extern union devmgr_hdlrs_union sysif_devmgr_actvhdlr_table[__devmgr_method_MAX];

extern union devmgr_hdlrs_union sysif_devmgr_actvcapcallhdlr_table[__devmgr_method_MAX];

extern void sysif_show_devmgr_methods(void);


#ifdef SYSIF_GEN_IFACE
#include <stdint.h>
#include <asm/actv_rpc.h>
#include <hongmeng/syscall.h>
#include <hongmeng/panic.h>
#include <hongmeng/errno.h>
#include <libstrict/strict.h>
#include <libhwsecurec/securec.h>
#include <libsysif/base/server_arg_compat.h>
#ifdef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_register_devhost(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_register_devhost(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, flags), __ARCH_ACTV_RPC_RECV_ARG(uref_t, ap_uref), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, group), __ARCH_ACTV_RPC_RECV_ARG(uref_t, devmgr_ap_uref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_register_devhost(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, flags), __ARCH_ACTV_RPC_RECV_ARG(uref_t, ap_uref), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, group), __ARCH_ACTV_RPC_RECV_ARG(uref_t, devmgr_ap_uref));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_core_devhost_init_done(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_core_devhost_init_done(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_device_add(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group)
{
	UNUSED(__actv_fallback_unused_1, __actv_fallback_unused_2);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_device_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, devname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, devnode_name), __ARCH_ACTV_RPC_RECV_ARG(int, parent), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, flags), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, devt), __ARCH_ACTV_RPC_RECV_ARG(int, vfs_mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, group));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	UNUSED(__actv_fallback_unused_1, __actv_fallback_unused_2);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_device_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, devname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, devnode_name), __ARCH_ACTV_RPC_RECV_ARG(int, parent), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, flags), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, devt), __ARCH_ACTV_RPC_RECV_ARG(int, vfs_mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, group));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_device_del(unsigned long long sender, unsigned long credential, int devid)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_device_del(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, devid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int devid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_device_del(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, devid));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_request_module(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_request_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, args));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, struct hm_actv_buf args)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_request_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, args));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_chrdev_register_region(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_chrdev_register_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, baseminor), __ARCH_ACTV_RPC_RECV_ARG(int, minorct), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_chrdev_register_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, baseminor), __ARCH_ACTV_RPC_RECV_ARG(int, minorct), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_chrdev_unregister_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, baseminor), __ARCH_ACTV_RPC_RECV_ARG(int, minorct));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_chrdev_unregister_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, baseminor), __ARCH_ACTV_RPC_RECV_ARG(int, minorct));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_blkdev_register_region(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_blkdev_register_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_blkdev_register_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_blkdev_unregister_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_blkdev_unregister_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_fops_open(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_fops_open(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, devno), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, vfs_flags), __ARCH_ACTV_RPC_RECV_ARG(int, vfs_mode), __ARCH_ACTV_RPC_RECV_ARG(rref_t, tgt_rref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_fops_open(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_fops_open(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, devno), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, vfs_flags), __ARCH_ACTV_RPC_RECV_ARG(int, vfs_mode), __ARCH_ACTV_RPC_RECV_ARG(rref_t, tgt_rref));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_mgmt_load_module(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_load_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, load_type), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modargs), __ARCH_ACTV_RPC_RECV_ARG(int, devid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_load_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, load_type), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modargs), __ARCH_ACTV_RPC_RECV_ARG(int, devid));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_unload_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, unsigned int cnode_idx)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_unload_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_mgmt_sync(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_sync(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_sync(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_mgmt_dump(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_dump(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct bunch_ipc_attr, attr));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct bunch_ipc_attr attr)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_dump(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct bunch_ipc_attr, attr));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_irq_map(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_map_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_map_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_map(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_map_arg, arg));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_irq_map(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_map_arg arg)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_map_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_map_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_map(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_map_arg, arg));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_irq_fetch(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_fetch_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_fetch_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_fetch(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_fetch_arg, arg));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_fetch_arg arg)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_fetch_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_fetch_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_fetch(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_fetch_arg, arg));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_irq_return(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_return_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_return_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_return(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_return_arg, arg));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_irq_return(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_return_arg arg)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_return_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_return_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_return(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_return_arg, arg));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex(unsigned long long sender, unsigned long credential, int ifindex)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_alloc_ifindex(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_alloc_ifindex(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_register(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_register(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(int, ifindex), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, features));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_register(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, int ifindex, unsigned long long features)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_register(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(int, ifindex), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, features));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_unregister(unsigned long long sender, unsigned long credential, int ifindex)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_unregister(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_unregister(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_net_hmnetd_ready(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_net_hmnetd_ready(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_open(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_open(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex), __ARCH_ACTV_RPC_RECV_ARG(rref_t, tgt_rref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_open(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex, rref_t tgt_rref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_open(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex), __ARCH_ACTV_RPC_RECV_ARG(rref_t, tgt_rref));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_pm_action(unsigned long long sender, unsigned long credential, unsigned int action)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_pm_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, action));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_pm_action(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_pm_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, action));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_pm_power_off(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_pm_power_off(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_pm_power_off(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_pm_reboot(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_pm_reboot(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_cmd, cmd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_pm_reboot(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_cmd, cmd));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_pm_cpuhp_action(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_pm_cpuhp_action(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_procfs_create_data(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_procfs_create_data(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, ops), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, linkname));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_procfs_create_data(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, ops), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, linkname));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_procfs_unlink(unsigned long long sender, unsigned long credential, struct hm_actv_buf name)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_procfs_unlink(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_procfs_unlink(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_procfs_read(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_procfs_write(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_dir(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_dir(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_create_file(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_file(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(int, tagid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, int tagid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_file(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(int, tagid));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_symlink(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, linkname));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_symlink(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, linkname));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_delete(unsigned long long sender, unsigned long credential, struct hm_actv_buf name)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_delete(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_delete(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_notify(unsigned long long sender, unsigned long credential, struct hm_actv_buf name)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_read(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_write(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_write(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, tagid), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, ctx), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, pos), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, actv_buf));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_write(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, tagid), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, ctx), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, pos), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, actv_buf));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_poll(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_poll(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_poll(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_fw_acquire_contents(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, buf), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, size), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, namelen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_fw_acquire_contents(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, buf), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, size), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, namelen));
}

#ifndef __sysif_server_devmgr_no_compat32_handlers__
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
struct compat_x3 {
	unsigned int reserverd;
	unsigned int w3;
};

#else
struct compat_x3 {
	unsigned int w3;
	unsigned int reserverd;
};

#endif
static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_core_register_devhost(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _flags;
	uref_t __maybe_unused _ap_uref;
	struct hm_actv_buf __maybe_unused _group;
	uref_t __maybe_unused _devmgr_ap_uref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_flags, data, 0, arg_sz, model, type, unsigned int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(uref_t);
		type = __type_of(uref_t);
		__fetch_one_arg((void*)&_ap_uref, data, 1, arg_sz, model, type, uref_t, _ap_uref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_group, data, 2, arg_sz, model, type, struct hm_actv_buf, _group)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(uref_t);
		type = __type_of(uref_t);
		__fetch_one_arg((void*)&_devmgr_ap_uref, data, 3, arg_sz, model, type, uref_t, _devmgr_ap_uref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_register_devhost(sender, credential, _flags, _ap_uref, _group, _devmgr_ap_uref);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_register_devhost(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _flags;
	uref_t __maybe_unused _ap_uref;
	struct hm_actv_buf __maybe_unused _group;
	uref_t __maybe_unused _devmgr_ap_uref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_flags, data, 0, arg_sz, model, type, unsigned int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(uref_t);
		type = __type_of(uref_t);
		__fetch_one_arg((void*)&_ap_uref, data, 1, arg_sz, model, type, uref_t, _ap_uref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_group, data, 2, arg_sz, model, type, struct hm_actv_buf, _group)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(uref_t);
		type = __type_of(uref_t);
		__fetch_one_arg((void*)&_devmgr_ap_uref, data, 3, arg_sz, model, type, uref_t, _devmgr_ap_uref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_register_devhost(sender, credential, _flags, _ap_uref, _group, _devmgr_ap_uref);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_core_devhost_init_done(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_core_devhost_init_done(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_devhost_init_done(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_core_devhost_init_done(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_core_device_add(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _devname;
	struct hm_actv_buf __maybe_unused _devnode_name;
	int __maybe_unused _parent;
	unsigned int __maybe_unused _flags;
	unsigned int __maybe_unused _devt;
	int __maybe_unused _vfs_mode;
	struct hm_actv_buf __maybe_unused _group;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_devname, data, 0, arg_sz, model, type, struct hm_actv_buf, _devname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_devnode_name, data, 1, arg_sz, model, type, struct hm_actv_buf, _devnode_name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_parent, data, 2, arg_sz, model, type, int, _parent)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, unsigned int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_devt, data, 4, arg_sz, model, type, unsigned int, _devt)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_vfs_mode, data, 5, arg_sz, model, type, int, _vfs_mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_group, data, 6, arg_sz, model, type, struct hm_actv_buf, _group)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_device_add(sender, credential, _devname, _devnode_name, _parent, _flags, _devt, _vfs_mode, _group);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_add(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_THREE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _devname;
	struct hm_actv_buf __maybe_unused _devnode_name;
	int __maybe_unused _parent;
	unsigned int __maybe_unused _flags;
	unsigned int __maybe_unused _devt;
	int __maybe_unused _vfs_mode;
	struct hm_actv_buf __maybe_unused _group;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_devname, data, 0, arg_sz, model, type, struct hm_actv_buf, _devname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_devnode_name, data, 1, arg_sz, model, type, struct hm_actv_buf, _devnode_name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_parent, data, 2, arg_sz, model, type, int, _parent)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, unsigned int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_devt, data, 4, arg_sz, model, type, unsigned int, _devt)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_vfs_mode, data, 5, arg_sz, model, type, int, _vfs_mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_group, data, 6, arg_sz, model, type, struct hm_actv_buf, _group)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_device_add(sender, credential, _devname, _devnode_name, _parent, _flags, _devt, _vfs_mode, _group);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_core_device_del(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _devid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_devid, data, 0, arg_sz, model, type, int, _devid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_device_del(sender, credential, _devid);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_del(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _devid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_devid, data, 0, arg_sz, model, type, int, _devid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_device_del(sender, credential, _devid);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_core_request_module(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _modname;
	struct hm_actv_buf __maybe_unused _args;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_modname, data, 0, arg_sz, model, type, struct hm_actv_buf, _modname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_args, data, 1, arg_sz, model, type, struct hm_actv_buf, _args)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_request_module(sender, credential, _modname, _args);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_request_module(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _modname;
	struct hm_actv_buf __maybe_unused _args;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_modname, data, 0, arg_sz, model, type, struct hm_actv_buf, _modname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_args, data, 1, arg_sz, model, type, struct hm_actv_buf, _args)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_core_request_module(sender, credential, _modname, _args);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_chrdev_register_region(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _major;
	unsigned int __maybe_unused _baseminor;
	int __maybe_unused _minorct;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_major, data, 0, arg_sz, model, type, unsigned int, _major)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_baseminor, data, 1, arg_sz, model, type, unsigned int, _baseminor)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_minorct, data, 2, arg_sz, model, type, int, _minorct)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 3, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_chrdev_register_region(sender, credential, _major, _baseminor, _minorct, _name);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_register_region(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _major;
	unsigned int __maybe_unused _baseminor;
	int __maybe_unused _minorct;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_major, data, 0, arg_sz, model, type, unsigned int, _major)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_baseminor, data, 1, arg_sz, model, type, unsigned int, _baseminor)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_minorct, data, 2, arg_sz, model, type, int, _minorct)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 3, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_chrdev_register_region(sender, credential, _major, _baseminor, _minorct, _name);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_chrdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _major;
	unsigned int __maybe_unused _baseminor;
	int __maybe_unused _minorct;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_major, data, 0, arg_sz, model, type, unsigned int, _major)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_baseminor, data, 1, arg_sz, model, type, unsigned int, _baseminor)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_minorct, data, 2, arg_sz, model, type, int, _minorct)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_chrdev_unregister_region(sender, credential, _major, _baseminor, _minorct);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _major;
	unsigned int __maybe_unused _baseminor;
	int __maybe_unused _minorct;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_major, data, 0, arg_sz, model, type, unsigned int, _major)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_baseminor, data, 1, arg_sz, model, type, unsigned int, _baseminor)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_minorct, data, 2, arg_sz, model, type, int, _minorct)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_chrdev_unregister_region(sender, credential, _major, _baseminor, _minorct);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_blkdev_register_region(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _major;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_major, data, 0, arg_sz, model, type, unsigned int, _major)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 1, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_blkdev_register_region(sender, credential, _major, _name);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_register_region(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _major;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_major, data, 0, arg_sz, model, type, unsigned int, _major)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 1, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_blkdev_register_region(sender, credential, _major, _name);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_blkdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _major;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_major, data, 0, arg_sz, model, type, unsigned int, _major)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 1, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_blkdev_unregister_region(sender, credential, _major, _name);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _major;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_major, data, 0, arg_sz, model, type, unsigned int, _major)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 1, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_blkdev_unregister_region(sender, credential, _major, _name);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_fops_open(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _devno;
	unsigned int __maybe_unused _vfs_flags;
	int __maybe_unused _vfs_mode;
	rref_t __maybe_unused _tgt_rref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_devno, data, 0, arg_sz, model, type, unsigned int, _devno)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_vfs_flags, data, 1, arg_sz, model, type, unsigned int, _vfs_flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_vfs_mode, data, 2, arg_sz, model, type, int, _vfs_mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(rref_t);
		type = __type_of(rref_t);
		__fetch_one_arg((void*)&_tgt_rref, data, 3, arg_sz, model, type, rref_t, _tgt_rref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_fops_open(sender, credential, _devno, _vfs_flags, _vfs_mode, _tgt_rref);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_fops_open(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _devno;
	unsigned int __maybe_unused _vfs_flags;
	int __maybe_unused _vfs_mode;
	rref_t __maybe_unused _tgt_rref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_devno, data, 0, arg_sz, model, type, unsigned int, _devno)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_vfs_flags, data, 1, arg_sz, model, type, unsigned int, _vfs_flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_vfs_mode, data, 2, arg_sz, model, type, int, _vfs_mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(rref_t);
		type = __type_of(rref_t);
		__fetch_one_arg((void*)&_tgt_rref, data, 3, arg_sz, model, type, rref_t, _tgt_rref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_fops_open(sender, credential, _devno, _vfs_flags, _vfs_mode, _tgt_rref);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_mgmt_load_module(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _load_type;
	struct hm_actv_buf __maybe_unused _modname;
	struct hm_actv_buf __maybe_unused _modargs;
	int __maybe_unused _devid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_load_type, data, 0, arg_sz, model, type, int, _load_type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_modname, data, 1, arg_sz, model, type, struct hm_actv_buf, _modname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_modargs, data, 2, arg_sz, model, type, struct hm_actv_buf, _modargs)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_devid, data, 3, arg_sz, model, type, int, _devid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_load_module(sender, credential, _load_type, _modname, _modargs, _devid);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_load_module(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _load_type;
	struct hm_actv_buf __maybe_unused _modname;
	struct hm_actv_buf __maybe_unused _modargs;
	int __maybe_unused _devid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_load_type, data, 0, arg_sz, model, type, int, _load_type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_modname, data, 1, arg_sz, model, type, struct hm_actv_buf, _modname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_modargs, data, 2, arg_sz, model, type, struct hm_actv_buf, _modargs)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_devid, data, 3, arg_sz, model, type, int, _devid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_load_module(sender, credential, _load_type, _modname, _modargs, _devid);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_mgmt_unload_module(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _modname;
	unsigned int __maybe_unused _cnode_idx;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_modname, data, 0, arg_sz, model, type, struct hm_actv_buf, _modname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cnode_idx, data, 1, arg_sz, model, type, unsigned int, _cnode_idx)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_unload_module(sender, credential, _modname, _cnode_idx);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_unload_module(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _modname;
	unsigned int __maybe_unused _cnode_idx;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_modname, data, 0, arg_sz, model, type, struct hm_actv_buf, _modname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cnode_idx, data, 1, arg_sz, model, type, unsigned int, _cnode_idx)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_unload_module(sender, credential, _modname, _cnode_idx);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_mgmt_sync(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_sync(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_sync(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_sync(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_mgmt_dump(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct bunch_ipc_attr __maybe_unused _attr;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct bunch_ipc_attr);
		type = __type_of(struct bunch_ipc_attr);
		__fetch_one_arg((void*)&_attr, data, 0, arg_sz, model, type, struct bunch_ipc_attr, _attr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_dump(sender, credential, _attr);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_dump(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct bunch_ipc_attr __maybe_unused _attr;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct bunch_ipc_attr);
		type = __type_of(struct bunch_ipc_attr);
		__fetch_one_arg((void*)&_attr, data, 0, arg_sz, model, type, struct bunch_ipc_attr, _attr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_mgmt_dump(sender, credential, _attr);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_irq_map(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct drvcall_devmgr_irq_map_arg __maybe_unused _arg;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct drvcall_devmgr_irq_map_arg);
		type = __type_of(struct drvcall_devmgr_irq_map_arg);
		__fetch_one_arg((void*)&_arg, data, 0, arg_sz, model, type, struct drvcall_devmgr_irq_map_arg, _arg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_map(sender, credential, _arg);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_map(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct drvcall_devmgr_irq_map_arg __maybe_unused _arg;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct drvcall_devmgr_irq_map_arg);
		type = __type_of(struct drvcall_devmgr_irq_map_arg);
		__fetch_one_arg((void*)&_arg, data, 0, arg_sz, model, type, struct drvcall_devmgr_irq_map_arg, _arg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_map(sender, credential, _arg);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_irq_fetch(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct drvcall_devmgr_irq_fetch_arg __maybe_unused _arg;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct drvcall_devmgr_irq_fetch_arg);
		type = __type_of(struct drvcall_devmgr_irq_fetch_arg);
		__fetch_one_arg((void*)&_arg, data, 0, arg_sz, model, type, struct drvcall_devmgr_irq_fetch_arg, _arg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_fetch(sender, credential, _arg);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_fetch(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct drvcall_devmgr_irq_fetch_arg __maybe_unused _arg;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct drvcall_devmgr_irq_fetch_arg);
		type = __type_of(struct drvcall_devmgr_irq_fetch_arg);
		__fetch_one_arg((void*)&_arg, data, 0, arg_sz, model, type, struct drvcall_devmgr_irq_fetch_arg, _arg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_fetch(sender, credential, _arg);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_irq_return(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct drvcall_devmgr_irq_return_arg __maybe_unused _arg;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct drvcall_devmgr_irq_return_arg);
		type = __type_of(struct drvcall_devmgr_irq_return_arg);
		__fetch_one_arg((void*)&_arg, data, 0, arg_sz, model, type, struct drvcall_devmgr_irq_return_arg, _arg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_return(sender, credential, _arg);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_return(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct drvcall_devmgr_irq_return_arg __maybe_unused _arg;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct drvcall_devmgr_irq_return_arg);
		type = __type_of(struct drvcall_devmgr_irq_return_arg);
		__fetch_one_arg((void*)&_arg, data, 0, arg_sz, model, type, struct drvcall_devmgr_irq_return_arg, _arg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_irq_return(sender, credential, _arg);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_net_alloc_ifindex(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _ifindex;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_ifindex, data, 0, arg_sz, model, type, int, _ifindex)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_alloc_ifindex(sender, credential, _ifindex);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_alloc_ifindex(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _ifindex;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_ifindex, data, 0, arg_sz, model, type, int, _ifindex)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_alloc_ifindex(sender, credential, _ifindex);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_net_register(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	int __maybe_unused _ifindex;
	unsigned long long __maybe_unused _features;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_ifindex, data, 1, arg_sz, model, type, int, _ifindex)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_features, data, 2, arg_sz, model, type, unsigned long long, _features)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_register(sender, credential, _name, _ifindex, _features);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_register(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	int __maybe_unused _ifindex;
	unsigned long long __maybe_unused _features;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_ifindex, data, 1, arg_sz, model, type, int, _ifindex)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_features, data, 2, arg_sz, model, type, unsigned long long, _features)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_register(sender, credential, _name, _ifindex, _features);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_net_unregister(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _ifindex;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_ifindex, data, 0, arg_sz, model, type, int, _ifindex)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_unregister(sender, credential, _ifindex);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_unregister(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _ifindex;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_ifindex, data, 0, arg_sz, model, type, int, _ifindex)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_unregister(sender, credential, _ifindex);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_net_hmnetd_ready(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_net_hmnetd_ready(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_hmnetd_ready(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_net_hmnetd_ready(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_net_open(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _ifindex;
	rref_t __maybe_unused _tgt_rref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_ifindex, data, 0, arg_sz, model, type, int, _ifindex)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(rref_t);
		type = __type_of(rref_t);
		__fetch_one_arg((void*)&_tgt_rref, data, 1, arg_sz, model, type, rref_t, _tgt_rref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_open(sender, credential, _ifindex, _tgt_rref);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_open(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _ifindex;
	rref_t __maybe_unused _tgt_rref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_ifindex, data, 0, arg_sz, model, type, int, _ifindex)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(rref_t);
		type = __type_of(rref_t);
		__fetch_one_arg((void*)&_tgt_rref, data, 1, arg_sz, model, type, rref_t, _tgt_rref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_net_open(sender, credential, _ifindex, _tgt_rref);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_pm_action(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _action;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_action, data, 0, arg_sz, model, type, unsigned int, _action)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_pm_action(sender, credential, _action);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_action(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _action;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_action, data, 0, arg_sz, model, type, unsigned int, _action)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_pm_action(sender, credential, _action);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_pm_power_off(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_pm_power_off(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_power_off(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_pm_power_off(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_pm_reboot(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct reboot_cmd __maybe_unused _cmd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct reboot_cmd);
		type = __type_of(struct reboot_cmd);
		__fetch_one_arg((void*)&_cmd, data, 0, arg_sz, model, type, struct reboot_cmd, _cmd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_pm_reboot(sender, credential, _cmd);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_reboot(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct reboot_cmd __maybe_unused _cmd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct reboot_cmd);
		type = __type_of(struct reboot_cmd);
		__fetch_one_arg((void*)&_cmd, data, 0, arg_sz, model, type, struct reboot_cmd, _cmd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_pm_reboot(sender, credential, _cmd);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_pm_cpuhp_action(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_pm_cpuhp_action(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_cpuhp_action(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_pm_cpuhp_action(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_procfs_create_data(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	unsigned int __maybe_unused _mode;
	struct hm_actv_buf __maybe_unused _ops;
	struct hm_actv_buf __maybe_unused _linkname;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_mode, data, 1, arg_sz, model, type, unsigned int, _mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_ops, data, 2, arg_sz, model, type, struct hm_actv_buf, _ops)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_linkname, data, 3, arg_sz, model, type, struct hm_actv_buf, _linkname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_procfs_create_data(sender, credential, _name, _mode, _ops, _linkname);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_create_data(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	unsigned int __maybe_unused _mode;
	struct hm_actv_buf __maybe_unused _ops;
	struct hm_actv_buf __maybe_unused _linkname;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_mode, data, 1, arg_sz, model, type, unsigned int, _mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_ops, data, 2, arg_sz, model, type, struct hm_actv_buf, _ops)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_linkname, data, 3, arg_sz, model, type, struct hm_actv_buf, _linkname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_procfs_create_data(sender, credential, _name, _mode, _ops, _linkname);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_procfs_unlink(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_procfs_unlink(sender, credential, _name);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_unlink(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_procfs_unlink(sender, credential, _name);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_procfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_procfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_dir(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	unsigned int __maybe_unused _mode;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_mode, data, 1, arg_sz, model, type, unsigned int, _mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_dir(sender, credential, _name, _mode);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_dir(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	unsigned int __maybe_unused _mode;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_mode, data, 1, arg_sz, model, type, unsigned int, _mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_dir(sender, credential, _name, _mode);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_file(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	unsigned int __maybe_unused _mode;
	int __maybe_unused _tagid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_mode, data, 1, arg_sz, model, type, unsigned int, _mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_tagid, data, 2, arg_sz, model, type, int, _tagid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_file(sender, credential, _name, _mode, _tagid);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_file(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	unsigned int __maybe_unused _mode;
	int __maybe_unused _tagid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_mode, data, 1, arg_sz, model, type, unsigned int, _mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_tagid, data, 2, arg_sz, model, type, int, _tagid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_file(sender, credential, _name, _mode, _tagid);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_symlink(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	unsigned int __maybe_unused _mode;
	struct hm_actv_buf __maybe_unused _linkname;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_mode, data, 1, arg_sz, model, type, unsigned int, _mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_linkname, data, 2, arg_sz, model, type, struct hm_actv_buf, _linkname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_symlink(sender, credential, _name, _mode, _linkname);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_symlink(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	unsigned int __maybe_unused _mode;
	struct hm_actv_buf __maybe_unused _linkname;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_mode, data, 1, arg_sz, model, type, unsigned int, _mode)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_linkname, data, 2, arg_sz, model, type, struct hm_actv_buf, _linkname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_create_symlink(sender, credential, _name, _mode, _linkname);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_sysfs_delete(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_delete(sender, credential, _name);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_delete(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_delete(sender, credential, _name);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_sysfs_notify(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_notify(sender, credential, _name);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_notify(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct hm_actv_buf __maybe_unused _name;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_name, data, 0, arg_sz, model, type, struct hm_actv_buf, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_notify(sender, credential, _name);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_sysfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_sysfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _tagid;
	unsigned long long __maybe_unused _ctx;
	unsigned long long __maybe_unused _pos;
	struct hm_actv_buf __maybe_unused _actv_buf;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_tagid, data, 0, arg_sz, model, type, int, _tagid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_ctx, data, 1, arg_sz, model, type, unsigned long long, _ctx)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_pos, data, 2, arg_sz, model, type, unsigned long long, _pos)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_actv_buf, data, 3, arg_sz, model, type, struct hm_actv_buf, _actv_buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_write(sender, credential, _tagid, _ctx, _pos, _actv_buf);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _tagid;
	unsigned long long __maybe_unused _ctx;
	unsigned long long __maybe_unused _pos;
	struct hm_actv_buf __maybe_unused _actv_buf;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_tagid, data, 0, arg_sz, model, type, int, _tagid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_ctx, data, 1, arg_sz, model, type, unsigned long long, _ctx)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_pos, data, 2, arg_sz, model, type, unsigned long long, _pos)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct hm_actv_buf);
		type = __type_of(struct hm_actv_buf);
		__fetch_one_arg((void*)&_actv_buf, data, 3, arg_sz, model, type, struct hm_actv_buf, _actv_buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_write(sender, credential, _tagid, _ctx, _pos, _actv_buf);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_sysfs_poll(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_poll(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_poll(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_drvhandler_devmgr_sysfs_poll(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_compat_fw_acquire_contents(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long __maybe_unused _buf;
	unsigned int __maybe_unused _size;
	unsigned long __maybe_unused _name;
	unsigned int __maybe_unused _namelen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_buf, data, 0, arg_sz, model, type, unsigned long, _buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_size, data, 1, arg_sz, model, type, unsigned int, _size)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_name, data, 2, arg_sz, model, type, unsigned long, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_namelen, data, 3, arg_sz, model, type, unsigned int, _namelen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_fw_acquire_contents(sender, credential, _buf, _size, _name, _namelen);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_compat_fw_acquire_contents(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long __maybe_unused _buf;
	unsigned int __maybe_unused _size;
	unsigned long __maybe_unused _name;
	unsigned int __maybe_unused _namelen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_buf, data, 0, arg_sz, model, type, unsigned long, _buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_size, data, 1, arg_sz, model, type, unsigned int, _size)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_name, data, 2, arg_sz, model, type, unsigned long, _name)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_namelen, data, 3, arg_sz, model, type, unsigned int, _namelen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_drvhandler_devmgr_fw_acquire_contents(sender, credential, _buf, _size, _name, _namelen);
}

#endif
#else
static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_register_devhost(unsigned long long sender, unsigned long credential, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_core_register_devhost(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, flags), __ARCH_ACTV_RPC_RECV_ARG(uref_t, ap_uref), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, group), __ARCH_ACTV_RPC_RECV_ARG(uref_t, devmgr_ap_uref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_core_register_devhost(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, flags), __ARCH_ACTV_RPC_RECV_ARG(uref_t, ap_uref), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, group), __ARCH_ACTV_RPC_RECV_ARG(uref_t, devmgr_ap_uref));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_drvhandler_devmgr_core_devhost_init_done(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_drvhandler_devmgr_core_devhost_init_done(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_device_add(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group)
{
	UNUSED(__actv_fallback_unused_1, __actv_fallback_unused_2);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_core_device_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, devname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, devnode_name), __ARCH_ACTV_RPC_RECV_ARG(int, parent), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, flags), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, devt), __ARCH_ACTV_RPC_RECV_ARG(int, vfs_mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, group));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	UNUSED(__actv_fallback_unused_1, __actv_fallback_unused_2);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_core_device_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, devname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, devnode_name), __ARCH_ACTV_RPC_RECV_ARG(int, parent), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, flags), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, devt), __ARCH_ACTV_RPC_RECV_ARG(int, vfs_mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, group));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_device_del(unsigned long long sender, unsigned long credential, int devid)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_core_device_del(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, devid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int devid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_core_device_del(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, devid));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_core_request_module(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, struct hm_actv_buf args)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_core_request_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, args));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, struct hm_actv_buf args)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_core_request_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, args));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_chrdev_register_region(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_chrdev_register_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, baseminor), __ARCH_ACTV_RPC_RECV_ARG(int, minorct), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_chrdev_register_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, baseminor), __ARCH_ACTV_RPC_RECV_ARG(int, minorct), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned int major, unsigned int baseminor, int minorct)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_chrdev_unregister_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, baseminor), __ARCH_ACTV_RPC_RECV_ARG(int, minorct));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, unsigned int baseminor, int minorct)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_chrdev_unregister_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, baseminor), __ARCH_ACTV_RPC_RECV_ARG(int, minorct));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_blkdev_register_region(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_blkdev_register_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_blkdev_register_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region(unsigned long long sender, unsigned long credential, unsigned int major, struct hm_actv_buf name)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_blkdev_unregister_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int major, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_blkdev_unregister_region(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, major), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_fops_open(unsigned long long sender, unsigned long credential, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_fops_open(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, devno), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, vfs_flags), __ARCH_ACTV_RPC_RECV_ARG(int, vfs_mode), __ARCH_ACTV_RPC_RECV_ARG(rref_t, tgt_rref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_fops_open(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_fops_open(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, devno), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, vfs_flags), __ARCH_ACTV_RPC_RECV_ARG(int, vfs_mode), __ARCH_ACTV_RPC_RECV_ARG(rref_t, tgt_rref));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_mgmt_load_module(unsigned long long sender, unsigned long credential, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_mgmt_load_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, load_type), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modargs), __ARCH_ACTV_RPC_RECV_ARG(int, devid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_mgmt_load_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, load_type), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modargs), __ARCH_ACTV_RPC_RECV_ARG(int, devid));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module(unsigned long long sender, unsigned long credential, struct hm_actv_buf modname, unsigned int cnode_idx)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_mgmt_unload_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf modname, unsigned int cnode_idx)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_mgmt_unload_module(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, modname), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_mgmt_sync(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_drvhandler_devmgr_mgmt_sync(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_drvhandler_devmgr_mgmt_sync(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_mgmt_dump(unsigned long long sender, unsigned long credential, struct bunch_ipc_attr attr)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_mgmt_dump(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct bunch_ipc_attr, attr));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct bunch_ipc_attr attr)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct bunch_ipc_attr), __arch_actv_rpc_stksz_alignment(struct bunch_ipc_attr));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_mgmt_dump(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct bunch_ipc_attr, attr));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_irq_map(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_map_arg arg)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_map_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_map_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_irq_map(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_map_arg, arg));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_irq_map(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_map_arg arg)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_map_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_map_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_irq_map(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_map_arg, arg));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_irq_fetch(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_fetch_arg arg)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_fetch_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_fetch_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_irq_fetch(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_fetch_arg, arg));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_fetch_arg arg)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_fetch_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_fetch_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_irq_fetch(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_fetch_arg, arg));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_irq_return(unsigned long long sender, unsigned long credential, struct drvcall_devmgr_irq_return_arg arg)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_return_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_return_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_irq_return(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_return_arg, arg));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_irq_return(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct drvcall_devmgr_irq_return_arg arg)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct drvcall_devmgr_irq_return_arg), __arch_actv_rpc_stksz_alignment(struct drvcall_devmgr_irq_return_arg));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_irq_return(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct drvcall_devmgr_irq_return_arg, arg));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex(unsigned long long sender, unsigned long credential, int ifindex)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_net_alloc_ifindex(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_net_alloc_ifindex(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_register(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, int ifindex, unsigned long long features)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_net_register(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(int, ifindex), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, features));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_register(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, int ifindex, unsigned long long features)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_net_register(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(int, ifindex), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, features));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_unregister(unsigned long long sender, unsigned long credential, int ifindex)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_net_unregister(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_net_unregister(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_drvhandler_devmgr_net_hmnetd_ready(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_drvhandler_devmgr_net_hmnetd_ready(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_net_open(unsigned long long sender, unsigned long credential, int ifindex, rref_t tgt_rref)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_net_open(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex), __ARCH_ACTV_RPC_RECV_ARG(rref_t, tgt_rref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_net_open(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int ifindex, rref_t tgt_rref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(rref_t), __arch_actv_rpc_stksz_alignment(rref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_net_open(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, ifindex), __ARCH_ACTV_RPC_RECV_ARG(rref_t, tgt_rref));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_pm_action(unsigned long long sender, unsigned long credential, unsigned int action)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_pm_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, action));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_pm_action(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int action)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_pm_action(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, action));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_pm_power_off(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_drvhandler_devmgr_pm_power_off(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_drvhandler_devmgr_pm_power_off(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_pm_reboot(unsigned long long sender, unsigned long credential, struct reboot_cmd cmd)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_pm_reboot(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_cmd, cmd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct reboot_cmd cmd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct reboot_cmd), __arch_actv_rpc_stksz_alignment(struct reboot_cmd));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_pm_reboot(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct reboot_cmd, cmd));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_drvhandler_devmgr_pm_cpuhp_action(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_drvhandler_devmgr_pm_cpuhp_action(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_procfs_create_data(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_procfs_create_data(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, ops), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, linkname));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_procfs_create_data(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, ops), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, linkname));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_procfs_unlink(unsigned long long sender, unsigned long credential, struct hm_actv_buf name)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_procfs_unlink(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_procfs_unlink(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_procfs_read(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_drvhandler_devmgr_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_drvhandler_devmgr_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_procfs_write(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_drvhandler_devmgr_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_drvhandler_devmgr_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_create_dir(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_create_dir(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_create_file(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, int tagid)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_create_file(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(int, tagid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, int tagid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_create_file(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(int, tagid));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink(unsigned long long sender, unsigned long credential, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_create_symlink(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, linkname));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_create_symlink(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, mode), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, linkname));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_delete(unsigned long long sender, unsigned long credential, struct hm_actv_buf name)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_delete(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_delete(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_notify(unsigned long long sender, unsigned long credential, struct hm_actv_buf name)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct hm_actv_buf name)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, name));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_read(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_drvhandler_devmgr_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_drvhandler_devmgr_sysfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_write(unsigned long long sender, unsigned long credential, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_write(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, tagid), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, ctx), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, pos), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, actv_buf));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct hm_actv_buf), __arch_actv_rpc_stksz_alignment(struct hm_actv_buf));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_sysfs_write(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, tagid), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, ctx), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, pos), __ARCH_ACTV_RPC_RECV_ARG(struct hm_actv_buf, actv_buf));
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_sysfs_poll(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_drvhandler_devmgr_sysfs_poll(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_drvhandler_devmgr_sysfs_poll(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents(unsigned long long sender, unsigned long credential, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_fw_acquire_contents(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, buf), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, size), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, namelen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_drvhandler_devmgr_fw_acquire_contents(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, buf), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, size), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, name), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, namelen));
}

#endif
#ifdef __sysif_server_devmgr_no_compat32_handlers__
union devmgr_hdlrs_union sysif_devmgr_actvhdlr_table[__devmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __devmgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__devmgr_method_core_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_register_devhost] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_register_devhost = (&__actvbridgehdlr_drvhandler_devmgr_core_register_devhost)
	},
	[__devmgr_method_core_devhost_init_done] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done = (&__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done)
	},
	[__devmgr_method_core_device_add] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_device_add = (&__actvbridgehdlr_drvhandler_devmgr_core_device_add)
	},
	[__devmgr_method_core_device_del] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_device_del = (&__actvbridgehdlr_drvhandler_devmgr_core_device_del)
	},
	[__devmgr_method_core_request_module] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_request_module = (&__actvbridgehdlr_drvhandler_devmgr_core_request_module)
	},
	[__devmgr_method_chrdev_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_register_region] = {
		.p__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region = (&__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region)
	},
	[__devmgr_method_chrdev_unregister_region] = {
		.p__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region = (&__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region)
	},
	[__devmgr_method_blkdev_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_register_region] = {
		.p__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region = (&__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region)
	},
	[__devmgr_method_blkdev_unregister_region] = {
		.p__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region = (&__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region)
	},
	[__devmgr_method_fops_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fops_open] = {
		.p__actvbridgehdlr_drvhandler_devmgr_fops_open = (&__actvbridgehdlr_drvhandler_devmgr_fops_open)
	},
	[__devmgr_method_mgmt_rsvd_4] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_load_module] = {
		.p__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module = (&__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module)
	},
	[__devmgr_method_mgmt_unload_module] = {
		.p__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module = (&__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module)
	},
	[__devmgr_method_mgmt_sync] = {
		.p__actvbridgehdlr_drvhandler_devmgr_mgmt_sync = (&__actvbridgehdlr_drvhandler_devmgr_mgmt_sync)
	},
	[__devmgr_method_mgmt_dump] = {
		.p__actvbridgehdlr_drvhandler_devmgr_mgmt_dump = (&__actvbridgehdlr_drvhandler_devmgr_mgmt_dump)
	},
	[__devmgr_method_irq_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_irq_map] = {
		.p__actvbridgehdlr_drvhandler_devmgr_irq_map = (&__actvbridgehdlr_drvhandler_devmgr_irq_map)
	},
	[__devmgr_method_irq_fetch] = {
		.p__actvbridgehdlr_drvhandler_devmgr_irq_fetch = (&__actvbridgehdlr_drvhandler_devmgr_irq_fetch)
	},
	[__devmgr_method_irq_return] = {
		.p__actvbridgehdlr_drvhandler_devmgr_irq_return = (&__actvbridgehdlr_drvhandler_devmgr_irq_return)
	},
	[__devmgr_method_net_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_alloc_ifindex] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex = (&__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex)
	},
	[__devmgr_method_net_register] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_register = (&__actvbridgehdlr_drvhandler_devmgr_net_register)
	},
	[__devmgr_method_net_unregister] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_unregister = (&__actvbridgehdlr_drvhandler_devmgr_net_unregister)
	},
	[__devmgr_method_net_hmnetd_ready] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready = (&__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready)
	},
	[__devmgr_method_net_open] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_open = (&__actvbridgehdlr_drvhandler_devmgr_net_open)
	},
	[__devmgr_method_pm_action] = {
		.p__actvbridgehdlr_drvhandler_devmgr_pm_action = (&__actvbridgehdlr_drvhandler_devmgr_pm_action)
	},
	[__devmgr_method_pm_power_off] = {
		.p__actvbridgehdlr_drvhandler_devmgr_pm_power_off = (&__actvbridgehdlr_drvhandler_devmgr_pm_power_off)
	},
	[__devmgr_method_pm_reboot] = {
		.p__actvbridgehdlr_drvhandler_devmgr_pm_reboot = (&__actvbridgehdlr_drvhandler_devmgr_pm_reboot)
	},
	[__devmgr_method_pm_cpuhp_action] = {
		.p__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action = (&__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action)
	},
	[__devmgr_method_procfs_create_data] = {
		.p__actvbridgehdlr_drvhandler_devmgr_procfs_create_data = (&__actvbridgehdlr_drvhandler_devmgr_procfs_create_data)
	},
	[__devmgr_method_procfs_unlink] = {
		.p__actvbridgehdlr_drvhandler_devmgr_procfs_unlink = (&__actvbridgehdlr_drvhandler_devmgr_procfs_unlink)
	},
	[__devmgr_method_procfs_read] = {
		.p__actvbridgehdlr_drvhandler_devmgr_procfs_read = (&__actvbridgehdlr_drvhandler_devmgr_procfs_read)
	},
	[__devmgr_method_procfs_write] = {
		.p__actvbridgehdlr_drvhandler_devmgr_procfs_write = (&__actvbridgehdlr_drvhandler_devmgr_procfs_write)
	},
	[__devmgr_method_sysfs_create_dir] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir)
	},
	[__devmgr_method_sysfs_create_file] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file)
	},
	[__devmgr_method_sysfs_create_symlink] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink)
	},
	[__devmgr_method_sysfs_delete] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_delete = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_delete)
	},
	[__devmgr_method_sysfs_notify] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_notify = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_notify)
	},
	[__devmgr_method_sysfs_read] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_read = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_read)
	},
	[__devmgr_method_sysfs_write] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_write = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_write)
	},
	[__devmgr_method_sysfs_poll] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_poll = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_poll)
	},
	[__devmgr_method_fw_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fw_acquire_contents] = {
		.p__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents = (&__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents)
	}
};

union devmgr_hdlrs_union sysif_devmgr_actvcapcallhdlr_table[__devmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __devmgr_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__devmgr_method_core_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_register_devhost] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost)
	},
	[__devmgr_method_core_devhost_init_done] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done)
	},
	[__devmgr_method_core_device_add] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add)
	},
	[__devmgr_method_core_device_del] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del)
	},
	[__devmgr_method_core_request_module] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module)
	},
	[__devmgr_method_chrdev_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_register_region] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region)
	},
	[__devmgr_method_chrdev_unregister_region] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region)
	},
	[__devmgr_method_blkdev_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_register_region] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region)
	},
	[__devmgr_method_blkdev_unregister_region] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region)
	},
	[__devmgr_method_fops_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fops_open] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open = (&__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open)
	},
	[__devmgr_method_mgmt_rsvd_4] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_load_module] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module = (&__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module)
	},
	[__devmgr_method_mgmt_unload_module] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module = (&__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module)
	},
	[__devmgr_method_mgmt_sync] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync = (&__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync)
	},
	[__devmgr_method_mgmt_dump] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump = (&__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump)
	},
	[__devmgr_method_irq_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_irq_map] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map = (&__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map)
	},
	[__devmgr_method_irq_fetch] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch = (&__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch)
	},
	[__devmgr_method_irq_return] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return = (&__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return)
	},
	[__devmgr_method_net_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_alloc_ifindex] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex)
	},
	[__devmgr_method_net_register] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_register = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_register)
	},
	[__devmgr_method_net_unregister] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister)
	},
	[__devmgr_method_net_hmnetd_ready] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready)
	},
	[__devmgr_method_net_open] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_open = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_open)
	},
	[__devmgr_method_pm_action] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action = (&__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action)
	},
	[__devmgr_method_pm_power_off] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off = (&__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off)
	},
	[__devmgr_method_pm_reboot] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot = (&__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot)
	},
	[__devmgr_method_pm_cpuhp_action] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action = (&__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action)
	},
	[__devmgr_method_procfs_create_data] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data = (&__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data)
	},
	[__devmgr_method_procfs_unlink] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink = (&__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink)
	},
	[__devmgr_method_procfs_read] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read = (&__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read)
	},
	[__devmgr_method_procfs_write] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write = (&__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write)
	},
	[__devmgr_method_sysfs_create_dir] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir)
	},
	[__devmgr_method_sysfs_create_file] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file)
	},
	[__devmgr_method_sysfs_create_symlink] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink)
	},
	[__devmgr_method_sysfs_delete] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete)
	},
	[__devmgr_method_sysfs_notify] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify)
	},
	[__devmgr_method_sysfs_read] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read)
	},
	[__devmgr_method_sysfs_write] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write)
	},
	[__devmgr_method_sysfs_poll] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll)
	},
	[__devmgr_method_fw_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fw_acquire_contents] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents = (&__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents)
	}
};

#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
union devmgr_hdlrs_union sysif_devmgr_actvhdlr_table[__devmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __devmgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__devmgr_method_core_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_register_devhost * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_register_devhost = (&__actvbridgehdlr_drvhandler_devmgr_core_register_devhost)
	},
	[__devmgr_method_core_register_devhost * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_core_register_devhost = (&__actvbridgehdlr_drvhandler_devmgr_compat_core_register_devhost)
	},
	[__devmgr_method_core_devhost_init_done * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done = (&__actvbridgehdlr_drvhandler_devmgr_core_devhost_init_done)
	},
	[__devmgr_method_core_devhost_init_done * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_core_devhost_init_done = (&__actvbridgehdlr_drvhandler_devmgr_compat_core_devhost_init_done)
	},
	[__devmgr_method_core_device_add * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_device_add = (&__actvbridgehdlr_drvhandler_devmgr_core_device_add)
	},
	[__devmgr_method_core_device_add * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_core_device_add = (&__actvbridgehdlr_drvhandler_devmgr_compat_core_device_add)
	},
	[__devmgr_method_core_device_del * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_device_del = (&__actvbridgehdlr_drvhandler_devmgr_core_device_del)
	},
	[__devmgr_method_core_device_del * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_core_device_del = (&__actvbridgehdlr_drvhandler_devmgr_compat_core_device_del)
	},
	[__devmgr_method_core_request_module * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_core_request_module = (&__actvbridgehdlr_drvhandler_devmgr_core_request_module)
	},
	[__devmgr_method_core_request_module * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_core_request_module = (&__actvbridgehdlr_drvhandler_devmgr_compat_core_request_module)
	},
	[__devmgr_method_chrdev_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_register_region * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region = (&__actvbridgehdlr_drvhandler_devmgr_chrdev_register_region)
	},
	[__devmgr_method_chrdev_register_region * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_register_region = (&__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_register_region)
	},
	[__devmgr_method_chrdev_unregister_region * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region = (&__actvbridgehdlr_drvhandler_devmgr_chrdev_unregister_region)
	},
	[__devmgr_method_chrdev_unregister_region * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_unregister_region = (&__actvbridgehdlr_drvhandler_devmgr_compat_chrdev_unregister_region)
	},
	[__devmgr_method_blkdev_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_register_region * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region = (&__actvbridgehdlr_drvhandler_devmgr_blkdev_register_region)
	},
	[__devmgr_method_blkdev_register_region * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_register_region = (&__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_register_region)
	},
	[__devmgr_method_blkdev_unregister_region * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region = (&__actvbridgehdlr_drvhandler_devmgr_blkdev_unregister_region)
	},
	[__devmgr_method_blkdev_unregister_region * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_unregister_region = (&__actvbridgehdlr_drvhandler_devmgr_compat_blkdev_unregister_region)
	},
	[__devmgr_method_fops_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fops_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fops_open * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_fops_open = (&__actvbridgehdlr_drvhandler_devmgr_fops_open)
	},
	[__devmgr_method_fops_open * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_fops_open = (&__actvbridgehdlr_drvhandler_devmgr_compat_fops_open)
	},
	[__devmgr_method_mgmt_rsvd_4 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_4 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_load_module * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module = (&__actvbridgehdlr_drvhandler_devmgr_mgmt_load_module)
	},
	[__devmgr_method_mgmt_load_module * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_load_module = (&__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_load_module)
	},
	[__devmgr_method_mgmt_unload_module * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module = (&__actvbridgehdlr_drvhandler_devmgr_mgmt_unload_module)
	},
	[__devmgr_method_mgmt_unload_module * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_unload_module = (&__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_unload_module)
	},
	[__devmgr_method_mgmt_sync * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_mgmt_sync = (&__actvbridgehdlr_drvhandler_devmgr_mgmt_sync)
	},
	[__devmgr_method_mgmt_sync * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_sync = (&__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_sync)
	},
	[__devmgr_method_mgmt_dump * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_mgmt_dump = (&__actvbridgehdlr_drvhandler_devmgr_mgmt_dump)
	},
	[__devmgr_method_mgmt_dump * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_dump = (&__actvbridgehdlr_drvhandler_devmgr_compat_mgmt_dump)
	},
	[__devmgr_method_irq_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_irq_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_irq_map * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_irq_map = (&__actvbridgehdlr_drvhandler_devmgr_irq_map)
	},
	[__devmgr_method_irq_map * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_irq_map = (&__actvbridgehdlr_drvhandler_devmgr_compat_irq_map)
	},
	[__devmgr_method_irq_fetch * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_irq_fetch = (&__actvbridgehdlr_drvhandler_devmgr_irq_fetch)
	},
	[__devmgr_method_irq_fetch * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_irq_fetch = (&__actvbridgehdlr_drvhandler_devmgr_compat_irq_fetch)
	},
	[__devmgr_method_irq_return * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_irq_return = (&__actvbridgehdlr_drvhandler_devmgr_irq_return)
	},
	[__devmgr_method_irq_return * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_irq_return = (&__actvbridgehdlr_drvhandler_devmgr_compat_irq_return)
	},
	[__devmgr_method_net_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_alloc_ifindex * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex = (&__actvbridgehdlr_drvhandler_devmgr_net_alloc_ifindex)
	},
	[__devmgr_method_net_alloc_ifindex * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_net_alloc_ifindex = (&__actvbridgehdlr_drvhandler_devmgr_compat_net_alloc_ifindex)
	},
	[__devmgr_method_net_register * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_register = (&__actvbridgehdlr_drvhandler_devmgr_net_register)
	},
	[__devmgr_method_net_register * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_net_register = (&__actvbridgehdlr_drvhandler_devmgr_compat_net_register)
	},
	[__devmgr_method_net_unregister * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_unregister = (&__actvbridgehdlr_drvhandler_devmgr_net_unregister)
	},
	[__devmgr_method_net_unregister * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_net_unregister = (&__actvbridgehdlr_drvhandler_devmgr_compat_net_unregister)
	},
	[__devmgr_method_net_hmnetd_ready * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready = (&__actvbridgehdlr_drvhandler_devmgr_net_hmnetd_ready)
	},
	[__devmgr_method_net_hmnetd_ready * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_net_hmnetd_ready = (&__actvbridgehdlr_drvhandler_devmgr_compat_net_hmnetd_ready)
	},
	[__devmgr_method_net_open * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_net_open = (&__actvbridgehdlr_drvhandler_devmgr_net_open)
	},
	[__devmgr_method_net_open * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_net_open = (&__actvbridgehdlr_drvhandler_devmgr_compat_net_open)
	},
	[__devmgr_method_pm_action * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_pm_action = (&__actvbridgehdlr_drvhandler_devmgr_pm_action)
	},
	[__devmgr_method_pm_action * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_pm_action = (&__actvbridgehdlr_drvhandler_devmgr_compat_pm_action)
	},
	[__devmgr_method_pm_power_off * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_pm_power_off = (&__actvbridgehdlr_drvhandler_devmgr_pm_power_off)
	},
	[__devmgr_method_pm_power_off * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_pm_power_off = (&__actvbridgehdlr_drvhandler_devmgr_compat_pm_power_off)
	},
	[__devmgr_method_pm_reboot * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_pm_reboot = (&__actvbridgehdlr_drvhandler_devmgr_pm_reboot)
	},
	[__devmgr_method_pm_reboot * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_pm_reboot = (&__actvbridgehdlr_drvhandler_devmgr_compat_pm_reboot)
	},
	[__devmgr_method_pm_cpuhp_action * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action = (&__actvbridgehdlr_drvhandler_devmgr_pm_cpuhp_action)
	},
	[__devmgr_method_pm_cpuhp_action * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_pm_cpuhp_action = (&__actvbridgehdlr_drvhandler_devmgr_compat_pm_cpuhp_action)
	},
	[__devmgr_method_procfs_create_data * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_procfs_create_data = (&__actvbridgehdlr_drvhandler_devmgr_procfs_create_data)
	},
	[__devmgr_method_procfs_create_data * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_create_data = (&__actvbridgehdlr_drvhandler_devmgr_compat_procfs_create_data)
	},
	[__devmgr_method_procfs_unlink * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_procfs_unlink = (&__actvbridgehdlr_drvhandler_devmgr_procfs_unlink)
	},
	[__devmgr_method_procfs_unlink * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_unlink = (&__actvbridgehdlr_drvhandler_devmgr_compat_procfs_unlink)
	},
	[__devmgr_method_procfs_read * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_procfs_read = (&__actvbridgehdlr_drvhandler_devmgr_procfs_read)
	},
	[__devmgr_method_procfs_read * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_read = (&__actvbridgehdlr_drvhandler_devmgr_compat_procfs_read)
	},
	[__devmgr_method_procfs_write * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_procfs_write = (&__actvbridgehdlr_drvhandler_devmgr_procfs_write)
	},
	[__devmgr_method_procfs_write * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_procfs_write = (&__actvbridgehdlr_drvhandler_devmgr_compat_procfs_write)
	},
	[__devmgr_method_sysfs_create_dir * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_create_dir)
	},
	[__devmgr_method_sysfs_create_dir * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_dir = (&__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_dir)
	},
	[__devmgr_method_sysfs_create_file * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_create_file)
	},
	[__devmgr_method_sysfs_create_file * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_file = (&__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_file)
	},
	[__devmgr_method_sysfs_create_symlink * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_create_symlink)
	},
	[__devmgr_method_sysfs_create_symlink * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_symlink = (&__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_create_symlink)
	},
	[__devmgr_method_sysfs_delete * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_delete = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_delete)
	},
	[__devmgr_method_sysfs_delete * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_delete = (&__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_delete)
	},
	[__devmgr_method_sysfs_notify * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_notify = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_notify)
	},
	[__devmgr_method_sysfs_notify * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_notify = (&__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_notify)
	},
	[__devmgr_method_sysfs_read * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_read = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_read)
	},
	[__devmgr_method_sysfs_read * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_read = (&__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_read)
	},
	[__devmgr_method_sysfs_write * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_write = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_write)
	},
	[__devmgr_method_sysfs_write * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_write = (&__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_write)
	},
	[__devmgr_method_sysfs_poll * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_sysfs_poll = (&__actvbridgehdlr_drvhandler_devmgr_sysfs_poll)
	},
	[__devmgr_method_sysfs_poll * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_poll = (&__actvbridgehdlr_drvhandler_devmgr_compat_sysfs_poll)
	},
	[__devmgr_method_fw_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fw_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fw_acquire_contents * 2] = {
		.p__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents = (&__actvbridgehdlr_drvhandler_devmgr_fw_acquire_contents)
	},
	[__devmgr_method_fw_acquire_contents * 2 + 1] = {
		.p__actvbridgehdlr_drvhandler_devmgr_compat_fw_acquire_contents = (&__actvbridgehdlr_drvhandler_devmgr_compat_fw_acquire_contents)
	}
};

#endif
union devmgr_hdlrs_union sysif_devmgr_actvcapcallhdlr_table[__devmgr_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __devmgr_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__devmgr_method_core_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_core_register_devhost * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_register_devhost)
	},
	[__devmgr_method_core_register_devhost * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_register_devhost = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_register_devhost)
	},
	[__devmgr_method_core_devhost_init_done * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_devhost_init_done)
	},
	[__devmgr_method_core_devhost_init_done * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_devhost_init_done = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_devhost_init_done)
	},
	[__devmgr_method_core_device_add * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_add)
	},
	[__devmgr_method_core_device_add * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_add = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_add)
	},
	[__devmgr_method_core_device_del * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_device_del)
	},
	[__devmgr_method_core_device_del * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_del = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_device_del)
	},
	[__devmgr_method_core_request_module * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module = (&__actvbridgecapcallhdlr_drvhandler_devmgr_core_request_module)
	},
	[__devmgr_method_core_request_module * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_request_module = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_core_request_module)
	},
	[__devmgr_method_chrdev_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_chrdev_register_region * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_register_region)
	},
	[__devmgr_method_chrdev_register_region * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_register_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_register_region)
	},
	[__devmgr_method_chrdev_unregister_region * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_chrdev_unregister_region)
	},
	[__devmgr_method_chrdev_unregister_region * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_unregister_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_chrdev_unregister_region)
	},
	[__devmgr_method_blkdev_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_blkdev_register_region * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_register_region)
	},
	[__devmgr_method_blkdev_register_region * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_register_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_register_region)
	},
	[__devmgr_method_blkdev_unregister_region * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_blkdev_unregister_region)
	},
	[__devmgr_method_blkdev_unregister_region * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_unregister_region = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_blkdev_unregister_region)
	},
	[__devmgr_method_fops_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fops_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fops_open * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open = (&__actvbridgecapcallhdlr_drvhandler_devmgr_fops_open)
	},
	[__devmgr_method_fops_open * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fops_open = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fops_open)
	},
	[__devmgr_method_mgmt_rsvd_4 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_4 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_mgmt_load_module * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module = (&__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_load_module)
	},
	[__devmgr_method_mgmt_load_module * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_load_module = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_load_module)
	},
	[__devmgr_method_mgmt_unload_module * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module = (&__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_unload_module)
	},
	[__devmgr_method_mgmt_unload_module * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_unload_module = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_unload_module)
	},
	[__devmgr_method_mgmt_sync * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync = (&__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_sync)
	},
	[__devmgr_method_mgmt_sync * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_sync = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_sync)
	},
	[__devmgr_method_mgmt_dump * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump = (&__actvbridgecapcallhdlr_drvhandler_devmgr_mgmt_dump)
	},
	[__devmgr_method_mgmt_dump * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_dump = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_mgmt_dump)
	},
	[__devmgr_method_irq_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_irq_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_irq_map * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map = (&__actvbridgecapcallhdlr_drvhandler_devmgr_irq_map)
	},
	[__devmgr_method_irq_map * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_map = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_map)
	},
	[__devmgr_method_irq_fetch * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch = (&__actvbridgecapcallhdlr_drvhandler_devmgr_irq_fetch)
	},
	[__devmgr_method_irq_fetch * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_fetch = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_fetch)
	},
	[__devmgr_method_irq_return * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return = (&__actvbridgecapcallhdlr_drvhandler_devmgr_irq_return)
	},
	[__devmgr_method_irq_return * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_return = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_irq_return)
	},
	[__devmgr_method_net_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_net_alloc_ifindex * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_alloc_ifindex)
	},
	[__devmgr_method_net_alloc_ifindex * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_alloc_ifindex = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_alloc_ifindex)
	},
	[__devmgr_method_net_register * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_register = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_register)
	},
	[__devmgr_method_net_register * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_register = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_register)
	},
	[__devmgr_method_net_unregister * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_unregister)
	},
	[__devmgr_method_net_unregister * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_unregister = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_unregister)
	},
	[__devmgr_method_net_hmnetd_ready * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_hmnetd_ready)
	},
	[__devmgr_method_net_hmnetd_ready * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_hmnetd_ready = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_hmnetd_ready)
	},
	[__devmgr_method_net_open * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_net_open = (&__actvbridgecapcallhdlr_drvhandler_devmgr_net_open)
	},
	[__devmgr_method_net_open * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_open = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_net_open)
	},
	[__devmgr_method_pm_action * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action = (&__actvbridgecapcallhdlr_drvhandler_devmgr_pm_action)
	},
	[__devmgr_method_pm_action * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_action = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_action)
	},
	[__devmgr_method_pm_power_off * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off = (&__actvbridgecapcallhdlr_drvhandler_devmgr_pm_power_off)
	},
	[__devmgr_method_pm_power_off * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_power_off = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_power_off)
	},
	[__devmgr_method_pm_reboot * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot = (&__actvbridgecapcallhdlr_drvhandler_devmgr_pm_reboot)
	},
	[__devmgr_method_pm_reboot * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_reboot = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_reboot)
	},
	[__devmgr_method_pm_cpuhp_action * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action = (&__actvbridgecapcallhdlr_drvhandler_devmgr_pm_cpuhp_action)
	},
	[__devmgr_method_pm_cpuhp_action * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_cpuhp_action = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_pm_cpuhp_action)
	},
	[__devmgr_method_procfs_create_data * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data = (&__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_create_data)
	},
	[__devmgr_method_procfs_create_data * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_create_data = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_create_data)
	},
	[__devmgr_method_procfs_unlink * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink = (&__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_unlink)
	},
	[__devmgr_method_procfs_unlink * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_unlink = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_unlink)
	},
	[__devmgr_method_procfs_read * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read = (&__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_read)
	},
	[__devmgr_method_procfs_read * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_read = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_read)
	},
	[__devmgr_method_procfs_write * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write = (&__actvbridgecapcallhdlr_drvhandler_devmgr_procfs_write)
	},
	[__devmgr_method_procfs_write * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_write = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_procfs_write)
	},
	[__devmgr_method_sysfs_create_dir * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_dir)
	},
	[__devmgr_method_sysfs_create_dir * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_dir = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_dir)
	},
	[__devmgr_method_sysfs_create_file * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_file)
	},
	[__devmgr_method_sysfs_create_file * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_file = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_file)
	},
	[__devmgr_method_sysfs_create_symlink * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_create_symlink)
	},
	[__devmgr_method_sysfs_create_symlink * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_symlink = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_create_symlink)
	},
	[__devmgr_method_sysfs_delete * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_delete)
	},
	[__devmgr_method_sysfs_delete * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_delete = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_delete)
	},
	[__devmgr_method_sysfs_notify * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_notify)
	},
	[__devmgr_method_sysfs_notify * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_notify = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_notify)
	},
	[__devmgr_method_sysfs_read * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_read)
	},
	[__devmgr_method_sysfs_read * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_read = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_read)
	},
	[__devmgr_method_sysfs_write * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_write)
	},
	[__devmgr_method_sysfs_write * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_write = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_write)
	},
	[__devmgr_method_sysfs_poll * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll = (&__actvbridgecapcallhdlr_drvhandler_devmgr_sysfs_poll)
	},
	[__devmgr_method_sysfs_poll * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_poll = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_sysfs_poll)
	},
	[__devmgr_method_fw_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fw_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__devmgr_method_fw_acquire_contents * 2] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents = (&__actvbridgecapcallhdlr_drvhandler_devmgr_fw_acquire_contents)
	},
	[__devmgr_method_fw_acquire_contents * 2 + 1] = {
		.p__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fw_acquire_contents = (&__actvbridgecapcallhdlr_drvhandler_devmgr_compat_fw_acquire_contents)
	}
};

#endif
void sysif_show_devmgr_methods(void)
{
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "core", "register_devhost", __devmgr_method_core_register_devhost);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "core", "register_devhost", __devmgr_method_core_register_devhost);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "core", "devhost_init_done", __devmgr_method_core_devhost_init_done);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "core", "devhost_init_done", __devmgr_method_core_devhost_init_done);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "core", "device_add", __devmgr_method_core_device_add);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "core", "device_add", __devmgr_method_core_device_add);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "core", "device_del", __devmgr_method_core_device_del);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "core", "device_del", __devmgr_method_core_device_del);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "core", "request_module", __devmgr_method_core_request_module);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "core", "request_module", __devmgr_method_core_request_module);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "chrdev", "register_region", __devmgr_method_chrdev_register_region);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "chrdev", "register_region", __devmgr_method_chrdev_register_region);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "chrdev", "unregister_region", __devmgr_method_chrdev_unregister_region);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "chrdev", "unregister_region", __devmgr_method_chrdev_unregister_region);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "blkdev", "register_region", __devmgr_method_blkdev_register_region);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "blkdev", "register_region", __devmgr_method_blkdev_register_region);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "blkdev", "unregister_region", __devmgr_method_blkdev_unregister_region);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "blkdev", "unregister_region", __devmgr_method_blkdev_unregister_region);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "fops", "open", __devmgr_method_fops_open);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "fops", "open", __devmgr_method_fops_open);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "mgmt", "load_module", __devmgr_method_mgmt_load_module);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "mgmt", "load_module", __devmgr_method_mgmt_load_module);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "mgmt", "unload_module", __devmgr_method_mgmt_unload_module);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "mgmt", "unload_module", __devmgr_method_mgmt_unload_module);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "mgmt", "sync", __devmgr_method_mgmt_sync);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "mgmt", "sync", __devmgr_method_mgmt_sync);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "mgmt", "dump", __devmgr_method_mgmt_dump);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "mgmt", "dump", __devmgr_method_mgmt_dump);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "irq", "map", __devmgr_method_irq_map);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "irq", "map", __devmgr_method_irq_map);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "irq", "fetch", __devmgr_method_irq_fetch);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "irq", "fetch", __devmgr_method_irq_fetch);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "irq", "return", __devmgr_method_irq_return);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "irq", "return", __devmgr_method_irq_return);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "net", "alloc_ifindex", __devmgr_method_net_alloc_ifindex);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "net", "alloc_ifindex", __devmgr_method_net_alloc_ifindex);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "net", "register", __devmgr_method_net_register);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "net", "register", __devmgr_method_net_register);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "net", "unregister", __devmgr_method_net_unregister);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "net", "unregister", __devmgr_method_net_unregister);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "net", "hmnetd_ready", __devmgr_method_net_hmnetd_ready);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "net", "hmnetd_ready", __devmgr_method_net_hmnetd_ready);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "net", "open", __devmgr_method_net_open);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "net", "open", __devmgr_method_net_open);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "pm", "action", __devmgr_method_pm_action);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "pm", "action", __devmgr_method_pm_action);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "pm", "power_off", __devmgr_method_pm_power_off);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "pm", "power_off", __devmgr_method_pm_power_off);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "pm", "reboot", __devmgr_method_pm_reboot);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "pm", "reboot", __devmgr_method_pm_reboot);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "pm", "cpuhp_action", __devmgr_method_pm_cpuhp_action);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "pm", "cpuhp_action", __devmgr_method_pm_cpuhp_action);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "procfs", "create_data", __devmgr_method_procfs_create_data);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "procfs", "create_data", __devmgr_method_procfs_create_data);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "procfs", "unlink", __devmgr_method_procfs_unlink);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "procfs", "unlink", __devmgr_method_procfs_unlink);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "procfs", "read", __devmgr_method_procfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "procfs", "read", __devmgr_method_procfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "procfs", "write", __devmgr_method_procfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "procfs", "write", __devmgr_method_procfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "sysfs", "create_dir", __devmgr_method_sysfs_create_dir);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "sysfs", "create_dir", __devmgr_method_sysfs_create_dir);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "sysfs", "create_file", __devmgr_method_sysfs_create_file);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "sysfs", "create_file", __devmgr_method_sysfs_create_file);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "sysfs", "create_symlink", __devmgr_method_sysfs_create_symlink);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "sysfs", "create_symlink", __devmgr_method_sysfs_create_symlink);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "sysfs", "delete", __devmgr_method_sysfs_delete);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "sysfs", "delete", __devmgr_method_sysfs_delete);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "sysfs", "notify", __devmgr_method_sysfs_notify);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "sysfs", "notify", __devmgr_method_sysfs_notify);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "sysfs", "read", __devmgr_method_sysfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "sysfs", "read", __devmgr_method_sysfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "sysfs", "write", __devmgr_method_sysfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "sysfs", "write", __devmgr_method_sysfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "sysfs", "poll", __devmgr_method_sysfs_poll);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "sysfs", "poll", __devmgr_method_sysfs_poll);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "drvcall_devmgr", "fw", "acquire_contents", __devmgr_method_fw_acquire_contents);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "drvhandler_devmgr", "fw", "acquire_contents", __devmgr_method_fw_acquire_contents);
	hm_info("%s_%s, max method num: %d\n", "devmgr", "method", __devmgr_method_MAX);
}

int __actvcall_drvcall_devmgr_procfs_read(unsigned long long __rpc_info, void *__buf)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_procfs_read((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcapcall_drvcall_devmgr_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_procfs_read((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcall_drvcall_devmgr_procfs_write(unsigned long long __rpc_info, void *__buf)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_procfs_write((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcapcall_drvcall_devmgr_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_procfs_write((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcall_drvcall_devmgr_sysfs_read(unsigned long long __rpc_info, void *__buf)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_sysfs_read((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcapcall_drvcall_devmgr_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_sysfs_read((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcall_drvcall_devmgr_sysfs_write(unsigned long long __rpc_info, void *__buf, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_sysfs_write((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, tagid, ctx, pos, actv_buf);
}

int __actvcapcall_drvcall_devmgr_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_sysfs_write((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, tagid, ctx, pos, actv_buf);
}

int __actvcall_drvcall_devmgr_sysfs_poll(unsigned long long __rpc_info, void *__buf)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_sysfs_poll((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcapcall_drvcall_devmgr_sysfs_poll(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_drvhandler_devmgr_sysfs_poll((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

#endif
#endif
