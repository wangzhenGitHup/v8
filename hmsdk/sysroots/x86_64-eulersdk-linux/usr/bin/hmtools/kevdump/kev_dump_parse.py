#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
# Description: Parses the raw data dumped from the kev buffer
# Author: Huawei OS Kernel Lab
# Create: Fri Feb 28 16:19:46 2020

from __future__ import absolute_import

import sys
import os
import argparse
import warnings
import struct
from enum import Enum, unique
from argparse import RawTextHelpFormatter


@unique
class EndianType(Enum):
    """ endian type, same as `enum kevdump_endian_type` """
    big    = 0
    little = 1

    @classmethod
    def type_of_value(cls, type_val):
        """ endian type of value """
        for _type in cls:
            if _type.value == type_val:
                return _type
        return None


@unique
class KevMagicType(Enum):
    """ kev magic type """
    kevdump = 0
    kevraw = 1


@unique
class KevType(Enum):
    """ kev type """
    sched_switch       = 0
    block              = 1
    unblock            = 2
    syscall            = 3
    pagefault          = 4
    irq                = 5
    klog               = 7
    tailcall           = 8
    kpreempt           = 9
    fiq                = 10
    sched_migrate_task = 11
    trap_el2           = 13
    el2_log            = 14
    vcpu_exit          = 15
    vcpu_enter         = 16
    el2_irq            = 17
    last               = 18
    invalid_type       = 0xFFFE
    region_separator   = 0xFFFF

    @classmethod
    def is_support_event(cls, type_val):
        """ support event """
        for _type in cls:
            if _type.value == type_val:
                return True
        return False

    @classmethod
    def type_of_value(cls, type_val):
        """ get type from kev type value """
        for _type in cls:
            if _type.value == type_val:
                return _type
        return None

    @classmethod
    def type_of_name(cls, name):
        """ get type from kev type name """
        for _type in cls:
            if _type.name == name:
                return _type
        return None

    @classmethod
    def print_support_events(cls):
        """ support events """
        for _type in cls:
            print(_type.name)

    @classmethod
    def events_name_list(cls):
        """ events name lists """
        return [_type.name for _type in cls]


