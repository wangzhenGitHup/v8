/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: armv7 pmuv1 event number for perf
 * Author: Huawei OS Kernel Lab
 * Create: Mon May 25 17:05:22 2020
 */
#ifndef ARM_PMU_V1_H
#define ARM_PMU_V1_H

enum armv7_pmuv1_perf_types {
	/* Common ARMV7 event types */
	PMUV1_PERFCTR_PMNC_SW_INCR		= 0x00,
	PMUV1_PERFCTR_L1_ICACHE_REFILL		= 0x01,
	PMUV1_PERFCTR_ITLB_REFILL		= 0x02,
	PMUV1_PERFCTR_L1_DCACHE_REFILL		= 0x03,
	PMUV1_PERFCTR_L1_DCACHE_ACCESS		= 0x04,
	PMUV1_PERFCTR_DTLB_REFILL		= 0x05,
	PMUV1_PERFCTR_MEM_READ			= 0x06,
	PMUV1_PERFCTR_MEM_WRITE			= 0x07,
	/*
	 * this event is not implemented in arm cortex-a9.
	 * However,similar functionality is provided by event number 0x68,Instructions
	 * comming out of the core renaming stage.
	 * For more information,please see the arm cortex-a9 trm documentation.
	 * */
	PMUV1_PERFCTR_INSTR_EXECUTED		= 0x08,
	PMUV1_PERFCTR_EXC_TAKEN			= 0x09,
	PMUV1_PERFCTR_EXC_EXECUTED		= 0x0A,
	PMUV1_PERFCTR_CID_WRITE			= 0x0B,
	/*
	 * ARMV7_PERFCTR_PC_WRITE is equivalent to HW_BRANCH_INSTRUCTIONS.
	 * It counts:
	 *  - all (taken) branch instructions,
	 *  - instructions that explicitly write the PC,
	 *  - exception generating instructions.
	 */
	PMUV1_PERFCTR_PC_WRITE			= 0x0C,
	PMUV1_PERFCTR_PC_IMM_BRANCH		= 0x0D,
	PMUV1_PERFCTR_PC_PROC_RETURN		= 0x0E,
	PMUV1_PERFCTR_MEM_UNALIGNED_ACCESS	= 0x0F,
	PMUV1_PERFCTR_PC_BRANCH_MIS_PRED	= 0x10,
	PMUV1_PERFCTR_CLOCK_CYCLES		= 0x11,
	PMUV1_PERFCTR_PC_BRANCH_PRED		= 0x12,

	/* PMUV1 supplement events. */
	PMUV1_PERFCTR_MEM_ACCESS		= 0x13,
	PMUV1_PERFCTR_L1_ICACHE_ACCESS		= 0x14,
	PMUV1_PERFCTR_L1_DCACHE_WB		= 0x15,
	PMUV1_PERFCTR_L2_CACHE_ACCESS		= 0x16,
	PMUV1_PERFCTR_L2_CACHE_REFILL		= 0x17,
	PMUV1_PERFCTR_L2_CACHE_WB		= 0x18,
	PMUV1_PERFCTR_BUS_ACCESS		= 0x19,
	PMUV1_PERFCTR_MEM_ERROR			= 0x1A,
	PMUV1_PERFCTR_INSTR_SPEC		= 0x1B,
	PMUV1_PERFCTR_TTBR_WRITE		= 0x1C,
	PMUV1_PERFCTR_BUS_CYCLES		= 0x1D,
	PMUV1_PERFCTR_CPU_CYCLES		= 0xFF,

	/* ARMv7 Cortex-A9 specific event types */
	PMUV1_A9_PERFCTR_INSTR_CORE_RENAME	= 0x68,
	PMUV1_A9_PERFCTR_STALL_ICACHE		= 0x60,
	PMUV1_A9_PERFCTR_STALL_DISPATCH		= 0x66,
};

#endif
