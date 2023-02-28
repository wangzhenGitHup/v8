/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: error encoding and function declarations of RSA
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_RSA_H
#define CRYPTO_HEADER_RSA_H

#include <hicrypto/crpt.h>
#include <hicrypto/params.h>
#include <hicrypto/bn.h>

#define RSA_DEFAULT_PRIME_NUM 2
#define RSA_MAX_PRIME_NUM     5

#define RSA_MIN_MODULUS_BITS     512
#define RSA_DEFAULT_MODULUS_BITS 2048
#define RSA_MAX_MODULUS_BITS     16384
#define CRPT_RSA_MAX_PUBEXP_BITS 64 /* exponent limit enforced for "large" modulus only */

/* limits in FIPS mode */
#define RSA_FIPS_MIN_MODULUS_BITS 1024

// padding
#define RSA_PKCS1_PADDING      1
#define RSA_SSLV23_PADDING     2
#define RSA_NO_PADDING         3
#define RSA_PKCS1_OAEP_PADDING 4
#define RSA_X931_PADDING       5
#define RSA_PKCS1_PSS_PADDING  6
#define RSA_PKCS1_PADDING_SIZE 11

// pss saltlen
#define RSA_PSS_SALTLEN_DIGEST   -1 /* Salt length matches digest */
#define RSA_PSS_SALTLEN_AUTO     -2 /* Verify only: auto detect salt length */
#define RSA_PSS_SALTLEN_MAX      -3 /* Set salt length to maximum possible */
#define RSA_PSS_SALTLEN_MAX_SIGN -2 /* Old compatible max salt length for sign only */

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct rsakey_st RSA_KEY;

/** @defgroup crypto_rsa */

/**
 * @ingroup crypto_rsa
 *
 * @brief get rsa keygen context
 *
 * @retval return static rsa keygen context
 */
CRPT_EXPORT const CRPT_KEYMGMT *CRPT_KEYMGMT_rsa(void);

#if !(defined RSA_NO_SIGNATURE_SIGN) || !(defined RSA_NO_SIGNATURE_VERIFY)
/**
 * @ingroup crypto_rsa
 *
 * @brief get rsa signature context
 *
 * @retval return static rsa signature context
 */
CRPT_EXPORT const CRPT_SIGNATURE *CRPT_SIGNATURE_rsa(void);
#endif

#if !(defined RSA_NO_ASYM_CIPHER_ENCRYPT) || !(defined RSA_NO_ASYM_CIPHER_DECRYPT)
/**
 * @ingroup crypto_rsa
 *
 * @brief get rsa aysm cipher context
 *
 * @retval return static rsa aysm cipher context
 */
CRPT_EXPORT const CRPT_ASYM_CIPHER *CRPT_ASYM_CIPHER_rsa(void);
#endif

#define RSA_PARAM_MODULUS          "n" /* n, hex-string or mpi-data */
#define RSA_PARAM_PUB_EXP          "e" /* e, hex-string or mpi-data */
#define RSA_PARAM_PRV_EXP          "d" /* d, hex-string or mpi-data */
#define RSA_PARAM_PRV_FAC_P        "p"
#define RSA_PARAM_PRV_FAC_Q        "q"
#define RSA_PARAM_KEY_BITS         "key-bits"
#define RSA_PARAM_KEY_BYTES        "key-bytes"
#define RSA_PARAM_MULTI_PRIMES_NUM "primes"

/*
 * RSA reason codes.
 */
#define CRPT_LIB_RSA                                   (CRPT_ERROR_USER + 1)
#define CRPT_ELIB_RSA                                  (CRPT_ELIB_USER - (CRPT_LIB_RSA - CRPT_ERROR_USER) * 256)
#define CRPT_ERSA_RSA_FAILED                           (CRPT_ELIB_RSA - 1)
#define CRPT_ERSA_BN_FAILED                            (CRPT_ELIB_RSA - 2)
#define CRPT_ERSA_DIGEST_FAILED                        (CRPT_ELIB_RSA - 3)
#define CRPT_ERSA_RAND_FAILED                          (CRPT_ELIB_RSA - 4)
#define CRPT_ERSA_E_WRONG_VALUE                        (CRPT_ELIB_RSA - 5)
#define CRPT_ERSA_WRONG_SIGN                           (CRPT_ELIB_RSA - 6)
#define CRPT_ERSA_DATA_TOO_LONG                        (CRPT_ELIB_RSA - 7)
#define CRPT_ERSA_BUF_TOO_SMALL                        (CRPT_ELIB_RSA - 8)
#define CRPT_ERSA_WRONG_MSG_LEN                        (CRPT_ELIB_RSA - 9)
#define CRPT_ERSA_WRONG_KEY                            (CRPT_ELIB_RSA - 10)
#define CRPT_ERSA_WRONG_KEY_LEN                        (CRPT_ELIB_RSA - 11)
#define CRPT_ERSA_VERIFY_PADDING_FAILED                (CRPT_ELIB_RSA - 12)
#define CRPT_ERSA_WRONG_PSS_SALT_LEN                   (CRPT_ELIB_RSA - 13)
#define CRPT_ERSA_WRONG_KEY_PRIME_NUM                  (CRPT_ELIB_RSA - 14)
#define CRPT_ERSA_KEY_BITS_TOO_SMALL                   (CRPT_ELIB_RSA - 15)
#define CRPT_ERSA_DECODE_OAEP_FAILED                   (CRPT_ELIB_RSA - 16)
#define CRPT_ERSA_WRONG_PADDING_MODE                   (CRPT_ELIB_RSA - 17)

#if defined(__cplusplus)
}
#endif

#endif
