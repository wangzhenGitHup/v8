/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Definitions related to klogctl
 * Author: Huawei OS Kernel Lab
 * Create: Fri Feb 14 21:59:54 2020
 */
#ifndef ULIBS_LIBHMLOG_KLOGCTL_H
#define ULIBS_LIBHMLOG_KLOGCTL_H

/* compatible with action type defined in syslog(2) */
enum klogctl_type {
	KLOGCTL_CLOSE			= 0, /* close the log */
	KLOGCTL_OPEN			= 1, /* open the log */
	KLOGCTL_WAIT_AND_READ		= 2, /* wait until kernel log buffer is nonempty then read */
	KLOGCTL_READ_ALL		= 3, /* read all kernel log in buffer */
	KLOGCTL_READ_AND_CLEAR		= 4, /* read all kernel log in buffer and clear them */
	KLOGCTL_CLEAR			= 5, /* clear kernel log in buffer */
	KLOGCTL_CONSOLE_OFF		= 6, /* disable klog to console */
	KLOGCTL_CONSOLE_ON		= 7, /* enable klog to console */
	KLOGCTL_SET_CONSOLE_LEVEL	= 8, /* set level of klog printed to console */
	KLOGCTL_GET_UNREAD_SIZE		= 9, /* bytes of logs currently available to be read in kernel buffer */
	KLOGCTL_GET_BUFFER_SIZE		= 10, /* get kernel buffer size */
	KLOGCTL_TYPE_MAX,
};

/*
 * klog that starts with this prefix indicate that logs older than this one
 * would not be printed.
 */
#define KLOG_CLEAR_LABEL_PREFIX		"[klog] kernel logs cleared"
#define KLOG_CLEAR_LABEL_FMT		KLOG_CLEAR_LABEL_PREFIX " (%x)\n"
#define KLOG_LOST_LABEL			"[klog data lost]"
#define KLOG_INVALID_LABEL		"[invalid klog]"

#ifdef __HOST_LLT__
#define LLT_KLOGCTL_BUF_SIZE    (3U * 1024U * 1024U)

extern struct kev_config llt_klogctl_config;
extern char llt_klogctl_raw_data[LLT_KLOGCTL_BUF_SIZE];
extern size_t llt_klogctl_raw_data_size;
extern int llt_klogctl_event_conf_ret;
extern int llt_klogctl_syslog_ret;
extern int llt_klogctl_read_head_ret;
#endif

#endif /* ULIBS_LIBHMLOG_KLOGCTL_H */
