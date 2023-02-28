/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Wrappers for methods of secmgr
 * Author: Huawei OS Kernel Lab
 * Create: Tue Oct 15 17:12:05 2019
 */

#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_SECURITY_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_SECURITY_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

struct sec_cred_cfg {
	size_t proc_num;
	size_t groups_num;
	uint32_t cfg_mask;
};

#define MAX_SEC_MOD_NUM 4
#define MAX_SEC_COMP_NUM 4

int hm_sec_cred_cfg(struct sec_cred_cfg *cfg);

int hm_sec_setexeccon(const char *context);

int hm_sec_umask(int mask);

int hm_sec_time_set_clock(void);

/* shared configurations */
int hm_sec_shconf_init(void);
int hm_sec_shconf_set_field(unsigned int field, unsigned int value);

#define HM_SEC_SHCONF_MAP_SIZE 4096
#define HM_SEC_SHCONF_SHM_NAME "sec_shconf"

extern uintptr_t _hm_sec_shconf_base;

#define HM_SEC_SHCONF_OFFSET_KPTR_RESTRICT	0U
#define HM_SEC_SHCONF_OFFSET_AUDIT		1U
#define HM_SEC_SHCONF_OFFSET_AUDIT_PID		4U
#define HM_SEC_SHCONF_OFFSET_AUDIT_SW		8U

/* signature verify state occupies 4 bytes */
#define HM_SEC_SHCONF_OFFSET_SIG_VERIF		12U
/* crl control occupies hm_sec_shconf_crl_cfg width bytes */
#define HM_SEC_SHCONF_OFFSET_CRL_CTRL		16U

struct hm_sec_shconf_crl_cfg {
	uint32_t seq_lock;
	uint32_t raw_shm_nm;
	size_t raw_crl_sz;
	size_t real_space;
};

static inline struct hm_sec_shconf_crl_cfg *hm_sec_shconf_crl_ctrl(void)
{
	return (struct hm_sec_shconf_crl_cfg *)(_hm_sec_shconf_base + HM_SEC_SHCONF_OFFSET_CRL_CTRL);
}

#define HM_SEC_SHCONF_KPTR_RESTRICT_DISABLE	0U
#define HM_SEC_SHCONF_KPTR_RESTRICT_ENABLE	1U
#define HM_SEC_SHCONF_KPTR_RESTRICT_FORCE	2U
#define HM_SEC_SHCONF_KPTR_RESTRICT_MAX		HM_SEC_SHCONF_KPTR_RESTRICT_FORCE

static inline uint8_t *hm_sec_shconf_kptr_restrict(void)
{
	return (uint8_t *)(_hm_sec_shconf_base + HM_SEC_SHCONF_OFFSET_KPTR_RESTRICT);
}

#define HM_SEC_SHCONF_AUDIT_DISABLE	0U
#define HM_SEC_SHCONF_AUDIT_ENABLE	1U
#define HM_SEC_SHCONF_AUDIT_ENABLE_LOCK	2U

#define HM_SEC_SHCONF_AUDIT_SW_DISABLE		0U
#define HM_SEC_SHCONF_AUDIT_SW_ENABLE		1U

#define HM_SEC_AUDIT_SW_ENABLED		"enabled"

static inline uint8_t *hm_sec_shconf_audit(void)
{
	return (uint8_t *)(_hm_sec_shconf_base + HM_SEC_SHCONF_OFFSET_AUDIT);
}

static inline uint32_t *hm_sec_shconf_audit_pid(void)
{
	return (uint32_t *)(_hm_sec_shconf_base + HM_SEC_SHCONF_OFFSET_AUDIT_PID);
}

#define HM_SEC_POLICY_MODE_LEN 32U
#define HM_SEC_POLICY_MODE_NORMAL_STR "normal"
#define HM_SEC_POLICY_MODE_BYPASS_STR "bypass"
#define HM_SEC_POLICY_MODE_NORMAL 0U
#define HM_SEC_POLICY_MODE_BYPASS 1U

#define HM_SEC_SHCONF_DTS_STRING_LEN 32U

#define HM_SEC_SHCONF_DTS_SIG_TYPE_SHA256 "sha256"
#define HM_SEC_SHCONF_DTS_SIG_TYPE_CMS "cms"

#define HM_SEC_SHCONF_DTS_SIG_MODE_DISABLED "disabled"
#define HM_SEC_SHCONF_DTS_SIG_MODE_ENFORCING "enforcing"
#define HM_SEC_SHCONF_DTS_SIG_MODE_PERMISSIVE "permissive"

#define HM_SEC_SHCONF_SIG_FEATURE_DISABLED 0U
#define HM_SEC_SHCONF_SIG_FEATURE_ENABLED 1U
#define HM_SEC_SHCONF_SIG_FEATURE_MASK HM_SEC_SHCONF_SIG_FEATURE_ENABLED

