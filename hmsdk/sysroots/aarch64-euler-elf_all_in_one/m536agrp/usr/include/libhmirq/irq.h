/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Irq lib for hongmeng irq part
 * Author: Huawei OS Kernel Lab
 * Create: Wed Apr 24 10:32:19 2019
 */
#ifndef ULIBS_LIBHMIRQ_IRQ_H
#define ULIBS_LIBHMIRQ_IRQ_H

#include <stdint.h>
#include <hmkernel/cpuset.h>
#include <hmkernel/capability.h>

struct hm_irq_register_setting {
	const char *name;		/* max strlen is 31 */
	uint32_t flags;			/* 0x01 wakeup */
};

int hm_irq_init_idx(void);
int hm_irq_conf_to_irq(int ctrl_id, const uint32_t *conf,
		       uint32_t conf_len, uint32_t cpu_id);
int hm_irq_suspend(void);
int hm_irq_resume(void);
rref_t hm_irq_require_grant(int ctrl_id, uint32_t irq);
int hm_irq_reject_grant(rref_t irq_rref);
int hm_irq_config(rref_t irq_rref, uint32_t irq,
		  uint32_t *conf, uint32_t conf_len);
int hm_irq_register(rref_t irq_rref, uint32_t irq,
		    const struct hm_irq_register_setting *setting,
		    cref_t tcb_cref);
int hm_irq_unregister(rref_t irq_rref, uint32_t irq);
int hm_irq_generate_sgi(rref_t irq_rref, uint32_t irq,
			__cpuset_t target_set,
			void *arg, uint32_t arg_len);
int hm_irq_ioctl(rref_t irq_rref, uint32_t irq,
		 uint32_t cmd, const void *arg, uint32_t arg_len);

#endif
