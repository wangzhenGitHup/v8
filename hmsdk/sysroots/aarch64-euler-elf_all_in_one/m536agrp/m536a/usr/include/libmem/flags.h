/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Definition of ulibs flags
 * Author: Huawei OS Kernel Lab
 * Create: Thu Sep 05 15:37:48 2019
 */

#ifndef ULIBS_INCLUDE_LIBMEM_MEM_FLAGS_H
#define ULIBS_INCLUDE_LIBMEM_MEM_FLAGS_H

#include <sys/mman.h>

/*
 * Protection attribute for hongmeng memory.
 * Compatible with POSIX PROT.
 */
#define MPROT_NONE			(unsigned int)PROT_NONE		/* 0 */
#define MPROT_READ			(unsigned int)PROT_READ		/* 1 */
#define MPROT_WRITE			(unsigned int)PROT_WRITE	/* 2 */
#define MPROT_EXEC			(unsigned int)PROT_EXEC		/* 4 */
#define MPROT_RWX_MASK			(unsigned int)0x7		/* mask for rwx properties */
/* hongmeng PROT extensions */
#define MPROT_NOCACHE			(unsigned int)0x8

/*
 * Hongmeng map flags.
 * Compatible with POSIX map flags, more needs to be added.
 */
#define MFLAG_MAP_FIXED			(unsigned int)MAP_FIXED			/* 0x10 */
#define MFLAG_MAP_FIXED_NOREPLACE	(unsigned int)MAP_FIXED_NOREPLACE	/* 0x100000 */
#define MFLAG_MAP_ANON			(unsigned int)MAP_ANON			/* 0x20 */
#define MFLAG_MAP_ANONYMOUS		(unsigned int)MAP_ANONYMOUS		/* 0x20 */
#define MFLAG_MAP_SHARED		(unsigned int)MAP_SHARED		/* 0x01 */
#define MFLAG_MAP_PRIVATE		(unsigned int)MAP_PRIVATE		/* 0x02 */
#define MFLAG_MAP_POPULATE		(unsigned int)MAP_POPULATE		/* 0x8000 */
#define MFLAG_MAP_LOCKED		(unsigned int)MAP_LOCKED		/* 0x2000 */
#define MFLAG_MAP_NORESERVE		(unsigned int)MAP_NORESERVE		/* 0x4000 */
#define MFLAG_MAP_STACK			(unsigned int)MAP_STACK			/* 0x20000 */

/* flags for huge page */
#define MFLAG_MAP_HUGETLB		(unsigned int)MAP_HUGETLB		/* 0x40000 */
#define MFLAG_MAP_HUGE_2MB		(unsigned int)MAP_HUGE_2MB		/* 21 << 26 */
#define MFLAG_MAP_HUGE_1GB		(unsigned int)MAP_HUGE_1GB		/* 30 << 26 */
#define MFLAG_MAP_HUGE_SHIFT		(unsigned int)MAP_HUGE_SHIFT		/* 26 */
#define MFLAG_MAP_HUGE_MASK		(unsigned int)MAP_HUGE_MASK		/* 0x3f */

/*
 * Hongmeng specific map flags.
 *
 * Cannot conflict with POSIX map flags.
 * Bits [26:31] encode the hugetlb page size.
 */
#define MFLAG_MAP_SHMM			(unsigned int)0x4       /* map native shm of IOMEM type */
#define MFLAG_MAP_IOMM			(unsigned int)0x1000000 /* IOMEM type */
#define MFLAG_MAP_STATIC_SHM_IO		(unsigned int)0x2000000 /* IOMEM type with static shmm */
#define MFLAG_MAP_FILE			(unsigned int)0x800000  /* FILE type */
#define MFLAG_MAP_VM			(unsigned int)0x400      /* mmap for virtual machine */
#define MFLAG_RLIMIT			(unsigned int)0x10000       /* whether need rlimit check */
#define MFLAG_MAP_ACTV			(unsigned int)0x8     /* actv stack mmap */
#define MFLAG_ALLOW_NOMEM		(unsigned int)0x80000 /* return no memory instead of oom */
#define MFLAG_NOCOW			(unsigned int)0x200000  /* vregion is not CoWable */
#define MFLAG_COWED			(unsigned int)0x400000  /* vregion has been CoWed */
/* flags used only when hughtlb is off */
#define MFLAG_MAP_RETRY			(unsigned int)0x10000000  /* try mmap retry when memory not enough */
/* flags used only when hughtlb is off */
#define MFLAG_MAP_PA_4G			(unsigned int)0x20000000 /* mmap for below 4G physical address*/

/* flags for msync */
#define MSYNC_FLAG_SYNC			(unsigned int)MS_SYNC       /* 4 */
#define MSYNC_FLAG_ASYNC		(unsigned int)MS_ASYNC      /* 1 */
#define MSYNC_FLAG_INVALIDATE		(unsigned int)MS_INVALIDATE /* 2 */

