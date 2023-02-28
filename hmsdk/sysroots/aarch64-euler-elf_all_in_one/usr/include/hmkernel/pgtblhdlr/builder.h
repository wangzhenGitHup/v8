/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Builder of page table handler functions
 * Author: Huawei OS Kernel Lab
 * Create: Sun Apr 04 12:34:46 2021
 */

#ifndef MAPI_UAPI_HMKERNEL_PGTBLHDLR_BUILDER_H
#define MAPI_UAPI_HMKERNEL_PGTBLHDLR_BUILDER_H

#ifndef __PGTBLHDLR_GENERATOR
# error mapi/uapi/pgtblhdlr.h should not be used standalone.
#endif

#include <hmkernel/types.h>
#include <hmkernel/const.h>
#include <hmkernel/memory.h>
#include <hmkernel/compiler.h>
#include <hmkernel/pgtblhdlr/naming.h>

#ifndef __pgtblhdlr_inline
# define __pgtblhdlr_inline inline __always_inline
#endif

#define __PGTBLHDLR_CODE
#include __PGTBL_DESC
#undef __PGTBLHDLR_CODE

/*
 * Undefine header guard so this header can be include multiple time.
 * Keep the guard to mute code scanner.
 */
#undef MAPI_UAPI_HMKERNEL_PGTBLHDLR_BUILDER_H

#define ____PGENTRY \
	__PGTBLHDLR_NAMING_LOWERCASE(pgentry_s)
#define ____PGENTRY_TYPE \
	__PGTBLHDLR_NAMING_LOWERCASE(pgentry_type_e)
#define ____PGCONFIG \
	__PGTBLHDLR_NAMING_LOWERCASE(pgcfg_s)
#define ____PGATTRIBUTE \
	__PGTBLHDLR_NAMING_LOWERCASE(pgattr_s)

#define PGTBLHDLR_RAWCFG(raw) struct __pgtblhdlr_rawcfg_##raw##_s;
#define PGTBLHDLR_RAWFMT(raw) struct __pgtblhdlr_rawfmt_##raw##_s;
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s)
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG

/*
 * pgentry_s is abstract type of a pagetable entry, which is
 * a union of possible physical page table entry pointer so
 * caller is able to fetch page table entry through:
 *
 * pgentry.u->__pgentry_arm_lv1[0]
 *
 * Internal type of union is pointer, so pass pgentry from argument,
 * donot use its pointer.
 */
struct ____PGENTRY {
	union {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw) struct __pgtblhdlr_rawfmt_##raw##_s *raw;
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s)
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
		void *invalid;
	} u;
};

/*
 * pgconfig_s is a wrapper to concrete rawcfg to uniform
 * typename. Do not need passing its pointer.
 */
struct ____PGCONFIG {
#define PGTBLHDLR_RAWCFG(raw) struct __pgtblhdlr_rawcfg_##raw##_s cfg;
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s)
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
};

/*
 * Key of type
 */
enum ____PGENTRY_TYPE {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s)	__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N),
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_INVALID),
};

enum ____PGENTRY_TYPE_NR {
	__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_NT_TYPES) = (unsigned int)__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_INVALID)
};

struct ____PGATTRIBUTE {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	struct __pgtblhdlr_rawfmt_##raw##_s tmpl_##n;
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
};

/*
 * is_present: check if the entry is specific type. PTE table type, check sec type,
 * return false
 * is_valid: check if the entry has a valid value for its level. PTE table type,
 * check sec type, return true
 * is_valid in descs should be adapted when the invalid formats are defined
 */
static __pgtblhdlr_inline __bool __PGTBLHDLR_NAMING_LOWERCASE(pgentry_is_valid)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg, struct ____PGENTRY e)
{
	__bool ret = __false;

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		ret = __pgtblhdlr_rawfmt_##raw##_is_valid(&cfg->cfg, e.u.raw); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	default:
		ret = false;
		break;
	}
	return ret;
}

