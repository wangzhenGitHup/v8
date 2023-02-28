INCLUDE(`builtin.m4')

COMMENT type definition for resmgrfs
DEF_TYPES(resmgrfs_group)
DEF_TYPES(resmgrfs_unlabeled)

COMMENT resmgrfs structure: /res/$PID.service/*
DEF_FILE_OBJECT(resmgrfs, ``/res'')
DEF_FILE_OBJECT(resmgrfs_unlabeled, ``resmgrfs:/*'')
DEF_FILE_OBJECT(resmgrfs_group, ``resmgrfs:/*.service'')
DEF_FILE_OBJECT(resmgrfs_group, ``resmgrfs:/*.service/*'')
DEF_FILE_OBJECT(resmgrfs_group, ``resmgrfs:/procs'')
DEF_FILE_OBJECT(resmgrfs_group, ``resmgrfs:/threads'')
DEF_FILE_OBJECT(resmgrfs_group, ``resmgrfs:/subtree_control'')
DEF_FILE_OBJECT(resmgrfs_group, ``resmgrfs:/controllers'')

COMMENT attach resmgrfs with basic_dir and mount_point attribute
TYPE_ADD_ATTRIBUTES((resmgrfs), (basic_dir, mount_point))

COMMENT init applies resource control for services itself
TE_POLICY(T(init), T(resmgrfs), (BUILTIN_FILE_WRITE))
TE_POLICY(T(init), T(resmgrfs_group), (BUILTIN_FILE_WRITE, BUILTIN_FILE_EXEC, BUILTIN_FILE_READ))
