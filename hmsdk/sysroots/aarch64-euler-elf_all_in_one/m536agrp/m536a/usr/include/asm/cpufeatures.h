/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: CPU features for uapi
 * Author: Huawei OS Kernel Lab
 * Create: Tue Oct 13 15:43:49 2020
 */
#ifndef AARCH64_UAPI_ASM_CPUFEATURES_H
#define AARCH64_UAPI_ASM_CPUFEATURES_H

#define __PE_MAINID_IMPLEMENTER(v)		(((__u32)(v) >> 24u) & ((1u << 8u) - 1u))
#define __PE_MAINID_VARIANT(v)			(((__u32)(v) >> 20u) & ((1u << 4u) - 1u))
#define __PE_MAINID_ARCHITECTURE(v)		(((__u32)(v) >> 16u) & ((1u << 4u) - 1u))
#define __PE_MAINID_PARTNUM(v)			(((__u32)(v) >> 4u) & ((1u << 12u) - 1u))
#define __PE_MAINID_REVISION(v)			((__u32)(v) & ((1u << 4u) - 1u))

#endif
