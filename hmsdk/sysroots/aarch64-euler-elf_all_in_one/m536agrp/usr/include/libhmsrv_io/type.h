/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: I/O service APIs type
 * Author: Huawei OS Kernel Lab
 * Create: Fri Nov 22 13:58:38 2019
 */
#ifndef ULIBS_LIBHMSRV_IO_TYPE_H
#define ULIBS_LIBHMSRV_IO_TYPE_H

#include <stdint.h>
#include <hmkernel/const.h>
#include <hmkernel/capability.h>

struct hmsrv_io_ctx {
	rref_t dh_ap_rref;
	unsigned int flags;
	union {
		unsigned long long filp;	/* for generic device */
		int ifindex;			/* for network interface */
	};
	__u32 dh_cnode_idx;
};

#define HMSRV_IO_CTX_FLAGS_OPEN_FORWARD		0x80000000  /* use forward for open/close */
#define HMSRV_IO_CTX_FLAGS_RW_FORWARD		0x40000000  /* use forward for read/write */
#define HMSRV_IO_CTX_FLAGS_IOCTL_FORWARD	0x20000000  /* use forward for ioctl      */
#define HMSRV_IO_CTX_FLAGS_CLOCK_FORWARD	0x10000000  /* use forward for posix-clock */
#define HMSRV_IO_CTX_FLAGS_CLOSE_NOREJECT	0x08000000  /* don't reject dh_ap_rref in close */

/* use forward actv transaction */
#define HMSRV_IO_CTX_FLAGS_ALL_FORWARD	((HMSRV_IO_CTX_FLAGS_OPEN_FORWARD) |	\
					 (HMSRV_IO_CTX_FLAGS_RW_FORWARD) |	\
					 (HMSRV_IO_CTX_FLAGS_IOCTL_FORWARD) |	\
					 (HMSRV_IO_CTX_FLAGS_CLOCK_FORWARD))

/* XXX Keep consistent with Linux */
typedef uint32_t devnum_t;
#define MINORBITS	20U
#define MINORMASK	((__U(1) << MINORBITS) - 1U)
#define MAJOR(dev)	((unsigned int) ((dev) >> MINORBITS))
#define MINOR(dev)	((unsigned int) ((dev) & MINORMASK))
#define MKDEV(ma, mi)	(((ma) << MINORBITS) | (mi))

#define DEV_KMSG_MAJOR		1U
#define DEV_KMSG_MINOR		11U

#endif	/* ULIBS_LIBHMSRV_IO_TYPE_H */
