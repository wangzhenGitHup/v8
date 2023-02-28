/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Implementation of creating or verifying system file checksums
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jun 21 20:32:56 2021
 */

#ifndef LIBHMSRV_CRT_VER_CKSUM_H
#define LIBHMSRV_CRT_VER_CKSUM_H

#include <limits.h>

#define SHA256SUM_RAW_LEN 32
#define SHA256SUM_STR_LEN ((SHA256SUM_RAW_LEN) * (2))
#define BIG_BUF_SIZE (SHA256SUM_STR_LEN + PATH_MAX + 1)

int compare_file_chksum(const char *path);

#endif
