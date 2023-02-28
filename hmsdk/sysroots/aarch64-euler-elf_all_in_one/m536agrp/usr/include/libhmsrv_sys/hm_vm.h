/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Interface of vmmgr
 * Author: Huawei OS Kernel Lab
 * Create: Wed Oct 30 11:20:00 2019
 */
#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_VM_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_VM_H

#include <stdint.h>
#include <hongmeng/errno.h>
#include <libstrict/strict.h>
#include <hmkernel/capability.h>
#include <libhwsecurec/securec.h>

#define VM_NORMAL	0
#define VM_GICPT	1

#define VM_SHM_REGIONS_NUM 3

#define VM_GPA_SLOTS_MAX 15

#define MAX_NR_GPA_LIST 256U

struct gpa_slot_s {
	uint64_t gpa;
	uint64_t length;
};

struct gpa_list_s {
	uint32_t nr_slots;
	struct gpa_slot_s slots[VM_GPA_SLOTS_MAX];
};

struct vm_region_s {
	uint64_t hva;
	uint64_t gpa;
	uint64_t size;
	uint8_t config;
};

struct hm_vm_shm_info {
	int32_t id;
	size_t len;
	void *vaddr;
	void *paddr;
};

struct vm_iomem_args {
	cref_t vm_cref;
	struct vm_region_s *regions;
	unsigned int region_num;
};

struct vm_shmmem_args {
	cref_t vm_cref;
	uint64_t *hpa;
	uint64_t *gpa;
	uint64_t *region_size;
};

struct vm_map_to_process_args {
	rref_t vm_rref;
	cref_t vm_cref;
	struct vm_region_s *regions;
	unsigned int region_num;
};

enum vm_region_type {
	VM_REGION_TYPE_IOMEM,
	VM_REGION_TYPE_VHOST,
};

static inline int hm_vm_get_name(char *buf, unsigned long len, int vm_type)
{
	return snprintf_s(buf, len, len - 1U, "uvmm-ap-path-%d", vm_type);
}

static inline int hm_vm_get_hpe_name(char *buf, unsigned long len)
{
	return hm_vm_get_name(buf, len, VM_GICPT);
}

int hm_vm_check_gpa_list(const struct gpa_list_s *gpa_list);
int hm_vm_map_iomem(struct vm_iomem_args *args);
int hm_vm_map_shmmem(struct vm_shmmem_args *args);
int hm_vm_alloc_static_shm_with_va(rref_t uvmm_rref, int32_t static_shm_idx,
				   void *addr, struct hm_vm_shm_info *ret_info);
int hm_vm_alloc_static_shm(rref_t uvmm_rref, int32_t static_shm_idx,
			   struct hm_vm_shm_info *ret_info);
int hm_vm_free_static_shm(rref_t uvmm_rref, int32_t static_shm_idx,
			  struct hm_vm_shm_info *shm_info);
int hm_vm_create_vm_vspace(void);
void hm_vm_destroy_vm_vspace(void);
int hm_vm_mmap_vdso(uint64_t gpa, uint64_t size);
int hm_vm_mmap(const struct gpa_list_s *gpa_list, unsigned int prot,
	       unsigned int flags, int fd, long offset);
int hm_vm_munmap(const struct gpa_list_s *gpa_list);

int hm_vm_map_to_process(struct vm_map_to_process_args *args);

int hm_vsock_vm_rx(rref_t uvmm_rref, const void *hdr, size_t hdr_len,
		   const void *data, size_t data_len);

int hm_vm_assert_irq(xref_t vm_xref, unsigned int vcpu_id,
		     unsigned int irq_id, unsigned int level);

int hm_vm_gpa_to_hpa(uintptr_t gpa, uintptr_t *hpa);
int hm_vm_get_region_num(xref_t vm_cref, unsigned int *region_num, unsigned int type);
#endif /* ULIBS_INCLUDE_LIBHMSRV_SYS_HM_VM_H */
