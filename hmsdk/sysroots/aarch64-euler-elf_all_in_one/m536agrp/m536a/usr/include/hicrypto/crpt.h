/*
* Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
* Description: types, macros and function declarations of CRPT_xxx abstraction
* Author: zhanxin
* Create: Tue Jul 07 09:20:24 2020
*
* Notes:
*   1. xxx, xxxsize, *xxxlen:
*      |xxxsize| is the max writtable length to |xxx|
*      *|xxxlen| can be NULL if don't care about the actual bytes has been written to |xxx|
*/

#ifndef CRYPTO_HEADER_CRPT_H
#define CRYPTO_HEADER_CRPT_H

#include <hicrypto/nid.h>
#include <hicrypto/params.h>
#include <hicrypto/refcount.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct crypto_ctx_st CRPTLIB_CTX;

/** @defgroup crypto_general */
/**
 * @ingroup crypto_general
 *
 * @brief create general context
 *
 * @param provctx [IN] NOT-USED now
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef void *(*CRPT_GENERIC_CTX_new_f)(void *provctx);

/**
 * @ingroup crypto_general
 *
 * @brief duplicate general context
 *
 * @param vctx [IN] implementation context
 *
 * @retval implementation context
 */
typedef void *(*CRPT_GENERIC_CTX_dup_f)(void *vctx);

/**
 * @ingroup crypto_general
 *
 * @brief destory general context
 *
 * @param vctx [IN] implementation context
 */
typedef void (*CRPT_GENERIC_CTX_free_f)(void *vctx);

/**
 * @ingroup crypto_general
 *
 * @brief get parameters of implementation
 *
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_GENERIC_get_params_f)(CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_general
 *
 * @brief gettable parameters of implementation
 *
 * @retval gettable parameters
 */
typedef const CRPT_PARAM *(*CRPT_GENERIC_gettable_params_f)(void);

/**
 * @ingroup crypto_general
 *
 * @brief get context's parameters
 *
 * @param vctx [IN] implementation context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_GENERIC_get_ctx_params_f)(void *vctx, CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_general
 *
 * @brief context's gettable parameters of implementation
 *
 * @retval context's gettable parameters
 */
typedef const CRPT_PARAM *(*CRPT_GENERIC_gettable_ctx_params_f)(void);

/**
 * @ingroup crypto_general
 *
 * @brief set context's parameters
 *
 * @param vctx [IN] implementation context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_GENERIC_set_ctx_params_f)(void *vctx, const CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_general
 *
 * @brief context's settable parameters of implementation
 *
 * @retval context's settable parameters
 */
typedef const CRPT_PARAM *(*CRPT_GENERIC_settable_ctx_params_f)(void);

/**
 * @ingroup crypto_general
 *
 * @brief check if buffer overlapped
 *
 * @param ptr1 [IN] pointer 1
 * @param ptr2 [IN] pointer 2
 * @param len [IN] check length
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_INLINE int crpt_is_overlapping(const void *ptr1, const void *ptr2, int len)
{
    crpt_ptrdiff_t diff = (crpt_ptrdiff_t)ptr1 - (crpt_ptrdiff_t)ptr2;
    return (len > 0) & ((diff < (crpt_ptrdiff_t)len) | (diff > (0 - (crpt_ptrdiff_t)len)));
}


/**
 * Digest
 *
 * A mathematical algorithm that maps data of arbitrary size (often called the
 * "message") to a bit array of a fixed size (the "hash value", "hash", or
 * "message digest") and is a one-way function, that is, a function which is
 * practically infeasible to invert.
 *
 */

/** @defgroup crypto_digest */

/**
 * @ingroup crypto_digest
 *
 * @brief initialize digest context
 * @param vctx [IN/OUT] implementation context
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_DIGEST_start_f)(void *vctx);

/**
 * @ingroup crypto_digest
 *
 * @brief compress data to update implementation context
 *
 * @param vctx [IN/OUT] implementation context
 * @param in [IN] pointer to input data
 * @param inlen [IN] length of input data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_DIGEST_update_f)(void *vctx, const unsigned char *in, size_t inlen);

/**
 * @ingroup crypto_digest
 *
 * @brief last computation of digest
 *
 * @param vctx [IN/OUT] implementation context
 * @param out [OUT] pointer to output buffer
 * @param outsize [IN] max size of output buffer
 * @param outlen [OUT] length of output digest
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_DIGEST_finish_f)(void *vctx, unsigned char *out, size_t outsize, size_t *outlen);

struct crpt_digest_st {
    int nid;

    CRPT_REFCNT refcnt;
    CRPT_THREAD_MUTEX *lock;

    CRPT_GENERIC_CTX_new_f newctx;
    CRPT_GENERIC_CTX_dup_f dupctx;
    CRPT_GENERIC_CTX_free_f freectx;

    CRPT_GENERIC_get_params_f get_params;
    CRPT_GENERIC_set_ctx_params_f set_ctx_params;
    CRPT_GENERIC_get_ctx_params_f get_ctx_params;
    CRPT_GENERIC_gettable_params_f gettable_params;
    CRPT_GENERIC_settable_ctx_params_f settable_ctx_params;
    CRPT_GENERIC_gettable_ctx_params_f gettable_ctx_params;

    CRPT_DIGEST_start_f start;
    CRPT_DIGEST_update_f update;
    CRPT_DIGEST_finish_f finish;
};
typedef struct crpt_digest_st CRPT_DIGEST;
typedef struct crpt_digest_ctx_st CRPT_DIGEST_CTX;

/* digest limits */
#define CRPT_DIGEST_MAX_SIZE        64  /* longest known is SHA512 */
#define CRPT_DIGEST_MAX_CBLOCK_SIZE 144 /* largest known is SHA3-224 */

/* digest parameters */
#define CRPT_DIGEST_PARAM_BLOCK_SIZE "block-size" /* size_t */
#define CRPT_DIGEST_PARAM_SIZE       "size"       /* size_t */

/**
 * @ingroup crypto_digest
 *
 * @brief fetch digest algorithm implement
 *
 * @param lib [IN/OUT] library context created via |HICRYPTO_new| or returned from |HICRYPTO_default|
 * @param algorithm [IN] algorithm name defined as SN_xxx, such as SN_sha256
 * @param properties [IN] implement properties, such as "fips=true, multi-buffer=true"
 *
 * @retval fetched implementation
 */
CRPT_EXPORT CRPT_DIGEST *CRPT_DIGEST_fetch(CRPTLIB_CTX *libctx, const char *algorithm, const char *properties);

/**
 * @ingroup crypto_digest
 *
 * @brief increase reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_up_ref(CRPT_DIGEST *op);

/**
 * @ingroup crypto_digest
 *
 * @brief decrease reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_down_ref(CRPT_DIGEST *op);

/**
 * @ingroup crypto_digest
 *
 * @brief destory implementation
 *
 * @param op [IN/OUT] implementation
 *
 */
CRPT_EXPORT void CRPT_DIGEST_free(CRPT_DIGEST *op);

/**
 * @ingroup crypto_digest
 *
 * @brief get name id of implementaion
 *
 * @param op [IN/OUT] implementation
 *
 * @retval name id of implementaion
 */
CRPT_EXPORT int CRPT_DIGEST_nid(const CRPT_DIGEST *op);

