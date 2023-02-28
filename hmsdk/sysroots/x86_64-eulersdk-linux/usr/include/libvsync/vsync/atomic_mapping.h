/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Author: Huawei Dresden Research Center
 * Create: Wed Mar  3 13:50:04 CET 2021
 */
#ifndef VSYNC_ATOMIC_MAPPING_H
#define VSYNC_ATOMIC_MAPPING_H

/*******************************************************************************
 * map vatomic_ to vatomic32_
 ******************************************************************************/
#define vatomic_t vatomic32_t

#undef vatomic_init
#define vatomic_init vatomic32_init

#define vatomic_read vatomic32_read
#define vatomic_read_rlx vatomic32_read_rlx
#define vatomic_read_acq vatomic32_read_acq

#define vatomic_write vatomic32_write
#define vatomic_write_rlx vatomic32_write_rlx
#define vatomic_write_rel vatomic32_write_rel

#define vatomic_xchg vatomic32_xchg
#define vatomic_xchg_rlx vatomic32_xchg_rlx
#define vatomic_xchg_rel vatomic32_xchg_rel
#define vatomic_xchg_acq vatomic32_xchg_acq

#define vatomic_cmpxchg vatomic32_cmpxchg
#define vatomic_cmpxchg_rlx vatomic32_cmpxchg_rlx
#define vatomic_cmpxchg_rel vatomic32_cmpxchg_rel
#define vatomic_cmpxchg_acq vatomic32_cmpxchg_acq

#define vatomic_get_add vatomic32_get_add
#define vatomic_get_add_rlx vatomic32_get_add_rlx
#define vatomic_get_add_rel vatomic32_get_add_rel
#define vatomic_get_add_acq vatomic32_get_add_acq

#define vatomic_and vatomic32_and
#define vatomic_and_rlx vatomic32_and_rlx
#define vatomic_and_rel vatomic32_and_rel
#define vatomic_and_acq vatomic32_and_acq

#define vatomic_or vatomic32_or
#define vatomic_or_rlx vatomic32_or_rlx
#define vatomic_or_rel vatomic32_or_rel
#define vatomic_or_acq vatomic32_or_acq

#define vatomic_get_or vatomic32_get_or
#define vatomic_get_or_rlx vatomic32_get_or_rlx
#define vatomic_get_or_rel vatomic32_get_or_rel
#define vatomic_get_or_acq vatomic32_get_or_acq

#define vatomic_add vatomic32_add
#define vatomic_add_rlx vatomic32_add_rlx
#define vatomic_add_rel vatomic32_add_rel
#define vatomic_add_acq vatomic32_add_acq

#define vatomic_get_inc vatomic32_get_inc
#define vatomic_get_inc_rlx vatomic32_get_inc_rlx
#define vatomic_get_inc_rel vatomic32_get_inc_rel
#define vatomic_get_inc_acq vatomic32_get_inc_acq

#define vatomic_inc vatomic32_inc
#define vatomic_inc_rlx vatomic32_inc_rlx
#define vatomic_inc_rel vatomic32_inc_rel
#define vatomic_inc_acq vatomic32_inc_acq

#define vatomic_get_sub vatomic32_get_sub
#define vatomic_get_sub_rlx vatomic32_get_sub_rlx
#define vatomic_get_sub_rel vatomic32_get_sub_rel
#define vatomic_get_sub_acq vatomic32_get_sub_acq

#define vatomic_sub vatomic32_sub
#define vatomic_sub_rlx vatomic32_sub_rlx
#define vatomic_sub_rel vatomic32_sub_rel
#define vatomic_sub_acq vatomic32_sub_acq

#define vatomic_get_dec vatomic32_get_dec
#define vatomic_get_dec_rlx vatomic32_get_dec_rlx
#define vatomic_get_dec_rel vatomic32_get_dec_rel
#define vatomic_get_dec_acq vatomic32_get_dec_acq

#define vatomic_dec vatomic32_dec
#define vatomic_dec_rlx vatomic32_dec_rlx
#define vatomic_dec_rel vatomic32_dec_rel
#define vatomic_dec_acq vatomic32_dec_acq

#define vatomic_await_eq vatomic32_await_eq
#define vatomic_await_eq_acq vatomic32_await_eq_acq
#define vatomic_await_eq_rel vatomic32_await_eq_rel
#define vatomic_await_eq_rlx vatomic32_await_eq_rlx

#define vatomic_await_gt vatomic32_await_gt
#define vatomic_await_gt_acq vatomic32_await_gt_acq
#define vatomic_await_gt_rel vatomic32_await_gt_rel
#define vatomic_await_gt_rlx vatomic32_await_gt_rlx

#define vatomic_await_neq vatomic32_await_neq
#define vatomic_await_neq_acq vatomic32_await_neq_acq
#define vatomic_await_neq_rel vatomic32_await_neq_rel
#define vatomic_await_neq_rlx vatomic32_await_neq_rlx

#define vatomic_await_ge_sub vatomic32_await_ge_sub
#define vatomic_await_ge_sub_acq vatomic32_await_ge_sub_acq
#define vatomic_await_ge_sub_rel vatomic32_await_ge_sub_rel
#define vatomic_await_ge_sub_rlx vatomic32_await_ge_sub_rlx

#define vatomic_await_eq_set vatomic32_await_eq_set
#define vatomic_await_eq_set_acq vatomic32_await_eq_set_acq
#define vatomic_await_eq_set_rel vatomic32_await_eq_set_rel
#define vatomic_await_eq_set_rlx vatomic32_await_eq_set_rlx

#define vatomic_await_counter_neq vatomic32_await_counter_neq
#define vatomic_await_counter_neq_acq vatomic32_await_counter_neq_acq
#define vatomic_await_counter_neq_rel vatomic32_await_counter_neq_rel
#define vatomic_await_counter_neq_rlx vatomic32_await_counter_neq_rlx

#define vatomic_await_mask_eq vatomic32_await_mask_eq
#define vatomic_await_mask_eq_acq vatomic32_await_mask_eq_acq
#define vatomic_await_mask_eq_rel vatomic32_await_mask_eq_rel
#define vatomic_await_mask_eq_rlx vatomic32_await_mask_eq_rlx

#define vatomic_await_mask_neq vatomic32_await_mask_neq
#define vatomic_await_mask_neq_acq vatomic32_await_mask_neq_acq
#define vatomic_await_mask_neq_rel vatomic32_await_mask_neq_rel
#define vatomic_await_mask_neq_rlx vatomic32_await_mask_neq_rlx

/*******************************************************************************
 * function suffix -- Each memory order defines a new function with a suffix.
 ******************************************************************************/
#ifndef VSYNC_SC

#define suf_mo_seq
#define suf_mo_acq _acq
#define suf_mo_rel _rel
#define suf_mo_rlx _rlx

#else /* If VSYNC_SC is defined, all function variants map to their seq_cst    \
	* counterpart. Just defined VSYNC_SC for testing.  */

