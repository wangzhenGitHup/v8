/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2022. All rights reserved.
 * Description: Header file for hmlog common declaration
 * Author: Huawei OS Kernel Lab
 * Create: Tue Feb 08 19:38:44 2022
 */

#ifndef ULIBS_INCLUDE_LIBHMLOG_HMLOG_COMMON_H
#define ULIBS_INCLUDE_LIBHMLOG_HMLOG_COMMON_H

#define DYNLOG_SECTION_NAME	"dynlog"
#define DYNLOG_FREQ_ALWAYS	(-1)
#define DYNLOG_FREQ_NEVER	0
#define DYNLOG_FREQ_DEFAULT	DYNLOG_FREQ_ALWAYS

struct dynlog_elf_entry {
	const char *path;
	const char *format;
	const char *space;
	unsigned int path_size;
	unsigned int format_size;
	unsigned int space_size;
	unsigned int line;
	int freq;
};

#define dynlog_elf_entry_initializer(space_str, fmt) { \
	 .path = __FILE__, \
	 .format = #fmt, \
	 .path_size = (unsigned int)sizeof(__FILE__), \
	 .format_size = (unsigned int)sizeof(#fmt), \
	 .space = space_str, \
	 .space_size = (unsigned int)sizeof(space_str), \
	 .line = __LINE__, \
	 .freq = DYNLOG_FREQ_DEFAULT, \
}

#endif /* !ULIBS_INCLUDE_LIBHMLOG_HMLOG_COMMON_H */
