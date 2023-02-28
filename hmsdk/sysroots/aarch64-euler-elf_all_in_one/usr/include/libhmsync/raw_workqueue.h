/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Interfaces of raw_workqueue
 * Author: Huawei OS Kernel Lab
 * Create: Thu Mar 7 15:11:53 2019
 */

#ifndef LIBHMSYNC_RAW_WORKQUEUE_H
#define LIBHMSYNC_RAW_WORKQUEUE_H

#include <libhmsync/raw_prioqueue.h>
#include <libhmsync/raw_threadpool.h>
#include <libhmsync/raw_thread_cond.h>

struct raw_work;
typedef int (*raw_work_handler)(struct raw_work *);

/* raw work priority */
#define RAW_WORK_PRIO_MAX 15
#define RAW_WORK_PRIO_MIN 0
#define RAW_WORK_PRIO_DEFAULT ((RAW_WORK_PRIO_MAX + RAW_WORK_PRIO_MIN) / 2)

struct raw_workqueue;
struct raw_work {
	struct {
		unsigned int canceled   : 1; /* 1 means canceled */
		unsigned int priority   : 4; /* priority: 0-15 */
		unsigned int reserved   : 27;
	} u;

	struct dlist_node node;
	raw_work_handler func;
	struct raw_workqueue *wq;
};

static inline int raw_work_is_canceled(struct raw_work *work)
{
	return work->u.canceled;
}

int raw_work_init(struct raw_work *work, raw_work_handler func, unsigned int prio);
void raw_work_destroy(struct raw_work *work);

struct raw_workqueue_attr {
	/* initial number of worker threads */
	unsigned int nr_workers;

	/* number of queues, equals to number of priority */
	unsigned int nr_queues;

	int inherit;
	int sched_policy;
	int thread_priority;

	/* name of workqueue thread */
	char name[RAW_THREADPOOL_NAME_LEN];
};

struct raw_waiter_list {
	struct raw_mutex mutex;
	struct dlist_node head;
};

struct raw_workqueue {
	/*
	 * number of works, condvar will check this attribute.
	 * if nr_works==0, worker thread will begin to wait
	 *
	 * protected by cond_mutex
	 */
	int nr_works;
	int state;

	/* wq_mutex protects prioqueue */
	struct raw_mutex wq_mutex;
	struct raw_prioqueue wait_wq;
	struct raw_prioqueue handling_wq;

	/* init once created, don't need lock */
	unsigned int nr_workers;
	unsigned int nr_queues;

	/* waiter list for flush, protected by waiters.mutex */
	struct raw_waiter_list waiters;

	/*
	 * cond_mutex & condvar are used to do thread wait/notification:
	 * - when nr_works==0, worker thread begin to wait on the condvar.
	 * - when add work to wq, nr_work++, will signal a worker to wakeup to handler work.
	 */
	struct raw_mutex cond_mutex;
	struct raw_thread_cond cond;

	/* threadpool: init at workqueue init, don't lock */
	struct raw_threadpool *pool;
};

int raw_workqueue_init(struct raw_workqueue *wq,
		       const struct raw_workqueue_attr *attr);
int raw_workqueue_destroy(struct raw_workqueue *wq);
int raw_workqueue_add_work(struct raw_workqueue *wq, struct raw_work *work);
int raw_workqueue_cancel_work(struct raw_workqueue *wq, struct raw_work *work);

/* NOTE: flush family API not implemented yet */
int raw_workqueue_flush(struct raw_workqueue *wq);
int raw_workqueue_flush_util(struct raw_workqueue *wq, struct raw_work *work);
int raw_workqueue_flush_prio(struct raw_workqueue *wq, unsigned int prio);

void raw_workqueue_attr_init(struct raw_workqueue_attr *attr,
			     unsigned int nr_workers, unsigned int nr_queues);
int raw_workqueue_attr_set_inherit(struct raw_workqueue_attr *attr, int inherit);
int raw_workqueue_attr_set_policy(struct raw_workqueue_attr *attr, int policy);
int raw_workqueue_attr_set_prio(struct raw_workqueue_attr *attr, int prio);
int raw_workqueue_attr_set_name(struct raw_workqueue_attr *attr, const char *name);

#endif
