/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Description of aarch64 page table
 * Author: Huawei OS Kernel Lab
 * Create: Fri Apr 02 18:02:39 2021
 */

#ifndef AARCH64_MAPI_UAPI_ASM_PGTBLDESC_H
#define AARCH64_MAPI_UAPI_ASM_PGTBLDESC_H

/* undefine guard to mute code scanner */
#undef AARCH64_MAPI_UAPI_ASM_PGTBLDESC_H

#ifdef __PGTBLHDLR_CODE

/* Real guard in __PGTBLHDLR_CODE block */
#ifndef AARCH64_MAPI_UAPI_ASM_PGTBLDESC_H__CODE
#define AARCH64_MAPI_UAPI_ASM_PGTBLDESC_H__CODE

#include <hmkernel/types.h>
#include <hmkernel/const.h>
#include <hmkernel/strict.h>

struct __pgtblhdlr_rawcfg_a64_s {
	unsigned int va_bits;
};

struct __pgtblhdlr_rawfmt_a64ttbrreg_s {
	__u64 v;
};

static __pgtblhdlr_inline __bool
__pgtblhdlr_rawfmt_a64ttbrreg_is_zero(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				      struct __pgtblhdlr_rawfmt_a64ttbrreg_s *raw)
{
	return ____NOT(raw->v);
}

static __pgtblhdlr_inline __bool
__pgtblhdlr_rawfmt_a64ttbrreg_is_valid(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				      struct __pgtblhdlr_rawfmt_a64ttbrreg_s *raw)
{
	return ____IS(raw->v);
}

struct __pgtblhdlr_rawfmt_a64pgentry_s {
	__u64 v;
};

static __pgtblhdlr_inline __bool
__pgtblhdlr_rawfmt_a64pgentry_is_zero(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				      struct __pgtblhdlr_rawfmt_a64pgentry_s *raw)
{
	return ____NOT(raw->v);
}

static __pgtblhdlr_inline __bool
__pgtblhdlr_rawfmt_a64pgentry_is_valid(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				      struct __pgtblhdlr_rawfmt_a64pgentry_s *raw)
{
	return ____IS((raw->v & __UL(1)));
}

/*
 * Define arm64 common page table entry operations
 */
static __pgtblhdlr_inline __bool
__pgtblhdlr_a64blk_common_is_present(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				     struct __pgtblhdlr_rawfmt_a64pgentry_s *raw)
{
	return ((raw->v & __UL(3)) == __UL(1));
}

static __pgtblhdlr_inline __bool
__pgtblhdlr_a64tbl_common_is_present(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				     struct __pgtblhdlr_rawfmt_a64pgentry_s *raw)
{
	return ((raw->v & __UL(3)) == __UL(3));
}

static __pgtblhdlr_inline __bool
__pgtblhdlr_a64tbl_common_is_lastlv(const struct __pgtblhdlr_rawcfg_a64_s *cfg)
{
	return __false;
}

static __pgtblhdlr_inline __bool
__pgtblhdlr_a64blk_common_is_lastlv(const struct __pgtblhdlr_rawcfg_a64_s *cfg)
{
	return __true;
}

#define __PGTBL_A64_COMMON_TBL_LEVEL(sz)	\
static __pgtblhdlr_inline __bool \
__pgtblhdlr_a64tbl##sz##_is_present(const struct __pgtblhdlr_rawcfg_a64_s *cfg, \
				    struct __pgtblhdlr_rawfmt_a64pgentry_s *raw) \
{ \
	return __pgtblhdlr_a64tbl_common_is_present(cfg, raw); \
} \
static __pgtblhdlr_inline __bool \
__pgtblhdlr_a64tbl##sz##_is_lastlv(const struct __pgtblhdlr_rawcfg_a64_s *cfg) \
{ \
	return __false; \
} \
static __pgtblhdlr_inline __paddr_t \
__pgtblhdlr_a64tbl##sz##_decode_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg, \
				   struct __pgtblhdlr_rawfmt_a64pgentry_s *raw) \
{ \
	return raw->v & __UL(0xfffffffff000); \
} \
static __pgtblhdlr_inline \
void __pgtblhdlr_a64tbl##sz##_populate_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg, \
					  struct __pgtblhdlr_rawfmt_a64pgentry_s *r, \
					  const struct __pgtblhdlr_rawfmt_a64pgentry_s *tmpl, \
					  __paddr_t pa) \
{ \
	r->v = tmpl->v | (pa & __UL(0xfffffffff000)); \
} \
static __pgtblhdlr_inline unsigned long \
__pgtblhdlr_a64tbl##sz##_tblentry_size(const struct __pgtblhdlr_rawcfg_a64_s *cfg) \
{ \
	return sizeof(__u64); \
} \
static __pgtblhdlr_inline bool \
__pgtblhdlr_a64tbl##sz##_va_is_aligned(__vaddr_t va_start, __vaddr_t va_end) \
{ \
	return __true; \
}

