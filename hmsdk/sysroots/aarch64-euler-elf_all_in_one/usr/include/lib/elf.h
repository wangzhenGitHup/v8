/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
 * Description: Elf
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jun 14 04:12:13 2018
 */
#ifndef KLIBS_ELF_H
#define KLIBS_ELF_H

#include <hmkernel/types.h>

/* ELF field index in e_indent */
#define EI_MAG0		0	/* magic number 0 */
#define ELFMAG0		0x7FU

#define EI_MAG1		1	/* magic number 1 */
#define ELFMAG1		'E'

#define EI_MAG2		2	/* magic number 2 */
#define ELFMAG2		'L'

#define EI_MAG3		3	/* magic number 3 */
#define ELFMAG3		'F'

#define ELFMAG		"\x7f""ELF"
#define SELFMAG		4UL

#define EI_CLASS	4	/* elf class, 32 or 64 bit */
#define ELFCLASS32	1U
#define ELFCLASS64	2U

#define EI_DATA		5	/* elf endianess */

#define EI_VERSION	6	/* must be EV_CURRENT */

#define EI_OSABI	7	/* target operating system ABI */

#define EI_ABIVERSION	8	/* the ABI version */

#define EI_PAD		9	/* padding bytes */
#define EI_NIDENT	16

#define ELFDATANONE	0
#define ELFDATA2LSB	1
#define ELFDATA2MSB	2

/* ELF type */
#define ET_NONE		0
#define ET_REL		1
#define ET_EXEC		2
#define ET_DYN		3
#define ET_CORE		4
#define ET_NUM		5	/* number of defined types */
#define ET_LOPROC	0xff00
#define ET_HIPROC	0xffff

/* ELF Machine types: (EM_*) */
#define EM_NONE		0
#define EM_ARM		40
#define EM_AARCH64	183

/* ELF file format version numbers */
#define	EV_NONE		0	/* invalid elf version */
#define	EV_CURRENT	1	/* original and current version of elf */
#define EV_NUM		2	/* number of defiend version number */

/* PHDR type */
#define PT_LOAD		1U
#define PT_DYNAMIC	2U
#define PT_PHDR		6U	/* segment containing PHDR itself */

/* dynamic entry type */
#define DT_RELA		7
#define DT_RELASZ	8
#define DT_REL		17
#define DT_RELSZ	18
#define DT_RELACOUNT	0x6ffffff9
#define DT_RELCOUNT	0x6ffffffa

/* AArch64 relocs */
#define R_AARCH64_NONE		0U
#define R_AARCH64_RELATIVE	1027U

/* ARM relocs */
#define R_ARM_NONE	0U
#define R_ARM_RELATIVE	23U

#define PF_R		0x4U
#define PF_W		0x2U
#define PF_X		0x1U

/* elf64 */
typedef u64	__Elf64_Addr;	/* Program address */
typedef u8	__Elf64_Byte;	/* Unsigned tiny integer */
typedef u16	__Elf64_Half;	/* Unsigned medium integer */
typedef u64	__Elf64_Off;	/* File offset */
typedef u16	__Elf64_Section;	/* Section index */
typedef s32	__Elf64_Sword;	/* Signed integer */
typedef u32	__Elf64_Word;	/* Unsigned integer */
typedef u64	__Elf64_Lword;	/* Unsigned long integer */
typedef u64	__Elf64_Xword;	/* Unsigned long integer */
typedef s64	__Elf64_Sxword;	/* Signed long integer */

