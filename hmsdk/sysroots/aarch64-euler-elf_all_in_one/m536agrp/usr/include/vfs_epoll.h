/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: State epoll ulib interface and data structure
 * Author: Huawei OS Kernel Lab
 * Create: Fri Feb 28 16:12:42 2020
 */
#ifndef LIBHMSRV_FS_VFS_EPOLL_H
#define LIBHMSRV_FS_VFS_EPOLL_H

#include <vfs.h>
#include <poll.h>
#include <libhmsrv_sys/hm_timer.h>
#include <libhmsrv_sys/hm_select_common.h>
#include <libhmsrv_sys/hm_mem.h>
#include <libhmsrv_sys/hm_ashm.h>
#include <libhmsync/raw_mutex.h>

#ifndef EPOLL_CLIENT_H
#define EPOLL_CLIENT_H

/* default futex lock time (300s) */
#define EPOLL_WAIT_TIME 300
/* default futex lock interval (300s * TIMER_KTOCK_FREQ) */
#define EPOLL_WAIT_INTERVAL 300000000ULL
#define EP_MAX_EVENTS ((int)(INT_MAX / sizeof(struct epoll_event)))

#define POLLIN_SET (EPOLLRDNORM | EPOLLRDBAND | \
		    EPOLLIN | EPOLLHUP | EPOLLERR | EPOLLIN_CACHE_EVENT)
#define POLLOUT_SET (EPOLLWRBAND | EPOLLWRNORM | EPOLLOUT | EPOLLERR)
#define POLLEX_SET (EPOLLPRI)

/* poll/select will use this epfd */
#define FAKE_EPFD (-1)

#define UINT32_BITS 32

/* number of long for "nr" bits */
#define FDS_BITPERLONG  (8 * sizeof(long))
#define FDS_LONGS(nr)   (((nr) + FDS_BITPERLONG - 1) / FDS_BITPERLONG)
#define FDS_BYTES(nr)   (FDS_LONGS((unsigned int)(nr)) * sizeof(long))

enum {
	POLL_NET,
	POLL_VFS,
	POLL_VPIPE,
	POLL_EP,
	POLL_BADF,
};

struct epoll_info {
	int op;
	int fd;
	uint32_t events;
	uint64_t data;
};

struct epoll_wait_args {
	struct timespec start_time;
	struct timespec timeout;
};

struct select_fds {
	fd_set *rfds;
	fd_set *wfds;
	fd_set *efds;
	fd_set *_rfds;
	fd_set *_wfds;
	fd_set *_efds;
};

struct epoll_tree {
	struct fs_mutex mutex;
	struct rbt_tree tree;
};

/*
 * shm_list_node is used to maintain shm_pool. One shm_list_node is related to
 * one server.
 *
 * one epitem will be connected to one slot of shm_list_node, and these slots
 * are maintained by bitmap in shm_list_node
 */
struct shm_list_node {
	int shm_fd;
	int poll_type;
	/*
	 * if one shm_list_node is not enough for one server, id is used to tell
	 * different shm_list_node
	 */
	uint32_t id;
	uint32_t bitmap_nr;
	/* node of shm_list */
	struct dlist_node node;
	/* bitmap is used to maintain slots */
	unsigned long long *bitmap;
	struct shm_pool *shm_pool;
	/* used for choosing shm_list_node for different server */
	rref_t server_rref;
};

struct eventpoll {
	bool is_poll;
	/* only epoll has a 'valid' epfd */
	int epfd;
	int flags;
	int shm_fd;
	uint64_t shm_key;
	struct raw_refcnt_nr refcnt;
	/* node of epoll_tree */
	struct rbt_node node;
	struct ep_share_info *ep_share;
	/* ep_mutex is used to protect epitem_tree and shm_list */
	struct fs_mutex ep_mutex;
	union {
		/* epitem will be inserted into epitem_tree for epoll */
		struct rbt_tree epitem_tree;
		/* epitem will be inserted into epitem_list for select/poll */
		struct dlist_node epitem_list;
	};
	/* all epitem shm will be held in shm_list */
	struct dlist_node shm_list;
	struct eventpoll_mgr *ep_mgr;
};

struct epitem {
	int fd;
	int poll_type;
	/* shm_list_node offer shm for epitem */
	struct shm_list_node *shm_list_node;
	/* shm_key used as pre epi_shm_key during reinit */
	uint64_t shm_key;
	uint32_t shm_index;
	union {
		/* node of epitem_tree */
		struct rbt_node node;
		/* node of epitem_list */
		struct dlist_node dnode;
	};
	/* events, revents, state are held by shm_pool_entry */
	struct shm_pool_entry *entry;
	struct eventpoll *eventpoll;
	rref_t server_rref;
};

struct epoll_sigset {
	sigset_t *sigmask;
	size_t sigsize;
};
#endif /* EPOLL_CLIENT_H */


struct vfs_epoll_pwait_info {
	int epfd;
	struct epoll_event *ev;
	int maxevents;
	int timeout;
	struct epoll_sigset *sigset;
};

extern void epoll_fork_mutex_acquire(void);
extern void epoll_fork_mutex_release(void);

extern int vfs_epoll_create(int size);
extern int vfs_epoll_create1(int flags);
extern int vfs_epoll_control(int epfd, int op, int fd,
			     const struct epoll_event *ev);
extern int vfs_epoll_wait(int epfd, struct epoll_event *ev, int maxevents,
			  int timeout, int *count);
extern int vfs_epoll_pwait(const struct vfs_epoll_pwait_info *pwait_info, int *count);
extern int vfs_epoll_close(int epfd);
extern void vfs_epoll_post_fork_reinit(void);
extern int vfs_poll(struct pollfd *fds, nfds_t nfds, int timeout, int *count);
extern int vfs_ppoll(struct pollfd *fds, nfds_t nfds,
		     const struct timespec *tsp, const struct epoll_sigset *sigset,
		     int *count);
extern int vfs_select(int nfds, struct select_fds *select_fds,
		      const struct timeval *tv, int *count);
extern int vfs_select6(int nfds, struct select_fds *select_fds,
		       const struct timespec *tsp, const struct epoll_sigset *sigset,
		       int *count);
extern int vfs_is_epoll_fd(int fd, bool *is_epoll_fd);
extern int epoll_shm_grant(rref_t rref, struct epitem *epitem,
			   struct eventpoll *eventpoll);
#endif /* LIBHMSRV_FS_VFS_EPOLL_H */
