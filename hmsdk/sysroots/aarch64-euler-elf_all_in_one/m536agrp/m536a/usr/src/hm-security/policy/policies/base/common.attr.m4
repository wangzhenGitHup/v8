COMMENT for all processes
DEF_ATTRIBUTES(subject_type)
COMMENT for all executable files
DEF_ATTRIBUTES(executable_type)
COMMENT processes that need to read/write tty
DEF_ATTRIBUTES(stdio)
DEF_ATTRIBUTES(mount_point)
COMMENT all device nodes
DEF_ATTRIBUTES(device_node)
DEF_ATTRIBUTES(device_directory)
COMMENT processes that could be killed by ctrl c
DEF_ATTRIBUTES(killed_by_ctrl_c)
COMMENT processes that need access system services
DEF_ATTRIBUTES(access_system_services)
COMMENT dirs come with rootfs like /bin, /etc, /home, /lib etc.
DEF_ATTRIBUTES(basic_dir)
COMMENT set thread priority greater than native service base
DEF_ATTRIBUTES(sched_native_service)
COMMENT processes that could create/delete activation pool
DEF_ATTRIBUTES(activation_pool_service)
COMMENT for all system service
DEF_ATTRIBUTES(system_service_type)
