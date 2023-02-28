/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Thread function declaration
 * Author: Huawei OS Kernel Lab
 * Create: Fri May 24 15:32:39 2019
 */
#ifndef ULIBS_INCLUDE_HM_THREAD_H
#define ULIBS_INCLUDE_HM_THREAD_H

#include <hmkernel/capability.h>
#include <hmkernel/tcb.h>
#include <stdint.h>
#include <stdbool.h>

void hm_thread_exit(int exitcode);
void hm_thread_reset_tid_cache(void);
int hm_thread_setname(cref_t thread_cref, const char *new_name, char *old_name);
int hm_thread_set_pdeath_signal(int signum);
int hm_thread_get_pdeath_signal(int *signum);
cref_t hm_thread_self_cref(void);
cref_t hm_thread_tid2cref(int tid);
cref_t hm_thread_vspace_cref(cref_t thread_cref);
int hm_thread_gettid(void);
int hm_thread_stat(cref_t tcb_cref, struct sysarg_thread_stat *stat, unsigned long flag);
int hm_thread_set_runqueue(int tid, unsigned int newrq);
int hm_thread_set_tickless(int tid, bool tickless);
int hm_thread_yield(void);
int hm_thread_suspend(void);
int hm_thread_suspend_ex(cref_t cref);
int hm_thread_resume(cref_t cref);
int hm_thread_freeze(int tid, int flag);
int hm_thread_thaw(int tid);
int hm_thread_sched_setparam(int tid, int newprio);
int hm_thread_sched_getparam(int tid);
int hm_thread_sched_setscheduler(int tid, int prio, int policy);
int hm_thread_sched_getscheduler(int tid);
int hm_thread_sched_getdefaultscheduler(void);
int hm_thread_sched_getdefaultpriority(void);
int hm_setpersonality(unsigned long personality);
int hm_getpersonality(unsigned long *personality);
int hm_thread_get_seq(int tid, uint64_t *seq);
int hm_thread_setpriority(int tid, int nice);
int hm_thread_getpriority(int tid);
int hm_thread_sched_setaffinity(int tid, __cpuset_t cpuset);
int hm_thread_sched_getaffinity(int tid, __cpuset_t *cpuset);
int hm_thread_sched_getattr(void);
int hm_thread_sched_get_interval_rr(void);
int hm_thread_kvic_source_bind(cref_t tcb_cref, unsigned int source_id, unsigned int flags);
int hm_thread_kvic_source_unbind(cref_t tcb_cref, unsigned int source_id);
int hm_thread_kvic_kev_source_bind(cref_t tcb_cref, unsigned int source_id, unsigned int flags);
int hm_thread_kvic_kev_source_unbind(cref_t tcb_cref, unsigned int source_id);
int hm_thread_attach_cpu_context(cref_t thread, cref_t context,
				 enum __tcb_attach_type type);
int hm_thread_detach_cpu_context(cref_t thread, cref_t *pcontext,
				 enum __tcb_attach_type type);

#endif
