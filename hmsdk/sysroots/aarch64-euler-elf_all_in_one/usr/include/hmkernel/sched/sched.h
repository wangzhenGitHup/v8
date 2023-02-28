/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Definition of sched proto for uapi
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jul 02 20:41:17 2020
 */
#ifndef UAPI_SCHED_H
#define UAPI_SCHED_H

#define SCHED_OTHER	0
#define SCHED_FIFO	1
#define SCHED_RR	2
#define SCHED_BATCH	3
#define SCHED_IDLE	5
#define SCHED_EDF	6
#define SCHED_NULL	7

#define SCHED_RESET_ON_FORK	0x40000000
#endif
