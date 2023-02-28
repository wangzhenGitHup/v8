/*
 * WARNING: do not edit!
 * Generated by Makefile from ../../../../../work-shared/hm-openssl-source/git/include/openssl/opensslconf.h.in
 *
 * Copyright 2016-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/opensslv.h>

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef OPENSSL_ALGORITHM_DEFINES
# error OPENSSL_ALGORITHM_DEFINES no longer supported
#endif

/*
 * OpenSSL was configured with the following options:
 */

#define OPENSSL_MIN_API 0x10100000L
#ifndef OPENSSL_NO_ARIA
# define OPENSSL_NO_ARIA
#endif
#ifndef OPENSSL_NO_BF
# define OPENSSL_NO_BF
#endif
#ifndef OPENSSL_NO_BLAKE2
# define OPENSSL_NO_BLAKE2
#endif
#ifndef OPENSSL_NO_CAMELLIA
# define OPENSSL_NO_CAMELLIA
#endif
#ifndef OPENSSL_NO_CAST
# define OPENSSL_NO_CAST
#endif
#ifndef OPENSSL_NO_CHACHA
# define OPENSSL_NO_CHACHA
#endif
#ifndef OPENSSL_NO_CMAC
# define OPENSSL_NO_CMAC
#endif
#ifndef OPENSSL_NO_CMP
# define OPENSSL_NO_CMP
#endif
#ifndef OPENSSL_NO_CMS
# define OPENSSL_NO_CMS
#endif
#ifndef OPENSSL_NO_COMP
# define OPENSSL_NO_COMP
#endif
#ifndef OPENSSL_NO_CRMF
# define OPENSSL_NO_CRMF
#endif
#ifndef OPENSSL_NO_CT
# define OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_DES
# define OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_DH
# define OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_DSA
# define OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_FIPS
# define OPENSSL_NO_FIPS
#endif
#ifndef OPENSSL_NO_GM_CERT_CNF
# define OPENSSL_NO_GM_CERT_CNF
#endif
#ifndef OPENSSL_NO_GMSM
# define OPENSSL_NO_GMSM
#endif
#ifndef OPENSSL_NO_GMTLS
# define OPENSSL_NO_GMTLS
#endif
#ifndef OPENSSL_NO_IDEA
# define OPENSSL_NO_IDEA
#endif
#ifndef OPENSSL_NO_MD2
# define OPENSSL_NO_MD2
#endif
#ifndef OPENSSL_NO_MD4
# define OPENSSL_NO_MD4
#endif
#ifndef OPENSSL_NO_MDC2
# define OPENSSL_NO_MDC2
#endif
#ifndef OPENSSL_NO_NDCPP
# define OPENSSL_NO_NDCPP
#endif
#ifndef OPENSSL_NO_OCSP
# define OPENSSL_NO_OCSP
#endif
#ifndef OPENSSL_NO_POLY1305
# define OPENSSL_NO_POLY1305
#endif
#ifndef OPENSSL_NO_RC2
# define OPENSSL_NO_RC2
#endif
#ifndef OPENSSL_NO_RC4
# define OPENSSL_NO_RC4
#endif
#ifndef OPENSSL_NO_RC5
# define OPENSSL_NO_RC5
#endif
#ifndef OPENSSL_NO_RMD160
# define OPENSSL_NO_RMD160
#endif
#ifndef OPENSSL_NO_SEED
# define OPENSSL_NO_SEED
#endif
#ifndef OPENSSL_NO_SIPHASH
# define OPENSSL_NO_SIPHASH
#endif
#ifndef OPENSSL_NO_SM2
# define OPENSSL_NO_SM2
#endif
#ifndef OPENSSL_NO_SM3
# define OPENSSL_NO_SM3
#endif
#ifndef OPENSSL_NO_SM4
# define OPENSSL_NO_SM4
#endif
#ifndef OPENSSL_NO_SRP
# define OPENSSL_NO_SRP
#endif
#ifndef OPENSSL_NO_TS
# define OPENSSL_NO_TS
#endif
#ifndef OPENSSL_NO_WHIRLPOOL
# define OPENSSL_NO_WHIRLPOOL
#endif
#ifndef OPENSSL_RAND_SEED_OS
# define OPENSSL_RAND_SEED_OS
#endif
#ifndef OPENSSL_NO_AFALGENG
# define OPENSSL_NO_AFALGENG
#endif
#ifndef OPENSSL_NO_ALT_MEMORY
# define OPENSSL_NO_ALT_MEMORY
#endif
#ifndef OPENSSL_NO_ASAN
# define OPENSSL_NO_ASAN
#endif
#ifndef OPENSSL_NO_ASM
# define OPENSSL_NO_ASM
#endif
#ifndef OPENSSL_NO_ASYNC
# define OPENSSL_NO_ASYNC
#endif
#ifndef OPENSSL_NO_AUTOLOAD_CONFIG
# define OPENSSL_NO_AUTOLOAD_CONFIG
#endif
#ifndef OPENSSL_NO_CAPIENG
# define OPENSSL_NO_CAPIENG
#endif
#ifndef OPENSSL_NO_CRL_MEMPOOL
# define OPENSSL_NO_CRL_MEMPOOL
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
# define OPENSSL_NO_CRYPTO_MDEBUG
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
# define OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
#endif
#ifndef OPENSSL_NO_DEPRECATED
# define OPENSSL_NO_DEPRECATED
#endif
#ifndef OPENSSL_NO_DEVCRYPTOENG
# define OPENSSL_NO_DEVCRYPTOENG
#endif
#ifndef OPENSSL_NO_DGRAM
# define OPENSSL_NO_DGRAM
#endif
#ifndef OPENSSL_NO_DSO
# define OPENSSL_NO_DSO
#endif
#ifndef OPENSSL_NO_DTLS
# define OPENSSL_NO_DTLS
#endif
#ifndef OPENSSL_NO_DTLS1
# define OPENSSL_NO_DTLS1
#endif
#ifndef OPENSSL_NO_DTLS1_2
# define OPENSSL_NO_DTLS1_2
#endif
#ifndef OPENSSL_NO_DTO
# define OPENSSL_NO_DTO
#endif
#ifndef OPENSSL_NO_EC_NISTP_64_GCC_128
# define OPENSSL_NO_EC_NISTP_64_GCC_128
#endif
#ifndef OPENSSL_NO_EGD
# define OPENSSL_NO_EGD
#endif
#ifndef OPENSSL_NO_ENGINE
# define OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ERR
# define OPENSSL_NO_ERR
#endif
#ifndef OPENSSL_NO_EXTERNAL_TESTS
# define OPENSSL_NO_EXTERNAL_TESTS
#endif
#ifndef OPENSSL_NO_FILENAMES
# define OPENSSL_NO_FILENAMES
#endif
#ifndef OPENSSL_NO_FUZZ_AFL
# define OPENSSL_NO_FUZZ_AFL
#endif
#ifndef OPENSSL_NO_FUZZ_LIBFUZZER
# define OPENSSL_NO_FUZZ_LIBFUZZER
#endif
#ifndef OPENSSL_NO_GOST
# define OPENSSL_NO_GOST
#endif
#ifndef OPENSSL_NO_HEARTBEATS
# define OPENSSL_NO_HEARTBEATS
#endif
#ifndef OPENSSL_NO_HW_PADLOCK
# define OPENSSL_NO_HW_PADLOCK
#endif
#ifndef OPENSSL_NO_MSAN
# define OPENSSL_NO_MSAN
#endif
#ifndef OPENSSL_NO_MULTIBLOCK
# define OPENSSL_NO_MULTIBLOCK
#endif
#ifndef OPENSSL_NO_NEXTPROTONEG
# define OPENSSL_NO_NEXTPROTONEG
#endif
#ifndef OPENSSL_NO_OCB
# define OPENSSL_NO_OCB
#endif
#ifndef OPENSSL_NO_PINSHARED
# define OPENSSL_NO_PINSHARED
#endif
#ifndef OPENSSL_NO_POSIX_IO
# define OPENSSL_NO_POSIX_IO
#endif
#ifndef OPENSSL_NO_PSK
# define OPENSSL_NO_PSK
#endif
#ifndef OPENSSL_NO_RDRAND
# define OPENSSL_NO_RDRAND
#endif
#ifndef OPENSSL_NO_RFC3779
# define OPENSSL_NO_RFC3779
#endif
#ifndef OPENSSL_NO_SCRYPT
# define OPENSSL_NO_SCRYPT
#endif
#ifndef OPENSSL_NO_SCTP
# define OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SOCK
# define OPENSSL_NO_SOCK
#endif
#ifndef OPENSSL_NO_SRTP
# define OPENSSL_NO_SRTP
#endif
#ifndef OPENSSL_NO_SSL_TRACE
# define OPENSSL_NO_SSL_TRACE
#endif
#ifndef OPENSSL_NO_SSL3
# define OPENSSL_NO_SSL3
#endif
#ifndef OPENSSL_NO_SSL3_METHOD
# define OPENSSL_NO_SSL3_METHOD
#endif
#ifndef OPENSSL_NO_TESTS
# define OPENSSL_NO_TESTS
#endif
#ifndef OPENSSL_NO_TTO
# define OPENSSL_NO_TTO
#endif
#ifndef OPENSSL_NO_UBSAN
# define OPENSSL_NO_UBSAN
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
# define OPENSSL_NO_UI_CONSOLE
#endif
#ifndef OPENSSL_NO_UNIT_TEST
# define OPENSSL_NO_UNIT_TEST
#endif
#ifndef OPENSSL_NO_WEAK_SSL_CIPHERS
# define OPENSSL_NO_WEAK_SSL_CIPHERS
#endif
#ifndef OPENSSL_NO_DYNAMIC_ENGINE
# define OPENSSL_NO_DYNAMIC_ENGINE
#endif