#define HM_SEC_SHCONF_SIG_TYPE_OFFSET 1U
#define HM_SEC_SHCONF_SIG_SHA256 0U
#define HM_SEC_SHCONF_SIG_CMS 1U
#define HM_SEC_SHCONF_SIG_TYPE_MASK (HM_SEC_SHCONF_SIG_CMS << HM_SEC_SHCONF_SIG_TYPE_OFFSET)

#define HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_OFFSET 2U
#define HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_MASK 3U
#define HM_SEC_SHCONF_SIG_DISABLED 0U
#define HM_SEC_SHCONF_SIG_ENFORCING 1U
#define HM_SEC_SHCONF_SIG_PERMISSIVE 2U

#define hm_sec_shconf_sig_is_cms_enable(value) (((value) & HM_SEC_SHCONF_SIG_FEATURE_ENABLED) != 0U && \
	((value) & (HM_SEC_SHCONF_SIG_CMS << HM_SEC_SHCONF_SIG_TYPE_OFFSET)) != 0U)

#define hm_sec_shconf_sig_is_sha256_enable(value) (((value) & HM_SEC_SHCONF_SIG_FEATURE_ENABLED) != 0U && \
	((value) & (HM_SEC_SHCONF_SIG_CMS << HM_SEC_SHCONF_SIG_TYPE_OFFSET)) == 0U)


#define hm_sec_shconf_sig_dyn_enforce(mode) (((mode) & \
	(HM_SEC_SHCONF_SIG_FEATURE_MASK | HM_SEC_SHCONF_SIG_TYPE_MASK)) | \
	(HM_SEC_SHCONF_SIG_ENFORCING << HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_OFFSET))

#define hm_sec_shconf_sig_dyn_permissive(mode) (((mode) & \
	(HM_SEC_SHCONF_SIG_FEATURE_MASK | HM_SEC_SHCONF_SIG_TYPE_MASK)) | \
	(HM_SEC_SHCONF_SIG_PERMISSIVE << HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_OFFSET))

static inline uint32_t *hm_sec_shconf_raw_sig_mode(void)
{
	return (uint32_t *)(_hm_sec_shconf_base + HM_SEC_SHCONF_OFFSET_SIG_VERIF);
}

/* need init signature resource: cms should initialize crl */
static inline bool hm_sec_shconf_sig_need_init(void)
{
	// only need init both sig verify enabled and choose cms mode.
	bool ret = false;
	uint32_t value = *hm_sec_shconf_raw_sig_mode();
	if (hm_sec_shconf_sig_is_cms_enable(value)) {
		ret = true;
	}
	return ret;
}

/* get dynamic cms verify mode: depends on enable from dts and choose cms from dts */
static inline uint32_t hm_sec_shconf_cms_verif_mode(void)
{
	uint32_t ret = HM_SEC_SHCONF_SIG_DISABLED;
	uint32_t value = *hm_sec_shconf_raw_sig_mode();
	if (hm_sec_shconf_sig_is_cms_enable(value)) {
		// when cms sig enabled
		ret = (value >> HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_OFFSET) & HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_MASK;
	}
	return ret;
}

/* get dynamic sha256 verify mode: depends on enable from dts and choose sha256 from dts */
static inline uint32_t hm_sec_shconf_sha256_verif_mode(void)
{
	uint32_t ret = HM_SEC_SHCONF_SIG_DISABLED;
	uint32_t value = *hm_sec_shconf_raw_sig_mode();
	if (hm_sec_shconf_sig_is_sha256_enable(value)) {
		// when sha256 sig enabled
		ret = (value >> HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_OFFSET) & HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_MASK;
	}
	return ret;
}

/* get dynamic signature verify mode: only depends on enable from dts */
static inline uint32_t hm_sec_shconf_sig_verif_mode(void)
{
	uint32_t ret = HM_SEC_SHCONF_SIG_DISABLED;
	uint32_t value = *hm_sec_shconf_raw_sig_mode();
	/* when enabled from dts */
	if ((value & HM_SEC_SHCONF_SIG_FEATURE_ENABLED) != 0U) {
		ret = (value >> HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_OFFSET) & HM_SEC_SHCONF_SIG_DYNAMIC_SWTICH_MASK;
	}
	return ret;
}

static inline uint8_t *hm_sec_shconf_audit_sw(void)
{
	return (uint8_t *)(_hm_sec_shconf_base + HM_SEC_SHCONF_OFFSET_AUDIT_SW);
}

void hm_sec_policy_set_mode(uint32_t mode);
uint32_t hm_sec_policy_get_mode(void);

#endif
