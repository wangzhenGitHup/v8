/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Prototypes for devhost power mgmt APIs
 * Author: Huawei OS Kernel Lab
 * Create: Fri Jan 11 10:45:12 2019
 */
#ifndef __DEVHOST_API_PM_H__
#define __DEVHOST_API_PM_H__

/*
 * CAUSION: This file will be used in linux source,
 *          **DO NOT** include any HMOS headers.
 */

struct devhost_plat_pm_ops {
	int (*prepare)(unsigned int type, char *cmd);
	int (*power_off)(void);
	int (*reboot)(const char *cmd);
	void (*syscore_shutdown)(void);
	int (*suspend)(void);
	void (*resume)(void);
	int (*suspend_late)(void);
	void (*resume_early)(void);
	int (*cpu_add)(unsigned int cpu);
	int (*cpu_remove)(unsigned int cpu);
};

#ifdef CONFIG_DEVHOST_PM_PLUGIN
int devhost_register_plat_pm(const struct devhost_plat_pm_ops *plat_pm_ops);
int devhost_pm_init(const struct devhost_plat_pm_ops *plat_pm_ops);
#endif

/* for shutdown hm */
int devhost_shutdown(void);

#if defined(CONFIG_DEVHOST_PM_PLUGIN) && defined(CONFIG_PM_WAKELOCK)
int devhost_wakelock_acquire(void);
int devhost_wakelock_release(void);
#else
static inline int devhost_wakelock_acquire(void)
{
	return 0;
}
static inline int devhost_wakelock_release(void)
{
	return 0;
}
#endif

#endif /* __DEVHOST_API_PM_H__ */
