/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Interface of init actions
 * Author: Huawei OS Kernel Lab
 * Create: Wed Sep 09 09:39:44 2020
 */
#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_INIT_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_INIT_H

int hminit_notify_service_ready(void);
int hminit_notify_reboot(const char *reboot_reason);
int hminit_notify_shutdown(void);

#endif
