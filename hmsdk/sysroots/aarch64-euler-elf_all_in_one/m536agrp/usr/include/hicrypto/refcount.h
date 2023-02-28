/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: function declarations of reference count
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_REFCOUNT_H
#define CRYPTO_HEADER_REFCOUNT_H

#include <hicrypto/target.h>

#ifndef CRPT_NO_ATOMICS

#if (defined __STDC_VERSION__) && __STDC_VERSION__ >= 201112L && !defined(__STDC_NO_ATOMICS__) \
    && defined(ATOMIC_INT_LOCK_FREE) && ATOMIC_INT_LOCK_FREE > 0

#include <stdatomic.h>

typedef _Atomic int CRPT_REFCNT;

/**
 * @ingroup crypto_runtime
 *
 * @brief add ref for val
 *
 * @param val [IN] value to added
 * @param ret [OUT] result
 * @param lock [IN] lock
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_INLINE int CRPT_UP_REF(_Atomic int *val, int *ret, void *lock)
{
    (void)lock;
    *ret = atomic_fetch_add_explicit(val, 1, memory_order_relaxed) + 1;
    return CRPT_SUCCESS;
}

/**
 * @ingroup crypto_runtime
 *
 * @brief delete ref for val
 *
 * @param val [IN] value to deleted
 * @param ret [OUT] result
 * @param lock [IN] lock
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_INLINE int CRPT_DOWN_REF(_Atomic int *val, int *ret, void *lock)
{
    (void)lock;
    *ret = atomic_fetch_sub_explicit(val, 1, memory_order_relaxed) - 1;
    if (*ret == 0)
        atomic_thread_fence(memory_order_acquire);
    return CRPT_SUCCESS;
}

#define CRPT_HAVE_ATOMIC

#elif defined(__GNUC__) && defined(__ATOMIC_RELAXED) && __GCC_ATOMIC_INT_LOCK_FREE > 0

typedef int CRPT_REFCNT;

/**
 * @ingroup crypto_runtime
 *
 * @brief add ref for val
 *
 * @param val [IN] value to added
 * @param ret [OUT] result
 * @param lock [IN] lock
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_INLINE int CRPT_UP_REF(int *val, int *ret, void *lock)
{
    (void)lock;
    *ret = __atomic_fetch_add(val, 1, __ATOMIC_RELAXED) + 1;
    return CRPT_SUCCESS;
}

/**
 * @ingroup crypto_runtime
 *
 * @brief delete ref for val
 *
 * @param val [IN] value to deleted
 * @param ret [OUT] result
 * @param lock [IN] lock
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_INLINE int CRPT_DOWN_REF(int *val, int *ret, void *lock)
{
    (void)lock;
    *ret = __atomic_fetch_sub(val, 1, __ATOMIC_RELAXED) - 1;
    if (*ret == 0) {
        __atomic_thread_fence(__ATOMIC_ACQUIRE);
    }

    return CRPT_SUCCESS;
}

#define CRPT_HAVE_ATOMIC

#endif

#endif

#ifndef CRPT_HAVE_ATOMIC

typedef int CRPT_REFCNT;

#define CRPT_UP_REF(val, ret, lock)   CRPT_atomic_add(val, 1, ret, lock)
#define CRPT_DOWN_REF(val, ret, lock) CRPT_atomic_add(val, -1, ret, lock)

#endif

#endif
