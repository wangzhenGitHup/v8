COMMENT basic policy of perf
DEF_ATTRIBUTES(perf_basic_policy)
COMMENT required for the ipc between the perf app and the perf module of the sysmgr
ABILITY_POLICY(A(perf_basic_policy), debug)
COMMENT required for obtaining sampled data from the microkernel using the kvic framework
ABILITY_POLICY(A(perf_basic_policy), irq)
COMMENT required for reading the number of system CPUs
ABILITY_POLICY(A(perf_basic_policy), sysconf)
COMMENT required for reading data from kev
ABILITY_POLICY(A(perf_basic_policy), cperm_kev_sample, kev, kevctrl)
COMMENT required for reading dynamic library loading information of process from sysmgr
ABILITY_POLICY(A(perf_basic_policy), stat)
COMMENT required for improving the priority of the thread for reading sampled data
ABILITY_POLICY(A(perf_basic_policy), cperm_sched_native_service)
