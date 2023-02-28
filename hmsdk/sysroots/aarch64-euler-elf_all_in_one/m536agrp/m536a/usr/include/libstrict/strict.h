/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Helpers for static warnings cleanup
 * Author: Huawei OS Kernel Lab
 * Create: Tue Feb 19 13:58:52 2019
 */
#ifndef ULIBS_LIBSTRICT_STRICT_H
#define ULIBS_LIBSTRICT_STRICT_H

#include <errno.h>
#include <securec.h>
#include <stdbool.h>

#include <hongmeng/panic.h>
#include <hongmeng/types.h>

#ifndef __hmbuild__
# ifdef CONFIG_STRICT_FOR_CODEDEX
#define __HMFEATURE_STRICT__
# else
#define __HMFEATURE_NO_STRICT__
# endif
#endif

#ifdef __HMFEATURE_STRICT__
#define __STRICT_MUST_HOLD(cond, reason) BUG_ON(!(cond))
#define __STRICT_INITED(v, def, reason)	do { (v) = (def); } while (__false)
#define __STRICT_FILLED(ptr, size, reason) do {		\
	void *__ptr = (void *)(ptr);	\
	size_t __size = (size_t)(size);	\
	NOFAIL(memset_s(__ptr, __size, 0, __size)); \
} while (__false)

#else
#define __STRICT_MUST_HOLD(cond, reason) do { } while (__false)
#define __STRICT_INITED(v, def, reason) do { } while (__false)
#define __STRICT_FILLED(ptr, size, reason) do { } while (__false)
#endif

# define __NR_VARS(m, a, b, c, d, e, f, g, h, i, j, k, n, ...) m##n
# define NR_VARS(m, ...)  __NR_VARS(m, __VA_ARGS__, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

# define __UNUSED1(a)  ((void)(a));
# define __UNUSED2(a, ...)  ((void)(a)); __UNUSED1(__VA_ARGS__)
# define __UNUSED3(a, ...)  ((void)(a)); __UNUSED2(__VA_ARGS__)
# define __UNUSED4(a, ...)  ((void)(a)); __UNUSED3(__VA_ARGS__)
# define __UNUSED5(a, ...)  ((void)(a)); __UNUSED4(__VA_ARGS__)
# define __UNUSED6(a, ...)  ((void)(a)); __UNUSED5(__VA_ARGS__)
# define __UNUSED7(a, ...)  ((void)(a)); __UNUSED6(__VA_ARGS__)
# define __UNUSED8(a, ...)  ((void)(a)); __UNUSED7(__VA_ARGS__)
# define __UNUSED9(a, ...)  ((void)(a)); __UNUSED8(__VA_ARGS__)
# define __UNUSED10(a, ...)  ((void)(a)); __UNUSED9(__VA_ARGS__)

# define UNUSED(...)  do { NR_VARS(__UNUSED, __VA_ARGS__)(__VA_ARGS__) } while (__false)

# define __COVERITY_NR_VARS(m, a, b, c, d, e, f, g, h, i, j, k, n, ...) m##n
# define COVERITY_NR_VARS(m, ...)  __COVERITY_NR_VARS(m, __VA_ARGS__, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
static inline void Coverity_Tainted_Set(void *buf)
{
	(void)buf;
}
#define coverity_taint_analysis_param_input1(a) Coverity_Tainted_Set((void *)(a));
#define coverity_taint_analysis_param_input2(a, ...) \
	Coverity_Tainted_Set((void *)(a)); coverity_taint_analysis_param_input1(__VA_ARGS__)
#define coverity_taint_analysis_param_input3(a, ...) \
	Coverity_Tainted_Set((void *)(a)); coverity_taint_analysis_param_input2(__VA_ARGS__)
#define coverity_taint_analysis_param_input4(a, ...) \
	Coverity_Tainted_Set((void *)(a)); coverity_taint_analysis_param_input3(__VA_ARGS__)
#define coverity_taint_analysis_param_input5(a, ...) \
	Coverity_Tainted_Set((void *)(a)); coverity_taint_analysis_param_input4(__VA_ARGS__)
#define coverity_taint_analysis_param_input6(a, ...) \
	Coverity_Tainted_Set((void *)(a)); coverity_taint_analysis_param_input5(__VA_ARGS__)
#define coverity_taint_analysis_param_input7(a, ...) \
	Coverity_Tainted_Set((void *)(a)); coverity_taint_analysis_param_input6(__VA_ARGS__)
#define coverity_taint_analysis_param_input8(a, ...) \
	Coverity_Tainted_Set((void *)(a)); coverity_taint_analysis_param_input7(__VA_ARGS__)
#define coverity_taint_analysis_param_input9(a, ...) \
	Coverity_Tainted_Set((void *)(a)); coverity_taint_analysis_param_input8(__VA_ARGS__)
#define coverity_taint_analysis_param_input10(a, ...) \
	Coverity_Tainted_Set((void *)(a)); coverity_taint_analysis_param_input9(__VA_ARGS__)

#define coverity_taint_analysis_param_input(...) \
	do { COVERITY_NR_VARS(coverity_taint_analysis_param_input, __VA_ARGS__)(__VA_ARGS__) } while (__false)

/*
 * Simply define coverity_taint_analysis_param_input to
 * #define coverity_taint_analysis_param_input(...)
 */

#define POSTCONDITION(cond, reason) __STRICT_MUST_HOLD(cond, reason)
#define PRECONDITION(cond, reason) __STRICT_MUST_HOLD(cond, reason)
#define IMPOSSIBLE(cond, reason) __STRICT_MUST_HOLD(!(cond), reason)

#define IS_OUTPUT_PARAM(v, def, reason)	__STRICT_INITED(v, def, reason)
#define IS_FILLED(ptr, size, reason) __STRICT_FILLED(ptr, size, reason)

#endif
