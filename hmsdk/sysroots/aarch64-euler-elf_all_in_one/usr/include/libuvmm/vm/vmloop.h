/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Tue Apr 6 21:35:22 2021
 */

#ifndef HM_VM_UVMM_VMLOOP_H
#define HM_VM_UVMM_VMLOOP_H

#include <lib/dlist.h>
#include <sys/epoll.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libhmsync/raw_mutex.h>

#include <external/libuvmm/uvmm.h>

struct vm_event_source;
struct vm_poll_sources;
typedef int (*event_handler)(const struct vm_event_source *source,
			     uint32_t events);

struct vm_event_source {
	struct dlist_node list;

	int fd;
	/* If set to true, vm loop will break when handler returns error */
	bool fatal_on_error;
	event_handler handler;
	void *priv;
};

struct vm_poll_sources {
	unsigned int active_count;

	struct raw_mutex source_list_lock;
	struct dlist_node source_head;

	int epoll_fd;
	int event_notify_fd;
	int signal_fd;
};

void vm_debug_request(const vcpu_t *vcpu);
int vm_add_event_source(vm_t *vm, int fd, event_handler handler,
			uint32_t poll_events, void *priv);
void vm_source_set_fatal_on_error(vm_t *vm, int fd, bool fatal_on_error);
void vm_release_event_source_by_fd(vm_t *vm, int fd, bool should_close);
int vm_loop_init(vm_t *vm);
void vm_loop_destroy(vm_t *vm);
void vm_notify_loop(const vm_t *vm);

#endif
