/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: SMC interface.
 * Author: Huawei OS Kernel Lab
 * Create: Thu Oct 14 13:34:09 2021
 */

#ifndef HM_UVMM_UVMM_TEEOS_H
#define HM_UVMM_UVMM_TEEOS_H

#include <hongmeng/errno.h>
struct vcpu;

#ifdef CONFIG_SUSPEND_RESUME_TEEOS
int teeos_resume(const struct vcpu *vcpu);
void teeos_cpu_off(void);
void teeos_cpu_suspend(void);
#else
static inline int teeos_resume(const struct vcpu *vcpu)
{
	UNUSED(vcpu);
	return E_HM_OK;
}

static inline void teeos_cpu_off(void)
{
	return;
}

static inline void teeos_cpu_suspend(void)
{
	return;
}
#endif

#endif // HM_UVMM_UVMM_TEEOS_H
