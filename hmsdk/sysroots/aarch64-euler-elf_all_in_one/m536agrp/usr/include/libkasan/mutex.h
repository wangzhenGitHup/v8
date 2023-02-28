/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Simple notrace mutex
 * Author: Huawei OS Kernel Lab
 * Create: Fri Mar 26 11:37:33 2021
 */

#ifndef KASAN_MUTEX_H
#define KASAN_MUTEX_H

#include <hmkernel/const.h>
#include <libhmsync/atomic.h>
#include <libhmsrv_sys/hm_futex.h>

#define CACHE_BLOCK_SIZE 64
#define CACHE_ALIGNED __attribute__((aligned(CACHE_BLOCK_SIZE)))
#define ALWAYS_INLINE __attribute__((always_inline)) static inline

struct kasan_mutex {
	raw_atomic_int_t value;
	raw_atomic_int_t waiter;
} CACHE_ALIGNED;

typedef struct kasan_mutex kasan_mutex_t;

/* thread will be blocked by futex_wait, and the wait value is MUTEX_WAIT_VALUE */
#define MUTEX_WAIT_VALUE 1

/* Do Not Use directly */
void kasan_mutex_wait(kasan_mutex_t *m, int value);
void kasan_mutex_wake(kasan_mutex_t *m);

ALWAYS_INLINE void kasan_mutex_init(kasan_mutex_t *m)
{
	(void)raw_atomic_int_set(&m->value, 0);
	(void)raw_atomic_int_set(&m->waiter, 0);
}

ALWAYS_INLINE void kasan_mutex_lock(kasan_mutex_t *m)
{
	while (raw_atomic_int_swap(&m->value, MUTEX_WAIT_VALUE) == MUTEX_WAIT_VALUE) {
		/*
		 * old value is MUTEX_WAIT_VALUE,
		 * a thread has got the lock, just wait
		 */
		kasan_mutex_wait(m, MUTEX_WAIT_VALUE);
	}
}

ALWAYS_INLINE void kasan_mutex_unlock(kasan_mutex_t *m)
{
	if (raw_atomic_int_read(&m->value) != 0) {
		(void)raw_atomic_int_set(&m->value, 0);
		kasan_mutex_wake(m);
	}
}

#endif /* KASAN_MUTEX_H */
