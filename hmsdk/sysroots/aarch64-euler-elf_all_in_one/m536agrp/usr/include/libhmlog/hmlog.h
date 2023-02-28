/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2022. All rights reserved.
 * Description: Definitions of hongmeng kernel log api
 * Author: Huawei OS Kernel Lab
 * Create: Wed Sep 19 03:43:55 2018
 */
#ifndef ULIBS_INCLUDE_LIBHMLOG_HMLOG_H
#define ULIBS_INCLUDE_LIBHMLOG_HMLOG_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <hongmeng/types.h>
#include <hmkernel/klog_level.h>
#include <libhmlog/hmlog_common.h>

#ifdef __HOST_LLT__
char *get_hmlog_buffer(void);
void clear_hmlog_buffer(void);
#endif

#ifndef __hmbuild__
# ifdef CONFIG_DEBUG_BUILD
#  define __hmfeature_debug__
# else
#  define __hmfeature_no_debug__
# endif
#endif

/* Only show addresses on the debug build */
#ifdef __hmfeature_debug__
#define vaddr_of(ptr) (unsigned long)(uintptr_t)(ptr)
#else
#define vaddr_of(ptr) ({uintptr_t __p; __p = (ptr) == NULL ? 0UL : UINTPTR_MAX; (unsigned long)__p;})
#endif

#define HMLOG_LEVEL_NR KLOG_LEVEL_NR
enum hmlog_level {
	HMLOG_DEBUG =	KLOG_DEBUG,
	HMLOG_INFO =	KLOG_INFO,
	HMLOG_WARN =	KLOG_WARN,
	HMLOG_ERROR =	KLOG_ERROR,
	HMLOG_PANIC =	KLOG_PANIC,
	HMLOG_INVALID =	KLOG_INVALID,
};

#ifdef __HOST_LLT__
enum hmlog_output_type {
	HMLOG_OUTPUT_PRINTF,
	HMLOG_OUTPUT_BUFFER,
	HMLOG_OUTPUT_INVAL,
};
#define HMLOG_DEFAULT_OUTPUT HMLOG_OUTPUT_PRINTF
#else
enum hmlog_output_type {
	HMLOG_OUTPUT_KBOX,
	HMLOG_OUTPUT_CONSOLE,
	HMLOG_OUTPUT_INVAL,
};
#define HMLOG_DEFAULT_OUTPUT HMLOG_OUTPUT_KBOX
#endif

void __attribute__((noreturn))
__panic_impl(const char *file, const char *func, int line);

void __attribute__((format(printf, 5, 6)))
__hmlog_printf(enum hmlog_level level, const char *file, const char *func,
	       int line, const char *fmt, ...);

void  __attribute__((format(printf, 4, 0)))
__hmlog_vprintf(enum hmlog_level level, const char *func,
		int line, const char *fmt, va_list args);

void __attribute__((format(printf, 5, 6)))
__hmlog_printf_syslog(enum hmlog_level level, const char *file, const char *func,
		      int line, const char *fmt, ...);

/* wait to be deleted */
#define hmlog_setlevel(level)

void hmlog_setoutput(enum hmlog_output_type output);

void hmlog_output(enum hmlog_output_type output_type, enum hmlog_level level,
		  const char *__log, size_t log_size);

const char *hmlog_name_of_level(unsigned int level);
unsigned int hmlog_level_of_name(const char *name);

#ifndef log_fmt
#define log_fmt(fmt) fmt
#endif /* log_fmt */

static inline bool __hmlog_filter_by_freq(const int *freq)
{
	return (freq != NULL) && (*freq == DYNLOG_FREQ_ALWAYS);
}

#define __hm_dynlog(lv, space_str, fmt, args...) \
do { \
	static struct dynlog_elf_entry __attribute((section(DYNLOG_SECTION_NAME))) \
		__dynamic_log_elf_entry = dynlog_elf_entry_initializer(space_str, fmt); \
	if (__hmlog_filter_by_freq(&__dynamic_log_elf_entry.freq)) { \
		__hmlog_printf(lv, __FILE__, __func__, __LINE__, log_fmt(fmt), ##args); \
	} \
} while (__false)

#define __hmlog(lv, fmt, args...) \
	__hmlog_printf(lv, __FILE__, __func__, __LINE__, fmt, ##args)

#define __hmlogv(lv, fmt, va) \
	__hmlog_vprintf(lv, __FILE__, __func__, __LINE__, fmt, va)

#ifdef __hmfeature_debug__
#ifndef LOG_SPACE
#define LOG_SPACE "/"
#endif /* LOG_SPACE */
#define hm_debug(fmt, args...)	__hm_dynlog(HMLOG_DEBUG, LOG_SPACE, fmt, ##args)
#else
static inline void __attribute__((format(printf, 1, 2)))
__no_hmlog(const char *fmt, ...)
{
	(void)fmt;
}
#define hm_debug(fmt...)	__no_hmlog(fmt)
#endif /* __hmfeature_debug__ */

#define hm_info(fmt, ...)	__hmlog(HMLOG_INFO, log_fmt(fmt), ##__VA_ARGS__)
#define hm_warn(fmt, ...)	__hmlog(HMLOG_WARN, log_fmt(fmt), ##__VA_ARGS__)
#define hm_error(fmt, ...)	__hmlog(HMLOG_ERROR, log_fmt(fmt), ##__VA_ARGS__)
#define hm_panic(fmt, ...)	\
	do {	\
		__hmlog(HMLOG_PANIC, log_fmt(fmt), ##__VA_ARGS__);	\
		__panic_impl(__FILE__, __FUNCTION__, __LINE__);	\
	} while (__false)

#define __hmlogv_panic(fmt, va) __hmlog_vprintf(HMLOG_PANIC, __FUNCTION__, __LINE__, fmt, va)

#endif /* ULIBS_INCLUDE_LIBHMLOG_HMLOG_H */
