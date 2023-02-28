/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: libc pek interface for rru
 * Author: Huawei OS Kernel Lab
 * Create: Thu Mar 18 17:07:11 2021
 */

#ifndef HM_INCLUDE_HMCT_PEK_H
#define HM_INCLUDE_HMCT_PEK_H

#include <stdint.h>
#include <stddef.h>
#include <hmsyscall.h>

/* encode open and close into ioctl cmd, different with other cmds */
#define HM_PEK_CMD_OPEN		0x10
#define HM_PEK_CMD_CLOSE	0x11

uint64_t hm_pek_open(const char *module_name);

int hm_pek_close(uint64_t module_rref);

int hm_pek_ioctl(uint64_t module_rret, uint32_t cmd,
		 void *cfg, uint32_t cfg_len,
		 void *rlt, uint32_t rlt_len);

#endif
