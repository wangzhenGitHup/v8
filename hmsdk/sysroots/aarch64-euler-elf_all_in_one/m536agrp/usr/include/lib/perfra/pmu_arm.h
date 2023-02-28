/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: performance monitor unit
 * Author: Huawei OS Kernel Lab
 * Create: Wed Aug 19 19:53:03 CST 2021
 */
#ifndef KLIBS_PERFRA_PMU_ARM_H
#define KLIBS_PERFRA_PMU_ARM_H

#include <asm/types.h>
#include <asm/sysreg_utils.h>

#ifdef __arm__

#define __pmu_arm_define_pmuv1reg_ro(name, code)		\
__ARM_DEFINE_sysreg_rd(__pmu_arm_sysreg_read, name, p15, code)	\
static inline __u32 __pmu_arm_##name##_read(void)		\
{								\
	return __pmu_arm_sysreg_read_##name();			\
}

#define __pmu_arm_define_pmuv1reg_wo(name, code)		\
__ARM_DEFINE_sysreg_wr(__pmu_arm_sysreg_write, name, p15, code)	\
static inline void __pmu_arm_##name##_write(__u32 v)		\
{								\
	__pmu_arm_sysreg_write_##name(v);			\
}

#define __pmu_arm_define_pmuv1reg(name, code)			\
	__pmu_arm_define_pmuv1reg_ro(name, code)		\
	__pmu_arm_define_pmuv1reg_wo(name, code)

__pmu_arm_define_pmuv1reg(pmcr,  "0, %0, c9, c12, 0")
__pmu_arm_define_pmuv1reg(pmcntenset,  "0, %0, c9, c12, 1")
__pmu_arm_define_pmuv1reg(pmcntenclr,  "0, %0, c9, c12, 2")

__pmu_arm_define_pmuv1reg(pmovsclr,  "0, %0, c9, c12, 3")
__pmu_arm_define_pmuv1reg(pmselr,  "0, %0, c9, c12, 5")
__pmu_arm_define_pmuv1reg(pmxevtyper,  "0, %0, c9, c13, 1")
__pmu_arm_define_pmuv1reg(pmxevcntr,  "0, %0, c9, c13, 2")
__pmu_arm_define_pmuv1reg(pmuserenr,  "0, %0, c9, c14, 0")
__pmu_arm_define_pmuv1reg(pmintenset,  "0, %0, c9, c14, 1")
__pmu_arm_define_pmuv1reg(pmintenclr,  "0, %0, c9, c14, 2")
__pmu_arm_define_pmuv1reg(pmovsset,  "0, %0, c9, c14, 3")
__pmu_arm_define_pmuv1reg_wo(pmswinc,  "0, %0, c9, c12, 4")

__pmu_arm_define_pmuv1reg(pmccntr,  "0, %0, c9, c13, 0")

__pmu_arm_define_pmuv1reg_ro(pmceid0,  "0, %0, c9, c12, 6")
__pmu_arm_define_pmuv1reg_ro(pmceid1,  "0, %0, c9, c12, 7")

static inline __u64 __pmu_pmccntr_read()
{
	return __pmu_arm_pmccntr_read();
}
static inline void __pmu_pmccntr_write(__u64 v)
{
	__pmu_arm_pmccntr_write(v);
}

static inline __u32 __pmu_pmccntr_read32()
{
	return __pmu_arm_pmccntr_read();
}
static inline void __pmu_pmccntr_write32(__u32 v)
{
	__pmu_arm_pmccntr_write(v);
}

#endif

#endif
