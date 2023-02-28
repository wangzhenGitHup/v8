/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Type definations for devmgr sysif APIs
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jan 11 10:45:12 2019
 */
#ifndef LIBSYSIF_DEVMGR_TYPES_H
#define LIBSYSIF_DEVMGR_TYPES_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <hmkernel/const.h>
#include <hmkernel/capability.h>

#define DM_PM_SUSPEND			__U(0)
#define DM_PM_RESUME			__U(1)
#define DM_PM_SUSPEND_LATE		__U(2)
#define DM_PM_RESUME_EARLY		__U(3)

#define DH_PM_DEV_SHUTDOWN		__U(0)
#define DH_PM_SYSCORE_SHUTDOWN		__U(1)
#define DH_PM_SUSPEND			__U(2)
#define DH_PM_RESUME			__U(3)
#define DH_PM_SUSPEND_LATE		__U(4)
#define DH_PM_RESUME_EARLY		__U(5)

#define DH_PM_SHUTDOWN_PREPARE		__U(0)
#define DH_PM_REBOOT_PREPARE		__U(1)

#define DH_PM_CPU_ADD			__U(0)
#define DH_PM_CPU_REMOVE		__U(1)

#define O_NO_OPEN 0x80000000

#define MODULE_NAME_LEN		32U

#define MODULE_ARGS_LEN		128U

#define DRIVER_NAME_LEN		32U

#define DRIVER_ARGS_LEN		128U

#define DEVICE_NAME_LEN		128U

#define MAJOR_NAME_LEN		32U

#define ISOLATE_GROUP_NAME_LEN	32U

#define DEVICE_CAN_PROBE	__U(1)
#define DEVICE_MUST_ISOLATE	(__U(1) << 1)
#define DEVICE_AUTO_LOAD	(__U(1) << 2)

#define DEVICE_CTX_PROXY	(__U(1) << 16)

static inline bool device_flag_test(unsigned int flags, unsigned int flag)
{
	return (flags & flag) != 0U;
}

/* devhost identity flags */
#define DH_FLAGS_STANDALONE	(__U(1) << 31)

static inline bool dh_flag_test(unsigned int flags, unsigned int flag)
{
	return (flags & flag) != 0U;
}

/* used in net */
#define MAC_ADDR_LEN		16
struct mac_addr {
	char sa_data[MAC_ADDR_LEN];
};

/* mount info of sb, root dentry and root node */
struct transfs_m_info_t {
	unsigned int sb_index;
	unsigned int root_d_index;
	unsigned int root_v_index;
	unsigned int root_lnkcnt;
	size_t per_write_size;
	unsigned long long filp;
	size_t block_size;
};

/* dentry and node info */
struct transfs_dn_info_t {
	unsigned int d_index;
	unsigned int v_index;
	uint32_t ino;
};

struct transfs_attr_t {
	unsigned long long blocks;
	unsigned long blksize;
};

struct netdev_status {
	unsigned long long	total_rx;
	unsigned long long	total_tx;
	unsigned long long	total_alloc;
	unsigned long long	total_free;

	unsigned long long	rx_in;
	unsigned long long	tx_in;
	unsigned long long	drv_alloc;
	unsigned long long	drv_free;
	unsigned long long	devhost_alloc;
	unsigned long long	devhost_free;
	unsigned long long	full_drop;
	unsigned long long	deact_drop;
	unsigned long long	null_drop;
};

/* used in fops_ioctl */
#define DEVHOST_IOCTL_MAX_DATA		256 /* DEPRECATED */

#define DEVMGR_IRQ_HWCONF_LEN_MAX	8
#define DEVMGR_IRQ_MAX_NR_CPUS		8

struct drvcall_devmgr_irq_map_arg {
	unsigned int oirq_offset;
	unsigned int hwconf_len;
	unsigned int hwconf[DEVMGR_IRQ_HWCONF_LEN_MAX];
};

struct drvcall_devmgr_irq_fetch_arg {
	unsigned int virt_irq;
	unsigned int rrefs_nr;
	rref_t irqctrl_rrefs[DEVMGR_IRQ_MAX_NR_CPUS];
};

struct drvcall_devmgr_irq_fetch_rlt {
	unsigned int irqs_nr;
	unsigned int hwconf_len;
	unsigned int hwconf[DEVMGR_IRQ_HWCONF_LEN_MAX];
	unsigned int logic_irqs[DEVMGR_IRQ_MAX_NR_CPUS];
};

struct drvcall_devmgr_irq_return_arg {
	unsigned int virt_irq;
	unsigned int rrefs_nr;
	rref_t irqctrl_rrefs[DEVMGR_IRQ_MAX_NR_CPUS];
};


#define DM_MGMT_INTERNAL_MODULE (0x0) /* located in /lib/modules directory */
#define DM_MGMT_EXTERNAL_MODULE (0x1)
#define DM_MGMT_TYPE_INVALID	(-1)
struct drvcall_devmgr_mgmt_load_module_arg {
	char *mod_buf;
	unsigned int mod_size;
};

bool __devmgr_type_is_valid_name(const char *name, unsigned int maxlen);
bool __devmgr_type_is_valid_filename(const char *name, unsigned int maxlen);

static inline bool is_valid_module_name(const char *name)
{
	return __devmgr_type_is_valid_filename(name, MODULE_NAME_LEN);
}

static inline bool is_valid_driver_name(const char *name)
{
	return __devmgr_type_is_valid_filename(name, DRIVER_NAME_LEN);
}

static inline bool is_valid_device_name(const char *name)
{
	return __devmgr_type_is_valid_name(name, DEVICE_NAME_LEN);
}

static inline bool is_valid_major_name(const char *name)
{
	return __devmgr_type_is_valid_name(name, MAJOR_NAME_LEN);
}

static inline bool is_valid_isolate_group_name(const char *name)
{
	return __devmgr_type_is_valid_name(name, ISOLATE_GROUP_NAME_LEN);
}

#endif	/* LIBSYSIF_DEVMGR_TYPES_H */
