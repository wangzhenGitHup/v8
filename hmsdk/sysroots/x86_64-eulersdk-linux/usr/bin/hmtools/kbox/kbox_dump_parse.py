#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
# Author: Huawei OS Kernel Lab
# Create: Wed Jun 16 16:19:46 2021

"""
Description:

This script parses the raw data dumped from the kbox buffer
and print readable information.
Usage: ./kbox_dump_parse.py kboxdump.bin
"""

from __future__ import absolute_import

import struct
import argparse
import warnings
import functools
from enum import Enum, unique
from typing import List, BinaryIO, Callable, Iterable
from dataclasses import dataclass


def product(arr: Iterable):
    """Calculate product"""
    return functools.reduce(lambda x, y: x * y, arr, 1)


def bytes_to_str(byte_str: bytes) -> str:
    """Covert bytes to str"""
    return byte_str.strip(b'\x00').decode('ascii')


def hex_to_str(hex_val: int) -> str:
    """Covert hex to str"""
    return bytes.fromhex(f'{hex_val:x}').decode('ascii')


@unique
class Endian(Enum):
    """Enum class representing endian"""
    big    = 0
    little = 1


@dataclass
class _CType:
    size: int       # size in bytes
    specifier: str  # specifier for struct.unpack
    count: int = 1

    def unpack(self, data: BinaryIO, endian: Endian):
        """
        @assume data contains at least self.total_size bytes of data
        """
        endian_format = '<' if endian is Endian.little else '>'
        format_str = f'{endian_format}{self.count}{self.specifier}'
        parsed = struct.unpack(format_str, data.read(self.total_size))
        return parsed[0] if len(parsed) == 1 else parsed

    def __getitem__(self, count: int):
        """
        Utility to define data array
        @assume count > 0
        @return _CType or _ArrayCType
        """
        if self.count > 1:
            return _ArrayCType(self, count)
        else:
            return _CType(size=self.size, specifier=self.specifier, count=count)

    @property
    def total_size(self):
        """Return total bytes used by this type"""
        return self.size*self.count

    @total_size.setter
    def total_size(self, total_size):
        """
        @assume total_size > 0 and (total_size % self.size) == 0
        """
        self.count = total_size // self.size


@dataclass
class _ArrayCType:
    base_type: _CType
    count: int

    def unpack(self, data: BinaryIO, endian: Endian) -> list:
        """
        @assume data contains at least self.count * self.base_type bytes of data
        """
        return list(self.base_type.unpack(data, endian) for _ in range(self.count))

    def __getitem__(self, count: int):
        """
        @assume count > 0
        """
        return _ArrayCType(self, count)

    @property
    def total_size(self):
        """Return total bytes used by this type"""
        return self.base_type.total_size*self.count

    @total_size.setter
    def total_size(self, total_size):
        """
        @assume total_size > 0 and (total_size % self.size) == 0
        """
        self.count = total_size // self.base_type.total_size


@dataclass
class G:
    """
    Global variable wrapper class
    Used to circumvent pylint warning
    """
    KBOX_ALIGN = 1 << 12
    KBOX_REGION_NUM_MAX = 64
    KBOX_REGION_NAME_SIZE = 32

    uint32 = _CType(4, 'I')
    char = _CType(1, 's')


class Pipeable:
    """
    A wrapper around basic types for the ease of
    future process
    e.g.
    >>> x = Pipeable((1, 1, 2)) | list | set
    >>> print(x.get_value())  # {1, 2}
    """
    def __init__(self, value):
        self.value = value

    def get_value(self):
        """Return value after calculation"""
        return self.value

    def apply(self, op: Callable):
        """Apply a new op to value"""
        self.value = op(self.value)
        return self

    def apply_foreach(self, op: Callable):
        """Apply a series of op to value"""
        self.value = list(map(op, self.value))
        return self

    def __or__(self, op: Callable):
        return self.apply(op)


@dataclass
class _UnwrapMixin:
    """
    Automatically unwrap Pipeable if presented
    """
    def __post_init__(self):
        for key, val in self.__dict__.items():
            if isinstance(val, Pipeable):
                self.__dict__[key] = val.get_value()


