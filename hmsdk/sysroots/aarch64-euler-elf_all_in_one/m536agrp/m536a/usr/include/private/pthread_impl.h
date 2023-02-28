#ifndef _PTHREAD_IMPL_H
#define _PTHREAD_IMPL_H

#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/mman.h>
#include "libc.h"
#include "syscall.h"
#include "atomic.h"
#include "futex.h"

#ifdef CONFIG_SHADOW_STACK
#define SHADOW_STACK_GUARD_SIZE		PAGE_SIZE
#define SHADOW_STACK_SIZE		PAGE_SIZE
#define SHADOW_STACK_TOTAL_SIZE		(SHADOW_STACK_GUARD_SIZE + SHADOW_STACK_SIZE + SHADOW_STACK_GUARD_SIZE)
#define shadow_stack_start_addr(addr)	(addr + SHADOW_STACK_GUARD_SIZE + SHADOW_STACK_SIZE - sizeof(void *))

#define get_shadow_stack(sstack) \
	asm volatile("mov %0, x18" : "=r"(sstack))

#define set_shadow_stack(sstack) \
	asm volatile("mov x18, %0" :: "r"(sstack))
#endif

#define pthread __pthread

struct pthread {
	/* Part 1 -- these fields may be external or
	 * internal (accessed via asm) ABI. Do not change. */
	struct pthread *self;
	uintptr_t *dtv;
	struct pthread *prev, *next; /* non-ABI */
	uintptr_t sysinfo;
	uintptr_t canary, canary2;

	/* Part 2 -- implementation details, non-ABI. */
	int tid;
	int errno_val;
	volatile int detach_state;
	volatile int cancel;
	volatile unsigned char canceldisable, cancelasync;
	volatile int do_syscall;
	unsigned char tsd_used:1;
	unsigned char dlerror_flag:1;
	/* mark thread type for HongMeng OS */
	char type;
	unsigned char *map_base;
	size_t map_size;
	void *stack;
#ifdef CONFIG_SHADOW_STACK
	void *sstack_base;
	void *sstack;	/* store the base address of the shadow stack */
#endif
	size_t stack_size;
	size_t guard_size;
	void *result;
	struct __ptcb *cancelbuf;
	void **tsd;
	struct {
		volatile void *volatile head;
		long off;
		volatile void *volatile pending;
	} robust_list;
	volatile int timer_id;
	locale_t locale;
	volatile int killlock[1];
	char *dlerror_buf;
	void *stdio_locks;
	long long himalloc_tcache_addr; /* used for himalloc tcache addr */

	/* Part 3 -- the positions of these fields relative to
	 * the end of the structure is external and internal ABI. */
	int signal_disable_count;
	int signal_trigger_count;
	uintptr_t canary_at_end;
	uintptr_t *dtv_copy;
};

enum {
	DT_EXITING = 0,
	DT_JOINABLE,
	DT_DETACHED,
};

struct __timer {
	int timerid;
	pthread_t thread;
};

#define __SU (sizeof(size_t)/sizeof(int))

#define _a_stacksize __u.__s[0]
#define _a_guardsize __u.__s[1]
#define _a_stackaddr __u.__s[2]
#define _a_cpuset __u.__s[3]
#define _a_cpusetsize __u.__s[4]
#define _a_detach __u.__i[5*__SU+0]
#define _a_sched __u.__i[5*__SU+1]
#define _a_policy __u.__i[5*__SU+2]
#define _a_prio __u.__i[5*__SU+3]
#define _m_type __u.__i[0]
#define _m_lock __u.__vi[1]
#define _m_waiters __u.__vi[2]
#define _m_prev __u.__p[3]
#define _m_next __u.__p[4]
#define _m_count __u.__i[5]
#define _c_shared __u.__p[0]
#define _c_seq __u.__vi[2]
#define _c_waiters __u.__vi[3]
#define _c_clock __u.__i[4]
#define _c_lock __u.__vi[8]
#define _c_head __u.__p[1]
#define _c_tail __u.__p[5]
#define _rw_lock __u.__vi[0]
#define _rw_waiters __u.__vi[1]
#define _rw_shared __u.__i[2]
#define _b_lock __u.__vi[0]
#define _b_waiters __u.__vi[1]
#define _b_limit __u.__i[2]
#define _b_count __u.__vi[3]
#define _b_waiters2 __u.__vi[4]
#define _b_inst __u.__p[3]

