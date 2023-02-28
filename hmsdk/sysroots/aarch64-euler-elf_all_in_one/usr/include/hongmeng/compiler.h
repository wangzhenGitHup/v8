/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Compiler
 * Author: Huawei OS Kernel Lab
 * Create: Wed Jul 25 12:57:57 2018
 */
#ifndef ULIBS_HONGMENG_COMPILER_H
#define ULIBS_HONGMENG_COMPILER_H

#include <hmkernel/compiler.h>

#define __app

#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

#define likely(x)      (x)
#define unlikely(x)    (x)

#define __raw_static_assert_name_comb(x, y)	x##y
#define raw_static_assert(condition, name) 	\
	extern int __raw_static_assert_name_comb(__STATIC_ASSERT_, name)[1 - 2 * ((condition) ? 0 : 1)]

#ifndef __hmbuild__
/* legacy */
#ifdef CONFIG_AARCH64_SHADOW_STACK_NORM
#define __nosstack	__attribute__((nosstack))
#else
#define __nosstack
#endif

#else

/* morden */
#ifdef __hmfeature_shadowstack__
#define __nosstack	__attribute__((nosstack))
#else
#define __nosstack
#endif

#endif

#endif
