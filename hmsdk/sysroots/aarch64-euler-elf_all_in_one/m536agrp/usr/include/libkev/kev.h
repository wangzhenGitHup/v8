/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Provide structure and interfaces for reading kev
 * Author: Huawei OS Kernel Lab
 * Create: Thu Feb 27 10:58:03 2020
 */

#ifndef ULIBS_LIBKEV_KEV_H
#define ULIBS_LIBKEV_KEV_H

#include "kev_types.h"

struct kev_config {
	bool enable;
	/*
	 * 'buffer' is a bitmap vector, bit 0 for ring buffer 0,
	 * bit 1 for ring buffer 1, etc.
	 */
	uint32_t buffer;
	uint64_t paddr;
	uint32_t size;
};

/*
 * read event configuration specified by 'type'. the event configuration readed
 * by this function include the index of ring buffer that contains the event
 * and the information whether the event is enabled in system.
 */
int kev_read_event_config(enum kev_type type, struct kev_config *config);

/* read the kev ringbuffer index specified by @kev_type */
int kev_buffer_index_of(unsigned int kev_type, unsigned int *buffer_index);

/* read the kev ringbuffer index specified by @config */
int kev_buffer_config_index_of(unsigned int kev_type, struct kev_config *config,
			       unsigned int *buffer_index);

/* read the current write head of ring buffer specified by 'index' */
int kev_read_head_of_buffer(unsigned int index, uint64_t *head);

/*
 * read up to 'size' bytes from position 'head' in ring buffer
 * specified by 'index' directly to buffer 'buf'.
 * NOTE: if 'head' eqauls to zero, data copy will start from current
 * write head in ring buffer.
 */
ssize_t kev_read_data(unsigned int index, uint64_t head,
		      char *buf, size_t size);

/*
 * access each kev stored in buffer 'buf' in order of time and
 * pass kev as a parameter to the callback function 'action'.
 */
int kev_for_each(const char *buf, size_t size,
		 int (*action)(const struct kev_s *event, uintptr_t arg),
		 uintptr_t arg);

/* enable or disable the event tracing specified by @event_name */
int kev_set_enable(const char *event_name, unsigned int enable);
int kev_set_filter(const char *event_name, const char *filter);

#endif
