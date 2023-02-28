/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: The Patch-Jump infrastructure
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jun 29 06:23:51 2021
 */
#ifndef KLIBS_PERFRA_PAJU_H
#define KLIBS_PERFRA_PAJU_H

#include <lib/perfra/paju_arm.h>
#include <lib/perfra/paju_x86_64.h>
#include <lib/perfra/paju_aarch64.h>

/*
 * We use a separated storing method to store patch-jumping:
 * 	* __paju_object_s: the patch jump object, which contains a string pointing to the name
 *	  	and the recorded label. It's supposed to be stored in a separated section
 *		in the elf, and could be separatedly stripped.
 *	* __paju_label_s: the recorded label, which contains the 2 jumping locations.
 *	* a string section: storing the name in __paju_object_s
 */
struct __paju_label_s {
	void *src_location;
	void *dst_location;
};

struct __paju_label32_s {
	__u32 src_location;
	__u32 dst_location;
};

struct __paju_label64_s {
	__u64 src_location;
	__u64 dst_location;
};

struct __paju_object_s {
	const char *name;
	struct __paju_label_s *label;
};

#define __paju_sectioned_true(jumpid, section_name) __paju_arch_true(jumpid, section_name)
#define __paju_true(jumpid) __paju_sectioned_true(jumpid, paju_default_section)

#define paju_true(jumpid)	__paju_true(jumpid)
#define paju_false(jumpid)	(!(paju_true(jumpid)))

#define paju_sec_true(jumpid, section_name) 	__paju_sectioned_true(jumpid, section_name)
#define paju_sec_false(jumpid, section_name) 	(!(__paju_sectioned_true(jumpid, section_name)))

extern struct __paju_label_s 	__start_paju_default_section_label[];
extern struct __paju_label_s 	__stop_paju_default_section_label[];

extern struct __paju_object_s 	__start_paju_default_section[];
extern struct __paju_object_s 	__stop_paju_default_section[];

/*
 * Currently, the reflecting only supports function (tT in link script) for sysmgr. So
 * to support variable reflecting, we have to manually declare the start/stop of paju
 * label section, so that they could be referenced directy in sysmgr.
 */
extern __u8 __start_paju_keeper[];
extern __u8 __stop_paju_keeper[];

enum __paju_arch_e {
	__PAJU_ARM,
	__PAJU_AARCH64,
	__PAJU_X86_64,
	__PAJU_ARCH_MAX,
};
struct __paju_creator_s {
	int (*create_jump)(void *buf, __u64 bufsize, __u64 dst, __u64 src, __bool is_le);
	int (*create_nop)(void *buf, __u64 bufsize);
	unsigned int sizeof_jump;
	unsigned int sizeof_nop;
};

static inline int paju_create_jump(
	void *buf,
	__u64 bufsize,
	__u64 dst,
	__u64 src,
	__bool is_le)
{
	return __arch_paju_create_jump(buf, bufsize, dst, src, is_le);
}

static inline int paju_create_nop(
	void *buf,
	__u64 bufsize)
{
	return __arch_paju_create_nop(buf, bufsize);
}

static inline int paju_switch_jump_in_vspace(
	struct __paju_label_s *paju_label)
{
	void *src = paju_label->src_location;
	void *dst = paju_label->dst_location;
	__u64 insn = *((__u64 *)src);
	int err = paju_create_jump(&insn, sizeof(__u64), (__u64)(__uptr_t)dst, (__u64)(__uptr_t)src, __PAJU_IS_LE);
	if (err == E_HM_OK) {
		*((__u64 *)src) = insn;
	}
	return err;
}

static inline int paju_switch_nop_in_vspace(
	struct __paju_label_s *paju_label)
{
	void *src = paju_label->src_location;
	__u64 insn = *((__u64 *)src);
	int err = paju_create_nop(&insn, sizeof(__u64));
	if (err == E_HM_OK) {
		*((__u64 *)src) = insn;
	}
	return err;
}

/* The in vspace paju selector */
struct __paju_selector_s {
	const char *dso_name;
	const char *section_name;
	unsigned int index;
};

#endif
