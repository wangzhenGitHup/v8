/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018. All rights reserved.
 * Description: Public interface of libuvmm
 * Author: Huawei OS Kernel Lab
 * Create: Wed Dec 19 13:34:09 2018
 */

#ifndef HM_UVMM_UVMM_H
#define HM_UVMM_UVMM_H

#include <stdint.h>
#include <libstrict/strict.h>
#include <hmkernel/sched/priority.h>
#include <hmkernel/drivers/hypervisor.h>
#include <libbunch/bunch_ipc.h>

#define VM_TYPE_UNINITIALIZED		(-1)

#define MAX_DTB_NODE_NUM		16
#define MAX_DTB_BOOTARG_NUM		3
#define MAX_PLUGIN_NUM			5

#define VM_VCPU_SET_SCHEDPOLICY 	1U
#define VM_VCPU_SET_SCHEDPRIO		(1U << 1U)

typedef struct vcpu vcpu_t;
typedef struct vm vm_t;

enum hyptrace_stats_act {
	HYPTRACE_STATS_ACT_SHOW,
	HYPTRACE_STATS_ACT_CLEAR,
	HYPTRACE_STATS_ACT_ENABLE,
	HYPTRACE_STATS_ACT_DISABLE,
#ifdef CONFIG_VCPU_TIMEOUT_MONITOR
	HYPTRACE_SET_VCPU_TRAP_TIMEOUT,
#endif
	HYPTRACE_STATS_ACT_INVALID,
};

struct dtb_info {
	void		*dtb_buf;
	size_t		dtb_bufsize;
};

struct sched_info {
	unsigned int 	flags;
	int 		sched_prio;
	int 		sched_policy;
	unsigned int	affinities[MAX_VCPUS];
#ifdef CONFIG_VM_TICKLESS
	bool		is_tickless;
#endif
};

struct vm_create_args {
	unsigned int	dev_group_id;
	unsigned int	nr_vcpus;
	bool		is_aarch32;
	bool		create_vnotify;
	bool		is_autopause;
	bool		set_pdeathsig;

	uint64_t	bootaddr;
	int		kernel_fd;
	int		initrd_fd;
	int		dtb_fd;
	int		guestbin_fd;
	struct dtb_info	dtb_info;

	const char      *gdb_args;

	unsigned int	nr_nodes;
	const char	*nodes[MAX_DTB_NODE_NUM];
	unsigned int	nr_bootargs;
	const char	*bootargs[MAX_DTB_BOOTARG_NUM];
#ifdef CONFIG_VM_VDSO_HOST
	uint64_t	vdso_gpa;
	uint64_t	vdso_gpa_size;
#endif
#ifdef CONFIG_VIRTIO_NET
	const char	*netdev;
#endif
	unsigned int	nr_plugin;
	const char	*plugin_so_path[MAX_PLUGIN_NUM];
	struct sched_info sched_info;
};
#ifdef CONFIG_VCPU_TIMEOUT_MONITOR
void vcpu_set_trap_timeout(vm_t *vm, uint64_t vcpu_trap_timeout);
#endif
vm_t *fetch_g_vm(void);
/* these functions are the public interface */
int vm_create(vm_t **vmp, const struct vm_create_args *pargs);
void vm_start(vm_t *vm);
void vm_stop(vm_t *vm);
int vm_pause(vm_t *vm);
int vm_unpause(vm_t *vm);
bool is_vm_running_locked(vm_t *vm);
bool is_vm_running(vm_t *vm);
void vm_reset(vm_t *vm);
void vm_destroy(vm_t *vm);
int vm_main_loop(vm_t *vm);

void vm_set_force_exit(bool flag);
void vm_set_exit_errno(int reason);
int vm_get_exit_errno(void);

#ifdef CONFIG_VM_GIC_PASSTHROUGH
int vm_setirq_attribute(const vm_t *vm, const struct vm_create_args *pargs);
#endif

int vm_map_iomem(vm_t *vm);
int vm_map_shmmem(vm_t *vm);
int vm_resume(vm_t *vm);

int uvmm_sysif_init(unsigned int id);
int uvmm_type_of(void);
int uvmm_path_of(char *buf, unsigned long len);


void vcpu_set_mpid(vcpu_t *vcpu, uint64_t mpid);

static inline bool is_vcpu_priority_valid(int priority)
{
	return ((priority >= HM_PRIORITY_SCHED_RT_MIN) && (priority <= HM_PRIORITY_NATIVE_SERVICE_BASE - 1));
}

int vm_get_vnotify_chns_info(vm_t *vm, struct bunch_ipc_attr *attr);

#ifdef CONFIG_VIRTIO_NET
struct vhost_memory_s;
int vm_get_vhost_memory(const vm_t *vm, struct vhost_memory_s *mem);
#endif

/*
 * Provides an ability to handle function flows for different platforms.
 * Handler func names are the same as caller:
 * vm_handler.create_init()<----------->uapps_vm_create().
 * vm_handler.create_deinit()<--------->uapps_vm_create().
 * vm_handler.prepare_init()<---------->prepare_vm().
 * vm_handler.vm_init()<--------------->init_vm().
 */
#define MAX_HOOKS 32

typedef struct vm_handler {
	void (*create_init)(void *);
	void (*create_deinit)(void *);
	void (*prepare_init)(void *);
	int (*vm_init)(const void *);
} vm_handler_t;

typedef struct vm_init_hook {
	vm_handler_t fn[MAX_HOOKS];
	unsigned int cur_id;
} vm_init_hook_t;

vm_init_hook_t *fetch_init_hook(void);

#define vm_init_hook_register(handler)						\
static void __attribute__((constructor)) do_vm_init_hook_##handler(void)	\
{										\
	vm_init_hook_t *hook = fetch_init_hook();				\
	if (hook->cur_id < MAX_HOOKS) {						\
		hook->fn[hook->cur_id] = handler;				\
		hook->cur_id++;							\
	} else {								\
		hm_error("register %s hook failed: length exceeds\n", #handler);\
	}									\
}

#endif /* HM_UVMM_UVMM_H */
