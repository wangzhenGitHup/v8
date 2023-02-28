/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Sat Nov 24 12:51:01 2018
 */

#ifndef HM_INCLUDE_HMSYSCALL_H
#define HM_INCLUDE_HMSYSCALL_H

/*
 * New added syscall number should be added here.
 *
 * Begins from 400
 *
 */

#define SYS_cpu_getnum 400
#define SYS_mq_close 401
#define SYS_set_thread_area 402
#define SYS_debug_proc_stack_vregion 403
#define SYS_debug_thread_sp 404
#define SYS_getifaddrs 405
#define SYS_gic_ctrl 406
#define SYS_hpi_ctrl 407
#define SYS_proc_check_regs 408
#define SYS_debug_load_symbol 409
#define SYS_debug_unload_symbol 410
#define SYS_debug_addr2sym 411
#define SYS_process_spawn 412
#define SYS_pek_ctrl 413
#define SYS_dopra_tick 500

#define __NR_cpu_getnum 400
#define __NR_mq_close 401
#define __NR_set_thread_area 402
#define __NR_debug_proc_stack_vregion 403
#define __NR_debug_thread_sp 404
#define __NR_getifaddrs 405
#define __NR_gic_ctrl 406
#define __NR_hpi_ctrl 407
#define __NR_proc_check_regs 408
#define __NR_debug_load_symbol 409
#define __NR_debug_unload_symbol 410
#define __NR_debug_addr2sym 411
#define __NR_process_spawn 412
#define __NR_pek_ctrl 413
#define __NR_dopra_tick 500

#endif
