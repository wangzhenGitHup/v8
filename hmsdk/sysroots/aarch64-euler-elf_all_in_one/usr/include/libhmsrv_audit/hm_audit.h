/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Transfer Hongmeng audit definitions to Linux audit definitions
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jul 26 15:42:28 2021
 */

#ifndef ULIBS_LIBAUDIT_HM_AUDIT_H
#define ULIBS_LIBAUDIT_HM_AUDIT_H
#include <stdint.h>

#define HM_AUDIT_GET			1000
#define HM_AUDIT_SET			1001
#define HM_AUDIT_LIST			1002
#define HM_AUDIT_ADD			1003
#define HM_AUDIT_DEL			1004
#define HM_AUDIT_USER			1005
#define HM_AUDIT_LOGIN			1006
#define HM_AUDIT_WATCH_INS		1007
#define HM_AUDIT_WATCH_REM		1008
#define HM_AUDIT_WATCH_LIST		1009
#define HM_AUDIT_SIGNAL_INFO		1010
#define HM_AUDIT_ADD_RULE		1011
#define HM_AUDIT_DEL_RULE		1012
#define HM_AUDIT_LIST_RULES		1013
#define HM_AUDIT_TRIM			1014
#define HM_AUDIT_MAKE_EQUIV		1015
#define HM_AUDIT_TTY_GET		1016
#define HM_AUDIT_TTY_SET		1017
#define HM_AUDIT_SET_FEATURE		1018
#define HM_AUDIT_GET_FEATURE		1019

#define HM_AUDIT_FIRST_USER_MSG		1100
#define HM_AUDIT_USER_AVC		1107
#define HM_AUDIT_USER_TTY		1124
#define HM_AUDIT_LAST_USER_MSG		1199
#define HM_AUDIT_FIRST_USER_MSG2	2100
#define HM_AUDIT_LAST_USER_MSG2		2999

#define HM_AUDIT_DAEMON_START		1200
#define HM_AUDIT_DAEMON_END		1201
#define HM_AUDIT_DAEMON_ABORT		1202
#define HM_AUDIT_DAEMON_CONFIG		1203

#define HM_AUDIT_SYSCALL		1300
#define HM_AUDIT_PATH			1302
#define HM_AUDIT_IPC			1303
#define HM_AUDIT_SOCKETCALL		1304
#define HM_AUDIT_CONFIG_CHANGE		1305
#define HM_AUDIT_SOCKADDR		1306
#define HM_AUDIT_CWD			1307
#define HM_AUDIT_EXECVE			1309
#define HM_AUDIT_IPC_SET_PERM		1311
#define HM_AUDIT_MQ_OPEN		1312
#define HM_AUDIT_MQ_SENDRECV		1313
#define HM_AUDIT_MQ_NOTIFY		1314
#define HM_AUDIT_MQ_GETSETATTR		1315
#define HM_AUDIT_KERNEL_OTHER		1316
#define HM_AUDIT_FD_PAIR		1317
#define HM_AUDIT_OBJ_PID		1318
#define HM_AUDIT_TTY			1319
#define HM_AUDIT_EOE			1320
#define HM_AUDIT_BPRM_FCAPS		1321
#define HM_AUDIT_CAPSET			1322
#define HM_AUDIT_MMAP			1323
#define HM_AUDIT_NETFILTER_PKT		1324
#define HM_AUDIT_NETFILTER_CFG		1325
#define HM_AUDIT_SECCOMP		1326
#define HM_AUDIT_PROCTITLE		1327
#define HM_AUDIT_FEATURE_CHANGE		1328
#define HM_AUDIT_REPLACE		1329
#define HM_AUDIT_KERN_MODULE		1330
#define HM_AUDIT_FANOTIFY		1331
#define HM_AUDIT_TIME_INJOFFSET		1332
#define HM_AUDIT_TIME_ADJNTPVAL		1333
#define HM_AUDIT_BPF			1334
#define HM_AUDIT_EVENT_LISTENER		1335

