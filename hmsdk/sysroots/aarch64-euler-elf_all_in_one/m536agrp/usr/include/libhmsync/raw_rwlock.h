/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Interfaces of raw_rwlock
 * Author: Huawei OS Kernel Lab
 * Create: Sun May 05 11:32:50 2019
 */
#ifndef LIBHMSYNC_RAW_RWLOCK_H
#define LIBHMSYNC_RAW_RWLOCK_H

#include <liblocktrace/lockowner.h>
#include <vsync/atomic.h>

/*
 * Only shared attribute is supported for now,
 * may be extended with bit-field.
 */
struct raw_rwlock_attr {
	unsigned int shared : 1;
	unsigned int reserved : 31;
};

/*
 * lock records the number of rwlock callers:
 * lock = 0 means rwlock unlock.
 * positive lock values read lock callers.
 * waiters means there is a write lock occupied.
 * attr: rwlock attributes:
 *	shared(1bit):
 *		0 ==> private rwlock (default)
 *		1 ==> shared rwlock
 */
struct raw_rwlock {
	/*
	 * NOTE:
	 * the 'owner' field must be the first, due to sysmgr copy
	 * the owner of the lock by the lock address directly.
	 */
	struct lock_owner_s owner;
	atomic_t lock;
	atomic_t waiters;
	struct raw_rwlock_attr attr;
};

#define RAW_RDLOCK_INITIALIZER {.owner = {{.align_id = 0ULL}, {.align_pc = 0ULL}}, .lock = ATOMIC_INIT(0), \
				.waiters = ATOMIC_INIT(0), .attr = {.shared = 0U, .reserved = 0U}}

void raw_rwlock_init(struct raw_rwlock *rwlock, struct raw_rwlock_attr *attr);
int raw_rwlock_tryrdlock(struct raw_rwlock *rwlock);
int raw_rwlock_rdlock(struct raw_rwlock *rwlock);
int raw_rwlock_wrlock(struct raw_rwlock *rwlock);
int raw_rwlock_trywrlock(struct raw_rwlock *rwlock);
int raw_rwlock_unlock(struct raw_rwlock *rwlock);
void raw_rwlock_destroy(struct raw_rwlock *rwlock);

void disable_raw_rwlock(void);
void enable_raw_rwlock(void);

void raw_rwlock_attr_setshared(struct raw_rwlock_attr *attr, int shared);
void raw_rwlock_init_shared(struct raw_rwlock *rwlock);

#endif
