INCLUDE(`builtin.m4')

TYPE_ADD_ATTRIBUTES((appdef), (subject_type, access_system_services, killed_by_ctrl_c, executable_type))
TE_POLICY(T(appdef), A(basic_dir), (addname, delname, mknod))
TE_POLICY(A(subject_type), T(appdef), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(appdef), A(device_node), (BUILTIN_FILE_EXEC, BUILTIN_FILE_READ, fwrite, setfileattr, link))
TE_POLICY(T(appdef), A(procfs_info), (BUILTIN_FILE_EXEC, BUILTIN_FILE_READ, fwrite, setfileattr, link))
TE_POLICY(T(appdef), A(sysfs_nodes), (BUILTIN_FILE_EXEC, BUILTIN_FILE_READ, fwrite, setfileattr, link))

COMMENT appdef can capset itself
TE_POLICY(T(appdef), T(appdef), (capset))


TYPE_ADD_ATTRIBUTES((appdef_devnode), (device_directory))
TE_POLICY(T(appdef), T(appdef_devnode), (BUILTIN_FILE_EXEC, BUILTIN_FILE_READ, BUILTIN_FILE_WRITE))
TE_POLICY(T(appdef), T(appdef_procnode), (BUILTIN_FILE_EXEC, BUILTIN_FILE_READ, BUILTIN_FILE_WRITE))
TE_POLICY(T(appdef), T(appdef_sysnode), (BUILTIN_FILE_EXEC, BUILTIN_FILE_READ, BUILTIN_FILE_WRITE))

COMMENT hminit can getlabel, query cnode idx
COMMENT hminit need devmgr_mgmt, net_admin, raw_socket to use network service
COMMENT hminit need stat to operate sysdump
COMMENT ABILITY_POLICY1(T(appdef), devmgr_mgmt, mount, getlabel, net_admin, raw_socket, stat)
COMMENT ab_stat for sysdump, kev and kevctrl for hmesg
COMMENT ABILITY_POLICY1(T(appdef), reboot, settime, sys_time, kev, kevctrl, iomem_mmap, kbox_user, kbox_admin, hostname, klogport, tty, serial_toggle)
ABILITY_HIERACHY_POLICY(T(appdef), ``/secadmin/*'', ``/posixcap/*'', ``/auditadmin/*'', ``/devel/perf/*'', ``/uvmm/*'')

ABILITY_HIERACHY_POLICY(T(appdef), ``/sysadmin/getconf'', ``/sysadmin/stat/*'', ``/sysadmin/reboot'', ``/sysadmin/dev/*'', ``/sysadmin/kev'', ``/sysadmin/coredump/*'', ``/sysadmin/services/*'')

COMMMENT separate kbox_user, kbox_admin from appdef
ABILITY_HIERACHY_POLICY(T(appdef), ``/sysadmin/dfx/dynlog'', ``/sysadmin/dfx/dumpshm'')

ABILITY_POLICY(T(appdef), getprocfd)
TE_POLICY(T(appdef), T(sec_shm), (shm_acquire))
TE_POLICY(T(appdef), T(dev_shm), (BUILTIN_FILE_EXEC, BUILTIN_FILE_READ, BUILTIN_FILE_WRITE))

COMMENT execute hmtrace
TRANSITION(appdef, hmtrace_exec, spawn, hmtrace)
TE_POLICY(T(hmtrace), T(appdef), (BUILTIN_FILE_WRITE))
TYPE_ADD_ATTRIBUTES((appdef), (hmtrace_basic_policy))

COMMENT execute hguardctl
TRANSITION(appdef, hguardctl_exec, spawn, hguardctl)
TE_POLICY(T(appdef), T(hguardctl_exec), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(appdef), T(hguardctl), (spawn))

COMMENT for sysdump
TE_POLICY(T(appdef), T(sysmgr), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC, shm_acquire, shm_destroy))

COMMENT for ps read proc/pid kernel services
TE_POLICY(T(appdef), T(init), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC, path_acquire))
TE_POLICY(T(appdef), T(vfs), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(appdef), T(devmgr), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(appdef), T(devhost), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(appdef), T(crypto), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(appdef), T(tppmgr), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(appdef), T(lwipd), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(appdef), T(keymgr), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))

COMMENT for ps read proc/pid uvmm, and sysif of vmctl
TE_POLICY(T(appdef), T(vm), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC, getfileattr, path_acquire))

COMMENT for df
TE_POLICY(T(appdef), A(generic_type), (getfsattr))

COMMENT for reboot procudure let appdef to send sig_kill to all processes, user should use posix cap to restrict this action further
TE_POLICY(T(appdef), A(subject_type), (signal))

COMMENT for appdef to umount tmp home var dirs
TE_POLICY(T(appdef), T(home_dir), (umount))
TE_POLICY(T(appdef), T(var_dir), (umount))
TE_POLICY(T(appdef), T(tmp_dir), (umount, BUILTIN_FILE_EXEC, BUILTIN_FILE_READ, BUILTIN_FILE_WRITE))
