/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Kev
 * Author: Huawei OS Kernel Lab
 * Create: Mon Apr 22 10:25:38 2019
 */
#ifndef UAPI_HMKERNEL_KEV_H
#define UAPI_HMKERNEL_KEV_H

#include <hmkernel/mm/udata.h>
#include <hmkernel/events/kev_part.h>

/* remove this when vsync atomic is ready */
#include <vsync/atomic.h>

struct kev_notify_event_s {
	__u64 water;
	__u64 threshold;
};

/*
 * first: sequence number and index of the first valid klog stored in the rb
 * next:  sequence number and index of the next klog to write to the rb
 *        next_idx is the write_head indeed
 * clear: sequence number and index of the next klog to read after the last `clear` command
 */
struct ring_buffer_s {
	atomic64_t write_head;
	__u64 read_head;
	atomic_t readable;
	__u32 mode;
	struct kev_notify_event_s notify_event;
	__u64 size;
	atomic64_t first_seq;
	atomic64_t next_seq;
	atomic64_t clear_seq;
	atomic_t first_idx;
	atomic_t next_idx;
	atomic_t clear_idx;
	unsigned char data[0] __aligned(sizeof(__u64));
} __attribute__((packed));

enum kev_trap_el2_type {
	KEV_EL2_ENTER,
	KEV_EL2_EXIT
};

enum kev_el2_irq_type {
	KEV_EL2_IRQ_ASSERT_EL1,
	KEV_EL2_IRQ_HOST,
	KEV_EL2_IRQ_INJECT,
	KEV_EL2_IRQ_INJECT_FAIL,
	KEV_EL2_IRQ_TYPE_NUM,
};

static const char *kev_el2_irq_texts[KEV_EL2_IRQ_TYPE_NUM] = {
	[KEV_EL2_IRQ_ASSERT_EL1] = "assert el1",
	[KEV_EL2_IRQ_HOST] = "host irq",
	[KEV_EL2_IRQ_INJECT] = "inject",
	[KEV_EL2_IRQ_INJECT_FAIL] = "inject fail",
};

static inline const char *el2_irq_type_str(enum kev_el2_irq_type type)
{
	const char *str = "invalid type";

	if (type < KEV_EL2_IRQ_TYPE_NUM) {
		str = kev_el2_irq_texts[type];
	}

	return str;
}

/* convert time tock into nsec */
static inline __u64
kev_tock2time(__u64 tock, __u64 tock_start, __u64 freq)
{
	__u64 nsec = 0ULL;
	__u64 tock_pure = tock - tock_start;

	if (freq != 0U) {
		nsec = (tock_pure / freq) * __NSEC_PER_SEC +
		       ((tock_pure % freq) * __NSEC_PER_SEC) / freq;
	}

	return nsec;
}

#endif
