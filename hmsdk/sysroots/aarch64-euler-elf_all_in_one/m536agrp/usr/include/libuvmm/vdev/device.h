/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Fri May 24 15:13:20 2019
 */

#ifndef DEVICE_H
#define DEVICE_H

#include "dev_bus.h"

#define TYPE_DEVICE "device"
#define DEVICE(ent) ENTITY_CHECK(device_entity_t, (ent), TYPE_DEVICE)
#define DEVICE_OPSET(opset) ENTITY_OPSET_CHECK(device_opset_t, (opset), TYPE_DEVICE)
#define DEVICE_GET_OPSET(ent) ENTITY_GET_OPSET(device_opset_t, (ent), TYPE_DEVICE)

device_entity_t *dev_entity_create(bus_entity_t *bus, const char *typename,
				   const char *device_name);

int dev_entity_reset_one(device_entity_t *dev);
int dev_entity_reset_all(device_entity_t *dev);

device_entity_t *dev_search_on_bus(const bus_entity_t *bus, const char *id);
bus_entity_t *dev_entity_get_parent_bus(device_entity_t *dev);
bus_entity_t *dev_entity_get_child_bus(const device_entity_t *dev, const char *name);

bool dev_entity_get_realized(const device_entity_t *dev);
int do_dev_entity_set_realized(device_entity_t *dev, bool is_realized);
int dev_entity_set_realized(device_entity_t *dev, bool is_realized);

/* returns E_HM_OK to walk children, > 0 to skip walk, < 0 to terminate walk */
int dev_entity_traverse_children(device_entity_t *dev,
				 dev_entity_traverse_op *pre_dev_op,
				 bus_entity_traverse_op *pre_bus_op,
				 dev_entity_traverse_op *post_dev_op,
				 bus_entity_traverse_op *post_bus_op);
#endif
