#!/usr/bin/env python3
# coding:utf-8
# Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
# Author: Huawei OS Kernel Lab
# Create: Fri Jul 24 10:03:00 2020
"""
Usage:
python ./proptytool.py --f ./manifest.txt --e ./bootimage.elf --o ./bootimage.elf.prop
default manifest is supportted when input parameter is "--f default"
default integrity parameter is supportted when input is "--e default"
"""
from __future__ import absolute_import
import struct
import os
import stat
import hashlib
import argparse


class ProptHeader:
    """property header"""
    def __init__(self, data):
        """init function"""
        unpacked_data             = struct.Struct('<16s5I').unpack(data) # little endian
        self.unpacked_data        = unpacked_data
        self.hmp_magic            = unpacked_data[0]
        self.hmp_version          = unpacked_data[1]
        self.hmp_header_size      = unpacked_data[2]
        self.hmp_segtable_itemsz  = unpacked_data[3]
        self.hmp_segtable_itemnum = unpacked_data[4]
        self.hmp_prop_total_sz    = unpacked_data[5]

    def print_propt_header(self):
        """print property header"""
        print("==ProptHeader ATTRIBUTE / VALUE==")
        for attr, value in self.__dict__.items():
            print(attr, value)
        print("==================================\n")

    def get_packed_propt_header(self):
        """get packed property header"""
        values = [self.hmp_magic,
                  self.hmp_version,
                  self.hmp_header_size,
                  self.hmp_segtable_itemsz,
                  self.hmp_segtable_itemnum,
                  self.hmp_prop_total_sz
                 ]
        return struct.Struct('<16s5I').pack(*values)


class ProptSegtableItem:
    """property segment table item"""
    def __init__(self, data):
        """init function"""
        unpacked_data               = struct.Struct('<4I').unpack(data)
        self.ntype                  = unpacked_data[0]
        self.dtype                  = unpacked_data[1]
        self.propty_value_size    = unpacked_data[2]
        self.propty_value_offset  = unpacked_data[3]

    def print_propt_segtable_item(self):
        """print property seg table item"""
        print("--ProptSegtableItem ATTRIBUTE / VALUE--")
        for attr, value in self.__dict__.items():
            print(attr, value)
        print("-----------------------------------------")

    def get_packed_propt_segtable_item(self):
        """get packed property seg table item"""
        values = [self.ntype,
                  self.dtype,
                  self.propty_value_size,
                  self.propty_value_offset
                 ]
        return struct.Struct('<4I').pack(*values)


class ProptSegdata:
    """property segment data"""
    def __init__(self):
        """init function"""
        self.list = []
        self.fmtStr = '<' # little endian, none native
        self.data_len = 0 # bytes

    def print_propt_segdata(self):
        """print property seg data"""
        print("==ProptSegdata ATTRIBUTE / VALUE==")
        for attr, value in self.__dict__.items():
            print(attr, value)
        print("==================================\n")

    def get_packed_propt_segdata(self):
        """get packed property seg data"""
        if len(self.list) is 0:
            return 0
        fmt = struct.Struct(self.fmtStr)
        if len(fmt.pack(*self.list)) != self.data_len:
            return 0
        return fmt.pack(*self.list)

    def add_propt_segdata(self, listmem, addfmt, data_len):
        """add property seg data"""
        print("##ProptSegdata Add fmt(%s),listmem(%s),len(%d)##\n" % (addfmt, listmem, data_len))
        if isinstance(listmem, list):
            self.list.extend(listmem)
        else:
            self.list.append(listmem)
        self.fmtStr = self.fmtStr + addfmt
        self.data_len = self.data_len + data_len


