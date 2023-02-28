/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Type definations and helper prototypes for block sysif
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 24 22:50:36 2019
 */

#ifndef ULIBS_INCLUDE_LIBSYSIF_BD_TYPES_H
#define ULIBS_INCLUDE_LIBSYSIF_BD_TYPES_H

/*
 * This rq_flag_bits must be consistent with
 * hm-liblinux/include/linux/blk_types.h rq_flag_bits
 */
#define __REQ_WRITE_		(0ULL) /* not set, read. set, write */
#define __REQ_DISCARD_		(7ULL) /* request to discard sectors */
#define __REQ_WRITE_SAME_	(9ULL) /* write same block many times */
#define __REQ_GC_		(14ULL) /* request to do sectors garbage collection */

#define REQ_READ_SYSIF			0
#define REQ_WRITE_SYSIF			(1ULL)
#define REQ_DISCARD_SYSIF		(1ULL << __REQ_DISCARD_)
#define REQ_WRITE_SAME_SYSIF		(1ULL << __REQ_WRITE_SAME_)
#define REQ_GC_SYSIF			(1ULL << __REQ_GC_)
#define REQ_WRITE_MASK (REQ_WRITE_SYSIF | REQ_WRITE_SAME_SYSIF)

#define REQ_SIO				1ULL

#define BD_FEATURE_DAS			(1ULL << 30)

#define BD_IO_STATUS_FREE	0
#define BD_IO_STATUS_INUSE	1
struct bd_io {
	int rw;
	unsigned int page_offset;
	unsigned int bv_len;
	uint64_t block_offset;
	int error;
	unsigned int flags;
	void *bd_io_private;
};

/* queue to process struct bd_io */
struct sring_buf;
struct raw_workqueue;
struct bd_queue {
	struct sring_buf *submit_queue;	/* vfs will push bio into the srbuf
					 * and devhost pop the bio then process it
					 */
	struct sring_buf *end_queue;	/* After devhost finished the bio,
					 * devhost pushes the bio into the end_queue
					 * to notify vfs
					 */
	struct raw_workqueue *bio_wq; 	/* worker to process bio */
};

#endif /* ULIBS_INCLUDE_LIBSYSIF_BLK_TYPES_H */
