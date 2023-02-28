/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: constant time operations
 * Author: zhanxin
 * Create: Web Aug 20 11:54:00 2020
 */

#ifndef CRYPTO_HEADER_CONSTANT_TIME_H
#define CRYPTO_HEADER_CONSTANT_TIME_H

#include <hicrypto/target.h>

/* Returns the given value with the MSB copied to all the other bits. */
CRPT_INLINE unsigned int constant_time_msb(unsigned int a)
{
    return 0 - (a >> (sizeof(a) * 8 - 1));
}
CRPT_INLINE size_t constant_time_msb_s(size_t a)
{
    return 0 - (a >> (sizeof(a) * 8 - 1));
}
CRPT_INLINE uint32_t constant_time_msb_32(uint32_t a)
{
    return 0 - (a >> 31);
}
CRPT_INLINE uint64_t constant_time_msb_64(uint64_t a)
{
    return 0 - (a >> 63);
}
CRPT_INLINE crpt_word_t constant_time_msb_w(crpt_word_t a)
{
    return 0u - (a >> (sizeof(a) * 8 - 1));
}


/* Returns 0xff..f if a < b and 0 otherwise. */
CRPT_INLINE unsigned int constant_time_lt(unsigned int a, unsigned int b)
{
    return constant_time_msb(a ^ ((a ^ b) | ((a - b) ^ b)));
}
CRPT_INLINE size_t constant_time_lt_s(size_t a, size_t b)
{
    return constant_time_msb_s(a ^ ((a ^ b) | ((a - b) ^ b)));
}
CRPT_INLINE uint32_t constant_time_lt_32(uint32_t a, uint32_t b)
{
    return constant_time_msb_32(a ^ ((a ^ b) | ((a - b) ^ b)));
}
CRPT_INLINE uint64_t constant_time_lt_64(uint64_t a, uint64_t b)
{
    return constant_time_msb_64(a ^ ((a ^ b) | ((a - b) ^ b)));
}
/* Convenience method for getting an 8-bit mask. */
CRPT_INLINE unsigned char constant_time_lt_8(unsigned int a, unsigned int b)
{
    return (unsigned char)constant_time_lt(a, b);
}


/* Returns 0xff..f if a >= b and 0 otherwise. */
CRPT_INLINE unsigned int constant_time_ge(unsigned int a, unsigned int b)
{
    return ~constant_time_lt(a, b);
}
CRPT_INLINE size_t constant_time_ge_s(size_t a, size_t b)
{
    return ~constant_time_lt_s(a, b);
}
CRPT_INLINE uint32_t constant_time_ge_32(uint32_t a, uint32_t b)
{
    return ~constant_time_lt_32(a, b);
}
CRPT_INLINE uint64_t constant_time_ge_64(uint64_t a, uint64_t b)
{
    return ~constant_time_lt_64(a, b);
}
/* Convenience method for getting an 8-bit mask. */
CRPT_INLINE unsigned char constant_time_ge_8(unsigned int a, unsigned int b)
{
    return (unsigned char)constant_time_ge(a, b);
}
CRPT_INLINE unsigned char constant_time_ge_8_s(size_t a, size_t b)
{
    return (unsigned char)constant_time_ge_s(a, b);
}


/* Returns 0xff..f if a == 0 and 0 otherwise. */
CRPT_INLINE unsigned int constant_time_is_zero(unsigned int a)
{
    return constant_time_msb(~a & (a - 1));
}
CRPT_INLINE size_t constant_time_is_zero_s(size_t a)
{
    return constant_time_msb_s(~a & (a - 1));
}
CRPT_INLINE uint32_t constant_time_is_zero_32(uint32_t a)
{
    return constant_time_msb_32(~a & (a - 1));
}
CRPT_INLINE uint64_t constant_time_is_zero_64(uint64_t a)
{
    return constant_time_msb_64(~a & (a - 1));
}
CRPT_INLINE crpt_word_t constant_time_is_zero_w(crpt_word_t a)
{
    return constant_time_msb_w(~a & (a - 1));
}
/* Convenience method for getting an 8-bit mask. */
CRPT_INLINE unsigned char constant_time_is_zero_8(unsigned int a)
{
    return (unsigned char)constant_time_is_zero(a);
}


/* Returns 0xff..f if a == b and 0 otherwise. */
CRPT_INLINE unsigned int constant_time_eq(unsigned int a, unsigned int b)
{
    return constant_time_is_zero(a ^ b);
}
CRPT_INLINE size_t constant_time_eq_s(size_t a, size_t b)
{
    return constant_time_is_zero_s(a ^ b);
}
CRPT_INLINE uint32_t constant_time_eq_32(uint32_t a, uint32_t b)
{
    return constant_time_is_zero_32(a ^ b);
}
CRPT_INLINE uint64_t constant_time_eq_64(uint64_t a, uint64_t b)
{
    return constant_time_is_zero_64(a ^ b);
}
CRPT_INLINE crpt_word_t constant_time_eq_w(crpt_word_t a, crpt_word_t b)
{
    return constant_time_is_zero_w(a ^ b);
}
/* Convenience method for getting an 8-bit mask. */
CRPT_INLINE unsigned char constant_time_eq_8(unsigned int a, unsigned int b)
{
    return (unsigned char)constant_time_eq(a, b);
}
CRPT_INLINE unsigned char constant_time_eq_8_s(size_t a, size_t b)
{
    return (unsigned char)constant_time_eq_s(a, b);
}
/* Signed integers. */
CRPT_INLINE unsigned int constant_time_eq_int(int a, int b)
{
    return constant_time_eq((unsigned)(a), (unsigned)(b));
}
/* Convenience method for getting an 8-bit mask. */
CRPT_INLINE unsigned char constant_time_eq_int_8(int a, int b)
{
    return constant_time_eq_8((unsigned)(a), (unsigned)(b));
}

