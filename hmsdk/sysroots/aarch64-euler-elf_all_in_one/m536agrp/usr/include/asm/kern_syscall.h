/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Wed Jul 25 12:57:57 2018
 */

/* Never change this guard: it should be same for each arch */
#ifndef UAPI_ARCH_ASM_KERN_SYSCALL_H
#define UAPI_ARCH_ASM_KERN_SYSCALL_H

#include <hmkernel/const.h>

/* divide svcno into 4 parts:
 *
 * 1  bit : proxycall or normal call
 * 1  bit : 32 or 64 bit
 * 9  bits: method
 * 5  bits: cap
 * */
#ifndef ____SYSCALL_SVCNO
# define ____SYSCALL_SVCNO(is_proxy, cap, method)	\
	(((is_proxy) << __U(15)) | (((method) << __U(5)) | (cap)))
#endif

#ifndef __SYSCALL_SVCNO
# define __SYSCALL_SVCNO(cap, method)		____SYSCALL_SVCNO(__U(0), cap, method)
#endif

#ifndef __SYSCALL_PROXY_SVCNO
# define __SYSCALL_PROXY_SVCNO(cap, method)	____SYSCALL_SVCNO(__U(1), cap, method)
#endif

#ifndef __FAST_SYSCALL_SVCNO
# define __FAST_SYSCALL_SVCNO(method)		__SYSCALL_SVCNO(__U(0), method)
#endif

#ifndef __CAP_SYSCALL_SVCNO
# define __CAP_SYSCALL_SVCNO(cap, method)	__SYSCALL_SVCNO(cap, method)
#endif

#ifndef __CAP_SYSCALL_PROXY_SVCNO
# define __CAP_SYSCALL_PROXY_SVCNO(cap, method)	__SYSCALL_PROXY_SVCNO(cap, method)
#endif

#ifndef ____SYSCALL32_SVCNO
# define ____SYSCALL32_SVCNO(is_proxy, cap, method)	\
	(((is_proxy) << __U(15)) | ((((method) << __U(5)) | (cap)) | (__U(1) << __U(14))))
#endif

#ifndef __SYSCALL32_SVCNO
# define __SYSCALL32_SVCNO(cap, method)		____SYSCALL32_SVCNO(__U(0), cap, method)
#endif

#ifndef __SYSCALL32_PROXY_SVCNO
# define __SYSCALL32_PROXY_SVCNO(cap, method)	____SYSCALL32_SVCNO(__U(1), cap, method)
#endif

#ifndef __FAST_SYSCALL32_SVCNO
# define __FAST_SYSCALL32_SVCNO(method)		__SYSCALL32_SVCNO(__U(0), method)
#endif

#ifndef __CAP_SYSCALL32_SVCNO
# define __CAP_SYSCALL32_SVCNO(cap, method)	__SYSCALL32_SVCNO(cap, method)
#endif

#ifndef __CAP_SYSCALL32_PROXY_SVCNO
# define __CAP_SYSCALL32_PROXY_SVCNO(cap, method)	__SYSCALL32_PROXY_SVCNO(cap, method)
#endif

#ifndef __FAST_SYSCALL
# define __FAST_SYSCALL(name, number)
#endif

#ifndef __FAST_SYSCALL_RESERVED
# define __FAST_SYSCALL_RESERVED(number)
#endif

__FAST_SYSCALL(linux_syscall, 0)
__FAST_SYSCALL(sched_yield, 1)
__FAST_SYSCALL(syslog, 2)
#define __FAST_SYSCALL_FUTEX_WAIT			__FAST_SYSCALL_SVCNO(3)
__FAST_SYSCALL(futex_wait, 3)
#define __FAST_SYSCALL_FUTEX_WAKE			__FAST_SYSCALL_SVCNO(4)
__FAST_SYSCALL(futex_wake, 4)
__FAST_SYSCALL_RESERVED(5)
__FAST_SYSCALL(futex_requeue, 6)
__FAST_SYSCALL(flush_cache, 7)
__FAST_SYSCALL_RESERVED(8)

/*
 * compat rpccall that used for 32bit client,
 * the syscall num is same as arm version.
 */
