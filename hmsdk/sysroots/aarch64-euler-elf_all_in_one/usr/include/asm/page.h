/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Fri Dec 7 19:08:00 2018
 */
#ifndef AARCH64_ULIBS_ASM_PAGE_H
#define AARCH64_ULIBS_ASM_PAGE_H

#ifndef PAGE_SHIFT
# define PAGE_SHIFT 12
#endif

#ifndef PAGE_SIZE
#if (PAGE_SHIFT == 12)
# define PAGE_SIZE 4096
#else
# error "page shift is not 12"
#endif
#endif

#endif
