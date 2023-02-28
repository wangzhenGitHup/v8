/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Supply memfd_create ulib interface
 * Author: Huawei OS Kernel Lab
 * Create: Wed Oct 14 16:12:42 2020
 */
#ifndef LIBHMSRV_FS_VFS_MEMFD_H
#define LIBHMSRV_FS_VFS_MEMFD_H

int vfs_memfd_create(const char *name, unsigned int flags);

#endif /* LIBHMSRV_FS_VFS_MEMFD_H */
