/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Declarations for ebr api
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jun 26 14:05:30 2020
 */
#ifndef ULIBS_LIBHMEBR_EBR_H
#define ULIBS_LIBHMEBR_EBR_H

#include <limits.h>
#include <lib/dlist.h>
#include <vsync/atomic.h>
#include <hmkernel/barrier.h>
#include <libhmsync/raw_mutex.h>
#include <libhmsync/raw_thread.h>

#ifdef CONFIG_CACHELINE_SIZE_L1
#define EBR_ALIGNED_SIZE CONFIG_CACHELINE_SIZE_L1
#else
#define EBR_ALIGNED_SIZE 64
#endif

#define ebr_assign_pointer(ptr, val)	\
do {					\
	smp_wmb();			\
	__write_once(ptr, val);		\
} while (__false);

/* only suits for scalar type thing */
#define ebr_dereference(ptr) (typeof(ptr))__read_once(ptr)

 /* MPSC stack for callbacks in EBR */
struct cb_stack_entry {
	struct cb_stack_entry *next;
};

struct cb_stack {
	struct cb_stack_entry *head;
};

struct call_ebr_obj;

struct epoch_set {
	/* lock for unit registration */
	struct raw_mutex reg_lock;
	struct dlist_node head;

	/* lock for initialization */
	struct raw_mutex init_lock;
	raw_thread_key_t key;
	uint32_t refcnt;

	/* epoch for each epoch set */
	atomic64_t epoch;
	/* pointer to instance of handling ebr callbacks */
	struct call_ebr_obj *call_obj;
} __aligned(EBR_ALIGNED_SIZE);

#define EBR_INIT(_name)	{			\
	.reg_lock = RAW_MUTEX_INITIALIZER,	\
	.head = DLIST_HEAD_INIT(_name.head),	\
	.init_lock = RAW_MUTEX_INITIALIZER,	\
	.key = UINT_MAX,			\
	.refcnt = 0U,				\
	.epoch = ATOMIC_INIT(0U),		\
	.call_obj = NULL,			\
}

struct ebr_entry {
	struct cb_stack_entry stack_entry;
	void (*cb_func)(struct ebr_entry *entry);
};

int ebr_init(struct epoch_set *es);
int ebr_register_unit(struct epoch_set *es);
int ebr_unregister_unit(struct epoch_set *es);
int ebr_read_lock(struct epoch_set *es);
int ebr_read_unlock(struct epoch_set *es);
int synchronize_ebr(struct epoch_set *es);
int call_ebr(struct epoch_set *es, struct ebr_entry *entry,
	     void (*cb_func)(struct ebr_entry *));
#endif
