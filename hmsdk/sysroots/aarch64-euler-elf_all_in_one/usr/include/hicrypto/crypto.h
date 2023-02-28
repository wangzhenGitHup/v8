/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: set of basic headers, library context function declarations
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_CRYPTO_H
#define CRYPTO_HEADER_CRYPTO_H

#include <hicrypto/conf.h>
#include <hicrypto/crpt.h>
#include <hicrypto/error.h>
#include <hicrypto/target.h>
#include <hicrypto/memory.h>
#include <hicrypto/string.h>
#include <hicrypto/thread.h>

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @ingroup crypto_library
 *
 * @brief get default crypto context
 *
 * @retval default crypto context
 */
CRPT_EXPORT CRPTLIB_CTX *HICRYPTO_default(void);

/**
 * @ingroup crypto_library
 *
 * @brief create crypto context
 *
 * @retval crypto context
 */
CRPT_EXPORT CRPTLIB_CTX *HICRYPTO_new(void);

/**
 * @ingroup crypto_library
 *
 * @brief free crypto context
 *
 * @param libctx [IN] crypto context
 */
CRPT_EXPORT void HICRYPTO_free(CRPTLIB_CTX *libctx);

#if defined(__cplusplus)
}
#endif

#endif
