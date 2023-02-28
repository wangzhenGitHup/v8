/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
 * Description: API of Cap syscall list
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 18 03:53:14 2018 -0700
 */

#ifndef ULIBS_INCLUDE_HONGMENG_CAP_SYSCALL_LIST_H
#define ULIBS_INCLUDE_HONGMENG_CAP_SYSCALL_LIST_H

#if !defined(__SYSCALL_CAP_DEFINE0) || \
    !defined(__SYSCALL_CAP_DEFINE1) || \
    !defined(__SYSCALL_CAP_DEFINE2) || \
    !defined(__SYSCALL_CAP_DEFINE3) || \
    !defined(__SYSCALL_CAP_DEFINE4) || \
    !defined(__SYSCALL_CAP_DEFINE5) || \
    !defined(__SYSCALL_CAP_DEFINE6) || \
    !defined(__SYSCALL_CAP_DEFINE7)
#error "You cannot include this header directly."
#endif

#ifdef __UAPI_COMPAT__
/* A fake CNodeCompatLLT for compat arg fetch test */
__SYSCALL_CAP_DEFINE7(CNode, CompatLLT, cref_t, base_pmem_cref,
		      unsigned long long, newcap_flag,
		      unsigned long, p1, unsigned long, p2,
		      unsigned long, p3, unsigned long, p4,
		      cref_t *, result)
#endif
__SYSCALL_CAP_DEFINE7(CNode, NewCap, cref_t, base_pmem_cref,
		      unsigned long long, newcap_flag,
		      unsigned long, p1, unsigned long, p2,
		      unsigned long, p3, unsigned long, p4,
		      cref_t *, result)
__SYSCALL_CAP_DEFINE7(CNode, MMSCD_NewCap, unsigned long, vstart,
		      unsigned long long, newcap_flag,
		      unsigned long, p1, unsigned long, p2,
		      unsigned long, p3, unsigned long, p4,
		      cref_t *, result)
__SYSCALL_CAP_DEFINE1(CNode, DeleteCap, cref_t, cref)
__SYSCALL_CAP_DEFINE1(CNode, MMSCD_DeleteCap, cref_t, cref)
__SYSCALL_CAP_DEFINE3(CNode, IterateCTableStart, unsigned int, captype,
		      unsigned int, state, cref_t *, pref)
__SYSCALL_CAP_DEFINE3(CNode, IterateCTableNext, unsigned int, captype,
		      unsigned int, state, cref_t *, pref)
__SYSCALL_CAP_DEFINE3(CNode, IterateUTableStart, unsigned int, captype,
		      unsigned int, state, cref_t *, pref)
__SYSCALL_CAP_DEFINE3(CNode, IterateUTableNext, unsigned int, captype,
		      unsigned int, state, cref_t *, pref)
__SYSCALL_CAP_DEFINE3(CNode, IterateRTableStart, unsigned int, captype,
		      unsigned int, state, cref_t *, pref)
__SYSCALL_CAP_DEFINE3(CNode, IterateRTableNext, unsigned int, captype,
		      unsigned int, state, cref_t *, pref)
__SYSCALL_CAP_DEFINE3(CNode, StatCap, struct sysarg_cnode_statcap *, presult,
		      cref_t, pcref, unsigned long, flags)
__SYSCALL_CAP_DEFINE2(CNode, ExtendCTable, cref_t, pmem, unsigned int, free_slots_water)
__SYSCALL_CAP_DEFINE2(CNode, ExtendRTable, cref_t, pmem, unsigned int, free_slots_water)
__SYSCALL_CAP_DEFINE2(CNode, ExtendUTable, cref_t, pmem, unsigned int, free_slots_water)
__SYSCALL_CAP_DEFINE3(CNode, MMSCD_ExtendCTable, unsigned long, vstart, unsigned long, size,
		      unsigned int, free_slots_water)
__SYSCALL_CAP_DEFINE3(CNode, MMSCD_ExtendRTable, unsigned long, vstart, unsigned long, size,
		      unsigned int, free_slots_water)
