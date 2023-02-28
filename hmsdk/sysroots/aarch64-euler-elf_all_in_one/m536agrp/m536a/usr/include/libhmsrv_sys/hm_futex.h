/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Definition of sysif server futex
 * Author: Huawei OS Kernel Lab
 * Create: Fri Sep 21 16:32:46 2018
 */
#ifndef _LIBVSYSCALL_HM_FUTEX_H
#define _LIBVSYSCALL_HM_FUTEX_H

#include <asm/types.h>

/* To be compabitable with linux futex, define the same macros as Linux here */
#define FUTEX_WAIT		0
#define FUTEX_WAKE		1
#define FUTEX_FD		2
#define FUTEX_REQUEUE		3
#define FUTEX_CMP_REQUEUE	4
#define FUTEX_WAKE_OP		5
#define FUTEX_LOCK_PI		6
#define FUTEX_UNLOCK_PI 	7
#define FUTEX_TRYLOCK_PI	8
#define FUTEX_WAIT_BITSET	9
#define FUTEX_WAKE_BITSET	10

#define FUTEX_TYPE_PRIVATE		(0x0U)
#define FUTEX_TYPE_SHARED		(0x1U)

#define FUTEX_PRIVATE_FLAG 128

#define FUTEX_CLOCK_REALTIME 256

#define FUTEX_BITSET_MATCH_ANY	0xffffffffUL

struct thread_futex_wait_args {
	__u64 uaddr;
	__s32 val;
	__u64 timeout;
	__u64 sigmask;
	__u64 bitset;
};

struct thread_futex_wake_args {
	__u64 uaddr;
	__u32 num;
	__u64 bitset;
};

struct thread_futex_requeue_args {
	__u64 src_uaddr;
	__u64 dst_uaddr;
	__u32 deq_num;
	__u32 req_num;
};

struct timespec;
struct __hmsigmask;
int hm_futex_wait(volatile int *uaddr, int val,
		  const struct timespec *ts, unsigned int flags);
int hm_futex_timedwait(volatile int *uaddr, int val, unsigned long long *timeout,
		       struct __hmsigmask *mask, unsigned int flags);
int hm_futex_wait_bitset(volatile int *uaddr, int val,
			 const struct timespec *ts, unsigned int flags, unsigned long bitset);
int hm_futex_wait_interruptible(volatile int *uaddr, int val,
				const struct timespec *ts, unsigned int flags);
int hm_futex_wake(volatile int *uaddr, unsigned int num, unsigned int flags);
int hm_futex_wake_bitset(volatile int *uaddr, unsigned int num, unsigned int flags, unsigned long bitset);
int hm_futex_requeue(volatile int *src_ptr, volatile int *dst_ptr,
		     unsigned int deq_num, unsigned int req_num, unsigned int flags);
int hm_set_robust_list(const void *list_head, unsigned long size);
int hm_get_robust_list(int tid, void **head_ptr, unsigned long *len);

#ifdef CONFIG_RT_FUTEX
int hm_futex_wait_pi(volatile int *uaddr, unsigned int flags,
		     const struct timespec *ts);
int hm_futex_wake_pi(volatile const int *uaddr, unsigned int flags);
#endif

/*
 * @option in futex_wake_op is encoded as:
 *  +---+---+-----------+-----------+
 *  |op |cmp|   oparg   |  cmparg   |
 *  +---+---+-----------+-----------+
 *    4   4       12          12    <== # of bits
 */
#define FUTEX_OP_OP_SHIFT       28u
#define FUTEX_OP_CMP_SHIFT      24u
#define FUTEX_OP_OPARG_SHIFT    12u

#define FUTEX_OP_SIGN_BIT       11u

#define FUTEX_OP_OP_MASK          (0x7u << 28)
#define FUTEX_OP_CMP_MASK         (0xfu << 24)
#define FUTEX_OP_OPARG_MASK       (0xfffu << 12)
#define FUTEX_OP_CMPARG_MASK      (0xfffu)

#define FUTEX_OP_SET		0u	/* *(int *)uaddr2 = oparg; */
#define FUTEX_OP_ADD		1u	/* *(int *)uaddr2 += oparg; */
#define FUTEX_OP_OR		2u	/* *(int *)uaddr2 |= oparg; */
#define FUTEX_OP_ANDN		3u	/* *(int *)uaddr2 &= ~oparg; */
#define FUTEX_OP_XOR		4u	/* *(int *)uaddr2 ^= oparg; */

/*
 * bit-wise ORing the following value into op
 * causes (1 << oparg) to be used as the operand
 */
#define FUTEX_OP_OPARG_FLAG	8u	/* Use (1 << oparg) as operand */

#define FUTEX_OP_CMP_EQ		0u	/* if (oldval == cmparg) wake */
#define FUTEX_OP_CMP_NE		1u	/* if (oldval != cmparg) wake */
#define FUTEX_OP_CMP_LT		2u	/* if (oldval < cmparg) wake */
#define FUTEX_OP_CMP_LE		3u	/* if (oldval <= cmparg) wake */
#define FUTEX_OP_CMP_GT		4u	/* if (oldval > cmparg) wake */
#define FUTEX_OP_CMP_GE		5u	/* if (oldval >= cmparg) wake */

int hm_futex_wake_op(volatile int *uaddr1, volatile int *uaddr2,
		     unsigned int nr_wake1, unsigned int nr_wake2,
		     int option);

#endif
