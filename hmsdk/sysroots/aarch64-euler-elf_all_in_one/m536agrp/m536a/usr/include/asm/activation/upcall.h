/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: The Actv Upcall
 * Author: Huawei OS Kernel Lab
 * Create: Fri Apr 16 10:22:00 2021
 */

#ifndef AARCH64_UAPI_ASM_ACTIVATION_UPCALL_H
#define AARCH64_UAPI_ASM_ACTIVATION_UPCALL_H

#include <asm/types.h>
#include <asm/exception.h>
#include <hmkernel/ipc/hmsignal.h>

#define __ARCH_ACTV_UPCALL_ARG0		0
#define __ARCH_ACTV_UPCALL_ARG1		1
#define __ARCH_ACTV_UPCALL_ARG2		2
#define __ARCH_ACTV_UPCALL_ARG_NR	3

/*
 * Define the format of the args transfered to the actv handler to
 * handle the specific task that cannot be completed in kernel.
 */
union __arch_actv_upcall_args_u {
	__u64 buf[__ARCH_ACTV_UPCALL_ARG_NR];

	struct actv_upcall_kpagefault_info_s {
		__u64 fault_addr;
		__u64 fault_size;
		__u64 write;
	} kpagefault;

	struct actv_upcall_linux_syscall_s {
		__u64 type;
	} linux_syscall;

	struct actv_upcall_copage_alloc_s {
		__u64 vstart;
		__u64 nrpages;
	} copage_alloc;

	struct actv_upcall_copage_free_s {
		__u64 vstart;
		__u64 nrpages;
	} copage_free;

	struct actv_upcall_copage_alloc_by_order_s {
		__u64 vstart;
		__u32 order;
	} copage_alloc_by_order;

	struct actv_upcall_copage_alloc_reserve_s {
		__u32 order;
		__u64 ret_addr;
	} copage_alloc_reserve;

	struct actv_upcall_pool_grant_change_s {
		__u32 event;
		__u32 u_slot_idx;
		/*
		 * Use old_credential to transfer the binding->credential
		 * corresponding to u_slot_idx.
		 */
		__u64 old_credential;
	} pool_grant_change;

	struct actv_upcall_hmsignal_s {
		struct __hmsigmask hmsignals;
		__u64 timer_cref;
		__u32 is_kcall_restartable;
	} hmsignal;

	struct __arch_exception_info ex_info;
};

#endif /* !AARCH64_UAPI_ASM_ACTIVATION_UPCALL_H */
