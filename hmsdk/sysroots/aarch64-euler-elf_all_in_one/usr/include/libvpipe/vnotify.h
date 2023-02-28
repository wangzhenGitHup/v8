/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Vnotify header defination
 * Author: Huawei OS Kernel Lab
 * Create: Mon Apr 12 16:00:03 2021
 */

#ifndef ULIBS_INCLUDE_LIBVPIPE_VNOTIFY_H
#define ULIBS_INCLUDE_LIBVPIPE_VNOTIFY_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include <sys/time.h>
#include <hmkernel/vnotify.h>
#include <libvpipe/vnotify_common.h>
#include <libhmsrv_sys/hm_futex.h>
#include <libhmsrv_sys/hm_vm.h>
#include <libbunch/bunch.h>

/* vnotify message types */
/* MODULE_VNOTIFY */
#define VNOTIFY_GUEST_ATTACH_CHN     0x1U
#define VNOTIFY_GUEST_DETACH_CHN     0x2U

#define VNOTIFY_NORMAL_CHN_BASE 2U
#define VNOTIFY_CHN_MAX 249U

#define CHN_MAX_LEN 32

/* mod ids */
#define MODULE_VNOTIFY 0x1U
#define MODULE_IPC     0x2U  /* System V ipc */
#define MODULE_MEM     0x3U
#define MODULE_FILE    0x4U

struct chn_attach_guest_msg_s {
	char chn_name[CHN_MAX_LEN];
	unsigned int flags;
};

struct chn_attach_guest_msg_resp_s {
	char chn_name[CHN_MAX_LEN]; /* double check name of chn acquired */
	int chn_id; /* chn id of chn acquired */
};

struct chn_detach_guest_msg_s {
	unsigned int chn_id;
};

struct chn_detach_guest_msg_resp_s {
	unsigned int chn_id;
};

/* MODULE_IPC */
#define VNOTIFY_GUEST_IPCSHM_GET        0x1U
#define VNOTIFY_GUEST_IPCSHM_MAP        0x2U
#define VNOTIFY_GUEST_IPCSHM_UNMAP      0x3U
#define VNOTIFY_GUEST_IPCSHM_CTL        0x4U

struct ipcshm_get_guest_msg_s {
	int32_t key;
	uint64_t size;
	int32_t shmflg;
};

struct ipcshm_map_guest_msg_s {
	int32_t shmid;
	int32_t shmflg;

	uint32_t gpa_lists_total;
	uint32_t gpa_lists_index;
	struct gpa_list_s gpa_list;
};

struct ipcshm_unmap_guest_msg_s {
	int32_t shmid;
};

struct ipcshm_ctl_guest_msg_s {
	int32_t shmid;
	int32_t cmd;
};

struct ipcshm_ctl_guest_msg_resp_s {
	uint64_t shm_segsz;
};

/* MODULE_MEM */
#define VNOTIFY_GUEST_MMAP              0x1U
#define VNOTIFY_GUEST_MUNMAP            0x2U
#define VNOTIFY_GUEST_GPA_TO_HPA        0x3U
#define VNOTIFY_GUEST_MADVISE           0x4U

#define VNOTIFY_HOST_MEM_TEST              0x1U

struct mmap_guest_msg_s {
	struct gpa_list_s gpa_list;
	uint32_t prot;
	uint32_t flags;
	int32_t fd;
	int64_t offset;
};

struct munmap_guest_msg_s {
	struct gpa_list_s gpa_list;
};

struct gpa_to_hpa_guest_msg_s {
	uint64_t gpa;
};

struct gpa_to_hpa_guest_msg_resp_s {
	uint64_t gpa;
	uint64_t hpa;
};

struct madvise_guest_msg_s {
	uint64_t gpa;
	uint64_t length;
	uint32_t flags;
};

struct madvise_guest_msg_resp_s {
	uint64_t gpa;
};

#define MAX_TEST_DATA 10
struct mem_test_host_msg_s {
	uint64_t gpa;
	uint64_t nr_pages;
	int32_t data[MAX_TEST_DATA];
};

/* MODULE_FILE */
#define VNOTIFY_GUEST_OPEN              0x1U
#define VNOTIFY_GUEST_CLOSE             0x2U
#define VNOTIFY_GUEST_FTRUNCATE         0x3U