__SYSCALL_CAP_DEFINE3(CNode, MMSCD_ExtendUTable, unsigned long, vstart, unsigned long, size,
		      unsigned int, free_slots_water)
__SYSCALL_CAP_DEFINE3(CNode, SpawnCNode,
		      unsigned long, flags,
		      struct sysarg_cnode_spawn_req *, spawn_req,
		      struct sysarg_cnode_spawn_res *, spawn_res)
__SYSCALL_CAP_DEFINE3(CNode, MMSCD_SpawnCNode,
		      unsigned long, flags,
		      struct mmscd_sysarg_cnode_spawn_req *, spawn_req,
		      struct sysarg_cnode_spawn_res *, spawn_res)
__SYSCALL_CAP_DEFINE0(CNode, Destroy)
__SYSCALL_CAP_DEFINE0(CNode, MMSCD_Destroy)

__SYSCALL_CAP_DEFINE3(CNode, Require, unsigned long, cnode_idx,
		      unsigned long, flags, rref_t *, result)
__SYSCALL_CAP_DEFINE6(CNode, Grant, rref_t, rref,  unsigned long, flags,
		      cref_t, cref, unsigned char, righs, unsigned long, args,
		      uref_t *, result)
__SYSCALL_CAP_DEFINE6(CNode, Export, unsigned int, cnode_idx,
		      unsigned long, flags, cref_t, cref, unsigned char, rights,
		      unsigned long, args, uref_t *, result)
__SYSCALL_CAP_DEFINE3(CNode, AcceptGrant, uref_t, uref, unsigned long, flags,
		      rref_t *, result)
__SYSCALL_CAP_DEFINE2(CNode, ProxyCall, rref_t, proxy_cnode,
		      unsigned long long, cref_invoke)

__SYSCALL_CAP_DEFINE1(CNode, Revoke, uref_t, uref)
__SYSCALL_CAP_DEFINE1(CNode, Reject, rref_t, rref)

__SYSCALL_CAP_DEFINE1(CNode, CRef, cref_t *, result)
__SYSCALL_CAP_DEFINE2(CNode, GrantMove, rref_t, new_rref, rref_t, old_rref)
__SYSCALL_CAP_DEFINE3(CNode, StatRRef, struct sysarg_cnode_statrref *, presult,
		      rref_t, rref, unsigned long, flags)
__SYSCALL_CAP_DEFINE3(CNode, StatURef, struct sysarg_cnode_staturef *, presult,
		      uref_t, uref, unsigned long, flags)
__SYSCALL_CAP_DEFINE2(CNode, ExportMove, rref_t, rref, unsigned int, cnode_idx)
__SYSCALL_CAP_DEFINE3(CNode, AcceptMove, rref_t, old_rref, unsigned long, flags,
		      rref_t *, result)

__SYSCALL_CAP_DEFINE2(CNode, SetCLimit, unsigned int, cap_type, int, new_limit)
__SYSCALL_CAP_DEFINE1(CNode, GetCLimit, struct sysarg_cnode_climit *, presult)
__SYSCALL_CAP_DEFINE2(CNode, Stat, unsigned long, flags, struct sysarg_cnode_stat *, presult)
__SYSCALL_CAP_DEFINE2(CNode, ReduceCapRights, cref_t, cref, __u8, rights)
__SYSCALL_CAP_DEFINE1(CNode, BindPermission, cref_t, permission_cref)
__SYSCALL_CAP_DEFINE0(CNode, UnBindPermission)
__SYSCALL_CAP_DEFINE3(CNode, SetPermission, cref_t, dst_permission,
		      cref_t, src_permission, __u64, permission)
__SYSCALL_CAP_DEFINE1(CNode, ExtFastcallBind, unsigned int, scno)
__SYSCALL_CAP_DEFINE1(CNode, ExtFastcallUnbind, unsigned int, scno)
__SYSCALL_CAP_DEFINE2(CNode, AuditContext, unsigned long, audit_operation, unsigned long, context_id)

