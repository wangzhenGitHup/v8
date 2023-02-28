#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
Description: Manifest for hmtools
Author: Huawei OS Kernel Lab
Create: Thu May 13 09:59:30 2021
"""

import os
import shlex
from hmtools import hmlogging
from hmtools.fsops import HMToolsTextFile
from hmtools.execute import execute_safe
from hmtools.exceptions import HMToolsBaseException
from hmtools.exceptions import HMToolsFileNotFoundException
from . import utils


class Conf(object):
    """
    conf class
    """
    class CmdConf(object):
        """
        cmd conf class
        """
        def __init__(self, sysroot_native, tools):
            self.sysroot_native = sysroot_native
            self._tools = {}
            for k in tools:
                v = tools[k]
                self._tools[k] = utils.find_native_tool_path(sysroot_native, v)

        def __getitem__(self, cmd_name):
            return self._tools.get(cmd_name)

    def __init__(self, dstroot_dir, sysroot_dirs, sysroot_native=None,
                 fscontrol=None, is_force=False,
                 tools=None):
        self.dstroot_dir    = dstroot_dir
        self.sysroot_dirs   = sysroot_dirs
        self.fscontrol      = fscontrol
        self.is_force       = is_force
        if tools is None:
            tools = {
                    "compressor" : "hm-compressor",
                    "genprop"    : "proptytool.py"
                    }
        self.cmd            = Conf.CmdConf(sysroot_native, tools)

    def find_file(self, filename):
        """
        find file function
        """
        for sysroot_dir in self.sysroot_dirs:
            f = sysroot_dir.join_binfile(filename)
            if f.is_file_exist():
                return f
        if self.is_force:
            hmlogging.warning(f'cannot find {filename}')
            return None
        else:
            raise HMToolsFileNotFoundException(f"{filename}")


class ManifestParseException(HMToolsBaseException):
    """
    manifest parse exception class
    """


class ManifestOptionException(HMToolsBaseException):
    """
    manifest option exception class
    """


class Manifest(object):
    """
    manifest class
    """

    class ManifestCmd(object):
        """
        manifest cmd class
        """
        def __init__(self, cmd_parts):
            self._cmd_parts = cmd_parts
            hmlogging.debug(f"read cmd: {self}")

        def run(self, conf):
            """
            manifest run function
            """
            hmlogging.warning(f'Skip running cmd: {self}')

    class CmdCopy(ManifestCmd):
        """
        copy cmd class
        """
        def __init__(self, cmd_parts):
            self._src_filename  = cmd_parts[0]
            self._dst_dir       = cmd_parts[1]
            self._options       = cmd_parts[2:] if len(cmd_parts) >= 3 else []

            super().__init__(cmd_parts)

        def __str__(self):
            return f"copy {self._src_filename} to {self._dst_dir}"

        @classmethod
        def _direct_cp(cls, src_file, dst_dir, conf, follow_symlinks=True):
            src_file.copy_to(dst_dir, follow_symlinks=follow_symlinks, fscontrol=conf.fscontrol)

        def _compress_cp(self, src_file, dst_dir, option, conf):

            cmd_option = {
                "comp"      : "-p 6",
                "nocomp"    : "-n",
                "comp2decomp": "-U -p 6",
            }.get(option)

            dst_file = dst_dir.join_binfile(src_file.basename_of(),
                                            fscontrol=conf.fscontrol)
            cmd = [f'{conf.cmd["compressor"]}', *shlex.split(cmd_option),
                    '-i', f'{src_file}', '-o', f'{dst_file}']
            execute_safe(cmd)
            if not dst_file.is_file_exist():
                hmlogging.info(f'file {src_file} is already compressed, direct copy')
                self._direct_cp(src_file, dst_dir, conf)
            else:
                dst_file.write_finish()
                dst_dir.write_finish()

        def _symlink_file_cp(self, src_file, dst_dir, conf):
            if 'raw' not in self._options:
                hmlogging.warning(f"ignore option {self._options} for symlink {src_file}")
            self._direct_cp(src_file, dst_dir, conf, follow_symlinks=False)

        def _normal_file_cp(self, src_file, dst_dir, conf):
            if 'comp' in self._options:
                self._compress_cp(src_file, dst_dir, "comp", conf)
            elif 'nocomp' in self._options:
                self._compress_cp(src_file, dst_dir, "nocomp", conf)
            elif 'comp2decomp' in self._options:
                self._compress_cp(src_file, dst_dir, "comp2decomp", conf)
            else:
                self._direct_cp(src_file, dst_dir, conf)

        def _run_one_sysroot(self, conf, sysroot_dir):
            src_file    = sysroot_dir.join_binfile(self._src_filename)
            if not src_file.is_file_exist():
                return False

            dst_dir     = conf.dstroot_dir.join_dir(self._dst_dir,
                                                    need_create=True,
                                                    fscontrol=conf.fscontrol)
            if src_file.is_symlink():
                self._symlink_file_cp(src_file, dst_dir, conf)
            else:
                self._normal_file_cp(src_file, dst_dir, conf)
            return True

        def run(self, conf):
            for sysroot_dir in conf.sysroot_dirs:
                if self._run_one_sysroot(conf, sysroot_dir):
                    return

            if conf.is_force:
                hmlogging.warning(f'skip copying inexist {self._src_filename}')
            else:
                raise HMToolsFileNotFoundException(f"{self._src_filename}")

    class CmdMkdir(ManifestCmd):
        """
        make dir class
        """
        def __init__(self, cmd_parts):
            self._dir   = cmd_parts[0]
            if len(cmd_parts) > 1:
                self._mode = cmd_parts[1]
            else:
                self._mode = "755"

            super().__init__(cmd_parts)

        def __str__(self):
            return f"mkdir {self._dir} {self._mode}"

        def run(self, conf):
            hmlogging.info(f'mkdir {self._dir} {self._mode}')
            oldmask = os.umask(000)
            dst_dir = conf.dstroot_dir.join_dir(self._dir,
                                                need_create=True,
                                                fscontrol=conf.fscontrol,
                                                mode=int(f"0o{self._mode}", 8))
            os.umask(oldmask)
            dst_dir.write_finish()

    class CmdGenProp(ManifestCmd):
        """
        gen property cmd class
        """
        def __init__(self, cmd_parts):
            self._src_filename = cmd_parts[0]
            self._src_spec_name = cmd_parts[1]
            self._dst_filename = cmd_parts[2]
            super().__init__(cmd_parts)

        def __str__(self):
            return f"gen property for {self._src_filename} with " \
                    "spec {self._src_spec_name} to {self._dst_filename}"

        @classmethod
        def _determine_proptytool_arg(cls, conf, arg):
            # proptytool's arg for --e and --f can be filepath or string 'default'
            if arg == 'default':
                return arg
            return conf.find_file(arg)

        def run(self, conf):
            src_file = self._determine_proptytool_arg(conf, self._src_filename)
            if src_file is None:
                return
            spec_file = self._determine_proptytool_arg(conf, self._src_spec_name)
            if spec_file is None:
                return
            dst_dir = conf.dstroot_dir.join_dir(os.path.dirname(self._dst_filename),
                                                need_create=True,
                                                fscontrol=conf.fscontrol)
            dst_file = conf.dstroot_dir.join_binfile(self._dst_filename)
            cmd = [f'{conf.cmd["genprop"]}', '--e', f'{src_file}', '--f', f'{spec_file}',
                    '--o', f'{dst_file}']
            execute_safe(cmd)
            dst_file.write_finish()
            dst_dir.write_finish()

    def __init__(self, manifest_lines):
        self._cmds_list = []
        for l in manifest_lines:
            if len(l) == 0:
                continue
            if l[0] == '#':
                continue

            hmlogging.debug(f'readline: {l}')
            parts = list(filter(lambda a: True if a else False, l.split('\t')))
            cmd = parts[0]
            hmlogging.debug(f'parts: {parts}')
            cmd_dict = {
                'copy'  : Manifest.CmdCopy,
                'mkdir' : Manifest.CmdMkdir,
                'genprop' : Manifest.CmdGenProp,
            }
            if cmd in cmd_dict.keys():
                self._cmds_list.append(cmd_dict.get(cmd)(parts[1:]))
            else:
                raise ManifestParseException(f"{cmd}")

    def run(self, conf):
        """
        run manifest
        """
        for cmd in self._cmds_list:
            cmd.run(conf)


def parse_manifest_files(manifest_files):
    """
    parse manifest files
    """
    manifest_files = (HMToolsTextFile(x) for x in manifest_files)
    manifest_lines_list = (l for f in manifest_files for l in f.lines_of())
    return Manifest(manifest_lines_list)