static __pgtblhdlr_inline __bool __PGTBLHDLR_NAMING_LOWERCASE(pgentry_is_present)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg, struct ____PGENTRY e)
{
	__bool rc = __false;

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		rc = __pgtblhdlr_##n##_is_present(&cfg->cfg, e.u.raw); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	default:
		rc = false;
		break;
	}
	return rc;
}

/*
 * is_zero and is_present are different. is_zero can be used to determin if
 * this entry is empty. Some entry like ttbrreg is present even if it is zero.
 */
static __pgtblhdlr_inline __bool __PGTBLHDLR_NAMING_LOWERCASE(pgentry_is_zero)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg, struct ____PGENTRY e)
{
	__bool result = __false;

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		result = __pgtblhdlr_rawfmt_##raw##_is_zero(&cfg->cfg, e.u.raw); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	default:
		result = false;
		break;
	}
	return result;
}

static __pgtblhdlr_inline __bool __PGTBLHDLR_NAMING_LOWERCASE(pgentry_is_lastlv)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg)
{
	__bool res = __false;

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		res = __pgtblhdlr_##n##_is_lastlv(&cfg->cfg); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	default:
		res = false;
		break;
	}
	return res;
}

static __pgtblhdlr_inline unsigned long __PGTBLHDLR_NAMING_LOWERCASE(pgentry_tblidx_from_va)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg, __vaddr_t va)
{
	__vaddr_t res = (__vaddr_t)(va);

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		res = __pgtblhdlr_##n##_tblidx_from_va(&cfg->cfg, va); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	default:
		res = (__vaddr_t)(__UL(0));
		break;
	}
	return res;
}

static __pgtblhdlr_inline unsigned long __PGTBLHDLR_NAMING_LOWERCASE(pgentry_nr_tblidx)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg)
{
	return __PGTBLHDLR_NAMING_LOWERCASE(pgentry_tblidx_from_va)(t, cfg, __VADDR_T_MAX) + __UL(1);
}

static __pgtblhdlr_inline unsigned long __PGTBLHDLR_NAMING_LOWERCASE(pgentry_table_size)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg)
{
	unsigned long res = __UL(0);

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		unsigned long nr_entries = __pgtblhdlr_##n##_tblidx_from_va(&cfg->cfg, __VADDR_T_MAX) + __UL(1); \
		res = __pgtblhdlr_##n##_tblentry_size(&cfg->cfg) * nr_entries; \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	default:
		res = (__UL(0));
		break;
	}
	return res;
}

static __pgtblhdlr_inline paddr_t __PGTBLHDLR_NAMING_LOWERCASE(pgentry_decode_pa)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg, struct ____PGENTRY e)
{
	__paddr_t res;

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		res = __pgtblhdlr_##n##_decode_pa(&cfg->cfg, e.u.raw); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
	default:
		res = (__paddr_t)(__UL(0));
		break;
	}
	return res;
}

static __pgtblhdlr_inline unsigned long __PGTBLHDLR_NAMING_LOWERCASE(pgentry_va_align)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg)
{
	unsigned long align = __UL(0);

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		align = ((a) == 0) ? __pgtblhdlr_ttbrreg_va_align(&cfg->cfg) : (__UL(a)); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
	default:
		align = __UL(0);
		break;
	}
	return align;
}

static __pgtblhdlr_inline bool __PGTBLHDLR_NAMING_LOWERCASE(pgentry_va_is_aligned)
	(enum ____PGENTRY_TYPE t, __vaddr_t va_start, __vaddr_t va_end)
{
	bool aligned = false;

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		aligned = __pgtblhdlr_##n##_va_is_aligned(va_start, va_end); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
	default:
		aligned = false;
		break;
	}
	return aligned;
}