__SYSCALL_CAP_DEFINE1(Scheduler, ThreadAttach, cref_t, thread_cref)
__SYSCALL_CAP_DEFINE1(Scheduler, Stat, struct scheduler_stat_s *, req)
__SYSCALL_CAP_DEFINE1(Thread, VSpaceOf, cref_t *, pref)
__SYSCALL_CAP_DEFINE1(Thread, Join, unsigned long long *, retval)
__SYSCALL_CAP_DEFINE1(Thread, SetCpu, unsigned int, cpu)
__SYSCALL_CAP_DEFINE1(Thread, GetCpu, unsigned int *, pcpu)
__SYSCALL_CAP_DEFINE1(Thread, SetRq, unsigned int, newrq)
__SYSCALL_CAP_DEFINE1(Thread, SetTickLess, _Bool, tickless)
__SYSCALL_CAP_DEFINE0(Thread, Suspend)
__SYSCALL_CAP_DEFINE0(Thread, Resume)
__SYSCALL_CAP_DEFINE1(Thread, HMSignalKill, unsigned int, signum)
__SYSCALL_CAP_DEFINE2(Thread, AttachCpuContext, cref_t, cpu_ctx_cref, unsigned int, type)
__SYSCALL_CAP_DEFINE2(Thread, DetachCpuContext, cref_t *, old_cpu_ctx_cref, unsigned int, type)
__SYSCALL_CAP_DEFINE2(Thread, Stat, struct sysarg_thread_stat *, presult, unsigned long, flags)
__SYSCALL_CAP_DEFINE2(Thread, SetName, const char *, uin, char *, uout)
__SYSCALL_CAP_DEFINE0(Thread, TriggerDetachOne)
__SYSCALL_CAP_DEFINE2(Thread, MiscdataRead, __u64 *, pv, unsigned long, miscdata_u)
__SYSCALL_CAP_DEFINE2(Thread, MiscdataWrite, unsigned long, v, unsigned long, miscdata_u)
__SYSCALL_CAP_DEFINE3(Thread, MiscdataReadv, void *, dest, unsigned long, sz, unsigned long, miscdata_u)
__SYSCALL_CAP_DEFINE3(Thread, MiscdataWritev, void *, data, unsigned long, sz, unsigned long, miscdata_u)
__SYSCALL_CAP_DEFINE5(Thread, MiscdataReadvCas, void *, dest, unsigned long, sz,
		      unsigned long, miscdata_u, unsigned long, expectval, unsigned long, newval)
__SYSCALL_CAP_DEFINE4(Thread, MiscdataWritevCas, void *, data, unsigned long, sz,
		      unsigned long, miscdata_u, unsigned long, expectval)
__SYSCALL_CAP_DEFINE1(Thread, ExtFastcallBind, unsigned int, scno)
__SYSCALL_CAP_DEFINE1(Thread, ExtFastcallUnbind, unsigned int, scno)
__SYSCALL_CAP_DEFINE1(Thread, AvailableExtFastcall, __u32 *, presult)

__SYSCALL_CAP_DEFINE2(PMEM, Stat, struct sysarg_pmem_stat *, presult, unsigned long, flags)
__SYSCALL_CAP_DEFINE5(VSpace, Map,
		      unsigned long, vstart, unsigned long, vend,
		      struct sysarg_vspace_map_pages *, pg_args,
		      unsigned long long, hint,
		      struct sysarg_vspace_map_pages *, pg_res)
__SYSCALL_CAP_DEFINE4(VSpace, MMSCD_MapKShare, unsigned long, dst_vstart,
		      unsigned long, src_vstart, unsigned long, nrpages,
		      unsigned long long, hint)
__SYSCALL_CAP_DEFINE3(VSpace, ReMapOnePage,
		      unsigned long, dst_vstart,
		      unsigned long, src_vstart,
		      unsigned long long, hint)
