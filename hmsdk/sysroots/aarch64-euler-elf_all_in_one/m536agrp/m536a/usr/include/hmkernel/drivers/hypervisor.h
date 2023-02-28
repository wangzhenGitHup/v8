/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: General macros and structs of hypervisor
 * Author: IT Software Infrastructure Lab, Munich Research Center
 * Create: Thu May 23 15:57:23 2019
 */

#ifndef UAPI_HMKERNEL_DRIVERS_HYPERVISOR_H
#define UAPI_HMKERNEL_DRIVERS_HYPERVISOR_H

#include <hmkernel/types.h>
#include <hmkernel/capability.h>

#define MAX_VCPUS		16U
#define MAX_DEV_GROUPS		8U
#define MAX_DEV_IO_REGS		256U
#define MAX_REG_SEG_NUM		2U

#define MAX_MMIO_REGION 5U

#define HM_VCPU_EVENT_VMEXIT	0x0U
#define HM_VCPU_EVENT_ERROR	0x1U
#define HM_VCPU_EVENT_SUSPEND	0x2U

#define HYP_VCPU_INVALID	0
#define HYP_VCPU_SETUP		1
#define HYP_VCPU_GETREG		2
#define HYP_VCPU_SETREG		3
#define HYP_VCPU_GETCTX		4
#define HYP_VCPU_SETCTX		5
#define HYP_VCPU_RESET		6
#define HYP_VGIC_ASSERT_IRQ	7
#define HYP_VCPU_START		8
#define HYP_VCPU_STOP		9
#define HYP_VCPU_DEBUG_SETUP		10 /* 0: disable, others: enable */
#define HYP_VCPU_GET_DEBUG_INFO		11
#define HYP_VCPU_SETIRQ_ATTRIBUTE	12
#define HYP_VCPU_GET_VIRTUAL_TIME	13
#define HYP_VCPU_SET_VIRTUAL_TIME	14
#define HYP_VCPU_PAUSE			15 /* use START to unpause vcpu */
#define HYP_VCPU_SET_TIMEOUT		16

#define HYP_VCPU_ONLY_CHANGE_VCPU_STATE		0ULL
#define HYP_VCPU_CHANGE_VCPU_STATE_WITH_THREAD	1ULL

#define HYP_MEMCONF_NORMAL_MEM	(1UL)
#define HYP_MEMCONF_UVMM_ACCESS	(1UL << 1)
#define HYP_MEMCONF_SHARE_MEM	(1UL << 2)
#define HYP_MEMCONF_RESERVE_MEM (1UL << 3)

struct __hyp_vcpu_config_setup {
	cref_t vm;
	__u8 is_aarch32;
};

struct __hyp_vcpu_config_setreg {
	__u64 reg;
	__u64 val;
};

struct __hyp_vcpu_debug_info {
	__u32 brp_nr;
	__u32 wrp_nr;
};

struct __vmexit_info {
	__u64 exit_event;
};

enum __hyp_mr_type {
	__MMIO_TYPE_MMIO_TRIGGER,
#ifdef CONFIG_MMIO_DISPATCHER_KICK_TYPE
	__MMIO_TYPE_MMIO_KICK,
#endif
	__MMIO_TYPE_MAX,
};

#endif
