/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: declares and defines atomic types and functions
 * Author: Huawei Dresden Research Center
 * Create: Wed 22 Jan 2020 01:02:52 PM CET
 */

#ifndef VSYNC_ATOMIC_H
#define VSYNC_ATOMIC_H

/*******************************************************************************
 * @file atomic.h
 * atomic.h declares and defines atomic types and functions.
 *
 * atomic.h provides a rich interface of atomic operations and fences. They are
 * implemented in custom assembly and C11, and provide common barrier modes.
 *
 * Always include the `atomic.h` header, other headers prefixed with `atomic_`
 * are for internal use only.
 *
 * ### Implementation variants
 *
 * Optimized atomic implementations are available for ARMv7 (32 and 64 bits)
 * and ARMv8 (32 and 64 bits). For all other architectures, including x86_64,
 * the fallback is C11 stdatomic. To force the use of C11 stdatomic, define
 * VSYNC_STDATOMIC.
 *
 * ### Atomic types
 *
 * atomic.h implements the following atomic types:
 *
 * | Atomic type (A) | Related type (T) |
 * | --------------- | ---------------- |
 * | vatomic32_t     | vuint32_t        |
 * | vatomic64_t     | vuint64_t        |
 * | vatomicptr_t    | void*            |
 *
 * Functions are always prefixed with the atomic type, eg, vatomic32_read(),
 * vatomic64_read(), vatomicptr_read(). Functions may take arguments or return
 * values of related types, eg, `vatomic64_write(vatomic64_t *a, vuint64_t v)`.
 *
 * For readability, the prefix vatomic_ maps to vatomic32_, for example,
 * vatomic_read() is the same as vatomic32_read() and vatomic_t is the same
 * as vatomic32_t.
 *
 * Note that a few functions are not defined for vatomicptr_t.
 *
 * ### Barrier modes
 *
 * Functions are *seq_cst* (sequentially consistent) by default. To speficy
 * another barrier mode, add the corresponding suffix the the function name:
 *
 * | Mode    | Suffix |
 * | ------- | ------ |
 * | acquire | `_acq` |
 * | release | `_rel` |
 * | relaxed | `_rlx` |
 *
 * Not all function support every barrier mode. See the function documentation
 * for the supported modes.
 *
 * ### Usage
 *
 * Here is a simple example of how to use the library:
 *
 * ```c
 * #include <vsync/atomic.h>
 * #include <stdint.h>
 * #include <stdio.h>
 * #include <assert.h>
 *
 * vatomic_t var;
 * vatomicptr_t ptr;
 * int x;
 *
 * void foo() {
 *     vatomic_write(&var, 1000);
 *     vatomic_add(&var, 10);
 *     uint32_t val = vatomic_read(&var);
 *     assert(val == 1010);
 *     assert(vatomic_cmpxchg(&var, val, 0) == val);
 *
 *     x = 123;
 *     vatomicptr_write(&ptr, &x);
 *     int *y = vatomicptr_read(&ptr);
 *     (*y)++;
 *     assert (*y == x);
 *
 *     printf("passed\n");
 * }
 * int main() { foo(); }
 * ```
 *
 ******************************************************************************/

/** By default, use vuint32_t and vuint64_t types from stdint.h. To disable
 * the include if stdinth, define VSYNC_FREESTANDING. In that case, the
 * user is responsible for defining these types.
 */
#ifndef VSYNC_FREESTANDING
#include <stdint.h>
#define vuint8_t uint8_t
#define vuint16_t uint16_t
#define vuint32_t uint32_t
#define vuint64_t uint64_t
#else
#include <vfreestanding.h>
#endif /* VSYNC_FREESTANDING */

#ifndef DOC
/*
 * Define to which instruction the mapping from relaxed fences is done.
 * Notice it is not supported on C11.
 */
#if defined(VSYNC_MAP_RLX_TO_NOP)
#define RLX_INSTRUCTION "nop"
#else
#define RLX_INSTRUCTION ""
#endif /* defined(VSYNC_MAP_RLX_TO_NOP) */

