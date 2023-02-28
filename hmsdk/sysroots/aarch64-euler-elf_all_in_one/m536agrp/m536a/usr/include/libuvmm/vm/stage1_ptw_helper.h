/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Fri Apr 16 20:05:33 2021
 */

#ifndef HM_UVMM_STAGE1_PTW_HELPER_H
#define HM_UVMM_STAGE1_PTW_HELPER_H

#include <stdint.h>
#include <libuvmm/vm.h>

enum mmu_access_type {
	MMU_DATA_LOAD  = 0,
	MMU_DATA_STORE = 1,
	MMU_INST_FETCH = 2
};

/*
 * extract32:
 * @value: the value to extract the bit field from
 * @start: the lowest bit in the bit field (numbered from 0)
 * @length: the length of the bit field
 *
 * Extract from the 32 bit input @value the bit field specified by the
 * @start and @length parameters, and return it. The bit field must
 * lie entirely within the 32 bit word. It is valid to request that
 * all 32 bits are returned (ie @length 32 and @start 0).
 *
 * Returns: the value of the bit field extracted from the input value.
 */
static inline uint32_t extract32(uint32_t value, uint32_t start, uint32_t length)
{
	BUG_ON(length == 0U || start + length > 32U);
	return (value >> start) & (~0U >> (32U - length));
}

/*
 * extract64:
 * @value: the value to extract the bit field from
 * @start: the lowest bit in the bit field (numbered from 0)
 * @length: the length of the bit field
 *
 * Extract from the 64 bit input @value the bit field specified by the
 * @start and @length parameters, and return it. The bit field must
 * lie entirely within the 64 bit word. It is valid to request that
 * all 64 bits are returned (ie @length 64 and @start 0).
 *
 * Returns: the value of the bit field extracted from the input value.
 */
static inline uint64_t extract64(uint64_t value, uint32_t start, uint32_t length)
{
	BUG_ON(length == 0U || start + length > 64U);
	return (value >> start) & (~0ULL >> (64U - length));
}

/**
 *  * sextract64:
 * @value: the value to extract the bit field from
 * @start: the lowest bit in the bit field (numbered from 0)
 * @length: the length of the bit field
 *
 * Extract from the 64 bit input @value the bit field specified by the
 * @start and @length parameters, and return it, sign extended to
 * an int64_t (ie with the most significant bit of the field propagated
 * to all the upper bits of the return value). The bit field must lie
 * entirely within the 64 bit word. It is valid to request that
 * all 64 bits are returned (ie @length 64 and @start 0).
 *
 * Returns: the sign extended value of the bit field extracted from the
 * input value.
 */
static inline uint64_t sextract64(uint64_t _value, uint32_t start, uint32_t length)
{
	uint64_t is_signed;
	uint64_t value = _value;
	BUG_ON(length == 0U || start + length > 64U);

	value = ((value << (64U - (start + length))) >> (64U - length));

	is_signed = (value >> (length - 1U));
	if (is_signed == 0x1ULL) {
		value |= ((~0ULL) << (length - 1U));
	}

	return value;
}

int stage1_ptw(const vcpu_t *vcpu, uint64_t gva, enum mmu_access_type access_type,
		uint64_t *gpa, uint32_t *p_page_size);
#endif
