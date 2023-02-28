INCLUDE(`builtin.m4')
TE_POLICY(T(vm), T(appdef_devnode), (fread, fwrite, fappend, getfileattr))

COMMENT allow uvmm to set devfreq
TE_POLICY(T(vm), T(appdef_sysnode), (BUILTIN_FILE_READ, BUILTIN_FILE_WRITE, BUILTIN_FILE_EXEC))

COMMENT allow vm to read and execute procnode
TE_POLICY(T(vm), T(appdef_procnode), (BUILTIN_FILE_EXEC, BUILTIN_FILE_READ))
