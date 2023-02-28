#!/usr/bin/env python3
# -*- coding:UTF-8 -*-
# Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
# Description: Parse unknown symbol of stack backtrace in hguard/sysrq/snapshot log.
# Author: Huawei OS Kernel Lab
# Create: Wed Oct 16 17:58:08 2019

from __future__ import absolute_import

import subprocess
import argparse
import datetime
import time
import sys
import os
import re
import tempfile


class HMlogkitSystem:
    """ Record all args for hmlogkit, and provide interactive performance function. """

    def __init__(self):
        self.init_timezone()
        args = HMlogkitSystem.parse_args()
        self.build_log = "/dev/null"
        self.check_args(args)
        self.arch = args.arch
        self.arch_address_widths = 8 if self.arch == "arm" else 16
        self.elf_dir = args.elf_dir
        self.input_file = args.input_file
        self.output_file = args.output_file
        self.build_log = args.build_log
        self.init_build_log()

    def init_timezone(self):
        """ Set timezone. """
        utc_offset_s = -time.timezone
        if utc_offset_s >= 0:
            utc_offset_h = utc_offset_s // 60 // 60
            utc_offset_m = utc_offset_s // 60 % 60
            self.timezone_info = str("+%02d:%02d" % (utc_offset_h, utc_offset_m))
        else:
            utc_offset_h = -utc_offset_s // 60 // 60
            utc_offset_m = -utc_offset_s // 60 % 60
            self.timezone_info = str("-%02d:%02d" % (utc_offset_h, utc_offset_m))

    def fetch_current_time(self):
        """ Get str time with given timezone. """
        return time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()) + self.timezone_info

    def kit_assert(self, error_log, assertion):
        """ If the assertion is false, panic the script and exit. """
        if not assertion:
            self.kit_log("ERROR", error_log)
            sys.exit(1)

    def kit_log(self, log_level, log):
        """ Print log with different level. """
        with open(self.build_log, 'a') as build_log_f:
            timestamp = self.fetch_current_time()
            if log_level == "ERROR":
                # output error log to stderr and build_log
                sys.stderr.write("[%s][%s]%s\n" % (timestamp, log_level, log))
                build_log_f.write("[%s][%s]%s\n" % (timestamp, log_level, log))
            elif log_level == "WARN":
                # only output warning log to build_log
                build_log_f.write("[%s][%s]%s\n" % (timestamp, log_level, log))
            elif log_level == "INFO":
                # output info log to stdout and build_log
                sys.stdout.write("[%s][%s]%s\n" % (timestamp, log_level, log))
                build_log_f.write("[%s][%s]%s\n" % (timestamp, log_level, log))
            else:
                pass

    @classmethod
    def parse_args(cls):
        """ Set input argument. """
        parser = argparse.ArgumentParser(usage="Usage: python3 hmlogkit.py [options]")
        parser.add_argument("-d", metavar="elf-dir", dest="elf_dir",
            required=True, help="the elf directory")
        parser.add_argument("-i", metavar="input-log", dest="input_file",
            required=True, help="the file name of input-log")
        parser.add_argument("-o", metavar="output-log", dest="output_file",
            default="output-log", help="the file name of output-log")
        parser.add_argument("-a", metavar="arch", dest="arch",
            required=True, help="the arch of input-log: %s" % ("/".join(["arm", "aarch64"])))
        parser.add_argument("-c", metavar="compile-toolchain", dest="compile_toolchain",
            required=True, help="the prefix of compile toolchain")
        parser.add_argument("-l", metavar="build-log", dest="build_log",
            default="/dev/null", help="the file name of build-log")
        parser.add_argument("-t", metavar="utc-hours", dest="convert_timestamp",
            help="convert unix time to UTC, utc-hours is 8 if UTC+8")

        return parser.parse_args()

    def check_args(self, args):
        """ Check input argument. """
        # elf_dir should be appointed and existed
        self.kit_assert("Error: please specify an exist directory of elf file, exit",
                        os.path.isdir(args.elf_dir))

        # arch should be arm or aarch64
        self.kit_assert("Error: please specify a valid arch of input-log, %s, exit" %
                ("/".join(["arm", "aarch64"])), args.arch in ["arm", "aarch64"])

        # judge whether addr2line in PATH
        addr2line_flag = 0
        self.compile_toolchain = args.compile_toolchain
        self.addr2line = args.compile_toolchain + "addr2line"
        for cmdpath in os.environ['PATH'].split(':'):
            if os.path.isdir(cmdpath) and self.addr2line in os.listdir(cmdpath):
                addr2line_flag = 1
                break
        self.kit_assert("Error: %s may not set in environment variables, exit" % self.addr2line,
                        addr2line_flag)

        # input-log output-log build-log should be different
        args.input_file = os.path.abspath(args.input_file)
        args.output_file = os.path.abspath(args.output_file)
        args.build_log = os.path.abspath(args.build_log)

        self.kit_assert("Error: output-log should be different from input-log, exit",
                        os.path.normcase(args.input_file) != os.path.normcase(args.output_file))

        self.kit_assert("Error: input-log should be different from build-log, exit",
                        os.path.normcase(args.input_file) != os.path.normcase(args.build_log))

        self.kit_assert("Error: output-log should be different from build-log, exit",
                        os.path.normcase(args.output_file) != os.path.normcase(args.build_log))

        # judge whether input_file is existed
        self.kit_assert("Error: please specify an exist input-log, exit",
                        os.path.isfile(args.input_file))

        self.kit_assert("Error: the input-log is null, exit",
                        os.path.getsize(args.input_file))

        # judge whether output_file is directory or existed
        self.kit_assert("Error: please specify a valid file name of output-log",
                        not os.path.isdir(args.output_file))

        self.kit_assert("Error: please specify a file of build-log instead of existed directory",
                        not os.path.isdir(args.build_log))

        # get local timezone info
        if args.convert_timestamp:
            try:
                if int(args.convert_timestamp) > 12 or int(args.convert_timestamp) < -12:
                    self.kit_assert("Error: utc hours needs to be within [-12, 12]", False)
                self.convert_timestamp = int(args.convert_timestamp)
            except ValueError:
                self.kit_assert("Error: utc hours needs to be within [-12, 12]", False)
            finally:
                pass
        else:
            self.convert_timestamp = sys.maxsize

    def kit_log_to_file(self, log_level, log):
        """ Print log to build log file. """
        with open(self.build_log, 'a') as build_log_f:
            timestamp = self.fetch_current_time()
            build_log_f.write("[%s][%s]%s" % (timestamp, log_level, log))

    def convert_unixtime2utc(self, line):
        """ Convert unix time to utc. """
        # valid timestamp format: [SS.ffffff]
        ts_list = re.findall(r'\[(\d+\.\d{6})\]', line)
        ts_dict = {i : datetime.datetime.fromtimestamp(float(i),
                    datetime.timezone(datetime.timedelta(hours=self.convert_timestamp)))\
                    .strftime("%Y-%m-%d %H:%M:%S-%f")
                    for i in ts_list}
        for old, new in ts_dict.items():
            line = line.replace('[' + old + ']', '[' + new + ']')
        return line

    def init_build_log(self):
        """ Print basic arg information in build log. """
        with open(self.build_log, 'w') as build_log_f:
            timestamp = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()) + self.timezone_info
            log_level = "INFO"
            build_log_f.write("[%s][%s]arguments list of hmlogkit:\n" % (timestamp, log_level))
            build_log_f.write("[%s][%s]arch: %s\n" % (timestamp, log_level, self.arch))
            build_log_f.write("[%s][%s]elf-dir: %s\n" % (timestamp, log_level,
                              os.path.abspath(self.elf_dir)))
            build_log_f.write("[%s][%s]input-log: %s\n" % (timestamp, log_level,
                              os.path.abspath(self.input_file)))
            build_log_f.write("[%s][%s]output-log: %s\n" % (timestamp, log_level,
                              os.path.abspath(self.output_file)))
            build_log_f.write("[%s][%s]build-log: %s\n" % (timestamp, log_level,
                              os.path.abspath(self.build_log)))
            build_log_f.write("[%s][%s]compile-toolchain: %s\n" % (timestamp, log_level,
                              self.compile_toolchain))
            build_log_f.write("[%s][%s]utc-hours: %d\n" % (timestamp, log_level,
                              self.convert_timestamp))

    def cut_input_file(self):
        """ Cut input file to files by some specfic string. """
        curr_file_num = 1
        tmp_input_file = "hmlogkit.input." + str(curr_file_num)
        tmp_input_file_list = {}

        with open(self.input_file, 'r', errors='ignore') as input_f:
            for line in input_f.readlines():
                if "Enter into elfloader" in line or "[transaction end]" in line:
                    curr_file_num = curr_file_num + 1
                    tmp_input_file = ''.join(["hmlogkit.input.", str(curr_file_num)])
                if tmp_input_file not in tmp_input_file_list:
                    tmp_input_file_list[tmp_input_file] = [line]
                else:
                    tmp_input_file_list.get(tmp_input_file).append(line)
        return tmp_input_file_list