#define HM_AUDIT_AVC			1400
#define HM_AUDIT_SELINUX_ERR		1401
#define HM_AUDIT_AVC_PATH		1402
#define HM_AUDIT_MAC_POLICY_LOAD	1403
#define HM_AUDIT_MAC_STATUS		1404
#define HM_AUDIT_MAC_CONFIG_CHANGE	1405
#define HM_AUDIT_MAC_UNLBL_ALLOW	1406
#define HM_AUDIT_MAC_CIPSOV4_ADD	1407
#define HM_AUDIT_MAC_CIPSOV4_DEL	1408
#define HM_AUDIT_MAC_MAP_ADD		1409
#define HM_AUDIT_MAC_MAP_DEL		1410
#define HM_AUDIT_MAC_IPSEC_ADDSA	1411
#define HM_AUDIT_MAC_IPSEC_DELSA	1412
#define HM_AUDIT_MAC_IPSEC_ADDSPD	1413
#define HM_AUDIT_MAC_IPSEC_DELSPD	1414
#define HM_AUDIT_MAC_IPSEC_EVENT	1415
#define HM_AUDIT_MAC_UNLBL_STCADD	1416
#define HM_AUDIT_MAC_UNLBL_STCDEL	1417
#define HM_AUDIT_MAC_CALIPSO_ADD	1418
#define HM_AUDIT_MAC_CALIPSO_DEL	1419

#define HM_AUDIT_FIRST_KERN_ANOM_MSG	1700
#define HM_AUDIT_LAST_KERN_ANOM_MSG	1799
#define HM_AUDIT_ANOM_PROMISCUOUS	1700
#define HM_AUDIT_ANOM_ABEND		1701
#define HM_AUDIT_ANOM_LINK		1702
#define HM_AUDIT_ANOM_CREAT		1703
#define HM_AUDIT_INTEGRITY_DATA		1800
#define HM_AUDIT_INTEGRITY_METADATA	1801
#define HM_AUDIT_INTEGRITY_STATUS	1802
#define HM_AUDIT_INTEGRITY_HASH		1803
#define HM_AUDIT_INTEGRITY_PCR		1804
#define HM_AUDIT_INTEGRITY_RULE		1805
#define HM_AUDIT_INTEGRITY_EVM_XATTR	1806
#define HM_AUDIT_INTEGRITY_POLICY_RULE	1807

#define HM_AUDIT_KERNEL		2000

#define HM_AUDIT_FILTER_USER	0x00
#define HM_AUDIT_FILTER_TASK	0x01
#define HM_AUDIT_FILTER_ENTRY	0x02
#define HM_AUDIT_FILTER_WATCH	0x03
#define HM_AUDIT_FILTER_EXIT	0x04
#define HM_AUDIT_FILTER_EXCLUDE	0x05
#define HM_AUDIT_FILTER_TYPE	HM_AUDIT_FILTER_EXCLUDE
#define HM_AUDIT_FILTER_FS	0x06

#define HM_AUDIT_NR_FILTERS	7

#define HM_AUDIT_FILTER_PREPEND	0x10

#define HM_AUDIT_NEVER    0
#define HM_AUDIT_POSSIBLE 1
#define HM_AUDIT_ALWAYS   2

#define HM_AUDIT_PID		0
#define HM_AUDIT_UID		1
#define HM_AUDIT_EUID		2
#define HM_AUDIT_SUID		3
#define HM_AUDIT_FSUID		4
#define HM_AUDIT_GID		5
#define HM_AUDIT_EGID		6
#define HM_AUDIT_SGID		7
#define HM_AUDIT_FSGID		8
#define HM_AUDIT_LOGINUID	9
#define HM_AUDIT_PERS		10
#define HM_AUDIT_ARCH		11
#define HM_AUDIT_MSGTYPE	12
#define HM_AUDIT_SUBJ_USER	13
#define HM_AUDIT_SUBJ_ROLE	14
#define HM_AUDIT_SUBJ_TYPE	15
#define HM_AUDIT_SUBJ_SEN	16
#define HM_AUDIT_SUBJ_CLR	17
#define HM_AUDIT_PPID		18
#define HM_AUDIT_OBJ_USER	19
#define HM_AUDIT_OBJ_ROLE	20
#define HM_AUDIT_OBJ_TYPE	21
#define HM_AUDIT_OBJ_LEV_LOW	22
#define HM_AUDIT_OBJ_LEV_HIGH	23
#define HM_AUDIT_LOGINUID_SET	24
#define HM_AUDIT_SESSIONID	25
#define HM_AUDIT_FSTYPE		26

