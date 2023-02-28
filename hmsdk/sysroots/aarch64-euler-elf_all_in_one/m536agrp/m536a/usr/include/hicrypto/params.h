/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: parameters abstraction for framework interfaces
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 *
 * WARN: All passed |params| ought to end with CRPT_PARAM_END,
 *       and for each param, data is corresepond with its key which indicates required type
 */

#ifndef CRYPTO_HEADER_CRPT_PARAMS_H
#define CRYPTO_HEADER_CRPT_PARAMS_H

#include <hicrypto/target.h>
#include <hicrypto/error.h>
#include <hicrypto/thread.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct {
    struct {
        const char *name; // NULL as the end of meaningful params
        unsigned int hashed;
    } identify;
    int type;
    uintptr_t data;
    size_t size;
    size_t return_size;
} CRPT_PARAM;
typedef int(CRPT_CALLBACK)(const CRPT_PARAM params[], void *arg);

// clang-format off
#define CRPT_PARAM_SIZE_UNMODIFIED              (size_t)(-1)
#define CRPT_PARAM_END                          {{NULL, 0}, 0, (uintptr_t)NULL, 0, 0}
#define CRPT_PARAM_DEFN(name, type, data, size) \
    {{(name), 0}, (type), (uintptr_t)(data), (size), CRPT_PARAM_SIZE_UNMODIFIED}
// clang-format on

#define CRPT_PARAM_GENERIC          0x00 /* generic or unspecified */
#define CRPT_PARAM_INTEGER          0x01 /* signed integer */
#define CRPT_PARAM_UNSIGNED_INTEGER 0x02 /* unsigned integer */
#define CRPT_PARAM_REAL             0x03 /* C binary floating point values in native form and alignment. */
#define CRPT_PARAM_UTF8_STRING      0x04 /* printable string. */
#define CRPT_PARAM_UTF8_PTR         0x05 /* pointer to a printable string */
#define CRPT_PARAM_OCTET_STRING     0x06 /* string of bytes, expected to be printed as a hexdump. */
#define CRPT_PARAM_OCTET_PTR        0x07 /* pointer to a string of bytes */
#define CRPT_PARAM_CALLABLE         0x08 /* callable object, usually callbacks or hooks */

/** @defgroup crypto_param */

/**
 * @ingroup crypto_param
 *
 * @brief check if param instance modified
 *
 * @param p [IN] param instance
 *
 * @retval return 1 if modified, otherwise 0
 */
CRPT_INLINE unsigned int CRPT_PARAM_modified(const CRPT_PARAM *p)
{
    CRPT_ASSERT(p != NULL);
    return p->return_size != CRPT_PARAM_SIZE_UNMODIFIED;
}

/**
 * @ingroup crypto_param
 *
 * @brief check if all param instance modified
 *
 * @param params [IN] param instance array
 *
 * @retval return 1 if modified, otherwise 0
 */
CRPT_INLINE unsigned int CRPT_PARAM_all_modifed(const CRPT_PARAM params[])
{
    CRPT_ASSERT(params != NULL);
    const CRPT_PARAM *p = params;
    while (p->identify.name != NULL) {
        if (!CRPT_PARAM_modified(p)) {
            return 0;
        }
        p++;
    }
    return p != params ? 1 : 0;
}

/* Search an CRPT_PARAM array for a matching name */
/**
 * @ingroup crypto_param
 *
 * @brief locate the named parameter from CRPT_PARAM array(internal mostly)
 *
 * @param params [IN] a CRPT_PARAM array
 * @param plen [IN] array len
 * @param name [IN] name of parameter,defined in evp.h
 *
 * @retval NULL if no such entry
 */
CRPT_EXPORT CRPT_PARAM *CRPT_PARAM_locate(CRPT_PARAM *params, size_t plen, const char *name);

