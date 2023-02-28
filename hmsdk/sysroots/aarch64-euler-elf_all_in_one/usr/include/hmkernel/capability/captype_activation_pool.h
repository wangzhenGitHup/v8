/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: API of Captype activation pool
 * Author: Huawei OS Kernel Lab
 * Create: Mon Aug 12 21:46:25 2019
 */
/*
 * Must choose one GRANT type from ALL/NO/COARSE/FINE
 * Must choose one GRANTMOVE type from ALL/NO/COARSE
 */
/*
 * ReservedCall used for occupy the CAPMETHOD number, and meet with aarch64.
 * Here, 32bit client under compatible mode invokes the first four CAPMETHOD
 * number, then fastpath fetch actv args same as arm32 version.
 */
#include <hmkernel/feature.h>

#ifndef __UAPI_COMPAT__
#define CAP_RPC_METHOD	\
	CAPMETHOD(ActivationPool, Call)			\
	CAPMETHOD(ActivationPool, NoBufCall)		\
	CAPMETHOD(ActivationPool, SendBufCall)		\
	CAPMETHOD(ActivationPool, RetBufCall)		\
	CAPMETHOD(ActivationPool, ReservedCall1)	\
	CAPMETHOD(ActivationPool, ReservedCall2)	\
	CAPMETHOD(ActivationPool, ReservedCall3)	\
	CAPMETHOD(ActivationPool, ReservedCall4)
#else
#define CAP_RPC_METHOD	\
	CAPMETHOD(ActivationPool, CompatCall)		\
	CAPMETHOD(ActivationPool, CompatNoBufCall)	\
	CAPMETHOD(ActivationPool, CompatSendBufCall)	\
	CAPMETHOD(ActivationPool, CompatRetBufCall)	\
	CAPMETHOD(ActivationPool, Call)			\
	CAPMETHOD(ActivationPool, NoBufCall)		\
	CAPMETHOD(ActivationPool, SendBufCall)		\
	CAPMETHOD(ActivationPool, RetBufCall)
#endif

CAPTYPE(ActivationPool, 6, CAPCOARSEGRANT(ActivationPool)
			   CAPCOARSEGRANTMOVE(ActivationPool)
			   CAPDEFAULTSIZE(ActivationPool),
	CAP_RPC_METHOD
	CAPMETHOD(ActivationPool, Bind)
	CAPMETHOD(ActivationPool, KillOne)
	CAPMETHOD(ActivationPool, Listen)
	CAPMETHOD(ActivationPool, ListenWater)
	CAPMETHOD(ActivationPool, CheckWater)
	CAPMETHOD(ActivationPool, SetWater)
	CAPMETHOD(ActivationPool, SetCredential)
	CAPMETHOD(ActivationPool, EmrgInit)

	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_NEED_RREF,		"E_HM_ACTIVATIONPOOL_NEED_RREF")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_ALREADY_BOUND,	"E_HM_ACTIVATIONPOOL_ALREADY_BOUND")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_INVAL_BIND_POINT,	"E_HM_ACTIVATIONPOOL_INVAL_BIND_POINT")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_UNBOUND,		"E_HM_ACTIVATIONPOOL_UNBOUND")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_NORES,		"E_HM_ACTIVATIONPOOL_NORES")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_UNALLOC_BIND_POINT,	"E_HM_ACTIVATIONPOOL_UNALLOC_BIND_POINT")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_BIND_TO_SELF,		"E_HM_ACTIVATIONPOOL_BIND_TO_SELF")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_PROXY_BIND_NODEFAULT, "E_HM_ACTIVATIONPOOL_PROXY_BIND_NODEFAULT")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_INVOKE_PREALLOC_POOL, "E_HM_ACTIVATIONPOOL_INVOKE_PREALLOC_POOL")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_INVAL_REF_BIND_POINT, "E_HM_ACTIVATIONPOOL_INVAL_REF_BIND_POINT")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_NO_SELF_ACTV,		"E_HM_ACTIVATIONPOOL_NO_SELF_ACTV")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_INVAL_DUPBIND,	"E_HM_ACTIVATIONPOOL_INVAL_DUPBIND")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_NO_WATER_TRIGGER,	"E_HM_ACTIVATIONPOOL_NO_WATER_TRIGGER")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_CRED_ALREADY_DEFINED,	"E_HM_ACTIVATIONPOOL_CRED_ALREADY_DEFINED")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_ALREADY_EMRG_INIT,	"E_HM_ACTIVATIONPOOL_ALREADY_EMRG_INIT")
	CAPERRNO(ActivationPool, EHMERROR, ACTIVATIONPOOL_NOT_ALLOW_EMRG,	"E_HM_ACTIVATIONPOOL_NOT_ALLOW_EMRG")
	)