#define HM_AUDIT_DEVMAJOR	100
#define HM_AUDIT_DEVMINOR	101
#define HM_AUDIT_INODE		102
#define HM_AUDIT_EXIT		103
#define HM_AUDIT_SUCCESS	104
#define HM_AUDIT_WATCH		105
#define HM_AUDIT_PERM		106
#define HM_AUDIT_DIR		107
#define HM_AUDIT_FILETYPE	108
#define HM_AUDIT_OBJ_UID	109
#define HM_AUDIT_OBJ_GID	110
#define HM_AUDIT_FIELD_COMPARE	111
#define HM_AUDIT_EXE		112
#define HM_AUDIT_SADDR_FAM	113

#define HM_AUDIT_ARG0      200
#define HM_AUDIT_ARG1      (HM_AUDIT_ARG0 + 1)
#define HM_AUDIT_ARG2      (HM_AUDIT_ARG0 + 2)
#define HM_AUDIT_ARG3      (HM_AUDIT_ARG0 + 3)

#define HM_AUDIT_FILTERKEY	210

#define HM_AUDIT_NEGATE			0x80000000

#define HM_AUDIT_MAX_FIELDS   64
#define HM_AUDIT_MAX_KEY_LEN  256
#define HM_AUDIT_BITMASK_SIZE 64
#define HM_AUDIT_BITS_IN_WORD 32U
#define HM_AUDIT_WORD(nr) ((uint32_t)((nr) / HM_AUDIT_BITS_IN_WORD))
#define HM_AUDIT_BIT(nr)  (1U << ((nr) - HM_AUDIT_WORD(nr) * HM_AUDIT_BITS_IN_WORD))

#define HM_AUDIT_SYSCALL_CLASSES 16
#define HM_AUDIT_CLASS_DIR_WRITE 0
#define HM_AUDIT_CLASS_DIR_WRITE_32 1
#define HM_AUDIT_CLASS_CHATTR 2
#define HM_AUDIT_CLASS_CHATTR_32 3
#define HM_AUDIT_CLASS_READ 4
#define HM_AUDIT_CLASS_READ_32 5
#define HM_AUDIT_CLASS_WRITE 6
#define HM_AUDIT_CLASS_WRITE_32 7
#define HM_AUDIT_CLASS_SIGNAL 8
#define HM_AUDIT_CLASS_SIGNAL_32 9

#define HM_AUDIT_BIT_MASK		0x08000000
#define HM_AUDIT_LESS_THAN		0x10000000
#define HM_AUDIT_GREATER_THAN		0x20000000
#define HM_AUDIT_NOT_EQUAL		0x30000000
#define HM_AUDIT_EQUAL			0x40000000
#define HM_AUDIT_BIT_TEST		(HM_AUDIT_BIT_MASK | HM_AUDIT_EQUAL)
#define HM_AUDIT_LESS_THAN_OR_EQUAL	(HM_AUDIT_LESS_THAN | HM_AUDIT_EQUAL)
#define HM_AUDIT_GREATER_THAN_OR_EQUAL	(HM_AUDIT_GREATER_THAN | HM_AUDIT_EQUAL)
#define HM_AUDIT_OPERATORS		(HM_AUDIT_EQUAL | HM_AUDIT_NOT_EQUAL | HM_AUDIT_BIT_MASK)

enum {
	HM_AUDIT_ENUM_EQUAL,
	HM_AUDIT_ENUM_NOT_EQUAL,
	HM_AUDIT_ENUM_BITMASK,
	HM_AUDIT_ENUM_BITTEST,
	HM_AUDIT_ENUM_LT,
	HM_AUDIT_ENUM_GT,
	HM_AUDIT_ENUM_LE,
	HM_AUDIT_ENUM_GE,
	HM_AUDIT_ENUM_BUG
};

