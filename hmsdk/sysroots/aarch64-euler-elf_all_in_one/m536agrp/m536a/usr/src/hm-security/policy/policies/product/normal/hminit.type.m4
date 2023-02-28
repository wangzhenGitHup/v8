INCLUDE(`builtin.m4')

COMMENT hminit is the type of shell
TYPE_ADD_ATTRIBUTES((hminit), (subject_type, stdio, access_system_services, killed_by_ctrl_c))

COMMENT ln /bin/busybox when system starts
TE_POLICY(T(hminit), T(bin_dir), (addname))
COMMENT ln /etc/mtab when system starts
TE_POLICY(T(hminit), T(etc_dir), (addname))
COMMENT busybox creates /.ash_history
TE_POLICY(T(hminit), T(initrd), (addname, delname))
COMMENT create file in /tmp
TE_POLICY(T(hminit), T(tmp_dir), (addname, delname))
COMMENT create file in /var
TE_POLICY(T(hminit), T(var_dir), (addname))
COMMENT create file in /devfs
TE_POLICY(T(hminit), T(devfs), (addname))

COMMENT ls needs ac_getfileattr currently, shoule be removed soon
TE_POLICY(T(hminit), A(device_node), (getfileattr, setfileattr))
COMMENT hminit could setlabel to files
TE_POLICY(T(hminit), A(subject_type), (BUILTIN_FILE_READ, setlabel))
TE_POLICY(T(hminit), A(executable_type), (BUILTIN_FILE_READ, setlabel))
TE_POLICY(T(hminit), T(unlabeled), (BUILTIN_FILE_READ, setlabel))
TE_POLICY(T(hminit), T(untrusted), (BUILTIN_FILE_READ, setlabel))
COMMENT for sectool.elf cred_init
TE_POLICY(T(hminit), T(sec_shm), (shm_acquire))

COMMENT hminit can getlabel, query cnode idx
COMMENT hminit need devmgr_mgmt, net_admin, raw_socket to use network service
COMMENT hminit need stat to operate sysdump
COMMENT ABILITY_POLICY(T(hminit), devmgr_mgmt, mount, getlabel, net_admin, raw_socket, stat)
COMMENT ab_stat for sysdump
COMMENT ABILITY_POLICY(T(hminit), reboot, settime, sys_time, iomem_mmap, hostname, klogport, tty, serial_toggle)
COMMENT ab_kevctrl, ab_kev, ab_cperm_kev_irq, ab_cperm_kev_privilege, ab_cperm_kev_klog, ab_cperm_kev_trap_el2, ab_kbox_user, ab_kbox_admin are all in sysadmin/*
ABILITY_HIERACHY_POLICY(T(hminit), ``/secadmin/*'', ``/posixcap/*'', ``/auditadmin/*'', ``/devel/perf/*'')

ABILITY_HIERACHY_POLICY(T(hminit), ``/sysadmin/getconf'', ``/sysadmin/stat/*'', ``/sysadmin/reboot'', ``/sysadmin/dev/*'', ``/sysadmin/kev'', ``/sysadmin/coredump/*'', ``/sysadmin/services/*'')

COMMMENT separate kbox_usr, kbox_admin from hminit
ABILITY_HIERACHY_POLICY(T(hminit), ``/sysadmin/dfx/dynlog'', ``/sysadmin/dfx/dumpshm'')

ABILITY_POLICY(T(hminit), getprocfd)

COMMENT execute hmtrace
TRANSITION(hminit, hmtrace_exec, spawn, hmtrace)
TYPE_ADD_ATTRIBUTES((hminit), (hmtrace_basic_policy))

COMMENT execute hguardctl
TRANSITION(hminit, hguardctl_exec, spawn, hguardctl)
TE_POLICY(T(hminit), T(hguardctl_exec), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(hminit), T(hguardctl), (spawn))

COMMENT for sysdump
TE_POLICY(T(hminit), T(sysmgr), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC, shm_acquire, shm_destroy))

COMMENT for ps read proc/pid kernel services
TE_POLICY(T(hminit), T(init), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC, path_acquire))
TE_POLICY(T(hminit), T(vfs), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(hminit), T(devmgr), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(hminit), T(devhost), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(hminit), T(crypto), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(hminit), T(tppmgr), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(hminit), T(lwipd), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(hminit), T(keymgr), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))

COMMENT for hminit to access all procfs nodes, should use DAC to do access control works
TE_POLICY(T(hminit), A(procfs_info), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC, BUILTIN_FILE_WRITE))

COMMENT for df
TE_POLICY(T(hminit), A(generic_type), (getfsattr))

COMMENT for reboot procudure let hminit to send sig_kill to all processes
TE_POLICY(T(hminit), A(subject_type), (signal))
