INCLUDE(`builtin.m4')

DEF_TYPES(hmesg_exec)
DEF_TYPES(hmesg)

COMMENT allow uvmm to call atfd kernel module
TE_POLICY(T(vm), T(atfd_mod), (mod_grant))

COMMENT allow devmgr to call devhost sched_get
TE_POLICY(T(devmgr), T(devhost), (sched_get))

COMMENT allow uvmm to reboot host when uvmm is panic
ABILITY_POLICY(T(vm), reboot)

COMMENT allow init to execute vm via a child shell
TE_POLICY(T(init), T(vm_exec), (BUILTIN_FILE_READ))

COMMENT allow devhost to add and remove cpu
ABILITY_POLICY(T(devhost), cpuhp_action)

COMMNET Allow sysmgr to map IOMEMs for theses ranges. The (0xB2CE4000, 0xB3600000)  range is used to access the shared memory corresponding to the KMSG.
COMMENT (0xB2CE4000, 0xB3600000)
MEM_RANGE(T(sysmgr), (2999861248, 3009413120))

COMMNET Allow devhost to map IOMEMs for theses ranges,  which are reserved memory for the driver.
COMMENT               (0xB2CE4000, 0xB3600000), (0xB3600000, 0xBFE00000)
MEM_RANGE(T(devhost), (2999861248, 3009413120), (3009413120, 3219128320))

COMMENT Allow vfs to map IOMEMs for theses ranges. The (0xB2CE4000, 0xB3564000)  range is used to access the shared memory corresponding to the KMSG. And the (0xB3600000, 0xBFE00000) range used to support DAX access to pramdisk.
COMMENT           (0xB2CE4000, 0xB3564000), (0xB3600000, 0xBFE00000)
MEM_RANGE(T(vfs), (2999861248, 3008774144), (3009413120, 3219128320))

COMMENT hkip-logbuf in m536a-hyp.dts
COMMENT          (0xB2CC4000, 0xB2CE4000)
MEM_RANGE(T(vm), (2999730176, 2999861248))

COMMNET dev0 in m536a-hyp.dts
COMMENT          (0xE0000000, 0x100000000)
MEM_RANGE(T(vm), (3758096384, 4294967296))

COMMENT Allows vm to map IOMEMs for these ranges, which are used to map virtualized guest memory space. (mem0 in m536a-hyp.dts)
COMMENT (0x00000000, 0x80000000), (0xC0000000, 0xE0000000), (0x100000000, 0x200000000), (0x800000000, 0x820000000)
MEM_RANGE(T(vm), (0, 2147483648), (3221225472, 3758096384), (4294967296, 8589934592), (34359738368, 34896609280))

COMMENT allow tppmgr register to uvmm for hotplug
TE_POLICY(T(tppmgr), T(vm), (path_acquire))

COMMNET The command 'hmesg.elf kbox print xxx' requires access to these memory ranges to print out kbox contents .
COMMENT             (0xB3464000, 0xB3600000)
MEM_RANGE(T(hmesg), (3007725568, 3009413120))