/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Prototypes for devhost interrupt APIs
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jan 11 10:45:12 2019
 */
#ifndef __DEVHOST_API_INTERRUPT_H__
#define __DEVHOST_API_INTERRUPT_H__

/*
 * CAUSION: This file will be used in linux source,
 *          **DO NOT** include any HMOS headers.
 */

/* for irq */
#define DEVHOST_IRQ_RUNQUEUE_NORMAL		52
#define DEVHOST_IRQ_RUNQUEUE_HIGH		53
#define DEVHOST_IRQ_RUNQUEUE_KVIC		54
/* devhost using 55 as masked irq priority */
#define DEVHOST_IRQ_RUNQUEUE_OFF		55

unsigned int devhost_create_irq_mapping(unsigned int oirq_offset,
					const unsigned int *args,
					unsigned int args_count);

/* same with linux irq_handler_t */
typedef int (*devhost_irq_handler_t)(int, void *);
int devhost_request_threaded_irq(unsigned int linux_irq,
				 devhost_irq_handler_t handler,
				 int is_kvic,
				 const char *devname,
				 void *dev_id);
void devhost_free_irq(unsigned int linux_irq);
void devhost_enable_irq(unsigned int linux_irq);
void devhost_disable_irq(unsigned int linux_irq);
int devhost_set_wake_irq(unsigned int linux_irq, unsigned int can_wakeup);

void devhost_disable_local_irq(void);
void devhost_enable_local_irq(void);
void devhost_restore_local_irq(unsigned long flags);
unsigned long devhost_save_local_irq(void);
unsigned long devhost_save_local_flags(void);

/* for kvic */
int devhost_kvic_default_ctrl(void);
/* kvic_irq_type: see <hmkernel/interrupt/kvic.h> */
int devhost_kvic_prepare_irq(unsigned int kvic_irq_type,
			     void *arg, unsigned int arg_len);
/* 0: invalid; 1-15: mapped virq */
unsigned int devhost_kvic_create_mapping(unsigned int kvic_irq_type);

#endif /* __DEVHOST_API_INTERRUPT_H__ */
