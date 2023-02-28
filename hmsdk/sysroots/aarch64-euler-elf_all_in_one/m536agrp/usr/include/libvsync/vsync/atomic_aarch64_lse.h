/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: libvsync's ARM64v8.1 LSE native support
 * Author: Huawei Dresden Research Center
 * Create: Thu 16 Apr 2020
 */

/* memory order mappings follow the table from this link:
 *	https://www.cl.cam.ac.uk/~pes20/cpp/cpp0xmappings.html
 *	ARM64v8.1 LSE support
 *		We currently support the following instructions from the LSE:
 *			cas(a/al/l),
 *			swp(a/al/l),
 *			ldadd(a/al/l),
 *			ldclr(a/al/l),
 *			ldset(a/al/l),
 */
#ifndef VSYNC_ATOMIC_AARCH64_LSE_H
#define VSYNC_ATOMIC_AARCH64_LSE_H
/* clang-format off */

#include <vsync/vatomic_types.h>

#define VATOMIC_INIT(v) { .__v = v }

/*******************************************************************************
 * options
 ******************************************************************************/

#if defined(VSYNC_DISABLE_POLITE_AWAIT) || defined(VSYNC_NO_WFE)
#define SEVL
#define WFE
#else
#define SEVL "sevl"
#define WFE  "wfe"
#endif

/*******************************************************************************
 * memory order mappings
 ******************************************************************************/

#define map_ld_mo_seq "a"
#define map_ld_mo_acq "a"
#define map_ld_mo_rel
#define map_ld_mo_rlx

#define map_st_mo_seq "l"
#define map_st_mo_acq
#define map_st_mo_rel "l"
#define map_st_mo_rlx

/* valid for cas, swp, ldadd, ldclr, ldset */
#define map_lse_mo_seq "al"
#define map_lse_mo_acq "a"
#define map_lse_mo_rel "l"
#define map_lse_mo_rlx


#define __LD(mo) "ld"__ATOMIC_EXPANDER(map_ld_, mo)"r"
#define __ST(mo) "st"__ATOMIC_EXPANDER(map_st_, mo)"r"
#define __LDX(mo) "ld"__ATOMIC_EXPANDER(map_ld_, mo)"xr"
#define __STX(mo) "st"__ATOMIC_EXPANDER(map_st_, mo)"xr"

#define __CAS(mo) "cas"__ATOMIC_EXPANDER(map_lse_, mo)""
#define __SWP(mo) "swp"__ATOMIC_EXPANDER(map_lse_, mo)""

/* used for ldadd, ldclr (bitwise and), ldset (bitwise store) */
#define __LSE_LD(op, mo) "ld"op""__ATOMIC_EXPANDER(map_lse_, mo)""


/*******************************************************************************
 * type mappings
 ******************************************************************************/

/* DEFINE_ATOMIC_FNAME(prefix) results in DEFINE_prefix_TYPE */
#define DEFINE_ATOMIC_FNAME(prefix) \
	__ATOMIC_EXPANDER(DEFINE_, __ATOMIC_EXPANDER(prefix, _TYPE))

/* DEFINE_FUNC_TYPE(name, mo) defines function name for all types */
#define DEFINE_FUNC_TYPE(name, mo)                                            \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomic32, vatomic32_t, vuint32_t, "w") \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomic64, vatomic64_t, vuint64_t, "x") \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomicptr, vatomicptr_t, void*, "x")

/* DEFINE_FUNC_INT_TYPE(name, mo) defines function name for all int types */
#define DEFINE_FUNC_INT_TYPE(name, mo)                                        \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomic32, vatomic32_t, vuint32_t, "w") \
	DEFINE_ATOMIC_FNAME(name)(mo, vatomic64, vatomic64_t, vuint64_t, "x")

/*******************************************************************************
 * vatomic_fence
 ******************************************************************************/
