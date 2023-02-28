/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: function declarations of string operations
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_STRING_H
#define CRYPTO_HEADER_STRING_H

#include <hicrypto/target.h>

/* securec */
#ifndef EOK
#define EOK 0
#endif
/** @defgroup securec_string */

/**
 * @ingroup securec_string
 *
 * @brief copies the value c into the object pointed to by dest
 *
 * @param dest [IN] dest pointer to be copyed
 * @param destsize [IN] dest pointer size
 * @param c [IN] the character c
 * @param count [IN] copy count
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_IMPORT int memset_s(void *dest, size_t destsize, int c, size_t count);

/**
 * @ingroup securec_string
 *
 * @brief copies count characters from the src to dest
 *
 * @param dest [IN] dest pointer to be copyed
 * @param destsize [IN] dest pointer size
 * @param src [IN] the object pointed to by src
 * @param count [IN] copy count
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_IMPORT int memcpy_s(void *dest, size_t destsize, const void *src, size_t count);

#ifndef CRPT_NO_STDARG
/**
 * @ingroup securec_string
 *
 * @brief write formatted output using a pointer to a list of arguments
 *
 * @param dest [IN] dest pointer
 * @param destsize [IN] dest pointer size
 * @param count [IN] maximum number of characters to write
 * @param format [IN] format specification
 * @param argList [IN] pointer to list of arguments.
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_IMPORT int vsnprintf_s(char *dest, size_t destsize, size_t count, const char *format, va_list argList)
    ATTRIBUT_FORMAT(4, 0);
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @ingroup crypto_runtime
 *
 * @brief duplicate given string |str|
 *
 * @param str [IN] given string
 *
 * @retval NULL if failed
 */
CRPT_EXPORT char *CRPT_strdup(const char *str);

/**
 * @ingroup crypto_runtime
 *
 * @brief duplicate given string |str|, but only copies at most n bytes
 *
 * @param str [IN] given string
 * @param s [IN] duplicate bytes
 *
 * @retval NULL if failed
 */
CRPT_EXPORT char *CRPT_strndup(const char *str, size_t s);

#if defined(__cplusplus)
}
#endif

#endif
