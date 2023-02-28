/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: Interface for thread names
 * Author: Huawei OS Kernel Lab
 * Create: Thu Mar 10 13:34:09 2022
 */

#ifndef HM_UVMM_UVMM_THREADS_H
#define HM_UVMM_UVMM_THREADS_H

#include <libhmsrv_sys/hm_thread.h>
#include <hongmeng/errno.h>
#include <libhmlog/hmlog.h>

/* vm.elf thread names */
#define VM_MAIN_TNAME			"vm-main"
#define VM_VCPU_TNAME			"vm-vcpu-"
#define VM_LISTENER_TNAME		"vm-listener-"
#define VM_NET_IO_TNAME			"vm-net-io"
#define VM_PL011_TNAME			"vm-pl011"
#define VM_SHMEM_DEV_TNAME		"vm-shmem-dev"
#define VM_VIRT_GPIO_TNAME		"vm-virt-gpio"
#define VM_BLOCK_DEV_TNAME		"vm-blkdev"
#define VM_VIRTIO_CONSOLE_TNAME		"vm-virtio-con"
#define VM_CTRL_VNOTIFY_TNAME		"vm-ctl-notify"
#define VM_SIGNAL_TNAME			"vm-signal"

static inline void set_self_thread_name(const char *name)
{
	int err = hm_thread_setname((cref_t)0, name, NULL);
	if (err != E_HM_OK) {
		hm_warn("set thread name failed: %s\n", name);
	}
}

#endif // HM_UVMM_UVMM_THREADS_H
