/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Definition for hongmeng system shutdown native api
 * Author: Huawei OS Kernel Lab
 * Create: Wed Sep 25 11:45:32 2019
 */

#ifndef ULIBS_LIBHMPM_SHUTDOWN_H
#define ULIBS_LIBHMPM_SHUTDOWN_H

#define REBOOT_CMD_LEN	96
struct reboot_cmd {
	char string[REBOOT_CMD_LEN];
};

int hm_shut_down(void);
int hm_reboot(const char *cmd);

#endif