class KevParser:
    """ kev parser """
    # sizeof(struct ring_buffer_s) is 88
    ringbuffer_headsize = 88
    NULL_CHAR = b'\x00'.decode('ascii')
    __NSEC_PER_SEC = 1000000000
    __NSEC_PER_USEC = 1000

    evt_fmt_dict = {
            KevType.sched_switch       : 'I64s64s2I2Q2IQ',
            KevType.block              : 'I64sI',
            KevType.unblock            : 'I64sI',
            KevType.syscall            : '3I',
            KevType.pagefault          : 'I2Q',
            KevType.irq                : '3IQ',
            KevType.tailcall           : '2I',
            KevType.kpreempt           : '2I',
            KevType.fiq                : '2I',
            KevType.trap_el2           : 'I4Qq2Q',
            # According to the data structures of kev_sched_migrate_task_s,
            # there will be a 4-bytes padding after the member of dest_cpu
            KevType.sched_migrate_task : 'I64sQ4I',
            # According to the data structures of kev_header_s and kev_vcpu_exit_s,
            # there will be a 1-byte padding after the reason member of kev_vcpu_exit_s.
            KevType.vcpu_exit          : '2I3B8scQq2Q',
            # According to the data structures of kev_vcpu_enter_s,
            # there will be a 3-bytes padding after the reason member of kev_vcpu_enter_s.
            KevType.vcpu_enter         : '2IB8s3cQq3Q',
            KevType.el2_irq            : 'IQq2Q',
        }

    @classmethod
    def get_param_of_evt_fmt(cls, fmt, evt_fmt):
        """ get each evt data fmt and size """
        evt_fmt = fmt + evt_fmt
        return (evt_fmt, struct.calcsize(evt_fmt))

    def __fmt_init(self, fmt):
        self.fmt_dict = {
            i : KevParser.get_param_of_evt_fmt(fmt, self.evt_fmt_dict.get(i)) \
                for i in self.evt_fmt_dict
        }
        self.fmt_dict[KevType.klog] = (None, 0, self.__fmt_klog)
        self.fmt_dict[KevType.el2_log] = (None, 0, self.__fmt_el2_log)

    def __init__(self, endian):
        self.header_evt_size_mask = (1 << 12) - 1
        self.header_evt_type_mask = (1 << 12) - 1
        self.header_cpuid_mask = (1 << 8) - 1
        self.endian_type = endian
        if endian is EndianType.little:
            pre_fmt = '<'
            self.header_evt_size_shift = 0
            self.header_evt_type_shift = 12
            self.header_cpuid_shift = 24
        else:
            pre_fmt = '>'
            self.header_evt_size_shift = 20
            self.header_evt_type_shift = 8
            self.header_cpuid_shift = 0

        self.__fmt_init(pre_fmt)
        self.head_fmt = pre_fmt + 'I'
        self.head_size = struct.calcsize(self.head_fmt)

        self.parse_func_dict = {
            KevType.sched_switch       : self.__parse_sched_switch,
            KevType.block              : self.__parse_block,
            KevType.unblock            : self.__parse_unblock,
            KevType.syscall            : self.__parse_syscall,
            KevType.pagefault          : self.__parse_pagefault,
            KevType.irq                : self.__parse_irq,
            KevType.klog               : self.__parse_klog,
            KevType.tailcall           : self.__parse_tailcall,
            KevType.kpreempt           : self.__parse_kpreempt,
            KevType.fiq                : self.__parse_fiq,
            KevType.trap_el2           : self.__parse_trap_el2,
            KevType.vcpu_exit          : self.__parse_vcpu_exit,
            KevType.vcpu_enter         : self.__parse_vcpu_enter,
            KevType.el2_irq            : self.__parse_el2_irq,
            KevType.el2_log            : self.__parse_el2_log,
            KevType.sched_migrate_task : self.__parse_sched_migrate_task,
        }

    @classmethod
    def tock_to_nanoseconds(cls, tock, tock_start, freq):
        """ tock to nanoseconds """
        nsec = 0
        pure = tock - tock_start
        if freq != 0:
            nsec = (pure * cls.__NSEC_PER_SEC) // freq
        return nsec

    @classmethod
    def nsec_to_timestamp(cls, nsec):
        """ nsec to timestamp """
        sec = nsec // cls.__NSEC_PER_SEC
        usec = (nsec % cls.__NSEC_PER_SEC) // cls.__NSEC_PER_USEC
        timestamp = "{:d}.{:06d}".format(sec, usec)
        return timestamp

    @classmethod
    def create_separator(cls, index, size):
        """ add a separator between different ringbuffers """
        evt = {}
        _type = KevType.region_separator
        evt['index'] = index
        evt['size'] = size
        evt = {'head' : None, 'type' : _type, 'data' : evt}
        return [evt]

    @classmethod
    def __fmt_klog(cls, head):
        fmt = None
        header_size = 12 # sizeof(struct kev_klog_s)
        if head['evt_size'] >= header_size:
            logsize = head['evt_size'] - header_size
            fmt = '2I' + '%ds' % logsize
        return fmt

    @classmethod
    def __fmt_el2_log(cls, head):
        fmt = None
        header_size = 4 # sizeof(kev_header_s)
        if head['evt_size'] >= header_size:
            logsize = head['evt_size'] - header_size
            fmt = '%ds' % logsize
        return fmt

    @classmethod
    def __parse_log(cls, log):
        evt = {}
        align_size = 4
        size = len(log)

        # obtain the last 4 bytes of the log and
        # find the first '\0' as the end.
        start_pos = max(0, size - align_size)
        pos = log.find(cls.NULL_CHAR, start_pos, size)
        if pos < 0:
            evt['log'] = log
        else:
            evt['log'] = log[0 : pos]
        return evt

    @classmethod
    def __parse_klog(cls, data):
        evt = {}
        # According to the data structures of kev_header_s and kev_klog_s,
        # 8 bytes need to be skipped here.
        log = data[2].decode('ascii', 'replace')
        evt = cls.__parse_log(log)
        evt['sequence'] = data[0]
        return evt

    @classmethod
    def __parse_el2_log(cls, data):
        evt = {}
        log = data[0].decode('ascii', 'replace')
        evt = cls.__parse_log(log)
        return evt

    @classmethod
    def __parse_fiq(cls, data):
        evt = {}
        evt['sequence'] = data[0]
        evt['text_id'] = data[1]
        return evt

    @classmethod
    def __parse_sched_switch(cls, data):
        evt = {}
        evt['sequence'] = data[0]
        evt['pname'] = data[1].decode('ascii', "replace").strip(cls.NULL_CHAR)
        evt['nname'] = data[2].decode('ascii', "replace").strip(cls.NULL_CHAR)
        evt['pprio'] = data[3]
        evt['nprio'] = data[4]
        evt['pcref'] = data[5]
        evt['ncref'] = data[6]
        evt['pstate'] = data[7]
        evt['cpu'] = data[8]
        evt['timestamp'] = data[9]
        return evt

    @classmethod
    def __parse_block(cls, data):
        evt = {}
        evt['sequence'] = data[0]
        evt['tname'] = data[1].decode('ascii', "replace").strip(cls.NULL_CHAR)
        evt['reason'] = data[2]
        return evt

    @classmethod
    def __parse_unblock(cls, data):
        evt = {}
        evt['sequence'] = data[0]
        evt['tname'] = data[1].decode('ascii', "replace").strip(cls.NULL_CHAR)
        evt['reason'] = data[2]
        return evt

    @classmethod
    def __parse_syscall(cls, data):
        evt = {}
        evt['sequence'] = data[0]
        evt['scno'] = data[1]
        evt['is_fastpath'] = data[2]
        return evt

    @classmethod
    def __parse_pagefault(cls, data):
        evt = {}
        evt['sequence'] = data[0]
        evt['faultpc'] = data[1]
        evt['faultaddr'] = data[2]
        return evt

    @classmethod
    def __parse_irq(cls, data):
        evt = {}
        evt['irqno'] = data[0]
        evt['sequence'] = data[1]
        evt['end'] = data[2]
        evt['timestamp'] = data[3]
        return evt

    @classmethod
    def __parse_kpreempt(cls, data):
        evt = {}
        evt['sequence'] = data[0]
        evt['tcno'] = data[1]
        return evt

    @classmethod
    def __parse_tailcall(cls, data):
        evt = {}
        evt['sequence'] = data[0]
        evt['tcno'] = data[1]
        return evt

    @classmethod
    def __parse_trap_el2(cls, data):
        evt = {}
        if data[0] == 0:
            evt['type'] = 'enter'
        elif data[0] == 1:
            evt['type'] = 'exit'
        evt['call_id'] = data[1]
        evt['x0'] = data[2]
        evt['x1'] = data[3]
        evt['x2'] = data[4]
        evt['tock'] = data[6]
        nsec = cls.tock_to_nanoseconds(data[6], data[5], data[7])
        evt['timestamp'] = cls.nsec_to_timestamp(nsec)
        return evt

    @classmethod
    def __parse_vcpu_exit(cls, data):
        evt = {}
        evt['idx'] = data[0]
        evt['esr_iss'] = data[1]
        evt['esr_ec'] = data[2]
        evt['esr_il'] = data[3]
        evt['vcpu_id'] = data[4]
        evt['reason'] = data[5].decode('ascii', "replace").strip(cls.NULL_CHAR)
        # 1-byte is skipped here
        evt['x0'] = data[7]
        evt['tock'] = data[10]
        nsec = cls.tock_to_nanoseconds(data[10], data[8], data[9])
        evt['timestamp'] = cls.nsec_to_timestamp(nsec)
        return evt

    @classmethod
    def __parse_vcpu_enter(cls, data):
        evt = {}
        evt['idx'] = data[0]
        evt['esr_el2'] = data[1]
        evt['vcpu_id'] = data[2]
        evt['reason'] = data[3].decode('ascii', "replace").strip(cls.NULL_CHAR)
        # 3-bytes skipped here, from data[4] to data[6]
        evt['data'] = data[7]
        evt['tock'] = data[9]
        evt['duration'] = cls.tock_to_nanoseconds(data[10], 0, data[11])
        nsec = cls.tock_to_nanoseconds(data[9], data[8], data[11])
        evt['timestamp'] = cls.nsec_to_timestamp(nsec)
        return evt

    @classmethod
    def __parse_sched_migrate_task(cls, data):
        evt = {}
        evt['sequence'] = data[0]
        evt['name'] = data[1].decode('ascii', "replace").strip(cls.NULL_CHAR)
        evt['cref'] = data[2]
        evt['prio'] = data[3]
        evt['orig_cpu'] = data[4]
        evt['dest_cpu'] = data[5]
        # 4-bytes skipped here, which is data[6]
        return evt

    @classmethod
    def __parse_el2_irq(cls, data):
        evt = {}
        irq_type = ['ASSERT EL1', 'HOST IRQ', 'INJECT', 'INJECT FALL']
        if data[0] < len(irq_type):
            evt['type'] = irq_type[data[0]]
        else:
            evt['type'] = None
        evt['irq'] = data[1]
        evt['tock'] = data[3]
        nsec = cls.tock_to_nanoseconds(data[3], data[2], data[4])
        evt['timestamp'] = cls.nsec_to_timestamp(nsec)
        return evt

    def parse_event(self, _type, data, data_format):
        """ parse event """
        data = struct.unpack(data_format, data)
        parse_func = self.parse_func_dict.get(_type)
        return parse_func(data)

    def parse_ringbuffer_head(self, data):
        """ parse ringbuffer head """
        buf_head = {}
        size = len(data)
        if size < self.ringbuffer_headsize:
            return None
        data = data[0 : self.ringbuffer_headsize]
        if self.endian_type is EndianType.little:
            fmt = '<11Q'
        else:
            fmt = '>11Q'
        data = struct.unpack(fmt, data)
        buf_head['size'] = data[5]
        buf_head['offset'] = data[0] & (buf_head.get('size') - 1)
        return buf_head

    def record_is_invalid(self, head, remain_len):
        """ check whether the record is vaild """
        align_size = 4
        _size = head.get('evt_size')
        _type = head.get('evt_type')

        ret = ((_size % align_size != 0) or (_size < self.head_size) or \
               (_type is None) or (_size > remain_len))
        return ret

    def parse_event_head(self, data):
        """ parse event head info """
        evt_head = struct.unpack(self.head_fmt, data)
        head = {}
        head['evt_size'] = (evt_head[0] >> self.header_evt_size_shift) & \
                                           self.header_evt_size_mask
        head['cpuid'] = (evt_head[0] >> self.header_cpuid_shift) & \
                                        self.header_cpuid_mask
        evt_type = (evt_head[0] >> self.header_evt_type_shift) & \
                                   self.header_evt_type_mask
        head['evt_type'] = KevType.type_of_value(evt_type)
        return head

    def parse_event_format_size(self, head):
        """ get evt data size and format from dict """
        data_param = {'format' : None, 'size' : 0}
        fmt_param = self.fmt_dict.get(head.get('evt_type'))
        if fmt_param is None:
            return data_param
        data_param['format'] = fmt_param[0]
        data_param['size'] = fmt_param[1]
        if data_param.get('format') is None:
            # when type is klog or el2_log, fmt_param[2] is the
            # fmt_func, and get the size based on head['evt_size']
            data_param['format'] = fmt_param[2](head)
            if data_param.get('format') is not None:
                data_param['size'] = struct.calcsize(data_param.get('format'))
        return data_param

    def find_next_valid_record(self, data, size, offset):
        """ traversal rb to find the correct record """
        head = None
        data_param = None
        cur_offset = offset
        evt_info = {'skipped' : 0}
        while offset < size:
            remain_len = size - offset
            if self.head_size > remain_len:
                break
            head = self.parse_event_head(data[offset : offset + self.head_size])
            if self.record_is_invalid(head, remain_len):
                # parsing is done
                if (head.get('evt_size') == 0) and (not any(data[offset :])):
                    evt_info['next_evt_offset'] = size
                    break
                else:
                    offset += 1
            else:
                if head.get('evt_type') is KevType.last:
                    offset += head.get('evt_size')
                    cur_offset = offset
                    continue
                data_param = self.parse_event_format_size(head)
                if data_param.get('size') + self.head_size != head.get('evt_size'):
                    offset += 1
                else:
                    evt_info['skipped'] = offset - cur_offset
                    evt_info['evt_offset_begin'] = offset + self.head_size
                    evt_info['evt_offset_end'] = evt_info.get('evt_offset_begin') + \
                                                 data_param.get('size')
                    evt_info['next_evt_offset'] = offset + head.get('evt_size')
                    evt_info['evt_fmt'] = data_param.get('format')
                    break
        return evt_info, head

    @classmethod
    def report_invalid_info(cls, skipped_bytes):
        """ report invalid data info """
        _type = KevType.invalid_type
        evt = {'head' : None, 'type' : _type,
               'data' : {'skipped' : skipped_bytes}}
        return evt

    def parse_data_content(self, size, data, evt_list):
        """ parse data content """
        parse_content_data = []
        evt_type_list = [KevType.type_of_name(name) for name in evt_list]
        offset = 0
        while offset < size:
            evt_info, head = self.find_next_valid_record(data, size, offset)

            if evt_info.get('skipped') != 0:
                evt = KevParser.report_invalid_info(evt_info.get('skipped'))
                parse_content_data.append(evt)
            if (head is None) or (evt_info.get('evt_fmt') is None):
                break
            offset = evt_info.get('next_evt_offset')
            _type = head.get('evt_type')
            if _type in evt_type_list:
                evt_data = data[evt_info.get('evt_offset_begin') : \
                                evt_info.get('evt_offset_end')]

                parse_evt = self.parse_event(_type, evt_data, evt_info.get('evt_fmt'))
                if parse_evt is None:
                    break
                # Reorder the event, with the newest events at the front.
                evt = {'head' : head, 'type' : _type, 'data' : parse_evt}
                parse_content_data.append(evt)

        # Flip the list to move the newest events to the end.
        parse_content_data.reverse()
        return parse_content_data


