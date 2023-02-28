/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for hmnet
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-network/git/ulibs/libevent/include/libsysif_net/api.sysif -I ../../../../../work-shared/hm-network/git/ulibs/libevent/include --api-dest ../image/usr/include/generated/sysif_client/net/libsysif_net/api.h --server-dest ../image/usr/include/generated/sysif_server/net/libsysif_net/service.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_HMNET_API_H
#define LIBSYSIF_HMNET_API_H
#ifndef LIBSYSIF_HMNET_COMMON_H
#define LIBSYSIF_HMNET_COMMON_H
#include <libsysif/utils_common.h>
#include <hongmeng/compiler.h>
#include <hongmeng/types.h>
#include <asm/actv_rpc.h>
#ifndef LIBSYSIF_BASE_API_COMMON_H
#define LIBSYSIF_BASE_API_COMMON_H
#include <stddef.h>
#include <stdint.h>
#include <hmkernel/capability.h>
struct sysif_reply_header {
	int32_t retval;
	uint32_t msgsz;
};

#define SYSIF_REPLY_LEN_MAX 256UL
extern void* hm_actvpool_prepare_ret(unsigned long long sender, unsigned long credential, unsigned long size);


extern struct arch_actv_local* hm_actv_current_arch_actv_local(void);


#endif
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>


#define NETTEST_BUF_LEN		64
struct sysif_nettest {
	char buf[NETTEST_BUF_LEN];
};



#include <netinet/in.h>
#include <net/if.h>

#define PROTOCOL_NAME_LEN_MAX	16
struct sysif_netif {
	char ifname[IF_NAMESIZE];
};

struct sysif_protocol {
	char protocol[PROTOCOL_NAME_LEN_MAX];
};




#include <net/if.h>
#include "hmnet_devices.h"

struct netdev_ifname {
	char name[IF_NAMESIZE];
};




enum vm_notify_cmd {
	VM_NOTIFY_VM_TX = 1,
	VM_NOTIFY_VQ_READY = 2,
};


raw_static_assert(sizeof(socklen_t) <= 96,
                    netcall_socket_bind_arg_len_is_too_large);
raw_static_assert(sizeof(socklen_t) <= 96,
                    netcall_socket_connect_arg_addrlen_is_too_large);
raw_static_assert(sizeof(socklen_t) <= 96,
                    netcall_socket_sendto_arg_addrlen_is_too_large);
raw_static_assert(sizeof(socklen_t) <= 96,
                    netcall_socket_setsockopt_arg_optlen_is_too_large);
raw_static_assert(sizeof(struct sysif_protocol) <= 96,
                    netcall_cfg_show_stats_arg_ss_protocol_is_too_large);
raw_static_assert(sizeof(enum hm_netdev_event) <= 96,
                    netcall_netdev_notify_arg_event_is_too_large);
raw_static_assert(sizeof(struct netdev_ifname) <= 96,
                    netcall_netdev_notify_arg_ifname_is_too_large);
struct __actvret_netcall_socket_revoke {
};

struct __actvret_netcall_socket_fork {
};

struct __actvret_netcall_socket_socket {
};

struct __actvret_netcall_socket_socketpair {
};

struct __actvret_netcall_socket_close {
};

struct __actvret_netcall_socket_shutdown {
};

struct __actvret_netcall_socket_bind {
};

struct __actvret_netcall_socket_listen {
};

struct __actvret_netcall_socket_accept {
};

struct __actvret_netcall_socket_connect {
};

struct __actvret_netcall_socket_send {
};

struct __actvret_netcall_socket_sendmsg {
};

struct __actvret_netcall_socket_recvmsg {
};

struct __actvret_netcall_socket_sendto {
};

struct __actvret_netcall_socket_recvfrom {
};

struct __actvret_netcall_socket_getsockopt {
};

struct __actvret_netcall_socket_setsockopt {
};

struct __actvret_netcall_socket_getsockname {
};

struct __actvret_netcall_socket_getpeername {
};

struct __actvret_netcall_socket_fcntl {
};

struct __actvret_netcall_socket_ioctl {
};

struct __actvret_netcall_socket_dup {
};

struct __actvret_netcall_socket_send_fd {
};

struct __actvret_netcall_socket_recv_fd {
};

struct __actvret_netcall_socket_put_send_fd {
};

struct __actvret_netcall_epoll_ctl {
};

struct __actvret_netcall_epoll_et_revents {
};

struct __actvret_netcall_epoll_reinit {
};

struct __actvret_netcall_cfg_loglevel {
};

struct __actvret_netcall_cfg_show_stats {
};

struct __actvret_netcall_cfg_getifaddrs {
};

struct __actvret_netcall_netdev_rx {
};

struct __actvret_netcall_netdev_notify {
};

struct __actvret_netcall_netdev_rx_ex_slowdata {
};

struct __actvret_netcall_procfs_read {
};

struct __actvret_netcall_procfs_write {
};

struct __actvret_netcall_procfs_fds_read {
};

struct __actvret_netcall_procfs_get_fd_path {
};

struct __actvret_netcall_netlink_register_generic {
	unsigned short familyid;
	unsigned int mcgrps_offset;
};

struct __actvret_netcall_netlink_unregister_generic {
};

struct __actvret_netcall_netlink_unicast {
};

struct __actvret_netcall_netlink_broadcast {
};

struct __actvret_netcall_vsock_register_vm {
};

struct __actvret_netcall_vsock_vm_notify {
};

struct __actvret_netcall_vsock_unregister_vm {
};

union __actvret_netcall {
	struct __actvret_netcall_socket_revoke socket_revoke;
	struct __actvret_netcall_socket_fork socket_fork;
	struct __actvret_netcall_socket_socket socket_socket;
	struct __actvret_netcall_socket_socketpair socket_socketpair;
	struct __actvret_netcall_socket_close socket_close;
	struct __actvret_netcall_socket_shutdown socket_shutdown;
	struct __actvret_netcall_socket_bind socket_bind;
	struct __actvret_netcall_socket_listen socket_listen;
	struct __actvret_netcall_socket_accept socket_accept;
	struct __actvret_netcall_socket_connect socket_connect;
	struct __actvret_netcall_socket_send socket_send;
	struct __actvret_netcall_socket_sendmsg socket_sendmsg;
	struct __actvret_netcall_socket_recvmsg socket_recvmsg;
	struct __actvret_netcall_socket_sendto socket_sendto;
	struct __actvret_netcall_socket_recvfrom socket_recvfrom;
	struct __actvret_netcall_socket_getsockopt socket_getsockopt;
	struct __actvret_netcall_socket_setsockopt socket_setsockopt;
	struct __actvret_netcall_socket_getsockname socket_getsockname;
	struct __actvret_netcall_socket_getpeername socket_getpeername;
	struct __actvret_netcall_socket_fcntl socket_fcntl;
	struct __actvret_netcall_socket_ioctl socket_ioctl;
	struct __actvret_netcall_socket_dup socket_dup;
	struct __actvret_netcall_socket_send_fd socket_send_fd;
	struct __actvret_netcall_socket_recv_fd socket_recv_fd;
	struct __actvret_netcall_socket_put_send_fd socket_put_send_fd;
	struct __actvret_netcall_epoll_ctl epoll_ctl;
	struct __actvret_netcall_epoll_et_revents epoll_et_revents;
	struct __actvret_netcall_epoll_reinit epoll_reinit;
	struct __actvret_netcall_cfg_loglevel cfg_loglevel;
	struct __actvret_netcall_cfg_show_stats cfg_show_stats;
	struct __actvret_netcall_cfg_getifaddrs cfg_getifaddrs;
	struct __actvret_netcall_netdev_rx netdev_rx;
	struct __actvret_netcall_netdev_notify netdev_notify;
	struct __actvret_netcall_netdev_rx_ex_slowdata netdev_rx_ex_slowdata;
	struct __actvret_netcall_procfs_read procfs_read;
	struct __actvret_netcall_procfs_write procfs_write;
	struct __actvret_netcall_procfs_fds_read procfs_fds_read;
	struct __actvret_netcall_procfs_get_fd_path procfs_get_fd_path;
	struct __actvret_netcall_netlink_register_generic netlink_register_generic;
	struct __actvret_netcall_netlink_unregister_generic netlink_unregister_generic;
	struct __actvret_netcall_netlink_unicast netlink_unicast;
	struct __actvret_netcall_netlink_broadcast netlink_broadcast;
	struct __actvret_netcall_vsock_register_vm vsock_register_vm;
	struct __actvret_netcall_vsock_vm_notify vsock_vm_notify;
	struct __actvret_netcall_vsock_unregister_vm vsock_unregister_vm;
};

enum __hmnet_mgr {
	__hmnet_INVAL_mgr=0,
	__hmnet_socket_mgr,
	__hmnet_epoll_mgr,
	__hmnet_cfg_mgr,
	__hmnet_netdev_mgr,
	__hmnet_procfs_mgr,
	__hmnet_netlink_mgr,
	__hmnet_vsock_mgr,
	__hmnet_MAX_mgr,
};