#undef CAP_RPC_METHOD

#ifdef CAP_EXPORT_API
#ifndef CAP_ACTVPOOL_API_EXPORTED
#define CAP_ACTVPOOL_API_EXPORTED

#include <hmkernel/types.h>
#include <hmkernel/capability.h>

enum {
	CRIGHT_ACTVPOOL_CALL_BIT,
	CRIGHT_ACTVPOOL_CTRL_BIT,
	CRIGHT_ACTVPOOL_BIND_BIT,
	CRIGHT_ACTVPOOL_MAX
};

#define CRIGHT_ACTVPOOL_CALL	(1U)
#define CRIGHT_ACTVPOOL_CTRL	(1U << CRIGHT_ACTVPOOL_CTRL_BIT)
#define CRIGHT_ACTVPOOL_BIND	(1U << CRIGHT_ACTVPOOL_BIND_BIT)

#define HMCAP_ACTVPOOL_NAME_SIZE	64

#define __CAP_ACTIVATION_POOL_OBJ_SIZE  2048u

enum __actv_bind_point {
	__CAP_ACTV_BIND_FASTCALL_G1_NOBUF,
	__CAP_ACTV_BIND_FASTCALL_G1_BUF,
	__CAP_ACTV_BIND_FASTCALL_G2_NOBUF,
	__CAP_ACTV_BIND_FASTCALL_G2_BUF,
};

struct __actvpool_grant {
	__u64 credential;
	__u64 pre_alloc_actv_cref;
};

/*
 * Define format of rpcinfo.
 * rpcinfo is a 64 bit unsigned int passed to kernel to describe the rpc call.
 *
 * the next version: use high 32 bits to support iov.
 *
 * Now, only 64bit servers use the hign 32 bits.
 * Hign 32 bits are composed by:
 *
 * From LSB to MSB:
 * 1bit:	Identity of the direct caller of the current actv. compat mode or not.
 * 1bit:	Identity of the transaction initiator of the call chain. compat mode or not.
 * 31bits:	Reserved.
 *
 * Low 32 bits is composed by:
 *
 * From LSB to MSB:
 *  14 bits:	length of memory buffer (so in outside caller's perspective,
 *					 this rpcinfo is buffer size. other
 *					 parts are 'ored' to buffer side by
 *					 userspace helper).
 *  1 bit:	0: start a new xact with the conf of the caller_actv.
 *		1: forward a xact with the xact_conf of the caller_actv.
 *  1 bit:	allow the callee actv to forward the current transaction again.
 *  11 bits:	call number
 *  5 bits:	stack size copied from client to server (in number of unsigned long)
 */
