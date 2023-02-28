/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Memory allocation, freeing, clearing
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_MEMORY_H
#define CRYPTO_HEADER_MEMORY_H

#include <hicrypto/target.h>

#if defined(__cplusplus)
extern "C" {
#endif

/** memory allocator: malloc, free, realloc */
/** @defgroup crypto_runtime */

/**
 * @ingroup crypto_runtime
 *
 * @brief allocate |size| bytes memory block
 *
 * @param size [IN] size to be malloced
 *
 * @retval NULL if failed or required memory size equals 0
 */
CRPT_EXPORT void *CRPT_malloc(size_t size);

/**
 * @ingroup crypto_runtime
 *
 * @brief allocate |size| bytes memory block and sets allocated memory to zero
 *
 * @param size [IN] size to be malloced
 *
 * @retval NULL if failed or required memory size equals 0
 */
CRPT_EXPORT void *CRPT_zalloc(size_t size);

/**
 * @ingroup crypto_runtime
 *
 * @brief attempts to resize the memory block pointed to by |ptr| that was previously allocated
 *
 * @param ptr [IN] the memory block pointer
 * @param size [IN] resize
 *
 * @retval NULL if failed or |size| equals 0
 */
CRPT_EXPORT void *CRPT_realloc(void *ptr, size_t size);

/**
 * @ingroup crypto_runtime
 *
 * @brief frees the memory space pointed to by |ptr|
 *
 * @param ptr [IN] the memory block pointer
 */
CRPT_EXPORT void CRPT_free(void *ptr);

/**
 * @ingroup crypto_runtime
 *
 * @brief set custom memory management functions
 *
 * @param alloc [IN] malloc function
 * @param dealloc [IN] free fuction
 * @param realloc [IN] realloc function
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_set_allocator(void *(*alloc)(size_t size), void (*dealloc)(void *ptr),
                                   void *(*realloc)(void *ptr, size_t size));

/* use to clean sensitive data structure */
/**
 * @ingroup crypto_runtime
 *
 * @brief sets memory pointed to by |ptr| to zero
 *
 * @param addr [IN] memory pointer
 * @param size [IN] memory size
 */
CRPT_EXPORT void CRPT_clean(void *addr, size_t size);

/**
 * @ingroup crypto_runtime
 *
 * @brief sets memory pointed to by |ptr| to zero, and then free
 *
 * @param addr [IN] memory pointer
 * @param size [IN] memory size
 */
CRPT_EXPORT void CRPT_clean_free(void *addr, size_t size);

/**
 * @ingroup crypto_runtime
 *
 * @brief reallocate memory and clean the old memory block
 *
 * @param ptr [IN] memory pointer
 * @param oldsize [IN] old memory size
 * @param size [IN] new memory size
 *
 * @retval NULL if failed or |size| equals 0
 */
CRPT_EXPORT void *CRPT_clean_realloc(void *ptr, size_t oldsize, size_t size);

// XXX: no secure memory operations support currently
#define CRPT_secure_malloc  CRPT_malloc
#define CRPT_secure_zalloc  CRPT_zalloc
#define CRPT_secure_realloc CRPT_realloc
#define CRPT_secure_free    CRPT_free

#if defined(__cplusplus)
}
#endif

#endif