__FAST_SYSCALL(rpc_compat_g1_nobuf, 9)
__FAST_SYSCALL(rpc_compat_g1_sendbuf, 10)
__FAST_SYSCALL(rpc_compat_g1_retbuf, 11)
__FAST_SYSCALL(rpc_compat_g1_fallback, 12)
__FAST_SYSCALL(wait_for_event, 13)
#define __FAST_SYSCALL_RPC_WFE			__FAST_SYSCALL_SVCNO(13)
__FAST_SYSCALL(actv_done_init, 14)
#define __FAST_SYSCALL_ACTV_DONE_INIT		__FAST_SYSCALL_SVCNO(14)

__FAST_SYSCALL(actv_exit, 15)

/* NOTE: Do not change callno of modulecall,
 * since liblinux has used hard-code 16 for smc adaption */
__FAST_SYSCALL(module_modif_call, 16)

__FAST_SYSCALL_RESERVED(17)
__FAST_SYSCALL_RESERVED(18)

__FAST_SYSCALL(rpc_read_xact_vm, 19)
__FAST_SYSCALL(rpc_write_xact_vm, 20)
__FAST_SYSCALL(rpc_copy_in_xact_vm, 21)
__FAST_SYSCALL(trigger_wait, 23)
__FAST_SYSCALL(trigger_done, 24)
__FAST_SYSCALL(trigger_read, 25)

__FAST_SYSCALL(tock_read, 26)

/*
 * compat rpccall that used for 32bit client,
 * the syscall num is same as arm version.
 */
__FAST_SYSCALL(rpc_compat_g2_nobuf, 27)
__FAST_SYSCALL(rpc_compat_g2_sendbuf, 28)
__FAST_SYSCALL(rpc_compat_g2_retbuf, 29)
__FAST_SYSCALL(rpc_compat_g2_fallback, 30)

__FAST_SYSCALL_RESERVED(31)

__FAST_SYSCALL(copage_ctrl, 32)
__FAST_SYSCALL(copage_alloc, 33)
__FAST_SYSCALL(copage_alloc_at, 34)
__FAST_SYSCALL(copage_free, 35)

__FAST_SYSCALL(thread_vspace_cref, 36)
__FAST_SYSCALL_RESERVED(37)
__FAST_SYSCALL(thread_set_runqueue, 38)
__FAST_SYSCALL(thread_get_cpu, 39)
__FAST_SYSCALL_RESERVED(40)
__FAST_SYSCALL(thread_suspend, 41)
__FAST_SYSCALL_RESERVED(42)
__FAST_SYSCALL_RESERVED(43)
__FAST_SYSCALL(thread_set_thread_area, 44)
__FAST_SYSCALL(thread_stat, 45)
__FAST_SYSCALL(thread_set_name, 46)
__FAST_SYSCALL(thread_trigger_detach_one, 47)

__FAST_SYSCALL(thread_cref, 48)
__FAST_SYSCALL(thread_hmsignal_mask, 49)
__FAST_SYSCALL(thread_hmsignal_pending, 50)
__FAST_SYSCALL(thread_hmsignal_unset, 51)

__FAST_SYSCALL_RESERVED(52)
__FAST_SYSCALL_RESERVED(53)

__FAST_SYSCALL(rpc_read_caller_vm, 54)
__FAST_SYSCALL(rpc_write_caller_vm, 55)

__FAST_SYSCALL(miscdata_read, 56)
__FAST_SYSCALL(miscdata_write, 57)
__FAST_SYSCALL(miscdata_readv, 58)
__FAST_SYSCALL(miscdata_writev, 59)
__FAST_SYSCALL(miscdata_readv_cas, 60)
__FAST_SYSCALL(miscdata_writev_cas, 61)

__FAST_SYSCALL(actv_load_stat, 62)

__FAST_SYSCALL(cspace_free_cnode_idx, 63)

__FAST_SYSCALL(set_tls, 64)

__FAST_SYSCALL_RESERVED(65)

__FAST_SYSCALL(actv_cref, 66)

__FAST_SYSCALL(remap_one_pfn, 67)

__FAST_SYSCALL(thread_flush_caller, 68)

__FAST_SYSCALL(linux_sysret, 69)