__SYSCALL_CAP_DEFINE5(VSpace, MMSCD_PreparePgTable,
		      __u64, hint, unsigned long, vstart, unsigned long, vend,
		      struct sysarg_vspace_pages *, pt_args,
		      struct sysarg_vspace_pages *, pt_res)
__SYSCALL_CAP_DEFINE5(VSpace, CreateMasterArea,
		      unsigned long, vstart, unsigned long, vend,
		      unsigned long long, hint,
		      struct sysarg_vspace_pages *, pt_args,
		      struct sysarg_vspace_pages *, pt_res)
__SYSCALL_CAP_DEFINE7(VSpace, MapPfnRange,
		      unsigned long, vstart, unsigned long, vend,
		      struct sysarg_vspace_map *, pg_args,
		      struct sysarg_vspace_map *, pt_args,
		      unsigned long long, hint,
		      struct sysarg_vspace_map *, pg_res,
		      struct sysarg_vspace_map *, pt_res)
__SYSCALL_CAP_DEFINE3(VSpace, ReMapOnePfn,
		      unsigned long, vstart,
		      unsigned long long, pfn,
		      unsigned long long, hint)
__SYSCALL_CAP_DEFINE5(VSpace, PreparePgTable,
		      __u64, hint, unsigned long, vstart, unsigned long, vend,
		      struct sysarg_vspace_map *, pt_args,
		      struct sysarg_vspace_map *, pt_res)
__SYSCALL_CAP_DEFINE3(VSpace, UnMap, unsigned long, vstart, unsigned long, vend,
		      struct sysarg_vspace_unmap *, res)
__SYSCALL_CAP_DEFINE3(VSpace, MMSCD_UnMap, unsigned long, vstart,
		      unsigned long, vend, struct sysarg_vspace_unmap *, res)
__SYSCALL_CAP_DEFINE3(VSpace, Shrink, unsigned long, vstart, unsigned long, vend,
		      struct sysarg_vspace_shrink *, res)
__SYSCALL_CAP_DEFINE3(VSpace, MMSCD_Shrink, unsigned long, vstart, unsigned long, vend,
		      struct sysarg_vspace_shrink *, res)
__SYSCALL_CAP_DEFINE3(VSpace, Scan, unsigned long, vstart, unsigned long, vend,
		      struct sysarg_vspace_range *, res)
__SYSCALL_CAP_DEFINE4(VSpace, MProtect, unsigned long long, hint,
		      unsigned long, vstart, unsigned long, vend,
		      unsigned long, flags)
__SYSCALL_CAP_DEFINE4(VSpace, MMSCD_MProtect, unsigned long long, hint,
		      unsigned long, vstart, unsigned long, vend,
		      unsigned long, flags)
__SYSCALL_CAP_DEFINE4(VSpace, WriteTo, void *, dst, void *, src,
		      unsigned long, size, unsigned long, flags)
__SYSCALL_CAP_DEFINE4(VSpace, ReadFrom, void *, src, void *, dst,
		      unsigned long, size, unsigned long, flags)
__SYSCALL_CAP_DEFINE3(VSpace, FlushCache, unsigned int, cmd,
		      unsigned long, vstart, unsigned long, vend)
__SYSCALL_CAP_DEFINE4(VSpace, MapKShare, unsigned long, vstart,
		      unsigned long long, pfn, unsigned long, nrpfn,
		      unsigned long long, hint)
__SYSCALL_CAP_DEFINE3(VSpace, Transfer, unsigned long, vstart,
		      unsigned long, nrpage, unsigned int, page_type)
__SYSCALL_CAP_DEFINE3(VSpace, Move, unsigned long, src_vstart,
		      unsigned long, dst_vstart, unsigned long, nrpage)
__SYSCALL_CAP_DEFINE2(VSpace, FutexWake, const int *, uaddr, unsigned int, num)
__SYSCALL_CAP_DEFINE4(Channel, MsgReceive, void *, revc_buf, unsigned long, recv_len,
		      struct sysarg_msginfo *, msginfo, int, timeout)
__SYSCALL_CAP_DEFINE2(Channel, MsgNotify, void *, buf, unsigned long, len)

