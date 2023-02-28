/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
 * Description: Compiler
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jun 7 10:56:55 2018
 */
#ifndef UAPI_HMKERNEL_COMPILER_H
#define UAPI_HMKERNEL_COMPILER_H

#include <asm/compiler.h>
#include <hmkernel/attributes/hmattributes.h>
#include <hmkernel/types.h>

/*
 * For __HOST_LLT__: x86 compiler provide __always_inline in
 * /usr/include/x86_64-linux-gnu/sys/cdefs.h
 */
#ifdef __always_inline
# undef __always_inline
#endif

#define __same_type(t1, t2)	(__builtin_types_compatible_p(t1, t2) == 1)
#define __is_signed(t)		(__same_type(t, int) || __same_type(t, long) || \
				 __same_type(t, long long))
#define __is_fixed64(t)		(__same_type(t, unsigned long long) || \
				 __same_type(t, long long))

/* Use __ prefix to avoid polluting namespace */
#define __used		__attribute__((used))
#define __maybe_unused	__attribute__((unused))
#define __visible	__attribute__((externally_visible))
#define __printf(a, b)	__attribute__((format(printf, a, b)))
#define __noreturn	__attribute__((noreturn))
#define __aligned(a)	__attribute__((aligned(a)))
#define __noinline	__attribute__((noinline))
#define __alias(name)	__attribute__((alias(#name)))
#define __pure		__attribute__((pure))

#ifndef __clang__
#define __error(s)	__attribute__((error(s)))
#endif

/* for LLT: /usr/include/x86_64-linux-gnu/sys/cdefs.h gives another __always_inline */
#ifndef __always_inline
# define __always_inline	__attribute__((always_inline))
#endif

#define barrier()	asm volatile ("" ::: "memory")

#ifdef __clang__
#define __no_stack_protector	__attribute__((no_stack_protector))
#else
#define __no_stack_protector	__attribute__((optimize("-fno-stack-protector")))
#endif

#define __likely(x)      (x)
#define __unlikely(x)    (x)

#define __read_once(v)		(*((volatile typeof(v) *) (&(v))))
#define __write_once(x, v)	(*(volatile typeof(x) *) (&(x))) = (typeof(x))(v)

#define KCFI_TAG 0x35c00

#define CERTAIN_NOFAIL(s) do {                 \
	int ___err;                             \
	___err = (s);                           \
	(void)(___err);                         \
	__rawattr_verifier_assert(___err != 0); \
} while (false)

#endif
