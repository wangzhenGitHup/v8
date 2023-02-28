/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for crypto
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libhmsrv_crypt/sysif/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/crypt/libsysif/crypt/api.h --server-dest ../image/usr/include/generated/sysif_server/crypt/libsysif/crypt/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_CRYPTO_SERVER_H
#define LIBSYSIF_CRYPTO_SERVER_H
#ifndef LIBSYSIF_CRYPTO_COMMON_H
#define LIBSYSIF_CRYPTO_COMMON_H
#include <libsysif/utils_common.h>
#include <hongmeng/compiler.h>
#include <hongmeng/types.h>
#include <asm/actv_rpc.h>
#ifndef LIBSYSIF_BASE_API_COMMON_H
#define LIBSYSIF_BASE_API_COMMON_H
#include <stddef.h>
#include <stdint.h>
#include <hmkernel/capability.h>
struct sysif_reply_header {
	int32_t retval;
	uint32_t msgsz;
};

#define SYSIF_REPLY_LEN_MAX 256UL
extern void* hm_actvpool_prepare_ret(unsigned long long sender, unsigned long credential, unsigned long size);


extern struct arch_actv_local* hm_actv_current_arch_actv_local(void);


#endif


#include <stdint.h>

enum crypt_rng_type {
	CRYPT_RNG_DEFAULT = 0,
	CRYPT_RNG_SYSTEM,
	CRYPT_RNG_HW,

	CRYPT_RNG_MAX
};

#define CRYPT_RNG_RAND_DATA_MAX	256
struct crypt_rng_rand_data {
	unsigned char buf[CRYPT_RNG_RAND_DATA_MAX];
	unsigned int len;
};

enum crypt_rng_rand_val_type {
	CRYPT_RNG_RAND_VAL_U8 = 0,
	CRYPT_RNG_RAND_VAL_U16,
	CRYPT_RNG_RAND_VAL_U32,
	CRYPT_RNG_RAND_VAL_U64,

	CRYPT_RNG_RAND_VAL_MAX
};

union crypt_rng_rand_value {
	uint8_t data_u8;
	uint16_t data_u16;
	uint32_t data_u32;
	uint64_t data_u64;
};



#include <libhmsrv_key/key.h>

raw_static_assert(sizeof(enum crypt_rng_type) <= 96,
                    cryptcall_rng_random_bytes_arg_rng_type_is_too_large);
raw_static_assert(sizeof(enum crypt_rng_type) <= 96,
                    cryptcall_rng_random_value_arg_rng_type_is_too_large);
raw_static_assert(sizeof(enum crypt_rng_rand_val_type) <= 96,
                    cryptcall_rng_random_value_arg_value_type_is_too_large);
raw_static_assert(sizeof(uref_t) <= 96,
                    cryptcall_crypto_register_arg_uref_is_too_large);
raw_static_assert(sizeof(struct key_add_param) <= 96,
                    cryptcall_keymgr_add_arg_param_is_too_large);
raw_static_assert(sizeof(struct key_request_param) <= 96,
                    cryptcall_keymgr_request_arg_param_is_too_large);
raw_static_assert(sizeof(struct keyctl_param) <= 96,
                    cryptcall_keymgr_control_arg_param_is_too_large);
struct __actvret_cryptcall_rng_random_bytes {
	struct crypt_rng_rand_data data;
};

struct __actvret_cryptcall_rng_random_value {
	union crypt_rng_rand_value value;
};

struct __actvret_cryptcall_procfs_read {
};

struct __actvret_cryptcall_procfs_write {
};

struct __actvret_cryptcall_crypto_register {
};

struct __actvret_cryptcall_keymgr_add {
};

struct __actvret_cryptcall_keymgr_request {
};

struct __actvret_cryptcall_keymgr_control {
	struct keyctl_ret ret;
};

union __actvret_cryptcall {
	struct __actvret_cryptcall_rng_random_bytes rng_random_bytes;
	struct __actvret_cryptcall_rng_random_value rng_random_value;
	struct __actvret_cryptcall_procfs_read procfs_read;
	struct __actvret_cryptcall_procfs_write procfs_write;
	struct __actvret_cryptcall_crypto_register crypto_register;
	struct __actvret_cryptcall_keymgr_add keymgr_add;
	struct __actvret_cryptcall_keymgr_request keymgr_request;
	struct __actvret_cryptcall_keymgr_control keymgr_control;
};

enum __crypto_mgr {
	__crypto_INVAL_mgr=0,
	__crypto_rng_mgr,
	__crypto_procfs_mgr,
	__crypto_crypto_mgr,
	__crypto_keymgr_mgr,
	__crypto_MAX_mgr,
};

