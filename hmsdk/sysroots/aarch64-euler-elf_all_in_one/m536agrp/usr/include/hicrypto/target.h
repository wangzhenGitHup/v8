/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: target information detection
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_TARGET_H
#define CRYPTO_HEADER_TARGET_H

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include <hicrypto/conf.h>

#ifndef CRPT_NO_STDIO
#include <stdio.h> // stdio.h is needed on MinGW for __MINGW_PRINTF_FORMAT.
#endif

#ifndef CRPT_NO_STDARG
#include <stdarg.h>
#endif

#if defined(__APPLE__)
#include <TargetConditionals.h>
#define CRPT_APPLE
// |TARGET_OS_MAC| is set for all Apple OS variants.
// |TARGET_OS_OSX| targets macOS specifically.
#if defined(TARGET_OS_OSX) && TARGET_OS_OSX
#define CRPT_MACOS
#endif
#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#define CRPT_IOS
#endif
#endif

#if defined(_WIN32)
#define CRPT_WINDOWS
#endif

#if defined(__linux__)
#define CRPT_LINUX
#endif

#if defined(__ANDROID_API__)
#define CRPT_ANDROID
#endif

#if defined(__cplusplus) || (defined(_MSC_VER) && !defined(__clang__))
// In C++ and non-clang MSVC, |static_assert| is a keyword.
#define CRPT_STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#else
// C11 defines the |_Static_assert| keyword and the |static_assert| macro in
// assert.h. While the former is available at all versions in Clang and GCC, the
// later depends on libc and, in glibc, depends on being built in C11 mode. We
// do not require this, for now, so use |_Static_assert| directly.
#define CRPT_STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#endif

#if defined(__GNUC__) || defined(__clang__)
#define CRPT_UNUSED __attribute__((unused))
#else
#define CRPT_UNUSED
#endif

#if defined(__cplusplus)
#define CRPT_INLINE inline
#else
#define CRPT_INLINE static inline
#endif

#if defined(CRPT_WINDOWS)
#ifdef CRPT_SHARED_LIBRARY
#ifdef __GNUC__
#define CRPT_EXPORT __attribute__((dllexport))
#else
#define CRPT_EXPORT __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#endif
#else
#ifdef __GNUC__
#define CRPT_EXPORT __attribute__((dllimport))
#else
#define CRPT_EXPORT __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
#endif
#endif
#define CRPT_HIDDEN
#else
#if __GNUC__ >= 4
#define CRPT_EXPORT __attribute__((visibility("default")))
#define CRPT_HIDDEN __attribute__((visibility("hidden")))
#else
#define CRPT_EXPORT
#define CRPT_HIDDEN
#endif
#endif

#ifndef CRPT_IMPORT
#if defined(__cplusplus)
#define CRPT_IMPORT extern "C"
#else
#define CRPT_IMPORT extern
#endif
#endif

#if defined(__x86_64) || defined(_M_AMD64) || defined(_M_X64)
#define CRPT_64_BIT
#define CRPT_X86_64
#elif defined(__x86) || defined(__i386) || defined(__i386__) || defined(_M_IX86)
#define CRPT_32_BIT
#define CRPT_X86
#elif defined(__aarch64__)
#define CRPT_64_BIT
#define CRPT_AARCH64
#elif defined(__arm) || defined(__arm__) || defined(_M_ARM)
#define CRPT_32_BIT
#define CRPT_ARM
#elif (defined(__PPC64__) || defined(__powerpc64__)) && defined(_LITTLE_ENDIAN)
#define CRPT_64_BIT
#define CRPT_PPC64LE
#elif defined(__mips__) && !defined(__LP64__)
#define CRPT_32_BIT
#define CRPT_MIPS
#elif defined(__mips__) && defined(__LP64__)
#define CRPT_64_BIT
#define CRPT_MIPS64
#elif defined(__pnacl__)
#define CRPT_32_BIT
#define CRPT_PNACL
#elif defined(__wasm__)
#define CRPT_32_BIT
#elif defined(__asmjs__)
#define CRPT_32_BIT
#elif defined(__myriad2__)
#define CRPT_32_BIT
#else
#error "Unknown target CPU"
#endif