#define HM_AUDIT_UNUSED_BITS	0x07FFFC00

#define HM_AUDIT_COMPARE_UID_TO_OBJ_UID		1
#define HM_AUDIT_COMPARE_GID_TO_OBJ_GID		2
#define HM_AUDIT_COMPARE_EUID_TO_OBJ_UID	3
#define HM_AUDIT_COMPARE_EGID_TO_OBJ_GID	4
#define HM_AUDIT_COMPARE_AUID_TO_OBJ_UID	5
#define HM_AUDIT_COMPARE_SUID_TO_OBJ_UID	6
#define HM_AUDIT_COMPARE_SGID_TO_OBJ_GID	7
#define HM_AUDIT_COMPARE_FSUID_TO_OBJ_UID	8
#define HM_AUDIT_COMPARE_FSGID_TO_OBJ_GID	9

#define HM_AUDIT_COMPARE_UID_TO_AUID		10
#define HM_AUDIT_COMPARE_UID_TO_EUID		11
#define HM_AUDIT_COMPARE_UID_TO_FSUID		12
#define HM_AUDIT_COMPARE_UID_TO_SUID		13

#define HM_AUDIT_COMPARE_AUID_TO_FSUID		14
#define HM_AUDIT_COMPARE_AUID_TO_SUID		15
#define HM_AUDIT_COMPARE_AUID_TO_EUID		16

#define HM_AUDIT_COMPARE_EUID_TO_SUID		17
#define HM_AUDIT_COMPARE_EUID_TO_FSUID		18

#define HM_AUDIT_COMPARE_SUID_TO_FSUID		19

#define HM_AUDIT_COMPARE_GID_TO_EGID		20
#define HM_AUDIT_COMPARE_GID_TO_FSGID		21
#define HM_AUDIT_COMPARE_GID_TO_SGID		22

#define HM_AUDIT_COMPARE_EGID_TO_FSGID		23
#define HM_AUDIT_COMPARE_EGID_TO_SGID		24
#define HM_AUDIT_COMPARE_SGID_TO_FSGID		25

#define HM_AUDIT_MAX_FIELD_COMPARE		HM_AUDIT_COMPARE_SGID_TO_FSGID

#define HM_AUDIT_STATUS_ENABLED				0x0001
#define HM_AUDIT_STATUS_FAILURE				0x0002
#define HM_AUDIT_STATUS_PID				0x0004
#define HM_AUDIT_STATUS_RATE_LIMIT			0x0008
#define HM_AUDIT_STATUS_BACKLOG_LIMIT			0x0010
#define HM_AUDIT_STATUS_BACKLOG_WAIT_TIME		0x0020
#define HM_AUDIT_STATUS_LOST				0x0040

#define HM_AUDIT_FEATURE_BITMAP_BACKLOG_LIMIT		0x00000001
#define HM_AUDIT_FEATURE_BITMAP_BACKLOG_WAIT_TIME	0x00000002
#define HM_AUDIT_FEATURE_BITMAP_EXECUTABLE_PATH		0x00000004
#define HM_AUDIT_FEATURE_BITMAP_EXCLUDE_EXTEND		0x00000008
#define HM_AUDIT_FEATURE_BITMAP_SESSIONID_FILTER	0x00000010
#define HM_AUDIT_FEATURE_BITMAP_LOST_RESET		0x00000020
#define HM_AUDIT_FEATURE_BITMAP_FILTER_FS		0x00000040

#define HM_AUDIT_FEATURE_BITMAP_ALL (HM_AUDIT_FEATURE_BITMAP_BACKLOG_LIMIT | \
				     HM_AUDIT_FEATURE_BITMAP_BACKLOG_WAIT_TIME | \
				     HM_AUDIT_FEATURE_BITMAP_EXECUTABLE_PATH | \
				     HM_AUDIT_FEATURE_BITMAP_EXCLUDE_EXTEND | \
				     HM_AUDIT_FEATURE_BITMAP_SESSIONID_FILTER | \
				     HM_AUDIT_FEATURE_BITMAP_LOST_RESET | \
				     HM_AUDIT_FEATURE_BITMAP_FILTER_FS)

