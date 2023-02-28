/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Wed Dec 19 13:34:09 2018
 */

#ifndef HM_UVMM_VMEXIT_H
#define HM_UVMM_VMEXIT_H

#include <lib/dlist.h>
#include <asm/drivers/hypervisor.h>
#include <external/libuvmm/uvmm.h>

#include "hyptrace_stats.h"

#define MSREX_DIR_READ		(1U)
#define MSREX_DIR_WRITE		(0U)
/* arm v8 manual C5.1.5 debug and trace system registers */
#define MSREX_OP0_DEBUG		(2U)
/* arm v8 manual C5.1.6 non-debug and special-purpose registers */
#define MSREX_OP0_NDSP		(3U)
#define MSREX_OP1_OPT		(3U)
#define MSREX_CRN_PMU		(9U)

struct svc_hvc_handler {
	struct dlist_node node;
	const char *name;
	bool (*check)(uint64_t vcpu_x0);
	int (*handle)(vcpu_t *vcpu, esr_t esr);

#ifdef CONFIG_HMUEV
	struct hyptrace_stats hvc_stats[MAX_VCPUS];
#endif
};

#define svc_hvc_handler_register(handler)				\
static void __attribute__((constructor)) do_svc_hvc_init_##handler(void)	\
{									\
	(void)register_svc_hvc_handler(&(handler));			\
}

int vmexit_create_listener_thread(vm_t *vm, unsigned int id);
void vmexit_clean_listener_threads(const vm_t *vm);
int handle_psci_func(vcpu_t *vcpu, esr_t esr);
bool is_psci(uint64_t x0);
int register_svc_hvc_handler(struct svc_hvc_handler  *handler);
int unregister_svc_hvc_handler(const struct svc_hvc_handler *handler);

#ifdef CONFIG_HMUEV
void show_hvc_trace_stats(uint32_t num_vcpus);
void clear_hvc_trace_stats(void);
#endif

#endif
