/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Export functions for libdtb
 * Author: Huawei OS Kernel Lab
 * Create: Wed Dec 11 09:18:59 2019
 */
#ifndef __DTB_H__
#define __DTB_H__

#include <external/libuvmm/uvmm.h>

struct vm_create_args;
int prepare_dtb_image(struct vm_create_args *pargs);
void release_dtb_image(struct vm_create_args *pargs);
int edit_chosen_node(void *fdt, const char *property, uint64_t val);

#endif
