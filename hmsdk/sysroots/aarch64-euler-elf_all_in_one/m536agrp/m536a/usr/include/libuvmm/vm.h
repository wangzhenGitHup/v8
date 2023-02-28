/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jun 03 11:10:40 2019
 */

#ifndef HM_UVMM_UVMM_VM_H
#define HM_UVMM_UVMM_VM_H
#include <stdint.h>
#include <hmkernel/drivers/hypervisor.h>
#include <external/libuvmm/uvmm.h>

uint64_t vcpu_get_reg(const vcpu_t *vcpu, uint64_t getreg);
void vcpu_set_reg(const vcpu_t *vcpu, uint64_t reg, uint64_t value);
void vcpu_skip_instruction(const vcpu_t *vcpu);

cref_t *vm_get_vcpu_ctx(const vm_t *vm, int index);

int vm_conv_gpa_to_hva(const vm_t *vm, uint64_t gpa, uint64_t *hva);
int vm_conv_gpa_to_hva_len(const vm_t *vm, uint64_t gpa, uint64_t *hva, uint64_t access_len);
int vm_conv_shm_hpa_to_hva(const vm_t *vm, uint64_t hpa, uint64_t *hva);
bool is_gpa_in_vm_region(const vm_t *vm, uint64_t gpa, size_t size);

void set_dev_group_id(unsigned int dev_group_id);
unsigned int get_dev_group_id(void);

#endif
