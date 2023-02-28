/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Fri May 24 11:31:40 2019
 */

#ifndef DEV_BUS_H
#define DEV_BUS_H

#include "entity.h"
#include "irq.h"
#include <lib/dlist.h>

typedef struct named_out_irq_entity {
	char *name;
	irq_entity_ptr *out_irq_ent;
	struct dlist_node sibling;
} named_out_irq_entity_t;

typedef struct named_gpio_list {
	char *name;
	irq_entity_t **in;
	int num_in;
	int num_out;
	named_out_irq_entity_t out_irq_head;
	struct dlist_node sibling;
} named_gpio_list_t;

typedef enum device_entity_category {
	DEVICE_CATEGORY_STORAGE,
	DEVICE_CATEGORY_NETWORK,
	DEVICE_CATEGORY_MAX
} device_entity_category_t;

typedef struct device_entity device_entity_t;
typedef struct bus_entity bus_entity_t;

typedef struct device_opset {
	entity_opset_t parent_opset;

	device_entity_category_t dev_category;
	const char *fw_name;
	const char *desc;

	int (*reset)(device_entity_t *dev);
	int (*realize)(device_entity_t *dev);
	int (*unrealize)(device_entity_t *dev);
} device_opset_t;

struct device_entity {
	entity_t parent_enity;

	char *id;
	bool realized;
	bus_entity_t *parent_bus;
	named_gpio_list_t gpios;
	/* forward declaration only works for pointer */
	bus_entity_t *child_bus;
	int num_child_bus;
};

typedef int (dev_entity_traverse_op)(device_entity_t *dev);
typedef int (bus_entity_traverse_op)(bus_entity_t *bus);

typedef struct bus_opset {
	entity_opset_t parent_opset;

	int (*reset)(bus_entity_t *bus);
	int (*realize)(bus_entity_t *bus);
	int (*unrealize)(bus_entity_t *bus);

	int max_dev;
	int auto_id;
} bus_opset_t;

typedef struct bus_entity_child {
	device_entity_t *child;

	int index;
	struct dlist_node sibling;
} bus_entity_child_t;

struct bus_entity {
	entity_t parent_ent;

	device_entity_t *parent_dev;
	char *name;
	int max_index;
	bool realized;
	bus_entity_child_t child_head;
	struct dlist_node sibling;
};
#endif