__SYSCALL_CAP_DEFINE0(SysCtrl, PowerOff)
__SYSCALL_CAP_DEFINE1(SysCtrl, Reboot, unsigned int, reboot_type)
__SYSCALL_CAP_DEFINE1(SysCtrl, StopMachine, __cpuset_t *, set)
__SYSCALL_CAP_DEFINE0(SysCtrl, ResumeMachine)
__SYSCALL_CAP_DEFINE1(SysCtrl, CpuUp, unsigned int, cpuid)
__SYSCALL_CAP_DEFINE1(SysCtrl, CpuOff, unsigned int, flag)
__SYSCALL_CAP_DEFINE2(SysCtrl, CpuAffinity, unsigned int, cpuid, unsigned int *, affinity_info)
__SYSCALL_CAP_DEFINE1(SysCtrl, PmSuspend, unsigned int, index)
__SYSCALL_CAP_DEFINE2(SysCtrl, PmCpuDown, unsigned int, target_cpu, unsigned int, flag)
__SYSCALL_CAP_DEFINE3(SysCtrl, LoadDTB, void *, buf,
		      unsigned long, size,
		      unsigned long, offset)
__SYSCALL_CAP_DEFINE4(SysCtrl, ReadDTB, const char *, path,
		      unsigned long, path_len, void *, buf,
		      unsigned long, buf_size)
__SYSCALL_CAP_DEFINE3(SysCtrl, ReadConf, unsigned int, type, void *, buf,
		      unsigned long, buflen)
__SYSCALL_CAP_DEFINE2(SysCtrl, GetTRNG, void *, buf, unsigned int, buflen)
__SYSCALL_CAP_DEFINE2(SysCtrl, Debug, unsigned int, cmd, void *, arg)
__SYSCALL_CAP_DEFINE2(SysCtrl, GetCpuStat, __cpuset_t *, set,
		      struct __sysctrl_cpu_stat *, cpu_stat)
__SYSCALL_CAP_DEFINE1(SysCtrl, SetTockReal, __u64, tock_real)
__SYSCALL_CAP_DEFINE1(SysCtrl, SetTockPolicy, struct vtimekeep_tock_policy *, tock_policy)
__SYSCALL_CAP_DEFINE2(SysCtrl, SetKlogportLevel, unsigned long, type_flags, unsigned int, level)
__SYSCALL_CAP_DEFINE3(SysCtrl, KevSetBlockInfo, unsigned int, type,
		      cref_t, vspace_cref, void *, uaddr)
__SYSCALL_CAP_DEFINE2(SysCtrl, KevSetEnable, const char *, event_name, unsigned int, enable)
__SYSCALL_CAP_DEFINE2(SysCtrl, KevSetFilter, const char *, event_name, const char *, event_filter)
__SYSCALL_CAP_DEFINE2(SysCtrl, KevSetWater, unsigned int, user_index, unsigned long long, user_water)
__SYSCALL_CAP_DEFINE4(SysCtrl, KevReadData, const void *, user_args, unsigned long, user_args_len,
		      void *, user_ret, unsigned long, user_ret_len)
__SYSCALL_CAP_DEFINE1(SysCtrl, KevReadEventNumber, unsigned int *, event_number)
__SYSCALL_CAP_DEFINE2(SysCtrl, KevReadEventConfig, unsigned int, event_type,
		      struct __sysctrl_kev_config *, event_config)
__SYSCALL_CAP_DEFINE4(SysCtrl, RespartCtrl,
		      const struct __res_partition_info_s *, part_info,
		      unsigned int, cmd, void *, user_args, unsigned long, user_args_len)
__SYSCALL_CAP_DEFINE3(SysCtrl, KShare, unsigned int, kshare_type,
		      unsigned long long, pfn, unsigned long, nrpfn)
