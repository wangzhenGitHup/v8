#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
# Author: Huawei OS Kernel Lab
# Create: Sun Apr 26 15:41:16 2020

#
# report_parser.py is used for parsing and symbolizing the utsan's raw print.
# If utsan finds a data race, it will output like:
#
#    [ERROR]................. DATA RACE................
#    [ERROR]
#    [ERROR]RaceInfo: idx: 1, addr: 0xc4e958, size: 4, tid0: 121, pc0: 0x4e2020,       tid1: 104, pc1: 0x4e2020, mode: ww-
#    [ERROR]
#    [ERROR]..............................................
#
# report_parser.py would accept runtime logs containing such outputs, extract the race and symbolize them
# according to the referenced source binary image, for example:
#     python3 report_parser.py a.log sysmgr.unstripped.elf
# will output three files: racexxx.raw.log, racexxx.src.log, race_submit.dat, with xxx being timestamp.
# In racexxx.raw.log file are the basic symbolized form of found races according to sysmgr.unstripped.elf, like:
#
#      'idx': '1', 'addr': '0xc4e958', 'size': '4', 'tid0': '121', 'tid1': '104',
#      'pc0': '0x4e2020', 'pc1': '0x4e2020',
#      'mode': 'ww',
#      'symbol_pc0_0x4e2020': '/home/abc/hm-yocto/build-aarch64/tmp/work-shared/hm-verif-kernel/git/sysmgr/security/prng_mecf.c:114\n',
#      'symbol_pc1_0x4e2020': '/home/abc/hm-yocto/build-aarch64/tmp/work-shared/hm-verif-kernel/git/sysmgr/security/prng_mecf.c:114\n'
#
# In racexxx.src.log are the source code info of found races, which is in fact used for uniquely identifing a race, like:
#
#     --- RACE 1,ww ---
#     hm-verif-kernel/git/sysmgr/security/prng_mecf.c:114, g_short_count++;
#     hm-verif-kernel/git/sysmgr/security/prng_mecf.c:114, g_short_count++;
#
# In race_submit.dat are the info needed for storing the race in database, such as signature.
#

import os, sys
import re
import subprocess
import hashlib
from datetime import datetime
import json

def LOG(*args):
    args = [str(i) for i in args]
    to_print = "".join(args)
    print(to_print)

def str_rebuilt(s, replace_list = []):
    s = " ".join(s.split())
    for rp in replace_list:
        s = s.replace(rp[0], rp[1])
    return s

def str_combine(*args, combiner = ""):
    args = [str(i) for i in args]
    s = ""
    for arg in args:
        s += (arg + combiner)
    return s

def parse_one_race(race_info):
    match = \
    re.search(r'RaceInfo: idx: (.*?), addr: (.*?), size: (.*?), tid.: (.*?), pc.: (.*?), tid.: (.*?), pc.: (.*?), mode: (..)', race_info, 0)

    if match is None or len(match.groups()) == 0:
        return None

    idx, addr, size, tid0, pc0, tid1, pc1, mode = match.groups()
    return {"idx": idx, "addr": addr, "size": size, "tid0": tid0, "tid1": tid1, "pc0": pc0, "pc1": pc1, "mode": mode}