/**
 * @ingroup crypto_digest
 *
 * @brief create digest context
 *
 * @param op [IN/OUT] implementation
 * @param provctx [IN] NOT-USED now
 *
 * @retval pointer to digest context
 */
CRPT_EXPORT CRPT_DIGEST_CTX *CRPT_DIGEST_CTX_new(CRPT_DIGEST *op, void *provctx);

/**
 * @ingroup crypto_digest
 *
 * @brief duplicate digest context
 *
 * @param ctx [IN/OUT] digest context
 *
 * @retval pointer to digest context
 */
CRPT_EXPORT CRPT_DIGEST_CTX *CRPT_DIGEST_CTX_dup(CRPT_DIGEST_CTX *ctx);

/**
 * @ingroup crypto_digest
 *
 * @brief destory digest context
 *
 * @param ctx [IN/OUT] digest context
 *
 */
CRPT_EXPORT void CRPT_DIGEST_CTX_free(CRPT_DIGEST_CTX *ctx);

/**
 * @ingroup crypto_digest
 *
 * @brief copy digest context
 *
 * @param out [OUT] digest context
 * @param in [IN] digest context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_CTX_copy(CRPT_DIGEST_CTX *out, const CRPT_DIGEST_CTX *in);

/**
 * @ingroup crypto_digest
 *
 * @brief initialize digest context
 *
 * @param ctx [IN/OUT] digest context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_start(CRPT_DIGEST_CTX *ctx);

/**
 * @ingroup crypto_digest
 *
 * @brief compress data to update digest context
 *
 * @param ctx [IN/OUT] digest context
 * @param in [IN] pointer to input data
 * @param inlen [IN] length of input data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_update(CRPT_DIGEST_CTX *ctx, const unsigned char *in, size_t inlen);

/**
 * @ingroup crypto_digest
 *
 * @brief last computation of digest
 *
 * @param ctx [IN/OUT] digest context
 * @param out [OUT] pointer to output buffer
 * @param outsize [IN] max size of output buffer
 * @param outlen [OUT] length of output digest
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_finish(CRPT_DIGEST_CTX *ctx, unsigned char *out, size_t outsize, size_t *outlen);

/**
 * @ingroup crypto_digest
 *
 * @brief digest computation
 *
 * @param op [IN/OUT] digest implementation
 * @param provctx [IN] NOT-USED now
 * @param in [IN] pointer to input data
 * @param inlen [IN] length of input data
 * @param out [OUT] pointer to output buffer
 * @param outsize [IN] max size of output buffer
 * @param outlen [OUT] length of output digest
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_digest(CRPT_DIGEST *op, void *provctx, const unsigned char *in, size_t inlen,
                                   unsigned char *out, size_t outsize, size_t *outlen);

/**
 * @ingroup crypto_digest
 *
 * @brief get parameters of digest implementation
 *
 * @param op [IN] digest implementation
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_get_params(const CRPT_DIGEST *op, CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_digest
 *
 * @brief gettable parameters of digest implementation
 *
 * @param op [IN] digest implementation
 *
 * @retval gettable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_DIGEST_gettable_params(const CRPT_DIGEST *op);

/**
 * @ingroup crypto_digest
 *
 * @brief get context's parameters
 *
 * @param ctx [IN] digest context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_get_ctx_params(CRPT_DIGEST_CTX *ctx, CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_digest
 *
 * @brief context's gettable parameters of digest implementation
 *
 * @param op [IN] digest implementation
 *
 * @retval context's gettable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_DIGEST_gettable_ctx_params(const CRPT_DIGEST *op);

/**
 * @ingroup crypto_digest
 *
 * @brief set context's parameters
 *
 * @param ctx [IN] digest context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_DIGEST_set_ctx_params(CRPT_DIGEST_CTX *ctx, const CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_digest
 *
 * @brief context's settable parameters of digest implementation
 *
 * @param op [IN] digest implementation
 *
 * @retval context's settable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_DIGEST_settable_ctx_params(const CRPT_DIGEST *op);

/**
 * @ingroup crypto_digest
 *
 * @brief get digest size
 *
 * @param op [IN] digest implementation
 *
 * @retval digest size
 */
CRPT_EXPORT size_t CRPT_DIGEST_size(CRPT_DIGEST *op);

/**
 * @ingroup crypto_digest
 *
 * @brief get block size
 *
 * @param op [IN] digest implementation
 *
 * @retval block size
 */
CRPT_EXPORT size_t CRPT_DIGEST_block_size(CRPT_DIGEST *op);


/**
 * MAC
 *
 * A message authentication code (MAC), sometimes known as a tag, is a short
 * piece of information used to authenticate a message—in other words, to
 * confirm that the message came from the stated sender (its authenticity) and
 * has not been changed. The MAC value protects both a message's data integrity
 * as well as its authenticity, by allowing verifiers (who also possess the
 * secret key) to detect any changes to the message content.
 *
 */

/** @defgroup crypto_mac */

/**
 * @ingroup crypto_mac
 *
 * @brief initialize mac context
 * @param vctx [IN/OUT] implementation context
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_MAC_start_f)(void *vctx);

/**
 * @ingroup crypto_mac
 *
 * @brief compress data to update implementation context
 *
 * @param vctx [IN/OUT] implementation context
 * @param in [IN] pointer to input data
 * @param inlen [IN] length of input data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_MAC_update_f)(void *vctx, const unsigned char *in, size_t inlen);

/**
 * @ingroup crypto_mac
 *
 * @brief last computation of mac
 *
 * @param vctx [IN/OUT] implementation context
 * @param out [OUT] pointer to output buffer
 * @param outsize [IN] max size of output buffer
 * @param outlen [OUT] length of output mac
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_MAC_finish_f)(void *vctx, unsigned char *out, size_t outsize, size_t *outlen);

struct crpt_mac_st {
    int nid;

    CRPT_REFCNT refcnt;
    CRPT_THREAD_MUTEX *lock;

    CRPT_GENERIC_CTX_new_f newctx;
    CRPT_GENERIC_CTX_dup_f dupctx;
    CRPT_GENERIC_CTX_free_f freectx;

    CRPT_GENERIC_get_params_f get_params;
    CRPT_GENERIC_get_ctx_params_f get_ctx_params;
    CRPT_GENERIC_set_ctx_params_f set_ctx_params;
    CRPT_GENERIC_gettable_params_f gettable_params;
    CRPT_GENERIC_gettable_ctx_params_f gettable_ctx_params;
    CRPT_GENERIC_settable_ctx_params_f settable_ctx_params;

    CRPT_MAC_start_f start;
    CRPT_MAC_update_f update;
    CRPT_MAC_finish_f finish;
};
typedef struct crpt_mac_st CRPT_MAC;
typedef struct crpt_mac_ctx_st CRPT_MAC_CTX;

/* MAC parameters */
#define CRPT_MAC_PARAM_SIZE         "size"              /* size_t */
#define CRPT_MAC_PARAM_KEY          "key"               /* octet string */
#define CRPT_MAC_PARAM_SALT         "salt"              /* octet string */
#define CRPT_MAC_PARAM_DIGEST       "digest"            /* utf8 string */
#define CRPT_MAC_PARAM_DIGEST_PROPS "digest-properties" /* utf8 string */