class KevPrint:
    """ kev print """
    def __init__(self):
        self.print_func_dict = {
            KevType.sched_switch       : self.__print_sched_switch,
            KevType.block              : self.__print_block,
            KevType.unblock            : self.__print_unblock,
            KevType.syscall            : self.__print_syscall,
            KevType.pagefault          : self.__print_pagefault,
            KevType.irq                : self.__print_irq,
            KevType.klog               : self.__print_klog,
            KevType.tailcall           : self.__print_tailcall,
            KevType.kpreempt           : self.__print_kpreempt,
            KevType.fiq                : self.__print_fiq,
            KevType.trap_el2           : self.__print_trap_el2,
            KevType.vcpu_exit          : self.__print_vcpu_exit,
            KevType.vcpu_enter         : self.__print_vcpu_enter,
            KevType.el2_irq            : self.__print_el2_irq,
            KevType.el2_log            : self.__print_el2_log,
            KevType.sched_migrate_task : self.__print_sched_migrate_task,
            KevType.invalid_type       : self.__print_invalid_record,
            KevType.region_separator   : self.__print_region_separator,
        }

    NSEC_PER_SEC = 1000000000

    @classmethod
    def __print_region_separator(cls, _, evt):
        print("%20s region:%d size:0x%-6x %20s\n" % ('-' * 20, evt['index'], evt['size'], '-' * 20))

    @classmethod
    def __print_invalid_record(cls, _, evt):
        print("%30s skipped %d bytes of invalid data %30s\n" % \
             ('-' * 30, evt['skipped'], '-' * 30))

    @classmethod
    def __print_sched_switch(cls, head, evt):
        print("[%u:%u]%12s: %u.%06u: prev_comm=%s prev_cref=0x%x prev_prio=%u prev_state=%u ==> " \
              "next_comm=%s next_cref=0x%x next_prio=%u" %
              (evt['sequence'], head['cpuid'], 'sched_switch',
              evt['timestamp'] // cls.NSEC_PER_SEC, evt['timestamp'] % cls.NSEC_PER_SEC // 1000,
              evt['pname'], evt['pcref'], evt['pprio'], evt['pstate'],
              evt['nname'], evt['ncref'], evt['nprio']))

    @classmethod
    def __print_block(cls, head, evt):
        print("[%u:%u]%12s: tcb=%s, reason=%u" %
              (evt['sequence'], head['cpuid'], 'block', evt['tname'], evt['reason']))

    @classmethod
    def __print_unblock(cls, head, evt):
        print("[%u:%u]%12s: tcb=%s, reason=%u" %
              (evt['sequence'], head['cpuid'], 'unblock', evt['tname'], evt['reason']))

    @classmethod
    def __print_syscall(cls, head, evt):
        print("[%u:%u]%12s: type=%s, scno=%u" %
              (evt['sequence'], head['cpuid'], 'syscall',
              "fastpath" if evt['is_fastpath'] else "slowpath", evt['scno']))

    @classmethod
    def __print_pagefault(cls, head, evt):
        print("[%u:%u]%12s: faultpc=0x%x, faultaddr=%x\n" %
              (evt['sequence'], head['cpuid'], "pagefault",
              evt['faultpc'], evt['faultaddr']))

    @classmethod
    def __print_irq(cls, head, evt):
        print("[%u:%u]%12s: %u.%06u: irqno=0x%x %s" %
              (evt['sequence'], head['cpuid'], 'irq',
              evt['timestamp'] // cls.NSEC_PER_SEC, evt['timestamp'] % cls.NSEC_PER_SEC // 1000,
              evt['irqno'], "end" if evt['end'] else "start"))

    @classmethod
    def __print_klog(cls, head, evt):
        print("[%u:%u]: %s" % (evt['sequence'], head['cpuid'], evt['log']))

    @classmethod
    def __print_el2_log(cls, head, evt):
        print("[%d]: %s" % (head['cpuid'], evt['log']))

    @classmethod
    def __print_fiq(cls, head, evt):
        print("[%u:%u]%12s: text_id=%s" % (evt['sequence'], head['cpuid'], 'fiq', evt['text_id']))

    @classmethod
    def __print_tailcall(cls, head, evt):
        print("[%u:%u]%12s: tcno=%u" % (evt['sequence'], head['cpuid'], 'tailcall', evt['tcno']))

    @classmethod
    def __print_kpreempt(cls, head, evt):
        print("[%u:%u]%12s: tcno=%u" % (evt['sequence'], head['cpuid'], 'kpreempt', evt['tcno']))

    @classmethod
    def __print_trap_el2(cls, head, evt):
        print("[%u]%8s [%s]%-5s: call_id=%u x0=0x%016x x1=0x%016x x2=0x%016x tock=%u" %
             (head['cpuid'], 'trap_el2', evt['timestamp'], evt['type'],
             evt['call_id'], evt['x0'], evt['x1'], evt['x2'], evt['tock']))

    @classmethod
    def __print_vcpu_exit(cls, head, evt):
        print("[%u]%10s: [%s]idx=%u vcpu_id=%d reason=%-7s esr.ec=0x%02x "
                "esr.il=%u esr.iss=0x%07x x0=0x%016x tock=%u" %
                (head['cpuid'], "vcpu_exit", evt['timestamp'], evt['idx'],
                evt['vcpu_id'], evt['reason'], evt['esr_ec'], evt['esr_il'],
                evt['esr_iss'], evt['x0'], evt['tock']))

    @classmethod
    def __print_vcpu_enter(cls, head, evt):
        print("[%u]%10s: [%s]idx=%u esr_el2=0x%08x vcpu_id=%d reason=%-7s "
                "data=0x%016x tock=%u duration=%u" %
                (head['cpuid'], "vcpu_enter", evt['timestamp'], evt['idx'],
                evt['esr_el2'], evt['vcpu_id'], evt['reason'], evt['data'],
                evt['tock'], evt['duration']))

    @classmethod
    def __print_el2_irq(cls, head, evt):
        print("[%u]%8s: [%s]type=%-10s irq=0x%04x tock=%u" % (head['cpuid'],
            "el2_irq", evt['timestamp'], evt['type'], evt['irq'], evt['tock']))

    @classmethod
    def __print_sched_migrate_task(cls, head, evt):
        print("[%u:%u]%18s: name=%s cref=0x%X prio=%u orig_cpu=%u dest_cpu=%u" %
             (evt['sequence'], head['cpuid'], 'sched_migrate_task', evt['name'],
              evt['cref'], evt['prio'], evt['orig_cpu'], evt['dest_cpu']))

    def print_event(self, _type, head, evt):
        """ print event """
        print_func = self.print_func_dict.get(_type)
        print_func(head, evt)


