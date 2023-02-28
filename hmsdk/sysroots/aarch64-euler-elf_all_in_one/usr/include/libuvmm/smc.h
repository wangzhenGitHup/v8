/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: SMC interface.
 * Author: Huawei OS Kernel Lab
 * Create: Thu Oct 14 13:34:09 2021
 */

#ifndef HM_UVMM_UVMM_SMC_H
#define HM_UVMM_UVMM_SMC_H

#define UVMM_SMC_RESULT_LEN	4
struct uvmm_smc_result {
	unsigned long arg[UVMM_SMC_RESULT_LEN];
};

int uvmm_smc_call(unsigned long func_id, unsigned long arg0, unsigned long arg1, unsigned long arg2,
		 unsigned long arg3, unsigned long arg4, unsigned long arg5, unsigned long arg6,
		 struct uvmm_smc_result *result);

#endif // HM_UVMM_UVMM_SMC_H
