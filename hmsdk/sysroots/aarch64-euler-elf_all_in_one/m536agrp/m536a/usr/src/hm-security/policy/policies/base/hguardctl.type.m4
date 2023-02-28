DEF_TYPES(hguardctl)
DEF_TYPES(hguardctl_exec)

DEF_FILE_OBJECT(hguardctl_exec, ``hguardctl.elf'')
DEF_FILE_OBJECT(hguardctl_exec, ``/bin/hguardctl.elf'')

TYPE_ADD_ATTRIBUTES((hguardctl_exec), (executable_type))
TYPE_ADD_ATTRIBUTES((hguardctl), (subject_type, stdio))

COMMENT hguardctl could ctrl service
ABILITY_POLICY(T(hguardctl), guard_service_ctrl)

COMMENT acquire path for needed service
TE_POLICY(T(hguardctl), T(init), (path_acquire))
TE_POLICY(T(hguardctl), T(vfs), (path_acquire))
TE_POLICY(T(hguardctl), T(sysmgr), (path_acquire))
