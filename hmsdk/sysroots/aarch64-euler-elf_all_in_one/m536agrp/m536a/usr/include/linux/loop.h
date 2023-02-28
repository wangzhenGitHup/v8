/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: add linux/loop.h to compat linux interface
 * Author: Huawei OS Kernel Lab
 * Create: Thu Sep 23 11:08:30 2021
 */

#ifndef _UAPI_LINUX_LOOP_H
#define _UAPI_LINUX_LOOP_H

#define LO_NAME_SIZE	64
#define LO_KEY_SIZE	32

#include<linux/types.h>

struct loop_info64 {
	__u64		   lo_device;
	__u64		   lo_inode;
	__u64		   lo_rdevice;
	__u64		   lo_offset;
	__u64		   lo_sizelimit;
	__u32		   lo_number;
	__u32		   lo_encrypt_type;
	__u32		   lo_encrypt_key_size;
	__u32		   lo_flags;
	__u8		   lo_file_name[LO_NAME_SIZE];
	__u8		   lo_crypt_name[LO_NAME_SIZE];
	__u8		   lo_encrypt_key[LO_KEY_SIZE];
	__u64		   lo_init[2];
};

#define LOOP_SET_STATUS64	0x4C04
#define LOOP_GET_STATUS64	0x4C05

#define LOOP_SET_FD		0x4C00
#define LOOP_CLR_FD		0x4C01

#endif
