/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Wed Dec 19 13:34:09 2018
 */

#ifndef HM_UVMM_VM_H
#define HM_UVMM_VM_H

#include <hmkernel/drivers/hypervisor.h>
#include <asm/drivers/hypervisor.h>
#include <libhmsrv_sys/hm_vm.h>
#include <hongmeng/panic.h>
#include <hongmeng/syscall.h>
#include <libhmlog/hmlog.h>
#include <libhmucap/ucap.h>
#include <libhmsync/raw_thread.h>
#include <libhmsync/atomic.h>
#include <external/libuvmm/uvmm.h>
#include <errno.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>

#include "vmloop.h"
#include "vmgdb.h"
#include "gdbtarget.h"

#define STAGE2_VA_BITS	39

typedef struct system_bus system_bus_t;

/*
 * State of vcpu:
 *
 *        [ CREATED ]---------------------------------------------+
 *             |                                                  |
 *             |                                                  |
 *             |                                                  |
 *          <start>                                          <autopause>
 *             |                                                  |
 *             |                                                  |
 *             |                                                  |
 *             V                                                  V
 *    +-->[ RUNNING ]---------------------------------------->[ PAUSE ]
 *    |        |                                                  |
 *    |        |                                                  |
 *    |        |                                                <stop>
 *    |        +----------------------------------------------+   |
 *    |        |                                              |   |
 *    |        |                                              |   |
 * <start>     |                                           <stop> |
 *    |        |                                              |   |
 *    |        V                                              V   V
 *    |   [ SUSPEND ]-------------------------<stop>------>[ STOPPED ]
 *    |                                                           |
 *    |                                                           |
 *    |                                                           |
 *    +----[ RESET ]<----------------<reset>----------------------+
 *
 * 1. RUNNING matches RUNNING in hypervisor
 * 2. STOPPED matches STOPPED in hypervisor
 * 3. PAUSE matches PAUSE in hypervisor
 * 4. SUSPEND is a special STOPPED, and also matches STOPPED in hypervisor
 * 5. CREATED is the state when creating vcpu thread, vcpu should be STOPPED in
 *    hypervisor
 * 6. RESET is a temp state when resetting vm, vcpu should go to STOPPED
 *    firstly, and set to RESET state.
 */

#define VCPU_STATE_NAME_CREATED "CREATED"
#define VCPU_STATE_NAME_RUNNING "RUNNING"
#define VCPU_STATE_NAME_STOPPED "STOPPED"
#define VCPU_STATE_NAME_RESET "RESET"
#define VCPU_STATE_NAME_SUSPEND "SUSPEND"
#define VCPU_STATE_NAME_PAUSE "PAUSE"

enum vcpu_state {
	VCPU_STATE_CREATED = 0,
	VCPU_STATE_RUNNING,
	VCPU_STATE_STOPPED,
	VCPU_STATE_RESET,
	VCPU_STATE_SUSPEND,
	VCPU_STATE_PAUSE,
	VCPU_NUM_STATES,
};

/* suspend resume context of psci */
struct psci_sr_ctx {
	/*
	 * entry point address where guest code execution needs to
	 * resume at wakeup time
	 * entry_point is a guest physical address.
	 */
	uint64_t	entry_point;
	/*
	 * context identifier only meaningfull for the guest. save at suspend
	 * time and restore to x0 at resume time
	 */
	uint64_t	context_id;
};

/*
 * struct vcpu locking conventions:
 * - The vcpu->lock shall be held by the handler thread while running
 * - The is_running variable is protected by the VM-wide mutex,
 *   and is volatile so it can be used to signal to a vcpu thread
 *   should stop running and release the vcpu's mutex.
 * Thus, any remote thread that wishes to manipulate an existing vcpu,
 * can first set is_running to false, and then wait for the mutex to
 * become available.
 *
 * To avoid deadlocks with two vcpu threads attempting to manipulate
 * each other, always _trylock the VM-wide mutex first. If this fails,
 * make sure to release our own lock in a safe manner, so that whoever
 * is now holding the VM-wide mutex can proceed deadlock-free.
 */
