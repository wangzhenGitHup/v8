/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Common structures and interfaces of audit module
 * Author: Huawei OS Kernel Lab
 * Create: Fri Dec 25 11:38:55 2020
 */
#ifndef ULIBS_LIBSEC_AUDIT_H
#define ULIBS_LIBSEC_AUDIT_H

#include <stdbool.h>
#include <stdint.h>
#include <libshlist/shlist.h>

#include "module.h"
#include "cred.h"
#include "method/para.h"
#include "method/var.h"

extern struct sec_mod sec_mod_audit;

#define SEC_DEFINE_AUDIT(NAME, ARG)						\
static int _sec_chk_audit_##NAME(const struct sec_chk_cred *cred,		\
			       const struct sec_cred_audit *audit_cred PARA(ARG));	\
static int sec_chk_audit_##NAME(const struct sec_chk_cred *cred PARA(ARG))	\
{										\
	struct sec_cred_audit audit = {0};					\
	int rc;									\
	rc = sec_cred_read_audit(cred, &audit);					\
	if (rc < 0)								\
		return rc;							\
	return _sec_chk_audit_##NAME(cred, &audit VAR(ARG));			\
}										\
static int _sec_chk_audit_##NAME(const struct sec_chk_cred *cred,		\
				 const struct sec_cred_audit *audit_cred PARA(ARG))

#define sec_define_audit_method(METHOD)						\
	sec_define_chk_method(METHOD, sec_chk_audit_##METHOD)

#define SEC_AUDIT_CMDLINE_SHM_SIZE 4096u

extern struct shlist g_sec_cred_cmdline_list;

static inline int sec_audit_cmdline_init(bool creator)
{
	char prefix[] = "sec_audit_cmdline_";
	struct shl_config cfg = {
		.shm_prefix = prefix,
		.shm_size = SEC_AUDIT_CMDLINE_SHM_SIZE
	};
	return shl_init(&g_sec_cred_cmdline_list, &cfg, creator);
}

static inline void sec_audit_cmdline_fini(void)
{
	shl_fini(&g_sec_cred_cmdline_list);
}

static inline struct shl_list_node *sec_audit_cmdline_alloc(size_t size)
{
	return shl_alloc(&g_sec_cred_cmdline_list, size);
}

static inline void sec_audit_cmdline_free(struct shl_list_node *node)
{
	shl_free(&g_sec_cred_cmdline_list, node);
}

static inline uintptr_t sec_audit_cmdline_base_of(uint32_t shm_idx)
{
	return (uintptr_t)shl_shm_base_of(&g_sec_cred_cmdline_list, shm_idx);
}

#endif /* ifndef ULIBS_LIBSEC_AUDIT_H */
