#!/usr/bin/env python3
# coding:utf-8
"""
Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
Description: Generating service property files
Author: Huawei OS Kernel Lab
Create: Tue May 25 17:48:24 2021
"""

import os
import argparse

from hmtools import hmlogging
from hmtools.fsops import HMToolsDir
from hmtools.fsops import HMToolsFSControl
from hmtools.manifest import Conf
from hmtools.manifest import parse_manifest_files
from hmtools.exceptions import HMToolsArgException
from hmtools.exceptions import HMToolsBaseException


class JobGenProp(object):
    """
    Gen property
    """
    def __init__(self, args):
        self._cmdline_args  = args
        self._fscontrol     = HMToolsFSControl(vars(self._cmdline_args))

        if args.sysroot is None:
            raise HMToolsArgException('--sysroot is required')

        if args.manifest is None:
            raise HMToolsArgException('--manifest is required')

        self._manifest = parse_manifest_files(args.manifest)

        self._workdir = HMToolsDir(args.output_dir, need_create=True)
        self._sysroots      = [HMToolsDir(x) for x in args.sysroot]
        self._is_force      = args.force
        self._sysroot_native = args.sysroot_native

    def execute(self):
        """
        Execute gen property
        """
        self._manifest.run(Conf(self._workdir,
                                self._sysroots,
                                sysroot_native=self._sysroot_native,
                                fscontrol=self._fscontrol,
                                is_force=self._is_force,
                                tools={"genprop":"usr/bin/hmtools/proptytool.py"}))
        self._workdir.write_finish()


def main():
    """
    Main function
    """
    parser = argparse.ArgumentParser(description='Generating property files for hongmeng services')
    parser.add_argument('--output-dir', default=os.getcwd(),
                        dest='output_dir', help='Output directory, default: $(pwd)')
    parser.add_argument('--sysroot', action='append', required=True,
                        dest='sysroot', help='Sysroot path for services')
    parser.add_argument('--sysroot-native', default=None,
                        dest='sysroot_native', help='Native sysroot path')
    parser.add_argument('--manifest', action='append', required=True,
                        dest='manifest', help='Manifest file for how to generating prooperty files')
    parser.add_argument('--force', action='store_true',
                        dest='force', help='Ignore files not found')

    parser.add_argument('--verbose', '-v', action='count', default=0,
                        dest='verbose', help='Verbose level')
    args = parser.parse_args()
    hmlogging.set_basic_config(vars(args))
    try:
        job = JobGenProp(args)
        job.execute()
    except HMToolsBaseException:
        hmlogging.exception()
        raise
    finally:
        # no need to manually cleanup
        pass

if __name__ == '__main__':
    main()
