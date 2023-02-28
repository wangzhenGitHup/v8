/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: The Patch-Jump utilites
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jun 29 06:23:51 2021
 */
#ifndef KLIBS_PERFRA_PAJU_UTILS_H
#define KLIBS_PERFRA_PAJU_UTILS_H

#include <asm/types.h>
#include <hmkernel/errno.h>

#if defined(CONFIG_BIG_ENDIAN)
#define __PAJU_IS_LE				0
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define __PAJU_IS_LE				1
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define __PAJU_IS_LE				0
#else
#define __PAJU_IS_LE				1
#endif

#ifndef __PAJU_NULL
#ifdef __cplusplus
#define __PAJU_NULL				(0L)
#else
#define __PAJU_NULL				((void *)0)
#endif
#endif

#define __PAJU_VALUE_TRUE			1
#define __PAJU_VALUE_FALSE			0

#define __paju_str_(...) 			#__VA_ARGS__
#define __paju_str(...)				__paju_str_(__VA_ARGS__)

#define __paju_comb_(a, b)			a##b
#define __paju_comb(a, b)			__paju_comb_(a, b)

#define __paju_asm_goto(n...) 			do { asm goto(n); asm(""); } while (0)
#define __paju_asm_volatile(n...)		do { asm (n);  asm(""); } while (0)

#define __paju_str_name_section_name_(section_name)	__paju_str(section_name##_name)
#define __paju_str_name_section_name(section_name)	__paju_str_name_section_name_(section_name)
#define __paju_str_label_section_name_(section_name)	__paju_str(section_name##_label)
#define __paju_str_label_section_name(section_name)	__paju_str_label_section_name_(section_name)
#define __paju_str_object_section_name(section_name)	__paju_str(section_name)

#define __paju_str_label_keeper_name_(section_name)	__paju_str(section_name##_label_keeper)
#define __paju_str_label_keeper_name(section_name)	__paju_str_label_keeper_name_(section_name)

#define __PAJU_BIT32				32
static inline __u32 __paju_mask32(
	__u32 val,
	__u32 bit,
	__u32 shift)
{
	__u32 bit_inrange = bit % __PAJU_BIT32;
	__u32 shift_inrange = shift % __PAJU_BIT32;
	return (val & ((1 << bit_inrange) - 1)) << shift_inrange;
}
#undef __PAJU_BIT32

static inline __u32 __paju_bswap32(
	__u32 val,
	__bool swap)
{
	__u32 tmp = val;
	if (swap) {
		tmp = __builtin_bswap32(val);
	}
	return tmp;
}

#define __PAJU_SECTION_NAME_LIMIT 64

#endif
