/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2018-2020. All rights reserved.
 * Description: Capability-based IrqCtrl management
 * Author: Huawei OS Kernel Lab
 * Create: Thu Oct 18 00:05:04 2018
 */
/*
 * Must choose one GRANT type from ALL/NO/COARSE/FINE
 * Must choose one GRANTMOVE type from ALL/NO/COARSE
 */
CAPTYPE(IrqCtrl, 9, CAPFINEGRANT(IrqCtrl)
		    CAPALLGRANTMOVE(IrqCtrl)
		    CAPNODEFAULTCREF(IrqCtrl)
		    CAPRAWCREFRLOOKUP(IrqCtrl)
		    CAPDEFAULTSIZE(IrqCtrl),
	/* for owner */
	CAPMETHOD(IrqCtrl, Info)
	CAPMETHOD(IrqCtrl, ToLogic)
	/*
	 * Note that we don't have a corresponding revoke operation
	 * to reverse the state change by assign because it is not
	 * easy to prevent owner revoke a irq which has already assigned
	 * to other and grant it to a second cnode, which makes owner
	 * of irqctrl has a way to grant a irqctrl to another cnode
	 * but disable its granting without revoking its grant.
	 * */
	CAPMETHOD(IrqCtrl, Assign)

	/* for user */
	CAPMETHOD(IrqCtrl, Register)
	CAPMETHOD(IrqCtrl, UnRegister)
	CAPMETHOD(IrqCtrl, Enable)
	CAPMETHOD(IrqCtrl, Disable)
	CAPMETHOD(IrqCtrl, Config)
	CAPMETHOD(IrqCtrl, SetWake)
	CAPMETHOD(IrqCtrl, SetAttribute)

	/* for special users to trigger sgi */
	CAPMETHOD(IrqCtrl, SGI)
	CAPMETHOD(IrqCtrl, Ioctl)
	/* for statistics */
	CAPMETHOD(IrqCtrl, Stat)
	CAPMETHOD(IrqCtrl, Suspend)
	CAPMETHOD(IrqCtrl, Resume)
	CAPERRNO(IrqCtrl, EHMERROR,	IRQCTRL_STATE,	"E_HM_IRQCTRL_STATE")
)

#ifdef CAP_EXPORT_API
#ifndef CAP_IRQCTRL_API_EXPORTED
#define CAP_IRQCTRL_API_EXPORTED

enum {
	CRIGHT_IRQCTRL_OWNER_BIT,
	CRIGHT_IRQCTRL_SGI_BIT,
	CRIGHT_IRQCTRL_IOCTL_BIT,
	CRIGHT_IRQCTRL_MAX
};

#define CRIGHT_IRQCTRL_OWNER		(1U << CRIGHT_IRQCTRL_OWNER_BIT)
#define CRIGHT_IRQCTRL_SGI		(1U << CRIGHT_IRQCTRL_SGI_BIT)
#define CRIGHT_IRQCTRL_IOCTL		(1U << CRIGHT_IRQCTRL_IOCTL_BIT)

#define IRQCTRL_REGISTER_STAYWAKE	0x1U

#define IRQCTRL_SET_WAKE		0x1U

#define IRQCTRL_NAME_LEN		32u

#define IRQ_SET_ATTRIBUTE_CPU		0x1U
#define IRQ_SET_ATTRIBUTE_GRP		0x2U
#define IRQ_SET_ATTRIBUTE_SEC		0x4U
#define IRQ_SET_ATTRIBUTE_TRI_TYPE	0x8U

struct sysarg_irqctrl_register {
	char name[IRQCTRL_NAME_LEN];
	__u32 flags;
};

struct sysarg_irqctrl_stat {
	char name[IRQCTRL_NAME_LEN];

	/* hw state: -1: invalid */
	__s8 hw_pending;
	__s8 hw_enable;
	__s8 hw_active;
	/* logic irq is_register 0: not register 1: register */
	__u8 is_regist;

	__u32 state;
	__u32 hw_irq;
	__u32 affinity;
	__u32 trigger_type;

	__u64 active_cnt;
	__u64 history_cnt;
};

struct sysarg_irqctrl_attribute {
	__u32 attr_cpu;
	__u32 attr_grp;
	__u32 attr_sec;
	__u32 attr_tri_type;
};

#endif
#endif
