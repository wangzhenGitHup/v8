/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2022. All rights reserved.
 * Description: Hypervisor trace stats interface
 * Author: Huawei OS Kernel Lab
 * Create: Sat Mar 12 14:48:37 2022
 */

#ifndef HM_LIBUVMM_VM_HYPTRACE_STATS_H
#define HM_LIBUVMM_VM_HYPTRACE_STATS_H

#include <asm/sysreg_utils.h>
#include <stdint.h>

#include "vm.h"

#define FILTER_TIME_US	5000UL // 5ms
#define MS_PER_SEC	1000UL


static inline __always_inline uint64_t get_sysclock(void)
{
	return __aarch64_read_sysreg("CNTPCT_EL0");
}

#ifdef CONFIG_TRACE_TRAP_TIMEOUT
static inline __always_inline uint64_t ms_to_ticks(uint64_t ms)
{
	return ms * __aarch64_read_sysreg("CNTFRQ_EL0") / MS_PER_SEC;
}

struct alarm_clock {
	uint64_t timeout; /* all in ticks */
	uint64_t begin;
	uint64_t end;
};

static inline __always_inline
uint64_t alarm_clock_to_ms(const struct alarm_clock *alarm)
{
	uint64_t spend = alarm->end - alarm->begin;
	return spend * MS_PER_SEC / __aarch64_read_sysreg("CNTFRQ_EL0");
}

#define trace_timeout_begin(name, time)					\
	struct alarm_clock name##_clock = {				\
		.begin = get_sysclock(),				\
		.timeout = (time),					\
		.end = 0UL,						\
	}

#define trace_timeout_end(name, __format, ...)					\
do {										\
	(name##_clock).end = get_sysclock();					\
	if (((name##_clock).end - (name##_clock).begin) >=			\
	     (name##_clock).timeout) {						\
		hm_warn(("[%lu, %lu] spend %lu ms. "__format),			\
			   (name##_clock).begin, (name##_clock).end,		\
			   alarm_clock_to_ms(&(name##_clock)), ##__VA_ARGS__);	\
	}									\
} while (0)
#else

#define trace_timeout_begin(name, time)
#define trace_timeout_end(name, __format, ...)
#endif

#ifdef CONFIG_HMUEV
struct hyptrace_stats {
	uint64_t count;
	/* Count the number of events that took longer than FILTER_TIME_US */
	uint64_t filter_count;

	/* The units of xxx_time are clock ticks */
	uint64_t max_time;
	uint64_t min_time;
	uint64_t total_time;
	uint64_t __begin_time;
};

void print_hyptrace_stats(const struct hyptrace_stats *stats, uint32_t vcpu_id,
			  const char *event_name);

void show_hyptrace_stats(const vm_t *vm);
void clear_hyptrace_stats(void);

void enable_hyptrace_stats(void);
void disable_hyptrace_stats(void);

void uev_trace_handle_hvc_register(void);
void uev_trace_mmio_rw_register(void);
#else /* !CONFIG_HMUEV */
static inline void uev_trace_handle_hvc_register(void) {}
static inline void uev_trace_mmio_rw_register(void) {}
#endif

#endif
