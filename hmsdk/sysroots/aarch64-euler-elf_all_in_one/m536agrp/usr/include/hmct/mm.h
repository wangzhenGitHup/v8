/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Sun Jun 28 17:43:23 2020
 */

#ifndef HM_INCLUDE_HMCT_MM_H
#define HM_INCLUDE_HMCT_MM_H

#include <stdint.h>
#include <stddef.h>
#include <hmsyscall.h>

/*
 * hm_mm_acquire_shm_page - Acquire grantted shared memory page
 * @shm_id: id of shared memory
 * @rvaddr: returned vaddr of shared memory
 *
 * Return 0 when successful
 * EINVAL: invalid param
 * ENOENT: can not find shm id
 * ESRCH : can not find corresponding process
 */
int hm_mm_acquire_shm_page(uint32_t shm_id, void **rvaddr);

/*
 * hm_mm_release_shm_page - Release grantted shared memory page
 * @shm_id: id of shared memory
 * @rvaddr: vaddr of shared memory
 *
 * Return 0 when successful
 * EINVAL: invalid param
 */
int hm_mm_release_shm_page(void *vaddr);

#endif
