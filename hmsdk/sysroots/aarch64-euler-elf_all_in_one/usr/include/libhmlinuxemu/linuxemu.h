/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Library interface of Linux syscall emulation
 * Author: Huawei OS Kernel Lab
 * Create: Mon May 18 03:49:00 2020
 */

#ifndef ULIBS_LIBHMLINUXEMU_LINUXEMU_H
#define ULIBS_LIBHMLINUXEMU_LINUXEMU_H

#include <hongmeng/errno.h>

extern int hmlinuxemu_install_handler(const void *pc, const void *sp);
extern int hmlinuxemu_get_callsite(void **p_pc, void **p_sp);
extern int hmlinuxemu_set_callsite(const void *pc, const void *sp);
extern int hmlinuxemu_get_spsr(unsigned long *p_spsr);
extern int hmlinuxemu_set_spsr(unsigned long spsr);

#endif