/* flags for mlockall */
#define MLOCK_FLAG_CURRENT		(unsigned int)MCL_CURRENT	/* 1 */
#define MLOCK_FLAG_FUTURE		(unsigned int)MCL_FUTURE	/* 2 */

/* flags for madvise */
#define MADV_FLAG_DONTNEED		POSIX_MADV_DONTNEED	/* 4 */
#define MADV_FLAG_REMOVE		MADV_REMOVE		/* 9 */
#define MADV_FLAG_DONTDUMP		MADV_DONTDUMP		/* 16 */
#define MADV_FLAG_DODUMP		MADV_DODUMP		/* 17 */
#define MADV_FLAG_NORMAL		POSIX_MADV_NORMAL       /* 0x00 */
#define MADV_FLAG_RANDOM		POSIX_MADV_RANDOM       /* 0x01 */
#define MADV_FLAG_SEQUENTIAL		POSIX_MADV_SEQUENTIAL   /* 0x02 */
#define MADV_FLAG_WILLNEED		POSIX_MADV_WILLNEED     /* 0x03 */
/*
 * reuse MFLAG_NOCOW as a madvise flag, MFLAG_NOCOW is a very
 * large number that will not conflict with future madvise flags
 */
#define MADV_FLAG_NOCOW			MFLAG_NOCOW /* 0x200000 */

/* flags for process_vm_readv/process_vm_writev */
#define MACCESS_VM_READ			0x00
#define MACCESS_VM_WRITE		0x01

/* native shm open flags, compatible with POSIX */
#define SHM_O_ACCMODE			(unsigned long long)0x03
#define SHM_O_RDONLY			(unsigned long long)0x00
#define SHM_O_WRONLY			(unsigned long long)0x01
#define SHM_O_RDWR			(unsigned long long)0x02
#define SHM_O_VM			(unsigned long long)0x04 /* Memory shared with virtual machine */
#define SHM_O_CREAT			(unsigned long long)0x40
#define SHM_O_EXCL			(unsigned long long)0x80
/* shm hugetlb flags */
#define SHM_O_HUGETLB			(unsigned long long)0x800 /* compatible with SHM_HUGETLB */
#define SHM_O_NORESERVE			(unsigned long long)0x1000 /* compatible with SHM_NORESERVE */
#define SHM_O_CONSUME_RESERVE		(unsigned long long)0x10000 /* consume reserve huge page when fill file page */
#define SHM_O_HUGE_SHIFT		(unsigned long long)MFLAG_MAP_HUGE_SHIFT /* 26 */
#define SHM_O_HUGE_MASK			(unsigned long long)MFLAG_MAP_HUGE_MASK
#define SHM_O_HUGE_2MB			(unsigned long long)MFLAG_MAP_HUGE_2MB
#define SHM_O_HUGE_1GB			(unsigned long long)MFLAG_MAP_HUGE_1GB

/* Hongmeng specific shm flags */
/* create shm with the specified physical address */
#define SHM_O_WITH_PA			(unsigned long long)0x10
/* the shm_node won't be auto unlinked when creator exits,
 * which means the shm_node will be unlinked by someone else,
 * and creator itself should not unlink it.
 */
#define SHM_O_KEEP			(unsigned long long)0x100
/* allocate contiguous physical pages when creating shm */
#define SHM_O_CELL			(unsigned long long)0x200
/* allocate non-contiguous physical pages when creating shm */
#define SHM_O_POPULATE			(unsigned long long)0x400
/* allow page allocation failure and will not trigger oom if failed */
#define SHM_O_NO_OOM			(unsigned long long)0x2000
/* allow granted server to regrant shm to other processes */
#define SHM_O_REGRANT			(unsigned long long)0x4000
#define SHM_O_GLOBAL			(unsigned long long)0x8000

/* native shm grant flags */
#define SHM_GRANT_ACCMODE		(unsigned int)0x03
#define SHM_GRANT_RDONLY		(unsigned int)0x00
#define SHM_GRANT_WRONLY		(unsigned int)0x01
#define SHM_GRANT_RDWR			(unsigned int)0x02
#define SHM_GRANT_UNLINK		(unsigned int)0x04   /* permission to unlink shm */
#define SHM_GRANT_TRANS			(unsigned int)0x08   /* permission to transfer authority to others */
/* native shm alloc flags */
#define SHM_ALLOC_POPULATE		(unsigned long long)0x1
#define SHM_ALLOC_GLOBAL		(unsigned long long)0x2


/*
 * flag for iomap
 *
 * devhost uses MFLAG_IOMAP_RECLAIM to notify sysmgr that
 * the virtual memory prepared in mmap can be reclaimed.
 */
#define MFLAG_IOMAP_RECLAIM		(unsigned int)0x1
#endif