static __pgtblhdlr_inline unsigned long __PGTBLHDLR_NAMING_LOWERCASE(pgentry_va_size)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg)
{
	unsigned long sz = __UL(0);

	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		sz = ((s) == 0) ? __pgtblhdlr_ttbrreg_va_size(&cfg->cfg) : (__UL(s)); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
	default:
		sz = __UL(0);
		break;
	}
	return sz;
}

static __pgtblhdlr_inline unsigned long __PGTBLHDLR_NAMING_LOWERCASE(pgentry_nextlv_va_size)
	(enum ____PGENTRY_TYPE parent_type, struct ____PGCONFIG *cfg)
{
	unsigned long sz = __UL(0);

#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s)
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx) \
	if (parent_type == __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N) && \
		 __pgtblhdlr_##n##_accept_##nx(&cfg->cfg)) \
	{ \
		sz = __PGTBLHDLR_NAMING_LOWERCASE(pgentry_va_size)( \
		 __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##NX), cfg); \
		return sz; \
	}

#include __PGTBL_DESC

#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	return sz;
}

static __pgtblhdlr_inline enum ____PGENTRY_TYPE __PGTBLHDLR_NAMING_LOWERCASE(pgentry_lookup_nextlv)
	(struct ____PGCONFIG *cfg, struct ____PGENTRY *p_next_entry,
	 enum ____PGENTRY_TYPE curr_type, struct ____PGENTRY curr_entry,
	 void *_table, unsigned long idx)
{
	enum ____PGENTRY_TYPE next_type = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_INVALID);

	if (__false) {
	}
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s)
	/* use else to help gcc optimization. One may think we
	 * can make this macro looks better by setting
	 * an indicator:
	 * if (!found) {
	 *     ....
	 *     if (match_a()) {
	 *         found = true;
	 *     }
	 * }
	 * if (!found) {
	 *     ....
	 *     if (match_b()) {
	 *         found = true;
	 *     }
	 * }
	 *
	 * However, it prevent gcc optimizing because 'found' is set in
	 * a different levelanother if branch.
	 */
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx) \
	else if ((curr_type == __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)) && \
		 __pgtblhdlr_##n##_accept_##nx(&cfg->cfg) && \
		 __pgtblhdlr_##nx##_is_present(&cfg->cfg, \
					       &((struct __pgtblhdlr_rawfmt_##rawx##_s *) \
						  (unsigned long)(_table))[idx])) { \
			p_next_entry->u.rawx = &((struct __pgtblhdlr_rawfmt_##rawx##_s *) \
						  (unsigned long)(_table))[idx]; \
			next_type = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##NX); \
		} \

#include __PGTBL_DESC
	else {
		p_next_entry->u.invalid = ((void *)__UL(0));
	}
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	return next_type;
}

static __pgtblhdlr_inline struct ____PGENTRY __PGTBLHDLR_NAMING_LOWERCASE(pgentry_from_table)
	(enum ____PGENTRY_TYPE type, void *_table, unsigned long idx)
{
	struct ____PGENTRY entry;

	switch (type) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		entry.u.raw = &((struct __pgtblhdlr_rawfmt_##raw##_s *)(unsigned long)(_table))[idx]; \
		break;\
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
	default:
		/* NULL */
		entry.u.invalid = ((void *)__UL(0));
		break;
	}
	return entry;
}

/*
 * Find the table type which has the same va_size with the input blk
 * type according to the order of PGTBLHDLR_PGENTRY
 * The input type must be blk type, ttbr and tbl types are forbidden
 */
static __pgtblhdlr_inline enum ____PGENTRY_TYPE
__PGTBLHDLR_NAMING_LOWERCASE(pgentry_choose_curlv_tblfit)
	(enum ____PGENTRY_TYPE type, struct ____PGCONFIG *cfg)
{
	enum ____PGENTRY_TYPE res = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_INVALID);
	unsigned long sz = __pgtblhdlr_pgentry_va_size(type, cfg);

#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	if (sz == __UL(s)) { \
		res = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N); \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	return res;
}

