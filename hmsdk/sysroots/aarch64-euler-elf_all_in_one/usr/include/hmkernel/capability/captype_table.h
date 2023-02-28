/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: Table capability types definition
 * Author: Huawei OS Kernel Lab
 * Create: Mon Feb 08 16:22:28 2021
 */
/*
 * Must choose one GRANT type from ALL/NO/COARSE/FINE
 * Must choose one GRANTMOVE type from ALL/NO/COARSE
 */
CAPTYPE(Table, 16, CAPNOGRANT(Table)
		   CAPNOGRANTMOVE(Table)
		   CAPDEFAULTSIZE(Table)
		   CAPNODEFAULTCREF(Table)
		   CAPRAWCREFRLOOKUP(Table),
	)

#ifdef CAP_EXPORT_API

enum {
	CRIGHT_TABLE_MAX
};

#endif
