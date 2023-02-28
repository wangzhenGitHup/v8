/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: The Patch-Jump infrastructure
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jun 29 06:23:51 2021
 */
#ifndef KLIBS_PERFRA_PAJU_ARM_H
#define KLIBS_PERFRA_PAJU_ARM_H

#include <lib/perfra/paju_utils.h>

/* arm nop */
#define __paju_arm_asm_nop(label_succ) 		"nop"
#define __PAJU_ARM_ASM_PTR_SIZE			4

#define __PAJU_ARM_INSN_SIZE			4

#define __PAJU_ARM_JUMP_IMM_BIT_NR		24
#define __PAJU_ARM_JUMP_OPCODE			0xa
#define __PAJU_ARM_JUMP_OPCODE_BIT_NR		4
#define __PAJU_ARM_JUMP_COND			0xe
#define __PAJU_ARM_JUMP_COND_BIT_NR		4
#define __PAJU_ARM_JUMP_OFFSET			2

#define __PAJU_ARM_JUMP_IMM_RANGE		((__s64)(1 << (__PAJU_ARM_JUMP_IMM_BIT_NR - 1)))
#define __PAJU_ARM_JUMP_IMM_MIN			((__s64)(-__PAJU_ARM_JUMP_IMM_RANGE * __PAJU_ARM_INSN_SIZE))
#define __PAJU_ARM_JUMP_IMM_MAX			((__s64)(__PAJU_ARM_JUMP_IMM_RANGE * __PAJU_ARM_INSN_SIZE))
static inline __bool __paju_arm_check_buf(
	const void *buf,
	__u64 bufsize)
{
	return (buf != __PAJU_NULL) && (bufsize >= __PAJU_ARM_INSN_SIZE);
}

static inline __bool __paju_arm_check_jump(
	__s64 diff)
{
	return (diff >= __PAJU_ARM_JUMP_IMM_MIN) && (diff < __PAJU_ARM_JUMP_IMM_MAX);
}

static inline void __paju_arm_create_jump_imm(
	void *buf,
	__u32 imm,
	__bool is_le)
{
	__u32 insn_jump = 0;
	insn_jump |= __paju_mask32(imm, __PAJU_ARM_JUMP_IMM_BIT_NR, 0);
	insn_jump |= __paju_mask32(__PAJU_ARM_JUMP_OPCODE, __PAJU_ARM_JUMP_OPCODE_BIT_NR,
				   __PAJU_ARM_JUMP_IMM_BIT_NR);
	insn_jump |= __paju_mask32(__PAJU_ARM_JUMP_COND, __PAJU_ARM_JUMP_COND_BIT_NR,
				   __PAJU_ARM_JUMP_IMM_BIT_NR + __PAJU_ARM_JUMP_OPCODE_BIT_NR);
	*(__u32 *)buf = __paju_bswap32(insn_jump, !is_le);
}

static inline int __paju_arm_create_jump(
	void *buf,
	__u64 bufsize,
	__u64 dst,
	__u64 src,
	__bool is_le)
{
	int err = E_HM_INVAL;
	__s64 diff = (__s64)(dst - src) - __PAJU_ARM_JUMP_OFFSET * __PAJU_ARM_INSN_SIZE;
	if (__paju_arm_check_buf(buf, bufsize) && (__paju_arm_check_jump(diff))) {
		__paju_arm_create_jump_imm(buf, (__u32)((__s32)diff / __PAJU_ARM_INSN_SIZE), is_le);
		err = E_HM_OK;
	}
	return err;
}

#undef __PAJU_ARM_JUMP_IMM_BIT_NR
#undef __PAJU_ARM_JUMP_OPCODE
#undef __PAJU_ARM_JUMP_OPCODE_BIT_NR
#undef __PAJU_ARM_JUMP_COND
#undef __PAJU_ARM_JUMP_COND_BIT_NR
#undef __PAJU_ARM_JUMP_OFFSET

#undef __PAJU_ARM_JUMP_IMM_RANGE
#undef __PAJU_ARM_JUMP_IMM_MIN
#undef __PAJU_ARM_JUMP_IMM_MAX

#define __PAJU_ARM_NOP_OPCODE			0xe1a00000
static inline int __paju_arm_create_nop(
	void *buf,
	__u64 size)
{
	int err = E_HM_INVAL;
	if (__paju_arm_check_buf(buf, size)) {
		*(__u32 *)buf = __PAJU_ARM_NOP_OPCODE;
		err = E_HM_OK;
	}
	return err;
}
#undef __PAJU_ARM_NOP_OPCODE

