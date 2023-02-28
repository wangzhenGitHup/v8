/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: performance monitor unit
 * Author: Huawei OS Kernel Lab
 * Create: Wed Aug 19 19:53:03 CST 2021
 */
#ifndef KLIBS_PERFRA_PMU_AARCH64_H
#define KLIBS_PERFRA_PMU_AARCH64_H

#include <asm/types.h>
#include <asm/sysreg_utils.h>

#ifdef __aarch64__

#define _aarch64_define_pmuv3reg_ro(name, el)		\
__AARCH64_DEFINE_sysreg_rd(__pmu_aarch64_sysreg_read, name, el)	\
__AARCH64_DEFINE_sysreg_rd32(__pmu_aarch64_sysreg_read32, name, el) \
static inline __u64 __pmu_aarch64_##name##_read(void)		\
{								\
	return __pmu_aarch64_sysreg_read_##name##_##el();	\
}								\
static inline __u32 __pmu_aarch64_##name##_read32(void)		\
{								\
	return __pmu_aarch64_sysreg_read32_##name##_##el();	\
}

#define _aarch64_define_pmuv3reg_wo(name, el)		\
__AARCH64_DEFINE_sysreg_wr(__pmu_aarch64_sysreg_write, name, el) \
__AARCH64_DEFINE_sysreg_wr32(__pmu_aarch64_sysreg_write32, name, el) \
static inline void __pmu_aarch64_##name##_write(__u64 v)	\
{								\
	__pmu_aarch64_sysreg_write_##name##_##el(v);		\
}								\
static inline void __pmu_aarch64_##name##_write32(__u32 v)	\
{								\
	__pmu_aarch64_sysreg_write32_##name##_##el(v);		\
}

#define _aarch64_define_pmuv3reg(name, el)			\
	_aarch64_define_pmuv3reg_ro(name, el)		\
	_aarch64_define_pmuv3reg_wo(name, el)

_aarch64_define_pmuv3reg(pmcntenset, el0)
_aarch64_define_pmuv3reg(pmcntenclr, el0)
_aarch64_define_pmuv3reg(pmovsclr, el0)
_aarch64_define_pmuv3reg(pmovsset, el0)
_aarch64_define_pmuv3reg(pmintenclr, el1)
_aarch64_define_pmuv3reg(pmintenset, el1)
_aarch64_define_pmuv3reg(pmuserenr, el0)
_aarch64_define_pmuv3reg(pmcr, el0)
_aarch64_define_pmuv3reg_wo(pmswinc, el0)

_aarch64_define_pmuv3reg(pmselr, el0)
_aarch64_define_pmuv3reg(pmxevcntr, el0)
_aarch64_define_pmuv3reg(pmxevtyper, el0)

_aarch64_define_pmuv3reg(pmccntr, el0)
_aarch64_define_pmuv3reg(pmccfiltr, el0)

