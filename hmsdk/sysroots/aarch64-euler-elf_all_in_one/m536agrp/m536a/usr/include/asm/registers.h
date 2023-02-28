/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jul 23 00:47:11 2018
 */
#ifndef AARCH64_UAPI_ASM_REGISTERS_H
#define AARCH64_UAPI_ASM_REGISTERS_H

#include <hmkernel/types.h>
#include <hmkernel/compiler.h>

/* Indicate that the arch_fpu_regs is used to save/restore the fpu context. */
#define __A64_FPU_REGS_FLAG_IS_USING		((__u32)0x1U)

struct arch_fpu_regs {
	__uint128_t vregs[32];
	__u32 fpsr;
	__u32 fpcr;
	__u32 flags;
	__u32 rsvd1;
};

#define __ARCH_FPU_REGS_ZEROED {{0, }, (__u32)0, (__u32)0}

struct __arch_fpsimd_state {
	struct arch_fpu_regs fpregs;
};

/*
 * In aarch64_context_switch, the SP would be set as the start
 * address of the arch_regs. According to the ARMv8 Architecture
 * Reference Manual, when the SCTLR_EL1.SA is set to 1, if a load
 * or store instruction executed at EL1 uses the SP as the base
 * address and the SP is not aligned to a 16-byte boundary, then
 * a SP alignment fault exception is generated. To avoid triggering
 * the SP alignment fault exception, let the base address of the
 * arch_regs be always aligned to 16-byte.
 */
struct arch_regs {
	__u64 __regs[36];
} __aligned(16);

#define __ARCH_REGS_ZEROED {{0, }}

/* special registers are same for aarch32 and aarch64 */
#define __REG_LR(regs)		((regs)->__regs[30])
#define __REG_SPSR(regs)	((regs)->__regs[31])
#define __REG_PC(regs)		((regs)->__regs[32])
#define __REG_SP(regs)		((regs)->__regs[33])
#define __REG_TPID(regs)	((regs)->__regs[34])
#define __REG_TPIDRRO(regs)	((regs)->__regs[35])
/*
 * __REG_TLS_K is set using sysfast_set_tls and readonly. __REG_TLS is also set using
 * sysfast_set_tls but can also changed in userspace. They should contain same value.
 */
#define __REG_TLS		__REG_TPID
#define __REG_TLS_K		__REG_TPIDRRO

#define __REG_NORMAL(regs, n)	((regs)->__regs[(n)])
#define __REG_FP(regs)		__REG_NORMAL(regs, 29)
#define __REG_X0(regs)		((regs)->__regs[0])
#define __REG_X1(regs)		((regs)->__regs[1])
#define __REG_X2(regs)		((regs)->__regs[2])
#define __REG_X3(regs)		((regs)->__regs[3])
#define __REG_X4(regs)		((regs)->__regs[4])
#define __REG_X5(regs)		((regs)->__regs[5])
#define __REG_X6(regs)		((regs)->__regs[6])
#define __REG_X7(regs)		((regs)->__regs[7])
#define __REG_X8(regs)		((regs)->__regs[8])
#define __REG_X9(regs)		((regs)->__regs[9])
#define __REG_X10(regs)		((regs)->__regs[10])
#define __REG_X11(regs)		((regs)->__regs[11])
#define __REG_X18(regs)		((regs)->__regs[18])
#define __REG_X19(regs)		((regs)->__regs[19])
#define __REG_X20(regs)		((regs)->__regs[20])
#define __REG_X21(regs)		((regs)->__regs[21])

#define __REG_ARG0		__REG_X0
#define __REG_ARG1		__REG_X1
#define __REG_ARG2		__REG_X2
#define __REG_ARG3		__REG_X3
#define __REG_ARG4		__REG_X4
#define __REG_ARG5		__REG_X5
#define __REG_ARG6		__REG_X6
#define __REG_ARG7		__REG_X7
#define __REG_RETV		__REG_X0

/* sysproc boot args */
#define __REG_SYSPROC_ARG0(regs)	__REG_X0(regs)
#define __REG_SYSPROC_ARG1(regs)	__REG_X1(regs)
#define __REG_SYSPROC_ARG2(regs)	__REG_X2(regs)
#define __REG_SYSPROC_ARG3(regs)	__REG_X3(regs)
#define __REG_SYSPROC_ARG4(regs)	__REG_X4(regs)
#define __REG_SYSPROC_ARG5(regs)	__REG_X5(regs)
#define __REG_SYSPROC_ARG6(regs)	__REG_X6(regs)
#define __REG_SYSPROC_ARG7(regs)	__REG_X7(regs)
#define __REG_SYSPROC_ARG8(regs)	__REG_X8(regs)
#define __REG_SYSPROC_ARG9(regs)	__REG_X9(regs)
#define __REG_SYSPROC_ARG10(regs)	__REG_X10(regs)
#define __REG_SYSPROC_ARG11(regs)	__REG_X11(regs)

/* RPCINFO is not part of ARG */
#define __REG_RPCINFO		__REG_X19
#define __REG_ACTV_INITATTR	__REG_X20
#define __REG_ACTV_USERADDR	__REG_X21

#endif