@dataclass
class KBoxRegion(_UnwrapMixin):
    """
    A KBox device is composed of multiple regions
    This class represents a parsed kbox region
    """
    control_bits: int
    index: int
    content: str

    @property
    def used_size(self):
        """Returns used size (i.e. with data) of this region"""
        return len(self.content)

    @property
    def reserved_bit(self):
        """Returns this region's reserved bit"""
        return int(f'{self.control_bits:032b}'[0])

    @property
    def empty_flag(self):
        """
        KBox region is a ring buffer
        empty flag shoud be 0 before first-time turnaround
        and 1 afterwards
        """
        return int(f'{self.control_bits:032b}'[1])

    @property
    def sequence_num(self):
        """Returns this region's sequence num"""
        return int(f'{self.control_bits:032b}'[2:], base=2)


@dataclass
class KBoxDevice(_UnwrapMixin):
    """
    This class represents the parsed entire kbox device
    """
    magic: int
    endian: int
    size: int
    region_count: int
    region_names: List[str]
    region_sizes: List[int]


@dataclass
class KBox(_UnwrapMixin):
    """
    This class represents the parsed entire kbox device and regions
    """
    device: KBoxDevice
    regions: List[KBoxRegion]

    @property
    def free_size(self):
        """Returns free size among all regions of this kbox"""
        return self.device.size - sum(r.used_size for r in self.regions)


class KBoxParser:
    """
    This class is able to serialize kbox struct from raw data
    """
    def __init__(self, dump: BinaryIO):
        self.dump = dump
        # endian is little until the endian section is unpacked
        self.endian = Endian.little

    def parse(self) -> KBox:
        """Parse the entire kbox from raw data"""
        with self.bind_ctype_call_to(self.wrap_ctype_call()):
            device = self.parse_device()
            self.dump.seek(G.KBOX_ALIGN)
            regions = self.parse_regions(device)

        return KBox(device, regions)

    def parse_device(self) -> KBoxDevice:
        """Parse device from raw data"""
        def _update_endian(endian):
            self.endian = endian
            return endian
        uint32 = G.uint32
        char = G.char

        region_names_type = char[G.KBOX_REGION_NAME_SIZE][G.KBOX_REGION_NUM_MAX]
        try:
            device = KBoxDevice(
                magic=uint32() | hex_to_str,
                endian=uint32() | Endian | _update_endian,
                size=uint32(),
                region_count=uint32(),
                region_names=region_names_type()
                             .apply_foreach(bytes_to_str),
                region_sizes=uint32[G.KBOX_REGION_NUM_MAX]()
            )
        except struct.error:
            raise ValueError('Failed to parse device head')
        else:
            self.check_device(device)
        finally:
            pass
        return device

    def parse_regions(self, device: KBoxDevice) -> List[KBoxRegion]:
        """Parse regions froms a device data"""
        regions = []
        uint32 = G.uint32
        char = G.char
        for ind in range(device.region_count):
            # it is possible for the last region to
            # be smaller than declared
            allow_no_enough_data = ind == device.region_count - 1
            region_size = device.region_sizes[ind]

            try:
                if region_size <= uint32.size*2:
                    raise ValueError(f'region_size={region_size} smaller than '
                                     'region head size')
                region = KBoxRegion(
                    control_bits=uint32(),
                    index=uint32(),
                    content=char[region_size - uint32.size*2]
                            (allow_no_enough_data)
                            | bytes_to_str
                )
            except ValueError as err:
                warnings.warn(f'Corrupted region #{ind}. Error: {err}')
            except struct.error as err:
                warnings.warn(f'Failed to parse region #{ind}. Error: {err}')
            else:
                regions.append(region)
            finally:
                pass
        self.check_regions(regions, device)
        return regions

    @staticmethod
    def check_device(device: KBoxDevice):
        """Check wether parsed device is valid"""
        if device.magic != 'KBOX':
            warnings.warn(f'Wrong magic: "{device.magic}", expected: "KBOX"')
        if device.size == 0:
            warnings.warn(f'Wrong kbox total size: {device.size} Bytes')
        if device.region_count > G.KBOX_REGION_NUM_MAX:
            warnings.warn(f'Too many kbox regions: {device.region_count}'
                          f' (Max: {G.KBOX_REGION_NUM_MAX})')

        unused_name_area = device.region_names[device.region_count:]
        if sum(len(name) for name in unused_name_area) > 0:
            warnings.warn(f'Unexpected region name data: {unused_name_area}. '
                          'Should be all zero')

        unused_size_area = device.region_sizes[device.region_count:]
        if sum(unused_size_area) > 0:
            warnings.warn(f'Unexpected region size data: {unused_size_area}. '
                          'Should be all zero')

    @staticmethod
    def check_regions(regions: List[KBoxRegion], device: KBoxDevice):
        """Check wether parsed regions are valid"""
        if len(regions) != device.region_count:
            warnings.warn(f'Expected {device.region_count} regions, '
                          f'parsed {len(regions)}')

    @staticmethod
    def bind_ctype_call_to(func: Callable):
        """
        Define a context in which _CType.__call__ and
        _ArrayCType.__call__ can be customized
        i.e. able to call
        >>> with bind_ctype_call_to(foo):
        >>>     uint32() # will call foo
        """
        class BindCtx:
            """Context manager class for ctype call wrapping"""
            def __init__(self):
                self.original_calls = (None, None)

            def __enter__(self):
                self.original_calls = (_CType.__call__, _ArrayCType.__call__)
                _CType.__call__ = func
                _ArrayCType.__call__ = func

            def __exit__(self, err_type, err_value, traceback):
                _CType.__call__, _ArrayCType.__call__ = self.original_calls

        return BindCtx()

    def wrap_ctype_call(self):
        """
        Wrapper around _Ctype.unpack and _ArrayCType.unpack
        to achieve
        1. data length check
        2. partial call with parser's attribute
        3. wrap result to Pipeable for the ease of future adaption
        """
        def adapt_ctype_size(ctype_self, self):
            size = ctype_self.total_size
            data = self.dump.read(size)
            ctype_self.total_size = min(len(data), size)
            self.dump.seek(self.dump.tell() - len(data))

        def unpack(ctype_self, allow_no_enough_data=False):
            if allow_no_enough_data:
                adapt_ctype_size(ctype_self, self)
            ret = ctype_self.unpack(self.dump, self.endian)
            return Pipeable(ret)

        return unpack


