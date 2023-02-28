/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Hguard notify interface
 * Author: Huawei OS Kernel Lab
 * Create: Fri Feb 28 10:12:20 2020
 */
#ifndef ULIBS_LIBHGUARD_HGUARD_H
#define ULIBS_LIBHGUARD_HGUARD_H

/*
 * NOTIFY_HEARTBEAT is the only accepted notify type,
 * for compatibility reason, a macro is kept in this file
 */
#define NOTIFY_HEARTBEAT 0U
int hguard_notify(unsigned int type);

#endif
