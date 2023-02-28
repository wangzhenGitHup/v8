/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Definitions about dumpstack shared for sysmgr and other uapp
 * Author: Huawei OS Kernel Lab
 * Create: Fri Nov 29 15:24:17 2019
 */
#ifndef SYSMGR_INCLUDE_AAPI_HMSYSMGR_DUMPSTACK_H
#define SYSMGR_INCLUDE_AAPI_HMSYSMGR_DUMPSTACK_H

enum {
	/* dump registers of the thread */
	DUMPSTACK_FLAGS_REGISTERS,
	/* dump registers of the fpsimd state */
	DUMPSTACK_FLAGS_FPSIMD_REGISTERS,
	/* dump function call stack with full symbol information */
	DUMPSTACK_FLAGS_STACK_BACKTRACE,
	/* dump function call stack without symbol information */
	DUMPSTACK_FLAGS_STACK_BACKTRACE_NOSYM,
	/* dump lock trace of thread */
	DUMPSTACK_FLAGS_LOCK_TRACE,
	/* dump load information of elf file in a process */
	DUMPSTACK_FLAGS_ELF_LOAD_INFO,
	/* dump the last 'bl' instruction */
	DUMPSTACK_FLAGS_LAST_BL_DATA,
	/* dump several data around the address in pc register */
	DUMPSTACK_FLAGS_DATA_AROUND_PC,
	/* dump contents of stack memory */
	DUMPSTACK_FLAGS_STACK_CONTENTS,
	DUMPSTACK_FLAGS_MAX,
};

#define dumpstack_flag_mask_of(f)	(((f) == 0) ? (1U) : (1U << ((unsigned int)(f))))
#define dumpstack_is_flag_set(x, f)	(((x) & dumpstack_flag_mask_of(f)) != 0U)
#define dumpstack_set_flag(x, f)	((x) |= dumpstack_flag_mask_of(f))
#define dumpstack_clear_flag(x, f)	((x) &= ~dumpstack_flag_mask_of(f))

#endif
