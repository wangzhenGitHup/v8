/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Destination: Wrapper of prng
 * Author: Huawei OS Kernel Lab
 * Create: Wed Jul 24 21:51:09 2019
 */
#ifndef LIBHMCRYPT_PRNG_WRAPPER_H
#define LIBHMCRYPT_PRNG_WRAPPER_H

typedef struct hmcrypt_prng_state hmcrypt_prng_state_t;

/*
 * Start the PRNG
 * @return A pointer to an initialized prng state if successful
 */
hmcrypt_prng_state_t *hmcrypt_prng_start(void);

/*
 * Add entropy to the PRNG state
 * @param in       The data to add
 * @param len      Length of the data to add, its value has no limit
 * @param prng     PRNG state to update
 * @return E_HM_OK if successful
 */
int hmcrypt_prng_add_entropy(const unsigned char *in, unsigned int len,
			     hmcrypt_prng_state_t *prng);

/*
 * Make the PRNG ready to read from
 * @param prng   The PRNG to make active
 * @return E_HM_OK if successful
 */
int hmcrypt_prng_ready(hmcrypt_prng_state_t *prng);

/*
 * Read from the PRNG
 * @param out      [out] Destination, alloced by caller
 * @param len      Length of output, its value has no limit
 * @param prng     The active PRNG to read from
 * @return Number of octets read
 */
unsigned int hmcrypt_prng_read(unsigned char *out, unsigned int len,
			       hmcrypt_prng_state_t *prng);

/*
 * Export the PRNG state
 * @param out       [out] Destination
 * @param len       [in/out] Max size and resulting size of the state
 * @param prng      The PRNG to export
 * @return E_HM_OK if successful
 */
int hmcrypt_prng_export(unsigned char *out, unsigned int *len,
			hmcrypt_prng_state_t *prng);

/*
 * Import a PRNG state
 * @param in       Pointer to the PRNG state
 * @param len      Size of the state
 * @param prng     The PRNG to import
 * @return E_HM_OK if successful
 */
int hmcrypt_prng_import(const unsigned char *in, unsigned int len,
			hmcrypt_prng_state_t *prng);

/*
 * Terminate the PRNG
 * @param prng   The PRNG to terminate
 */
void hmcrypt_prng_done(hmcrypt_prng_state_t *prng);

#endif
