#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
# Author: Huawei OS Kernel Lab
# Create: Mon Apr 22 10:25:38 2019

"""
Description:
1. copy kev ring buffer output from console and save as "sample.data"
2. copy relevat elf files, directory structure is as follows:
├── elf
│   ├── devhost.elf
│   ├── test.elf
│   ├── xxx.elf
│   ├── libc.so
│   └── sysmgr.elf
├── convert_perf_data.py
├── config
└── sample.data
3. config file example:
devmgr.elf:
libc.so 0x9c4000
libhmulibs.so 0x3b26000
4. run this scripts, it will generate "perf.data"
5. run perf report to display hotspot functions
"""
import argparse
import enum
import logging
import os
import struct
import sys

# Rely on python-pyelftools
from elftools.elf.elffile import ELFFile
from elftools.common.exceptions import ELFError


@enum.unique
class StackContextType(enum.Enum):
    """
    Define perf call stack structure, for each of following types of PC,
    needs to save corresponding type of value first.
    """
    STACK_TYPE_HV = -32
    STACK_TYPE_KERNEL = -128
    STACK_TYPE_USER = -512

    STACK_TYPE_GUEST = -2048
    STACK_TYPE_GUEST_KERNEL = -2176
    STACK_TYPE_GUEST_USER = -2560


def writeb(array, f):
    """
    Write a unsigned char array to file
    """
    for x in array:
        a = struct.pack('B', x)
        f.write(a)


def writeh(x, f):
    """
    Write a unsigned int variable to file in big-endian
    """
    a = struct.pack('>H', x)
    f.write(a)


def writeq(x, f):
    """
    Write a unsigned long long variable to file in big-endian
    """
    a = struct.pack('>Q', x)
    f.write(a)


def writel(x, f):
    """
    Write a unsigned long variable to file in big-endian
    """
    a = struct.pack('>L', x)
    f.write(a)


def dict_op_get(dic, keys):
    """
    Get the dict value from keys
    """
    cur = dic
    for key in keys:
        if key in cur:
            cur = cur[key]
        else:
            raise KeyError('{dic}: {keys}'.format(dic=dic, keys=keys))
    return cur


def dict_op_set(dic, keys, value):
    """
    Set the dict value from keys
    """
    cur = dic
    for key in keys[0:-1]:
        if key in cur:
            cur = cur[key]
        else:
            raise KeyError('{dic}: {keys}'.format(dic=dic, keys=keys))
    cur[keys[-1]] = value


class PerfHeaderSection:
    """
    file header structure, include:
        magic                : 8Byte
        size of header       : 8Byte
        size of attr         : 8Byte
        attrs section        : 16Byte
        data_offset section  : 8Byte
        event_type section   : 16Byte
        adds features section: 16Byte

    file section, include:
        offset  : 8Byte
        size    : 8Byte
    """

    def __init__(self, fd, data_size):
        self.fd = fd
        self.data_size = data_size

    def pub_holder(self):
        """
        Give a fd
        """
        return self.fd

    @staticmethod
    def _generate_magic(fd):
        array = [0x32, 0x45, 0x4c, 0x49, 0x46, 0x52, 0x45, 0x50,  # magic
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68,  # sizeof header
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80]  # sizeof one attr section
        writeb(array, fd)

    @staticmethod
    def _generate_attrs_section(fd):
        array = [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68,  # attr.offset
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80]  # attr_size
        writeb(array, fd)

    @staticmethod
    def _generate_data_section(data_size, fd):
        array = [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8]  # data_offset
        writeb(array, fd)
        writeq(data_size, fd)

    @staticmethod
    def _generate_event_type_section(fd):
        array = [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # event_type_offset
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]  # event_type_size
        writeb(array, fd)

    @staticmethod
    def _generate_adds_features_section(fd):
        array = [0x00, 0x01, 0x3D, 0xFC, 0x00, 0x00, 0x00, 0x00,  # add_features

                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # add_features
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # add_features

                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]  # add_features
        writeb(array, fd)

    @staticmethod
    def _generate_file_attr_section(fd):
        array = [0x00, 0x00, 0x00, 0x00,                          # type
                 0x00, 0x00, 0x00, 0x70,                          # size

                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # config
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xA0,  # sample_period/sample_freq

                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x27,  # sample_type
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # read_format

                 0xC0, 0xCD, 0xA9, 0x80, 0x00, 0x00, 0x00, 0x00,  # disable.....inhert....
                 0x00, 0x00, 0x00, 0x00,                          # wakeup_events/wakeup_watermark
                 0x00, 0x00, 0x00, 0x00,                          # bp_type

                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # bp_addr
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # bp_len

                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # branch_sample_type
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # sample_regs_user

                 0x00, 0x00, 0x00, 0x00,                          # sample_stack_user
                 0x00, 0x00, 0x00, 0x00,                          # clockid
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  # sample_regs_intr

                 0x00, 0x00, 0x00, 0x00,                          # aux_watermark
                 0x00, 0x00, 0x00, 0x00]                          # __reserved_2
        writeb(array, fd)

    @staticmethod
    def _generate_perf_file_section(fd):
        array = [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68,  # ids offset
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]  # ids size
        writeb(array, fd)

    def generate_section(self):
        """
        Generate according to the template and write the file head of perf.data to `perf.data`
        """
        PerfHeaderSection._generate_magic(self.fd)
        PerfHeaderSection._generate_attrs_section(self.fd)
        PerfHeaderSection._generate_data_section(self.data_size, self.fd)
        PerfHeaderSection._generate_event_type_section(self.fd)
        PerfHeaderSection._generate_adds_features_section(self.fd)
        PerfHeaderSection._generate_file_attr_section(self.fd)
        PerfHeaderSection._generate_perf_file_section(self.fd)


