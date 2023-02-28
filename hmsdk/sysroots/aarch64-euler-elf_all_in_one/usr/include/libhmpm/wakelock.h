/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Definition for system wakelock hongmeng native api
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 6 9:52:54 2019
 */

#ifndef ULIBS_LIBHMPM_WAKELOCK_H
#define ULIBS_LIBHMPM_WAKELOCK_H

#include <libbunch/bunch.h>
#include <libstrict/strict.h>
#include <hongmeng/errno.h>
#define WAKELOCK_STAT_ALL	"$wakelock_stat_all$"

#ifndef CONFIG_PLAT_M536A
int hm_wake_lock_add(const char *name);
int hm_wake_lock_remove(const char *name);
int hm_wake_lock_acquire_timeout(const char *name, unsigned long msec);
int hm_wake_lock_acquire(const char *name);
int hm_wake_lock_release(const char *name);
int hm_wake_lock_get_count(unsigned int *count);
int hm_wake_lock_save_count(unsigned int count);
int hm_wake_lock_stat(const char *name, struct bunch *bunch);
#else
#ifdef CONFIG_DEBUG_BUILD
int hm_wake_lock_add(const char *name);
int hm_wake_lock_remove(const char *name);
int hm_wake_lock_acquire_timeout(const char *name, unsigned long msec);
int hm_wake_lock_acquire(const char *name);
int hm_wake_lock_release(const char *name);
int hm_wake_lock_get_count(unsigned int *count);
int hm_wake_lock_save_count(unsigned int count);
int hm_wake_lock_stat(const char *name, struct bunch *bunch);
#else
static inline int hm_wake_lock_add(const char *name)
{
	UNUSED(name);
	return E_HM_NOSYS;
}

static inline int hm_wake_lock_remove(const char *name)
{
	UNUSED(name);
	return E_HM_NOSYS;
}

static inline int hm_wake_lock_acquire_timeout(const char *name,
					       unsigned long msec)
{
	UNUSED(name, msec);
	return E_HM_NOSYS;
}

static inline int hm_wake_lock_acquire(const char *name)
{
	UNUSED(name);
	return E_HM_NOSYS;
}

static inline int hm_wake_lock_release(const char *name)
{
	UNUSED(name);
	return E_HM_NOSYS;
}

static inline int hm_wake_lock_get_count(unsigned int *count)
{
	UNUSED(count);
	return E_HM_NOSYS;
}

static inline int hm_wake_lock_save_count(unsigned int count)
{
	UNUSED(count);
	return E_HM_NOSYS;
}

static inline int hm_wake_lock_stat(const char *name, struct bunch *bunch)
{
	UNUSED(name, bunch);
	return E_HM_NOSYS;
}
#endif
#endif

#endif
