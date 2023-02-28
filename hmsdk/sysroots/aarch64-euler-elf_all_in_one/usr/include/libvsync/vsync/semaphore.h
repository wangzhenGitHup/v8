/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Description: semaphore apis
 * Author: Huawei Dresden Research Center
 * Create: Tue 10 Dec 2019 07:50:29 PM CET
 */
#ifndef VSYNC_SEMAPHORE_H
#define VSYNC_SEMAPHORE_H

#include <vsync/atomic.h>

struct semaphore_s {
	atomic_t s;
};

typedef struct semaphore_s semaphore_t;

// Initializes the semaphore with n resources.
#define SEMAPHORE_INIT(n)                                                      \
	{                                                                      \
		ATOMIC_INIT(n)                                                 \
	}

static inline void semaphore_init(struct semaphore_s *s, unsigned int n)
{
	atomic_write(&s->s, n);
}

/* Acquires i resources of the semaphore if available, other blocks until enough
 * resources are available in the semaphore.
 * Requirement: Only call semaphore_acquire with i <= N.
 */
static inline void semaphore_acquire(struct semaphore_s *s, unsigned int i)
{
	// awaits the subtraction does not overflow, then subtract.
	// This could be implemented with a cmpxchg loop as well, but
	// atomic_await_ge_sub politely waits with WFE instruction.
	atomic_await_ge_sub_acq(&s->s, i, i);
}

/* Acquires i resources of the semaphore if available and returns 1, otherwise
 * returns 0.
 * Requirement: Only call semaphore_acquire with i <= N.
 */
static inline int semaphore_tryacquire(struct semaphore_s *s, unsigned int i)
{
	unsigned int old = atomic_read_rlx(&s->s);
	if (old < i)
		return 0;
	return atomic_cmpxchg_acq(&s->s, old, old - i) == old;
}

/* Releases i resources of the semaphore. */
static inline void semaphore_release(struct semaphore_s *s, unsigned int i)
{
	atomic_add_rel(&s->s, i);
}

#endif
