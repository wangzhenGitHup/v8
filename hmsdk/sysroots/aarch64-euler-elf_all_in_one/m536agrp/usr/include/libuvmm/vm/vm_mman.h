/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: vm memory management
 * Author: Huawei OS Kernel Lab
 * Create: Thu Dec 02 15:33:03 2021
 */
#ifndef HM_UVMM_VM_MMAN_H
#define HM_UVMM_VM_MMAN_H

#include <stdint.h>

int hm_vm_gpa_madvise(uint64_t gpa, uint64_t length, uint32_t flags);

#endif
