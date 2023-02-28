/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: libvsync's ARM32 native support
 * Author: Huawei OS Kernel Lab
 * Create: Sun Jun 07 19:51:20 2020
 */

/* memory order mappings follow the table from this link:
 *   https://www.cl.cam.ac.uk/~pes20/cpp/cpp0xmappings.html
 *
 * Compared against the compiler output of corresponding C11
 * implementations, both v7 and v8.
 */
#ifndef VSYNC_ATOMIC_ARM32_H
#define VSYNC_ATOMIC_ARM32_H
/* clang-format off */

#ifndef VSYNC_UNUSED
# define __NR_VARS(m, a, b, c, d, e, f, g, h, i, j, k, n, ...) m##n
# define NR_VARS(m, ...)  __NR_VARS(m, __VA_ARGS__, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

# define VSYNC_UNUSED1(a)  ((void)(a))
# define VSYNC_UNUSED2(a, ...)  ((void)(a)); VSYNC_UNUSED1(__VA_ARGS__)
# define VSYNC_UNUSED3(a, ...)  ((void)(a)); VSYNC_UNUSED2(__VA_ARGS__)
# define VSYNC_UNUSED4(a, ...)  ((void)(a)); VSYNC_UNUSED3(__VA_ARGS__)
# define VSYNC_UNUSED5(a, ...)  ((void)(a)); VSYNC_UNUSED4(__VA_ARGS__)
# define VSYNC_UNUSED6(a, ...)  ((void)(a)); VSYNC_UNUSED5(__VA_ARGS__)
# define VSYNC_UNUSED7(a, ...)  ((void)(a)); VSYNC_UNUSED6(__VA_ARGS__)
# define VSYNC_UNUSED8(a, ...)  ((void)(a)); VSYNC_UNUSED7(__VA_ARGS__)
# define VSYNC_UNUSED9(a, ...)  ((void)(a)); VSYNC_UNUSED8(__VA_ARGS__)
# define VSYNC_UNUSED10(a, ...)  ((void)(a)); VSYNC_UNUSED9(__VA_ARGS__)

# define VSYNC_UNUSED(...)  do { NR_VARS(VSYNC_UNUSED, __VA_ARGS__)(__VA_ARGS__); } while (0)
#endif

#if defined(CPU_ARMV7)
#define VSYNC_ATOMIC_ARMV7
#elif defined(CPU_ARMV8)
#define VSYNC_ATOMIC_ARMV8
#endif

/* Set default to be armv7 */
#if !defined(VSYNC_ATOMIC_ARMV7) && !defined(VSYNC_ATOMIC_ARMV8)
#define VSYNC_ATOMIC_ARMV7
#endif

#include <vsync/vatomic_types.h>

#define VATOMIC_INIT(v) { .__v = v }

/*******************************************************************************
 * options
 ******************************************************************************/

#ifdef VSYNC_NO_WFE
#define SEV
#define WFE
#else
#define SEV "sev"
#define WFE "wfe"
#endif

/*******************************************************************************
 * memory order mappings
 ******************************************************************************/


#if defined(VSYNC_ATOMIC_ARMV8)
#define map_ld_mo_seq "a"
#define map_ld_mo_acq "a"
#define map_ld_mo_rel "r"
#define map_ld_mo_rlx "r"

#define map_st_mo_seq "l"
#define map_st_mo_acq "r"
#define map_st_mo_rel "l"
#define map_st_mo_rlx "r"
#elif defined(VSYNC_ATOMIC_ARMV7)
#define map_ld_mo_seq "r"
#define map_ld_mo_acq "r"
#define map_ld_mo_rel "r"
#define map_ld_mo_rlx "r"

#define map_st_mo_seq "r"
#define map_st_mo_acq "r"
#define map_st_mo_rel "r"
#define map_st_mo_rlx "r"
#endif

#define __LD(mo) "ld"__ATOMIC_EXPANDER(map_ld_, mo)
#define __ST(mo) "st"__ATOMIC_EXPANDER(map_st_, mo)
#define __LDX(mo) "ld"__ATOMIC_EXPANDER(map_ld_, mo)"ex"
#define __STX(mo) "st"__ATOMIC_EXPANDER(map_st_, mo)"ex"

#define __LDD(mo) "ld"__ATOMIC_EXPANDER(map_ld_, mo)"exd"
#define __STD(mo) "st"__ATOMIC_EXPANDER(map_st_, mo)"exd"
#define __LDXD(mo) "ld"__ATOMIC_EXPANDER(map_ld_, mo)"exd"
#define __STXD(mo) "st"__ATOMIC_EXPANDER(map_st_, mo)"exd"

/*******************************************************************************
 * type mappings
 ******************************************************************************/

/* DEFINE_ATOMIC_FNAME(prefix) results in DEFINE_prefix_TYPE */
#define DEFINE_ATOMIC_FNAME(prefix) \
	__ATOMIC_EXPANDER(DEFINE_, __ATOMIC_EXPANDER(prefix, _TYPE))

/* DEFINE_FUNC_TYPE(name, mo) defines function name for all types */
#define DEFINE_FUNC_TYPE(name, mo)                                            \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomic32, vatomic32_t, vuint32_t, 32)  \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomic64, vatomic64_t, vuint64_t, 64)  \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomicptr, vatomicptr_t, void*, 32)

/* DEFINE_FUNC_INT_TYPE(name, mo) defines function name for all int types */
#define DEFINE_FUNC_INT_TYPE(name, mo)                                        \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomic32, vatomic32_t, vuint32_t, 32)  \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomic64, vatomic64_t, vuint64_t, 64)

/*******************************************************************************
 * ARM32 specific barriers for lda/stl
 ******************************************************************************/

