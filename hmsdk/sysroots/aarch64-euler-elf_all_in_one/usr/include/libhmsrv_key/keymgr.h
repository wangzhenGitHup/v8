/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Keymgr path info
 * Author: Huawei OS Kernel Lab
 * Create: Thu Mar 11 19:37:31 2021
 */
#ifndef LIBHMSRV_KEYMGR_H
#define LIBHMSRV_KEYMGR_H

#include <libhmutils/server_connect.h>

#define KEYMGR_PATH	"keymgr.actv"
void keymgr_server_init(void);
rref_t key_get_keymgr_rref(void);

#endif
