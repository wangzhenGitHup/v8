/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: add linux/linux-asm/mtd/mtd-abi.h to compat linux interface
 * Author: Huawei OS Kernel Lab
 * Create: Mon Nov 29 10:52:50 2021
 */

#ifndef __MTD_ABI_H__
#define __MTD_ABI_H__

#include <linux/types.h>
#include <asm/ioctl.h>

#define MTD_NANDFLASH		4
#define MTD_MLCNANDFLASH	8


struct mtd_info_user {
	__u8 type;
	__u32 flags;
	__u32 size;
	__u32 erasesize;
	__u32 writesize;
	__u32 oobsize;
	__u64 padding;
};

#define MEMGETINFO		_IOR('M', 1, struct mtd_info_user)
#define ECCGETSTATS		_IOR('M', 18, struct mtd_ecc_stats)

struct mtd_ecc_stats {
	__u32 corrected;
	__u32 failed;
	__u32 badblocks;
	__u32 bbtblocks;
};

#endif
