INCLUDE(`builtin.m4')

DEF_TYPES(hmtrace)
DEF_TYPES(hmtrace_exec)
DEF_TYPES(hmtrace_path)

COMMENT system services that can enable ftrace
DEF_ATTRIBUTES(ftrace_system_services)

DEF_FILE_OBJECT(hmtrace_exec, ``hmtrace.elf'')
DEF_FILE_OBJECT(hmtrace_exec, ``/usr/bin/hmtrace.elf'')
DEF_FILE_OBJECT(hmtrace_path, ``path:hmtracemgr_ap_*'')
DEF_ATTRIBUTES(hmtrace_basic_policy)
TE_POLICY(A(hmtrace_basic_policy), T(hmtrace_exec), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC))
TE_POLICY(A(hmtrace_basic_policy), T(hmtrace), (spawn))
TYPE_ADD_ATTRIBUTES((hmtrace_exec), (executable_type))
TYPE_ADD_ATTRIBUTES((hmtrace), (subject_type))

COMMENT add frace enabled system services
TYPE_ADD_ATTRIBUTES((tppmgr), (ftrace_system_services))
TYPE_ADD_ATTRIBUTES((lwipd), (ftrace_system_services))
TYPE_ADD_ATTRIBUTES((devmgr), (ftrace_system_services))
TYPE_ADD_ATTRIBUTES((devhost), (ftrace_system_services))
TYPE_ADD_ATTRIBUTES((sysmgr), (ftrace_system_services))
TYPE_ADD_ATTRIBUTES((vfs), (ftrace_system_services))
TYPE_ADD_ATTRIBUTES((vm), (ftrace_system_services))
TE_POLICY(A(ftrace_system_services), T(hmtrace_path), (path_create))

TE_POLICY(T(hmtrace), T(hmtrace_path), (path_acquire))
TYPE_ADD_ATTRIBUTES((hmtrace), (stdio, access_system_services, killed_by_ctrl_c))