#define FILE_NAME_MAX 128

struct open_guest_msg_s {
	int32_t flags;
	char pathname[FILE_NAME_MAX];
};

struct close_guest_msg_s {
	int32_t fd;
};

struct ftruncate_guest_msg_s {
	int32_t fd;
	uint64_t length;
};

struct vnotify_msg_s {
	struct vnotify_msg_header_s header;
	union {
		struct chn_attach_guest_msg_s chn_attach_guest_msg;
		struct chn_detach_guest_msg_s chn_detach_guest_msg;
		struct ipcshm_get_guest_msg_s ipcshm_get_guest_msg;
		struct ipcshm_map_guest_msg_s ipcshm_map_guest_msg;
		struct ipcshm_unmap_guest_msg_s ipcshm_unmap_guest_msg;
		struct ipcshm_ctl_guest_msg_s ipcshm_ctl_guest_msg;
		struct mmap_guest_msg_s mmap_guest_msg;
		struct munmap_guest_msg_s munmap_guest_msg;
		struct open_guest_msg_s open_guest_msg;
		struct close_guest_msg_s close_guest_msg;
		struct ftruncate_guest_msg_s ftruncate_guest_msg;
		struct gpa_to_hpa_guest_msg_s gpa_to_hpa_guest_msg;
		struct madvise_guest_msg_s madvise_guest_msg;

		struct mem_test_host_msg_s mem_test_host_msg;

		char payload[__VNOTIFY_CHN_MSG_PAYLOAD];
	};
};

struct vnotify_resp_header_s {
	unsigned char modid; /* module ID */
	unsigned char type; /* msg type */
	unsigned short len; /* msg len */
	int rc; /* msg return value, 0: success, or -ERRNO will be set. */
};

struct vnotify_resp_s {
	struct vnotify_resp_header_s header;
	union {
		struct chn_attach_guest_msg_resp_s chn_attach_guest_msg_resp;
		struct chn_detach_guest_msg_resp_s chn_detach_guest_msg_resp;
		struct ipcshm_ctl_guest_msg_resp_s ipcshm_ctl_guest_msg_resp;
		struct gpa_to_hpa_guest_msg_resp_s gpa_to_hpa_guest_msg_resp;
		struct madvise_guest_msg_resp_s madvise_guest_msg_resp;

		char payload[__VNOTIFY_CHN_MSG_PAYLOAD];
	};
};

static inline int
hm_vnotify_chnid_of(const struct vnotify_s *vnotify)
{
	return (int)vnotify->chn_id;
}

bool is_valid_chn_name(const char *name);
bool is_valid_attach_flags(unsigned int flags);
void hm_vnotify_init(struct vnotify_s *vnotify);
int hm_vnotify_create(struct vnotify_s *vnotify);
int hm_vnotify_attach_chn(struct vnotify_s *vnotify, const char *name, unsigned int flags);
int hm_vnotify_detach_chn(const struct vnotify_s *vnotify, bool sync, const struct timespec *timeout);
int hm_vnotify_notify(const struct vnotify_s *vnotify);
int hm_vnotify_receive(struct vnotify_s *vnotify,
		       const struct timespec *ts,
		       unsigned int flags);

int hm_vnotify_inject_event(const struct vnotify_s *vnotify);

int hm_vnotify_destroy(const struct vnotify_s *vnotify, bool sync, const struct timespec *timeout);
int hm_vnotify_update_futex(struct vnotify_s *vnotify, int *futex, bool shared);
int hm_vnotify_read_status(const struct vnotify_s *vnotify, unsigned int *status);

int vm_vnotify_chns_info(struct bunch *bunch);

/* Used by uvmm only */
int hm_vnotify_init_ctrl_chn(cref_t vm_cref, __u32 cnode_idx);
int hm_vnotify_receive_and_reply(void (*handler)(struct vnotify_msg_s *receive,
						 struct vnotify_resp_s *reply));
int hm_vnotify_send_and_receive(struct vnotify_msg_s *msg,
				struct vnotify_resp_s *resp);
#endif /* !ULIBS_INCLUDE_LIBVPIPE_VNOTIFY_H */
