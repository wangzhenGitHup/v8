/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Privilged services access uapps memory implementation on SPIN.
 * Author: Huawei OS Kernel Lab
 * Create: Thu Nov 5 10:33:25 2020
 */
#ifndef ULIBS_LIBMEM_UMEM_H
#define ULIBS_LIBMEM_UMEM_H

#include <stddef.h>
#include <stdint.h>

#define SPIN_MEM_SAFE_COPY 0x1U

void hm_setup_spin_flags(uint32_t flags);
int hm_copy_to_user(void *dst, const void *src, size_t bytes);
int hm_copy_from_user(void *dst, const void *src, size_t bytes);

#endif /* ULIBS_LIBMEM_UMEM_H */