/*
 * Find the best acceptable nextlv according to the order of PGTBLHDLR_CONN
 * blk types are considered better than tbl types
 */
static __pgtblhdlr_inline enum ____PGENTRY_TYPE
__PGTBLHDLR_NAMING_LOWERCASE(pgentry_choose_nextlv_bestfit)
	(enum ____PGENTRY_TYPE parent_type, struct ____PGCONFIG *cfg, __vaddr_t va_start, __vaddr_t va_end)
{
	enum ____PGENTRY_TYPE res = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_INVALID);

#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s)
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx) \
	if (parent_type == __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N) && \
		 __pgtblhdlr_##n##_accept_##nx(&cfg->cfg) && \
		__PGTBLHDLR_NAMING_LOWERCASE(pgentry_va_is_aligned)( \
		 __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##NX), va_start, va_end)) \
	{ \
		res = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##NX); \
	} else

#include __PGTBL_DESC
	{ }
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	return res;
}

/*
 * Find the first acceptable nextlv according to the order of PGTBLHDLR_CONN
 */
static __pgtblhdlr_inline enum ____PGENTRY_TYPE
__PGTBLHDLR_NAMING_LOWERCASE(pgentry_choose_nextlv_blkfit)
	(enum ____PGENTRY_TYPE parent_type, struct ____PGCONFIG *cfg)
{
	enum ____PGENTRY_TYPE res = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_INVALID);

#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s)
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx) \
	if (parent_type == __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N) && \
		 __pgtblhdlr_##n##_accept_##nx(&cfg->cfg)) \
	{ \
		res = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##NX); \
	} else

#include __PGTBL_DESC
	{ }
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	return res;
}

/*
 * Find the last acceptable nextlv according to the order of PGTBLHDLR_CONN
 */
static __pgtblhdlr_inline enum ____PGENTRY_TYPE __PGTBLHDLR_NAMING_LOWERCASE(pgentry_choose_nextlv_tblfit)
	(enum ____PGENTRY_TYPE parent_type, struct ____PGCONFIG *cfg)
{
	enum ____PGENTRY_TYPE res = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_INVALID);

#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s)
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx) \
	if (parent_type == __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N) && \
		 __pgtblhdlr_##n##_accept_##nx(&cfg->cfg)) \
	{ \
		res = __PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##NX); \
	}

#include __PGTBL_DESC

#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	return res;
}

static __pgtblhdlr_inline void __PGTBLHDLR_NAMING_LOWERCASE(pgentry_zero)
	(struct ____PGCONFIG *cfg, enum ____PGENTRY_TYPE t, struct ____PGENTRY e)
{
	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		__pgtblhdlr_##raw##_zero(e.u.raw); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	default:
		break;
	}
}

static __pgtblhdlr_inline void __PGTBLHDLR_NAMING_LOWERCASE(pgentry_populate_pa)
	(enum ____PGENTRY_TYPE t, struct ____PGCONFIG *cfg, struct ____PGENTRY e,
	 const struct ____PGATTRIBUTE *attribute, __paddr_t pa)
{
	switch (t) {
#define PGTBLHDLR_RAWCFG(raw)
#define PGTBLHDLR_RAWFMT(raw)
#define PGTBLHDLR_PGENTRY(n, N, raw, a, s) \
	case (__PGTBLHDLR_NAMING_UPPERCASE(PGENTRY_TYPE_##N)): { \
		__pgtblhdlr_##n##_populate_pa(&cfg->cfg, e.u.raw, &attribute->tmpl_##n, pa); \
		break; \
	}
#define PGTBLHDLR_CONN(n, N, raw, nx, NX, rawx)
#include __PGTBL_DESC
#undef PGTBLHDLR_CONN
#undef PGTBLHDLR_PGENTRY
#undef PGTBLHDLR_RAWFMT
#undef PGTBLHDLR_RAWCFG
	default:
		break;
	}
}

#endif
