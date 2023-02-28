/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: typedefs, macros and function declarations for thread
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_THREAD_H
#define CRYPTO_HEADER_THREAD_H

#include <hicrypto/target.h>

#if defined(CRPT_NO_THREAD)
typedef unsigned int CRPT_THREAD_ID;
typedef unsigned int CRPT_THREAD_ONCE;
typedef unsigned int CRPT_THREAD_LOCAL;
typedef unsigned int CRPT_THREAD_MUTEX;

#define CRPT_THREAD_ONCE_INITIALIZER  0
#define CRPT_THREAD_MUTEX_INITIALIZER 1

#else
#if defined(CRPT_LINUX) || defined(CRPT_UNIX) || defined(CRPT_APPLE)
#include <pthread.h>

typedef pthread_t CRPT_THREAD_ID;
typedef pthread_once_t CRPT_THREAD_ONCE;
typedef pthread_key_t CRPT_THREAD_LOCAL;
typedef pthread_mutex_t CRPT_THREAD_MUTEX;

#define CRPT_THREAD_ONCE_INITIALIZER  PTHREAD_ONCE_INIT
#define CRPT_THREAD_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER

#else
#error "Unknown target OS"
#endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/** thread info */
/**
 * @ingroup crypto_runtime
 *
 * @brief get current thread id
 *
 * @retval current thread id
 */
CRPT_EXPORT CRPT_THREAD_ID CRPT_THREAD_id(void);

/**
 * @ingroup crypto_runtime
 *
 * @brief check if thread id |a| equals to |b|
 *
 * @retval same as pthread_equal
 */
CRPT_EXPORT int CRPT_THREAD_compare(CRPT_THREAD_ID a, CRPT_THREAD_ID b);

/**
 * @ingroup crypto_runtime
 *
 * @brief get the thread name
 *
 * @retval the thread name string, or "unamed" if haven't been setted
 */
CRPT_EXPORT const char *CRPT_THREAD_name(void);

/**
 * @ingroup crypto_runtime
 *
 * @brief set the thread name to |name|
 *
 * @param name [IN] string to be set
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_THREAD_set_name(const char *name);


/** mutex */
/**
 * @ingroup crypto_runtime
 *
 * @brief create a mutex
 *
 * @retval NULL if failed
 */
CRPT_EXPORT CRPT_THREAD_MUTEX *CRPT_THREAD_MUTEX_new(void);

/**
 * @ingroup crypto_runtime
 *
 * @brief free the mutex |lock|
 *
 * @param lock [IN] mutex
 */
CRPT_EXPORT void CRPT_THREAD_MUTEX_free(CRPT_THREAD_MUTEX *lock);

/**
 * @ingroup crypto_runtime
 *
 * @brief try to lock the mutex |lock|
 *
 * @param lock [IN] mutex to be locked
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_THREAD_MUTEX_acquire(CRPT_THREAD_MUTEX *lock);

/**
 * @ingroup crypto_runtime
 *
 * @brief try to unlock the mutex |lock|
 *
 * @param lock [IN] mutex to be unnlocked
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_THREAD_MUTEX_release(CRPT_THREAD_MUTEX *lock);


/** thread local */
/**
 * @ingroup crypto_runtime
 *
 * @brief allocate a thread local variable which label by |key|
 *
 * @param key [IN] local key
 * @param destructor [IN] destructor when when thread exit
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_THREAD_LOCAL_create(CRPT_THREAD_LOCAL *key, void (*destructor)(void *arg));

/**
 * @ingroup crypto_runtime
 *
 * @brief free the thread local variable which label by |key|
 *
 * @param key [IN] local key
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_THREAD_LOCAL_delete(CRPT_THREAD_LOCAL *key);

/**
 * @ingroup crypto_runtime
 *
 * @brief set value at |val| to the thread local variable which label by |key|
 *
 * @param key [IN] local key
 * @param val [IN] local variable
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_THREAD_LOCAL_set(CRPT_THREAD_LOCAL *key, void *val);

/**
 * @ingroup crypto_runtime
 *
 * @brief get value of the thread local variable which label by |key|
 *
 * @param key [IN] local key
 *
 * @retval NULL if failed or it has been set to NULL
 */
CRPT_EXPORT void *CRPT_THREAD_LOCAL_get(CRPT_THREAD_LOCAL *key);


/** thread once */
/**
 * @ingroup crypto_runtime
 *
 * @brief run the function |init| just once in current thread
 *
 * @param once [IN] pointer of a thread local variable
 * @param init [IN] init function
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_THREAD_ONCE_run(CRPT_THREAD_ONCE *once, void (*init)(void));


/** atomic */
/**
 * @ingroup crypto_runtime
 *
 * @brief add amount to the thread local variable
 *
 * @param val [IN/OUT] local variable
 * @param amount [IN] amount
 * @param ret [IN/OUT] result
 * @param lock [IN] mutex
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_atomic_add(int *val, int amount, int *ret, CRPT_THREAD_MUTEX *lock);

#if defined(__cplusplus)
}
#endif

#endif
