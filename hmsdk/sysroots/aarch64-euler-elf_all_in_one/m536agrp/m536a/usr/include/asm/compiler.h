/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Compiler.h for uapi
 * Author: Huawei OS Kernel Lab
 * Create: Sat Sep 21 18:01:50 2019
 */

#ifndef AARCH64_UAPI_ASM_COMPILER_H
#define AARCH64_UAPI_ASM_COMPILER_H

#ifndef __clang__
# define __opt_noframe		__attribute__((optimize("omit-frame-pointer")))
# define __opt_nonoframe	__attribute__((optimize("no-omit-frame-pointer")))
# define __opt_nostkprot	__attribute__((optimize("no-stack-protector")))
#else
# define __opt_noframe
# define __opt_nonoframe
# define __opt_nostkprot
#endif

#endif
