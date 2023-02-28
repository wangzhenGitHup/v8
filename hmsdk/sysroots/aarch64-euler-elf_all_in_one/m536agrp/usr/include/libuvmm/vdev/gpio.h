/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Mon June 24 17:21:40 2019
 */
#ifndef GPIO_H
#define GPIO_H

#include "dev_bus.h"

int dev_entity_init_gpio_in_named(device_entity_t *dev, irq_handler handler,
				  const char *name, int n_new,
				  const irq_info_t *irq_info);
int dev_entity_init_gpio_out_named(device_entity_t *dev, irq_entity_t **outs,
				   const char *name, int num);
int dev_entity_conn_gpio_out_named(device_entity_t *dev, const char *name,
				      irq_entity_t *irq, int index);
int dev_entity_intercept_gpio_out(device_entity_t *dev, const char *name,
				  irq_entity_t *icpt, int index);
irq_entity_t *dev_entity_get_gpio_in_named(device_entity_t *dev,
					   const char *name, unsigned int index);
irq_entity_t *dev_entity_get_gpio_out_named(device_entity_t *dev,
					    const char *name, int index);
#endif