class PerfSampleEvent:
    """
    event header, include:
        type  : 4Byte
        misc  : 2Byte
        size  : 2Byte

    sample event structure, include:
        event header : 8Byte
        ip           : 8Byte
        pid, tid     : 4Byte
        time         : 8Byte
        period       : 8Byte
        nr           : 8Byte
        ips[nr]      : nr * 8Byte
    """

    def __init__(self, fd, event_data):
        self.fd = fd
        self.ip = event_data['ip']
        self.stack = event_data['stack']
        self.pid = event_data['pid']
        self.tid = event_data['tid']
        self.time = event_data['time']
        self.period = event_data['period']
        # insert PERF_CONTEXT_USER
        self.stack.insert(0, StackContextType['STACK_TYPE_USER'].value & 0xFFFFFFFFFFFFFFFF)
        self.stack_nr = len(self.stack)

    def pub_holder(self):
        """
        Give a fd
        """
        return self.fd

    @staticmethod
    def _generate_user_header(stack_nr, fd):
        # 9: SAMPLE 2: USER
        array = [0, 0, 0, 9, 0, 2]
        writeb(array, fd)
        writeh((6 + stack_nr) * 8, fd)

    @staticmethod
    def _generate_kernel_header(stack_nr, fd):
        # 9: SAMPLE 1: KERNEL
        array = [0, 0, 0, 9, 0, 1, 0, ((6 + stack_nr) * 8)]
        writeb(array, fd)

    @staticmethod
    def _generate_ip(ip, fd):
        writeq(ip, fd)

    @staticmethod
    def _generate_pid_tid(pid, tid, fd):
        writel(pid, fd)
        writel(tid, fd)

    @staticmethod
    def _generate_time(time, fd):
        writeq(time, fd)

    @staticmethod
    def _generate_period(period, fd):
        writeq(period, fd)

    @staticmethod
    def _generate_stack(stack, stack_nr, fd):
        writeq(stack_nr, fd)
        for i in range(stack_nr):
            writeq(stack[i], fd)

    def generate_event(self):
        """
        Generate a perf sample event and write to the specified file
        """
        PerfSampleEvent._generate_user_header(self.stack_nr, self.fd)
        PerfSampleEvent._generate_ip(self.ip, self.fd)
        PerfSampleEvent._generate_pid_tid(self.pid, self.tid, self.fd)
        PerfSampleEvent._generate_time(self.time, self.fd)
        PerfSampleEvent._generate_period(self.period, self.fd)
        PerfSampleEvent._generate_stack(self.stack, self.stack_nr, self.fd)