#if defined(CRPT_64_BIT)
typedef uint64_t crpt_word_t;
#elif defined(CRPT_32_BIT)
typedef uint32_t crpt_word_t;
#else
#error "Must define either CRPT_32_BIT or CRPT_64_BIT"
#endif

#if defined(__SSE2__) && !defined(CRPT_NO_SSE2)
#define CRPT_SSE2
#endif

#if defined(__has_feature)
#if __has_feature(address_sanitizer)
#define CRPT_ASAN
#endif
#if __has_feature(thread_sanitizer)
#define CRPT_TSAN
#endif
#if __has_feature(memory_sanitizer)
#define CRPT_MSAN
#define CRPT_ASM_INCOMPATIBLE
#endif
#endif

#if (defined __GNUC__) || (defined __clang__)
#define ATTRIBUT_FORMAT(f, v) __attribute__((format(printf, f, v)))
#define ATTRIBUT_ALIGNAS(v)   __attribute__((aligned(v)))
#else
#define ATTRIBUT_FORMAT(f, v)
#define ATTRIBUT_ALIGNAS(v)
#endif

// Have a generic fall-through for different versions of C/C++.
#if defined(__cplusplus) && __cplusplus >= 201703L
#define ATTRIBUT_FALLTHROUGH [[fallthrough]]
#elif defined(__cplusplus) && __cplusplus >= 201103L && defined(__clang__)
#define ATTRIBUT_FALLTHROUGH [[clang::fallthrough]]
#elif defined(__cplusplus) && __cplusplus >= 201103L && defined(__GNUC__) && __GNUC__ >= 7
#define ATTRIBUT_FALLTHROUGH [[gnu::fallthrough]]
#elif defined(__GNUC__) && __GNUC__ >= 7 // gcc 7
#define ATTRIBUT_FALLTHROUGH __attribute__((fallthrough))
#elif defined(__clang__)
#if __has_attribute(fallthrough) && __clang_major__ >= 5
// Clang 3.5, at least, complains about "error: declaration does not declare
// anything", possibily because we put a semicolon after this macro in
// practice. Thus limit it to >= Clang 5, which does work.
#define ATTRIBUT_FALLTHROUGH __attribute__((fallthrough))
#else // clang versions that do not support fallthrough.
#define ATTRIBUT_FALLTHROUGH
#endif
#else // C++11 on gcc 6, and all other cases
#define ATTRIBUT_FALLTHROUGH
#endif

/* Endianness conversions. */
#if defined(__GNUC__) && __GNUC__ >= 2
/** @defgroup gcc_buildin */

/**
 * @ingroup gcc_buildin
 *
 * @brief returns x with the order of the bytes reversed
 *
 * @param x [IN] integer to be reversed
 *
 * @retval reversed result
 */
static inline uint16_t CRPT_bswap2(uint16_t x)
{
    return __builtin_bswap16(x);
}

/**
 * @ingroup gcc_buildin
 *
 * @brief similar to CRPT_bswap2, but return types are 32-bit
 *
 * @param x [IN] integer to be reversed
 *
 * @retval reversed result
 */
static inline uint32_t CRPT_bswap4(uint32_t x)
{
    return __builtin_bswap32(x);
}

/**
 * @ingroup gcc_buildin
 *
 * @brief similar to CRPT_bswap2, but return types are 64-bit
 *
 * @param x [IN] integer to be reversed
 *
 * @retval reversed result
 */
static inline uint64_t CRPT_bswap8(uint64_t x)
{
    return __builtin_bswap64(x);
}
#elif defined(_MSC_VER)
#include <stdlib.h>
#pragma intrinsic(_byteswap_uint64, _byteswap_ulong, _byteswap_ushort)

/**
 * @ingroup gcc_buildin
 *
 * @brief reverses the order of bytes in an integer
 *
 * @param x [IN] integer to be reversed
 *
 * @retval reversed result
 */
static inline uint16_t CRPT_bswap2(uint16_t x)
{
    return _byteswap_ushort(x);
}

/**
 * @ingroup gcc_buildin
 *
 * @brief similar to CRPT_bswap2, but return types are 32-bit
 *
 * @param x [IN] integer to be reversed
 *
 * @retval reversed result
 */
