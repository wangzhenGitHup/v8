/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Some user level api of tty to export
 * Author: Huawei OS Kernel Lab
 * Create: Tue Apr 07 12:11:57 2020
 */
#ifndef ULIBS_LIBTTY_TTY_H
#define ULIBS_LIBTTY_TTY_H

/* HONGMENG TTY defined ioctl cmd */
#define TTY_ENABLE_NONBLOCK 0x1001
#define TTY_DISABLE_NONBLOCK 0x1002
#define TTY_RESET_SETTING 0x1003
#define TTY_SERIAL_CONTROL 0x1004
#define TTY_SERIAL_OOFF 0x0
#define TTY_SERIAL_OON 0x1
#define TTY_SERIAL_IOFF 0x2
#define TTY_SERIAL_ION 0x3

#endif	/* ULIBS_LIBTTY_TTY_H */
