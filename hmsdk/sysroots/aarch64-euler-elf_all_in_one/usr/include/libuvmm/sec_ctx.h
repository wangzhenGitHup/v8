/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Security context
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 28 11:48:03 2021
 */
#ifndef HM_UVMM_UVMM_SEC_CTX_H
#define HM_UVMM_UVMM_SEC_CTX_H

#include <stdlib.h>

struct sec_ctx_mac;
struct sec_ctx_s {
	struct sec_ctx_mac *mac_ctx;
};

static inline void sec_ctx_init(struct sec_ctx_s *sec_ctx)
{
	if (sec_ctx != NULL) {
		sec_ctx->mac_ctx = NULL;
	}
}

static inline void sec_ctx_fini(struct sec_ctx_s *sec_ctx)
{
	if (sec_ctx != NULL) {
		free(sec_ctx->mac_ctx);
		sec_ctx->mac_ctx = NULL;
	}
}

#endif