static inline uint32_t CRPT_bswap4(uint32_t x)
{
    return _byteswap_ulong(x);
}

/**
 * @ingroup gcc_buildin
 *
 * @brief similar to CRPT_bswap2, but return types are 64-bit
 *
 * @param x [IN] integer to be reversed
 *
 * @retval reversed result
 */
static inline uint64_t CRPT_bswap8(uint64_t x)
{
    return _byteswap_uint64(x);
}
#else

/**
 * @ingroup gcc_buildin
 *
 * @brief reverses the order of bytes in an integer
 *
 * @param x [IN] integer to be reversed
 *
 * @retval reversed result
 */
static inline uint16_t CRPT_bswap2(uint16_t x)
{
    // swap 2 bytes sequence
    return (x >> 8) | (x << 8);
}

/**
 * @ingroup gcc_buildin
 *
 * @brief similar to CRPT_bswap2, but return types are 32-bit
 *
 * @param x [IN] integer to be reversed
 *
 * @retval reversed result
 */
static inline uint32_t CRPT_bswap4(uint32_t x)
{
    // reverse 4 bytes sequence
    x = (x >> 16) | (x << 16);
    x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
    return x;
}

/**
 * @ingroup gcc_buildin
 *
 * @brief similar to CRPT_bswap2, but return types are 64-bit
 *
 * @param x [IN] integer to be reversed
 *
 * @retval reversed result
 */
static inline uint64_t CRPT_bswap8(uint64_t x)
{
    // reverse 8 bytes sequence
    return CRPT_bswap4(x >> 32) | (((uint64_t)CRPT_bswap4(x)) << 32);
}
#endif

// clang-format off

/** @defgroup manipulation_integer */

/**
 * @ingroup manipulation_integer
 *
 * @brief 32-bit integer to bytes
 *
 * @param v [IN] integer to be converted
 * @param bytes [OUT] converted result
 */
static inline void CRPT_uint32_to_be_bytes(uint32_t v, uint8_t *bytes)
{
    bytes[0] = (uint8_t)(v >> 24);
    bytes[1] = (uint8_t)(v >> 16);
    bytes[2] = (uint8_t)(v >> 8);
    bytes[3] = (uint8_t)(v & 0xffu);
}

/* Endianess with 64 bits values */

/*
 * 64-bit integer manipulation functions (big endian)
 */
/**
 * @ingroup manipulation_integer
 *
 * @brief 64-bit integer from bytes
 *
 * @param bytes [IN] integer to be converted
 *
 * @retval converted result
 */
static inline uint64_t CRPT_uint64_from_be_bytes(const uint8_t *bytes)
{
    return (((uint64_t)bytes[0] << 56) |
            ((uint64_t)bytes[1] << 48) |
            ((uint64_t)bytes[2] << 40) |
            ((uint64_t)bytes[3] << 32) |
            ((uint64_t)bytes[4] << 24) |
            ((uint64_t)bytes[5] << 16) |
            ((uint64_t)bytes[6] << 8) |
            (uint64_t)bytes[7]);
}

/**
 * @ingroup manipulation_integer
 *
 * @brief 64-bit integer from bytes
 *
 * @param v [IN] integer to be converted
 * @param bytes [OUT] converted result
 */
static inline void CRPT_uint64_to_be_bytes(uint64_t v, uint8_t *bytes)
{
    bytes[0] = (uint8_t)(v >> 56);
    bytes[1] = (uint8_t)(v >> 48);
    bytes[2] = (uint8_t)(v >> 40);
    bytes[3] = (uint8_t)(v >> 32);
    bytes[4] = (uint8_t)(v >> 24);
    bytes[5] = (uint8_t)(v >> 16);
    bytes[6] = (uint8_t)(v >> 8);
    bytes[7] = (uint8_t)(v & 0xffu);
}
// clang-format on

#if defined(CRPT_SYS_VMS) && __INITIAL_POINTER_SIZE == 64
typedef uint64_t crpt_ptrdiff_t;
#else
typedef size_t crpt_ptrdiff_t;
#endif

#endif
