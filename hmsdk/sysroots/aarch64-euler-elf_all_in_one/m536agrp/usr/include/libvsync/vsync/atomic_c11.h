/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: the mappings of C/C++11 atomic operations
 * Author: Huawei Dresden Research Center
 * Create: Wed 22 Jan 2020 01:02:31 PM CET
 */
#ifndef VSYNC_ATOMIC_C11_H
#define VSYNC_ATOMIC_C11_H

#include <stdatomic.h>

typedef struct {
	atomic_uint_least32_t __v;
} vatomic32_t;
typedef struct {
	atomic_uint_least64_t __v;
} vatomic64_t;
typedef struct {
	atomic_uintptr_t __v;
} vatomicptr_t;

typedef unsigned long vuintptr_t;

/*******************************************************************************
 * atomic_init
 ******************************************************************************/

#define DEFINE_ATOMIC_INIT()                                                   \
	static inline void vatomic32_init(vatomic32_t *a, vuint32_t v)         \
	{                                                                      \
		a->__v = v;                                                    \
	}                                                                      \
	static inline void vatomic64_init(vatomic64_t *a, vuint64_t v)         \
	{                                                                      \
		a->__v = v;                                                    \
	}                                                                      \
	static inline void vatomicptr_init(vatomicptr_t *a, void *v)           \
	{                                                                      \
		a->__v = (unsigned long)(vuintptr_t)v;                         \
	}

#define VATOMIC_INIT(v)                                                        \
	{                                                                      \
		.__v = v                                                       \
	}

/*******************************************************************************
 * memory order mappings
 ******************************************************************************/

#define map_mo_seq memory_order_seq_cst
#define map_mo_acq memory_order_acquire
#define map_mo_rel memory_order_release
#define map_mo_rlx memory_order_relaxed

/*******************************************************************************
 * type mappings
 ******************************************************************************/

/* __atyp: atomic types */
#define __atyp(p) __ATOMIC_EXPANDER(map_atyp_, p)
#define map_atyp_vatomic32 vatomic32_t
#define map_atyp_vatomic64 vatomic64_t
#define map_atyp_vatomicptr vatomicptr_t

/* __vtyp: argument variable types */
#define __vtyp(p) __ATOMIC_EXPANDER(map_vtyp_, p)
#define map_vtyp_vatomic32 vuint32_t
#define map_vtyp_vatomic64 vuint64_t
#define map_vtyp_vatomicptr void *

/* __utyp: internal map to c11-compatible types */
#define __utyp(p) __ATOMIC_EXPANDER(map_utyp_, p)
#define map_utyp_vatomic32 vuint32_t
#define map_utyp_vatomic64 vuint64_t
#define map_utyp_vatomicptr vuintptr_t

/* DEFINE_ATOMIC_FUNC_NAME(prefix) results in DEFINE_prefix_TYPE */
#define DEFINE_ATOMIC_FUNC_NAME(prefix)                                        \
	__ATOMIC_EXPANDER(DEFINE_, __ATOMIC_EXPANDER(prefix, _TYPE))

/* DEFINE_FUNC_INT_TYPE(name, mo) defines function name for all int types */
#define DEFINE_FUNC_INT_TYPE(name, mo)                                         \
	DEFINE_ATOMIC_FUNC_NAME(name)                                          \
	(mo, vatomic32) DEFINE_ATOMIC_FUNC_NAME(name)(mo, vatomic64)

/* DEFINE_FUNC_PTR_TYPE(name, mo) defines function name for ptr types */
#define DEFINE_FUNC_PTR_TYPE(name, mo)                                         \
	DEFINE_ATOMIC_FUNC_NAME(name)(mo, vatomicptr)

/* DEFINE_FUNC_TYPE(name, mo) defines function name for all types */
#define DEFINE_FUNC_TYPE(name, mo)                                             \
	DEFINE_FUNC_INT_TYPE(name, mo)                                         \
	DEFINE_FUNC_PTR_TYPE(name, mo)

/*******************************************************************************
 * vatomic_fence
 ******************************************************************************/