#define map_dmb_mo_seq "dmb ish"
#define map_dmb_mo_acq "dmb ishld"
#define map_dmb_mo_rel "dmb ish"
#define map_dmb_mo_rlx RLX_INSTRUCTION

/*******************************************************************************
 * vatomic_{read, write, init, xchg, cmpxchg}
 ******************************************************************************/

#define DEFINE_ATOMIC_READ_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline vtyp                               \
	__ATOMIC_ENAME(pfx##_read, mo)(atyp *a)          \
	{                                                \
		vtyp val;                                \
		__asm__ volatile(                        \
			__LD(mo)" %"T"[v], %[a]"         \
			: [v] "=&r"(val)                 \
			: [a] "Q"(a->__v)                \
			: "memory"                       \
		);                                       \
		return val;                              \
	}
#define DEFINE_ATOMIC_READ(mo) DEFINE_FUNC_TYPE(ATOMIC_READ, mo)

#define DEFINE_ATOMIC_WRITE_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline void                                \
	__ATOMIC_ENAME(pfx##_write, mo)(atyp *a, vtyp v)  \
	{                                                 \
		__asm__ volatile(                         \
			__ST(mo)" %"T"[v], %[a]"          \
			:                                 \
			: [v] "r"(v),                     \
			  [a] "Q"(a->__v)                 \
			: "memory"                        \
		);                                        \
	}
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

/**
 * LSE supports: SWP (word/double word), SWPB (byte), SWPH (halfword)
 * 32-bit: swp <Ws>, <Wt>, [<Xn|SP>]
 * 64-bit: swp <Xs>, <Xt>, [<Xn|SP>]
 *	<Ws> | <Xs> register to be stored (Rs)
 *	<Wt> | <Xt> register to be loaded (Rt)
 *	<Xn|SP> base register or stack pointer (Rn)
 */
#define DEFINE_ATOMIC_XCHG_TYPE(mo, pfx, atyp, vtyp, T)               \
	static inline vtyp                                            \
	__ATOMIC_ENAME(pfx##_xchg, mo)(atyp *a, vtyp v)               \
	{                                                             \
		vtyp old;                                             \
		__asm__ volatile(                                     \
			""__SWP(mo)" %"T"[newv], %"T"[oldv], %[a]\n"  \
			: [oldv] "=&r"(old)                           \
			: [newv]   "r"(v),                            \
			     [a]   "Q"(a->__v)                        \
			: "memory"                                    \
		);                                                    \
		return old;                                           \
	}
#define DEFINE_ATOMIC_XCHG(mo) DEFINE_FUNC_TYPE(ATOMIC_XCHG, mo)

/**
 * LSE supports: CAS (word/double word), CASB (byte), CASH (halfword),
 *		CASP (Pair of words/double words )
 * 32-bit: cas <Ws>, <Wt>, [<Xn|SP>{,#0}]
 * 64-bit: cas <Xs>, <Xt>, [<Xn|SP>{,#0}]
 *	<Ws> | <Xs> register to be compared and loaded (Rs)
 *	<Wt> | <Xt> register to be conditionally stored (Rt)
 *	<Xn|SP> base register or stack pointer (Rn)
 */
#define DEFINE_ATOMIC_CMPXCHG_TYPE(mo, pfx, atyp, vtyp, T)            \
	static inline vtyp                                            \
	__ATOMIC_ENAME(pfx##_cmpxchg, mo)(atyp *a, vtyp e, vtyp v)    \
	{                                                             \
		__asm__ volatile(                                     \
			""__CAS(mo)" %"T"[oldv], %"T"[newv], %[a]\n"  \
			: [oldv] "+r"(e)                              \
			: [newv]  "r"(v),                             \
			     [a]  "Q"(a->__v)                         \
			: "memory"                                    \
		);                                                    \
		return e;                                             \
	}
#define DEFINE_ATOMIC_CMPXCHG(mo) DEFINE_FUNC_TYPE(ATOMIC_CMPXCHG, mo)

/*******************************************************************************
 * vatomic_{get_add, add, inc}
 ******************************************************************************/
/*
 * the following template is used by ldadd, ldclr & ldset
 */
#define ATOMIC_LSE_OP_MO(op, mo, T)                                \
	__asm__ volatile(                                          \
		__LSE_LD(op, mo)" %"T"[newv], %"T"[oldv], %[a]\n"  \
		: [oldv] "=&r"(oldv)                               \
		: [newv] "r" (v),                                  \
		  [a] "Q"(a->__v)                                  \
		: "memory"                                         \
	)

/**
 * LSE supports: LDADD (word/double word), LDADDB (byte), LDADDH (halfword)
 * 32-bit: ldadd <Ws>, <Wt>, [<Xn|SP>]
 * 64-bit: ldadd <Xs>, <Xt>, [<Xn|SP>]
 *	<Ws> | <Xs> register holding the data value to be operated on with the
 *		memory contents of the memory location (Rs)
 *	<Wt> | <Xt> register to be loaded (Rt)
 *	<Xn|SP> base register or stack pointer (Rn)
 *	oldv = *a
 *	*a = *a + v
 */
#define DEFINE_ATOMIC_GET_ADD_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline vtyp                                  \
	__ATOMIC_ENAME(pfx##_get_add, mo)(atyp *a, vtyp v)  \
	{                                                   \
		vtyp oldv;                                  \
		ATOMIC_LSE_OP_MO("add", mo, T);             \
		return oldv;                                \
	}

#define DEFINE_ATOMIC_GET_ADD(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_ADD, mo)

#define DEFINE_ATOMIC_ADD_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline vtyp                              \
	__ATOMIC_ENAME(pfx##_add, mo)(atyp *a, vtyp v)  \
	{                                               \
		vtyp oldv;                              \
		ATOMIC_LSE_OP_MO("add", mo, T);         \
		return oldv + v;                        \
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
/**
 * LSE supports: LDSET (word/double word), LDSETB (byte), LDSETH (halfword)
 * 32-bit: ldset <Ws>, <Wt>, [<Xn|SP>]
 * 64-bit: ldset <Xs>, <Xt>, [<Xn|SP>]
 *	<Ws> | <Xs> register holding the data value to be operated on with the
 *		memory contents of the memory location (Rs)
 *	<Wt> | <Xt> register to be loaded (Rt)
 *	<Xn|SP> base register or stack pointer (Rn)
 *	oldv = *a
 *	*a = *a | v
 */
#define DEFINE_ATOMIC_GET_OR_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline vtyp                                 \
	__ATOMIC_ENAME(pfx##_get_or, mo)(atyp *a, vtyp v)  \
	{                                                  \
		vtyp oldv;                                 \
		ATOMIC_LSE_OP_MO("set", mo, T);            \
		return oldv;                               \
	}
#define DEFINE_ATOMIC_GET_OR(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_OR, mo)

#define DEFINE_ATOMIC_OR_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline vtyp                             \
	__ATOMIC_ENAME(pfx##_or, mo)(atyp *a, vtyp v)  \
	{                                              \
		vtyp oldv;                             \
		ATOMIC_LSE_OP_MO("set", mo, T);        \
		return oldv | v;                       \
	}
#define DEFINE_ATOMIC_OR(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_OR, mo)

/*******************************************************************************
 * vatomic_{get_and, and}
 ******************************************************************************/
/**
 * LSE supports: LDCLR (word/double word), LDCLRB (byte), LDCLRH (halfword)
 * 32-bit: ldset <Ws>, <Wt>, [<Xn|SP>]
 * 64-bit: ldset <Xs>, <Xt>, [<Xn|SP>]
 *	<Ws> | <Xs> register holding the data value to be operated on with the
 *		memory contents of the memory location (Rs)
 *	<Wt> | <Xt> register to be loaded (Rt)
 *	<Xn|SP> base register or stack pointer (Rn)
 *	oldv = *a
 *	*a = *a & ~v
 */
#define DEFINE_ATOMIC_GET_AND_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline vtyp                                  \
	__ATOMIC_ENAME(pfx##_get_and, mo)(atyp *a, vtyp v)  \
	{                                                   \
		vtyp oldv;                                  \
		v = ~v;                                     \
		ATOMIC_LSE_OP_MO("clr", mo, T);             \
		return oldv;                                \
	}
#define DEFINE_ATOMIC_GET_AND(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_AND, mo)

#define DEFINE_ATOMIC_AND_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline vtyp                              \
	__ATOMIC_ENAME(pfx##_and, mo)(atyp *a, vtyp v)  \
	{                                               \
		vtyp oldv;                              \
		vtyp tmp = v;                           \
		v = ~v;                                 \
		ATOMIC_LSE_OP_MO("clr", mo, T);         \
		return oldv & tmp;                      \
	}
#define DEFINE_ATOMIC_AND(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_AND, mo)

/*******************************************************************************
 * vatomic_{get_sub, sub, dec}
 ******************************************************************************/
// TODO: for sub we need to send -v not v and use add, use the sub instruction!
/**
 * Since LSE does not have an LDSUB instruction we are going to use LDADD
 * instead! But first we need to make v to -v, for that purpose we first
 * do tmp = 0 - v using the sub instruction, we do that on asm-level and
 * not C-level, to avoid an overflow possiblity with an undefined behaviour
 */

#define ATOMIC_LSE_SUB_MO(op, mo, T)                              \
	__asm__ volatile(                                         \
		"sub %"T"[tmp], "T"zr, %"T"[newv]\n"              \
		__LSE_LD(op, mo)" %"T"[tmp], %"T"[oldv], %[a]\n"  \
		: [oldv] "=&r"(oldv),                             \
		  [tmp] "=&r"(tmp)                                \
		: [newv] "r" (v),                                 \
		  [a] "Q"(a->__v)                                 \
		: "memory"                                        \
	)

#define DEFINE_ATOMIC_GET_SUB_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline vtyp                                  \
	__ATOMIC_ENAME(pfx##_get_sub, mo)(atyp *a, vtyp v)  \
	{                                                   \
		vtyp oldv, tmp;                             \
		ATOMIC_LSE_SUB_MO("add", mo, T);            \
		return oldv;                                \
	}
#define DEFINE_ATOMIC_GET_SUB(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_SUB, mo)


#define DEFINE_ATOMIC_SUB_TYPE(mo, pfx, atyp, vtyp, T)  \
	static inline vtyp                              \
	__ATOMIC_ENAME(pfx##_sub, mo)(atyp *a, vtyp v)  \
	{                                               \
		vtyp oldv, tmp;                         \
		ATOMIC_LSE_SUB_MO("add", mo, T);        \
		return oldv - v;                        \
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
#define VSYNC_CODE_ALIGN ".align 5\n"

#define __await_map_b_lt  "b.lo"
#define __await_map_b_le  "b.ls"
#define __await_map_b_gt  "b.hi"
#define __await_map_b_ge  "b.hs"
#define __await_map_b_eq  "b.eq"
#define __await_map_b_neq "b.ne"

#define __AWAIT_B_IF(cond) __ATOMIC_EXPANDER(__await_map_b_, cond)

#define __await_map_b_not_lt  "b.hs"
#define __await_map_b_not_le  "b.hi"
#define __await_map_b_not_gt  "b.ls"
#define __await_map_b_not_ge  "b.lo"
#define __await_map_b_not_eq  "b.ne"
#define __await_map_b_not_neq "b.eq"

#define __AWAIT_B_IFNOT(cond) __ATOMIC_EXPANDER(__await_map_b_not_, cond)

#define DEFINE_ATOMIC_AWAIT_MO(cond, mo, pfx, atyp, vtyp, T)             \
	static inline vtyp                                               \
	__ATOMIC_ENAME(pfx##_await_##cond, mo)(atyp *a, vtyp v)          \
	{                                                                \
		vtyp val;                                                \
		__asm__ volatile(                                        \
			"   prfm pstl1strm, %[a]\n"                       \
			"  "__LD(mo)"	 	%"T"[val], %[a]\n"       \
			"   cmp			%"T"[val], %"T"[exp]\n"  \
			"  "__AWAIT_B_IF(cond)" 2f\n"                    \
		        "  "SEVL "\n"                                    \
			"  "VSYNC_CODE_ALIGN"\n"                         \
			"1:"WFE "\n"                                     \
			"  "__LDX(mo)"	 	%"T"[val], %[a]\n"       \
			"   cmp			%"T"[val], %"T"[exp]\n"  \
			"  "__AWAIT_B_IFNOT(cond)" 1b\n"                 \
			"2:\n"                                           \
			: [val] "=&r"(val)                               \
			: [exp]   "r"(v),                                \
			    [a]   "Q"(a->__v)                            \
			: "memory"                                       \
		);                                                       \
		return val;                                              \
	}

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
#define DEFINE_ATOMIC_AWAIT_COUNTER_MO(cond, mo, pfx, atyp, vtyp, T)		\
	static inline vtyp							\
	__ATOMIC_ENAME(pfx##_await_counter_##cond, mo)(atyp *a, vtyp v, vtyp c) \
	{									\
		vtyp val;							\
		__asm__ volatile(						\
			"   prfm pstl1strm, %[a]\n"				\
			"  "__LD(mo)"	 	%"T"[val], %[a]\n"		\
			"   cmp			%"T"[val], %"T"[exp]\n"		\
			"  "__AWAIT_B_IF(cond)" 2f\n"				\
		        "  "SEVL "\n"						\
			"  "VSYNC_CODE_ALIGN"\n"                                \
			"1:"WFE "\n"						\
			"   cmp			%"T"[cnt], #0\n"		\
			"   b.eq		2f\n"				\
			"   sub			%"T"[cnt], %"T"[cnt], #1\n"	\
			"  "__LDX(mo)"	 	%"T"[val], %[a]\n"		\
			"   cmp			%"T"[val], %"T"[exp]\n"		\
			"  "__AWAIT_B_IFNOT(cond)" 1b\n"			\
			"2:\n"							\
			: [val] "=&r"(val)					\
			: [exp]   "r"(v),					\
			  [cnt]   "r"(c),					\
			    [a]   "Q"(a->__v)					\
			: "memory"						\
		);								\
		return val;							\
	}

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
#define DEFINE_ATOMIC_AWAIT_MASK_MO(cond, mo, pfx, atyp, vtyp, T)			\
	static inline vtyp								\
	__ATOMIC_ENAME(pfx##_await_mask_##cond, mo)(atyp *a, vtyp v, vtyp bitmask)		\
	{										\
		vtyp val; vtyp tmp;                                                     \
		__asm__ volatile(							\
			"   prfm pstl1strm, %[a]\n"				\
			"  "__LD(mo)"	 	%"T"[val], %[a]\n"			\
			"   and			%"T"[tmp], %"T"[val], %"T"[bitmask]\n"	\
			"   cmp			%"T"[tmp], %"T"[exp]\n"			\
			"  "__AWAIT_B_IF(cond)" 2f\n"					\
			"  "SEVL "\n"							\
			"  "VSYNC_CODE_ALIGN"\n"                                        \
			"1:"WFE "\n"							\
			"  "__LDX(mo)"	 	%"T"[val], %[a]\n"			\
			"   and			%"T"[tmp], %"T"[val], %"T"[bitmask]\n"	\
			"   cmp			%"T"[tmp], %"T"[exp]\n"			\
			"  "__AWAIT_B_IFNOT(cond)" 1b\n"				\
			"2:\n"								\
			: [val] "=&r"(val),						\
			  [tmp] "=&r"(tmp)						\
			: [exp]   "r"(v),						\
			  [bitmask]   "r"(bitmask),						\
			    [a]   "Q"(a->__v)						\
			: "memory"							\
		);									\
		return val;								\
	}

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

#define __await_map_op_add(T) "add %"T"[tmpv], %"T"[oldv], %"T"[newv]"
#define __await_map_op_sub(T) "sub %"T"[tmpv], %"T"[oldv], %"T"[newv]"
#define __await_map_op_set(T) "mov %"T"[tmpv], %"T"[newv]"

#define __AWAIT_OP(op, T) __ATOMIC_EXPANDER(__await_map_op_, op)(T)

#define DEFINE_ATOMIC_AWAIT_COND_OP_MO(cond, op, mo, pfx, atyp, vtyp, T)      \
	static inline vtyp                                                    \
	__ATOMIC_AWAIT_ENAME(pfx, cond, op, mo)(atyp *a, vtyp c, vtyp v)      \
	{                                                                     \
		vtyp old; vtyp tmpv;                                          \
		vuint32_t tmp;                                                \
		__asm__ volatile(                                             \
			"   prfm pstl1strm, %[a]\n"                       \
			"  "__LDX(mo)"		%"T"[oldv], %[a]\n"           \
			"   cmp			%"T"[oldv], %"T"[expv]\n"     \
			"  "__AWAIT_B_IF(cond)" 3f\n"                         \
			"  "SEVL "\n"                                         \
			"  "VSYNC_CODE_ALIGN"\n"                              \
			"1:"WFE "\n"                                          \
			"2:"__LDX(mo)"	 	%"T"[oldv], %[a]\n"           \
			"   cmp			%"T"[oldv], %"T"[expv]\n"     \
			"  "__AWAIT_B_IFNOT(cond)" 1b\n"                      \
			"3:"__AWAIT_OP(op, T)"\n"                             \
			"  "__STX(mo)"	 	%w[tmp], %"T"[tmpv], %[a]\n"  \
			"   cbnz 		%w[tmp], 2b\n"                \
			: [oldv] "=&r"(old),                                  \
			  [newv] "+&r"(v),                                    \
			   [tmp] "=&r"(tmp),                                  \
			   [tmpv] "=&r"(tmpv)                                 \
			: [expv]   "r"(c),                                    \
			     [a]   "Q"(a->__v)                                \
			: "memory"                                            \
		);                                                            \
		return old;                                                   \
	}

#define DEFINE_ATOMIC_AWAIT_COND_OP_ALL(op, mo, pfx, atyp, vtyp, T)             \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(lt, op, mo, pfx, atyp, vtyp, T)  \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(le, op, mo, pfx, atyp, vtyp, T)  \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(gt, op, mo, pfx, atyp, vtyp, T)  \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(ge, op, mo, pfx, atyp, vtyp, T)  \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(eq, op, mo, pfx, atyp, vtyp, T)  \
		DEFINE_ATOMIC_AWAIT_COND_OP_MO(neq, op, mo, pfx, atyp, vtyp, T)

#define DEFINE_ATOMIC_AWAIT_COND_OP_MO_ALL_TYPE(mo, pfx, atyp, vtyp, T)  \
	DEFINE_ATOMIC_AWAIT_COND_OP_ALL(add, mo, pfx, atyp, vtyp, T)     \
	DEFINE_ATOMIC_AWAIT_COND_OP_ALL(sub, mo, pfx, atyp, vtyp, T)     \
	DEFINE_ATOMIC_AWAIT_COND_OP_ALL(set, mo, pfx, atyp, vtyp, T)

#define DEFINE_ATOMIC_AWAIT_COND_OP(mo) \
	DEFINE_FUNC_TYPE(ATOMIC_AWAIT_COND_OP_MO_ALL, mo)

#endif