/* 64 bit EHDR */
struct elf64_hdr {
	unsigned char	e_ident[EI_NIDENT];	/* ELF identification */
	__Elf64_Half	e_type;			/* Object file type (ET_*) */
	__Elf64_Half	e_machine;		/* Machine type (EM_*) */
	__Elf64_Word	e_version;		/* File format version (EV_*) */
	__Elf64_Addr	e_entry;		/* Start address */
	__Elf64_Off 	e_phoff;		/* File offset to the PHDR table */
	__Elf64_Off 	e_shoff;		/* File offset to the SHDR table */
	__Elf64_Word	e_flags;		/* Flags (EF_*) */
	__Elf64_Half	e_ehsize;		/* Elf header size in bytes */
	__Elf64_Half	e_phentsize;		/* PHDR table entry size in bytes */
	__Elf64_Half	e_phnum;		/* Number of PHDR entries */
	__Elf64_Half	e_shentsize;		/* SHDR table entry size in bytes */
	__Elf64_Half	e_shnum;		/* Number of SHDR entries */
	__Elf64_Half	e_shstrndx;		/* Index of section name string table */
};

/* 64 bit PHDR entry */
struct elf64_phdr {
	__Elf64_Word	p_type;		/* Type of segment */
	__Elf64_Word	p_flags;	/* Segment flags */
	__Elf64_Off	p_offset;	/* File offset to segment */
	__Elf64_Addr	p_vaddr;	/* Virtual address in memory */
	__Elf64_Addr	p_paddr;	/* Physical address (if relevant) */
	__Elf64_Xword	p_filesz;	/* Size of segment in file */
	__Elf64_Xword	p_memsz;	/* Size of segment in memory */
	__Elf64_Xword	p_align;	/* Alignment constraints */
};

struct elf64_hdr *elf64_load_check_hdr(void *addr);
struct elf64_phdr *elf64_load_phdrs(const struct elf64_hdr *hdr);

/* elf32 */
typedef u32	__Elf32_Addr;	/* Program address */
typedef u8	__Elf32_Byte;	/* Unsigned tiny integer */
typedef u16	__Elf32_Half;	/* Unsigned medium integer */
typedef u32	__Elf32_Off;	/* File offset */
typedef u16	__Elf32_Section;	/* Section index */
typedef s32	__Elf32_Sword;	/* Signed integer */
typedef u32	__Elf32_Word;	/* Unsigned integer */
typedef u32	__Elf32_Lword;	/* Unsigned long integer */
typedef u32	__Elf32_Xword;	/* Unsigned long integer */
typedef s32	__Elf32_Sxword;	/* Signed long integer */

/* 32 bit EHDR */
struct elf32_hdr {
	unsigned char	e_ident[EI_NIDENT];	/* ELF identification */
	__Elf32_Half	e_type;			/* Object file type (ET_*) */
	__Elf32_Half	e_machine;		/* Machine type (EM_*) */
	__Elf32_Word	e_version;		/* File format version (EV_*) */
	__Elf32_Addr	e_entry;		/* Start address */
	__Elf32_Off	e_phoff;		/* File offset to the PHDR table */
	__Elf32_Off	e_shoff;		/* File offset to the SHDR table */
	__Elf32_Word	e_flags;		/* Flags (EF_*) */
	__Elf32_Half	e_ehsize;		/* Elf header size in bytes */
	__Elf32_Half	e_phentsize;		/* PHDR table entry size in bytes */
	__Elf32_Half	e_phnum;		/* Number of PHDR entries */
	__Elf32_Half	e_shentsize;		/* SHDR table entry size in bytes */
	__Elf32_Half	e_shnum;		/* Number of SHDR entries */
	__Elf32_Half	e_shstrndx;		/* Index of section name string table */
};

/* 32 bit PHDR entry */
struct elf32_phdr {
	__Elf32_Word	p_type;		/* Type of segment */
	__Elf32_Off	p_offset;	/* File offset to segment */
	__Elf32_Addr	p_vaddr;	/* Virtual address in memory */
	__Elf32_Addr	p_paddr;	/* Physical address (if relevant) */
	__Elf32_Xword	p_filesz;	/* Size of segment in file */
	__Elf32_Xword	p_memsz;	/* Size of segment in memory */
	__Elf32_Word	p_flags;	/* Segment flags */
	__Elf32_Xword	p_align;	/* Alignment constraints */
};

struct elf32_hdr *elf32_load_check_hdr(void *addr);
struct elf32_phdr *elf32_load_phdrs(const struct elf32_hdr *hdr);

#endif
