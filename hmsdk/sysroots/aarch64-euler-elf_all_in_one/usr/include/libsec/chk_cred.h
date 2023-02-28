/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Secure check credential head file
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jul 30 15:05:25 2019
 */
#ifndef ULIBS_LIBSEC_CHK_CRED_H
#define ULIBS_LIBSEC_CHK_CRED_H

#include <hmkernel/strict.h>
#include <libshtable/types.h>
#include <librequester/requester.h>
#include "cred_common.h"

struct sec_chk_cred {
	sht_idx_t node;
	seq_t seq;
	uint32_t  cnode_idx;
};

#define SEC_CHK_CRED_RESET {				\
		.node = 0,				\
		.seq = 0,				\
		.cnode_idx = CNODE_IDX_INVALD_ZERO	\
	}

static inline int sec_chk_cred_init(struct sec_chk_cred *cred,
				    uint32_t cnode_idx)
{
	int ret;

	ret = sec_cred_search(cnode_idx, &cred->node, &cred->seq);
	if (ret == E_HM_OK) {
		cred->cnode_idx = cnode_idx;
	}
	return ret;
}

int sec_chk_cred_init_requester(struct sec_chk_cred *cred);

struct sec_chk_cred_xact {
	struct requester _req;
	struct sec_chk_cred _src_cred;
	struct sec_chk_cred _fwd_cred;
};

#define SEC_CHK_CRED_XACT_RESET {			\
		._req = {0},				\
		._src_cred = SEC_CHK_CRED_RESET,	\
		._fwd_cred = SEC_CHK_CRED_RESET,	\
	}

static inline int sec_chk_cred_xact_init(struct sec_chk_cred_xact *cred)
{
	struct sec_chk_cred_xact c = SEC_CHK_CRED_XACT_RESET;
	int rc;

	rc = requester_init(&c._req);
	if (rc == E_HM_OK) {
		*cred = c;
	}

	return rc;
}

static inline
struct sec_chk_cred *_sec_chk_cred_xact_init(struct sec_chk_cred *cred,
					     uint32_t cnode_idx)
{
	struct sec_chk_cred *ret = cred;
	/* we need not initialize the credential again */
	if (is_cnode_idx_valid(cred->cnode_idx) == 0) {
		int rc = sec_chk_cred_init(cred, cnode_idx);
		if (rc != E_HM_OK) {
			ret = NULL;
		}
	}
	return ret;
}

static inline
struct sec_chk_cred *sec_chk_fwd_cred(struct sec_chk_cred_xact *cred)
{
	return _sec_chk_cred_xact_init(&cred->_fwd_cred,
				       cred->_req.fwd_cnode_idx);
}

static inline
struct sec_chk_cred *sec_chk_src_cred(struct sec_chk_cred_xact *cred)
{
	struct sec_chk_cred *ret = NULL;
	/* only use one credential for performance if we can */
	if (cred->_req.src_cnode_idx == cred->_req.fwd_cnode_idx) {
		ret = sec_chk_fwd_cred(cred);
	} else {
		ret = _sec_chk_cred_xact_init(&cred->_src_cred,
					      cred->_req.src_cnode_idx);
	}

	return ret;
}

#endif
