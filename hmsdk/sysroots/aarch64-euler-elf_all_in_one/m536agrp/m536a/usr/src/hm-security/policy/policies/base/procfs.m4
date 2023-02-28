DEF_FILE_OBJECT(procfs, ``/proc'')

DEF_TYPES(proc_stat)
DEF_TYPES(proc_hstat)
DEF_TYPES(proc_mem)
DEF_TYPES(proc_uptime)
DEF_TYPES(proc_sys)
DEF_TYPES(proc_self)
DEF_TYPES(proc_mnt)
DEF_TYPES(proc_vm)
DEF_TYPES(proc_net)
DEF_TYPES(proc_fs)
DEF_TYPES(proc_kernel)
DEF_TYPES(proc_rsm)
DEF_TYPES(proc_yama)
DEF_TYPES(proc_unlabeled)


DEF_FILE_OBJECT(proc_unlabeled, ``procfs:/*'')
DEF_FILE_OBJECT(proc_stat, ``procfs:/stat'')
DEF_FILE_OBJECT(proc_hstat, ``procfs:/hstat'')
DEF_FILE_OBJECT(proc_mem, ``procfs:/meminfo'')
DEF_FILE_OBJECT(proc_uptime, ``procfs:/uptime'')
DEF_FILE_OBJECT(proc_sys, ``procfs:/sys'')
DEF_FILE_OBJECT(proc_self, ``procfs:/self'')
DEF_FILE_OBJECT(proc_mnt, ``procfs:/mounts'')
DEF_FILE_OBJECT(proc_vm, ``procfs:/sys/vm'')
DEF_FILE_OBJECT(proc_vm, ``procfs:/sys/vm/*'')
DEF_FILE_OBJECT(proc_net, ``procfs:/net'')
DEF_FILE_OBJECT(proc_net, ``procfs:/net/*'')
DEF_FILE_OBJECT(proc_net, ``procfs:/sys/net'')
DEF_FILE_OBJECT(proc_net, ``procfs:/sys/net/*'')
DEF_FILE_OBJECT(proc_fs, ``procfs:/sys/fs'')
DEF_FILE_OBJECT(proc_fs, ``procfs:/sys/fs/*'')
DEF_FILE_OBJECT(proc_kernel, ``procfs:/sys/kernel'')
DEF_FILE_OBJECT(proc_kernel, ``procfs:/sys/kernel/*'')
DEF_FILE_OBJECT(proc_yama, ``procfs:/sys/kernel/yama'')
DEF_FILE_OBJECT(proc_yama, ``procfs:/sys/kernel/yama/pdebug_scope'')
DEF_FILE_OBJECT(proc_rsm, ``procfs:/rsm'')
DEF_FILE_OBJECT(proc_rsm, ``procfs:/rsm/*'')

TYPE_ADD_ATTRIBUTES((procfs), (basic_dir, mount_point))

DEF_ATTRIBUTES(procfs_info)
TYPE_ADD_ATTRIBUTES((procfs, proc_unlabeled, proc_stat, proc_hstat, proc_mem,
proc_uptime, proc_sys, proc_self, proc_mnt, proc_vm, proc_net, proc_fs,
proc_kernel, proc_rsm, proc_yama), (procfs_info))