/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Uvmm gdb target header
 * Author: Huawei OS Kernel Lab
 * Create: Tue Apr 13 11:37:02 2021
 */


#ifndef HM_LIBUVMM_VM_GDBTARGET_H
#define HM_LIBUVMM_VM_GDBTARGET_H

#include <external/libuvmm/uvmm.h>
#include <lib/dlist.h>
#include <hmkernel/types.h>

#define GDB_AARCH64_GENERAL_REGNUM 31
#define GDB_ARCH_NAME_LEN_MAX 16

enum target_wp_type {
	TARGET_WP_WRITE,
	TARGET_WP_READ,
	TARGET_WP_ACCESS,
};

typedef struct {
	__u64 addr;
	__u64 len;
	enum target_wp_type type;
} vcpu_watchpoint;

struct gdb_target {
	/* Default number of registers that can be operated by the gdb client. */
	int core_reg_num;
	char name[GDB_ARCH_NAME_LEN_MAX];
	const struct target_ops *ops;

	void *debug_info;
};

typedef struct sw_breakpoint_info {
	__u64 pc;
	__u32 saved_insn;
	int ref_count;
	struct dlist_node entry;
} sw_breakpoint_t;

struct target_ops {
	int (*init)(const vm_t *vm);
	int (*setup_guset_debug)(const vm_t *vm, bool enable);
	int (*set_pc)(const vcpu_t *vcpu, uint64_t addr);
	int (*get_pc)(const vcpu_t *vcpu, uint64_t *addr);
	int (*write_register)(const vcpu_t *vcpu, uint32_t regid, uint64_t val);
	int (*read_register)(const vcpu_t *vcpu, uint32_t regid, uint64_t *val);
	int (*write_registers)(const vcpu_t *vcpu, uint32_t regnum,
			       const uint64_t *regs);
	int (*read_registers)(const vcpu_t *vcpu, uint32_t regnum,
			      uint64_t *regs);
	int (*write_mem)(const vcpu_t *vcpu, __u64 addr, const char *buf,
			 __u64 size);
	int (*read_mem)(const vcpu_t *vcpu, __u64 addr, char *buf, __u64 size);
	int (*enable_single_step)(const vcpu_t *vcpu);
	int (*disable_single_step)(const vcpu_t *vcpu);
	int (*insert_hw_breakpoint)(const vm_t *vm, __u64 addr);
	int (*delete_hw_breakpoint)(const vm_t *vm, __u64 addr);
	int (*find_hw_breakpoint)(__u64 addr);
	int (*insert_sw_breakpoint)(const vcpu_t *vcpu, __u64 addr);
	int (*delete_sw_breakpoint)(const vcpu_t *vcpu, __u64 addr);
	sw_breakpoint_t *(*find_sw_breakpoint)(__u64 addr);
	int (*insert_hw_watchpoint)(const vm_t *vm, __u64 addr, __u64 len,
				    enum target_wp_type type);
	int (*delete_hw_watchpoint)(const vm_t *vm, __u64 addr, __u64 len, enum target_wp_type type);
	vcpu_watchpoint *(*find_hw_watchpoint)(__u64 addr, bool is_store);
	void (*clear_debug_contrl_config)(const vcpu_t *vcpu, bool detach);
};

const struct target_ops *get_target_ops(const vm_t *vm);

#endif
