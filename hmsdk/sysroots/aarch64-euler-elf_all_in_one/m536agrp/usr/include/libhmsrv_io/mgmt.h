/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: devmgr mgmt helper APIs
 * Author: Huawei OS Kernel Lab
 * Create: Wed Jun 16 16:46:07 2021
 */
#ifndef ULIBS_LIBHMSRV_IO_MGMT_H
#define ULIBS_LIBHMSRV_IO_MGMT_H

#include <libsysif/devmgr/api.h>

int hmsrv_io_mgmt_load_module(int devid, const char *modname, const char *args);

int hmsrv_io_mgmt_load_external_module(int devid, const char *pathname,
				       const char *args);

int hmsrv_io_mgmt_unload_module(unsigned int cnode_idx, const char *modname);

int hmsrv_io_mgmt_sync(void);

typedef int (*hmsrv_io_mgmt_dump_callback_fn)(void *ctx, const char *data);
int hmsrv_io_mgmt_dump(const hmsrv_io_mgmt_dump_callback_fn fn, void *ctx);

#endif /* ULIBS_LIBHMSRV_IO_MGMT_H */
