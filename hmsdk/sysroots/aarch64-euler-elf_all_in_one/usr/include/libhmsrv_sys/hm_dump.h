/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: User interface of dump function
 * Author: Huawei OS Kernel Lab
 * Create: Wed Mar 11 21:45:18 2020
 */
#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HMDUMP_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HMDUMP_H

#include <unistd.h>
#include <libbunch/bunch.h>

int hm_dump_thread_to_bunch(pid_t tid, unsigned int flags, struct bunch *bunch);
int hm_dump_thread_to_klog(pid_t tid, unsigned int flags);

#endif