def parse_kev_head(f, dump_file_size):
    """ parse kev head """
    fmt = '4s'
    magic_type = None
    endian_type = None
    headinfo = {}

    magic_size = struct.calcsize(fmt)
    if dump_file_size < magic_size:
        sys.exit("Error: Dump file too small to hold magic header.")

    magic = struct.unpack(fmt, f.read(magic_size))
    magic = magic[0].decode('ascii')
    if magic == 'DVEK':
        head_size = 16 # sizeof(struct kevdump_memory)
        magic_type = KevMagicType.kevdump
        if dump_file_size < head_size:
            sys.exit("Error: The dump file size is smaller than the header size of the dump memory")
        endian_type = read_kevdump_endian(f)
        headinfo = read_kevdump_head(f, head_size, dump_file_size, endian_type)
    elif magic == 'NVEK' or magic == 'KEVN':
        head_size = 8 # sizeof(struct kev_mem_s)
        magic_type = KevMagicType.kevraw
        if magic == 'NVEK':
            endian_type = EndianType.little
        else:
            endian_type = EndianType.big

        if dump_file_size < head_size:
            sys.exit("Error: The dump file size is smaller than the header size of the dump memory")
        headinfo = read_kevraw_head(f, head_size, dump_file_size, endian_type)
    else:
        sys.exit("Error: Invalid magic: %s" % magic)

    return magic_type, endian_type, headinfo


