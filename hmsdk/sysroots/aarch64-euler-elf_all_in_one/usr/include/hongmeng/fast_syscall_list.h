/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
 * Description: API of Fast syscall list
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 18 03:53:14 2018
 */

#ifndef ULIBS_INCLUDE_HONGMENG_FAST_SYSCALL_LIST_H
#define ULIBS_INCLUDE_HONGMENG_FAST_SYSCALL_LIST_H

#if !defined(__SYSCALL_FAST_DEFINE0) || \
    !defined(__SYSCALL_FAST_DEFINE1) || \
    !defined(__SYSCALL_FAST_DEFINE2) || \
    !defined(__SYSCALL_FAST_DEFINE3) || \
    !defined(__SYSCALL_FAST_DEFINE4) || \
    !defined(__SYSCALL_FAST_DEFINE5) || \
    !defined(__SYSCALL_FAST_DEFINE6) || \
    !defined(__SYSCALL_FAST_DEFINE7)
#error "You cannot include this header file directly."
#endif

#include <hmkernel/capability.h>

__SYSCALL_FAST_DEFINE0(linux_syscall)
__SYSCALL_FAST_DEFINE0(linux_sysret)
__SYSCALL_FAST_DEFINE4(syslog, unsigned long, level, const char *, str,
		       unsigned long, size, const cref_t *, p_perm_cref)
__SYSCALL_FAST_DEFINE3(kconsole_print, const char *, str, unsigned long, size,
		       const cref_t *, p_perm_cref)
__SYSCALL_FAST_DEFINE1(kconsole_enable, const cref_t *, p_perm_cref)
__SYSCALL_FAST_DEFINE1(kconsole_disable, const cref_t *, p_perm_cref)
__SYSCALL_FAST_DEFINE6(futex_wait, volatile int *, ptr, int, key, __u64 *, utimeout,
		       struct __hmsigmask *, sigmask,
		       unsigned long, flags, unsigned long, bitset)
__SYSCALL_FAST_DEFINE3(futex_wait_simple, int *, ptr, int, key,
		       unsigned long, mask_type)
__SYSCALL_FAST_DEFINE4(futex_wake, volatile int *, ptr, unsigned int, num,
		       unsigned long, flags, unsigned long, bitset)
__SYSCALL_FAST_DEFINE2(futex_wake_simple, int *, ptr, unsigned int, num)
__SYSCALL_FAST_DEFINE4(futex_requeue, volatile int *, src_ptr, volatile int *, dst_ptr,
		       unsigned int, deq_num, unsigned int, req_num)
__SYSCALL_FAST_DEFINE3(flush_cache, unsigned long, cmd, unsigned long, start, unsigned long, end)
__SYSCALL_FAST_DEFINE0(rpc_g1_nobuf)
__SYSCALL_FAST_DEFINE0(rpc_g1_sendbuf)
__SYSCALL_FAST_DEFINE0(rpc_g1_retbuf)
__SYSCALL_FAST_DEFINE0(rpc_g1_fallback)
__SYSCALL_FAST_DEFINE0(rpc_g2_nobuf)
__SYSCALL_FAST_DEFINE0(rpc_g2_sendbuf)
__SYSCALL_FAST_DEFINE0(rpc_g2_retbuf)
__SYSCALL_FAST_DEFINE0(rpc_g2_fallback)

__SYSCALL_FAST_DEFINE4(wait_for_event, long, retval,
		       void *, data_ptr, void *, buf_ptr,
		       unsigned long, data_buf_size)
__SYSCALL_FAST_DEFINE3(actv_done_init, long, retval,
		       void *, buf_ptr, unsigned long, data_buf_size)

__SYSCALL_FAST_DEFINE0(sched_yield)
__SYSCALL_FAST_DEFINE3(rpc_read_xact_vm,
		     void *, dst, const void *, src,
		     unsigned long, size)
__SYSCALL_FAST_DEFINE3(rpc_write_xact_vm,
		     void *, dst, const void *, src,
		     unsigned long, size)
__SYSCALL_FAST_DEFINE3(rpc_read_caller_vm,
		     void *, dst, const void *, src,
		     unsigned long, size)
__SYSCALL_FAST_DEFINE3(rpc_write_caller_vm,
		     void *, dst, const void *, src,
		     unsigned long, size)
__SYSCALL_FAST_DEFINE3(rpc_copy_in_xact_vm,
		     void *, dst, const void *, src,
		     unsigned long, size)
__SYSCALL_FAST_DEFINE1(remap_one_pfn, const struct sysarg_vspace_remap_one_pfn *, args)
__SYSCALL_FAST_DEFINE2(trigger_wait, unsigned long, flags,
		       const struct __hmsigmask *, sigmask)
__SYSCALL_FAST_DEFINE0(trigger_done)
__SYSCALL_FAST_DEFINE2(trigger_read, void *, buf, unsigned long, buf_size)
__SYSCALL_FAST_DEFINE2(tock_read, unsigned int, clkid, __u64 *, utock)

__SYSCALL_FAST_DEFINE2(timer_first_timeout, unsigned long, cpuid, __u64 *, timeout)

__SYSCALL_FAST_DEFINE5(copage_ctrl, unsigned int, cmd, void *, args, unsigned long, args_size,
		       void *, ret, unsigned long, ret_size)
