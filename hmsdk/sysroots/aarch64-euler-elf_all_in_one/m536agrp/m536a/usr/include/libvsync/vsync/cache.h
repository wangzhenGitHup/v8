/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: cache aligment
 * Author: Huawei Dresden Research Center
 * Create: Thu 09 Apr 2020 10:49:20 AM CEST
 */
#ifndef VSYNC_CACHE_H
#define VSYNC_CACHE_H
/*******************************************************************************
 * This file provides cache macros to align and pad data structures to the cache
 * line size.  The cache alignment is disabled if the code is compiled for
 * verification (with VSYNC_VERIFICATION defined).
 ******************************************************************************/

#ifndef CACHE_LINE_LENGTH
#define CACHE_LINE_LENGTH 128 /* L3 cache line size for ARM processors */
#endif

#ifdef VSYNC_VERIFICATION
#define __vsync_cachealign
#define __vsync_cachepad(typ, var) typ var
#else /* ! VSYNC_VERIFICATION */
#define __vsync_cachealign __attribute__((aligned(CACHE_LINE_LENGTH)))
#define __vsync_cachediff(sz) (CACHE_LINE_LENGTH - (sz % CACHE_LINE_LENGTH))
#define __vsync_cachepad(typ, var) char var[__vsync_cachediff(sizeof(typ))]
#endif /* ! VSYNC_VERIFICATION */

#endif