/**
 * @ingroup crypto_param
 *
 * @brief locate the named parameter from CRPT_PARAM array(internal mostly)
 *
 * @param params [IN] a CRPT_PARAM array
 * @param plen [IN] array len
 * @param name [IN] name of parameter,defined in evp.h
 *
 * @retval NULL if no such entry
 */
CRPT_EXPORT const CRPT_PARAM *CRPT_PARAM_locate_const(const CRPT_PARAM *params, size_t plen, const char *name);

/**
 * @ingroup crypto_param
 *
 * @brief construct a parameter |p| with given parameters(internal mostly)
 *
 * @param p [OUT] a CRPT_PARAM array
 * @param name [IN] name of parameter
 * @param type [IN] type of parameter
 * @param data [IN] pointer to data whose type is |type|
 * @param size [IN] size of data whose type is |type|
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_PARAM_construct(CRPT_PARAM *p, const char *name, int type, void *data, size_t size);

/**
 * @ingroup crypto_param
 *
 * @brief construct a const parameter |p| with given parameters(internal mostly)
 *
 * @param p [OUT] a CRPT_PARAM array
 * @param name [IN] name of parameter
 * @param type [IN] type of parameter
 * @param data [IN] pointer to data whose type is |type|
 * @param size [IN] size of data whose type is |type|
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_PARAM_construct_const(CRPT_PARAM *p, const char *name, int type, const void *data, size_t size);

/**
 * @ingroup crypto_param
 *
 * @brief check return_size of the parameter in array
 *
 * @param params [IN] a CRPT_PARAM array
 * @param n [IN] array size
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_PARAM_check(CRPT_PARAM *params, size_t n);

#define CRPT_PARAM_MAKE_FUNCTION(TYPE, tag, type)                                                      \
    CRPT_INLINE int CRPT_PARAM_construct_##tag(CRPT_PARAM *p, const char *name, type *v)               \
    {                                                                                                  \
        return CRPT_PARAM_construct(p, name, CRPT_PARAM_##TYPE, (void *)v, sizeof(type));              \
    }                                                                                                  \
    CRPT_INLINE int CRPT_PARAM_construct_##tag##_const(CRPT_PARAM *p, const char *name, const type *v) \
    {                                                                                                  \
        return CRPT_PARAM_construct_const(p, name, CRPT_PARAM_##TYPE, (const void *)v, sizeof(type));  \
    }                                                                                                  \
    CRPT_INLINE type CRPT_PARAM_get_##tag(const CRPT_PARAM *p)                                         \
    {                                                                                                  \
        type v = 0;                                                                                    \
        if (p != NULL && p->size == sizeof(type)) {                                                    \
            v = *(const type *)p->data;                                                                \
        }                                                                                              \
        return v;                                                                                      \
    }                                                                                                  \
    CRPT_INLINE int CRPT_PARAM_set_##tag(CRPT_PARAM *p, type v)                                        \
    {                                                                                                  \
        if (p != NULL && p->size == sizeof(type)) {                                                    \
            *(type *)p->data = v;                                                                      \
            p->return_size = sizeof(type);                                                             \
            return 0;                                                                                  \
        }                                                                                              \
        return CRPT_EINVAL;                                                                            \
    }

/**
 * int, char, short, long, llong, ssize_t
 * uint, uchar, ushort, ulong, ullong size_t
 *
 * int8_t, int16_t, int32_t, int64_t
 * uint8_t, uint16_t, uint32_t, uint64_t
 *
 */

CRPT_PARAM_MAKE_FUNCTION(INTEGER, int, int)
CRPT_PARAM_MAKE_FUNCTION(INTEGER, char, char)
CRPT_PARAM_MAKE_FUNCTION(INTEGER, short, short)
CRPT_PARAM_MAKE_FUNCTION(INTEGER, long, long)
CRPT_PARAM_MAKE_FUNCTION(INTEGER, llong, long long)
CRPT_PARAM_MAKE_FUNCTION(INTEGER, ssize_t, ssize_t)

CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, uint, unsigned int)
CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, uchar, unsigned char)
CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, ushort, unsigned short)
CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, ulong, unsigned long)
CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, ullong, unsigned long long)
CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, size_t, size_t)

CRPT_PARAM_MAKE_FUNCTION(INTEGER, int8_t, int8_t)
CRPT_PARAM_MAKE_FUNCTION(INTEGER, int16_t, int16_t)
CRPT_PARAM_MAKE_FUNCTION(INTEGER, int32_t, int32_t)
CRPT_PARAM_MAKE_FUNCTION(INTEGER, int64_t, int64_t)

CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, uint8_t, uint8_t)
CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, uint16_t, uint16_t)
CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, uint32_t, uint32_t)
CRPT_PARAM_MAKE_FUNCTION(UNSIGNED_INTEGER, uint64_t, uint64_t)

/* utf8 string */
/**
 * @ingroup crypto_param
 *
 * @brief CRPT_PARAM_construct_const for string type
 *
 * @param p [IN] parameter
 * @param name [IN] name of parameter
 * @param v [IN] const data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_INLINE int CRPT_PARAM_construct_utf8_const(CRPT_PARAM *p, const char *name, const char *v)
{
    // for zero-terminated utf8-string, no need to get it's length
    return CRPT_PARAM_construct_const(p, name, CRPT_PARAM_UTF8_STRING, (const void *)v, 0);
}

/**
 * @ingroup crypto_param
 *
 * @brief CRPT_PARAM_construct_const for string type
 *
 * @param p [IN] parameter
 * @param name [IN] name of parameter
 * @param v [IN] data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_INLINE int CRPT_PARAM_construct_utf8(CRPT_PARAM *p, const char *name, char *v)
{
    // for zero-terminated utf8-string, no need to get it's length
    return CRPT_PARAM_construct(p, name, CRPT_PARAM_UTF8_STRING, (void *)v, 0);
}

/**
 * @ingroup crypto_param
 *
 * @brief get data from parameter
 *
 * @param p [IN] parameter
 *
 * @retval NULL if p is NULL, else return p->data
 */
CRPT_INLINE const char *CRPT_PARAM_get_utf8_const(const CRPT_PARAM *p)
{
    return p != NULL ? (const char *)p->data : NULL;
}

/* octet string */
/**
 * @ingroup crypto_param
 *
 * @brief CRPT_PARAM_construct_const for octet type
 *
 * @param p [IN] parameter
 * @param name [IN] name of parameter
 * @param buff [IN] const octet buffer
 * @param buffsize [IN] size of buffer
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_INLINE int CRPT_PARAM_construct_octets_const(CRPT_PARAM *p, const char *name, const unsigned char *buff,
                                                  size_t buffsize)
{
    return CRPT_PARAM_construct_const(p, name, CRPT_PARAM_OCTET_STRING, (const void *)buff, buffsize);
}

/**
 * @ingroup crypto_param
 *
 * @brief CRPT_PARAM_construct_const for octet type
 *
 * @param p [IN] parameter
 * @param name [IN] name of parameter
 * @param buff [IN] octet buffer
 * @param buffsize [IN] size of buffer
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_INLINE int CRPT_PARAM_construct_octets(CRPT_PARAM *p, const char *name, unsigned char *buff, size_t buffsize)
{
    return CRPT_PARAM_construct(p, name, CRPT_PARAM_OCTET_STRING, (void *)buff, buffsize);
}

/**
 * @ingroup crypto_param
 *
 * @brief get data from parameter
 *
 * @param p [IN] parameter
 *
 * @retval NULL if p is NULL, else return p->data
 */
CRPT_INLINE unsigned const char *CRPT_PARAM_get_octets_const(const CRPT_PARAM *p)
{
    return p != NULL ? (const unsigned char *)p->data : NULL;
}

#if defined(__cplusplus)
}
#endif
#endif