__FAST_SYSCALL(rpc_g1_nobuf, 70)
#define __FAST_SYSCALL_RPC_GROUP1_NOBUF		__FAST_SYSCALL_SVCNO(70)
__FAST_SYSCALL(rpc_g1_sendbuf, 71)
#define __FAST_SYSCALL_RPC_GROUP1_SENDBUF	__FAST_SYSCALL_SVCNO(71)
__FAST_SYSCALL(rpc_g1_retbuf, 72)
#define __FAST_SYSCALL_RPC_GROUP1_RETBUF	__FAST_SYSCALL_SVCNO(72)
__FAST_SYSCALL(rpc_g1_fallback, 73)
#define __FAST_SYSCALL_RPC_GROUP1_FALLBACK	__FAST_SYSCALL_SVCNO(73)
__FAST_SYSCALL(rpc_g2_nobuf, 74)
#define __FAST_SYSCALL_RPC_GROUP2_NOBUF		__FAST_SYSCALL_SVCNO(74)
__FAST_SYSCALL(rpc_g2_sendbuf, 75)
#define __FAST_SYSCALL_RPC_GROUP2_SENDBUF	__FAST_SYSCALL_SVCNO(75)
__FAST_SYSCALL(rpc_g2_retbuf, 76)
#define __FAST_SYSCALL_RPC_GROUP2_RETBUF	__FAST_SYSCALL_SVCNO(76)
__FAST_SYSCALL(rpc_g2_fallback, 77)
#define __FAST_SYSCALL_RPC_GROUP2_FALLBACK	__FAST_SYSCALL_SVCNO(77)

__FAST_SYSCALL(unmap, 78)

__FAST_SYSCALL(mprotect, 79)

__FAST_SYSCALL(futex_wait_simple, 80)
#define __FAST_SYSCALL_FUTEX_WAIT_SIMPLE	__FAST_SYSCALL_SVCNO(80)

__FAST_SYSCALL(futex_wake_simple, 81)
#define __FAST_SYSCALL_FUTEX_WAKE_SIMPLE	__FAST_SYSCALL_SVCNO(81)

__FAST_SYSCALL(clone_master_area, 82)

__FAST_SYSCALL(kconsole_print, 83)

__FAST_SYSCALL(kconsole_enable, 84)
__FAST_SYSCALL(kconsole_disable, 85)

__FAST_SYSCALL(mmscd_clone_page, 86)

__FAST_SYSCALL(timer_first_timeout, 87)

__FAST_SYSCALL(set_local_area, 88)
/*
 * the ext fastcall should be the last fastcalls, the EXT_FASTCALL_BASE
 * should be increased synchronously when add new normal fastcalls.
 */
#define __EXT_FASTCALL_CALLNO_BASE		89
#define __EXT_FASTCALL_NR_GLOBAL		13
#define __EXT_FASTCALL_NR_PER_CNODE		5
#define __EXT_FASTCALL_NR_PER_THREAD		5
#define __EXT_FASTCALL_NR_TOTAL			(__EXT_FASTCALL_NR_GLOBAL + \
						 __EXT_FASTCALL_NR_PER_CNODE + \
						 __EXT_FASTCALL_NR_PER_THREAD)
#define __EXT_FASTCALL_CALLNO_BASE_GLOBAL	__EXT_FASTCALL_CALLNO_BASE
#define __EXT_FASTCALL_CALLNO_BASE_PER_CNODE	(__EXT_FASTCALL_CALLNO_BASE + \
						 __EXT_FASTCALL_NR_GLOBAL)
#define __EXT_FASTCALL_CALLNO_BASE_PER_THREAD	(__EXT_FASTCALL_CALLNO_BASE + \
						 __EXT_FASTCALL_NR_GLOBAL + \
						 __EXT_FASTCALL_NR_PER_CNODE)
#define __EXT_FASTCALL_CALLNO_MAX		(__EXT_FASTCALL_CALLNO_BASE + \
						 __EXT_FASTCALL_NR_TOTAL - 1)
#define __EXT_FASTCALL_IS_GLOBAL(scno)		((scno) >= (unsigned int)(__EXT_FASTCALL_CALLNO_BASE_GLOBAL) && \
						 (scno) < (unsigned int)(__EXT_FASTCALL_CALLNO_BASE_PER_CNODE))
#define __EXT_FASTCALL_IS_PER_CNODE(scno)	((scno) >= (unsigned int)(__EXT_FASTCALL_CALLNO_BASE_PER_CNODE) && \
						 (scno) < (unsigned int)(__EXT_FASTCALL_CALLNO_BASE_PER_THREAD))
