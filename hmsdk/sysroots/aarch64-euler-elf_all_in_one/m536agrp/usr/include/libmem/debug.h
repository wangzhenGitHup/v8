/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Mem debug function declaration
 * Author: Huawei OS Kernel Lab
 * Create: Sat Feb 22 17:09:21 2020
 */
#ifndef ULIBS_INCLUDE_LIBMEM_DEBUG_H
#define ULIBS_INCLUDE_LIBMEM_DEBUG_H

#include <stdio.h>
#include <libhmlog/hmlog.h>

#ifndef __hmbuild__
# ifdef CONFIG_DEBUG_BUILD
#  define __hmfeature_debug__
# else
#  define __hmfeature_no_debug__
# endif
#endif

void mem_debug_switch_open(void);
void mem_debug_switch_close(void);

bool fetch_debug_switch(void);

#ifdef __hmfeature_debug__
#define hmmem_debug(fmt...) \
	do { \
		if (fetch_debug_switch()) { \
			__hmlog_printf(HMLOG_DEBUG, __FILE__, __func__, __LINE__, fmt); \
		} \
	} while (1 != 1)
#else
#define hmmem_debug(fmt...) \
	do { \
		if (fetch_debug_switch()) { \
			__no_hmlog(fmt); \
		} \
	} while (1 != 1)
#endif

#define hmmem_info(fmt...) \
	do { \
		if (fetch_debug_switch()) { \
			__hmlog_printf(HMLOG_INFO, __FILE__, __func__, __LINE__, fmt); \
		} \
	} while (1 != 1)

#endif
