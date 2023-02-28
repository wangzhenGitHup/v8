/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: Header file for socket
 * Author: Huawei OS Kernel Lab
 * Create: Tue Sep 24 11:20:38 2019
 */

#ifndef __HM_SOCKET_H_
#define __HM_SOCKET_H_

#include <sys/socket.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <poll.h>
#include <ifaddrs.h>

#include <vfs.h>
#include <vfs_epoll.h>

#include <hmkernel/capability.h>
#include <libhmsrv_sys/hm_select_common.h>

#define MAX_MSG_SIZE 0xFFFF
#define HMNET_SOCKET_VERSION 2019111401

void net_revoke_process(cref_t rref, uint32_t cnode_idx);
int net_notify_fork(cref_t ch, uint32_t src_cidx, uint32_t dst_cidx);

int hm_net_socket(int domain, int type, int protocol);
int hm_net_socketpair(int domain, int type, int protocol, int sv[2]);

int hm_net_send_fd(int send_fd, uint32_t send_cidx, uint32_t recv_cidx);
int hm_net_recv_fd(int send_fd, uint32_t send_cidx);
int hm_net_put_send_fd(int send_fd, uint32_t send_cidx, uint32_t recv_cidx);

int hm_net_shutdown(int sockfd, int how);
int hm_net_close(int sockfd);
void hm_fd_close_net(const struct hm_fd *hf);
void hm_fd_put_net(const struct hm_fd *hf);
int hm_fd_check_net(const struct hm_fd *hf);

int hm_net_bind(int sockfd, const struct sockaddr *addr, socklen_t len);
int hm_net_listen(int sockfd, int backlog);
int hm_net_accept(int sockfd, struct sockaddr *addr,
		  socklen_t *len);
int hm_net_accept4(int sockfd, struct sockaddr *addr,
		   socklen_t *len, int flags);
int hm_net_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

ssize_t hm_net_sendto(int sockfd, const void *buf, size_t len, int flags,
		      const struct sockaddr *addr, socklen_t alen);
ssize_t hm_net_recvfrom(int sockfd, void *buf, size_t len, int flags,
			struct sockaddr *addr,
			socklen_t *alen);

ssize_t hm_net_send(int sockfd, const void *buf, size_t len, int flags);
ssize_t hm_net_recv(int sockfd, void *buf, size_t len, int flags);

ssize_t hm_net_sendmsg(int sockfd, const struct msghdr *msg, int flags);
ssize_t hm_net_recvmsg(int sockfd, struct msghdr *msg, int flags);

int hm_net_fcntl(int sockfd, int cmd, int val);
int hm_net_ioctl(int sockfd, int request, unsigned long args);
int hm_net_dup(int oldfd);
int hm_net_dup2(int oldfd, int newfd);

int hm_net_getsockopt(int sockfd, int level, int optname, void *optval,
		      socklen_t *optlen);
int hm_net_setsockopt(int sockfd, int level, int optname, const void *optval,
		      socklen_t optlen);

int hm_net_getsockname(int sockfd, struct sockaddr *addr,
		       socklen_t *len);
int hm_net_getpeername(int sockfd, struct sockaddr *addr,
		       socklen_t *len);

int hm_net_getifaddrs(struct ifaddrs **ifap);

int hm_net_get_netfd_size(void);
int hm_net_copy_netfd(const char *fd_start);


int hm_net_epoll_ctl(struct epitem *epitem, struct eventpoll *eventpoll, int op);
int hm_net_epoll_et_revents(const struct epitem *epitem, uint32_t *revents);
int hm_net_epoll_reinit(struct epitem *epitem, struct eventpoll *eventpoll,
			const void *epoll_pre_reg_info);

static inline bool is_invalid_sockfd(int fd)
{
	return (fd < VFS_MIN_REGFILE_NUM || fd >= (int)hm_fdtable_size());
}

int hm_net_read_fds(uint32_t cnode_idx, int *fdcnt, int *fds, unsigned int max_files);
int hm_net_get_fd_path(int fd, char *path_buf, unsigned int path_buf_len, uint32_t cnode_idx);

#endif
