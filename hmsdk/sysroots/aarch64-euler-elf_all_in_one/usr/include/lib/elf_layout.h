/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Provide ASLR interfaces of sysmgr
 * Author: Huawei OS Kernel Lab
 * Create: Wed Oct 16 19:32:26 2019
 */
#ifndef KLIBS_ELFLOADER_ELF_LAYOUT_H
#define KLIBS_ELFLOADER_ELF_LAYOUT_H

#include <lib/vspace_layout.h>
#include <hmkernel/const.h>
#include <hmkernel/boot/sysproc.h>
#include <elfloader/binfmt.h>

#define PROC_STACK_SHIFT_PERCPU			12
#define PROC_DEFAULT_STACK_SIZE			0U
#define PROC_DEFAULT_HEAP_SIZE			0U
/* To support up to CONFIG_NR_CPUS, the stack size must be enough */
#define PROC_IDLE_STACK_SIZE			(UL(CONFIG_NR_CPUS) << PROC_STACK_SHIFT_PERCPU)

#define PROC_SYS_STACK_SIZE 			UL(CONFIG_SYSMGR_LAYOUT_STACK_SIZE)
#define PROC_SYS_HEAP_SIZE			UL(CONFIG_SYSMGR_LAYOUT_HEAP_SIZE)
#define PROC_RESERVED_BASE			UL(CONFIG_SYSMGR_LAYOUT_RESERVED_BASE)
#define PROC_EXEC_LOADOFFSET			UL(CONFIG_SYSMGR_LAYOUT_EXEC_LOAD_BASE)

#define ASLR_RND_BITS_DYN			0U
#define ASLR_RND_BITS_LOAD			U(CONFIG_ASLR_SYSMGR_RND_BITS_LOAD)
#define ASLR_RND_BITS_HEAP			0U
#define ASLR_RND_BITS_STACK			U(CONFIG_ASLR_SYSMGR_RND_BITS_STACK)
#define ASLR_RND_BITS_MMAP			U(CONFIG_ASLR_SYSMGR_RND_BITS_MMAP)
#define ASLR_RND_BITS_ARGV			0U

#ifdef CONFIG_SYSMGR_ADDRESS_SPACE_LAYOUT_RANDOMIZATION
static const u8 rnd_bits[ASLR_OFFSET_NR] = {
	(u8)ASLR_RND_BITS_DYN,
	(u8)ASLR_RND_BITS_LOAD,
	(u8)ASLR_RND_BITS_HEAP,
	(u8)ASLR_RND_BITS_STACK,
	(u8)ASLR_RND_BITS_MMAP,
	(u8)ASLR_RND_BITS_ARGV,
};

#endif
/* use to distinguish sysmgr and idle */
enum elf_type {
	ELF_TYPE_SYSMGR,
	ELF_TYPE_IDLE,
};

void elf_layout_setup(struct vspace_layout *layout, enum elf_type type,
		      const struct elfloader_binfmt_output_elf *elf, uptr_t *pload_offset);

void elf_layout_fill_param(struct sysproc_mem_s *layout, uptr_t load_offset);
#endif
