/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jul 23 00:47:11 2018
 */
#ifndef AARCH64_UAPI_ASM_UCONTEXT_H
#define AARCH64_UAPI_ASM_UCONTEXT_H

#include <hmkernel/types.h>
#include <asm/registers.h>

#define ARCH_UCONTEXT_32BIT		((__u64)0x1UL)
#define A64_UCONTEXT_PRIVILEGE_SERVICE	((__u64)0x2UL)
/*
 * The flag set to indicate that the tcb in the BLOCKED state is just woken up
 * due to an interrupt, and the tcb is able to restart the syscall or instruction
 * that blocked it by rewinding the pc. This is a kernel-internal flag, which
 * should be cleared before restoring user context.
 *
 * Currently, the kcall restartable flag is mainly used to help handle the
 * HMSIGNAL_ALARM: when the POSIX signal in sysmgr corresponding to the HMSIGNAL_ALARM
 * is masked, then the tcb raising the HMSIGNAL_ALARM should:
 *
 * - If the kcall restartable flag is true, it means the tcb was in BLOCKED
 *   state and woken up to handle the HMSIGNAL_ALARM. Then the tcb should
 *   rewind the pc to restore the original state of it => BLOCKED.
 *
 * - If the kcall restartable flag is false, then the tcb should do nothing and
 *   continue to execute based on the original context.
 */
#define A64_UCONTEXT_KCALL_RESTARTABLE	((__u64)0x4UL)

/*
 * make scno aligned with 32 bits so compiler is able to generate better insns.
 * See el0_sync, scno can be 0 ~ 0xffff. 0 is Linux syscall, so we make 0xffff
 * a invalid a syscall number.
 */
#define A64_UCONTEXT_FLAG_SCNO_OF(x)			\
	((__u64)(((x) >> 32u) & 0xffffULL))
#define A64_UCONTEXT_FLAG_SET_SCNO(flags, scno)		\
	(((flags) & (0xffffffffULL)) | (((scno) & 0xffffULL) << 32u))
#define A64_UCONTEXT_FLAG_SCNO_INVALID 0xffff

struct arch_uctx {
	struct arch_regs regs;
	__u64 flags;
	__u64 orig_r0;
};

static inline void
arch_uctx_set_privileged_service(struct arch_uctx *ctx)
{
	ctx->flags |= A64_UCONTEXT_PRIVILEGE_SERVICE;
}

static inline void
arch_flush_uctx_flags(struct arch_uctx *ctx, __u64 flags)
{
	ctx->flags &= (~ARCH_UCONTEXT_32BIT);
	ctx->flags |= (flags & ARCH_UCONTEXT_32BIT);
}

#define __ARCH_UCTX_ZEROED {__ARCH_REGS_ZEROED, (__u64)0, (__u64)0}
#define DEFINE_ARCH_UCTX(name) struct arch_uctx name = __ARCH_UCTX_ZEROED

#define __ARCH_UCTX_TLS_MINIMAL_SIZE	4096

#endif
