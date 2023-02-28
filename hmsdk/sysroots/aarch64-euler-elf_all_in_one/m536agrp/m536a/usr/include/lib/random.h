/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Wed Nov 13 15:52:25 2019
 */
#ifndef KLIBS_RANDOM_H
#define KLIBS_RANDOM_H
#include <lib/jitter.h>

void random_seed(unsigned int seed);
unsigned long random_get(void);
int random_seed_with_jitter(const struct jitter_mem_ctx *ctx);

#endif