/*
 * Sometimes OPENSSSL_NO_xxx ends up with an empty file and some compilers
 * don't like that.  This will hopefully silence them.
 */
#define NON_EMPTY_TRANSLATION_UNIT static void *dummy = &dummy;

/*
 * Applications should use -DOPENSSL_API_COMPAT=<version> to suppress the
 * declarations of functions deprecated in or before <version>. Otherwise, they
 * still won't see them if the library has been built to disable deprecated
 * functions.
 */
#ifndef DECLARE_DEPRECATED
# define DECLARE_DEPRECATED(f)   f;
# ifdef __GNUC__
#  if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 0)
#   undef DECLARE_DEPRECATED
#   define DECLARE_DEPRECATED(f)    f __attribute__ ((deprecated));
#  endif
# elif defined(__SUNPRO_C)
#  if (__SUNPRO_C >= 0x5130)
#   undef DECLARE_DEPRECATED
#   define DECLARE_DEPRECATED(f)    f __attribute__ ((deprecated));
#  endif
# endif
#endif

#ifndef OPENSSL_FILE
# ifdef OPENSSL_NO_FILENAMES
#  define OPENSSL_FILE ""
#  define OPENSSL_LINE 0
# else
#  define OPENSSL_FILE __FILE__
#  define OPENSSL_LINE __LINE__
# endif
#endif

