INCLUDE(`builtin.m4')

DEF_FILE_OBJECT(hmesg_exec, ``/usr/bin/hmesg.elf'')

TYPE_ADD_ATTRIBUTES((hmesg_exec), (executable_type))
TYPE_ADD_ATTRIBUTES((hmesg), (subject_type))

TYPE_ADD_ATTRIBUTES((hmesg), (access_system_services, killed_by_ctrl_c))
TE_POLICY(T(hmesg), A(basic_dir), (addname, delname, mknod))
TE_POLICY(A(subject_type), T(hmesg), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(hmesg), A(device_node), (BUILTIN_FILE_EXEC, BUILTIN_FILE_READ, fwrite, setfileattr, link))

TE_POLICY(T(hmesg),T(appdef),(BUILTIN_FILE_READ, BUILTIN_FILE_WRITE, BUILTIN_FILE_EXEC))

ABILITY_HIERACHY_POLICY(T(hmesg), ``/sysadmin/kevdata/*'', ``/sysadmin/kevctrl'')

ABILITY_POLICY(T(hmesg), kev)

ABILITY_POLICY(T(hmesg), kbox_user)
ABILITY_POLICY(T(hmesg), kbox_admin)

ABILITY_POLICY(T(hmesg), klogport)
ABILITY_POLICY(T(hmesg), tty)
ABILITY_POLICY(T(hmesg), serial_toggle)

COMMENT allow hmesg to mmap kbox memory regions
ABILITY_POLICY(T(hmesg), iomem_mmap)

COMMENT allow app to write log to kev
ABILITY_POLICY(T(appdef), cperm_klog)

COMMENT appdef execute hmesg
TRANSITION(appdef, hmesg_exec, spawn, hmesg)
TE_POLICY(T(appdef), T(hmesg_exec), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(T(appdef), T(hmesg), (spawn))
