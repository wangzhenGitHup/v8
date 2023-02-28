/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Common utils for sysif
 * Author: Huawei OS Kernel Lab
 * Create: Tue Aug 31 19:24:56 2021
 */
#ifndef LIBSYSIF_UTILS_COMMON_H
#define LIBSYSIF_UTILS_COMMON_H

#include <libsysif/base/macro.h>
#include <libsysif/generic_cred.h>
#include <hmkernel/capability.h>
#include <asm/activation.h>
#include <asm/activation/upcall.h>

#include <hongmeng/syscall.h>
#include <hongmeng/errno.h>

#include <asm/actv_rpc.h>
#include <asm/libsysif/utils.h>

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <libsecure/sec_cred.h>
#include <libhmactv/actv.h>
#include <hongmeng/macro.h>

#define ULIBS_NEW_SYSIF_MASK_ALL
void sysif_mask_all(uint64_t *old);

void sysif_mask_restore(const uint64_t *old);

struct sysif_actv_selfcall {
	void *data;
	unsigned long data_sz;
	void *buf;
	unsigned long buf_sz;
};

#define __ACTV_CRED_SELFCALL			__ARCH_ACTV_CRED_INVAL_SELFCALL
#define __ACTV_CRED_UNDEFINED			__ARCH_ACTV_CRED_UNDEFINED
#define __ACTV_CRED_FWD_XACT			__ARCH_ACTV_CRED_INVAL_FWD_XACT

/*
 * Check if a sysif actvcall is selfcall.
 * Selfcall set credential be __ACTV_CRED_SELFCALL.
 */
static inline bool
sysif_actv_is_selfcall(unsigned long cred)
{
	return (cred == __ACTV_CRED_SELFCALL) ? true : false;
}

/* Check whether it is an undefined cred in sysif actv handler. */
static inline bool
sysif_cred_is_undefined(unsigned long cred)
{
	return (cred == __ACTV_CRED_UNDEFINED) ? true : false;
}

/* Check whether it is an invalid cred used for forwarding transaction. */
static inline bool
sysif_cred_is_fwd_xact(unsigned long cred)
{
	return (cred == __ACTV_CRED_FWD_XACT) ? true : false;
}

static inline bool
sysif_actv_is_fwd_xact(unsigned long long sender)
{
	return (__RPC_SENDER_DECODE_FWD_CIDX(sender) !=
		__RPC_SENDER_DECODE_SRC_CIDX(sender));
}

static inline bool
sysif_cred_is_invalid(unsigned long cred)
{
	return (cred >= __ARCH_ACTV_CRED_INVAL_MIN) ? true : false;
}

extern __thread struct sec_cred sysif_callinfo;

static inline struct sec_cred* sysif_actv_current_callinfo(void)
{
	return &sysif_callinfo;
}

static inline __u32 sysif_actv_src_cnode_idx(void)
{
	return __RPC_SENDER_DECODE_SRC_CIDX(sysif_actv_current_callinfo()->sender);
}

static inline __u32 sysif_actv_fwd_cnode_idx(void)
{
	return __RPC_SENDER_DECODE_FWD_CIDX(sysif_actv_current_callinfo()->sender);
}

static inline void sysif_actv_update_callinfo(unsigned long long sender,
					      unsigned long credential)
{
	struct sec_cred *info = sysif_actv_current_callinfo();
	info->sender = sender;
	info->credential = credential;
}

struct actv;
struct actv_attr;
struct actv_pure_attr;

#endif
