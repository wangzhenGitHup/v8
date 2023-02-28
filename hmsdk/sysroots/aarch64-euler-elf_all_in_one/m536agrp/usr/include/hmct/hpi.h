/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Thu Feb 27 19:45:32 2020
 */

#ifndef HM_INCLUDE_HMCT_HPI_H
#define HM_INCLUDE_HMCT_HPI_H

#include <stdint.h>
#include <stddef.h>
#include <hmsyscall.h>

/* HPI (Host Port Interface) is heavily used in products and is a key hotspot.
 * Must be carefully optimized for best performance. We use vsyscall->ulibs->syscall
 * to replace devhost->vfs->ulibs->syscall to reduce overhead */

/* Existing ioctl cmds:
 * #define HPI_CMD_WRITEREG                0xFF010000U
 * #define HPI_CMD_READREG                 0xFF010001U
 *
 * #define HPI_CMD_READ_I                  0xFF010100U
 * #define HPI_CMD_WRITE_I                 0xFF010101U
 * #define HPI_CMD_OR_I                    0xFF010102U
 * #define HPI_CMD_AND_I                   0xFF010103U
 * #define HPI_CMD_SETN2M_BIT_I            0xFF010104U
 * #define HPI_CMD_SET_BIT_I               0xFF010105U
 * #define HPI_CMD_CLRBIT_I                0xFF010106U
 * #define HPI_CMD_MAX_I                   0xFF010107U
 */
/* encode open and close into ioctl cmd, different with above existing cmds */
#define HM_HPI_CMD_OPEN		0x10
#define HM_HPI_CMD_CLOSE	0x11

uint64_t hm_hpi_open(const char *module_name);

int hm_hpi_close(uint64_t module_rref);

int hm_hpi_ioctl(uint64_t module_rref, uint32_t cmd,
		 void *cfg, uint32_t cfg_len,
		 void *rlt, uint32_t rlt_len);

#endif
