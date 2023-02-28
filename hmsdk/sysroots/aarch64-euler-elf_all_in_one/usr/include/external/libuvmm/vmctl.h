/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Head file of vmctl.c under uapps/vmctrl
 * Author: Huawei OS Kernel Lab
 * Create: Sat Jul 03 16:29:48 2021
 */
#ifndef HM_UVMM_VMCTL_H
#define HM_UVMM_VMCTL_H

struct vm_state_info {
	bool vm_state;
	unsigned int nr_vcpus;
};

#endif
