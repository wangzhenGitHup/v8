/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jun 10 15:32:40 2019
 */
#ifndef IRQ_H
#define IRQ_H

#include "entity.h"

#define TYPE_IRQ "irq"
#define IRQ(ent) ENTITY_CHECK(struct irq_entity, (ent), TYPE_IRQ)

typedef int (*irq_handler)(unsigned int n, int level, void *opaque);
typedef struct irq_entity irq_entity_t;
typedef struct irq_entity *irq_entity_ptr;

struct irq_entity {
	entity_t parent_entity;
	void *dev;
	irq_handler handler;
	unsigned int n;
	void *opaque;
};

typedef struct irq_map_node {
	unsigned int irq_no;
	unsigned int num;
	unsigned int in_pins_start;
} irq_map_node_t;

typedef struct irq_info {
	irq_map_node_t *irqmap;
	void *opaque;
} irq_info_t;

typedef struct new_irq_arg {
	int n_new;
	irq_handler handler;
	void *dev;
	const irq_info_t *irq_info;
} new_irq_arg_t;

irq_entity_ptr *extend_irqs(irq_entity_ptr *irq_old, int num_old,
			    const new_irq_arg_t *args);
irq_entity_t *allocate_irq(irq_handler handler, void *dev, unsigned int index,
			   void *opaque);
int free_irq(irq_entity_t *irq);
int free_irqs(irq_entity_ptr *irq_head, int num);
#endif
