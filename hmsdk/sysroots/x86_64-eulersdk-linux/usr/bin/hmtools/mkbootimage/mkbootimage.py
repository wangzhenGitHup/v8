#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
Description: mkbootimage
Author: Huawei OS Kernel Lab
Create: Fri Oct 16 11:24:04 2020
"""

import argparse
import struct
import shutil
import shlex
import os
import re

from hmtools.fsops import HMToolsBinFile
from hmtools.fsops import HMToolsTextFile
from hmtools.fsops import HMToolsFSControl
from hmtools.exceptions import HMToolsArgException
from hmtools.exceptions import HMToolsBaseException
from hmtools import utils
from hmtools import hmlogging
from hmtools.execute import execute_safe
from hmtools.execute import execute_output_safe


class MapInfo(object):
    """
    MapInfo
    """
    class MapSegment(object):
        """
        MapSegment
        """

        @classmethod
        def regexp_match(cls, line):
            """
            match line
            """
            regexp = re.compile('LOAD[ ]*(0x[0-9a-f]+) (0x[0-9a-f]+) 0x[0-9a-f]+ ' \
                    '(0x[0-9a-f]+) (0x[0-9a-f]+).*$')
            m =  regexp.match(line)
            return m

        def __init__(self, match):
            self.offset  = int(match.group(1), 16)
            self.vaddr   = int(match.group(2), 16)
            self.filesz  = int(match.group(3), 16)
            self.memsz   = int(match.group(4), 16)

        def is_inside_editable(self, vaddr):
            """
            Determine if editable
            """
            if self.vaddr <= vaddr < self.vaddr + self.filesz:
                return True
            return False

        def __str__(self):
            return "offset=0x%x vaddr=0x%x filesz=0x%x(%d) memsz=0x%x(%d)" % \
                    (self.offset, self.vaddr, self.filesz, self.filesz, self.memsz, self.memsz)

    class MapArg(object):
        """
        MapArg
        """

        @classmethod
        def regexp_match(cls, line):
            """
            match line
            """
            regexp = re.compile('^([0-9a-f]+) . BOOTIMAGEARG_(.*)$')
            m = regexp.match(line)
            return m

        def __init__(self, match):
            self.name       = match.group(2)
            self.vaddr      = int(match.group(1), 16)

    def __init__(self, hmfile):
        self._args      = {}
        self._segments  = []
        self._hmfile    = hmfile

        hmlogging.info(f"start parsing {hmfile}")
        for l in hmfile.lines_of():
            hmlogging.debug(f"readline: {l}")
            marg = self.MapArg.regexp_match(l)
            msgm = self.MapSegment.regexp_match(l)

            if marg:
                arg = self.MapArg(marg)
                self._args[arg.name] = arg
                hmlogging.info(f'arg append: {arg.name} = {arg.vaddr}')
            if msgm:
                sgm = self.MapSegment(msgm)
                self._segments.append(sgm)
                hmlogging.info(f'seg append: {sgm}')

    def segment_of(self, vaddr):
        """
        Segment of vaddr
        """
        for sgm in self._segments:
            if sgm.is_inside_editable(vaddr):
                return sgm
        raise Exception("vaddr invalid: {}".format(vaddr))

    def segment_first(self):
        """
        First segment
        """
        first_sgm = self._segments[0]
        for sgm in self._segments:
            if sgm.vaddr <= first_sgm.vaddr:
                first_sgm = sgm
        return first_sgm

    def elffileoffset_of(self, argname):
        """
        Elf file offset
        """
        arg = self._args.get(argname)
        vaddr = arg.vaddr
        sgm = self.segment_of(vaddr)
        return vaddr - sgm.vaddr + sgm.offset

    def binaryfileoffset_of(self, argname):
        """
        Binary file offset
        """
        # we should not use elf file offset to calculate the bianry file offset
        # since objcopy results in the same result as running view
        # so the offset is actually arg vaddr - first segment vaddr
        arg = self._args.get(argname)
        first_sgm = self.segment_first()
        return arg.vaddr - first_sgm.vaddr

    def apply(self, f, conf):
        """
        Apply
        """
        for argname in conf.keys():
            if argname in self._args:
                offset = self.elffileoffset_of(argname)
                v = struct.pack('<I', conf[argname])
                f.seek(offset)
                f.write(v)
                hmlogging.info(f"apply {argname}: write {v} at offset {offset} of file {f}")


def append_file_aligned(dst, _f, logger=None):
    """
    Append file aligned
    """
    _, append = utils.align_fix(_f.size_of())
    with _f.open('rb') as f:
        hmlogging.info(f"append {_f} to {dst}", logger=logger)
        shutil.copyfileobj(f, dst)
        hmlogging.info(f"append {append} bytes to {dst}", logger=logger)
        if append > 0:
            dst.write(struct.pack('b' * append, *([0] * append)))


class JobSplice(object):
    """
    job for making Image
    """

    @classmethod
    def checkargs(cls, args):
        """
        Check arguments
        """
        if not args.elfloader_elf:
            return False
        if not args.elfloader_map:
            raise HMToolsArgException('--elfloader-map is required when providing --elfloader-elf')
        if args.bootimage_head_elf and args.bootimage_head_map:
            return True
        raise HMToolsArgException('--bootimage-head-elf and --bootimage-head-map are required')

    def __init__(self, args):
        self._cmdline_args          = args
        self._fsctrl                = HMToolsFSControl(vars(self._cmdline_args))

        self._bootimage_head_elf    = HMToolsBinFile(args.bootimage_head_elf)
        self._archive               = HMToolsBinFile(args.archive)
        self._elfloader_elf         = HMToolsBinFile(args.elfloader_elf)
        self._output                = HMToolsBinFile(args.output, fscontrol=self._fsctrl)

        self._elfloader_map         = MapInfo(HMToolsTextFile(args.elfloader_map))
        self._bootimage_map         = MapInfo(HMToolsTextFile(args.bootimage_head_map))
        self._cmd_objcopy           = '{}objcopy'.format(args.cross_compile)
        self._rootfs                = None
        self._tmp_code = None
        self._tmp_head = None
        if args.rootfs:
            self._rootfs            = HMToolsBinFile(args.rootfs)

        hmlogging.debug(f"bootimage_head.elf\t:{self._bootimage_head_elf}")
        hmlogging.debug(f"archive\t:{self._archive}")
        hmlogging.debug(f"elfloader_elf\t:{self._elfloader_elf}")
        hmlogging.debug(f"archive\t:{self._archive}")
        hmlogging.debug(f"elfloader.map\t:{args.elfloader_map}")
        hmlogging.debug(f"bootimage.map\t:{args.bootimage_head_map}")
        hmlogging.debug(f"_rootfs\t:{self._rootfs}")


    def _gen_tmp_head(self):
        tmpfile = HMToolsBinFile(None, tmpfile=True)
        cmd = ['cp', f'{self._bootimage_head_elf}', f'{tmpfile}']
        execute_safe(cmd)
        self._tmp_head = tmpfile

    def _gen_tmp_code(self):
        tmpfile = HMToolsBinFile(None, tmpfile=True)
        cmd = [f'{self._cmd_objcopy}', '-O', 'binary', f'{self._elfloader_elf}', f'{tmpfile}']
        execute_safe(cmd)
        self._tmp_code = tmpfile

    def _edit_tmp_head(self):
        archive_aligned_size = utils.align_up(self._archive.size_of())
        rootfs_aligned_size = 0
        if self._rootfs:
            rootfs_aligned_size = utils.align_up(self._rootfs.size_of())
        conf = {'archive_size':
                    archive_aligned_size,
                'code_size':
                    self._tmp_code.size_of(),
                'bootimgargs_offset':
                    self._elfloader_map.binaryfileoffset_of('bootimgargs'),
                'rootfs_size':
                    rootfs_aligned_size
                }

        with self._tmp_head.open('rb+') as f:
            self._bootimage_map.apply(f, conf)

    def _assemble(self):
        cmd = [f'{self._cmd_objcopy}', '--only-section=.text.start', '-O', 'binary',
                f'{self._tmp_head}', f'{self._output}']
        execute_safe(cmd)

        with self._output.open('ab+') as output_file:
            append_file_aligned(output_file, self._archive)
            if self._rootfs:
                append_file_aligned(output_file, self._rootfs)
            append_file_aligned(output_file, self._tmp_code)

    def execute(self):
        """
        Execute making bootimage
        """
        self._gen_tmp_code()
        self._gen_tmp_head()
        self._edit_tmp_head()
        self._assemble()


class JobLink(object):
    """
    Link bootimage.elf job
    """

    @classmethod
    def checkargs(cls, args):
        """
        Check arguments
        """
        if not args.elfloader_obj:
            return False
        if args.elfloader_lds and args.text_start:
            return True
        raise HMToolsArgException('--elfloader-lds and --text-start is required')

    def __init__(self, args):
        self._cmdline_args          = args
        self._fsctrl                = HMToolsFSControl(vars(self._cmdline_args))

        self._archive       = HMToolsBinFile(args.archive)
        self._elfloader_obj = HMToolsBinFile(args.elfloader_obj)
        self._elfloader_lds = HMToolsTextFile(args.elfloader_lds)
        self._output        = HMToolsBinFile(args.output, fscontrol=self._fsctrl)
        self._cmd_ld        = '{}ld'.format(args.cross_compile)
        self._cmd_objcpy    = '{}objcopy'.format(args.cross_compile)
        self._cmd_readelf   = '{}readelf'.format(args.cross_compile)
        self._text_start    = args.text_start
        self._rootfs        = None
        self._tmp_rootfs = None
        self._tmp_archive = None
        self._elf_endianess = None
        self._elf_arch      = None
        self._elf_bfdname   = None
        if args.rootfs:
            self._rootfs    = HMToolsBinFile(args.rootfs)

        hmlogging.debug(f"archive\t:{self._archive}")
        hmlogging.debug(f"elfloader.o\t:{self._elfloader_obj}")
        hmlogging.debug(f"elfloader.lds\t:{self._elfloader_lds}")
        hmlogging.debug(f"output\t:{self._output}")
        hmlogging.debug(f"rootfs\t:{self._rootfs}")

        if not args.libs:
            a_files = ['libgcc.a',
                       'libclang_rt.builtins.a',
                       'libklibs.a']
            real_a_files = []
            for f in a_files:
                cmd = [f'{args.cross_compile}gcc', f'-print-file-name={f}']
                output = execute_output_safe(cmd)
                if os.path.exists(output):
                    real_a_files.append(output)
                    hmlogging.debug(f'{output} is found')
                else:
                    hmlogging.debug(f'{output} is not found')

            self._libs = real_a_files
        else:
            self._libs = []
            for x in args.libs:
                self._libs += shlex.split(x)

        hmlogging.debug(f"libs\t:{self._libs}")

    def _detect_elf_args(self):
        cmd = [f'{self._cmd_readelf}', '-h', f'{self._elfloader_obj}']
        elfheader = execute_output_safe(cmd)
        header_dict = {}
        for l in elfheader.split('\n'):
            kv = l.split(':')
            header_dict[kv[0].strip()] = (':'.join(kv[1:])).strip()

        elfclass = ['32', '64'][header_dict.get('Class') == 'ELF64']

        self._elf_endianess = ['little', 'big']['big' in header_dict.get('Data')]
        self._elf_arch      = ['arm', 'aarch64']['AArch64' in header_dict.get('Machine')]
        self._elf_bfdname   = 'elf{}-{}{}'.format(elfclass, self._elf_endianess, self._elf_arch)
        hmlogging.info(f"bfdname is {self._elf_bfdname}")

    def _gen_archive_obj(self):
        tmp_archive = HMToolsBinFile(None, tmpfile=True)
        cmd = [f'{self._cmd_objcpy}', '-B', f'{self._elf_arch}', '-I', 'binary', '-O',
                f'{self._elf_bfdname}', f'{self._archive}', f'{tmp_archive}',
                '--rename-section', '.data=.archive']
        execute_safe(cmd)
        self._tmp_archive = tmp_archive

    def _gen_rootfs_obj(self):
        hmlogging.debug(f'rootfs is {self._rootfs}')
        if not self._rootfs:
            return
        tmp_rootfs = HMToolsBinFile(None, tmpfile=True)
        cmd = [f'{self._cmd_objcpy}', '-B', f'{self._elf_arch}', '-I', 'binary', '-O',
                f'{self._elf_bfdname}', f'{self._rootfs}', f'{tmp_rootfs}',
                '--rename-section', '.data=.rootfs']
        execute_safe(cmd)
        self._tmp_rootfs = tmp_rootfs

    def _link(self):
        # A class Linker would required when we support more architectures.
        if self._elf_endianess == 'little':
            endianess_opt = '-EL'
        else:
            if self._elf_arch == 'aarch64':
                # aarch64 ld say invalid BFD target for -be8, and unrecognized option for --be8
                # however, from gcc ARM-Options manual, BE8 is default formats for armv6 and later
                # thus it is safe to not add this option for aarch64 big endian
                endianess_opt = '-EB'
            else:
                endianess_opt = '-EB --be8'

        cmd = [f'{self._cmd_ld}', '-T', f'{self._elfloader_lds}', '-o', f'{self._output}',
                *shlex.split(endianess_opt),
                '-z', 'noexecstack', '-X', '--pic-veneer', '-pie', '-z', 'relro', '-z', 'now',
                f'{self._elfloader_obj}', f'{self._tmp_archive}',
                f'{self._tmp_rootfs}' if self._tmp_rootfs else '',
                '--start-group', *(f'{x}' for x in self._libs), '--end-group',
                f'-Ttext={self._text_start}'
                ]
        execute_safe(cmd)
        self._output.write_finish()

    def execute(self):
        """
        Execute making bootimage
        """
        self._detect_elf_args()
        self._gen_archive_obj()
        self._gen_rootfs_obj()
        self._link()


def dispatch(args):
    """
    Dispatch job class from arguments
    """
    jobclasses = [JobSplice, JobLink]

    if not args.cross_compile:
        raise HMToolsArgException('--cross-compile is mandatory')
    if not args.archive:
        raise HMToolsArgException('--archive is mandatory')
    if not args.output:
        raise HMToolsArgException('--output is mandatory')

    if (args.elfloader_elf is not None) and (args.elfloader_obj is not None):
        raise HMToolsArgException('--elfloader-elf and --elfloader-obj are exclusive')

    for cls in jobclasses:
        if cls.checkargs(args):
            hmlogging.debug(f'choose jobclass {cls}')
            return cls

    raise HMToolsArgException('One of --elfloader-elf and --elfloader-obj is required')


def main():
    """
    Main function
    """
    parser = argparse.ArgumentParser(description='Make hongmeng bootimage')

    # mandatory arguments
    parser.add_argument('--archive',
                        dest='archive', help='Path to archive to be linked')
    parser.add_argument('--output',
                        dest='output', help='Path to output bootimage.elf')
    parser.add_argument('--cross-compile',
                        dest='cross_compile', help='Prefix of toolchain')

    # optional arguments
    parser.add_argument('--rootfs',
                        dest='rootfs', help='Path to rootfs archive')
    parser.add_argument('--timestamp',
                        dest='timestamp', help='Timestamp of all entries in rootfs')

    # Arguments group 1: Combine everything directly
    parser.add_argument('--bootimage-head-elf',
                        dest='bootimage_head_elf', help='Path to bootimage_head.elf')
    parser.add_argument('--bootimage-head-map',
                        dest='bootimage_head_map', help='Path to bootimage_head.map')
    parser.add_argument('--elfloader-elf',
                        dest='elfloader_elf', help='Path to elfloader.elf')
    parser.add_argument('--elfloader-map',
                        dest='elfloader_map', help='Path to elfloader.map')

    # Arguments group 2: Link everything together
    parser.add_argument('--elfloader-obj',
                        dest='elfloader_obj', help='Path to elfloader.o')
    parser.add_argument('--libs',
                        dest='libs', help='Libs of libgcc and libfdt',
                        action='append')
    parser.add_argument('--elfloader-lds',
                        dest='elfloader_lds', help='Path to elfloader.lds')
    parser.add_argument('--text-start',
                        dest='text_start', help='Start of elfloader text section')
    parser.add_argument('--verbose', '-v', action='count', default=0,
                        dest='verbose', help='Verbose level')
    args = parser.parse_args()

    hmlogging.set_basic_config(vars(args))

    try:
        jobcls = dispatch(args)
        job = jobcls(args)
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
