/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: global rand method
 * Author: zhanxin
 * Create: Web Aug 20 11:54:00 2020
 */

#ifndef CRYPTO_HEADER_RAND_H
#define CRYPTO_HEADER_RAND_H

#include <hicrypto/target.h>

#if defined(__cplusplus)
extern "C" {
#endif

struct crpt_rand_meth_st {
    int (*seed)(const void *buf, size_t num);
    int (*bytes)(unsigned char *buf, size_t num);
    int (*add)(const void *buf, size_t num, double randomness);
    int (*status)(void);
    void (*cleanup)(void);
};
typedef struct crpt_rand_meth_st CRPT_RAND_METH;

/** @defgroup crypto_library */

/**
 * @ingroup crypto_library
 *
 * @brief set random |meth| to generate random for library HiCRYPTO
 *
 * @param meth [IN] contain functions to generate random
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_RAND_set_method(const CRPT_RAND_METH *meth);

/**
 * @ingroup crypto_library
 *
 * @brief get the random method which setted by user
 *
 * @retval random method
 */
CRPT_EXPORT const CRPT_RAND_METH *CRPT_RAND_get_method(void);

/**
 * @ingroup crypto_library
 *
 * @brief generate |num| size random number
 *
 * @param buf [IN/OUT] buffer to store the generated random number
 * @param num [IN] buffer len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_RAND_bytes(unsigned char *buf, size_t num);

/**
 * @ingroup crypto_library
 *
 * @brief generate |num| size random number, same as CRPT_RAND_bytes
 *
 * @param buf [IN/OUT] buffer to store the generated random number
 * @param num [IN] buffer len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_RAND_priv_bytes(unsigned char *buf, size_t num);

/**
 * @ingroup crypto_library
 *
 * @brief get the random generator status
 *
 * @retval CRPT_ESTATUS if method not set,
 * CRPT_SUCCESS if method function status not exist,
 * value return from method function status
 */
CRPT_EXPORT int CRPT_RAND_status(void);

/**
 * @ingroup crypto_library
 *
 * @brief set given |num| bytes seed for the random number generator
 * and uses it for random number generation
 *
 * @param buf [IN/OUT] buffer which store the seed
 * @param num [IN] buffer len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_RAND_seed(const void *buf, size_t num);

/**
 * @ingroup crypto_library
 *
 * @brief mixes given |num| size entropy to the random number generator
 * and uses it for random number generation
 *
 * @param buf [IN/OUT] buffer which store the entropy
 * @param num [IN] buffer len
 * @param randomness [IN] an estimate of how much randomness is contained in buf,
 * in bytes, and should be a number between zero and num
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_RAND_add(const void *buf, size_t num, double randomness);

#if defined(__cplusplus)
}
#endif

#endif
