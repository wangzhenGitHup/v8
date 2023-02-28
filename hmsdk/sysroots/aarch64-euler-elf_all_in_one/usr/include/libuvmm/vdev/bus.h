/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Fri May 24 14:20:40 2019
 */
#ifndef BUS_H
#define BUS_H
#include "dev_bus.h"

#define TYPE_BUS "bus"
#define BUS(ent) ENTITY_CHECK(bus_entity_t, (ent), TYPE_BUS)
#define BUS_OPSET(opset) ENTITY_OPSET_CHECK(bus_opset_t, (opset), TYPE_BUS)
#define BUS_GET_OPSET(ent) ENTITY_GET_OPSET(bus_opset_t, (ent), TYPE_BUS)

int bus_entity_create_fast(bus_entity_t *bus, int size, const char *typename,
			   device_entity_t *parent_dev, const char *name);
bool bus_entity_get_realized(const bus_entity_t *bus);
int do_bus_entity_set_realized(bus_entity_t *bus, bool is_realized);
int bus_entity_set_realized(bus_entity_t *bus, bool is_realized);

int bus_entity_remove_child(bus_entity_t *bus, device_entity_t *child);
int bus_entity_add_child(bus_entity_t *bus, device_entity_t *child);

int bus_entity_reset_one(bus_entity_t *bus);
int bus_entity_reset_all(bus_entity_t *bus);
/* returns 0 to walk children, > 0 to skip walk, < 0 to terminate walk */
int bus_entity_traverse_children(bus_entity_t *bus,
				 dev_entity_traverse_op *pre_dev_op,
				 bus_entity_traverse_op *pre_bus_op,
				 dev_entity_traverse_op *post_dev_op,
				 bus_entity_traverse_op *post_bus_op);
bus_entity_t *bus_search(bus_entity_t *bus, const char *bus_type);
#endif
