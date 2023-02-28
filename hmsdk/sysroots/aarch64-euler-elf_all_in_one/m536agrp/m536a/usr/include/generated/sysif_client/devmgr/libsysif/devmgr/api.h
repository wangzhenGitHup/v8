/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for devmgr
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libsysif/devmgr/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/devmgr/libsysif/devmgr/api.h --server-dest ../image/usr/include/generated/sysif_server/devmgr/libsysif/devmgr/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_DEVMGR_API_H
#define LIBSYSIF_DEVMGR_API_H
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

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_core_register_devhost(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_core_register_devhost(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_core_register_devhost(unsigned long long __rpc_info, void *__buf, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	uref_t __maybe_unused __actv_local_var_ap_uref = ap_uref;
	struct hm_actv_buf __maybe_unused __actv_local_var_group = group;
	uref_t __maybe_unused __actv_local_var_devmgr_ap_uref = devmgr_ap_uref;
	__ret = ____actvcall_drvcall_devmgr_core_register_devhost(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(ap_uref, __actv_local_var_ap_uref), __ARCH_ACTV_RPC_PASS_ARG(group, __actv_local_var_group), __ARCH_ACTV_RPC_PASS_ARG(devmgr_ap_uref, __actv_local_var_devmgr_ap_uref));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_core_register_devhost(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int flags, uref_t ap_uref, struct hm_actv_buf group, uref_t devmgr_ap_uref)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	uref_t __maybe_unused __actv_local_var_ap_uref = ap_uref;
	struct hm_actv_buf __maybe_unused __actv_local_var_group = group;
	uref_t __maybe_unused __actv_local_var_devmgr_ap_uref = devmgr_ap_uref;
	__ret = ____actvcapcall_drvcall_devmgr_core_register_devhost(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(ap_uref, __actv_local_var_ap_uref), __ARCH_ACTV_RPC_PASS_ARG(group, __actv_local_var_group), __ARCH_ACTV_RPC_PASS_ARG(devmgr_ap_uref, __actv_local_var_devmgr_ap_uref));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_core_devhost_init_done(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_core_devhost_init_done(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_core_devhost_init_done(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devmgr_core_devhost_init_done(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_core_devhost_init_done(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devmgr_core_devhost_init_done(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_drvcall_devmgr_core_device_add(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_drvcall_devmgr_core_device_add(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_core_device_add(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_devname = devname;
	struct hm_actv_buf __maybe_unused __actv_local_var_devnode_name = devnode_name;
	int __maybe_unused __actv_local_var_parent = parent;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_devt = devt;
	int __maybe_unused __actv_local_var_vfs_mode = vfs_mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_group = group;
	__ret = ____actvcall_drvcall_devmgr_core_device_add(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(devname, __actv_local_var_devname), __ARCH_ACTV_RPC_PASS_ARG(devnode_name, __actv_local_var_devnode_name), __ARCH_ACTV_RPC_PASS_ARG(parent, __actv_local_var_parent), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(devt, __actv_local_var_devt), __ARCH_ACTV_RPC_PASS_ARG(vfs_mode, __actv_local_var_vfs_mode), __ARCH_ACTV_RPC_PASS_ARG(group, __actv_local_var_group));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_core_device_add(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, struct hm_actv_buf devname, struct hm_actv_buf devnode_name, int parent, unsigned int flags, unsigned int devt, int vfs_mode, struct hm_actv_buf group)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_devname = devname;
	struct hm_actv_buf __maybe_unused __actv_local_var_devnode_name = devnode_name;
	int __maybe_unused __actv_local_var_parent = parent;
	unsigned int __maybe_unused __actv_local_var_flags = flags;
	unsigned int __maybe_unused __actv_local_var_devt = devt;
	int __maybe_unused __actv_local_var_vfs_mode = vfs_mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_group = group;
	__ret = ____actvcapcall_drvcall_devmgr_core_device_add(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(devname, __actv_local_var_devname), __ARCH_ACTV_RPC_PASS_ARG(devnode_name, __actv_local_var_devnode_name), __ARCH_ACTV_RPC_PASS_ARG(parent, __actv_local_var_parent), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(devt, __actv_local_var_devt), __ARCH_ACTV_RPC_PASS_ARG(vfs_mode, __actv_local_var_vfs_mode), __ARCH_ACTV_RPC_PASS_ARG(group, __actv_local_var_group));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_core_device_del(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_core_device_del(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_core_device_del(unsigned long long __rpc_info, void *__buf, int devid)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	__ret = ____actvcall_drvcall_devmgr_core_device_del(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_core_device_del(rref_t __rref, unsigned long long __rpc_info, void *__buf, int devid)
{
	int __ret;
	int __maybe_unused __actv_local_var_devid = devid;
	__ret = ____actvcapcall_drvcall_devmgr_core_device_del(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_core_request_module(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_core_request_module(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_core_request_module(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf modname, struct hm_actv_buf args)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_modname = modname;
	struct hm_actv_buf __maybe_unused __actv_local_var_args = args;
	__ret = ____actvcall_drvcall_devmgr_core_request_module(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(modname, __actv_local_var_modname), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_core_request_module(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf modname, struct hm_actv_buf args)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_modname = modname;
	struct hm_actv_buf __maybe_unused __actv_local_var_args = args;
	__ret = ____actvcapcall_drvcall_devmgr_core_request_module(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(modname, __actv_local_var_modname), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_chrdev_register_region(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_chrdev_register_region(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_chrdev_register_region(unsigned long long __rpc_info, void *__buf, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_major = major;
	unsigned int __maybe_unused __actv_local_var_baseminor = baseminor;
	int __maybe_unused __actv_local_var_minorct = minorct;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcall_drvcall_devmgr_chrdev_register_region(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(major, __actv_local_var_major), __ARCH_ACTV_RPC_PASS_ARG(baseminor, __actv_local_var_baseminor), __ARCH_ACTV_RPC_PASS_ARG(minorct, __actv_local_var_minorct), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_chrdev_register_region(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int major, unsigned int baseminor, int minorct, struct hm_actv_buf name)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_major = major;
	unsigned int __maybe_unused __actv_local_var_baseminor = baseminor;
	int __maybe_unused __actv_local_var_minorct = minorct;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcapcall_drvcall_devmgr_chrdev_register_region(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(major, __actv_local_var_major), __ARCH_ACTV_RPC_PASS_ARG(baseminor, __actv_local_var_baseminor), __ARCH_ACTV_RPC_PASS_ARG(minorct, __actv_local_var_minorct), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_chrdev_unregister_region(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_chrdev_unregister_region(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_chrdev_unregister_region(unsigned long long __rpc_info, void *__buf, unsigned int major, unsigned int baseminor, int minorct)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_major = major;
	unsigned int __maybe_unused __actv_local_var_baseminor = baseminor;
	int __maybe_unused __actv_local_var_minorct = minorct;
	__ret = ____actvcall_drvcall_devmgr_chrdev_unregister_region(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(major, __actv_local_var_major), __ARCH_ACTV_RPC_PASS_ARG(baseminor, __actv_local_var_baseminor), __ARCH_ACTV_RPC_PASS_ARG(minorct, __actv_local_var_minorct));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_chrdev_unregister_region(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int major, unsigned int baseminor, int minorct)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_major = major;
	unsigned int __maybe_unused __actv_local_var_baseminor = baseminor;
	int __maybe_unused __actv_local_var_minorct = minorct;
	__ret = ____actvcapcall_drvcall_devmgr_chrdev_unregister_region(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(major, __actv_local_var_major), __ARCH_ACTV_RPC_PASS_ARG(baseminor, __actv_local_var_baseminor), __ARCH_ACTV_RPC_PASS_ARG(minorct, __actv_local_var_minorct));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_blkdev_register_region(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_blkdev_register_region(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_blkdev_register_region(unsigned long long __rpc_info, void *__buf, unsigned int major, struct hm_actv_buf name)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_major = major;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcall_drvcall_devmgr_blkdev_register_region(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(major, __actv_local_var_major), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_blkdev_register_region(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int major, struct hm_actv_buf name)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_major = major;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcapcall_drvcall_devmgr_blkdev_register_region(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(major, __actv_local_var_major), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_blkdev_unregister_region(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_blkdev_unregister_region(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_blkdev_unregister_region(unsigned long long __rpc_info, void *__buf, unsigned int major, struct hm_actv_buf name)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_major = major;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcall_drvcall_devmgr_blkdev_unregister_region(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(major, __actv_local_var_major), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_blkdev_unregister_region(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int major, struct hm_actv_buf name)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_major = major;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcapcall_drvcall_devmgr_blkdev_unregister_region(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(major, __actv_local_var_major), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_fops_open(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_fops_open(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_fops_open(unsigned long long __rpc_info, void *__buf, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_devno = devno;
	unsigned int __maybe_unused __actv_local_var_vfs_flags = vfs_flags;
	int __maybe_unused __actv_local_var_vfs_mode = vfs_mode;
	rref_t __maybe_unused __actv_local_var_tgt_rref = tgt_rref;
	__ret = ____actvcall_drvcall_devmgr_fops_open(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno), __ARCH_ACTV_RPC_PASS_ARG(vfs_flags, __actv_local_var_vfs_flags), __ARCH_ACTV_RPC_PASS_ARG(vfs_mode, __actv_local_var_vfs_mode), __ARCH_ACTV_RPC_PASS_ARG(tgt_rref, __actv_local_var_tgt_rref));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_fops_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int devno, unsigned int vfs_flags, int vfs_mode, rref_t tgt_rref)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_devno = devno;
	unsigned int __maybe_unused __actv_local_var_vfs_flags = vfs_flags;
	int __maybe_unused __actv_local_var_vfs_mode = vfs_mode;
	rref_t __maybe_unused __actv_local_var_tgt_rref = tgt_rref;
	__ret = ____actvcapcall_drvcall_devmgr_fops_open(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno), __ARCH_ACTV_RPC_PASS_ARG(vfs_flags, __actv_local_var_vfs_flags), __ARCH_ACTV_RPC_PASS_ARG(vfs_mode, __actv_local_var_vfs_mode), __ARCH_ACTV_RPC_PASS_ARG(tgt_rref, __actv_local_var_tgt_rref));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_drvcall_devmgr_mgmt_load_module(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_drvcall_devmgr_mgmt_load_module(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_mgmt_load_module(unsigned long long __rpc_info, void *__buf, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid)
{
	int __ret;
	int __maybe_unused __actv_local_var_load_type = load_type;
	struct hm_actv_buf __maybe_unused __actv_local_var_modname = modname;
	struct hm_actv_buf __maybe_unused __actv_local_var_modargs = modargs;
	int __maybe_unused __actv_local_var_devid = devid;
	__ret = ____actvcall_drvcall_devmgr_mgmt_load_module(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(load_type, __actv_local_var_load_type), __ARCH_ACTV_RPC_PASS_ARG(modname, __actv_local_var_modname), __ARCH_ACTV_RPC_PASS_ARG(modargs, __actv_local_var_modargs), __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_mgmt_load_module(rref_t __rref, unsigned long long __rpc_info, void *__buf, int load_type, struct hm_actv_buf modname, struct hm_actv_buf modargs, int devid)
{
	int __ret;
	int __maybe_unused __actv_local_var_load_type = load_type;
	struct hm_actv_buf __maybe_unused __actv_local_var_modname = modname;
	struct hm_actv_buf __maybe_unused __actv_local_var_modargs = modargs;
	int __maybe_unused __actv_local_var_devid = devid;
	__ret = ____actvcapcall_drvcall_devmgr_mgmt_load_module(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(load_type, __actv_local_var_load_type), __ARCH_ACTV_RPC_PASS_ARG(modname, __actv_local_var_modname), __ARCH_ACTV_RPC_PASS_ARG(modargs, __actv_local_var_modargs), __ARCH_ACTV_RPC_PASS_ARG(devid, __actv_local_var_devid));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_mgmt_unload_module(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_mgmt_unload_module(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_mgmt_unload_module(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf modname, unsigned int cnode_idx)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_modname = modname;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcall_drvcall_devmgr_mgmt_unload_module(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(modname, __actv_local_var_modname), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_mgmt_unload_module(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf modname, unsigned int cnode_idx)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_modname = modname;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	__ret = ____actvcapcall_drvcall_devmgr_mgmt_unload_module(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(modname, __actv_local_var_modname), __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_mgmt_sync(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_mgmt_sync(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_mgmt_sync(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devmgr_mgmt_sync(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_mgmt_sync(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devmgr_mgmt_sync(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_mgmt_dump(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_mgmt_dump(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_mgmt_dump(unsigned long long __rpc_info, void *__buf, struct bunch_ipc_attr attr)
{
	int __ret;
	struct bunch_ipc_attr __maybe_unused __actv_local_var_attr = attr;
	__ret = ____actvcall_drvcall_devmgr_mgmt_dump(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(attr, __actv_local_var_attr));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_mgmt_dump(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct bunch_ipc_attr attr)
{
	int __ret;
	struct bunch_ipc_attr __maybe_unused __actv_local_var_attr = attr;
	__ret = ____actvcapcall_drvcall_devmgr_mgmt_dump(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(attr, __actv_local_var_attr));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_irq_map(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_irq_map(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_irq_map(unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_map_arg arg)
{
	int __ret;
	struct drvcall_devmgr_irq_map_arg __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcall_drvcall_devmgr_irq_map(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_irq_map(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_map_arg arg)
{
	int __ret;
	struct drvcall_devmgr_irq_map_arg __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcapcall_drvcall_devmgr_irq_map(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_irq_fetch(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_irq_fetch(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_irq_fetch(unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_fetch_arg arg)
{
	int __ret;
	struct drvcall_devmgr_irq_fetch_arg __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcall_drvcall_devmgr_irq_fetch(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_irq_fetch(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_fetch_arg arg)
{
	int __ret;
	struct drvcall_devmgr_irq_fetch_arg __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcapcall_drvcall_devmgr_irq_fetch(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_irq_return(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_irq_return(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_irq_return(unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_return_arg arg)
{
	int __ret;
	struct drvcall_devmgr_irq_return_arg __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcall_drvcall_devmgr_irq_return(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_irq_return(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct drvcall_devmgr_irq_return_arg arg)
{
	int __ret;
	struct drvcall_devmgr_irq_return_arg __maybe_unused __actv_local_var_arg = arg;
	__ret = ____actvcapcall_drvcall_devmgr_irq_return(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(arg, __actv_local_var_arg));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_net_alloc_ifindex(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_net_alloc_ifindex(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_net_alloc_ifindex(unsigned long long __rpc_info, void *__buf, int ifindex)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	__ret = ____actvcall_drvcall_devmgr_net_alloc_ifindex(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_net_alloc_ifindex(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	__ret = ____actvcapcall_drvcall_devmgr_net_alloc_ifindex(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_net_register(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_net_register(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_net_register(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, int ifindex, unsigned long long features)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	unsigned long long __maybe_unused __actv_local_var_features = features;
	__ret = ____actvcall_drvcall_devmgr_net_register(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(features, __actv_local_var_features));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_net_register(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, int ifindex, unsigned long long features)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	unsigned long long __maybe_unused __actv_local_var_features = features;
	__ret = ____actvcapcall_drvcall_devmgr_net_register(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(features, __actv_local_var_features));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_net_unregister(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_net_unregister(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_net_unregister(unsigned long long __rpc_info, void *__buf, int ifindex)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	__ret = ____actvcall_drvcall_devmgr_net_unregister(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_net_unregister(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	__ret = ____actvcapcall_drvcall_devmgr_net_unregister(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_net_hmnetd_ready(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_net_hmnetd_ready(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_net_hmnetd_ready(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devmgr_net_hmnetd_ready(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_net_hmnetd_ready(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devmgr_net_hmnetd_ready(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_net_open(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_net_open(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_net_open(unsigned long long __rpc_info, void *__buf, int ifindex, rref_t tgt_rref)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	rref_t __maybe_unused __actv_local_var_tgt_rref = tgt_rref;
	__ret = ____actvcall_drvcall_devmgr_net_open(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(tgt_rref, __actv_local_var_tgt_rref));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_net_open(rref_t __rref, unsigned long long __rpc_info, void *__buf, int ifindex, rref_t tgt_rref)
{
	int __ret;
	int __maybe_unused __actv_local_var_ifindex = ifindex;
	rref_t __maybe_unused __actv_local_var_tgt_rref = tgt_rref;
	__ret = ____actvcapcall_drvcall_devmgr_net_open(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ifindex, __actv_local_var_ifindex), __ARCH_ACTV_RPC_PASS_ARG(tgt_rref, __actv_local_var_tgt_rref));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_pm_action(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_pm_action(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_pm_action(unsigned long long __rpc_info, void *__buf, unsigned int action)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_action = action;
	__ret = ____actvcall_drvcall_devmgr_pm_action(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(action, __actv_local_var_action));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_pm_action(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int action)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_action = action;
	__ret = ____actvcapcall_drvcall_devmgr_pm_action(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(action, __actv_local_var_action));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_pm_power_off(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_pm_power_off(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_pm_power_off(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devmgr_pm_power_off(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_pm_power_off(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devmgr_pm_power_off(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_pm_reboot(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_pm_reboot(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_pm_reboot(unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd)
{
	int __ret;
	struct reboot_cmd __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcall_drvcall_devmgr_pm_reboot(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_pm_reboot(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct reboot_cmd cmd)
{
	int __ret;
	struct reboot_cmd __maybe_unused __actv_local_var_cmd = cmd;
	__ret = ____actvcapcall_drvcall_devmgr_pm_reboot(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_drvcall_devmgr_pm_cpuhp_action(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_drvcall_devmgr_pm_cpuhp_action(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_pm_cpuhp_action(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devmgr_pm_cpuhp_action(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_pm_cpuhp_action(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devmgr_pm_cpuhp_action(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_procfs_create_data(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_procfs_create_data(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_procfs_create_data(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_ops = ops;
	struct hm_actv_buf __maybe_unused __actv_local_var_linkname = linkname;
	__ret = ____actvcall_drvcall_devmgr_procfs_create_data(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops), __ARCH_ACTV_RPC_PASS_ARG(linkname, __actv_local_var_linkname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_procfs_create_data(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf ops, struct hm_actv_buf linkname)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_ops = ops;
	struct hm_actv_buf __maybe_unused __actv_local_var_linkname = linkname;
	__ret = ____actvcapcall_drvcall_devmgr_procfs_create_data(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(ops, __actv_local_var_ops), __ARCH_ACTV_RPC_PASS_ARG(linkname, __actv_local_var_linkname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_procfs_unlink(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_procfs_unlink(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_procfs_unlink(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcall_drvcall_devmgr_procfs_unlink(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_procfs_unlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcapcall_drvcall_devmgr_procfs_unlink(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_drvcall_devmgr_procfs_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_drvcall_devmgr_procfs_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_procfs_read(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devmgr_procfs_read(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devmgr_procfs_read(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_drvcall_devmgr_procfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_drvcall_devmgr_procfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_procfs_write(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devmgr_procfs_write(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devmgr_procfs_write(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_sysfs_create_dir(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_sysfs_create_dir(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_sysfs_create_dir(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcall_drvcall_devmgr_sysfs_create_dir(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_sysfs_create_dir(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	__ret = ____actvcapcall_drvcall_devmgr_sysfs_create_dir(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_sysfs_create_file(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_sysfs_create_file(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_sysfs_create_file(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, int tagid)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	int __maybe_unused __actv_local_var_tagid = tagid;
	__ret = ____actvcall_drvcall_devmgr_sysfs_create_file(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_sysfs_create_file(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, int tagid)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	int __maybe_unused __actv_local_var_tagid = tagid;
	__ret = ____actvcapcall_drvcall_devmgr_sysfs_create_file(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_sysfs_create_symlink(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_sysfs_create_symlink(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_sysfs_create_symlink(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_linkname = linkname;
	__ret = ____actvcall_drvcall_devmgr_sysfs_create_symlink(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(linkname, __actv_local_var_linkname));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_sysfs_create_symlink(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name, unsigned int mode, struct hm_actv_buf linkname)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_mode = mode;
	struct hm_actv_buf __maybe_unused __actv_local_var_linkname = linkname;
	__ret = ____actvcapcall_drvcall_devmgr_sysfs_create_symlink(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(mode, __actv_local_var_mode), __ARCH_ACTV_RPC_PASS_ARG(linkname, __actv_local_var_linkname));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_sysfs_delete(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_sysfs_delete(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_sysfs_delete(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcall_drvcall_devmgr_sysfs_delete(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_sysfs_delete(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcapcall_drvcall_devmgr_sysfs_delete(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_sysfs_notify(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_sysfs_notify(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_sysfs_notify(unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcall_drvcall_devmgr_sysfs_notify(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_sysfs_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct hm_actv_buf name)
{
	int __ret;
	struct hm_actv_buf __maybe_unused __actv_local_var_name = name;
	__ret = ____actvcapcall_drvcall_devmgr_sysfs_notify(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_drvcall_devmgr_sysfs_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_drvcall_devmgr_sysfs_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_sysfs_read(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devmgr_sysfs_read(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_sysfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devmgr_sysfs_read(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_drvcall_devmgr_sysfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_drvcall_devmgr_sysfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_sysfs_write(unsigned long long __rpc_info, void *__buf, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	int __ret;
	int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_ctx = ctx;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_buf = actv_buf;
	__ret = ____actvcall_drvcall_devmgr_sysfs_write(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(actv_buf, __actv_local_var_actv_buf));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_sysfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf, int tagid, unsigned long long ctx, unsigned long long pos, struct hm_actv_buf actv_buf)
{
	int __ret;
	int __maybe_unused __actv_local_var_tagid = tagid;
	unsigned long long __maybe_unused __actv_local_var_ctx = ctx;
	unsigned long long __maybe_unused __actv_local_var_pos = pos;
	struct hm_actv_buf __maybe_unused __actv_local_var_actv_buf = actv_buf;
	__ret = ____actvcapcall_drvcall_devmgr_sysfs_write(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(tagid, __actv_local_var_tagid), __ARCH_ACTV_RPC_PASS_ARG(ctx, __actv_local_var_ctx), __ARCH_ACTV_RPC_PASS_ARG(pos, __actv_local_var_pos), __ARCH_ACTV_RPC_PASS_ARG(actv_buf, __actv_local_var_actv_buf));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_drvcall_devmgr_sysfs_poll(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_drvcall_devmgr_sysfs_poll(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_sysfs_poll(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_drvcall_devmgr_sysfs_poll(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_sysfs_poll(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_drvcall_devmgr_sysfs_poll(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_drvcall_devmgr_fw_acquire_contents(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_drvcall_devmgr_fw_acquire_contents(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_drvcall_devmgr_fw_acquire_contents(unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_buf = buf;
	unsigned int __maybe_unused __actv_local_var_size = size;
	unsigned long __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_namelen = namelen;
	__ret = ____actvcall_drvcall_devmgr_fw_acquire_contents(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_drvcall_devmgr_fw_acquire_contents(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long buf, unsigned int size, unsigned long name, unsigned int namelen)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_buf = buf;
	unsigned int __maybe_unused __actv_local_var_size = size;
	unsigned long __maybe_unused __actv_local_var_name = name;
	unsigned int __maybe_unused __actv_local_var_namelen = namelen;
	__ret = ____actvcapcall_drvcall_devmgr_fw_acquire_contents(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size), __ARCH_ACTV_RPC_PASS_ARG(name, __actv_local_var_name), __ARCH_ACTV_RPC_PASS_ARG(namelen, __actv_local_var_namelen));
	return __ret;
}

#endif
#endif
