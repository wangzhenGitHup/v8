/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Credential define head file
 * Author: Huawei OS Kernel Lab
 * Create: Thu Apr 25 10:49:14 2019
 */
#ifndef ULIBS_LIBSEC_CRED_H
#define ULIBS_LIBSEC_CRED_H
// hongmeng
#include <libhmlog/hmlog.h>
// security
#include "chk.h"
#include "cred_common.h"
#include "posix_cap_def.h"

#ifndef SEC_PLC_PERMISSIVE_CACHE
#define SEC_PLC_PERMISSIVE_CACHE
#endif

#define SEC_SUPPORT_MAC_BIT 1U
#define SEC_SUPPORT_DAC_BIT 2U
#define SEC_SUPPORT_CAP_BIT 4U
#define SEC_SUPPORT_AUDITBIT 8U

#define sec_deny_log(fmt...) __hmlog(HMLOG_INFO, fmt)

#define sec_dac_deny_log(fmt...) __hmlog(HMLOG_DEBUG, fmt)

#define SEC_BASIC_SYS_SRVC 1u

#define SEC_DEFAULT_UID __U(0)
#define SEC_DEFAULT_GID __U(0)

struct sec_cred_basic {
	pid_t pid;
	pid_t ppid;
	uint32_t flags;
};

struct sec_cred_mac {
	uint64_t sid;
};

struct sec_cred_caps {
	posix_cap_t inher_cap;
	posix_cap_t perm_cap;
	posix_cap_t eff_cap;
	posix_cap_t bset_cap;
	posix_cap_t amb_cap;
	unsigned secure_bits;
};

struct sec_cred_groups {
	uint32_t shm_idx;
	uint32_t offset;
	uint32_t size;
};

struct sec_cred_dac {
	uid_t			ruid;
	gid_t			rgid;
	uid_t			euid;
	gid_t			egid;
	uid_t			suid;
	gid_t			sgid;
	uid_t			fsuid;
	gid_t			fsgid;
	struct sec_cred_groups	groups;
	uint8_t			dumpable;
	mode_t			umask;
};

struct sec_cred_str {
	uint32_t shm_idx;
	uint32_t offset;
	uint32_t size;
};

struct sec_cred_audit {
	/* TODO completed */
	uid_t	login_uid;
	uid_t	session_id;
	struct sec_cred_str cmdline;
};

struct sec_cred_keyring {
	void *proc_keyring_addr;
	void *ses_keyring_addr;
};

struct group_search_args {
	gid_t gid;      /* object gid, such as files and native objects */
	gid_t proc_gid; /* gid of the process which will be searched */
};

extern struct sht_mod g_sec_cred_basic_mod;
extern struct sht_mod g_sec_cred_mac_mod;
extern struct sht_mod g_sec_cred_caps_mod;
extern struct sht_mod g_sec_cred_dac_mod;
extern struct sht_mod g_sec_cred_audit_mod;
extern struct sht_mod g_sec_cred_keyring_mod;

static inline struct sec_cred_basic *sec_cred_basic(sht_idx_t node)
{
	return (struct sec_cred_basic *)sht_mod_ref(&g_sec_cred_basic_mod, node);
}

static inline struct sec_cred_mac *sec_cred_mac(sht_idx_t node)
{
	return (struct sec_cred_mac *)sht_mod_ref(&g_sec_cred_mac_mod, node);
}

static inline struct sec_cred_caps *sec_cred_caps(sht_idx_t node)
{
	return (struct sec_cred_caps *)sht_mod_ref(&g_sec_cred_caps_mod,
						   node);
}

static inline struct sec_cred_dac *sec_cred_dac(sht_idx_t node)
{
	return (struct sec_cred_dac *)sht_mod_ref(&g_sec_cred_dac_mod, node);
}

static inline struct sec_cred_audit *sec_cred_audit(sht_idx_t node)
{
	return (struct sec_cred_audit *)sht_mod_ref(&g_sec_cred_audit_mod, node);
}

static inline struct sec_cred_keyring *sec_cred_keyring(sht_idx_t node)
{
	return (struct sec_cred_keyring *)sht_mod_ref(&g_sec_cred_keyring_mod, node);
}

static inline int sec_cred_check_expiration(const struct sec_chk_cred *chk)
{
	return sec_cred_retry(chk->node, chk->seq) ? E_HM_SRCH : E_HM_OK;
}

static inline int sec_cred_read_basic(const struct sec_chk_cred *chk,
				      struct sec_cred_basic *cred)
{
	int rc = sht_mod_read(&g_sec_cred_basic_mod, chk->node, cred);
	if (rc == E_HM_OK) {
		rc = sec_cred_check_expiration(chk);
	}
	return rc;
}

static inline int sec_cred_read_mac(const struct sec_chk_cred *chk,
				    struct sec_cred_mac *cred)
{
	int rc = sht_mod_read(&g_sec_cred_mac_mod, chk->node, cred);
	if (rc == E_HM_OK) {
		rc = sec_cred_check_expiration(chk);
	}
	return rc;
}

static inline int sec_cred_read_posix_cap(const struct sec_chk_cred *chk,
					  struct sec_cred_caps *cred)
{
	int rc = sht_mod_read(&g_sec_cred_caps_mod, chk->node, cred);
	if (rc == E_HM_OK) {
		rc = sec_cred_check_expiration(chk);
	}
	return rc;
}

static inline int sec_cred_read_dac(const struct sec_chk_cred *chk,
				    struct sec_cred_dac *cred)
{
	int rc = sht_mod_read(&g_sec_cred_dac_mod, chk->node, cred);
	if (rc == E_HM_OK) {
		rc = sec_cred_check_expiration(chk);
	}
	return rc;
}

int sec_cred_dac_groups_check(sht_idx_t node, void *arg);

static inline int sec_cred_read_dac_groups(const struct sec_chk_cred *chk,
					   void *value, int *result)
{
	struct sht_mod_cb_arg arg;
	struct sht_mod *mod = &g_sec_cred_dac_mod;
	int rc = E_HM_INVAL;

	if (value != NULL) {
		arg.value = value;
		arg.mod = mod;

		rc = sht_read(mod->sht, chk->node, sec_cred_dac_groups_check, &arg, result);
	}

	return rc;
}

static inline int sec_cred_read_audit(const struct sec_chk_cred *chk,
				      struct sec_cred_audit *cred)
{
	int rc = sht_mod_read(&g_sec_cred_audit_mod, chk->node, cred);
	if (rc == E_HM_OK) {
		rc = sec_cred_check_expiration(chk);
	}
	return rc;
}

static inline int sec_cred_read_keyring(const struct sec_chk_cred *chk,
					struct sec_cred_keyring *cred)
{
	int rc = sht_mod_read(&g_sec_cred_keyring_mod, chk->node, cred);
	if (rc == E_HM_OK) {
		rc = sec_cred_check_expiration(chk);
	}
	return rc;
}

typedef void (*sec_chk_show_extra)(const struct sec_chk_cred *cred, const void *arg);

/* Extra log handler usually logging object information such as process name and etc.. */
struct sec_log_extra_info {
	sec_chk_show_extra func;
	const void *arg;
};

int sec_cred_groups_search(const gid_t *group_list, uint32_t size, gid_t gid);

#endif /* ifndef ULIBS_LIBSEC_CRED_H */
