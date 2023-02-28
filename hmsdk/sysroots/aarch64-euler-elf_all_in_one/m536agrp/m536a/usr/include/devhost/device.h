/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Prototypes and type definitions for device APIs
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jan 11 10:45:12 2019
 */
#ifndef __DEVHOST_API_DEVICE_H__
#define __DEVHOST_API_DEVICE_H__

#if defined(MODULE)
#include <linux/types.h>
#elif defined(UDK_MODULE) || defined(UDK_FRAMEWORK)
#include <udk/stdint.h>
#include <stddef.h>
#else
#include <stdint.h>
#include <stddef.h>
#endif

/* device APIs */
struct device_private;
struct devhost_pt_info;
struct device_info {
	struct device_private *p;
	const char *devname;
	int devid;
	int parent;
	/* this function is used to release the owner of device_info or device_info itself */
	void (*release)(struct device_info *devinfo);
};

int devhost_register_device(struct device_info *info);
int devhost_unregister_device(struct device_info *info);
int devhost_create_device(int devid, struct device_info *info);
int devhost_acquire_device(int devid, struct device_info **pinfo);
void devhost_devinfo_put(struct device_info *info);

int devhost_device_init(struct device_info *devinfo);
void devhost_device_destroy(struct device_info *devinfo);
void devhost_device_set_autoload(struct device_info *devinfo);
void devhost_device_set_isolate(struct device_info *devinfo, const char *isolate_group);
int devhost_device_set_probeable(struct device_info *devinfo,
				const char *compatible, size_t size);

/* devfs capable */
struct devhost_fops {
	int (*open)(struct device_info *dev, void **ctx, unsigned int flags);
	int (*close)(void *ctx);
	int (*read)(void *ctx, void *buf, unsigned long count,
		    unsigned long long off);
	int (*write)(void *ctx, const void *buf, unsigned long count,
		     unsigned long long off);
	int (*ioctl)(void *ctx, unsigned int cmd, unsigned long arg);
	int (*mmap)(void *ctx,
		    unsigned long addr, unsigned long length, unsigned long prot,
		    unsigned long offset);
	int (*poll)(void *ctx, unsigned long *event_out,
		    struct devhost_pt_info *pt_info, uint64_t key);
	long long (*llseek)(void *ctx, long long offset, int whence);
	void **owner;
};

struct devhost_vma_info;
/*
 * devfs capable extensible
 */
struct devhost_fops_ex {
	size_t size;      /* size of the structure */
	unsigned long __rsvd1[3]; /* reserved for future use */
	int (*compat_ioctl)(void *ctx, unsigned int cmd, unsigned long arg);
	int (*mmap_ex)(void *ctx, struct devhost_vma_info *vma_info);
	unsigned long __rsvd2[2]; /* reserved for future use */
};

/*
 * devnode_fn_t gets the information needed to create
 * the device node, currently only the node name is
 * supported, and subsequent extensions support
 * mode/uid/gid information
 */
typedef int (*devnode_fn_t)(struct device_info *devinfo,
			    char *devnode_name, unsigned int size);
void devhost_device_capable_devfs(struct device_info *devinfo,
				  uint32_t devt, int vfs_mode,
				  devnode_fn_t devnode_fn,
				  struct devhost_fops *fops);

void devhost_device_capable_devfs_ex(struct device_info *devinfo,
				     struct devhost_fops_ex *ex_fops);

struct bd_io;
/* block capable */
struct devhost_block_ops {
	void* (*bio_alloc)(void *filep,
			   const struct bd_io *bd_io,
			   void *private, unsigned int bd_io_idx);
	void (*bio_free)(void *bio);
	int (*submit_bio)(void *bio, unsigned int flags);
	int (*bio_add_data)(void *bio, uintptr_t vaddr, unsigned int bv_len);
	int (*dev_check_feature)(void *filep, int idx, uint64_t feature,
				 uint64_t *supported_features);
	int (*direct_access)(void *filep,
			     unsigned long offset, unsigned long size,
			     unsigned long *paddr, unsigned long *ret_size);
};
/* requirement:
 *   - `flags == !DEVICE_CAN_PROBE`
 *   - `devt != 0`
 *   - vfs_mode == MODE_BLK
 */
