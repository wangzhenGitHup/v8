/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: proc vcpu of uvmm
 * Author: Huawei OS Kernel Lab
 * Create: Jan 30 10:44:42 2022
 */

#ifndef __UVMM_VCPU_H__
#define __UVMM_VCPU_H__

#include "vm.h"

#define GET_AFFINITY_MASK		0xFF00FFFFFFU
#define SET_AFFINITY_MASK		0xFFC1FFFFFFU

/* AArch64 SPSR bits */
#define PSR_M4_BIT			0x00000010UL
#define PSR_F_BIT			0x00000040UL
#define PSR_I_BIT			0x00000080UL
#define PSR_A_BIT			0x00000100UL
#define PSR_D_BIT			0x00000200UL

#define SCTLR_M_BIT			(1UL)
#define SCTLR_C_BIT			(1ULL << 2)
#define SCTLR_I_BIT			(1ULL << 12)
#define SCTLR_SPAN_BIT			(1ULL << 23)

#define VCPU_COMM_REG_STEP		2

int vcpu_create(vm_t *vm, unsigned int idx);
void vcpu_destroy(vcpu_t *vcpu);
void vcpu_start_raw(vcpu_t *vcpu);
void vcpu_stop_raw(vcpu_t *vcpu);
void vcpu_suspend_raw(vcpu_t *vcpu);
void vcpu_resume_raw(vcpu_t *vcpu);
int vcpu_pause_raw(vcpu_t *vcpu);
int vcpu_unpause_raw(vcpu_t *vcpu);
void vcpu_reset_raw(vcpu_t *vcpu);
void vcpu_reset_by_remote(vcpu_t *vcpu);
uint64_t vcpu_get_mpid(const vcpu_t *vcpu);
void vcpu_set_mpid(vcpu_t *vcpu, uint64_t mpid);
uint64_t vcpu_get_reg(const vcpu_t *vcpu, uint64_t getreg);
void vcpu_set_reg(const vcpu_t *vcpu, uint64_t reg, uint64_t value);
void vcpu_dump_regs(const vcpu_t *vcpu);
void vcpu_skip_instruction(const vcpu_t *vcpu);
void vcpu_change_state(vcpu_t *vcpu, const enum vcpu_state state);
vcpu_t *vcpu_get_suspend_object(vm_t *vm);
int vcpu_set_schedinfo(vm_t *vm, unsigned int vcpu_id, const struct sched_info *sched_info);

#endif