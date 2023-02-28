/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Hash
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jan 15 21:27:14 2020
 */

#ifndef ULIBS_LIBALGO_HASH_H
#define ULIBS_LIBALGO_HASH_H

#include <stdint.h>

uint32_t str_to_hash(const unsigned char *str);
/* case-insensitive */
uint32_t str_to_hash_nocase(const unsigned char *str, uint32_t len);

#endif  /* ULIBS_LIBALGO_HASH_H */
