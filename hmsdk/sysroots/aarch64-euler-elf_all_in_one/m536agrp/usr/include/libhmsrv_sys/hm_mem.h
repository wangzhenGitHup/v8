/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Interface for memory management
 * Author: Huawei OS Kernel Lab
 * Create: Wed Mar 27 06:26:16 2019
 */
#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_MEM_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_MEM_H

#include <stdint.h>
#include <stddef.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <libbunch/bunch.h>
#include <libmem/types.h>
#include <libmem/flags.h>
#include <libsysif/sysmgr/api.h>
#include <hmkernel/capability.h>
#include "hm_stat.h"

/* the share memory that sysmgr created to share vfs.elf with init */
#define INIT_SHM_NAME		"init_launch_shm"

/*
 * struct hm_mem_fnode_s - Unique identification file
 * @index: inode index in fs
 * @dev_id: device id
 */
struct hm_mem_fnode_s {
	uint32_t index;
	uint64_t dev_id;
};

/* NOTE: this function is only be used in libvsyscall */
void *hm_mem_mmap_posix(void *addr, size_t len,
			uint32_t prot, uint32_t flags,
			int32_t fd, int64_t offset, int *ret_err);
void *hm_server_mem_mmap_posix(rref_t server,
			       const void *addr, size_t len,
			       uint32_t prot, uint32_t flags,
			       int32_t fd, int64_t offset, int *ret_err);
int hm_server_mem_munmap(rref_t server, const void *addr, size_t len);

void *hm_mem_mmap(void *addr, size_t len,
		  uint32_t prot, uint32_t flags,
		  int32_t fd, int64_t offset);

void *hm_mem_mremap(void *old_addr, size_t old_len, size_t new_len,
		    uint32_t flags, void *new_addr, int *ret_err);

int hm_mem_munmap(void *addr, size_t len);
int hm_mem_rmap_unmap_page(const void *addr);
/* NOTE: this function is only be used in libvsyscall */
int hm_mem_brk(const void *brk, void **rvaddr);

int hm_mem_madvise(const void *addr, size_t len, uint32_t flags);

int hm_mem_mprotect(const void *addr, size_t len, uint32_t prot);

int hm_mem_msync(const void *addr, size_t len, uint32_t flags);

int hm_mem_mlock(const void *addr, size_t len);

int hm_mem_munlock(const void *addr, size_t len);

int hm_mem_mlockall(uint32_t flags);

int hm_mem_munlockall(void);

uintptr_t hm_mem_alloc_kmem(size_t size);

int hm_mem_free_kmem(uintptr_t vstart);

cref_t hm_mem_alloc_pmem(size_t size);

int hm_mem_free_pmem(cref_t cref);

int hm_mem_shm_open(const char *name, size_t len, uint64_t oflags,
		    size_t *ret_len);

int hm_mem_shm_open_with_mode(const char *name, size_t len, uint64_t oflags,
			      mode_t mode, size_t *ret_len);

int hm_mem_shm_unlink(const char *name);

int hm_mem_shm_close(int32_t shm_id);

int hm_mem_shm_reclaim_pages(int32_t shm_id, const void *start_addr,
			     unsigned long nr_pages);

int hm_mem_query_shm_info(int32_t shm_id,
			  struct shm_node_info *shm_info);
int hm_mem_query_shm_paddr(int32_t shm_id,
			   unsigned long long *dst,
			   unsigned long size);

int hm_mem_shm_dump_info(void);

int hm_mem_stat(unsigned int flags, struct bunch *bunch);

int hm_server_mem_stat(rref_t server, unsigned int flags, struct bunch *bunch);

int hm_mem_set_anon_name(const void *start, size_t len, const char *name);

int hm_mem_process_vm_access(int pid, int direction,
			     const void *local_addr, unsigned long llen,
			     const void *remote_addr, unsigned long rlen,
			     unsigned int flags, size_t *total_copied);

int hm_mem_mincore(const void *addr, size_t length, const unsigned char *vec);
int hm_mem_calculate(struct memstat_deviation *div);
int hm_mem_fs_stat_register(const void *stat_addr);
int hm_mem_hugetlbfs_mount(const struct hgtlb_mount_args_s *args, unsigned int *order);
int hm_mem_file_mapping_stat(struct hm_mem_fnode_s fnode,
			     struct file_map_info_s *map_info);

int hm_mem_shm_chmod(const char* name, mode_t mode);

int hm_mem_cma_dyn_init(size_t size, unsigned int *cma_id);
int hm_mem_cma_alloc(unsigned int cma_id, size_t size, unsigned long long *paddr);
int hm_mem_cma_free(unsigned int cma_id, unsigned long long paddr, size_t size);

size_t hm_mem_drop_file_cache(void);
#endif /* ULIBS_INCLUDE_LIBHMSRV_SYS_HM_MEM_H */
