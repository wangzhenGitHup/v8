/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Seqlock
 * Author: Huawei OS Kernel Lab
 * Create: Mon Dec 9 09:49:33 2019
 */
#ifndef UAPI_HMKERNEL_SEQLOCK_H
#define UAPI_HMKERNEL_SEQLOCK_H
#include <hmkernel/barrier.h>
#include <hmkernel/compiler.h>
#include <hmkernel/types.h>
#include <asm/processor.h>
#include <asm/types.h>

struct __seqcnt_s {
	__u32 __sequence;
};

static inline void __seqcnt_init(struct __seqcnt_s *sc)
{
	sc->__sequence = 0;
}

static inline __u32 ____seqcnt_start_read(const struct __seqcnt_s *sc)
{
	__u32 seq;
	do {
		seq = __read_once(sc->__sequence);
		if ((seq & 1U) == 0U) {
			break;
		}
		cpu_relax();
	} while (__true);
	return seq;
}

static inline __u32 __seqcnt_start_read(const struct __seqcnt_s *sc)
{
	__u32 seq;

	seq = ____seqcnt_start_read(sc);
	__smp_rmb();
	return seq;
}

static inline __s32 __seqcnt_retry_read(const struct __seqcnt_s *sc, __u32 seq)
{
	__smp_rmb();
	return __unlikely(sc->__sequence != seq);
}

static inline void __seqcnt_begin_write(struct __seqcnt_s *sc)
{
	sc->__sequence++;
	__smp_wmb();
}

static inline void __seqcnt_end_write(struct __seqcnt_s *sc)
{
	__smp_wmb();
	sc->__sequence++;
}
#endif
