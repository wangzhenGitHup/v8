/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Interface of lock trace stack
 * Author: Huawei OS Kernel Lab
 * Create: Mon Mar 02 21:44:44 2020
 */

#ifndef ULIBS_INCLUDE_LIBLOCKTRACE_LOCKTRACE_STACK_H
#define ULIBS_INCLUDE_LIBLOCKTRACE_LOCKTRACE_STACK_H

#include <libstrict/strict.h>

struct lock_info_s {
	const void *lock;      /* lock identity, this is the key field */
	const void *pc;        /* pc of last access the lock */
};

struct lock_trace_s {
	struct lock_info_s wait;
};

#ifdef CONFIG_LOCK_TRACE
void lock_trace_ready(void);
void lock_trace_init(struct lock_trace_s *lock_trace);
struct lock_trace_s *lock_trace_of_self(void);
#else
static inline
void lock_trace_ready(void)
{ }

static inline
void lock_trace_init(struct lock_trace_s *lock_trace)
{
	UNUSED(lock_trace);
}

static inline
struct lock_trace_s *lock_trace_of_self(void)
{
	return NULL;
}
#endif /* !CONFIG_LOCK_TRACE */
#endif
