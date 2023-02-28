/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: configurations of target, crypto framework and library features.
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 *
 * WARN: Auto-generated, NEVER edit this, and keep this file at first.
 */

#ifndef CRYPTO_HEADER_CONF_H
#define CRYPTO_HEADER_CONF_H

/* target information */
#define CRPT_NO_STDIO
#define CRPT_NO_STDARG
#define CRPT_NO_THREAD
/* #undef CRPT_NO_MALLOC */
/* #undef CRPT_NO_ATOMICS */
#define CRPT_NO_BACKTRACE

#ifdef __DEBUG__
#include <assert.h>
#define CRPT_ASSERT(cond) assert(cond)
#else
#define CRPT_ASSERT(cond)
#endif

/** @defgroup build_information [build information] */

/**
 * @ingroup build_information
 *
 * @brief get compiler description(UTF-8 string)
 * @retval compiler description(UTF-8 string)
 */
static inline const char *HICRYPTO_BUILDINFO_compiler(void)
{
    static const char *compiler = "Linux GNU with \"-fstack-protector-strong      -O2 -pipe   -mlittle-endian  --sysroot=/home/tsungli/gpu/open_source/build_tools/yocto/ng/build/tmp/work/aarch64-euler-elf/hm-hicrypto-headers/git-r0/flatten-recipe-sysroot  -Werror -Wall -Wformat=2 -Wextra -fvisibility=hidden -fno-common -Wwrite-strings -Wvla -Wcast-align -Wcast-qual -Wswitch-enum -Wundef -Wdouble-promotion -Wtrampolines -Wdate-time -Wfloat-equal -freg-struct-return -fno-strict-aliasing -pipe -Wl,-z,relro,-z,now -fstack-protector-strong -fdata-sections -ffunction-sections -Wl,--gc-sections -Wstrict-overflow=1 -Wswitch-default -Wunused -Wpointer-arith -Wlogical-op -Wduplicated-cond -Wnull-dereference -Wduplicated-branches -Wrestrict -Wno-free-nonheap-object -Wmissing-prototypes -Wold-style-definition -Wstrict-prototypes -Wshadow -Wc++-compat -fsigned-char -std=gnu99\"";
    return compiler;
}

#endif
