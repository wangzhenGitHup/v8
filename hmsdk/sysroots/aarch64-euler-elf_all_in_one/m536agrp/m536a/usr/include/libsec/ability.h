/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Provide ability check functions
 * Author: Huawei OS Kernel Lab
 * Create: Wed May 08 11:18:53 2019
 */
#ifndef ULIBS_LIBSEC_ABILITY_H
#define ULIBS_LIBSEC_ABILITY_H

#include <libhmlog/hmlog.h>
#include <libpolicy_api.h>
#include <policy_def.h>
#include "log.h"
#include "module.h"
#include "cred.h"
#include "method/para.h"
#include "method/var.h"
#include "method/unused_var.h"
#include "ability_hierachy.h"

extern struct sec_mod sec_mod_ability;

#define SEC_DEFINE_ABILITY(NAME, _ARG)						\
static int _sec_chk_ability_##NAME(const struct sec_chk_cred *cred,		\
				   const struct sec_cred_mac *mac_cred PARA(_ARG));\
static int sec_chk_ability_##NAME(const struct sec_chk_cred *cred PARA(_ARG))	\
{										\
	struct sec_cred_mac mac = {0};						\
	int rc;									\
	rc = sec_cred_read_mac(cred, &mac);					\
	if (rc >= 0) {								\
		rc = _sec_chk_ability_##NAME(cred, &mac VAR(_ARG));		\
	}									\
	return rc;								\
}										\
static int _sec_chk_ability_##NAME(const struct sec_chk_cred *cred,		\
				   const struct sec_cred_mac *mac_cred PARA(_ARG))

#define SEC_DEFINE_FWD_CRED_ABILITY(NAME, _ARG)					\
static int _sec_chk_ability_##NAME(const struct sec_chk_cred *cred,		\
				   const struct sec_cred_mac *mac_cred		\
				   PARA(_ARG));					\
static int sec_chk_ability_##NAME(struct sec_chk_cred_xact *cred PARA(_ARG))	\
{										\
	struct sec_chk_cred *fwd_cred = NULL;					\
	struct sec_cred_mac mac = {0};						\
	int rc;									\
	fwd_cred = sec_chk_fwd_cred(cred);					\
	if (fwd_cred == NULL) {							\
		rc = E_HM_SRCH;							\
	} else {								\
		rc = sec_cred_read_mac(fwd_cred, &mac);				\
	}									\
	if (rc == E_HM_OK) {							\
		rc = _sec_chk_ability_##NAME(fwd_cred, &mac VAR(_ARG));		\
	}									\
	return rc;								\
}										\
static int _sec_chk_ability_##NAME(const struct sec_chk_cred *cred,		\
				   const struct sec_cred_mac *mac_cred		\
				   PARA(_ARG))