class KBoxPrinter:
    """
    This class is able to print serialized kbox struct
    """
    def __init__(self, kbox: KBox):
        self.kbox = kbox

    def print(self, arg):
        """Pretty print a kbox"""
        if arg.region is None:
            self.print_device_info()
            target_regions = enumerate(self.kbox.regions)
        else:
            target_regions = (
                    (ind, region) for (ind, region) in
                    enumerate(self.kbox.regions) if
                    self.kbox.device.region_names[ind] == arg.region
            )

        found = False
        for ind, region in target_regions:
            found = True
            self.print_region_info(ind, region)
            if not arg.no_content:
                self.print_region_content(ind, region)

        if arg.region is not None and not found:
            print(f'Error: region "{arg.region}" not found')

    def print_device_info(self):
        """Pretty print a kbox device overall information"""
        dev = self.kbox.device
        print(f'--------- Device Info ---------')
        print(f'magic           {dev.magic}')
        print(f'endian          {dev.endian.name}')
        print(f'size            {dev.size:<10} Bytes')
        print(f'free            {self.kbox.free_size:<10} Bytes')
        print(f'region_count    {dev.region_count}')
        print()

    def print_region_info(self, ind, region: KBoxRegion):
        """Pretty print a kbox region overall information"""
        dev = self.kbox.device
        print(f'-------- Region #{ind} Info -------')
        print(f'name            {dev.region_names[ind]}')
        print(f'index           {region.index}')
        print(f'size            {dev.region_sizes[ind]:<10} Bytes')
        print(f'data            {region.used_size:<10} Bytes')
        print(f'control bits    {region.control_bits:032b}')
        print(f'reserved bit    {region.reserved_bit}')
        print(f'empty flag      {region.empty_flag}')
        print(f'sequence number {region.sequence_num}')
        print()

    @staticmethod
    def print_region_content(ind, region: KBoxRegion):
        """Dump the content of a kbox region"""
        print(f'------- Region #{ind} Content ------')
        print(region.content)
        print()


def get_args():
    """Parse user input arguments"""
    ap = argparse.ArgumentParser(description='Parse kbox dump data.')
    ap.add_argument('dumpfile', metavar='dumpfile',
                    help='Kbox memory dump file')
    ap.add_argument('-r', '--region', metavar='KBOX_REGION', action='store',
                    help='Specify kbox region to parse by name')
    ap.add_argument('-i', '--no-content', action='store_true',
                    help='Only show info, skip region content')
    return ap.parse_args()


def main():
    """Function entry point"""
    args = get_args()
    with open(args.dumpfile, 'rb') as dump:
        kbox = KBoxParser(dump).parse()
        KBoxPrinter(kbox).print(args)


if __name__ == '__main__':
    main()
