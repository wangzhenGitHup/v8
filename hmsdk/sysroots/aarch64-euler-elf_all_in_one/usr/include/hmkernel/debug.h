/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Headers of arm_debug module
 * Author: Huawei OS Kernel Lab
 * Create: Wed Apr 24 13:58:42 2019
 */
#ifndef UAPI_HMKERNEL_DEBUG_H
#define UAPI_HMKERNEL_DEBUG_H

#include <hmkernel/types.h>

enum __debug_config_cmd {
	DEBUG_CONFIG_GET_DEBUG_INFO,	/* get debug info */
	DEBUG_CONFIG_WP_REG,		/* arg len: 3 */
	DEBUG_CONFIG_WP_ENABLE,		/* arg len: 1, only use index */
	DEBUG_CONFIG_WP_DISABLE,	/* arg len: 1, only use index */
	DEBUG_CONFIG_SS_ENABLE,		/* enable single step, only for aarch64 */
	DEBUG_CONFIG_SS_DISABLE,	/* disable single step, only for aarch64 */
	DEBUG_CONFIG_INVAL,
};

struct __debug_config_arg {
	__u32 reg_idx;	/* config[0] */
	union {		/* config[1,2] */
		struct {
			__u64 addr;
			__u64 ctrl;
		} watch_point;
	};
};

struct __debug_config_result {
	union {
		struct {
			__u32 version;
			__u32 brp_nr;
			__u32 wrp_nr;
			__u32 max_wp_len;
		} debug_info;
	};
};

#endif