#define __hmnet_method_MIN __ACTV_HIGHTABLE_START
#define __hmnet_method_socket_revoke (__ACTV_HIGHTABLE_START + 1)
#define __hmnet_method_socket_fork (__ACTV_HIGHTABLE_START + 2)
#define __hmnet_method_socket_socket (__ACTV_HIGHTABLE_START + 3)
#define __hmnet_method_socket_socketpair (__ACTV_HIGHTABLE_START + 4)
#define __hmnet_method_socket_close (__ACTV_HIGHTABLE_START + 5)
#define __hmnet_method_socket_shutdown (__ACTV_HIGHTABLE_START + 6)
#define __hmnet_method_socket_bind (__ACTV_HIGHTABLE_START + 7)
#define __hmnet_method_socket_listen (__ACTV_HIGHTABLE_START + 8)
#define __hmnet_method_socket_accept (__ACTV_HIGHTABLE_START + 9)
#define __hmnet_method_socket_connect (__ACTV_HIGHTABLE_START + 10)
#define __hmnet_method_socket_send (__ACTV_HIGHTABLE_START + 11)
#define __hmnet_method_socket_sendmsg (__ACTV_HIGHTABLE_START + 12)
#define __hmnet_method_socket_recvmsg (__ACTV_HIGHTABLE_START + 13)
#define __hmnet_method_socket_sendto (__ACTV_HIGHTABLE_START + 14)
#define __hmnet_method_socket_recvfrom (__ACTV_HIGHTABLE_START + 15)
#define __hmnet_method_socket_getsockopt (__ACTV_HIGHTABLE_START + 16)
#define __hmnet_method_socket_setsockopt (__ACTV_HIGHTABLE_START + 17)
#define __hmnet_method_socket_getsockname (__ACTV_HIGHTABLE_START + 18)
#define __hmnet_method_socket_getpeername (__ACTV_HIGHTABLE_START + 19)
#define __hmnet_method_socket_fcntl (__ACTV_HIGHTABLE_START + 20)
#define __hmnet_method_socket_ioctl (__ACTV_HIGHTABLE_START + 21)
#define __hmnet_method_socket_dup (__ACTV_HIGHTABLE_START + 22)
#define __hmnet_method_socket_send_fd (__ACTV_HIGHTABLE_START + 23)
#define __hmnet_method_socket_recv_fd (__ACTV_HIGHTABLE_START + 24)
#define __hmnet_method_socket_put_send_fd (__ACTV_HIGHTABLE_START + 25)
#define __hmnet_method_socket_rsvd_7 (__ACTV_HIGHTABLE_START + 26)
#define __hmnet_method_socket_rsvd_6 (__ACTV_HIGHTABLE_START + 27)
#define __hmnet_method_socket_rsvd_5 (__ACTV_HIGHTABLE_START + 28)
#define __hmnet_method_socket_rsvd_4 (__ACTV_HIGHTABLE_START + 29)
#define __hmnet_method_socket_rsvd_3 (__ACTV_HIGHTABLE_START + 30)
#define __hmnet_method_socket_rsvd_2 (__ACTV_HIGHTABLE_START + 31)
#define __hmnet_method_socket_rsvd_1 (__ACTV_HIGHTABLE_START + 32)
#define __hmnet_method_epoll_ctl (__ACTV_HIGHTABLE_START + 33)
#define __hmnet_method_epoll_et_revents (__ACTV_HIGHTABLE_START + 34)
#define __hmnet_method_epoll_reinit (__ACTV_HIGHTABLE_START + 35)
#define __hmnet_method_epoll_rsvd_1 (__ACTV_HIGHTABLE_START + 36)
#define __hmnet_method_cfg_loglevel (__ACTV_HIGHTABLE_START + 37)
#define __hmnet_method_cfg_show_stats (__ACTV_HIGHTABLE_START + 38)
#define __hmnet_method_cfg_getifaddrs (__ACTV_HIGHTABLE_START + 39)
#define __hmnet_method_cfg_rsvd_1 (__ACTV_HIGHTABLE_START + 40)
#define __hmnet_method_netdev_rx (__ACTV_HIGHTABLE_START + 41)
#define __hmnet_method_netdev_notify (__ACTV_HIGHTABLE_START + 42)
#define __hmnet_method_netdev_rx_ex_slowdata (__ACTV_HIGHTABLE_START + 43)
#define __hmnet_method_netdev_rsvd_1 (__ACTV_HIGHTABLE_START + 44)
#define __hmnet_method_procfs_read (__ACTV_HIGHTABLE_START + 45)
#define __hmnet_method_procfs_write (__ACTV_HIGHTABLE_START + 46)
#define __hmnet_method_procfs_fds_read (__ACTV_HIGHTABLE_START + 47)
#define __hmnet_method_procfs_get_fd_path (__ACTV_HIGHTABLE_START + 48)
#define __hmnet_method_netlink_register_generic (__ACTV_HIGHTABLE_START + 49)
#define __hmnet_method_netlink_unregister_generic (__ACTV_HIGHTABLE_START + 50)
#define __hmnet_method_netlink_unicast (__ACTV_HIGHTABLE_START + 51)
#define __hmnet_method_netlink_broadcast (__ACTV_HIGHTABLE_START + 52)
#define __hmnet_method_netlink_rsvd_4 (__ACTV_HIGHTABLE_START + 53)
#define __hmnet_method_netlink_rsvd_3 (__ACTV_HIGHTABLE_START + 54)
#define __hmnet_method_netlink_rsvd_2 (__ACTV_HIGHTABLE_START + 55)
#define __hmnet_method_netlink_rsvd_1 (__ACTV_HIGHTABLE_START + 56)
#define __hmnet_method_vsock_register_vm (__ACTV_HIGHTABLE_START + 57)
#define __hmnet_method_vsock_vm_notify (__ACTV_HIGHTABLE_START + 58)
#define __hmnet_method_vsock_unregister_vm (__ACTV_HIGHTABLE_START + 59)
#define __hmnet_method_vsock_rsvd_1 (__ACTV_HIGHTABLE_START + 60)
#define __hmnet_method_MAX_NOCOMPAT (__ACTV_HIGHTABLE_START + 61)
#define __hmnet_method_MAX_COMPAT ((__ACTV_HIGHTABLE_START + 61) * 2)
raw_static_assert(sizeof(struct __actvret_netcall_socket_revoke) < 512,
                netcall_socket_revoke_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_fork) < 512,
                netcall_socket_fork_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_socket) < 512,
                netcall_socket_socket_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_socketpair) < 512,
                netcall_socket_socketpair_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_close) < 512,
                netcall_socket_close_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_shutdown) < 512,
                netcall_socket_shutdown_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_bind) < 512,
                netcall_socket_bind_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_listen) < 512,
                netcall_socket_listen_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_accept) < 512,
                netcall_socket_accept_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_connect) < 512,
                netcall_socket_connect_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_send) < 512,
                netcall_socket_send_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_sendmsg) < 512,
                netcall_socket_sendmsg_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_recvmsg) < 512,
                netcall_socket_recvmsg_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_sendto) < 512,
                netcall_socket_sendto_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_recvfrom) < 512,
                netcall_socket_recvfrom_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_getsockopt) < 512,
                netcall_socket_getsockopt_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_setsockopt) < 512,
                netcall_socket_setsockopt_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_getsockname) < 512,
                netcall_socket_getsockname_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_getpeername) < 512,
                netcall_socket_getpeername_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_fcntl) < 512,
                netcall_socket_fcntl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_ioctl) < 512,
                netcall_socket_ioctl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_dup) < 512,
                netcall_socket_dup_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_send_fd) < 512,
                netcall_socket_send_fd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_recv_fd) < 512,
                netcall_socket_recv_fd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_socket_put_send_fd) < 512,
                netcall_socket_put_send_fd_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_epoll_ctl) < 512,
                netcall_epoll_ctl_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_epoll_et_revents) < 512,
                netcall_epoll_et_revents_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_epoll_reinit) < 512,
                netcall_epoll_reinit_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_cfg_loglevel) < 512,
                netcall_cfg_loglevel_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_cfg_show_stats) < 512,
                netcall_cfg_show_stats_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_cfg_getifaddrs) < 512,
                netcall_cfg_getifaddrs_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_netdev_rx) < 512,
                netcall_netdev_rx_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_netdev_notify) < 512,
                netcall_netdev_notify_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_netdev_rx_ex_slowdata) < 512,
                netcall_netdev_rx_ex_slowdata_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_procfs_read) < 512,
                netcall_procfs_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_procfs_write) < 512,
                netcall_procfs_write_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_procfs_fds_read) < 512,
                netcall_procfs_fds_read_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_procfs_get_fd_path) < 512,
                netcall_procfs_get_fd_path_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_netlink_register_generic) < 512,
                netcall_netlink_register_generic_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_netlink_unregister_generic) < 512,
                netcall_netlink_unregister_generic_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_netlink_unicast) < 512,
                netcall_netlink_unicast_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_netlink_broadcast) < 512,
                netcall_netlink_broadcast_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_vsock_register_vm) < 512,
                netcall_vsock_register_vm_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_vsock_vm_notify) < 512,
                netcall_vsock_vm_notify_too_many_actvret_data);
raw_static_assert(sizeof(struct __actvret_netcall_vsock_unregister_vm) < 512,
                netcall_vsock_unregister_vm_too_many_actvret_data);
raw_static_assert(sizeof(union __actvret_netcall) < 512,
        netcall_too_many_actvret_data);
