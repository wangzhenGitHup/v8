/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Prototypes for devhost security APIs
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jan 11 10:45:12 2019
 */
#ifndef __DEVHOST_API_SECURITY_H__
#define __DEVHOST_API_SECURITY_H__

/*
 * CAUSION: This file will be used in linux source,
 *          **DO NOT** include any HMOS headers.
 */

/* for `current` */
int devhost_current_pid(void);
int devhost_current_pgid(void);

/* for procmgr */
int devhost_mysid(void);
int devhost_getsid(int pid);
int devhost_getpgid(int pid);
int devhost_getfgpgrp(int sid);
int devhost_setfgpgrp(int sid, int pgrp);

/* for caller security check */
int devhost_caller_has_ability(int ability);
int devhost_caller_has_capability(unsigned int capability);
int devhost_caller_has_ab_and_cap(int ability, unsigned int capability);

#endif /* __DEVHOST_API_SECURITY_H__ */