/* map actual implementations to something else */
#define suf_mo_seq
#define suf_mo_acq _IGNORE_acq
#define suf_mo_rel _IGNORE_rel
#define suf_mo_rlx _IGNORE_rlx

#define vatomic_fence_rlx __ATOMIC_ENAME(vatomic_fence, mo_seq)
#define vatomic_fence_rel __ATOMIC_ENAME(vatomic_fence, mo_seq)
#define vatomic_fence_acq __ATOMIC_ENAME(vatomic_fence, mo_seq)

/* map all variants to seq_cst version */
#define vatomic32_read_rlx __ATOMIC_ENAME(vatomic32_read, mo_seq)
#define vatomic32_read_acq __ATOMIC_ENAME(vatomic32_read, mo_seq)

#define vatomic32_write_rlx __ATOMIC_ENAME(vatomic32_write, mo_seq)
#define vatomic32_write_rel __ATOMIC_ENAME(vatomic32_write, mo_seq)

#define vatomic32_xchg_rlx __ATOMIC_ENAME(vatomic32_xchg, mo_seq)
#define vatomic32_xchg_rel __ATOMIC_ENAME(vatomic32_xchg, mo_seq)
#define vatomic32_xchg_acq __ATOMIC_ENAME(vatomic32_xchg, mo_seq)

#define vatomic32_cmpxchg_rlx __ATOMIC_ENAME(vatomic32_cmpxchg, mo_seq)
#define vatomic32_cmpxchg_rel __ATOMIC_ENAME(vatomic32_cmpxchg, mo_seq)
#define vatomic32_cmpxchg_acq __ATOMIC_ENAME(vatomic32_cmpxchg, mo_seq)

#define vatomic32_get_or_rlx __ATOMIC_ENAME(vatomic32_get_or, mo_seq)
#define vatomic32_get_or_rel __ATOMIC_ENAME(vatomic32_get_or, mo_seq)
#define vatomic32_get_or_acq __ATOMIC_ENAME(vatomic32_get_or, mo_seq)

#define vatomic32_or_rlx __ATOMIC_ENAME(vatomic32_or, mo_seq)
#define vatomic32_or_rel __ATOMIC_ENAME(vatomic32_or, mo_seq)
#define vatomic32_or_acq __ATOMIC_ENAME(vatomic32_or, mo_seq)

#define vatomic32_and_rlx __ATOMIC_ENAME(vatomic32_and, mo_seq)
#define vatomic32_and_rel __ATOMIC_ENAME(vatomic32_and, mo_seq)
#define vatomic32_and_acq __ATOMIC_ENAME(vatomic32_and, mo_seq)

#define vatomic32_get_and_rlx __ATOMIC_ENAME(vatomic32_get_and, mo_seq)
#define vatomic32_get_and_rel __ATOMIC_ENAME(vatomic32_get_and, mo_seq)
#define vatomic32_get_and_acq __ATOMIC_ENAME(vatomic32_get_and, mo_seq)

#define vatomic32_get_add_rlx __ATOMIC_ENAME(vatomic32_get_add, mo_seq)
#define vatomic32_get_add_rel __ATOMIC_ENAME(vatomic32_get_add, mo_seq)
#define vatomic32_get_add_acq __ATOMIC_ENAME(vatomic32_get_add, mo_seq)

#define vatomic32_add_rlx __ATOMIC_ENAME(vatomic32_add, mo_seq)
#define vatomic32_add_rel __ATOMIC_ENAME(vatomic32_add, mo_seq)
#define vatomic32_add_acq __ATOMIC_ENAME(vatomic32_add, mo_seq)

#define vatomic32_get_inc_rlx __ATOMIC_ENAME(vatomic32_get_inc, mo_seq)
#define vatomic32_get_inc_rel __ATOMIC_ENAME(vatomic32_get_inc, mo_seq)
#define vatomic32_get_inc_acq __ATOMIC_ENAME(vatomic32_get_inc, mo_seq)

#define vatomic32_inc_rlx __ATOMIC_ENAME(vatomic32_inc, mo_seq)
#define vatomic32_inc_rel __ATOMIC_ENAME(vatomic32_inc, mo_seq)
#define vatomic32_inc_acq __ATOMIC_ENAME(vatomic32_inc, mo_seq)

#define vatomic32_get_sub_rlx __ATOMIC_ENAME(vatomic32_get_sub, mo_seq)
#define vatomic32_get_sub_rel __ATOMIC_ENAME(vatomic32_get_sub, mo_seq)
#define vatomic32_get_sub_acq __ATOMIC_ENAME(vatomic32_get_sub, mo_seq)

#define vatomic32_sub_rlx __ATOMIC_ENAME(vatomic32_sub, mo_seq)
#define vatomic32_sub_rel __ATOMIC_ENAME(vatomic32_sub, mo_seq)
#define vatomic32_sub_acq __ATOMIC_ENAME(vatomic32_sub, mo_seq)

#define vatomic32_get_dec_rlx __ATOMIC_ENAME(vatomic32_get_dec, mo_seq)
#define vatomic32_get_dec_rel __ATOMIC_ENAME(vatomic32_get_dec, mo_seq)
#define vatomic32_get_dec_acq __ATOMIC_ENAME(vatomic32_get_dec, mo_seq)

#define vatomic32_dec_rlx __ATOMIC_ENAME(vatomic32_dec, mo_seq)
#define vatomic32_dec_rel __ATOMIC_ENAME(vatomic32_dec, mo_seq)
#define vatomic32_dec_acq __ATOMIC_ENAME(vatomic32_dec, mo_seq)

#define vatomic32_await_eq_acq __ATOMIC_ENAME(vatomic32_await_eq, mo_seq)
#define vatomic32_await_eq_rel __ATOMIC_ENAME(vatomic32_await_eq, mo_seq)
#define vatomic32_await_eq_rlx __ATOMIC_ENAME(vatomic32_await_eq, mo_seq)

#define vatomic32_await_neq_acq __ATOMIC_ENAME(vatomic32_await_neq, mo_seq)
#define vatomic32_await_neq_rel __ATOMIC_ENAME(vatomic32_await_neq, mo_seq)
#define vatomic32_await_neq_rlx __ATOMIC_ENAME(vatomic32_await_neq, mo_seq)

#define vatomic32_await_eq_set_seq                                             \
	__ATOMIC_ENAME(vatomic32_await_eq_set, mo_seq)
#define vatomic32_await_eq_set_acq                                             \
	__ATOMIC_ENAME(vatomic32_await_eq_set, mo_seq)
#define vatomic32_await_eq_set_rel                                             \
	__ATOMIC_ENAME(vatomic32_await_eq_set, mo_seq)
#define vatomic32_await_eq_set_rlx                                             \
	__ATOMIC_ENAME(vatomic32_await_eq_set, mo_seq)

#define vatomic32_await_ge_sub_seq                                             \
	__ATOMIC_ENAME(vatomic32_await_ge_sub, mo_seq)