__SYSCALL_CAP_DEFINE2(SysCtrl, KUnShare, unsigned long long, pfn, unsigned long, nrpfn)
__SYSCALL_CAP_DEFINE1(SysCtrl, GetRootfsInfo, struct __sysctrl_rootfs_va_size *, info)
__SYSCALL_CAP_DEFINE3(SysCtrl, InjectRasError, unsigned int, cmd,
		      unsigned long, param1, unsigned long, param2)
__SYSCALL_CAP_DEFINE4(SysCtrl, ScanMemRange, struct __page_range *, res,
		      unsigned long long, pfn_start, unsigned long long, pfn_end,
		      unsigned long, query_bits)
__SYSCALL_CAP_DEFINE2(SysCtrl, UpdateRsvMemRange, unsigned long long, pfn_start,
		      unsigned long long *, p_pfn_end)
/* for owner */
__SYSCALL_CAP_DEFINE4(IrqCtrl, Info, char *, name, unsigned int, name_len,
		      unsigned int *, ctrl_id, unsigned int *, max_logic_irqs)
__SYSCALL_CAP_DEFINE4(IrqCtrl, ToLogic, const __u32 *, hwconf, unsigned int, hwconf_len,
		      unsigned int, cpuid, __u32 *, logic_irq)
/*
 * See kernel/include/mapi/uapi/hmkernel/capability/captype_irqctrl.h,
 * Once a logic irq is assigned, it is used by owner of irqctrl
 * and never released.
 */
__SYSCALL_CAP_DEFINE1(IrqCtrl, Assign, unsigned int, logic_irq)

/* for user */
__SYSCALL_CAP_DEFINE3(IrqCtrl, Register, unsigned int, logic_irq,
		      struct sysarg_irqctrl_register *, config,
		      cref_t, tcb)
__SYSCALL_CAP_DEFINE1(IrqCtrl, UnRegister, unsigned int, logic_irq)
__SYSCALL_CAP_DEFINE1(IrqCtrl, Enable, unsigned int, logic_irq)
__SYSCALL_CAP_DEFINE1(IrqCtrl, Disable, unsigned int, logic_irq)
__SYSCALL_CAP_DEFINE3(IrqCtrl, Config, unsigned int, logic_irq,
		      __u32 *, hwconf, unsigned int, hwconf_len)
__SYSCALL_CAP_DEFINE3(IrqCtrl, SetAttribute, unsigned int, logic_irq,
		      const struct sysarg_irqctrl_attribute *, __attr,
		      unsigned int, flag);
/* special user */
__SYSCALL_CAP_DEFINE4(IrqCtrl, SGI, unsigned int, logic_irq,
		      __cpuset_t *, target_set, void *, user_args,
		      unsigned int, user_args_len)
__SYSCALL_CAP_DEFINE4(IrqCtrl, Ioctl, unsigned int, logic_irq, unsigned int, cmd,
		      const void *, user_args, unsigned long, user_args_len)
__SYSCALL_CAP_DEFINE2(IrqCtrl, Stat, unsigned int, logic_irq,
		      struct sysarg_irqctrl_stat *, __stat)

__SYSCALL_CAP_DEFINE0(IrqCtrl, Suspend)
__SYSCALL_CAP_DEFINE0(IrqCtrl, Resume)
__SYSCALL_CAP_DEFINE2(IrqCtrl, SetWake, unsigned int, logic_irq,
		      unsigned int, flag)

__SYSCALL_CAP_DEFINE5(CpuContext, Config, unsigned long, cmd,
		      void *, config, unsigned long, config_size,
		      void *, result, unsigned long, result_size)
__SYSCALL_CAP_DEFINE1(CpuContext, AttachCPU, unsigned int, cpu)
__SYSCALL_CAP_DEFINE0(CpuContext, DetachCPU)
__SYSCALL_CAP_DEFINE1(VM, GetIORegNum, unsigned int *, _ioregs_count)
__SYSCALL_CAP_DEFINE5(VM, GetIORegs, unsigned int, ioregs_count,
		      __u64 *, _pregs, __u64 *, _vregs, __u8 *, _is_normal, __u8 *, _mem_prot)
