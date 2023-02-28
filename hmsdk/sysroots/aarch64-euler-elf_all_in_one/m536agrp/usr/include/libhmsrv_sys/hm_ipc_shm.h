/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Thu Feb 06 22:00:34 2020
 */
#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_IPC_SHM_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_IPC_SHM_H

#include <stddef.h>
#include <sys/shm.h>
#include "hm_ipc_comm.h"
#include "hm_ipc_shm_common.h"

int hm_ipc_shmget(int key, size_t size, int flags);

void *hm_ipc_shmat(int shmid, const void *addr, int flags, int *errn);

int hm_ipc_shmdt(const void *addr);

int hm_ipc_shmctl(int shmid, int cmd, struct shmid_ds *buf);

#endif