extern int __actvcall_netcall_socket_revoke(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_netcall_socket_revoke(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_revoke(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_socket_revoke;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_revoke(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_revoke(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_socket_revoke;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_revoke(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_revoke(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_netcall_socket_revoke(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_revoke(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_netcall_socket_revoke(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_netcall_socket_fork(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_netcall_socket_fork(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_fork(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_socket_fork;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_fork(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_fork(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_socket_fork;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_fork(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_fork(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_netcall_socket_fork(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_fork(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_netcall_socket_fork(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_netcall_socket_socket(unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd);


extern int __actvcapcall_netcall_socket_socket(rref_t __rref, unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_socket(bool is_xact_fwd, bool is_xact_allow_refwd, int domain, int type, int protocol, int fd)
{
	const unsigned long __callno = __hmnet_method_socket_socket;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_socket(rpc_info, NULL, domain, type, protocol, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_socket(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int domain, int type, int protocol, int fd)
{
	const unsigned long __callno = __hmnet_method_socket_socket;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_socket(__rref, rpc_info, NULL, domain, type, protocol, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_socket(int domain, int type, int protocol, int fd)
{
	return actvxactcall_netcall_socket_socket(false, false, domain, type, protocol, fd);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_socket(rref_t __rref, int domain, int type, int protocol, int fd)
{
	return actvxactcapcall_netcall_socket_socket(false, false, __rref, domain, type, protocol, fd);
}

extern int __actvcall_netcall_socket_socketpair(unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd, int fd2);


extern int __actvcapcall_netcall_socket_socketpair(rref_t __rref, unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd, int fd2);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_socketpair(bool is_xact_fwd, bool is_xact_allow_refwd, int domain, int type, int protocol, int fd, int fd2)
{
	const unsigned long __callno = __hmnet_method_socket_socketpair;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_socketpair(rpc_info, NULL, domain, type, protocol, fd, fd2);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_socketpair(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int domain, int type, int protocol, int fd, int fd2)
{
	const unsigned long __callno = __hmnet_method_socket_socketpair;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_socketpair(__rref, rpc_info, NULL, domain, type, protocol, fd, fd2);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_socketpair(int domain, int type, int protocol, int fd, int fd2)
{
	return actvxactcall_netcall_socket_socketpair(false, false, domain, type, protocol, fd, fd2);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_socketpair(rref_t __rref, int domain, int type, int protocol, int fd, int fd2)
{
	return actvxactcapcall_netcall_socket_socketpair(false, false, __rref, domain, type, protocol, fd, fd2);
}

extern int __actvcall_netcall_socket_close(unsigned long long __rpc_info, void *__buf, int fd);


extern int __actvcapcall_netcall_socket_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_close(bool is_xact_fwd, bool is_xact_allow_refwd, int fd)
{
	const unsigned long __callno = __hmnet_method_socket_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_close(rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_close(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd)
{
	const unsigned long __callno = __hmnet_method_socket_close;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_close(__rref, rpc_info, NULL, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_close(int fd)
{
	return actvxactcall_netcall_socket_close(false, false, fd);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_close(rref_t __rref, int fd)
{
	return actvxactcapcall_netcall_socket_close(false, false, __rref, fd);
}

extern int __actvcall_netcall_socket_shutdown(unsigned long long __rpc_info, void *__buf, int fd, int how);


extern int __actvcapcall_netcall_socket_shutdown(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int how);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_shutdown(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int how)
{
	const unsigned long __callno = __hmnet_method_socket_shutdown;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_shutdown(rpc_info, NULL, fd, how);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_shutdown(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int how)
{
	const unsigned long __callno = __hmnet_method_socket_shutdown;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_shutdown(__rref, rpc_info, NULL, fd, how);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_shutdown(int fd, int how)
{
	return actvxactcall_netcall_socket_shutdown(false, false, fd, how);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_shutdown(rref_t __rref, int fd, int how)
{
	return actvxactcapcall_netcall_socket_shutdown(false, false, __rref, fd, how);
}

extern int __actvcall_netcall_socket_bind(unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t len);


extern int __actvcapcall_netcall_socket_bind(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t len);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_bind(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *addr, socklen_t len)
{
	const unsigned long __callno = __hmnet_method_socket_bind;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_bind(rpc_info, NULL, fd, addr, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_bind(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *addr, socklen_t len)
{
	const unsigned long __callno = __hmnet_method_socket_bind;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_bind(__rref, rpc_info, NULL, fd, addr, len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_bind(int fd, const void *addr, socklen_t len)
{
	return actvxactcall_netcall_socket_bind(false, false, fd, addr, len);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_bind(rref_t __rref, int fd, const void *addr, socklen_t len)
{
	return actvxactcapcall_netcall_socket_bind(false, false, __rref, fd, addr, len);
}

extern int __actvcall_netcall_socket_listen(unsigned long long __rpc_info, void *__buf, int fd, int backlog);


extern int __actvcapcall_netcall_socket_listen(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int backlog);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_listen(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int backlog)
{
	const unsigned long __callno = __hmnet_method_socket_listen;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_listen(rpc_info, NULL, fd, backlog);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_listen(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int backlog)
{
	const unsigned long __callno = __hmnet_method_socket_listen;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_listen(__rref, rpc_info, NULL, fd, backlog);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_listen(int fd, int backlog)
{
	return actvxactcall_netcall_socket_listen(false, false, fd, backlog);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_listen(rref_t __rref, int fd, int backlog)
{
	return actvxactcapcall_netcall_socket_listen(false, false, __rref, fd, backlog);
}

extern int __actvcall_netcall_socket_accept(unsigned long long __rpc_info, void *__buf, int sockfd, void *addr, void *addrlen, int flags, int fd);


extern int __actvcapcall_netcall_socket_accept(rref_t __rref, unsigned long long __rpc_info, void *__buf, int sockfd, void *addr, void *addrlen, int flags, int fd);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_accept(bool is_xact_fwd, bool is_xact_allow_refwd, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	const unsigned long __callno = __hmnet_method_socket_accept;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_accept(rpc_info, NULL, sockfd, addr, addrlen, flags, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_accept(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	const unsigned long __callno = __hmnet_method_socket_accept;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_accept(__rref, rpc_info, NULL, sockfd, addr, addrlen, flags, fd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_accept(int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	return actvxactcall_netcall_socket_accept(false, false, sockfd, addr, addrlen, flags, fd);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_accept(rref_t __rref, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	return actvxactcapcall_netcall_socket_accept(false, false, __rref, sockfd, addr, addrlen, flags, fd);
}

extern int __actvcall_netcall_socket_connect(unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t addrlen);


extern int __actvcapcall_netcall_socket_connect(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t addrlen);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_connect(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *addr, socklen_t addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_connect;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_connect(rpc_info, NULL, fd, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_connect(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *addr, socklen_t addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_connect;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_connect(__rref, rpc_info, NULL, fd, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_connect(int fd, const void *addr, socklen_t addrlen)
{
	return actvxactcall_netcall_socket_connect(false, false, fd, addr, addrlen);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_connect(rref_t __rref, int fd, const void *addr, socklen_t addrlen)
{
	return actvxactcapcall_netcall_socket_connect(false, false, __rref, fd, addr, addrlen);
}

extern int __actvcall_netcall_socket_send(unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags);


extern int __actvcapcall_netcall_socket_send(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_send(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *buf, size_t len, int flags)
{
	const unsigned long __callno = __hmnet_method_socket_send;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_send(rpc_info, NULL, fd, buf, len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_send(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *buf, size_t len, int flags)
{
	const unsigned long __callno = __hmnet_method_socket_send;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_send(__rref, rpc_info, NULL, fd, buf, len, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_send(int fd, const void *buf, size_t len, int flags)
{
	return actvxactcall_netcall_socket_send(false, false, fd, buf, len, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_send(rref_t __rref, int fd, const void *buf, size_t len, int flags)
{
	return actvxactcapcall_netcall_socket_send(false, false, __rref, fd, buf, len, flags);
}

extern int __actvcall_netcall_socket_sendmsg(unsigned long long __rpc_info, void *__buf, int fd, const void *msg, int flags);


extern int __actvcapcall_netcall_socket_sendmsg(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *msg, int flags);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_sendmsg(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *msg, int flags)
{
	const unsigned long __callno = __hmnet_method_socket_sendmsg;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_sendmsg(rpc_info, NULL, fd, msg, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_sendmsg(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *msg, int flags)
{
	const unsigned long __callno = __hmnet_method_socket_sendmsg;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_sendmsg(__rref, rpc_info, NULL, fd, msg, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_sendmsg(int fd, const void *msg, int flags)
{
	return actvxactcall_netcall_socket_sendmsg(false, false, fd, msg, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_sendmsg(rref_t __rref, int fd, const void *msg, int flags)
{
	return actvxactcapcall_netcall_socket_sendmsg(false, false, __rref, fd, msg, flags);
}

extern int __actvcall_netcall_socket_recvmsg(unsigned long long __rpc_info, void *__buf, int fd, void *msg, int flags);


extern int __actvcapcall_netcall_socket_recvmsg(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *msg, int flags);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_recvmsg(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, void *msg, int flags)
{
	const unsigned long __callno = __hmnet_method_socket_recvmsg;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_recvmsg(rpc_info, NULL, fd, msg, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_recvmsg(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, void *msg, int flags)
{
	const unsigned long __callno = __hmnet_method_socket_recvmsg;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_recvmsg(__rref, rpc_info, NULL, fd, msg, flags);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_recvmsg(int fd, void *msg, int flags)
{
	return actvxactcall_netcall_socket_recvmsg(false, false, fd, msg, flags);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_recvmsg(rref_t __rref, int fd, void *msg, int flags)
{
	return actvxactcapcall_netcall_socket_recvmsg(false, false, __rref, fd, msg, flags);
}

extern int __actvcall_netcall_socket_sendto(unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);


extern int __actvcapcall_netcall_socket_sendto(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_sendto(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_sendto;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_sendto(rpc_info, NULL, fd, buf, len, flags, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_sendto(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_sendto;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_sendto(__rref, rpc_info, NULL, fd, buf, len, flags, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_sendto(int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	return actvxactcall_netcall_socket_sendto(false, false, fd, buf, len, flags, addr, addrlen);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_sendto(rref_t __rref, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	return actvxactcapcall_netcall_socket_sendto(false, false, __rref, fd, buf, len, flags, addr, addrlen);
}

extern int __actvcall_netcall_socket_recvfrom(unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);


extern int __actvcapcall_netcall_socket_recvfrom(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_recvfrom(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_recvfrom;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_recvfrom(rpc_info, NULL, fd, buf, len, flags, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_recvfrom(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_recvfrom;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_recvfrom(__rref, rpc_info, NULL, fd, buf, len, flags, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_recvfrom(int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	return actvxactcall_netcall_socket_recvfrom(false, false, fd, buf, len, flags, addr, addrlen);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_recvfrom(rref_t __rref, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	return actvxactcapcall_netcall_socket_recvfrom(false, false, __rref, fd, buf, len, flags, addr, addrlen);
}

extern int __actvcall_netcall_socket_getsockopt(unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, void *optval, socklen_t *optlen);


extern int __actvcapcall_netcall_socket_getsockopt(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, void *optval, socklen_t *optlen);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_getsockopt(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	const unsigned long __callno = __hmnet_method_socket_getsockopt;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t*), __arch_actv_rpc_stksz_alignment(socklen_t*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_getsockopt(rpc_info, NULL, fd, level, optname, optval, optlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_getsockopt(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	const unsigned long __callno = __hmnet_method_socket_getsockopt;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t*), __arch_actv_rpc_stksz_alignment(socklen_t*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_getsockopt(__rref, rpc_info, NULL, fd, level, optname, optval, optlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	return actvxactcall_netcall_socket_getsockopt(false, false, fd, level, optname, optval, optlen);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_getsockopt(rref_t __rref, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	return actvxactcapcall_netcall_socket_getsockopt(false, false, __rref, fd, level, optname, optval, optlen);
}

extern int __actvcall_netcall_socket_setsockopt(unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, const void *optval, socklen_t optlen);


extern int __actvcapcall_netcall_socket_setsockopt(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, const void *optval, socklen_t optlen);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_setsockopt(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	const unsigned long __callno = __hmnet_method_socket_setsockopt;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_setsockopt(rpc_info, NULL, fd, level, optname, optval, optlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_setsockopt(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	const unsigned long __callno = __hmnet_method_socket_setsockopt;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_setsockopt(__rref, rpc_info, NULL, fd, level, optname, optval, optlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	return actvxactcall_netcall_socket_setsockopt(false, false, fd, level, optname, optval, optlen);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_setsockopt(rref_t __rref, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	return actvxactcapcall_netcall_socket_setsockopt(false, false, __rref, fd, level, optname, optval, optlen);
}

extern int __actvcall_netcall_socket_getsockname(unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen);


extern int __actvcapcall_netcall_socket_getsockname(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_getsockname(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, void *addr, void *addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_getsockname;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_getsockname(rpc_info, NULL, fd, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_getsockname(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, void *addr, void *addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_getsockname;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_getsockname(__rref, rpc_info, NULL, fd, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_getsockname(int fd, void *addr, void *addrlen)
{
	return actvxactcall_netcall_socket_getsockname(false, false, fd, addr, addrlen);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_getsockname(rref_t __rref, int fd, void *addr, void *addrlen)
{
	return actvxactcapcall_netcall_socket_getsockname(false, false, __rref, fd, addr, addrlen);
}

extern int __actvcall_netcall_socket_getpeername(unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen);


extern int __actvcapcall_netcall_socket_getpeername(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_getpeername(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, void *addr, void *addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_getpeername;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_getpeername(rpc_info, NULL, fd, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_getpeername(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, void *addr, void *addrlen)
{
	const unsigned long __callno = __hmnet_method_socket_getpeername;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_getpeername(__rref, rpc_info, NULL, fd, addr, addrlen);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_getpeername(int fd, void *addr, void *addrlen)
{
	return actvxactcall_netcall_socket_getpeername(false, false, fd, addr, addrlen);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_getpeername(rref_t __rref, int fd, void *addr, void *addrlen)
{
	return actvxactcapcall_netcall_socket_getpeername(false, false, __rref, fd, addr, addrlen);
}

extern int __actvcall_netcall_socket_fcntl(unsigned long long __rpc_info, void *__buf, int fd, int cmd, int val);


extern int __actvcapcall_netcall_socket_fcntl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int cmd, int val);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_fcntl(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int cmd, int val)
{
	const unsigned long __callno = __hmnet_method_socket_fcntl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_fcntl(rpc_info, NULL, fd, cmd, val);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_fcntl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int cmd, int val)
{
	const unsigned long __callno = __hmnet_method_socket_fcntl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_fcntl(__rref, rpc_info, NULL, fd, cmd, val);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_fcntl(int fd, int cmd, int val)
{
	return actvxactcall_netcall_socket_fcntl(false, false, fd, cmd, val);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_fcntl(rref_t __rref, int fd, int cmd, int val)
{
	return actvxactcapcall_netcall_socket_fcntl(false, false, __rref, fd, cmd, val);
}

extern int __actvcall_netcall_socket_ioctl(unsigned long long __rpc_info, void *__buf, int fd, int request, unsigned long args);


extern int __actvcapcall_netcall_socket_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int request, unsigned long args);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, int fd, int request, unsigned long args)
{
	const unsigned long __callno = __hmnet_method_socket_ioctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_ioctl(rpc_info, NULL, fd, request, args);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_ioctl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int fd, int request, unsigned long args)
{
	const unsigned long __callno = __hmnet_method_socket_ioctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_ioctl(__rref, rpc_info, NULL, fd, request, args);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_ioctl(int fd, int request, unsigned long args)
{
	return actvxactcall_netcall_socket_ioctl(false, false, fd, request, args);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_ioctl(rref_t __rref, int fd, int request, unsigned long args)
{
	return actvxactcapcall_netcall_socket_ioctl(false, false, __rref, fd, request, args);
}

extern int __actvcall_netcall_socket_dup(unsigned long long __rpc_info, void *__buf, int oldfd, int newfd);


extern int __actvcapcall_netcall_socket_dup(rref_t __rref, unsigned long long __rpc_info, void *__buf, int oldfd, int newfd);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_dup(bool is_xact_fwd, bool is_xact_allow_refwd, int oldfd, int newfd)
{
	const unsigned long __callno = __hmnet_method_socket_dup;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_dup(rpc_info, NULL, oldfd, newfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_dup(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int oldfd, int newfd)
{
	const unsigned long __callno = __hmnet_method_socket_dup;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_dup(__rref, rpc_info, NULL, oldfd, newfd);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_dup(int oldfd, int newfd)
{
	return actvxactcall_netcall_socket_dup(false, false, oldfd, newfd);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_dup(rref_t __rref, int oldfd, int newfd)
{
	return actvxactcapcall_netcall_socket_dup(false, false, __rref, oldfd, newfd);
}

extern int __actvcall_netcall_socket_send_fd(unsigned long long __rpc_info, void *__buf, unsigned long argu_info);


extern int __actvcapcall_netcall_socket_send_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long argu_info);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_send_fd(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long argu_info)
{
	const unsigned long __callno = __hmnet_method_socket_send_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_send_fd(rpc_info, NULL, argu_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_send_fd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long argu_info)
{
	const unsigned long __callno = __hmnet_method_socket_send_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_send_fd(__rref, rpc_info, NULL, argu_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_send_fd(unsigned long argu_info)
{
	return actvxactcall_netcall_socket_send_fd(false, false, argu_info);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_send_fd(rref_t __rref, unsigned long argu_info)
{
	return actvxactcapcall_netcall_socket_send_fd(false, false, __rref, argu_info);
}

extern int __actvcall_netcall_socket_recv_fd(unsigned long long __rpc_info, void *__buf, unsigned long argu_info);


extern int __actvcapcall_netcall_socket_recv_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long argu_info);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_recv_fd(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long argu_info)
{
	const unsigned long __callno = __hmnet_method_socket_recv_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_recv_fd(rpc_info, NULL, argu_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_recv_fd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long argu_info)
{
	const unsigned long __callno = __hmnet_method_socket_recv_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_recv_fd(__rref, rpc_info, NULL, argu_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_recv_fd(unsigned long argu_info)
{
	return actvxactcall_netcall_socket_recv_fd(false, false, argu_info);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_recv_fd(rref_t __rref, unsigned long argu_info)
{
	return actvxactcapcall_netcall_socket_recv_fd(false, false, __rref, argu_info);
}

extern int __actvcall_netcall_socket_put_send_fd(unsigned long long __rpc_info, void *__buf, uintptr_t argu_info);


extern int __actvcapcall_netcall_socket_put_send_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, uintptr_t argu_info);


static inline int __attribute__((always_inline)) actvxactcall_netcall_socket_put_send_fd(bool is_xact_fwd, bool is_xact_allow_refwd, uintptr_t argu_info)
{
	const unsigned long __callno = __hmnet_method_socket_put_send_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_socket_put_send_fd(rpc_info, NULL, argu_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_socket_put_send_fd(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, uintptr_t argu_info)
{
	const unsigned long __callno = __hmnet_method_socket_put_send_fd;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_socket_put_send_fd(__rref, rpc_info, NULL, argu_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_socket_put_send_fd(uintptr_t argu_info)
{
	return actvxactcall_netcall_socket_put_send_fd(false, false, argu_info);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_socket_put_send_fd(rref_t __rref, uintptr_t argu_info)
{
	return actvxactcapcall_netcall_socket_put_send_fd(false, false, __rref, argu_info);
}

extern int __actvcall_netcall_epoll_ctl(unsigned long long __rpc_info, void *__buf, int socket_fd, int op, const void *epoll_reg_info);


extern int __actvcapcall_netcall_epoll_ctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int socket_fd, int op, const void *epoll_reg_info);


static inline int __attribute__((always_inline)) actvxactcall_netcall_epoll_ctl(bool is_xact_fwd, bool is_xact_allow_refwd, int socket_fd, int op, const void *epoll_reg_info)
{
	const unsigned long __callno = __hmnet_method_epoll_ctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_epoll_ctl(rpc_info, NULL, socket_fd, op, epoll_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_epoll_ctl(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int socket_fd, int op, const void *epoll_reg_info)
{
	const unsigned long __callno = __hmnet_method_epoll_ctl;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_epoll_ctl(__rref, rpc_info, NULL, socket_fd, op, epoll_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_epoll_ctl(int socket_fd, int op, const void *epoll_reg_info)
{
	return actvxactcall_netcall_epoll_ctl(false, false, socket_fd, op, epoll_reg_info);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_epoll_ctl(rref_t __rref, int socket_fd, int op, const void *epoll_reg_info)
{
	return actvxactcapcall_netcall_epoll_ctl(false, false, __rref, socket_fd, op, epoll_reg_info);
}

extern int __actvcall_netcall_epoll_et_revents(unsigned long long __rpc_info, void *__buf, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);


extern int __actvcapcall_netcall_epoll_et_revents(rref_t __rref, unsigned long long __rpc_info, void *__buf, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);


static inline int __attribute__((always_inline)) actvxactcall_netcall_epoll_et_revents(bool is_xact_fwd, bool is_xact_allow_refwd, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	const unsigned long __callno = __hmnet_method_epoll_et_revents;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_epoll_et_revents(rpc_info, NULL, socket_fd, epi_shm_key, epi_shm_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_epoll_et_revents(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	const unsigned long __callno = __hmnet_method_epoll_et_revents;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_epoll_et_revents(__rref, rpc_info, NULL, socket_fd, epi_shm_key, epi_shm_index);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_epoll_et_revents(int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	return actvxactcall_netcall_epoll_et_revents(false, false, socket_fd, epi_shm_key, epi_shm_index);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_epoll_et_revents(rref_t __rref, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	return actvxactcapcall_netcall_epoll_et_revents(false, false, __rref, socket_fd, epi_shm_key, epi_shm_index);
}

extern int __actvcall_netcall_epoll_reinit(unsigned long long __rpc_info, void *__buf, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);


extern int __actvcapcall_netcall_epoll_reinit(rref_t __rref, unsigned long long __rpc_info, void *__buf, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);


static inline int __attribute__((always_inline)) actvxactcall_netcall_epoll_reinit(bool is_xact_fwd, bool is_xact_allow_refwd, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	const unsigned long __callno = __hmnet_method_epoll_reinit;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_epoll_reinit(rpc_info, NULL, socket_fd, epoll_pre_reg_info, epoll_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_epoll_reinit(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	const unsigned long __callno = __hmnet_method_epoll_reinit;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_epoll_reinit(__rref, rpc_info, NULL, socket_fd, epoll_pre_reg_info, epoll_reg_info);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_epoll_reinit(int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	return actvxactcall_netcall_epoll_reinit(false, false, socket_fd, epoll_pre_reg_info, epoll_reg_info);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_epoll_reinit(rref_t __rref, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	return actvxactcapcall_netcall_epoll_reinit(false, false, __rref, socket_fd, epoll_pre_reg_info, epoll_reg_info);
}

extern int __actvcall_netcall_cfg_loglevel(unsigned long long __rpc_info, void *__buf, unsigned int loglevel);


extern int __actvcapcall_netcall_cfg_loglevel(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int loglevel);


static inline int __attribute__((always_inline)) actvxactcall_netcall_cfg_loglevel(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int loglevel)
{
	const unsigned long __callno = __hmnet_method_cfg_loglevel;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_cfg_loglevel(rpc_info, NULL, loglevel);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_cfg_loglevel(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int loglevel)
{
	const unsigned long __callno = __hmnet_method_cfg_loglevel;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_cfg_loglevel(__rref, rpc_info, NULL, loglevel);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_cfg_loglevel(unsigned int loglevel)
{
	return actvxactcall_netcall_cfg_loglevel(false, false, loglevel);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_cfg_loglevel(rref_t __rref, unsigned int loglevel)
{
	return actvxactcapcall_netcall_cfg_loglevel(false, false, __rref, loglevel);
}

extern int __actvcall_netcall_cfg_show_stats(unsigned long long __rpc_info, void *__buf, struct sysif_protocol ss_protocol, unsigned long long shm_key);


extern int __actvcapcall_netcall_cfg_show_stats(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct sysif_protocol ss_protocol, unsigned long long shm_key);


static inline int __attribute__((always_inline)) actvxactcall_netcall_cfg_show_stats(bool is_xact_fwd, bool is_xact_allow_refwd, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	const unsigned long __callno = __hmnet_method_cfg_show_stats;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysif_protocol), __arch_actv_rpc_stksz_alignment(struct sysif_protocol));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_cfg_show_stats(rpc_info, NULL, ss_protocol, shm_key);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_cfg_show_stats(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	const unsigned long __callno = __hmnet_method_cfg_show_stats;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysif_protocol), __arch_actv_rpc_stksz_alignment(struct sysif_protocol));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_cfg_show_stats(__rref, rpc_info, NULL, ss_protocol, shm_key);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_cfg_show_stats(struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	return actvxactcall_netcall_cfg_show_stats(false, false, ss_protocol, shm_key);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_cfg_show_stats(rref_t __rref, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	return actvxactcapcall_netcall_cfg_show_stats(false, false, __rref, ss_protocol, shm_key);
}

extern int __actvcall_netcall_cfg_getifaddrs(unsigned long long __rpc_info, void *__buf, unsigned long long shm_key);


extern int __actvcapcall_netcall_cfg_getifaddrs(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long shm_key);


static inline int __attribute__((always_inline)) actvxactcall_netcall_cfg_getifaddrs(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long long shm_key)
{
	const unsigned long __callno = __hmnet_method_cfg_getifaddrs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_cfg_getifaddrs(rpc_info, NULL, shm_key);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_cfg_getifaddrs(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long long shm_key)
{
	const unsigned long __callno = __hmnet_method_cfg_getifaddrs;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_cfg_getifaddrs(__rref, rpc_info, NULL, shm_key);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_cfg_getifaddrs(unsigned long long shm_key)
{
	return actvxactcall_netcall_cfg_getifaddrs(false, false, shm_key);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_cfg_getifaddrs(rref_t __rref, unsigned long long shm_key)
{
	return actvxactcapcall_netcall_cfg_getifaddrs(false, false, __rref, shm_key);
}

extern int __actvcall_netcall_netdev_rx(unsigned long long __rpc_info, void *__buf, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);


extern int __actvcapcall_netcall_netdev_rx(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);


static inline int __attribute__((always_inline)) actvxactcall_netcall_netdev_rx(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	const unsigned long __callno = __hmnet_method_netdev_rx;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_netdev_rx(rpc_info, NULL, cell_pool_offset, shm_len, rx_len, offset, devno);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_netdev_rx(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	const unsigned long __callno = __hmnet_method_netdev_rx;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_netdev_rx(__rref, rpc_info, NULL, cell_pool_offset, shm_len, rx_len, offset, devno);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_netdev_rx(unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	return actvxactcall_netcall_netdev_rx(false, false, cell_pool_offset, shm_len, rx_len, offset, devno);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_netdev_rx(rref_t __rref, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	return actvxactcapcall_netcall_netdev_rx(false, false, __rref, cell_pool_offset, shm_len, rx_len, offset, devno);
}

extern int __actvcall_netcall_netdev_notify(unsigned long long __rpc_info, void *__buf, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);


extern int __actvcapcall_netcall_netdev_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);


static inline int __attribute__((always_inline)) actvxactcall_netcall_netdev_notify(bool is_xact_fwd, bool is_xact_allow_refwd, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	const unsigned long __callno = __hmnet_method_netdev_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum hm_netdev_event), __arch_actv_rpc_stksz_alignment(enum hm_netdev_event));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct netdev_ifname), __arch_actv_rpc_stksz_alignment(struct netdev_ifname));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_netdev_notify(rpc_info, NULL, event, devno, option, ifname, features);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_netdev_notify(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	const unsigned long __callno = __hmnet_method_netdev_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum hm_netdev_event), __arch_actv_rpc_stksz_alignment(enum hm_netdev_event));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct netdev_ifname), __arch_actv_rpc_stksz_alignment(struct netdev_ifname));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_netdev_notify(__rref, rpc_info, NULL, event, devno, option, ifname, features);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_netdev_notify(enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	return actvxactcall_netcall_netdev_notify(false, false, event, devno, option, ifname, features);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_netdev_notify(rref_t __rref, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	return actvxactcapcall_netcall_netdev_notify(false, false, __rref, event, devno, option, ifname, features);
}

extern int __actvcall_netcall_netdev_rx_ex_slowdata(unsigned long long __rpc_info, void *__buf, int num);


extern int __actvcapcall_netcall_netdev_rx_ex_slowdata(rref_t __rref, unsigned long long __rpc_info, void *__buf, int num);


static inline int __attribute__((always_inline)) actvxactcall_netcall_netdev_rx_ex_slowdata(bool is_xact_fwd, bool is_xact_allow_refwd, int num, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_netdev_rx_ex_slowdata;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_netdev_rx_ex_slowdata(rpc_info, ___void_buf, num);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_netdev_rx_ex_slowdata(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int num, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_netdev_rx_ex_slowdata;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_netdev_rx_ex_slowdata(__rref, rpc_info, ___void_buf, num);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_netdev_rx_ex_slowdata(int num, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_netcall_netdev_rx_ex_slowdata(false, false, num, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_netdev_rx_ex_slowdata(rref_t __rref, int num, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_netcall_netdev_rx_ex_slowdata(false, false, __rref, num, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_netcall_procfs_read(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_netcall_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_netcall_procfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_procfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_procfs_read(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_procfs_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_procfs_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_procfs_read(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_procfs_read(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_netcall_procfs_read(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_procfs_read(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_netcall_procfs_read(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_netcall_procfs_write(unsigned long long __rpc_info, void *__buf);


extern int __actvcapcall_netcall_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf);


static inline int __attribute__((always_inline)) actvxactcall_netcall_procfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_procfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_procfs_write(rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_procfs_write(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_procfs_write;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_procfs_write(__rref, rpc_info, ___void_buf);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_procfs_write(void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_netcall_procfs_write(false, false, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_procfs_write(rref_t __rref, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_netcall_procfs_write(false, false, __rref, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_netcall_procfs_fds_read(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);


extern int __actvcapcall_netcall_procfs_fds_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);


static inline int __attribute__((always_inline)) actvxactcall_netcall_procfs_fds_read(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	const unsigned long __callno = __hmnet_method_procfs_fds_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_procfs_fds_read(rpc_info, NULL, cnode_idx, fd_map, max_files);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_procfs_fds_read(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	const unsigned long __callno = __hmnet_method_procfs_fds_read;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_procfs_fds_read(__rref, rpc_info, NULL, cnode_idx, fd_map, max_files);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_procfs_fds_read(unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	return actvxactcall_netcall_procfs_fds_read(false, false, cnode_idx, fd_map, max_files);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_procfs_fds_read(rref_t __rref, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	return actvxactcapcall_netcall_procfs_fds_read(false, false, __rref, cnode_idx, fd_map, max_files);
}

extern int __actvcall_netcall_procfs_get_fd_path(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);


extern int __actvcapcall_netcall_procfs_get_fd_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);


static inline int __attribute__((always_inline)) actvxactcall_netcall_procfs_get_fd_path(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	const unsigned long __callno = __hmnet_method_procfs_get_fd_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_procfs_get_fd_path(rpc_info, NULL, cnode_idx, fd, path_buf, path_buf_len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_procfs_get_fd_path(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	const unsigned long __callno = __hmnet_method_procfs_get_fd_path;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_procfs_get_fd_path(__rref, rpc_info, NULL, cnode_idx, fd, path_buf, path_buf_len);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_procfs_get_fd_path(unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	return actvxactcall_netcall_procfs_get_fd_path(false, false, cnode_idx, fd, path_buf, path_buf_len);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_procfs_get_fd_path(rref_t __rref, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	return actvxactcapcall_netcall_procfs_get_fd_path(false, false, __rref, cnode_idx, fd, path_buf, path_buf_len);
}

extern int __actvcall_netcall_netlink_register_generic(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned long long dh_ap_uref);


extern int __actvcapcall_netcall_netlink_register_generic(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned long long dh_ap_uref);


static inline int __attribute__((always_inline)) actvxactcall_netcall_netlink_register_generic(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned long long dh_ap_uref, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_netcall_netlink_register_generic *__ret)
{
	const unsigned long __callno = __hmnet_method_netlink_register_generic;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_netlink_register_generic(rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dh_ap_uref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_netlink_register_generic(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned long long dh_ap_uref, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_netcall_netlink_register_generic *__ret)
{
	const unsigned long __callno = __hmnet_method_netlink_register_generic;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_netlink_register_generic(__rref, rpc_info, ___void_buf, ptr_to_void(__ret), sizeof*__ret, dh_ap_uref);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_netlink_register_generic(unsigned long long dh_ap_uref, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_netcall_netlink_register_generic *__ret)
{
	return actvxactcall_netcall_netlink_register_generic(false, false, dh_ap_uref, ___void_buf, ___void_buf_sz, __ret);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_netlink_register_generic(rref_t __rref, unsigned long long dh_ap_uref, void *___void_buf, unsigned long ___void_buf_sz, struct __actvret_netcall_netlink_register_generic *__ret)
{
	return actvxactcapcall_netcall_netlink_register_generic(false, false, __rref, dh_ap_uref, ___void_buf, ___void_buf_sz, __ret);
}

extern int __actvcall_netcall_netlink_unregister_generic(unsigned long long __rpc_info, void *__buf, unsigned short familyid);


extern int __actvcapcall_netcall_netlink_unregister_generic(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned short familyid);


static inline int __attribute__((always_inline)) actvxactcall_netcall_netlink_unregister_generic(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned short familyid)
{
	const unsigned long __callno = __hmnet_method_netlink_unregister_generic;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_netlink_unregister_generic(rpc_info, NULL, familyid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_netlink_unregister_generic(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned short familyid)
{
	const unsigned long __callno = __hmnet_method_netlink_unregister_generic;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_netlink_unregister_generic(__rref, rpc_info, NULL, familyid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_netlink_unregister_generic(unsigned short familyid)
{
	return actvxactcall_netcall_netlink_unregister_generic(false, false, familyid);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_netlink_unregister_generic(rref_t __rref, unsigned short familyid)
{
	return actvxactcapcall_netcall_netlink_unregister_generic(false, false, __rref, familyid);
}

extern int __actvcall_netcall_netlink_unicast(unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_port);


extern int __actvcapcall_netcall_netlink_unicast(rref_t __rref, unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_port);


static inline int __attribute__((always_inline)) actvxactcall_netcall_netlink_unicast(bool is_xact_fwd, bool is_xact_allow_refwd, int protocol, unsigned int src_portid, unsigned int dst_port, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_netlink_unicast;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_netlink_unicast(rpc_info, ___void_buf, protocol, src_portid, dst_port);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_netlink_unicast(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int protocol, unsigned int src_portid, unsigned int dst_port, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_netlink_unicast;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_netlink_unicast(__rref, rpc_info, ___void_buf, protocol, src_portid, dst_port);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_netlink_unicast(int protocol, unsigned int src_portid, unsigned int dst_port, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_netcall_netlink_unicast(false, false, protocol, src_portid, dst_port, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_netlink_unicast(rref_t __rref, int protocol, unsigned int src_portid, unsigned int dst_port, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_netcall_netlink_unicast(false, false, __rref, protocol, src_portid, dst_port, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_netcall_netlink_broadcast(unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_group);


extern int __actvcapcall_netcall_netlink_broadcast(rref_t __rref, unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_group);


static inline int __attribute__((always_inline)) actvxactcall_netcall_netlink_broadcast(bool is_xact_fwd, bool is_xact_allow_refwd, int protocol, unsigned int src_portid, unsigned int dst_group, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_netlink_broadcast;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_netlink_broadcast(rpc_info, ___void_buf, protocol, src_portid, dst_group);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_netlink_broadcast(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, int protocol, unsigned int src_portid, unsigned int dst_group, void *___void_buf, unsigned long ___void_buf_sz)
{
	const unsigned long __callno = __hmnet_method_netlink_broadcast;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, ___void_buf_sz, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_netlink_broadcast(__rref, rpc_info, ___void_buf, protocol, src_portid, dst_group);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_netlink_broadcast(int protocol, unsigned int src_portid, unsigned int dst_group, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcall_netcall_netlink_broadcast(false, false, protocol, src_portid, dst_group, ___void_buf, ___void_buf_sz);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_netlink_broadcast(rref_t __rref, int protocol, unsigned int src_portid, unsigned int dst_group, void *___void_buf, unsigned long ___void_buf_sz)
{
	return actvxactcapcall_netcall_netlink_broadcast(false, false, __rref, protocol, src_portid, dst_group, ___void_buf, ___void_buf_sz);
}

extern int __actvcall_netcall_vsock_register_vm(unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned int dev_group_id);


extern int __actvcapcall_netcall_vsock_register_vm(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned int dev_group_id);


static inline int __attribute__((always_inline)) actvxactcall_netcall_vsock_register_vm(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cid, unsigned int dev_group_id)
{
	const unsigned long __callno = __hmnet_method_vsock_register_vm;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_vsock_register_vm(rpc_info, NULL, cid, dev_group_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_vsock_register_vm(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cid, unsigned int dev_group_id)
{
	const unsigned long __callno = __hmnet_method_vsock_register_vm;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_vsock_register_vm(__rref, rpc_info, NULL, cid, dev_group_id);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_vsock_register_vm(unsigned int cid, unsigned int dev_group_id)
{
	return actvxactcall_netcall_vsock_register_vm(false, false, cid, dev_group_id);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_vsock_register_vm(rref_t __rref, unsigned int cid, unsigned int dev_group_id)
{
	return actvxactcapcall_netcall_vsock_register_vm(false, false, __rref, cid, dev_group_id);
}

extern int __actvcall_netcall_vsock_vm_notify(unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned short cmd, void *args, size_t size);


extern int __actvcapcall_netcall_vsock_vm_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned short cmd, void *args, size_t size);


static inline int __attribute__((always_inline)) actvxactcall_netcall_vsock_vm_notify(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	const unsigned long __callno = __hmnet_method_vsock_vm_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_vsock_vm_notify(rpc_info, NULL, cid, cmd, args, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_vsock_vm_notify(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	const unsigned long __callno = __hmnet_method_vsock_vm_notify;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_vsock_vm_notify(__rref, rpc_info, NULL, cid, cmd, args, size);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_vsock_vm_notify(unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	return actvxactcall_netcall_vsock_vm_notify(false, false, cid, cmd, args, size);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_vsock_vm_notify(rref_t __rref, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	return actvxactcapcall_netcall_vsock_vm_notify(false, false, __rref, cid, cmd, args, size);
}

extern int __actvcall_netcall_vsock_unregister_vm(unsigned long long __rpc_info, void *__buf, unsigned int cid);


extern int __actvcapcall_netcall_vsock_unregister_vm(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cid);


static inline int __attribute__((always_inline)) actvxactcall_netcall_vsock_unregister_vm(bool is_xact_fwd, bool is_xact_allow_refwd, unsigned int cid)
{
	const unsigned long __callno = __hmnet_method_vsock_unregister_vm;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcall_netcall_vsock_unregister_vm(rpc_info, NULL, cid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvxactcapcall_netcall_vsock_unregister_vm(bool is_xact_fwd, bool is_xact_allow_refwd, rref_t __rref, unsigned int cid)
{
	const unsigned long __callno = __hmnet_method_vsock_unregister_vm;
	int __res;
	unsigned long __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	do {
		unsigned long long rpc_info = __arch_actv_xact_rpc_info_gen(is_xact_fwd, is_xact_allow_refwd, __callno, 0UL, __stacksz / sizeof(unsigned long));
		__res = __actvcapcall_netcall_vsock_unregister_vm(__rref, rpc_info, NULL, cid);
	} while (__res == (int)E_HM_ACTIVATION_RPC_RETRY);
	return __res;
}

static inline int __attribute__((always_inline)) actvcall_netcall_vsock_unregister_vm(unsigned int cid)
{
	return actvxactcall_netcall_vsock_unregister_vm(false, false, cid);
}

static inline int __attribute__((always_inline)) actvcapcall_netcall_vsock_unregister_vm(rref_t __rref, unsigned int cid)
{
	return actvxactcapcall_netcall_vsock_unregister_vm(false, false, __rref, cid);
}

#endif
#ifdef SYSIF_GEN_IFACE
#include <hmkernel/compiler.h>
#include <asm/actv_rpc.h>
#include <hongmeng/errno.h>
#include <hongmeng/syscall.h>
#include <hongmeng/panic.h>
#include <libstrict/strict.h>
static int __used __noinline __opt_noframe __internal_rpccall_nobuf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_buf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_retbuf(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccall_fallback(void)
{
	hm_panic("calling unimplemented actvcall. Use actvcapcall or ebbcall instead\n");
	return E_HM_NOSYS;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_nobuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(NoBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_buf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(SendBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_retbuf(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(RetBuf, ret);
	return ret;
}

static int __used __noinline __opt_noframe __internal_rpccapcall_fallback(void)
{
	__RPC_DEF_RETVAR(int, ret);
	__RPC_CAP_SYSCALL(, ret);
	return ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_netcall_socket_revoke(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_netcall_socket_revoke(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_revoke(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_netcall_socket_revoke(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_revoke(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_netcall_socket_revoke(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_netcall_socket_fork(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_netcall_socket_fork(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_fork(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_netcall_socket_fork(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_fork(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_netcall_socket_fork(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_socket(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_socket(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_socket(unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_domain = domain;
	int __maybe_unused __actv_local_var_type = type;
	int __maybe_unused __actv_local_var_protocol = protocol;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_netcall_socket_socket(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(domain, __actv_local_var_domain), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_socket(rref_t __rref, unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_domain = domain;
	int __maybe_unused __actv_local_var_type = type;
	int __maybe_unused __actv_local_var_protocol = protocol;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_netcall_socket_socket(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(domain, __actv_local_var_domain), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_socketpair(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_socketpair(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_socketpair(unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd, int fd2)
{
	int __ret;
	int __maybe_unused __actv_local_var_domain = domain;
	int __maybe_unused __actv_local_var_type = type;
	int __maybe_unused __actv_local_var_protocol = protocol;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_fd2 = fd2;
	__ret = ____actvcall_netcall_socket_socketpair(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(domain, __actv_local_var_domain), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(fd2, __actv_local_var_fd2));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_socketpair(rref_t __rref, unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd, int fd2)
{
	int __ret;
	int __maybe_unused __actv_local_var_domain = domain;
	int __maybe_unused __actv_local_var_type = type;
	int __maybe_unused __actv_local_var_protocol = protocol;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_fd2 = fd2;
	__ret = ____actvcapcall_netcall_socket_socketpair(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(domain, __actv_local_var_domain), __ARCH_ACTV_RPC_PASS_ARG(type, __actv_local_var_type), __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(fd2, __actv_local_var_fd2));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_close(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_close(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_close(unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_netcall_socket_close(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_netcall_socket_close(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_shutdown(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_shutdown(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_shutdown(unsigned long long __rpc_info, void *__buf, int fd, int how)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_how = how;
	__ret = ____actvcall_netcall_socket_shutdown(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(how, __actv_local_var_how));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_shutdown(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int how)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_how = how;
	__ret = ____actvcapcall_netcall_socket_shutdown(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(how, __actv_local_var_how));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_bind(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_bind(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_bind(unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t len)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_addr = addr;
	socklen_t __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcall_netcall_socket_bind(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_bind(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t len)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_addr = addr;
	socklen_t __maybe_unused __actv_local_var_len = len;
	__ret = ____actvcapcall_netcall_socket_bind(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_listen(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_listen(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_listen(unsigned long long __rpc_info, void *__buf, int fd, int backlog)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_backlog = backlog;
	__ret = ____actvcall_netcall_socket_listen(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(backlog, __actv_local_var_backlog));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_listen(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int backlog)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_backlog = backlog;
	__ret = ____actvcapcall_netcall_socket_listen(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(backlog, __actv_local_var_backlog));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_accept(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_accept(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_accept(unsigned long long __rpc_info, void *__buf, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_sockfd = sockfd;
	__maybe_unused void *__actv_local_var_addr = addr;
	__maybe_unused void *__actv_local_var_addrlen = addrlen;
	int __maybe_unused __actv_local_var_flags = flags;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcall_netcall_socket_accept(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sockfd, __actv_local_var_sockfd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_accept(rref_t __rref, unsigned long long __rpc_info, void *__buf, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	int __ret;
	int __maybe_unused __actv_local_var_sockfd = sockfd;
	__maybe_unused void *__actv_local_var_addr = addr;
	__maybe_unused void *__actv_local_var_addrlen = addrlen;
	int __maybe_unused __actv_local_var_flags = flags;
	int __maybe_unused __actv_local_var_fd = fd;
	__ret = ____actvcapcall_netcall_socket_accept(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(sockfd, __actv_local_var_sockfd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_connect(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_connect(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_connect(unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_addr = addr;
	socklen_t __maybe_unused __actv_local_var_addrlen = addrlen;
	__ret = ____actvcall_netcall_socket_connect(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_connect(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_addr = addr;
	socklen_t __maybe_unused __actv_local_var_addrlen = addrlen;
	__ret = ____actvcapcall_netcall_socket_connect(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_send(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_send(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_send(unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_netcall_socket_send(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_send(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_netcall_socket_send(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_sendmsg(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_sendmsg(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_sendmsg(unsigned long long __rpc_info, void *__buf, int fd, const void *msg, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_msg = msg;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_netcall_socket_sendmsg(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_sendmsg(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *msg, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_msg = msg;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_netcall_socket_sendmsg(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_recvmsg(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_recvmsg(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_recvmsg(unsigned long long __rpc_info, void *__buf, int fd, void *msg, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_msg = msg;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcall_netcall_socket_recvmsg(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_recvmsg(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *msg, int flags)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_msg = msg;
	int __maybe_unused __actv_local_var_flags = flags;
	__ret = ____actvcapcall_netcall_socket_recvmsg(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(msg, __actv_local_var_msg), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_sendto(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_sendto(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_sendto(unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused const void *__actv_local_var_addr = addr;
	socklen_t __maybe_unused __actv_local_var_addrlen = addrlen;
	__ret = ____actvcall_netcall_socket_sendto(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_sendto(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused const void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused const void *__actv_local_var_addr = addr;
	socklen_t __maybe_unused __actv_local_var_addrlen = addrlen;
	__ret = ____actvcapcall_netcall_socket_sendto(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_recvfrom(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_recvfrom(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_recvfrom(unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused void *__actv_local_var_addr = addr;
	__maybe_unused void *__actv_local_var_addrlen = addrlen;
	__ret = ____actvcall_netcall_socket_recvfrom(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_recvfrom(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_buf = buf;
	size_t __maybe_unused __actv_local_var_len = len;
	int __maybe_unused __actv_local_var_flags = flags;
	__maybe_unused void *__actv_local_var_addr = addr;
	__maybe_unused void *__actv_local_var_addrlen = addrlen;
	__ret = ____actvcapcall_netcall_socket_recvfrom(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(buf, __actv_local_var_buf), __ARCH_ACTV_RPC_PASS_ARG(len, __actv_local_var_len), __ARCH_ACTV_RPC_PASS_ARG(flags, __actv_local_var_flags), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_getsockopt(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_getsockopt(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_getsockopt(unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_level = level;
	int __maybe_unused __actv_local_var_optname = optname;
	__maybe_unused void *__actv_local_var_optval = optval;
	__maybe_unused socklen_t *__actv_local_var_optlen = optlen;
	__ret = ____actvcall_netcall_socket_getsockopt(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(level, __actv_local_var_level), __ARCH_ACTV_RPC_PASS_ARG(optname, __actv_local_var_optname), __ARCH_ACTV_RPC_PASS_ARG(optval, __actv_local_var_optval), __ARCH_ACTV_RPC_PASS_ARG(optlen, __actv_local_var_optlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_getsockopt(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_level = level;
	int __maybe_unused __actv_local_var_optname = optname;
	__maybe_unused void *__actv_local_var_optval = optval;
	__maybe_unused socklen_t *__actv_local_var_optlen = optlen;
	__ret = ____actvcapcall_netcall_socket_getsockopt(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(level, __actv_local_var_level), __ARCH_ACTV_RPC_PASS_ARG(optname, __actv_local_var_optname), __ARCH_ACTV_RPC_PASS_ARG(optval, __actv_local_var_optval), __ARCH_ACTV_RPC_PASS_ARG(optlen, __actv_local_var_optlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_setsockopt(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_setsockopt(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_setsockopt(unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_level = level;
	int __maybe_unused __actv_local_var_optname = optname;
	__maybe_unused const void *__actv_local_var_optval = optval;
	socklen_t __maybe_unused __actv_local_var_optlen = optlen;
	__ret = ____actvcall_netcall_socket_setsockopt(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(level, __actv_local_var_level), __ARCH_ACTV_RPC_PASS_ARG(optname, __actv_local_var_optname), __ARCH_ACTV_RPC_PASS_ARG(optval, __actv_local_var_optval), __ARCH_ACTV_RPC_PASS_ARG(optlen, __actv_local_var_optlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_setsockopt(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_level = level;
	int __maybe_unused __actv_local_var_optname = optname;
	__maybe_unused const void *__actv_local_var_optval = optval;
	socklen_t __maybe_unused __actv_local_var_optlen = optlen;
	__ret = ____actvcapcall_netcall_socket_setsockopt(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(level, __actv_local_var_level), __ARCH_ACTV_RPC_PASS_ARG(optname, __actv_local_var_optname), __ARCH_ACTV_RPC_PASS_ARG(optval, __actv_local_var_optval), __ARCH_ACTV_RPC_PASS_ARG(optlen, __actv_local_var_optlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_getsockname(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_getsockname(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_getsockname(unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_addr = addr;
	__maybe_unused void *__actv_local_var_addrlen = addrlen;
	__ret = ____actvcall_netcall_socket_getsockname(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_getsockname(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_addr = addr;
	__maybe_unused void *__actv_local_var_addrlen = addrlen;
	__ret = ____actvcapcall_netcall_socket_getsockname(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_getpeername(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_getpeername(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_getpeername(unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_addr = addr;
	__maybe_unused void *__actv_local_var_addrlen = addrlen;
	__ret = ____actvcall_netcall_socket_getpeername(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_getpeername(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	__maybe_unused void *__actv_local_var_addr = addr;
	__maybe_unused void *__actv_local_var_addrlen = addrlen;
	__ret = ____actvcapcall_netcall_socket_getpeername(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(addr, __actv_local_var_addr), __ARCH_ACTV_RPC_PASS_ARG(addrlen, __actv_local_var_addrlen));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_fcntl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_fcntl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_fcntl(unsigned long long __rpc_info, void *__buf, int fd, int cmd, int val)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_cmd = cmd;
	int __maybe_unused __actv_local_var_val = val;
	__ret = ____actvcall_netcall_socket_fcntl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(val, __actv_local_var_val));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_fcntl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int cmd, int val)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_cmd = cmd;
	int __maybe_unused __actv_local_var_val = val;
	__ret = ____actvcapcall_netcall_socket_fcntl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(val, __actv_local_var_val));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_ioctl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_ioctl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_ioctl(unsigned long long __rpc_info, void *__buf, int fd, int request, unsigned long args)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_request = request;
	unsigned long __maybe_unused __actv_local_var_args = args;
	__ret = ____actvcall_netcall_socket_ioctl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(request, __actv_local_var_request), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int request, unsigned long args)
{
	int __ret;
	int __maybe_unused __actv_local_var_fd = fd;
	int __maybe_unused __actv_local_var_request = request;
	unsigned long __maybe_unused __actv_local_var_args = args;
	__ret = ____actvcapcall_netcall_socket_ioctl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(request, __actv_local_var_request), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_dup(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_dup(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_dup(unsigned long long __rpc_info, void *__buf, int oldfd, int newfd)
{
	int __ret;
	int __maybe_unused __actv_local_var_oldfd = oldfd;
	int __maybe_unused __actv_local_var_newfd = newfd;
	__ret = ____actvcall_netcall_socket_dup(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(oldfd, __actv_local_var_oldfd), __ARCH_ACTV_RPC_PASS_ARG(newfd, __actv_local_var_newfd));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_dup(rref_t __rref, unsigned long long __rpc_info, void *__buf, int oldfd, int newfd)
{
	int __ret;
	int __maybe_unused __actv_local_var_oldfd = oldfd;
	int __maybe_unused __actv_local_var_newfd = newfd;
	__ret = ____actvcapcall_netcall_socket_dup(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(oldfd, __actv_local_var_oldfd), __ARCH_ACTV_RPC_PASS_ARG(newfd, __actv_local_var_newfd));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_send_fd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_send_fd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_send_fd(unsigned long long __rpc_info, void *__buf, unsigned long argu_info)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_argu_info = argu_info;
	__ret = ____actvcall_netcall_socket_send_fd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(argu_info, __actv_local_var_argu_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_send_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long argu_info)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_argu_info = argu_info;
	__ret = ____actvcapcall_netcall_socket_send_fd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(argu_info, __actv_local_var_argu_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_recv_fd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_recv_fd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_recv_fd(unsigned long long __rpc_info, void *__buf, unsigned long argu_info)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_argu_info = argu_info;
	__ret = ____actvcall_netcall_socket_recv_fd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(argu_info, __actv_local_var_argu_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_recv_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long argu_info)
{
	int __ret;
	unsigned long __maybe_unused __actv_local_var_argu_info = argu_info;
	__ret = ____actvcapcall_netcall_socket_recv_fd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(argu_info, __actv_local_var_argu_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_socket_put_send_fd(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_socket_put_send_fd(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_socket_put_send_fd(unsigned long long __rpc_info, void *__buf, uintptr_t argu_info)
{
	int __ret;
	uintptr_t __maybe_unused __actv_local_var_argu_info = argu_info;
	__ret = ____actvcall_netcall_socket_put_send_fd(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(argu_info, __actv_local_var_argu_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_socket_put_send_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, uintptr_t argu_info)
{
	int __ret;
	uintptr_t __maybe_unused __actv_local_var_argu_info = argu_info;
	__ret = ____actvcapcall_netcall_socket_put_send_fd(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(argu_info, __actv_local_var_argu_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_epoll_ctl(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_epoll_ctl(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_epoll_ctl(unsigned long long __rpc_info, void *__buf, int socket_fd, int op, const void *epoll_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_socket_fd = socket_fd;
	int __maybe_unused __actv_local_var_op = op;
	__maybe_unused const void *__actv_local_var_epoll_reg_info = epoll_reg_info;
	__ret = ____actvcall_netcall_epoll_ctl(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(socket_fd, __actv_local_var_socket_fd), __ARCH_ACTV_RPC_PASS_ARG(op, __actv_local_var_op), __ARCH_ACTV_RPC_PASS_ARG(epoll_reg_info, __actv_local_var_epoll_reg_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_epoll_ctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int socket_fd, int op, const void *epoll_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_socket_fd = socket_fd;
	int __maybe_unused __actv_local_var_op = op;
	__maybe_unused const void *__actv_local_var_epoll_reg_info = epoll_reg_info;
	__ret = ____actvcapcall_netcall_epoll_ctl(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(socket_fd, __actv_local_var_socket_fd), __ARCH_ACTV_RPC_PASS_ARG(op, __actv_local_var_op), __ARCH_ACTV_RPC_PASS_ARG(epoll_reg_info, __actv_local_var_epoll_reg_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_epoll_et_revents(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_epoll_et_revents(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_epoll_et_revents(unsigned long long __rpc_info, void *__buf, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	int __ret;
	int __maybe_unused __actv_local_var_socket_fd = socket_fd;
	unsigned long long __maybe_unused __actv_local_var_epi_shm_key = epi_shm_key;
	unsigned int __maybe_unused __actv_local_var_epi_shm_index = epi_shm_index;
	__ret = ____actvcall_netcall_epoll_et_revents(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(socket_fd, __actv_local_var_socket_fd), __ARCH_ACTV_RPC_PASS_ARG(epi_shm_key, __actv_local_var_epi_shm_key), __ARCH_ACTV_RPC_PASS_ARG(epi_shm_index, __actv_local_var_epi_shm_index));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_epoll_et_revents(rref_t __rref, unsigned long long __rpc_info, void *__buf, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	int __ret;
	int __maybe_unused __actv_local_var_socket_fd = socket_fd;
	unsigned long long __maybe_unused __actv_local_var_epi_shm_key = epi_shm_key;
	unsigned int __maybe_unused __actv_local_var_epi_shm_index = epi_shm_index;
	__ret = ____actvcapcall_netcall_epoll_et_revents(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(socket_fd, __actv_local_var_socket_fd), __ARCH_ACTV_RPC_PASS_ARG(epi_shm_key, __actv_local_var_epi_shm_key), __ARCH_ACTV_RPC_PASS_ARG(epi_shm_index, __actv_local_var_epi_shm_index));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_epoll_reinit(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_epoll_reinit(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_epoll_reinit(unsigned long long __rpc_info, void *__buf, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_socket_fd = socket_fd;
	__maybe_unused const void *__actv_local_var_epoll_pre_reg_info = epoll_pre_reg_info;
	__maybe_unused const void *__actv_local_var_epoll_reg_info = epoll_reg_info;
	__ret = ____actvcall_netcall_epoll_reinit(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(socket_fd, __actv_local_var_socket_fd), __ARCH_ACTV_RPC_PASS_ARG(epoll_pre_reg_info, __actv_local_var_epoll_pre_reg_info), __ARCH_ACTV_RPC_PASS_ARG(epoll_reg_info, __actv_local_var_epoll_reg_info));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_epoll_reinit(rref_t __rref, unsigned long long __rpc_info, void *__buf, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	int __ret;
	int __maybe_unused __actv_local_var_socket_fd = socket_fd;
	__maybe_unused const void *__actv_local_var_epoll_pre_reg_info = epoll_pre_reg_info;
	__maybe_unused const void *__actv_local_var_epoll_reg_info = epoll_reg_info;
	__ret = ____actvcapcall_netcall_epoll_reinit(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(socket_fd, __actv_local_var_socket_fd), __ARCH_ACTV_RPC_PASS_ARG(epoll_pre_reg_info, __actv_local_var_epoll_pre_reg_info), __ARCH_ACTV_RPC_PASS_ARG(epoll_reg_info, __actv_local_var_epoll_reg_info));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_cfg_loglevel(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_cfg_loglevel(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_cfg_loglevel(unsigned long long __rpc_info, void *__buf, unsigned int loglevel)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_loglevel = loglevel;
	__ret = ____actvcall_netcall_cfg_loglevel(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(loglevel, __actv_local_var_loglevel));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_cfg_loglevel(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int loglevel)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_loglevel = loglevel;
	__ret = ____actvcapcall_netcall_cfg_loglevel(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(loglevel, __actv_local_var_loglevel));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_cfg_show_stats(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_cfg_show_stats(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_cfg_show_stats(unsigned long long __rpc_info, void *__buf, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	int __ret;
	struct sysif_protocol __maybe_unused __actv_local_var_ss_protocol = ss_protocol;
	unsigned long long __maybe_unused __actv_local_var_shm_key = shm_key;
	__ret = ____actvcall_netcall_cfg_show_stats(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ss_protocol, __actv_local_var_ss_protocol), __ARCH_ACTV_RPC_PASS_ARG(shm_key, __actv_local_var_shm_key));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_cfg_show_stats(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	int __ret;
	struct sysif_protocol __maybe_unused __actv_local_var_ss_protocol = ss_protocol;
	unsigned long long __maybe_unused __actv_local_var_shm_key = shm_key;
	__ret = ____actvcapcall_netcall_cfg_show_stats(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(ss_protocol, __actv_local_var_ss_protocol), __ARCH_ACTV_RPC_PASS_ARG(shm_key, __actv_local_var_shm_key));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_cfg_getifaddrs(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_cfg_getifaddrs(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_cfg_getifaddrs(unsigned long long __rpc_info, void *__buf, unsigned long long shm_key)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_shm_key = shm_key;
	__ret = ____actvcall_netcall_cfg_getifaddrs(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_key, __actv_local_var_shm_key));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_cfg_getifaddrs(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long shm_key)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_shm_key = shm_key;
	__ret = ____actvcapcall_netcall_cfg_getifaddrs(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(shm_key, __actv_local_var_shm_key));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_netdev_rx(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_netdev_rx(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_netdev_rx(unsigned long long __rpc_info, void *__buf, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cell_pool_offset = cell_pool_offset;
	int __maybe_unused __actv_local_var_shm_len = shm_len;
	int __maybe_unused __actv_local_var_rx_len = rx_len;
	int __maybe_unused __actv_local_var_offset = offset;
	int __maybe_unused __actv_local_var_devno = devno;
	__ret = ____actvcall_netcall_netdev_rx(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cell_pool_offset, __actv_local_var_cell_pool_offset), __ARCH_ACTV_RPC_PASS_ARG(shm_len, __actv_local_var_shm_len), __ARCH_ACTV_RPC_PASS_ARG(rx_len, __actv_local_var_rx_len), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_netdev_rx(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cell_pool_offset = cell_pool_offset;
	int __maybe_unused __actv_local_var_shm_len = shm_len;
	int __maybe_unused __actv_local_var_rx_len = rx_len;
	int __maybe_unused __actv_local_var_offset = offset;
	int __maybe_unused __actv_local_var_devno = devno;
	__ret = ____actvcapcall_netcall_netdev_rx(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cell_pool_offset, __actv_local_var_cell_pool_offset), __ARCH_ACTV_RPC_PASS_ARG(shm_len, __actv_local_var_shm_len), __ARCH_ACTV_RPC_PASS_ARG(rx_len, __actv_local_var_rx_len), __ARCH_ACTV_RPC_PASS_ARG(offset, __actv_local_var_offset), __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_netdev_notify(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_netdev_notify(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_netdev_notify(unsigned long long __rpc_info, void *__buf, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	int __ret;
	enum hm_netdev_event __maybe_unused __actv_local_var_event = event;
	int __maybe_unused __actv_local_var_devno = devno;
	int __maybe_unused __actv_local_var_option = option;
	struct netdev_ifname __maybe_unused __actv_local_var_ifname = ifname;
	unsigned long long __maybe_unused __actv_local_var_features = features;
	__ret = ____actvcall_netcall_netdev_notify(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event), __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno), __ARCH_ACTV_RPC_PASS_ARG(option, __actv_local_var_option), __ARCH_ACTV_RPC_PASS_ARG(ifname, __actv_local_var_ifname), __ARCH_ACTV_RPC_PASS_ARG(features, __actv_local_var_features));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_netdev_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	int __ret;
	enum hm_netdev_event __maybe_unused __actv_local_var_event = event;
	int __maybe_unused __actv_local_var_devno = devno;
	int __maybe_unused __actv_local_var_option = option;
	struct netdev_ifname __maybe_unused __actv_local_var_ifname = ifname;
	unsigned long long __maybe_unused __actv_local_var_features = features;
	__ret = ____actvcapcall_netcall_netdev_notify(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(event, __actv_local_var_event), __ARCH_ACTV_RPC_PASS_ARG(devno, __actv_local_var_devno), __ARCH_ACTV_RPC_PASS_ARG(option, __actv_local_var_option), __ARCH_ACTV_RPC_PASS_ARG(ifname, __actv_local_var_ifname), __ARCH_ACTV_RPC_PASS_ARG(features, __actv_local_var_features));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_netcall_netdev_rx_ex_slowdata(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_netcall_netdev_rx_ex_slowdata(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_netdev_rx_ex_slowdata(unsigned long long __rpc_info, void *__buf, int num)
{
	int __ret;
	int __maybe_unused __actv_local_var_num = num;
	__ret = ____actvcall_netcall_netdev_rx_ex_slowdata(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(num, __actv_local_var_num));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_netdev_rx_ex_slowdata(rref_t __rref, unsigned long long __rpc_info, void *__buf, int num)
{
	int __ret;
	int __maybe_unused __actv_local_var_num = num;
	__ret = ____actvcapcall_netcall_netdev_rx_ex_slowdata(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(num, __actv_local_var_num));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_netcall_procfs_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_netcall_procfs_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_procfs_read(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_netcall_procfs_read(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_netcall_procfs_read(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_netcall_procfs_write(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_netcall_procfs_write(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_procfs_write(unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcall_netcall_procfs_write(__rpc_info, __buf);
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	int __ret;
	__ret = ____actvcapcall_netcall_procfs_write(__rref, __rpc_info, __buf);
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_procfs_fds_read(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_procfs_fds_read(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_procfs_fds_read(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned long long __maybe_unused __actv_local_var_fd_map = fd_map;
	unsigned int __maybe_unused __actv_local_var_max_files = max_files;
	__ret = ____actvcall_netcall_procfs_fds_read(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(fd_map, __actv_local_var_fd_map), __ARCH_ACTV_RPC_PASS_ARG(max_files, __actv_local_var_max_files));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_procfs_fds_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	unsigned long long __maybe_unused __actv_local_var_fd_map = fd_map;
	unsigned int __maybe_unused __actv_local_var_max_files = max_files;
	__ret = ____actvcapcall_netcall_procfs_fds_read(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(fd_map, __actv_local_var_fd_map), __ARCH_ACTV_RPC_PASS_ARG(max_files, __actv_local_var_max_files));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_procfs_get_fd_path(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_procfs_get_fd_path(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_procfs_get_fd_path(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_path_buf = path_buf;
	unsigned int __maybe_unused __actv_local_var_path_buf_len = path_buf_len;
	__ret = ____actvcall_netcall_procfs_get_fd_path(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(path_buf, __actv_local_var_path_buf), __ARCH_ACTV_RPC_PASS_ARG(path_buf_len, __actv_local_var_path_buf_len));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_procfs_get_fd_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cnode_idx = cnode_idx;
	int __maybe_unused __actv_local_var_fd = fd;
	unsigned long long __maybe_unused __actv_local_var_path_buf = path_buf;
	unsigned int __maybe_unused __actv_local_var_path_buf_len = path_buf_len;
	__ret = ____actvcapcall_netcall_procfs_get_fd_path(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cnode_idx, __actv_local_var_cnode_idx), __ARCH_ACTV_RPC_PASS_ARG(fd, __actv_local_var_fd), __ARCH_ACTV_RPC_PASS_ARG(path_buf, __actv_local_var_path_buf), __ARCH_ACTV_RPC_PASS_ARG(path_buf_len, __actv_local_var_path_buf_len));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_fallback"))) ____actvcall_netcall_netlink_register_generic(unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


static int __attribute__((alias("__internal_rpccapcall_fallback"))) ____actvcapcall_netcall_netlink_register_generic(rref_t __rref, unsigned long long rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_netlink_register_generic(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned long long dh_ap_uref)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_dh_ap_uref = dh_ap_uref;
	__ret = ____actvcall_netcall_netlink_register_generic(__rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dh_ap_uref, __actv_local_var_dh_ap_uref));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_netlink_register_generic(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned long long dh_ap_uref)
{
	int __ret;
	unsigned long long __maybe_unused __actv_local_var_dh_ap_uref = dh_ap_uref;
	__ret = ____actvcapcall_netcall_netlink_register_generic(__rref, __rpc_info, __buf, __rply_buf, rply_buf_sz, __ARCH_ACTV_RPC_PASS_ARG(dh_ap_uref, __actv_local_var_dh_ap_uref));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_netlink_unregister_generic(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_netlink_unregister_generic(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_netlink_unregister_generic(unsigned long long __rpc_info, void *__buf, unsigned short familyid)
{
	int __ret;
	unsigned short __maybe_unused __actv_local_var_familyid = familyid;
	__ret = ____actvcall_netcall_netlink_unregister_generic(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(familyid, __actv_local_var_familyid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_netlink_unregister_generic(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned short familyid)
{
	int __ret;
	unsigned short __maybe_unused __actv_local_var_familyid = familyid;
	__ret = ____actvcapcall_netcall_netlink_unregister_generic(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(familyid, __actv_local_var_familyid));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_netcall_netlink_unicast(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_netcall_netlink_unicast(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_netlink_unicast(unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_port)
{
	int __ret;
	int __maybe_unused __actv_local_var_protocol = protocol;
	unsigned int __maybe_unused __actv_local_var_src_portid = src_portid;
	unsigned int __maybe_unused __actv_local_var_dst_port = dst_port;
	__ret = ____actvcall_netcall_netlink_unicast(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(src_portid, __actv_local_var_src_portid), __ARCH_ACTV_RPC_PASS_ARG(dst_port, __actv_local_var_dst_port));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_netlink_unicast(rref_t __rref, unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_port)
{
	int __ret;
	int __maybe_unused __actv_local_var_protocol = protocol;
	unsigned int __maybe_unused __actv_local_var_src_portid = src_portid;
	unsigned int __maybe_unused __actv_local_var_dst_port = dst_port;
	__ret = ____actvcapcall_netcall_netlink_unicast(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(src_portid, __actv_local_var_src_portid), __ARCH_ACTV_RPC_PASS_ARG(dst_port, __actv_local_var_dst_port));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_buf"))) ____actvcall_netcall_netlink_broadcast(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_buf"))) ____actvcapcall_netcall_netlink_broadcast(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_netlink_broadcast(unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_group)
{
	int __ret;
	int __maybe_unused __actv_local_var_protocol = protocol;
	unsigned int __maybe_unused __actv_local_var_src_portid = src_portid;
	unsigned int __maybe_unused __actv_local_var_dst_group = dst_group;
	__ret = ____actvcall_netcall_netlink_broadcast(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(src_portid, __actv_local_var_src_portid), __ARCH_ACTV_RPC_PASS_ARG(dst_group, __actv_local_var_dst_group));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_netlink_broadcast(rref_t __rref, unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_group)
{
	int __ret;
	int __maybe_unused __actv_local_var_protocol = protocol;
	unsigned int __maybe_unused __actv_local_var_src_portid = src_portid;
	unsigned int __maybe_unused __actv_local_var_dst_group = dst_group;
	__ret = ____actvcapcall_netcall_netlink_broadcast(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(protocol, __actv_local_var_protocol), __ARCH_ACTV_RPC_PASS_ARG(src_portid, __actv_local_var_src_portid), __ARCH_ACTV_RPC_PASS_ARG(dst_group, __actv_local_var_dst_group));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_vsock_register_vm(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_vsock_register_vm(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_vsock_register_vm(unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned int dev_group_id)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cid = cid;
	unsigned int __maybe_unused __actv_local_var_dev_group_id = dev_group_id;
	__ret = ____actvcall_netcall_vsock_register_vm(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cid, __actv_local_var_cid), __ARCH_ACTV_RPC_PASS_ARG(dev_group_id, __actv_local_var_dev_group_id));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_vsock_register_vm(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned int dev_group_id)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cid = cid;
	unsigned int __maybe_unused __actv_local_var_dev_group_id = dev_group_id;
	__ret = ____actvcapcall_netcall_vsock_register_vm(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cid, __actv_local_var_cid), __ARCH_ACTV_RPC_PASS_ARG(dev_group_id, __actv_local_var_dev_group_id));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_vsock_vm_notify(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_vsock_vm_notify(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_vsock_vm_notify(unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cid = cid;
	unsigned short __maybe_unused __actv_local_var_cmd = cmd;
	__maybe_unused void *__actv_local_var_args = args;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcall_netcall_vsock_vm_notify(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cid, __actv_local_var_cid), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_vsock_vm_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cid = cid;
	unsigned short __maybe_unused __actv_local_var_cmd = cmd;
	__maybe_unused void *__actv_local_var_args = args;
	size_t __maybe_unused __actv_local_var_size = size;
	__ret = ____actvcapcall_netcall_vsock_vm_notify(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cid, __actv_local_var_cid), __ARCH_ACTV_RPC_PASS_ARG(cmd, __actv_local_var_cmd), __ARCH_ACTV_RPC_PASS_ARG(args, __actv_local_var_args), __ARCH_ACTV_RPC_PASS_ARG(size, __actv_local_var_size));
	return __ret;
}

static int __attribute__((alias("__internal_rpccall_nobuf"))) ____actvcall_netcall_vsock_unregister_vm(unsigned long long rpc_info, void *__buf, ...);


static int __attribute__((alias("__internal_rpccapcall_nobuf"))) ____actvcapcall_netcall_vsock_unregister_vm(rref_t __rref, unsigned long long rpc_info, void *__buf, ...);


int __opt_noframe __opt_nostkprot __actvcall_netcall_vsock_unregister_vm(unsigned long long __rpc_info, void *__buf, unsigned int cid)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cid = cid;
	__ret = ____actvcall_netcall_vsock_unregister_vm(__rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cid, __actv_local_var_cid));
	return __ret;
}

int __opt_noframe __opt_nostkprot __actvcapcall_netcall_vsock_unregister_vm(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cid)
{
	int __ret;
	unsigned int __maybe_unused __actv_local_var_cid = cid;
	__ret = ____actvcapcall_netcall_vsock_unregister_vm(__rref, __rpc_info, __buf, __ARCH_ACTV_RPC_PASS_ARG(cid, __actv_local_var_cid));
	return __ret;
}

#endif
#endif