#define vatomic32_await_ge_sub_acq                                             \
	__ATOMIC_ENAME(vatomic32_await_ge_sub, mo_seq)
#define vatomic32_await_ge_sub_rel                                             \
	__ATOMIC_ENAME(vatomic32_await_ge_sub, mo_seq)
#define vatomic32_await_ge_sub_rlx                                             \
	__ATOMIC_ENAME(vatomic32_await_ge_sub, mo_seq)

#define vatomic32_await_counter_neq                                            \
	__ATOMIC_ENAME(vatomic32_await_counter_neq, mo_seq)
#define vatomic32_await_counter_neq_acq                                        \
	__ATOMIC_ENAME(vatomic32_await_counter_neq, mo_seq)
#define vatomic32_await_counter_neq_rel                                        \
	__ATOMIC_ENAME(vatomic32_await_counter_neq, mo_seq)
#define vatomic32_await_counter_neq_rlx                                        \
	__ATOMIC_ENAME(vatomic32_await_counter_neq, mo_seq)

#define vatomic32_await_mask_eq __ATOMIC_ENAME(vatomic32_await_mask_eq, mo_seq)
#define vatomic32_await_mask_eq_acq                                            \
	__ATOMIC_ENAME(vatomic32_await_mask_eq, mo_seq)
#define vatomic32_await_mask_eq_rel                                            \
	__ATOMIC_ENAME(vatomic32_await_mask_eq, mo_seq)
#define vatomic32_await_mask_eq_rlx                                            \
	__ATOMIC_ENAME(vatomic32_await_mask_eq, mo_seq)

#define vatomic32_await_mask_neq                                               \
	__ATOMIC_ENAME(vatomic32_await_mask_neq, mo_seq)
#define vatomic32_await_mask_neq_acq                                           \
	__ATOMIC_ENAME(vatomic32_await_mask_neq, mo_seq)
#define vatomic32_await_mask_neq_rel                                           \
	__ATOMIC_ENAME(vatomic32_await_mask_neq, mo_seq)
#define vatomic32_await_mask_neq_rlx                                           \
	__ATOMIC_ENAME(vatomic32_await_mask_neq, mo_seq)

// vatomic64
#define vatomic64_read_rlx __ATOMIC_ENAME(vatomic64_read, mo_seq)
#define vatomic64_read_acq __ATOMIC_ENAME(vatomic64_read, mo_seq)

#define vatomic64_write_rlx __ATOMIC_ENAME(vatomic64_write, mo_seq)
#define vatomic64_write_rel __ATOMIC_ENAME(vatomic64_write, mo_seq)

#define vatomic64_xchg_rlx __ATOMIC_ENAME(vatomic64_xchg, mo_seq)
#define vatomic64_xchg_rel __ATOMIC_ENAME(vatomic64_xchg, mo_seq)
#define vatomic64_xchg_acq __ATOMIC_ENAME(vatomic64_xchg, mo_seq)

#define vatomic64_cmpxchg_rlx __ATOMIC_ENAME(vatomic64_cmpxchg, mo_seq)
#define vatomic64_cmpxchg_rel __ATOMIC_ENAME(vatomic64_cmpxchg, mo_seq)
#define vatomic64_cmpxchg_acq __ATOMIC_ENAME(vatomic64_cmpxchg, mo_seq)

#define vatomic64_get_or_rlx __ATOMIC_ENAME(vatomic64_get_or, mo_seq)
#define vatomic64_get_or_rel __ATOMIC_ENAME(vatomic64_get_or, mo_seq)
#define vatomic64_get_or_acq __ATOMIC_ENAME(vatomic64_get_or, mo_seq)

#define vatomic64_or_rlx __ATOMIC_ENAME(vatomic64_or, mo_seq)
#define vatomic64_or_rel __ATOMIC_ENAME(vatomic64_or, mo_seq)
#define vatomic64_or_acq __ATOMIC_ENAME(vatomic64_or, mo_seq)

#define vatomic64_and_rlx __ATOMIC_ENAME(vatomic64_and, mo_seq)
#define vatomic64_and_rel __ATOMIC_ENAME(vatomic64_and, mo_seq)
#define vatomic64_and_acq __ATOMIC_ENAME(vatomic64_and, mo_seq)

#define vatomic64_get_add_rlx __ATOMIC_ENAME(vatomic64_get_add, mo_seq)
#define vatomic64_get_add_rel __ATOMIC_ENAME(vatomic64_get_add, mo_seq)
#define vatomic64_get_add_acq __ATOMIC_ENAME(vatomic64_get_add, mo_seq)

#define vatomic64_add_rlx __ATOMIC_ENAME(vatomic64_add, mo_seq)
#define vatomic64_add_rel __ATOMIC_ENAME(vatomic64_add, mo_seq)
#define vatomic64_add_acq __ATOMIC_ENAME(vatomic64_add, mo_seq)

#define vatomic64_get_inc_rlx __ATOMIC_ENAME(vatomic64_get_inc, mo_seq)
#define vatomic64_get_inc_rel __ATOMIC_ENAME(vatomic64_get_inc, mo_seq)
#define vatomic64_get_inc_acq __ATOMIC_ENAME(vatomic64_get_inc, mo_seq)

#define vatomic64_inc_rlx __ATOMIC_ENAME(vatomic64_inc, mo_seq)
#define vatomic64_inc_rel __ATOMIC_ENAME(vatomic64_inc, mo_seq)
#define vatomic64_inc_acq __ATOMIC_ENAME(vatomic64_inc, mo_seq)

#define vatomic64_get_sub_rlx __ATOMIC_ENAME(vatomic64_get_sub, mo_seq)
#define vatomic64_get_sub_rel __ATOMIC_ENAME(vatomic64_get_sub, mo_seq)
#define vatomic64_get_sub_acq __ATOMIC_ENAME(vatomic64_get_sub, mo_seq)

#define vatomic64_sub_rlx __ATOMIC_ENAME(vatomic64_sub, mo_seq)
#define vatomic64_sub_rel __ATOMIC_ENAME(vatomic64_sub, mo_seq)
#define vatomic64_sub_acq __ATOMIC_ENAME(vatomic64_sub, mo_seq)

#define vatomic64_get_dec_rlx __ATOMIC_ENAME(vatomic64_get_dec, mo_seq)
#define vatomic64_get_dec_rel __ATOMIC_ENAME(vatomic64_get_dec, mo_seq)
#define vatomic64_get_dec_acq __ATOMIC_ENAME(vatomic64_get_dec, mo_seq)

#define vatomic64_dec_rlx __ATOMIC_ENAME(vatomic64_dec, mo_seq)
#define vatomic64_dec_rel __ATOMIC_ENAME(vatomic64_dec, mo_seq)
#define vatomic64_dec_acq __ATOMIC_ENAME(vatomic64_dec, mo_seq)

