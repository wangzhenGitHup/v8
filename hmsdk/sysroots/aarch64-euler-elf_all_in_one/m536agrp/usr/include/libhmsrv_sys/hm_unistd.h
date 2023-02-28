/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Header file for unistd source code
 * Author: Huawei OS Kernel Lab
 * Create: Thu May 28 22:23:14 2020
 */
#ifndef ULIBS_INCLUDE_LIBHMSRV_HM_UNISTD_H
#define ULIBS_INCLUDE_LIBHMSRV_HM_UNISTD_H

#include <sys/socket.h>

long hm_writev(int fd, struct iovec *iovs, int iovcnt);

#endif
