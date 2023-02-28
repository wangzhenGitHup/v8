INCLUDE(`builtin.m4')
TYPE_ADD_ATTRIBUTES((vm), (subject_type, stdio, killed_by_ctrl_c))
TYPE_ADD_ATTRIBUTES((vm_exec), (executable_type))
TYPE_ADD_ATTRIBUTES((vm), (activation_pool_service))
TE_POLICY(T(vm), T(vfs), (path_acquire))
COMMENT virtio vsock need visiting hmnetd's actv-handler
TE_POLICY(T(vm), T(lwipd), (path_acquire))
TE_POLICY(T(vm), T(sysmgr), (path_acquire))
TE_POLICY(T(vm), T(tppmgr), (path_acquire))
COMMENT virtio-console,virtio-block... both need visit /dev/xxxx
TE_POLICY(T(vm), A(device_node), (fread, fwrite, fappend, getfileattr))
COMMENT uvmm need to generate dtb files in tmp directory
TE_POLICY(T(vm), T(tmp_dir), (BUILTIN_FILE_READ, BUILTIN_FILE_EXEC, BUILTIN_FILE_WRITE))
COMMENT ab_getprocfd: virtio-console may call mknod to create /dev/pts
COMMENT ab_net_admin: virtio-net need to create tap devices through socket ioctl
ABILITY_POLICY(T(vm), sysconf, sysconf_kernel, cap_new_vm, cap_new_vspace, vm_vspace, cpuctx_vcpu, cpuhp_listen, cperm_klog, iomem_mmap, getprocfd, cperm_actv_rw_caller_vm, cperm_sched_native_service, cperm_sched_admin, net_admin, mmap_min_addr, ipc_lock)
DEF_FILE_OBJECT(vm_exec, ``/usr/bin/vm.elf'')
TRANSITION(sysmgr, vm_exec, spawn, vm)
TE_POLICY(T(vm), T(sec_shm), (shm_acquire))
ABILITY_POLICY(T(vm), privileged_affinity)
TE_POLICY(T(vm), T(init), (path_acquire))
TE_POLICY(T(vm), T(sys_class), (BUILTIN_FILE_EXEC))
TE_POLICY(T(vm), T(sys_dev), (BUILTIN_FILE_EXEC))
TE_POLICY(T(vm), T(sys_platform), (BUILTIN_FILE_EXEC))
TE_POLICY(T(vm), T(sys_platform_root), (BUILTIN_FILE_EXEC))
