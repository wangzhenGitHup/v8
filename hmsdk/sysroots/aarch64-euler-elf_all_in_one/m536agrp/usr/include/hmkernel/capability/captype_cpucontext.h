/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Captype definition for CpuContext
 * Author: Huawei OS Kernel Lab
 * Create: Thu Dec 13 12:47:00 2018
 */
/*
 * Must choose one GRANT type from ALL/NO/COARSE/FINE
 * Must choose one GRANTMOVE type from ALL/NO/COARSE
 */
CAPTYPE(CpuContext, 10, CAPNOGRANT(CpuContext)
			CAPNOGRANTMOVE(CpuContext)
			CAPNODEFAULTCREF(CpuContext)
			CAPRAWCREFRLOOKUP(CpuContext),
	CAPMETHOD(CpuContext, Config)
	CAPMETHOD(CpuContext, AttachCPU)
	CAPMETHOD(CpuContext, DetachCPU)
	)

#ifdef CAP_EXPORT_API
#ifndef CAP_CPUCONTEXT_API_EXPORTED
#define CAP_CPUCONTEXT_API_EXPORTED

enum {
	CRIGHT_CPUCONTEXT_ATTACH_CPU_BIT,
	CRIGHT_CPUCONTEXT_THREAD_ATTACH_BIT,
	CRIGHT_CPUCONTEXT_MAX
};

#define CRIGHT_CPUCONTEXT_ATTACH_CPU		(1U << CRIGHT_CPUCONTEXT_ATTACH_CPU_BIT)
#define CRIGHT_CPUCONTEXT_THREAD_ATTACH		(1U << CRIGHT_CPUCONTEXT_THREAD_ATTACH_BIT)

/* sizeof(struct arm_pmu_perf_ctx_s) is 816 in kernel */
#define CPUCONTEXT_ARM_PMU_STRUCT_SIZE		900UL
#define CPUCONTEXT_ARM_DEBUG_STRUCT_SIZE	600UL
#ifdef CONFIG_MMIO_DISPATCHER
#define CPUCONTEXT_ARM_VCPU_STRUCT_SIZE		3000UL
#else
#define CPUCONTEXT_ARM_VCPU_STRUCT_SIZE		2500UL
#endif
#define CPUCONTEXT_FPU_STRUCT_SIZE		1024UL

#endif
#endif
