/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: error encoding and function declarations for HMAC
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_HMAC_H
#define CRYPTO_HEADER_HMAC_H

#include <hicrypto/crpt.h>

#if defined(__cplusplus)
extern "C" {
#endif

/** @defgroup crypto_hmac */

/**
 * @ingroup crypto_hmac
 *
 * @brief get hmac context
 *
 * @retval return static hmac context
 */
CRPT_EXPORT const CRPT_MAC *CRPT_MAC_hmac(void);

#define CRPT_LIB_HMAC               (CRPT_ERROR_USER + 2)
#define CRPT_ELIB_HMAC              (CRPT_ELIB_USER - (CRPT_LIB_HMAC - CRPT_ERROR_USER) * 256)
#define CRPT_EHMAC_NEWCTX_FAILED    (CRPT_ELIB_HMAC - 1)
#define CRPT_EHMAC_DUPCTX_FAILED    (CRPT_ELIB_HMAC - 2)
#define CRPT_EHMAC_DIGEST_FAILED    (CRPT_ELIB_HMAC - 3)

#if defined(__cplusplus)
}
#endif

#endif