__SYSCALL_FAST_DEFINE2(copage_alloc, unsigned int, nr_pages, void *, pfn_offset)
__SYSCALL_FAST_DEFINE2(copage_alloc_at, const void *, pfn_offset, unsigned int, nr_pages)
__SYSCALL_FAST_DEFINE2(copage_free, const void *, pfn_offset, unsigned int, nr_pages)
__SYSCALL_FAST_DEFINE3(unmap, cref_t *, vspace_cref,
		       unsigned long, vstart,
		       unsigned long, vend)
__SYSCALL_FAST_DEFINE4(clone_master_area, cref_t *, src_vspace_cref, cref_t *, dst_vspace_cref,
		       unsigned long, vstart, unsigned long, size)
__SYSCALL_FAST_DEFINE3(mmscd_clone_page, unsigned long, master_pte_vaddr,
		       unsigned long, slave_pte_vaddr, const unsigned long long *, hint)

__SYSCALL_FAST_DEFINE1(mprotect, const struct sysarg_vspace_mprotect *, args)
/* fast call used for default_ref only calller,
 * orders keep same in all related files with captype_thread.h */
__SYSCALL_FAST_DEFINE1(thread_vspace_cref, cref_t *, presult)
__SYSCALL_FAST_DEFINE1(thread_set_runqueue, unsigned long, newrq)
__SYSCALL_FAST_DEFINE1(thread_get_cpu, unsigned int *, pcpu)
__SYSCALL_FAST_DEFINE0(thread_suspend)
__SYSCALL_FAST_DEFINE2(thread_stat, struct sysarg_thread_stat *, presult,
		       unsigned long, flags)
__SYSCALL_FAST_DEFINE2(thread_set_name, const char *, uin, char *, uout)
__SYSCALL_FAST_DEFINE0(thread_trigger_detach_one)

__SYSCALL_FAST_DEFINE1(thread_cref, cref_t *, presult)
__SYSCALL_FAST_DEFINE2(thread_hmsignal_mask, struct __hmsigmask *, uin,
		       struct __hmsigmask *, uout)
__SYSCALL_FAST_DEFINE1(thread_hmsignal_pending, struct __hmsigmask *, dst)
__SYSCALL_FAST_DEFINE1(thread_hmsignal_unset, struct __hmsigmask *, unset_hmsignals)

/*
 * __u64 here is common way in a syscall when reading data through a user pointer.
 * internally, miscdata read from kernel is `unsigned long`. In syscall boundary,
 * kernel converts it to __u64 to make sure arm32/64 see samething.
 */
__SYSCALL_FAST_DEFINE3(miscdata_read, __u64 *, dest, unsigned long, miscdata, unsigned long, access)
__SYSCALL_FAST_DEFINE3(miscdata_write, unsigned long, v, unsigned long, miscdata, unsigned long, access)
/*
 * In these vectorized accessing syscalls, miscdata are treated as memory, not
 * a group of values, so dest/data should be same format as them in kernel, and
 * format transformation will not be done. User should know this difference that,
 * for a same miscdata, reading it using miscdata_read and miscdata_readv gives
 * different result on a 32 bit system:
 * miscdata_read need 8 bytes to store a 32-bit unsigned long, miscdata_readv needs
 * only 4 bytes.
 *
 * for sz, nids * sizeof(unsigned long) is suggest when we knows that
 * app and kernel are in same data model.
 *
 * Avoid using it if user and kernel are possible to be in different data model.
 */
__SYSCALL_FAST_DEFINE4(miscdata_readv, void *, dest, unsigned long, sz,
		       unsigned long, miscdata, unsigned long, access)
__SYSCALL_FAST_DEFINE4(miscdata_writev, void *, data, unsigned long, sz,
		       unsigned long, miscdata, unsigned long, access)

__SYSCALL_FAST_DEFINE6(miscdata_readv_cas, void *, dest, unsigned long, sz,
		       unsigned long, miscdata, unsigned long, access,
		       unsigned long, expectval, unsigned long, newval)
__SYSCALL_FAST_DEFINE5(miscdata_writev_cas, void *, data, unsigned long, sz,
		       unsigned long, miscdata, unsigned long, access,
		       unsigned long, expectval)

__SYSCALL_FAST_DEFINE5(actv_load_stat, struct sysarg_actv_stat *, actv_out,
		       struct __arch_fpsimd_state *, fpsimd,
		       cref_t *, actv_chain_iter,
		       const cref_t *, p_thread_cref,
		       unsigned long, flags)
__SYSCALL_FAST_DEFINE1(cspace_free_cnode_idx, __u32, cnode_idx)

__SYSCALL_FAST_DEFINE1(set_tls, void *, address)

__SYSCALL_FAST_DEFINE1(set_local_area, long, offset)

__SYSCALL_FAST_DEFINE1(actv_cref, cref_t *, p_cref)

__SYSCALL_FAST_DEFINE1(thread_flush_caller,
		       const struct sysarg_execve_config *, execve_conf)

/* survive the stupid code checker */
#undef ULIBS_INCLUDE_HONGMENG_FAST_SYSCALL_LIST_H
#endif