#ifdef __arm__

/* The paju data structure of assembly code is similar. However, since they are separately developped, we don't forcely
 * extract a common pattern, so that modifying each one will not affect the other. */
#define __paju_arm_asm_label_keeper_data(section_name) \
	"\n" __paju_str_label_keeper_name(section_name) ": " \
	"\n\t.4byte __start_" __paju_str_label_section_name(section_name) "," \
	          " __stop_" __paju_str_label_section_name(section_name) "," \
		  __paju_str_label_keeper_name(section_name) "_stop_name-" \
		  __paju_str_label_keeper_name(section_name) "_start_name" \
	"\n" __paju_str_label_keeper_name(section_name) "_start_name: " \
	"\n\t.string \"" __paju_str(section_name) "\"" \
	"\n" __paju_str_label_keeper_name(section_name) "_stop_name: "
#define __paju_arm_asm_label_keeper(section_name) \
	"\n\t.ifndef " __paju_str_label_keeper_name(section_name) \
	"\n\t.weak " __paju_str_label_keeper_name(section_name) \
	"\n\t.pushsection paju_keeper,\"awM\",%progbits,1" \
	"\n\t.type " __paju_str_label_keeper_name(section_name) ", %object" \
	__paju_arm_asm_label_keeper_data(section_name) \
	"\n\t.size " __paju_str_label_keeper_name(section_name) ", .-" __paju_str_label_keeper_name(section_name) \
	"\n\t.popsection" \
	"\n\t.endif"

#define __paju_arm_asm_name_section(jumpid, section_name) \
	"\n1:" \
	"\n\t.pushsection " __paju_str_name_section_name(section_name) ",\"awM\",%progbits,1" \
	"\n\t.p2align 3" \
	"\n4:" \
	"\n\t.string \"" __paju_str(jumpid) "\"" \
	"\n\t.popsection"
#define __paju_arm_asm_object_section(jumpid, section_name) \
	"\n\t.pushsection " __paju_str_object_section_name(section_name) ",\"awM\",%progbits,1" \
	"\n\t.p2align 3" \
	"\n5:" \
	"\n\t.4byte 4b, 6f" \
	"\n\t.popsection"
#define __paju_arm_asm_label_declare(jumpid, section_name) \
	"\n\t.pushsection " __paju_str_label_section_name(section_name) ",\"awM\",%progbits,1" \
	"\n\t.previous"
#define __paju_arm_asm_label_section(dst) \
	"\n2:" \
	"\n\tnop" \
	"\n\t.previous" \
	"\n\t.p2align 3" \
	"\n6:" \
	"\n\t.4byte 2b, %l[" __paju_str(dst) "]" \
	"\n\t.popsection"

#ifndef __clang__
__attribute__((always_inline)) static inline
__bool __paju_arm_value_true(void)
{
	__paju_asm_goto(__paju_arm_asm_label_section(dst) :::: dst);
	__bool ret = __PAJU_VALUE_TRUE;
	for (;;) {
		break;
dst:		ret = __PAJU_VALUE_FALSE;
		break;
	}
	return ret;
}
#define __paju_arm_true(jumpid, section_name) ({ \
		__paju_asm_volatile( \
			__paju_arm_asm_label_keeper(section_name) \
			__paju_arm_asm_name_section(jumpid, section_name) \
			__paju_arm_asm_object_section(jumpid, section_name) \
			__paju_arm_asm_label_declare(jumpid, section_name)); \
		__paju_asm_volatile("" ::: "memory"); \
		__paju_arm_value_true(); \
	})
#else
#define __paju_arm_true(jumpid, section_name) __PAJU_VALUE_TRUE
#endif

#define __paju_arch_true(jumpid, section_name)	__paju_arm_true(jumpid, section_name)

static inline int __arch_paju_create_jump(
	void *buf,
	__u64 bufsize,
	__u64 dst,
	__u64 src,
	__bool is_le)
{
	return __paju_arm_create_jump(buf, bufsize, dst, src, is_le);
}

static inline int __arch_paju_create_nop(
	void *buf,
	__u64 bufsize)
{
	return __paju_arm_create_nop(buf, bufsize);
}

#endif

#endif
