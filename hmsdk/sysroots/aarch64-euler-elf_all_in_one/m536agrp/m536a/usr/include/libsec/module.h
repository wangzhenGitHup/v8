/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Secure module init and finish head file
 * Author: Huawei OS Kernel Lab
 * Create: Wed May 08 11:21:52 2019
 */
#ifndef ULIBS_LIBSEC_MODULE_H
#define ULIBS_LIBSEC_MODULE_H

typedef int (*sec_mod_init_ft)(void);
typedef void (*sec_mod_fini_ft)(void);
struct sec_mod_ops {
	sec_mod_init_ft init;
	sec_mod_fini_ft fini;
};

struct sec_mod {
	const char *name;
	struct sec_mod_ops ops;
};

int sec_mod_init(const struct sec_mod *mod);
void sec_mod_fini(const struct sec_mod *mod);

#endif
