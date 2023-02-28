TYPE_ADD_ATTRIBUTES((vfs), (subject_type))
TYPE_ADD_ATTRIBUTES((vfs), (activation_pool_service))
TYPE_ADD_ATTRIBUTES((vfs), (system_service_type))
TYPE_ADD_ATTRIBUTES((vfs_exec), (executable_type))
TE_POLICY(T(vfs), A(mount_point), (umount))
TE_POLICY(T(vfs), T(sysfs), (mknod))
TE_POLICY(T(vfs), T(unlabeled), (mknod))
TE_POLICY(T(vfs), T(devmgr), (path_acquire, shm_acquire, mp_acquire))
TE_POLICY(T(vfs), T(lwipd), (path_acquire, shm_acquire, mp_acquire))
TE_POLICY(T(vfs), T(tppmgr), (path_acquire))
COMMENT for random procfs entries
TE_POLICY(T(vfs), T(crypto), (path_acquire))
TE_POLICY(T(vfs), T(init), (path_acquire))
TE_POLICY(T(vfs), T(cpiofs), (shm_acquire))
TE_POLICY(T(vfs), T(vfs), (spawn))
TE_POLICY(T(vfs), T(vfs_exec), (fexec))
TE_POLICY(T(vfs), T(sec_shm), (shm_acquire))
TE_POLICY(T(vfs), T(sysmgr), (shm_destroy, mp_destroy, path_acquire))
TE_POLICY(T(vfs), T(rootfs_shm), (shm_acquire))
TE_POLICY(T(vfs), T(devfs), (addname))
TE_POLICY(T(vfs), T(dev_ashmem), (mknod))
TE_POLICY(T(vfs), T(dev_binder), (mknod))
TE_POLICY(T(vfs), T(devhost), (shm_acquire))
TE_POLICY(T(vfs), T(sysmgr2vfs_shm), (shm_acquire, shm_destroy))
TE_POLICY(T(vfs), T(dev_ubifs_ctrl), (getfileattr))
COMMENT transfer the permission on share memory to a process
TE_POLICY(T(vfs), T(devhost), (shm_trans_grant_to))
TE_POLICY(T(vfs), T(crypto), (shm_trans_grant_to))
COMMENT vfs need cperm_kev_klog to listen the kev klog and implement the kmsg epoll
ABILITY_POLICY(T(vfs), devmgr_fops, devmgr_fops_sysfs, devhost_fops, devhost_fops_sysfs, sysmgr_sysfs,
	       procfsmgr_access, resmgr_resmgrfs, sysconf_kernel, stat, net_fs,
	       guard_fs, kev, kevctrl, cperm_actv_rw_caller_vm, getprocfd,
	       devhost_fops_mmap, inotify, fanotify, rlimit, iomem_mmap, cperm_klog, cperm_kev_klog)
COMMENT set thread priority when init
ABILITY_POLICY(T(vfs), cperm_sched_native_service)
COMMENT a workaround for calling wakelock or suspend. should be moved to sysfs later
ABILITY_POLICY(T(vfs), pwrmgr_sysfs, wakelock, suspend_system)
DEF_FILE_OBJECT(vfs_exec, ``vfs.elf'')
DEF_FILE_OBJECT(vfs_exec, ``/bin/vfs.elf'')
DEF_FILE_OBJECT(vfs, ``path:fsmgr'')
DEF_FILE_OBJECT(vfs, ``path:fsmgr-actv'')
DEF_FILE_OBJECT(vfs, ``path:fs-procfs'')
DEF_FILE_OBJECT(vfs, ``path:fs-procfs-actv'')
DEF_FILE_OBJECT(vfs, ``path:fs-sysfs'')
DEF_FILE_OBJECT(vfs, ``path:fs-sysfs-actv'')
DEF_FILE_OBJECT(vfs, ``path:fs-?'')
DEF_FILE_OBJECT(vfs, ``path:fs-?-actv'')
DEF_FILE_OBJECT(vfs, ``path:fs-??'')
DEF_FILE_OBJECT(vfs, ``path:fs-??-actv'')
DEF_FILE_OBJECT(vfs, ``path:fs-???'')
DEF_FILE_OBJECT(vfs, ``path:fs-???-actv'')
DEF_FILE_OBJECT(vfs, ``path:fs-????'')
DEF_FILE_OBJECT(vfs, ``path:fs-????-actv'')
DEF_FILE_OBJECT(vfs, ``path:fs-?????'')
DEF_FILE_OBJECT(vfs, ``path:fs-?????-actv'')
TRANSITION(vfs, vfs_exec, spawn, vfs)
