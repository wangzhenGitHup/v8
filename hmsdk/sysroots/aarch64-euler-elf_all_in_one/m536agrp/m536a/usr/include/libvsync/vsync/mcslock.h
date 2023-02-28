/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Mellor-Crummey Scott Lock
 * Author: Huawei Dresden Research Center
 * Create: Fri 31 Jan 2020 03:21:29 PM CET
 */
#ifndef VSYNC_MCSLOCK_H
#define VSYNC_MCSLOCK_H
/*******************************************************************************
 * Mellor-Crummey Scott Lock - the well-known scalable lock.
 *
 * MCS lock is a scalable lock that guarantees FIFO order. The MCS lock forms
 * a queue of waiting threads (each thread has one node in the queue), and lets
 * them spin on local variables of their nodes.
 *
 * Note that this implementation is not reentrant (recursive).
 *
 * ## Example mcslock:
 *
 * The following example shows how to use the MCS lock. Each threads needs a
 * context, ie, an instance of `mcs_node_t`. When acquiring or releasing the
 * lock, one needs to pass the lock and the context as arguments. The context
 * of a thread should not be used in multiple MCS locks at the same time.
 *
 * ```
 * #include <vsync/mcslock.h>
 *
 * mcslock_t lock = MCSLOCK_INIT();
 * mcs_node_t nodes[MAX_THREADS];
 *
 * void run(unsigned int tid) {
 *     mcs_node_t *i = &nodes[tid];
 *
 *     mcslock_acquire(&lock, i);
 *     ...
 *     mcslock_release(&lock, i);
 * }
 * ```
 *
 * Reference:
 *     J.Mellor-Crummey, M.L.Scott. Algorithms for scalable synchronization
 *     on shared-memory multiprocessors. ACM Trans. on Computer Systems. 1991
 *
 ******************************************************************************/

#include <vsync/atomic.h>
#include <vsync/cache.h>
#include <stddef.h>

typedef struct mcs_node_s {
	vatomicptr(struct mcs_node_s *) next;
	vatomic_t locked;
} __vsync_cachealign mcs_node_t;

typedef struct mcslock_s {
	vatomicptr(struct mcs_node_s *) tail;
} __vsync_cachealign mcslock_t;

/** Initializer of `mcslock`. */
#define MCSLOCK_INIT()                                                         \
	{                                                                      \
		.tail = VATOMIC_INIT(0)                                        \
	}

/*******************************************************************************
 * functions
 ******************************************************************************/

static inline void mcslock_init(struct mcslock_s *l)
{
	vatomicptr_write(&l->tail, NULL);
}

/**
 * Tries to acquire the MCS lock.
 *
 * @param l MCS lock
 * @param i thread/core node
 * @return 1 on success, 0 on failure
 */
static inline int mcslock_tryacquire(struct mcslock_s *l, struct mcs_node_s *i)
{
	struct mcs_node_s *pred;

	vatomicptr_write_rlx(&i->next, NULL);
	vatomic_write_rlx(&i->locked, 1);
	pred = vatomicptr_cmpxchg(&l->tail, NULL, i);
	if (pred == NULL)
		return 1;

	__VERIFIER_vatomicptr_read_neq(&l->tail, pred);
	return 0;
}

/**
 * Acquires the MCS lock.
 *
 * @param l MCS lock
 * @param i thread/core node
 */
static inline void mcslock_acquire(struct mcslock_s *l, struct mcs_node_s *i)
{
	struct mcs_node_s *pred;

	vatomicptr_write_rlx(&i->next, NULL);
	vatomic_write_rlx(&i->locked, 1);
	pred = vatomicptr_xchg(&l->tail, i);
	if (pred == NULL)
		return;
	vatomicptr_write_rel(&pred->next, i);
	vatomic_await_eq_acq(&i->locked, 0);
}

static inline void mcslock_release(struct mcslock_s *l, struct mcs_node_s *i)
{
	struct mcs_node_s *next;

	if (vatomicptr_read_rlx(&i->next) == NULL) {
		next = vatomicptr_cmpxchg_rel(&l->tail, i, NULL);
		if (next == i)
			return;
		vatomicptr_await_neq_rlx(&i->next, NULL);
	}
	next = vatomicptr_read_acq(&i->next);
	vatomic_write_rel(&next->locked, 0);
}

/**
 * Returns whether there is a thread waiting to acquire the MCS lock.
 *
 * This function should only be called by the current owner of the lock.
 *
 * @param l MCS lock
 * @param i thread/core node
 */
static inline int mcslock_has_waiters(struct mcslock_s *l, struct mcs_node_s *i)
{
	(void)l;
	return (vatomicptr_read_rlx(&i->next) != NULL);
}

#endif