#define vatomic64_await_eq_acq __ATOMIC_ENAME(vatomic64_await_eq, mo_seq)
#define vatomic64_await_eq_rel __ATOMIC_ENAME(vatomic64_await_eq, mo_seq)
#define vatomic64_await_eq_rlx __ATOMIC_ENAME(vatomic64_await_eq, mo_seq)

#define vatomic64_await_neq_acq __ATOMIC_ENAME(vatomic64_await_neq, mo_seq)
#define vatomic64_await_neq_rel __ATOMIC_ENAME(vatomic64_await_neq, mo_seq)
#define vatomic64_await_neq_rlx __ATOMIC_ENAME(vatomic64_await_neq, mo_seq)

#define vatomic64_await_eq_set_seq                                             \
	__ATOMIC_ENAME(vatomic64_await_eq_set, mo_seq)
#define vatomic64_await_eq_set_acq                                             \
	__ATOMIC_ENAME(vatomic64_await_eq_set, mo_seq)
#define vatomic64_await_eq_set_rel                                             \
	__ATOMIC_ENAME(vatomic64_await_eq_set, mo_seq)
#define vatomic64_await_eq_set_rlx                                             \
	__ATOMIC_ENAME(vatomic64_await_eq_set, mo_seq)

#define vatomic64_await_ge_sub_seq                                             \
	__ATOMIC_ENAME(vatomic64_await_ge_sub, mo_seq)
#define vatomic64_await_ge_sub_acq                                             \
	__ATOMIC_ENAME(vatomic64_await_ge_sub, mo_seq)
#define vatomic64_await_ge_sub_rel                                             \
	__ATOMIC_ENAME(vatomic64_await_ge_sub, mo_seq)
#define vatomic64_await_ge_sub_rlx                                             \
	__ATOMIC_ENAME(vatomic64_await_ge_sub, mo_seq)

// vatomicptr
#define vatomicptr_read_rlx __ATOMIC_ENAME(vatomicptr_read, mo_seq)
#define vatomicptr_read_acq __ATOMIC_ENAME(vatomicptr_read, mo_seq)

#define vatomicptr_write_rlx __ATOMIC_ENAME(vatomicptr_write, mo_seq)
#define vatomicptr_write_rel __ATOMIC_ENAME(vatomicptr_write, mo_seq)

#define vatomicptr_xchg_rlx __ATOMIC_ENAME(vatomicptr_xchg, mo_seq)
#define vatomicptr_xchg_rel __ATOMIC_ENAME(vatomicptr_xchg, mo_seq)
#define vatomicptr_xchg_acq __ATOMIC_ENAME(vatomicptr_xchg, mo_seq)

#define vatomicptr_cmpxchg_rlx __ATOMIC_ENAME(vatomicptr_cmpxchg, mo_seq)
#define vatomicptr_cmpxchg_rel __ATOMIC_ENAME(vatomicptr_cmpxchg, mo_seq)
#define vatomicptr_cmpxchg_acq __ATOMIC_ENAME(vatomicptr_cmpxchg, mo_seq)

#define vatomicptr_get_or_rlx __ATOMIC_ENAME(vatomicptr_get_or, mo_seq)
#define vatomicptr_get_or_rel __ATOMIC_ENAME(vatomicptr_get_or, mo_seq)
#define vatomicptr_get_or_acq __ATOMIC_ENAME(vatomicptr_get_or, mo_seq)

#define vatomicptr_or_rlx __ATOMIC_ENAME(vatomicptr_or, mo_seq)
#define vatomicptr_or_rel __ATOMIC_ENAME(vatomicptr_or, mo_seq)
#define vatomicptr_or_acq __ATOMIC_ENAME(vatomicptr_or, mo_seq)

#define vatomicptr_and_rlx __ATOMIC_ENAME(vatomicptr_and, mo_seq)
#define vatomicptr_and_rel __ATOMIC_ENAME(vatomicptr_and, mo_seq)
#define vatomicptr_and_acq __ATOMIC_ENAME(vatomicptr_and, mo_seq)

#define vatomicptr_get_add_rlx __ATOMIC_ENAME(vatomicptr_get_add, mo_seq)
#define vatomicptr_get_add_rel __ATOMIC_ENAME(vatomicptr_get_add, mo_seq)
#define vatomicptr_get_add_acq __ATOMIC_ENAME(vatomicptr_get_add, mo_seq)

#define vatomicptr_add_rlx __ATOMIC_ENAME(vatomicptr_add, mo_seq)
#define vatomicptr_add_rel __ATOMIC_ENAME(vatomicptr_add, mo_seq)
#define vatomicptr_add_acq __ATOMIC_ENAME(vatomicptr_add, mo_seq)

#define vatomicptr_get_inc_rlx __ATOMIC_ENAME(vatomicptr_get_inc, mo_seq)
#define vatomicptr_get_inc_rel __ATOMIC_ENAME(vatomicptr_get_inc, mo_seq)
#define vatomicptr_get_inc_acq __ATOMIC_ENAME(vatomicptr_get_inc, mo_seq)

#define vatomicptr_inc_rlx __ATOMIC_ENAME(vatomicptr_inc, mo_seq)
#define vatomicptr_inc_rel __ATOMIC_ENAME(vatomicptr_inc, mo_seq)
#define vatomicptr_inc_acq __ATOMIC_ENAME(vatomicptr_inc, mo_seq)

#define vatomicptr_get_sub_rlx __ATOMIC_ENAME(vatomicptr_get_sub, mo_seq)
#define vatomicptr_get_sub_rel __ATOMIC_ENAME(vatomicptr_get_sub, mo_seq)
#define vatomicptr_get_sub_acq __ATOMIC_ENAME(vatomicptr_get_sub, mo_seq)

#define vatomicptr_sub_rlx __ATOMIC_ENAME(vatomicptr_sub, mo_seq)
#define vatomicptr_sub_rel __ATOMIC_ENAME(vatomicptr_sub, mo_seq)
#define vatomicptr_sub_acq __ATOMIC_ENAME(vatomicptr_sub, mo_seq)

#define vatomicptr_get_dec_rlx __ATOMIC_ENAME(vatomicptr_get_dec, mo_seq)
#define vatomicptr_get_dec_rel __ATOMIC_ENAME(vatomicptr_get_dec, mo_seq)
#define vatomicptr_get_dec_acq __ATOMIC_ENAME(vatomicptr_get_dec, mo_seq)

#define vatomicptr_dec_rlx __ATOMIC_ENAME(vatomicptr_dec, mo_seq)
#define vatomicptr_dec_rel __ATOMIC_ENAME(vatomicptr_dec, mo_seq)
#define vatomicptr_dec_acq __ATOMIC_ENAME(vatomicptr_dec, mo_seq)

#define vatomicptr_await_eq_acq __ATOMIC_ENAME(vatomicptr_await_eq, mo_seq)
#define vatomicptr_await_eq_rel __ATOMIC_ENAME(vatomicptr_await_eq, mo_seq)
#define vatomicptr_await_eq_rlx __ATOMIC_ENAME(vatomicptr_await_eq, mo_seq)