#include "pthread_arch.h"

#ifndef CANARY
#define CANARY canary
#endif

#ifndef DTP_OFFSET
#define DTP_OFFSET 0
#endif

#ifndef tls_mod_off_t
#define tls_mod_off_t size_t
#endif

#define SIGTIMER 32
#define SIGCANCEL 33
#define SIGSYNCCALL 34

#define SIGALL_SET ((sigset_t *)(const unsigned long long [2]){ -1,-1 })
#define SIGPT_SET \
	((sigset_t *)(const unsigned long [_NSIG/8/sizeof(long)]){ \
	[sizeof(long)==4] = 3UL<<(32*(sizeof(long)>4)) })
#define SIGTIMER_SET \
	((sigset_t *)(const unsigned long [_NSIG/8/sizeof(long)]){ \
	 0x80000000 })

#ifdef CONFIG_SHADOW_STACK
void *__mmap_sstack(void);
#endif

void *__tls_get_addr(tls_mod_off_t *);
hidden int __init_tp(void *);
hidden void *__copy_tls(unsigned char *);
hidden void __reset_tls(void);

hidden void __membarrier_init(void);
hidden void __dl_thread_cleanup(void);
hidden void __testcancel(void);
hidden void __do_cleanup_push(struct __ptcb *);
hidden void __do_cleanup_pop(struct __ptcb *);
hidden void __pthread_tsd_run_dtors(void);

hidden void __pthread_key_delete_synccall(void (*)(void *), void *);
hidden int __pthread_key_delete_impl(pthread_key_t);

extern hidden volatile size_t __pthread_tsd_size;
extern hidden void *__pthread_tsd_main[];
extern hidden volatile int __aio_fut;

hidden int __clone(int (*)(void *), void *, int, void *, int *, void *, int *);
hidden int __set_thread_area(void *);
hidden int __libc_sigaction(int, const struct sigaction *, struct sigaction *);
hidden void __unmapself(void *, size_t);

hidden int __timedwait(volatile int *, int, clockid_t, const struct timespec *, int);
hidden int __timedwait_cp(volatile int *, int, clockid_t, const struct timespec *, int);
hidden void __wait(volatile int *, volatile int *, int, int);
static inline void __wake(volatile void *addr, int cnt, int priv)
{
	if (priv) priv = FUTEX_PRIVATE;
	if (cnt<0) cnt = INT_MAX;
	__syscall(SYS_futex, addr, FUTEX_WAKE|priv, cnt) != -ENOSYS ||
	__syscall(SYS_futex, addr, FUTEX_WAKE, cnt);
}
static inline void __futexwait(volatile void *addr, int val, int priv)
{
	if (priv) priv = FUTEX_PRIVATE;
	__syscall(SYS_futex, addr, FUTEX_WAIT|priv, val, 0) != -ENOSYS ||
	__syscall(SYS_futex, addr, FUTEX_WAIT, val, 0);
}

static inline int
is_sched_policy_valid(int policy)
{
	return (policy == SCHED_FIFO) || (policy == SCHED_RR) || (policy == SCHED_OTHER);
}

hidden void __acquire_ptc(void);
hidden void __release_ptc(void);
hidden void __inhibit_ptc(void);

void __tl_lock(void);
void __tl_unlock(void);
hidden void __tl_sync(pthread_t);

extern hidden volatile int __thread_list_lock;

extern hidden unsigned __default_stacksize;
extern hidden unsigned __default_guardsize;

#define DEFAULT_STACK_SIZE 131072
#define DEFAULT_GUARD_SIZE 8192

#define DEFAULT_STACK_MAX (8<<20)
#define DEFAULT_GUARD_MAX (1<<20)

#define __ATTRP_C11_THREAD ((void*)(uintptr_t)-1)

#ifdef PTHREAD_SIMPLE_CHECK
#define IS_PTHREAD_VALID(p) ({					\
	bool found = false;					\
	pthread_t __td = __pthread_self();			\
	pthread_t __self = __td;				\
	__tl_lock();						\
	do {							\
		if (p == __td && p->tid == __td->tid) {		\
			found = true;				\
		}						\
		__td = __td->next;				\
	} while (__td != __self);				\
	__tl_unlock();						\
	found;							\
})
#else
#define IS_PTHREAD_VALID(p) true
#endif

#endif
