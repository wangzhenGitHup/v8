/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Signal
 * Author: Huawei OS Kernel Lab
 * Create: Tue Nov 13 17:34:38 2018
 */
#ifndef UAPI_HMKERNEL_SIGNAL_H
#define UAPI_HMKERNEL_SIGNAL_H

#include <asm/types.h>

union sigval_u {
	int sival_int;
	__u64 sival_ptr;
};

struct __siginfo {
	__u32 si_code;
	__u32 signum;
	__u32 sender;
	__u32 si_type;
	union {
		struct {
			__u64 fault_addr;
		} __fault;
		struct {
			__s32 pid;
			__u32 uid;
			__s32 status;
		} __sigchld;
		union sigval_u sig_value;
		struct {
			__s32 pid;
			__u32 uid;
		} __sigkill;
	};
};

/* si_type */
#define __SI_KILL	0U
#define __SI_CHLD	1U
#define __SI_FAULT	2U
#define __SI_RT		3U

/* si_codes for SIGTRAP */
#define TRAP_BKPT       1       /* breakpoint */
#define TRAP_HWBKPT     4       /* hw watchpoint */

/* si_codes for SIGFPE */
#define __FPE_INTDIV	1	/* integer divide by zero */
#define __FPE_INTOVF	2	/* integer overflow */
#define __FPE_FLTDIV	3	/* floating point divide by zero */
#define __FPE_FLTOVF	4	/* floating point overflow */
#define __FPE_FLTUND	5	/* floating point underflow */
#define __FPE_FLTRES	6	/* floating point inexact result */
#define __FPE_FLTINV	7	/* floating point invalid operation */
#define __FPE_FLTUNK	14	/* undiagnosed floating-point exception */

/*
 * Same as the definition in <signal.h>.
 *
 * If __SS_AUTODISARM is set, kernel will clear the alternate
 * signal stack settings on entry to the signal handler.
 */
#define __SS_AUTODISARM       (1U << 31)

#define __SIGNAL_MIN_STANDARD  1U
#define __SIGNAL_NR_STANDARD  34U
#define __SIGNAL_MAX_STANDARD (__SIGNAL_MIN_STANDARD + __SIGNAL_NR_STANDARD - 1U)
#define __SIGNAL_MASK_STANDARD (((1ULL << __SIGNAL_MAX_STANDARD) - 1ULL) -\
				((1ULL << (__SIGNAL_MIN_STANDARD - 1)) - 1ULL))

#define __SIGNAL_UNDEFINED_MIN 32U
#define __SIGNAL_UNDEFINED_MAX 34U

#define __SIGNAL_MIN_RT  (__SIGNAL_NR_STANDARD + 1U)
#define __SIGNAL_MAX_RT 64U
#define __SIGNAL_NR_RT  (__SIGNAL_MAX_RT - __SIGNAL_MIN_RT + 1U)

#define __SIGNAL_RT __SIGNAL_MIN_RT

#define __SIGNAL_MASK_RT ((((1ULL << (__SIGNAL_MAX_RT - 1U)) - 1ULL) -\
			  ((1ULL << (__SIGNAL_MIN_RT -2U)) - 1ULL)) << 1)
#endif
