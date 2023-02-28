/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: IPC shared memory proxy for VM
 * Author: Huawei OS Kernel Lab
 * Create: Wed Sep 15 10:11:07 2021
 */
#ifndef HM_UVMM_IPCSHM_H
#define HM_UVMM_IPCSHM_H

#include <stdint.h>
#include <libhmsrv_sys/hm_vm.h>

int hm_vm_ipcshm_map(int32_t shmid, int32_t shmflg, uint32_t gpa_lists_total,
		     uint32_t gpa_lists_index, const struct gpa_list_s *gpa_list);

int hm_vm_ipcshm_unmap(int32_t shmid);

#endif