#define vatomicptr_await_neq_acq __ATOMIC_ENAME(vatomicptr_await_neq, mo_seq)
#define vatomicptr_await_neq_rel __ATOMIC_ENAME(vatomicptr_await_neq, mo_seq)
#define vatomicptr_await_neq_rlx __ATOMIC_ENAME(vatomicptr_await_neq, mo_seq)

#define vatomicptr_await_eq_set_seq                                            \
	__ATOMIC_ENAME(vatomicptr_await_eq_set, mo_seq)
#define vatomicptr_await_eq_set_acq                                            \
	__ATOMIC_ENAME(vatomicptr_await_eq_set, mo_seq)
#define vatomicptr_await_eq_set_rel                                            \
	__ATOMIC_ENAME(vatomicptr_await_eq_set, mo_seq)
#define vatomicptr_await_eq_set_rlx                                            \
	__ATOMIC_ENAME(vatomicptr_await_eq_set, mo_seq)

#define vatomicptr_await_ge_sub_seq                                            \
	__ATOMIC_ENAME(vatomicptr_await_ge_sub, mo_seq)
#define vatomicptr_await_ge_sub_acq                                            \
	__ATOMIC_ENAME(vatomicptr_await_ge_sub, mo_seq)
#define vatomicptr_await_ge_sub_rel                                            \
	__ATOMIC_ENAME(vatomicptr_await_ge_sub, mo_seq)
#define vatomicptr_await_ge_sub_rlx                                            \
	__ATOMIC_ENAME(vatomicptr_await_ge_sub, mo_seq)

#endif

/*******************************************************************************
 * mapping of atomic prefix to vatomic prefix
 ******************************************************************************/
#ifdef VSYNC_MAP_ATOMICS
#define ATOMIC_INIT VATOMIC_INIT
#define atomicptr(v) vatomicptr(v)

#define atomic_t vatomic32_t
#define atomic32_t vatomic32_t
#define atomic64_t vatomic64_t
#define atomicptr_t vatomicptr_t

#undef atomic_init
#define atomic_init vatomic32_init
#define atomic32_init vatomic32_init
#define atomic64_init vatomic64_init
#define atomicptr_init vatomicptr_init

#define atomic_read vatomic32_read
#define atomic32_read vatomic32_read
#define atomic64_read vatomic64_read
#define atomicptr_read vatomicptr_read
#define atomic_read_rlx vatomic32_read_rlx
#define atomic32_read_rlx vatomic32_read_rlx
#define atomic64_read_rlx vatomic64_read_rlx
#define atomicptr_read_rlx vatomicptr_read_rlx
#define atomic_read_acq vatomic32_read_acq
#define atomic32_read_acq vatomic32_read_acq
#define atomic64_read_acq vatomic64_read_acq
#define atomicptr_read_acq vatomicptr_read_acq

#define atomic_write vatomic32_write
#define atomic32_write vatomic32_write
#define atomic64_write vatomic64_write
#define atomicptr_write vatomicptr_write
#define atomic_write_rlx vatomic32_write_rlx
#define atomic32_write_rlx vatomic32_write_rlx
#define atomic64_write_rlx vatomic64_write_rlx
#define atomicptr_write_rlx vatomicptr_write_rlx
#define atomic_write_rel vatomic32_write_rel
#define atomic32_write_rel vatomic32_write_rel
#define atomic64_write_rel vatomic64_write_rel
#define atomicptr_write_rel vatomicptr_write_rel

#define atomic_xchg vatomic32_xchg
#define atomic32_xchg vatomic32_xchg
#define atomic64_xchg vatomic64_xchg
#define atomicptr_xchg vatomicptr_xchg
#define atomic_xchg_rlx vatomic32_xchg_rlx
#define atomic32_xchg_rlx vatomic32_xchg_rlx
#define atomic64_xchg_rlx vatomic64_xchg_rlx
#define atomicptr_xchg_rlx vatomicptr_xchg_rlx
#define atomic_xchg_rel vatomic32_xchg_rel
#define atomic32_xchg_rel vatomic32_xchg_rel
#define atomic64_xchg_rel vatomic64_xchg_rel
#define atomicptr_xchg_rel vatomicptr_xchg_rel
#define atomic_xchg_acq vatomic32_xchg_acq
#define atomic32_xchg_acq vatomic32_xchg_acq
#define atomic64_xchg_acq vatomic64_xchg_acq
#define atomicptr_xchg_acq vatomicptr_xchg_acq

#define atomic_cmpxchg vatomic32_cmpxchg
#define atomic32_cmpxchg vatomic32_cmpxchg
#define atomic64_cmpxchg vatomic64_cmpxchg
#define atomicptr_cmpxchg vatomicptr_cmpxchg
#define atomic_cmpxchg_rlx vatomic32_cmpxchg_rlx
#define atomic32_cmpxchg_rlx vatomic32_cmpxchg_rlx
#define atomic64_cmpxchg_rlx vatomic64_cmpxchg_rlx
#define atomicptr_cmpxchg_rlx vatomicptr_cmpxchg_rlx
#define atomic_cmpxchg_rel vatomic32_cmpxchg_rel
#define atomic32_cmpxchg_rel vatomic32_cmpxchg_rel
#define atomic64_cmpxchg_rel vatomic64_cmpxchg_rel
#define atomicptr_cmpxchg_rel vatomicptr_cmpxchg_rel
#define atomic_cmpxchg_acq vatomic32_cmpxchg_acq
#define atomic32_cmpxchg_acq vatomic32_cmpxchg_acq
#define atomic64_cmpxchg_acq vatomic64_cmpxchg_acq
#define atomicptr_cmpxchg_acq vatomicptr_cmpxchg_acq

#define atomic_get_add vatomic32_get_add
#define atomic32_get_add vatomic32_get_add
#define atomic64_get_add vatomic64_get_add
#define atomicptr_get_add vatomicptr_get_add
#define atomic_get_add_rlx vatomic32_get_add_rlx
#define atomic32_get_add_rlx vatomic32_get_add_rlx
#define atomic64_get_add_rlx vatomic64_get_add_rlx
#define atomicptr_get_add_rlx vatomicptr_get_add_rlx
#define atomic_get_add_rel vatomic32_get_add_rel
#define atomic32_get_add_rel vatomic32_get_add_rel
#define atomic64_get_add_rel vatomic64_get_add_rel
#define atomicptr_get_add_rel vatomicptr_get_add_rel
#define atomic_get_add_acq vatomic32_get_add_acq
#define atomic32_get_add_acq vatomic32_get_add_acq
#define atomic64_get_add_acq vatomic64_get_add_acq
#define atomicptr_get_add_acq vatomicptr_get_add_acq

