/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: cpu hotplug notifier interface
 * Author: Huawei OS Kernel Lab
 * Create: Sat Nov 20 10:38:47 2021
 */
#ifndef ULIBS_LIBHMNOTIFY_HM_LISTENER_H
#define ULIBS_LIBHMNOTIFY_HM_LISTENER_H

#include <libhmnotifier/hm_notifier.h>

enum cpuhp_event {
	CPU_ADD,
	CPU_ADD_FAILED,
	CPU_REMOVE,
	CPU_REMOVE_FAILED,
};

struct hm_cpuhp_notifier_args {
	unsigned int cpu;
	unsigned int event;
}__attribute((packed));

int cpuhp_notifier_create_listener_helper(const struct hm_notifier_cb *ops);
int cpuhp_notifier_remove_listener_helper(const struct hm_notifier_cb *ops);

int hm_cpuhp_notifier_cpu_add(struct hm_notifier *notifier, unsigned int cpu);
int hm_cpuhp_notifier_cpu_remove(struct hm_notifier *notifier, unsigned int cpu);

#endif
