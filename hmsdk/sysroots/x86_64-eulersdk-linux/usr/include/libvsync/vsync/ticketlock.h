/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: ticketlock apis
 * Author: Huawei Dresden Research Center
 * Create: Wed 22 Jan 2020 12:00:47 PM CET
 */
#ifndef VSYNC_TICKETLOCK_H
#define VSYNC_TICKETLOCK_H
/*******************************************************************************
 * @file ticketlock.h
 * @brief Ticketlock implementation
 *
 * Ticketlock is a simple, fair lock (guarantees FIFO order).
 *
 * ## Example ticketlock:
 *
 * ```
 * #include <vsync/ticketlock.h>
 *
 * ticketlock_t lock = TICKETLOCK_INIT();
 *
 * void run() {
 *     ticketlock_acquire(&lock);
 *     ...
 *     ticketlock_release(&lock);
 * }
 * ```

 ******************************************************************************/

#include <vsync/atomic.h>

struct ticketlock_s {
	vatomic_t next;
	vatomic_t owner;
};
typedef struct ticketlock_s ticketlock_t;

#define VINT_WIDTH 32U

/* Initializer of `ticketlock`. */
#define TICKETLOCK_INIT()                                                      \
	{                                                                      \
		.next = VATOMIC_INIT(0), .owner = VATOMIC_INIT(0)              \
	}

/**
 * Initializes the ticketlock.
 *
 * @param l ticketlock
 */
static inline void ticketlock_init(struct ticketlock_s *l)
{
	vatomic_init(&l->next, 0);
	vatomic_init(&l->owner, 0);
}

/**
 * Acquires the ticketlock.
 *
 * @param l ticketlock
 */
static inline void ticketlock_acquire(struct ticketlock_s *l)
{
	vuint32_t ticket = vatomic_get_inc_rlx(&l->next);
	vatomic_await_eq_acq(&l->owner, ticket);
}

/**
 * Tries to acquire the ticketlock.
 *
 * @param l ticketlock
 * @return 1 on success, 0 on failure
 */
static inline int ticketlock_tryacquire(struct ticketlock_s *l)
{
	vuint32_t o = vatomic_read_acq(&l->owner);
	vuint32_t n = vatomic_cmpxchg_rlx(&l->next, o, o + 1);
	if (n != o)
		__VERIFIER_vatomic_read_neq(&l->owner, o);
	return n == o;
}

/**
 * Releases the ticketlock.
 *
 * @param l ticketlock
 */
static inline void ticketlock_release(struct ticketlock_s *l)
{
	vuint32_t owner = vatomic_read_rlx(&l->owner);
	vatomic_write_rel(&l->owner, owner + 1);
}

/**
 * Checks whether there are threads waiting to acquire the lock.
 *
 * This can only be called by the thread holding the lock, ie, after acquire but
 * before release.
 *
 * @param l ticketlock
 * @return 1 if threads are waiting to acquire the lock, otherwise 0.
 */
static inline int ticketlock_has_waiters(struct ticketlock_s *l)
{
	vuint64_t owner = (vuint64_t)vatomic_read_rlx(&l->owner);
	vuint64_t next = (vuint64_t)vatomic_read_rlx(&l->next);

	vuint64_t diff = next - owner;
	// correct overflows
	diff += (next < owner) ? (1UL << VINT_WIDTH) : 0;

	return (diff > 1);
}
#endif
