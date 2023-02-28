/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: Log information denied by security framework
 * Author: Huawei OS Kernel Lab
 * Create: Thu Apr 23 23:20:59 2020
 */
#ifndef ULIBS_LIBSEC_LOG_H
#define ULIBS_LIBSEC_LOG_H
#include <stdarg.h>
#include <stdint.h>

struct sec_chk_cred;
void sec_chk_show_obj_name(const struct sec_chk_cred *cred, const void *obj);
typedef int (*sec_deny_log_hook_func_t)(uint32_t audit_type, uint32_t flag, const char *fmt, va_list args);

#ifdef CONFIG_AUDIT
void sec_set_deny_log_hook(const sec_deny_log_hook_func_t func);
void sec_deny_log_hook(const char *fmt, ...);
#else
static inline void sec_set_deny_log_hook(const sec_deny_log_hook_func_t func)
{
	(void)func;
	return;
}

static inline void sec_deny_log_hook(const char *fmt, ...)
{
	(void)fmt;
	return;
}
#endif

#endif /* ifndef ULIBS_LIBSEC_LOG_H */