#if defined(VSYNC_STDATOMIC) || defined(VSYNC_VERIFICATION)
#include <vsync/atomic_c11.h>
#elif defined(__x86_64__)
#include <vsync/atomic_c11.h>
#elif defined(__arm__)
#include <vsync/atomic_arm32.h>
#elif defined(__aarch64__) && defined(VSYNC_ATOMIC_AARCH64_LSE)
#include <vsync/atomic_aarch64_lse.h>
#elif defined(__aarch64__)
#include <vsync/atomic_aarch64.h>
#else
#include <vsync/atomic_c11.h>
#endif

/* utils and mapping should be included after <vsync/atomic_c11.h> to avoid
 * using C11 atomic_init */
#include <vsync/atomic_utils.h>
#ifndef VSYNC_DISABLE_ATOMIC_MAPPING
#define VSYNC_MAP_ATOMICS
#endif
#include <vsync/atomic_mapping.h>
#endif /* !DOC */

/*******************************************************************************
 * @def vatomicptr(T)
 * @brief declares an atomic pointer type.
 *
 * When declaring an atomic pointer it may be useful to annotate it with the
 * original type. Use vatomicptr(T) macro for that.
 *
 * **Example**
 * ```
 * 	typedef struct mcs_node_s {
 * 		vatomicptr(struct mcs_node_s*) next;
 * 	} mcs_node_t;
 * ```
 ******************************************************************************/
#ifdef DOC
#define vatomicptr(T)
#else
#define vatomicptr(T) vatomicptr_t
#endif

/*******************************************************************************
 * @def vatomic_cpu_relax()
 * @brief call CPU relax instruction if available, eg, `PAUSE` in x86
 *
 * Tight spinloops often overuse the memory subsytem. This macro calls an
 * architecture-dependent instruction to slowdown spinloops (`PAUSE` in x86
 * and `YIELD` in aarch64). Define `VSYNC_DISABLE_POLITE_AWAIT` to disable the
 * effect of this macro.
 *
 * **Example**
 * ```
 * 	while (!vatomic_read(&flag)) vatomic_cpu_relax();
 * ```
 ******************************************************************************/
#ifdef DOC
#define vatomic_cpu_relax()
#else
#if !defined(VSYNC_DISABLE_POLITE_AWAIT)
#if defined(__x86_64__)
#define vatomic_cpu_relax() __asm__ volatile("pause\n" ::: "memory")
#elif defined(__aarch64__) || defined(__arm__)
#define vatomic_cpu_relax() __asm__ volatile("yield\n" ::: "memory")
#endif
#endif

#ifndef vatomic_cpu_relax
#define vatomic_cpu_relax()                                                    \
	do {                                                                   \
	} while (0)
#endif
#endif

/*******************************************************************************
 * @fn static inline void vatomic_fence(void)
 * @brief creates an atomic fence
 *
 * | Mode    | Function            |
 * | ------- | ------------------- |
 * | seq_cst | vatomic_fence()     |
 * | acquire | vatomic_fence_acq() |
 * | release | vatomic_fence_rel() |
 * | relaxed | vatomic_fence_rlx() |
 *
 ******************************************************************************/
#ifdef DOC
static inline void vatomic_fence(void);
#else
static inline void vatomic_fence_acq(void);
static inline void vatomic_fence_rel(void);
static inline void vatomic_fence_rlx(void);

