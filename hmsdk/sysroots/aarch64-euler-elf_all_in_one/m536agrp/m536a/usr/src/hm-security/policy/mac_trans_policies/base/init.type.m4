INCLUDE(`builtin.m4')
TYPE_ADD_ATTRIBUTES((init), (subject_type, executable_type, access_system_services))
TYPE_ADD_ATTRIBUTES((init), (activation_pool_service))
COMMENT inherit from hguard for setting priority of hguard threads
TYPE_ADD_ATTRIBUTES((init), (sched_native_service))

TE_POLICY(T(init), T(devmgr), (spawn))
TE_POLICY(T(init), T(sec_shm), (shm_acquire))
TE_POLICY(T(init), T(sysmgr2init_shm), (shm_acquire, shm_destroy))
TE_POLICY(T(init), T(vfs), (spawn))
TE_POLICY(T(init), T(devfs), (addname, mknod))
TE_POLICY(T(init), T(dev_binder), (mknod))
TE_POLICY(T(init), T(initrd), (addname))
TE_POLICY(T(init), T(bin_dir), (addname))
TE_POLICY(T(init), T(proc_mnt), (fread))
TE_POLICY(T(init), A(mount_point), (fread, fexec, umount))
COMMENT set label to /bin/vfs.elf when init filesystems
TE_POLICY(T(init), T(init), (setlabel))
TE_POLICY(T(init), T(dev_shm), (mknod))
TE_POLICY(T(init), T(dev_kmsg), (mknod))
TE_POLICY(T(init), T(tppmgr), (spawn))
TE_POLICY(T(init), T(cpiofs), (spawn))
TE_POLICY(T(init), T(lwipd), (spawn))
TE_POLICY(T(init), T(crypto), (spawn))
TE_POLICY(T(init), T(tmp_dir), (umount))

TE_POLICY(T(init), A(subject_type), (signal))
TE_POLICY(T(init), A(executable_type), (fexec))
TE_POLICY(T(init), T(dev_tty), (fread, fwrite, getfileattr))

COMMENT inherit from hguard
COMMENT acquire guardmgr for sysif
TE_POLICY(T(init), T(guardmgr), (path_acquire))
COMMENT have wtd_mod for hguard threads
TE_POLICY(T(init), T(wtd_mod), (mod_grant))
COMMENT vfs and sysmgr for procfs shm
TE_POLICY(T(init), T(vfs), (path_acquire, shm_acquire, mp_acquire))
TE_POLICY(T(init), T(sysmgr), (path_acquire, shm_acquire, mp_acquire, shm_destroy, mp_destroy))
COMMENT When hguard-watchdog stops watchdog, it attempts a normal shutdown
COMMENT via hm_reboot which will acquire tppmgr
TE_POLICY(T(init), T(tppmgr), (path_acquire))
COMMENT capset for hguard to specify the capability of forked user service processes
TE_POLICY(T(init), T(init), (capset))

COMMENT sched_admin is for init to switch loadbalance
ABILITY_POLICY(T(init), devmgr_mgmt, mount, sysconf_kernel, cperm_sched_admin, cperm_klog)
COMMENT reboot is for init to run the system shutdown/reboot flow
ABILITY_POLICY(T(init), reboot)
COMMENT cpuctrl is for init to force shutdown system when reboot vsyscall[tppmgr] failed or timeout
ABILITY_POLICY(T(init), cpuctrl)
COMMENT watchdog configuration for init
ABILITY_POLICY(T(init), cperm_watchdog)
COMMENT inherit from hguard
COMMENT sysguard for accessing guardmgr
ABILITY_POLICY(T(init), sysguard, procfs, procfsmgr_access)
ABILITY_POLICY(T(init), privileged_affinity)
COMMENT setexeccon to support hguard spawn a child shell as init_t
ABILITY_POLICY(T(init), setexeccon)
COMMENT init can promote priority
ABILITY_POLICY(T(init), rlimit_rtprio, rlimit_nice)
COMMENT init_notify for system services to notify init that
COMMENT their startup has completed after init starts them
ABILITY_POLICY(A(system_service_type), init_notify)
COMMENT setuid/gid for hguard to specify the uid/gid of user service processes
COMMENT according to their configuration file
ABILITY_POLICY(T(init), setuid, setgid)

DEF_FILE_OBJECT(init, ``init.elf'')

TRANSITION(init, tppmgr_exec, spawn, tppmgr)
TRANSITION(init, vfs_exec, spawn, vfs)
TRANSITION(init, cpiofs_exec, spawn, cpiofs)
TRANSITION(init, devmgr_exec, spawn, devmgr)
TRANSITION(init, lwipd_exec, spawn, lwipd)
TRANSITION(init, crypto_exec, spawn, crypto)
TRANSITION(init, vm_exec, spawn, vm)
TE_POLICY(T(init), T(vm), (spawn))
