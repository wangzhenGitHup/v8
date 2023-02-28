TYPE_ADD_ATTRIBUTES((crypto_exec), (executable_type))
TYPE_ADD_ATTRIBUTES((crypto), (subject_type, access_system_services, stdio))
TYPE_ADD_ATTRIBUTES((crypto), (sched_native_service))
TYPE_ADD_ATTRIBUTES((crypto), (activation_pool_service))
TYPE_ADD_ATTRIBUTES((crypto), (system_service_type))
ABILITY_POLICY(T(crypto), sysconf, devmgr, cperm_actv_rw_caller_vm, cperm_klog)
COMMENT for /proc/sys/kernel/random/*
ABILITY_POLICY(T(crypto), procfs)
DEF_FILE_OBJECT(crypto_exec, ``/bin/crypto.elf'')
DEF_FILE_OBJECT(crypto, ``path:crypto'')
TE_POLICY(T(crypto), T(sec_shm), (shm_acquire))
TE_POLICY(T(crypto), T(init), (path_acquire))
