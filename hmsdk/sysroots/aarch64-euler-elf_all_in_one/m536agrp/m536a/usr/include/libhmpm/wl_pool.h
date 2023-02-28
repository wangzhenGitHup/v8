/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 3 18:43:25 2019
 */

#ifndef ULIBS_LIBHMPM_WL_POOL_H
#define ULIBS_LIBHMPM_WL_POOL_H

#include <stdbool.h>

#include <libbunch/bunch.h>
#include <libstrict/strict.h>
#include <hongmeng/errno.h>
#define TIMEOUT_INFINITE	0

enum wl_stat_filter {
	WL_STAT_FILTER_NONE,
	WL_STAT_FILTER_NAME,
	WL_STAT_FILTER_ACQUIRED,
	WL_STAT_FILTER_RELEASED,
};

struct wl_pool;

#ifndef CONFIG_PLAT_M536A
struct wl_pool *wl_pool_init(void (*acquire_timeout_cb)(void));
void wl_pool_destroy(struct wl_pool *pool);
int wl_pool_add_entry(struct wl_pool *pool, const char *name);
int wl_pool_remove_entry(struct wl_pool *pool, const char *name);
int wl_pool_acquire_entry_timeout(struct wl_pool *pool, const char *name,
				  unsigned long msec);
int wl_pool_acquire_entry(struct wl_pool *pool, const char *name);
int wl_pool_release_entry(struct wl_pool *pool, const char *name);
int wl_pool_acquired_num(struct wl_pool *pool, int *acquired_num);
int wl_pool_is_acquired(struct wl_pool *pool, const char *name,
			bool *acquired);
int wl_pool_stat(struct wl_pool *pool, enum wl_stat_filter filter,
		 struct bunch *bunch, const void *data);
#else
#ifdef CONFIG_DEBUG_BUILD
struct wl_pool *wl_pool_init(void (*acquire_timeout_cb)(void));
void wl_pool_destroy(struct wl_pool *pool);
int wl_pool_add_entry(struct wl_pool *pool, const char *name);
int wl_pool_remove_entry(struct wl_pool *pool, const char *name);
int wl_pool_acquire_entry_timeout(struct wl_pool *pool, const char *name,
				  unsigned long msec);
int wl_pool_release_entry(struct wl_pool *pool, const char *name);
int wl_pool_acquire_entry(struct wl_pool *pool, const char *name);
int wl_pool_acquired_num(struct wl_pool *pool, int *acquired_num);
int wl_pool_is_acquired(struct wl_pool *pool, const char *name,
			bool *acquired);
int wl_pool_stat(struct wl_pool *pool, enum wl_stat_filter filter,
		 struct bunch *bunch, const void *data);
#else
static inline struct wl_pool *wl_pool_init(void (*acquire_timeout_cb)(void))
{
	UNUSED(acquire_timeout_cb);
	return NULL;
}

static inline void wl_pool_destroy(struct wl_pool *pool)
{
	UNUSED(pool);
}

static inline int wl_pool_add_entry(struct wl_pool *pool, const char *name)
{
	UNUSED(pool, name);
	return E_HM_NOSYS;
}

static inline int wl_pool_remove_entry(struct wl_pool *pool, const char *name)
{
	UNUSED(pool, name);
	return E_HM_NOSYS;
}

static inline int wl_pool_acquire_entry_timeout(struct wl_pool *pool, const char *name,
				  unsigned long msec)
{
	UNUSED(pool, name, msec);
	return E_HM_NOSYS;
}

static inline int wl_pool_acquire_entry(struct wl_pool *pool, const char *name)
{
	UNUSED(pool, name);
	return E_HM_NOSYS;
}

static inline int wl_pool_release_entry(struct wl_pool *pool, const char *name)
{
	UNUSED(pool, name);
	return E_HM_NOSYS;
}

static inline int wl_pool_acquired_num(struct wl_pool *pool, int *acquired_num)
{
	UNUSED(pool, acquired_num);
	return E_HM_NOSYS;
}

static inline int wl_pool_is_acquired(struct wl_pool *pool, const char *name,
			bool *acquired)
{
	UNUSED(pool, name, acquired);
	return E_HM_NOSYS;
}

static inline int wl_pool_stat(struct wl_pool *pool, enum wl_stat_filter filter,
		 struct bunch *bunch, const void *data)
{
	UNUSED(pool, filter, bunch, data);
	return E_HM_NOSYS;
}
#endif
#endif

#endif
