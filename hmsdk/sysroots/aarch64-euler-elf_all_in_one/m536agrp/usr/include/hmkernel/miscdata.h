/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Miscdata
 * Author: Huawei OS Kernel Lab
 * Create: Wed Mar 04 19:26:00 2020
 */
#ifndef MAPI_UAPI_MISCDATA_H
#define MAPI_UAPI_MISCDATA_H

/*
 * This header defines user available misc data.
 * Values are part of ABI and should be fixed.
 * internal u_to_k are required to convert misc data
 * to array index.
 */

/*
 * Misc data in actvconf (thread and actvpool).
 * All undefined
 */
#define __MISCDATA_ACTVCONF_SIGHDLR_PC	1
#define __MISCDATA_ACTVCONF_SIGHDLR_SP	2
#define __MISCDATA_ACTVCONF_UNUSED3	3
#define __MISCDATA_ACTVCONF_UNUSED4	4
#define __MISCDATA_ACTVCONF_UNUSED5	5

/*
 * Misc data in activation. All undefined
 */
#define __MISCDATA_ACTV_SIGPROC_STATE	9
#define __MISCDATA_ACTV_SIGRET_PC	10
#define __MISCDATA_ACTV_SIGRET_SP	11
#define __MISCDATA_ACTV_SIGINFO_R0	12
#define __MISCDATA_ACTV_SIGINFO_R1	13
#define __MISCDATA_ACTV_SIGINFO_R2	14
#define __MISCDATA_ACTV_SIGINFO_R3	15
#define __MISCDATA_ACTV_SIGINFO_R4	16
#define __MISCDATA_ACTV_SIGINFO_R5	17
#define __MISCDATA_ACTV_SIGINFO_R6	18
#define __MISCDATA_ACTV_SIGINFO_R7	19

/*
 * Misc data in tcb. All undefined
 */
#define __MISCDATA_TCB_UNUSED1		20
#define __MISCDATA_TCB_UNUSED2		21
#define __MISCDATA_TCB_UNUSED3		22
#define __MISCDATA_TCB_UNUSED4		23
#define __MISCDATA_TCB_UNUSED5		24
#define __MISCDATA_TCB_UNUSED6		25
#define __MISCDATA_TCB_UNUSED7		26
#define __MISCDATA_TCB_UNUSED8		27
#define __MISCDATA_TCB_UNUSED9		28
#define __MISCDATA_TCB_UNUSED10		29
#define __MISCDATA_TCB_UNUSED11		30
#define __MISCDATA_TCB_UNUSED12		31
#define __MISCDATA_TCB_UNUSED13		32
#define __MISCDATA_TCB_UNUSED14		33
#define __MISCDATA_TCB_UNUSED15		34
#define __MISCDATA_TCB_ID		35

/*
 * Access (read or write) misc data from where?
 */
#define __MISCACCESS_SELF		1
#define __MISCACCESS_CALLER		2
#define __MISCACCESS_CALLER_G1		3
#define __MISCACCESS_CALLER_L1		4
#define __MISCACCESS_CALLER_G1L1	5
#define __MISCACCESS_XACT		6
#define __MISCACCESS_THREAD		7

#define __MISCACCESS_TRAPSOURCE	__MISCACCESS_CALLER_G1
#define __MISCACCESS_MGR	__MISCACCESS_CALLER_G1
#define __MISCACCESS_BASECALL	__MISCACCESS_CALLER_L1
#define __MISCACCESS_BASEMGR	__MISCACCESS_CALLER_G1L1

#endif
