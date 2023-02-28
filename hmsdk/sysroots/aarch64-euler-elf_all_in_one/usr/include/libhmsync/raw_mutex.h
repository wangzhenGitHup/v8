/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Interfaces of raw_mutex
 * Author: Huawei OS Kernel Lab
 * Create: Sat Oct 27 15:11:53 2018
 */
#ifndef LIBHMSYNC_RAW_MUTEX_H
#define LIBHMSYNC_RAW_MUTEX_H

#include <vsync/atomic.h>
#include <liblocktrace/lockowner.h>

/* keep sizeof(attr) is equals to sizeof(unsigned int). */
typedef union {
	atomic_t v;
	struct {
		volatile unsigned int waiters  : 20;
		volatile unsigned int counters : 8;
		volatile unsigned int shared   : 1;
		volatile unsigned int type     : 3;
	} __v;
} raw_mutex_attr_t;

/*
 * raw_mutex:
 *  lock: => futex
 *  attr: -> mutex attributes:
 *      waiters(20bits): numbers of waiters.
 *      counters(8bits): recursive mutex counters.
 *      shared(1bit):
 *          a.  0   => private mutex.
 *          b.  1   => shared mutex.
 *      type(3bits):
 *          a.  000 => nornal mutex.
 *          b.  001 => recursive mutex.
 *          c.  010 => pi mutex.
 */
struct raw_mutex {
	/*
	 * NOTE:
	 * the 'owner' field must be the first, due to sysmgr copy
	 * the owner of the lock by the lock address directly.
	 */
	struct lock_owner_s owner;
	atomic_t lock;
	raw_mutex_attr_t attr;
};

struct raw_mutex_attr {
	unsigned int attr;
};

/* for recursive muetx */
#define RAW_MUTEX_RECURSIVE  0x1U
/* for priority inheritance mutex */
#define RAW_MUTEX_PI         0x2U
#define RAW_MUTEX_TYPE_MASK  0x7U
#define RAW_MUTEX_SHARED_MASK 0x8U

#define RAW_MUTEX_COUNTERS_MAX ((1U<<8)-1U)
#define RAW_MUTEX_WAITERS_MAX  ((1U<<20)-1U)

#define RAW_MUTEX_LOCK_MASK  0x7fffffffUL

#define RAW_MUTEX_INITIALIZER {.owner = {{.align_id = 0ULL}, {.align_pc = 0ULL}}, .lock = ATOMIC_INIT(0), \
			       .attr = {.v = ATOMIC_INIT(0)}}
#define RAW_MUTEX_INITIALIZER_PI {.owner = {{.align_id = 0ULL}, {.align_pc = 0ULL}}, .lock = ATOMIC_INIT(0), \
				  .attr = {.__v.waiters = 0U, .__v.counters = 0U, .__v.type = RAW_MUTEX_PI}}
#define RAW_MUTEX_INITIALIZER_RECURSIVE {.owner = {{.align_id = 0ULL}, {.align_pc = 0ULL}}, .lock = ATOMIC_INIT(0), \
					 .attr = {.__v.waiters = 0U, .__v.counters = 0U, .__v.type = RAW_MUTEX_RECURSIVE}}

static inline int raw_mutex_is_locked(struct raw_mutex *mutex)
{
	uint32_t val = atomic_read_rlx(&mutex->lock);
	return (int)(unsigned int)(val & RAW_MUTEX_LOCK_MASK);
}

void raw_mutex_init(struct raw_mutex *mutex);
void raw_mutex_init_recursive(struct raw_mutex *mutex);
void raw_mutex_init_shared(struct raw_mutex *mutex);
void raw_mutex_init_pi(struct raw_mutex *mutex);
void raw_mutex_init_with_attr(struct raw_mutex *mutex, const struct raw_mutex_attr *attr);
void raw_mutex_destroy(struct raw_mutex *mutex);

void raw_mutex_attr_init(struct raw_mutex_attr *attr);
void raw_mutex_attr_settype(struct raw_mutex_attr* attr, unsigned int type);
void raw_mutex_attr_setshared(struct raw_mutex_attr *attr, int shared);

void raw_mutex_inc_waiters(struct raw_mutex *mutex);
void raw_mutex_dec_waiters(struct raw_mutex *mutex);

int raw_mutex_trylock(struct raw_mutex* mutex);
void raw_mutex_lock(struct raw_mutex *mutex);
void raw_mutex_unlock(struct raw_mutex* mutex);
int raw_mutex_lock_pair(struct raw_mutex *mutex_a, struct raw_mutex *mutex_b);
int raw_mutex_unlock_pair(struct raw_mutex *mutex_a, struct raw_mutex *mutex_b);

void disable_raw_mutex(void);
void enable_raw_mutex(void);

#endif
