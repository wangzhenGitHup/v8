/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Memory-Pool defination and Fixed-Size Memory-Pool declarations
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_MEMPOOL_H
#define CRYPTO_HEADER_MEMPOOL_H

#include <hicrypto/target.h>

/**
 * Fast efficient fixed-size memory pool
 *
 */
typedef struct {
    unsigned int blocks;
    unsigned int blocksize; // MUST >= 4 bytes
    unsigned int blocks_free;
    unsigned int blocks_initialized;

    unsigned char *base;
    unsigned char *next;
#ifdef CRPT_STATS_MEMPOOL
    struct {
        size_t used;
        size_t peak;
        size_t calls;
    } stats;
#define CRPT_FIXED_MEMPOOL_STATS \
    {                            \
        0, 0, 0                  \
    }
#else
#define CRPT_FIXED_MEMPOOL_STATS
#endif
} CRPT_FIXED_MEMPOOL;
#define CRPT_FIXED_MEMPOOL_INITIALIZER(addr, blksize, size)          \
    {                                                                \
        size, blksize, size, 0, addr, addr, CRPT_FIXED_MEMPOOL_STATS \
    }

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @ingroup crypto_runtime
 *
 * @brief allocate memory pools
 *
 * @param p [IN] fixed memory pool
 *
 * @retval NULL if reallocate failed
 */
CRPT_HIDDEN void *CRPT_FIXED_MEMPOOL_allocate(CRPT_FIXED_MEMPOOL *p);

/**
 * @ingroup crypto_runtime
 *
 * @brief deallocate memory pools
 *
 * @param p [IN] fixed memory pool
 * @param addr [IN] addr to be deallocated
 */
CRPT_HIDDEN void CRPT_FIXED_MEMPOOL_deallocate(CRPT_FIXED_MEMPOOL *p, void *addr);

/*
 * Set of Fast efficient fixed-size memory pool
 * pools MUST BE sorted and end with `p->base == NULL`
 *
 */
/**
 * @ingroup crypto_runtime
 *
 * @brief allocate |size| bytes memory block from |pools|
 *
 * @param pools [IN] memory pool array
 * @param size [IN] bytes size
 *
 * @retval NULL if reallocate failed
 */
CRPT_EXPORT void *CRPT_FIXED_MEMPOOL_malloc(CRPT_FIXED_MEMPOOL pools[], size_t size);

/**
 * @ingroup crypto_runtime
 *
 * @brief attempts to resize the memory block pointed to by |ptr|
 *
 * @param pools [IN] memory pool array
 * @param ptr [IN] memory pointer
 * @param size [IN] bytes size
 *
 * @retval NULL if reallocate failed
 */
CRPT_EXPORT void *CRPT_FIXED_MEMPOOL_realloc(CRPT_FIXED_MEMPOOL pools[], void *ptr, size_t size);

/**
 * @ingroup crypto_runtime
 *
 * @brief deallocate postion |ptr| memory to |pools|
 *
 * @param pools [IN] memory pool array
 * @param ptr [IN] memory pointer
 *
 * @retval NULL if reallocate failed
 */
CRPT_EXPORT void CRPT_FIXED_MEMPOOL_free(CRPT_FIXED_MEMPOOL pools[], void *ptr);

/**
 * @ingroup crypto_runtime
 *
 * @brief print memory pool stats
 *
 * @param pools [IN] memory pool array
 * @param print [IN] print function
 * @param arg [IN] arguments
 */
CRPT_EXPORT void CRPT_FIXED_MEMPOOL_stats(const CRPT_FIXED_MEMPOOL pools[], void (*print)(void *, void *), void *arg);

/**
 * @ingroup crypto_runtime
 *
 * @brief check if |length| size buffer at postion |ptr|
 * is fully belong to current |pools|
 *
 * @param pools [IN] memory pool array
 * @param ptr [IN] pointer
 * @param length [IN] print function
 * @param mode [IN] arguments
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_FIXED_MEMPOOL_access(const CRPT_FIXED_MEMPOOL pools[], const void *ptr, size_t length,
                                          unsigned int mode);

#if (defined CRPT_STATS_MEMPOOL) && !(defined CRPT_NO_STREAM)
/**
 * @ingroup crypto_runtime
 *
 * @brief print memory pool stats
 *
 * @param pools [IN] fixed memory pool
 * @param stream [IN] crypto stream
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT void CRPT_FIXED_MEMPOOL_print_stats(const CRPT_FIXED_MEMPOOL *pools, CRPT_STREAM *stream);
#endif

#if defined(__cplusplus)
}
#endif

#endif
