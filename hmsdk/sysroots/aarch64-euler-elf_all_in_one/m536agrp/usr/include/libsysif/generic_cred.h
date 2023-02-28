/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: The common api of generic cred
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jun 30 19:17:51 2020
 */
#ifndef LIBSYSIF_GENERIC_CRED_H
#define LIBSYSIF_GENERIC_CRED_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <lib/dlist.h>
#include <asm/activation.h>
#include <libhmactv/actv.h>
#include <hongmeng/errno.h>
#include <hongmeng/macro.h>
#include <hongmeng/syscall.h>
#include <libhmsync/raw_mutex.h>
#include <libhmsync/raw_scopedptr.h>
#include <libhmsync/raw_mutex_guard.h>
#include <libhmsrv_sys/hm_thread.h>
#include <libhmsrv_sys/hmsrv_sys.h>
#include <libhmsrv_sys/hm_procmgr.h>
#include <libhwsecurec/securec.h>

/*
 * SUB_CRED_TABLE_SIZE is the maximum number of credential entries
 * that an generic_cred_entry supports. Currently only sec_cred occupies
 * one slot in sub cred table.
 */
#define SUB_CRED_TABLE_SIZE 4

/*
 * generic cred records various kinds of credential, which provides cached (and fast)
 * access to multiple kinds of resource related to the client, includeing security
 * credential (mac cred and dac cred) and server specific credentials.
 *
 *
 * kernel_delivered_credential- - - - - - - -> generic_cred_entry
 *							|
 *							|
 * 						 ______\|/_____
 * actvhdlr_foo(sender, credential, ...)        |              |
 *                           ^------------------|-default cred |
 *                                              |______________|
 *                                              |   grant      |
 *                                              |  metadata    |
 *                                              |______________|
 *             struct xxx_cred of sender        |              |
 *                                 ^\           | sub_cred_tbl |
 *                                   \          |(ptrs to cred)|
 *                                    \         |              |
 *                                     \- - - - | - xxx cred   |
 *                                              |              |
 * struct yyy_cred of sender  < - - - - - - - - | - yyy cred   |
 *                                              |    ...       |
 *                                              |______________|
 *
 *
 *        client        |        kernel       |                       server(actvpool)
 * _____________________|_____________________|______________________________________________________________
 *                      |                     | 1. grab refcnt of the kernel delivered credential which
 *       actvcall       |                     |    points to generic_cred_entry of the client
 *                      |   actvpool invoke   | 2. replace the credential with default cred which is passed to:
 *                      |                     |    actvhdlr_foo(sender, credential, ...)
 *                      |                     | 3. execute actvhdlrs
 *                      |                     | 4. put refcnt of the kernel delivered crendential which
 *                      |                     |    points to generic_cred_entry of the client.
 */
struct generic_cred_entry {
	unsigned long default_credential; /* default credential, the credential used in actvhdlrs */
	uint32_t client_cnode_idx; /* cnode idx of the client(grantee) */
	cref_t ap_cref; /* cref of the granted actvpool */
	struct raw_refcnt_nr refcnt; /* protect generic cred entry from UAF */
	struct dlist_node node; /* generic_cred_entries is linked through the node for the ease of management */
	void *sub_cred_table[SUB_CRED_TABLE_SIZE]; /* place for custom credential pointers, e.g. sec_cred_cache */
};

/*
 * global varible which records the number of registered sub cred types, a server
 * can register up-to SUB_CRED_TABLE_SIZE kinds of sub creds.
 */
extern int g_nr_used_sub_cred;

/*
 * mutex to protect the linked list of generic cred entries.
 */
extern struct raw_mutex g_generic_cred_entry_list_mutex;

/*
 * tls variable which points to generic cred entry corresponding
 * to current client
 */
extern __thread struct generic_cred_entry *curr_generic_cred;

/*
 * generic_cred_entry reserved for the server itself.
 */
extern struct generic_cred_entry selfcall_generic_cred;

int hm_set_default_credential(cref_t ap_cref, uref_t uref,
			      unsigned int dst_cnode_idx,
			      unsigned long credential);

void hm_generic_cred_init(void);

uint64_t hm_cred_default(void);

unsigned long hm_grant_info_default(void);

void hm_generic_cred_remove_entry_by_cnode_idx(const uint32_t cnode_idx);

int hm_generic_cred_set_default_cred(unsigned long new_default_cred);

struct generic_cred_entry *
generic_cred_entry_alloc(unsigned long default_credential,
			 uint32_t dst_cnode_idx, cref_t ap_cref);

void generic_cred_entry_del(struct generic_cred_entry* entry);

void generic_cred_entry_put(unsigned long credential);

struct generic_cred_entry* generic_cred_entry_get(unsigned long credential);

int generic_cred_handle_reject(unsigned long long sender,
			       uint32_t u_slot_idx,
			       unsigned long old_credential);

int generic_cred_handle_set_cred(unsigned long long sender,
				 uint32_t u_slot_idx,
				 unsigned long old_credential);

int generic_cred_handle_fwd_xact(unsigned long long sender,
				 unsigned long fwd_xact_cred);

int generic_cred_replace_cred(unsigned long *cred);

int generic_cred_replace_cred_no_get(unsigned long *cred);

bool generic_cred_is_enabled(void);
void generic_cred_set_enable(bool enable);

#define GENERIC_CRED_DECLARE_SUB_CRED(name, cred_type)				\
extern int g_generic_cred_idx_of_##name;					\
int generic_cred_register_sub_cred_##name(void);				\
cred_type* name##_of_current_credential(void);					\
int name##_set_current_credential(cred_type* new_cred);

#define GENERIC_CRED_DEFINE_SUB_CRED(name, cred_type)				\
int g_generic_cred_idx_of_##name = -1;						\
int generic_cred_register_sub_cred_##name(void)					\
{										\
	int err = E_HM_INVAL;							\
	if (generic_cred_is_enabled()) {					\
		RAW_MUTEX_GUARD(_, &g_generic_cred_entry_list_mutex);		\
		if (likely(g_generic_cred_idx_of_##name == -1)) {		\
			g_generic_cred_idx_of_##name = g_nr_used_sub_cred++; 	\
			err = E_HM_OK;						\
		} 								\
	}									\
	return err;								\
}										\
cred_type* name##_of_current_credential(void)					\
{										\
	cred_type* current_##name = NULL;					\
	struct generic_cred_entry *tmp = curr_generic_cred;			\
	if (likely(tmp != NULL)) {						\
		if (unlikely(g_generic_cred_idx_of_##name == -1)) {		\
			hm_panic("uninitialized sub cred idx\n");		\
		}								\
		current_##name = tmp->sub_cred_table[g_generic_cred_idx_of_##name];\
	}									\
	return current_##name;							\
}										\
int name##_set_current_credential(cred_type* new_cred)				\
{										\
	int err = E_HM_INVAL;							\
	if(generic_cred_is_enabled()) {						\
		struct generic_cred_entry *tmp;					\
		tmp = curr_generic_cred;					\
		if ((tmp != NULL) && (g_generic_cred_idx_of_##name != -1)) {	\
			tmp->sub_cred_table[g_generic_cred_idx_of_##name] = new_cred;\
			err = E_HM_OK;						\
		}								\
	}									\
	return err;								\
}
#endif