#define atomic_add vatomic32_add
#define atomic32_add vatomic32_add
#define atomic64_add vatomic64_add
#define atomicptr_add vatomicptr_add
#define atomic_add_rlx vatomic32_add_rlx
#define atomic32_add_rlx vatomic32_add_rlx
#define atomic64_add_rlx vatomic64_add_rlx
#define atomicptr_add_rlx vatomicptr_add_rlx
#define atomic_add_rel vatomic32_add_rel
#define atomic32_add_rel vatomic32_add_rel
#define atomic64_add_rel vatomic64_add_rel
#define atomicptr_add_rel vatomicptr_add_rel
#define atomic_add_acq vatomic32_add_acq
#define atomic32_add_acq vatomic32_add_acq
#define atomic64_add_acq vatomic64_add_acq
#define atomicptr_add_acq vatomicptr_add_acq

#define atomic_get_inc vatomic32_get_inc
#define atomic32_get_inc vatomic32_get_inc
#define atomic64_get_inc vatomic64_get_inc
#define atomicptr_get_inc vatomicptr_get_inc
#define atomic_get_inc_rlx vatomic32_get_inc_rlx
#define atomic32_get_inc_rlx vatomic32_get_inc_rlx
#define atomic64_get_inc_rlx vatomic64_get_inc_rlx
#define atomicptr_get_inc_rlx vatomicptr_get_inc_rlx
#define atomic_get_inc_rel vatomic32_get_inc_rel
#define atomic32_get_inc_rel vatomic32_get_inc_rel
#define atomic64_get_inc_rel vatomic64_get_inc_rel
#define atomicptr_get_inc_rel vatomicptr_get_inc_rel
#define atomic_get_inc_acq vatomic32_get_inc_acq
#define atomic32_get_inc_acq vatomic32_get_inc_acq
#define atomic64_get_inc_acq vatomic64_get_inc_acq
#define atomicptr_get_inc_acq vatomicptr_get_inc_acq

#define atomic_inc vatomic32_inc
#define atomic32_inc vatomic32_inc
#define atomic64_inc vatomic64_inc
#define atomicptr_inc vatomicptr_inc
#define atomic_inc_rlx vatomic32_inc_rlx
#define atomic32_inc_rlx vatomic32_inc_rlx
#define atomic64_inc_rlx vatomic64_inc_rlx
#define atomicptr_inc_rlx vatomicptr_inc_rlx
#define atomic_inc_rel vatomic32_inc_rel
#define atomic32_inc_rel vatomic32_inc_rel
#define atomic64_inc_rel vatomic64_inc_rel
#define atomicptr_inc_rel vatomicptr_inc_rel
#define atomic_inc_acq vatomic32_inc_acq
#define atomic32_inc_acq vatomic32_inc_acq
#define atomic64_inc_acq vatomic64_inc_acq
#define atomicptr_inc_acq vatomicptr_inc_acq

#define atomic_get_sub vatomic32_get_sub
#define atomic32_get_sub vatomic32_get_sub
#define atomic64_get_sub vatomic64_get_sub
#define atomicptr_get_sub vatomicptr_get_sub
#define atomic_get_sub_rlx vatomic32_get_sub_rlx
#define atomic32_get_sub_rlx vatomic32_get_sub_rlx
#define atomic64_get_sub_rlx vatomic64_get_sub_rlx
#define atomicptr_get_sub_rlx vatomicptr_get_sub_rlx
#define atomic_get_sub_rel vatomic32_get_sub_rel
#define atomic32_get_sub_rel vatomic32_get_sub_rel
#define atomic64_get_sub_rel vatomic64_get_sub_rel
#define atomicptr_get_sub_rel vatomicptr_get_sub_rel
#define atomic_get_sub_acq vatomic32_get_sub_acq
#define atomic32_get_sub_acq vatomic32_get_sub_acq
#define atomic64_get_sub_acq vatomic64_get_sub_acq
#define atomicptr_get_sub_acq vatomicptr_get_sub_acq

#define atomic_sub vatomic32_sub
#define atomic32_sub vatomic32_sub
#define atomic64_sub vatomic64_sub
#define atomicptr_sub vatomicptr_sub
#define atomic_sub_rlx vatomic32_sub_rlx
#define atomic32_sub_rlx vatomic32_sub_rlx
#define atomic64_sub_rlx vatomic64_sub_rlx
#define atomicptr_sub_rlx vatomicptr_sub_rlx
#define atomic_sub_rel vatomic32_sub_rel
#define atomic32_sub_rel vatomic32_sub_rel
#define atomic64_sub_rel vatomic64_sub_rel
#define atomicptr_sub_rel vatomicptr_sub_rel
#define atomic_sub_acq vatomic32_sub_acq
#define atomic32_sub_acq vatomic32_sub_acq
#define atomic64_sub_acq vatomic64_sub_acq
#define atomicptr_sub_acq vatomicptr_sub_acq

#define atomic_get_dec vatomic32_get_dec
#define atomic32_get_dec vatomic32_get_dec
#define atomic64_get_dec vatomic64_get_dec
#define atomicptr_get_dec vatomicptr_get_dec
#define atomic_get_dec_rlx vatomic32_get_dec_rlx
#define atomic32_get_dec_rlx vatomic32_get_dec_rlx
#define atomic64_get_dec_rlx vatomic64_get_dec_rlx
#define atomicptr_get_dec_rlx vatomicptr_get_dec_rlx
#define atomic_get_dec_rel vatomic32_get_dec_rel
#define atomic32_get_dec_rel vatomic32_get_dec_rel
#define atomic64_get_dec_rel vatomic64_get_dec_rel
#define atomicptr_get_dec_rel vatomicptr_get_dec_rel
#define atomic_get_dec_acq vatomic32_get_dec_acq
#define atomic32_get_dec_acq vatomic32_get_dec_acq
#define atomic64_get_dec_acq vatomic64_get_dec_acq
#define atomicptr_get_dec_acq vatomicptr_get_dec_acq

#define atomic_dec vatomic32_dec
#define atomic32_dec vatomic32_dec
#define atomic64_dec vatomic64_dec
#define atomicptr_dec vatomicptr_dec
#define atomic_dec_rlx vatomic32_dec_rlx
#define atomic32_dec_rlx vatomic32_dec_rlx
#define atomic64_dec_rlx vatomic64_dec_rlx
#define atomicptr_dec_rlx vatomicptr_dec_rlx
#define atomic_dec_rel vatomic32_dec_rel
#define atomic32_dec_rel vatomic32_dec_rel
#define atomic64_dec_rel vatomic64_dec_rel
#define atomicptr_dec_rel vatomicptr_dec_rel
#define atomic_dec_acq vatomic32_dec_acq
#define atomic32_dec_acq vatomic32_dec_acq
#define atomic64_dec_acq vatomic64_dec_acq
#define atomicptr_dec_acq vatomicptr_dec_acq