#define __crypto_method_MIN __ACTV_HIGHTABLE_START
#define __crypto_method_rng_random_bytes (__ACTV_HIGHTABLE_START + 1)
#define __crypto_method_rng_random_value (__ACTV_HIGHTABLE_START + 2)
#define __crypto_method_rng_rsvd_2 (__ACTV_HIGHTABLE_START + 3)
#define __crypto_method_rng_rsvd_1 (__ACTV_HIGHTABLE_START + 4)
#define __crypto_method_procfs_read (__ACTV_HIGHTABLE_START + 5)
#define __crypto_method_procfs_write (__ACTV_HIGHTABLE_START + 6)
#define __crypto_method_procfs_rsvd_2 (__ACTV_HIGHTABLE_START + 7)
#define __crypto_method_procfs_rsvd_1 (__ACTV_HIGHTABLE_START + 8)
#define __crypto_method_crypto_register (__ACTV_HIGHTABLE_START + 9)
#define __crypto_method_keymgr_add (__ACTV_HIGHTABLE_START + 10)
#define __crypto_method_keymgr_request (__ACTV_HIGHTABLE_START + 11)
#define __crypto_method_keymgr_control (__ACTV_HIGHTABLE_START + 12)
#define __crypto_method_keymgr_rsvd_1 (__ACTV_HIGHTABLE_START + 13)
#define __crypto_method_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + 14)
#define __crypto_method_MAX_COMPAT ((__ACTV_HIGHTABLE_START + 14) * 2)
raw_static_assert(sizeof(struct __actvret_cryptcall_rng_random_bytes) < 512,
                cryptcall_rng_random_bytes_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_cryptcall_rng_random_value) < 512,
                cryptcall_rng_random_value_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_cryptcall_procfs_read) < 512,
                cryptcall_procfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_cryptcall_procfs_write) < 512,
                cryptcall_procfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_cryptcall_crypto_register) < 512,
                cryptcall_crypto_register_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_cryptcall_keymgr_add) < 512,
                cryptcall_keymgr_add_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_cryptcall_keymgr_request) < 512,
                cryptcall_keymgr_request_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_cryptcall_keymgr_control) < 512,
                cryptcall_keymgr_control_too_many_actvret_data);
raw_static_assert(sizeof(union __actvret_cryptcall) < 512,
        cryptcall_too_many_actvret_data);
extern int __actvcall_cryptcall_rng_random_bytes(unsigned long long __rpc_info, void *__buf, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);


extern int __actvcapcall_cryptcall_rng_random_bytes(rref_t __rref, unsigned long long __rpc_info, void *__buf, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);


