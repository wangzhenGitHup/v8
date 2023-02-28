/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Provide common secure credential operation functions
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jul 30 14:51:46 2019
 */
#ifndef ULIBS_LIBSEC_CRED_COMMON_H
#define ULIBS_LIBSEC_CRED_COMMON_H
// sys
#include <sys/types.h>
// hongmeng
#include <hongmeng/errno.h>
// security
#include <libshlist/shlist.h>
#include <libseqlock/seqlock.h>
#include <libshtable/shtable.h>

extern struct shtable g_sec_cred_sht;

int sec_cred_init(bool is_creator);
void sec_cred_fini(void);

static inline int sec_cred_insert(uint32_t cnode_idx, sht_cb_ft func,
				  void *args, int *result)
{
	return sht_insert(&g_sec_cred_sht, &cnode_idx, func, args, result);
}

static inline int sec_cred_delete(uint32_t cnode_idx)
{
	return sht_delete(&g_sec_cred_sht, &cnode_idx);
}

static inline int sec_cred_update(uint32_t cnode_idx, sht_cb_ft func,
				  void *args, int *result)
{
	return sht_update(&g_sec_cred_sht, &cnode_idx, func, args, result);
}

static inline int sec_cred_search(uint32_t cnode_idx, sht_idx_t *p_node,
				  seq_t *p_seq)
{
	return sht_search(&g_sec_cred_sht, &cnode_idx, p_node, p_seq);
}

static inline int sec_cred_read(sht_idx_t node, sht_cb_ft func, void *args,
				int *result)
{
	return sht_read(&g_sec_cred_sht, node, func, args, result);
}

static inline bool sec_cred_retry(sht_idx_t node, seq_t seq)
{
	return sht_retry(&g_sec_cred_sht, node, seq) == E_HM_AGAIN;
}

#endif