#define atomic_get_and vatomic32_get_and
#define atomic32_get_and vatomic32_get_and
#define atomic64_get_and vatomic64_get_and
#define atomicptr_get_and vatomicptr_get_and
#define atomic_get_and_rlx vatomic32_get_and_rlx
#define atomic32_get_and_rlx vatomic32_get_and_rlx
#define atomic64_get_and_rlx vatomic64_get_and_rlx
#define atomicptr_get_and_rlx vatomicptr_get_and_rlx
#define atomic_get_and_rel vatomic32_get_and_rel
#define atomic32_get_and_rel vatomic32_get_and_rel
#define atomic64_get_and_rel vatomic64_get_and_rel
#define atomicptr_get_and_rel vatomicptr_get_and_rel
#define atomic_get_and_acq vatomic32_get_and_acq
#define atomic32_get_and_acq vatomic32_get_and_acq
#define atomic64_get_and_acq vatomic64_get_and_acq
#define atomicptr_get_and_acq vatomicptr_get_and_acq

#define atomic_and vatomic32_and
#define atomic32_and vatomic32_and
#define atomic64_and vatomic64_and
#define atomicptr_and vatomicptr_and
#define atomic_and_rlx vatomic32_and_rlx
#define atomic32_and_rlx vatomic32_and_rlx
#define atomic64_and_rlx vatomic64_and_rlx
#define atomicptr_and_rlx vatomicptr_and_rlx
#define atomic_and_rel vatomic32_and_rel
#define atomic32_and_rel vatomic32_and_rel
#define atomic64_and_rel vatomic64_and_rel
#define atomicptr_and_rel vatomicptr_and_rel
#define atomic_and_acq vatomic32_and_acq
#define atomic32_and_acq vatomic32_and_acq
#define atomic64_and_acq vatomic64_and_acq
#define atomicptr_and_acq vatomicptr_and_acq

#define atomic_get_or vatomic32_get_or
#define atomic32_get_or vatomic32_get_or
#define atomic64_get_or vatomic64_get_or
#define atomicptr_get_or vatomicptr_get_or
#define atomic_get_or_rlx vatomic32_get_or_rlx
#define atomic32_get_or_rlx vatomic32_get_or_rlx
#define atomic64_get_or_rlx vatomic64_get_or_rlx
#define atomicptr_get_or_rlx vatomicptr_get_or_rlx
#define atomic_get_or_rel vatomic32_get_or_rel
#define atomic32_get_or_rel vatomic32_get_or_rel
#define atomic64_get_or_rel vatomic64_get_or_rel
#define atomicptr_get_or_rel vatomicptr_get_or_rel
#define atomic_get_or_acq vatomic32_get_or_acq
#define atomic32_get_or_acq vatomic32_get_or_acq
#define atomic64_get_or_acq vatomic64_get_or_acq
#define atomicptr_get_or_acq vatomicptr_get_or_acq

#define atomic_or vatomic32_or
#define atomic32_or vatomic32_or
#define atomic64_or vatomic64_or
#define atomicptr_or vatomicptr_or
#define atomic_or_rlx vatomic32_or_rlx
#define atomic32_or_rlx vatomic32_or_rlx
#define atomic64_or_rlx vatomic64_or_rlx
#define atomicptr_or_rlx vatomicptr_or_rlx
#define atomic_or_rel vatomic32_or_rel
#define atomic32_or_rel vatomic32_or_rel
#define atomic64_or_rel vatomic64_or_rel
#define atomicptr_or_rel vatomicptr_or_rel
#define atomic_or_acq vatomic32_or_acq
#define atomic32_or_acq vatomic32_or_acq
#define atomic64_or_acq vatomic64_or_acq
#define atomicptr_or_acq vatomicptr_or_acq

#define atomic_await_eq vatomic32_await_eq
#define atomic32_await_eq vatomic32_await_eq
#define atomic64_await_eq vatomic64_await_eq
#define atomicptr_await_eq vatomicptr_await_eq
#define atomic_await_eq_acq vatomic32_await_eq_acq
#define atomic32_await_eq_acq vatomic32_await_eq_acq
#define atomic64_await_eq_acq vatomic64_await_eq_acq
#define atomicptr_await_eq_acq vatomicptr_await_eq_acq
#define atomic_await_eq_rel vatomic32_await_eq_rel
#define atomic32_await_eq_rel vatomic32_await_eq_rel
#define atomic64_await_eq_rel vatomic64_await_eq_rel
#define atomicptr_await_eq_rel vatomicptr_await_eq_rel
#define atomic_await_eq_rlx vatomic32_await_eq_rlx
#define atomic32_await_eq_rlx vatomic32_await_eq_rlx
#define atomic64_await_eq_rlx vatomic64_await_eq_rlx
#define atomicptr_await_eq_rlx vatomicptr_await_eq_rlx

#define atomic_await_gt vatomic32_await_gt
#define atomic32_await_gt vatomic32_await_gt
#define atomic64_await_gt vatomic64_await_gt
#define atomicptr_await_gt vatomicptr_await_gt
#define atomic_await_gt_acq vatomic32_await_gt_acq
#define atomic32_await_gt_acq vatomic32_await_gt_acq
#define atomic64_await_gt_acq vatomic64_await_gt_acq
#define atomicptr_await_gt_acq vatomicptr_await_gt_acq
#define atomic_await_gt_rel vatomic32_await_gt_rel
#define atomic32_await_gt_rel vatomic32_await_gt_rel
#define atomic64_await_gt_rel vatomic64_await_gt_rel
#define atomicptr_await_gt_rel vatomicptr_await_gt_rel
#define atomic_await_gt_rlx vatomic32_await_gt_rlx
#define atomic32_await_gt_rlx vatomic32_await_gt_rlx
#define atomic64_await_gt_rlx vatomic64_await_gt_rlx
#define atomicptr_await_gt_rlx vatomicptr_await_gt_rlx

#define atomic_await_neq vatomic32_await_neq
#define atomic32_await_neq vatomic32_await_neq
#define atomic64_await_neq vatomic64_await_neq
#define atomicptr_await_neq vatomicptr_await_neq
#define atomic_await_neq_acq vatomic32_await_neq_acq
#define atomic32_await_neq_acq vatomic32_await_neq_acq
#define atomic64_await_neq_acq vatomic64_await_neq_acq
#define atomicptr_await_neq_acq vatomicptr_await_neq_acq
#define atomic_await_neq_rel vatomic32_await_neq_rel
#define atomic32_await_neq_rel vatomic32_await_neq_rel
#define atomic64_await_neq_rel vatomic64_await_neq_rel
#define atomicptr_await_neq_rel vatomicptr_await_neq_rel
#define atomic_await_neq_rlx vatomic32_await_neq_rlx
#define atomic32_await_neq_rlx vatomic32_await_neq_rlx
#define atomic64_await_neq_rlx vatomic64_await_neq_rlx
#define atomicptr_await_neq_rlx vatomicptr_await_neq_rlx

