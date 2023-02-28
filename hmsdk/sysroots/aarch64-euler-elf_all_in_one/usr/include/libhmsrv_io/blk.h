/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: I/O service APIs of block device operation
 * Author: Huawei OS Kernel Lab
 * Create: Fri Nov 22 13:58:38 2019
 */
#ifndef ULIBS_LIBHMSRV_IO_BLK_H
#define ULIBS_LIBHMSRV_IO_BLK_H

#include <stdlib.h>
#include <libhmsrv_io/type.h>

int hmsrv_io_blk_check_feature(const struct hmsrv_io_ctx *ctx,
			       int idx, uint64_t feature, uint64_t *feature_out);

int hmsrv_io_blk_register_bio_notify(const struct hmsrv_io_ctx *ctx,
				     cref_t ap_cref,
				     unsigned int method,
				     size_t bd_shm_size,
				     uint64_t *submit_fd, uint64_t *end_fd,
				     uint64_t *shm_id,
				     size_t *obj_cnt);

int hmsrv_io_blk_run_queue(const struct hmsrv_io_ctx *ctx, unsigned int flags,
			   unsigned int idx);

#endif	/* ULIBS_LIBHMSRV_IO_BLK_H */
