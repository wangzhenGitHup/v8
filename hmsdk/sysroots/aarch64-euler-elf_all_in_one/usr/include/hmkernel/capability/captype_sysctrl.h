/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Definition of sysctrl capability
 * Author: Huawei OS Kernel Lab
 * Create: Tue Oct 16 01:55:19 2018
 */
/*
 * Must choose one GRANT type from ALL/NO/COARSE/FINE
 * Must choose one GRANTMOVE type from ALL/NO/COARSE
 */
CAPTYPE(SysCtrl, 8, CAPALLGRANT(SysCtrl)
		    CAPNOGRANTMOVE(SysCtrl)
		    CAPNODEFAULTCREF(SysCtrl)
		    CAPRAWCREFRLOOKUP(SysCtrl)
		    CAPDEFAULTSIZE(SysCtrl),
	CAPMETHOD(SysCtrl, PowerOff)
	CAPMETHOD(SysCtrl, Reboot)
	CAPMETHOD(SysCtrl, StopMachine)
	CAPMETHOD(SysCtrl, ResumeMachine)
	CAPMETHOD(SysCtrl, CpuUp)
	CAPMETHOD(SysCtrl, CpuOff)
	CAPMETHOD(SysCtrl, CpuAffinity)
	CAPMETHOD(SysCtrl, PmSuspend)
	CAPMETHOD(SysCtrl, PmCpuDown)
	CAPMETHOD(SysCtrl, LoadDTB)
	CAPMETHOD(SysCtrl, ReadDTB)
	CAPMETHOD(SysCtrl, ReadConf)
	CAPMETHOD(SysCtrl, GetTRNG)
	CAPMETHOD(SysCtrl, Debug)
	CAPMETHOD(SysCtrl, GetCpuStat)
	CAPMETHOD(SysCtrl, SetTockReal)
	CAPMETHOD(SysCtrl, SetTockPolicy)
	CAPMETHOD(SysCtrl, SetKlogportLevel)
	CAPMETHOD(SysCtrl, KevSetEnable)
	CAPMETHOD(SysCtrl, KevSetFilter)
	CAPMETHOD(SysCtrl, KevSetWater)
	CAPMETHOD(SysCtrl, KevSetBlockInfo)
	CAPMETHOD(SysCtrl, KevReadData)
	CAPMETHOD(SysCtrl, KevReadEventNumber)
	CAPMETHOD(SysCtrl, KevReadEventConfig)
	CAPMETHOD(SysCtrl, RespartCtrl)
	CAPMETHOD(SysCtrl, KShare)
	CAPMETHOD(SysCtrl, KUnShare)
	CAPMETHOD(SysCtrl, GetRootfsInfo)
	CAPMETHOD(SysCtrl, InjectRasError)
	CAPMETHOD(SysCtrl, ScanMemRange)
	CAPMETHOD(SysCtrl, UpdateRsvMemRange)
	)

#ifdef CAP_EXPORT_API

#include <hmkernel/klogport_type_flag.h>
#include <hmkernel/klog_level.h>
#include <hmkernel/events/kev_part.h>
#include <hmkernel/drivers/respart.h>

enum {
	CRIGHT_SYSCTRL_CPUCTRL_BIT,
	CRIGHT_SYSCTRL_SYSREAD_BIT,
	CRIGHT_SYSCTRL_DEBUG_BIT,
	CRIGHT_SYSCTRL_SETTIME_BIT,
	CRIGHT_SYSCTRL_KLOGPORT_BIT,
	CRIGHT_SYSCTRL_KEVCTRL_BIT,
	CRIGHT_SYSCTRL_RESPART_BIT,
	CRIGHT_SYSCTRL_SYSPROC_BIT,
	CRIGHT_SYSCTRL_MAX
};

#define CRIGHT_SYSCTRL_CPUCTRL	(1U << CRIGHT_SYSCTRL_CPUCTRL_BIT)
#define CRIGHT_SYSCTRL_SYSREAD	(1U << CRIGHT_SYSCTRL_SYSREAD_BIT) /* Read right for sensible data */
#define CRIGHT_SYSCTRL_DEBUG	(1U << CRIGHT_SYSCTRL_DEBUG_BIT) /* Debug functions */
#define CRIGHT_SYSCTRL_SETTIME	(1U << CRIGHT_SYSCTRL_SETTIME_BIT) /* Set time */
#define CRIGHT_SYSCTRL_KLOGPORT	(1U << CRIGHT_SYSCTRL_KLOGPORT_BIT) /* Set klogport level */
#define CRIGHT_SYSCTRL_KEVCTRL	(1U << CRIGHT_SYSCTRL_KEVCTRL_BIT) /* Kev ctrl */
#define CRIGHT_SYSCTRL_RESPART	(1U << CRIGHT_SYSCTRL_RESPART_BIT) /* resource partition ctrl */
#define CRIGHT_SYSCTRL_SYSPROC	(1U << CRIGHT_SYSCTRL_SYSPROC_BIT) /* functions only can be called by sysproc */

#define SYSCTRL_DTB_PATH_SIZE	512U

enum __sysctrl_kshare_type {
	__SYSCTRL_KSHARE_UDATA,
	__SYSCTRL_KSHARE_COPAGE,
	__SYSCTRL_NR_KSHARE,
};

struct __sysctrl_cpu_stat  {
	__u64 run_time;
	__u64 idle_time;
	__u64 nr_interrupt;
	__u64 nr_ctx_switch;
	__u64 sys_time;
	__u64 irq_time;
};

struct __sysctrl_rootfs_va_size  {
	__u64 va;
	__u64 size;
};

struct __sysctrl_kev_config {
	char event_name[KEV_EVENT_NAME_SIZE];
	__u32 config;
	__u32 enable;
	__u64 paddr;
	__u32 size;
};

#endif
