/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: atomic operations
 * Author: Huawei Dresden Research Center
 * Create: Wed 22 Jan 2020 01:00:33 PM CET
 */
#ifndef VSYNC_ATOMIC_UTILS_H
#define VSYNC_ATOMIC_UTILS_H

/*******************************************************************************
 * helpers
 ******************************************************************************/

/* paster and expander for atomic.h */
#define __ATOMIC_PASTER(a, b) a##b
#define __ATOMIC_EXPANDER(a, b) __ATOMIC_PASTER(a, b)

/* __ATOMIC_ENAME(name, mo) expands name with memory order */
#define __ATOMIC_ENAME(name, mo)                                               \
	__ATOMIC_EXPANDER(name, __ATOMIC_EXPANDER(suf_, mo))

/* __ATOMIC_EMO(mo) expands memory order mo */
#define __ATOMIC_EMO(mo) __ATOMIC_EXPANDER(map_, mo)

#define ATOMIC_NAME(t, f, mo) __ATOMIC_ENAME(vatomic##t##_##f, mo)

/*******************************************************************************
 * verification macros
 *
 * If we are verifying code, __VERIFIER_assume is interpreted by the
 * verification tools. If we additionally are checking termination, then
 * __VERIFIER_*_read_neq is also interpreted by the verification tools.
 ******************************************************************************/

#ifdef VSYNC_VERIFICATION
void __VERIFIER_assume(int);
#else
#define __VERIFIER_assume(X)                                                   \
	do {                                                                   \
	} while (0)
#endif

#if defined(VSYNC_VERIFICATION) && defined(VSYNC_CHECK_TERMINATION)
vuint32_t __read_neq_explicit_vatomic32_t(atomic_uint_least32_t *x, vuint32_t v,
					  memory_order mo);
vuint64_t __read_neq_explicit_vatomic64_t(atomic_uint_least64_t *x, vuint64_t v,
					  memory_order mo);
uintptr_t __read_neq_explicit_vatomicptr_t(atomic_uintptr_t *x, uintptr_t v,
					   memory_order mo);
vuint32_t __read_neq_explicit_vuint32_t(vuint32_t *x, vuint32_t v,
					memory_order mo);

#define __VERIFIER_vatomic32_read_neq(a, val)                                  \
	__read_neq_explicit_vatomic32_t(&((a)->__v), val, 0)

#define __VERIFIER_vatomic_read_neq(a, val)                                    \
	__VERIFIER_vatomic32_read_neq(a, val)

#define __VERIFIER_vatomic64_read_neq(a, val)                                  \
	__read_neq_explicit_vatomic64_t(&((a)->__v), val, 0)

#define __VERIFIER_vatomicptr_read_neq(a, val)                                 \
	__read_neq_explicit_vatomicptr_t(&((a)->__v), (uintptr_t)val, 0)

#define __VERIFIER_read_neq_vuint32(ptr, val)                                  \
	__read_neq_explicit_vuint32_t(ptr, val, 0)

#else /* NO VERIFICATION or NO CHECK TERMINATION */

#define __VERIFIER_vatomic_read_neq(ptr, val)                                  \
	do {                                                                   \
	} while (0)
#define __VERIFIER_vatomic32_read_neq(ptr, val)                                \
	do {                                                                   \
	} while (0)
#define __VERIFIER_vatomic64_read_neq(ptr, val)                                \
	do {                                                                   \
	} while (0)
#define __VERIFIER_vatomicptr_read_neq(ptr, val)                               \
	do {                                                                   \
	} while (0)
#define __VERIFIER_read_neq_vuint32(ptr, val)                                  \
	do {                                                                   \
	} while (0)

#endif
#endif
