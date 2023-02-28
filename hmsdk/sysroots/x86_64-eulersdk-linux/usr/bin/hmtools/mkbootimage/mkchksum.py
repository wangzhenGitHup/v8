#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
Description: Script for mkchksum
Author: Huawei OS Kernel Lab
Create: Mon Jun 21 09:58:26 2021
"""

import os
import re
import shutil
import argparse

from hmtools.fsops import HMToolsBinFile
from hmtools.fsops import HMToolsFSControl
from hmtools.fsops import HMToolsDir
from hmtools.exceptions import HMToolsArgException
from hmtools.exceptions import HMToolsBaseException
from hmtools.exceptions import HMToolsFileNotFoundException
from hmtools import utils
from hmtools import hmlogging
from hmtools.execute import execute_safe
from hmtools.execute import execute_chain_safe


class ChecksumMaker(object):
    """ Checksum maker """
    def __init__(self, args):
        self._cmdline_args  = args
        self._fscontrol     = HMToolsFSControl(vars(self._cmdline_args))

        if args.sysroot is None:
            raise HMToolsArgException('--sysroot is required')

        self._output        = HMToolsBinFile(args.output)
        self._sysroots = (HMToolsDir(x) for x in args.sysroot)
        self._sysroot_native = args.sysroot_native
        self._tmpdir = args.tmpdir
        self._tools = utils.find_native_tool_path(self._sysroot_native, "usr/bin/hm-decompressor")
        self._rootfscpio = args.rootfscpio

    def _create_checksum(self):
        hmlogging.debug('create checksum for files in rootfs')

        output_abspath = self._output.path_of(abspath=True)
        rootfs_dir = '%s%s' % (self._tmpdir, '/rootfs')
        rootfs_unzip_dir = '%s%s' % (self._tmpdir, '/rootfs_unzip')

        if os.path.exists(rootfs_dir):
            shutil.rmtree(rootfs_dir)
        if os.path.exists(rootfs_unzip_dir):
            shutil.rmtree(rootfs_unzip_dir)

        _rootfs_dir = HMToolsDir(rootfs_dir, need_create=True)
        _rootfs_unzip_dir = HMToolsDir(rootfs_unzip_dir, need_create=True)

        with _rootfs_unzip_dir.chdir():
            _rootfs_subdir = HMToolsDir('rootfs', need_create=True)
            with _rootfs_subdir.chdir():
                execute_chain_safe([['cat', f'{self._rootfscpio}'], ['cpio', '-idmv']])

        rootfs_unzip_subdir = '%s%s' % (rootfs_unzip_dir, '/rootfs')
        for path, dir_list, file_list in os.walk(rootfs_unzip_subdir):
            for file_name in file_list:
                os.remove(os.path.join(path, file_name))

        with _rootfs_dir.chdir():
            execute_chain_safe([['cat', f'{self._rootfscpio}'], ['cpio', '-idmv']])
        os.chdir(self._tmpdir)
        for path, dir_list, file_list in os.walk(r"rootfs"):
            for file_name in file_list:
                unzip_file_path = os.path.join(path, file_name)
                if os.path.exists(unzip_file_path):
                    cmds = [f'{self._tools}', '-o', f'{rootfs_unzip_dir}/{unzip_file_path}',
                            '-i', f'{self._tmpdir}/{unzip_file_path}']
                    execute_safe(cmds)

        _rootfs_unzip_subdir = HMToolsDir(rootfs_unzip_subdir)
        with _rootfs_unzip_subdir.chdir():
            cmds = [['find', '.', '-type', 'f', '-o', '-type', 'l'],
                    ['xargs', 'sha256sum']
                   ]
            _f = HMToolsBinFile(output_abspath)
            with _f.open('wb') as f:
                f.write(execute_chain_safe(cmds))
            hmlogging.debug('write mkcksumfile done')
        shutil.rmtree(rootfs_unzip_dir)
        shutil.rmtree(rootfs_dir)

        # replace symbols in checksum file line by line
        with open(os.open(output_abspath, os.O_RDWR, 0o644), 'w+') as f:
            contents = f.read()
            new_contents = re.sub(r' ./', '/', contents)
            f.seek(0)
            f.truncate()
            f.write(new_contents)

    def _run(self):
        self._create_checksum()

    def execute(self):
        """ Execute """
        self._run()


def parse_args():
    """ Parse arguments """
    parser = argparse.ArgumentParser(description='Make checksum for rootfs files')
    # common args
    parser.add_argument('--output', default='checksum.txt',
                        dest='output', help='Output name, default: checksum.txt')
    parser.add_argument('--sysroot', action='append',
                        dest='sysroot', help='SDK sysroot path')
    parser.add_argument('--sysroot-native', default=None,
                        dest='sysroot_native', help='Path to native sysroot')
    parser.add_argument('--tmpdir', default=None,
                        dest='tmpdir', help='Tmp dir for unzip rootfs.cpio')
    parser.add_argument('--timestamp',
                        dest='timestamp', help='timestamp for rootfs files')
    parser.add_argument('--verbose', '-v', action='count', default=0,
                        dest='verbose', help='Verbose level')
    parser.add_argument('--rootfscpio', '-r',
                        dest='rootfscpio', help='rootfs.cpio path')
    return parser.parse_args()


def main():
    """ Main function """
    args = parse_args()

    hmlogging.set_basic_config(vars(args))

    try:
        job = ChecksumMaker(args)
        # rootfs dir permission need be 755
        os.umask(0o022)
        job.execute()
    except HMToolsArgException as e:
        hmlogging.error(f"Invalid argument: {e}")
        raise
    except HMToolsFileNotFoundException as e:
        hmlogging.error(f"File not found: {e}")
        raise
    except HMToolsBaseException:
        hmlogging.exception("Unexpected exception")
        raise
    finally:
        pass

if __name__ == '__main__':
    main()