#define __PGTBL_A64_COMMON_BLK_LEVEL(sz)	\
static __pgtblhdlr_inline __bool \
__pgtblhdlr_a64blk##sz##_is_present(const struct __pgtblhdlr_rawcfg_a64_s *cfg, \
				    struct __pgtblhdlr_rawfmt_a64pgentry_s *raw) \
{ \
	return __pgtblhdlr_a64blk_common_is_present(cfg, raw); \
} \
static __pgtblhdlr_inline __bool \
__pgtblhdlr_a64blk##sz##_is_lastlv(const struct __pgtblhdlr_rawcfg_a64_s *cfg) \
{ \
	return __true; \
} \
static __pgtblhdlr_inline unsigned long \
__pgtblhdlr_a64blk##sz##_tblentry_size(const struct __pgtblhdlr_rawcfg_a64_s *cfg) \
{ \
	return __UL(1); \
}

/*
 * Register in ttbr (logical)
 * Address 0 is valid in some devices, in this case ttbr should not point to address 0
 */
static __pgtblhdlr_inline __bool
__pgtblhdlr_a64ttbrreg_is_present(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				  struct __pgtblhdlr_rawfmt_a64ttbrreg_s *raw)
{
	return ____IS(raw->v);
}

static __pgtblhdlr_inline __bool
__pgtblhdlr_a64ttbrreg_is_lastlv(const struct __pgtblhdlr_rawcfg_a64_s *cfg)
{
	return __false;
}

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_a64ttbrreg_tblidx_from_va(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				      __vaddr_t va)
{
	unsigned int va_bits = cfg->va_bits;
	unsigned long result;

	if (va_bits > __U(39)) {
		result = (va >> __U(39)) & ((__UL(1) << (va_bits - __U(39))) - __UL(1));
	} else if (va_bits > __U(30)) {
		result = (va >> __U(30)) & ((__UL(1) << (va_bits - __U(30))) - __UL(1));
	} else if (va_bits > __U(21)) {
		result = (va >> __U(21)) & ((__UL(1) << (va_bits - __U(21))) - __UL(1));
	} else {
		result = (va >> __U(12)) & ((__UL(1) << (va_bits - __U(12))) - __UL(1));
	}
	return result;
}

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_ttbrreg_va_align(const struct __pgtblhdlr_rawcfg_a64_s *cfg)
{
	return __UL(1) << cfg->va_bits;
}

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_ttbrreg_va_size(const struct __pgtblhdlr_rawcfg_a64_s *cfg)
{
	return __UL(1) << cfg->va_bits;
}

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_a64ttbrreg_tblentry_size(const struct __pgtblhdlr_rawcfg_a64_s *cfg)
{
	return sizeof(__u64);
}

static __pgtblhdlr_inline __paddr_t
__pgtblhdlr_a64ttbrreg_decode_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				 struct __pgtblhdlr_rawfmt_a64ttbrreg_s *raw)
{
	return raw->v & __UL(0xfffffffffffe);
}


static __pgtblhdlr_inline
void __pgtblhdlr_a64ttbrreg_populate_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
					struct __pgtblhdlr_rawfmt_a64ttbrreg_s *r,
					const struct __pgtblhdlr_rawfmt_a64ttbrreg_s *tmpl,
					__paddr_t pa)
{
	r->v = tmpl->v | (pa & __UL(0xfffffffffffe));
}

static __pgtblhdlr_inline bool
__pgtblhdlr_a64ttbrreg_va_is_aligned(__vaddr_t va_start, __vaddr_t va_end)
{
	return __true;
}

/*
 * Only table is allowed at level 1 (controls bit 48~39)
 */
__PGTBL_A64_COMMON_TBL_LEVEL(512g)

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_a64tbl512g_tblidx_from_va(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				      __vaddr_t va)
{
	return (va >> __U(30)) & (__UL(0x1ff));
}

/*
 * decode_pa for table has been auto generated using __PGTBL_A64_COMMON_LEVELxxx because
 * for all table entry, pa points to a 4k aligned table.
 */
__PGTBL_A64_COMMON_TBL_LEVEL(1g)

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_a64tbl1g_tblidx_from_va(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				    __vaddr_t va)
{
	return (va >> __U(21)) & (__UL(0x1ff));
}

static __pgtblhdlr_inline
void __pgtblhdlr_a64blk1g_populate_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				      struct __pgtblhdlr_rawfmt_a64pgentry_s *r,
				      const struct __pgtblhdlr_rawfmt_a64pgentry_s *tmpl,
				      __paddr_t pa)
{
	r->v = tmpl->v | (pa & __UL(0xffffc0000000));
}
__PGTBL_A64_COMMON_BLK_LEVEL(1g)