static inline int __attribute__((always_inline)) actvxactcall_cryptcall_rng_random_bytes(bool is_xact_fwd, bool is_xact_allow_refwd, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags, struct __actvret_cryptcall_rng_random_bytes *__ret)
{
	const unsigned long __callno = __crypto_method_rng_random_bytes;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_cryptcall_rng_random_bytes(rpc_info, __ret, rng_type, bytes_len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_cryptcall_rng_random_bytes(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags, struct __actvret_cryptcall_rng_random_bytes *__ret)
{
	const unsigned long __callno = __crypto_method_rng_random_bytes;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_cryptcall_rng_random_bytes(__rref, rpc_info, __ret, rng_type, bytes_len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_cryptcall_rng_random_bytes(enum crypt_rng_type rng_type, unsigned int bytes_len, int flags, struct __actvret_cryptcall_rng_random_bytes *__ret)
{
	return actvxactcall_cryptcall_rng_random_bytes(false, false, rng_type, bytes_len, flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_cryptcall_rng_random_bytes(rref_t __rref, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags, struct __actvret_cryptcall_rng_random_bytes *__ret)
{
	return actvxactcapcall_cryptcall_rng_random_bytes(false, false, __rref, rng_type, bytes_len, flags, __ret);
}

extern int __actvcall_cryptcall_rng_random_value(unsigned long long __rpc_info, void *__buf, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);


extern int __actvcapcall_cryptcall_rng_random_value(rref_t __rref, unsigned long long __rpc_info, void *__buf, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);


static inline int __attribute__((always_inline)) actvxactcall_cryptcall_rng_random_value(bool is_xact_fwd, bool is_xact_allow_refwd, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags, struct __actvret_cryptcall_rng_random_value *__ret)
{
	const unsigned long __callno = __crypto_method_rng_random_value;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_rand_val_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_rand_val_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_cryptcall_rng_random_value(rpc_info, __ret, rng_type, value_type, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_cryptcall_rng_random_value(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags, struct __actvret_cryptcall_rng_random_value *__ret)
{
	const unsigned long __callno = __crypto_method_rng_random_value;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_rand_val_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_rand_val_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_cryptcall_rng_random_value(__rref, rpc_info, __ret, rng_type, value_type, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_cryptcall_rng_random_value(enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags, struct __actvret_cryptcall_rng_random_value *__ret)
{
	return actvxactcall_cryptcall_rng_random_value(false, false, rng_type, value_type, flags, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_cryptcall_rng_random_value(rref_t __rref, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags, struct __actvret_cryptcall_rng_random_value *__ret)
{
	return actvxactcapcall_cryptcall_rng_random_value(false, false, __rref, rng_type, value_type, flags, __ret);
}

extern int __actvcall_cryptcall_procfs_read(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_cryptcall_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_cryptcall_procfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __crypto_method_procfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_cryptcall_procfs_read(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_cryptcall_procfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __crypto_method_procfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_cryptcall_procfs_read(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_cryptcall_procfs_read(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_cryptcall_procfs_read(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_cryptcall_procfs_read(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_cryptcall_procfs_read(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_cryptcall_procfs_write(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_cryptcall_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_cryptcall_procfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __crypto_method_procfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_cryptcall_procfs_write(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_cryptcall_procfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __crypto_method_procfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_cryptcall_procfs_write(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_cryptcall_procfs_write(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_cryptcall_procfs_write(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_cryptcall_procfs_write(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_cryptcall_procfs_write(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_cryptcall_crypto_register(unsigned long long __rpc_info, void *__buf, uref_t uref);


extern int __actvcapcall_cryptcall_crypto_register(rref_t __rref, unsigned long long __rpc_info, void *__buf, uref_t uref);


static inline int __attribute__((always_inline)) actvxactcall_cryptcall_crypto_register(bool is_xact_fwd, bool is_xact_allow_refwd, uref_t uref)
{
	const unsigned long __callno = __crypto_method_crypto_register;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_cryptcall_crypto_register(rpc_info, NULL, uref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_cryptcall_crypto_register(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, uref_t uref)
{
	const unsigned long __callno = __crypto_method_crypto_register;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_cryptcall_crypto_register(__rref, rpc_info, NULL, uref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_cryptcall_crypto_register(uref_t uref)
{
	return actvxactcall_cryptcall_crypto_register(false, false, uref);
}

static inline int __attribute__((always_inline)) actvcapcall_cryptcall_crypto_register(rref_t __rref, uref_t uref)
{
	return actvxactcapcall_cryptcall_crypto_register(false, false, __rref, uref);
}

extern int __actvcall_cryptcall_keymgr_add(unsigned long long __rpc_info, void *__buf, int shm_id, struct key_add_param param);


extern int __actvcapcall_cryptcall_keymgr_add(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct key_add_param param);


static inline int __attribute__((always_inline)) actvxactcall_cryptcall_keymgr_add(bool is_xact_fwd, bool is_xact_allow_refwd, int shm_id, struct key_add_param param)
{
	const unsigned long __callno = __crypto_method_keymgr_add;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_cryptcall_keymgr_add(rpc_info, NULL, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_cryptcall_keymgr_add(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int shm_id, struct key_add_param param)
{
	const unsigned long __callno = __crypto_method_keymgr_add;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_cryptcall_keymgr_add(__rref, rpc_info, NULL, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_cryptcall_keymgr_add(int shm_id, struct key_add_param param)
{
	return actvxactcall_cryptcall_keymgr_add(false, false, shm_id, param);
}

static inline int __attribute__((always_inline)) actvcapcall_cryptcall_keymgr_add(rref_t __rref, int shm_id, struct key_add_param param)
{
	return actvxactcapcall_cryptcall_keymgr_add(false, false, __rref, shm_id, param);
}

extern int __actvcall_cryptcall_keymgr_request(unsigned long long __rpc_info, void *__buf, int shm_id, struct key_request_param param);


extern int __actvcapcall_cryptcall_keymgr_request(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct key_request_param param);


static inline int __attribute__((always_inline)) actvxactcall_cryptcall_keymgr_request(bool is_xact_fwd, bool is_xact_allow_refwd, int shm_id, struct key_request_param param)
{
	const unsigned long __callno = __crypto_method_keymgr_request;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_cryptcall_keymgr_request(rpc_info, NULL, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_cryptcall_keymgr_request(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int shm_id, struct key_request_param param)
{
	const unsigned long __callno = __crypto_method_keymgr_request;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_cryptcall_keymgr_request(__rref, rpc_info, NULL, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_cryptcall_keymgr_request(int shm_id, struct key_request_param param)
{
	return actvxactcall_cryptcall_keymgr_request(false, false, shm_id, param);
}

static inline int __attribute__((always_inline)) actvcapcall_cryptcall_keymgr_request(rref_t __rref, int shm_id, struct key_request_param param)
{
	return actvxactcapcall_cryptcall_keymgr_request(false, false, __rref, shm_id, param);
}

extern int __actvcall_cryptcall_keymgr_control(unsigned long long __rpc_info, void *__buf, int shm_id, struct keyctl_param param);


extern int __actvcapcall_cryptcall_keymgr_control(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct keyctl_param param);


static inline int __attribute__((always_inline)) actvxactcall_cryptcall_keymgr_control(bool is_xact_fwd, bool is_xact_allow_refwd, int shm_id, struct keyctl_param param, struct __actvret_cryptcall_keymgr_control *__ret)
{
	const unsigned long __callno = __crypto_method_keymgr_control;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcall_cryptcall_keymgr_control(rpc_info, __ret, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_cryptcall_keymgr_control(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int shm_id, struct keyctl_param param, struct __actvret_cryptcall_keymgr_control *__ret)
{
	const unsigned long __callno = __crypto_method_keymgr_control;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, sizeof*__ret, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_cryptcall_keymgr_control(__rref, rpc_info, __ret, shm_id, param);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_cryptcall_keymgr_control(int shm_id, struct keyctl_param param, struct __actvret_cryptcall_keymgr_control *__ret)
{
	return actvxactcall_cryptcall_keymgr_control(false, false, shm_id, param, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_cryptcall_keymgr_control(rref_t __rref, int shm_id, struct keyctl_param param, struct __actvret_cryptcall_keymgr_control *__ret)
{
	return actvxactcapcall_cryptcall_keymgr_control(false, false, __rref, shm_id, param, __ret);
}

#endif
#ifdef __sysif_server_crypto_no_compat32_handlers__
# define __crypto_method_MAX __crypto_method_MAX_NOCOMPAT
#else
# define __crypto_method_MAX __crypto_method_MAX_COMPAT
#endif
#include <libsysif/utils.h>
#include <asm/actv_rpc.h>
#include <asm/types.h>
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
extern int actvhdlr_crypthandler_rng_random_bytes(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);


extern int actvhdlr_crypthandler_rng_random_value(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);


extern int actvhdlr_crypthandler_procfs_read(unsigned long long sender, unsigned long credential);


extern int actvhdlr_crypthandler_procfs_write(unsigned long long sender, unsigned long credential);


extern int actvhdlr_crypthandler_crypto_register(unsigned long long sender, unsigned long credential, uref_t uref);


extern int actvhdlr_crypthandler_keymgr_add(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);


extern int actvhdlr_crypthandler_keymgr_request(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);


extern int actvhdlr_crypthandler_keymgr_control(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);


#else
extern int actvhdlr_crypthandler_rng_random_bytes(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);


extern int __actvshadowhdlr_crypthandler_rng_random_bytes(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_crypthandler_rng_random_value(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);


extern int __actvshadowhdlr_crypthandler_rng_random_value(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_crypthandler_procfs_read(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_crypthandler_procfs_read(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_crypthandler_procfs_write(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_crypthandler_procfs_write(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_crypthandler_crypto_register(unsigned long long sender, unsigned long credential, uref_t uref);


extern int __actvshadowhdlr_crypthandler_crypto_register(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_crypthandler_keymgr_add(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);


extern int __actvshadowhdlr_crypthandler_keymgr_add(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_crypthandler_keymgr_request(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);


extern int __actvshadowhdlr_crypthandler_keymgr_request(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_crypthandler_keymgr_control(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);


extern int __actvshadowhdlr_crypthandler_keymgr_control(unsigned long long sender, unsigned long credential, ...);


#endif
static inline struct __actvret_cryptcall_rng_random_bytes* actvhdlr_crypthandler_rng_random_bytes_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_cryptcall_rng_random_bytes));
	return (struct __actvret_cryptcall_rng_random_bytes*)__ret;
}

static inline struct __actvret_cryptcall_rng_random_value* actvhdlr_crypthandler_rng_random_value_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_cryptcall_rng_random_value));
	return (struct __actvret_cryptcall_rng_random_value*)__ret;
}

static inline struct __actvret_cryptcall_procfs_read* actvhdlr_crypthandler_procfs_read_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_cryptcall_procfs_read));
	return (struct __actvret_cryptcall_procfs_read*)__ret;
}

static inline struct __actvret_cryptcall_procfs_write* actvhdlr_crypthandler_procfs_write_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_cryptcall_procfs_write));
	return (struct __actvret_cryptcall_procfs_write*)__ret;
}

static inline struct __actvret_cryptcall_crypto_register* actvhdlr_crypthandler_crypto_register_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_cryptcall_crypto_register));
	return (struct __actvret_cryptcall_crypto_register*)__ret;
}

static inline struct __actvret_cryptcall_keymgr_add* actvhdlr_crypthandler_keymgr_add_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_cryptcall_keymgr_add));
	return (struct __actvret_cryptcall_keymgr_add*)__ret;
}

static inline struct __actvret_cryptcall_keymgr_request* actvhdlr_crypthandler_keymgr_request_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_cryptcall_keymgr_request));
	return (struct __actvret_cryptcall_keymgr_request*)__ret;
}

static inline struct __actvret_cryptcall_keymgr_control* actvhdlr_crypthandler_keymgr_control_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_cryptcall_keymgr_control));
	return (struct __actvret_cryptcall_keymgr_control*)__ret;
}

#ifdef __sysif_server_crypto_no_compat32_handlers__
#ifdef __HOST_LLT__
union crypto_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgehdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgehdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, uref_t uref);
	int (*p__actvbridgecapcallhdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uref_t uref);
	int (*p__actvbridgehdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union crypto_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgehdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgehdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, uref_t uref);
	int (*p__actvbridgecapcallhdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uref_t uref);
	int (*p__actvbridgehdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union crypto_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgehdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgehdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, uref_t uref);
	int (*p__actvbridgecapcallhdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uref_t uref);
	int (*p__actvbridgehdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
#ifdef __HOST_LLT__
union crypto_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgehdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgehdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, uref_t uref);
	int (*p__actvbridgecapcallhdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uref_t uref);
	int (*p__actvbridgehdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p__actvbridgehdlr_crypthandler_compat_rng_random_bytes)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_rng_random_bytes)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_rng_random_value)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_rng_random_value)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_crypto_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_crypto_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union crypto_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgehdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgehdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, uref_t uref);
	int (*p__actvbridgecapcallhdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uref_t uref);
	int (*p__actvbridgehdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p__actvbridgehdlr_crypthandler_compat_rng_random_bytes)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_rng_random_bytes)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_rng_random_value)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_rng_random_value)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_crypto_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_crypto_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union crypto_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_bytes)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags);
	int (*p__actvbridgehdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgecapcallhdlr_crypthandler_rng_random_value)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags);
	int (*p__actvbridgehdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_crypthandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, uref_t uref);
	int (*p__actvbridgecapcallhdlr_crypthandler_crypto_register)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uref_t uref);
	int (*p__actvbridgehdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_add)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_request)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param);
	int (*p__actvbridgehdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param);
	int (*p__actvbridgecapcallhdlr_crypthandler_keymgr_control)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param);
	int (*p__actvbridgehdlr_crypthandler_compat_rng_random_bytes)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_rng_random_bytes)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_rng_random_value)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_rng_random_value)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_crypto_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_crypto_register)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_add)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_request)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_crypthandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_control)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#endif
#endif
extern union crypto_hdlrs_union sysif_crypto_actvhdlr_table[__crypto_method_MAX];

extern union crypto_hdlrs_union sysif_crypto_actvcapcallhdlr_table[__crypto_method_MAX];

extern void sysif_show_crypto_methods(void);


#ifdef SYSIF_GEN_IFACE
#include <stdint.h>
#include <asm/actv_rpc.h>
#include <hongmeng/syscall.h>
#include <hongmeng/panic.h>
#include <hongmeng/errno.h>
#include <libstrict/strict.h>
#include <libhwsecurec/securec.h>
#include <libsysif/base/server_arg_compat.h>
#ifdef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
static int __opt_nonoframe __actvbridgehdlr_crypthandler_rng_random_bytes(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_rng_random_bytes(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_type, rng_type), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, bytes_len), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_rng_random_bytes(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_rng_random_bytes(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_type, rng_type), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, bytes_len), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_rng_random_value(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_rand_val_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_rand_val_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_rng_random_value(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_type, rng_type), __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_rand_val_type, value_type), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_rng_random_value(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_rand_val_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_rand_val_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_rng_random_value(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_type, rng_type), __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_rand_val_type, value_type), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_procfs_read(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_crypthandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_procfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_crypthandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_procfs_write(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_crypthandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_procfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_crypthandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_crypto_register(unsigned long long sender, unsigned long credential, uref_t uref)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_crypto_register(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(uref_t, uref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_crypto_register(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uref_t uref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_crypto_register(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(uref_t, uref));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_keymgr_add(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_add_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_keymgr_add(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_add_param, param));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_keymgr_request(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_request(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_request_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_keymgr_request(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_request(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_request_param, param));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_keymgr_control(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_control(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct keyctl_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_keymgr_control(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_control(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct keyctl_param, param));
}

#ifndef __sysif_server_crypto_no_compat32_handlers__
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
struct compat_x3 {
	unsigned int reserverd;
	unsigned int w3;
};

#else
struct compat_x3 {
	unsigned int w3;
	unsigned int reserverd;
};

#endif
static int __opt_nonoframe __actvbridgehdlr_crypthandler_compat_rng_random_bytes(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	enum crypt_rng_type __maybe_unused _rng_type;
	unsigned int __maybe_unused _bytes_len;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(enum crypt_rng_type);
		type = __type_of(enum crypt_rng_type);
		__fetch_one_arg((void*)&_rng_type, data, 0, arg_sz, model, type, enum crypt_rng_type, _rng_type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_bytes_len, data, 1, arg_sz, model, type, unsigned int, _bytes_len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 2, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_rng_random_bytes(sender, credential, _rng_type, _bytes_len, _flags);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_compat_rng_random_bytes(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	enum crypt_rng_type __maybe_unused _rng_type;
	unsigned int __maybe_unused _bytes_len;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(enum crypt_rng_type);
		type = __type_of(enum crypt_rng_type);
		__fetch_one_arg((void*)&_rng_type, data, 0, arg_sz, model, type, enum crypt_rng_type, _rng_type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_bytes_len, data, 1, arg_sz, model, type, unsigned int, _bytes_len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 2, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_rng_random_bytes(sender, credential, _rng_type, _bytes_len, _flags);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_compat_rng_random_value(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	enum crypt_rng_type __maybe_unused _rng_type;
	enum crypt_rng_rand_val_type __maybe_unused _value_type;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(enum crypt_rng_type);
		type = __type_of(enum crypt_rng_type);
		__fetch_one_arg((void*)&_rng_type, data, 0, arg_sz, model, type, enum crypt_rng_type, _rng_type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(enum crypt_rng_rand_val_type);
		type = __type_of(enum crypt_rng_rand_val_type);
		__fetch_one_arg((void*)&_value_type, data, 1, arg_sz, model, type, enum crypt_rng_rand_val_type, _value_type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 2, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_rng_random_value(sender, credential, _rng_type, _value_type, _flags);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_compat_rng_random_value(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	enum crypt_rng_type __maybe_unused _rng_type;
	enum crypt_rng_rand_val_type __maybe_unused _value_type;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(enum crypt_rng_type);
		type = __type_of(enum crypt_rng_type);
		__fetch_one_arg((void*)&_rng_type, data, 0, arg_sz, model, type, enum crypt_rng_type, _rng_type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(enum crypt_rng_rand_val_type);
		type = __type_of(enum crypt_rng_rand_val_type);
		__fetch_one_arg((void*)&_value_type, data, 1, arg_sz, model, type, enum crypt_rng_rand_val_type, _value_type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 2, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_rng_random_value(sender, credential, _rng_type, _value_type, _flags);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_compat_procfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_crypthandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_compat_procfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_crypthandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_compat_procfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_crypthandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_compat_procfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_crypthandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_compat_crypto_register(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	uref_t __maybe_unused _uref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(uref_t);
		type = __type_of(uref_t);
		__fetch_one_arg((void*)&_uref, data, 0, arg_sz, model, type, uref_t, _uref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_crypto_register(sender, credential, _uref);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_compat_crypto_register(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	uref_t __maybe_unused _uref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(uref_t);
		type = __type_of(uref_t);
		__fetch_one_arg((void*)&_uref, data, 0, arg_sz, model, type, uref_t, _uref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_crypto_register(sender, credential, _uref);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_compat_keymgr_add(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct key_add_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct key_add_param);
		type = __type_of(struct key_add_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct key_add_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_add(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_compat_keymgr_add(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct key_add_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct key_add_param);
		type = __type_of(struct key_add_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct key_add_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_add(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_compat_keymgr_request(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct key_request_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct key_request_param);
		type = __type_of(struct key_request_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct key_request_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_request(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_compat_keymgr_request(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct key_request_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct key_request_param);
		type = __type_of(struct key_request_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct key_request_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_request(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_compat_keymgr_control(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct keyctl_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct keyctl_param);
		type = __type_of(struct keyctl_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct keyctl_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_control(sender, credential, _shm_id, _param);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_compat_keymgr_control(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _shm_id;
	struct keyctl_param __maybe_unused _param;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_id, data, 0, arg_sz, model, type, int, _shm_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct keyctl_param);
		type = __type_of(struct keyctl_param);
		__fetch_one_arg((void*)&_param, data, 1, arg_sz, model, type, struct keyctl_param, _param)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_crypthandler_keymgr_control(sender, credential, _shm_id, _param);
}

#endif
#else
static int __opt_nonoframe __actvbridgehdlr_crypthandler_rng_random_bytes(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_rng_random_bytes(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_type, rng_type), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, bytes_len), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_rng_random_bytes(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_rng_random_bytes(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_type, rng_type), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, bytes_len), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_rng_random_value(unsigned long long sender, unsigned long credential, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_rand_val_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_rand_val_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_rng_random_value(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_type, rng_type), __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_rand_val_type, value_type), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_rng_random_value(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum crypt_rng_rand_val_type), __arch_actv_rpc_stksz_alignment(enum crypt_rng_rand_val_type));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_rng_random_value(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_type, rng_type), __ARCH_ACTV_RPC_RECV_ARG(enum crypt_rng_rand_val_type, value_type), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_procfs_read(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_crypthandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_procfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_crypthandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_procfs_write(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_crypthandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_procfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_crypthandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_crypto_register(unsigned long long sender, unsigned long credential, uref_t uref)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_crypto_register(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(uref_t, uref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_crypto_register(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uref_t uref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uref_t), __arch_actv_rpc_stksz_alignment(uref_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_crypto_register(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(uref_t, uref));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_keymgr_add(unsigned long long sender, unsigned long credential, int shm_id, struct key_add_param param)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_keymgr_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_add_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_keymgr_add(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_add_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_add_param), __arch_actv_rpc_stksz_alignment(struct key_add_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_keymgr_add(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_add_param, param));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_keymgr_request(unsigned long long sender, unsigned long credential, int shm_id, struct key_request_param param)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_keymgr_request(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_request_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_keymgr_request(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct key_request_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct key_request_param), __arch_actv_rpc_stksz_alignment(struct key_request_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_keymgr_request(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct key_request_param, param));
}

static int __opt_nonoframe __actvbridgehdlr_crypthandler_keymgr_control(unsigned long long sender, unsigned long credential, int shm_id, struct keyctl_param param)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_keymgr_control(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct keyctl_param, param));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_crypthandler_keymgr_control(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int shm_id, struct keyctl_param param)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct keyctl_param), __arch_actv_rpc_stksz_alignment(struct keyctl_param));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_crypthandler_keymgr_control(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, shm_id), __ARCH_ACTV_RPC_RECV_ARG(struct keyctl_param, param));
}

#endif
#ifdef __sysif_server_crypto_no_compat32_handlers__
union crypto_hdlrs_union sysif_crypto_actvhdlr_table[__crypto_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __crypto_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__crypto_method_rng_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_random_bytes] = {
		.p__actvbridgehdlr_crypthandler_rng_random_bytes = (&__actvbridgehdlr_crypthandler_rng_random_bytes)
	},
	[__crypto_method_rng_random_value] = {
		.p__actvbridgehdlr_crypthandler_rng_random_value = (&__actvbridgehdlr_crypthandler_rng_random_value)
	},
	[__crypto_method_procfs_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_read] = {
		.p__actvbridgehdlr_crypthandler_procfs_read = (&__actvbridgehdlr_crypthandler_procfs_read)
	},
	[__crypto_method_procfs_write] = {
		.p__actvbridgehdlr_crypthandler_procfs_write = (&__actvbridgehdlr_crypthandler_procfs_write)
	},
	[__crypto_method_crypto_register] = {
		.p__actvbridgehdlr_crypthandler_crypto_register = (&__actvbridgehdlr_crypthandler_crypto_register)
	},
	[__crypto_method_keymgr_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_keymgr_add] = {
		.p__actvbridgehdlr_crypthandler_keymgr_add = (&__actvbridgehdlr_crypthandler_keymgr_add)
	},
	[__crypto_method_keymgr_request] = {
		.p__actvbridgehdlr_crypthandler_keymgr_request = (&__actvbridgehdlr_crypthandler_keymgr_request)
	},
	[__crypto_method_keymgr_control] = {
		.p__actvbridgehdlr_crypthandler_keymgr_control = (&__actvbridgehdlr_crypthandler_keymgr_control)
	}
};

union crypto_hdlrs_union sysif_crypto_actvcapcallhdlr_table[__crypto_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __crypto_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__crypto_method_rng_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_random_bytes] = {
		.p__actvbridgecapcallhdlr_crypthandler_rng_random_bytes = (&__actvbridgecapcallhdlr_crypthandler_rng_random_bytes)
	},
	[__crypto_method_rng_random_value] = {
		.p__actvbridgecapcallhdlr_crypthandler_rng_random_value = (&__actvbridgecapcallhdlr_crypthandler_rng_random_value)
	},
	[__crypto_method_procfs_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_read] = {
		.p__actvbridgecapcallhdlr_crypthandler_procfs_read = (&__actvbridgecapcallhdlr_crypthandler_procfs_read)
	},
	[__crypto_method_procfs_write] = {
		.p__actvbridgecapcallhdlr_crypthandler_procfs_write = (&__actvbridgecapcallhdlr_crypthandler_procfs_write)
	},
	[__crypto_method_crypto_register] = {
		.p__actvbridgecapcallhdlr_crypthandler_crypto_register = (&__actvbridgecapcallhdlr_crypthandler_crypto_register)
	},
	[__crypto_method_keymgr_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_keymgr_add] = {
		.p__actvbridgecapcallhdlr_crypthandler_keymgr_add = (&__actvbridgecapcallhdlr_crypthandler_keymgr_add)
	},
	[__crypto_method_keymgr_request] = {
		.p__actvbridgecapcallhdlr_crypthandler_keymgr_request = (&__actvbridgecapcallhdlr_crypthandler_keymgr_request)
	},
	[__crypto_method_keymgr_control] = {
		.p__actvbridgecapcallhdlr_crypthandler_keymgr_control = (&__actvbridgecapcallhdlr_crypthandler_keymgr_control)
	}
};

#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
union crypto_hdlrs_union sysif_crypto_actvhdlr_table[__crypto_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __crypto_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__crypto_method_rng_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_random_bytes * 2] = {
		.p__actvbridgehdlr_crypthandler_rng_random_bytes = (&__actvbridgehdlr_crypthandler_rng_random_bytes)
	},
	[__crypto_method_rng_random_bytes * 2 + 1] = {
		.p__actvbridgehdlr_crypthandler_compat_rng_random_bytes = (&__actvbridgehdlr_crypthandler_compat_rng_random_bytes)
	},
	[__crypto_method_rng_random_value * 2] = {
		.p__actvbridgehdlr_crypthandler_rng_random_value = (&__actvbridgehdlr_crypthandler_rng_random_value)
	},
	[__crypto_method_rng_random_value * 2 + 1] = {
		.p__actvbridgehdlr_crypthandler_compat_rng_random_value = (&__actvbridgehdlr_crypthandler_compat_rng_random_value)
	},
	[__crypto_method_procfs_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_read * 2] = {
		.p__actvbridgehdlr_crypthandler_procfs_read = (&__actvbridgehdlr_crypthandler_procfs_read)
	},
	[__crypto_method_procfs_read * 2 + 1] = {
		.p__actvbridgehdlr_crypthandler_compat_procfs_read = (&__actvbridgehdlr_crypthandler_compat_procfs_read)
	},
	[__crypto_method_procfs_write * 2] = {
		.p__actvbridgehdlr_crypthandler_procfs_write = (&__actvbridgehdlr_crypthandler_procfs_write)
	},
	[__crypto_method_procfs_write * 2 + 1] = {
		.p__actvbridgehdlr_crypthandler_compat_procfs_write = (&__actvbridgehdlr_crypthandler_compat_procfs_write)
	},
	[__crypto_method_crypto_register * 2] = {
		.p__actvbridgehdlr_crypthandler_crypto_register = (&__actvbridgehdlr_crypthandler_crypto_register)
	},
	[__crypto_method_crypto_register * 2 + 1] = {
		.p__actvbridgehdlr_crypthandler_compat_crypto_register = (&__actvbridgehdlr_crypthandler_compat_crypto_register)
	},
	[__crypto_method_keymgr_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_keymgr_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_keymgr_add * 2] = {
		.p__actvbridgehdlr_crypthandler_keymgr_add = (&__actvbridgehdlr_crypthandler_keymgr_add)
	},
	[__crypto_method_keymgr_add * 2 + 1] = {
		.p__actvbridgehdlr_crypthandler_compat_keymgr_add = (&__actvbridgehdlr_crypthandler_compat_keymgr_add)
	},
	[__crypto_method_keymgr_request * 2] = {
		.p__actvbridgehdlr_crypthandler_keymgr_request = (&__actvbridgehdlr_crypthandler_keymgr_request)
	},
	[__crypto_method_keymgr_request * 2 + 1] = {
		.p__actvbridgehdlr_crypthandler_compat_keymgr_request = (&__actvbridgehdlr_crypthandler_compat_keymgr_request)
	},
	[__crypto_method_keymgr_control * 2] = {
		.p__actvbridgehdlr_crypthandler_keymgr_control = (&__actvbridgehdlr_crypthandler_keymgr_control)
	},
	[__crypto_method_keymgr_control * 2 + 1] = {
		.p__actvbridgehdlr_crypthandler_compat_keymgr_control = (&__actvbridgehdlr_crypthandler_compat_keymgr_control)
	}
};

#endif
union crypto_hdlrs_union sysif_crypto_actvcapcallhdlr_table[__crypto_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __crypto_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__crypto_method_rng_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_rng_random_bytes * 2] = {
		.p__actvbridgecapcallhdlr_crypthandler_rng_random_bytes = (&__actvbridgecapcallhdlr_crypthandler_rng_random_bytes)
	},
	[__crypto_method_rng_random_bytes * 2 + 1] = {
		.p__actvbridgecapcallhdlr_crypthandler_compat_rng_random_bytes = (&__actvbridgecapcallhdlr_crypthandler_compat_rng_random_bytes)
	},
	[__crypto_method_rng_random_value * 2] = {
		.p__actvbridgecapcallhdlr_crypthandler_rng_random_value = (&__actvbridgecapcallhdlr_crypthandler_rng_random_value)
	},
	[__crypto_method_rng_random_value * 2 + 1] = {
		.p__actvbridgecapcallhdlr_crypthandler_compat_rng_random_value = (&__actvbridgecapcallhdlr_crypthandler_compat_rng_random_value)
	},
	[__crypto_method_procfs_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_procfs_read * 2] = {
		.p__actvbridgecapcallhdlr_crypthandler_procfs_read = (&__actvbridgecapcallhdlr_crypthandler_procfs_read)
	},
	[__crypto_method_procfs_read * 2 + 1] = {
		.p__actvbridgecapcallhdlr_crypthandler_compat_procfs_read = (&__actvbridgecapcallhdlr_crypthandler_compat_procfs_read)
	},
	[__crypto_method_procfs_write * 2] = {
		.p__actvbridgecapcallhdlr_crypthandler_procfs_write = (&__actvbridgecapcallhdlr_crypthandler_procfs_write)
	},
	[__crypto_method_procfs_write * 2 + 1] = {
		.p__actvbridgecapcallhdlr_crypthandler_compat_procfs_write = (&__actvbridgecapcallhdlr_crypthandler_compat_procfs_write)
	},
	[__crypto_method_crypto_register * 2] = {
		.p__actvbridgecapcallhdlr_crypthandler_crypto_register = (&__actvbridgecapcallhdlr_crypthandler_crypto_register)
	},
	[__crypto_method_crypto_register * 2 + 1] = {
		.p__actvbridgecapcallhdlr_crypthandler_compat_crypto_register = (&__actvbridgecapcallhdlr_crypthandler_compat_crypto_register)
	},
	[__crypto_method_keymgr_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_keymgr_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__crypto_method_keymgr_add * 2] = {
		.p__actvbridgecapcallhdlr_crypthandler_keymgr_add = (&__actvbridgecapcallhdlr_crypthandler_keymgr_add)
	},
	[__crypto_method_keymgr_add * 2 + 1] = {
		.p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_add = (&__actvbridgecapcallhdlr_crypthandler_compat_keymgr_add)
	},
	[__crypto_method_keymgr_request * 2] = {
		.p__actvbridgecapcallhdlr_crypthandler_keymgr_request = (&__actvbridgecapcallhdlr_crypthandler_keymgr_request)
	},
	[__crypto_method_keymgr_request * 2 + 1] = {
		.p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_request = (&__actvbridgecapcallhdlr_crypthandler_compat_keymgr_request)
	},
	[__crypto_method_keymgr_control * 2] = {
		.p__actvbridgecapcallhdlr_crypthandler_keymgr_control = (&__actvbridgecapcallhdlr_crypthandler_keymgr_control)
	},
	[__crypto_method_keymgr_control * 2 + 1] = {
		.p__actvbridgecapcallhdlr_crypthandler_compat_keymgr_control = (&__actvbridgecapcallhdlr_crypthandler_compat_keymgr_control)
	}
};

#endif
void sysif_show_crypto_methods(void)
{
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "cryptcall", "rng", "random_bytes", __crypto_method_rng_random_bytes);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "crypthandler", "rng", "random_bytes", __crypto_method_rng_random_bytes);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "cryptcall", "rng", "random_value", __crypto_method_rng_random_value);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "crypthandler", "rng", "random_value", __crypto_method_rng_random_value);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "cryptcall", "procfs", "read", __crypto_method_procfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "crypthandler", "procfs", "read", __crypto_method_procfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "cryptcall", "procfs", "write", __crypto_method_procfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "crypthandler", "procfs", "write", __crypto_method_procfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "cryptcall", "crypto", "register", __crypto_method_crypto_register);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "crypthandler", "crypto", "register", __crypto_method_crypto_register);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "cryptcall", "keymgr", "add", __crypto_method_keymgr_add);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "crypthandler", "keymgr", "add", __crypto_method_keymgr_add);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "cryptcall", "keymgr", "request", __crypto_method_keymgr_request);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "crypthandler", "keymgr", "request", __crypto_method_keymgr_request);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "cryptcall", "keymgr", "control", __crypto_method_keymgr_control);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "crypthandler", "keymgr", "control", __crypto_method_keymgr_control);
	hm_info("%s_%s, max method num: %d\n", "crypto", "method", __crypto_method_MAX);
}

#endif
#endif
