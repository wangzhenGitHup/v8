/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Definition of ulibs utils
 * Author: Huawei OS Kernel Lab
 * Create: Fri Mar 08 14:26:47 2019
 */
#ifndef ULIBS_INCLUDE_LIBMEM_MEM_UTILS_H
#define ULIBS_INCLUDE_LIBMEM_MEM_UTILS_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <sys/mman.h>
#include <asm/page.h>
#include <libmem/types.h>
#include <libmem/flags.h>
#include <hongmeng/errno.h>
#include <hongmeng/panic.h>
#include <libhmlog/hmlog.h>
#include <libalgo/bitops.h>
#include <hmkernel/errno.h>
#include <hmkernel/mm/pgtable.h>

#ifndef SIZE_TO_MEM_ORDER
/* There is no correspond page_order when size is 0 */
#define SIZE_TO_MEM_ORDER(size) \
	({BUG_ON((size) == 0U); \
	  (((sizeof(uint64_t) * 8UL) - (size_t)PAGE_SHIFT) - bit_clzll((size_t)(PAGE_ALIGN_UP(size) - 1ULL)));})
#endif

#ifndef SIZE_TO_NRPFN
#define SIZE_TO_NRPFN(size) ((size) >> PAGE_SHIFT)
#endif

#ifndef MEM_ORDER_TO_COUNT
#define MEM_ORDER_TO_COUNT(order) (1ULL << (order))
#endif

#ifndef MEM_ORDER_TO_SIZE
#define MEM_ORDER_TO_SIZE(order) (1UL << ((order) + ((unsigned)PAGE_SHIFT)))
#endif

#define PAGE_ALIGN_UP(size)   (__typeof__(size))(uintptr_t)(ALIGN_UP((uintptr_t)(size), (uintptr_t)PAGE_SIZE))
#define PAGE_ALIGN_DOWN(size) (__typeof__(size))(uintptr_t)(ALIGN_DOWN((uintptr_t)(size), (uintptr_t)PAGE_SIZE))
#define PAGE_ALIGNED(ptr)     IS_ALIGNED((uintptr_t)(ptr), (uintptr_t)(PAGE_SIZE))

#define GB(n) ((n)*1024UL*1024UL*1024UL)
#define MB(n) ((n)*1024UL*1024UL)
#define KB_SHIFT 10

/*
 * In many scenarios, we use raw_atomic_long_xxx() to calculate
 * count of pages. That's acceptable because we don't have atomic
 * functions for ulong and in most systems, long is enough as
 * the number of pages.
 */
#if __SIZEOF_LONG__==8
#define MEM_COUNT_MAX (long)((unsigned long)LONG_MAX >> PAGE_SHIFT)
#else
#define MEM_COUNT_MAX LONG_MAX
#endif
#define MEM_SIZE_MAX  ((unsigned long long)(long long)MEM_COUNT_MAX << PAGE_SHIFT)

/* check size whether align to 2^n power of PAGE_SIZE */
static inline bool is_size_powerof2(size_t size)
{
	return (size >= PAGE_SIZE) && ((size & (size - 1UL)) == 0UL);
}

/* size 0 is considered as invalid */
static inline bool is_size_aligned2page(size_t size)
{
	return (size > 0UL) && ((size & PAGE_OFFMASK) == 0UL);
}

static inline int check_range_valid(uintptr_t start, size_t len)
{
	int rc = E_HM_OK;
	/* len is 0 or overflow which will considered as invalid */
	if ((len == 0UL) || (len > SIZE_MAX - start)) {
		rc = E_HM_INVAL;
	}
	/*
	 * if addr and len do not align to PAGE_SIZE
	 * which will return error
	 * NOTE: here start can be 0
	 */
	if (((start & PAGE_OFFMASK) != 0UL) || ((len & PAGE_OFFMASK) != 0UL)) {
		rc = E_HM_INVAL;
	}
	return rc;
}

/*
 * NOTE: Just a work around to enable page demanding, and
 * we should remove this function when kernel copy_to_user
 * support page demanding.
 */
int __touch_buffer(void *touch_ptr, size_t touch_len, bool need_write);

static inline int touch_buffer(void *touch_ptr, size_t touch_len)
{
	return __touch_buffer(touch_ptr, touch_len, true);
}

static inline int touch_buffer_read(void *touch_ptr, size_t touch_len)
{
	return __touch_buffer(touch_ptr, touch_len, false);
}

/*
 * NOTE: LLT will not recognized MAP_FIXED_NOREPLACE
 */
#ifdef __HOST_LLT__
#define MAP_FIXED_NOREPLACE 0x100000
#endif

static inline bool is_map_with_fixed(unsigned int flags)
{
	bool is_fixed = true;

	if (((flags & (uint32_t)MAP_FIXED) == 0U) &&
	    ((flags & (uint32_t)MAP_FIXED_NOREPLACE) == 0U)) {
		is_fixed = false;
	}
	return is_fixed;
}

static inline bool is_mflags_valid(unsigned int flags)
{
	uint32_t mask = (uint32_t)(MAP_PRIVATE | MAP_SHARED);
	return (((flags & mask) != 0U) && ((flags & mask) != mask));
}

