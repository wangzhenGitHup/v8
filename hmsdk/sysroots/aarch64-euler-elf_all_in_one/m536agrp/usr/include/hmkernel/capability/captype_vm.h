/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Definition of VM captype
 * Author: IT Software Infrastructure Lab, Munich Research Center
 * Create: Thu Feb 7 16:53:23 2019
 */
/*
 * Must choose one GRANT type from ALL/NO/COARSE/FINE
 * Must choose one GRANTMOVE type from ALL/NO/COARSE
 */
CAPTYPE(VM, 12, CAPALLGRANT(VM)
		CAPNOGRANTMOVE(VM)
		CAPNODEFAULTCREF(VM)
		CAPRAWCREFRLOOKUP(VM)
		CAPDEFAULTSIZE(VM),
	CAPMETHOD(VM, GetIORegNum)
	CAPMETHOD(VM, GetIORegs)
	CAPMETHOD(VM, RegisterIOReg)
	CAPMETHOD(VM, BindVcpuListener)
	CAPMETHOD(VM, CreateVnotify)
	CAPMETHOD(VM, VnotifyCreateChannel)
	CAPMETHOD(VM, VnotifyDestroyChannel)
	CAPMETHOD(VM, VnotifyConfig)
	CAPMETHOD(VM, GetNumVcpus)
	CAPMETHOD(VM, VperfctxConfig)
	CAPMETHOD(VM, VperfctxAttach)
	CAPMETHOD(VM, VperfctxDetach)
	CAPMETHOD(VM, RegisterMMIORegion)
	CAPMETHOD(VM, BindVcpuMMIODispatcher)
	CAPMETHOD(VM, AssertIrq)
	)

#ifdef CAP_EXPORT_API
#ifndef CAP_VM_API_EXPORTED
#define CAP_VM_API_EXPORTED

struct sysarg_vm_config {
	cref_t vm_vspace;
	__u16 dev_group_id;
};

struct sysarg_vm_vnotify_info {
	__u32 irq;
	__u64 addr;
	__u64 size;
};

enum {
	CRIGHT_VM_MAX
};

#endif
#endif
