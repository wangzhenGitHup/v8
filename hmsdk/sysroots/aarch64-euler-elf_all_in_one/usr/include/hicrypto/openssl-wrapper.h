/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: wrapper for openssl
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRPT_HEADER_OPENSSL_WRAPPER_H
#define CRPT_HEADER_OPENSSL_WRAPPER_H

#include <hicrypto/conf.h>
#include <hicrypto/target.h>
#include <hicrypto/memory.h>
#include <hicrypto/string.h>
#include <hicrypto/thread.h>
#include <hicrypto/opensslconf.h>

#define OPENSSL_API_COMPAT 0x10100000L

#undef assert
#define assert(cond) CRPT_ASSERT(cond)

#undef ossl_inline
#define ossl_inline inline

#define ossl_isdigit(ch)  ((ch) >= '0' && (ch) <= '9')
#define ossl_isxdigit(ch) (((ch) >= '0' && (ch) <= '9') || ((ch) >= 'a' && (ch) <= 'f') || ((ch) >= 'A' && (ch) <= 'F'))

#ifdef HICRYPTO_SMALL_FOOTPRINT
#define OPENSSL_SMALL_FOOTPRINT
#endif

#ifdef HICRYPTO_NO_ASM
#define OPENSSL_NO_ASM
#endif

#ifndef OSSL_NELEM
#define OSSL_NELEM(arr) (sizeof(arr) / sizeof(*(arr)))
#endif

/** memory & string */
#define OPENSSL_malloc            CRPT_malloc
#define OPENSSL_zalloc            CRPT_zalloc
#define OPENSSL_realloc           CRPT_realloc
#define OPENSSL_free              CRPT_free
#define OPENSSL_cleanse           CRPT_clean
#define OPENSSL_clear_free        CRPT_clean_free
#define OPENSSL_clear_realloc     CRPT_clean_realloc
#define OPENSSL_secure_malloc     CRPT_secure_malloc
#define OPENSSL_secure_zalloc     CRPT_secure_zalloc
#define OPENSSL_secure_realloc    CRPT_secure_realloc
#define OPENSSL_secure_clear_free CRPT_clean_free
#define OPENSSL_strdup            CRPT_strdup
#define CRYPTO_memcmp             memcmp

CRPT_INLINE int OPENSSL_hexchar2int(char ch)
{
    if (isxdigit(ch)) {
        // ('0' - '9') -> (0x30 - 0x39) & 0x0F -> (0 - 9)
        // ('a' - 'f') -> (0x61 - 0x7A) +9-> (0x6A - 0x6F) & 0x0F -> (0x0A - 0x0F)
        // ('A' - 'F') -> (0x41 - 0x5A) +9-> (0x4A - 0x4F) & 0x0F -> (0x0A - 0x0F)
        return (unsigned char)(ch > '9' ? ch + 9 : ch) & 0x0F;
    }
    return -1;
}

/** thread */
#define CRYPTO_THREAD_ID             CRPT_THREAD_ID
#define CRYPTO_THREAD_get_current_id CRPT_THREAD_id
#define CRYPTO_THREAD_compare_id     CRPT_THREAD_compare

#define CRYPTO_RWLOCK                  CRPT_THREAD_MUTEX
#define CRYPTO_THREAD_lock_new         CRPT_THREAD_MUTEX_new
#define CRYPTO_THREAD_lock_free        CRPT_THREAD_MUTEX_free
#define CRYPTO_THREAD_write_lock(lock) (CRPT_THREAD_MUTEX_acquire(lock) == CRPT_SUCCESS ? 1 : 0)
#define CRYPTO_THREAD_read_lock(lock)  (CRPT_THREAD_MUTEX_acquire(lock) == CRPT_SUCCESS ? 1 : 0)
#define CRYPTO_THREAD_unlock(lock)     (CRPT_THREAD_MUTEX_release(lock) == CRPT_SUCCESS ? 1 : 0)

/** random */
#ifndef CRPT_NO_RAND
#include <hicrypto/rand.h>
static inline int RAND_bytes(unsigned char *buf, int len)
{
    if (len > 0 && buf != NULL) {
        CRPT_RAND_bytes(buf, (size_t)len);
    }
    return 1;
}

static inline int RAND_priv_bytes(unsigned char *buf, int len)
{
    if (len > 0 && buf != NULL) {
        CRPT_RAND_bytes(buf, (size_t)len);
    }
    return 1;
}
#endif

/* fatal error */
#define ERR_R_FATAL                       0x40
#define ERR_R_MALLOC_FAILURE              0x41
#define ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED 0x42
#define ERR_R_PASSED_NULL_PARAMETER       0x43
#define ERR_R_INTERNAL_ERROR              0x44
#define ERR_R_DISABLED                    0x45
#define ERR_R_INIT_FAIL                   0x46
#define ERR_R_OPERATION_FAIL              0x48

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif
