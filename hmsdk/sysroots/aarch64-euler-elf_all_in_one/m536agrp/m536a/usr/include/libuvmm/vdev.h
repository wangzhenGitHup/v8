/*
* Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
* Author: Huawei OS Kernel Lab
* Create: Tue Aug 13 15:53:56 2019
*/

#ifndef HM__EXTERNAL_VDEV_H
#define HM__EXTERNAL_VDEV_H

#include <external/libuvmm/uvmm.h>

int vdev_create(vm_t *vm, uint16_t dev_group_id, const char *nodes[],
		int nr_nodes);
void vdev_destroy(vm_t *vm);

#endif // HM__EXTERNAL_VDEV_H
