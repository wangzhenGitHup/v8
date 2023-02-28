/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Provide type declaration of symbol and interfaces of symbol_lookup
 * Author: Huawei OS Kernel Lab
 * Create: Wed 11 Dec 2019 11:41:08 AM CST
 */
#ifndef ULIBS_LIBHMELF_SYMBOL_H
#define ULIBS_LIBHMELF_SYMBOL_H
#include <stdint.h>
#include <stddef.h>

#define SYMBOL_NAME_MAX_LEN		128U
#define UNKNOWN_NAME			"?????"

enum symbol_mode {
	SYMBOL_MODE_32,
	SYMBOL_MODE_64,
};

#define MAIN_ELF_SYMBOL			1U
#define DSO_ELF_SYMBOL			2U

struct symbol_entry {
	const char *fname; /* symbol in which binary file */
	char name[SYMBOL_NAME_MAX_LEN];
	unsigned long offset;
	unsigned long size;
	unsigned long value;
};

struct generic_sym_item {
	unsigned long value;
	unsigned long size;
	unsigned int index;
	unsigned short shndx;
	unsigned char type;
};

enum section_type {
	SECTION_SYMTAB,
	SECTION_STRTAB,
	SECTION_MAX,
};

struct section_mem {
	uintptr_t addr;
	size_t size;
};

struct dso_sym_range {
	unsigned long symtab_addr;
	unsigned long strtab_addr;
	unsigned int symtab_len;
	unsigned int strtab_len;
};

struct symbol_desc {
	const char *fname; /* binary file name */
	unsigned int flags;
	uintptr_t base;
	unsigned int base_len;
	unsigned int elf_type;
	uintptr_t offset;
	unsigned int load_state; /* mark load state */
	struct section_mem secmem[SECTION_MAX];
	struct dso_sym_range dso_sym; /* come from dso symbol info */
	struct symbol_desc *next; /* link all parsed symbol_desc */
	char data[0]; /* put file name content here if needed */
};

int symbol_lookup_by_addr(struct symbol_desc *sym_desc, enum symbol_mode mode,
			  unsigned long addr, struct symbol_entry *entry);
int symbol_lookup_by_name(struct symbol_desc *sym_desc, enum symbol_mode mode,
			  const char *name, struct symbol_entry *entry);
int symbol_lookup_by_name_and_type(struct symbol_desc *sym_desc, enum symbol_mode mode,
				   const char *name, unsigned int type_mask, struct symbol_entry *entry);
#endif
