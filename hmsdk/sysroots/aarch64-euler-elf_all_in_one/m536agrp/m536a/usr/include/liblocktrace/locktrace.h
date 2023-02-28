/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Interface of lock trace access
 * Author: Huawei OS Kernel Lab
 * Create: Mon Mar 02 18:34:08 2020
 */

#ifndef ULIBS_INCLUDE_LIBLOCKTRACE_LOCKTRACE_H
#define ULIBS_INCLUDE_LIBLOCKTRACE_LOCKTRACE_H

#include <libstrict/strict.h>
#include <hongmeng/errno.h>

struct lock_track_s {
	const void *lock;
	const void *pc;
};

#ifdef CONFIG_LOCK_TRACE

int lock_trace_wait_lock(const struct lock_track_s *lock_track);
int lock_trace_wait_lock_finish(const struct lock_track_s *lock_track);

#else

static inline
int lock_trace_wait_lock(const struct lock_track_s *lock_track)
{
	UNUSED(lock_track);
	return E_HM_NOSYS;
}

static inline
int lock_trace_wait_lock_finish(const struct lock_track_s *lock_track)
{
	UNUSED(lock_track);
	return E_HM_NOSYS;
}

#endif

#endif
