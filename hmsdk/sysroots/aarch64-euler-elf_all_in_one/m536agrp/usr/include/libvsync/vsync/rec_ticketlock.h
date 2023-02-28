/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: recursive ticketlock
 * Author: Huawei Dresden Research Center
 * Create: Thu 15 Oct 2020 01:17:49 PM CEST
 */
#ifndef VSYNC_REC_TICKETLOCK_H
#define VSYNC_REC_TICKETLOCK_H
/*******************************************************************************
 * @file rec_ticketlock.h
 * @brief Recursive ticketlock implementation using recursive.h
 *
 * `rec_ticketlock` is a ticketlock that supports recursion, ie, is reentrant.
 ******************************************************************************/

#include <vsync/atomic.h>
#include <vsync/cache.h>
#include <vsync/ticketlock.h>
#include <vsync/recursive.h>

/** @cond DO_NOT_DOCUMENT */
DEF_RECURSIVE_LOCK(rec_ticketlock, ticketlock_t, ticketlock_init,
		   ticketlock_acquire, ticketlock_release,
		   WITH_TRYACQUIRE(ticketlock_tryacquire), WITHOUT_CONTEXT)
/** @endcond */

/** Initializer of `rec_ticketlock`. */
#define REC_TICKETLOCK_INIT() RECURSIVE_LOCK_INIT(TICKETLOCK_INIT())

/**
 * Initializes the recursive ticketlock.
 *
 * @param l recursive ticketlock
 */
void rec_ticketlock_init(struct rec_ticketlock_s *l);

/**
 * Acquires the recursive ticketlock.
 *
 * This function can be called multiple times by the same thread, consecutively.
 *
 * @param l recursive ticketlock
 * @param id thread ID or core ID
 */
void rec_ticketlock_acquire(struct rec_ticketlock_s *l, vuint32_t id);

/**
 * Releases the recursive ticketlock.
 *
 * To fully release the lock, this function should be called the same number of
 * times as the acquire was consecutively called by thread that currently owns
 * the lock.
 *
 * @param l recursive ticketlock
 */
void rec_ticketlock_release(struct rec_ticketlock_s *l);

/**
 * Tries to acquire the recursive ticketlock.
 *
 * This can be called multiple times by the same thread, consecutively.
 *
 * @param l recursive ticketlock
 * @param id thread ID or core ID
 * @return 1 on success, 0 on failure
 */
int rec_ticketlock_tryacquire(struct rec_ticketlock_s *l, vuint32_t id);

#endif
