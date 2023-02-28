/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Klog
 * Author: Huawei OS Kernel Lab
 * Create: Sat Jun 9 07:55:53 2018
 */
#ifndef KLIBS_KLOG_H
#define KLIBS_KLOG_H

#include <hmkernel/klog_level.h>
#include <hmkernel/compiler.h>
#include <hmkernel/types.h>
#include <stdarg.h>

extern void
klog_set_time_offset(u64 offset);

extern void
klog_set_read_time(u64 (*func)(void));

extern void
klog_set_read_time_nolock(u64 (*func)(void));

extern void
klog_log_time_enable(bool enable);

/* Force output with klog level */
extern void __printf(2, 3)
klog_printf(enum klog_level level, const char *fmt, ...);

/*
 * nolock == false: klog print with lock, include timekeeplock and kconsolelock
 * nolock == true: klog print without lock, and print to kev only
 */
extern void __printf(2, 3)
klog_printf_nolock(enum klog_level level, const char *fmt, ...);

extern void __printf(3, 0)
__klog_vprintf(bool nolock, enum klog_level level, const char *fmt, va_list args);

void klog_enter_lastword(void);
extern void klog_enable_multi_buffer(void);

#define __klog(lv, fmt, ...)		klog_printf(lv, "[%s:%d] "fmt, __func__, __LINE__, ##__VA_ARGS__)

#ifdef CONFIG_KLOG_PURE_NOLOCK
#define __klog_nolock(lv, fmt, ...)	klog_printf_nolock(lv, fmt, ##__VA_ARGS__)
#else
#define __klog_nolock(lv, fmt, ...)	klog_printf_nolock(lv, "[%s:%d] "fmt, __func__, __LINE__, ##__VA_ARGS__)
#endif /* CONFIG_KLOG_PURE_NOLOCK */

#ifdef CONFIG_DEBUG_BUILD
#define klog_debug(fmt...)		__klog(KLOG_DEBUG, fmt)
#define klog_debug_nolock(fmt...)	__klog_nolock(KLOG_DEBUG, fmt)
#else
static inline void __printf(1, 2)
__no_klog(const char *fmt, ...)
{
	UNUSED(fmt);
}
#define klog_debug(fmt...)		__no_klog(fmt)
#define klog_debug_nolock(fmt...)	__no_klog(fmt)
#endif /* CONFIG_DEBUG_BUILD */

#define klog_info(fmt...)		__klog(KLOG_INFO, fmt)
#define klog_warn(fmt...)		__klog(KLOG_WARN, fmt)
#define klog_error(fmt...)		__klog(KLOG_ERROR, fmt)
#define __klog_panic(fmt...)		__klog(KLOG_PANIC, fmt)
#define __klogv_panic(fmt, va)		__klog_vprintf(false, KLOG_PANIC, fmt, va)

/* nolock version */
#define klog_info_nolock(fmt...)	__klog_nolock(KLOG_INFO, fmt)
#define klog_warn_nolock(fmt...)	__klog_nolock(KLOG_WARN, fmt)
#define klog_error_nolock(fmt...)	__klog_nolock(KLOG_ERROR, fmt)
#define klog_panic_nolock(fmt...)	__klog_nolock(KLOG_PANIC, fmt)

#define klog_info_panic(is_panic, fmt...) \
	do { \
		if (is_panic) { \
			__klog(KLOG_PANIC, fmt); \
		} else { \
			__klog(KLOG_INFO, fmt); \
		} \
	} while (__false)

#define klog_info_panic_nolock(is_panic, fmt...) \
	do { \
		if (is_panic) { \
			__klog_nolock(KLOG_PANIC, fmt); \
		} else { \
			__klog_nolock(KLOG_INFO, fmt); \
		} \
	} while (__false)

#endif