/*
 * Returns the value unmodified, but avoids optimizations.
 * The barriers prevent the compiler from narrowing down the
 * possible value range of the mask and ~mask in the select
 * statements, which avoids the recognition of the select
 * and turning it into a conditional load or branch.
 */
CRPT_INLINE unsigned int value_barrier(unsigned int a)
{
#if !defined(HICRYPTO_NO_ASM) && defined(__GNUC__)
    unsigned int r;
    __asm__("" : "=r"(r) : "0"(a));
#else
    volatile unsigned int r = a;
#endif
    return r;
}
CRPT_INLINE size_t value_barrier_s(size_t a)
{
#if !defined(HICRYPTO_NO_ASM) && defined(__GNUC__)
    size_t r;
    __asm__("" : "=r"(r) : "0"(a));
#else
    volatile size_t r = a;
#endif
    return r;
}
CRPT_INLINE uint32_t value_barrier_32(uint32_t a)
{
#if !defined(HICRYPTO_NO_ASM) && defined(__GNUC__)
    uint32_t r;
    __asm__("" : "=r"(r) : "0"(a));
#else
    volatile uint32_t r = a;
#endif
    return r;
}
CRPT_INLINE uint64_t value_barrier_64(uint64_t a)
{
#if !defined(HICRYPTO_NO_ASM) && defined(__GNUC__)
    uint64_t r;
    __asm__("" : "=r"(r) : "0"(a));
#else
    volatile uint64_t r = a;
#endif
    return r;
}
CRPT_INLINE crpt_word_t value_barrier_w(crpt_word_t a)
{
#if !defined(HICRYPTO_NO_ASM) && (defined(__GNUC__) || defined(__clang__))
    crpt_word_t r;
    __asm__("" : "=r"(r) : "0"(a));
#else
    volatile uint32_t r = a;
#endif
    return r;
}


/*-
 * Returns (mask & a) | (~mask & b).
 *
 * When |mask| is all 1s or all 0s (as returned by the methods above),
 * the select methods return either |a| (if |mask| is nonzero) or |b|
 * (if |mask| is zero).
 */
CRPT_INLINE unsigned int constant_time_select(unsigned int mask, unsigned int a, unsigned int b)
{
    return (value_barrier(mask) & a) | (value_barrier(~mask) & b);
}
CRPT_INLINE size_t constant_time_select_s(size_t mask, size_t a, size_t b)
{
    return (value_barrier_s(mask) & a) | (value_barrier_s(~mask) & b);
}
CRPT_INLINE uint32_t constant_time_select_32(uint32_t mask, uint32_t a, uint32_t b)
{
    return (value_barrier_32(mask) & a) | (value_barrier_32(~mask) & b);
}
CRPT_INLINE uint64_t constant_time_select_64(uint64_t mask, uint64_t a, uint64_t b)
{
    return (value_barrier_64(mask) & a) | (value_barrier_64(~mask) & b);
}
/* Convenience method for unsigned chars. */
CRPT_INLINE unsigned char constant_time_select_8(unsigned char mask, unsigned char a, unsigned char b)
{
    return (unsigned char)constant_time_select(mask, a, b);
}
/* Convenience method for signed integers. */
CRPT_INLINE int constant_time_select_int(unsigned int mask, int a, int b)
{
    return (int)constant_time_select(mask, (unsigned)(a), (unsigned)(b));
}
CRPT_INLINE int constant_time_select_int_s(size_t mask, int a, int b)
{
    return (int)constant_time_select((unsigned)mask, (unsigned)(a), (unsigned)(b));
}
/* Convenience method for crpt_word_t. */
CRPT_INLINE crpt_word_t constant_time_select_w(crpt_word_t mask, crpt_word_t a, crpt_word_t b)
{
    // Clang recognizes this pattern as a select. While it usually transforms it
    // to a cmov, it sometimes further transforms it into a branch, which we do
    // not want.
    //
    // Adding barriers to both |mask| and |~mask| breaks the relationship between
    // the two, which makes the compiler stick with bitmasks.
    return (value_barrier_w(mask) & a) | (value_barrier_w(~mask) & b);
}


/* condtional swap */
CRPT_INLINE void constant_time_cond_swap_32(uint32_t mask, uint32_t *a, uint32_t *b)
{
    CRPT_ASSERT(mask == 0xFFFFFFFF || mask == 0x00000000);
    uint32_t xor_ = *a ^ *b;

    xor_ &= mask;
    *a ^= xor_;
    *b ^= xor_;
}
CRPT_INLINE void constant_time_cond_swap_64(uint64_t mask, uint64_t *a, uint64_t *b)
{
    CRPT_ASSERT(mask == 0xFFFFFFFFFFFFFFFF || mask == 0x0000000000000000);
    uint64_t xor_ = *a ^ *b;

    xor_ &= mask;
    *a ^= xor_;
    *b ^= xor_;
}

#endif
