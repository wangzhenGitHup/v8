/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Convert the retval of hm ipc_shm interfaces to posix errno
 * Author: Huawei OS Kernel Lab
 * Create: Mon Aug 09 20:33:13 2021
 */
#ifndef LIBDEVHOST_VPIPE_IPC_SHM_H
#define LIBDEVHOST_VPIPE_IPC_SHM_H

/*
 * NOTE: Now the <libdevhost/vpipe/hm_ipc_shm.h> might be included
 * when compiling a liblinux module. To support this, cannot include
 * any unsupported-for-liblinux-module header files here.
 */
#include <libhmsrv_sys/hm_ipc_shm_common.h>

int libdh_ipc_shmget(int key, unsigned long size, int flags);
void *libdh_ipc_shmat(int shmid, const void *addr, int flags, int *errn);
int libdh_ipc_shmdt(const void *addr);
int libdh_ipc_shmctl(int shmid, int cmd, struct hm_shmid_ds_s *buf);

#endif /* !LIBDEVHOST_VPIPE_IPC_SHM_H */
