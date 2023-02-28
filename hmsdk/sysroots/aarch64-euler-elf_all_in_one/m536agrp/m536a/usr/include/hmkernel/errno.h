/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Errno
 * Author: Huawei OS Kernel Lab
 * Create: Sun Jul 8 01:29:43 2018
 */
#ifndef UAPI_HMKERNEL_ERRNO_H
#define UAPI_HMKERNEL_ERRNO_H

#include <hmkernel/types.h>
#include <hmkernel/capability.h>

/* Support at most 512 errno for each cap */
/* we use 5 bits for captype (at most 32 caps). See kernel/capability/cap.h */
#define __HMK_ERR_CODE_BITS	9U
#define __HM_ERR_CAP_MASK	((1u << __CAP_BITS) - 1u)
#define __HM_MKERR(cap, code)	\
	(-1 * (__s32)((((__u32)(cap) & __HM_ERR_CAP_MASK) << __HMK_ERR_CODE_BITS) | (__u32)(code)))
#define __HM_ERR_CODE(err)	((~((__u32)(err) - 1U)) & ((1U << __HMK_ERR_CODE_BITS) - 1U))
#define __HM_ERR_CAP(err)	(((~((__u32)(err) - 1U)) >> __HMK_ERR_CODE_BITS) & __HM_ERR_CAP_MASK)

/*
 * Most hm errno have corresponding posix/linux errno, but some hm
 * errno and most hm cap errno don't have corresponding posix/linux
 * errno, use this reserved posix/linux style errno in hmerrno2posix
 * transition.
 *
 * It won't be conflict with posix/linux errno because the maximum
 * number of posix/linux errno is 133. And the range of errno in libc
 * is 8-bit, we use 255 as our hmerror.
 */
#ifndef EHMERROR
#define EHMERROR    255
#endif

enum {
#define __HM_EDEF(name, posix, desc) __POS_ERRNO_##name,
#define HM_EDEF(...)   __HM_EDEF(__VA_ARGS__)
#define HM_EDEF_P(...) __HM_EDEF(__VA_ARGS__)
#include <hmkernel/__errno_common.h>
#undef HM_EDEF_P
#undef HM_EDEF
#undef __HM_EDEF
};

#define CAPMETHOD(type, method)
#define CAPERRNO(type, perrno, ename, desc)     __hm_kerrno_base_##type##_##ename,
#define CAPTYPE(type, num, grant, content)	\
	enum __hm_kerrno_base_##type {		\
		__hm_kerrno_base_##type##_NULL = 0,\
		content				\
		__hm_kerrno_base_##type##_MAX	\
	};
#include <hmkernel/capability/captypes.h>
#undef CAPTYPE
#undef CAPERRNO
#undef CAPMETHOD

/*
 * NOTE: Don't use __E_HM_XXX directly, use ERR_AS_ENUM(E_HM_XXX)
 * or ERR_AS_INT(E_HM_XXX).
 */
enum __hm_kerrno {
	/* kernel errno */
#define __HM_EDEF(name, posix, desc)			\
	__##name = __HM_MKERR(0, __POS_ERRNO_##name),
#define HM_EDEF(...)   __HM_EDEF(__VA_ARGS__)
#define HM_EDEF_P(...) __HM_EDEF(__VA_ARGS__)
#include <hmkernel/__errno_common.h>
#undef HM_EDEF_P
#undef HM_EDEF
#undef __HM_EDEF

	/* cap errno */
#define CAPMETHOD(type, method)
#define CAPERRNO(type, perrno, ename, desc)		\
	__E_HM_##ename = __HM_MKERR(hmobj_##type,	\
				    __hm_kerrno_base_##type##_##ename),
#define CAPTYPE(type, num, grant, content)		\
			content
#include <hmkernel/capability/captypes.h>
#undef CAPTYPE
#undef CAPERRNO
#undef CAPMETHOD
};

/* kernel errno */
#define __HM_EDEF(name, posix, desc) static const int name = (int)__##name;
#define HM_EDEF(...)   __HM_EDEF(__VA_ARGS__)
#define HM_EDEF_P(...) __HM_EDEF(__VA_ARGS__)
#include <hmkernel/__errno_common.h>
#undef HM_EDEF_P
#undef HM_EDEF
#undef __HM_EDEF

/* cap errno */
#define CAPMETHOD(type, method)
#define CAPERRNO(type, perrno, ename, desc)		\
	static const int E_HM_##ename = (int)__E_HM_##ename;
#define CAPTYPE(type, num, grant, content)		\
			content
#include <hmkernel/capability/captypes.h>
#undef CAPTYPE
#undef CAPERRNO
#undef CAPMETHOD

#define ERR_AS_ENUM(ename)	__##ename
#define ERR_AS_INT(ename)	((int)__##ename)

typedef __rawattr_errorable__(int, enum __hm_errno) __hmerr_t;

static inline __bool IS_REF_ERR(__u64 cref)
{
	return ((cref >> 32U) == 0xffffffffULL) || ((cref >> 32U) == 0ULL) ? __true : __false;
}

static inline __bool IS_REF_VALID(__u64 cref)
{
	return !IS_REF_ERR(cref);
}

static inline int REF_TO_ERR(__u64 cref)
{
	int err = E_HM_OK;
	__u64 _cref = 0ULL;

	if (IS_REF_ERR(cref)) {
		_cref = cref & 0xffffffffULL;
		err = (_cref != 0ULL && (_cref & ((1UL << (__HMK_ERR_CODE_BITS + __CAP_BITS)) - 1UL)) != 0ULL)
		       ? (int)_cref : E_HM_KERNEL_MAX;
	}
	return err;
}

static inline __u64 ERR_TO_REF(int err)
{
	unsigned int tmperr = (unsigned int)err & 0xffffffffU;

	return (__u64)tmperr;
}

static inline __bool is_cnode_idx_err(__u32 cnode_idx)
{
	return (((cnode_idx >> 31) == 0x1U) || (cnode_idx == CNODE_IDX_INVALD_ZERO)) ? __true : __false;
}

static inline __bool is_cnode_idx_valid(__u32 cnode_idx)
{
	return !is_cnode_idx_err(cnode_idx);
}

static inline int cnode_idx_to_err(__u32 cnode_idx)
{
	int err = E_HM_OK;

	if (is_cnode_idx_err(cnode_idx)) {
		err = (cnode_idx == CNODE_IDX_INVALD_ZERO) ?
		      E_HM_KERNEL_MAX : ((int)(unsigned int)(cnode_idx | 0x80000000U));
	}
	return err;
}

static inline __u32 err_to_cnode_idx(int err)
{
	return ((__u32)(((unsigned int)err) | 0x80000000U));
}
#endif
