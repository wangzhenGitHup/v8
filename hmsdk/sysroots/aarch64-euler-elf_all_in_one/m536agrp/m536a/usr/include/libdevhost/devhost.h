/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: libdh prototypes for devhost core support
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jan 21 17:11:57 2020
 */
#ifndef ULIBS_LIBDEVHOST_DEVHOST_H
#define ULIBS_LIBDEVHOST_DEVHOST_H

#include <stdlib.h>
#include <asm/page.h>

#include <hongmeng/errno.h>
#include <hongmeng/syscall.h>
#include <libhmsrv_io/type.h>

/* libdh actvpool default config */
#define LIBDH_ACTV_STACK_ORDER		1UL /* 8K */
#define LIBDH_ACTV_STACK_SIZE		(1UL << (LIBDH_ACTV_STACK_ORDER + (unsigned long)PAGE_SHIFT))
#define LIBDH_ACTV_NUM_MAX		8
#define LIBDH_ACTV_BUF_SIZE		2048UL
#define LIBDH_ACTV_TSD_SIZE		128U

/*
 * Register to devmgr as a libdevhost with exist actvpool.
 *
 * Parameters:
 *  - name		name of this devhost
 *  - ap_cref		actvpool cref with required sysif handler
 *  - flags		devhost flags:
 *  			  - DH_FLAGS_STANDALONE standalone devhost
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
int libdh_init_ap(const char *name, cref_t ap_cref, unsigned int flags);

/*
 * Create actvpool for libdh
 *
 * Parameters:
 *  - name			actvpool name
 *  - actv_nr			actv number
 *  - stack_size		actv stack size
 *  - recv_buf_size		actv recvbuf size
 *  - ap_cref_out	[OUT]	created actvpool cref
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
int libdh_ap_create(const char *name, int actv_nr,
		    size_t stack_size, size_t recv_buf_size,
		    cref_t *ap_cref_out);

static inline
__hmerr_t libdh_ap_create_default(const char *name, cref_t *ap_cref /* out */)
{
	return libdh_ap_create(name, LIBDH_ACTV_NUM_MAX,
			       LIBDH_ACTV_STACK_SIZE, LIBDH_ACTV_BUF_SIZE,
			       ap_cref);
}

/*
 * Grant libdh actvpool to target
 *
 * Parameters:
 *  - tgt_rref		target rref
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
uref_t libdh_ap_grant(rref_t tgt_rref);

/*
 * Register to devmgr as a libdevhost with new actvpool.
 *
 * Parameters:
 *  - name		name of this devhost
 *  - flags		devhost flags, check libdh_init_ap() for details
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
static inline
int libdh_init(const char *name, unsigned int flags)
{
	cref_t ap_cref;
	int ret;

	ret = libdh_ap_create_default(name, &ap_cref);
	if (ret == E_HM_OK) {
		ret = libdh_init_ap(name, ap_cref, flags);
	}
	return ret;
}

rref_t libdh_get_devmgr_ap(void);
unsigned int libdh_get_devmgr_cnode_idx(void);

cref_t libdh_get_dh_ap(void);

/*
 * Listen for actvpool elastic event.
 *
 * Parameters:
 *  - ap_cref		actvpool cref
 *  - ready_add_water	actv elastic add water mark
 *  - ready_del_water	actv elastic delete water mark
 *  - stack_size	actv stack size
 *  - recv_buf_size	actv recvbuf size
 *
 * Return E_HM_OK for success, hmerrno for errors.
*/
int libdh_ap_elastic(cref_t ap_cref, unsigned int ready_add_water,
		     unsigned int ready_del_water, size_t stack_size,
		     size_t recv_buf_size);

static inline
int libdh_ap_elastic_default(cref_t ap_cref, unsigned int ready_add_water,
			     unsigned int ready_del_water)
{
	return libdh_ap_elastic(ap_cref, ready_add_water, ready_del_water,
				LIBDH_ACTV_STACK_SIZE, LIBDH_ACTV_BUF_SIZE);
}


/*
 * devt region helpers
 */

/*
 * Register and reserve chrdev region to devmgr.
 * All request to registered chrdev regions will be redirected to
 * this devhost.
 *
 * Parameters:
 *  - major		major to register, 0 for auto selected
 *  - baseminor		first minor to reserved
 *  - minorct		minor count to reserved
 *  - name		identifier for this region
 *  - major_out	[OUT]	major number reserved, only valid when return success
 *  			should equal to major if major is not `0`
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
int libdh_register_chrdev_region(unsigned int major, unsigned int baseminor, int minorct,
				 const char *name, unsigned int *major_out /* out */);

/*
 * Release registered chrdev region.
 * Requests will no longer redirected to this devhost after unregister.
 *
 * Parameters:
 *  - major		major to register, must equal to major returned when register
 *  - baseminor		first minor to release, must equal to baseminor when register
 *  - minorct		minor count to release, must equal to minorct when register
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
void libdh_unregister_chrdev_region(unsigned int major, unsigned int baseminor, int minorct);

/*
 * Register and reserve blkdev region to devmgr.
 * All request to registered blkdev regions will be redirected to
 * this devhost.
 *
 * Parameters:
 *  - major		major to register, 0 for auto selected
 *  - name		identifier for this region
 *  - major_out	[OUT]	major number reserved, only valid when return success.
 *  			should equal to major if major is not `0`
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
int libdh_register_blkdev_region(unsigned int major, const char *name, unsigned int *major_out);

/*
 * Release registered blkdev region.
 * Requests will no longer redirected to this devhost after unregister.
 *
 * Parameters:
 *  - major		major to register, must equal to major returned when register
 *  - baseminor		first minor to release, must equal to baseminor when register
 *  - minorct		minor count to release, must equal to minorct when register
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
void libdh_unregister_blkdev_region(unsigned int major, const char *name);


/*
 * device create helpers
 */

/*
 * Create device to devmgr, the request devt must be registered before.
 *
 * Parameters:
 *  - name		device name
 *  - devt		device number, a.k.a. <major, minor>
 *  - devid_out	[OUT]	device identifier used by fops
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
int libdh_chrdev_create(const char *name, unsigned int devt,
			int *devid_out /* out */);

/*
 * Simple wrapper to libdh_chrdev_add, register chr region and create device.
 *
 * Parameters:
 *  - name		device name
 *  - major		device major, 0 for auto selected
 *  - devid_out	[OUT]	device identifier used by fops
 *  - devt_out	[OUT]	selected devt
 *
 * Return E_HM_OK for success, hmerrno for errors.
 */
int libdh_chrdev_create_simple(const char *name, unsigned int major,
			       int *devid_out /* out */,
			       unsigned int *devt_out /* out */);

#endif	/* ULIBS_LIBDEVHOST_DEVHOST_H */