void devhost_device_capable_blk(struct device_info *devinfo,
				struct devhost_block_ops *blkops);

int devhost_block_end_io(void *private, int bi_error, unsigned int bd_io_idx);

/* pm capable */
struct devhost_dev_pm_ops {
	int (*shutdown)(struct device_info *info);
	int (*pre_suspend)(struct device_info *info);
	int (*suspend)(struct device_info *info);
	int (*post_suspend)(struct device_info *info);
	int (*noirq_suspend)(struct device_info *info);
	int (*noirq_resume)(struct device_info *info);
	int (*pre_resume)(struct device_info *info);
	int (*resume)(struct device_info *info);
	int (*post_resume)(struct device_info *info);
};

void devhost_device_capable_pm(struct device_info *devinfo,
			       struct devhost_dev_pm_ops *pmops);

/* net capable */
struct netdev_status;
struct devhost_net_ops {
	int (*net_tx)(unsigned long flags, unsigned int payload_len, unsigned int size,
		      unsigned int offset, struct device_info *info);
	int (*show_status)(struct device_info *info, struct netdev_status *p);
	int (*driver_ioctl)(struct device_info *info, int request, unsigned long args);
};

/* requirement: `flags == !DEVICE_CAN_PROBE` */
void devhost_device_capable_net(struct device_info *devinfo,
				struct devhost_net_ops *netops);

/* posix-clock capable */
struct timex;
struct timespec;
struct devhost_posix_clock_ops {
	int (*clock_adjtime)(unsigned long long file_id, struct timex *tx);
	int (*clock_gettime)(unsigned long long file_id, struct timespec *tp);
	int (*clock_getres) (unsigned long long file_id, struct timespec *tp);
	int (*clock_settime)(unsigned long long file_id, const struct timespec *tp);
};

/* requirement:
 *  - flags == !DEVICE_CAN_PROBE
 *  - vfs_mode == MODE_CHR
 *  - devt != 0
 */
void devhost_device_capable_pclk(struct device_info *devinfo,
				 struct devhost_posix_clock_ops *clkops);

struct driver_private;
typedef struct hm_driver {
	struct driver_private *p;
	char *libname;
	/* this function is used to release the owner of hm_driver or hm_driver itself */
	void (*release)(struct hm_driver *drv);
} hm_driver_t;

/* driver APIs */
struct device_create_args {
	int parent_devid;
	const void *resource;
	size_t resource_size;
};
typedef struct hm_driver_ops {
	int (*bind)(void *ctx, struct device_info *dev);
	int (*create)(void *ctx, const char *name,
		      const struct device_create_args *args,
		      struct device_info **info_out);
	void **owner;
} hm_driver_ops_t;

int devhost_driver_init(hm_driver_t *drv, const struct hm_driver_ops *ops, void *ctx);
void devhost_driver_destroy(hm_driver_t *drv);
int devhost_driver_register(hm_driver_t *drv);
int devhost_driver_add_compat(hm_driver_t *drv, const char *compat, size_t compat_len);

int devhost_register_driver(const char *libname, const struct hm_driver_ops *ops, void *ctx);
void devhost_drv_put(struct hm_driver *drv);

/* this function will increase drv`s refcnt */
int devhost_acquire_driver(const char *compat, hm_driver_t **pdrv);

/* iov support */
int devhost_iov_add_device(int iov_ctrl_id, unsigned int device);
int devhost_iov_attach_device(int iov_ctrl_id, unsigned int device);
int devhost_iov_bind_vspace(int iov_ctrl_id, unsigned int device, int pid, int *pasid);
int devhost_iov_unbind_vspace(int iov_ctrl_id, unsigned int device, int pid, int pasid);

#endif /* __DEVHOST_API_DEVICE_H__ */
