/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Define lock owner data struct
 * Author: Huawei OS Kernel Lab
 * Create: Wed Jun 10 15:42:44 2020
 */

#ifndef ULIBS_INCLUDE_LIBLOCKTRACE_LOCKOWNER_H
#define ULIBS_INCLUDE_LIBLOCKTRACE_LOCKOWNER_H

struct lock_owner_s {
	union {
		unsigned long id; /* lock owner id */
		unsigned long long align_id; /* ensure align in 32 and 64 data model */
	};
	union {
		const void *pc; /* pc of lock the lock */
		unsigned long long align_pc; /* ensure align in 32 and 64 data model */
	};
};

#endif
