/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Interface of lookup symbol virtual address
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jan 20 15:43:06 2020
 */

#ifndef ULIBS_INCLUDE_LIBHMELF_VSYMBOL_H
#define ULIBS_INCLUDE_LIBHMELF_VSYMBOL_H

struct vsymbol_info {
	char *fname; /* symbol in which binary file */
	char *sname; /* symbol name */
	unsigned long addr; /* symbol vspace address */
	unsigned long size; /* symbol size in byte */
};

int hm_elf_lookup_vsymbol_by_name(const char *filename, const char *name,
				  struct vsymbol_info *info);
int hm_elf_lookup_vsymbol_by_addr(const char *filename, unsigned long addr,
				  struct vsymbol_info *info);
void hm_elf_release_vsymbol_info(struct vsymbol_info *info);

#endif
