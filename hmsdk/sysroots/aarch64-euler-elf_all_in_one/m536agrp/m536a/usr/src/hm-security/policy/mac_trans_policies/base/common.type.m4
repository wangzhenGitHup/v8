DEF_TYPES(wtd_mod)
DEF_TYPES(atfd_mod)
COMMENT a new mount point would be set to untrusted_t when it's unconfigured
TYPE_ADD_ATTRIBUTES((untrusted), (mount_point))
COMMENT initial root file systems
DEF_FILE_OBJECT(crl_shm, ``shm:default_crl_*'')
DEF_FILE_OBJECT(sec_shm, ``shm:policydb'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_cred_sht_bucket'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_cred_sht_node'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_cred_sht_key'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_cred_basic'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_cred_mac'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_cred_dac'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_cred_dac_groups_*'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_cred_posix_cap'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_audit_cmdline_*'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_cred_keyring'')
DEF_FILE_OBJECT(sec_shm, ``shm:sec_shconf'')
DEF_FILE_OBJECT(guardmgr, ``path:guard_mgr'')
COMMENT modulemgr need check grant
DEF_FILE_OBJECT(wtd_mod, ``module:watchdog_module'')
DEF_FILE_OBJECT(atfd_mod, ``module:atfd'')
COMMENT process could do bunch of actions to itself
TE_POLICY(A(subject_type), self, (path_create, path_acquire, topic_create, topic_broadcast, topic_subscribe, topic_destroy, shm_create, shm_acquire, shm_reclaim, mq_create, mq_acquire, mq_destroy, mp_create, mp_acquire, mp_destroy, mp_reclaim, mp_populate, signal, fread, fwrite, mknod, rename, unlink, getfsattr, getfileattr, setfileattr, addname, delname, fappend, fexec, spawn, shm_destroy, sem_create, sem_acquire, sem_alter, svmq_create, svmq_read, svmq_write, svmq_destroy, svsem_create, svsem_read, svsem_write, svsem_destroy, svshm_create, svshm_read, svshm_write, svshm_destroy, mod_grant, sched_set, sched_get, nice_set, umount, link))
TE_POLICY(A(access_system_services), T(lwipd), (path_acquire))
TE_POLICY(A(access_system_services), T(vfs), (path_acquire))
TE_POLICY(A(access_system_services), T(tppmgr), (path_acquire))
TE_POLICY(A(access_system_services), T(sysmgr), (path_acquire))
TE_POLICY(A(access_system_services), T(devhost), (path_acquire))
TE_POLICY(A(access_system_services), T(devmgr), (path_acquire))
TE_POLICY(A(access_system_services), T(crypto), (path_acquire))

TE_POLICY(A(subject_type), T(proc_self), (fread, getfileattr, fexec))
TE_POLICY(A(subject_type), T(busyboxhm_exec), (fread, fexec, getfileattr))
TE_POLICY(A(subject_type), T(dev_comm), (fread, fwrite, fappend))

ABILITY_POLICY(A(sched_native_service), cperm_sched_native_service)
COMMENT for create and delete activation pool
ABILITY_POLICY(A(activation_pool_service), cperm_new_del_actvpool)
COMMENT all system service can promote priority
ABILITY_POLICY(A(system_service_type), rlimit_rtprio, rlimit_nice)

COMMENT for keymgr
COMMENT this is workaround to avoid yocto-ng's packaging problem
DEF_TYPES(keymgr_exec)
