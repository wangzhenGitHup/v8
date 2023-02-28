#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
Description: mkarchive
Author: Huawei OS Kernel Lab
Create: Wed Dec 09 17:53:08 2020
"""
import argparse
from pathlib import Path

from hmtools.fsops import HMToolsBinFile
from hmtools.fsops import HMToolsFSControl
from hmtools.fsops import HMToolsDir
from hmtools.exceptions import HMToolsArgException
from hmtools.exceptions import HMToolsBaseException
from hmtools import hmlogging
from hmtools.execute import execute_chain_safe


def cpio_name_aligned(relpath, align):
    """
    cpio name aligned
    """
    def align_part(base, part, align):
        # We need a 8 bytes alignment.
        # according to newc cpio file format:
        # see Documentation/early-userspace/buffer-format.txt from Linux kernel
        # Each file has a 110 bytes header

        header_sz = 110
        p = str(Path(base) / part)
        sz = header_sz + len(p) + 1

        padding = (align - (sz % align)) % align
        return '{}{}'.format(part, "_" * padding)

    curr_path = ''
    path = Path(relpath)
    for part in path.parts:
        new_part = align_part(curr_path, part, align)
        curr_path = str(Path(curr_path) / new_part)
    return curr_path


class JobPack(object):
    """
    Job pack archive
    """

    def _append_file(self, path, prefix):
        f = HMToolsBinFile(path)
        if self._name_align and '_' in f.basename_of():
            raise HMToolsArgException(f"{f.basename_of()} contains underscore '_'")
        if f.is_file_exist(check=(not self._is_force)):
            self._files.append((f, prefix))
        else:
            hmlogging.warning(f"skip inexist file {path}")


    def __init__(self, args):
        self._cmdline_args  = args
        self._fsctrl        = HMToolsFSControl(vars(self._cmdline_args))
        self._files         = []
        self._name_align    = args.name_align
        self._size_align    = args.size_align
        self._is_force      = args.force

        if args.kernel_file is not None:
            self._append_file(args.kernel_file, '')
        if args.rootfs_file is not None:
            self._append_file(args.rootfs_file, '')
        for path in args.dtb_files or []:
            self._append_file(path, 'dtb')
        for path in args.sysproc_files or []:
            self._append_file(path, '')
        for path in args.append_files or []:
            self._append_file(path, '')

        self._output = HMToolsBinFile(args.output, fscontrol=self._fsctrl)
        hmlogging.debug(f"output is {self._output}")
        for f in self._files:
            hmlogging.debug(f"archive file: src='{f[0]}' dst='{f[1]}'")

        self._tmpdir = HMToolsDir(None, tmpdir=True)
        self._workdir = self._tmpdir.join_dir('root', fscontrol=self._fsctrl)

    def _copy_files(self):
        for f in self._files:
            src = f[0]
            dst_root = self._workdir
            dst_prefix = f[1]

            if self._name_align:
                dst_dirpath_str  = cpio_name_aligned(dst_prefix, 8)
                dst_filename_str = Path(cpio_name_aligned(str(Path(dst_dirpath_str) /
                                                              src.basename_of()), 8)).parts[-1]
            else:
                dst_dirpath_str = dst_prefix
                dst_filename_str = (Path(dst_dirpath_str) / src.basename_of()).parts[-1]

            dst = src.copy_to(dst_root.join_dir(dst_dirpath_str,
                                                need_create=True),
                              dstfilename=dst_filename_str,
                              fscontrol=self._fsctrl)
            if self._size_align:
                dst.fix_size_aligned(8)

    def _gen_archive(self):

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

    def execute(self):
        """
        Execute
        """
        self._copy_files()
        self._gen_archive()


def main():
    """
    Main function
    """
    parser = argparse.ArgumentParser(description='Make archive for hongmeng bootimage')

    # do not require --kernel since it will be removed in the future, prefer --append instead
    parser.add_argument('--kernel',
                        dest='kernel_file', help='Path to kernel.elf to be archived')
    parser.add_argument('--sysproc',
                        dest='sysproc_files',
                        help='Path to sysproc to be archived (can be specified multiple times)',
                        action='append')
    parser.add_argument('--dtb',
                        dest='dtb_files',
                        help='Path to dtb files',
                        action='append')
    parser.add_argument('--rootfs',
                        dest='rootfs_file', help='Optional rootfs.cpio')
    # since this tool will be used to make both uapps.cpio and archive.cpio
    # the following arguments should be used to replacing above arguments
    # for creating an arbitary hongmeng archive. When no user uses above options
    # they should be removed
    parser.add_argument('--append',
                        action='append',
                        help='Files to be appended in archive',
                        dest='append_files')
    # currently filenames in uapps.cpio should not be padded with '_'
    # because sysmgr cannot handle it, and filenames in uapps.cpio contains '_'
    parser.add_argument('--no-name-align',
                        action='store_false',
                        help='Disable name alignment with padding dash',
                        dest='name_align')
    parser.add_argument('--no-size-align',
                        action='store_false',
                        help='Disable size alignment with padding zero',
                        dest='size_align')
    parser.add_argument('--output', default='archive.cpio',
                        dest='output', help='Output name, default: archive.cpio')
    parser.add_argument('--timestamp',
                        dest='timestamp', help='timestamp for archive files')
    parser.add_argument('--verbose', '-v', action='count', default=0,
                        dest='verbose', help='Verbose level')
    parser.add_argument('--force', action='store_true', help='Ignore inexist files',
                        dest='force')
    args = parser.parse_args()

    hmlogging.set_basic_config(vars(args))

    try:
        job = JobPack(args)
        job.execute()
    except HMToolsArgException as e:
        hmlogging.error(f"Invalid argument: {e}")
        raise
    except HMToolsBaseException:
        hmlogging.exception("Unexpected exception")
        raise
    finally:
        # no need to manually cleanup
        pass

if __name__ == '__main__':
    main()
