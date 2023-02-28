/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Declarations of libhmsig APIs
 * Author: Huawei OS Kernel Lab
 * Create: Mon June 28 10:51:16 2021
 */
#ifndef ULIBS_LIBHMSIG_HMSIG_CRL_H
#define ULIBS_LIBHMSIG_HMSIG_CRL_H
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <hmkernel/const.h>

#define CRL_RAW_SHM_NM_1  1U
#define CRL_RAW_SHM_NM_2  2U
#define CRL_RAW_SHM_NM_MAX  3U
#define CRL_RAW_SHM_NUM1  "default_crl_1"
#define CRL_RAW_SHM_NUM2  "default_crl_2"

struct hmsig_shm {
	uintptr_t base;
	size_t size;
};

int hmsig_crl_shm_create(const void *raw_data, size_t raw_sz);

int hmsig_crl_shm_init(void);

int hmsig_crl_verify_sig(const void *data, size_t size, const void *sig, size_t sig_size);

int hmsig_crl_shm_write(const void *raw_data, size_t raw_sz);

int hmsig_crl_shm_read(void *dst_data, size_t dst_sz, size_t offset, unsigned int *read_sz);

#endif /* ifndef ULIBS_LIBHMSIG_HMSIG_CRL_H */
