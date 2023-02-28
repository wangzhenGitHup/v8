/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Implementation of fs ldso
 * Author: Huawei OS Kernel Lab
 * Create: Wed Aug 28 17:26:50 2019
 */
#ifndef LIBVFS_FS_H
#define LIBVFS_FS_H

#include <unistd.h>
#include <asm/types.h>
#include <sys/stat.h>

void ldso_fs_init(void);
int ldso_open(const char* name, unsigned int flags, unsigned int mode);
ssize_t ldso_read(int fd, void *data, size_t len);
off_t ldso_lseek(int fd, off_t offset, int whence);
ssize_t ldso_pread(int fd, int64_t pos, void *data, size_t len);
int ldso_close(int fd);
void ldso_dump_open_fd(void);
int ldso_stat(int fd, struct stat *st);
int fd_of_real(int fd);
char *fd_of_pathname(int fd);

#endif
