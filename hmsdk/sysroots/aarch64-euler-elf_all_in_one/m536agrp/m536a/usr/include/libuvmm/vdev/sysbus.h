/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jun 10 16:30:40 2019
 */
#ifndef SYSBUS_H
#define SYSBUS_H
#include "dev_bus.h"
#include "vm.h"

#define TYPE_SYSTEM_BUS "main-system-bus"
#define SYSTEM_BUS(ent) ENTITY_CHECK(system_bus_t, (ent), TYPE_SYSTEM_BUS)

struct system_bus {
	bus_entity_t bus_ent;
	vm_t *vm;
};

system_bus_t *sysbus_create(vm_t *vm);
system_bus_t *sysbus_get_default(void);
void sysbus_destroy(vm_t *vm);

#endif