def read_kevraw_head(f, mem_head_size, dump_file_size, endian_type):
    """ read kev raw head """
    if endian_type is EndianType.little:
        fmt = '<I'
    else:
        fmt = '>I'

    data = f.read(struct.calcsize(fmt))
    data = struct.unpack(fmt, data)
    raw_head = {}
    raw_head['ring_count'] = data[0]
    if raw_head.get('ring_count') == 0:
        sys.exit("Error: region count err")
    raw_head['dump_size'] = dump_file_size - mem_head_size
    if raw_head.get('dump_size') <= 0:
        sys.exit("Error: No data to dump")

    return raw_head


def read_kevdump_endian(f):
    """ read kevdump endian """
    endian = struct.unpack('<I', f.read(struct.calcsize('<I')))
    endian_type = EndianType.type_of_value(endian[0])
    return endian_type


def read_kevdump_head(f, mem_head_size, dump_file_size, endian_type):
    """ read kevdump head """
    if endian_type is EndianType.little:
        fmt = '<2I'
    else:
        fmt = '>2I'

    data = f.read(struct.calcsize(fmt))
    data = struct.unpack(fmt, data)
    mem_head = {}
    mem_head['size'] = data[0]
    mem_head['dump_size'] = data[1]

    # The size should >= dump_file_size
    if mem_head.get('size') < dump_file_size:
        sys.exit("Error: check dump memory size failed")
    if mem_head.get('dump_size') + mem_head_size > mem_head.get('size'):
        sys.exit("Error: check dump data size failed")

    return mem_head


