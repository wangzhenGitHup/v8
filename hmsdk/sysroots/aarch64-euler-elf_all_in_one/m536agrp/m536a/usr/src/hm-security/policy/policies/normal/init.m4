TE_POLICY(T(init), T(hminit), (spawn))
TRANSITION(init, busyboxhm_exec, spawn, hminit)