struct vcpu {
	pthread_mutex_t	lock;
	enum vcpu_state	state;

	vm_t		*vm;

	cref_t		vcpu_thread;
	int		vcpu_thread_tid;

	cref_t		vcpu_ctx;

	vcpu_watchpoint	*wp_hit;

	uint64_t		mpid;
	unsigned int		index;
	struct psci_sr_ctx	psci_sr_ctx;
#if defined(CONFIG_SUSPEND_RESUME_TEEOS) || defined(CONFIG_VM_VCPU_HOTPLUG)
	unsigned int		affinity;
#endif

#ifdef CONFIG_VM_VCPU_HOTPLUG
	int			hotplug_futex;
#endif
};

struct vm {
	pthread_mutex_t	lock;

	unsigned int		num_vcpus;
	raw_atomic_int_t	online_vcpus;
	vcpu_t			*vcpus[MAX_VCPUS];

	system_bus_t	*sysbus;

	struct vm_region_s *regions;
	unsigned int	vm_region_num;

	int 		shm_id[VM_SHM_REGIONS_NUM];
	uint64_t	vm_shm_hva[VM_SHM_REGIONS_NUM]; /* host virtual address */
	uint64_t	vm_shm_hpa[VM_SHM_REGIONS_NUM]; /* host physic address */
	uint64_t	vm_shm_gpa[VM_SHM_REGIONS_NUM]; /* guest physic address */
	unsigned long	vm_shm_size[VM_SHM_REGIONS_NUM];

	cref_t		vm_cref;
	cref_t		vm_cref_pmem;

	uint64_t	bootaddr;
	/* those elements specified the boot files used to init vm */
	int		kernel_fd;
	int		initrd_fd;
	int		guestbin_fd;
	/* dtb for booting guest is keeped in dtb_info */
	const struct dtb_info	*dtb_info;
	bool		is_aarch32;
	bool		is_autopause;
	/* The virtual time when the vm starts to pause */
	uint64_t		vtime;
	raw_atomic_int_t	is_vtime_valid;

	raw_thread_t	listener_threads[MAX_VCPUS];

	struct vm_poll_sources poll_sources;
	struct vm_gdbstub *gdbstub;
	struct sysarg_vm_vnotify_info *vnotify_info;

#ifdef CONFIG_VM_VCPU_HOTPLUG
	/*
	 * every bit indicate a vcpu hotplug on/off status (0b1: hotplug off, 0b0: hotplug on)
	 *  bit[0] for vcpu0
	 *  bit[1] for vcpu1
	 *  etc...
	*/
	raw_atomic_int_t expect_mask;
	raw_atomic_int_t cur_mask;
	raw_atomic_int_t hotplug_flag;
#endif
};

void vm_start_raw(vm_t *vm);
void vm_stop_raw(vm_t *vm);
int vm_pause_raw(const vm_t *vm);
int vm_unpause_raw(const vm_t *vm);
void vm_reset_raw(vm_t *vm, const vcpu_t *caller);


vcpu_t *vm_get_vcpu_by_mpid(vm_t *vm, uint64_t affinity);
void vm_dump_vcpu_regs(const vm_t *vm);

/*
 * vm_lock_all_vcpus and vm_unlock_all_vcpus:
 *   lock and unlock all VCPUs of a VM
 */
static inline void vm_lock_all_vcpus(vm_t *vm)
{
	if (vm == NULL) {
		hm_error("Null pointer provided to lock vm cpus\n");
	} else {
		for (unsigned int i = 0U; i < vm->num_vcpus; i++) {
			(void)pthread_mutex_lock(&vm->vcpus[i]->lock);
		}
	}
}

static inline void vm_unlock_all_vcpus(vm_t *vm)
{
	if (vm == NULL) {
		hm_error("Null pointer provided to unlock vm cpus\n");
	} else {
		for (unsigned int i = 0U; i < vm->num_vcpus; i++) {
			(void)pthread_mutex_unlock(&vm->vcpus[i]->lock);
		}
	}
}

#endif /* HM_UVMM_VM_H */
