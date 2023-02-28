/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: hotplug head file
 * Author: Huawei OS Kernel Lab
 * Create: Dec 2 10:44:42 2021
 */

#ifndef HM_LIBUVMM_VM_HOTPLUG_H
#define HM_LIBUVMM_VM_HOTPLUG_H

#include <libhmnotifier/hm_cpuhp_notifier.h>
#include "vm.h"

#define UVMM_CPUHP_LISTENER_PRIORITY		(99U)
#define VM_HOTPLUG_NOTIFY_TIMEOUT		(1) /* 1 second */
#define VM_HOTPLUG_FUTEX_RUN			(1)
#define VM_HOTPLUG_FUTEX_STOP			(0)
#define VM_HOTPLUG_CPU_ADD			CPU_ADD
#define VM_HOTPLUG_CPU_ADD_FAILED		CPU_ADD_FAILED
#define VM_HOTPLUG_CPU_REMOVE			CPU_REMOVE
#define VM_HOTPLUG_CPU_REMOVE_FAILED		CPU_REMOVE_FAILED

#define VM_HOTPLUG_VCPU_IRQ			(148 + 32)
#define VM_NOTIFY_HOTPLUG_ADDR			(0x200001000)

#define VM_NOTIFY_HOTPLUG_SIZE			(sizeof(raw_atomic_int_t)) /* size equal with vm->expect_mask */
#define vcpu_offline_mask(index)		(unsigned int)(1UL << (index))

typedef int (*cpuhp_notifier_op)(const struct hm_notifier_cb *ops);

void hotplug_notifier_call(const cpuhp_notifier_op func);
int hotplug_proc_cpu_event(vm_t *vm, unsigned int core, unsigned int event);
void hotplug_futex_wakeup(vcpu_t *vcpu, int action);
bool hotplug_is_vcpu_poweroff(const vcpu_t *vcpu);

#define HOTPLUG_NOTIFIER_REGISTER	hotplug_notifier_call(cpuhp_notifier_create_listener_helper)
#define HOTPLUG_NOTIFIER_UNREGISTER	hotplug_notifier_call(cpuhp_notifier_remove_listener_helper)


#endif /* end of #ifndef HM_LIBUVMM_VM_HOTPLUG_H */