#define sec_define_ability_method(METHOD)					\
	sec_define_chk_method(METHOD, sec_chk_ability_##METHOD)

bool sec_check_ability_failed(const struct sec_chk_cred *cred, uint64_t subj, enum ability_def ability);

static inline bool sec_check_ability(const struct sec_chk_cred *cred,
				     uint64_t subj, enum ability_def ability)
{
	bool check_passed = true;

	if (!check_ability(subj, ability)) {
		check_passed = sec_check_ability_failed(cred, subj, ability);
	}

	return check_passed;
}

bool sec_check_ability_extra_failed(const struct sec_chk_cred *cred,
				    uint64_t subj, enum ability_def ability,
				    sec_chk_show_extra func, const void *arg);

static inline bool sec_check_ability_extra(const struct sec_chk_cred *cred,
					   uint64_t subj, enum ability_def ability,
					   sec_chk_show_extra func, const void *arg)
{
	bool check_passed = true;

	if (!check_ability(subj, ability)) {
		check_passed = sec_check_ability_extra_failed(cred, subj, ability, func, arg);
	}

	return check_passed;
}

#define SEC_DEFINE_ABILITY_DEFAULT(NAME, _ARG, ABILITY)				\
SEC_DEFINE_ABILITY(NAME, _ARG)							\
{										\
	UNUSED_VAR(_ARG);							\
	return sec_check_ability_extra(cred, mac_cred->sid, ABILITY,		\
				       sec_chk_show_obj_name, NULL) ? 		\
		E_HM_OK : E_HM_ACCES;						\
}

// check ability of fwd credential in a transaction
#define SEC_DEFINE_FWD_CRED_ABILITY_DEFAULT(NAME, _ARG, ABILITY)	\
SEC_DEFINE_FWD_CRED_ABILITY(NAME, _ARG)					\
{									\
	UNUSED_VAR(_ARG);						\
	return sec_check_ability_extra(cred, mac_cred->sid, ABILITY,	\
				       sec_chk_show_obj_name, NULL) ? 	\
		E_HM_OK : E_HM_ACCES;					\
}

int sec_check_abilities_failed(const struct sec_chk_cred *cred,
			       const struct sec_cred_mac *mac_cred,
			       const ability_t *missed_ab,
			       sec_chk_show_extra show_proc);

/*
 * caculate the missed abililites from available and expected abilities
 */
static inline void sec_calc_missed_abilities(const ability_t *exp_ablty,
					     const ability_t *avail_ablty,
					     ability_t *missed_ab)
{
	for (unsigned int i = 0; i < ABILITY_WIDTH; i++) {
		missed_ab->ability[i] = (avail_ablty->ability[i] | exp_ablty->ability[i]) ^
					avail_ablty->ability[i];
	}
}

static inline int sec_do_chk_and_exp_abilities(const struct sec_chk_cred *cred,
					       const struct sec_cred_mac *mac_cred,
					       ability_t *exp_ablty,
					       ability_t *avail_ablty)
{
	int ret = E_HM_OK;

	ability_t log_avail_ab = {0};
	if (!check_and_export_abilities(mac_cred->sid, exp_ablty, avail_ablty, &log_avail_ab)) {
		ability_t missed_ab = {0};
		sec_calc_missed_abilities(exp_ablty, &log_avail_ab, &missed_ab);
		ret = sec_check_abilities_failed(cred, mac_cred, &missed_ab, NULL);
	}

	return ret;
}

static inline int sec_check_and_export_abilities(const struct sec_chk_cred *cred,
						 ability_t *exp_ablty,
						 ability_t *avail_ablty)
{
	struct sec_cred_mac mac_cred = {0};
	int ret;

	ret = sec_cred_read_mac(cred, &mac_cred);
	if (ret == E_HM_OK) {
		ret = sec_do_chk_and_exp_abilities(cred, &mac_cred,
						   exp_ablty, avail_ablty);
	}
	return ret;
}

static inline int sec_chk_export_abilities(const struct sec_chk_cred *cred,
					   const struct sec_cred_mac *mac_cred,
					   ability_t *exp_ab, ability_t *avail_ab,
					   sec_chk_show_extra show_proc)
{
	int ret = E_HM_OK;

	ability_t log_avail_ab = {0};
	if (!check_and_export_abilities(mac_cred->sid, exp_ab, avail_ab, &log_avail_ab)) {
		ability_t missed_ab = {0};
		sec_calc_missed_abilities(exp_ab, &log_avail_ab, &missed_ab);
		ret = sec_check_abilities_failed(cred, mac_cred, &missed_ab, show_proc);
	}

	return ret;
}

static inline int sec_chk_export_abilities_with_name(const struct sec_chk_cred *cred,
						     ability_t *exp_ablty,
						     ability_t *avail_ablty,
						     sec_chk_show_extra show_proc)
{
	struct sec_cred_mac mac_cred = {0};
	int ret;

	ret = sec_cred_read_mac(cred, &mac_cred);
	if (ret == E_HM_OK) {
		ret = sec_chk_export_abilities(cred, &mac_cred, exp_ablty, avail_ablty,
					       show_proc);
	}

	return ret;
}

#endif
