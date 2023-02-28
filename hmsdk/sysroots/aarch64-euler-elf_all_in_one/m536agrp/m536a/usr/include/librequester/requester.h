/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: Requester frame actions head file
 * Author: Huawei OS Kernel Lab
 * Create: Tue Jul 30 18:12:10 2019
 */
#ifndef ULIBS_LIBREQUESTER_REQUESTER_H
#define ULIBS_LIBREQUESTER_REQUESTER_H
// libc
#include <stdbool.h>
// hongmeng
#include <hmkernel/capability.h>
#include <hongmeng/errno.h>
#include <libsysif/utils.h>
#include <libhmucap/ucap.h>

/*
 * We are consistent with activation transaction of the kernel.
 * src: the direct senders transfering the messages
 * fwd: the original senders of forward messages
 */
struct requester {
	uint32_t src_cnode_idx;
	union {
		/* cnode_idx is an alias of fwd_cnode_idx */
		uint32_t fwd_cnode_idx;
		uint32_t cnode_idx;
	};
};

int requester_init(struct requester *req);

enum requester_state_type {
	REQUESTER_DEFAULT,
	REQUESTER_INIT,
	REQUESTER_WORKQUE,
	REQUESTER_FROMSELF
};

struct requester_frame {
	struct requester requester;
	enum requester_state_type requester_state;
};

extern __thread struct requester_frame *t_requester_current_frame;

static inline struct requester_frame *requester_current_frame(void)
{
	return t_requester_current_frame;
}

static inline bool requester_frame_nodefault(const struct requester_frame *req)
{
	struct sec_cred *cred_info = sysif_actv_current_callinfo();
	return req != NULL && req->requester_state != REQUESTER_DEFAULT &&
		cred_info->selfcall_type == __SEC_CRED_NO_SELFCALL;
}

static inline struct requester_frame *requester_frame_replace(
	struct requester_frame *new_frame)
{
	struct requester_frame *old_frame = t_requester_current_frame;
	t_requester_current_frame = new_frame;
	return old_frame;
}

static inline void requester_frame_restore(struct requester_frame *frame)
{
	t_requester_current_frame = frame;
}

static inline void requester_frame_cleanup(struct requester_frame **frame)
{
	requester_frame_restore(*frame);
}

static inline bool requester_frame_is_fromself(void)
{
	return (t_requester_current_frame != NULL &&
		t_requester_current_frame->requester_state == REQUESTER_FROMSELF);
}

/*
 * We can't add do-while wrapper for this macro because of the cleanup attribute
 * depending on the scope.
 */
#define requester_frame_replace_temporarily(REQUESTER, STATE)			\
	struct requester_frame __requester_frame = {				\
		.requester = (REQUESTER),					\
		.requester_state = (STATE)					\
	};									\
	struct requester_frame *__requester_frame_old				\
		__attribute__ ((unused))					\
		__attribute__ ((cleanup(requester_frame_cleanup))) = 		\
			requester_frame_replace(&__requester_frame)

#define requester_frame_replace_begin(REQUESTER, STATE) { \
	requester_frame_replace_temporarily(REQUESTER, STATE)
#define requester_frame_repalce_end() }

int requester_frame_set_init_frame(void);
void requester_frame_rst_init_frame(void);

#endif /* ifndef ULIBS_LIBREQUESTER_REQUESTER_H */
