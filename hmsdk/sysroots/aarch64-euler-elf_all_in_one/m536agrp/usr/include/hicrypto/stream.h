/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Basic Input/Output device abstraction
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_BIO_H
#define CRYPTO_HEADER_BIO_H

#include <hicrypto/target.h>

#if !(defined CRPT_STREAM_DEFAULT_BUFFER_SIZE) && !(defined HICRYPTO_NO_DEFAULT)
#define CRPT_STREAM_DEFAULT_BUFFER_SIZE 1024
#endif

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct crpt_stream_st CRPT_STREAM;
struct crpt_stream_st {
    unsigned int type;
    void *state;
    int (*write)(void *, const unsigned char *, size_t, size_t *);
    int (*read)(void *, unsigned char *, size_t, size_t *);
    int (*puts)(void *, const char *);
    int (*gets)(void *, char *, size_t);
};
/** @defgroup crypto_stream */

/**
 * @ingroup crypto_stream
 *
 * @brief write buffer to stream
 *
 * @param stream [IN/OUT] stream to write
 * @param buff [IN] write buffer
 * @param buffsize [IN] buffer size
 * @param wtlen [OUT] wirte bytes
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_STREAM_write(CRPT_STREAM *stream, const unsigned char *buff, size_t buffsize, size_t *wtlen);

/**
 * @ingroup crypto_stream
 *
 * @brief read buffer to stream
 *
 * @param stream [IN/OUT] stream to read
 * @param buff [IN] read buffer
 * @param buffsize [IN] buffer size
 * @param wtlen [OUT] read bytes
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_STREAM_read(CRPT_STREAM *stream, unsigned char *buff, size_t buffsize, size_t *rdlen);

/**
 * @ingroup crypto_stream
 *
 * @brief puts buffer to stream
 *
 * @param stream [IN/OUT] stream to puts
 * @param buff [IN] puts buffer
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_STREAM_puts(CRPT_STREAM *stream, const char *buff);

/**
 * @ingroup crypto_stream
 *
 * @brief gets buffer to stream
 *
 * @param stream [IN/OUT] stream to puts
 * @param buff [OUT] gets buffer
 * @param buffsize [IN] buffer size
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_STREAM_gets(CRPT_STREAM *stream, char *buff, size_t buffsize);

#ifndef CRPT_NO_STDARG

/**
 * @ingroup crypto_stream
 *
 * @brief writes the C string pointed by format to stream
 *
 * @param stream [IN/OUT] stream to puts
 * @param format [OUT] format specification
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_STREAM_printf(CRPT_STREAM *stream, const char *format, ...) ATTRIBUT_FORMAT(2, 3);
#endif

#if defined(__cplusplus)
}
#endif

#endif