static inline bool is_file_backed_map(unsigned int flags)
{
	bool is_file_backed = false;
	if ((flags & (uint32_t)MAP_ANONYMOUS) == 0U) {
			is_file_backed = true;
	}
	return is_file_backed;
}

static inline bool is_valid_msync_flag(uint32_t flags)
{
	uint32_t f;
	bool is_valid = true;

	f = MSYNC_FLAG_SYNC | MSYNC_FLAG_ASYNC | MSYNC_FLAG_INVALIDATE;

	if (((flags & (~f)) != 0U) ||
	    (((flags & MSYNC_FLAG_SYNC) != 0U) &&
	     ((flags & MSYNC_FLAG_ASYNC) != 0U))) {
		is_valid = false;
	}
	return is_valid;
}

static inline uint64_t hint_get_read_bit(uint32_t prot, bool priv)
{
	uint64_t hint_bit = 0ULL;
	if ((prot & MPROT_READ) != 0U) {
		hint_bit = priv ? PGTABLE_ATTR_KREAD : PGTABLE_ATTR_UREAD;
	}
	return hint_bit;
}

static inline uint64_t hint_get_write_bit(uint32_t prot, bool priv)
{
	uint64_t hint_bit = 0ULL;
	if ((prot & MPROT_WRITE) != 0U) {
		hint_bit = priv ? PGTABLE_ATTR_KWRITE : PGTABLE_ATTR_UWRITE;
	}
	return hint_bit;
}

static inline uint64_t hint_get_exec_bit(uint32_t prot, bool priv)
{
	uint64_t hint_bit = 0ULL;
	if ((prot & MPROT_EXEC) != 0U) {
		hint_bit = priv ? PGTABLE_ATTR_KEXEC : PGTABLE_ATTR_UEXEC;
	}
	return hint_bit;
}

static inline uint64_t hint_get_nocache_bit(uint32_t prot)
{
	uint64_t hint_bit = 0ULL;
	if ((prot & MPROT_NOCACHE) != 0U) {
		hint_bit = PGTABLE_ATTR_NOCACHE;
	}
	return hint_bit;
}

static inline uint64_t hint_get_huge_bit(unsigned int page_order)
{
	uint64_t hint_bit = 0ULL;
	if (page_order != 0U) {
		hint_bit = PGTABLE_HINT_BEST;
	}
	return hint_bit;
}

static inline uint64_t prot_to_hint(uint32_t prot, bool priv, unsigned int page_order)
{
	uint64_t hint = 0ULL;

	hint |= hint_get_read_bit(prot, priv);
	hint |= hint_get_write_bit(prot, priv);
	hint |= hint_get_exec_bit(prot, priv);
	hint |= hint_get_nocache_bit(prot);
	hint |= hint_get_huge_bit(page_order);
	return (priv ? (hint |= (PGTABLE_ATTR_KMAP | PGTABLE_ATTR_PSMAP)) : hint);
}

static inline uint32_t prot_get_read_bit(uint64_t hint)
{
	uint32_t prot_bit = 0U;
	if (((hint & PGTABLE_ATTR_UREAD) != 0ULL) || ((hint & PGTABLE_ATTR_KREAD) != 0ULL)) {
		prot_bit = MPROT_READ;
	}
	return prot_bit;
}

static inline uint32_t prot_get_write_bit(uint64_t hint)
{
	uint32_t prot_bit = 0U;
	if (((hint & PGTABLE_ATTR_UWRITE) != 0ULL) || ((hint & PGTABLE_ATTR_KWRITE)) != 0ULL) {
		prot_bit = MPROT_WRITE;
	}
	return prot_bit;
}

static inline uint32_t prot_get_exec_bit(uint64_t hint)
{
	uint32_t prot_bit = 0U;
	if (((hint & PGTABLE_ATTR_UEXEC) != 0ULL) || ((hint & PGTABLE_ATTR_KEXEC) != 0ULL)) {
		prot_bit = MPROT_EXEC;
	}
	return prot_bit;
}

static inline uint32_t hint_to_prot(uint64_t hint)
{
	uint32_t prot = 0U;

	prot |= prot_get_read_bit(hint);
	prot |= prot_get_write_bit(hint);
	prot |= prot_get_exec_bit(hint);

	return prot;
}

/*
 * Convert nrpfn to order(power of 2)that equals or
 * is next greater than nrpfn
 */
#define BITS_PER_BYTE 8U
static inline uint32_t nrpfn_to_page_order(uint64_t nrpfn)
{
	/*
	 * The order for 0 is 0, because 0 is the smaller order
	 * whose value of power 2 larger than 0.
	 */
	return ((nrpfn == 0ULL) || (nrpfn == 1ULL)) ?
	       0U : (uint32_t)((BITS_PER_BYTE * sizeof(uint64_t)) - bit_clzll(nrpfn - 1ULL));
}

#ifndef SIZE_TO_POWEROF2_PAGE_SIZE
#define SIZE_TO_POWEROF2_PAGE_SIZE(size) \
	((uint64_t)((uint64_t)1 << (SIZE_TO_MEM_ORDER(size) + (unsigned long long)PAGE_SHIFT)))
#endif

int memstr_to_size(const char *ptr, unsigned long long *r_size);

#endif