#ifndef OPENSSL_MIN_API
# define OPENSSL_MIN_API 0
#endif

#if !defined(OPENSSL_API_COMPAT) || OPENSSL_API_COMPAT < OPENSSL_MIN_API
# undef OPENSSL_API_COMPAT
# define OPENSSL_API_COMPAT OPENSSL_MIN_API
#endif

/*
 * Do not deprecate things to be deprecated in version 1.2.0 before the
 * OpenSSL version number matches.
 */
#if OPENSSL_VERSION_NUMBER < 0x10200000L
# define DEPRECATEDIN_1_2_0(f)   f;
#elif OPENSSL_API_COMPAT < 0x10200000L
# define DEPRECATEDIN_1_2_0(f)   DECLARE_DEPRECATED(f)
#else
# define DEPRECATEDIN_1_2_0(f)
#endif

#if OPENSSL_API_COMPAT < 0x10100000L
# define DEPRECATEDIN_1_1_0(f)   DECLARE_DEPRECATED(f)
#else
# define DEPRECATEDIN_1_1_0(f)
#endif

#if OPENSSL_API_COMPAT < 0x10000000L
# define DEPRECATEDIN_1_0_0(f)   DECLARE_DEPRECATED(f)
#else
# define DEPRECATEDIN_1_0_0(f)
#endif

#if OPENSSL_API_COMPAT < 0x00908000L
# define DEPRECATEDIN_0_9_8(f)   DECLARE_DEPRECATED(f)
#else
# define DEPRECATEDIN_0_9_8(f)
#endif

/* Generate 80386 code? */
#undef I386_ONLY

#undef OPENSSL_UNISTD
#define OPENSSL_UNISTD <unistd.h>

#undef OPENSSL_EXPORT_VAR_AS_FUNCTION

/*
 * The following are cipher-specific, but are part of the public API.
 */
#if !defined(OPENSSL_SYS_UEFI)
# undef BN_LLONG
/* Only one for the following should be defined */
# define SIXTY_FOUR_BIT_LONG
# undef SIXTY_FOUR_BIT
# undef THIRTY_TWO_BIT
#endif

#define RC4_INT unsigned char

#ifdef  __cplusplus
}
#endif
