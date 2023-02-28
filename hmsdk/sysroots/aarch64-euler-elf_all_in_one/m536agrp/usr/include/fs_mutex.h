/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Implementation of fs mutex
 * Author: Huawei OS Kernel Lab
 * Create: Wed Aug 21 22:19:44 2019
 */

#ifndef LIBVFS_FS_MUTEX_H
#define LIBVFS_FS_MUTEX_H

#include <libhmsync/atomic.h>
#include <libhmsync/raw_mutex.h>
#include <stdbool.h>
#ifdef FS_MUTEX_DEBUG
#include <libhwsecurec/securec.h>
#endif

#define FS_MUTEX_INFO_LEN 256

struct fs_mutex {
	struct raw_mutex mutex;
#ifdef FS_MUTEX_DEBUG
	raw_atomic_int_t refcnt;
	const char *func;
	unsigned int line;
	const char *init_func;
	unsigned int init_line;
#endif
};

#ifdef FS_MUTEX_DEBUG
extern bool fs_mutex_debug_on(void);
#define FS_MUTEX_INITIALIZER {RAW_MUTEX_INITIALIZER, \
			      .func = NULL, \
			      .line = 0, .init_func = __FILE__, \
			      .init_line = __LINE__}
#define FS_MUTEX_INITIALIZER_RECURSIVE {RAW_MUTEX_INITIALIZER_RECURSIVE, \
					.func = NULL, \
					.line = 0, .init_func = __FILE__, \
					.init_line = __LINE__}

#define fs_mutex_debug_init(fm) do { \
	raw_atomic_int_init(&(fm)->refcnt, 0); \
	(fm)->func = NULL; \
	(fm)->line = 0; \
	(fm)->init_func = __func__; \
	(fm)->init_line = __LINE__; \
} while (0)


#define fs_mutex_init(fm) \
	({ \
		if (fs_mutex_debug_on()) { \
			fs_mutex_debug_init(fm); \
		} \
		raw_mutex_init(&(fm)->mutex); \
	})

#define fs_mutex_init_shared(fm) \
	({ \
		if (fs_mutex_debug_on()) {  \
			fs_mutex_debug_init(fm); \
		} \
		raw_mutex_init_shared(&(fm)->mutex); \
	})

#define fs_mutex_log(fm, refcnt) do {						\
	char buf[FS_MUTEX_INFO_LEN] = {0};					\
	if (snprintf_s(buf, sizeof(buf), sizeof(buf) - 1, "fs_mutex:%p rc:%d "	\
		       "if:%s il:%u lf:%s ll:%u cf:%s cl:%u\n", &(fm)->mutex,	\
		       refcnt, (fm)->init_func, (fm)->init_line, (fm)->func,	\
		       (fm)->line, __func__, __LINE__) > 0) {			\
		sysfast_syslog(HMLOG_INFO, buf, FS_MUTEX_INFO_LEN, NULL);	\
	}									\
} while (0)

#define fs_mutex_read_and_log(fm) do { \
	if (fs_mutex_debug_on()) { \
		int refcnt = raw_atomic_int_read_relaxed(&(fm)->refcnt); \
		if (refcnt) { \
			fs_mutex_log(fm, refcnt); \
		} \
	} \
} while (0)

#define fs_mutex_relaxed_update(fm) do {			\
	if (fs_mutex_debug_on()) {					\
		(void)raw_atomic_int_inc_relaxed(&(fm)->refcnt);\
		(fm)->func = __func__;				\
		(fm)->line = __LINE__;				\
	}							\
} while (0)


#define fs_mutex_lock(fm) \
	({ \
		fs_mutex_read_and_log(fm);	\
		raw_mutex_lock(&(fm)->mutex);	\
		fs_mutex_relaxed_update(fm);	\
	})

#define fs_mutex_trylock(fm) \
	({ \
		int ret = raw_mutex_trylock(&(fm)->mutex); \
		if (ret == 0) { \
			fs_mutex_relaxed_update(fm); \
		} \
		ret; \
	})

#define fs_mutex_unlock(fm) \
	({ \
		raw_mutex_unlock(&(fm)->mutex); \
		if (fs_mutex_debug_on()) \
			(void)raw_atomic_int_dec_relaxed(&(fm)->refcnt); \
	})

#define fs_mutex_lock_pair(fm_a, fm_b) \
	({ \
		fs_mutex_read_and_log(fm_a); \
		fs_mutex_read_and_log(fm_b); \
		(void)raw_mutex_lock_pair(&(fm_a)->mutex, &(fm_b)->mutex); \
		fs_mutex_relaxed_update(fm_a); \
		fs_mutex_relaxed_update(fm_b); \
	})

#define fs_mutex_unlock_pair(fm_a, fm_b) \
	({ \
		(void)raw_mutex_unlock_pair(&(fm_a)->mutex, &(fm_b)->mutex); \
		if (fs_mutex_debug_on()) { \
			(void)raw_atomic_int_dec_relaxed(&(fm_a)->refcnt); \
			(void)raw_atomic_int_dec_relaxed(&(fm_b)->refcnt); \
		} \
	})
#else
#define FS_MUTEX_INITIALIZER { RAW_MUTEX_INITIALIZER }
#define FS_MUTEX_INITIALIZER_RECURSIVE { RAW_MUTEX_INITIALIZER_RECURSIVE }
#define fs_mutex_init(fm) raw_mutex_init(&(fm)->mutex)
#define fs_mutex_init_recursive(fm) raw_mutex_init_recursive(&(fm)->mutex)
#define fs_mutex_init_shared(fm) raw_mutex_init_shared(&(fm)->mutex)

#define fs_mutex_lock(fm) raw_mutex_lock(&(fm)->mutex)
#define fs_mutex_trylock(fm) raw_mutex_trylock(&(fm)->mutex)
#define fs_mutex_unlock(fm) raw_mutex_unlock(&(fm)->mutex)
#define fs_mutex_lock_pair(fm_a, fm_b) raw_mutex_lock_pair(&(fm_a)->mutex, &(fm_b)->mutex);
#define fs_mutex_unlock_pair(fm_a, fm_b) raw_mutex_unlock_pair(&(fm_a)->mutex, &(fm_b)->mutex);
#endif

#define fs_mutex_is_locked(fm) (raw_mutex_is_locked(&(fm)->mutex) != 0)
#define fs_mutex_destroy(fm) raw_mutex_destroy(&(fm)->mutex)
#define FS_MUTEX_GUARD(guard, fm) RAW_MUTEX_GUARD(guard, &(fm)->mutex)
#define fs_thread_cond_wait(cond, fm) raw_thread_cond_wait(cond, &(fm)->mutex)
#define fs_thread_cond_timedwait(cond, fm, ts) raw_thread_cond_timedwait(cond, &(fm)->mutex, ts)

#endif	/* !LIBVFS_FS_MUTEX_H */
