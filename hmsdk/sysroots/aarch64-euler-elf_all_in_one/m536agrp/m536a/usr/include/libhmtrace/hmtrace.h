/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Definition of data struct and declaration of hmtrace API
 * Author: Huawei OS Kernel Lab
 * Create: Mon Sep 9 16:30:16 2019
 */
#ifndef ULIBS_LIBHMTRACE_HMTRACE_H
#define ULIBS_LIBHMTRACE_HMTRACE_H

#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <lib/dlist.h>
#include <libhmtrace/efmt.h>
#include <libhmtrace/ring_buffer/ring_buffer.h>
#include <libbunch/bunch_ipc.h>

#define HMTRACE_MAX_CLASS_NAME_SIZE			32
#define HMTRACE_MAX_EVENT_NAME_SIZE HMTRACE_MAX_CLASS_NAME_SIZE
#define HMTRACE_DEFAULT_LOCAL_BUFFER_SIZE		(1 << 16)
#define EVENT_DATA_HDR_SIZE				sizeof(struct event_data)
#define trace_info(format, ...) (void)printf(format, ##__VA_ARGS__)
#define trace_warn(format, ...) (void)fprintf(stderr, "[hmtrace|%s]"format, \
					      __func__, ##__VA_ARGS__)

struct uev_trace_event;

enum hmtrace_tracing_status {
	TRACING_OFF = 0x0,
	TRACING_ON,
};

struct event_data {
	int eid;
	uint64_t timestamp;
	unsigned char data[0];
};

struct event_entry {
	int eid;
	struct class_entry *class_entry;
	struct dlist_node dlist;

	/* event status, reference enumeration value */
	enum hmtrace_tracing_status status;
};

struct hmtrace_event {
	struct event_entry event_entry;

	/* specify event name */
	char name[HMTRACE_MAX_EVENT_NAME_SIZE];
	struct event_format *efmt;
};

struct class_entry {
	struct dlist_node dlist;

	/* holds a link list of registered events */
	struct dlist_node events_list;

	/* this class's ring buffer */
	struct rb *rb;

	/* the number of events registered on this class */
	int event_num;
};

struct hmtrace_class {
	struct class_entry class_entry;

	/* specify hmtrace class name */
	char name[HMTRACE_MAX_CLASS_NAME_SIZE];

	union {
		struct uev_trace_event **uev_table;
	} event_table;
	size_t table_size;
	/* called when register the event by hmtrace.elf */
	int (*register_event)(struct hmtrace_class *trace_class,
			      const void *buffer, unsigned int buffer_size);

	/* called when unregister the event by hmtrace.elf */
	int (*unregister_event)(struct hmtrace_class *trace_class,
				const void *buffer, unsigned int buffer_size);

	/* called when enable the event by hmtrace.elf */
	int (*enable_event)(const struct hmtrace_event *trace_event);

	/* called when disable the event by hmtrace.elf */
	int (*disable_event)(const struct hmtrace_event *trace_event);

	/* called when get_available_events_list by hmtrace.elf */
	int (*get_available_events_list)(struct bunch *bunch, void *data);

	/* called when show event by hmtrace.elf */
	int (*prepare_for_show)(struct hmtrace_class *trace_class);
};

#define HMTRACE_CLASS_ENTRY_INIT(class_entry) { DLIST_HEAD_INIT((class_entry).dlist),\
						DLIST_HEAD_INIT((class_entry).events_list),\
						NULL, 0 }

#define HMTRACE_EVENT_ENTRY_INIT(event_entry) { -1, NULL, \
						DLIST_HEAD_INIT((event_entry).dlist),\
						TRACING_OFF }

/* init hmtrace framework */
void hm_trace_init(pid_t pid);

/* init class entry before register class */
void class_entry_init(struct class_entry *class_entry);

/* register a class */
int hm_trace_register_class(struct hmtrace_class *trace_class);

/* unregister a class */
int hm_trace_unregister_class(struct hmtrace_class *trace_class);

/* acquire the struct of trace_class by class_name */
struct hmtrace_class *hm_trace_class_of_class_name(const char* class_name);

/* init event entry before register event */
void event_entry_init(struct event_entry *event_entry);

/* register a event, a event can only be registered to a unique class */
int hm_trace_register_event(struct hmtrace_class *trace_class,
			    struct hmtrace_event *trace_event);

/* unregister a event, and remove from events_class belongs to */
int hm_trace_unregister_event(struct hmtrace_event *trace_event);

/* acquire the struct of trace_event by class_name and event_name */
struct hmtrace_event *hm_trace_event_of_event_name(const struct hmtrace_class *trace_class,
						   const char *event_name);

/* set event tracing on by server */
int hm_trace_set_event_tracing_on(struct hmtrace_event *trace_event);

/* set event tracing on by server */
int hm_trace_set_event_tracing_off(struct hmtrace_event *trace_event);

/* get event tracing status by server */
int hm_trace_get_event_tracing_status(struct hmtrace_event *trace_event,
				      int *status);

/* write event data to buffer, with checking validity of event */
int hm_trace_write_event(struct hmtrace_event *trace_event,
			 const void *data, size_t data_size);

/* turn on/off all the trace event in hmtrace */
int hm_trace_tracing_on(enum hmtrace_tracing_status status);

int hm_trace_write_event_unblock(struct hmtrace_event *trace_event,
				 const void *data, size_t data_size);
#endif
