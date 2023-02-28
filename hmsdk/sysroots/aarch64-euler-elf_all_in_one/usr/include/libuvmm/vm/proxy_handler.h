/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Handler for proxies
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jun 15 14:32:07 2021
 */
#ifndef HM_UVMM_PROXY_HANDLER_H
#define HM_UVMM_PROXY_HANDLER_H

#include <libvpipe/vnotify.h>
#include <libuvmm/mmio.h>
#include <libuvmm/vm.h>

#define SHMGET_FUNC 	1020ULL
#define SHMMAP_FUNC 	1021ULL
#define SHMUNMAP_FUNC 	1022ULL
#define SHMCTL_FUNC 	1023ULL

int proxy_handler_hvc(vcpu_t *vcpu, esr_t esr);
int proxy_handler_vnotify(struct vnotify_msg_s *msg,
			  struct vnotify_resp_s *resp);

int handle_module_ipc(struct vnotify_msg_s *msg, struct vnotify_resp_s *resp);
int handle_module_mem(struct vnotify_msg_s *msg, struct vnotify_resp_s *resp);
int handle_module_file(struct vnotify_msg_s *msg, struct vnotify_resp_s *resp);

static inline bool is_proxy_handler(uint64_t vcpu_x0)
{
	return ((vcpu_x0 >= SHMGET_FUNC) && (vcpu_x0 <= SHMCTL_FUNC));
}
#endif
