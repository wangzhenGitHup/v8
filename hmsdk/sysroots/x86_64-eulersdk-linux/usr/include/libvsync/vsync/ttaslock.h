/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Test and Set lock
 * Author: Huawei Dresden Research Center
 * Create: Thu 02 Apr 2020
 */
#ifndef VSYNC_TTAS_H
#define VSYNC_TTAS_H
/*******************************************************************************
 * TTAS Test, Test and Set lock
 *
 * Reference:
 *   Maurice Herlihy, Nir Shavit, The Art of Multiprocessor Programming [ch 7.3]
 ******************************************************************************/

#include <vsync/atomic.h>

struct ttaslock_s {
	vatomic_t state;
};
typedef struct ttaslock_s ttaslock_t;

#define TTASLOCK_INIT()                                                        \
	{                                                                      \
		.state = ATOMIC_INIT(0)                                        \
	}

static inline void ttaslock_init(struct ttaslock_s *l)
{
	vatomic_init(&l->state, 0);
}

static inline void ttaslock_acquire(struct ttaslock_s *l)
{
	while (1) {
		vatomic_await_eq_rlx(&l->state, 0);
		if (!vatomic32_xchg_acq(&l->state, 1))
			return;
	}
}

static inline void ttaslock_release(struct ttaslock_s *l)
{
	vatomic_write_rel(&l->state, 0);
}
#endif