__SYSCALL_CAP_DEFINE3(VM, RegisterIOReg, unsigned long, reg_uvmm_hva,
		      unsigned long, reg_gpa, unsigned long, size)
__SYSCALL_CAP_DEFINE1(VM, BindVcpuListener, unsigned int, vcpu_id)
__SYSCALL_CAP_DEFINE1(VM, CreateVnotify, struct sysarg_vm_vnotify_info *, conf)
__SYSCALL_CAP_DEFINE1(VM, VnotifyCreateChannel, struct __vnotify_args_s *, _args)
__SYSCALL_CAP_DEFINE1(VM, VnotifyDestroyChannel, unsigned int, chn_id)
__SYSCALL_CAP_DEFINE3(VM, VnotifyConfig, unsigned long, cmd, const void *, uconfig,
		      unsigned long, config_size)
__SYSCALL_CAP_DEFINE1(VM, GetNumVcpus, __u32 *, _pnum_vcpus)
__SYSCALL_CAP_DEFINE6(VM, VperfctxConfig, unsigned int, vcpu_id,
		      unsigned long, cmd,
		      void *, config, unsigned long, config_size,
		      void *, result, unsigned long, result_size)
__SYSCALL_CAP_DEFINE1(VM, VperfctxAttach, unsigned int, vcpu_id)
__SYSCALL_CAP_DEFINE1(VM, VperfctxDetach, unsigned int, vcpu_id)
__SYSCALL_CAP_DEFINE3(VM, RegisterMMIORegion, unsigned long, addr,
		      unsigned long, size, unsigned int, type)
__SYSCALL_CAP_DEFINE3(VM, BindVcpuMMIODispatcher, unsigned int, mr_idx,
		      unsigned int, vcpu_id, const void *, data)
__SYSCALL_CAP_DEFINE3(VM, AssertIrq, unsigned int, vcpu_id,
		      unsigned int, irq_id, unsigned int, level)

__SYSCALL_CAP_DEFINE2(Timer, Cancel, __u64 *, rem_value, __u64 *, old_interval)
__SYSCALL_CAP_DEFINE2(Timer, Remain, __u64 *, rem_value, __u64 *, interval)
__SYSCALL_CAP_DEFINE1(Timer, OverrunCount, __u64 *, count)
__SYSCALL_CAP_DEFINE5(Timer, Start, cref_t, target, struct __siginfo *, siginfo,
		      int, flags, unsigned long long, value, unsigned long long, interval)
__SYSCALL_CAP_DEFINE0(Module, BindModif)
__SYSCALL_CAP_DEFINE0(Module, UnbindModif)
__SYSCALL_CAP_DEFINE5(Module, Ioctl, unsigned long, cmd,
		      void *, args, unsigned long, args_size,
		      void *, result, unsigned long, result_size)
__SYSCALL_CAP_DEFINE2(Module, Info, char *, name, unsigned int, name_len)

__SYSCALL_CAP_DEFINE2(Activation, Init, void *, entry,
		      unsigned long, uarg)

__SYSCALL_CAP_DEFINE0(Activation, Ready)
__SYSCALL_CAP_DEFINE0(Activation, Recycle)
__SYSCALL_CAP_DEFINE0(Activation, Kill)

__SYSCALL_CAP_DEFINE2(Activation, LoadLastUctx,
		      struct arch_uctx *, uctx_buf,
		      cref_t, permission_cref)

__SYSCALL_CAP_DEFINE2(Activation, StoreLastUctx,
		      struct arch_uctx *, uctx_buf,
		      cref_t, permission_cref)
__SYSCALL_CAP_DEFINE2(Activation, HMSignalMask, struct __hmsigmask *, uin,
		      struct __hmsigmask *, uout)
__SYSCALL_CAP_DEFINE0(Activation, TriggerDetachOne)
__SYSCALL_CAP_DEFINE1(Activation, AvailableExtFastcall, __u32 *, presult)
__SYSCALL_CAP_DEFINE2(Activation, InstallElambdaExtension,
		      unsigned int, extension_id,
		      void *, args)
