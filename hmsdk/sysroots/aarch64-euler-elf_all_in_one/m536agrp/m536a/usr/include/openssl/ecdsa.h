/*
 * Copyright 2002-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef ECDSA_H
# define ECDSA_H
#include <openssl/ec.h>

#ifndef OPENSSL_NO_FIPS
#define ECDSA_VERIFY_SIG_MIN_KEY_SIZE 160
#define ECDSA_SIGN_SIG_MIN_KEY_SIZE 224
#endif

#endif // ECDSA_H
