/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Hmvsyscall
 * Author: Huawei OS Kernel Lab
 * Create: Thu Sep 6 14:33:05 2018
 */
#ifndef HMVSYSCALL_H
#define HMVSYSCALL_H

#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>

#ifndef CONFIG_DOPRA_TICK
#define MAX_SYS_NO 414L
#else
#define MAX_SYS_NO 501L
#endif

typedef long (*hmsyscall_t)(va_list);

long hm_vsyscall(long num, ...);
int hm_install_syscall(long no, hmsyscall_t syscall);

#ifdef CONFIG_RRU_PERF_HACK
/*
 * VFS_FDTABLESIZE is 512. When opening /proc/%u/task/%u/status,
 * return an invalid fd to hack.
 */
extern pid_t hmhack_procfs_task_status_pid;
extern unsigned int hmhack_procfs_task_status_tid;
/*
 * state: 0 -- open --> 1 -- read --> 2 -- close --> 0
 */
extern unsigned int hmhack_procfs_task_status_state;
#define __HMHACK_PROCFS_TASK_STATUS_FD	1024

#define __HMHACK_PROC_TASK_STATUS_STATE_ACTIVE		1
#define __HMHACK_PROC_TASK_STATUS_STATE_ZOMBIE		2
#define __HMHACK_PROC_TASK_STATUS_STATE_SLEEPING	3
#define __HMHACK_PROC_TASK_STATUS_STATE_STOPPED		4
#define __HMHACK_PROC_TASK_STATUS_STATE_DEAD		5

#define HMKACK_PROCFS_FILE_CLOSED	0
#define HMKACK_PROCFS_FILE_OPENED	1
#define HMKACK_PROCFS_FILE_READ		2

extern unsigned int hmhack_procfs_uptime_state;
#define __HMHACK_PROCFS_UPTIME_FD	1025
#endif

#endif