/**
 * @ingroup crypto_mac
 *
 * @brief fetch mac algorithm implement
 *
 * @param lib [IN/OUT] library context created via |HICRYPTO_new| or returned from |HICRYPTO_default|
 * @param algorithm [IN] algorithm name defined as SN_xxx, such as SN_hmac
 * @param properties [IN] implement properties, such as "fips=true, multi-buffer=true"
 *
 * @retval fetched implementation
 */
CRPT_EXPORT CRPT_MAC *CRPT_MAC_fetch(CRPTLIB_CTX *libctx, const char *algorithm, const char *properties);

/**
 * @ingroup crypto_mac
 *
 * @brief increase reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_MAC_up_ref(CRPT_MAC *op);

/**
 * @ingroup crypto_mac
 *
 * @brief decrease reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_MAC_down_ref(CRPT_MAC *op);

/**
 * @ingroup crypto_mac
 *
 * @brief destory implementation
 *
 * @param op [IN/OUT] implementation
 *
 */
CRPT_EXPORT void CRPT_MAC_free(CRPT_MAC *op);

/**
 * @ingroup crypto_mac
 *
 * @brief get name id of implementaion
 *
 * @param op [IN/OUT] implementation
 *
 * @retval name id of implementaion
 */
CRPT_EXPORT int CRPT_MAC_nid(const CRPT_MAC *op);

/**
 * @ingroup crypto_mac
 *
 * @brief create mac context
 *
 * @param op [IN/OUT] implementation
 * @param provctx [IN] NOT-USED now
 *
 * @retval pointer to mac context
 */
CRPT_EXPORT CRPT_MAC_CTX *CRPT_MAC_CTX_new(CRPT_MAC *op, void *provctx);

/**
 * @ingroup crypto_mac
 *
 * @brief duplicate mac context
 *
 * @param ctx [IN/OUT] mac context
 *
 * @retval pointer to mac context
 */
CRPT_EXPORT CRPT_MAC_CTX *CRPT_MAC_CTX_dup(CRPT_MAC_CTX *ctx);

/**
 * @ingroup crypto_mac
 *
 * @brief copy mac context
 *
 * @param out [OUT] mac context
 * @param in [IN] mac context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_MAC_CTX_copy(CRPT_MAC_CTX *out, const CRPT_MAC_CTX *in);

/**
 * @ingroup crypto_mac
 *
 * @brief destory mac context
 *
 * @param ctx [IN/OUT] mac context
 *
 */
CRPT_EXPORT void CRPT_MAC_CTX_free(CRPT_MAC_CTX *ctx);

/**
 * @ingroup crypto_mac
 *
 * @brief initialize mac context
 *
 * @param ctx [IN/OUT] mac context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_MAC_start(CRPT_MAC_CTX *ctx);

/**
 * @ingroup crypto_mac
 *
 * @brief compress data to update mac context
 *
 * @param ctx [IN/OUT] mac context
 * @param in [IN] pointer to input data
 * @param inlen [IN] length of input data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_MAC_update(CRPT_MAC_CTX *ctx, const unsigned char *in, size_t inlen);

/**
 * @ingroup crypto_mac
 *
 * @brief last computation of mac
 *
 * @param ctx [IN/OUT] mac context
 * @param out [OUT] pointer to output buffer
 * @param outsize [IN] max size of output buffer
 * @param outlen [OUT] length of output mac
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_MAC_finish(CRPT_MAC_CTX *ctx, unsigned char *out, size_t outsize, size_t *outlen);

/**
 * @ingroup crypto_mac
 *
 * @brief get parameters of mac implementation
 *
 * @param op [IN] mac implementation
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_MAC_get_params(const CRPT_MAC *op, CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_mac
 *
 * @brief gettable parameters of mac implementation
 *
 * @param op [IN] mac implementation
 *
 * @retval gettable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_MAC_gettable_params(const CRPT_MAC *op);

/**
 * @ingroup crypto_mac
 *
 * @brief get context's parameters
 *
 * @param ctx [IN] mac context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_MAC_get_ctx_params(CRPT_MAC_CTX *ctx, CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_mac
 *
 * @brief context's gettable parameters of mac implementation
 *
 * @param op [IN] mac implementation
 *
 * @retval context's gettable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_MAC_gettable_ctx_params(const CRPT_MAC *op);

/**
 * @ingroup crypto_mac
 *
 * @brief set context's parameters
 *
 * @param ctx [IN] mac context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_MAC_set_ctx_params(CRPT_MAC_CTX *ctx, const CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_mac
 *
 * @brief context's settable parameters of mac implementation
 *
 * @param op [IN] mac implementation
 *
 * @retval context's settable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_MAC_settable_ctx_params(const CRPT_MAC *op);

/**
 * @ingroup crypto_mac
 *
 * @brief get mac size
 *
 * @param op [IN] mac implementation
 *
 * @retval mac size
 */
CRPT_EXPORT size_t CRPT_MAC_size(const CRPT_MAC_CTX *ctx);

/**
 * @ingroup crypto_mac
 *
 * @brief set mac key
 *
 * @param ctx [IN/OUT] mac context
 * @param key [IN] user key
 * @param keylen [IN] length of user key
 *
 * @retval error code, @see <hicrypto/error.h>
 */
CRPT_EXPORT int CRPT_MAC_set_key(CRPT_MAC_CTX *ctx, unsigned char *key, size_t keylen);

/**
 * @ingroup crypto_mac
 *
 * @brief set mac salt
 *
 * @param ctx [IN/OUT] mac context
 * @param salt [IN] salt
 * @param saltlen [IN] length of salt
 *
 * @retval error code, @see <hicrypto/error.h>
 */
CRPT_EXPORT int CRPT_MAC_set_salt(CRPT_MAC_CTX *ctx, unsigned char *salt, size_t saltlen);

/**
 * @ingroup crypto_mac
 *
 * @brief set mac digest
 *
 * @param ctx [IN/OUT] mac context
 * @param digest [IN] digest
 * @param props [IN] properties of digest
 *
 * @retval error code, @see <hicrypto/error.h>
 */
CRPT_EXPORT int CRPT_MAC_set_digest(CRPT_MAC_CTX *ctx, const char *digest, const char *props);


/**
 * Key management
 *
 * Key management refers to management of cryptographic keys in a cryptosystem.
 * This includes dealing with the generation, exchange, storage, use,
 * crypto-shredding (destruction) and replacement of keys. It includes
 * cryptographic protocol design, key servers, user procedures, and other
 * relevant protocols.
 *
 */

 /** @defgroup crypto_keymgmt */

/* Basic key object creation/destruction */
/**
 * @ingroup crypto_keymgmt
 *
 * @brief create key
 *
 * @param provctx [IN] NOT-USED now
 *
 * @retval pointer to keydata
 */
typedef void *(*CRPT_KEYMGMT_newkey_f)(void *provctx);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief destory key
 *
 * @param keydata [IN/OUT] key data
 *
 */
typedef void (*CRPT_KEYMGMT_freekey_f)(void *keydata);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief copy key
 *
 * @param keydata_to [IN/OUT] key data
 * @param keydata_from [IN/OUT] key data
 * @param selection [IN] copy selection
 *
 */
typedef int (*CRPT_KEYMGMT_copy_f)(void *keydata_to, const void *keydata_from, unsigned int selection);