DEFINE_ATOMIC_FENCE(mo_seq)
DEFINE_ATOMIC_FENCE(mo_rel)
DEFINE_ATOMIC_FENCE(mo_acq)
DEFINE_ATOMIC_FENCE(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_read(A *a)
 * @brief returns the value of the atomic variable pointed by a.
 *
 * @param a atomic variable
 * @return current value
 *
 * @types vatomic32_t, vatomic64_t, vatomicptr_t
 * @modes seq_cst, acquire, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_read(A *a);
#else
static inline vuint32_t vatomic32_read(vatomic32_t *a);
static inline vuint64_t vatomic64_read(vatomic64_t *a);
static inline void *vatomicptr_read(vatomicptr_t *a);

DEFINE_ATOMIC_READ(mo_seq)
DEFINE_ATOMIC_READ(mo_acq)
DEFINE_ATOMIC_READ(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline void vatomic_write(A *a, T v)
 * @brief writes value v in the atomic variable pointed by a.
 *
 * @param a atomic variable
 * @param v new value
 *
 * @types vatomic32_t, vatomic64_t, vatomicptr_t
 * @modes seq_cst, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline void vatomic_write(A *a, T v);
#else
static inline void vatomic32_write(vatomic32_t *a, vuint32_t v);
static inline void vatomic64_write(vatomic64_t *a, vuint64_t v);
static inline void vatomicptr_write(vatomicptr_t *a, void *v);

DEFINE_ATOMIC_WRITE(mo_seq)
DEFINE_ATOMIC_WRITE(mo_rel)
DEFINE_ATOMIC_WRITE(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline void vatomic_init(A *a, T v)
 * @brief initializes the atomic variable a with value v.
 *
 * The initialization is equivalent to an vatomic_write().
 *
 * @param a atomic variable
 * @param v initial value
 *
 * @types vatomic32_t, vatomic64_t, vatomicptr_t
 * @modes NA
 ******************************************************************************/
#ifdef DOC
static inline void vatomic_init(A *a, T v);
#endif

DEFINE_ATOMIC_INIT()

/*******************************************************************************
 * @fn static inline T vatomic_xchg(A *a, T v)
 * @brief writes v in a and returns old value.
 *
 * @param a atomic variable
 * @param v new value
 * @return old value
 *
 * @types vatomic32_t, vatomic64_t, vatomicptr_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_xchg(A *a, T v);
#else
static inline vuint32_t vatomic32_xchg(vatomic32_t *a, vuint32_t v);
static inline vuint64_t vatomic64_xchg(vatomic64_t *a, vuint64_t v);
static inline void *vatomicptr_xchg(vatomicptr_t *a, void *v);

DEFINE_ATOMIC_XCHG(mo_seq)
DEFINE_ATOMIC_XCHG(mo_acq)
DEFINE_ATOMIC_XCHG(mo_rel)
DEFINE_ATOMIC_XCHG(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_cmpxchg(A *a, T e, T v)
 * @brief writes value v in a if e is the current value.
 *
 * @param a atomic variable
 * @param e expected value
 * @param v new value
 * @return old value
 *
 * @types vatomic32_t, vatomic64_t, vatomicptr_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_cmpxchg(A *a, T e, T v);
#else
static inline vuint32_t vatomic32_cmpxchg(vatomic32_t *a, vuint32_t e,
					  vuint32_t v);
static inline vuint64_t vatomic64_cmpxchg(vatomic64_t *a, vuint64_t e,
					  vuint64_t v);
static inline void *vatomicptr_cmpxchg(vatomicptr_t *a, void *e, void *v);

DEFINE_ATOMIC_CMPXCHG(mo_seq)
DEFINE_ATOMIC_CMPXCHG(mo_acq)
DEFINE_ATOMIC_CMPXCHG(mo_rel)
DEFINE_ATOMIC_CMPXCHG(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_get_and(A *a, T v)
 * @brief applies bitwise and to the value of a and returns the old value.
 *
 * @param a atomic variable
 * @param v new value
 * @return old value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_get_and(A *a, T v);
#else
static inline vuint32_t vatomic32_get_and(vatomic32_t *a, vuint32_t v);
static inline vuint64_t vatomic64_get_and(vatomic64_t *a, vuint64_t v);

DEFINE_ATOMIC_GET_AND(mo_seq)
DEFINE_ATOMIC_GET_AND(mo_acq)
DEFINE_ATOMIC_GET_AND(mo_rel)
DEFINE_ATOMIC_GET_AND(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_and(A *a, T v)
 * @brief applies bitwise and operation with v to the value of a and returns
 * the new value.
 *
 * @param a atomic variable
 * @param v new value
 * @return new value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_and(A *a, T v);
#else
static inline vuint32_t vatomic32_and(vatomic32_t *a, vuint32_t v);
static inline vuint64_t vatomic64_and(vatomic64_t *a, vuint64_t v);

DEFINE_ATOMIC_AND(mo_seq)
DEFINE_ATOMIC_AND(mo_acq)
DEFINE_ATOMIC_AND(mo_rel)
DEFINE_ATOMIC_AND(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_get_or(A *a, T v)
 * @brief applies bitwise or operation with v to the value of a and returns
 * the old value.
 *
 * @param a atomic variable
 * @param v new value
 * @return old value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_get_or(A *a, T v);
#else
static inline vuint32_t vatomic32_get_or(vatomic32_t *a, vuint32_t v);
static inline vuint64_t vatomic64_get_or(vatomic64_t *a, vuint64_t v);

DEFINE_ATOMIC_GET_OR(mo_seq)
DEFINE_ATOMIC_GET_OR(mo_acq)
DEFINE_ATOMIC_GET_OR(mo_rel)
DEFINE_ATOMIC_GET_OR(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_or(A *a, T v)
 * @brief applies bitwise or operation with v to the value of a and returns
 * the new value.
 *
 * @param a atomic variable
 * @param v new value
 * @return new value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_or(A *a, T v);
#else
static inline vuint32_t vatomic32_or(vatomic32_t *a, vuint32_t v);
static inline vuint64_t vatomic64_or(vatomic64_t *a, vuint64_t v);

DEFINE_ATOMIC_OR(mo_seq)
DEFINE_ATOMIC_OR(mo_acq)
DEFINE_ATOMIC_OR(mo_rel)
DEFINE_ATOMIC_OR(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_get_add(A *a, T v)
 * @brief adds v to the value of a and returns the old value.
 *
 * @param a atomic variable
 * @param v addend value
 * @return old value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_get_add(A *a, T v);
#else
static inline vuint32_t vatomic32_get_add(vatomic32_t *a, vuint32_t v);
static inline vuint64_t vatomic64_get_add(vatomic64_t *a, vuint64_t v);

DEFINE_ATOMIC_GET_ADD(mo_seq)
DEFINE_ATOMIC_GET_ADD(mo_acq)
DEFINE_ATOMIC_GET_ADD(mo_rel)
DEFINE_ATOMIC_GET_ADD(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_add(A *a, T v)
 * @brief adds v to the value of a and returns the new value.
 *
 * @param a atomic variable
 * @param v addend value
 * @return new value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_add(A *a, T v);
#else
static inline vuint32_t vatomic32_add(vatomic32_t *a, vuint32_t v);
static inline vuint64_t vatomic64_add(vatomic64_t *a, vuint64_t v);

DEFINE_ATOMIC_ADD(mo_seq)
DEFINE_ATOMIC_ADD(mo_acq)
DEFINE_ATOMIC_ADD(mo_rel)
DEFINE_ATOMIC_ADD(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_get_inc(A *a)
 * @brief increments the value of a and returns the old value.
 *
 * @param a atomic variable
 * @return old value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_get_inc(A *a);
#else
static inline vuint32_t vatomic32_get_inc(vatomic32_t *a);
static inline vuint64_t vatomic64_get_inc(vatomic64_t *a);

DEFINE_ATOMIC_GET_INC(mo_seq)
DEFINE_ATOMIC_GET_INC(mo_acq)
DEFINE_ATOMIC_GET_INC(mo_rel)
DEFINE_ATOMIC_GET_INC(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_inc(A *a)
 * @brief increments the value of a and returns the new value.
 *
 * @param a atomic variable
 * @return old value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_inc(A *a);
#else
static inline vuint32_t vatomic32_inc(vatomic32_t *a);
static inline vuint64_t vatomic64_inc(vatomic64_t *a);

DEFINE_ATOMIC_INC(mo_seq)
DEFINE_ATOMIC_INC(mo_acq)
DEFINE_ATOMIC_INC(mo_rel)
DEFINE_ATOMIC_INC(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_get_sub(A *a, T v)
 * @brief substracts v from a and returns the old value.
 *
 * @param a atomic variable
 * @param v subtrahend value
 * @return old value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_get_sub(A *a, T v);
#else
static inline vuint32_t vatomic32_get_sub(vatomic32_t *a, vuint32_t v);
static inline vuint64_t vatomic64_get_sub(vatomic64_t *a, vuint64_t v);

DEFINE_ATOMIC_GET_SUB(mo_seq)
DEFINE_ATOMIC_GET_SUB(mo_acq)
DEFINE_ATOMIC_GET_SUB(mo_rel)
DEFINE_ATOMIC_GET_SUB(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_sub(A *a, T v)
 * @brief substracts v from a and returns the new value.
 *
 * @param a atomic variable
 * @param v subtrahend value
 * @return new value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_sub(A *a, T v);
#else
static inline vuint32_t vatomic32_sub(vatomic32_t *a, vuint32_t v);
static inline vuint64_t vatomic64_sub(vatomic64_t *a, vuint64_t v);

DEFINE_ATOMIC_SUB(mo_seq)
DEFINE_ATOMIC_SUB(mo_acq)
DEFINE_ATOMIC_SUB(mo_rel)
DEFINE_ATOMIC_SUB(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_get_dec(A *a)
 * @brief decrements the value of a and returns the old value.
 *
 * @param a atomic variable
 * @return old value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_get_dec(A *a);
#else
static inline vuint32_t vatomic32_get_dec(vatomic32_t *a);
static inline vuint64_t vatomic64_get_dec(vatomic64_t *a);

DEFINE_ATOMIC_GET_DEC(mo_seq)
DEFINE_ATOMIC_GET_DEC(mo_acq)
DEFINE_ATOMIC_GET_DEC(mo_rel)
DEFINE_ATOMIC_GET_DEC(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_dec(A *a)
 * @brief decrements the value of a and returns the new value.
 *
 * @param a atomic variable
 * @return new value
 *
 * @types vatomic32_t, vatomic64_t
 * @modes seq_cst, acquire, release, relaxed
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_dec(A *a);
#else
static inline vuint32_t vatomic32_dec(vatomic32_t *a);
static inline vuint64_t vatomic64_dec(vatomic64_t *a);

DEFINE_ATOMIC_DEC(mo_seq)
DEFINE_ATOMIC_DEC(mo_acq)
DEFINE_ATOMIC_DEC(mo_rel)
DEFINE_ATOMIC_DEC(mo_rlx)
#endif

/*******************************************************************************
 * @fn static inline T vatomic_await_COND(A *a, T c)
 * @brief politely awaits a condition on variable a and value c.
 *
 * These functions are used to politely await a condition on an atomic variable.
 * The return value is the first read value that satifies the condition, as if
 * read with vatomic_read(a).
 *
 * @param a atomic variable
 * @param c value to compare
 * @return value satistifying the condition
 *
 * @modes seq_cst, acquire, relaxed
 *
 * **Conditions**
 *
 * | COND     | Condition   | Atomic types                           |
 * | -------- | ----------- | -------------------------------------- |
 * | lt       | (*a <  c)   | vatomic32_t, vatomic64_t               |
 * | le       | (*a <= c)   | vatomic32_t, vatomic64_t               |
 * | gt       | (*a >  c)   | vatomic32_t, vatomic64_t               |
 * | ge       | (*a >= c)   | vatomic32_t, vatomic64_t               |
 * | eq       | (*a == c)   | vatomic32_t, vatomic64_t, vatomicptr_t |
 * | neq      | (*a != c)   | vatomic32_t, vatomic64_t, vatomicptr_t |
 *
 * **Example**
 *
 * The following example waits for the pointer me->next to be different than
 * NULL. The variable next contains the value that satistisfied the condition.
 * The operation has an acquire barrier.
 *
 * ```
 * node_t *next = vatomicptr_await_neq_acq(me->next, NULL);
 * ```
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_await_COND(A *a, T c);
#else
static inline vuint32_t vatomic32_await_lt(vatomic32_t *a, vuint32_t c);
static inline vuint32_t vatomic32_await_le(vatomic32_t *a, vuint32_t c);
static inline vuint32_t vatomic32_await_gt(vatomic32_t *a, vuint32_t c);
static inline vuint32_t vatomic32_await_ge(vatomic32_t *a, vuint32_t c);
static inline vuint32_t vatomic32_await_eq(vatomic32_t *a, vuint32_t c);
static inline vuint32_t vatomic32_await_neq(vatomic32_t *a, vuint32_t c);

static inline vuint64_t vatomic64_await_lt(vatomic64_t *a, vuint64_t c);
static inline vuint64_t vatomic64_await_le(vatomic64_t *a, vuint64_t c);
static inline vuint64_t vatomic64_await_gt(vatomic64_t *a, vuint64_t c);
static inline vuint64_t vatomic64_await_ge(vatomic64_t *a, vuint64_t c);
static inline vuint64_t vatomic64_await_eq(vatomic64_t *a, vuint64_t c);
static inline vuint64_t vatomic64_await_neq(vatomic64_t *a, vuint64_t c);

static inline void *vatomicptr_await_eq(vatomicptr_t *a, void *c);
static inline void *vatomicptr_await_neq(vatomicptr_t *a, void *c);

/* unary variants */
/* - vatomic_await(p) awaits *p to be true, ie, (*p != 0)
 * - vatomic_await_false(p) awaits (*p == 0).
 * - vatomic_await_true(p) same as vatomic_await(p).
 */

#define vatomic32_await(p) vatomic32_await_neq(p, 0)
#define vatomic32_await_true(p) vatomic32_await_neq(p, 0)
#define vatomic32_await_false(p) vatomic32_await_eq(p, 0)

#define vatomic64_await(p) vatomic64_await_neq(p, 0)
#define vatomic64_await_true(p) vatomic64_await_neq(p, 0)
#define vatomic64_await_false(p) vatomic64_await_eq(p, 0)

DEFINE_ATOMIC_AWAIT(mo_seq)
DEFINE_ATOMIC_AWAIT(mo_acq)
DEFINE_ATOMIC_AWAIT(mo_rlx)
#endif

/* await with counter */
static inline vuint32_t vatomic32_await_counter_eq(vatomic32_t *a, vuint32_t v,
						   vuint32_t c);
static inline vuint32_t vatomic32_await_counter_neq(vatomic32_t *a, vuint32_t v,
						    vuint32_t c);

DEFINE_ATOMIC_AWAIT_COUNTER(mo_seq)
DEFINE_ATOMIC_AWAIT_COUNTER(mo_acq)
DEFINE_ATOMIC_AWAIT_COUNTER(mo_rlx)

/* await with bitmask */
static inline vuint32_t vatomic32_await_mask_eq(vatomic32_t *a, vuint32_t v,
						vuint32_t bitmask);
static inline vuint32_t vatomic32_await_mask_neq(vatomic32_t *a, vuint32_t v,
						 vuint32_t bitmask);

DEFINE_ATOMIC_AWAIT_MASK(mo_seq)
DEFINE_ATOMIC_AWAIT_MASK(mo_acq)
DEFINE_ATOMIC_AWAIT_MASK(mo_rlx)

/*******************************************************************************
 * @fn static inline T vatomic_await_COND_OP(A *a, T c, T v)
 * @brief politely awaits a condition on variable a and value c, performing an
 * operation with value v once the condition is satisfied.
 *
 * Theses functions are used to politely await a condition on an atomic variable
 * and apply a modification to the variable according to an operation once the
 * condition is met. The return value is the first read value that satifies
 * the condition, as if read with vatomic_read(a).
 *
 * @param a atomic variable
 * @param c value to compare
 * @param v value to apply the operation
 * @return value satistifying the condition
 *
 * @modes seq_cst, acquire, release, relaxed
 *
 * **Conditions**
 *
 * | COND     | Condition   | Atomic types                           |
 * | -------- | ----------- | -------------------------------------- |
 * | lt       | (*a <  c)   | vatomic32_t, vatomic64_t               |
 * | le       | (*a <= c)   | vatomic32_t, vatomic64_t               |
 * | gt       | (*a >  c)   | vatomic32_t, vatomic64_t               |
 * | ge       | (*a >= c)   | vatomic32_t, vatomic64_t               |
 * | eq       | (*a == c)   | vatomic32_t, vatomic64_t, vatomicptr_t |
 * | neq      | (*a != c)   | vatomic32_t, vatomic64_t, vatomicptr_t |
 *
 * **Operations**
 *
 * | OP   | Operation   | Atomic types                           |
 * | ---- | ----------- | -------------------------------------- |
 * | add  | *a += v     | vatomic32_t, vatomic64_t               |
 * | sub  | *a -= v     | vatomic32_t, vatomic64_t               |
 * | set  | *a = v      | vatomic32_t, vatomic64_t, vatomicptr_t |
 *
 * **Example**
 *
 * The following example waits for the pointer me->next to be equal to pred.
 * Once the condition is met, write NULL in me->next. The variable next contains
 * the value that satistisfied the condition. The operation has an release
 * barrier.
 *
 * ```
 * node_t *next = vatomicptr_await_eq_set_acq(me->next, pred, NULL);
 * ```
 ******************************************************************************/
#ifdef DOC
static inline T vatomic_await_COND_OP(A *a, T c, T v);
#else
static inline vuint32_t vatomic32_await_lt_add(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_le_add(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_gt_add(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_ge_add(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_eq_add(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_neq_add(vatomic32_t *a, vuint32_t c,
						vuint32_t v);

static inline vuint32_t vatomic32_await_lt_sub(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_le_sub(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_gt_sub(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_ge_sub(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_eq_sub(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_neq_sub(vatomic32_t *a, vuint32_t c,
						vuint32_t v);

static inline vuint32_t vatomic32_await_lt_set(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_le_set(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_gt_set(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_ge_set(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_eq_set(vatomic32_t *a, vuint32_t c,
					       vuint32_t v);
static inline vuint32_t vatomic32_await_neq_set(vatomic32_t *a, vuint32_t c,
						vuint32_t v);

static inline vuint64_t vatomic64_await_lt_add(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_le_add(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_gt_add(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_ge_add(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_eq_add(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_neq_add(vatomic64_t *a, vuint64_t c,
						vuint64_t v);

static inline vuint64_t vatomic64_await_lt_sub(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_le_sub(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_gt_sub(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_ge_sub(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_eq_sub(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_neq_sub(vatomic64_t *a, vuint64_t c,
						vuint64_t v);

static inline vuint64_t vatomic64_await_lt_set(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_le_set(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_gt_set(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_ge_set(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_eq_set(vatomic64_t *a, vuint64_t c,
					       vuint64_t v);
static inline vuint64_t vatomic64_await_neq_set(vatomic64_t *a, vuint64_t c,
						vuint64_t v);

static inline void *vatomicptr_await_eq_set(vatomicptr_t *a, void *c, void *v);
static inline void *vatomicptr_await_neq_set(vatomicptr_t *a, void *c, void *v);

DEFINE_ATOMIC_AWAIT_COND_OP(mo_seq)
DEFINE_ATOMIC_AWAIT_COND_OP(mo_acq)
DEFINE_ATOMIC_AWAIT_COND_OP(mo_rel)
DEFINE_ATOMIC_AWAIT_COND_OP(mo_rlx)
#endif

#endif /* VSYNC_ATOMIC_H */