#define __EXT_FASTCALL_IS_PER_THREAD(scno)	((scno) >= (unsigned int)(__EXT_FASTCALL_CALLNO_BASE_PER_THREAD) && \
						 (scno) <= (unsigned int)(__EXT_FASTCALL_CALLNO_MAX))
#define __EXT_FASTCALL_IS_VALID(scno)		((scno) >= (unsigned int)(__EXT_FASTCALL_CALLNO_BASE) && \
						 (scno) <= (unsigned int)(__EXT_FASTCALL_CALLNO_MAX))
#define __EXT_FASTCALL_MKCALLNO_GLOBAL(index)	(__EXT_FASTCALL_CALLNO_BASE_GLOBAL + (index))
#define __EXT_FASTCALL_MKCALLNO_PER_CNODE(index) (__EXT_FASTCALL_CALLNO_BASE_PER_CNODE + (index))
#define __EXT_FASTCALL_MKCALLNO_PER_THREAD(index) (__EXT_FASTCALL_CALLNO_BASE_PER_THREAD + (index))
#define __EXT_FASTCALL_MKINDEX_GLOBAL(scno)	((scno) - (unsigned int)(__EXT_FASTCALL_CALLNO_BASE_GLOBAL))
#define __EXT_FASTCALL_MKINDEX_PER_CNODE(scno)	((scno) - (unsigned int)(__EXT_FASTCALL_CALLNO_BASE_PER_CNODE))
#define __EXT_FASTCALL_MKINDEX_PER_THREAD(scno) ((scno) - (unsigned int)(__EXT_FASTCALL_CALLNO_BASE_PER_THREAD))

/* ext fastcall type: GLOBAL */
__FAST_SYSCALL(ext_global_0, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL))
__FAST_SYSCALL(ext_global_1, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 1))
__FAST_SYSCALL(ext_global_2, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 2))
__FAST_SYSCALL(ext_global_3, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 3))
__FAST_SYSCALL(ext_global_4, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 4))  /* watchdog config for CDC*/
__FAST_SYSCALL(ext_global_5, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 5))  /* vnotify_notify_channel */
__FAST_SYSCALL(ext_global_6, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 6))  /* vnotify_notify_ctrl_channel */
__FAST_SYSCALL(ext_global_7, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 7))  /* vnotify_read_chn_msg */
__FAST_SYSCALL(ext_global_8, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 8))  /* vnotify_update_futex */
__FAST_SYSCALL(ext_global_9, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 9))  /* vnotify_read_status */
__FAST_SYSCALL(ext_global_10, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 10))  /* vnotify_inject_event */
__FAST_SYSCALL(ext_global_11, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 11))  /* vnotify_clear_vspace */
__FAST_SYSCALL(ext_global_12, (__EXT_FASTCALL_CALLNO_BASE_GLOBAL + 12))  /* iomem_atomic_op_32 */
/* ext fastcall type: PER_CNODE */
__FAST_SYSCALL(ext_per_cnode_0, (__EXT_FASTCALL_CALLNO_BASE_PER_CNODE))
__FAST_SYSCALL(ext_per_cnode_1, (__EXT_FASTCALL_CALLNO_BASE_PER_CNODE + 1))
__FAST_SYSCALL(ext_per_cnode_2, (__EXT_FASTCALL_CALLNO_BASE_PER_CNODE + 2))
__FAST_SYSCALL(ext_per_cnode_3, (__EXT_FASTCALL_CALLNO_BASE_PER_CNODE + 3))
__FAST_SYSCALL(ext_per_cnode_4, (__EXT_FASTCALL_CALLNO_BASE_PER_CNODE + 4))
/* ext fastcall type: PER_THREAD */
__FAST_SYSCALL(ext_per_thread_0, (__EXT_FASTCALL_CALLNO_BASE_PER_THREAD))
__FAST_SYSCALL(ext_per_thread_1, (__EXT_FASTCALL_CALLNO_BASE_PER_THREAD + 1))
__FAST_SYSCALL(ext_per_thread_2, (__EXT_FASTCALL_CALLNO_BASE_PER_THREAD + 2))
__FAST_SYSCALL(ext_per_thread_3, (__EXT_FASTCALL_CALLNO_BASE_PER_THREAD + 3))
__FAST_SYSCALL(ext_per_thread_4, (__EXT_FASTCALL_CALLNO_BASE_PER_THREAD + 4))

#endif
