/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: proc signal of uvmm
 * Author: Huawei OS Kernel Lab
 * Create: Jan 25 16:44:42 2022
 */

#ifndef HM_LIBUVMM_UVMM_SIGNAL_H
#define HM_LIBUVMM_UVMM_SIGNAL_H

#include "vm.h"

#define UVMM_SIGNAL_READ_FD		0
#define UVMM_SIGNAL_WRITE_FD		1
#define UVMM_SIGNAL_FD_NUM		2

typedef void *(*compat_thread_func)(void *);

struct compat_thread_arg {
	sigset_t mask;
	int fd;
};

int vm_signal_init(vm_t *vm);
void vm_signal_destroy(vm_t *vm);

#endif