def parse_kevdump_data(data, endian_type, evt_list):
    """ parse kev dump data """
    parse_data = []
    size = len(data)
    kev_parser = KevParser(endian_type)
    parse_data = kev_parser.parse_data_content(size, data, evt_list)

    return parse_data


def parse_kevraw_data(data, endian_type, evt_list, ring_count):
    """ parse kev raw data """
    data_offset = 0
    parse_data = []
    remain_len = len(data)
    kev_parser = KevParser(endian_type)
    for i in range(0, ring_count):
        if remain_len < kev_parser.ringbuffer_headsize:
            break
        # parse ringbuffer header
        ringbuf_head = kev_parser.parse_ringbuffer_head( \
                        data[data_offset : data_offset + \
                        kev_parser.ringbuffer_headsize])
        region_offset = ringbuf_head.get('offset')
        size = ringbuf_head.get('size')
        remain_len -= kev_parser.ringbuffer_headsize
        if remain_len < size:
            warnings.warn("Warn: remain length is smaller than ringbuffer content size")
            break

        # combine data
        first_part_offset = data_offset + kev_parser.ringbuffer_headsize + region_offset
        first_part_len = size - region_offset
        second_part_offset = data_offset + kev_parser.ringbuffer_headsize
        second_part_len = region_offset
        region_data = data[first_part_offset : first_part_offset + first_part_len] + \
                      data[second_part_offset : second_part_offset + second_part_len]

        # parse data
        parse_data += kev_parser.create_separator(i, size)
        parse_data += kev_parser.parse_data_content(size, region_data, evt_list)
        remain_len -= size
        data_offset += (size + kev_parser.ringbuffer_headsize)

    return parse_data


