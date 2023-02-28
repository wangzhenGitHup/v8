/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: HMSIGNUM arrangement
 * Author: Huawei OS Kernel Lab
 * Create: Tue Aug 13 13:24:12 2019
 */
#ifndef UAPI_HMSIGNAL_H
#define UAPI_HMSIGNAL_H

#include <hmkernel/types.h>
#include <hmkernel/strict.h>

struct __hmsigmask {
	/* We have 64 signals, use 2 bits for each */
	__u64 __mask;
};

#define HMSIGNUM_MIN		1
#define HMSIGNAL_KILL		1
#define HMSIGNAL_PDEBUG_STOP	2
#define HMSIGNAL_FREEZE		3
#define HMSIGNAL_COREDUMP	4
#define HMSIGNAL_POSIX		10

/*
 * Because the timer signal is directly from the kernel to the user space,
 * we use another hmsignal(different with HMSIGNAL_POSIX) to handle alarm signal.
 */
#define HMSIGNAL_ALARM		11
#define HMSIGNUM_MAX		63

/*
 * Allow HMSIGNAL_KILL/POSIX/ALARM/PDEBUG_STOP to interrupt futex wait with mask == NULL
 * by default.
 */
#define HMSIGNAL_DEFAULT_NONMASK ((1ULL << (unsigned long long)(HMSIGNAL_KILL)) | \
				  (1ULL << (unsigned long long)(HMSIGNAL_POSIX)) | \
				  (1ULL << (unsigned long long)(HMSIGNAL_ALARM)) | \
				  (1ULL << (unsigned long long)(HMSIGNAL_PDEBUG_STOP)))

/*
 * can't mask such hmsignals for base actv
 * HMSIGNAL_KILL        ensure the tcb can be killed immediately
 * HMSIGNAL_PDEBUG_STOP ensure the tcb can be stoped for debug
 * HMSIGNAL_FREEZE      ensure the tcb can be freezed immediately
 * HMSIGNAL_COREDUMP    ensure the tcb can be coredumped
 *
 * posix sinal should not be masked, as some libc interface has dependency
 * on them to sync other threads, such as __membarrier.
 * HMSIGNAL_POSIX       ensure the tcb can handle posix signal
 * HMSIGNAL_ALARM       ensure the tcb can handle posix signal ALARM
 */
#define HMSIGNAL_BASE_ACTV_NONMASK ((((unsigned long long)1u << (unsigned long long)(HMSIGNAL_KILL)) | \
				    ((unsigned long long)1u << (unsigned long long)(HMSIGNAL_PDEBUG_STOP)) | \
				    ((unsigned long long)1u << (unsigned long long)(HMSIGNAL_FREEZE)) | \
				    ((unsigned long long)1u << (unsigned long long)(HMSIGNAL_COREDUMP)) | \
				    ((unsigned long long)1u << (unsigned long long)(HMSIGNAL_POSIX)) | \
				    ((unsigned long long)1u << (unsigned long long)(HMSIGNAL_ALARM))))

/*
 * can't mask such hmsignals for emrg actv
 * HMSIGNAL_KILL        ensure the tcb can be killed immediately
 */
#define HMSIGNAL_EMRG_ACTV_NONMASK ((unsigned long long)1u << (unsigned long long)(HMSIGNAL_KILL))

#define HMSIGNAL_MASK_NONE ((__u64)0)
#define HMSIGNAL_MASK_ALL ((__u64)-1)
#define HMSIGNAL_MASK_EMRG (~HMSIGNAL_EMRG_ACTV_NONMASK)

/* Do not change the priority of the thread */
#define HMSIGNAL_DEFAULT_PRIO_FLAG (unsigned int)(-1)

static inline __bool
__hmsignum_is_valid(int signum)
{
	return signum >= HMSIGNUM_MIN && signum <= HMSIGNUM_MAX;
}
#endif /* !UAPI_HMSIGNAL_H */
