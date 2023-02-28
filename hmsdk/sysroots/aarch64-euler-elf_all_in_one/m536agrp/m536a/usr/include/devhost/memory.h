/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Prototypes for devhost memory APIs
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jan 11 10:45:12 2019
 */
#ifndef __DEVHOST_API_MEMORY_H__
#define __DEVHOST_API_MEMORY_H__

#if defined(MODULE)
#include <linux/types.h>
#elif defined(UDK_MODULE) || defined(UDK_FRAMEWORK)
#include <udk/stdint.h>
#include <stddef.h>
#else
#include <stdint.h>
#include <stddef.h>
#endif

/*
 * CAUSION: This file will be used in linux source,
 *          **DO NOT** include any HMOS headers.
 */

unsigned int pool_va2offset(uintptr_t va);
uintptr_t pool_offset2va(unsigned int offset);
unsigned long long pool_offset2pa(unsigned int offset);

/* dma mem related */
void devhost_shm_release(void *shm_vaddr, size_t shm_len);
int __devhost_shm_mem_alloc(size_t size, unsigned long long *paddr,
			    int *ret_id);
int __devhost_shm_mem_destroy(int shm_id);
void *devhost_backend_mem_alloc(size_t size, uint32_t mprot,
				unsigned long long *rpaddr,
				int *rshmid);
void devhost_backend_mem_free(int shmid, void *vaddr, size_t size);

/* for net service only */
void *devhost_dma_pool_alloc(unsigned long long *paddr,
			     unsigned int *offset);
void *devhost_dma_pool_alloc_ex(unsigned long long *paddr,
				unsigned int *offset, unsigned int size);
int devhost_dma_pool_free(unsigned int offset);
unsigned int devhost_dma_get_free_num(void);

/* firmware, a.k.a. device tree */
int devhost_firmware_data(uint64_t drv_shm_key, void **buf);

/*
 * mapping support
 */
#define PAL_REMAP_NONE  0x0
#define PAL_REMAP_CACHE 0x1
#define PAL_REMAP_NORMAL_NC 0x2
#define PAL_REMAP_DEVICE 0x4
#define PAL_VM_TO_USER		(1U << 31)

int devhost_pal_iomem_map(unsigned long vaddr, unsigned long paddr,
			  unsigned long size, unsigned long prot,
			  unsigned int flags);
void* devhost_pal_ioremap(unsigned long paddr, unsigned long size,
			  unsigned long prot, unsigned int flags);
/* liblinux_pal_ioremap_ex will be remove when liblinux support this */
void *liblinux_pal_ioremap_ex(unsigned long phys_addr, unsigned long size, unsigned long prot,
			  unsigned int flags);
void devhost_pal_iounmap(const void *vaddr, unsigned long size);
int devhost_pal_copy_from_user(void *dst, const void *src, unsigned long n);
int devhost_pal_copy_to_user(void *dst, const void *src, unsigned long n);
int devhost_pal_copy_in_user(void *dst, const void *src, unsigned long n);

/*
 * struct devhost_vma_info - vma info in devhost for support user apps map and munmap
 * @len:	  lenght of the virtual address area from sysmgr
 * @start:	  start  of the virtual address area
 * @prot:	  protection mode of the memory
 * @offset:	  offset of the memory
 * @flags:	  flags of the memory
 * @vma_id:	  id of the devhost vma info
 * @priv:	  private data of the backend
 */
struct devhost_vma_info {
	unsigned long len;
	unsigned long start;
	unsigned long prot;
	unsigned long offset;
	unsigned int flags;
	unsigned int vma_id;
	void *priv;
};

int devhost_pal_umap_populate(const void *va, unsigned long long pa,
			      unsigned long len, unsigned int prot,
			      unsigned int flag);

int devhost_pal_usermap_prepare(unsigned long addr, unsigned long len,
				unsigned long prot, unsigned int flags,
				struct devhost_vma_info **out);
void devhost_pal_usermap_finish(const struct devhost_vma_info *vma_info, int success);
int devhost_pal_usermap_munmap(unsigned long addr, unsigned long len);
int __do_devhost_usermap_munmap(unsigned int vma_id, unsigned long len);

#ifdef CONFIG_ENABLE_KASAN
int devhost_pal_umap_iomap_finish(const void *va_addr, unsigned long len, unsigned int flag);
#endif

#endif /* __DEVHOST_API_MEMORY_H__ */
