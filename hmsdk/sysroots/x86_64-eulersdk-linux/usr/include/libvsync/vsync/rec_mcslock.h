/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: recursive msclock
 * Author: Huawei Dresden Research Center
 * Create: Thu 15 Oct 2020 01:33:17 PM CEST
 */
#ifndef VSYNC_REC_MCSLOCK_H
#define VSYNC_REC_MCSLOCK_H
/*******************************************************************************
 * @file rec_mcslock.h
 * @brief Recursive MCS lock implementation using recursive.h
 *
 * `rec_mcslock` is a MCS lock that supports recursion, ie, is reentrant.
 ******************************************************************************/

#include <vsync/atomic.h>
#include <vsync/cache.h>
#include <vsync/mcslock.h>
#include <vsync/recursive.h>

/** @cond DO_NOT_DOCUMENT */
DEF_RECURSIVE_LOCK(rec_mcslock, struct mcslock_s, mcslock_init, mcslock_acquire,
		   mcslock_release, WITHOUT_TRYACQUIRE,
		   WITH_CONTEXT(struct mcs_node_s))
/** @endcond */

/** Initializer of `rec_mcslock`. */
#define REC_MCSLOCK_INIT() RECURSIVE_LOCK_INIT(MCSLOCK_INIT())

/**
 * Initializes the recursive MCS lock.
 *
 * @param l recursive MCS lock
 */
void rec_mcslock_init(struct rec_mcslock_s *l);

/**
 * Acquires the recursive MCS lock.
 *
 * This function can be called multiple times by the same thread, consecutively.
 *
 * @param l recursive MCS lock
 * @param id thread ID or core ID
 * @param ctx MCS node of the caller thread/core
 */
void rec_mcslock_acquire(struct rec_mcslock_s *l, vuint32_t id,
			 struct mcs_node_s *ctx);

/**
 * Releases the recursive MCS lock.
 *
 * To fully release the lock, this function should be called the same number of
 * times as the acquire was consecutively called by thread that currently owns
 * the lock.
 *
 * @param l recursive MCS lock
 * @param ctx MCS node of the caller thread/core
 */
void rec_mcslock_release(struct rec_mcslock_s *l, struct mcs_node_s *ctx);

#endif
