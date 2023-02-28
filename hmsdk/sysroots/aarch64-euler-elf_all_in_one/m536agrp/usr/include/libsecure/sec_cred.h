/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Secure credential definition
 * Author: Huawei OS Kernel Lab
 * Create: Thi Nov 13 10:43:11 2019
 */

#ifndef ULIBS_INCLUDE_LIBSECURE_SEC_CRED_H
#define ULIBS_INCLUDE_LIBSECURE_SEC_CRED_H

enum sec_cred_selfcall_type {
	__SEC_CRED_NO_SELFCALL,
	__SEC_CRED_EBB_SELFCALL,
	__SEC_CRED_ACTV_SELFCALL
};
struct sec_cred {
	unsigned long long sender;
	unsigned long credential;
	enum sec_cred_selfcall_type selfcall_type;
};

#endif
