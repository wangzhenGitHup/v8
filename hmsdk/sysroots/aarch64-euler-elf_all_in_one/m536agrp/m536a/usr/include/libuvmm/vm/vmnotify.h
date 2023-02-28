/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Interface of vm notifiers
 * Author: Huawei OS Kernel Lab
 * Create: Tue Aug 3 15:30:00 2021
 */
#ifndef HM_UVMM_VM_VMNOTIFY_H
#define HM_UVMM_VM_VMNOTIFY_H

#include <lib/dlist.h>
#include <libhmsync/raw_mutex.h>

struct vm_notifier_obj {
	struct dlist_node node;
	void (*handler)(struct vm_notifier_obj *obj, int event);
	void *private_data;
};

struct vm_notifier_pool {
	struct dlist_node head;
	struct raw_mutex lock;
};

int vm_notifier_register(struct vm_notifier_pool *pool, struct vm_notifier_obj *obj);
void vm_notifier_unregister(struct vm_notifier_pool *pool, struct vm_notifier_obj *obj);
void vm_notifier_trigger(struct vm_notifier_pool *pool, int event);

int pm_reboot_notify_register(struct vm_notifier_obj *obj);
void pm_reboot_notify_unregister(struct vm_notifier_obj *obj);
void pm_reboot_notify_trigger(int event);
void vm_notifier_init(void);

#endif
