/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jun 24 22:05:13 2021
 */
#ifndef HM_UVMM_NET_H
#define HM_UVMM_NET_H

#include <lib/dlist.h>
#include <net/if.h>

#define NET_ID_LEN_MAX 16
#define NET_MAC_LEN_MAX 17
#define NET_TYPE_LEN_MAX 16

#define NET_TYPE_TAP 1
#define NET_TYPE_SOCKET	2

#define VIRITIO_NET_DEFAULT_RINGSZ 256

#define NETDEV_OPTIONS_LEN_MAX  64

enum netdev_type {
	NETDEV_TYPE_TAP,
	NETDEV_TYPE_VHOST_USER,
	NETDEV_TYPE_MAX,
};

struct netdev_tap_options {
	char ifname[IF_NAMESIZE];
};

struct netdev_vhostuser_options {
	char backend[NETDEV_OPTIONS_LEN_MAX];
};

struct netdev_options {
	enum netdev_type type;
	char id[NETDEV_OPTIONS_LEN_MAX];
	union {
		struct netdev_tap_options tap;
		struct netdev_vhostuser_options vhost_user;
	} u;
};

enum {
	VNET_QUEUE_RX,
	VNET_QUEUE_TX,
	VNET_QUEUE_MAX,
};

struct net_device;
struct virtio_entity;
struct net_device_ops {
	const char *name;
	int (*open)(struct net_device *dev);
	void (*close)(struct net_device *dev);
	int (*set_feature)(struct net_device *dev, uint64_t feature);
	int (*get_feature)(struct net_device *dev, uint64_t *feature);
	int (*xmit_init)(struct net_device *dev, struct virtio_entity *vent);
	int (*config)(struct net_device *dev, const char *config);
	int (*start)(struct net_device *dev, struct virtio_entity *vent);
};

struct virtqueue_info;
struct net_device {
	enum netdev_type type;
	char id[NETDEV_OPTIONS_LEN_MAX];
	int fd;
	bool enabled;
	struct net_device_ops *ops;
	struct virtqueue_info *vq[VNET_QUEUE_MAX];

	struct dlist_node node;
};

struct net_device *net_dev_find(const char *devid);
int net_dev_get_feature(struct net_device *dev, uint64_t *feature);
int net_dev_config(struct net_device *dev, const char *config);
int net_dev_enable(struct net_device *dev);
int net_dev_disable(struct net_device *dev);
int net_dev_xmit_init(struct net_device *dev, struct virtio_entity *vent);
int net_io_vq_linkup(struct net_device *dev, struct virtio_entity *vent);
int net_dev_start(struct net_device *dev, struct virtio_entity *vent);

int netdev_init_device(const char *netarg);
int netdev_init_tap(const struct netdev_options *option);
int netdev_init_vhost_user(const struct netdev_options *option);
struct net_device *netdev_new_device(size_t size);
void netdev_register(struct net_device *dev);
void netdev_clean_device(struct net_device *dev);

#endif
