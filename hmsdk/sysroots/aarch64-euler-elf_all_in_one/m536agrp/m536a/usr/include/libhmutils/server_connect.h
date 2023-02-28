/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Security server connect header
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jul 06 19:48:39 2021
 */
#ifndef LIBHMSRV_SEC_SERVER_CONNECT_H
#define LIBHMSRV_SEC_SERVER_CONNECT_H

#include <libmem/utils.h>
#include <hmkernel/const.h>
#include <hongmeng/types.h>
#include <hongmeng/errno.h>
#include <libhmlog/hmlog.h>
#include <libhmucap/ucap.h>
#include <libhmsync/raw_mutex.h>
#include <libhmsrv_sys/hm_path.h>
#include <libhmsrv_sys/hm_procmgr.h>

struct hm_server_connector {
	char *path;
	rref_t rref;
	struct raw_mutex lock;
	struct hm_post_fork_hook *hook;
};

void hm_server_connect(struct hm_server_connector *sc);
void hm_server_connector_init(struct hm_server_connector *sc, char *path,
			      struct hm_post_fork_hook *hook);

#endif
