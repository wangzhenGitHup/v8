/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Public interface of virtual device
 * Author: Huawei OS Kernel Lab
 * Create: Wed Apr 01 14:16:09 2020
 */
#ifndef HM_UVMM_EXTERNAL_DEVICE_H
#define HM_UVMM_EXTERNAL_DEVICE_H
#include <stdint.h>

#include "vm/vm.h"

int vdev_create(vm_t *vm, const char *nodes[], int nr_nodes);
void vdev_destroy_all(void);
#endif
