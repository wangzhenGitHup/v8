/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jun 03 11:10:40 2019
 */
#ifndef _VEM_INIT_H_
#define _VEM_INIT_H_

#include <lib/dlist.h>

typedef void (*type_init_fn)(void);

#define type_init(function)						  \
static void __attribute__((constructor)) do_venom_init_##function(void) \
{									  \
	register_type_init(function);					  \
}

typedef struct init_entry {
	type_init_fn init;
	struct dlist_node node;
} init_entry_t;

void register_type_init(type_init_fn fn);
/* init virtual entity model with vem_init_call function */
void vem_init_call(void);
void vem_uninit_call(void);
#endif
