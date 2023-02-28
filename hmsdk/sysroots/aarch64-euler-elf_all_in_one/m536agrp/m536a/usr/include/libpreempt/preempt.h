/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Preempt interface
 * Author: Huawei OS Kernel Lab
 * Create: Thu Aug 13 15:16:15 2020
 */
#ifndef ULIBS_LIBPREEMPT_PREEMPT_H
#define ULIBS_LIBPREEMPT_PREEMPT_H

#include <stdbool.h>

void preempt_enable(void);
void preempt_disable(void);
void preempt_disable_passive(void);
int preempt_process_enable(void);
int preempt_process_disable(void);
int preempt_process_register(void);
int preempt_process_unregister(void);
void preempt_process_reset(void);
int preempt_process_cpu_get(void);
bool preempt_process_feature_enabled(void);

int preempt_process_set_slv(unsigned int cpu, unsigned int slv);
int preempt_thread_set_slv(int tid, unsigned int slv);

#endif
