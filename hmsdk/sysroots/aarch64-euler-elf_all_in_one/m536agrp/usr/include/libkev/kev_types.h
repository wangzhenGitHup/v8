/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Provide kev structures for reading kev
 * Author: Huawei OS Kernel Lab
 * Create: Thu Feb 27 10:02:38 2020
 */

#ifndef ULIBS_LIBKEV_KEV_TYPES_H
#define ULIBS_LIBKEV_KEV_TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <hmkernel/audit.h>
#include <hongmeng/macro.h>
#include <hmkernel/perf_event.h>
#include <hmkernel/events/kev.h>
#include <hmkernel/events/kev_fiq_texts.h>

#define DEFINE_KEV(N, ...) KEV_TYPE_##N,
enum kev_type {
#include <hmkernel/events/kev_list.h>
		KEV_TYPE_NR,
};
#undef DEFINE_KEV

#define KEV_EVENT_SIZE_BITS	12U
#define KEV_TYPE_BITS		12U
#define KEV_CPU_BITS		8U
struct kev_header_s {
	uint32_t evt_size : KEV_EVENT_SIZE_BITS;
	uint32_t type : KEV_TYPE_BITS;
	uint32_t cpuid : KEV_CPU_BITS;
};

struct kev_s {
	struct kev_header_s header;
	unsigned char data[0];
};

#define __KEV_STRING(name, size)	name[size]
#define KEV_STRUCT(...)	__VA_ARGS__
#define KEV_STRUCT_GEN(name, n, ...)					\
		struct kev_##name##_s {					\
			struct kev_header_s header;			\
			__SC_MAPSTAT(n, __SC_DECL, __VA_ARGS__);	\
		};

#define DEFINE_KEV(NAME, name, args, str, ...)				\
	KEV_STRUCT_GEN(name, str)

#include <hmkernel/events/kev_list.h>

#undef __KEV_STRING
#undef DEFINE_KEV

static inline bool kev_type_is_valid(unsigned int type)
{
	return type < (unsigned int)KEV_TYPE_NR;
}

const char *kev_name_of_type(enum kev_type type);
enum kev_type kev_type_of_name(const char *name);

#endif
