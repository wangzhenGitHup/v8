/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Header file for handling debug exception
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jul 1 16:34:40 2021
 */

#ifndef HM_UVMM_VMEXIT_DEBUG_H
#define HM_UVMM_VMEXIT_DEBUG_H

#include <asm/drivers/hypervisor.h>
#include <external/libuvmm/uvmm.h>
#include <hongmeng/errno.h>

#ifdef CONFIG_VM_GDB_DEBUG
int gdbstub_handle_debug(vcpu_t *vcpu, esr_t esr);
#else
static inline int gdbstub_handle_debug(vcpu_t *vcpu, esr_t esr)
{
	UNUSED(vcpu, esr);
	return E_HM_OPNOTSUPP;
}
#endif

#endif
