/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Definition of native auxv elements
 * Author: Huawei OS Kernel Lab
 * Create: Thu Feb 27 17:37:09 2020
 */
#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_AUXV_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_AUXV_H

#include <sys/auxv.h>

#define AT_FDMAP				(AT_L3_CACHEGEOMETRY + 1)
#define AT_FDSIZE				(AT_L3_CACHEGEOMETRY + 2)
#define AT_DSOINFO				(AT_L3_CACHEGEOMETRY + 3)
/* AT_MINSIGSTKSZ defined as 51, which equals to AT_L3_CACHEGEOMETRY + 4 */
#define AT_SYS_CNODE_IDX			(AT_L3_CACHEGEOMETRY + 5)
#define AT_LIBCMAPLEN				(AT_L3_CACHEGEOMETRY + 6)

/* AT_AUXV_NUM should be the last one item + 2 */
#define AT_AUXV_NUM				(AT_LIBCMAPLEN + 2)
#endif