static __pgtblhdlr_inline __paddr_t
__pgtblhdlr_a64blk1g_decode_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
			       struct __pgtblhdlr_rawfmt_a64pgentry_s *raw)
{
	return raw->v & __UL(0xffffc0000000);
}

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_a64blk1g_tblidx_from_va(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				    __vaddr_t va)
{
	/* all 30 bites */
	return va & __UL(0x3fffffff);
}

static __pgtblhdlr_inline bool
__pgtblhdlr_a64blk1g_va_is_aligned(__vaddr_t va_start, __vaddr_t va_end)
{
	return (va_start % 0x40000000 == 0) && (va_end % 0x40000000 == 0);
}

__PGTBL_A64_COMMON_TBL_LEVEL(2m)

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_a64tbl2m_tblidx_from_va(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				    __vaddr_t va)
{
	return (va >> __U(12)) & (__UL(0x1ff));
}

static __pgtblhdlr_inline
void __pgtblhdlr_a64blk2m_populate_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				      struct __pgtblhdlr_rawfmt_a64pgentry_s *r,
				      const struct __pgtblhdlr_rawfmt_a64pgentry_s *tmpl,
				      __paddr_t pa)
{
	r->v = tmpl->v | (pa & __UL(0xffffffe00000));
}

__PGTBL_A64_COMMON_BLK_LEVEL(2m)

static __pgtblhdlr_inline __paddr_t
__pgtblhdlr_a64blk2m_decode_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
			       struct __pgtblhdlr_rawfmt_a64pgentry_s *raw)
{
	return raw->v & __UL(0xffffffe00000);
}

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_a64blk2m_tblidx_from_va(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				    __vaddr_t va)
{
	/* all 21 bits */
	return va & __UL(0x1fffff);
}

static __pgtblhdlr_inline bool
__pgtblhdlr_a64blk2m_va_is_aligned(__vaddr_t va_start, __vaddr_t va_end)
{
	return (va_start % 0x200000 == 0) && (va_end % 0x200000 == 0);
}

/*
 * Last level 4k page
 */
static __pgtblhdlr_inline __bool
__pgtblhdlr_a64page4k_is_present(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				 struct __pgtblhdlr_rawfmt_a64pgentry_s *raw)
{
	return (raw->v & __UL(3)) == __UL(3);
}

static __pgtblhdlr_inline __bool
__pgtblhdlr_a64page4k_is_lastlv(const struct __pgtblhdlr_rawcfg_a64_s *cfg)
{
	return __true;
}

static __pgtblhdlr_inline __paddr_t
__pgtblhdlr_a64page4k_decode_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				struct __pgtblhdlr_rawfmt_a64pgentry_s *raw)
{
	return raw->v & __UL(0xfffffffff000);
}

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_a64page4k_tblidx_from_va(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				     __vaddr_t va)
{
	return va & __UL(0xfff);
}

static __pgtblhdlr_inline
void __pgtblhdlr_a64page4k_populate_pa(const struct __pgtblhdlr_rawcfg_a64_s *cfg,
				       struct __pgtblhdlr_rawfmt_a64pgentry_s *r,
				       const struct __pgtblhdlr_rawfmt_a64pgentry_s *tmpl,
				       __paddr_t pa)
{
	r->v = tmpl->v | (pa & __UL(0xfffffffff000));
}

static __pgtblhdlr_inline unsigned long
__pgtblhdlr_a64page4k_tblentry_size(const struct __pgtblhdlr_rawcfg_a64_s *cfg)
{
	return __U(1);
}

static __pgtblhdlr_inline bool
__pgtblhdlr_a64page4k_va_is_aligned(__vaddr_t va_start, __vaddr_t va_end)
{
	return __true;
}

#define __PGTBL_A64_CONN_ACCEPT_UNCOND(n, raw, nx, rawx)	\
static __pgtblhdlr_inline __bool \
__pgtblhdlr_##n##_accept_##nx(const struct __pgtblhdlr_rawcfg_a64_s *cfg) \
{ \
	return __true; \
}

__PGTBL_A64_CONN_ACCEPT_UNCOND(a64tbl512g,	a64pgentry,	a64tbl1g,	a64pgentry)
__PGTBL_A64_CONN_ACCEPT_UNCOND(a64tbl512g,	a64pgentry,	a64blk1g,	a64pgentry)
__PGTBL_A64_CONN_ACCEPT_UNCOND(a64tbl1g,	a64pgentry,	a64tbl2m,	a64pgentry)
__PGTBL_A64_CONN_ACCEPT_UNCOND(a64tbl1g,	a64pgentry,	a64blk2m,	a64pgentry)
__PGTBL_A64_CONN_ACCEPT_UNCOND(a64tbl2m,	a64pgentry,	a64page4k,	a64pgentry)

