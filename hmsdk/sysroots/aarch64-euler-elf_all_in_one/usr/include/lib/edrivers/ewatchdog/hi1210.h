/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Header for ewatchdog hi1210
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jan 28 13:17:45 2021
 */

#ifndef LIB_EDRIVERS_EWATCHDOG_HI1210_H
#define LIB_EDRIVERS_EWATCHDOG_HI1210_H

#include <lib/edrivers/ewatchdog.h>
#include <hmkernel/types.h>

struct ewatchdog_hi1210_pin_info {
	void __iomem* base_addr;

	u32 pin;
	u32 pulse_width;
	u32 last_width;
	u32 gpio_pin;
	u32 reset_pin;
};

#define EWATCHDOG_HI1210_MAX_PULSE_NUM	5u

struct ewatchdog_hi1210_dev {
	struct ewatchdog_dev edev;
	struct ewatchdog_hi1210_pin_info wdt_array[EWATCHDOG_HI1210_MAX_PULSE_NUM];
	unsigned int pulse_num;
};

void ewatchdog_hi1210_init(struct ewatchdog_hi1210_dev *hi1210_dev, paddr_t base_addr_phy);

#endif
