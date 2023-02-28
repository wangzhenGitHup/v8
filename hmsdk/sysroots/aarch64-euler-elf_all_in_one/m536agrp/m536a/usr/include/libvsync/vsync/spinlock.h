/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: spinlock apis
 * Author: Huawei Dresden Research Center
 * Create: Wed 22 Jan 2020 12:00:47 PM CET
 */
#ifndef VSYNC_SPIN_H
#define VSYNC_SPIN_H

#include <vsync/atomic.h>

struct spinlock_s {
	atomic_t lock;
};

typedef struct spinlock_s spinlock_t;

// Initializes the ticketlock.
#define SPINLOCK_INIT()                                                        \
	{                                                                      \
		.lock = ATOMIC_INIT(0)                                         \
	}

static inline void spinlock_init(struct spinlock_s *l)
{
	vatomic_init(&l->lock, 0);
}

static inline void spinlock_acquire(struct spinlock_s *l)
{
	vatomic32_await_eq_set_acq(&l->lock, 0, 1);
}

static inline int spinlock_tryacquire(struct spinlock_s *l)
{
	return vatomic32_cmpxchg_acq(&l->lock, 0, 1) == 0;
}

static inline void spinlock_release(struct spinlock_s *l)
{
	vatomic_write_rel(&l->lock, 0);
}

#endif