def make_unstripped_elf(elf_file_name):
    """ Fetch a elf_file's unstripped version name. """
    if elf_file_name.endswith(".elf"):
        return "%s%s" % (elf_file_name[:-3], "unstripped.elf")
    elif elf_file_name.find(".so") != -1:
        return "%s%s" % (elf_file_name[:elf_file_name.find(".so")], ".unstripped.so")
    else:
        return ""


def find_file(file_dir, mode, file_name):
    """ Find all file with the name in dir. """
    file_list = []
    for root, _, files in os.walk(file_dir):
        if file_name in files:
            abs_file_path = os.path.join(root, file_name)
            stdout = tempfile.TemporaryFile("wb+")
            subprocess.call(['readelf', '-h', abs_file_path], stdout=stdout)
            stdout.seek(0, 0)
            if mode in str(stdout.read()):
                file_list.append(abs_file_path)
            stdout.close()
    return file_list


class SymbolParser:
    """ Parse raw log file and write back to output file. """

    def __init__(self, tmp_input_file, output_f, logkit):
        self.tmp_input_file = tmp_input_file
        self.output_f = output_f
        self.logkit = logkit
        self.tag_list = {}
        self.process_elf_load_info = {}
        self.elf_file_dict = {"ELF32" : {}, "ELF64" : {}}

    def update_process_elf_load_info(self, key, info):
        """ Update elf load info in a class-dict. """
        if key not in self.process_elf_load_info:
            self.process_elf_load_info[key] = [info]
        else:
            self.process_elf_load_info.get(key).append(info)

    def collect_elf_load_info(self):
        """ Collect elf load info with base, size, elf_type and name. """
        tag = ""
        key = ""
        sub_header = ""
        sub_item = ""
        header = re.compile("\[(\S{2}_[0-9a-f]{2})\]Elf load info \(pname=(.*), pid=(\d+)\):")

        for line in self.tmp_input_file:
            if line == '\n':
                continue
            if not key:
                mat = header.search(line)
                if mat:
                    tag = mat.group(1)
                    pid = mat.group(3)
                    sub_header = re.compile("\[%s\][\ ]+base[\ ]+size[\ ]+elf_type[\ ]+name" % tag)
                    sub_item = re.compile("\[%s\] ([0-9a-f]+) ([0-9a-f]+) (ET_\S+) +(\S+)" % tag)
                    key = "%s.%s" % (pid, tag)
                continue
            mat = sub_header.search(line)
            if not mat:
                mat = sub_item.search(line)
                if mat:
                    base = int(mat.group(1), 16)
                    size = int(mat.group(2), 16)
                    elf_type = mat.group(3)
                    name = mat.group(4)
                    self.update_process_elf_load_info(key, (base, size, elf_type, name))
                else:
                    key = ""

    def dump_parsed_elf_load_info(self):
        """ Dump the elf load info in build log. """
        width = self.logkit.arch_address_widths
        log = "Dump parsed \"Elf load info\":\n"
        for key in self.process_elf_load_info:
            log = "%s%s:\n" % (log, key)
            log = "%s %0*s %08s %-8s %s\n" % (log, width, "base", "size", "elf_type", "name")
            for base, size, elf_type, name in self.process_elf_load_info.get(key):
                log = "%s %0*x %08x %-8s %s\n" % (log, width, base, size, elf_type, name)
        self.logkit.kit_log_to_file("INFO", log)

    def lookup_symbol(self, elf_file_name, elf_mode, unloaded_addr):
        """ Use addr2line to lookup symbol with addr. """
        elf_file_name = elf_file_name.split("/")[-1]
        unloaded_addr = hex(unloaded_addr)

        # find the elf file in elf_file_dict first to improve the search efficiency
        if elf_mode in self.elf_file_dict and elf_file_name in self.elf_file_dict.get(elf_mode):
            elf_file_list = self.elf_file_dict.get(elf_mode).get(elf_file_name)
        else:
            # find the elf file in elf_dir
            elf_file_list = find_file(self.logkit.elf_dir, elf_mode, elf_file_name)

        if len(elf_file_list) == 0:
            self.logkit.kit_log("WARN", "can not find %s %s binary file" % (elf_mode,
                                elf_file_name))
            return "???"

        for elf_file in elf_file_list:
            stdout = tempfile.TemporaryFile("wb+")
            stderr = tempfile.TemporaryFile("wb+")
            addr2line_ret = subprocess.call([self.logkit.addr2line, unloaded_addr, '-e', \
                                            elf_file, '-f'], stdout=stdout, stderr=stderr)
            stdout.seek(0, 0)
            stderr.seek(0, 0)
            if addr2line_ret == 0:
                symbol = str(stdout.read()).split("\'")[1].split("\\")[0]
                if elf_mode in self.elf_file_dict and symbol not in ["??", "$a", "$d"]:
                    # store elf_file in elf_file_dict
                    self.elf_file_dict.get(elf_mode)[elf_file_name] = [elf_file]
                    return symbol
            else:
                err_log = str(stderr.read()).split("\'")[1].split("\\")[0]
                if err_log:
                    self.logkit.kit_log("WARN", err_log)
            stdout.close()
            stderr.close()

        # if there is no symbol for the given addr, just set the symbol as ???
        return "???"

    def parse_unknown_symbol_for_addr(self, process_info, loaded_addr, origin_line):
        """ Judge which elf the addr belong to and try some different-name elf. """
        server_pid, tag, mode = process_info
        key = str(server_pid) + "." + str(tag)
        if key not in self.process_elf_load_info:
            self.output_f.write(origin_line)
            return
        for base, size, elf_type, elf_file_name in self.process_elf_load_info.get(key):
            if not(loaded_addr >= base and loaded_addr <= base + size):
                continue
            unloaded_addr = loaded_addr - (base if elf_type in ("ET_DYN", "ET_REL") else 0)
            symbol = "???"
            unstripped_elf_file_name = make_unstripped_elf(elf_file_name)

            # use unstripped elf
            if len(unstripped_elf_file_name) > 0:
                symbol = self.lookup_symbol(unstripped_elf_file_name, mode, unloaded_addr)
                if symbol != "???":
                    origin_line = origin_line.replace("???", symbol, 1).replace("(???)",
                                "(%s)" % unstripped_elf_file_name, 1)
                    break

            #use origin elf
            symbol = self.lookup_symbol(elf_file_name, mode, unloaded_addr)
            if symbol != "???":
                origin_line = origin_line.replace("???", symbol, 1).replace("(???)",
                            "(%s)" % elf_file_name, 1)
                break

            #try to use ko elf
            if elf_type == "ET_REL":
                symbol = self.lookup_symbol("%s%s" % (elf_file_name, ".ko"), mode, unloaded_addr)
                if symbol != "???":
                    origin_line = origin_line.replace("???", symbol, 1).replace("(???)",
                                "(%s)" % ("%s%s" % (elf_file_name, ".ko")), 1)
                    break

            break

        self.output_f.write(origin_line)

    def parse_tmp_input_file(self):
        """ Entry to parse input file. """
        mode = ""
        self.collect_elf_load_info()
        self.dump_parsed_elf_load_info()

        # read the tmp input file line by line
        for line in self.tmp_input_file:
            if self.logkit.convert_timestamp != sys.maxsize:
                line = self.logkit.convert_unixtime2utc(line)

            # acquire the server process pid and store in tag_list
            if "Stack backtrace (pname=" in line:
                tag = line.split("[")[-1].split("]")[0]
                server_pid = line.split("=")[-1].split(")")[0]
                self.tag_list[tag] = [server_pid]

            # judge whether the line need to be parsed
            if "<???+0x0/0x0> (???)" not in line:
                self.output_f.write(line)
                continue

            tag = line.split("[")[-3].split("]")[0]
            if tag not in self.tag_list:
                self.output_f.write(line)
                continue

            server_pid = self.tag_list.get(tag)[0]
            loaded_addr_str = line.split("[")[-2].split("]")[0]
            if len(loaded_addr_str) == 8:
                mode = "ELF32"
            else:
                mode = "ELF64"
            loaded_addr = int(loaded_addr_str, 16)
            self.parse_unknown_symbol_for_addr((server_pid, tag, mode), loaded_addr, line)


def main():
    """ Entry of the script. """
    logkit = HMlogkitSystem()
    logkit.kit_log("INFO", "Start to parse symbol for: %s" % logkit.input_file)
    tmp_input_file_list = logkit.cut_input_file()

    # create output_file
    with open(logkit.output_file, 'w') as output_f:
        curr_file_num = 1
        while True:
            tmp_input_file = ''.join(["hmlogkit.input.", str(curr_file_num)])
            if tmp_input_file in tmp_input_file_list:
                parser = SymbolParser(tmp_input_file_list.get(tmp_input_file), output_f, logkit)
                parser.parse_tmp_input_file()
            else:
                break

            curr_file_num = curr_file_num + 1

    logkit.kit_log("INFO", "Finish, the output file is: %s" % logkit.output_file)
    sys.exit(0)


if __name__ == "__main__":
    main()