class PerfMmapEvent:
    """
    sample event structure, include:
       event header      : 8Byte
       pid, tid          : 4Byte
       addr              : 8Byte
       len               : 8Byte
       pgoff             : 8Byte
       major, min        : 4Byte
       ino               : 8Byte
       ino_generation    : 8Byte
       prot, flags       : 4Byte
       filename          :
       sample id: pid_tid: 4Byte
       sample_id: time   : 8Byte
    """

    def __init__(self, fd, event_data):
        self.name = event_data['name']
        self.pid = event_data['pid']
        self.tid = event_data['tid']
        self.addr = event_data['addr']
        self.mmap2_len = event_data['mmap2_len']
        self.pgoff = event_data['pgoff']
        self.time = event_data['time']
        self.fd = fd

    def pub_holder(self):
        """
        Give a fd
        """
        return self.fd

    @staticmethod
    def _generate_header(name, fd):
        name_len = len(name)
        name_space = int(name_len / 8 + 1) * 8
        size = 88 + name_space
        array = [0, 0, 0, 0xA, 0, 2]                              # A: MMAP 2: USER
        writeb(array, fd)
        writeh(size, fd)

    @staticmethod
    def _generate_pid_tid(pid, tid, fd):
        writel(pid, fd)
        writel(tid, fd)

    @staticmethod
    def _generate_mmap_info(addr, mmap2_len, pgoff, fd):
        writeq(addr, fd)
        writeq(mmap2_len, fd)
        writeq(pgoff, fd)

    @staticmethod
    def _generate_node_info(fd):
        # major, minor
        writel(0x0, fd)
        writel(0x0, fd)
        # ino
        writeq(0x0, fd)
        # ino_generation
        writeq(0x0, fd)
        # prot flags
        writeq(0x00000000, fd)

    @staticmethod
    def _generate_path(name, fd):
        fd.write(name.encode())

        name_len = len(name)
        name_space = int(name_len / 8 + 1) * 8
        left = name_space - name_len
        for _ in range(left):
            array = [0]
            writeb(array, fd)

    @staticmethod
    def _generate_id(pid, tid, time, fd):
        writel(pid, fd)
        writel(tid, fd)
        writeq(time, fd)

    def generate_event(self):
        """
        Generate a perf mmap event and write to the specified file
        """
        PerfMmapEvent._generate_header(self.name, self.fd)
        PerfMmapEvent._generate_pid_tid(self.pid, self.tid, self.fd)
        PerfMmapEvent._generate_mmap_info(self.addr, self.mmap2_len, self.pgoff, self.fd)
        PerfMmapEvent._generate_node_info(self.fd)
        PerfMmapEvent._generate_path(self.name, self.fd)
        PerfMmapEvent._generate_id(self.pid, self.tid, self.time, self.fd)


class PerfCommEvent:
    """
    command event structure, include:
       event header      : 8Byte
       pid, tid          : 4Byte
       comm[]            : 16Byte
       sample id: pid_tid: 4Byte
       sample_id: time   : 8Byte
    """
    def __init__(self, fd, event_data):
        self.fd = fd
        self.comm = event_data['comm']
        self.pid = event_data['pid']
        self.tid = event_data['tid']
        self.time = event_data['time']
        self.execf = event_data['execf']

    def pub_holder(self):
        """
        Give a fd
        """
        return self.fd

    @staticmethod
    def _generate_header(execf, comm, fd):
        comm_len = len(comm)
        comm_space = int(comm_len / 8 + 1) * 8
        size = 32 + comm_space
        array = [0, 0, 0, 0x3, 0x20 if execf else 0x0, 0]
        writeb(array, fd)
        writeh(size, fd)

    @staticmethod
    def _generate_pid_tid(pid, tid, fd):
        writel(pid, fd)
        writel(tid, fd)

    @staticmethod
    def _generate_comm(comm, fd):
        fd.write(comm.encode())

        comm_len = len(comm)
        comm_space = int(comm_len / 8 + 1) * 8
        left = comm_space - comm_len
        for _ in range(left):
            array = [0]
            writeb(array, fd)

    @staticmethod
    def _generate_id(pid, tid, time, fd):
        writel(pid, fd)
        writel(tid, fd)
        writeq(time, fd)

    def generate_event(self):
        """
        Generate a perf common event and write to the specified file
        """
        PerfCommEvent._generate_header(self.execf, self.comm, self.fd)
        PerfCommEvent._generate_pid_tid(self.pid, self.tid, self.fd)
        PerfCommEvent._generate_comm(self.comm, self.fd)
        PerfCommEvent._generate_id(self.pid, self.tid, self.time, self.fd)


