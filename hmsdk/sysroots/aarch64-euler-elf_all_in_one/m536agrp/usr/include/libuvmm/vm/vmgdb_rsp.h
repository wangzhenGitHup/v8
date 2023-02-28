/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Wed Apr 21 17:01:52 2021
 */

#ifndef HM_UVMM_VM_VMGDB_RSP_H
#define HM_UVMM_VM_VMGDB_RSP_H

#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "vmgdb_rsp_cmd.h"

#define MAX_VALUE_COUNT_PER_CMD (5U)

enum vmgdb_cmd_value_kind {
	CMD_VALUE_KIND_STRING = 0U,
	CMD_VALUE_KIND_CHAR,
	CMD_VALUE_KIND_INTEGER,
	CMD_VALUE_KIND_THREAD_ID,
};

enum thread_id_kind {
	THREAD_ID_ALL_PROCESS,
	THREAD_ID_ALL_THREAD,
	THREAD_ID_ONE_THREAD,
};

struct thread_id {
	enum thread_id_kind kind;
	uint32_t pid;
	uint32_t tid;
};

struct vmgdb_cmd_value {
	size_t text_len;
	enum vmgdb_cmd_value_kind value_kind;
	union {
		const char *string;
		char ch;
		__u64 u64_val;
		struct thread_id thread_id;
	} val;
};

struct vmgdb_cmd_value_list {
	size_t count;
	size_t capacity;
	struct vmgdb_cmd_value values[MAX_VALUE_COUNT_PER_CMD];
};

typedef int (*command_handler)(const struct vmgdb_cmd_value_list *value_list);

struct vmgdb_cmd_desc {
	const char *command;
	const char *format;
	command_handler handler;

	struct vmgdb_cmd_desc *subdesc_table;
	size_t subdesc_count;
};

int vmgdb_rsp_receive(const uint8_t *buffer, size_t len);
int vmgdb_rsp_init(vm_t *vm);
void vmgdb_rsp_send(const char *buffer);
void vmgdb_rsp_send_empty(void);

__attribute__((format(printf, 1, 2)))
void vmgdb_strbuf_write(const char *format, ...);
void vmgdb_strbuf_append_string(const char *str);
void vmgdb_strbuf_append_hex(const uint8_t *mem, size_t len);
int vmgdb_rsp_add_top_cmddescs(const struct vmgdb_cmd_desc *cmd_descs, size_t desc_count);
void vmgdb_rsp_send_strbuf(void);

#define CMD_DESC(__command, __format, __handler) 	\
{							\
	.command = (__command), 			\
	.format = (__format),				\
	.handler = (__handler),				\
	.subdesc_table = NULL,				\
	.subdesc_count = 0U				\
}

#define CMD_DESC_WITHSUB(__command, __format, __handler, __subtable)	\
{									\
	.command = (__command), 					\
	.format = (__format),						\
	.handler = (__handler),						\
	.subdesc_table = (__subtable),					\
	.subdesc_count = ARRAY_SIZE(__subtable)				\
}

int parse_cmd_value_list(struct vmgdb_cmd_value_list *cmd_value_list,
			 const char *text, const char *format);

int parse_gdb_thread_spec(const char *text, size_t text_len,
			  uint32_t *pid, uint32_t *tid, size_t *consumed_len);
enum thread_id_kind get_thread_id_kind(uint32_t pid, uint32_t tid);

const char *get_string_value_at(const struct vmgdb_cmd_value_list *value_list,
				size_t idx, size_t *len);
const uint8_t *get_ustr_value_at(const struct vmgdb_cmd_value_list *value_list,
				 size_t idx, size_t *len);
int get_char_value_at(const struct vmgdb_cmd_value_list *value_list,
		      size_t idx, char *ch_val);
int get_integer_value_u64_at(const struct vmgdb_cmd_value_list *value_list,
			 size_t idx, __u64 *value);
int get_integer_value_u32_at(const struct vmgdb_cmd_value_list *value_list,
			 size_t idx, __u32 *value);
const struct thread_id *get_thread_id_at(
			const struct vmgdb_cmd_value_list *value_list,
			size_t idx);

#endif
