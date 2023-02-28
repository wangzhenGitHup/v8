/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for crypto
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-verif-kernel/git/ulibs/include/libhmsrv_crypt/sysif/api.sysif -I ../../../../../work-shared/hm-verif-kernel/git/ulibs/include --api-dest ../image/usr/include/generated/sysif_client/crypt/libsysif/crypt/api.h --server-dest ../image/usr/include/generated/sysif_server/crypt/libsysif/crypt/server.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_CRYPTO_API_H
#define LIBSYSIF_CRYPTO_API_H
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
#ifdef SYSIF_GEN_IFACE
#include <hmkernel/compiler.h>
#include <asm/actv_rpc.h>
#include <hongmeng/errno.h>
#include <hongmeng/syscall.h>
#include <hongmeng/panic.h>
#include <libstrict/strict.h>
static int __used __noinline __opt_noframe __internal_rpccall_nobuf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_buf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_retbuf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_fallback(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_nobuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(NoBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_buf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(SendBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_retbuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(RetBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_fallback(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(, ret);
	return ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_cryptcall_rng_random_bytes(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_cryptcall_rng_random_bytes(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_cryptcall_rng_random_bytes(unsigned long long __rpc_info, void *__buf, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags)
{
	int __ret;
	enum crypt_rng_type __maybe_unused __actv_local_var_rng_type = rng_type;
	unsigned int __maybe_unused __actv_local_var_bytes_len = bytes_len;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_cryptcall_rng_random_bytes(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(rng_type, __actv_local_var_rng_type), __ARCH_ACTV_RPC_PASS_ARG(bytes_len, __actv_local_var_bytes_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_cryptcall_rng_random_bytes(rref_t __rref, unsigned long long __rpc_info, void *__buf, enum crypt_rng_type rng_type, unsigned int bytes_len, int flags)
{
	int __ret;
	enum crypt_rng_type __maybe_unused __actv_local_var_rng_type = rng_type;
	unsigned int __maybe_unused __actv_local_var_bytes_len = bytes_len;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_cryptcall_rng_random_bytes(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(rng_type, __actv_local_var_rng_type), __ARCH_ACTV_RPC_PASS_ARG(bytes_len, __actv_local_var_bytes_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_cryptcall_rng_random_value(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_cryptcall_rng_random_value(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_cryptcall_rng_random_value(unsigned long long __rpc_info, void *__buf, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags)
{
	int __ret;
	enum crypt_rng_type __maybe_unused __actv_local_var_rng_type = rng_type;
	enum crypt_rng_rand_val_type __maybe_unused __actv_local_var_value_type = value_type;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_cryptcall_rng_random_value(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(rng_type, __actv_local_var_rng_type), __ARCH_ACTV_RPC_PASS_ARG(value_type, __actv_local_var_value_type), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_cryptcall_rng_random_value(rref_t __rref, unsigned long long __rpc_info, void *__buf, enum crypt_rng_type rng_type, enum crypt_rng_rand_val_type value_type, int flags)
{
	int __ret;
	enum crypt_rng_type __maybe_unused __actv_local_var_rng_type = rng_type;
	enum crypt_rng_rand_val_type __maybe_unused __actv_local_var_value_type = value_type;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_cryptcall_rng_random_value(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(rng_type, __actv_local_var_rng_type), __ARCH_ACTV_RPC_PASS_ARG(value_type, __actv_local_var_value_type), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_cryptcall_procfs_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_cryptcall_procfs_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_cryptcall_procfs_read(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_cryptcall_procfs_read(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_cryptcall_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_cryptcall_procfs_read(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_cryptcall_procfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_cryptcall_procfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_cryptcall_procfs_write(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_cryptcall_procfs_write(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_cryptcall_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_cryptcall_procfs_write(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_cryptcall_crypto_register(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_cryptcall_crypto_register(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_cryptcall_crypto_register(unsigned long long __rpc_info, void *__buf, uref_t uref)
{
	int __ret;
	uref_t __maybe_unused __actv_local_var_uref = uref;
	__ret = ____actvcall_cryptcall_crypto_register(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(uref, __actv_local_var_uref));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_cryptcall_crypto_register(rref_t __rref, unsigned long long __rpc_info, void *__buf, uref_t uref)
{
	int __ret;
	uref_t __maybe_unused __actv_local_var_uref = uref;
	__ret = ____actvcapcall_cryptcall_crypto_register(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(uref, __actv_local_var_uref));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_cryptcall_keymgr_add(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_cryptcall_keymgr_add(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_cryptcall_keymgr_add(unsigned long long __rpc_info, void *__buf, int shm_id, struct key_add_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct key_add_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcall_cryptcall_keymgr_add(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_cryptcall_keymgr_add(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct key_add_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct key_add_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcapcall_cryptcall_keymgr_add(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_cryptcall_keymgr_request(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_cryptcall_keymgr_request(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_cryptcall_keymgr_request(unsigned long long __rpc_info, void *__buf, int shm_id, struct key_request_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct key_request_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcall_cryptcall_keymgr_request(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_cryptcall_keymgr_request(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct key_request_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct key_request_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcapcall_cryptcall_keymgr_request(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_retbuf"))) ____actvcall_cryptcall_keymgr_control(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_retbuf"))) ____actvcapcall_cryptcall_keymgr_control(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_cryptcall_keymgr_control(unsigned long long __rpc_info, void *__buf, int shm_id, struct keyctl_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct keyctl_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcall_cryptcall_keymgr_control(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_cryptcall_keymgr_control(rref_t __rref, unsigned long long __rpc_info, void *__buf, int shm_id, struct keyctl_param param)
{
	int __ret;
	int __maybe_unused __actv_local_var_shm_id = shm_id;
	struct keyctl_param __maybe_unused __actv_local_var_param = param;
	__ret = ____actvcapcall_cryptcall_keymgr_control(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_id, __actv_local_var_shm_id), __ARCH_ACTV_RPC_PASS_ARG(param, __actv_local_var_param));
	return __ret;
}

#endif
#endif
