/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Header file of vhost-user exported to SDK
 * Author: Huawei OS Kernel Lab
 * Create: Mon Oct 11 17:31:48 2021
 */

#ifndef HM_UVMM_VDEV_VHOST_USER_H
#define HM_UVMM_VDEV_VHOST_USER_H

#include <libuvmm/net.h>
#include <libhmsrv_sys/hm_vm.h>

struct vhost_user_device {
	struct net_device ndev;
	struct vhost_user_ops_s *ops;
	void *opaque;
};

struct vring_addr_s {
	unsigned int index;
	uint64_t desc_addr;
	uint64_t avail_addr;
	uint64_t used_addr;
};

struct vring_state_s {
	unsigned int idx;
	unsigned int val;
};

struct vhost_mem_region_s {
	uint64_t gpa;
	uint64_t mem_size;
};

struct vhost_memory_s {
	unsigned int nr_regions;
	struct vhost_mem_region_s *regions;
};

/*
 * struct vhost_user_ops_s - vhost-user backend operation methods
 * @backend_init:	Basic init of the backend, like open a file descriptor
 *			or grant a rref, etc.
 * @mmio_bind:		Bind mmio mem region to mmio_dispatcher.
 * @set_mem_table:	Set guest memory to backend.
 * @set_vring_num:	Set the vring size to backend.
 * @set_vring_addr:	Set the vring address to backend.
 * @set_vring_kick:	Set the kick monitor. Different backends may have
 *			different type of kick monitor.
 * @set_feature:	Set the driver features (front guest).
 * @get_feature:	Get the backend features.
 * @done:		Tell backend the negotiation is done.
 * */
struct vhost_user_ops_s {
	int (*vhostuser_backend_init)(struct vhost_user_device *dev);
	int (*vhostuser_mmio_bind)(struct vhost_user_device *dev);
	int (*vhostuser_set_mem_table)(struct vhost_user_device *dev,
				       struct vhost_memory_s *memory);
	int (*vhostuser_set_vring_num)(struct vhost_user_device *dev,
				       struct vring_state_s *state);
	int (*vhostuser_set_vring_addr)(struct vhost_user_device *dev,
					struct vring_addr_s *addr);
	int (*vhostuser_set_vring_kick)(struct vhost_user_device *dev, unsigned int idx);
	int (*vhostuser_set_feature)(struct vhost_user_device *dev, uint64_t feature);
	int (*vhostuser_get_feature)(struct vhost_user_device *dev, uint64_t *feature);
	int (*vhostuser_done)(struct vhost_user_device *dev);
};

void vhostuser_ops_register(const char *name, struct vhost_user_ops_s *ops);

#ifdef CONFIG_VHOST_USER_HPE_BACKEND
/*
 * hpe_mmio_bind - a helper function for hpe backend
 *
 * Bind virtio_mmio to kernel mmio_dispatcher. When the front driver in guest
 * update the virtqueue and kick the host, kernel will notify the hpe backend
 * through a vnotify channel.
 *
 * Returns:
 *  >= 0 : Successful and the vnotify channel id returns
 *  < 0  : Some error happens and a hongmeng errno returns
 */
int hpe_mmio_bind(struct vhost_user_device *dev);
#endif

#endif