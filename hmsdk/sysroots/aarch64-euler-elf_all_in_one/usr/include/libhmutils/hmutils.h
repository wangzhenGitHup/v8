/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Definition of libhmutils
 * Author: Huawei OS Kernel Lab
 * Create: Mon May 31 19:46:33 2021
 */

#ifndef ULIBS_LIBHMUTILS__H
#define ULIBS_LIBHMUTILS__H

static inline char *trans_to_hex_upper(char *_str, char in_val)
{
	const char hex_upper_array[] = "0123456789ABCDEF";
	char *str = _str;
	*str++ = hex_upper_array[((unsigned char)(in_val) & 0xf0) >> 4];
	*str++ = hex_upper_array[((unsigned char)(in_val) & 0x0f)];
	return str;
}

#endif /* ULIBS_LIBHMUTILS__H */