def print_parse_data(data, endian_type, evt_list):
    """ print parse data """
    kev_print = KevPrint()

    print("Endian: %s" % endian_type.name)
    print("Parsing events list: ", evt_list)
    print("--------------------Parse Start-----------------------")
    for evt in data:
        kev_print.print_event(evt['type'], evt['head'], evt['data'])
    print("--------------------Parse End-------------------------")


def get_cmd_args():
    """ get cmd args """
    ap = argparse.ArgumentParser(description='Parse kev dump data.',
                                 formatter_class=RawTextHelpFormatter)
    ap.add_argument('cmd', metavar='command', choices=['list', 'parse'],
                    help='list\t\tPrint all support events\nparse\t\tParse kev dump file')
    ap.add_argument('-f', '--file', metavar='inputfile',
                    help='When use command parse, this param is required')
    ap.add_argument('-e', '--event', metavar='all/event_name1[,event_name2]',
                    help='When use command parse, this param is required.'\
                    '\nall               Parse all support events in dump file'\
                    '\nevent_name1,...   Parse specific events')
    ap.add_argument('-s', '--seek', metavar='offset', type=int, default=0,
                    help='Set to start parsing from a certain offset.'\
                    '\nWhen use command parse, this param is optional. The default is 0.')
    ap.add_argument('-o', '--output', metavar='output',
                    help='Set the path and name of the output file.'\
                    '\nWhen use command parse, this param is optional.'\
                    '\nPrint to stdout by default.')

    return ap.parse_args()