#define HM_AUDIT_FAIL_SILENT	0
#define HM_AUDIT_FAIL_PRINTK	1
#define HM_AUDIT_FAIL_PANIC	2

#define HM_ARM		40
#define HM_AARCH64	183

#define __HM_AUDIT_ARCH_64BIT 0x80000000
#define __HM_AUDIT_ARCH_LE	   0x40000000

#define HM_AUDIT_ARCH_AARCH64		(HM_AARCH64 | __HM_AUDIT_ARCH_64BIT | __HM_AUDIT_ARCH_LE)
#define HM_AUDIT_ARCH_ARM		(HM_ARM | __HM_AUDIT_ARCH_LE)
#define HM_AUDIT_ARCH_ARMEB		(HM_ARM)

#define HM_AUDIT_PERM_EXEC		1
#define HM_AUDIT_PERM_WRITE		2
#define HM_AUDIT_PERM_READ		4
#define HM_AUDIT_PERM_ATTR		8

#define HM_AUDIT_TYPE_UNKNOWN		0x0
#define HM_AUDIT_TYPE_NORMAL		0x1
#define HM_AUDIT_TYPE_PARENT		0x2
#define HM_AUDIT_TYPE_CHILD_DELETE	0x3
#define HM_AUDIT_TYPE_CHILD_CREATE	0x4

#define HM_AUDIT_MESSAGE_TEXT_MAX	8560

#define HM_AUDIT_NLGRP_MAX                (__AUDIT_NLGRP_MAX - 1)

#define HM_AUDIT_OFF		0
#define HM_AUDIT_ON		1
#define HM_AUDIT_LOCKED		2

#define HM_AUDIT_FEATURE_ONLY_UNSET_LOGINUID	0
#define HM_AUDIT_FEATURE_LOGINUID_IMMUTABLE	1
#define HM_AUDIT_LAST_FEATURE			AUDIT_FEATURE_LOGINUID_IMMUTABLE

#define HM_AUDIT_FEATURE_TO_MASK(x)	(1 << ((x) & 31))
#define HM_AUDIT_UID_UNSET ((unsigned int)-1)
#define HM_AUDIT_SID_UNSET ((unsigned int)-1)

struct audit_status {
	uint32_t		mask;
	uint32_t		enabled;
	uint32_t		failure;
	uint32_t		pid;
	uint32_t		rate_limit;
	uint32_t		backlog_limit;
	uint32_t		lost;
	uint32_t		backlog;
	union {
		uint32_t	version;
		uint32_t	feature_bitmap;
	};
	uint32_t		backlog_wait_time;
};

struct audit_features {
#define HM_AUDIT_FEATURE_VERSION	1
	uint32_t	vers;
	uint32_t	mask;
	uint32_t	features;
	uint32_t	lock;
};

struct audit_tty_status {
	uint32_t		enabled;
	uint32_t		log_passwd;
};

struct audit_rule_data {
	uint32_t		flags;
	uint32_t		action;
	uint32_t		field_count;
	uint32_t		mask[HM_AUDIT_BITMASK_SIZE];
	uint32_t		fields[HM_AUDIT_MAX_FIELDS];
	uint32_t		values[HM_AUDIT_MAX_FIELDS];
	uint32_t		fieldflags[HM_AUDIT_MAX_FIELDS];
	uint32_t		buflen;
	char			buf[0];
};

enum audit_nlgrps {
	AUDIT_NLGRP_NONE,
	AUDIT_NLGRP_READLOG,
	__AUDIT_NLGRP_MAX
};

#define audit_feature_valid(x)		((x) >= 0 && (x) <= AUDIT_LAST_FEATURE)

#define HM_AUDIT_MIN_BUFLEN		(sizeof(struct audit_rule_data))
#endif /* ULIBS_LIBAUDIT_HM_AUDIT_H */