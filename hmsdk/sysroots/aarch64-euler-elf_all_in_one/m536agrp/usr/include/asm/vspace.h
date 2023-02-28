/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Tue May 07 15:55:58 2019
 */
#ifndef AARCH64_UAPI_ASM_VSPACE_H
#define AARCH64_UAPI_ASM_VSPACE_H

#include <asm/types.h>

struct arch_vspace_config {
	__u16 asid;
};

static inline void
arch_vspace_config_set_asid(struct arch_vspace_config *vspace_conf, unsigned int asid)
{
	vspace_conf->asid = (__u16)asid;
}

#endif