class PerfData:
    """
    The main process that convert perf data form hongmeng format to linux format
    """
    def __init__(self, info):
        self.sample_num = 0
        self.DEFAULT_PID = 0x1
        self.DEFAULT_TID = 0x1
        self.DEFAULT_TIME = 0x01950B25262670
        self.DEFAULT_PERIOD = 0x1
        self.DEFAULT_STACK_DEPTH = 20
        self.nostack = info['nostack']
        self.process_list = []
        self.process_mmap_info = {}
        self.file_link_libraries_dict = {}
        self.files_mmap_dict = {}
        self.little_endian = info['little_endian']
        self.LITTLE_ENDIAN_SAMPLE_DATA_MAGIC_NAME = "TDELPMAS"
        self.BIG_ENDIAN_SAMPLE_DATA_MAGIC_NAME = "SAMPLEDT"
        self.KEV_EVT_SIZE_MASK = (1 << 12) - 1

        self.sysname = None
        self.nodename = None
        self.release = None
        self.version = None
        self.machine = None
        self.process_dict = {}
        self.KEV_EVT_SIZE_SHIFT = None
        self.sample_data = None
        self.elf_load_data = None
        self.system_info_data = None
        self.sample_data_fd = None
        self.perf_data_fd = None

        self.KEV_EVENT_HEADER_SIZE = struct.calcsize("I")

        # There are 4 bytes padding at the end of structure kev_sample_data
        self.KEV_SAMPLE_DATA_SIZE = struct.calcsize("QI16sI")
        self.SAMPLE_SIZE = self.KEV_EVENT_HEADER_SIZE + self.KEV_SAMPLE_DATA_SIZE
        self.BLOCK_SIZE = 4096
        self.SAMPLE_TYPE = 6
        self.CPUID = 0

        self.sample_file = info['sample_file']
        self.perf_data_file = info['perf_data']
        self.elf_dir = info['elf_dir']
        self.config_path = info['config_path']

    def __unpack(self, data, offset, fmt):
        bytes_fmt = "%s" % fmt if self.little_endian else ">%s" % fmt
        return struct.unpack(bytes_fmt, data[offset : offset + struct.calcsize(bytes_fmt)]) + \
                             (offset + struct.calcsize(bytes_fmt),)

    def __uptr(self):
        uptr_type = {"arm" : "I", "aarch64" : "Q"}
        for (machine, uptr) in uptr_type.items():
            if machine in self.machine:
                return uptr
        logging.error("invalid machine type %s", self.machine)
        sys.exit(1)

    def __update_system_info(self):
        sysname, nodename, release, version, machine, _ = \
            self.__unpack(self.system_info_data, 0, "65s65s65s65s65s")
        self.sysname = bytes.decode(sysname.split(b"\x00")[0], errors='ignore')
        self.nodename = bytes.decode(nodename.split(b"\x00")[0], errors='ignore')
        self.release = bytes.decode(release.split(b"\x00")[0], errors='ignore')
        self.version = bytes.decode(version.split(b"\x00")[0], errors='ignore')
        self.machine = bytes.decode(machine.split(b"\x00")[0], errors='ignore')

    def __update_elf_load_info(self):
        count, offset = self.__unpack(self.elf_load_data, 0, "i")
        for _ in range(count):
            cnode_idx, offset = self.__unpack(self.elf_load_data, offset, "I")
            self.process_dict[cnode_idx] = {}
            num, offset = self.__unpack(self.elf_load_data, offset, "i")
            for _ in range(num):
                name_len, offset = self.__unpack(self.elf_load_data, offset, "I")
                name, offset = self.__unpack(self.elf_load_data, offset, "%ds" % name_len)
                name = bytes.decode(name, errors='ignore').strip(b'\x00'.decode())
                _, offset = self.__unpack(self.elf_load_data, offset, "I")
                base_addr, offset = self.__unpack(self.elf_load_data, offset, "Q")
                offset_addr, offset = self.__unpack(self.elf_load_data, offset, "Q")
                base_len, offset = self.__unpack(self.elf_load_data, offset, "I")
                symtab_addr, offset = self.__unpack(self.elf_load_data, offset, "Q")
                strtab_addr, offset = self.__unpack(self.elf_load_data, offset, "Q")
                symtab_len, offset = self.__unpack(self.elf_load_data, offset, "I")
                strtab_len, offset = self.__unpack(self.elf_load_data, offset, "I")
                dict_op_set(self.process_dict,
                            [cnode_idx, name],
                            {"base_addr" : base_addr,
                             "offset_addr" : offset_addr,
                             "base_len" : base_len,
                             "symtab_addr" : symtab_addr,
                             "strtab_addr" : strtab_addr,
                             "symtab_len" : symtab_len,
                             "strtab_len" : strtab_len})

    def __read_sample_data(self):
        header_size = struct.calcsize("8sQQQQ")
        data = self.sample_data_fd.read(header_size)
        magic_name, = struct.unpack("8s", data[:8])
        magic_name = magic_name.decode(errors='ignore').strip(b'\x00'.decode())
        offset = struct.calcsize("8s")

        if magic_name == self.LITTLE_ENDIAN_SAMPLE_DATA_MAGIC_NAME:
            self.little_endian = True
        elif magic_name == self.BIG_ENDIAN_SAMPLE_DATA_MAGIC_NAME:
            self.little_endian = False
        else:
            logging.error("'%s' is not a valid sample data type file", self.sample_file)
            sys.exit(1)

        # endian can be determined only by reading MAGIC_NAME,
        # KEV_EVT_SIZE_SHIFT must be set after endian are determined
        self.KEV_EVT_SIZE_SHIFT = 0 if self.little_endian else 20

        total_size, sample_data_size, elf_load_info_size, system_info_size, offset = \
            self.__unpack(data, offset, "QQQQ")

        if total_size != os.path.getsize(self.sample_file):
            logging.error("'%s' total size = %d do not match file size = %d",
                  self.sample_file, total_size, os.path.getsize(self.sample_file))
            sys.exit(1)

        self.sample_data = b""
        size = 0
        while size + self.BLOCK_SIZE < sample_data_size:
            block = self.sample_data_fd.read(self.BLOCK_SIZE)
            self.sample_data = block + self.sample_data
            size += self.BLOCK_SIZE

        self.sample_data = self.sample_data_fd.read(sample_data_size - size) + self.sample_data
        self.elf_load_data = self.sample_data_fd.read(elf_load_info_size)
        self.system_info_data = self.sample_data_fd.read(system_info_size)
        logging.info("sample_data_size = %d, elf_load_info_size = %d, system_info_size = %d",
                     sample_data_size, elf_load_info_size, system_info_size)

    @staticmethod
    def _generate_header_section(fd):
        head = PerfHeaderSection(fd, 0x12345678)
        head.generate_section()

    def __search_elf_file(self, comm):
        if comm in self.files_mmap_dict:
            return comm

        (filepath, filename) = os.path.split(comm)
        logging.debug('Do use the variable: %s', filepath)
        if filename in self.files_mmap_dict:
            return filename

        if filename + ".elf" in self.files_mmap_dict:
            return filename + ".elf"

        (basename, extension) = os.path.splitext(filename)
        logging.debug('Do use the variable: %s', extension)
        if basename + ".elf" in self.files_mmap_dict:
            return basename + ".elf"

        raise Exception('{comm} cannot find the corresponding elf file'.format(comm=comm))


    def _generate_mmap_events(self, comm, fd):
        """
        The function has not been called until now.
        """
        dict_op_set(self.process_mmap_info,
                    [comm],
                    {"pid" : self.process_list.index(comm),
                     "mmap" : {}})

        filename = self.__search_elf_file(comm)
        if filename in self.files_mmap_dict:
            for i in dict_op_get(self.files_mmap_dict, [filename, "mmap"]):
                dict_op_set(self.process_mmap_info,
                            [comm, "mmap", filename],
                            {"addr" : i["addr"], "size" : i["size"], "offset" : i["offset"]})
                event_data = {
                        'name': dict_op_get(self.files_mmap_dict, [filename, "filepath"]),
                        'pid': self.DEFAULT_PID + self.process_list.index(comm),
                        'tid': self.DEFAULT_TID + self.process_list.index(comm),
                        'addr': i['addr'],
                        'mmap2_len': i['size'],
                        'pgoff': i['offset'],
                        'time': self.DEFAULT_TIME}
                mmap_event = PerfMmapEvent(fd, event_data)
                mmap_event.generate_event()
        else:
            dict_op_set(self.process_mmap_info,
                        [comm, "mmap", filename],
                        {"addr" : 0xFFFFFFFF, "size" : 0, "offset" : 0})

        if filename in self.file_link_libraries_dict:
            for (library_name, library_addr) in dict_op_get(self.file_link_libraries_dict,
                                                            [filename]).items():
                if library_name in self.files_mmap_dict:
                    mmap2_len = dict_op_get(self.files_mmap_dict,
                                            [library_name, "mmap", 0, "size"]) + \
                                dict_op_get(self.files_mmap_dict,
                                            [library_name, "mmap", 0, "addr"])
                    dict_op_set(self.process_mmap_info,
                                [comm, "mmap", library_name],
                                {"addr" : int(library_addr, 16), "size" : mmap2_len, "offset" : 0})
                    event_data = {
                            'name': dict_op_get(self.files_mmap_dict, [library_name, "filepath"]),
                            'pid': self.DEFAULT_PID + self.process_list.index(comm),
                            'tid': self.DEFAULT_TID + self.process_list.index(comm),
                            'addr': int(library_addr, 16),
                            'mmap2_len': mmap2_len,
                            'pgoff': 0,
                            'time': self.DEFAULT_TIME}
                    mmap_event = PerfMmapEvent(fd, event_data)
                    mmap_event.generate_event()
                else:
                    dict_op_set(self.process_mmap_info,
                                [comm, "mmap", library_name],
                                {"addr" : 0xFFFFFFFF, "size" : 0, "offset" : 0})

    def __generate_mmap_events(self, fd, cnode_idx, comm, event_data):
        if cnode_idx not in self.process_dict:
            logging.error("cnode_idx = %d, actv_name = '%s' cannot find elf load info",
                         cnode_idx, comm)
            return

        self.process_mmap_info[comm] = {"pid" : event_data['pid'], "mmap" : {}}
        for (elf_name, mmaps) in dict_op_get(self.process_dict, [cnode_idx]).items():
            (filepath, basename) = os.path.split(elf_name)
            logging.debug('Do use the variable: %s', filepath)
            if basename not in self.files_mmap_dict:
                found = False
                base_addr = mmaps["base_addr"]
                base_len = mmaps["base_len"]
                offset = mmaps["offset_addr"]
                logging.error("'%s' not exist in elf dict for actv_name = '%s'", basename, comm)
            elif dict_op_get(self.files_mmap_dict, [basename, "type"]) == "ET_EXEC":
                found = True
                base_addr = dict_op_get(self.files_mmap_dict,
                                        [basename, "mmap", 0, "addr"])
                base_len = dict_op_get(self.files_mmap_dict, [basename, "mmap", 0, "size"])
                offset = dict_op_get(self.files_mmap_dict, [basename, "mmap", 0, "offset"])
            elif dict_op_get(self.files_mmap_dict, [basename, "type"]) == "ET_DYN":
                found = True
                base_len = dict_op_get(self.files_mmap_dict, [basename, "mmap", 0, "size"]) \
                    if mmaps["base_len"] == 0 else mmaps["base_len"]
                offset = 0
                base_addr = mmaps["base_addr"]
            else:
                found = False
                base_addr = mmaps["base_addr"]
                base_len = mmaps["base_len"]
                offset = mmaps["offset_addr"]
                logging.error("'%s' is not a dynamic library or executable for actv_name = '%s'",
                             basename, comm)

            if found:
                data = {'name': dict_op_get(self.files_mmap_dict, [basename, "filepath"]),
                        'pid': event_data['pid'], 'tid': event_data['tid'],
                        'addr': base_addr, 'mmap2_len': base_len,
                        'pgoff': offset, 'time': self.DEFAULT_TIME}
                mmap_event = PerfMmapEvent(fd, data)
                mmap_event.generate_event()

            dict_op_set(self.process_mmap_info,
                       [comm, "mmap", elf_name],
                       {"addr" : base_addr, "size" : base_len, "offset" : offset, "found" : found})

    def __generate_sample_events(self, fd):
        offset = 0
        while offset < len(self.sample_data):
            index = offset
            header, index = self.__unpack(self.sample_data, index, "I")
            evt_size = (header >> self.KEV_EVT_SIZE_SHIFT) & self.KEV_EVT_SIZE_MASK

            pc, cnode_idx, comm, _, index = self.__unpack(self.sample_data, index, "QI16sI")
            comm = comm.decode(errors='ignore').strip(b'\x00'.decode())
            process = {"cnode_idx" : cnode_idx, "comm" : comm}
            if process not in self.process_list:
                self.process_list.append(process)
                event_data = {
                        'comm': comm,
                        'execf': True,
                        'pid': self.DEFAULT_PID + self.process_list.index(process),
                        'tid': self.DEFAULT_TID + self.process_list.index(process),
                        'time': self.DEFAULT_TIME}
                event = PerfCommEvent(fd, event_data)
                event.generate_event()

                event_data = {
                        'pid': self.DEFAULT_PID + self.process_list.index(process),
                        'tid': self.DEFAULT_TID + self.process_list.index(process)}
                self.__generate_mmap_events(
                        fd=fd,
                        cnode_idx=cnode_idx,
                        comm=comm,
                        event_data=event_data)

            if not self.nostack and evt_size > self.SAMPLE_SIZE:
                stack_nr, index = self.__unpack(self.sample_data, index, "Q")
                stack = [pc]
                stack.extend(list(self.__unpack(self.sample_data, index, "%dQ" % stack_nr))[: -1])
            else:
                stack = []

            event_data = {
                    'ip': pc,
                    'stack': stack,
                    'pid': self.DEFAULT_PID + self.process_list.index(process),
                    'tid': self.DEFAULT_TID + self.process_list.index(process),
                    'time': self.DEFAULT_TIME,
                    'period': self.DEFAULT_PERIOD}
            event = PerfSampleEvent(fd, event_data)
            event.generate_event()
            self.sample_num += 1
            offset += evt_size
        if offset != len(self.sample_data):
            logging.error("There is a problem with data analysis")

    def __load_file_mmap_info(self, filename, fd):
        logging.debug('Do use the variable: %d', fd)
        addr = size = offset = 0
        (filepath, basename) = os.path.split(filename)
        logging.debug('Do use the variable: %s', filepath)
        if basename not in self.files_mmap_dict:
            self.files_mmap_dict[basename] = {
                "filepath" : filename,
                "mmap" : [],
                "type" : None}
        with open(filename, 'rb') as f:
            for sect in ELFFile(f).iter_sections():
                if sect.header['sh_type'] == 'SHT_NULL':
                    continue
                if sect.name == '.text' or sect.name == b'.text':
                    addr = sect.header['sh_addr']
                    offset = sect.header['sh_offset']
                    size = sect.header['sh_size']
                    pid = self.DEFAULT_PID
                    tid = self.DEFAULT_TID
                    time = self.DEFAULT_TIME
                    logging.debug('Do use the variable: %d %d %s', pid, tid, time)
                    dict_op_set(self.files_mmap_dict,
                                [basename, 'mmap'],
                                [{"addr": addr, "offset": offset, "size": size}])
                    dict_op_set(self.files_mmap_dict,
                                [basename, 'type'],
                                ELFFile(f).header.e_type)
        if basename not in self.files_mmap_dict:
            logging.error("'%s' .text section not found", basename)

    def __load_all_mmap_info(self, fd, elf_path):
        if not os.path.exists(elf_path):
            os.mkdir(elf_path)
            return

        for entry in os.listdir(elf_path):
            file_path = os.path.join(elf_path, entry)
            if os.path.isdir(file_path):
                continue
            try:
                self.__load_file_mmap_info(file_path, fd)
            except ELFError:
                logging.error("'%s' format invalid, maybe not a elf file", file_path)
            except Exception as e:
                logging.error("'%s' analysis data failed: %s", file_path, str(e))
                raise e
            finally:
                logging.error('Execute finally clause')

    def __load_link_libraries(self, configfile):
        if not os.path.isfile(configfile):
            logging.info("link libraries config file not exist")
            return

        with open(configfile, 'r') as f:
            while True:
                line = f.readline()
                if not line:
                    break
                line = line.strip()
                if line is '' or line.startswith('#'):
                    continue

                if line[-1] == ':':
                    filename = line[:-1]
                    self.file_link_libraries_dict[filename] = {}
                else:
                    [soname, loadaddr] = line.split(' ')
                    dict_op_set(self.file_link_libraries_dict,
                                [filename, soname],
                                loadaddr)
            logging.info("load link libraries config file: %s", configfile)

    def generate_data(self):
        """
        Convert from a hongmeng sample.data to a linux perf.data
        """
        with open(self.sample_file, 'rb') as self.sample_data_fd:
            self.__read_sample_data()

        self.__update_system_info()
        self.__update_elf_load_info()
        self.__load_link_libraries(self.config_path)

        with os.fdopen(os.open(self.perf_data_file, os.O_CREAT | os.O_WRONLY, 0o600),
                       'wb') as self.perf_data_fd:
            self.__load_all_mmap_info(self.perf_data_fd, self.elf_dir)
            PerfData._generate_header_section(self.perf_data_fd)
            self.__generate_sample_events(self.perf_data_fd)


    @staticmethod
    def _print_dividing_line():
        """
        Print a dividing line
        """
        logging.info("=" * 100)

    def print_mmap_info(self):
        """
        Print the mmap info after conversion
        """
        PerfData._print_dividing_line()
        logging.info("Maps information: ")
        for (comm, entry) in self.process_mmap_info.items():
            logging.info('%s (pid: %d)', comm, entry['pid'])
            if entry["mmap"] is None:
                logging.info("  Not mmap information")
                continue
            for (filename, mmap_info) in sorted(entry["mmap"].items(),
                                                key=lambda d: d[1]["addr"],
                                                reverse=False):
                if mmap_info["addr"] == 0xFFFFFFFF:
                    logging.info(" - %-40s: Cannot not found file in elf directory", filename)
                else:
                    logging.info(" - %-40s: 0x%08x - 0x%08x (0x%08x/0x%08x) (%s)",
                                 filename,
                                 mmap_info["addr"],
                                 mmap_info["addr"] + mmap_info["size"],
                                 mmap_info["size"],
                                 mmap_info["offset"],
                                 "Found" if mmap_info["found"] else "Not found")

    def print_system_info(self):
        """
        Print the system info after conversion
        """
        PerfData._print_dividing_line()
        logging.info("System information: ")
        logging.info("  Sysname : %s\n  Nodename: %s\n  Release : %s\n"
              "  Version : %s\n  Machine : %s\n  Endian  : %s\n",
              self.sysname, self.nodename, self.release, self.version, self.machine,
              "little-endian" if self.little_endian else "big-endian")