/* Generation, a more complex constructor */
/**
 * @ingroup crypto_keymgmt
 *
 * @brief create context for key generation
 *
 * @param provctx [IN] NOT-USED now
 * @param selection [IN] generation selection
 *
 */
typedef void *(*CRPT_KEYMGMT_gen_newctx_f)(void *provctx, unsigned int selection);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief destory context of key generation
 *
 * @param genctx [IN/OUT] context of key generation
 *
 */
typedef void (*CRPT_KEYMGMT_gen_freectx_f)(void *genctx);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief generate key
 *
 * @param genctx [IN/OUT] context of key generation
 * @param cb [IN] will be deprecated, NOT-USED now
 * @param cbarg [IN] will be deprecated, NOT-USED now
 *
 * @retval generated key data
 */
typedef void *(*CRPT_KEYMGMT_gen_f)(void *genctx, CRPT_CALLBACK *cb, void *cbarg);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief get parameters
 *
 * @param params [IN/OUT] parameters to query
 *
 * @retval error code
 */
typedef int (*CRPT_KEYMGMT_get_params_f)(CRPT_PARAM params[]);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief gettable parameters of keymgmt implementation
 *
 * @retval gettable parameters
 */
typedef const CRPT_PARAM *(*CRPT_KEYMGMT_gettable_params_f)(void);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief get context's parameters
 *
 * @param vctx [IN] implementation context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_KEYMGMT_get_ctx_params_f)(void *genctx, CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief context's gettable parameters of keymgmt implementation
 *
 * @param genctx [IN] generation context
 *
 * @retval context's gettable parameters
 */
typedef const CRPT_PARAM *(*CRPT_KEYMGMT_gettable_ctx_params_f)(void *genctx);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief set context's parameters
 *
 * @param vctx [IN] implementation context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_KEYMGMT_set_ctx_params_f)(void *genctx, const CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief context's settable parameters of keymgmt implementation
 *
 * @param genctx [IN] generation context
 *
 * @retval context's settable parameters
 */
typedef const CRPT_PARAM *(*CRPT_KEYMGMT_settable_ctx_params_f)(void *genctx);

/* Key checks - key data content checks, validation, matching */
/**
 * @ingroup crypto_keymgmt
 *
 * @brief key checks
 *
 * @param keydata [IN] key data
 * @param selection [IN] selection
 *
 * @retval error code
 */
typedef int (*CRPT_KEYMGMT_has_f)(void *keydata, unsigned int selection);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief key validation
 *
 * @param keydata [IN] key data
 * @param selection [IN] selection
 *
 * @retval error code
 */
typedef int (*CRPT_KEYMGMT_validate_f)(void *keydata, unsigned int selection);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief selective matching of two keys
 *
 * @param keydata1 [IN] key data 1
 * @param keydata2 [IN] key data 2
 * @param selection [IN] selection
 *
 * @retval error code
 */
typedef int (*CRPT_KEYMGMT_match_f)(const void *keydata1, const void *keydata2, unsigned int selection);

/* Import and export functions, with discovery */
/**
 * @ingroup crypto_keymgmt
 *
 * @brief selective import
 *
 * @param keydata [IN/OUT] key data
 * @param selection [IN] selection
 * @param params [IN] data to import
 * @param plen [IN] length of parameters
 *
 * @retval error code
 */
typedef int (*CRPT_KEYMGMT_import_f)(void *keydata, unsigned int selection, const CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief selective export
 *
 * @param keydata [IN/OUT] key data
 * @param selection [IN] selection
 * @param param_cb [IN] callback
 * @param cbarg [IN] callback argument
 *
 * @retval error code
 */
typedef int (*CRPT_KEYMGMT_export_f)(void *keydata, unsigned int selection, CRPT_CALLBACK *param_cb, void *cbarg);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief import types
 *
 * @param selection [IN] selection
 *
 * @retval import types
 */
typedef const CRPT_PARAM *(*CRPT_KEYMGMT_import_types_f)(unsigned int selection);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief export types
 *
 * @param selection [IN] selection
 *
 * @retval export types
 */
typedef const CRPT_PARAM *(*CRPT_KEYMGMT_export_types_f)(unsigned int selection);

struct crpt_keymgmt_st {
    int nid;

    CRPT_REFCNT refcnt;
    CRPT_THREAD_MUTEX *lock;

    /* Constructor(s), destructor, information */
    CRPT_KEYMGMT_newkey_f newkey;
    CRPT_KEYMGMT_freekey_f freekey;

    /* Key object information */
    CRPT_GENERIC_get_ctx_params_f get_key_params;
    CRPT_GENERIC_set_ctx_params_f set_key_params;
    CRPT_GENERIC_gettable_ctx_params_f gettable_key_params;
    CRPT_GENERIC_settable_ctx_params_f settable_key_params;

    /* Generation, a complex constructor */
    CRPT_KEYMGMT_gen_newctx_f gen_newctx;
    CRPT_KEYMGMT_gen_freectx_f gen_freectx;
    CRPT_KEYMGMT_set_ctx_params_f gen_set_params;
    CRPT_KEYMGMT_gettable_ctx_params_f gen_settable_params;
    CRPT_KEYMGMT_gen_f gen;

    /* Key object checking */
    CRPT_KEYMGMT_has_f has;
    CRPT_KEYMGMT_match_f match;
    CRPT_KEYMGMT_validate_f validate;

    /* Import and export routines */
    CRPT_KEYMGMT_copy_f copy;
    CRPT_KEYMGMT_import_f import_key;
    CRPT_KEYMGMT_export_f export_key;
    CRPT_KEYMGMT_import_types_f import_types;
    CRPT_KEYMGMT_export_types_f export_types;
};
typedef struct crpt_keymgmt_st CRPT_KEYMGMT;

/* Key data subset selection - individual bits */
#define CRPT_KEYMGMT_SELECT_PRIVATE_KEY       0x01
#define CRPT_KEYMGMT_SELECT_PUBLIC_KEY        0x02
#define CRPT_KEYMGMT_SELECT_DOMAIN_PARAMETERS 0x04
#define CRPT_KEYMGMT_SELECT_OTHER_PARAMETERS  0x80

/* Key data subset selection - combinations */
#define CRPT_KEYMGMT_SELECT_ALL_PARAMS (CRPT_KEYMGMT_SELECT_DOMAIN_PARAMETERS | CRPT_KEYMGMT_SELECT_OTHER_PARAMETERS)
#define CRPT_KEYMGMT_SELECT_KEYPAIR    (CRPT_KEYMGMT_SELECT_PRIVATE_KEY | CRPT_KEYMGMT_SELECT_PUBLIC_KEY)
#define CRPT_KEYMGMT_SELECT_ALL        (CRPT_KEYMGMT_SELECT_KEYPAIR | CRPT_KEYMGMT_SELECT_ALL_PARAMS)

/**
 * @ingroup crypto_keymgmt
 *
 * @brief fetch keymgmt algorithm implement
 *
 * @param lib [IN/OUT] library context created via |HICRYPTO_new| or returned from |HICRYPTO_default|
 * @param algorithm [IN] algorithm name defined as SN_xxx, such as SN_rsa
 * @param properties [IN] implement properties, such as "fips=true, multi-buffer=true"
 *
 * @retval fetched implementation
 */
CRPT_EXPORT CRPT_KEYMGMT *CRPT_KEYMGMT_fetch(CRPTLIB_CTX *libctx, const char *algorithm, const char *properties);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief increase reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_KEYMGMT_up_ref(CRPT_KEYMGMT *op);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief decrease reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_KEYMGMT_down_ref(CRPT_KEYMGMT *op);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief destory implementation
 *
 * @param op [IN/OUT] implementation
 *
 */
CRPT_EXPORT void CRPT_KEYMGMT_free(CRPT_KEYMGMT *op);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief get name id of implementaion
 *
 * @param op [IN/OUT] implementation
 *
 * @retval name id of implementaion
 */
CRPT_EXPORT int CRPT_KEYMGMT_nid(const CRPT_KEYMGMT *op);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief create keydata
 *
 * @param op [IN/OUT] implementation
 * @param provctx [IN] NOT-USED now
 *
 * @retval pointer to keydata
 */
CRPT_EXPORT void *CRPT_KEYMGMT_newkey(const CRPT_KEYMGMT *op, void *provctx);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief destory keydata
 *
 * @param op [IN] keymgmt implementation
 * @param keydata [IN/OUT] keydata
 *
 */
CRPT_EXPORT void CRPT_KEYMGMT_freekey(const CRPT_KEYMGMT *op, void *keydata);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief create key generation context
 *
 * @param op [IN] keymgmt implementation
 * @param selection [IN/OUT] selection
 * @param provctx [IN] NOT-USED now
 *
 * @retval key generation context
 */
CRPT_EXPORT void *CRPT_KEYMGMT_gen_newctx(const CRPT_KEYMGMT *op, unsigned int selection, void *provctx);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief destory key generation context
 *
 * @param op [IN] keymgmt implementation
 * @param genctx [IN/OUT] generation context
 *
 */
CRPT_EXPORT void CRPT_KEYMGMT_gen_freectx(const CRPT_KEYMGMT *op, void *genctx);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief generate key
 *
 * @param op [IN] keymgmt implementation
 * @param genctx [IN/OUT] context of key generation
 * @param cb [IN] will be deprecated, NOT-USED now
 * @param cbarg [IN] will be deprecated, NOT-USED now
 *
 * @retval generated key data
 */
CRPT_EXPORT void *CRPT_KEYMGMT_gen(const CRPT_KEYMGMT *op, void *genctx, CRPT_CALLBACK *cb, void *cbarg);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief set context's parameters
 *
 * @param op [IN] keymgmt implementation
 * @param genctx [IN] key generation context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_KEYMGMT_gen_set_params(const CRPT_KEYMGMT *op, void *genctx, const CRPT_PARAM params[],
                                            size_t plen);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief context's settable parameters of keymgmt implementation
 *
 * @param op [IN] keymgmt implementation
 * @param provctx [IN] will be deprecated, NOT-USED now
 *
 * @retval context's settable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_KEYMGMT_gen_settable_params(const CRPT_KEYMGMT *op, void *provctx);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief get key's parameters
 *
 * @param op [IN] keymgmt implementation
 * @param keydata [IN] key data
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_KEYMGMT_get_key_params(const CRPT_KEYMGMT *op, void *keydata, CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief context's gettable parameters of key data
 *
 * @param op [IN] keymgmt implementation
 *
 * @retval key's gettable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_KEYMGMT_gettable_key_params(const CRPT_KEYMGMT *op);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief set key's parameters
 *
 * @param op [IN] keymgmt implementation
 * @param keydata [IN/OUT] key data
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_KEYMGMT_set_key_params(const CRPT_KEYMGMT *op, void *keydata, const CRPT_PARAM params[],
                                            size_t plen);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief key's settable parameters of keymgmt implementation
 *
 * @param op [IN] keymgmt implementation
 *
 * @retval key's settable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_KEYMGMT_settable_key_params(const CRPT_KEYMGMT *op);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief key checks
 *
 * @param op [IN] keymgmt implementation
 * @param keydata [IN] key data
 * @param selection [IN] selection
 *
 * @retval error code
 */
CRPT_EXPORT int CRPT_KEYMGMT_has(const CRPT_KEYMGMT *op, void *keydata, unsigned int selection);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief key validation
 *
 * @param op [IN] keymgmt implementation
 * @param keydata [IN] key data
 * @param selection [IN] selection
 *
 * @retval error code
 */
CRPT_EXPORT int CRPT_KEYMGMT_validate(const CRPT_KEYMGMT *op, void *keydata, unsigned int selection);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief selective matching of two keys
 *
 * @param op [IN] keymgmt implementation
 * @param keydata1 [IN] key data 1
 * @param keydata2 [IN] key data 2
 * @param selection [IN] selection
 *
 * @retval error code
 */
CRPT_EXPORT int CRPT_KEYMGMT_match(const CRPT_KEYMGMT *op, const void *keydata1, const void *keydata2,
                                   unsigned int selection);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief copy key
 *
 * @param op [IN] keymgmt implementation
 * @param keydata_to [OUT] key data
 * @param keydata_from [IN] key data 2
 * @param selection [IN] selection
 *
 * @retval error code
 */
CRPT_EXPORT int CRPT_KEYMGMT_copy(const CRPT_KEYMGMT *op, void *keydata_to, const void *keydata_from,
                                  unsigned int selection);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief selective import
 *
 * @param op [IN] keymgmt implementation
 * @param keydata [IN/OUT] key data
 * @param selection [IN] selection
 * @param params [IN] data to import
 * @param plen [IN] length of parameters
 *
 * @retval error code
 */
CRPT_EXPORT int CRPT_KEYMGMT_import(const CRPT_KEYMGMT *op, void *keydata, unsigned int selection,
                                    const CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief import types
 *
 * @param op [IN] keymgmt implementation
 * @param selection [IN] selection
 *
 * @retval import types
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_KEYMGMT_import_types(const CRPT_KEYMGMT *op, unsigned int selection);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief selective export
 *
 * @param op [IN] keymgmt implementation
 * @param keydata [IN/OUT] key data
 * @param selection [IN] selection
 * @param param_cb [IN] callback
 * @param cbarg [IN] callback argument
 *
 * @retval error code
 */
CRPT_EXPORT int CRPT_KEYMGMT_export(const CRPT_KEYMGMT *op, void *keydata, unsigned int selection,
                                    CRPT_CALLBACK *param_cb, void *cbarg);

/**
 * @ingroup crypto_keymgmt
 *
 * @brief import types
 *
 * @param op [IN] keymgmt implementation
 * @param selection [IN] selection
 *
 * @retval import types
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_KEYMGMT_export_types(const CRPT_KEYMGMT *op, unsigned int selection);


/**
 * Signature
 *
 * A digital signature is a mathematical scheme for verifying the authenticity
 * of digital messages or documents. A valid digital signature, where the
 * prerequisites are satisfied, gives a recipient very strong reason to believe
 * that the message was created by a known sender (authentication), and that the
 * message was not altered in transit (integrity)
 *
 */

/** @defgroup crypto_signature */

/**
 * @ingroup crypto_signature
 *
 * @brief initialize signature context
 *
 * @param vctx [IN/OUT] implementation context
 * @param key [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int(CRPT_SIGNATURE_sign_init_fn)(void *vctx, void *key);

/**
 * @ingroup crypto_signature
 *
 * @brief do sign
 *
 * @param vctx [IN/OUT] implementation context
 * @param sig [OUT] signature
 * @param sigsize [IN] max room of sig
 * @param siglen [OUT] length of signature
 * @param tbs [IN] data to be sign
 * @param tbslen [IN] length of tbs
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int(CRPT_SIGNATURE_sign_fn)(void *vctx, unsigned char *sig, size_t sigsize, size_t *siglen,
                                    const unsigned char *tbs, size_t tbslen);

/**
 * @ingroup crypto_signature
 *
 * @brief initialize signature context
 *
 * @param vctx [IN/OUT] implementation context
 * @param key [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int(CRPT_SIGNATURE_verify_init_fn)(void *vctx, void *key);

/**
 * @ingroup crypto_signature
 *
 * @brief do verify
 *
 * @param vctx [IN/OUT] implementation context
 * @param sig [IN] signature
 * @param siglen [IN] length of signature
 * @param tbs [IN] data to be sign
 * @param tbslen [IN] length of tbs
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int(CRPT_SIGNATURE_verify_fn)(void *vctx, const unsigned char *sig, size_t siglen, const unsigned char *tbs,
                                      size_t tbslen);

/**
 * @ingroup crypto_signature
 *
 * @brief initialize signature context
 *
 * @param vctx [IN/OUT] implementation context
 * @param key [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int(CRPT_SIGNATURE_verify_recover_init_fn)(void *vctx, void *key);

/**
 * @ingroup crypto_signature
 *
 * @brief do verify-recover
 *
 * @param vctx [IN/OUT] implementation context
 * @param rout [OUT] recovered data
 * @param routsize [IN] max room of rout
 * @param routlen [OUT] length of recovered data
 * @param tbs [IN] data to be sign
 * @param tbslen [IN] length of tbs
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int(CRPT_SIGNATURE_verify_recover_fn)(void *vctx, unsigned char *rout, size_t routsize, size_t *routlen,
                                              const unsigned char *sig, size_t siglen);

struct crpt_signature_st {
    int nid;

    CRPT_REFCNT refcnt;
    CRPT_THREAD_MUTEX *lock;

    CRPT_GENERIC_CTX_new_f newctx;
    CRPT_GENERIC_CTX_dup_f dupctx;
    CRPT_GENERIC_CTX_free_f freectx;

    CRPT_GENERIC_get_ctx_params_f get_ctx_params;
    CRPT_GENERIC_set_ctx_params_f set_ctx_params;
    CRPT_GENERIC_gettable_ctx_params_f gettable_ctx_params;
    CRPT_GENERIC_settable_ctx_params_f settable_ctx_params;

    CRPT_SIGNATURE_sign_init_fn *sign_init;
    CRPT_SIGNATURE_sign_fn *sign;

    CRPT_SIGNATURE_verify_init_fn *verify_init;
    CRPT_SIGNATURE_verify_fn *verify;

    CRPT_SIGNATURE_verify_recover_init_fn *verify_recover_init;
    CRPT_SIGNATURE_verify_recover_fn *verify_recover;
};
typedef struct crpt_signature_st CRPT_SIGNATURE;
typedef struct crpt_signature_ctx_st CRPT_SIGNATURE_CTX;

/* Signature parameters */
#define CRPT_SIGNATURE_PARAM_PAD_MODE          "padding"
#define CRPT_SIGNATURE_PARAM_DIGEST            "digest"
#define CRPT_SIGNATURE_PARAM_DIGEST_PROPS      "digest-properties"
#define CRPT_SIGNATURE_PARAM_PSS_DIGEST        "pss-digest"
#define CRPT_SIGNATURE_PARAM_PSS_DIGEST_PROPS  "pss-digest-properties"
#define CRPT_SIGNATURE_PARAM_PSS_SALT_LEN      "salt-length"
#define CRPT_SIGNATURE_PARAM_MGF1_DIGEST       "mgf1-digest"
#define CRPT_SIGNATURE_PARAM_MGF1_DIGEST_PROPS "mgf1-digest-properties"

/**
 * @ingroup crypto_signature
 *
 * @brief fetch signature algorithm implement
 *
 * @param lib [IN/OUT] library context created via |HICRYPTO_new| or returned from |HICRYPTO_default|
 * @param algorithm [IN] algorithm name defined as SN_xxx, such as SN_rsa
 * @param properties [IN] implement properties, such as "fips=true, multi-buffer=true"
 *
 * @retval fetched implementation
 */
CRPT_EXPORT CRPT_SIGNATURE *CRPT_SIGNATURE_fetch(CRPTLIB_CTX *libctx, const char *algorithm, const char *properties);

/**
 * @ingroup crypto_signature
 *
 * @brief increase reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_up_ref(CRPT_SIGNATURE *op);

/**
 * @ingroup crypto_signature
 *
 * @brief decrease reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_down_ref(CRPT_SIGNATURE *op);

/**
 * @ingroup crypto_signature
 *
 * @brief destory implementation
 *
 * @param op [IN/OUT] implementation
 *
 */
CRPT_EXPORT void CRPT_SIGNATURE_free(CRPT_SIGNATURE *op);

/**
 * @ingroup crypto_signature
 *
 * @brief get name id of implementaion
 *
 * @param op [IN/OUT] implementation
 *
 * @retval name id of implementaion
 */
CRPT_EXPORT int CRPT_SIGNATURE_nid(const CRPT_SIGNATURE *op);

/**
 * @ingroup crypto_signature
 *
 * @brief create signature context
 *
 * @param op [IN/OUT] implementation
 * @param provctx [IN] NOT-USED now
 *
 * @retval pointer to signature context
 */
CRPT_EXPORT CRPT_SIGNATURE_CTX *CRPT_SIGNATURE_CTX_new(CRPT_SIGNATURE *op, void *provctx);

/**
 * @ingroup crypto_signature
 *
 * @brief duplicate signature context
 *
 * @param ctx [IN/OUT] signature context
 *
 * @retval pointer to signature context
 */
CRPT_EXPORT CRPT_SIGNATURE_CTX *CRPT_SIGNATURE_CTX_dup(CRPT_SIGNATURE_CTX *ctx);

/**
 * @ingroup crypto_signature
 *
 * @brief copy signature context
 *
 * @param out [OUT] signature context
 * @param in [IN] signature context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_CTX_copy(CRPT_SIGNATURE_CTX *out, const CRPT_SIGNATURE_CTX *in);

/**
 * @ingroup crypto_signature
 *
 * @brief destory signature context
 *
 * @param ctx [IN/OUT] signature context
 *
 */
CRPT_EXPORT void CRPT_SIGNATURE_CTX_free(CRPT_SIGNATURE_CTX *ctx);

/**
 * @ingroup crypto_signature
 *
 * @brief get context's parameters
 *
 * @param ctx [IN] signature context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_get_ctx_params(CRPT_SIGNATURE_CTX *ctx, CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_signature
 *
 * @brief context's gettable parameters of signature implementation
 *
 * @param op [IN] signature implementation
 *
 * @retval context's gettable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_SIGNATURE_gettable_ctx_params(const CRPT_SIGNATURE *op);

/**
 * @ingroup crypto_signature
 *
 * @brief set context's parameters
 *
 * @param ctx [IN] signature context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_set_ctx_params(CRPT_SIGNATURE_CTX *ctx, const CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_signature
 *
 * @brief context's settable parameters of signature implementation
 *
 * @param op [IN] signature implementation
 *
 * @retval context's settable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_SIGNATURE_settable_ctx_params(const CRPT_SIGNATURE *op);

/**
 * @ingroup crypto_signature
 *
 * @brief initialize signature context
 *
 * @param ctx [IN/OUT] signature context
 * @param provkey [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_sign_init(CRPT_SIGNATURE_CTX *ctx, void *provkey);

/**
 * @ingroup crypto_signature
 *
 * @brief do sign
 *
 * @param ctx [IN/OUT] signature context
 * @param sig [OUT] signature
 * @param sigsize [IN] max room of sig
 * @param siglen [OUT] length of signature
 * @param tbs [IN] data to be sign
 * @param tbslen [IN] length of tbs
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_sign(CRPT_SIGNATURE_CTX *ctx, unsigned char *sig, size_t sigsize, size_t *siglen,
                                    const unsigned char *tbs, size_t tbslen);

/**
 * @ingroup crypto_signature
 *
 * @brief initialize signature context
 *
 * @param ctx [IN/OUT] crypto_signature context
 * @param provkey [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_verify_init(CRPT_SIGNATURE_CTX *ctx, void *provkey);

/**
 * @ingroup crypto_signature
 *
 * @brief do verify
 *
 * @param ctx [IN/OUT] signature context
 * @param sig [IN] signature
 * @param siglen [IN] length of signature
 * @param tbs [IN] data to be sign
 * @param tbslen [IN] length of tbs
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_verify(CRPT_SIGNATURE_CTX *ctx, const unsigned char *sig, size_t siglen,
                                      const unsigned char *tbs, size_t tbslen);

/**
 * @ingroup crypto_signature
 *
 * @brief initialize signature context
 *
 * @param ctx [IN/OUT] signature context
 * @param provkey [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_verify_recover_init(CRPT_SIGNATURE_CTX *ctx, void *provkey);

/**
 * @ingroup crypto_signature
 *
 * @brief do verify-recover
 *
 * @param ctx [IN/OUT] signature context
 * @param rout [OUT] recovered data
 * @param routsize [IN] max room of rout
 * @param routlen [OUT] length of recovered data
 * @param tbs [IN] data to be sign
 * @param tbslen [IN] length of tbs
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_verify_recover(CRPT_SIGNATURE_CTX *ctx, unsigned char *rout, size_t routsize,
                                              size_t *routlen, const unsigned char *sig, size_t siglen);

/**
 * @ingroup crypto_signature
 *
 * @brief initialize signature context
 *
 * @param ctx [IN/OUT] signature context
 * @param provkey [IN] key
 * @param provkey [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_digest_sign_start(CRPT_SIGNATURE_CTX *ctx, CRPT_DIGEST *digest, void *provkey);

/**
 * @ingroup crypto_signature
 *
 * @brief compress data to update signature context
 *
 * @param ctx [IN/OUT] signature context
 * @param data [IN] pointer to input data
 * @param datalen [IN] length of input data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_digest_sign_update(CRPT_SIGNATURE_CTX *ctx, const unsigned char *data, size_t datalen);

/**
 * @ingroup crypto_signature
 *
 * @brief do sign
 *
 * @param ctx [IN/OUT] signature context
 * @param sig [OUT] signature
 * @param sigsize [IN] max room of sig
 * @param siglen [OUT] length of signature
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_digest_sign_finish(CRPT_SIGNATURE_CTX *ctx, unsigned char *sig, size_t sigsize,
                                                  size_t *siglen);

/**
 * @ingroup crypto_signature
 *
 * @brief do sign
 *
 * @param ctx [IN/OUT] signature context
 * @param sig [OUT] signature
 * @param sigsize [IN] max room of sig
 * @param siglen [OUT] length of signature
 * @param tbs [IN] data to be sign
 * @param tbslen [IN] length of tbs
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_digest_sign(CRPT_SIGNATURE_CTX *ctx, unsigned char *sig, size_t sigsize, size_t *siglen,
                                           const unsigned char *data, size_t datalen);

/**
 * @ingroup crypto_signature
 *
 * @brief initialize signature context
 *
 * @param ctx [IN/OUT] signature context
 * @param provkey [IN] key
 * @param provkey [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_digest_verify_start(CRPT_SIGNATURE_CTX *ctx, CRPT_DIGEST *digest, void *provkey);

/**
 * @ingroup crypto_signature
 *
 * @brief compress data to update signature context
 *
 * @param ctx [IN/OUT] signature context
 * @param data [IN] pointer to input data
 * @param datalen [IN] length of input data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_digest_verify_update(CRPT_SIGNATURE_CTX *ctx, const unsigned char *data, size_t datalen);

/**
 * @ingroup crypto_signature
 *
 * @brief do sign
 *
 * @param ctx [IN/OUT] signature context
 * @param sig [OUT] signature
 * @param sigsize [IN] max room of sig
 * @param siglen [OUT] length of signature
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_digest_verify_finish(CRPT_SIGNATURE_CTX *ctx, unsigned char *sig, size_t siglen);

/**
 * @ingroup crypto_signature
 *
 * @brief do sign
 *
 * @param ctx [IN/OUT] signature context
 * @param sig [OUT] signature
 * @param sigsize [IN] max room of sig
 * @param siglen [OUT] length of signature
 * @param data [IN] data
 * @param datalen [IN] length of data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_SIGNATURE_digest_verify(CRPT_SIGNATURE_CTX *ctx, unsigned char *sig, size_t siglen,
                                             const unsigned char *data, size_t datalen);


/**
 * Asymmetric Cipher
 *
 * Public-key cryptography, or asymmetric cryptography, is a cryptographic
 * system that uses pairs of keys: public keys, which may be disseminated
 * widely, and private keys, which are known only to the owner. The generation
 * of such keys depends on cryptographic algorithms based on mathematical
 * problems to produce one-way functions. Effective security only requires
 * keeping the private key private; the public key can be openly distributed
 * without compromising security.
 *
 */

/** @defgroup crypto_asym_cipher */

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief initialize asym_cipher context
 *
 * @param vctx [IN/OUT] implementation context
 * @param key [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_ASYM_CIPHER_cipher_init_f)(void *vctx, void *key);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief do asym_cipher
 *
 * @param vctx [IN/OUT] implementation context
 * @param out [OUT] output buffer
 * @param outsize [IN] max room of output buffer
 * @param outlen [OUT] length of output data
 * @param in [IN] input buffer
 * @param inlen [IN] length of input data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
typedef int (*CRPT_ASYM_CIPHER_cipher_f)(void *vctx, unsigned char *out, size_t outsize, size_t *outlen,
                                         const unsigned char *in, size_t inlen);

typedef int(CRPT_ASYM_CIPHER_get_ctx_params_fn)(void *vctx, CRPT_PARAM params[], size_t plen);
typedef int(CRPT_ASYM_CIPHER_set_ctx_params_fn)(void *vctx, const CRPT_PARAM params[], size_t plen);
typedef const CRPT_PARAM *(CRPT_ASYM_CIPHER_gettable_ctx_params_fn)(void);
typedef const CRPT_PARAM *(CRPT_ASYM_CIPHER_settable_ctx_params_fn)(void);

struct crpt_asym_cipher_st {
    int nid;

    CRPT_REFCNT refcnt;
    CRPT_THREAD_MUTEX *lock;

    CRPT_GENERIC_CTX_new_f newctx;
    CRPT_GENERIC_CTX_dup_f dupctx;
    CRPT_GENERIC_CTX_free_f freectx;

    CRPT_GENERIC_get_ctx_params_f get_ctx_params;
    CRPT_GENERIC_set_ctx_params_f set_ctx_params;
    CRPT_GENERIC_gettable_ctx_params_f gettable_ctx_params;
    CRPT_GENERIC_settable_ctx_params_f settable_ctx_params;

    CRPT_ASYM_CIPHER_cipher_init_f encrypt_init;
    CRPT_ASYM_CIPHER_cipher_f encrypt;

    CRPT_ASYM_CIPHER_cipher_init_f decrypt_init;
    CRPT_ASYM_CIPHER_cipher_f decrypt;
};

/* Asym cipher parameters */
#define CRPT_ASYM_CIPHER_PARAM_PAD_MODE          "padding"
#define CRPT_ASYM_CIPHER_PARAM_DIGEST            "digest"
#define CRPT_ASYM_CIPHER_PARAM_DIGEST_PROPS      "digest-properties"
#define CRPT_ASYM_CIPHER_PARAM_MGF1_DIGEST       "mgf1-digest"
#define CRPT_ASYM_CIPHER_PARAM_MGF1_DIGEST_PROPS "mgf1-digest-properties"
#define CRPT_ASYM_CIPHER_PARAM_OAEP_DIGEST       "oaep-digest"
#define CRPT_ASYM_CIPHER_PARAM_OAEP_DIGEST_PROPS "oaep-digest-properties"

typedef struct crpt_asym_cipher_st CRPT_ASYM_CIPHER;
typedef struct crpt_asym_cipher_ctx_st CRPT_ASYM_CIPHER_CTX;

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief fetch asym_cipher algorithm implement
 *
 * @param lib [IN/OUT] library context created via |HICRYPTO_new| or returned from |HICRYPTO_default|
 * @param algorithm [IN] algorithm name defined as SN_xxx, such as SN_rsa
 * @param properties [IN] implement properties, such as "fips=true, multi-buffer=true"
 *
 * @retval fetched implementation
 */
CRPT_EXPORT CRPT_ASYM_CIPHER *CRPT_ASYM_CIPHER_fetch(CRPTLIB_CTX *libctx, const char *algorithm,
                                                     const char *properties);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief increase reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_up_ref(CRPT_ASYM_CIPHER *op);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief decrease reference count
 *
 * @param op [IN/OUT] implementation
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_down_ref(CRPT_ASYM_CIPHER *op);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief destory implementation
 *
 * @param op [IN/OUT] implementation
 *
 */
CRPT_EXPORT void CRPT_ASYM_CIPHER_free(CRPT_ASYM_CIPHER *op);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief get name id of implementaion
 *
 * @param op [IN/OUT] implementation
 *
 * @retval name id of implementaion
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_nid(const CRPT_ASYM_CIPHER *op);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief create asym_cipher context
 *
 * @param op [IN/OUT] implementation
 * @param provctx [IN] NOT-USED now
 *
 * @retval pointer to asym_cipher context
 */
CRPT_EXPORT CRPT_ASYM_CIPHER_CTX *CRPT_ASYM_CIPHER_CTX_new(CRPT_ASYM_CIPHER *op, void *provctx);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief duplicate asym_cipher context
 *
 * @param ctx [IN/OUT] asym_cipher context
 *
 * @retval pointer to asym_cipher context
 */
CRPT_EXPORT CRPT_ASYM_CIPHER_CTX *CRPT_ASYM_CIPHER_CTX_dup(CRPT_ASYM_CIPHER_CTX *ctx);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief copy asym_cipher context
 *
 * @param out [OUT] asym_cipher context
 * @param in [IN] asym_cipher context
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_CTX_copy(CRPT_ASYM_CIPHER_CTX *out, const CRPT_ASYM_CIPHER_CTX *in);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief destory asym_cipher context
 *
 * @param ctx [IN/OUT] asym_cipher context
 *
 */
CRPT_EXPORT void CRPT_ASYM_CIPHER_CTX_free(CRPT_ASYM_CIPHER_CTX *ctx);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief initialize asym_cipher context
 *
 * @param ctx [IN/OUT] asym_cipher context
 * @param provkey [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_encrypt_init(CRPT_ASYM_CIPHER_CTX *ctx, void *provkey);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief initialize asym_cipher context
 *
 * @param ctx [IN/OUT] asym_cipher context
 * @param provkey [IN/OUT] key data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_decrypt_init(CRPT_ASYM_CIPHER_CTX *ctx, void *provkey);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief do asym_cipher
 *
 * @param ctx [IN/OUT] asym_cipher context
 * @param out [OUT] output buffer
 * @param outsize [IN] max room of output buffer
 * @param outlen [OUT] length of output data
 * @param in [IN] input buffer
 * @param inlen [IN] length of input data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_encrypt(CRPT_ASYM_CIPHER_CTX *ctx, unsigned char *out, size_t outsize, size_t *outlen,
                                         const unsigned char *in, size_t inlen);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief do asym_cipher
 *
 * @param ctx [IN/OUT] asym_cipher context
 * @param out [OUT] output buffer
 * @param outsize [IN] max room of output buffer
 * @param outlen [OUT] length of output data
 * @param in [IN] input buffer
 * @param inlen [IN] length of input data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_decrypt(CRPT_ASYM_CIPHER_CTX *ctx, unsigned char *out, size_t outsize, size_t *outlen,
                                         const unsigned char *in, size_t inlen);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief get context's parameters
 *
 * @param ctx [IN] asym_cipher context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_get_ctx_params(CRPT_ASYM_CIPHER_CTX *ctx, CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief context's gettable parameters of asym_cipher implementation
 *
 * @param op [IN] asym_cipher implementation
 *
 * @retval context's gettable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_ASYM_CIPHER_gettable_ctx_params(const CRPT_ASYM_CIPHER *op);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief set context's parameters
 *
 * @param ctx [IN] asym_cipher context
 * @param params [IN/OUT] pointer to parameters
 * @param plen [IN] length of parameters
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_set_ctx_params(CRPT_ASYM_CIPHER_CTX *ctx, const CRPT_PARAM params[], size_t plen);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief context's settable parameters of asym_cipher implementation
 *
 * @param op [IN] asym_cipher implementation
 *
 * @retval context's settable parameters
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_ASYM_CIPHER_settable_ctx_params(const CRPT_ASYM_CIPHER *op);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief set padding scheme
 *
 * @param ctx [IN/OUT] asym_cipher context
 * @param padding [IN] padding scheme
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_set_padding(CRPT_ASYM_CIPHER_CTX *ctx, int padding);

/**
 * @ingroup crypto_asym_cipher
 *
 * @brief set digest
 *
 * @param ctx [IN/OUT] asym_cipher context
 * @param digest [IN] digest name
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ASYM_CIPHER_set_digest(CRPT_ASYM_CIPHER_CTX *ctx, const char *digest);


#if defined(__cplusplus)
}
#endif

#endif