def symbolize(race, src_img):
    pcs = ["pc0", "pc1"]
    for _ in pcs:
        pc = race[_]
        item = str_combine("symbol_", _, "_", pc)
        if "nil" in pc:
            race[item] = "NA"
        else:
            cmd = str_combine("addr2line -e ", src_img, " -a ", pc)
            p=subprocess.Popen(cmd,shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
            stdoutput,erroutput = p.communicate()
            if type(stdoutput) is bytes:
                stdoutput = stdoutput.decode("ascii")
            race[item] = stdoutput[stdoutput.find('/'):];

def parse_console(file, src_img):
    all_race = []
    output_buf = ""
    with open(file, "r") as f:
        lines = f.readlines()
        for l in lines:
            race = parse_one_race(l)
            if race is None:
                continue
            symbolize(race, src_img)
            all_race.append(race)
            output_buf += (str(race) + "\n")

    unique_file = unique_file_prefix + ".raw.log"
    latest_file = latest_file_prefix + ".raw.log"

    with open(unique_file, "w+") as f:
        f.write(output_buf)
        with open(latest_file, "w+") as f:
            f.write(output_buf)
            LOG("  *** races parsed from console log recorded locally into: ", unique_file, "\n, also in: ", latest_file)

    return all_race

def submit_races(races):
    def get_rel_name(file_longname):
        """
        file_longname: File path extracted from the elf debug info, which contains the developer's local path, for instance, /home/limo/.....
        file_shortname: File path containing only the repo's relative path, for instance, hm-verfif-kernel/....
        """
        repo_names = ["hm-verif-kernel", "hm-filesystems", "hm-network", "hm-test",
                    "hm-security", "hm-vendor-drivers", "hm-uvmm", "hm-3rdparty-modules"]
        name_pieces = file_longname.split("/")
        short_name = ""
        for i, p in enumerate(name_pieces):
            if p in repo_names:
                short_name = "/".join(name_pieces[i:])
                break
        return short_name

    def formalize_visual_info(elements):
        """
        To give users symbolized info of the race's source code'
        """
        visual_info = ""
        for ele in elements:
            visual_info = visual_info + \
                        str_combine(ele[0], ":", ele[1], ", ", ele[2], "\r\n")
        if (len(elements) == 1):
            visual_info = visual_info + "UNKOWN\r\n"
        return visual_info

    def formalize_sig_info(elements):
        """
        To generate signature used info. Regarless of th line number
        """
        sig_info = ""
        for ele in elements:
            sig_info = sig_info + \
                        str_combine(ele[0], " && ", ele[2])
        return sig_info

    def race_signature(r):
        elements = []
        for k in r:
            if type(r[k]) is bytes:
                r[k] = r[k].decode("ascii")
            if 'symbol_' not in k:
                continue

            file_line = str(r[k]).strip()
            res = re.search("(/.*?):([0-9]+)", file_line)
            if (res is None or len(res.groups()) != 2):
                continue

            file_name, line_num = res.groups()
            line_num = int(line_num)
            file_longname = os.path.abspath(file_name)
            file_shortname = get_rel_name(file_longname)

            if not os.path.exists(file_name):
                continue

            with open(file_name, "r") as f:
                lines = f.readlines()
                if (line_num < len(lines)):
                    line_code = str_rebuilt(str(lines[line_num - 1]))
                    elements.append([file_shortname, line_num, line_code])

        if len(elements) > 0:
            elements.sort()
            visual_info = formalize_visual_info(elements)

            sig_info = formalize_sig_info(elements)

            hl = hashlib.md5()
            hl.update(sig_info.encode(encoding='utf-8'))
            signature = hl.hexdigest()
            to_submit = {"signature": signature, "mode": r['mode'], "source_code": visual_info, "raw_info": r}

            # for local storage
            visual_info = str_combine("--- RACE ", r['idx'], ",", r['mode']," ---\r\n", visual_info)
            return to_submit, visual_info

        return None, None

    def submit_core(entries):
        """
        entries is an array of:
            [{"signature": xxx, "source_code": yyy, "raw_info": zzz}, ...]
        """
        with open("race_submit.dat", "w+") as f:
            f.write(json.dumps(entries))

    source_info = ""
    race_entries = []
    for r in races:
        sign_entry, source_code = race_signature(r)
        if sign_entry is not None:
            race_entries.append(sign_entry)
            source_info += str_combine(source_code, "\n")

    submit_core(race_entries)
    unique_file = unique_file_prefix + ".src.log"
    latest_file = latest_file_prefix + ".src.log"

    with open(unique_file, "w+") as f:
        f.write(source_info)
        with open(latest_file, "w+") as f:
            f.write(source_info)
            LOG("  *** races's source code info are recorded locally into: \n", unique_file, "\n, also in: \n", latest_file)


if __name__ == "__main__":
    now_time = str_rebuilt(str(datetime.now()), [[":", "-"], [" ", "-"], [".", "-"]])
    unique_file_prefix = "race" + now_time
    latest_file_prefix = "race_latest"

    if len(sys.argv) == 3:
        LOG("Mode>>>  parse raw console log\n");
        f = sys.argv[1]
        src_img = sys.argv[2]

        races = parse_console(f, src_img)
        submit_races(races)
        LOG(" >>> DONE <<< ")
    elif len(sys.argv) == 2:
        # input old races.log
        LOG("Mode>>>  parse race log\n");
        f = sys.argv[1]
        all_races = []
        with open(f, "r") as f:
            lines = f.readlines()
            for l in lines:
                l = l.replace("\\n", " ")
                l = l.strip()
                if l != "":
                    race = eval(l)
                    all_races.append(race)

            submit_races(all_races)
        LOG(" >>> DONE <<< ")
    else:
        LOG("Usage 1: parse.py console_log source_image")
        LOG("Usage 2: parse.py races.log")
        exit(0)