def main():
    """
    The entry of conversion
    """
    logging.basicConfig(
            level=logging.INFO,
            format='[%(levelname)s] %(message)s')

    elf_dir = "elf"
    configfile = "config"
    sample_data_file = "sample.data"
    perf_data_file = "perf.data"

    parser = argparse.ArgumentParser(formatter_class=argparse.RawTextHelpFormatter)
    # By default, convert according to contents of file,
    # we provide a parameter to support remove stacks
    parser.add_argument('-g', '--no-stack', action='store_true', dest='nostack',
                        help="don't convert callchain stack")
    parser.add_argument("-l", "--little-endian", action='store_true', dest="little_endian",
                        help="parse sample data according to little endian")
    args = parser.parse_args()

    cwd = os.getcwd()
    elf_path = os.path.join(cwd, elf_dir)
    config_path = os.path.join(cwd, configfile)
    perfdata_info = {
            'elf_dir': elf_path,
            'config_path': config_path,
            'sample_file': sample_data_file,
            'perf_data': perf_data_file,
            'nostack': args.nostack,
            'little_endian': args.little_endian}
    perf_data = PerfData(perfdata_info)
    perf_data.generate_data()
    logging.info("Generate perf.data:")
    logging.info("Callchain stack : %s", ("Enable" if not args.nostack else "Disable"))
    logging.info("Endian mode     : %s",
                 ("Little-Endian" if args.little_endian else "Big-Endian"))
    logging.info("ELF files dir   : %s", elf_path)
    logging.info("Config file     : %s", config_path)
    logging.info("Sample file     : %s, num = %d", sample_data_file, perf_data.sample_num)
    logging.info("Output perf data: %s\n", perf_data_file)
    perf_data.print_mmap_info()
    perf_data.print_system_info()

if __name__ == '__main__':
    main()
