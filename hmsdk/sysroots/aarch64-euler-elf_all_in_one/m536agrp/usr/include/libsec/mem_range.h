/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: Provide mem range check functions
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jan 25 11:18:53 2022
 */
#ifndef ULIBS_LIBSEC_MEM_RANGE_H
#define ULIBS_LIBSEC_MEM_RANGE_H

#include <libpolicy_api.h>
#include <policy_def.h>
#include "cred.h"

bool sec_check_mem_range(const struct sec_chk_cred *cred, uint64_t subj, mrange_t *mrange);
bool sec_check_mem_range_extra(const struct sec_chk_cred *cred, uint64_t subj, mrange_t *mrange,
			       sec_chk_show_extra func, const void *arg);

#endif
