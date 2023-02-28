/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: reentrant spinlock
 * Author: Huawei Dresden Research Center
 * Create: Fri 14 Feb 2020 10:23:15 AM CET
 */
#ifndef VSYNC_REC_SPIN_H
#define VSYNC_REC_SPIN_H
/*******************************************************************************
 * Reentrant implementation of a CAS spinlock
 *
 * Requires NR_OWNERS to be defined.
 *******************************************************************************/

#ifndef NR_OWNERS
#error Must config NR_OWNERS to be the total number of potential lock owners.
#endif

#include <vsync/atomic.h>
#include <vsync/cache.h>

struct rec_spinlock_s {
	vatomic_t owner;
	__vsync_cachepad(atomic_t, pad);
	vuint32_t counter;
} __vsync_cachealign;
typedef struct rec_spinlock_s rec_spinlock_t;

// Initializes the reentrant spinlock.
#define REC_SPINLOCK_INIT()                                                    \
	{                                                                      \
		.owner = ATOMIC_INIT(NR_OWNERS), .counter = 0                  \
	}

static inline void rec_spinlock_init(struct rec_spinlock_s *l)
{
	vatomic_init(&l->owner, NR_OWNERS);
	l->counter = 0;
}

// Returns 1 if lock successfully acquired, otherwise 0.
static inline int rec_spinlock_trylock(struct rec_spinlock_s *l,
				       unsigned int cpuid)
{
	vuint32_t old;
	vuint32_t owner = vatomic_read_rlx(&l->owner);

	if (owner == cpuid) {
		l->counter++;
		return 1;
	}

	if (owner != NR_OWNERS)
		return 0;

	old = vatomic_cmpxchg_acq(&l->owner, NR_OWNERS, cpuid);
	return old == NR_OWNERS;
}

static inline void rec_spinlock_lock(struct rec_spinlock_s *l,
				     unsigned int cpuid)
{
	if (vatomic_read_rlx(&l->owner) == cpuid) {
		l->counter++;
		return;
	}

	// Wait until spinlock is unlocked (value NR_OWNERS) and then lock
	vatomic32_await_eq_set_acq(&l->owner, NR_OWNERS, cpuid);
}

static inline void rec_spinlock_unlock(struct rec_spinlock_s *l)
{
	if (l->counter == 0) {
		vatomic_write_rel(&l->owner, NR_OWNERS);
		return;
	}
	l->counter--;
}

#endif