#if defined(VSYNC_ATOMIC_ARMV8)
#define map_barrier_st_pre_mo_seq ""
#define map_barrier_st_pre_mo_acq ""
#define map_barrier_st_pre_mo_rel ""
#define map_barrier_st_pre_mo_rlx ""
#define map_barrier_st_post_mo_seq ""
#define map_barrier_st_post_mo_acq ""
#define map_barrier_st_post_mo_rel ""
#define map_barrier_st_post_mo_rlx ""
#define map_barrier_ld_post_mo_seq ""
#define map_barrier_ld_post_mo_acq ""
#define map_barrier_ld_post_mo_rel ""
#define map_barrier_ld_post_mo_rlx ""
#elif defined(VSYNC_ATOMIC_ARMV7)
#define map_barrier_st_pre_mo_seq "dmb ish"
#define map_barrier_st_pre_mo_acq ""
#define map_barrier_st_pre_mo_rel "dmb ish"
#define map_barrier_st_pre_mo_rlx ""
#define map_barrier_st_post_mo_seq "dmb ish"
#define map_barrier_st_post_mo_acq ""
#define map_barrier_st_post_mo_rel ""
#define map_barrier_st_post_mo_rlx ""
#define map_barrier_ld_post_mo_seq "dmb ish"
#define map_barrier_ld_post_mo_acq "dmb ish"
#define map_barrier_ld_post_mo_rel ""
#define map_barrier_ld_post_mo_rlx ""
#endif

#define __BARRIER_PRE_ST(mo) __ATOMIC_EXPANDER(map_barrier_st_pre_, mo)""
/* ARMv7 does not guarantee a monitor state event to be triggered
 * when a non-exclusive store to the location is issued. According
 * to DDI0406C A3.4.1, this is implementation defined.
 *
 * To ensure WFE can be correctly waken from a state change event,
 * Non-ARMv8 platforms enforce a clrex to reset the monitor state.
 */
#ifdef VSYNC_NO_WFE
#define __BARRIER_POST_ST(mo) __ATOMIC_EXPANDER(map_barrier_st_post_, mo)""
#else
#if defined(VSYNC_ATOMIC_ARMV8)
#define __BARRIER_POST_ST(mo) __ATOMIC_EXPANDER(map_barrier_st_post_, mo)""
#else
#define __BARRIER_POST_ST(mo) __ATOMIC_EXPANDER(map_barrier_st_post_, mo)"\nclrex"
#endif // VSYNC_ATOMIC_ARMV8
#endif // VSYNC_NO_WFE

#define __BARRIER_POST_LD(mo) __ATOMIC_EXPANDER(map_barrier_ld_post_, mo)""


/*******************************************************************************
 * vatomic_fence
 ******************************************************************************/
#if defined(VSYNC_ATOMIC_ARMV8)
#define map_dmb_mo_seq "dmb ish"
#define map_dmb_mo_acq "dmb ishld"
#define map_dmb_mo_rel "dmb ish"
#define map_dmb_mo_rlx RLX_INSTRUCTION
#elif defined(VSYNC_ATOMIC_ARMV7)
#define map_dmb_mo_seq "dmb ish"
#define map_dmb_mo_acq "dmb ish"
#define map_dmb_mo_rel "dmb ish"
#define map_dmb_mo_rlx RLX_INSTRUCTION
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define __compare_eq_64(__v1, __v2) \
	"cmp  %H["__v1"], %H["__v2"]\ncmpeq  %["__v1"], %["__v2"]\n"
#else
#define __compare_eq_64(__v1, __v2) \
	"cmp  %["__v1"], %["__v2"]\ncmpeq %H["__v1"], %H["__v2"]\n"
#endif

/*******************************************************************************
 * vatomic_{read, write, init, xchg, cmpxchg}
 ******************************************************************************/

