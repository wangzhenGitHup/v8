/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Header of io vspace uapi.
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 06 14:21:11 2019
 */
#ifndef UAPI_IOV_MODULE
#define UAPI_IOV_MODULE

#include <asm/types.h>
#include <hmkernel/capability.h>

struct __iov_pmem_info_s {
	__u64 add_dev_pfn_size;		/* add_device ops need pfn size */
	__u64 att_dev_pfn_size;		/* attach_device ops need pfn size */
	__u64 vs_add_pfn_size;		/* vspace_add ops need pfn size */
};

struct __iov_entry_s {
	__s32 iov_ctrl_id;		/* the offset of iov dev node in dts */
	struct __iov_pmem_info_s info;	/* pmem size used by this iov ctrl */
};

struct __iov_ops_param_s {
	__u64 pfn;			/* the start pfn of the memory used by add/attach device */
	__u64 nrpfn;			/* page number of the memory used by add/attach device */
	__u32 device_id;		/* id of device node in dts(iommu = <&xxxx id>) */
	cref_t vspace; 			/* vspace cref add/attach to dev(behind iov dev) */
	__u32 vspace_id;		/* identify vspace */
	__u32 iov_sum;			/* num sum of iov when get iov info */
};

struct __iov_module_args_s {
	__s32 iov_ctrl_id;		/* the offset of iov dev node in dts */
	struct __iov_ops_param_s param;
};

#define __IOV_ATTACH_DEV		0x32U
#define __IOV_ADD_DEV			0x33U
#define __IOV_VSPACE_ADD		0x34U
#define __IOV_VSPACE_ATTACH		0x35U
#define __IOV_VSPACE_DETACH		0x36U
#define __IOV_RESET_ALL			0x37U
#define __IOV_GET_INFO			0x38U

#endif