__SYSCALL_CAP_DEFINE1(Activation, UninstallElambdaExtension,
		      unsigned int, extension_id)

__SYSCALL_CAP_DEFINE1(Activation, AttachFpuContext,
		      cref_t, fpuctx_cref)

__SYSCALL_CAP_DEFINE1(Activation, DetachFpuContext,
		      cref_t *, old_fpuctx_cref)

__SYSCALL_CAP_DEFINE4(ActivationPool, Call, unsigned long long, rpc_info,
		      void *, send_buf, void *, rply_buf,
		      unsigned long, rply_buf_sz)
__SYSCALL_CAP_DEFINE0(ActivationPool, KillOne)
__SYSCALL_CAP_DEFINE1(ActivationPool, Listen, int, retval)
__SYSCALL_CAP_DEFINE1(ActivationPool, NoBufCall, unsigned long long, rpc_info)
__SYSCALL_CAP_DEFINE2(ActivationPool, SendBufCall, unsigned long long, rpc_info,
		      void *, send_buf)
__SYSCALL_CAP_DEFINE2(ActivationPool, RetBufCall, unsigned long long, rpc_info,
		      void *, ret_buf)
__SYSCALL_CAP_DEFINE3(ActivationPool, Bind,
		      cref_t, bind_to,
		      unsigned int, tgt_bind_point,
		      unsigned long, flags)
__SYSCALL_CAP_DEFINE1(ActivationPool, ListenWater, int, retval)
__SYSCALL_CAP_DEFINE1(ActivationPool, CheckWater,
		      struct __actv_pool_water_trigger_info *, p_info)
__SYSCALL_CAP_DEFINE2(ActivationPool, SetWater, struct __actv_pool_water *, actv_water,
		      unsigned long, flags)

__SYSCALL_CAP_DEFINE3(ActivationPool, SetCredential,
		      uref_t, actv_pool_uref,
		      unsigned int, dst_cnode_idx,
		      unsigned long, credential)

__SYSCALL_CAP_DEFINE3(ActivationPool, EmrgInit,
		      const void *, entry, unsigned long, uarg, int *, futex_addr)

__SYSCALL_CAP_DEFINE2(Thread, KvicSourceBind, unsigned int, source_id, unsigned int, flags)
__SYSCALL_CAP_DEFINE1(Thread, KvicSourceUnbind, unsigned int, source_id)
__SYSCALL_CAP_DEFINE2(Thread, KvicKevSourceBind, unsigned int, source_id, unsigned int, flags)
__SYSCALL_CAP_DEFINE1(Thread, KvicKevSourceUnbind, unsigned int, source_id)

#ifndef __UAPI_COMPAT__
__SYSCALL_CAP_DEFINE0(ActivationPool, ReservedCall1)
__SYSCALL_CAP_DEFINE0(ActivationPool, ReservedCall2)
__SYSCALL_CAP_DEFINE0(ActivationPool, ReservedCall3)
__SYSCALL_CAP_DEFINE0(ActivationPool, ReservedCall4)
#else
__SYSCALL_CAP_DEFINE4(ActivationPool, CompatCall, unsigned long long, rpc_info,
		      void *, send_buf, void *, rply_buf,
		      unsigned long, rply_buf_sz)
__SYSCALL_CAP_DEFINE1(ActivationPool, CompatNoBufCall, unsigned long long, rpc_info)
__SYSCALL_CAP_DEFINE2(ActivationPool, CompatSendBufCall, unsigned long long, rpc_info,
		      void *, send_buf)
__SYSCALL_CAP_DEFINE2(ActivationPool, CompatRetBufCall, unsigned long long, rpc_info,
		      void *, ret_buf)
#endif /* __UAPI_COMPAT__ */

__SYSCALL_CAP_DEFINE1(Permission, Stat, __u64 *, permission)

/* survive the stupid code checker */
#undef ULIBS_INCLUDE_HONGMENG_CAP_SYSCALL_LIST_H
#endif
