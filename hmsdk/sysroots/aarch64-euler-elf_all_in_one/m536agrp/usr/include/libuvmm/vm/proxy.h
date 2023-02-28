/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: plugin proxy module interface
 * Author: Huawei OS Kernel Lab
 * Create: Thu Aug 12 15:17:38 2021
 */
#ifndef HM_UVMM_PROXY_H
#define HM_UVMM_PROXY_H

struct vnotify_msg_s;
struct vnotify_resp_s;

struct module_func_s {
	int (*func)(struct vnotify_msg_s *msg, struct vnotify_resp_s *resp);
};

int proxy_module_register(unsigned int module_id,
			  int (*func)(struct vnotify_msg_s *msg,
				      struct vnotify_resp_s *resp));
int proxy_module_unregister(unsigned int module_id);
int proxy_modules_invoke(unsigned int module_id,
			 struct vnotify_msg_s *msg,
			 struct vnotify_resp_s *resp);
#endif
