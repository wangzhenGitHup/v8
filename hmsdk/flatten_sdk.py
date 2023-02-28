#!/usr/bin/env python
# -*- coding: UTF-8 -*

#Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
#Description: flatten sdk scripts, run during sdk installing
#Author: Huawei OS Kernel Lab
#Create: Wed Mar 31 01:32:05 2021

import os
import logging
import argparse
from pathlib import Path

argparser = argparse.ArgumentParser(description='Flatten SDK according to SDK file list')
argparser.add_argument('--sdkroot',
                       dest='sdkroot', help='SDK root')
argparser.add_argument('--sysroot',
                       dest='sysroot', help='sysroot to be flatten')
argparser.add_argument('--verbose', '-v', action='count', default=0,
                       dest='verbose', help='Verbose level')
args = argparser.parse_args()

user_set_level = 0
if args is not None and 'verbose' in vars(args):
    user_set_level = args.verbose
if user_set_level > 2:
    user_set_level = 2

logging.basicConfig(format = '%(levelname)s:\t%(message)s',
                    level = logging.DEBUG)
logger = logging.getLogger()
level = [logging.WARNING, logging.INFO, logging.DEBUG][user_set_level]
logger = logging.getLogger()
logger.setLevel(level)

if not args.sdkroot:
    raise Exception('--sdkroot is mandatory')
if not args.sysroot:
    raise Exception('--sysroot is mandatory')

sdkrootpath     = Path(args.sdkroot)
product_flist   = set(sdkrootpath.glob('sdk-fileslist-*-*'))
group_flist     = set(sdkrootpath.glob('sdk-fileslist-*')).difference(product_flist)
base_flist      = set(sdkrootpath.glob('sdk-fileslist'))

sysrootpath     = Path(args.sysroot)

if (not base_flist):
    raise Exception('sdk-fileslist is missing in sdkroot %s' % args.sdkroot)

def readflist(flistpath, lst, exclude_prefix):
    logger.info('Found filelist %s' % flistpath)
    with open(str(flistpath)) as f:
        for l in f.readlines():
            l = l.strip()
            path = Path(l)
            if len(path.parts) > 0 and path.parts[0] in exclude_prefix:
                continue
            lst.add(l)

product_files = {}
for path in product_flist:
    group, product = path.parts[-1].replace('sdk-fileslist-', '').split('-')
    product_files[(group, product)] = set()
    readflist(path, product_files[(group, product)], set())

group_files = {}
for path in group_flist:
    group = path.parts[-1].replace('sdk-fileslist-', '')
    group_files[group] = set()
    readflist(path, group_files[group], [i[1] for i in product_files.keys() if i[0] == group])

allfiles = set()
readflist(list(base_flist)[0], allfiles, group_files.keys())

def do_flatten(_fn, _basedir, _dstdir):
    def clone_symlink(src, dst):
        to = os.readlink(str(src))
        os.symlink(to, str(dst))

    def clone_file(src, dst):
        try:
            os.link(str(src), str(dst))
        except OSError as err:
            if err.errno == errno.EXDEV:
                bb.utils.copyfile(str(src), str(dst))
            else:
                raise

    src = sysrootpath / _basedir / _fn
    dst = sysrootpath / _dstdir / _fn

    logger.debug("flatten: clone %s to %s" % (str(src), str(dst)))

    if not dst.parents[0].is_dir():
        os.makedirs(str(dst.parents[0]))

    if not os.path.lexists(str(src)):
        logger.warn("flatten: path %s not exist"% (str(src)))
        return

    if src.is_symlink():
        if os.path.lexists(str(dst)):
            logger.warn("flatten: Skip softlink file %s to %s because it is already there" %
                        (str(src), str(dst)))
        else:
            logger.debug("flatten: copy symlink %s to %s" % (str(src), str(dst)))
            clone_symlink(src, dst)
    elif src.is_dir():
        logger.debug("flatten: mkdir: %s to %s" % (str(src), str(dst)))
        if not dst.is_dir():
            os.makedirs(str(dst))
    elif os.path.lexists(str(dst)):
        logger.warn("flatten: Skip hardlink file %s to %s because it is already there" %
                    (str(src), str(dst)))
    else:
        logger.debug("flatten: hardlink %s to %s" % (str(src), str(dst)))
        clone_file(src, dst)

for grp in group_files.keys():
    logger.info('Flatten to group %s' % grp)
    for fn in allfiles:
        path = Path(fn)
        if fn not in group_files[grp]:
            logger.debug('flatten global file %s to group %s' % (fn, grp))
            do_flatten(path, '', Path(grp))

for (grp, prod) in product_files.keys():
    logger.info('Flatten to product %s-%s' % (grp, prod))
    for fn in group_files[grp]:
        path = Path(fn)
        if fn not in product_files[(grp, prod)]:
            do_flatten(path, Path(grp), Path(grp, prod))
    for fn in allfiles:
        path = Path(fn)
        if fn not in group_files[grp] and fn not in product_files[(grp, prod)]:
            do_flatten(path, '', Path(grp, prod))
