/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: error encoding, constants and function declarations for SHA
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_SHA_H
#define CRYPTO_HEADER_SHA_H

#include <hicrypto/crpt.h>

#if defined(__cplusplus)
extern "C" {
#endif

/** SHA1 */
#define SHA1_BLOCK_SIZE  64
#define SHA1_DIGEST_SIZE 20

/** SHA2-256 */
#define SHA224_BLOCK_SIZE  64
#define SHA224_DIGEST_SIZE 28

#define SHA256_BLOCK_SIZE  64
#define SHA256_DIGEST_SIZE 32

typedef struct {
    uint32_t h[8];                                        /* 128 bits for SHA256 state */
    uint32_t N[2];                                        /* input bits counter, max 2^64 bits */
    uint32_t block[SHA256_BLOCK_SIZE / sizeof(uint32_t)]; /* block cache */
    unsigned int blocklen;
    unsigned int outlen;        /* digest output length */
    unsigned int computed : 1;  /* Is the digest computed? */
    unsigned int corrupted : 1; /* Is the digest corrupted? */
} SHA224_CTX, SHA256_CTX;

/** @defgroup crypto_sha */

/**
 * @ingroup crypto_sha
 *
 * @brief sha224 start
 *
 * @param ctx [IN] sha224 context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA224_start(SHA224_CTX *ctx);

/**
 * @ingroup crypto_sha
 *
 * @brief sha224 update
 *
 * @param ctx [IN] sha224 context
 * @param data [IN] data to be updated
 * @param len [IN] data len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA224_update(SHA224_CTX *ctx, const unsigned char *data, size_t len);

/**
 * @ingroup crypto_sha
 *
 * @brief sha224 finish
 *
 * @param ctx [IN] sha224 context
 * @param md [OUT] sha224 result
 * @param mdsize [IN] sha224 size
 * @param outlen [OUT] out len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA224_finish(SHA224_CTX *ctx, unsigned char *md, size_t mdsize, size_t *outlen);

/**
 * @ingroup crypto_sha
 *
 * @brief sha256 start
 *
 * @param ctx [IN] sha256 context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA256_start(SHA256_CTX *ctx);

/**
 * @ingroup crypto_sha
 *
 * @brief sha256 update
 *
 * @param ctx [IN] sha256 context
 * @param data [IN] data to be updated
 * @param len [IN] data len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA256_update(SHA256_CTX *ctx, const unsigned char *data, size_t len);

/**
 * @ingroup crypto_sha
 *
 * @brief sha256 finish
 *
 * @param ctx [IN] sha256 context
 * @param md [OUT] sha256 result
 * @param mdsize [IN] sha256 size
 * @param outlen [OUT] out len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA256_finish(SHA256_CTX *ctx, unsigned char *md, size_t mdsize, size_t *outlen);

/** SHA2-512 */
#define SHA384_BLOCK_SIZE  128
#define SHA384_DIGEST_SIZE 48

#define SHA512_BLOCK_SIZE  128
#define SHA512_DIGEST_SIZE 64

typedef struct {
    uint64_t h[SHA512_DIGEST_SIZE / sizeof(uint64_t)];
    uint64_t Nl, Nh;
    uint8_t block[SHA512_BLOCK_SIZE];
    unsigned int num, mdlen;
    unsigned computed : 1;  /* Is the digest computed? */
    unsigned corrupted : 1; /* Is the digest corrupted? */
} SHA384_CTX, SHA512_CTX;

/**
 * @ingroup crypto_sha
 *
 * @brief sha384 start
 *
 * @param ctx [IN] sha384 context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA384_start(SHA384_CTX *ctx);

/**
 * @ingroup crypto_sha
 *
 * @brief sha384 update
 *
 * @param ctx [IN] sha384 context
 * @param data [IN] data to be updated
 * @param len [IN] data len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA384_update(SHA384_CTX *ctx, const unsigned char *data, size_t len);

/**
 * @ingroup crypto_sha
 *
 * @brief sha384 finish
 *
 * @param ctx [IN] sha384 context
 * @param md [OUT] sha384 result
 * @param mdsize [IN] sha384 size
 * @param outlen [OUT] out len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA384_finish(SHA384_CTX *ctx, unsigned char *md, size_t mdsize, size_t *mdlen);

/**
 * @ingroup crypto_sha
 *
 * @brief sha512 start
 *
 * @param ctx [IN] sha512 context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA512_start(SHA512_CTX *ctx);

/**
 * @ingroup crypto_sha
 *
 * @brief sha512 update
 *
 * @param ctx [IN] sha512 context
 * @param data [IN] data to be updated
 * @param len [IN] data len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA512_update(SHA512_CTX *ctx, const unsigned char *data, size_t len);

/**
 * @ingroup crypto_sha
 *
 * @brief sha512 finish
 *
 * @param ctx [IN] sha512 context
 * @param md [OUT] sha512 result
 * @param mdsize [IN] sha512 size
 * @param outlen [OUT] out len
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int SHA512_finish(SHA512_CTX *ctx, unsigned char *md, size_t mdsize, size_t *mdlen);

/**
 * @ingroup crypto_sha
 *
 * @brief get sha1 innstace
 *
 * @retval sha1 innstace
 */
CRPT_EXPORT const CRPT_DIGEST *CRPT_DIGEST_sha1(void);

/**
 * @ingroup crypto_sha
 *
 * @brief get sha224 innstace
 *
 * @retval sha224 innstace
 */
CRPT_EXPORT const CRPT_DIGEST *CRPT_DIGEST_sha224(void);

/**
 * @ingroup crypto_sha
 *
 * @brief get sha256 innstace
 *
 * @retval sha256 innstace
 */
CRPT_EXPORT const CRPT_DIGEST *CRPT_DIGEST_sha256(void);

/**
 * @ingroup crypto_sha
 *
 * @brief get sha384 innstace
 *
 * @retval sha384 innstace
 */
CRPT_EXPORT const CRPT_DIGEST *CRPT_DIGEST_sha384(void);

/**
 * @ingroup crypto_sha
 *
 * @brief get sha512 innstace
 *
 * @retval sha512 innstace
 */
CRPT_EXPORT const CRPT_DIGEST *CRPT_DIGEST_sha512(void);


#define CRPT_LIB_SHA  (CRPT_ERROR_USER + 0)
#define CRPT_ELIB_SHA (CRPT_ELIB_USER - (CRPT_LIB_SHA - CRPT_ERROR_USER) * 256)

/* error encoding for SHA */
#define SHA_ERROR_INVAL        (-22)  // Invalid argument
#define SHA_ERROR_BADSEQ       (-257) // Bad sequence
#define SHA_ERROR_ENOTSUP      (-259) // Not supported
#define SHA_ERROR_STATUS       (-260) // Wrong status
#define SHA_ERROR_EINTERNAL    (-262) // Internal error

#if defined(__cplusplus)
}
#endif

#endif
