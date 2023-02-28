/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Description: A write-preferring rwlock based on semaphore and an atomic bool
 * Author: Huawei Dresden Research Center
 * Create: Fri Oct 25 10:02:43 CEST 2019
 */
#ifndef VSYNC_RWLOCK_WP_H
#define VSYNC_RWLOCK_WP_H

/*******************************************************************************
 * A write-preferring rwlock based on semaphore and an atomic bool.
 *
 * When acquiring a read lock, wait for writers and then reserve one resource.
 * When acquiring a write lock, lock writer bit and reserve all N resources.
 *
 * Algorithm:
 *
 * write_acquire:
 *	await (wb = 0)
 *	wb = 1
 *
 * 	await (resources = N)
 * 	resources = 0
 *
 * write_release:
 * 	wb = 0
 * 	resources = N
 *
 * read_acquire:
 *	await (wb = 0)
 *
 * 	await (resources > 0)
 * 	resources--
 *
 * read_release:
 * 	resources++
 *
 ******************************************************************************/

#include <vsync/semaphore.h>
#include <vsync/atomic.h>

struct rwlock_s {
	unsigned int n;
	vatomic_t wb;
	semaphore_t rs;
};

typedef struct rwlock_s rwlock_t;

#define RWLOCK_N (1 << 31)
#define RWLOCK_INITN(N)                                                        \
	{                                                                      \
		.n = N, .wb = ATOMIC_INIT(0), .rs = SEMAPHORE_INIT(N),         \
	}

// Initializes the semaphore with the default number of resources.
#define RWLOCK_INIT() RWLOCK_INITN(RWLOCK_N)

static inline void rwlock_init(struct rwlock_s *l)
{
	l->n = RWLOCK_N;
	vatomic_init(&l->wb, 0);
	semaphore_init(&l->rs, RWLOCK_N);
}

static inline void rwlock_write_acquire(struct rwlock_s *l)
{
	vatomic_await_eq_set_rlx(&l->wb, 0, 1);
	semaphore_acquire(&l->rs, l->n); // acquire fence
}

static inline int rwlock_write_tryacquire(struct rwlock_s *l)
{
	if (vatomic_cmpxchg_rlx(&l->wb, 0, 1) != 0) { // relaxed
		return 0;
	}
	return semaphore_tryacquire(&l->rs, l->n); // acquire fence
}

static inline void rwlock_write_release(struct rwlock_s *l)
{
	vatomic_write_rlx(&l->wb, 0); // relaxed store
	semaphore_release(&l->rs, l->n); // release fence
}

static inline void rwlock_read_acquire(struct rwlock_s *l)
{
	vatomic_await_eq_rlx(&l->wb, 0);
	semaphore_acquire(&l->rs, 1); // acquire fence
}

static inline int rwlock_read_tryacquire(struct rwlock_s *l)
{
	if (vatomic_read_rlx(&l->wb)) { // relaxed read
		return 0;
	}
	return semaphore_tryacquire(&l->rs, 1); // acquire fence
}

static inline void rwlock_read_release(struct rwlock_s *l)
{
	semaphore_release(&l->rs, 1); // release fence
}

#endif
