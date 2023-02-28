/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Inner interfaces of POSIX access control list
 * Author: Huawei OS Kernel Lab
 * Create: Thu Sep 23 05:50:25 2021
 */
#ifndef __POSIX_ACL_H
#define __POSIX_ACL_H

#include <stdbool.h>
#include <sys/types.h>
#include "posix_acl_def.h"

struct sec_cred_dac;
struct sec_chk_cred;
struct sec_posix_acl_obj {
	uid_t uid;
	gid_t gid;
	struct sec_posix_acl *acl;
};

struct sec_posix_acl *sec_posix_acl_alloc(size_t entry_num);
int sec_posix_acl_check(const struct sec_chk_cred *cred,
			const struct sec_cred_dac *dac_cred,
			const struct sec_posix_acl_obj *obj,
			unsigned short mask);
int sec_posix_acl_from_xattr(const char *xattr, size_t size, struct sec_posix_acl **acl);
ssize_t sec_posix_acl_to_xattr(const struct sec_posix_acl *acl, char *xattr, size_t size);
struct sec_posix_acl *sec_posix_acl_dup(const struct sec_posix_acl *acl);
void sec_posix_acl_free(struct sec_posix_acl *acl);
int sec_posix_acl_get(struct sec_posix_acl *acl);
void sec_posix_acl_put(struct sec_posix_acl *acl);
/*
 * from, to
 * true, true: fix acl and mode
 * true, false: acl <- mode
 * false, false: acl -> mode
 * false, false: invalid
 *
 * Only permission bits of modes may be modified.
 *
 * + SEC_POSIX_ACL_TRIVIAL: convert success and `acl` is equivalent with `mode`.
 * + E_HM_OK: convert success and `acl` is not equivalent with `mode`.
 * + E_HM_INVAL: unexpected arguments or combination of arguments.
 */
int sec_posix_acl_convert_mode(struct sec_posix_acl *acl, mode_t *mode,
			       bool from_mode, bool to_mode);

#endif /* ifndef __POSIX_ACL_H */
