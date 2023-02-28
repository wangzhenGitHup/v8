/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Wed Jul 14 15:57:04 2021
 */
#ifndef __VSOCK_H__
#define __VSOCK_H__

#include <stdlib.h>

int vsock_vm_rx(const void *hdr, size_t hdr_len, const void *data, size_t data_len);

#endif