#define atomic_await_ge_sub vatomic32_await_ge_sub
#define atomic32_await_ge_sub vatomic32_await_ge_sub
#define atomic64_await_ge_sub vatomic64_await_ge_sub
#define atomicptr_await_ge_sub vatomicptr_await_ge_sub
#define atomic_await_ge_sub_acq vatomic32_await_ge_sub_acq
#define atomic32_await_ge_sub_acq vatomic32_await_ge_sub_acq
#define atomic64_await_ge_sub_acq vatomic64_await_ge_sub_acq
#define atomicptr_await_ge_sub_acq vatomicptr_await_ge_sub_acq
#define atomic_await_ge_sub_rel vatomic32_await_ge_sub_rel
#define atomic32_await_ge_sub_rel vatomic32_await_ge_sub_rel
#define atomic64_await_ge_sub_rel vatomic64_await_ge_sub_rel
#define atomicptr_await_ge_sub_rel vatomicptr_await_ge_sub_rel
#define atomic_await_ge_sub_rlx vatomic32_await_ge_sub_rlx
#define atomic32_await_ge_sub_rlx vatomic32_await_ge_sub_rlx
#define atomic64_await_ge_sub_rlx vatomic64_await_ge_sub_rlx
#define atomicptr_await_ge_sub_rlx vatomicptr_await_ge_sub_rlx

#define atomic_await_eq_set vatomic32_await_eq_set
#define atomic32_await_eq_set vatomic32_await_eq_set
#define atomic64_await_eq_set vatomic64_await_eq_set
#define atomicptr_await_eq_set vatomicptr_await_eq_set
#define atomic_await_eq_set_acq vatomic32_await_eq_set_acq
#define atomic32_await_eq_set_acq vatomic32_await_eq_set_acq
#define atomic64_await_eq_set_acq vatomic64_await_eq_set_acq
#define atomicptr_await_eq_set_acq vatomicptr_await_eq_set_acq
#define atomic_await_eq_set_rel vatomic32_await_eq_set_rel
#define atomic32_await_eq_set_rel vatomic32_await_eq_set_rel
#define atomic64_await_eq_set_rel vatomic64_await_eq_set_rel
#define atomicptr_await_eq_set_rel vatomicptr_await_eq_set_rel
#define atomic_await_eq_set_rlx vatomic32_await_eq_set_rlx
#define atomic32_await_eq_set_rlx vatomic32_await_eq_set_rlx
#define atomic64_await_eq_set_rlx vatomic64_await_eq_set_rlx
#define atomicptr_await_eq_set_rlx vatomicptr_await_eq_set_rlx

#define atomic_await_counter_neq vatomic32_await_counter_neq
#define atomic32_await_counter_neq vatomic32_await_counter_neq
#define atomic64_await_counter_neq vatomic64_await_counter_neq
#define atomicptr_await_counter_neq vatomicptr_await_counter_neq
#define atomic_await_counter_neq_acq vatomic32_await_counter_neq_acq
#define atomic32_await_counter_neq_acq vatomic32_await_counter_neq_acq
#define atomic64_await_counter_neq_acq vatomic64_await_counter_neq_acq
#define atomicptr_await_counter_neq_acq vatomicptr_await_counter_neq_acq
#define atomic_await_counter_neq_rel vatomic32_await_counter_neq_rel
#define atomic32_await_counter_neq_rel vatomic32_await_counter_neq_rel
#define atomic64_await_counter_neq_rel vatomic64_await_counter_neq_rel
#define atomicptr_await_counter_neq_rel vatomicptr_await_counter_neq_rel
#define atomic_await_counter_neq_rlx vatomic32_await_counter_neq_rlx
#define atomic32_await_counter_neq_rlx vatomic32_await_counter_neq_rlx
#define atomic64_await_counter_neq_rlx vatomic64_await_counter_neq_rlx
#define atomicptr_await_counter_neq_rlx vatomicptr_await_counter_neq_rlx

#define atomic_await_mask_eq vatomic32_await_mask_eq
#define atomic32_await_mask_eq vatomic32_await_mask_eq
#define atomic64_await_mask_eq vatomic64_await_mask_eq
#define atomicptr_await_mask_eq vatomicptr_await_mask_eq
#define atomic_await_mask_eq_acq vatomic32_await_mask_eq_acq
#define atomic32_await_mask_eq_acq vatomic32_await_mask_eq_acq
#define atomic64_await_mask_eq_acq vatomic64_await_mask_eq_acq
#define atomicptr_await_mask_eq_acq vatomicptr_await_mask_eq_acq
#define atomic_await_mask_eq_rel vatomic32_await_mask_eq_rel
#define atomic32_await_mask_eq_rel vatomic32_await_mask_eq_rel
#define atomic64_await_mask_eq_rel vatomic64_await_mask_eq_rel
#define atomicptr_await_mask_eq_rel vatomicptr_await_mask_eq_rel
#define atomic_await_mask_eq_rlx vatomic32_await_mask_eq_rlx
#define atomic32_await_mask_eq_rlx vatomic32_await_mask_eq_rlx
#define atomic64_await_mask_eq_rlx vatomic64_await_mask_eq_rlx
#define atomicptr_await_mask_eq_rlx vatomicptr_await_mask_eq_rlx

#define atomic_await_mask_neq vatomic32_await_mask_neq
#define atomic32_await_mask_neq vatomic32_await_mask_neq
#define atomic64_await_mask_neq vatomic64_await_mask_neq
#define atomicptr_await_mask_neq vatomicptr_await_mask_neq
#define atomic_await_mask_neq_acq vatomic32_await_mask_neq_acq
#define atomic32_await_mask_neq_acq vatomic32_await_mask_neq_acq
#define atomic64_await_mask_neq_acq vatomic64_await_mask_neq_acq
#define atomicptr_await_mask_neq_acq vatomicptr_await_mask_neq_acq
#define atomic_await_mask_neq_rel vatomic32_await_mask_neq_rel
#define atomic32_await_mask_neq_rel vatomic32_await_mask_neq_rel
#define atomic64_await_mask_neq_rel vatomic64_await_mask_neq_rel
#define atomicptr_await_mask_neq_rel vatomicptr_await_mask_neq_rel
#define atomic_await_mask_neq_rlx vatomic32_await_mask_neq_rlx
#define atomic32_await_mask_neq_rlx vatomic32_await_mask_neq_rlx
#define atomic64_await_mask_neq_rlx vatomic64_await_mask_neq_rlx
#define atomicptr_await_mask_neq_rlx vatomicptr_await_mask_neq_rlx

#define atomic_fence vatomic_fence
#define atomic_fence_acq vatomic_fence_acq
#define atomic_fence_rel vatomic_fence_rel
#define atomic_fence_rlx vatomic_fence_rlx

#define __VERIFIER_atomic_read_neq __VERIFIER_vatomic32_read_neq
#define __VERIFIER_atomic32_read_neq __VERIFIER_vatomic32_read_neq
#define __VERIFIER_atomic64_read_neq __VERIFIER_vatomic64_read_neq
#define __VERIFIER_atomicptr_read_neq __VERIFIER_vatomicptr_read_neq
#endif /* VSYNC_ATOMIC_MAP */

#endif
