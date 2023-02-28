/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: State epoll server common interface and data structure
 * Author: Huawei OS Kernel Lab
 * Create: Wed Feb 12 21:00:44 2020
 */
#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_SELECT_COMMON_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_SELECT_COMMON_H

#include <lib/dlist.h>
#include <libhmsrv_sys/hm_mem.h>
#include <libhmsrv_sys/hm_ashm.h>
#include <libalgo/rbtree.h>
#include <libhmsync/raw_mutex.h>
#include <libhmsync/raw_scopedptr.h>
#include <sys/epoll.h>

#define EPOLL_SHM_PROT ((unsigned)PROT_READ | (unsigned)PROT_WRITE)
#define EPOLL_SHM_FLAGS ((unsigned)MAP_SHARED | (unsigned)MAP_ANONYMOUS)
#define EPI_SHM_SIZE 4096U
#define EP_SHM_SIZE (sizeof(struct ep_share_info))
#define EP_FUTEX_WAIT 0
#define EP_FUTEX_NO_WAIT 1

#define EPI_WORKING    0x0
#define EPI_CLOSED     0x1

#define EPOLLIN_CACHE_EVENT 0x00000800U

#define EPOLL_RECHECK 0x00020000U

#define DEFAULT_POLLMASK (EPOLLIN | EPOLLOUT | EPOLLRDNORM | EPOLLWRNORM)

struct epoll_reg_info {
	uint64_t epi_shm_key;
	uint32_t epi_shm_index;
	uint64_t ep_shm_key;
};

struct epoll_pre_reg_info {
	uint64_t epi_shm_key;
	uint32_t epi_shm_index;
};

/*
 * server will use epoll_shm_tree to maintain all shm used for epoll, so one
 * shm only need to be mmapped once
 */
struct epoll_shm_tree {
	struct raw_mutex mutex;
	struct rbt_tree tree;
};

/*
 * shm_pool_entry is used to share events/revents/state/data between client and
 * server
 *
 * 'EPI_CLOSED' means the server has closed the fd, client should not poll any
 * events from the epitem with 'EPI_CLOSED'
 *
 * for forked epoll, if one epitem's 'epoll data' has changed, the forked epitem
 * should also get updated
 */
struct shm_pool_entry {
	raw_atomic_int_t events;
	raw_atomic_int_t revents;
	/* epitem's state is held here */
	raw_atomic_int_t state;
	raw_atomic_ullong_t data;
};

/*
 * shm_pool is pointed to share memory, and divided into several pieces,
 * 'shm_pool_entry'
 */
struct shm_pool {
	struct shm_pool_entry entries[0];
};

/*
 * meta is used to align bytes with shm_pool,
 * futex and number of CLOSED is put in ep shm
 */
struct ep_share_info {
	raw_atomic_int_t futex;
	raw_atomic_int_t close_num;
};

/*
 * all epi and ep shm will be hold in an epoll_shm_tree, epoll_shm is one node
 * of the tree
 *
 * If server wants to use the same shm, epoll_shm should be searched from
 * epoll_shm_tree and add refcnt
 */
struct epoll_shm {
	struct raw_refcnt_nr refcnt;
	uint64_t shm_key;
	int shm_fd;
	size_t shm_size;
	/* node of epoll_shm_tree */
	struct rbt_node node;
	union {
		void *rvaddr;
		struct shm_pool *shm_pool;
		struct ep_share_info *ep_share;
	};
};

/*
 * adding epfd to epfd is not supported yet, one epi_node is related to one
 * eventpoll
 */
struct epi_node {
	uint32_t epi_shm_index;
	__u32 client_cnode_idx;
	int fd;
	uint64_t key;
	/* node of epi_tree */
	struct rbt_node node;
	/* forked epi will be held in a list */
	struct dlist_node fork_node;
	struct epoll_shm *epi_shm;
	struct epoll_shm *ep_shm;
};

typedef int (*poll_batch_common_handler_t)(int fd, int op, bool is_epoll,
					   const struct epoll_reg_info *epoll_reg_info,
					   __u32 cnode_idx);

static inline uint32_t entry_atomic_read(raw_atomic_int_t *v)
{
	return (uint32_t)raw_atomic_int_read(v);
}

static inline void entry_atomic_set(raw_atomic_int_t *v, uint32_t val)
{
	(void)raw_atomic_int_set(v, (int)val);
}

void entry_atomic_add(raw_atomic_int_t *v, uint32_t val);
void entry_atomic_clear(raw_atomic_int_t *v, uint32_t val);
int epoll_add_with_key(struct rbt_tree *epi_tree, uint32_t revents,
		       const struct epoll_reg_info *epoll_reg_info,
		       const struct epi_node *node_info);
int epoll_add(struct rbt_tree *epi_tree, uint32_t revents,
	      const struct epoll_reg_info *epoll_reg_info,
	      __u32 client_cnode_idx, int fd);
int epoll_del(struct rbt_tree *epi_tree,
	      const struct epoll_reg_info *epoll_reg_info);
int epoll_mod(const struct rbt_tree *epi_tree, uint32_t revents,
	      const struct epoll_reg_info *epoll_reg_info);
void epoll_wakeup_with_key(const struct rbt_tree *epi_tree,
			   uint32_t revents, uint64_t key);
void epoll_wakeup(const struct rbt_tree *epi_tree, uint32_t revents);
void epoll_clean_revents_with_key(const struct rbt_tree *epi_tree,
				  uint32_t revents, uint64_t key);
void epoll_clean_revents(const struct rbt_tree *epi_tree, uint32_t revents);
void epoll_close_epi(struct rbt_tree *epi_tree, __u32 client_cnode_idx, int fd,
		     uint32_t revents);
void epoll_et_revents(const struct rbt_tree *epi_tree, uint64_t epi_shm_key,
		      uint32_t epi_shm_index, uint32_t *revents);
int epoll_reinit_add_with_key(struct rbt_tree *epi_tree,
			      const struct epoll_pre_reg_info *pre_info,
			      const struct epoll_reg_info *info,
			      const struct epi_node *node_info);
int epoll_reinit_add(struct rbt_tree *epi_tree,
		     const struct epoll_pre_reg_info *pre_info,
		     const struct epoll_reg_info *info, __u32 cnode_idx,
		     int fd);
int poll_batch_common(int op, struct epoll_reg_info *epoll_reg_info, __u32 cnode_idx,
		      const poll_batch_common_handler_t handle, bool is_poll);

#endif /* ULIBS_INCLUDE_LIBHMSRV_SYS_HM_SELECT_COMMON_H */