#define DEFINE_ATOMIC_FENCE_TYPE(mo)                                           \
	static inline void __ATOMIC_ENAME(vatomic_fence, mo)(void)             \
	{                                                                      \
		atomic_thread_fence(__ATOMIC_EMO(mo));                         \
	}
#define DEFINE_ATOMIC_FENCE(mo) DEFINE_ATOMIC_FENCE_TYPE(mo)

/*******************************************************************************
 * vatomic_{read, write, xchg, cmpxchg}
 ******************************************************************************/

#define DEFINE_ATOMIC_READ_TYPE(mo, t)                                         \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_read, mo)(__atyp(t) * a)    \
	{                                                                      \
		return (__vtyp(t))(__utyp(t))atomic_load_explicit(             \
			&a->__v, __ATOMIC_EMO(mo));                            \
	}
#define DEFINE_ATOMIC_READ(mo) DEFINE_FUNC_TYPE(ATOMIC_READ, mo)

#define DEFINE_ATOMIC_WRITE_TYPE(mo, t)                                        \
	static inline void __ATOMIC_ENAME(t##_write, mo)(__atyp(t) * a,        \
							 __vtyp(t) v)          \
	{                                                                      \
		atomic_store_explicit(&a->__v, (__utyp(t))v,                   \
				      __ATOMIC_EMO(mo));                       \
	}
#define DEFINE_ATOMIC_WRITE(mo) DEFINE_FUNC_TYPE(ATOMIC_WRITE, mo)

#define DEFINE_ATOMIC_XCHG_TYPE(mo, t)                                         \
	static inline __vtyp(t)                                                \
		__ATOMIC_ENAME(t##_xchg, mo)(__atyp(t) * a, __vtyp(t) v)       \
	{                                                                      \
		return (__vtyp(t))(__utyp(t))atomic_exchange_explicit(         \
			&a->__v, (__utyp(t))v, __ATOMIC_EMO(mo));              \
	}
#define DEFINE_ATOMIC_XCHG(mo) DEFINE_FUNC_TYPE(ATOMIC_XCHG, mo)

/* compare_exchange has two access modes: success and failure. We preset the
 * failure mode based on the success mode as follows. */
#define __map_fail_mo_seq map_mo_seq
#define __map_fail_mo_acq map_mo_acq
#define __map_fail_mo_rel map_mo_rlx /* release mode failure is invalid */
#define __map_fail_mo_rlx map_mo_rlx
#define __ATOMIC_FMO(mo) __ATOMIC_EXPANDER(__map_fail_, mo)

#define DEFINE_ATOMIC_CMPXCHG_TYPE(mo, t)                                      \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_cmpxchg, mo)(               \
		__atyp(t) * a, __vtyp(t) ev, __vtyp(t) v)                      \
	{                                                                      \
		__utyp(t) euv = (__utyp(t))ev;                                 \
		atomic_compare_exchange_strong_explicit(&a->__v, &euv,         \
							(__utyp(t))v,          \
							__ATOMIC_EMO(mo),      \
							__ATOMIC_FMO(mo));     \
		return (__vtyp(t))(__utyp(t))euv;                              \
	}
#define DEFINE_ATOMIC_CMPXCHG(mo) DEFINE_FUNC_TYPE(ATOMIC_CMPXCHG, mo)

/*******************************************************************************
 * vatomic_{get_and, and}
 ******************************************************************************/

