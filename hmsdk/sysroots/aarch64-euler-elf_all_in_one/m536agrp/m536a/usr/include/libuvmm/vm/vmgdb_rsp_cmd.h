/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Wed Apr 25 10:28:39 2021
 */

#ifndef HM_UVMM_VM_VMGDB_RSP_CMD_H
#define HM_UVMM_VM_VMGDB_RSP_CMD_H

#include <errno.h>
#include <libhmlog/hmlog.h>
#include <hongmeng/errno.h>

#include "vm.h"

/* Since 0 indicates any gdb process, the pid starts from 1 */
#define FIRST_GDB_PROCESS_PID (1U)

enum gdb_signal {
	GDB_SIGNAL_INT = 2,
	GDB_SIGNAL_TRAP = 5,
};

int vmgdb_rsp_cmd_init(vm_t *vm);
void vmgdb_rsp_cmd_cleanup(void);
bool is_gdb_state_vm_running(void);
void pause_vm_and_notify_gdb(enum gdb_signal signal);
void gdb_set_stop_vcpu(vcpu_t *vcpu);

#endif
