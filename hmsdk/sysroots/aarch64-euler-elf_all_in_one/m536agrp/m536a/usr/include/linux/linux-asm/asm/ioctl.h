/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: add linux/linux-asm/asm/ioctl.h to compat linux interface
 * Author: Huawei OS Kernel Lab
 * Create: Mon Nov 15 16:33:42 2021
 */

#ifndef LINUX_ASM_IOCTL_H
#define LINUX_ASM_IOCTL_H

#define _IOC_NRBITS	8
#define _IOC_TYPEBITS	8

#ifndef _IOC_SIZEBITS
#define _IOC_SIZEBITS	14
#endif

#define _IOC_NRSHIFT	0
#define _IOC_TYPESHIFT	(_IOC_NRSHIFT+_IOC_NRBITS)
#define _IOC_SIZESHIFT	(_IOC_TYPESHIFT+_IOC_TYPEBITS)
#define _IOC_DIRSHIFT	(_IOC_SIZESHIFT+_IOC_SIZEBITS)


#ifndef _IOC_NONE
#define _IOC_NONE	0U
#endif

#ifndef _IOC_WRITE
#define _IOC_WRITE	1U
#endif

#ifndef _IOC_READ
#define _IOC_READ	2U
#endif

#define _IOC(dir,type,nr,size) \
	(((dir)  << _IOC_DIRSHIFT) | \
	((type) << _IOC_TYPESHIFT) | \
	((nr)   << _IOC_NRSHIFT) | \
	((size) << _IOC_SIZESHIFT))

#ifndef __KERNEL__
#define _IOC_TYPECHECK(t) (sizeof(t))
#endif

#define _IO(type,nr)		_IOC(_IOC_NONE,(type),(nr),0)
#define _IOR(type,nr,size)	_IOC(_IOC_READ,(type),(nr),(_IOC_TYPECHECK(size)))
#define _IOW(type,nr,size)	_IOC(_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))
#define _IOWR(type,nr,size)	_IOC(_IOC_READ|_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))

#endif
