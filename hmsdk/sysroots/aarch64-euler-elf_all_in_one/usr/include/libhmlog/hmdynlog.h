/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2022. All rights reserved.
 * Description: Definitions of dynamic log interfaces
 * Author: Huawei OS Kernel Lab
 * Create: Sat Aug 29 09:56:47 2020
 */
#ifndef ULIBS_INCLUDE_LIBHMLOG_HMDYNLOG_H
#define ULIBS_INCLUDE_LIBHMLOG_HMDYNLOG_H

#include <unistd.h>
#include <libhmlog/hmlog_common.h>

#define DYNLOG_INDEX_ALL	INT_MAX
#define HMLOG_FORMAT_SIZE	128U
#define HMLOG_PATH_SIZE		128U
#define HMLOG_SPACE_SIZE	32U

struct dynlog_read_entry {
	pid_t pid;
	unsigned int line;
	int freq;
	char format[HMLOG_FORMAT_SIZE];
	char path[HMLOG_PATH_SIZE];
	char space[HMLOG_SPACE_SIZE];
};

int hm_dynlog_query_by_tid(pid_t tid);
int hm_dynlog_read_by_tid(pid_t tid, const struct dynlog_read_entry *rentry, int num);
int hm_dynlog_update_by_tid(pid_t tid, int index, int freq);
int hm_dynlog_query_by_lspace(const char *lspace);
int hm_dynlog_read_by_lspace(const char *lspace, const struct dynlog_read_entry *rentry, int num);
int hm_dynlog_update_by_lspace(const char *lspace, int index, int freq);

#endif /* !ULIBS_INCLUDE_LIBHMLOG_HMDYNLOG_H */
