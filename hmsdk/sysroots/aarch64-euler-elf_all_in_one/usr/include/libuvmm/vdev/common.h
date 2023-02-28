/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Tues May 28 11:31:40 2019
 */
#ifndef VEM_COMMON_H
#define VEM_COMMON_H

#include <stdbool.h>
#include <ctype.h>

#include <libhmlog/hmlog.h>
#include <hongmeng/panic.h>
#include <libhwsecurec/securec.h>
#include <lib/dlist.h>
#include <hongmeng/errno.h>

#include <search.h>
#include <limits.h>

#define v_tolower(c)	tolower((unsigned char)(c))
#define v_toupper(c)	toupper((unsigned char)(c))

char *v_strdup_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

enum DEVICE_TYPE {
	VIRTIO_MMIO,
#ifdef CONFIG_VDEV_SHMEM
	SHMEM_MMIO,
#endif
#ifdef CONFIG_VDEV_PL011
	PL011_MMIO,
#endif
#ifdef CONFIG_VDEV_PL031
	PL031_MMIO,
#endif
#ifdef CONFIG_VDEV_GPIO
	VIRTGPIO_MMIO,
#endif
#ifdef CONFIG_VDEV_PCA9555
	PCA9555_MMIO,
#endif
	TOTAL_DEVICE_NUM
};

#endif