#define DEFINE_ATOMIC_GET_AND_TYPE(mo, t)                                      \
	static inline __vtyp(t)                                                \
		__ATOMIC_ENAME(t##_get_and, mo)(__atyp(t) * a, __vtyp(t) v)    \
	{                                                                      \
		return (__vtyp(t))atomic_fetch_and_explicit(                   \
			&a->__v, (__utyp(t))v, __ATOMIC_EMO(mo));              \
	}
#define DEFINE_ATOMIC_GET_AND(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_AND, mo)

#define DEFINE_ATOMIC_AND_TYPE(mo, t)                                          \
	static inline __vtyp(t)                                                \
		__ATOMIC_ENAME(t##_and, mo)(__atyp(t) * a, __vtyp(t) v)        \
	{                                                                      \
		return (__vtyp(t))__ATOMIC_ENAME(t##_get_and, mo)(a, v) & v;   \
	}
#define DEFINE_ATOMIC_AND(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_AND, mo)

/*******************************************************************************
 * vatomic_{get_or, or}
 ******************************************************************************/

#define DEFINE_ATOMIC_GET_OR_TYPE(mo, t)                                       \
	static inline __vtyp(t)                                                \
		__ATOMIC_ENAME(t##_get_or, mo)(__atyp(t) * a, __vtyp(t) v)     \
	{                                                                      \
		return (__vtyp(t))atomic_fetch_or_explicit(                    \
			&a->__v, (__utyp(t))v, __ATOMIC_EMO(mo));              \
	}
#define DEFINE_ATOMIC_GET_OR(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_OR, mo)

#define DEFINE_ATOMIC_OR_TYPE(mo, t)                                           \
	static inline __vtyp(t)                                                \
		__ATOMIC_ENAME(t##_or, mo)(__atyp(t) * a, __vtyp(t) v)         \
	{                                                                      \
		return __ATOMIC_ENAME(t##_get_or, mo)(a, v) | v;               \
	}
#define DEFINE_ATOMIC_OR(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_OR, mo)

/*******************************************************************************
 * vatomic_{get_add, add, inc}
 ******************************************************************************/

#define DEFINE_ATOMIC_GET_ADD_TYPE(mo, t)                                      \
	static inline __vtyp(t)                                                \
		__ATOMIC_ENAME(t##_get_add, mo)(__atyp(t) * a, __vtyp(t) v)    \
	{                                                                      \
		return (__vtyp(t))atomic_fetch_add_explicit(&a->__v, v,        \
							    __ATOMIC_EMO(mo)); \
	}
#define DEFINE_ATOMIC_GET_ADD(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_ADD, mo)

#define DEFINE_ATOMIC_ADD_TYPE(mo, t)                                          \
	static inline __vtyp(t)                                                \
		__ATOMIC_ENAME(t##_add, mo)(__atyp(t) * a, __vtyp(t) v)        \
	{                                                                      \
		return __ATOMIC_ENAME(t##_get_add, mo)(a, v) + v;              \
	}
#define DEFINE_ATOMIC_ADD(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_ADD, mo)

#define DEFINE_ATOMIC_GET_INC_TYPE(mo, t)                                      \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_get_inc, mo)(__atyp(t) * a) \
	{                                                                      \
		return __ATOMIC_ENAME(t##_get_add, mo)(a, 1U);                 \
	}
#define DEFINE_ATOMIC_GET_INC(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_INC, mo)

#define DEFINE_ATOMIC_INC_TYPE(mo, t)                                          \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_inc, mo)(__atyp(t) * a)     \
	{                                                                      \
		return __ATOMIC_ENAME(t##_add, mo)(a, 1U);                     \
	}
#define DEFINE_ATOMIC_INC(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_INC, mo)

/*******************************************************************************
 * vatomic_{get_sub, sub, dec}
 ******************************************************************************/

#define DEFINE_ATOMIC_GET_SUB_TYPE(mo, t)                                      \
	static inline __vtyp(t)                                                \
		__ATOMIC_ENAME(t##_get_sub, mo)(__atyp(t) * a, __vtyp(t) v)    \
	{                                                                      \
		return atomic_fetch_sub_explicit(&a->__v, v,                   \
						 __ATOMIC_EMO(mo));            \
	}
#define DEFINE_ATOMIC_GET_SUB(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_SUB, mo)

#define DEFINE_ATOMIC_SUB_TYPE(mo, t)                                          \
	static inline __vtyp(t)                                                \
		__ATOMIC_ENAME(t##_sub, mo)(__atyp(t) * a, __vtyp(t) v)        \
	{                                                                      \
		return __ATOMIC_ENAME(t##_get_sub, mo)(a, v) - v;              \
	}
#define DEFINE_ATOMIC_SUB(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_SUB, mo)

#define DEFINE_ATOMIC_GET_DEC_TYPE(mo, t)                                      \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_get_dec, mo)(__atyp(t) * a) \
	{                                                                      \
		return __ATOMIC_ENAME(t##_get_sub, mo)(a, 1U);                 \
	}
#define DEFINE_ATOMIC_GET_DEC(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_GET_DEC, mo)

#define DEFINE_ATOMIC_DEC_TYPE(mo, t)                                          \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_dec, mo)(__atyp(t) * a)     \
	{                                                                      \
		return __ATOMIC_ENAME(t##_sub, mo)(a, 1U);                     \
	}
#define DEFINE_ATOMIC_DEC(mo) DEFINE_FUNC_INT_TYPE(ATOMIC_DEC, mo)

/*******************************************************************************
 * vatomic_await_cond functions
 ******************************************************************************/

#if defined(VSYNC_CHECK_TERMINATION) && defined(VSYNC_VERIFICATION)
uint32_t __read_neq_explicit_atomic32_t(atomic_uint_least32_t *x, uint32_t v,
					memory_order mo);
uint64_t __read_neq_explicit_atomic64_t(atomic_uint_least64_t *x, uint64_t v,
					memory_order mo);
uintptr_t __read_neq_explicit_atomicptr_t(atomic_uintptr_t *x, uintptr_t v,
					  memory_order mo);

void __VERIFIER_assume(int);

#ifdef VSYNC_AWAIT_ASSUME
#define DEFINE_ATOMIC_AWAIT_MO(name, comp, mo, t)                              \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_##name,               \
					       mo)(__atyp(t) * a, __vtyp(t) v) \
	{                                                                      \
		__vtyp(t) cur = __ATOMIC_ENAME(t##_read, mo)(a);               \
		if (!(cur comp v)) {                                           \
			__ATOMIC_EXPANDER(__read_neq_explicit_, __atyp(t))     \
			(&a->__v, (__utyp(t))cur, memory_order_relaxed);       \
			__VERIFIER_assume(0);                                  \
		}                                                              \
		return cur;                                                    \
	}

#define DEFINE_ATOMIC_AWAIT_COUNTER_MO(name, comp, mo, t)                      \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_counter_##name, mo)(  \
		__atyp(t) * a, __vtyp(t) v, __vtyp(t) c)                       \
	{                                                                      \
		__vtyp(t) cur = __ATOMIC_ENAME(t##_read, mo)(a);               \
		if (!(cur comp v)) {                                           \
			__ATOMIC_EXPANDER(__read_neq_explicit_, __atyp(t))     \
			(&a->__v, (__utyp(t))cur, memory_order_relaxed);       \
			__VERIFIER_assume(0);                                  \
		}                                                              \
		return cur;                                                    \
	}

#define DEFINE_ATOMIC_AWAIT_MASK_MO(name, comp, mo, t)                         \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_mask_##name, mo)(     \
		__atyp(t) * a, __vtyp(t) v, __vtyp(t) bitmask)                 \
	{                                                                      \
		__vtyp(t) cur = __ATOMIC_ENAME(t##_read, mo)(a);               \
		if (!((cur & bitmask) comp v)) {                               \
			__ATOMIC_EXPANDER(__read_neq_explicit_, __atyp(t))     \
			(&a->__v, (__utyp(t))cur, memory_order_relaxed);       \
			__VERIFIER_assume(0);                                  \
		}                                                              \
		return cur;                                                    \
	}
#else

#ifdef VSYNC_USE_READ_NEQ
#define DEFINE_ATOMIC_AWAIT_MO(name, comp, mo, t)                              \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_##name,               \
					       mo)(__atyp(t) * a, __vtyp(t) v) \
	{                                                                      \
		__vtyp(t) cur;                                                 \
		while ((cur = __ATOMIC_ENAME(t##_read, mo)(a),                 \
			!(cur comp v))) {                                      \
			__ATOMIC_EXPANDER(__read_neq_explicit_, __atyp(t))     \
			(&a->__v, (__utyp(t))cur, memory_order_relaxed);       \
		}                                                              \
		return cur;                                                    \
	}

#define DEFINE_ATOMIC_AWAIT_COUNTER_MO(name, comp, mo, t)                      \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_counter_##name, mo)(  \
		__atyp(t) * a, __vtyp(t) v, __vtyp(t) c)                       \
	{                                                                      \
		__vtyp(t) cur;                                                 \
		while ((cur = __ATOMIC_ENAME(t##_read, mo)(a),                 \
			!(cur comp v) && c--)) {                               \
			__ATOMIC_EXPANDER(__read_neq_explicit_, __atyp(t))     \
			(&a->__v, (__utyp(t))cur, memory_order_relaxed);       \
		}                                                              \
		return cur;                                                    \
	}

#define DEFINE_ATOMIC_AWAIT_MASK_MO(name, comp, mo, t)                         \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_mask_##name, mo)(     \
		__atyp(t) * a, __vtyp(t) v, __vtyp(t) bitmask)                 \
	{                                                                      \
		__vtyp(t) cur;                                                 \
		while ((cur = __ATOMIC_ENAME(t##_read, mo)(a),                 \
			!((cur & bitmask) comp v))) {                          \
			__ATOMIC_EXPANDER(__read_neq_explicit_, __atyp(t))     \
			(&a->__v, (__utyp(t))cur, memory_order_relaxed);       \
		}                                                              \
		return cur;                                                    \
	}
#else /* When VSYNC_USE_READ_NEQ is undefined use AWAIT_WHILE macro            \
		 instead */

#define DEFINE_ATOMIC_AWAIT_MO(name, comp, mo, t)                              \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_##name,               \
					       mo)(__atyp(t) * a, __vtyp(t) v) \
	{                                                                      \
		__vtyp(t) cur;                                                 \
		AWAIT_WHILE((cur = __ATOMIC_ENAME(t##_read, mo)(a),            \
			     !(cur comp v)));                                  \
		return cur;                                                    \
	}

#define DEFINE_ATOMIC_AWAIT_COUNTER_MO(name, comp, mo, t)                      \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_counter_##name, mo)(  \
		__atyp(t) * a, __vtyp(t) v, __vtyp(t) c)                       \
	{                                                                      \
		__vtyp(t) cur;                                                 \
		AWAIT_WHILE((cur = __ATOMIC_ENAME(t##_read, mo)(a),            \
			     !(cur comp v) && c--));                           \
		return cur;                                                    \
	}

#define DEFINE_ATOMIC_AWAIT_MASK_MO(name, comp, mo, t)                         \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_mask_##name, mo)(     \
		__atyp(t) * a, __vtyp(t) v, __vtyp(t) mask)                    \
	{                                                                      \
		__vtyp(t) cur;                                                 \
		AWAIT_WHILE((cur = __ATOMIC_ENAME(t##_read, mo)(a),            \
			     !((cur & mask) comp v)));                         \
		return cur;                                                    \
	}

#endif /* VSYNC_USE_READ_NEQ */
#endif /* VSYNC_AWAIT_ASSUME */

#else /* VSYNC_CHECK_TERMINATION */

#define DEFINE_ATOMIC_AWAIT_MO(name, comp, mo, t)                              \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_##name,               \
					       mo)(__atyp(t) * a, __vtyp(t) v) \
	{ /* this implementation is not polite */                              \
		__vtyp(t) cur;                                                 \
		while (cur = __ATOMIC_ENAME(t##_read, mo)(a), !(cur comp v)) { \
			vatomic_cpu_relax();                                   \
		}                                                              \
		return (__vtyp(t))cur;                                         \
	}

#define DEFINE_ATOMIC_AWAIT_COUNTER_MO(name, comp, mo, t)                      \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_counter_##name, mo)(  \
		__atyp(t) * a, __vtyp(t) v, __vtyp(t) c)                       \
	{ /* this implementation is not polite */                              \
		__vtyp(t) cur;                                                 \
		while (cur = __ATOMIC_ENAME(t##_read, mo)(a),                  \
		       !(cur comp v) && (c != (__vtyp(t))0)) {                 \
			c--;                                                   \
			vatomic_cpu_relax();                                   \
		}                                                              \
		return (__vtyp(t))cur;                                         \
	}

#define DEFINE_ATOMIC_AWAIT_MASK_MO(name, comp, mo, t)                         \
	static inline __vtyp(t) __ATOMIC_ENAME(t##_await_mask_##name, mo)(     \
		__atyp(t) * a, __vtyp(t) v, __vtyp(t) bitmask)                 \
	{ /* this implementation is not polite */                              \
		__vtyp(t) cur;                                                 \
		while (cur = __ATOMIC_ENAME(t##_read, mo)(a),                  \
		       !((cur & bitmask) comp v)) {                            \
			vatomic_cpu_relax();                                   \
		}                                                              \
		return cur;                                                    \
	}
#endif

#define DEFINE_ATOMIC_AWAIT_MO_INT_TYPE(mo, t)                                 \
	DEFINE_ATOMIC_AWAIT_MO(lt, <, mo, t)                                   \
	DEFINE_ATOMIC_AWAIT_MO(le, <=, mo, t)                                  \
	DEFINE_ATOMIC_AWAIT_MO(gt, >, mo, t)                                   \
	DEFINE_ATOMIC_AWAIT_MO(ge, >=, mo, t)                                  \
	DEFINE_ATOMIC_AWAIT_MO(eq, ==, mo, t)                                  \
	DEFINE_ATOMIC_AWAIT_MO(neq, !=, mo, t)

#define DEFINE_ATOMIC_AWAIT_MO_PTR_TYPE(mo, t)                                 \
	DEFINE_ATOMIC_AWAIT_MO(eq, ==, mo, t)                                  \
	DEFINE_ATOMIC_AWAIT_MO(neq, !=, mo, t)

#define DEFINE_ATOMIC_AWAIT_MASK_MO_ALL_TYPE(mo, t)                            \
	DEFINE_ATOMIC_AWAIT_MASK_MO(lt, <, mo, t)                              \
	DEFINE_ATOMIC_AWAIT_MASK_MO(le, <=, mo, t)                             \
	DEFINE_ATOMIC_AWAIT_MASK_MO(gt, >, mo, t)                              \
	DEFINE_ATOMIC_AWAIT_MASK_MO(ge, >=, mo, t)                             \
	DEFINE_ATOMIC_AWAIT_MASK_MO(eq, ==, mo, t)                             \
	DEFINE_ATOMIC_AWAIT_MASK_MO(neq, !=, mo, t)

#define DEFINE_ATOMIC_AWAIT_COUNTER_MO_ALL_TYPE(mo, t)                         \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(lt, <, mo, t)                           \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(le, <=, mo, t)                          \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(gt, >, mo, t)                           \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(ge, >=, mo, t)                          \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(eq, ==, mo, t)                          \
	DEFINE_ATOMIC_AWAIT_COUNTER_MO(neq, !=, mo, t)

#define DEFINE_ATOMIC_AWAIT(mo)                                                \
	DEFINE_FUNC_INT_TYPE(ATOMIC_AWAIT_MO_INT, mo)                          \
	DEFINE_FUNC_PTR_TYPE(ATOMIC_AWAIT_MO_PTR, mo)

#define DEFINE_ATOMIC_AWAIT_MASK(mo)                                           \
	DEFINE_FUNC_INT_TYPE(ATOMIC_AWAIT_MASK_MO_ALL, mo)

#define DEFINE_ATOMIC_AWAIT_COUNTER(mo)                                        \
	DEFINE_FUNC_INT_TYPE(ATOMIC_AWAIT_COUNTER_MO_ALL, mo)

/*******************************************************************************
 * vatomic_await_cond_op functions
 ******************************************************************************/

#define __await_map_mo_seq mo_seq
#define __await_map_mo_acq mo_rlx
#define __await_map_mo_rel mo_rlx
#define __await_map_mo_rlx mo_rlx

#define __AWAIT_EMO(mo) __ATOMIC_EXPANDER(__await_map_, mo)

#define __AWAIT_READ(pfx, cond, mo)                                            \
	__ATOMIC_ENAME(pfx##_await_##cond, __AWAIT_EMO(mo))

#define __AWAIT_CMPXCHG(pfx, mo) __ATOMIC_ENAME(pfx##_cmpxchg, mo)

#define __ATOMIC_AWAIT_ENAME(pfx, cond, name, mo)                              \
	__ATOMIC_ENAME(pfx##_await_##cond##_##name, mo)

#define DEFINE_ATOMIC_AWAIT_COND_OP_MO(cond, name, op, mo, t)                  \
	static inline __vtyp(t) __ATOMIC_AWAIT_ENAME(t, cond, name, mo)(       \
		__atyp(t) * a, __vtyp(t) c, __vtyp(t) v)                       \
	{                                                                      \
		__vtyp(t) old;                                                 \
		do {                                                           \
			old = __AWAIT_READ(t, cond, mo)(a, c);                 \
		} while (__AWAIT_CMPXCHG(t, mo)(a, old, op(old, v)) != old);   \
		return old;                                                    \
	}

#define ATOMIC_AWAIT_OP_SUB(a, b) a - b
#define ATOMIC_AWAIT_OP_ADD(a, b) a + b
#define ATOMIC_AWAIT_OP_SET(a, b) b

#define DEFINE_ATOMIC_AWAIT_COND_OP_INT(name, op, mo, pfx)                     \
	DEFINE_ATOMIC_AWAIT_COND_OP_MO(lt, name, op, mo, pfx)                  \
	DEFINE_ATOMIC_AWAIT_COND_OP_MO(le, name, op, mo, pfx)                  \
	DEFINE_ATOMIC_AWAIT_COND_OP_MO(gt, name, op, mo, pfx)                  \
	DEFINE_ATOMIC_AWAIT_COND_OP_MO(ge, name, op, mo, pfx)                  \
	DEFINE_ATOMIC_AWAIT_COND_OP_MO(eq, name, op, mo, pfx)                  \
	DEFINE_ATOMIC_AWAIT_COND_OP_MO(neq, name, op, mo, pfx)

#define DEFINE_ATOMIC_AWAIT_COND_OP_PTR(name, op, mo, pfx)                     \
	DEFINE_ATOMIC_AWAIT_COND_OP_MO(eq, name, op, mo, pfx)                  \
	DEFINE_ATOMIC_AWAIT_COND_OP_MO(neq, name, op, mo, pfx)

#define DEFINE_ATOMIC_AWAIT_COND_OP_MO_INT_TYPE(mo, pfx)                       \
	DEFINE_ATOMIC_AWAIT_COND_OP_INT(add, ATOMIC_AWAIT_OP_ADD, mo, pfx)     \
	DEFINE_ATOMIC_AWAIT_COND_OP_INT(sub, ATOMIC_AWAIT_OP_SUB, mo, pfx)     \
	DEFINE_ATOMIC_AWAIT_COND_OP_INT(set, ATOMIC_AWAIT_OP_SET, mo, pfx)

#define DEFINE_ATOMIC_AWAIT_COND_OP_MO_PTR_TYPE(mo, pfx)                       \
	DEFINE_ATOMIC_AWAIT_COND_OP_PTR(set, ATOMIC_AWAIT_OP_SET, mo, pfx)

#define DEFINE_ATOMIC_AWAIT_COND_OP(mo)                                        \
	DEFINE_FUNC_INT_TYPE(ATOMIC_AWAIT_COND_OP_MO_INT, mo)                  \
	DEFINE_FUNC_PTR_TYPE(ATOMIC_AWAIT_COND_OP_MO_PTR, mo)
#endif
