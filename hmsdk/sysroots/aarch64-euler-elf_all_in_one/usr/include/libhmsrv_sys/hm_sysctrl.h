/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2022. All rights reserved.
 * Description: Definition of sysif server sysctrl
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jun 20 12:21:52 2019
 */

#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_SYSCTRL_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_SYSCTRL_H

#include <sys/types.h>

#include <libbunch/bunch.h>
#include <libkev/kev_types.h>
#include <asm/types.h>
#include <hmkernel/drivers/respart.h>
#include <hmkernel/sysconf.h>
#include <hmkernel/vtimekeep.h>
#include <hmkernel/capability.h>

struct hm_respart_partition {
	unsigned int nodeid;
	unsigned int partid;
};

#if defined __HOST_LLT__

#include <libhwsecurec/securec.h>

static inline int
hm_sysctrl_read_conf(unsigned int type, void *buf, unsigned int buflen)
{
	/*
	 * add support for LLT test of process_spawn_with_ppid
	 */
	if (type == __SYSCONF_CONFIG_TIMER) {
		NOFAIL(strncpy_s(buf, buflen,
				 __TIMER_TIMEWHEEL, sizeof(__TIMER_TIMEWHEEL)));
	}
	/*
	 * add support for LLT test of spif(test_spif_user_if_utils_op_percpu)
	 */
	if (type == __SYSCONF_CONFIG_CPU) {
		*((unsigned long *)buf) = CONFIG_NR_CPUS;
	}

	return 0;
}
static inline int
hm_sysctrl_load_dtb(void *buf, unsigned long size, unsigned long offset)
{
	return 0;
}
static inline int
hm_sysctrl_read_dtb(const char *path, unsigned long path_len, void *buf,
		    unsigned long buf_size)
{
	return 0;
}

static inline int
hm_sysctrl_attach_cpuctx(void)
{
	return 0;
}

static inline int
hm_sysctrl_detach_cpuctx(void)
{
	return 0;
}

static inline int
hm_sysctrl_check_cpuctx(unsigned int *is_attached)
{
	if (is_attached != NULL)
		*is_attached = 0;
	return 0;
}

#else

int hm_sysctrl_read_conf(unsigned int type, void *buf, unsigned int buflen);
int hm_sysctrl_load_dtb(void *buf, unsigned long size, unsigned long offset);
int hm_sysctrl_read_dtb(const char *path, unsigned long path_len, void *buf,
			unsigned long buf_size);
int hm_sysctrl_attach_cpuctx(void);
int hm_sysctrl_detach_cpuctx(void);
int hm_sysctrl_check_cpuctx(unsigned int *is_attached);

void hm_sysctrl_set_cref(rref_t cref);
#endif

rref_t hm_sysctrl_rref_of(void);
int hm_init_sysctrl(void);
void hm_sysctrl_reinit(void);
int hm_sysctrl_cpu_stat(unsigned int flags, struct bunch *bunch);
int hm_sysctl_cpu_stat_of(unsigned int cpu, struct __sysctrl_cpu_stat *stat);

int hm_sysctrl_power_off(void);
int hm_sysctrl_reboot(unsigned int reboot_type);
int hm_sysctrl_pm_suspend(unsigned int index);
int hm_sysctrl_pm_cpudown(unsigned int target_cpu, unsigned int flag);
int hm_sysctrl_cpuaffinity(unsigned int target_cpu, unsigned int *val);
int hm_sysctrl_cpuup(unsigned int target_cpu);
int hm_sysctrl_set_klogport_level(unsigned long type_flag, unsigned int level);
int hm_sysctrl_enable_klogport(unsigned long type_flag);
int hm_sysctrl_disable_klogport(unsigned long type_flag);

unsigned int hm_sysctrl_respart_read_nodenum(void);
int hm_sysctrl_respart_read_nodeinfo(unsigned int nodeid,
				     struct __res_node_info_s *node_info);
int hm_sysctrl_respart_monitor_enable(struct hm_respart_partition part);
int hm_sysctrl_respart_monitor_disable(struct hm_respart_partition part);
int hm_sysctrl_respart_monitor_capture(struct hm_respart_partition part, unsigned int *val);
int hm_sysctrl_respart_read_partinfo(struct hm_respart_partition part,
				     struct __res_partition_info_s *part_info);
int hm_sysctrl_inject_ras_error(unsigned int cmd, unsigned long param1,
				unsigned long param2);
ssize_t hm_sysctrl_kev_read_data(unsigned int ring_buffer_index,
				 const void *buf, size_t size, uint64_t *head);
int hm_sysctrl_kev_set_block_info(enum kev_type type, cref_t vspace_cref, void *uaddr);
int hm_sysctrl_kev_set_water(unsigned int ring_buffer_index, uint64_t water);
#endif