#define __PGTBL_A64_CONN_ACCEPT_TTBRREG(nx, b)	\
static __pgtblhdlr_inline __bool \
__pgtblhdlr_a64ttbrreg_accept_##nx(const struct __pgtblhdlr_rawcfg_a64_s *cfg) \
{ \
	unsigned int va_bits = cfg->va_bits; \
	__bool res; \
	if ((va_bits > __U(b)) && (va_bits <= (__U(b) + __U(9)))) { \
		res = __true; \
	} else { \
		res = __false; \
	} \
	return res; \
}

__PGTBL_A64_CONN_ACCEPT_TTBRREG(a64tbl512g,	39)
__PGTBL_A64_CONN_ACCEPT_TTBRREG(a64tbl1g,	30)
__PGTBL_A64_CONN_ACCEPT_TTBRREG(a64blk1g,	30)
__PGTBL_A64_CONN_ACCEPT_TTBRREG(a64tbl2m,	21)
__PGTBL_A64_CONN_ACCEPT_TTBRREG(a64blk2m,	21)
__PGTBL_A64_CONN_ACCEPT_TTBRREG(a64page4k,	12)

static __pgtblhdlr_inline
void __pgtblhdlr_a64ttbrreg_zero(struct __pgtblhdlr_rawfmt_a64ttbrreg_s *r)
{
	r->v = __UL(0);
}

static __pgtblhdlr_inline
void __pgtblhdlr_a64pgentry_zero(struct __pgtblhdlr_rawfmt_a64pgentry_s *r)
{
	r->v = __UL(0);
}

#endif /* real guard */

#else  /* !__PGTBLHDLR_CODE */

PGTBLHDLR_RAWCFG(a64)
PGTBLHDLR_RAWFMT(a64ttbrreg)
PGTBLHDLR_RAWFMT(a64pgentry)

PGTBLHDLR_PGENTRY(a64ttbrreg, A64TTBRREG, a64ttbrreg, 0,		0)
PGTBLHDLR_PGENTRY(a64tbl512g, A64TBL512G, a64pgentry, 0x8000000000,	0x8000000000)
PGTBLHDLR_PGENTRY(a64blk1g,   A64BLK1G,   a64pgentry, 0x40000000,	0x40000000)
PGTBLHDLR_PGENTRY(a64tbl1g,   A64TBL1G,   a64pgentry, 0x40000000,	0x40000000)
PGTBLHDLR_PGENTRY(a64blk2m,   A64BLK2M,   a64pgentry, 0x200000,		0x200000)
PGTBLHDLR_PGENTRY(a64tbl2m,   A64TBL2M,   a64pgentry, 0x200000,		0x200000)
PGTBLHDLR_PGENTRY(a64page4k,  A64PAGE4K,  a64pgentry, 0x1000,		0x1000)

PGTBLHDLR_CONN(a64ttbrreg, A64TTBRREG, a64ttbrreg, a64tbl512g, A64TBL512G, a64pgentry)
PGTBLHDLR_CONN(a64ttbrreg, A64TTBRREG, a64ttbrreg, a64blk1g,   A64BLK1G,   a64pgentry)
PGTBLHDLR_CONN(a64ttbrreg, A64TTBRREG, a64ttbrreg, a64tbl1g,   A64TBL1G,   a64pgentry)
PGTBLHDLR_CONN(a64ttbrreg, A64TTBRREG, a64ttbrreg, a64blk2m,   A64BLK2M,   a64pgentry)
PGTBLHDLR_CONN(a64ttbrreg, A64TTBRREG, a64ttbrreg, a64tbl2m,   A64TBL2M,   a64pgentry)
PGTBLHDLR_CONN(a64ttbrreg, A64TTBRREG, a64ttbrreg, a64page4k,  A64PAGE4K,  a64pgentry)

PGTBLHDLR_CONN(a64tbl512g, A64TBL512G, a64pgentry, a64blk1g,   A64BLK1G,   a64pgentry)
PGTBLHDLR_CONN(a64tbl512g, A64TBL512G, a64pgentry, a64tbl1g,   A64TBL1G,   a64pgentry)
PGTBLHDLR_CONN(a64tbl1g,   A64TBL1G,   a64pgentry, a64blk2m,   A64BLK2M,   a64pgentry)
PGTBLHDLR_CONN(a64tbl1g,   A64TBL1G,   a64pgentry, a64tbl2m,   A64TBL2M,   a64pgentry)
PGTBLHDLR_CONN(a64tbl2m,   A64TBL2M,   a64pgentry, a64page4k,  A64PAGE4K,  a64pgentry)

#endif  /* __PGTBLHDLR_CODE */

#endif  /* fake guard */
