TE_POLICY(T(boot), T(init), (spawn, fexec))
TE_POLICY(T(boot), T(sysmgr), (spawn, fexec))
TRANSITION(boot, sysmgr, spawn, sysmgr)
TRANSITION(boot, init, spawn, init)