#define __DEFINE_ATOMIC_READ_TYPE_32(mo, pfx, atyp, vtyp)  \
	static inline vtyp                                 \
	__ATOMIC_ENAME(pfx##_read, mo)(atyp *a)            \
	{                                                  \
		vtyp val;                                  \
		__asm__ volatile(                          \
			__LD(mo)" %[v], %[a]\n"            \
			__BARRIER_POST_LD(mo)"\n"          \
			: [v] "=&r"(val)                   \
			: [a] "Q"(a->__v)                  \
			: "memory"                         \
		);                                         \
		return val;                                \
	}

#define __DEFINE_ATOMIC_READ_TYPE_64(mo, pfx, atyp, vtyp)  \
	static inline vtyp                                 \
	__ATOMIC_ENAME(pfx##_read, mo)(atyp *a)            \
	{                                                  \
		vtyp val;                                  \
		__asm__ volatile(                          \
			__LDD(mo)" %[v], %[a]\n"           \
			__BARRIER_POST_LD(mo)"\n"          \
			: [v] "=&r"(val)                   \
			: [a] "Q"(a->__v)                  \
			: "memory"                         \
		);                                         \
		return val;                                \
	}

#define DEFINE_ATOMIC_READ_TYPE(mo, pfx, atyp, vtyp, T)  \
	__ATOMIC_EXPANDER(__DEFINE_ATOMIC_READ_TYPE_, T)(mo, pfx, atyp, vtyp)
#define DEFINE_ATOMIC_READ(mo) DEFINE_FUNC_TYPE(ATOMIC_READ, mo)

#define __DEFINE_ATOMIC_WRITE_TYPE_32(mo, pfx, atyp, vtyp)  \
	static inline void                                  \
	__ATOMIC_ENAME(pfx##_write, mo)(atyp *a, vtyp v)    \
	{                                                   \
		__asm__ volatile(                           \
			__BARRIER_PRE_ST(mo)"\n"            \
			__ST(mo)" %[v], %[a]\n"             \
			__BARRIER_POST_ST(mo)"\n"           \
			:                                   \
			: [v] "r"(v),                       \
			  [a] "Q"(a->__v)                   \
			: "memory"                          \
		);                                          \
	}

/* According to DDI0406C, a ld*exd is required to indicate an active
 * exclusive access in the local monitor, which ensures the following
 * st*exd to be atomic.
 * As a result, atomic write of double word falls back to xchg. */
#define __DEFINE_ATOMIC_WRITE_TYPE_64(mo, pfx, atyp, vtyp)                  \
	static inline void                                                  \
	__ATOMIC_ENAME(pfx##_write, mo)(atyp *a, vtyp v)                    \
	{                                                                   \
		vtyp old;                                                   \
		vuint32_t tmp;                                              \
		__asm__ volatile(                                           \
			__BARRIER_PRE_ST(mo)"\n"                            \
			"1:"__LDXD(mo)"	%[oldv], %H[oldv], %[a]\n"          \
			__STXD(mo)"	%[tmp], %[newv], %H[newv], %[a]\n"  \
			"cmp %[tmp], #0\n"                                  \
			"bne 1b\n"                                          \
			__BARRIER_POST_ST(mo)"\n"                           \
			: [oldv] "=&r"(old),                                \
			  [tmp] "=&r"(tmp)                                  \
			: [newv]   "r"(v),                                  \
			     [a]   "Q"(a->__v)                              \
			: "memory"                                          \
		);                                                          \
		VSYNC_UNUSED(old);                                                \
	}

#define DEFINE_ATOMIC_WRITE_TYPE(mo, pfx, atyp, vtyp, T)  \
	__ATOMIC_EXPANDER(__DEFINE_ATOMIC_WRITE_TYPE_, T)(mo, pfx, atyp, vtyp)
#define DEFINE_ATOMIC_WRITE(mo) DEFINE_FUNC_TYPE(ATOMIC_WRITE, mo)

#define DEFINE_ATOMIC_INIT()                        \
	static inline void                          \
	vatomic32_init(vatomic32_t *a, vuint32_t v) \
	{                                           \
		vatomic32_write(a, v);              \
	}                                           \
	static inline void                          \
	vatomic64_init(vatomic64_t *a, vuint64_t v) \
	{                                           \
		vatomic64_write(a, v);              \
	}                                           \
	static inline void                          \
	vatomicptr_init(vatomicptr_t *a, void *v)   \
	{                                           \
		vatomicptr_write(a, v);             \
	}

#define __DEFINE_ATOMIC_XCHG_TYPE_32(mo, pfx, atyp, vtyp)         \
	static inline vtyp                                        \
	__ATOMIC_ENAME(pfx##_xchg, mo)(atyp *a, vtyp v)           \
	{                                                         \
		vtyp old;                                         \
		vuint32_t tmp;                                    \
		__asm__ volatile(                                 \
			__BARRIER_PRE_ST(mo)"\n"                  \
			"1:"__LDX(mo)"	%[oldv], %[a]\n"          \
			__STX(mo)"	%[tmp], %[newv], %[a]\n"  \
			"cmp %[tmp], #0\n"                        \
			"bne 1b\n"                                \
			__BARRIER_POST_LD(mo)"\n"                 \
			: [oldv] "=&r"(old),                      \
			   [tmp] "=&r"(tmp)                       \
			: [newv]   "r"(v),                        \
			     [a]   "Q"(a->__v)                    \
			: "memory"                                \
		);                                                \
		return old;                                       \
	}

#define __DEFINE_ATOMIC_XCHG_TYPE_64(mo, pfx, atyp, vtyp)                   \
	static inline vtyp                                                  \
	__ATOMIC_ENAME(pfx##_xchg, mo)(atyp *a, vtyp v)                     \
	{                                                                   \
		vtyp old;                                                   \
		vuint32_t tmp;                                              \
		__asm__ volatile(                                           \
			__BARRIER_PRE_ST(mo)"\n"                            \
			"1:"__LDXD(mo)"	%[oldv], %H[oldv], %[a]\n"          \
			__STXD(mo)"	%[tmp], %[newv], %H[newv], %[a]\n"  \
			"cmp %[tmp], #0\n"                                  \
			"bne 1b\n"                                          \
			__BARRIER_POST_LD(mo)"\n"                           \
			: [oldv] "=&r"(old),                                \
			  [tmp] "=&r"(tmp)                                  \
			: [newv]   "r"(v),                                  \
			     [a]   "Q"(a->__v)                              \
			: "memory"                                          \
		);                                                          \
		return old;                                                 \
	}

#define DEFINE_ATOMIC_XCHG_TYPE(mo, pfx, atyp, vtyp, T)               \
	__ATOMIC_EXPANDER(__DEFINE_ATOMIC_XCHG_TYPE_, T)(mo, pfx, atyp, vtyp)
#define DEFINE_ATOMIC_XCHG(mo) DEFINE_FUNC_TYPE(ATOMIC_XCHG, mo)

#define __DEFINE_ATOMIC_CMPXCHG_TYPE_32(mo, pfx, atyp, vtyp)        \
	static inline vtyp                                          \
	__ATOMIC_ENAME(pfx##_cmpxchg, mo)(atyp *a, vtyp e, vtyp v)  \
	{                                                           \
		vtyp old;                                           \
		vuint32_t tmp;                                      \
		__asm__ volatile(                                   \
			__BARRIER_PRE_ST(mo)"\n"                    \
			"1:"__LDX(mo)"	%[oldv], %[a]\n"            \
			"cmp		%[oldv], %[expv]\n"         \
			"bne	2f\n"                               \
			__STX(mo)"	%[tmp], %[newv], %[a]\n"    \
			"cmp		%[tmp], #0\n"               \
			"bne	1b\n"                               \
			"2:\n"                                      \
			__BARRIER_POST_LD(mo)"\n"                   \
			: [oldv] "=&r"(old),                        \
			   [tmp] "=&r"(tmp)                         \
			: [newv]   "r"(v),                          \
			  [expv]   "r"(e),                          \
			     [a]   "Q"(a->__v)                      \
			: "memory"                                  \
		);                                                  \
		return old;                                         \
	}

#define __DEFINE_ATOMIC_CMPXCHG_TYPE_64(mo, pfx, atyp, vtyp)                \
	static inline vtyp                                                  \
	__ATOMIC_ENAME(pfx##_cmpxchg, mo)(atyp *a, vtyp e, vtyp v)          \
	{                                                                   \
		vtyp old;                                                   \
		vuint32_t tmp;                                              \
		asm volatile(                                               \
			__BARRIER_PRE_ST(mo)"\n"                            \
			"1:"__LDXD(mo)"	%[oldv], %H[oldv], %[a]\n"          \
			__compare_eq_64("oldv", "exp")                      \
			"bne 2f\n"                                          \
			__STXD(mo)"	%[tmp], %[newv], %H[newv], %[a]\n"  \
			"cmp		%[tmp], #0\n"                       \
			"bne 1b\n"                                          \
			"2:"                                                \
			__BARRIER_POST_LD(mo)"\n"                           \
			: [oldv] "=&r"(old),                                \
			  [tmp] "=&r"(tmp)                                  \
			: [newv] "r"(v),                                    \
			  [exp] "r"(e),                                     \
			  [a]    "Q"(a->__v)                                \
			: "memory"                                          \
		);                                                          \
		return old;                                                 \
	}

#define DEFINE_ATOMIC_CMPXCHG_TYPE(mo, pfx, atyp, vtyp, T)            \
	__ATOMIC_EXPANDER(__DEFINE_ATOMIC_CMPXCHG_TYPE_, T)(mo, pfx, atyp, vtyp)
#define DEFINE_ATOMIC_CMPXCHG(mo) DEFINE_FUNC_TYPE(ATOMIC_CMPXCHG, mo)

/*******************************************************************************
 * vatomic_{get_add, add, inc}
 ******************************************************************************/

#define __ATOMIC_OP_MO_32(op1, op2, op3, vtyp, mo)                 \
	__asm__ volatile(                                          \
		__BARRIER_PRE_ST(mo)"\n"                           \
		"1:"__LDX(mo)"	 	%[oldv], %[a]\n"           \
		op1"			%[newv], %[oldv], %[v]\n"  \
		__STX(mo)"	 	%[tmp], %[newv], %[a]\n"   \
		__BARRIER_POST_LD(mo)"\n"                          \
		"cmp		%[tmp], #0\n"                      \
		"bne	1b\n"                                      \
		: [oldv] "=&r"(oldv),                              \
		  [newv] "=&r"(newv),                              \
		   [tmp] "=&r"(tmp)                                \
		:    [v]   "r"(v),                                 \
		     [a]   "Q"(a->__v)                             \
		: "memory"                                         \
	)

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define ____ATOMIC_OP_64(op1, op2, op3)                            \
		op2"			%[newv], %[oldv], %[v]\n"  \
		op3"			%H[newv], %H[oldv], %H[v]\n"
#else
#define ____ATOMIC_OP_64(op1, op2, op3)                               \
		op2"			%H[newv], %H[oldv], %H[v]\n"  \
		op3"			%[newv], %[oldv], %[v]\n"
#endif

#define __ATOMIC_OP_MO_64(op1, op2, op3, vtyp, mo)                          \
	__asm__ volatile(                                                   \
		__BARRIER_PRE_ST(mo)"\n"                                    \
		"1:"__LDXD(mo)"	 	%[oldv], %H[oldv], %[a]\n"          \
		____ATOMIC_OP_64(op1, op2, op3)                             \
		__STXD(mo)"	 	%[tmp], %[newv], %H[newv], %[a]\n"  \
		"cmp		%[tmp], #0\n"                               \
		"bne		1b\n"                                       \
		__BARRIER_POST_LD(mo)"\n"                                   \
		: [oldv] "=&r"(oldv),                                       \
		  [newv] "=&r"(newv),                                       \
		  [tmp] "=&r"(tmp)                                          \
		: [v]   "r"(v),                                             \
		  [a]    "Q"(a->__v)                                        \
		: "memory"                                                  \
	)                                                               \

#define ATOMIC_OP_MO(op1, op2, op3, vtyp, mo, T)  \
	__ATOMIC_EXPANDER(__ATOMIC_OP_MO_, T)(op1, op2, op3, vtyp, mo)

#define DEFINE_ATOMIC_GET_ADD_TYPE(mo, pfx, atyp, vtyp, T)       \
	static inline vtyp                                       \
	__ATOMIC_ENAME(pfx##_get_add, mo)(atyp *a, vtyp v)       \
	{                                                        \
		vtyp oldv; vtyp newv;                            \
		vuint32_t tmp;                                   \
		ATOMIC_OP_MO("add", "adds", "adc", vtyp, mo, T);  \
		VSYNC_UNUSED(newv);                                    \
		return oldv;                                     \
	}
#define DEFINE_ATOMIC_GET_ADD(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_ADD, mo)

#define DEFINE_ATOMIC_ADD_TYPE(mo, pfx, atyp, vtyp, T)           \
	static inline vtyp                                       \
	__ATOMIC_ENAME(pfx##_add, mo)(atyp *a, vtyp v)           \
	{                                                        \
		vtyp oldv; vtyp newv;                            \
		vuint32_t tmp;                                   \
		ATOMIC_OP_MO("add", "adds", "adc", vtyp, mo, T); \
		VSYNC_UNUSED(oldv);                                    \
		return newv;                                     \
	}
#define DEFINE_ATOMIC_ADD(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_ADD, mo)

#define DEFINE_ATOMIC_GET_INC_TYPE(mo, pfx, atyp, vtyp, T)        \
	static inline vtyp                                        \
	__ATOMIC_ENAME(pfx##_get_inc, mo)(atyp *a)                \
	{                                                         \
		return __ATOMIC_ENAME(pfx##_get_add, mo)(a, 1U);  \
	}
#define DEFINE_ATOMIC_GET_INC(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_INC, mo)

#define DEFINE_ATOMIC_INC_TYPE(mo, pfx, atyp, vtyp, T)        \
	static inline vtyp                                    \
	__ATOMIC_ENAME(pfx##_inc, mo)(atyp *a)                \
	{                                                     \
		return __ATOMIC_ENAME(pfx##_add, mo)(a, 1U);  \
	}
#define DEFINE_ATOMIC_INC(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_INC, mo)

/*******************************************************************************
 * vatomic_{get_or, or}
 ******************************************************************************/

#define DEFINE_ATOMIC_GET_OR_TYPE(mo, pfx, atyp, vtyp, T)       \
	static inline vtyp                                      \
	__ATOMIC_ENAME(pfx##_get_or, mo)(atyp *a, vtyp v)       \
	{                                                       \
		vtyp oldv; vtyp newv;                           \
		vuint32_t tmp;                                  \
		ATOMIC_OP_MO("orr", "orr", "orr", vtyp, mo, T); \
		VSYNC_UNUSED(newv);                                   \
		return oldv;                                    \
	}
#define DEFINE_ATOMIC_GET_OR(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_OR, mo)

#define DEFINE_ATOMIC_OR_TYPE(mo, pfx, atyp, vtyp, T)           \
	static inline vtyp                                      \
	__ATOMIC_ENAME(pfx##_or, mo)(atyp *a, vtyp v)           \
	{                                                       \
		vtyp oldv; vtyp newv;                           \
		vuint32_t tmp;                                  \
		ATOMIC_OP_MO("orr", "orr", "orr", vtyp, mo, T); \
		VSYNC_UNUSED(oldv);                                   \
		return newv;                                    \
	}
#define DEFINE_ATOMIC_OR(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_OR, mo)

/*******************************************************************************
 * vatomic_{get_and, and}
 ******************************************************************************/

#define DEFINE_ATOMIC_GET_AND_TYPE(mo, pfx, atyp, vtyp, T)      \
	static inline vtyp                                      \
	__ATOMIC_ENAME(pfx##_get_and, mo)(atyp *a, vtyp v)      \
	{                                                       \
		vtyp oldv; vtyp newv;                           \
		vuint32_t tmp;                                  \
		ATOMIC_OP_MO("and", "and", "and", vtyp, mo, T); \
		VSYNC_UNUSED(newv);                                   \
		return oldv;                                    \
	}
#define DEFINE_ATOMIC_GET_AND(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_AND, mo)

#define DEFINE_ATOMIC_AND_TYPE(mo, pfx, atyp, vtyp, T)          \
	static inline vtyp                                      \
	__ATOMIC_ENAME(pfx##_and, mo)(atyp *a, vtyp v)          \
	{                                                       \
		vtyp oldv; vtyp newv;                           \
		vuint32_t tmp;                                  \
		ATOMIC_OP_MO("and", "and", "and", vtyp, mo, T); \
		VSYNC_UNUSED(oldv);                                   \
		return newv;                                    \
	}
#define DEFINE_ATOMIC_AND(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_AND, mo)

/*******************************************************************************
 * vatomic_{get_sub, sub, dec}
 ******************************************************************************/

#define DEFINE_ATOMIC_GET_SUB_TYPE(mo, pfx, atyp, vtyp, T)       \
	static inline vtyp                                       \
	__ATOMIC_ENAME(pfx##_get_sub, mo)(atyp *a, vtyp v)       \
	{                                                        \
		vtyp oldv; vtyp newv;                            \
		vuint32_t tmp;                                   \
		ATOMIC_OP_MO("sub", "subs", "sbc", vtyp, mo, T); \
		VSYNC_UNUSED(newv);                                    \
		return oldv;                                     \
	}
#define DEFINE_ATOMIC_GET_SUB(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_SUB, mo)


#define DEFINE_ATOMIC_SUB_TYPE(mo, pfx, atyp, vtyp, T)           \
	static inline vtyp                                       \
	__ATOMIC_ENAME(pfx##_sub, mo)(atyp *a, vtyp v)           \
	{                                                        \
		vtyp oldv; vtyp newv;                            \
		vuint32_t tmp;                                   \
		ATOMIC_OP_MO("sub", "subs", "sbc", vtyp, mo, T); \
		VSYNC_UNUSED(oldv);                                    \
		return newv;                                     \
	}
#define DEFINE_ATOMIC_SUB(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_SUB, mo)


#define DEFINE_ATOMIC_GET_DEC_TYPE(mo, pfx, atyp, vtyp, T)        \
	static inline vtyp                                        \
	__ATOMIC_ENAME(pfx##_get_dec, mo)(atyp *a)                \
	{                                                         \
		return __ATOMIC_ENAME(pfx##_get_sub, mo)(a, 1U);  \
	}
#define DEFINE_ATOMIC_GET_DEC(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_DEC, mo)

#define DEFINE_ATOMIC_DEC_TYPE(mo, pfx, atyp, vtyp, T)        \
	static inline vtyp                                    \
	__ATOMIC_ENAME(pfx##_dec, mo)(atyp *a)                \
	{                                                     \
		return __ATOMIC_ENAME(pfx##_sub, mo)(a, 1U);  \
	}
#define DEFINE_ATOMIC_DEC(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_DEC, mo)

/*******************************************************************************
 * vatomic_await functions (binary variants)
 ******************************************************************************/

#define __await_map_b_lt  "blo"
#define __await_map_b_le  "bls"
#define __await_map_b_gt  "bhi"
#define __await_map_b_ge  "bhs"
#define __await_map_b_eq  "beq"
#define __await_map_b_neq "bne"

#define __AWAIT_B_IF(cond) __ATOMIC_EXPANDER(__await_map_b_, cond)

#define __await_map_b_not_lt  "bhs"
#define __await_map_b_not_le  "bhi"
#define __await_map_b_not_gt  "bls"
#define __await_map_b_not_ge  "blo"
#define __await_map_b_not_eq  "bne"
#define __await_map_b_not_neq "beq"

#define __AWAIT_B_IFNOT(cond) __ATOMIC_EXPANDER(__await_map_b_not_, cond)

#ifdef VSYNC_NO_WFE
#define __WFE_IFNOT(cond)
#else
#define __wfe_map_lt  "wfehs"
#define __wfe_map_le  "wfehi"
#define __wfe_map_gt  "wfels"
#define __wfe_map_ge  "wfelo"
#define __wfe_map_eq  "wfene"
#define __wfe_map_neq "wfeeq"
#define __WFE_IFNOT(cond) __ATOMIC_EXPANDER(__wfe_map_, cond)
#endif

#define __DEFINE_ATOMIC_AWAIT_MO_32(cond, mo, pfx, atyp, vtyp)     \
	static inline vtyp                                         \
	__ATOMIC_ENAME(pfx##_await_##cond, mo)(atyp *a, vtyp v)    \
	{                                                          \
		vtyp val;                                          \
		__asm__ volatile(                                  \
			__LD(mo)"	 	%[val], %[a]\n"    \
			"cmp			%[val], %[exp]\n"  \
			__AWAIT_B_IF(cond)" 2f\n"                  \
			"1:"__LDX(mo)"	 	%[val], %[a]\n"    \
			"cmp			%[val], %[exp]\n"  \
			__WFE_IFNOT(cond)"\n"                      \
			__AWAIT_B_IFNOT(cond)" 1b\n"               \
			"clrex\n"                                  \
			"2:\n"                                     \
			__BARRIER_POST_LD(mo)"\n"                  \
			: [val] "=&r"(val)                         \
			: [exp]   "r"(v),                          \
			    [a]   "Q"(a->__v)                      \
			: "memory"                                 \
		);                                                 \
		return val;                                        \
	}

#define __DEFINE_ATOMIC_AWAIT_MO_64(cond, mo, pfx, atyp, vtyp)        \
	static inline vtyp                                            \
	__ATOMIC_ENAME(pfx##_await_##cond, mo)(atyp *a, vtyp v)       \
	{                                                             \
		vtyp val;                                             \
		__asm__ volatile(                                     \
			__LDXD(mo)"	 	%[v], %H[v], %[a]\n"  \
			__compare_eq_64("v", "exp")                   \
			__AWAIT_B_IF(cond)" 2f\n"                     \
			"1:"__LDXD(mo)"	 	%[v], %H[v], %[a]\n"  \
			__compare_eq_64("v", "exp")                   \
			__WFE_IFNOT(cond)"\n"                         \
			__AWAIT_B_IFNOT(cond)" 1b\n"                  \
			"2: clrex\n"                                  \
			__BARRIER_POST_LD(mo)"\n"                     \
			: [v] "=&r"(val)                              \
			: [exp] "r"(v),                               \
			    [a]   "Q"(a->__v)                         \
			: "memory"                                    \
		);                                                    \
		return val;                                           \
	}

#define DEFINE_ATOMIC_AWAIT_MO(cond, mo, pfx, atyp, vtyp, T) \
	__ATOMIC_EXPANDER(__DEFINE_ATOMIC_AWAIT_MO_, T)(cond, mo, pfx, atyp, vtyp)

#define DEFINE_ATOMIC_AWAIT_MO_TYPE(mo, pfx, atyp, vtyp, T)  \
	DEFINE_ATOMIC_AWAIT_MO(lt, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MO(le, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MO(gt, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MO(ge, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MO(eq, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MO(neq, mo, pfx, atyp, vtyp, T)

#define DEFINE_ATOMIC_AWAIT(mo) \
	DEFINE_FUNC_TYPE(ATOMIC_AWAIT_MO, mo)

/*******************************************************************************
 * vatomic_await functions (counter variants)
 ******************************************************************************/
#define __DEFINE_ATOMIC_AWAIT_COUNTER_MO_32(cond, mo, pfx, atyp, vtyp)           \
	static inline vtyp                                                       \
	__ATOMIC_ENAME(pfx##_await_counter_##cond, mo)(atyp *a, vtyp v, vtyp c)  \
	{                                                                        \
		vtyp val;                                                        \
		__asm__ volatile(                                                \
			__LD(mo)"	 	%[val], %[a]\n"                  \
			"cmp			%[val], %[exp]\n"                \
			__AWAIT_B_IF(cond)" 2f\n"                                \
			"1: cmp		%[cnt], #0\n"                            \
			"beq		2f\n"                                    \
			"sub			%[cnt], %[cnt], #1\n"            \
			__LDX(mo)"	 	%[val], %[a]\n"                  \
			"cmp			%[val], %[exp]\n"                \
			__WFE_IFNOT(cond)"\n"                                    \
			__AWAIT_B_IFNOT(cond)" 1b\n"                             \
			"clrex\n"                                                \
			"2:\n"                                                   \
			__BARRIER_POST_LD(mo)"\n"                                \
			: [val] "=&r"(val)                                       \
			: [exp]   "r"(v),                                        \
			  [cnt]   "r"(c),                                        \
			    [a]   "Q"(a->__v)                                    \
			: "memory"                                               \
		);                                                               \
		return val;                                                      \
	}

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define ____ATOMIC_COUNTER_OP_64                                \
		"adds			%[cnt], %[cnt], #-1\n"  \
		"adc			%H[cnt], %H[cnt], #-1\n"
#else
#define ____ATOMIC_COUNTER_OP_64                                  \
		"adds			%H[cnt], %H[cnt], #-1\n"  \
		"adc			%[cnt], %[cnt], #-1\n"
#endif

#define __DEFINE_ATOMIC_AWAIT_COUNTER_MO_64(cond, mo, pfx, atyp, vtyp)           \
	static inline vtyp                                                       \
	__ATOMIC_ENAME(pfx##_await_counter_##cond, mo)(atyp *a, vtyp v, vtyp c)  \
	{                                                                        \
		vtyp val;                                                        \
		__asm__ volatile(                                                \
			__LDXD(mo)"	 	%[val], %H[val], %[a]\n"         \
			__compare_eq_64("val", "exp")                            \
			__AWAIT_B_IF(cond)" 2f\n"                                \
			"1: cmp		%[cnt], #0\n"                            \
			"cmpeq		%H[cnt], #0\n"                           \
			"beq		2f\n"                                    \
			____ATOMIC_COUNTER_OP_64                                 \
			__LDXD(mo)"	 	%[val], %H[val], %[a]\n"         \
			__compare_eq_64("val", "exp")                            \
			__WFE_IFNOT(cond)"\n"                                    \
			__AWAIT_B_IFNOT(cond)" 1b\n"                             \
			"2: clrex\n"                                             \
			__BARRIER_POST_LD(mo)"\n"                                \
			: [val] "=&r"(val)                                       \
			: [exp] "r"(v),                                          \
			  [cnt]   "r"(c),                                        \
			    [a]   "Q"(a->__v)                                    \
			: "memory"                                               \
		);                                                               \
		return val;                                                      \
	}

#define DEFINE_ATOMIC_AWAIT_COUNTER_MO(cond, mo, pfx, atyp, vtyp, T) \
	__ATOMIC_EXPANDER(__DEFINE_ATOMIC_AWAIT_COUNTER_MO_, T)(cond, mo, pfx, atyp, vtyp)

#define DEFINE_ATOMIC_AWAIT_COUNTER_MO_TYPE(mo, pfx, atyp, vtyp, T)  \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(lt, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(le, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(gt, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(ge, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(eq, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(neq, mo, pfx, atyp, vtyp, T)

#define DEFINE_ATOMIC_AWAIT_COUNTER(mo) \
	DEFINE_FUNC_TYPE(ATOMIC_AWAIT_COUNTER_MO, mo)

/*******************************************************************************
 * vatomic_await functions (mask variants)
 ******************************************************************************/
#define __DEFINE_ATOMIC_AWAIT_MASK_MO_32(cond, mo, pfx, atyp, vtyp)              \
	static inline vtyp                                                       \
	__ATOMIC_ENAME(pfx##_await_mask_##cond, mo)(atyp *a, vtyp v, vtyp bitmask)  \
	{                                                                        \
		vtyp val;                                                        \
		vtyp tmp;                                                        \
		__asm__ volatile(                                                \
			__LD(mo)"	 	%[val], %[a]\n"                  \
			"and			%[tmp], %[val], %[bitmask]\n"       \
			"cmp			%[tmp], %[exp]\n"                \
			__AWAIT_B_IF(cond)" 2f\n"                                \
			"1:"__LDX(mo)"	 	%[val], %[a]\n"                  \
			"and			%[tmp], %[val], %[bitmask]\n"       \
			"cmp			%[tmp], %[exp]\n"                \
			__WFE_IFNOT(cond)"\n"                                    \
			__AWAIT_B_IFNOT(cond)" 1b\n"                             \
			"clrex\n"                                                \
			"2:\n"                                                   \
			__BARRIER_POST_LD(mo)"\n"                                \
			: [val] "=&r"(val),                                      \
			  [tmp] "=&r"(tmp)                                       \
			: [exp]   "r"(v),                                        \
			  [bitmask]   "r"(bitmask),                              \
			    [a]   "Q"(a->__v)                                    \
			: "memory"                                               \
		);                                                           \
		return val;                                                  \
	}

#define __DEFINE_ATOMIC_AWAIT_MASK_MO_64(cond, mo, pfx, atyp, vtyp)              \
	static inline vtyp                                                       \
	__ATOMIC_ENAME(pfx##_await_mask_##cond, mo)(atyp *a, vtyp v, vtyp bitmask)  \
	{                                                                        \
		vtyp val;                                                        \
		vtyp tmp;                                                        \
		__asm__ volatile(                                                \
			__LDXD(mo)"		%[val], %H[val], %[a]\n"         \
			"and			%[tmp], %[val], %[bitmask]\n"       \
			"and			%H[tmp], %H[val], %H[bitmask]\n"    \
			__compare_eq_64("tmp", "exp")                            \
			__AWAIT_B_IF(cond)" 2f\n"                                \
			"1:"__LDXD(mo)"	 	%[val], %H[val], %[a]\n"         \
			"and			%[tmp], %[val], %[bitmask]\n"       \
			"and			%H[tmp], %H[val], %H[bitmask]\n"    \
			__compare_eq_64("tmp", "exp")                            \
			__WFE_IFNOT(cond)"\n"                                    \
			__AWAIT_B_IFNOT(cond)" 1b\n"                             \
			"2: clrex\n"                                             \
			__BARRIER_POST_LD(mo)"\n"                                \
			: [val] "=&r"(val),                                      \
			  [tmp] "=&r"(tmp)                                       \
			: [exp] "r"(v),                                          \
			  [bitmask] "r"(bitmask),                                \
			  [a]   "Q"(a->__v)                                      \
			: "memory"                                               \
		);                                                               \
		return val;                                                      \
	}

#define DEFINE_ATOMIC_AWAIT_MASK_MO(cond, mo, pfx, atyp, vtyp, T) \
	__ATOMIC_EXPANDER(__DEFINE_ATOMIC_AWAIT_MASK_MO_, T)(cond, mo, pfx, atyp, vtyp)

#define DEFINE_ATOMIC_AWAIT_MASK_MO_TYPE(mo, pfx, atyp, vtyp, T)  \
	DEFINE_ATOMIC_AWAIT_MASK_MO(lt, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MASK_MO(le, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MASK_MO(gt, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MASK_MO(ge, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MASK_MO(eq, mo, pfx, atyp, vtyp, T)   \
	DEFINE_ATOMIC_AWAIT_MASK_MO(neq, mo, pfx, atyp, vtyp, T)

#define DEFINE_ATOMIC_AWAIT_MASK(mo) \
	DEFINE_FUNC_TYPE(ATOMIC_AWAIT_MASK_MO, mo)

/*******************************************************************************
 * vatomic_await functions (ternary variants)
 ******************************************************************************/

#define __await_map_mo_seq mo_seq
#define __await_map_mo_acq mo_rlx
#define __await_map_mo_rel mo_rlx
#define __await_map_mo_rlx mo_rlx

#define __AWAIT_EMO(mo) __ATOMIC_EXPANDER(__await_map_, mo)

#define __ATOMIC_AWAIT_ENAME(pfx, cond, name, mo) \
	__ATOMIC_ENAME(pfx##_await_##cond##_##name, mo)

#define __await_map_op_32_add "add %[tmpv], %[oldv], %[newv]"
#define __await_map_op_32_sub "sub %[tmpv], %[oldv], %[newv]"
#define __await_map_op_32_set "mov %[tmpv], %[newv]"

#define __AWAIT_OP_32(op) __ATOMIC_EXPANDER(__await_map_op_32_, op)

#define __DEFINE_ATOMIC_AWAIT_COND_OP_MO_32(cond, op, mo, pfx, atyp, vtyp)  \
	static inline vtyp                                                  \
	__ATOMIC_AWAIT_ENAME(pfx, cond, op, mo)(atyp *a, vtyp c, vtyp v)    \
	{                                                                   \
		vtyp old;                                                   \
		vtyp tmpv;                                                  \
		vuint32_t tmp;                                              \
		__asm__ volatile(                                           \
			__BARRIER_PRE_ST(mo)"\n"                            \
			__LDX(mo)"		%[oldv], %[a]\n"            \
			"cmp			%[oldv], %[expv]\n"         \
			__AWAIT_B_IF(cond)" 2f\n"                           \
			"1:"__LDX(mo)"	 	%[oldv], %[a]\n"            \
			"cmp			%[oldv], %[expv]\n"         \
			__WFE_IFNOT(cond)"\n"                               \
			__AWAIT_B_IFNOT(cond)" 1b\n"                        \
			"2:"__AWAIT_OP_32(op)"\n"                           \
			__STX(mo)"	 	%[tmp], %[tmpv], %[a]\n"    \
			"cmp		%[tmp], #0\n"                       \
			"bne		1b\n"                               \
			__BARRIER_POST_LD(mo)"\n"                           \
			: [oldv] "=&r"(old),                                \
			  [newv] "+&r"(v),                                  \
			   [tmp] "=&r"(tmp),                                \
			   [tmpv] "=&r"(tmpv)                               \
			: [expv]   "r"(c),                                  \
			     [a]   "Q"(a->__v)                              \
			: "memory"                                          \
		);                                                          \
		return old;                                                 \
	}

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define __await_map_op_64_add \
		"adds %[tmpv], %[oldv], %[newv]\nadc  %H[tmpv], %H[oldv], %H[newv]"
#define __await_map_op_64_sub \
		"subs %[tmpv], %[oldv], %[newv]\nsbc  %H[tmpv], %H[oldv], %H[newv]"
#else
#define __await_map_op_64_add \
		"adds %H[tmpv], %H[oldv], %H[newv]\nadc  %[tmpv], %[oldv], %[newv]"
#define __await_map_op_64_sub \
		"subs %H[tmpv], %H[oldv], %H[newv]\nsbc  %[tmpv], %[oldv], %[newv]"
#endif

#define __await_map_op_64_set \
		"mov %[tmpv], %[newv]\nmov %H[tmpv], %H[newv]"

#define __AWAIT_OP_64(op) __ATOMIC_EXPANDER(__await_map_op_64_, op)

#define __DEFINE_ATOMIC_AWAIT_COND_OP_MO_64(cond, op, mo, pfx, atyp, vtyp)  \
	static inline vtyp                                                  \
	__ATOMIC_AWAIT_ENAME(pfx, cond, op, mo)(atyp *a, vtyp c, vtyp v)    \
	{                                                                   \
		vtyp old; vtyp tmpv;                                        \
		vuint32_t tmp;                                              \
		__asm__ volatile(                                           \
			__BARRIER_PRE_ST(mo)"\n"                            \
			__LDXD(mo)"	%[oldv], %H[oldv], %[a]\n"          \
			__compare_eq_64("oldv", "expv")                     \
			__AWAIT_B_IF(cond)" 2f\n"                           \
			"1:"__LDXD(mo)"	 	%[oldv], %H[oldv], %[a]\n"  \
			__compare_eq_64("oldv", "expv")                     \
			__WFE_IFNOT(cond)"\n"                               \
			__AWAIT_B_IFNOT(cond)" 1b\n"                        \
			"2:\n"                                              \
			__AWAIT_OP_64(op)"\n"                               \
			__STXD(mo)" 	%[tmp], %[tmpv], %H[tmpv], %[a]\n"  \
			"cmp		%[tmp], #0\n"                       \
			"bne		1b\n"                               \
			__BARRIER_POST_LD(mo)"\n"                           \
			: [oldv] "=&r"(old),                                \
			  [newv] "+&r"(v),                                  \
			   [tmp] "=&r"(tmp),                                \
			   [tmpv] "=&r"(tmpv)                               \
			: [expv] "r"(c),                                    \
			     [a]   "Q"(a->__v)                              \
			: "memory"                                          \
		);                                                          \
		return old;                                                 \
	}

#define DEFINE_ATOMIC_AWAIT_COND_OP_MO(cond, op, mo, pfx, atyp, vtyp, T)  \
	__ATOMIC_EXPANDER(__DEFINE_ATOMIC_AWAIT_COND_OP_MO_, T)(cond, op, mo, pfx, atyp, vtyp)

#define DEFINE_ATOMIC_AWAIT_COND_OP_ALL(op, mo, pfx, atyp, vtyp, T)            \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(lt, op, mo, pfx, atyp, vtyp, T) \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(le, op, mo, pfx, atyp, vtyp, T) \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(gt, op, mo, pfx, atyp, vtyp, T) \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(ge, op, mo, pfx, atyp, vtyp, T) \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(eq, op, mo, pfx, atyp, vtyp, T) \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(neq, op, mo, pfx, atyp, vtyp, T)

#define DEFINE_ATOMIC_AWAIT_COND_OP_MO_ALL_TYPE(mo, pfx, atyp, vtyp, T)  \
	DEFINE_ATOMIC_AWAIT_COND_OP_ALL(add, mo, pfx, atyp, vtyp, T)     \
	DEFINE_ATOMIC_AWAIT_COND_OP_ALL(sub, mo, pfx, atyp, vtyp, T)     \
	DEFINE_ATOMIC_AWAIT_COND_OP_ALL(set, mo, pfx, atyp, vtyp, T)

#define DEFINE_ATOMIC_AWAIT_COND_OP(mo) \
	DEFINE_FUNC_TYPE(ATOMIC_AWAIT_COND_OP_MO_ALL, mo)

#endif
