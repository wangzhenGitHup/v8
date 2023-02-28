/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Hmcrt
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jan 21 09:00:17 2019
 */
#ifndef ULIBS_LIBCRT_HMCRT_H
#define ULIBS_LIBCRT_HMCRT_H

/* defined in libcrt/hook.c */
#include <libhmsrv_sys/hmsrv_sys.h>

#define AUX_CNT 38U

extern size_t *hm_crt_current_aux(void);
extern void hm_setup_vdso_aux(uintptr_t base);
#endif
