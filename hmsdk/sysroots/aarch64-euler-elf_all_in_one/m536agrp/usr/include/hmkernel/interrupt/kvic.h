/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Define structures and prototypes of kvic
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jan 25 10:25:38 2019
 */
#ifndef UAPI_HMKERNEL_KVIC_H
#define UAPI_HMKERNEL_KVIC_H

#include <hmkernel/capability.h>

#define KVIC_DROP	0x1U

/* XXX seems like tty or sth depends on the ID_UART value, and it must be 0 */
enum __kvic_source_id {
	/* kvic source id for uart & tty */
	__KVIC_SOURCE_ID_UART = 0,
	/* kvic source id for kshortcut/sysrq */
	__KVIC_SOURCE_ID_SYSRQ,
	/* kvic source id for watchdog */
	__KVIC_SOURCE_ID_WDT,
	/* kvic source id for preempt */
	__KVIC_SOURCE_ID_PREEMPT,
	/* kvic source id for hotplug */
	__KVIC_SOURCE_ID_HOTPLUG,
	/* kvic source id for settime */
	__KVIC_SOURCE_ID_SETTIME,

	/*
	 * put the kev source id in the end of the enum and add other new source
	 * ids before the kev start.
	 *
	 * The trigger source is attached with a kev ringbuffer, not with the
	 * KEV TYPE, i.e., we notify the userspace listener from the
	 * perspective of the ringbuffer but not the KEV TYPE. There is a middle
	 * layer to handle the mapping from kev source id to the ringbuffer.
	 */
	__KVIC_SOURCE_ID_KEV_START,	/* kvic source id for kev start */
#define DEFINE_KEV(NAME, ...) __KVIC_SOURCE_ID_##NAME,
	#include <hmkernel/events/kev_list.h>
#undef DEFINE_KEV
	__NR_KVIC_SOURCE_ID,		/* number of kvic source id */
};

#define __KVIC_SOURCE_ID_INVALID	__NR_KVIC_SOURCE_ID

/*
 * The problem is that one instruction will not be executed
 * until the another one is entered in serial, for some
 * instruction chars which should be filled into KVIC buffer,
 * have been blocked in UART buffer. To reduce the risk,
 * this KVIC buffer length can be increased accordingly.
 */
#define KVIC_UART_DATA_MAX 1024U

struct __kvic_uart_read_data {
	unsigned int datalen;
	char data[KVIC_UART_DATA_MAX];
};

struct __kvic_kev_data {
	__u64 head;
	__u32 index;
};

#define __KVIC_SNAPSHOT_FIQ_ARG_LOWDOG	0x1U
#define __KVIC_SNAPSHOT_FIQ_ARG_HWDOG	0x2U

enum __kvic_snapshot_irq_type {
	__KVIC_SNAPSHOT_FIQ,
	__KVIC_SNAPSHOT_SYSRQ,
	__KVIC_SNAPSHOT_PREEMPT,
	__KVIC_SNAPSHOT_HOTPLUG
};

struct __kvic_snapshot_irq_data {
	__u32 type;
	__u32 arg;
	union {
		cref_t tcb_cref;
		__u32 target_cpu;
	};
};

#endif