_aarch64_define_pmuv3reg(pmevcntr0, el0)
_aarch64_define_pmuv3reg(pmevcntr1, el0)
_aarch64_define_pmuv3reg(pmevcntr2, el0)
_aarch64_define_pmuv3reg(pmevcntr3, el0)
_aarch64_define_pmuv3reg(pmevcntr4, el0)
_aarch64_define_pmuv3reg(pmevcntr5, el0)
_aarch64_define_pmuv3reg(pmevcntr6, el0)
_aarch64_define_pmuv3reg(pmevcntr7, el0)
_aarch64_define_pmuv3reg(pmevcntr8, el0)
_aarch64_define_pmuv3reg(pmevcntr9, el0)
_aarch64_define_pmuv3reg(pmevcntr10, el0)
_aarch64_define_pmuv3reg(pmevcntr11, el0)
_aarch64_define_pmuv3reg(pmevcntr12, el0)
_aarch64_define_pmuv3reg(pmevcntr13, el0)
_aarch64_define_pmuv3reg(pmevcntr14, el0)
_aarch64_define_pmuv3reg(pmevcntr15, el0)
_aarch64_define_pmuv3reg(pmevcntr16, el0)
_aarch64_define_pmuv3reg(pmevcntr17, el0)
_aarch64_define_pmuv3reg(pmevcntr18, el0)
_aarch64_define_pmuv3reg(pmevcntr19, el0)
_aarch64_define_pmuv3reg(pmevcntr20, el0)
_aarch64_define_pmuv3reg(pmevcntr21, el0)
_aarch64_define_pmuv3reg(pmevcntr22, el0)
_aarch64_define_pmuv3reg(pmevcntr23, el0)
_aarch64_define_pmuv3reg(pmevcntr24, el0)
_aarch64_define_pmuv3reg(pmevcntr25, el0)
_aarch64_define_pmuv3reg(pmevcntr26, el0)
_aarch64_define_pmuv3reg(pmevcntr27, el0)
_aarch64_define_pmuv3reg(pmevcntr28, el0)
_aarch64_define_pmuv3reg(pmevcntr29, el0)
_aarch64_define_pmuv3reg(pmevcntr30, el0)

_aarch64_define_pmuv3reg(pmevtyper0, el0)
_aarch64_define_pmuv3reg(pmevtyper1, el0)
_aarch64_define_pmuv3reg(pmevtyper2, el0)
_aarch64_define_pmuv3reg(pmevtyper3, el0)
_aarch64_define_pmuv3reg(pmevtyper4, el0)
_aarch64_define_pmuv3reg(pmevtyper5, el0)
_aarch64_define_pmuv3reg(pmevtyper6, el0)
_aarch64_define_pmuv3reg(pmevtyper7, el0)
_aarch64_define_pmuv3reg(pmevtyper8, el0)
_aarch64_define_pmuv3reg(pmevtyper9, el0)
_aarch64_define_pmuv3reg(pmevtyper10, el0)
_aarch64_define_pmuv3reg(pmevtyper11, el0)
_aarch64_define_pmuv3reg(pmevtyper12, el0)
_aarch64_define_pmuv3reg(pmevtyper13, el0)
_aarch64_define_pmuv3reg(pmevtyper14, el0)
_aarch64_define_pmuv3reg(pmevtyper15, el0)
_aarch64_define_pmuv3reg(pmevtyper16, el0)
_aarch64_define_pmuv3reg(pmevtyper17, el0)
_aarch64_define_pmuv3reg(pmevtyper18, el0)
_aarch64_define_pmuv3reg(pmevtyper19, el0)
_aarch64_define_pmuv3reg(pmevtyper20, el0)
_aarch64_define_pmuv3reg(pmevtyper21, el0)
_aarch64_define_pmuv3reg(pmevtyper22, el0)
_aarch64_define_pmuv3reg(pmevtyper23, el0)
_aarch64_define_pmuv3reg(pmevtyper24, el0)
_aarch64_define_pmuv3reg(pmevtyper25, el0)
_aarch64_define_pmuv3reg(pmevtyper26, el0)
_aarch64_define_pmuv3reg(pmevtyper27, el0)
_aarch64_define_pmuv3reg(pmevtyper28, el0)
_aarch64_define_pmuv3reg(pmevtyper29, el0)
_aarch64_define_pmuv3reg(pmevtyper30, el0)

static inline __u64 __pmu_pmccntr_read()
{
	return __pmu_aarch64_pmccntr_read();
}
static inline void __pmu_pmccntr_write(__u64 v)
{
	__pmu_aarch64_pmccntr_write(v);
}

static inline __u32 __pmu_pmccntr_read32()
{
	return __pmu_aarch64_pmccntr_read32();
}
static inline void __pmu_pmccntr_write32(__u32 v)
{
	__pmu_aarch64_pmccntr_write32(v);
}

#endif

#endif
