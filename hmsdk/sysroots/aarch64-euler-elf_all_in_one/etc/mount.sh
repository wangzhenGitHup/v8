#!/bin/bash

#================================================================
# Copyright (c) Huawei Technologies Co.,Ltd. 2020. All rights reserved.
# Description: Mount android system, vender, and data partition
# Author: Huawei OS Kernel Lab
# Create: Wed Aug 12 14:57:45 2020
#================================================================
set -e

version=""
preload=""
userdata=""
devs=$(ls -1 /dev | grep sd.$)
for dev in $devs; do
	while read line; do
		# Keyword version, preload, and userdata may appear in other
		# information such as sector size, disk identifier, etc. But
		# we ignore this case now.
		if echo "$line" | grep "version" - > /dev/null; then
			num=$(echo "$line" | cut -d " " -f 1)
			version="/dev/$dev$num"
		fi
		if echo "$line" | grep "preload" - > /dev/null; then
			num=$(echo "$line" | cut -d " " -f 1)
			preload="/dev/$dev$num"
		fi
		if echo "$line" | grep "userdata" - > /dev/null; then
			num=$(echo "$line" | cut -d " " -f 1)
			userdata="/dev/$dev$num"
		fi
	done << EOF
	$(fdisk -l "/dev/$dev")
EOF
done

if [ -z "$version" ]; then
	echo "can not find partition named version"
else
	mount -t ext2 -o sync "$version" ../system/
fi

if [ -z "$preload" ]; then
	echo "can not find partition named preload"
else
	mount -t ext2 -o sync "$preload" ../vendor/
fi

if [ -z "$userdata" ]; then
	echo "can not find partition named userdata"
else
	mount -t ext2 -o sync "$userdata" ../data/
fi
