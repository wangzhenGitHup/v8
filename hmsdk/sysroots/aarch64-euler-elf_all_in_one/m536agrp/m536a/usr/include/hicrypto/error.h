/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: error stack, vision to view program from outside
 * Author: zhanxin
 * Create: Tue Jul 07 09:20:24 2020
 */

#ifndef CRYPTO_HEADER_ERROR_H
#define CRYPTO_HEADER_ERROR_H

#include <hicrypto/target.h>

#ifndef CRPT_NO_STREAM
#include <hicrypto/stream.h>
#endif

typedef struct crpt_error_st {
    int error;
    void *data;
    const char *file;
    int line;
    unsigned mark : 1;
} CRPT_ERROR;
CRPT_STATIC_ASSERT(sizeof(unsigned int) >= 4, "sizeof(unsigned int) must larger than 4 bytes");
#ifndef CRPT_ERROR_DATA_BUFFER_SIZE
#define CRPT_ERROR_DATA_BUFFER_SIZE 256
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/** @defgroup crypto_error */

/**
 * @ingroup crypto_error
 *
 * @brief put error
 *
 * @param error [IN] error number
 * @param data [IN] error data
 * @param file [IN] file name
 * @param line [IN] line number
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_ERROR_put(int error, void *data, const char *file, int line);
#define CRPT_ERROR_raise(err) CRPT_ERROR_put(err, NULL, __FILE__, __LINE__)
#ifndef CRPT_NO_STDARG

/**
 * @ingroup crypto_error
 *
 * @brief format error message
 *
 * @param format [IN]format specification
 *
 * @retval fomat string
 */
CRPT_EXPORT char *crpt_error_format(const char *format, ...) ATTRIBUT_FORMAT(1, 2);
#define CRPT_ERROR_raise_data(err, ...) CRPT_ERROR_put(err, crpt_error_format(__VA_ARGS__), __FILE__, __LINE__)
#else
#define CRPT_ERROR_raise_data(err, ...) CRPT_ERROR_put(err, NULL, __FILE__, __LINE__)
#endif

#ifndef CRPT_NO_STREAM
/**
 * @ingroup crypto_error
 *
 * @brief print error message
 *
 * @param stream [IN] stream to be printed
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_print_errors(CRPT_STREAM *stream);
#endif

/**
 * @ingroup crypto_error
 *
 * @brief clear error message
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int CRPT_clear_errors(void);


/** Developer API */
/**
 * @ingroup crypto_error
 *
 * @brief pop error struct
 *
 * @retval error struct
 */
CRPT_EXPORT CRPT_ERROR *crpt_error_pop(void);

/**
 * @ingroup crypto_error
 *
 * @brief peek error strcut
 *
 * @retval error struct
 */
CRPT_EXPORT CRPT_ERROR *crpt_error_peek(void);

/**
 * @ingroup crypto_error
 *
 * @brief clear specified error strcut
 *
 * @param err [IN] error instance
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int crpt_error_clear(CRPT_ERROR *err);

/**
 * @ingroup crypto_error
 *
 * @brief set custom data
 *
 * @param data [IN] custom data
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int crpt_error_set_data(void *data);

/**
 * @ingroup crypto_error
 *
 * @brief mark error
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int crpt_error_mark(void);

/**
 * @ingroup crypto_error
 *
 * @brief pop error until mark position
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int crpt_error_pop_to_mark(void);

/**
 * @ingroup crypto_error
 *
 * @brief clear last mark position
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int crpt_error_clear_last_mark(void);

/**
 * will invoke `print` with all errors in stack, and then invoke with `error = NULL`
 */
/**
 * @ingroup crypto_error
 *
 * @brief invoke `print` with all errors in stack,
 * and then invoke with `error = NULL`
 *
 * @param print [IN] print function
 * @param arg [IN] arguments
 *
 * @retval error code, @see <hicrypto/errno.h>
 */
CRPT_EXPORT int crpt_print_errors_cb(int (*print)(const CRPT_ERROR *err, void *arg), void *arg);

/**
 * Error coding
 *
 * `err = 0` for operate successfully
 *
 * TODO: dynamic error encoding and error textualization
 *
 */

/* system generic errors */
#define CRPT_SUCCESS                 0
#define CRPT_EPERM                 (-1)   /* Operation not permitted */
#define CRPT_ENOENT                (-2)   /* No such entry, file or directory */
#define CRPT_ESRCH                 (-3)   /* No such process */
#define CRPT_EINTR                 (-4)   /* Interrupted system call */
#define CRPT_EIO                   (-5)   /* I/O error */
#define CRPT_ENXIO                 (-6)   /* No such device or address */
#define CRPT_E2BIG                 (-7)   /* Argument list too long */
#define CRPT_ENOEXEC               (-8)   /* Exec format error */
#define CRPT_EBADF                 (-9)   /* Bad file number */
#define CRPT_ECHILD                (-10)  /* No child processes */
#define CRPT_EAGAIN                (-11)  /* Try again */
#define CRPT_ENOMEM                (-12)  /* Out of memory */
#define CRPT_EACCES                (-13)  /* Permission denied */
#define CRPT_EFAULT                (-14)  /* Bad address */
#define CRPT_ENOTBLK               (-15)  /* Block device required */
#define CRPT_EBUSY                 (-16)  /* Device or resource busy */
#define CRPT_EEXIST                (-17)  /* File exists */
#define CRPT_EXDEV                 (-18)  /* Cross-device link */
#define CRPT_ENODEV                (-19)  /* No such device */
#define CRPT_ENOTDIR               (-20)  /* Not a directory */
#define CRPT_EISDIR                (-21)  /* Is a directory */
#define CRPT_EINVAL                (-22)  /* Invalid argument */
#define CRPT_ENFILE                (-23)  /* File table overflow */
#define CRPT_EMFILE                (-24)  /* Too many open files */
#define CRPT_ENOTTY                (-25)  /* Not a typewriter */
#define CRPT_ETXTBSY               (-26)  /* Text file busy */
#define CRPT_EFBIG                 (-27)  /* File too large */
#define CRPT_ENOSPC                (-28)  /* No space left on device */
#define CRPT_ESPIPE                (-29)  /* Illegal seek */
#define CRPT_EROFS                 (-30)  /* Read-only file system */
#define CRPT_EMLINK                (-31)  /* Too many links */
#define CRPT_EPIPE                 (-32)  /* Broken pipe */
#define CRPT_EDOM                  (-33)  /* Math argument out of domain of func */
#define CRPT_ERANGE                (-34)  /* Math result not representable */
#define CRPT_ERESERVED_SYSTEMS_MAX (-255) // Error code reserved for system(-1 ~ -255)

/* crypto generic errors */
#define CRPT_EUNDEF                (-256) // Undefined error
#define CRPT_EBADSEQ               (-257) // Bad sequence
#define CRPT_ENOIMPL               (-258) // Not implemented
#define CRPT_ENOTSUP               (-259) // Not supported
#define CRPT_ESTATUS               (-260) // Wrong status
#define CRPT_ELIMIT                (-261) // Resource limitation
#define CRPT_EINTERNAL             (-262) // Internal error
#define CRPT_ERESERVED_GENERIC_MAX (-511) // Reserved library error code(-256 ~ -511)

/* base libaray offset of user error code   */
#define CRPT_ERROR_USER             128
/* base user error code */
#define CRPT_ELIB_USER             (-(512 + CRPT_ERROR_USER * 256))

#if defined(__cplusplus)
}
#endif

#endif
