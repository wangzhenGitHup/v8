#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
Description: Script for mkrootfs
Author: Huawei OS Kernel Lab
Create: Thu Jan 14 09:58:26 2021
"""
import os
import argparse

from hmtools.fsops import HMToolsBinFile
from hmtools.fsops import HMToolsFSControl
from hmtools.fsops import HMToolsDir
from hmtools.exceptions import HMToolsArgException
from hmtools.exceptions import HMToolsBaseException
from hmtools.exceptions import HMToolsFileNotFoundException
from hmtools import hmlogging
from hmtools.execute import execute_chain_safe
from hmtools.manifest import Conf
from hmtools.manifest import ManifestParseException
from hmtools.manifest import ManifestOptionException
from hmtools.manifest import parse_manifest_files


class RootfsMaker(object):
    """
    Rootfs maker
    """
    def __init__(self, args):
        self._cmdline_args  = args
        self._fscontrol     = HMToolsFSControl(vars(self._cmdline_args))

        if args.sysroot is None:
            raise HMToolsArgException('--sysroot is required')

        self._manifest      = parse_manifest_files(args.manifest) if args.manifest else \
                              [l.strip() for l in default_manifest.split('\n')]
        self._output        = HMToolsBinFile(args.output)
        self._sysroots      = [HMToolsDir(x) for x in args.sysroot]
        self._is_force      = args.force

        self._tmpdir        = HMToolsDir(None, tmpdir=True)

        # mkdtemp always create directory with mode 0600, no matter
        # what the umask is, thus we need work in a subdirectory in
        # the tmp dir
        self._workdir       = self._tmpdir.join_dir('rootfs',
                                                    need_create=True,
                                                    fscontrol=self._fscontrol)

        self._sysroot_native = args.sysroot_native

    def _create_cpio(self):

        hmlogging.debug('write finish recursive')
        self._workdir.write_finish_recursive()

        output_abspath = self._output.path_of(abspath=True)
        with self._workdir.chdir():
            cmds = [
                    ['find', '.'],
                    ['sort'],
                    ['cpio', '--reproducible', '--quiet', '-o', '-H', 'newc', '-R', '0:0'],
                    ]
            _f = HMToolsBinFile(output_abspath)
            with _f.open('wb') as f:
                f.write(execute_chain_safe(cmds))
        self._output.write_finish()

    def _run(self):
        self._manifest.run(Conf(self._workdir,
                                self._sysroots,
                                sysroot_native=self._sysroot_native,
                                fscontrol=self._fscontrol,
                                is_force=self._is_force,
                                tools={"compressor" : "usr/bin/hm-compressor"}))
        self._workdir.write_finish()
        self._create_cpio()

    def execute(self):
        """
        Execute rootfs maker
        """
        self._run()


def parse_args():
    """
    parse arguments
    """
    parser = argparse.ArgumentParser(description='Make rootfs for hongmeng bootimage')
    # common args
    parser.add_argument('--output', default='rootfs.cpio',
                        dest='output', help='Output name, default: rootfs.cpio')
    parser.add_argument('--sysroot', action='append',
                        dest='sysroot', help='SDK sysroot path')
    parser.add_argument('--manifest', action='append',
                        dest='manifest', help='rootfs manifest file')
    parser.add_argument('--force', action='store_true',
                        dest='force', help='ignore files not found')
    parser.add_argument('--sysroot-native', default=None,
                        dest='sysroot_native', help='Path to native sysroot')
    parser.add_argument('--timestamp',
                        dest='timestamp', help='timestamp for rootfs files')
    parser.add_argument('--verbose', '-v', action='count', default=0,
                        dest='verbose', help='Verbose level')
    return parser.parse_args()


def main():
    """
    main function
    """
    args = parse_args()

    hmlogging.set_basic_config(vars(args))

    try:
        job = RootfsMaker(args)
        # rootfs dir permission need be 755
        os.umask(0o022)
        job.execute()
    except HMToolsArgException as e:
        hmlogging.error(f"Invalid argument: {e}")
        raise
    except HMToolsFileNotFoundException as e:
        hmlogging.error(f"File not found: {e}")
        raise
    except ManifestParseException as e:
        hmlogging.error(f"Invalid manifest cmd: {e}")
        raise
    except ManifestOptionException as e:
        hmlogging.error(f"Invalid manifest option: {e}")
        raise
    except HMToolsBaseException:
        hmlogging.exception("Unexpected exception")
        raise
    finally:
        # no need to manually cleanup
        pass


default_manifest = '''
# be carefule to use tab as seperator, not spaces!
# copy			src			dst			option
copy		usr/bin/crypto.elf		bin			comp
copy		bin/devhost.elf			bin			comp
copy		bin/devmgr.elf			bin			comp
copy		usr/bin/ethtool.elf		bin			comp
copy		usr/bin/ftpd.elf		bin			comp
copy		bin/hguard.elf			bin			comp
copy		usr/bin/hmnetd-test.elf		bin			comp
copy		usr/bin/hmnetd.elf		bin			comp
copy		usr/bin/ipcfg.elf		bin			comp
copy		usr/bin/qperf.elf		bin			comp
copy		usr/bin/tcpdump.elf		bin			comp
copy		bin/tppmgr.elf			bin			comp
copy		lib/hmld.so.elf			lib			comp
copy		usr/lib/libc++.so		lib			comp
copy		usr/lib/libc++.so.1		lib			comp
copy		usr/lib/libc++.so.1.0		lib			comp
copy		usr/lib/libc++abi.so		lib			comp
copy		usr/lib/libc++abi.so.1		lib			comp
copy		usr/lib/libc++abi.so.1.0	lib			comp
copy		usr/lib/libc-sys.so		lib			comp
copy		usr/lib/libc.so			lib			comp
copy		lib/libdh-linux.so.4.4		lib			comp
copy		lib/libdh-linux.so.4.4.162	lib			comp
copy		lib/libdh-udk.so.0		lib			comp
copy		lib/libdh-udk.so.0.1		lib			comp
copy		usr/lib/libhmc.so		lib			comp
copy		usr/lib/libhmcrypt.so		lib			comp
copy		usr/lib/libhmcrypt.so.0		lib			comp
copy		usr/lib/libhmcrypt.so.0.1	lib			comp
copy		usr/lib/libhmsrv_fs.so		lib			comp
copy		usr/lib/libhmsrv_fs.so.0	lib			comp
copy		usr/lib/libhmsrv_fs.so.0.1	lib			comp
copy		usr/lib/libhmsrv_kernfs.so	lib			comp
copy		usr/lib/libhmsrv_kernfs.so.0	lib			comp
copy		usr/lib/libhmsrv_kernfs.so.0.1	lib			comp
copy		usr/lib/libhmsrv_net.so		lib			comp
copy		usr/lib/libhmsrv_net.so.0	lib			comp
copy		usr/lib/libhmsrv_sec.so		lib			comp
copy		usr/lib/libhmsrv_sec.so.0	lib			comp
copy		usr/lib/libhmsrv_sec.so.0.1	lib			comp
copy		usr/lib/libhwsecurec.so		lib			comp
copy		usr/lib/libhwsecurec.so.1	lib			comp
copy		usr/lib/libhwsecurec.so.1.0	lib			comp
copy		usr/lib/libkasan.so		lib			comp
copy		usr/lib/libkasan.so.0		lib			comp
copy		usr/lib/libkasan.so.0.1		lib			comp
copy		usr/lib/libmemleak.so		lib			comp
copy		usr/lib/libmemleak.so.0		lib			comp
copy		usr/lib/libmemleak.so.0.1	lib			comp
copy		usr/lib/libtomcrypt.so		lib			comp
copy		usr/lib/libtomcrypt.so.1	lib			comp
copy		usr/lib/libtomcrypt.so.1.1	lib			comp
copy		lib/modules/cfi_cmdset_0001.ko	lib/modules		comp
copy		lib/modules/cfi_probe.ko	lib/modules		comp
copy		lib/modules/cfi_util.ko		lib/modules		comp
copy		lib/modules/chipreg.ko		lib/modules		comp
copy		lib/modules/devhost.ko		lib/modules		comp
copy		lib/modules/sysfs_epoll_test.ko	lib/modules		comp
copy		lib/modules/epoll_test.ko	lib/modules		comp
copy		lib/modules/gen_probe.ko	lib/modules		comp
copy		lib/modules/genuio.ko		lib/modules		comp
copy		lib/modules/ioctl_test.ko	lib/modules		comp
copy		lib/modules/kconsole.ko		lib/modules		comp
copy		lib/modules/kthread.ko		lib/modules		comp
copy		lib/modules/mtd.ko		lib/modules		comp
copy		lib/modules/mtd_blkdevs.ko	lib/modules		comp
copy		lib/modules/mtdblock.ko		lib/modules		comp
copy		lib/modules/of.ko		lib/modules		comp
copy		lib/modules/of.proxy.ko		lib/modules		comp
copy		lib/modules/of_udk.udk		lib/modules		comp
copy		lib/modules/pclk_test.ko	lib/modules		comp
copy		lib/modules/physmap.ko		lib/modules		comp
copy		lib/modules/physmap_of.ko	lib/modules		comp
copy		lib/modules/pramdisk.ko		lib/modules		comp
copy		lib/modules/serial_pl011.ko	lib/modules		comp
copy		lib/modules/stream.ko		lib/modules		comp
copy		lib/modules/tty.ko		lib/modules		comp
copy		lib/modules/udk_kconsole.udk	lib/modules		comp
copy		lib/modules/udk_serial_8250.udk	lib/modules		comp
copy		lib/modules/udk_stream.udk	lib/modules		comp
copy		lib/modules/udk_tty.udk		lib/modules		comp
copy		lib/modules/udkblk-test.udk	lib/modules		comp
copy		lib/modules/udktest.udk		lib/modules		comp
copy		lib/modules/udktest_net.udk	lib/modules		comp
copy		lib/modules/udktest_unload.udk	lib/modules		comp
copy		lib/modules/udkuio.udk		lib/modules		comp
copy		lib/modules/uio.ko		lib/modules		comp
copy		lib/modules/uio_pdrv_genirq.ko	lib/modules		comp
copy		lib/modules/virtio.ko		lib/modules		comp
copy		lib/modules/virtio_blk.ko	lib/modules		comp
copy		lib/modules/virtio_mmio.ko	lib/modules		comp
copy		lib/modules/virtio_net.ko	lib/modules		comp
copy		lib/modules/virtio_ring.ko	lib/modules		comp
copy		lib/modules/workqueue_test.ko	lib/modules		comp
copy		usr/bin/dmctl.elf		usr/bin			comp
copy		usr/bin/dumpe2fs		usr/bin			comp
copy		usr/bin/e2fsck			usr/bin			comp
copy		usr/bin/fs-test.elf		usr/bin			comp
copy		usr/bin/fsckfat.elf		usr/bin			comp
copy		usr/bin/helloworld.elf		usr/bin			comp
copy		usr/bin/hm-test-dynamic.elf	usr/bin			comp
copy		usr/bin/hm-test-kasan.elf	usr/bin			comp
copy		usr/bin/hm-test.elf		usr/bin			comp
copy		usr/bin/hm-testmaxpath.elf	usr/bin			comp
copy		usr/bin/hm-spawn-test.elf	usr/bin			comp
copy		usr/bin/hmesg.elf		usr/bin			comp
copy		usr/bin/hmnet_st.elf		usr/bin			comp
copy		usr/bin/iperf.elf		usr/bin			comp
copy		usr/bin/libc-dyn-test.elf	usr/bin			comp
copy		usr/bin/libc-dyn-memleak.elf	usr/bin			comp
copy		usr/bin/libc-test.elf		usr/bin			comp
copy		usr/bin/libc-memleak.elf	usr/bin			comp
copy		usr/bin/mke2fs			usr/bin			comp
copy		usr/bin/mkfat.elf		usr/bin			comp
copy		usr/bin/perf.elf		usr/bin			comp
copy		usr/bin/perf_test.elf		usr/bin			comp
copy		usr/bin/performance		usr/bin			comp
copy		usr/bin/probe_dev.elf		usr/bin			comp
copy		usr/bin/uiomem.elf		usr/bin			comp
copy		usr/bin/sec-test-noperm.elf	usr/bin			comp
copy		usr/bin/sec-test-transition.elf	usr/bin			comp
copy		usr/bin/sec-test.elf		usr/bin			comp
copy		usr/bin/sectool.elf		usr/bin			comp
copy		usr/bin/shell_test		usr/bin			comp
copy		usr/bin/shutdownhm.elf		usr/bin			comp
copy		usr/bin/sysdump.elf		usr/bin			comp
copy		usr/bin/test-helper.elf		usr/bin			comp
copy		usr/bin/tty_control.elf		usr/bin			comp
copy		usr/bin/udhcpc.script		usr/bin			comp
copy		usr/bin/udk-test-base.elf	usr/bin			comp
copy		usr/bin/udk-test-blk.elf	usr/bin			comp
copy		usr/bin/udk-test-net.elf	usr/bin			comp
copy		usr/bin/udk-test-unload.elf	usr/bin			comp
copy		usr/lib/libclang_rt.builtins_s.so	usr/lib		comp
copy		usr/lib/liblinked.so		usr/lib			comp
copy		usr/lib/liblinked.so.0		usr/lib			comp
copy		usr/lib/liblinked.so.0.1	usr/lib			comp
copy		usr/lib/libpreload.so		usr/lib			comp
copy		usr/lib/libpreload.so.0		usr/lib			comp
copy		usr/lib/libpreload.so.0.1	usr/lib			comp
copy		usr/lib/libtest.so		usr/lib			comp
copy		usr/lib/libtest.so.0		usr/lib			comp
copy		usr/lib/libtest.so.0.1		usr/lib			comp
copy		usr/lib/libunwind_s.so		usr/lib			comp
copy		usr/lib/libunwind_s.so.1	usr/lib			comp
copy		usr/lib/libunwind_s.so.1.0	usr/lib			comp
copy		etc/fstab			etc			nocomp
copy		etc/hguard.d/crypto.service	etc/hguard.d		nocomp
copy		etc/hguard.d/devhost.service	etc/hguard.d		nocomp
copy		etc/hguard.d/devmgr.service	etc/hguard.d		nocomp
copy		etc/hguard.d/hmnetd.service	etc/hguard.d		nocomp
copy		etc/hguard.d/tppmgr.service	etc/hguard.d		nocomp
copy		etc/hguard.d/vfs-tmp.service	etc/hguard.d		nocomp
copy		etc/hm.local			etc			nocomp
copy		etc/hosts			etc			nocomp
copy		etc/inittab			etc			nocomp
copy		etc/mount.sh			etc			nocomp
copy		etc/profile			etc			nocomp
copy		etc/rc.local			etc			nocomp
copy		etc/rc.shutdown			etc			nocomp
copy		etc/resolv.conf			etc			nocomp
copy		etc/services			etc			nocomp
copy		usr/share/locale		usr/share		comp
copy		usr/lib/libdh.so.0.1		lib			comp
copy		usr/lib/libdh.so.0		lib			comp
copy		usr/lib/libdh.so		lib			comp
copy		usr/lib/libhmulibs.so.0.1	lib			comp
copy		usr/lib/libhmulibs.so.0		lib			comp
copy		usr/lib/libhmulibs.so		lib			comp
copy		usr/bin/gdb.elf			usr/bin			comp
copy		usr/bin/gdb			usr/bin			comp
copy		usr/bin/fsstress		usr/bin			comp
copy		usr/bin/iptables		usr/bin			comp
copy		usr/bin/hmtrace-test-server.elf	usr/bin			comp
# shell test
copy		usr/bin/shell_test/fs_cat_in_deep_dir.sh	usr/bin/shell_test	comp
copy		usr/bin/shell_test/fs_fsstress.sh		usr/bin/shell_test	comp
copy		usr/bin/shell_test/fs_mem_check1.sh		usr/bin/shell_test	comp
copy		usr/bin/shell_test/fs_mem_check2.sh		usr/bin/shell_test	comp
copy		usr/bin/shell_test/fs_racer.sh			usr/bin/shell_test	comp
copy		usr/bin/shell_test/fs_racer_lib.sh		usr/bin/shell_test	comp
copy		usr/bin/shell_test/test_echo.sh			usr/bin/shell_test	comp
copy		usr/bin/shell_test/test_perf_common.sh		usr/bin/shell_test	comp
copy		usr/bin/shell_test/test_perf_record.sh		usr/bin/shell_test	comp
copy		usr/bin/shell_test/test_perf_stat.sh		usr/bin/shell_test	comp
copy		usr/bin/shell_test/uev_trace_cmdtest.sh		usr/bin/shell_test	comp
# locale
copy		usr/share/locale/zh_CN/LC_MESSAGES/iso_15924.mo		usr/share/locale/zh_CN/LC_MESSAGES	comp
copy		usr/share/locale/zh_CN/LC_MESSAGES/iso_3166_1.mo	usr/share/locale/zh_CN/LC_MESSAGES	comp
copy		usr/share/locale/zh_CN/LC_MESSAGES/iso_4217.mo		usr/share/locale/zh_CN/LC_MESSAGES	comp
copy		usr/share/locale/zh_CN/LC_MESSAGES/iso_639_1.mo		usr/share/locale/zh_CN/LC_MESSAGES	comp
# busybox links
copy		usr/bin/busyboxhm.elf		bin			comp
copy		bin/uncompress			bin			raw
copy		bin/gunzip			bin			raw
copy		bin/bzip2			bin			raw
copy		bin/gzip			bin			raw
copy		bin/tar				bin			raw
copy		bin/unzip			bin			raw
copy		bin/clear			bin			raw
copy		bin/basename			bin			raw
copy		bin/cat				bin			raw
copy		bin/chmod			bin			raw
copy		bin/cp				bin			raw
copy		bin/cut				bin			raw
copy		bin/date			bin			raw
copy		bin/dd				bin			raw
copy		bin/df				bin			raw
copy		bin/dirname			bin			raw
copy		bin/du				bin			raw
copy		bin/echo			bin			raw
copy		bin/env				bin			raw
copy		bin/expand			bin			raw
copy		bin/unexpand			bin			raw
copy		bin/expr			bin			raw
copy		bin/false			bin			raw
copy		bin/head			bin			raw
copy		bin/link			bin			raw
copy		bin/ln				bin			raw
copy		bin/ls				bin			raw
copy		bin/md5sum			bin			raw
copy		bin/mkdir			bin			raw
copy		bin/mkfifo			bin			raw
copy		bin/mknod			bin			raw
copy		bin/mv				bin			raw
copy		bin/nice			bin			raw
copy		bin/nohup			bin			raw
copy		bin/printenv			bin			raw
copy		bin/printf			bin			raw
copy		bin/pwd				bin			raw
copy		bin/readlink			bin			raw
copy		bin/realpath			bin			raw
copy		bin/rm				bin			raw
copy		bin/rmdir			bin			raw
copy		bin/seq				bin			raw
copy		bin/sleep			bin			raw
copy		bin/sort			bin			raw
copy		bin/stat			bin			raw
copy		bin/sum				bin			raw
copy		bin/sync			bin			raw
copy		bin/fsync			bin			raw
copy		bin/tac				bin			raw
copy		bin/tail			bin			raw
copy		bin/tee				bin			raw
copy		bin/test			bin			raw
copy		bin/[				bin			raw
copy		bin/[[				bin			raw
copy		bin/touch			bin			raw
copy		bin/tr				bin			raw
copy		bin/true			bin			raw
copy		bin/truncate			bin			raw
copy		bin/uname			bin			raw
copy		bin/uniq			bin			raw
copy		bin/unlink			bin			raw
copy		bin/wc				bin			raw
copy		bin/which			bin			raw
copy		bin/awk				bin			raw
copy		bin/cmp				bin			raw
copy		bin/diff			bin			raw
copy		bin/sed				bin			raw
copy		bin/vi				bin			raw
copy		bin/find			bin			raw
copy		bin/grep			bin			raw
copy		bin/egrep			bin			raw
copy		bin/fgrep			bin			raw
copy		bin/xargs			bin			raw
copy		bin/less			bin			raw
copy		bin/time			bin			raw
copy		bin/ftpget			bin			raw
copy		bin/ftpput			bin			raw
copy		bin/netstat			bin			raw
copy		bin/ping			bin			raw
copy		bin/free			bin			raw
copy		bin/kill			bin			raw
copy		bin/killall			bin			raw
copy		bin/lsof			bin			raw
copy		bin/pgrep			bin			raw
copy		bin/pkill			bin			raw
copy		bin/pidof			bin			raw
copy		bin/ps				bin			raw
copy		bin/pstree			bin			raw
copy		bin/watch			bin			raw
copy		bin/ash				bin			raw
copy		bin/sh				bin			raw
copy		bin/bash			bin			raw
copy		bin/dmesg			bin			raw
copy		bin/hexdump			bin			raw
copy		bin/more			bin			raw
copy		bin/mount			bin			raw
copy		bin/taskset			bin			raw
copy		bin/umount			bin			raw
copy		bin/helloworld			bin			raw
copy		bin/pmuctrl			bin			raw
copy		bin/top				bin			raw
copy		sbin/chroot			sbin			raw
copy		sbin/fsck			sbin			raw
copy		sbin/halt			sbin			raw
copy		sbin/poweroff			sbin			raw
copy		sbin/reboot			sbin			raw
copy		sbin/devmem			sbin			raw
copy		sbin/ifconfig			sbin			raw
copy		sbin/ifenslave			sbin			raw
copy		sbin/ifup			sbin			raw
copy		sbin/ifdown			sbin			raw
copy		sbin/ip				sbin			raw
copy		sbin/ipaddr			sbin			raw
copy		sbin/iplink			sbin			raw
copy		sbin/iproute			sbin			raw
copy		sbin/ipneigh			sbin			raw
copy		sbin/route			sbin			raw
copy		sbin/telnetd			sbin			raw
copy		sbin/vconfig			sbin			raw
copy		sbin/fdisk			sbin			raw
copy		sbin/hwclock			sbin			raw
copy		sbin/nologin			sbin			raw
copy		sbin/udhcpc			sbin			raw
# empty directories in rootfs
mkdir	dev
mkdir	home
mkdir	proc
mkdir	sys
mkdir	tmp
mkdir	var
mkdir	usr/bin/performance
mkdir	usr/sbin
# for aarch64 qemu fs-test
copy		usr/bin/binderfs-test.elf	usr/bin			comp
# test modules
mkdir	lib/modules/mod-tests
copy	lib/modules/hello.ko		lib/modules/mod-tests	comp
# big endian
copy		lib/libgcc_s.so			lib			nocomp
copy		lib/libgcc_s.so.1		lib			comp
'''

if __name__ == '__main__':
    main()
