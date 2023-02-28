/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Fri Apr 9 16:04:22 2021
 */

#ifndef HM_UVMM_VM_VMGDB_H
#define HM_UVMM_VM_VMGDB_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <libhmsync/raw_mutex.h>
#include <hongmeng/errno.h>

#include <external/libuvmm/uvmm.h>

#define gdbstub_backend_init(btype, ops)				\
static void __attribute__((constructor)) backend_init_##btype(void)	\
{									\
	vm_gdbstub_register_backend(btype, ops);			\
}

#define MAX_DATA_LENGTH (4096U)

enum vm_gdbstub_backend_type {
	GDBSTUB_BACKEND_PIPE = 0,
	GDBSTUB_BACKEND_SOCKET,
	GDBSTUB_BACKEND_INVALID,
#define GDBSTUB_BACKEND_COUNT (int)(GDBSTUB_BACKEND_INVALID)
};

struct vm_gdbstub_backend_operations {
	int (*prepare_gdbstub)(vm_t *vm, const char *input_arg);
	int (*start_gdbstub)(vm_t *vm);
	void (*release_gdbstub)(vm_t *vm);
};

struct vm_gdbstub_backend {
	enum vm_gdbstub_backend_type btype;
	const struct vm_gdbstub_backend_operations *ops;
};

struct vm_gdbstub {
	const struct vm_gdbstub_backend *backend;
	void *priv_data;
};

struct vm_gdbstub_session {
	struct raw_mutex session_lock;
	vm_t *vm;
	int out_fd;
};

bool is_vm_gdbstub_available(const vm_t *vm);
void vm_gdbstub_destroy(vm_t *vm);
int vm_gdbstub_start(vm_t *vm, const char *gdb_args);
int vm_gdbstub_release(vm_t *vm);
void vm_gdbstub_set_privdata(vm_t *vm, void *priv_data);
void *vm_gdbstub_get_privdata(vm_t *vm);

void vm_gdbstub_register_backend(enum vm_gdbstub_backend_type btype,
				 const struct vm_gdbstub_backend_operations *ops);

const struct vm_gdbstub_backend *vm_find_gdbstub_backend(
				enum vm_gdbstub_backend_type btype);

int gdbstub_receive(const uint8_t *buffer, size_t len);
void gdbstub_send(const uint8_t *buffer, size_t len);
int init_gdbstub_session(vm_t *vm, int out_fd);
void release_gdbstub_session(void);

static inline ssize_t write_io(int fd, const void *buf, size_t count)
{
	ssize_t ret = E_HM_OK;
	do {
		ret = write(fd, buf, count);
	} while (ret < 0 && errno == EINTR);

	if (ret < 0) {
		ret = posix2hmerrno(errno);
	}
	return ret;
}

static inline ssize_t read_io(int fd, void *buf, size_t count)
{
	ssize_t ret = E_HM_OK;
	do {
		ret = read(fd, buf, count);
	} while (ret < 0 && errno == EINTR);

	if (ret < 0) {
		ret = posix2hmerrno(errno);
	}
	return ret;
}

#endif
