/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Sat Aug 3 15:38:47 2019
 */
#ifndef HM_UVMM_VDEV_MMIO_H
#define HM_UVMM_VDEV_MMIO_H

#include <asm/drivers/hypervisor.h>
#include <external/libuvmm/uvmm.h>
#include <mem_region.h>

int handle_mmio_read_write(const vcpu_t *vcpu, mem_region_t *mr, esr_t esr, __u64 fault_addr);
int register_mmio_region(void *opaque, mem_region_t *mr, const mem_region_ops_t *ops,
			 unsigned int dev_id, unsigned int dev_idx);
void destroy_mmio_region(mem_region_t *mr);

#ifdef CONFIG_GUEST_REGION
int register_mmio_region_for_guest(void *opaque, mem_region_t *mr, const mem_region_ops_t *ops,
				   const mem_map_node_t *mem_node);
#endif

#endif
