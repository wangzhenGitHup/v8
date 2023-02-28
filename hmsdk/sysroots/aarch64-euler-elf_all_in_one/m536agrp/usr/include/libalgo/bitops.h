/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Wrappers for builtin bit operations
 * Author: Huawei OS Kernel Lab
 * Create: Fri Mar 05 11:40:46 2021
 */
#ifndef ULIBS_LIBALGO_BITOPS_H
#define ULIBS_LIBALGO_BITOPS_H

#include <stdint.h>

/*
 * count the trailing zeros of the given unsigned long long integer
 *
 * @param val [I] Value to count
 *
 * @return    Count of tail zeros
 *
 * @note      Input 0 is undefined for __builtin_ctzll.
 */
static inline uint32_t bit_ctzll(uint64_t val)
{
	return (val == 0ULL) ? 0U : (uint32_t)__builtin_ctzll(val);
}

/*
 * count the leading zeros of the given unsigned long long integer
 *
 * @param val [I] Value to count
 *
 * @return    Count of leading zeros
 *
 * @note      Input 0 is undefined for __builtin_clzll.
 */
static inline uint32_t bit_clzll(uint64_t val)
{
	return (val == 0ULL) ? 0U : (uint32_t)__builtin_clzll(val);
}

#endif /* ULIBS_LIBALGO_BITOPS_H */
