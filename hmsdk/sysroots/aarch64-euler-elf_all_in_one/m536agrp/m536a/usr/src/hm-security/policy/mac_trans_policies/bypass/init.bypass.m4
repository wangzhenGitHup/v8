TE_POLICY(T(init), T(appdef), (spawn, umount))
TE_POLICY(T(init), T(appdef_devnode), (getfileattr))
COMMENT boot affinity need init has ac_sched_get for children
TE_POLICY(T(init), T(appdef), (sched_get))
TRANSITION(init, appdef, spawn, appdef)
TRANSITION(init, busyboxhm_exec, spawn, appdef)