def parse_arg_event(events):
    """ print arg event """
    evt_list = KevType.events_name_list()
    if events == 'all':
        return evt_list
    events = events.split(',')
    parse_list = []
    for event in events:
        if event in evt_list:
            parse_list = parse_list + [event]
        else:
            warnings.warn("Warn: %s is not supported" % event)
    return parse_list


def parse_args(args):
    """ parse args """
    if args.file is None:
        sys.exit("Error: need an input file")
    if args.event is None:
        sys.exit("Error: need to specify the events to be parsed")

    input_file = args.file
    seek_size = args.seek
    if seek_size < 0:
        sys.exit("Error: seek parameter must be a non-negative integer")
    if seek_size >= os.path.getsize(input_file):
        sys.exit("Error: seek parameter should be less than file size")

    evt_list = parse_arg_event(args.event)
    if len(evt_list) == 0:
        sys.exit("Error: no supported events are specified")
    output_file_path = args.output

    return input_file, seek_size, evt_list, output_file_path


def main():
    """ entry of the script """
    args = get_cmd_args()
    if args.cmd == 'list':
        KevType.print_support_events()
        sys.exit(0)
    else:
        input_file, seek_size, evt_list, output_file_path = parse_args(args)

    # command parse
    dump_file_size = os.path.getsize(input_file) - seek_size

    with open(input_file, 'rb') as f:
        f.seek(seek_size)
        magic_type, endian_type, headinfo = parse_kev_head(f, dump_file_size)
        if not magic_type:
            sys.exit('Error: file magic number does not match KEVD or KEVN.')
        if not endian_type:
            sys.exit("Error: unknown endian")
        data = f.read(headinfo['dump_size'])
        if magic_type == KevMagicType.kevdump:
            parse_data = parse_kevdump_data(data, endian_type, evt_list)
        elif magic_type == KevMagicType.kevraw:
            parse_data = parse_kevraw_data(data, endian_type, evt_list, headinfo['ring_count'])
        else:
            sys.exit('Error: invalid kev dump file.')

    if output_file_path:
        dirname = os.path.dirname(output_file_path)
        basename = os.path.basename(output_file_path)
        if len(basename) == 0:
            sys.exit('Error: missing output filename after -o')
        if (len(dirname) != 0) and (not os.path.exists(dirname)):
            os.makedirs(dirname)
        sys.stdout = os.fdopen(os.open(output_file_path, \
                        os.O_WRONLY | os.O_CREAT, 0o644), 'w')
    print_parse_data(parse_data, endian_type, evt_list)

    if output_file_path:
        sys.stdout.close()

if __name__ == '__main__':
    main()
