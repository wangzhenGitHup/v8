TYPE_ADD_ATTRIBUTES((lwipd), (subject_type, stdio))
TYPE_ADD_ATTRIBUTES((lwipd), (sched_native_service))
TYPE_ADD_ATTRIBUTES((lwipd), (activation_pool_service))
TYPE_ADD_ATTRIBUTES((lwipd), (system_service_type))
TYPE_ADD_ATTRIBUTES((lwipd_exec), (executable_type))
TE_POLICY(T(lwipd), T(devmgr), (path_acquire))
TE_POLICY(T(lwipd), T(devhost), (path_acquire))
COMMENT vsock implements need to visit actv-handler of uvmm
TE_POLICY(T(lwipd), T(vm), (path_acquire))
TE_POLICY(T(lwipd), T(vfs), (path_acquire))
TE_POLICY(T(lwipd), T(devfs), (fwrite, fappend))
TE_POLICY(T(lwipd), T(procfs), (fwrite))
TE_POLICY(T(lwipd), T(vfs), (shm_acquire, mp_acquire))
TE_POLICY(T(lwipd), T(sec_shm), (shm_acquire))
TE_POLICY(T(lwipd), T(lwipd), (spawn))
TE_POLICY(T(lwipd), T(dev_shm), (addname))
TE_POLICY(T(lwipd), T(dev_shm), (fexec))
TE_POLICY(T(lwipd), T(lwipd_exec), (fexec))
TE_POLICY(T(lwipd), T(sysmgr), (path_acquire))
TE_POLICY(T(lwipd), T(init), (path_acquire))
TE_POLICY(T(lwipd), T(dev_uio), (fread))
TE_POLICY(T(lwipd), T(tmp_dir), (addname))
COMMENT vhost user implements need map vm's memory and need iomem_mmap ability
COMMENT vhost user implements need vm_vhost ability
ABILITY_POLICY(T(lwipd), devmgr_hmnetd,
	       devhost_net_prepare, netd, irq, sysconf, sysfs, procfs,
	       cperm_pmem_stat_paddr, cperm_actv_rw_caller_vm,
	       devhost_net_vlan_getmaster, procfsmgr_access, cperm_klog, iomem_mmap,
	       vm_vhost)
DEF_FILE_OBJECT(lwipd_exec, ``/bin/hmnetd.elf'')
DEF_FILE_OBJECT(lwipd, ``path:hmnetd_ch'')
DEF_FILE_OBJECT(lwipd, ``path:hmnetd_cfg_ch'')
DEF_FILE_OBJECT(lwipd, ``path:net_tcpip_ch'')
TRANSITION(lwipd, lwipd_exec, spawn, lwipd)