#define __RPC_INFO_COMPAT_BIT			32u
#define __RPC_INFO_XACT_COMPAT_BIT		33u
#define __RPC_INFO_ENCODE_MEM_BUF_LEN(x)	(__u64)(__u32)(((__u32)(x) & ((1u << 14u) - 1u)))
#define __RPC_INFO_ENCODE_FWD_XACT(x)		(__u64)(__u32)(((__u32)(x) & ((1u <<  1u) - 1u)) << 14u)
#define __RPC_INFO_ENCODE_ALLOW_REFWD(x)	(__u64)(__u32)(((__u32)(x) & ((1u <<  1u) - 1u)) << 15u)
#define __RPC_INFO_ENCODE_CALLNO(x)		(__u64)(__u32)(((__u32)(x) & ((1u << 11u) - 1u)) << 16u)
#define __RPC_INFO_ENCODE_STK_BUF_NR_UL(x)	(__u64)(__u32)(((__u32)(x) & ((1u <<  5u) - 1u)) << 27u)
#define __RPC_INFO_ENCODE_COMPAT_BIT(x)		(((__u64)(x) & ((1ULL <<  1u) - 1u)) << 32u)
#define __RPC_INFO_ENCODE_XACT_COMPAT_BIT(x)	(((__u64)(x) & ((1ULL <<  1u) - 1u)) << 33u)
#define __RPC_INFO_ENCODE(callno, mem_buf_len, stk_buf_nr_ul) (		\
		__RPC_INFO_ENCODE_CALLNO(callno)		|	\
		__RPC_INFO_ENCODE_MEM_BUF_LEN(mem_buf_len)	|	\
		__RPC_INFO_ENCODE_STK_BUF_NR_UL(stk_buf_nr_ul)		\
)
/*
 * fwd  allow_refwd
 *  0   0 : Start a new transaction but not allow the callee actv to forward it.
 *  0   1 : Start a new transaction and allow the callee actv to forward it.
 *  1   0 : Forward a transaction but not allow the callee actv to forward it again.
 *  1   1 : Forward a transaction and allow the callee actv to forward it again.
 */
#define __RPC_INFO_ENCODE_XACT(fwd, allow_refwd, callno, mem_buf_len, stk_buf_nr_ul) ( \
		__RPC_INFO_ENCODE_FWD_XACT(fwd)			|	\
		__RPC_INFO_ENCODE_ALLOW_REFWD(allow_refwd)	|	\
		__RPC_INFO_ENCODE_CALLNO(callno)		|	\
		__RPC_INFO_ENCODE_MEM_BUF_LEN(mem_buf_len)	|	\
		__RPC_INFO_ENCODE_STK_BUF_NR_UL(stk_buf_nr_ul)		\
)

#define __RPC_INFO_DECODE_MEM_BUF_LEN(v)	((unsigned long)(((v)) & ((1UL << 14u) - 1UL)))
#define __RPC_INFO_DECODE_FWD_XACT(v)		((unsigned long)(((v) >> 14u) & ((1UL <<  1u) - 1UL)))
#define __RPC_INFO_DECODE_ALLOW_REFWD(v)	((unsigned long)(((v) >> 15u) & ((1UL <<  1u) - 1UL)))
#define __RPC_INFO_DECODE_CALLNO(v)		((unsigned long)(((v) >> 16u) & ((1UL <<  11u) - 1UL)))
#define __RPC_INFO_DECODE_STK_BUF_NR_UL(v)	((unsigned long)(((v) >> 27u) & ((1UL <<  5u) - 1UL)))
#define __RPC_INFO_DECODE_COMPAT_BIT(v)		((unsigned long)(((v) >> 32u) & ((1UL <<  1u) - 1UL)))
#define __RPC_INFO_DECODE_XACT_COMPAT_BIT(v)	((unsigned long)(((v) >> 33u) & ((1UL <<  1u) - 1UL)))

#define __RPC_SENDER_DECODE_SRC_CIDX(v)		(__u32)((v) & 0xffffffffULL)
#define __RPC_SENDER_DECODE_FWD_CIDX(v)		(__u32)(((v) >> 32u) & 0xffffffffULL)

#define __RPC_INFO_MAX_STK_BUF_NR_UL	__RPC_INFO_DECODE_STK_BUF_NR_UL(0xffffffffffffffffULL)
#define __RPC_INFO_MAX_MEM_BUF_LEN	__RPC_INFO_DECODE_MEM_BUF_LEN(0xffffffffffffffffULL)

/*
 * prototype of wait_for_event:
 * sys_wait_for_event(int retval, void *data, void *buffer, unsigned long data_buf_sz);
 * data_buf_sz encode size of data (reply data) and buffer (send buffer) use a 32 bit
 * number.
 */
#define __RPC_BUFSZ_ENCODE_BUFSZ(sz)	(__u32)(((sz) & ((1u << 16u) - 1u)) << 0u)
#define __RPC_BUFSZ_ENCODE_DATASZ(sz)	(__u32)(((sz) & ((1u << 16u) - 1u)) << 16u)
#define __RPC_BUFSZ_ENCODE(b, d)	\
	(((unsigned long)__RPC_BUFSZ_ENCODE_BUFSZ(b)) | ((unsigned long)__RPC_BUFSZ_ENCODE_DATASZ(d)))

