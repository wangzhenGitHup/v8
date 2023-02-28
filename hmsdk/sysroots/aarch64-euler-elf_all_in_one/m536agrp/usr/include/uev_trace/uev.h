/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Interfaces of uev_list in uvmm
 * Author: Huawei OS Kernel Lab
 * Create: Tue Apr 27 16:30:47 2021
 */

#ifndef HM_UVMM_UEV_TRACE_UEV_H
#define HM_UVMM_UEV_TRACE_UEV_H

struct vcpu;
struct svc_hvc_handler;
struct mem_region;

#ifdef CONFIG_HMUEV
/* "__HM_UEV__" should be defined before including uev_template.h */
#define __HM_UEV__
#endif
#include <libhmuev/uev_template.h>

#define UEV_POINT	DECLARE_UEV
#include <uev_trace/uev_list.h>
#undef	UEV_POINT

#endif