class ProptData:
    """serial func for get info of data strcuture"""
    def __init__(self, file_header, segdata):
        """init function"""
        # property data type dict {key : value}
        self.propty_datatype = {
            "uchar" : [0, 1, 'B'],  # enum number, size, format
            "int32" : [1, 4, 'i'],
            "uint32" : [2, 4, 'I'],
            "int64" : [3, 8, 'q'],
            "uint64" : [4, 8, 'Q'],
            "bool" : [5, 1, 'B'],
            "string" : [6, 0, ''],  # unfixed length
            "binary" : [7, -1, ''], # unfixed length
        }
        # property name type dict {key : value}
        self.propty_nametype = {
            "system_service": 0,
            "sync_reclaimable": 1,
            "debuggable": 2,
            "integrity" : 3,
            "killable" : 4,
            "coredump" : 5,
            "root_fs" : 6,
            "stoppable" : 7,
        }
        # global segment table Items list
        self.segtable_item = []
        self.file_header = file_header
        self.segdata = segdata

    def get_data_type(self, datatype):
        """get data type"""
        if datatype in self.propty_datatype:
            return self.propty_datatype.get(datatype)[0]
        else:
            raise AssertionError(datatype)


    def get_data_size(self, datatype, data_len):
        """get data size"""
        if datatype in self.propty_datatype:
            if self.propty_datatype.get(datatype)[1] > 0:
                return self.propty_datatype.get(datatype)[1]
            elif self.propty_datatype.get(datatype)[1] == 0: # string
                return data_len
            else:                                  # binary
                return data_len // 2 - 1
        else:
            raise AssertionError(datatype)


    def get_data_fmt(self, datatype, data_len):
        """get data fmt"""
        if datatype in self.propty_datatype:
            if self.propty_datatype.get(datatype)[1] > 0:
                return self.propty_datatype.get(datatype)[2]
            elif self.propty_datatype.get(datatype)[1] == 0: # string
                return str(data_len) + 's'
            else:                                  # binary
                return str(data_len // 2 - 1) + 'B'
        else:
            raise AssertionError(datatype)

    # parsing binary data on format of hex
    @staticmethod
    def get_binary_data(string):
        """get binary data"""
        if string[0 : 2] == '0x' or string[0 : 2] == '0X':
            raise AssertionError(string)
        _str = string[2 :]
        values = []
        for i in range(len(_str), 0, -2):
            if (i - 2) < 0:
                values.append(int(_str[0 : i], 16))
            else:
                values.append(int(_str[i - 2 : i], 16))
        values.reverse()
        return values

    def get_data_by_str(self, datatype, string):
        """get binary data by string"""
        if datatype in self.propty_datatype:
            if self.propty_datatype.get(datatype)[1] > 0:
                if datatype == 'bool':
                    return string == 'true'
                else:
                    return int(string)
            elif self.propty_datatype.get(datatype)[1] == 0: # string
                string = string + '\0'
                return string.encode('utf-8')
            else:                                  # binary
                return self.get_binary_data(string)
        else:
            raise AssertionError(datatype)

    def get_name_type(self, namestr):
        """get name type"""
        if namestr in self.propty_nametype:
            return self.propty_nametype.get(namestr)
        else:
            raise AssertionError(namestr)

    def parse_prop_line(self, line):
        """parse property line"""
        line = line.strip()
        if len(line) == 0:
            return # ignore blank line
        factor = line.decode().split(':', 2)
        self.file_header.hmp_segtable_itemnum = self.file_header.hmp_segtable_itemnum + 1
        # create ProptSegtableItem according to factor
        lenth = self.get_data_size(factor[1], len(factor[2]) + 1)
        values = [self.get_name_type(factor[0]),
            self.get_data_type(factor[1]), lenth, self.segdata.data_len]
        segtable_item = ProptSegtableItem(struct.pack('<4I', *values))
        # for debug
        segtable_item.print_propt_segtable_item()
        # append self.segtable_item
        self.segtable_item.append(segtable_item)
        # fill ProptSegdata data
        fmt = self.get_data_fmt(factor[1], len(factor[2]) + 1)
        data = self.get_data_by_str(factor[1], factor[2])
        self.segdata.add_propt_segdata(data, fmt, lenth)

    def read_prop_file(self, manifest_file):
        """read manifest file"""
        if manifest_file == "default": # not need manifest
            return
        flags = os.O_RDONLY | os.O_CREAT
        modes = stat.S_IWUSR | stat.S_IRUSR
        with os.fdopen(os.open(manifest_file, flags, modes), "rb") as f:
            lines = f.readlines()
        for line in lines:
            self.parse_prop_line(line)

    def supply_hash_prop(self, filepath):
        """supply hash property"""
        if filepath == "default": # not need hash property
            return
        # get hash value
        extracted_file_size = os.path.getsize(filepath)
        hash_op = hashlib.sha256()
        flags = os.O_RDONLY | os.O_CREAT
        modes = stat.S_IWUSR | stat.S_IRUSR
        with os.fdopen(os.open(filepath, flags, modes), "rb") as extracted_file:
            hash_op.update(extracted_file.read(extracted_file_size))
        hex_hash_str = hash_op.hexdigest()
        # modify hmp_segtable_itemnum on header and create ProptSegtableItem
        self.file_header.hmp_segtable_itemnum = self.file_header.hmp_segtable_itemnum + 1
        values = [self.get_name_type("integrity"),
            self.get_data_type("binary"), 32, self.segdata.data_len]
        segtable_item = ProptSegtableItem(struct.pack('<4I', *values))
        # for debug
        segtable_item.print_propt_segtable_item()
        self.segtable_item.append(segtable_item)
        # fill ProptSegdata data
        data = []
        for i in range(0, len(hex_hash_str), 2):
            data.append(int(hex_hash_str[i : i + 2], 16))
        self.segdata.add_propt_segdata(data, "32B", 32)

    def generate_binary_file(self, filepath):
        """generate Binary File"""
        # recorrect self.segtable_item offset
        offset = self.file_header.hmp_header_size + \
            self.file_header.hmp_segtable_itemsz * len(self.segtable_item)
        self.file_header.hmp_prop_total_sz = offset + self.segdata.data_len
        flags = os.O_WRONLY | os.O_CREAT
        modes = stat.S_IWUSR | stat.S_IRUSR
        with os.fdopen(os.open(filepath, flags, modes), "wb") as fp:
            fp.write(self.file_header.get_packed_propt_header())
            for item in self.segtable_item:
                item.propty_value_offset = item.propty_value_offset + offset
                fp.write(item.get_packed_propt_segtable_item())
            fp.write(self.segdata.get_packed_propt_segdata())

    @staticmethod
    def generate_data(generate_f):
        """generate data, using sha256 hash value replace sign"""
        extracted_file_size = os.path.getsize(generate_f)
        hash_op = hashlib.sha256()
        flags = os.O_RDONLY | os.O_CREAT
        modes = stat.S_IWUSR | stat.S_IRUSR
        with os.fdopen(os.open(generate_f, flags, modes), "rb") as extracted_file:
            hash_op.update(extracted_file.read(extracted_file_size))
        hex_hash_str = hash_op.hexdigest()
        data = []
        for i in range(0, len(hex_hash_str), 2):
            data.append(int(hex_hash_str[i : i + 2], 16))
        flags = os.O_WRONLY | os.O_APPEND | os.O_CREAT
        with os.fdopen(os.open(generate_f, flags, modes), "ab") as fp:
            fp.write(struct.Struct('<32B').pack(*data))


def main():
    """create global Object"""
    default_header_values = ['HMP0000000000000'.encode('utf-8'), 1, 36, 16, 0, 0] # default header
    file_header = ProptHeader(struct.pack('<16s5I', *default_header_values))
    segdata = ProptSegdata()
    # debug
    file_header.print_propt_header()
    # parse inout parameter
    parser = argparse.ArgumentParser(description="parse")
    parser.add_argument("--f", type=str, help="manifest file")
    parser.add_argument("--o", type=str, help="generate file")
    parser.add_argument("--e", type=str, help="extracted file")
    args = parser.parse_args()

    manifest_f = args.f
    generate_f = args.o
    extracted_f = args.e

    propdata = ProptData(file_header, segdata)
    propdata.read_prop_file(manifest_f)
    propdata.supply_hash_prop(extracted_f)
    propdata.generate_binary_file(generate_f)
    propdata.generate_data(generate_f)


if __name__ == '__main__':
    main()
