/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: APIs of libpolicy provided by security service
 * Author: Huawei OS Kernel Lab
 * Create: Thu Sep 19 11:01:37 CST 2019
 */
#ifndef __LIBPOLICY_API_H_
#define __LIBPOLICY_API_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <policy_def.h>
#include <hmkernel/strict.h>
#include <libsecplc/policy_fmt.h>
#include <inttypes.h>

typedef uint64_t type_id_t;

int get_sub_id_by_path(const char *path, uint64_t *sub_id);
bool get_type_transition(uint64_t sub_id, uint64_t obj_id, enum action_def act_id, uint64_t *tgt_id);
bool check_te_policy(uint64_t sub_type, uint64_t obj_type,
		     uint64_t act);
bool check_ability(uint64_t sub_type, enum ability_def ablty);
bool check_mrange(uint64_t sub_type, mrange_t *mrange);
int policy_init(void *policy, size_t sz);
void *policy_mmap(const char *file_name, size_t *sz);
void policy_munmap(void *addr, size_t sz);
int check_type_id(type_id_t id);
bool check_and_export_abilities(uint64_t sub_type, ability_t *exp_ablty, ability_t *avail_ablty,
				ability_t *log_avial_ablty);
const char *sec_plc_def2str(uint64_t sub_id, enum POLICY_DESC_TYPE policy_type);
uint64_t sec_plc_str2def(const char *type_name);

static inline bool ability_set_check(const ability_t *ablty, enum ability_def ability)
{
	uint64_t i = (uint64_t)ability / ABILITY_BITS_PER_ELEMENT;

	return ____IS(ablty->ability[i] & ((uint64_t)1 << ((uint64_t)ability % ABILITY_BITS_PER_ELEMENT)));
}

static inline void ability_set_add(ability_t *ablty, enum ability_def ability)
{
	uint64_t i = (uint64_t)ability / ABILITY_BITS_PER_ELEMENT;

	ablty->ability[i] = ablty->ability[i] | ((uint64_t)1 << ((uint64_t)ability % ABILITY_BITS_PER_ELEMENT));

	return;
}

static inline const char* sec_plc_get_type_name(uint64_t type_id)
{
	return sec_plc_def2str(type_id, TYPY_DEF_DESC);
}

static inline const char* sec_plc_get_ability_name(uint64_t ability_id)
{
	return sec_plc_def2str(ability_id, ABILITY_DEF_DESC);
}

static inline const char* sec_plc_get_action_name(uint64_t action_id)
{
	return sec_plc_def2str(action_id, ACTION_DEF_DESC);
}

bool sec_plc_check_port_range(uint64_t sub_type, const sec_plc_port_range_t *range);
int sec_plc_iter_port_range_start(enum type_def subj, struct sec_plc_port_range_iterator *it);
void sec_plc_iter_port_range_next(struct sec_plc_port_range_iterator *it);
int sec_plc_iter_port_range_get(const struct sec_plc_port_range_iterator *it,
				sec_plc_port_range_t *range);
int sec_plc_port_range_get_reserved(struct sec_plc_port_range_iterator *it);

int sec_plc_set_mode(unsigned int mode);
int sec_policy_chksum(uint8_t* chksum, size_t len);
int sec_u8_to_hex_str(char* str_chksum, size_t str_len, const uint8_t* chksum, size_t len);
unsigned int sec_plc_mode(void);
const char* sec_plc_mode2str(unsigned int plc_mode);
bool sec_plc_mode_is_disable(void);
bool sec_plc_mode_is_permissive(void);
bool sec_plc_mode_is_pmsv_cache(void);  // permissive_cache mode

#define POLICY_NAME "policy.db"
#define POLICY_SHM "policydb"
#endif
