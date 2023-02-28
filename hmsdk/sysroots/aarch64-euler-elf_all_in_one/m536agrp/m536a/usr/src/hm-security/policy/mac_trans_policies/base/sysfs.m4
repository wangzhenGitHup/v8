DEF_FILE_OBJECT(sysfs, ``/sys'')
TYPE_ADD_ATTRIBUTES((sysfs), (basic_dir, mount_point))

DEF_TYPES(sys_dev)
DEF_TYPES(sys_pwr)
DEF_TYPES(sys_pwr_wakelock)
DEF_TYPES(sys_class)
DEF_TYPES(sys_class_gpio)
DEF_TYPES(sys_uio0)
DEF_TYPES(sys_platform)
DEF_TYPES(sys_platform_root)
DEF_TYPES(sys_platform_root_gpio)
DEF_FILE_OBJECT(sys_dev, ``sysfs:/devices'')
DEF_FILE_OBJECT(sys_pwr, ``sysfs:/power'')
DEF_FILE_OBJECT(sys_class, ``sysfs:/class'')
DEF_FILE_OBJECT(sys_class_gpio, ``sysfs:/class/gpio'')
DEF_FILE_OBJECT(sys_class_gpio, ``sysfs:/class/gpio/*'')
DEF_FILE_OBJECT(sys_pwr_wakelock, ``sysfs:/power/wake_lock'')
DEF_FILE_OBJECT(sys_pwr_wakelock, ``sysfs:/power/wake_unlock'')
DEF_FILE_OBJECT(sys_pwr_wakelock, ``sysfs:/power/wakeup_count'')
COMMENT /sys/devices/uio0
DEF_FILE_OBJECT(sys_uio0, ``sysfs:/devices/uio0'')
DEF_FILE_OBJECT(sys_uio0, ``sysfs:/devices/uio0/*'')
DEF_FILE_OBJECT(sys_platform, ``sysfs:/devices/platform'')
DEF_FILE_OBJECT(sys_platform_root, ``sysfs:/devices/platform/root:of'')
DEF_FILE_OBJECT(sys_platform_root_gpio, ``sysfs:/devices/platform/root:of/*gpio'')
DEF_FILE_OBJECT(sys_platform_root_gpio, ``sysfs:/devices/platform/root:of/*gpio/*'')

COMMENT for sysfs nodes
DEF_ATTRIBUTES(sysfs_nodes)

COMMENT add all sysfs nodes in sysfs_nodes attribute
TYPE_ADD_ATTRIBUTES((sys_dev, sys_pwr, sys_pwr_wakelock, sys_class, sys_class_gpio, sys_uio0, sys_platform,
sys_platform_root, sys_platform_root_gpio), (sysfs_nodes))
