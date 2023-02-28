TYPE_ADD_ATTRIBUTES((devhost_exec), (executable_type))
TYPE_ADD_ATTRIBUTES((devhost), (subject_type))
TYPE_ADD_ATTRIBUTES((devhost), (sched_native_service))
TYPE_ADD_ATTRIBUTES((devhost), (activation_pool_service))
TYPE_ADD_ATTRIBUTES((devhost), (system_service_type))
TE_POLICY(T(devhost), A(killed_by_ctrl_c), (signal))
TE_POLICY(T(devhost), T(sysmgr), (path_acquire))
TE_POLICY(T(devhost), T(devmgr), (path_acquire, shm_acquire, mp_acquire))
TE_POLICY(T(devhost), T(vfs), (path_acquire, shm_acquire, mp_acquire))
TE_POLICY(T(devhost), T(lwipd), (path_acquire))
TE_POLICY(T(devhost), T(tppmgr), (path_acquire))
TE_POLICY(T(devhost), T(crypto), (path_acquire))
TE_POLICY(T(devhost), T(keymgr), (path_acquire))
TE_POLICY(T(devhost), T(devhost), (fread, getfileattr, fexec, mknod, addname, fwrite, delname))
TE_POLICY(T(devhost), T(sys_dev), (mknod, unlink))
TE_POLICY(T(devhost), T(unlabeled), (mknod, unlink))
TE_POLICY(T(devhost), T(sec_shm), (shm_acquire))
TE_POLICY(T(devhost), T(atfd_mod), (mod_grant))
ABILITY_POLICY(T(devhost), irq, devmgr, devhost_rpc_invoke,
	       cperm_actv_rw_caller_vm, iomem_mmap, sysconf_kernel,
	       wakelock, procfs, sysfs, net_dev, cpuctx_timer, cperm_pmem_stat_paddr,
	       kbox_user, procfsmgr_access, cperm_klog, cperm_kconsole, cperm_sched_preempt,
	       reboot, vnotify_create_achn, devmgr_mgmt)
ABILITY_POLICY(T(devhost), privileged_affinity)
COMMENT devhost need settime and sys_time ablity to syn rtc time to sys
ABILITY_POLICY(T(devhost), settime, sys_time)
MEM_RANGE(T(devhost), (1, 15), (15, 48), (1024, 2038), (2038, 4096))
DEF_FILE_OBJECT(devhost_exec, ``/bin/devhost.elf'')
DEF_FILE_OBJECT(devhost, ``path:devhost'')
