/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Wed Oct 23 14:53:17 2019
 */

#ifndef HM_INCLUDE_HMDSOSYM_H
#define HM_INCLUDE_HMDSOSYM_H

struct dso_sym_entry {
	uint32_t flag; /* Is entry valid or not, 0:invalid, 1:invalid */
	uint32_t elf_type; /* Object file type */
	uint64_t fname; /* Object file name */
	uint64_t base; /* Address of dynamic shared object loaded */
	uint64_t tls_offset; /* Offset from TP of dso's TLS */
	uint64_t symtab_addr; /* Address of symbol section loaded*/
	uint64_t strtab_addr; /* Address of strings section loaded*/
	uint32_t fname_len; /* Length of file name, include last null character*/
	uint32_t base_len; /* Length of dso */
	uint32_t symtab_len; /* Length of symbol section loaded */
	uint32_t strtab_len; /* Length of strings section loaded */
};

#define MEM_SIZE_FOR_DSO_INFO	(3 * 4096)
#define DSO_INFO_MAGIC	"HMDSO"
#define DSO_INFO_MAGIC_LEN	(16)

/* reserve memory for dso info, must align to 4k
 *
 *  ----------------------------------------
 * |  dso_sym_info |  paddings  |  entries  |
 *  ----------------------------------------
 */
struct dso_sym_info {
	char magic[DSO_INFO_MAGIC_LEN]; /* Magic info, default is "HMDSO" */
	uint32_t nr_sym_entry; /* number of available entries  */
	uint32_t nr_valid_entry; /* current number of valid entries */
	uint64_t entry_offset; /* offset of first entry from here */
	char paddings[0]; /* reserve some space */
};

int fill_dso_syminfo(struct dso_sym_entry *sym_entry);
void drop_dso_syminfo(const void *base);

#endif
