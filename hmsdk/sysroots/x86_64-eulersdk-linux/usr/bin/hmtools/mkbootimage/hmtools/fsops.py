#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
Description: Filesystem operations for hmtools
Author: Huawei OS Kernel Lab
Create: Sat Jan 30 11:48:18 2021
"""

import tempfile
import atexit
import struct
import shutil
import os

from datetime import datetime
from pathlib import Path
from hmtools.exceptions import HMToolsBaseException

from . import utils
from . import hmlogging


class HMToolsFSControl(object):
    ''' HM fs control tools class '''
    def __init__(self, ctrldict):
        self._dict = ctrldict
        if 'timestamp' in self._dict.keys() and self._dict['timestamp'] is not None:
            timestamp_str = self._dict['timestamp']
            timestamp = datetime.strptime(timestamp_str, "%Y%m%d%H%M").timestamp()
            self._timestamp = timestamp

    def timestamp(self):
        ''' Get timestamp '''
        if '_timestamp' in dir(self):
            return self._timestamp


class HMToolsFile(object):
    ''' HM fs file tools class '''
    def __init__(self, path_str, fscontrol=None, tmpfile=False):
        self.is_tmpfile = tmpfile
        if tmpfile:
            if path_str:
                raise HMToolsBaseException("tmpfile has fixed mame")

            tmpfd, tmppath = tempfile.mkstemp()
            os.close(tmpfd)
            path_str = tmppath

        self.__path_str = str(path_str)

        if fscontrol is None:
            self.__fscontrol = HMToolsFSControl({})
        else:
            self.__fscontrol = fscontrol

        self.__f = None

        atexit.register(self.cleanup)

    def cleanup(self):
        ''' Clean up tmp file '''
        if self.is_tmpfile:
            hmlogging.debug(f'remove tmpfile {self.__path_str}')
            utils.unlink_force(self.__path_str)

    def __str__(self):
        ''' Get path '''
        return self.__path_str

    def path_of(self, abspath=False):
        ''' Get path '''
        if not abspath:
            return self.__path_str
        else:
            return os.path.abspath(self.__path_str)

    def dirname_of(self, abspath=False):
        ''' Get dir path '''
        if not abspath:
            return os.path.dirname(self.__path_str)
        else:
            os.path.abspath(os.path.dirname(self.__path_str))

    def basename_of(self):
        ''' Get base dir of path '''
        return os.path.basename(self.__path_str)

    def open(self, *a):
        ''' Open path '''
        self.__f = open(self.__path_str, *a)
        return self

    def write_finish(self):
        ''' Update timestamp '''
        timestamp = self.__fscontrol.timestamp()
        if timestamp is not None:
            hmlogging.debug(f'update timestamp for {self.__path_str}')
            os.utime(self.__path_str, times=(int(timestamp), int(timestamp)), follow_symlinks=False)

    def size_of(self):
        ''' Return size of path str '''
        size = os.stat(self.__path_str).st_size
        return size

    def is_file_exist(self, check=False):
        ''' Check file is exist or not '''
        exist = Path(self.__path_str).is_file()
        if check and not exist:
            raise HMToolsBaseException(f"{self.__path_str} not exist")
        return exist

    def is_symlink(self):
        ''' Check file is symlink or not '''
        return Path(self.__path_str).is_symlink()

    def copy_to(self, dstdir, dstfilename=None, follow_symlinks=True, **kwargs):
        ''' Copy file to dstfile '''
        self.is_file_exist(check=True)

        dstfilename = self.basename_of() if dstfilename is None else dstfilename

        shutil.copy2(self.__path_str, Path(str(dstdir)) / dstfilename, \
                     follow_symlinks=follow_symlinks)
        dstfile = HMToolsBinFile(Path(str(dstdir)) / dstfilename, **kwargs)
        # No need to check dst file exists. If follow_symlinks is True,
        # src is already checked, and what we copy is the target.
        # If follow_symlinks is False, which means we are intend to copy symlink
        # itself, no matter it is broken or not
        hmlogging.info(f'copy {self.__path_str} to {dstfile}')
        dstfile.write_finish()
        dstdir.write_finish()

        return dstfile

    def fix_size_aligned(self, aligned_to):
        ''' Fix size aligned '''
        size = self.size_of()
        _, append = utils.align_fix(size, aligned_to)
        if self.__f is not None:
            raise HMToolsBaseException("open twice")
        if append > 0:
            hmlogging.debug(f'append {append} bytes to {self.__path_str}')
            with self.open('ab+') as _f:
                _f.write(struct.pack('b' * append, *([0] * append)))
        else:
            hmlogging.debug(f'no need to fix size of {self.__path_str}')

    def dir_of(self, **kwargs):
        ''' Get dir name '''
        return HMToolsDir(self.dirname_of(), **kwargs)

    # deligate to File
    def __enter__(self):
        return self

    def __exit__(self, _type, value, traceback):
        if self.__f is not None:
            is_write = ('w' in self.__f.mode) or ('+' in self.__f.mode) or ('a' in self.__f.mode)
            self.__f.close()
            self.__f = None

            if is_write:
                self.write_finish()

    def __getattr__(self, called_method):
        if self.__f is not None:
            method = getattr(self.__f, called_method)
            return method
        raise HMToolsBaseException("called_method {} not found or {} is closed"
                            .format(called_method, self.__path_str))


class HMToolsTextFile(HMToolsFile):
    ''' HM fs text file tools class '''
    def __init__(self, path_str, **a):
        super().__init__(path_str, **a)

    def lines_of(self):
        ''' Get line of file '''
        f = self.open()
        content = (l.strip() for l in f.readlines())
        f.close()
        return content


class HMToolsBinFile(HMToolsFile):
    ''' HM fs bin file tools class '''
    def __init__(self, path_str, **a):
        super().__init__(path_str, **a)

    def open(self, *a):
        ''' Open binary file '''
        if len(a) != 0:
            if a[0] not in ["rb", "wb", "rb+", "wb+", "ab", "ab+"]:
                raise HMToolsBaseException("open bin file with non-binary mode")
        return super(HMToolsBinFile, self).open(*a)


class HMToolsDir(object):
    ''' HM fs dir tools class '''
    def makedirs(self):
        ''' Make dirs '''
        hmlogging.info(f'makedirs: {self.__path_str}')
        os.makedirs(self.__path_str, exist_ok=True, mode=self._mode)
        self.write_finish()

    def __init__(self, path_str, need_create=False, fscontrol=None, tmpdir=False, mode=0o755):
        if fscontrol is None:
            self.__fscontrol = HMToolsFSControl({})
        else:
            self.__fscontrol = fscontrol

        self._mode = mode
        self.is_tmpdir = tmpdir
        if tmpdir:
            if path_str is not None:
                raise HMToolsBaseException("Give a name to tmpdir")
            path_str = tempfile.mkdtemp()
            self.is_tmpdir = True
            atexit.register(self.cleanup)
            hmlogging.debug(f"create tmpdir {path_str}")

        self.__path_str = path_str
        if need_create and not tmpdir:
            self.makedirs()
        self._prev_dir = None

    def cleanup(self):
        ''' Clean up path tree '''
        if self.is_tmpdir:
            hmlogging.debug(f"rmtree: {self.__path_str}")
            shutil.rmtree(self.__path_str)

    def join_dir(self, relpath, **kwargs):
        ''' Join dir '''
        return HMToolsDir(os.path.join(self.__path_str, relpath), **kwargs)

    def join_binfile(self, relpath, **kwargs):
        ''' Join binary file '''
        return HMToolsBinFile(os.path.join(self.__path_str, relpath), **kwargs)

    def chdir(self):
        ''' Switch prev dir to path dir '''
        if self._prev_dir is not None:
            raise HMToolsBaseException(f"Embeded chdir is not supported: "\
                                       "_prev_dir={self._prev_dir}")
        self._prev_dir = os.getcwd()
        os.chdir(self.__path_str)
        hmlogging.debug(f"chdir from {self._prev_dir} to {self.__path_str}")
        return self

    def chdir_back(self):
        ''' Switch path dir back to prev dir '''
        if self._prev_dir is None:
            raise HMToolsBaseException("Impossible chdir_back")
        hmlogging.debug(f"chdir back from {os.getcwd()} to {self._prev_dir}")
        os.chdir(self._prev_dir)
        self._prev_dir = None

    def write_finish(self):
        ''' Update timestamp '''
        timestamp = self.__fscontrol.timestamp()
        if timestamp is not None:
            hmlogging.debug(f'update timestamp for {self.__path_str}')
            os.utime(self.__path_str, times=(int(timestamp), int(timestamp)), follow_symlinks=False)

    def write_finish_recursive(self):
        ''' Do write_finish recursive '''
        p = Path(self.path_of())
        for child in p.iterdir():
            if child.is_dir():
                child_dir = self.join_dir(child.relative_to(p), fscontrol=self.__fscontrol)
                child_dir.write_finish_recursive()
            else:
                child_file = self.join_binfile(child.relative_to(p), fscontrol=self.__fscontrol)
                child_file.write_finish()
        self.write_finish()

    def path_of(self, abspath=False):
        ''' Get path '''
        if not abspath:
            return self.__path_str
        else:
            return os.path.abspath(self.__path_str)

    def __enter__(self):
        if self._prev_dir is None:
            raise HMToolsBaseException("Impossible")
        return self

    def __exit__(self, _type, value, traceback):
        self.chdir_back()

    def __str__(self):
        return self.__path_str