#define __RPC_BUFSZ_DECODE_BUFSZ(v)	((v) & 0xffffUL)
#define __RPC_BUFSZ_DECODE_DATASZ(v)	(((v) >> 16u) & 0xffffUL)
#define __RPC_BUFSZ_BUFSZ_MAXLEN	((1UL << 16u) - 1UL)
#define __RPC_BUFSZ_DATASZ_MAXLEN	((1UL << 16u) - 1UL)

#define __ACTV_POOL_BIND_FLAG_PRE_ALLOC	1UL
#define __ACTV_POOL_BIND_FLAG_POOL	2UL

/*
 * The actvs in this actv pool have __actv_local_area_k to
 * synchronize kernel information.
 */
#define __ACTV_POOL_FLAG_HAVE_LOCAL_AREA	1UL

/* Low table for posix signal (callnum <= 64) */
#define __ACTV_LOWTABLE_START	0
/* Mid table for kenrel exceptions or events (callnum from 65 ~ 127) */
#define __ACTV_MIDTABLE_START	65
/* High table for other actions and interrupts (callnum >= 128) */
#define __ACTV_HIGHTABLE_START	128

/* max num of actv added in an actvpool: 2^20 */
#define __ACTV_POOL_MAX_ACTVS	0x100000u

/* max num of emrg actv that can be pushed in an actvpool: 2^20 */
#define __ACTV_POOL_MAX_EMRG_ACTVS	0x100000u

/* max cnt of actv upcall that can be raised to an actvpool at the same time: 2^20 */
#define __ACTV_POOL_MAX_UPCALL_CNT	0x100000u

/* actv pool grant change events */
enum {
	__ACTV_POOL_GRANT_REJECTED,
	__ACTV_POOL_GRANT_SET_CRED,
};

/*
 * Elastic Infomation.
 * One can add other needed info in the future,
 * for example the gap between nr_ready_actvs and water.
 */
struct __actv_pool_water_trigger_info {
	unsigned int type;

	/* used for __ACTV_POOL_ELASTIC_TYPE_DEL */
	unsigned int is_user_inited;
	cref_t killed_actv;
};

#define __ACTV_IS_USER_UNINITED	0u
#define __ACTV_IS_USER_INITED	1u

#define __ACTV_POOL_WATER_TRIGGER_TYPE_ADD	1u
#define __ACTV_POOL_WATER_TRIGGER_TYPE_DEL	2u
#define __ACTV_POOL_WATER_TRIGGER_TYPE_NONE	3u

#define __ACTV_POOL_TRIGGER_ADD_ACTV 1u
#define __ACTV_POOL_TRIGGER_DEL_ACTV 2u

struct __actv_pool_water {
	__u32 ready_add_water;
	__u32 ready_del_water;
};

#define __ACTV_KERNMIN          65U
#define __ACTV_DATA_FAULT       66U
#define __ACTV_INSN_FAULT       67U
#define __ACTV_DEBUG_FAULT      68U
#define __ACTV_ILLINSN_FAULT    69U
#define __ACTV_HYP_VMEXIT       70U
#define __ACTV_KERN_NOTIF       71U
#define __ACTV_SP_PC_FAULT      72U
#define __ACTV_FPU_FAULT	73U
#define __ACTV_HW_WP_FAULT      74U

#define __ACTV_UPCALL_HMSIGNALS			75U
#define __ACTV_UPCALL_LINUX_SYSCALL		76U
#define __ACTV_UPCALL_POOL_GRANT_CHANGE		77U
#define __ACTV_UPCALL_KPAGEFAULT		78U
#define __ACTV_UPCALL_COPAGE_ALLOC		79U
#define __ACTV_UPCALL_COPAGE_ALLOC_BY_ORDER	80U
#define __ACTV_UPCALL_COPAGE_FREE		81U
#define __ACTV_UPCALL_COPAGE_ALLOC_RESERVE	82U

#define __ACTV_KERNMAX          127U

#endif
#endif
