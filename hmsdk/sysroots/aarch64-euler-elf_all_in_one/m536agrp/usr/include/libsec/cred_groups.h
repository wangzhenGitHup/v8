/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: DAC groups interfaces
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jan 05 15:36:48 2021
 */
#ifndef ULIB_LIBSEC_CRED_GROUPS_H
#define ULIB_LIBSEC_CRED_GROUPS_H

#include <stdbool.h>
#include <stdint.h>
#include <libshlist/shlist.h>

extern struct shlist g_sec_cred_grp_list;

#define SEC_CRED_GRP_SHM_SIZE 4096u

static inline int sec_cred_grp_init(bool creator)
{
	char dac_grp_prefix[] = "sec_cred_dac_groups_";
	struct shl_config cfg = {
		.shm_prefix = dac_grp_prefix,
		.shm_size = SEC_CRED_GRP_SHM_SIZE
	};
	return shl_init(&g_sec_cred_grp_list, &cfg, creator);
}

static inline void sec_cred_grp_fini(void)
{
	shl_fini(&g_sec_cred_grp_list);
}

static inline struct shl_list_node *sec_cred_grp_alloc(size_t size)
{
	return shl_alloc(&g_sec_cred_grp_list, size);
}

static inline void sec_cred_grp_free(struct shl_list_node *node)
{
	shl_free(&g_sec_cred_grp_list, node);
}

static inline uintptr_t sec_cred_grp_shm_base_of(uint32_t shm_idx)
{
	return shl_shm_base_of(&g_sec_cred_grp_list, shm_idx);
}

#endif /* ifndef ULIB_LIBSEC_GROUPS_H */
