/*
* Automatically generated file; DO NOT EDIT.
* Automatically generated sysif apis for hmnet
* Using command: ../recipe-sysroot-native/usr/bin/hm-dsl/hm-dsl sysif ../../../../../work-shared/hm-network/git/ulibs/libevent/include/libsysif_net/api.sysif -I ../../../../../work-shared/hm-network/git/ulibs/libevent/include --api-dest ../image/usr/include/generated/sysif_client/net/libsysif_net/api.h --server-dest ../image/usr/include/generated/sysif_server/net/libsysif_net/service.h --legacy-mode
* Create: Mon Nov 28 09:47:53 2022
*/
#ifndef LIBSYSIF_HMNET_SERVER_H
#define LIBSYSIF_HMNET_SERVER_H
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
#ifdef __sysif_server_hmnet_no_compat32_handlers__
# define __hmnet_method_MAX __hmnet_method_MAX_NOCOMPAT
#else
# define __hmnet_method_MAX __hmnet_method_MAX_COMPAT
#endif
#include <libsysif/utils.h>
#include <asm/actv_rpc.h>
#include <asm/types.h>
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
extern int actvhdlr_nethandler_socket_revoke(unsigned long long sender, unsigned long credential);


extern int actvhdlr_nethandler_socket_fork(unsigned long long sender, unsigned long credential);


extern int actvhdlr_nethandler_socket_socket(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd);


extern int actvhdlr_nethandler_socket_socketpair(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2);


extern int actvhdlr_nethandler_socket_close(unsigned long long sender, unsigned long credential, int fd);


extern int actvhdlr_nethandler_socket_shutdown(unsigned long long sender, unsigned long credential, int fd, int how);


extern int actvhdlr_nethandler_socket_bind(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len);


extern int actvhdlr_nethandler_socket_listen(unsigned long long sender, unsigned long credential, int fd, int backlog);


extern int actvhdlr_nethandler_socket_accept(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd);


extern int actvhdlr_nethandler_socket_connect(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen);


extern int actvhdlr_nethandler_socket_send(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags);


extern int actvhdlr_nethandler_socket_sendmsg(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags);


extern int actvhdlr_nethandler_socket_recvmsg(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags);


extern int actvhdlr_nethandler_socket_sendto(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);


extern int actvhdlr_nethandler_socket_recvfrom(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);


extern int actvhdlr_nethandler_socket_getsockopt(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen);


extern int actvhdlr_nethandler_socket_setsockopt(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen);


extern int actvhdlr_nethandler_socket_getsockname(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);


extern int actvhdlr_nethandler_socket_getpeername(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);


extern int actvhdlr_nethandler_socket_fcntl(unsigned long long sender, unsigned long credential, int fd, int cmd, int val);


extern int actvhdlr_nethandler_socket_ioctl(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args);


extern int actvhdlr_nethandler_socket_dup(unsigned long long sender, unsigned long credential, int oldfd, int newfd);


extern int actvhdlr_nethandler_socket_send_fd(unsigned long long sender, unsigned long credential, unsigned long argu_info);


extern int actvhdlr_nethandler_socket_recv_fd(unsigned long long sender, unsigned long credential, unsigned long argu_info);


extern int actvhdlr_nethandler_socket_put_send_fd(unsigned long long sender, unsigned long credential, uintptr_t argu_info);


extern int actvhdlr_nethandler_epoll_ctl(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info);


extern int actvhdlr_nethandler_epoll_et_revents(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);


extern int actvhdlr_nethandler_epoll_reinit(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);


extern int actvhdlr_nethandler_cfg_loglevel(unsigned long long sender, unsigned long credential, unsigned int loglevel);


extern int actvhdlr_nethandler_cfg_show_stats(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key);


extern int actvhdlr_nethandler_cfg_getifaddrs(unsigned long long sender, unsigned long credential, unsigned long long shm_key);


extern int actvhdlr_nethandler_netdev_rx(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);


extern int actvhdlr_nethandler_netdev_notify(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);


extern int actvhdlr_nethandler_netdev_rx_ex_slowdata(unsigned long long sender, unsigned long credential, int num);


extern int actvhdlr_nethandler_procfs_read(unsigned long long sender, unsigned long credential);


extern int actvhdlr_nethandler_procfs_write(unsigned long long sender, unsigned long credential);


extern int actvhdlr_nethandler_procfs_fds_read(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);


extern int actvhdlr_nethandler_procfs_get_fd_path(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);


extern int actvhdlr_nethandler_netlink_register_generic(unsigned long long sender, unsigned long credential, unsigned long long dh_ap_uref);


extern int actvhdlr_nethandler_netlink_unregister_generic(unsigned long long sender, unsigned long credential, unsigned short familyid);


extern int actvhdlr_nethandler_netlink_unicast(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port);


extern int actvhdlr_nethandler_netlink_broadcast(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group);


extern int actvhdlr_nethandler_vsock_register_vm(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id);


extern int actvhdlr_nethandler_vsock_vm_notify(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size);


extern int actvhdlr_nethandler_vsock_unregister_vm(unsigned long long sender, unsigned long credential, unsigned int cid);


#else
extern int actvhdlr_nethandler_socket_revoke(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_nethandler_socket_revoke(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_fork(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_nethandler_socket_fork(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_socket(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd);


extern int __actvshadowhdlr_nethandler_socket_socket(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_socketpair(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2);


extern int __actvshadowhdlr_nethandler_socket_socketpair(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_close(unsigned long long sender, unsigned long credential, int fd);


extern int __actvshadowhdlr_nethandler_socket_close(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_shutdown(unsigned long long sender, unsigned long credential, int fd, int how);


extern int __actvshadowhdlr_nethandler_socket_shutdown(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_bind(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len);


extern int __actvshadowhdlr_nethandler_socket_bind(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_listen(unsigned long long sender, unsigned long credential, int fd, int backlog);


extern int __actvshadowhdlr_nethandler_socket_listen(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_accept(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd);


extern int __actvshadowhdlr_nethandler_socket_accept(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_connect(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen);


extern int __actvshadowhdlr_nethandler_socket_connect(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_send(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags);


extern int __actvshadowhdlr_nethandler_socket_send(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_sendmsg(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags);


extern int __actvshadowhdlr_nethandler_socket_sendmsg(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_recvmsg(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags);


extern int __actvshadowhdlr_nethandler_socket_recvmsg(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_sendto(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);


extern int __actvshadowhdlr_nethandler_socket_sendto(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_recvfrom(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);


extern int __actvshadowhdlr_nethandler_socket_recvfrom(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_getsockopt(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen);


extern int __actvshadowhdlr_nethandler_socket_getsockopt(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_setsockopt(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen);


extern int __actvshadowhdlr_nethandler_socket_setsockopt(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_getsockname(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);


extern int __actvshadowhdlr_nethandler_socket_getsockname(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_getpeername(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);


extern int __actvshadowhdlr_nethandler_socket_getpeername(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_fcntl(unsigned long long sender, unsigned long credential, int fd, int cmd, int val);


extern int __actvshadowhdlr_nethandler_socket_fcntl(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_ioctl(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args);


extern int __actvshadowhdlr_nethandler_socket_ioctl(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_dup(unsigned long long sender, unsigned long credential, int oldfd, int newfd);


extern int __actvshadowhdlr_nethandler_socket_dup(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_send_fd(unsigned long long sender, unsigned long credential, unsigned long argu_info);


extern int __actvshadowhdlr_nethandler_socket_send_fd(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_recv_fd(unsigned long long sender, unsigned long credential, unsigned long argu_info);


extern int __actvshadowhdlr_nethandler_socket_recv_fd(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_socket_put_send_fd(unsigned long long sender, unsigned long credential, uintptr_t argu_info);


extern int __actvshadowhdlr_nethandler_socket_put_send_fd(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_epoll_ctl(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info);


extern int __actvshadowhdlr_nethandler_epoll_ctl(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_epoll_et_revents(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);


extern int __actvshadowhdlr_nethandler_epoll_et_revents(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_epoll_reinit(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);


extern int __actvshadowhdlr_nethandler_epoll_reinit(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_cfg_loglevel(unsigned long long sender, unsigned long credential, unsigned int loglevel);


extern int __actvshadowhdlr_nethandler_cfg_loglevel(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_cfg_show_stats(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key);


extern int __actvshadowhdlr_nethandler_cfg_show_stats(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_cfg_getifaddrs(unsigned long long sender, unsigned long credential, unsigned long long shm_key);


extern int __actvshadowhdlr_nethandler_cfg_getifaddrs(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_netdev_rx(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);


extern int __actvshadowhdlr_nethandler_netdev_rx(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_netdev_notify(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);


extern int __actvshadowhdlr_nethandler_netdev_notify(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_netdev_rx_ex_slowdata(unsigned long long sender, unsigned long credential, int num);


extern int __actvshadowhdlr_nethandler_netdev_rx_ex_slowdata(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_procfs_read(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_nethandler_procfs_read(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_procfs_write(unsigned long long sender, unsigned long credential);


extern int __actvshadowhdlr_nethandler_procfs_write(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_procfs_fds_read(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);


extern int __actvshadowhdlr_nethandler_procfs_fds_read(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_procfs_get_fd_path(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);


extern int __actvshadowhdlr_nethandler_procfs_get_fd_path(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_netlink_register_generic(unsigned long long sender, unsigned long credential, unsigned long long dh_ap_uref);


extern int __actvshadowhdlr_nethandler_netlink_register_generic(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_netlink_unregister_generic(unsigned long long sender, unsigned long credential, unsigned short familyid);


extern int __actvshadowhdlr_nethandler_netlink_unregister_generic(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_netlink_unicast(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port);


extern int __actvshadowhdlr_nethandler_netlink_unicast(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_netlink_broadcast(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group);


extern int __actvshadowhdlr_nethandler_netlink_broadcast(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_vsock_register_vm(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id);


extern int __actvshadowhdlr_nethandler_vsock_register_vm(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_vsock_vm_notify(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size);


extern int __actvshadowhdlr_nethandler_vsock_vm_notify(unsigned long long sender, unsigned long credential, ...);


extern int actvhdlr_nethandler_vsock_unregister_vm(unsigned long long sender, unsigned long credential, unsigned int cid);


extern int __actvshadowhdlr_nethandler_vsock_unregister_vm(unsigned long long sender, unsigned long credential, ...);


#endif
static inline struct __actvret_netcall_socket_revoke* actvhdlr_nethandler_socket_revoke_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_revoke));
	return (struct __actvret_netcall_socket_revoke*)__ret;
}

static inline struct __actvret_netcall_socket_fork* actvhdlr_nethandler_socket_fork_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_fork));
	return (struct __actvret_netcall_socket_fork*)__ret;
}

static inline struct __actvret_netcall_socket_socket* actvhdlr_nethandler_socket_socket_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_socket));
	return (struct __actvret_netcall_socket_socket*)__ret;
}

static inline struct __actvret_netcall_socket_socketpair* actvhdlr_nethandler_socket_socketpair_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_socketpair));
	return (struct __actvret_netcall_socket_socketpair*)__ret;
}

static inline struct __actvret_netcall_socket_close* actvhdlr_nethandler_socket_close_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_close));
	return (struct __actvret_netcall_socket_close*)__ret;
}

static inline struct __actvret_netcall_socket_shutdown* actvhdlr_nethandler_socket_shutdown_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_shutdown));
	return (struct __actvret_netcall_socket_shutdown*)__ret;
}

static inline struct __actvret_netcall_socket_bind* actvhdlr_nethandler_socket_bind_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_bind));
	return (struct __actvret_netcall_socket_bind*)__ret;
}

static inline struct __actvret_netcall_socket_listen* actvhdlr_nethandler_socket_listen_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_listen));
	return (struct __actvret_netcall_socket_listen*)__ret;
}

static inline struct __actvret_netcall_socket_accept* actvhdlr_nethandler_socket_accept_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_accept));
	return (struct __actvret_netcall_socket_accept*)__ret;
}

static inline struct __actvret_netcall_socket_connect* actvhdlr_nethandler_socket_connect_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_connect));
	return (struct __actvret_netcall_socket_connect*)__ret;
}

static inline struct __actvret_netcall_socket_send* actvhdlr_nethandler_socket_send_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_send));
	return (struct __actvret_netcall_socket_send*)__ret;
}

static inline struct __actvret_netcall_socket_sendmsg* actvhdlr_nethandler_socket_sendmsg_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_sendmsg));
	return (struct __actvret_netcall_socket_sendmsg*)__ret;
}

static inline struct __actvret_netcall_socket_recvmsg* actvhdlr_nethandler_socket_recvmsg_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_recvmsg));
	return (struct __actvret_netcall_socket_recvmsg*)__ret;
}

static inline struct __actvret_netcall_socket_sendto* actvhdlr_nethandler_socket_sendto_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_sendto));
	return (struct __actvret_netcall_socket_sendto*)__ret;
}

static inline struct __actvret_netcall_socket_recvfrom* actvhdlr_nethandler_socket_recvfrom_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_recvfrom));
	return (struct __actvret_netcall_socket_recvfrom*)__ret;
}

static inline struct __actvret_netcall_socket_getsockopt* actvhdlr_nethandler_socket_getsockopt_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_getsockopt));
	return (struct __actvret_netcall_socket_getsockopt*)__ret;
}

static inline struct __actvret_netcall_socket_setsockopt* actvhdlr_nethandler_socket_setsockopt_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_setsockopt));
	return (struct __actvret_netcall_socket_setsockopt*)__ret;
}

static inline struct __actvret_netcall_socket_getsockname* actvhdlr_nethandler_socket_getsockname_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_getsockname));
	return (struct __actvret_netcall_socket_getsockname*)__ret;
}

static inline struct __actvret_netcall_socket_getpeername* actvhdlr_nethandler_socket_getpeername_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_getpeername));
	return (struct __actvret_netcall_socket_getpeername*)__ret;
}

static inline struct __actvret_netcall_socket_fcntl* actvhdlr_nethandler_socket_fcntl_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_fcntl));
	return (struct __actvret_netcall_socket_fcntl*)__ret;
}

static inline struct __actvret_netcall_socket_ioctl* actvhdlr_nethandler_socket_ioctl_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_ioctl));
	return (struct __actvret_netcall_socket_ioctl*)__ret;
}

static inline struct __actvret_netcall_socket_dup* actvhdlr_nethandler_socket_dup_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_dup));
	return (struct __actvret_netcall_socket_dup*)__ret;
}

static inline struct __actvret_netcall_socket_send_fd* actvhdlr_nethandler_socket_send_fd_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_send_fd));
	return (struct __actvret_netcall_socket_send_fd*)__ret;
}

static inline struct __actvret_netcall_socket_recv_fd* actvhdlr_nethandler_socket_recv_fd_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_recv_fd));
	return (struct __actvret_netcall_socket_recv_fd*)__ret;
}

static inline struct __actvret_netcall_socket_put_send_fd* actvhdlr_nethandler_socket_put_send_fd_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_socket_put_send_fd));
	return (struct __actvret_netcall_socket_put_send_fd*)__ret;
}

static inline struct __actvret_netcall_epoll_ctl* actvhdlr_nethandler_epoll_ctl_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_epoll_ctl));
	return (struct __actvret_netcall_epoll_ctl*)__ret;
}

static inline struct __actvret_netcall_epoll_et_revents* actvhdlr_nethandler_epoll_et_revents_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_epoll_et_revents));
	return (struct __actvret_netcall_epoll_et_revents*)__ret;
}

static inline struct __actvret_netcall_epoll_reinit* actvhdlr_nethandler_epoll_reinit_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_epoll_reinit));
	return (struct __actvret_netcall_epoll_reinit*)__ret;
}

static inline struct __actvret_netcall_cfg_loglevel* actvhdlr_nethandler_cfg_loglevel_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_cfg_loglevel));
	return (struct __actvret_netcall_cfg_loglevel*)__ret;
}

static inline struct __actvret_netcall_cfg_show_stats* actvhdlr_nethandler_cfg_show_stats_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_cfg_show_stats));
	return (struct __actvret_netcall_cfg_show_stats*)__ret;
}

static inline struct __actvret_netcall_cfg_getifaddrs* actvhdlr_nethandler_cfg_getifaddrs_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_cfg_getifaddrs));
	return (struct __actvret_netcall_cfg_getifaddrs*)__ret;
}

static inline struct __actvret_netcall_netdev_rx* actvhdlr_nethandler_netdev_rx_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_netdev_rx));
	return (struct __actvret_netcall_netdev_rx*)__ret;
}

static inline struct __actvret_netcall_netdev_notify* actvhdlr_nethandler_netdev_notify_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_netdev_notify));
	return (struct __actvret_netcall_netdev_notify*)__ret;
}

static inline struct __actvret_netcall_netdev_rx_ex_slowdata* actvhdlr_nethandler_netdev_rx_ex_slowdata_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_netdev_rx_ex_slowdata));
	return (struct __actvret_netcall_netdev_rx_ex_slowdata*)__ret;
}

static inline struct __actvret_netcall_procfs_read* actvhdlr_nethandler_procfs_read_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_procfs_read));
	return (struct __actvret_netcall_procfs_read*)__ret;
}

static inline struct __actvret_netcall_procfs_write* actvhdlr_nethandler_procfs_write_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_procfs_write));
	return (struct __actvret_netcall_procfs_write*)__ret;
}

static inline struct __actvret_netcall_procfs_fds_read* actvhdlr_nethandler_procfs_fds_read_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_procfs_fds_read));
	return (struct __actvret_netcall_procfs_fds_read*)__ret;
}

static inline struct __actvret_netcall_procfs_get_fd_path* actvhdlr_nethandler_procfs_get_fd_path_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_procfs_get_fd_path));
	return (struct __actvret_netcall_procfs_get_fd_path*)__ret;
}

static inline struct __actvret_netcall_netlink_register_generic* actvhdlr_nethandler_netlink_register_generic_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_netlink_register_generic));
	return (struct __actvret_netcall_netlink_register_generic*)__ret;
}

static inline struct __actvret_netcall_netlink_unregister_generic* actvhdlr_nethandler_netlink_unregister_generic_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_netlink_unregister_generic));
	return (struct __actvret_netcall_netlink_unregister_generic*)__ret;
}

static inline struct __actvret_netcall_netlink_unicast* actvhdlr_nethandler_netlink_unicast_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_netlink_unicast));
	return (struct __actvret_netcall_netlink_unicast*)__ret;
}

static inline struct __actvret_netcall_netlink_broadcast* actvhdlr_nethandler_netlink_broadcast_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_netlink_broadcast));
	return (struct __actvret_netcall_netlink_broadcast*)__ret;
}

static inline struct __actvret_netcall_vsock_register_vm* actvhdlr_nethandler_vsock_register_vm_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_vsock_register_vm));
	return (struct __actvret_netcall_vsock_register_vm*)__ret;
}

static inline struct __actvret_netcall_vsock_vm_notify* actvhdlr_nethandler_vsock_vm_notify_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_vsock_vm_notify));
	return (struct __actvret_netcall_vsock_vm_notify*)__ret;
}

static inline struct __actvret_netcall_vsock_unregister_vm* actvhdlr_nethandler_vsock_unregister_vm_prepare_ret(unsigned long long sender, unsigned long credential)
{
	void *__ret = hm_actvpool_prepare_ret(sender, credential, sizeof(struct __actvret_netcall_vsock_unregister_vm));
	return (struct __actvret_netcall_vsock_unregister_vm*)__ret;
}

#ifdef __sysif_server_hmnet_no_compat32_handlers__
#ifdef __HOST_LLT__
union hmnet_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgehdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, int fd, int how);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int how);
	int (*p__actvbridgehdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgehdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, int fd, int backlog);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int backlog);
	int (*p__actvbridgehdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgehdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, int fd, int cmd, int val);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int cmd, int val);
	int (*p__actvbridgehdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int request, unsigned long args);
	int (*p__actvbridgehdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, int oldfd, int newfd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int oldfd, int newfd);
	int (*p__actvbridgehdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, uintptr_t argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uintptr_t argu_info);
	int (*p__actvbridgehdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgehdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned int loglevel);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int loglevel);
	int (*p__actvbridgehdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgehdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, int num);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int num);
	int (*p__actvbridgehdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgehdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgehdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgehdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned short familyid);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned short familyid);
	int (*p__actvbridgehdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgehdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgehdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgehdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgehdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned int cid);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union hmnet_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgehdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, int fd, int how);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int how);
	int (*p__actvbridgehdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgehdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, int fd, int backlog);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int backlog);
	int (*p__actvbridgehdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgehdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, int fd, int cmd, int val);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int cmd, int val);
	int (*p__actvbridgehdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int request, unsigned long args);
	int (*p__actvbridgehdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, int oldfd, int newfd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int oldfd, int newfd);
	int (*p__actvbridgehdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, uintptr_t argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uintptr_t argu_info);
	int (*p__actvbridgehdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgehdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned int loglevel);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int loglevel);
	int (*p__actvbridgehdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgehdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, int num);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int num);
	int (*p__actvbridgehdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgehdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgehdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgehdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned short familyid);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned short familyid);
	int (*p__actvbridgehdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgehdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgehdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgehdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgehdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned int cid);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union hmnet_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgehdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, int fd, int how);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int how);
	int (*p__actvbridgehdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgehdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, int fd, int backlog);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int backlog);
	int (*p__actvbridgehdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgehdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, int fd, int cmd, int val);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int cmd, int val);
	int (*p__actvbridgehdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int request, unsigned long args);
	int (*p__actvbridgehdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, int oldfd, int newfd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int oldfd, int newfd);
	int (*p__actvbridgehdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, uintptr_t argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uintptr_t argu_info);
	int (*p__actvbridgehdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgehdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned int loglevel);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int loglevel);
	int (*p__actvbridgehdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgehdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, int num);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int num);
	int (*p__actvbridgehdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgehdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgehdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgehdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned short familyid);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned short familyid);
	int (*p__actvbridgehdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgehdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgehdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgehdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgehdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned int cid);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
#ifdef __HOST_LLT__
union hmnet_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgehdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, int fd, int how);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int how);
	int (*p__actvbridgehdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgehdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, int fd, int backlog);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int backlog);
	int (*p__actvbridgehdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgehdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, int fd, int cmd, int val);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int cmd, int val);
	int (*p__actvbridgehdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int request, unsigned long args);
	int (*p__actvbridgehdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, int oldfd, int newfd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int oldfd, int newfd);
	int (*p__actvbridgehdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, uintptr_t argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uintptr_t argu_info);
	int (*p__actvbridgehdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgehdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned int loglevel);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int loglevel);
	int (*p__actvbridgehdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgehdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, int num);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int num);
	int (*p__actvbridgehdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgehdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgehdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgehdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned short familyid);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned short familyid);
	int (*p__actvbridgehdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgehdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgehdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgehdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgehdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned int cid);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid);
	int (*p__actvbridgehdlr_nethandler_compat_socket_revoke)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_revoke)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_fork)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_fork)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_socket)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_socket)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_socketpair)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_socketpair)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_close)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_close)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_bind)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_bind)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_listen)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_listen)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_accept)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_accept)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_connect)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_connect)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_send)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_send)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_sendmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_sendmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_recvmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_recvmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_sendto)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_sendto)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_recvfrom)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_recvfrom)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_getsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_getsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_setsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_setsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_getsockname)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_getsockname)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_getpeername)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_getpeername)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_fcntl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_fcntl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_ioctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_ioctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_dup)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_dup)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_put_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_put_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_epoll_ctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_epoll_ctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_epoll_et_revents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_epoll_et_revents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_epoll_reinit)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_epoll_reinit)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_cfg_show_stats)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_cfg_show_stats)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netdev_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netdev_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_unicast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_unicast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_broadcast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_broadcast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(void);
};

#else
#ifdef __aarch64__
union hmnet_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgehdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, int fd, int how);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int how);
	int (*p__actvbridgehdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgehdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, int fd, int backlog);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int backlog);
	int (*p__actvbridgehdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgehdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, int fd, int cmd, int val);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int cmd, int val);
	int (*p__actvbridgehdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int request, unsigned long args);
	int (*p__actvbridgehdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, int oldfd, int newfd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int oldfd, int newfd);
	int (*p__actvbridgehdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, uintptr_t argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uintptr_t argu_info);
	int (*p__actvbridgehdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgehdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned int loglevel);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int loglevel);
	int (*p__actvbridgehdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgehdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, int num);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int num);
	int (*p__actvbridgehdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgehdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgehdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgehdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned short familyid);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned short familyid);
	int (*p__actvbridgehdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgehdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgehdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgehdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgehdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned int cid);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid);
	int (*p__actvbridgehdlr_nethandler_compat_socket_revoke)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_revoke)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_fork)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_fork)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_socket)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_socket)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_socketpair)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_socketpair)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_close)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_close)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_bind)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_bind)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_listen)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_listen)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_accept)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_accept)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_connect)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_connect)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_send)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_send)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_sendmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_sendmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_recvmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_recvmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_sendto)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_sendto)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_recvfrom)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_recvfrom)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_getsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_getsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_setsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_setsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_getsockname)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_getsockname)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_getpeername)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_getpeername)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_fcntl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_fcntl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_ioctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_ioctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_dup)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_dup)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_put_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_put_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_epoll_ctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_epoll_ctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_epoll_et_revents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_epoll_et_revents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_epoll_reinit)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_epoll_reinit)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_cfg_show_stats)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_cfg_show_stats)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netdev_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netdev_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_unicast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_unicast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_broadcast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_broadcast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential, __u64 arg1, __u64 arg2, __u64 arg3);
};

#endif
#ifdef __arm__
union hmnet_hdlrs_union {
	void *p_sysif_actvhdlr_ptr_void;
	int (*p_sysif_default_handler)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgehdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_revoke)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fork)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socket)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_socketpair)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd, int fd2);
	int (*p__actvbridgehdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_close)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, int fd, int how);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_shutdown)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int how);
	int (*p__actvbridgehdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_bind)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t len);
	int (*p__actvbridgehdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, int fd, int backlog);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_listen)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int backlog);
	int (*p__actvbridgehdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_accept)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int sockfd, void *addr, void *addrlen, int flags, int fd);
	int (*p__actvbridgehdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_connect)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvmsg)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *msg, int flags);
	int (*p__actvbridgehdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_sendto)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recvfrom)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, void *optval, socklen_t *optlen);
	int (*p__actvbridgehdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_setsockopt)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, const void *optval, socklen_t optlen);
	int (*p__actvbridgehdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getsockname)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_getpeername)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen);
	int (*p__actvbridgehdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, int fd, int cmd, int val);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_fcntl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int cmd, int val);
	int (*p__actvbridgehdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_ioctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int request, unsigned long args);
	int (*p__actvbridgehdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, int oldfd, int newfd);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_dup)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int oldfd, int newfd);
	int (*p__actvbridgehdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_recv_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info);
	int (*p__actvbridgehdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, uintptr_t argu_info);
	int (*p__actvbridgecapcallhdlr_nethandler_socket_put_send_fd)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uintptr_t argu_info);
	int (*p__actvbridgehdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_ctl)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, int op, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_et_revents)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index);
	int (*p__actvbridgehdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgecapcallhdlr_nethandler_epoll_reinit)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info);
	int (*p__actvbridgehdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned int loglevel);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_loglevel)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int loglevel);
	int (*p__actvbridgehdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_show_stats)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct sysif_protocol ss_protocol, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long long shm_key);
	int (*p__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long long shm_key);
	int (*p__actvbridgehdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno);
	int (*p__actvbridgehdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features);
	int (*p__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, int num);
	int (*p__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int num);
	int (*p__actvbridgehdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_write)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS);
	int (*p__actvbridgehdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_fds_read)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files);
	int (*p__actvbridgehdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len);
	int (*p__actvbridgehdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_register_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref);
	int (*p__actvbridgehdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned short familyid);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned short familyid);
	int (*p__actvbridgehdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_unicast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_port);
	int (*p__actvbridgehdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgecapcallhdlr_nethandler_netlink_broadcast)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_group);
	int (*p__actvbridgehdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_register_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned int dev_group_id);
	int (*p__actvbridgehdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_vm_notify)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned short cmd, void *args, size_t size);
	int (*p__actvbridgehdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned int cid);
	int (*p__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid);
	int (*p__actvbridgehdlr_nethandler_compat_socket_revoke)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_revoke)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_fork)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_fork)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_socket)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_socket)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_socketpair)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_socketpair)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_close)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_close)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_shutdown)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_bind)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_bind)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_listen)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_listen)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_accept)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_accept)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_connect)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_connect)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_send)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_send)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_sendmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_sendmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_recvmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_recvmsg)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_sendto)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_sendto)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_recvfrom)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_recvfrom)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_getsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_getsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_setsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_setsockopt)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_getsockname)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_getsockname)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_getpeername)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_getpeername)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_fcntl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_fcntl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_ioctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_ioctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_dup)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_dup)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_recv_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_socket_put_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_socket_put_send_fd)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_epoll_ctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_epoll_ctl)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_epoll_et_revents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_epoll_et_revents)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_epoll_reinit)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_epoll_reinit)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_cfg_loglevel)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_cfg_show_stats)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_cfg_show_stats)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_cfg_getifaddrs)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netdev_rx)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netdev_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netdev_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netdev_rx_ex_slowdata)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_write)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_fds_read)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_procfs_get_fd_path)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_register_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_unregister_generic)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_unicast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_unicast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_netlink_broadcast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_netlink_broadcast)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_vsock_register_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_vsock_vm_notify)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgehdlr_nethandler_compat_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p__actvbridgecapcallhdlr_nethandler_compat_vsock_unregister_vm)(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3);
	int (*p_sysif_handle_kcall_entry)(unsigned long long sender, unsigned long credential);
};

#endif
#endif
#endif
#endif
extern union hmnet_hdlrs_union sysif_hmnet_actvhdlr_table[__hmnet_method_MAX];

extern union hmnet_hdlrs_union sysif_hmnet_actvcapcallhdlr_table[__hmnet_method_MAX];

extern void sysif_show_hmnet_methods(void);


#ifdef SYSIF_GEN_IFACE
#include <stdint.h>
#include <asm/actv_rpc.h>
#include <hongmeng/syscall.h>
#include <hongmeng/panic.h>
#include <hongmeng/errno.h>
#include <libstrict/strict.h>
#include <libhwsecurec/securec.h>
#include <libsysif/base/server_arg_compat.h>
#ifdef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_revoke(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_nethandler_socket_revoke(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_revoke(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_nethandler_socket_revoke(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_fork(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_nethandler_socket_fork(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_fork(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_nethandler_socket_fork(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_socket(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_socket(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, domain), __ARCH_ACTV_RPC_RECV_ARG(int, type), __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_socket(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_socket(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, domain), __ARCH_ACTV_RPC_RECV_ARG(int, type), __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_socketpair(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_socketpair(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, domain), __ARCH_ACTV_RPC_RECV_ARG(int, type), __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, fd2));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_socketpair(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd, int fd2)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_socketpair(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, domain), __ARCH_ACTV_RPC_RECV_ARG(int, type), __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, fd2));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_close(unsigned long long sender, unsigned long credential, int fd)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_close(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_close(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_close(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_shutdown(unsigned long long sender, unsigned long credential, int fd, int how)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_shutdown(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, how));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_shutdown(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int how)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_shutdown(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, how));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_bind(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_bind(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, len));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_bind(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t len)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_bind(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, len));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_listen(unsigned long long sender, unsigned long credential, int fd, int backlog)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_listen(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, backlog));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_listen(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int backlog)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_listen(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, backlog));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_accept(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_accept(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, sockfd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_accept(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_accept(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, sockfd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_connect(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_connect(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_connect(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_connect(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_send(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_send(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_send(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_send(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_sendmsg(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_sendmsg(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, msg), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_sendmsg(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *msg, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_sendmsg(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, msg), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_recvmsg(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recvmsg(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, msg), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_recvmsg(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *msg, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recvmsg(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, msg), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_sendto(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_sendto(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_sendto(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_sendto(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_recvfrom(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recvfrom(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_recvfrom(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recvfrom(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_getsockopt(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t*), __arch_actv_rpc_stksz_alignment(socklen_t*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getsockopt(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, level), __ARCH_ACTV_RPC_RECV_ARG(int, optname), __ARCH_ACTV_RPC_RECV_ARG(void*, optval), __ARCH_ACTV_RPC_RECV_ARG(socklen_t*, optlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_getsockopt(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t*), __arch_actv_rpc_stksz_alignment(socklen_t*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getsockopt(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, level), __ARCH_ACTV_RPC_RECV_ARG(int, optname), __ARCH_ACTV_RPC_RECV_ARG(void*, optval), __ARCH_ACTV_RPC_RECV_ARG(socklen_t*, optlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_setsockopt(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_setsockopt(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, level), __ARCH_ACTV_RPC_RECV_ARG(int, optname), __ARCH_ACTV_RPC_RECV_ARG(const void*, optval), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, optlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_setsockopt(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_setsockopt(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, level), __ARCH_ACTV_RPC_RECV_ARG(int, optname), __ARCH_ACTV_RPC_RECV_ARG(const void*, optval), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, optlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_getsockname(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getsockname(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_getsockname(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getsockname(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_getpeername(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getpeername(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_getpeername(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getpeername(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_fcntl(unsigned long long sender, unsigned long credential, int fd, int cmd, int val)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_fcntl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, cmd), __ARCH_ACTV_RPC_RECV_ARG(int, val));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_fcntl(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int cmd, int val)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_fcntl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, cmd), __ARCH_ACTV_RPC_RECV_ARG(int, val));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_ioctl(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_ioctl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, request), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, args));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_ioctl(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int request, unsigned long args)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_ioctl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, request), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, args));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_dup(unsigned long long sender, unsigned long credential, int oldfd, int newfd)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_dup(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, oldfd), __ARCH_ACTV_RPC_RECV_ARG(int, newfd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_dup(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int oldfd, int newfd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_dup(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, oldfd), __ARCH_ACTV_RPC_RECV_ARG(int, newfd));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_send_fd(unsigned long long sender, unsigned long credential, unsigned long argu_info)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_send_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, argu_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_send_fd(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_send_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, argu_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_recv_fd(unsigned long long sender, unsigned long credential, unsigned long argu_info)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recv_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, argu_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_recv_fd(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recv_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, argu_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_put_send_fd(unsigned long long sender, unsigned long credential, uintptr_t argu_info)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_put_send_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(uintptr_t, argu_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_put_send_fd(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uintptr_t argu_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_put_send_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(uintptr_t, argu_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_epoll_ctl(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_ctl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(int, op), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_reg_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_epoll_ctl(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, int op, const void *epoll_reg_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_ctl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(int, op), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_reg_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_epoll_et_revents(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_et_revents(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, epi_shm_key), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, epi_shm_index));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_epoll_et_revents(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_et_revents(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, epi_shm_key), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, epi_shm_index));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_epoll_reinit(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_reinit(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_pre_reg_info), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_reg_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_epoll_reinit(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_reinit(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_pre_reg_info), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_reg_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_cfg_loglevel(unsigned long long sender, unsigned long credential, unsigned int loglevel)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_loglevel(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, loglevel));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_cfg_loglevel(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int loglevel)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_loglevel(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, loglevel));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_cfg_show_stats(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysif_protocol), __arch_actv_rpc_stksz_alignment(struct sysif_protocol));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_show_stats(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct sysif_protocol, ss_protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, shm_key));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_cfg_show_stats(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysif_protocol), __arch_actv_rpc_stksz_alignment(struct sysif_protocol));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_show_stats(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct sysif_protocol, ss_protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, shm_key));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_cfg_getifaddrs(unsigned long long sender, unsigned long credential, unsigned long long shm_key)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_getifaddrs(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, shm_key));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_cfg_getifaddrs(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long long shm_key)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_getifaddrs(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, shm_key));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netdev_rx(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_rx(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cell_pool_offset), __ARCH_ACTV_RPC_RECV_ARG(int, shm_len), __ARCH_ACTV_RPC_RECV_ARG(int, rx_len), __ARCH_ACTV_RPC_RECV_ARG(int, offset), __ARCH_ACTV_RPC_RECV_ARG(int, devno));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netdev_rx(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_rx(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cell_pool_offset), __ARCH_ACTV_RPC_RECV_ARG(int, shm_len), __ARCH_ACTV_RPC_RECV_ARG(int, rx_len), __ARCH_ACTV_RPC_RECV_ARG(int, offset), __ARCH_ACTV_RPC_RECV_ARG(int, devno));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netdev_notify(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum hm_netdev_event), __arch_actv_rpc_stksz_alignment(enum hm_netdev_event));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct netdev_ifname), __arch_actv_rpc_stksz_alignment(struct netdev_ifname));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum hm_netdev_event, event), __ARCH_ACTV_RPC_RECV_ARG(int, devno), __ARCH_ACTV_RPC_RECV_ARG(int, option), __ARCH_ACTV_RPC_RECV_ARG(struct netdev_ifname, ifname), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, features));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netdev_notify(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum hm_netdev_event), __arch_actv_rpc_stksz_alignment(enum hm_netdev_event));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct netdev_ifname), __arch_actv_rpc_stksz_alignment(struct netdev_ifname));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum hm_netdev_event, event), __ARCH_ACTV_RPC_RECV_ARG(int, devno), __ARCH_ACTV_RPC_RECV_ARG(int, option), __ARCH_ACTV_RPC_RECV_ARG(struct netdev_ifname, ifname), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, features));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netdev_rx_ex_slowdata(unsigned long long sender, unsigned long credential, int num)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_rx_ex_slowdata(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, num));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int num)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_rx_ex_slowdata(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, num));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_procfs_read(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_nethandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_procfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_nethandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_procfs_write(unsigned long long sender, unsigned long credential)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_nethandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_procfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	return __actvshadowhdlr_nethandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_procfs_fds_read(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_procfs_fds_read(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, fd_map), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, max_files));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_procfs_fds_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_procfs_fds_read(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, fd_map), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, max_files));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_procfs_get_fd_path(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_procfs_get_fd_path(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx), __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, path_buf), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, path_buf_len));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_procfs_get_fd_path(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_procfs_get_fd_path(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx), __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, path_buf), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, path_buf_len));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netlink_register_generic(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref)
{
	UNUSED(__actv_fallback_unused_1, __actv_fallback_unused_2);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_register_generic(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, dh_ap_uref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netlink_register_generic(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	UNUSED(__actv_fallback_unused_1, __actv_fallback_unused_2);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_register_generic(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, dh_ap_uref));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netlink_unregister_generic(unsigned long long sender, unsigned long credential, unsigned short familyid)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_unregister_generic(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned short, familyid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netlink_unregister_generic(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned short familyid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_unregister_generic(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned short, familyid));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netlink_unicast(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_unicast(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, src_portid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dst_port));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netlink_unicast(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_port)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_unicast(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, src_portid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dst_port));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netlink_broadcast(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_broadcast(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, src_portid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dst_group));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netlink_broadcast(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_group)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_broadcast(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, src_portid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dst_group));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_vsock_register_vm(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_register_vm(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dev_group_id));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_vsock_register_vm(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned int dev_group_id)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_register_vm(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dev_group_id));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_vsock_vm_notify(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_vm_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid), __ARCH_ACTV_RPC_RECV_ARG(unsigned short, cmd), __ARCH_ACTV_RPC_RECV_ARG(void*, args), __ARCH_ACTV_RPC_RECV_ARG(size_t, size));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_vsock_vm_notify(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_vm_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid), __ARCH_ACTV_RPC_RECV_ARG(unsigned short, cmd), __ARCH_ACTV_RPC_RECV_ARG(void*, args), __ARCH_ACTV_RPC_RECV_ARG(size_t, size));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_vsock_unregister_vm(unsigned long long sender, unsigned long credential, unsigned int cid)
{
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_unregister_vm(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_vsock_unregister_vm(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	__maybe_unused unsigned long *__p_prev_frame = __builtin_frame_address(0);
	unsigned long __maybe_unused __stacksz = __ARCH_ACTV_STACK_ARG_SIZE;
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_unregister_vm(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid));
}

#ifndef __sysif_server_hmnet_no_compat32_handlers__
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
struct compat_x3 {
	unsigned int reserverd;
	unsigned int w3;
};

#else
struct compat_x3 {
	unsigned int w3;
	unsigned int reserverd;
};

#endif
static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_revoke(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_nethandler_socket_revoke(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_revoke(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_nethandler_socket_revoke(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_fork(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_nethandler_socket_fork(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_fork(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_nethandler_socket_fork(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_socket(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _domain;
	int __maybe_unused _type;
	int __maybe_unused _protocol;
	int __maybe_unused _fd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_domain, data, 0, arg_sz, model, type, int, _domain)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_type, data, 1, arg_sz, model, type, int, _type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_protocol, data, 2, arg_sz, model, type, int, _protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 3, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_socket(sender, credential, _domain, _type, _protocol, _fd);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_socket(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _domain;
	int __maybe_unused _type;
	int __maybe_unused _protocol;
	int __maybe_unused _fd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_domain, data, 0, arg_sz, model, type, int, _domain)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_type, data, 1, arg_sz, model, type, int, _type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_protocol, data, 2, arg_sz, model, type, int, _protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 3, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_socket(sender, credential, _domain, _type, _protocol, _fd);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_socketpair(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _domain;
	int __maybe_unused _type;
	int __maybe_unused _protocol;
	int __maybe_unused _fd;
	int __maybe_unused _fd2;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_domain, data, 0, arg_sz, model, type, int, _domain)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_type, data, 1, arg_sz, model, type, int, _type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_protocol, data, 2, arg_sz, model, type, int, _protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 3, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd2, data, 4, arg_sz, model, type, int, _fd2)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_socketpair(sender, credential, _domain, _type, _protocol, _fd, _fd2);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_socketpair(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _domain;
	int __maybe_unused _type;
	int __maybe_unused _protocol;
	int __maybe_unused _fd;
	int __maybe_unused _fd2;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_domain, data, 0, arg_sz, model, type, int, _domain)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_type, data, 1, arg_sz, model, type, int, _type)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_protocol, data, 2, arg_sz, model, type, int, _protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 3, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd2, data, 4, arg_sz, model, type, int, _fd2)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_socketpair(sender, credential, _domain, _type, _protocol, _fd, _fd2);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_close(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_close(sender, credential, _fd);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_close(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_close(sender, credential, _fd);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_shutdown(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _how;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_how, data, 1, arg_sz, model, type, int, _how)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_shutdown(sender, credential, _fd, _how);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_shutdown(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _how;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_how, data, 1, arg_sz, model, type, int, _how)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_shutdown(sender, credential, _fd, _how);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_bind(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_addr;
	socklen_t __maybe_unused _len;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, const void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t);
		type = __type_of(socklen_t);
		__fetch_one_arg((void*)&_len, data, 2, arg_sz, model, type, socklen_t, _len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_bind(sender, credential, _fd, _addr, _len);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_bind(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_addr;
	socklen_t __maybe_unused _len;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, const void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t);
		type = __type_of(socklen_t);
		__fetch_one_arg((void*)&_len, data, 2, arg_sz, model, type, socklen_t, _len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_bind(sender, credential, _fd, _addr, _len);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_listen(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _backlog;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_backlog, data, 1, arg_sz, model, type, int, _backlog)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_listen(sender, credential, _fd, _backlog);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_listen(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _backlog;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_backlog, data, 1, arg_sz, model, type, int, _backlog)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_listen(sender, credential, _fd, _backlog);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_accept(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _sockfd;
	__maybe_unused void *_addr;
	__maybe_unused void *_addrlen;
	int __maybe_unused _flags;
	int __maybe_unused _fd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_sockfd, data, 0, arg_sz, model, type, int, _sockfd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addrlen, data, 2, arg_sz, model, type, void*, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 4, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_accept(sender, credential, _sockfd, _addr, _addrlen, _flags, _fd);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_accept(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _sockfd;
	__maybe_unused void *_addr;
	__maybe_unused void *_addrlen;
	int __maybe_unused _flags;
	int __maybe_unused _fd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_sockfd, data, 0, arg_sz, model, type, int, _sockfd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addrlen, data, 2, arg_sz, model, type, void*, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 4, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_accept(sender, credential, _sockfd, _addr, _addrlen, _flags, _fd);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_connect(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_addr;
	socklen_t __maybe_unused _addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, const void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t);
		type = __type_of(socklen_t);
		__fetch_one_arg((void*)&_addrlen, data, 2, arg_sz, model, type, socklen_t, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_connect(sender, credential, _fd, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_connect(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_addr;
	socklen_t __maybe_unused _addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, const void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t);
		type = __type_of(socklen_t);
		__fetch_one_arg((void*)&_addrlen, data, 2, arg_sz, model, type, socklen_t, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_connect(sender, credential, _fd, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_send(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_buf;
	size_t __maybe_unused _len;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_buf, data, 1, arg_sz, model, type, const void*, _buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(size_t);
		type = __type_of(size_t);
		__fetch_one_arg((void*)&_len, data, 2, arg_sz, model, type, size_t, _len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_send(sender, credential, _fd, _buf, _len, _flags);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_send(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_buf;
	size_t __maybe_unused _len;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_buf, data, 1, arg_sz, model, type, const void*, _buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(size_t);
		type = __type_of(size_t);
		__fetch_one_arg((void*)&_len, data, 2, arg_sz, model, type, size_t, _len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_send(sender, credential, _fd, _buf, _len, _flags);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_sendmsg(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_msg;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_msg, data, 1, arg_sz, model, type, const void*, _msg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 2, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_sendmsg(sender, credential, _fd, _msg, _flags);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_sendmsg(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_msg;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_msg, data, 1, arg_sz, model, type, const void*, _msg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 2, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_sendmsg(sender, credential, _fd, _msg, _flags);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_recvmsg(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused void *_msg;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_msg, data, 1, arg_sz, model, type, void*, _msg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 2, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recvmsg(sender, credential, _fd, _msg, _flags);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_recvmsg(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused void *_msg;
	int __maybe_unused _flags;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_msg, data, 1, arg_sz, model, type, void*, _msg)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 2, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recvmsg(sender, credential, _fd, _msg, _flags);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_sendto(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_buf;
	size_t __maybe_unused _len;
	int __maybe_unused _flags;
	__maybe_unused const void *_addr;
	socklen_t __maybe_unused _addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_buf, data, 1, arg_sz, model, type, const void*, _buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(size_t);
		type = __type_of(size_t);
		__fetch_one_arg((void*)&_len, data, 2, arg_sz, model, type, size_t, _len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_addr, data, 4, arg_sz, model, type, const void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t);
		type = __type_of(socklen_t);
		__fetch_one_arg((void*)&_addrlen, data, 5, arg_sz, model, type, socklen_t, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_sendto(sender, credential, _fd, _buf, _len, _flags, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_sendto(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused const void *_buf;
	size_t __maybe_unused _len;
	int __maybe_unused _flags;
	__maybe_unused const void *_addr;
	socklen_t __maybe_unused _addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_buf, data, 1, arg_sz, model, type, const void*, _buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(size_t);
		type = __type_of(size_t);
		__fetch_one_arg((void*)&_len, data, 2, arg_sz, model, type, size_t, _len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_addr, data, 4, arg_sz, model, type, const void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t);
		type = __type_of(socklen_t);
		__fetch_one_arg((void*)&_addrlen, data, 5, arg_sz, model, type, socklen_t, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_sendto(sender, credential, _fd, _buf, _len, _flags, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_recvfrom(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused void *_buf;
	size_t __maybe_unused _len;
	int __maybe_unused _flags;
	__maybe_unused void *_addr;
	__maybe_unused void *_addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_buf, data, 1, arg_sz, model, type, void*, _buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(size_t);
		type = __type_of(size_t);
		__fetch_one_arg((void*)&_len, data, 2, arg_sz, model, type, size_t, _len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addr, data, 4, arg_sz, model, type, void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addrlen, data, 5, arg_sz, model, type, void*, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recvfrom(sender, credential, _fd, _buf, _len, _flags, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_recvfrom(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused void *_buf;
	size_t __maybe_unused _len;
	int __maybe_unused _flags;
	__maybe_unused void *_addr;
	__maybe_unused void *_addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_buf, data, 1, arg_sz, model, type, void*, _buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(size_t);
		type = __type_of(size_t);
		__fetch_one_arg((void*)&_len, data, 2, arg_sz, model, type, size_t, _len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_flags, data, 3, arg_sz, model, type, int, _flags)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addr, data, 4, arg_sz, model, type, void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addrlen, data, 5, arg_sz, model, type, void*, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recvfrom(sender, credential, _fd, _buf, _len, _flags, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_getsockopt(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _level;
	int __maybe_unused _optname;
	__maybe_unused void *_optval;
	__maybe_unused socklen_t *_optlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_level, data, 1, arg_sz, model, type, int, _level)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_optname, data, 2, arg_sz, model, type, int, _optname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_optval, data, 3, arg_sz, model, type, void*, _optval)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t*);
		type = __type_of(socklen_t*);
		__fetch_one_arg((void*)&_optlen, data, 4, arg_sz, model, type, socklen_t*, _optlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getsockopt(sender, credential, _fd, _level, _optname, _optval, _optlen);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_getsockopt(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _level;
	int __maybe_unused _optname;
	__maybe_unused void *_optval;
	__maybe_unused socklen_t *_optlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_level, data, 1, arg_sz, model, type, int, _level)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_optname, data, 2, arg_sz, model, type, int, _optname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_optval, data, 3, arg_sz, model, type, void*, _optval)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t*);
		type = __type_of(socklen_t*);
		__fetch_one_arg((void*)&_optlen, data, 4, arg_sz, model, type, socklen_t*, _optlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getsockopt(sender, credential, _fd, _level, _optname, _optval, _optlen);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_setsockopt(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _level;
	int __maybe_unused _optname;
	__maybe_unused const void *_optval;
	socklen_t __maybe_unused _optlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_level, data, 1, arg_sz, model, type, int, _level)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_optname, data, 2, arg_sz, model, type, int, _optname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_optval, data, 3, arg_sz, model, type, const void*, _optval)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t);
		type = __type_of(socklen_t);
		__fetch_one_arg((void*)&_optlen, data, 4, arg_sz, model, type, socklen_t, _optlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_setsockopt(sender, credential, _fd, _level, _optname, _optval, _optlen);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_setsockopt(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _level;
	int __maybe_unused _optname;
	__maybe_unused const void *_optval;
	socklen_t __maybe_unused _optlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_level, data, 1, arg_sz, model, type, int, _level)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_optname, data, 2, arg_sz, model, type, int, _optname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_optval, data, 3, arg_sz, model, type, const void*, _optval)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(socklen_t);
		type = __type_of(socklen_t);
		__fetch_one_arg((void*)&_optlen, data, 4, arg_sz, model, type, socklen_t, _optlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_setsockopt(sender, credential, _fd, _level, _optname, _optval, _optlen);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_getsockname(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused void *_addr;
	__maybe_unused void *_addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addrlen, data, 2, arg_sz, model, type, void*, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getsockname(sender, credential, _fd, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_getsockname(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused void *_addr;
	__maybe_unused void *_addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addrlen, data, 2, arg_sz, model, type, void*, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getsockname(sender, credential, _fd, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_getpeername(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused void *_addr;
	__maybe_unused void *_addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addrlen, data, 2, arg_sz, model, type, void*, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getpeername(sender, credential, _fd, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_getpeername(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	__maybe_unused void *_addr;
	__maybe_unused void *_addrlen;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addr, data, 1, arg_sz, model, type, void*, _addr)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_addrlen, data, 2, arg_sz, model, type, void*, _addrlen)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_getpeername(sender, credential, _fd, _addr, _addrlen);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_fcntl(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _cmd;
	int __maybe_unused _val;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_cmd, data, 1, arg_sz, model, type, int, _cmd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_val, data, 2, arg_sz, model, type, int, _val)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_fcntl(sender, credential, _fd, _cmd, _val);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_fcntl(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _cmd;
	int __maybe_unused _val;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_cmd, data, 1, arg_sz, model, type, int, _cmd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_val, data, 2, arg_sz, model, type, int, _val)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_fcntl(sender, credential, _fd, _cmd, _val);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_ioctl(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _request;
	unsigned long __maybe_unused _args;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_request, data, 1, arg_sz, model, type, int, _request)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_args, data, 2, arg_sz, model, type, unsigned long, _args)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_ioctl(sender, credential, _fd, _request, _args);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_ioctl(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _fd;
	int __maybe_unused _request;
	unsigned long __maybe_unused _args;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 0, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_request, data, 1, arg_sz, model, type, int, _request)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_args, data, 2, arg_sz, model, type, unsigned long, _args)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_ioctl(sender, credential, _fd, _request, _args);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_dup(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _oldfd;
	int __maybe_unused _newfd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_oldfd, data, 0, arg_sz, model, type, int, _oldfd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_newfd, data, 1, arg_sz, model, type, int, _newfd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_dup(sender, credential, _oldfd, _newfd);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_dup(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _oldfd;
	int __maybe_unused _newfd;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_oldfd, data, 0, arg_sz, model, type, int, _oldfd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_newfd, data, 1, arg_sz, model, type, int, _newfd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_dup(sender, credential, _oldfd, _newfd);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_send_fd(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long __maybe_unused _argu_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_argu_info, data, 0, arg_sz, model, type, unsigned long, _argu_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_send_fd(sender, credential, _argu_info);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_send_fd(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long __maybe_unused _argu_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_argu_info, data, 0, arg_sz, model, type, unsigned long, _argu_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_send_fd(sender, credential, _argu_info);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_recv_fd(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long __maybe_unused _argu_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_argu_info, data, 0, arg_sz, model, type, unsigned long, _argu_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recv_fd(sender, credential, _argu_info);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_recv_fd(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long __maybe_unused _argu_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long);
		type = __type_of(unsigned long);
		__fetch_one_arg((void*)&_argu_info, data, 0, arg_sz, model, type, unsigned long, _argu_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_recv_fd(sender, credential, _argu_info);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_socket_put_send_fd(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	uintptr_t __maybe_unused _argu_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(uintptr_t);
		type = __type_of(uintptr_t);
		__fetch_one_arg((void*)&_argu_info, data, 0, arg_sz, model, type, uintptr_t, _argu_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_put_send_fd(sender, credential, _argu_info);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_socket_put_send_fd(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	uintptr_t __maybe_unused _argu_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(uintptr_t);
		type = __type_of(uintptr_t);
		__fetch_one_arg((void*)&_argu_info, data, 0, arg_sz, model, type, uintptr_t, _argu_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_socket_put_send_fd(sender, credential, _argu_info);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_epoll_ctl(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _socket_fd;
	int __maybe_unused _op;
	__maybe_unused const void *_epoll_reg_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_socket_fd, data, 0, arg_sz, model, type, int, _socket_fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_op, data, 1, arg_sz, model, type, int, _op)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_epoll_reg_info, data, 2, arg_sz, model, type, const void*, _epoll_reg_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_ctl(sender, credential, _socket_fd, _op, _epoll_reg_info);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_epoll_ctl(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _socket_fd;
	int __maybe_unused _op;
	__maybe_unused const void *_epoll_reg_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_socket_fd, data, 0, arg_sz, model, type, int, _socket_fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_op, data, 1, arg_sz, model, type, int, _op)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_epoll_reg_info, data, 2, arg_sz, model, type, const void*, _epoll_reg_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_ctl(sender, credential, _socket_fd, _op, _epoll_reg_info);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_epoll_et_revents(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _socket_fd;
	unsigned long long __maybe_unused _epi_shm_key;
	unsigned int __maybe_unused _epi_shm_index;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_socket_fd, data, 0, arg_sz, model, type, int, _socket_fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_epi_shm_key, data, 1, arg_sz, model, type, unsigned long long, _epi_shm_key)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_epi_shm_index, data, 2, arg_sz, model, type, unsigned int, _epi_shm_index)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_et_revents(sender, credential, _socket_fd, _epi_shm_key, _epi_shm_index);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_epoll_et_revents(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _socket_fd;
	unsigned long long __maybe_unused _epi_shm_key;
	unsigned int __maybe_unused _epi_shm_index;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_socket_fd, data, 0, arg_sz, model, type, int, _socket_fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_epi_shm_key, data, 1, arg_sz, model, type, unsigned long long, _epi_shm_key)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_epi_shm_index, data, 2, arg_sz, model, type, unsigned int, _epi_shm_index)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_et_revents(sender, credential, _socket_fd, _epi_shm_key, _epi_shm_index);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_epoll_reinit(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _socket_fd;
	__maybe_unused const void *_epoll_pre_reg_info;
	__maybe_unused const void *_epoll_reg_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_socket_fd, data, 0, arg_sz, model, type, int, _socket_fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_epoll_pre_reg_info, data, 1, arg_sz, model, type, const void*, _epoll_pre_reg_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_epoll_reg_info, data, 2, arg_sz, model, type, const void*, _epoll_reg_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_reinit(sender, credential, _socket_fd, _epoll_pre_reg_info, _epoll_reg_info);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_epoll_reinit(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _socket_fd;
	__maybe_unused const void *_epoll_pre_reg_info;
	__maybe_unused const void *_epoll_reg_info;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_socket_fd, data, 0, arg_sz, model, type, int, _socket_fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_epoll_pre_reg_info, data, 1, arg_sz, model, type, const void*, _epoll_pre_reg_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(const void*);
		type = __type_of(const void*);
		__fetch_one_arg((void*)&_epoll_reg_info, data, 2, arg_sz, model, type, const void*, _epoll_reg_info)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_epoll_reinit(sender, credential, _socket_fd, _epoll_pre_reg_info, _epoll_reg_info);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_cfg_loglevel(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _loglevel;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_loglevel, data, 0, arg_sz, model, type, unsigned int, _loglevel)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_loglevel(sender, credential, _loglevel);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_cfg_loglevel(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _loglevel;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_loglevel, data, 0, arg_sz, model, type, unsigned int, _loglevel)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_loglevel(sender, credential, _loglevel);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_cfg_show_stats(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct sysif_protocol __maybe_unused _ss_protocol;
	unsigned long long __maybe_unused _shm_key;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct sysif_protocol);
		type = __type_of(struct sysif_protocol);
		__fetch_one_arg((void*)&_ss_protocol, data, 0, arg_sz, model, type, struct sysif_protocol, _ss_protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_shm_key, data, 1, arg_sz, model, type, unsigned long long, _shm_key)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_show_stats(sender, credential, _ss_protocol, _shm_key);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_cfg_show_stats(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	struct sysif_protocol __maybe_unused _ss_protocol;
	unsigned long long __maybe_unused _shm_key;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct sysif_protocol);
		type = __type_of(struct sysif_protocol);
		__fetch_one_arg((void*)&_ss_protocol, data, 0, arg_sz, model, type, struct sysif_protocol, _ss_protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_shm_key, data, 1, arg_sz, model, type, unsigned long long, _shm_key)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_show_stats(sender, credential, _ss_protocol, _shm_key);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_cfg_getifaddrs(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long long __maybe_unused _shm_key;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_shm_key, data, 0, arg_sz, model, type, unsigned long long, _shm_key)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_getifaddrs(sender, credential, _shm_key);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_cfg_getifaddrs(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long long __maybe_unused _shm_key;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_shm_key, data, 0, arg_sz, model, type, unsigned long long, _shm_key)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_cfg_getifaddrs(sender, credential, _shm_key);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_netdev_rx(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cell_pool_offset;
	int __maybe_unused _shm_len;
	int __maybe_unused _rx_len;
	int __maybe_unused _offset;
	int __maybe_unused _devno;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cell_pool_offset, data, 0, arg_sz, model, type, unsigned int, _cell_pool_offset)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_len, data, 1, arg_sz, model, type, int, _shm_len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_rx_len, data, 2, arg_sz, model, type, int, _rx_len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_offset, data, 3, arg_sz, model, type, int, _offset)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_devno, data, 4, arg_sz, model, type, int, _devno)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_rx(sender, credential, _cell_pool_offset, _shm_len, _rx_len, _offset, _devno);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_netdev_rx(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cell_pool_offset;
	int __maybe_unused _shm_len;
	int __maybe_unused _rx_len;
	int __maybe_unused _offset;
	int __maybe_unused _devno;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cell_pool_offset, data, 0, arg_sz, model, type, unsigned int, _cell_pool_offset)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_shm_len, data, 1, arg_sz, model, type, int, _shm_len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_rx_len, data, 2, arg_sz, model, type, int, _rx_len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_offset, data, 3, arg_sz, model, type, int, _offset)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_devno, data, 4, arg_sz, model, type, int, _devno)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_rx(sender, credential, _cell_pool_offset, _shm_len, _rx_len, _offset, _devno);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_netdev_notify(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	enum hm_netdev_event __maybe_unused _event;
	int __maybe_unused _devno;
	int __maybe_unused _option;
	struct netdev_ifname __maybe_unused _ifname;
	unsigned long long __maybe_unused _features;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(enum hm_netdev_event);
		type = __type_of(enum hm_netdev_event);
		__fetch_one_arg((void*)&_event, data, 0, arg_sz, model, type, enum hm_netdev_event, _event)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_devno, data, 1, arg_sz, model, type, int, _devno)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_option, data, 2, arg_sz, model, type, int, _option)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct netdev_ifname);
		type = __type_of(struct netdev_ifname);
		__fetch_one_arg((void*)&_ifname, data, 3, arg_sz, model, type, struct netdev_ifname, _ifname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_features, data, 4, arg_sz, model, type, unsigned long long, _features)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_notify(sender, credential, _event, _devno, _option, _ifname, _features);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_netdev_notify(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	enum hm_netdev_event __maybe_unused _event;
	int __maybe_unused _devno;
	int __maybe_unused _option;
	struct netdev_ifname __maybe_unused _ifname;
	unsigned long long __maybe_unused _features;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(enum hm_netdev_event);
		type = __type_of(enum hm_netdev_event);
		__fetch_one_arg((void*)&_event, data, 0, arg_sz, model, type, enum hm_netdev_event, _event)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_devno, data, 1, arg_sz, model, type, int, _devno)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_option, data, 2, arg_sz, model, type, int, _option)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(struct netdev_ifname);
		type = __type_of(struct netdev_ifname);
		__fetch_one_arg((void*)&_ifname, data, 3, arg_sz, model, type, struct netdev_ifname, _ifname)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_features, data, 4, arg_sz, model, type, unsigned long long, _features)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_notify(sender, credential, _event, _devno, _option, _ifname, _features);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_netdev_rx_ex_slowdata(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _num;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_num, data, 0, arg_sz, model, type, int, _num)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_rx_ex_slowdata(sender, credential, _num);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_netdev_rx_ex_slowdata(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _num;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_num, data, 0, arg_sz, model, type, int, _num)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netdev_rx_ex_slowdata(sender, credential, _num);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_procfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_nethandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_procfs_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_nethandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_procfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_nethandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_procfs_write(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	return __actvshadowhdlr_nethandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_procfs_fds_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cnode_idx;
	unsigned long long __maybe_unused _fd_map;
	unsigned int __maybe_unused _max_files;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cnode_idx, data, 0, arg_sz, model, type, unsigned int, _cnode_idx)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_fd_map, data, 1, arg_sz, model, type, unsigned long long, _fd_map)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_max_files, data, 2, arg_sz, model, type, unsigned int, _max_files)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_procfs_fds_read(sender, credential, _cnode_idx, _fd_map, _max_files);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_procfs_fds_read(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cnode_idx;
	unsigned long long __maybe_unused _fd_map;
	unsigned int __maybe_unused _max_files;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cnode_idx, data, 0, arg_sz, model, type, unsigned int, _cnode_idx)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_fd_map, data, 1, arg_sz, model, type, unsigned long long, _fd_map)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_max_files, data, 2, arg_sz, model, type, unsigned int, _max_files)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_procfs_fds_read(sender, credential, _cnode_idx, _fd_map, _max_files);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_procfs_get_fd_path(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cnode_idx;
	int __maybe_unused _fd;
	unsigned long long __maybe_unused _path_buf;
	unsigned int __maybe_unused _path_buf_len;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cnode_idx, data, 0, arg_sz, model, type, unsigned int, _cnode_idx)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 1, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_path_buf, data, 2, arg_sz, model, type, unsigned long long, _path_buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_path_buf_len, data, 3, arg_sz, model, type, unsigned int, _path_buf_len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_procfs_get_fd_path(sender, credential, _cnode_idx, _fd, _path_buf, _path_buf_len);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_procfs_get_fd_path(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cnode_idx;
	int __maybe_unused _fd;
	unsigned long long __maybe_unused _path_buf;
	unsigned int __maybe_unused _path_buf_len;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cnode_idx, data, 0, arg_sz, model, type, unsigned int, _cnode_idx)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_fd, data, 1, arg_sz, model, type, int, _fd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_path_buf, data, 2, arg_sz, model, type, unsigned long long, _path_buf)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_path_buf_len, data, 3, arg_sz, model, type, unsigned int, _path_buf_len)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_procfs_get_fd_path(sender, credential, _cnode_idx, _fd, _path_buf, _path_buf_len);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_netlink_register_generic(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long long __maybe_unused _dh_ap_uref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_dh_ap_uref, data, 0, arg_sz, model, type, unsigned long long, _dh_ap_uref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_register_generic(sender, credential, _dh_ap_uref);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_netlink_register_generic(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_THREE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned long long __maybe_unused _dh_ap_uref;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned long long);
		type = __type_of(unsigned long long);
		__fetch_one_arg((void*)&_dh_ap_uref, data, 0, arg_sz, model, type, unsigned long long, _dh_ap_uref)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_register_generic(sender, credential, _dh_ap_uref);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_netlink_unregister_generic(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned short __maybe_unused _familyid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned short);
		type = __type_of(unsigned short);
		__fetch_one_arg((void*)&_familyid, data, 0, arg_sz, model, type, unsigned short, _familyid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_unregister_generic(sender, credential, _familyid);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_netlink_unregister_generic(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned short __maybe_unused _familyid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned short);
		type = __type_of(unsigned short);
		__fetch_one_arg((void*)&_familyid, data, 0, arg_sz, model, type, unsigned short, _familyid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_unregister_generic(sender, credential, _familyid);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_netlink_unicast(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _protocol;
	unsigned int __maybe_unused _src_portid;
	unsigned int __maybe_unused _dst_port;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_protocol, data, 0, arg_sz, model, type, int, _protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_src_portid, data, 1, arg_sz, model, type, unsigned int, _src_portid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_dst_port, data, 2, arg_sz, model, type, unsigned int, _dst_port)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_unicast(sender, credential, _protocol, _src_portid, _dst_port);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_netlink_unicast(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _protocol;
	unsigned int __maybe_unused _src_portid;
	unsigned int __maybe_unused _dst_port;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_protocol, data, 0, arg_sz, model, type, int, _protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_src_portid, data, 1, arg_sz, model, type, unsigned int, _src_portid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_dst_port, data, 2, arg_sz, model, type, unsigned int, _dst_port)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_unicast(sender, credential, _protocol, _src_portid, _dst_port);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_netlink_broadcast(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _protocol;
	unsigned int __maybe_unused _src_portid;
	unsigned int __maybe_unused _dst_group;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_protocol, data, 0, arg_sz, model, type, int, _protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_src_portid, data, 1, arg_sz, model, type, unsigned int, _src_portid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_dst_group, data, 2, arg_sz, model, type, unsigned int, _dst_group)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_broadcast(sender, credential, _protocol, _src_portid, _dst_group);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_netlink_broadcast(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	int __maybe_unused _protocol;
	unsigned int __maybe_unused _src_portid;
	unsigned int __maybe_unused _dst_group;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(int);
		type = __type_of(int);
		__fetch_one_arg((void*)&_protocol, data, 0, arg_sz, model, type, int, _protocol)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_src_portid, data, 1, arg_sz, model, type, unsigned int, _src_portid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_dst_group, data, 2, arg_sz, model, type, unsigned int, _dst_group)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_netlink_broadcast(sender, credential, _protocol, _src_portid, _dst_group);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_vsock_register_vm(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cid;
	unsigned int __maybe_unused _dev_group_id;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cid, data, 0, arg_sz, model, type, unsigned int, _cid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_dev_group_id, data, 1, arg_sz, model, type, unsigned int, _dev_group_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_register_vm(sender, credential, _cid, _dev_group_id);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_vsock_register_vm(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cid;
	unsigned int __maybe_unused _dev_group_id;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cid, data, 0, arg_sz, model, type, unsigned int, _cid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_dev_group_id, data, 1, arg_sz, model, type, unsigned int, _dev_group_id)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_register_vm(sender, credential, _cid, _dev_group_id);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_vsock_vm_notify(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cid;
	unsigned short __maybe_unused _cmd;
	__maybe_unused void *_args;
	size_t __maybe_unused _size;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cid, data, 0, arg_sz, model, type, unsigned int, _cid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned short);
		type = __type_of(unsigned short);
		__fetch_one_arg((void*)&_cmd, data, 1, arg_sz, model, type, unsigned short, _cmd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_args, data, 2, arg_sz, model, type, void*, _args)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(size_t);
		type = __type_of(size_t);
		__fetch_one_arg((void*)&_size, data, 3, arg_sz, model, type, size_t, _size)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_vm_notify(sender, credential, _cid, _cmd, _args, _size);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_vsock_vm_notify(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cid;
	unsigned short __maybe_unused _cmd;
	__maybe_unused void *_args;
	size_t __maybe_unused _size;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cid, data, 0, arg_sz, model, type, unsigned int, _cid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned short);
		type = __type_of(unsigned short);
		__fetch_one_arg((void*)&_cmd, data, 1, arg_sz, model, type, unsigned short, _cmd)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(void*);
		type = __type_of(void*);
		__fetch_one_arg((void*)&_args, data, 2, arg_sz, model, type, void*, _args)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(size_t);
		type = __type_of(size_t);
		__fetch_one_arg((void*)&_size, data, 3, arg_sz, model, type, size_t, _size)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_vm_notify(sender, credential, _cid, _cmd, _args, _size);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_compat_vsock_unregister_vm(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_NONE;
	bool __maybe_unused is_r3_passing = true;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cid, data, 0, arg_sz, model, type, unsigned int, _cid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_unregister_vm(sender, credential, _cid);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_compat_vsock_unregister_vm(unsigned long long sender, unsigned long credential, unsigned long sp, unsigned long x3)
{
	__maybe_unused union {
		unsigned long x3;
		struct compat_x3 __compat_x3;
	} ___val = {
		0
	};
	___val.x3 = x3;
	unsigned int __maybe_unused ___w3 = ___val.__compat_x3.w3;
	__maybe_unused char *data = (char*)(uintptr_t)sp;
	unsigned int __maybe_unused cursor = __RPC_ACTVCALL_HDLR_UNUSED_ARGS_ONE;
	bool __maybe_unused is_r3_passing = false;
	enum __data_model __maybe_unused model = _DATA_MODEL_ILP32;
	enum __type __maybe_unused type;
	unsigned int __maybe_unused _cid;
	do {
		int fetch_sz;
		unsigned long align;
		unsigned long arg_sz = sizeof(unsigned int);
		type = __type_of(unsigned int);
		__fetch_one_arg((void*)&_cid, data, 0, arg_sz, model, type, unsigned int, _cid)
		if (fetch_sz < 0) {
			panic("failed to fetch arg: %s\n", hmstrerror(fetch_sz));
		}
		cursor += fetch_sz;
	} while (0);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	if (__nr_ul * sizeof(__u32) != cursor) {
		return E_HM_INVAL;
	}
	return __actvshadowhdlr_nethandler_vsock_unregister_vm(sender, credential, _cid);
}

#endif
#else
static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_revoke(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_nethandler_socket_revoke(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_revoke(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_nethandler_socket_revoke(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_fork(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_nethandler_socket_fork(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_fork(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_nethandler_socket_fork(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_socket(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_socket(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, domain), __ARCH_ACTV_RPC_RECV_ARG(int, type), __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_socket(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_socket(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, domain), __ARCH_ACTV_RPC_RECV_ARG(int, type), __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_socketpair(unsigned long long sender, unsigned long credential, int domain, int type, int protocol, int fd, int fd2)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_socketpair(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, domain), __ARCH_ACTV_RPC_RECV_ARG(int, type), __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, fd2));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_socketpair(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int domain, int type, int protocol, int fd, int fd2)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_socketpair(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, domain), __ARCH_ACTV_RPC_RECV_ARG(int, type), __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, fd2));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_close(unsigned long long sender, unsigned long credential, int fd)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_close(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_close(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_close(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_shutdown(unsigned long long sender, unsigned long credential, int fd, int how)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_shutdown(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, how));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_shutdown(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int how)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_shutdown(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, how));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_bind(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t len)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_bind(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, len));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_bind(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t len)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_bind(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, len));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_listen(unsigned long long sender, unsigned long credential, int fd, int backlog)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_listen(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, backlog));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_listen(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int backlog)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_listen(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, backlog));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_accept(unsigned long long sender, unsigned long credential, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_accept(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, sockfd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_accept(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_accept(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, sockfd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(int, fd));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_connect(unsigned long long sender, unsigned long credential, int fd, const void *addr, socklen_t addrlen)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_connect(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_connect(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *addr, socklen_t addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_connect(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_send(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_send(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_send(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_send(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_sendmsg(unsigned long long sender, unsigned long credential, int fd, const void *msg, int flags)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_sendmsg(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, msg), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_sendmsg(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *msg, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_sendmsg(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, msg), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_recvmsg(unsigned long long sender, unsigned long credential, int fd, void *msg, int flags)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_recvmsg(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, msg), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_recvmsg(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *msg, int flags)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_recvmsg(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, msg), __ARCH_ACTV_RPC_RECV_ARG(int, flags));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_sendto(unsigned long long sender, unsigned long credential, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_sendto(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_sendto(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_sendto(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(const void*, addr), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_recvfrom(unsigned long long sender, unsigned long credential, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_recvfrom(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_recvfrom(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_recvfrom(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, buf), __ARCH_ACTV_RPC_RECV_ARG(size_t, len), __ARCH_ACTV_RPC_RECV_ARG(int, flags), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_getsockopt(unsigned long long sender, unsigned long credential, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t*), __arch_actv_rpc_stksz_alignment(socklen_t*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_getsockopt(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, level), __ARCH_ACTV_RPC_RECV_ARG(int, optname), __ARCH_ACTV_RPC_RECV_ARG(void*, optval), __ARCH_ACTV_RPC_RECV_ARG(socklen_t*, optlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_getsockopt(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t*), __arch_actv_rpc_stksz_alignment(socklen_t*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_getsockopt(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, level), __ARCH_ACTV_RPC_RECV_ARG(int, optname), __ARCH_ACTV_RPC_RECV_ARG(void*, optval), __ARCH_ACTV_RPC_RECV_ARG(socklen_t*, optlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_setsockopt(unsigned long long sender, unsigned long credential, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_setsockopt(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, level), __ARCH_ACTV_RPC_RECV_ARG(int, optname), __ARCH_ACTV_RPC_RECV_ARG(const void*, optval), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, optlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_setsockopt(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(socklen_t), __arch_actv_rpc_stksz_alignment(socklen_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_setsockopt(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, level), __ARCH_ACTV_RPC_RECV_ARG(int, optname), __ARCH_ACTV_RPC_RECV_ARG(const void*, optval), __ARCH_ACTV_RPC_RECV_ARG(socklen_t, optlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_getsockname(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_getsockname(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_getsockname(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_getsockname(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_getpeername(unsigned long long sender, unsigned long credential, int fd, void *addr, void *addrlen)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_getpeername(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_getpeername(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, void *addr, void *addrlen)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_getpeername(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(void*, addr), __ARCH_ACTV_RPC_RECV_ARG(void*, addrlen));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_fcntl(unsigned long long sender, unsigned long credential, int fd, int cmd, int val)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_fcntl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, cmd), __ARCH_ACTV_RPC_RECV_ARG(int, val));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_fcntl(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int cmd, int val)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_fcntl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, cmd), __ARCH_ACTV_RPC_RECV_ARG(int, val));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_ioctl(unsigned long long sender, unsigned long credential, int fd, int request, unsigned long args)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_ioctl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, request), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, args));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_ioctl(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int fd, int request, unsigned long args)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_ioctl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(int, request), __ARCH_ACTV_RPC_RECV_ARG(unsigned long, args));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_dup(unsigned long long sender, unsigned long credential, int oldfd, int newfd)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_dup(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, oldfd), __ARCH_ACTV_RPC_RECV_ARG(int, newfd));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_dup(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int oldfd, int newfd)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_dup(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, oldfd), __ARCH_ACTV_RPC_RECV_ARG(int, newfd));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_send_fd(unsigned long long sender, unsigned long credential, unsigned long argu_info)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_send_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, argu_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_send_fd(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_send_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, argu_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_recv_fd(unsigned long long sender, unsigned long credential, unsigned long argu_info)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_recv_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, argu_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_recv_fd(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long argu_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long), __arch_actv_rpc_stksz_alignment(unsigned long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_recv_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long, argu_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_socket_put_send_fd(unsigned long long sender, unsigned long credential, uintptr_t argu_info)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_put_send_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(uintptr_t, argu_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_socket_put_send_fd(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, uintptr_t argu_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(uintptr_t), __arch_actv_rpc_stksz_alignment(uintptr_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_socket_put_send_fd(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(uintptr_t, argu_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_epoll_ctl(unsigned long long sender, unsigned long credential, int socket_fd, int op, const void *epoll_reg_info)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_epoll_ctl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(int, op), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_reg_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_epoll_ctl(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, int op, const void *epoll_reg_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_epoll_ctl(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(int, op), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_reg_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_epoll_et_revents(unsigned long long sender, unsigned long credential, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_epoll_et_revents(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, epi_shm_key), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, epi_shm_index));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_epoll_et_revents(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_epoll_et_revents(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, epi_shm_key), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, epi_shm_index));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_epoll_reinit(unsigned long long sender, unsigned long credential, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_epoll_reinit(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_pre_reg_info), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_reg_info));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_epoll_reinit(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(const void*), __arch_actv_rpc_stksz_alignment(const void*));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_epoll_reinit(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, socket_fd), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_pre_reg_info), __ARCH_ACTV_RPC_RECV_ARG(const void*, epoll_reg_info));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_cfg_loglevel(unsigned long long sender, unsigned long credential, unsigned int loglevel)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_cfg_loglevel(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, loglevel));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_cfg_loglevel(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int loglevel)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_cfg_loglevel(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, loglevel));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_cfg_show_stats(unsigned long long sender, unsigned long credential, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysif_protocol), __arch_actv_rpc_stksz_alignment(struct sysif_protocol));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_cfg_show_stats(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct sysif_protocol, ss_protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, shm_key));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_cfg_show_stats(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct sysif_protocol), __arch_actv_rpc_stksz_alignment(struct sysif_protocol));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_cfg_show_stats(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(struct sysif_protocol, ss_protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, shm_key));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_cfg_getifaddrs(unsigned long long sender, unsigned long credential, unsigned long long shm_key)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_cfg_getifaddrs(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, shm_key));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_cfg_getifaddrs(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long long shm_key)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_cfg_getifaddrs(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, shm_key));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netdev_rx(unsigned long long sender, unsigned long credential, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netdev_rx(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cell_pool_offset), __ARCH_ACTV_RPC_RECV_ARG(int, shm_len), __ARCH_ACTV_RPC_RECV_ARG(int, rx_len), __ARCH_ACTV_RPC_RECV_ARG(int, offset), __ARCH_ACTV_RPC_RECV_ARG(int, devno));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netdev_rx(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netdev_rx(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cell_pool_offset), __ARCH_ACTV_RPC_RECV_ARG(int, shm_len), __ARCH_ACTV_RPC_RECV_ARG(int, rx_len), __ARCH_ACTV_RPC_RECV_ARG(int, offset), __ARCH_ACTV_RPC_RECV_ARG(int, devno));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netdev_notify(unsigned long long sender, unsigned long credential, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum hm_netdev_event), __arch_actv_rpc_stksz_alignment(enum hm_netdev_event));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct netdev_ifname), __arch_actv_rpc_stksz_alignment(struct netdev_ifname));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netdev_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum hm_netdev_event, event), __ARCH_ACTV_RPC_RECV_ARG(int, devno), __ARCH_ACTV_RPC_RECV_ARG(int, option), __ARCH_ACTV_RPC_RECV_ARG(struct netdev_ifname, ifname), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, features));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netdev_notify(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(enum hm_netdev_event), __arch_actv_rpc_stksz_alignment(enum hm_netdev_event));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(struct netdev_ifname), __arch_actv_rpc_stksz_alignment(struct netdev_ifname));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netdev_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(enum hm_netdev_event, event), __ARCH_ACTV_RPC_RECV_ARG(int, devno), __ARCH_ACTV_RPC_RECV_ARG(int, option), __ARCH_ACTV_RPC_RECV_ARG(struct netdev_ifname, ifname), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, features));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netdev_rx_ex_slowdata(unsigned long long sender, unsigned long credential, int num)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netdev_rx_ex_slowdata(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, num));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int num)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netdev_rx_ex_slowdata(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, num));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_procfs_read(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_nethandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_procfs_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_nethandler_procfs_read(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_procfs_write(unsigned long long sender, unsigned long credential)
{
	return actvhdlr_nethandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_procfs_write(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	return actvhdlr_nethandler_procfs_write(sender, credential);
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_procfs_fds_read(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_procfs_fds_read(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, fd_map), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, max_files));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_procfs_fds_read(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_procfs_fds_read(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, fd_map), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, max_files));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_procfs_get_fd_path(unsigned long long sender, unsigned long credential, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_procfs_get_fd_path(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx), __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, path_buf), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, path_buf_len));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_procfs_get_fd_path(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_procfs_get_fd_path(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cnode_idx), __ARCH_ACTV_RPC_RECV_ARG(int, fd), __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, path_buf), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, path_buf_len));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netlink_register_generic(unsigned long long sender, unsigned long credential, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref)
{
	UNUSED(__actv_fallback_unused_1, __actv_fallback_unused_2);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netlink_register_generic(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, dh_ap_uref));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netlink_register_generic(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned long __actv_fallback_unused_1, unsigned long __actv_fallback_unused_2, unsigned long long dh_ap_uref)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	UNUSED(__actv_fallback_unused_1, __actv_fallback_unused_2);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 1);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned long long), __arch_actv_rpc_stksz_alignment(unsigned long long));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netlink_register_generic(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned long long, dh_ap_uref));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netlink_unregister_generic(unsigned long long sender, unsigned long credential, unsigned short familyid)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netlink_unregister_generic(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned short, familyid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netlink_unregister_generic(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned short familyid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netlink_unregister_generic(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned short, familyid));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netlink_unicast(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_port)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netlink_unicast(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, src_portid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dst_port));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netlink_unicast(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_port)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netlink_unicast(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, src_portid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dst_port));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_netlink_broadcast(unsigned long long sender, unsigned long credential, int protocol, unsigned int src_portid, unsigned int dst_group)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netlink_broadcast(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, src_portid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dst_group));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_netlink_broadcast(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, int protocol, unsigned int src_portid, unsigned int dst_group)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(int), __arch_actv_rpc_stksz_alignment(int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_netlink_broadcast(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(int, protocol), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, src_portid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dst_group));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_vsock_register_vm(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned int dev_group_id)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_vsock_register_vm(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dev_group_id));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_vsock_register_vm(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned int dev_group_id)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_vsock_register_vm(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid), __ARCH_ACTV_RPC_RECV_ARG(unsigned int, dev_group_id));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_vsock_vm_notify(unsigned long long sender, unsigned long credential, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_vsock_vm_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid), __ARCH_ACTV_RPC_RECV_ARG(unsigned short, cmd), __ARCH_ACTV_RPC_RECV_ARG(void*, args), __ARCH_ACTV_RPC_RECV_ARG(size_t, size));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_vsock_vm_notify(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned short), __arch_actv_rpc_stksz_alignment(unsigned short));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(void*), __arch_actv_rpc_stksz_alignment(void*));
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(size_t), __arch_actv_rpc_stksz_alignment(size_t));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_vsock_vm_notify(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid), __ARCH_ACTV_RPC_RECV_ARG(unsigned short, cmd), __ARCH_ACTV_RPC_RECV_ARG(void*, args), __ARCH_ACTV_RPC_RECV_ARG(size_t, size));
}

static int __opt_nonoframe __actvbridgehdlr_nethandler_vsock_unregister_vm(unsigned long long sender, unsigned long credential, unsigned int cid)
{
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(0, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_vsock_unregister_vm(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid));
}

static int __opt_nonoframe __actvbridgecapcallhdlr_nethandler_vsock_unregister_vm(unsigned long long sender, unsigned long credential, __RPC_CAPCALL_HDLR_UNUSED_ARGS, unsigned int cid)
{
	UNUSED(__RPC_CAPCALL_HDLR_UNUSED_ARGS_STRICT);
	struct arch_actv_local *__local = hm_actv_current_arch_actv_local();
	unsigned long __nr_ul = __RPC_INFO_DECODE_STK_BUF_NR_UL(__local->rpcinfo);
	unsigned long __maybe_unused __stacksz = 0UL;
	struct __arch_actv_stksz_state __stksz_state;
	__stksz_state = __arch_actv_rpc_stksz_init(1, 0);
	__stksz_state = __arch_actv_rpc_stksz_append(__stksz_state, sizeof(unsigned int), __arch_actv_rpc_stksz_alignment(unsigned int));
	__stacksz = __arch_actv_rpc_stksz_done(__stksz_state);
	if (__nr_ul * sizeof(unsigned long) != __stacksz) {
		return E_HM_INVAL;
	}
	return actvhdlr_nethandler_vsock_unregister_vm(sender, credential, __ARCH_ACTV_RPC_RECV_ARG(unsigned int, cid));
}

#endif
#ifdef __sysif_server_hmnet_no_compat32_handlers__
union hmnet_hdlrs_union sysif_hmnet_actvhdlr_table[__hmnet_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __hmnet_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__hmnet_method_socket_rsvd_7] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_6] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_5] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_4] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_revoke] = {
		.p__actvbridgehdlr_nethandler_socket_revoke = (&__actvbridgehdlr_nethandler_socket_revoke)
	},
	[__hmnet_method_socket_fork] = {
		.p__actvbridgehdlr_nethandler_socket_fork = (&__actvbridgehdlr_nethandler_socket_fork)
	},
	[__hmnet_method_socket_socket] = {
		.p__actvbridgehdlr_nethandler_socket_socket = (&__actvbridgehdlr_nethandler_socket_socket)
	},
	[__hmnet_method_socket_socketpair] = {
		.p__actvbridgehdlr_nethandler_socket_socketpair = (&__actvbridgehdlr_nethandler_socket_socketpair)
	},
	[__hmnet_method_socket_close] = {
		.p__actvbridgehdlr_nethandler_socket_close = (&__actvbridgehdlr_nethandler_socket_close)
	},
	[__hmnet_method_socket_shutdown] = {
		.p__actvbridgehdlr_nethandler_socket_shutdown = (&__actvbridgehdlr_nethandler_socket_shutdown)
	},
	[__hmnet_method_socket_bind] = {
		.p__actvbridgehdlr_nethandler_socket_bind = (&__actvbridgehdlr_nethandler_socket_bind)
	},
	[__hmnet_method_socket_listen] = {
		.p__actvbridgehdlr_nethandler_socket_listen = (&__actvbridgehdlr_nethandler_socket_listen)
	},
	[__hmnet_method_socket_accept] = {
		.p__actvbridgehdlr_nethandler_socket_accept = (&__actvbridgehdlr_nethandler_socket_accept)
	},
	[__hmnet_method_socket_connect] = {
		.p__actvbridgehdlr_nethandler_socket_connect = (&__actvbridgehdlr_nethandler_socket_connect)
	},
	[__hmnet_method_socket_send] = {
		.p__actvbridgehdlr_nethandler_socket_send = (&__actvbridgehdlr_nethandler_socket_send)
	},
	[__hmnet_method_socket_sendmsg] = {
		.p__actvbridgehdlr_nethandler_socket_sendmsg = (&__actvbridgehdlr_nethandler_socket_sendmsg)
	},
	[__hmnet_method_socket_recvmsg] = {
		.p__actvbridgehdlr_nethandler_socket_recvmsg = (&__actvbridgehdlr_nethandler_socket_recvmsg)
	},
	[__hmnet_method_socket_sendto] = {
		.p__actvbridgehdlr_nethandler_socket_sendto = (&__actvbridgehdlr_nethandler_socket_sendto)
	},
	[__hmnet_method_socket_recvfrom] = {
		.p__actvbridgehdlr_nethandler_socket_recvfrom = (&__actvbridgehdlr_nethandler_socket_recvfrom)
	},
	[__hmnet_method_socket_getsockopt] = {
		.p__actvbridgehdlr_nethandler_socket_getsockopt = (&__actvbridgehdlr_nethandler_socket_getsockopt)
	},
	[__hmnet_method_socket_setsockopt] = {
		.p__actvbridgehdlr_nethandler_socket_setsockopt = (&__actvbridgehdlr_nethandler_socket_setsockopt)
	},
	[__hmnet_method_socket_getsockname] = {
		.p__actvbridgehdlr_nethandler_socket_getsockname = (&__actvbridgehdlr_nethandler_socket_getsockname)
	},
	[__hmnet_method_socket_getpeername] = {
		.p__actvbridgehdlr_nethandler_socket_getpeername = (&__actvbridgehdlr_nethandler_socket_getpeername)
	},
	[__hmnet_method_socket_fcntl] = {
		.p__actvbridgehdlr_nethandler_socket_fcntl = (&__actvbridgehdlr_nethandler_socket_fcntl)
	},
	[__hmnet_method_socket_ioctl] = {
		.p__actvbridgehdlr_nethandler_socket_ioctl = (&__actvbridgehdlr_nethandler_socket_ioctl)
	},
	[__hmnet_method_socket_dup] = {
		.p__actvbridgehdlr_nethandler_socket_dup = (&__actvbridgehdlr_nethandler_socket_dup)
	},
	[__hmnet_method_socket_send_fd] = {
		.p__actvbridgehdlr_nethandler_socket_send_fd = (&__actvbridgehdlr_nethandler_socket_send_fd)
	},
	[__hmnet_method_socket_recv_fd] = {
		.p__actvbridgehdlr_nethandler_socket_recv_fd = (&__actvbridgehdlr_nethandler_socket_recv_fd)
	},
	[__hmnet_method_socket_put_send_fd] = {
		.p__actvbridgehdlr_nethandler_socket_put_send_fd = (&__actvbridgehdlr_nethandler_socket_put_send_fd)
	},
	[__hmnet_method_epoll_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_epoll_ctl] = {
		.p__actvbridgehdlr_nethandler_epoll_ctl = (&__actvbridgehdlr_nethandler_epoll_ctl)
	},
	[__hmnet_method_epoll_et_revents] = {
		.p__actvbridgehdlr_nethandler_epoll_et_revents = (&__actvbridgehdlr_nethandler_epoll_et_revents)
	},
	[__hmnet_method_epoll_reinit] = {
		.p__actvbridgehdlr_nethandler_epoll_reinit = (&__actvbridgehdlr_nethandler_epoll_reinit)
	},
	[__hmnet_method_cfg_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_cfg_loglevel] = {
		.p__actvbridgehdlr_nethandler_cfg_loglevel = (&__actvbridgehdlr_nethandler_cfg_loglevel)
	},
	[__hmnet_method_cfg_show_stats] = {
		.p__actvbridgehdlr_nethandler_cfg_show_stats = (&__actvbridgehdlr_nethandler_cfg_show_stats)
	},
	[__hmnet_method_cfg_getifaddrs] = {
		.p__actvbridgehdlr_nethandler_cfg_getifaddrs = (&__actvbridgehdlr_nethandler_cfg_getifaddrs)
	},
	[__hmnet_method_netdev_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netdev_rx] = {
		.p__actvbridgehdlr_nethandler_netdev_rx = (&__actvbridgehdlr_nethandler_netdev_rx)
	},
	[__hmnet_method_netdev_notify] = {
		.p__actvbridgehdlr_nethandler_netdev_notify = (&__actvbridgehdlr_nethandler_netdev_notify)
	},
	[__hmnet_method_netdev_rx_ex_slowdata] = {
		.p__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata = (&__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata)
	},
	[__hmnet_method_procfs_read] = {
		.p__actvbridgehdlr_nethandler_procfs_read = (&__actvbridgehdlr_nethandler_procfs_read)
	},
	[__hmnet_method_procfs_write] = {
		.p__actvbridgehdlr_nethandler_procfs_write = (&__actvbridgehdlr_nethandler_procfs_write)
	},
	[__hmnet_method_procfs_fds_read] = {
		.p__actvbridgehdlr_nethandler_procfs_fds_read = (&__actvbridgehdlr_nethandler_procfs_fds_read)
	},
	[__hmnet_method_procfs_get_fd_path] = {
		.p__actvbridgehdlr_nethandler_procfs_get_fd_path = (&__actvbridgehdlr_nethandler_procfs_get_fd_path)
	},
	[__hmnet_method_netlink_rsvd_4] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_register_generic] = {
		.p__actvbridgehdlr_nethandler_netlink_register_generic = (&__actvbridgehdlr_nethandler_netlink_register_generic)
	},
	[__hmnet_method_netlink_unregister_generic] = {
		.p__actvbridgehdlr_nethandler_netlink_unregister_generic = (&__actvbridgehdlr_nethandler_netlink_unregister_generic)
	},
	[__hmnet_method_netlink_unicast] = {
		.p__actvbridgehdlr_nethandler_netlink_unicast = (&__actvbridgehdlr_nethandler_netlink_unicast)
	},
	[__hmnet_method_netlink_broadcast] = {
		.p__actvbridgehdlr_nethandler_netlink_broadcast = (&__actvbridgehdlr_nethandler_netlink_broadcast)
	},
	[__hmnet_method_vsock_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_vsock_register_vm] = {
		.p__actvbridgehdlr_nethandler_vsock_register_vm = (&__actvbridgehdlr_nethandler_vsock_register_vm)
	},
	[__hmnet_method_vsock_vm_notify] = {
		.p__actvbridgehdlr_nethandler_vsock_vm_notify = (&__actvbridgehdlr_nethandler_vsock_vm_notify)
	},
	[__hmnet_method_vsock_unregister_vm] = {
		.p__actvbridgehdlr_nethandler_vsock_unregister_vm = (&__actvbridgehdlr_nethandler_vsock_unregister_vm)
	}
};

union hmnet_hdlrs_union sysif_hmnet_actvcapcallhdlr_table[__hmnet_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE + 1U ... __hmnet_method_MIN] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__hmnet_method_socket_rsvd_7] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_6] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_5] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_4] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_revoke] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_revoke = (&__actvbridgecapcallhdlr_nethandler_socket_revoke)
	},
	[__hmnet_method_socket_fork] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_fork = (&__actvbridgecapcallhdlr_nethandler_socket_fork)
	},
	[__hmnet_method_socket_socket] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_socket = (&__actvbridgecapcallhdlr_nethandler_socket_socket)
	},
	[__hmnet_method_socket_socketpair] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_socketpair = (&__actvbridgecapcallhdlr_nethandler_socket_socketpair)
	},
	[__hmnet_method_socket_close] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_close = (&__actvbridgecapcallhdlr_nethandler_socket_close)
	},
	[__hmnet_method_socket_shutdown] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_shutdown = (&__actvbridgecapcallhdlr_nethandler_socket_shutdown)
	},
	[__hmnet_method_socket_bind] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_bind = (&__actvbridgecapcallhdlr_nethandler_socket_bind)
	},
	[__hmnet_method_socket_listen] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_listen = (&__actvbridgecapcallhdlr_nethandler_socket_listen)
	},
	[__hmnet_method_socket_accept] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_accept = (&__actvbridgecapcallhdlr_nethandler_socket_accept)
	},
	[__hmnet_method_socket_connect] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_connect = (&__actvbridgecapcallhdlr_nethandler_socket_connect)
	},
	[__hmnet_method_socket_send] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_send = (&__actvbridgecapcallhdlr_nethandler_socket_send)
	},
	[__hmnet_method_socket_sendmsg] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_sendmsg = (&__actvbridgecapcallhdlr_nethandler_socket_sendmsg)
	},
	[__hmnet_method_socket_recvmsg] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_recvmsg = (&__actvbridgecapcallhdlr_nethandler_socket_recvmsg)
	},
	[__hmnet_method_socket_sendto] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_sendto = (&__actvbridgecapcallhdlr_nethandler_socket_sendto)
	},
	[__hmnet_method_socket_recvfrom] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_recvfrom = (&__actvbridgecapcallhdlr_nethandler_socket_recvfrom)
	},
	[__hmnet_method_socket_getsockopt] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_getsockopt = (&__actvbridgecapcallhdlr_nethandler_socket_getsockopt)
	},
	[__hmnet_method_socket_setsockopt] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_setsockopt = (&__actvbridgecapcallhdlr_nethandler_socket_setsockopt)
	},
	[__hmnet_method_socket_getsockname] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_getsockname = (&__actvbridgecapcallhdlr_nethandler_socket_getsockname)
	},
	[__hmnet_method_socket_getpeername] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_getpeername = (&__actvbridgecapcallhdlr_nethandler_socket_getpeername)
	},
	[__hmnet_method_socket_fcntl] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_fcntl = (&__actvbridgecapcallhdlr_nethandler_socket_fcntl)
	},
	[__hmnet_method_socket_ioctl] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_ioctl = (&__actvbridgecapcallhdlr_nethandler_socket_ioctl)
	},
	[__hmnet_method_socket_dup] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_dup = (&__actvbridgecapcallhdlr_nethandler_socket_dup)
	},
	[__hmnet_method_socket_send_fd] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_send_fd = (&__actvbridgecapcallhdlr_nethandler_socket_send_fd)
	},
	[__hmnet_method_socket_recv_fd] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_recv_fd = (&__actvbridgecapcallhdlr_nethandler_socket_recv_fd)
	},
	[__hmnet_method_socket_put_send_fd] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_put_send_fd = (&__actvbridgecapcallhdlr_nethandler_socket_put_send_fd)
	},
	[__hmnet_method_epoll_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_epoll_ctl] = {
		.p__actvbridgecapcallhdlr_nethandler_epoll_ctl = (&__actvbridgecapcallhdlr_nethandler_epoll_ctl)
	},
	[__hmnet_method_epoll_et_revents] = {
		.p__actvbridgecapcallhdlr_nethandler_epoll_et_revents = (&__actvbridgecapcallhdlr_nethandler_epoll_et_revents)
	},
	[__hmnet_method_epoll_reinit] = {
		.p__actvbridgecapcallhdlr_nethandler_epoll_reinit = (&__actvbridgecapcallhdlr_nethandler_epoll_reinit)
	},
	[__hmnet_method_cfg_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_cfg_loglevel] = {
		.p__actvbridgecapcallhdlr_nethandler_cfg_loglevel = (&__actvbridgecapcallhdlr_nethandler_cfg_loglevel)
	},
	[__hmnet_method_cfg_show_stats] = {
		.p__actvbridgecapcallhdlr_nethandler_cfg_show_stats = (&__actvbridgecapcallhdlr_nethandler_cfg_show_stats)
	},
	[__hmnet_method_cfg_getifaddrs] = {
		.p__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs = (&__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs)
	},
	[__hmnet_method_netdev_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netdev_rx] = {
		.p__actvbridgecapcallhdlr_nethandler_netdev_rx = (&__actvbridgecapcallhdlr_nethandler_netdev_rx)
	},
	[__hmnet_method_netdev_notify] = {
		.p__actvbridgecapcallhdlr_nethandler_netdev_notify = (&__actvbridgecapcallhdlr_nethandler_netdev_notify)
	},
	[__hmnet_method_netdev_rx_ex_slowdata] = {
		.p__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata = (&__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata)
	},
	[__hmnet_method_procfs_read] = {
		.p__actvbridgecapcallhdlr_nethandler_procfs_read = (&__actvbridgecapcallhdlr_nethandler_procfs_read)
	},
	[__hmnet_method_procfs_write] = {
		.p__actvbridgecapcallhdlr_nethandler_procfs_write = (&__actvbridgecapcallhdlr_nethandler_procfs_write)
	},
	[__hmnet_method_procfs_fds_read] = {
		.p__actvbridgecapcallhdlr_nethandler_procfs_fds_read = (&__actvbridgecapcallhdlr_nethandler_procfs_fds_read)
	},
	[__hmnet_method_procfs_get_fd_path] = {
		.p__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path = (&__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path)
	},
	[__hmnet_method_netlink_rsvd_4] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_3] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_register_generic] = {
		.p__actvbridgecapcallhdlr_nethandler_netlink_register_generic = (&__actvbridgecapcallhdlr_nethandler_netlink_register_generic)
	},
	[__hmnet_method_netlink_unregister_generic] = {
		.p__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic = (&__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic)
	},
	[__hmnet_method_netlink_unicast] = {
		.p__actvbridgecapcallhdlr_nethandler_netlink_unicast = (&__actvbridgecapcallhdlr_nethandler_netlink_unicast)
	},
	[__hmnet_method_netlink_broadcast] = {
		.p__actvbridgecapcallhdlr_nethandler_netlink_broadcast = (&__actvbridgecapcallhdlr_nethandler_netlink_broadcast)
	},
	[__hmnet_method_vsock_rsvd_1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_vsock_register_vm] = {
		.p__actvbridgecapcallhdlr_nethandler_vsock_register_vm = (&__actvbridgecapcallhdlr_nethandler_vsock_register_vm)
	},
	[__hmnet_method_vsock_vm_notify] = {
		.p__actvbridgecapcallhdlr_nethandler_vsock_vm_notify = (&__actvbridgecapcallhdlr_nethandler_vsock_vm_notify)
	},
	[__hmnet_method_vsock_unregister_vm] = {
		.p__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm = (&__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm)
	}
};

#else
#ifndef __ARCH_RPC_REQUIRE_BRIDGE_HDLR
#error "Only support 64-bit server, build for aarch64 please!"
#else
union hmnet_hdlrs_union sysif_hmnet_actvhdlr_table[__hmnet_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __hmnet_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__hmnet_method_socket_rsvd_7 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_6 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_5 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_4 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_7 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_6 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_5 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_4 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_revoke * 2] = {
		.p__actvbridgehdlr_nethandler_socket_revoke = (&__actvbridgehdlr_nethandler_socket_revoke)
	},
	[__hmnet_method_socket_revoke * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_revoke = (&__actvbridgehdlr_nethandler_compat_socket_revoke)
	},
	[__hmnet_method_socket_fork * 2] = {
		.p__actvbridgehdlr_nethandler_socket_fork = (&__actvbridgehdlr_nethandler_socket_fork)
	},
	[__hmnet_method_socket_fork * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_fork = (&__actvbridgehdlr_nethandler_compat_socket_fork)
	},
	[__hmnet_method_socket_socket * 2] = {
		.p__actvbridgehdlr_nethandler_socket_socket = (&__actvbridgehdlr_nethandler_socket_socket)
	},
	[__hmnet_method_socket_socket * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_socket = (&__actvbridgehdlr_nethandler_compat_socket_socket)
	},
	[__hmnet_method_socket_socketpair * 2] = {
		.p__actvbridgehdlr_nethandler_socket_socketpair = (&__actvbridgehdlr_nethandler_socket_socketpair)
	},
	[__hmnet_method_socket_socketpair * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_socketpair = (&__actvbridgehdlr_nethandler_compat_socket_socketpair)
	},
	[__hmnet_method_socket_close * 2] = {
		.p__actvbridgehdlr_nethandler_socket_close = (&__actvbridgehdlr_nethandler_socket_close)
	},
	[__hmnet_method_socket_close * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_close = (&__actvbridgehdlr_nethandler_compat_socket_close)
	},
	[__hmnet_method_socket_shutdown * 2] = {
		.p__actvbridgehdlr_nethandler_socket_shutdown = (&__actvbridgehdlr_nethandler_socket_shutdown)
	},
	[__hmnet_method_socket_shutdown * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_shutdown = (&__actvbridgehdlr_nethandler_compat_socket_shutdown)
	},
	[__hmnet_method_socket_bind * 2] = {
		.p__actvbridgehdlr_nethandler_socket_bind = (&__actvbridgehdlr_nethandler_socket_bind)
	},
	[__hmnet_method_socket_bind * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_bind = (&__actvbridgehdlr_nethandler_compat_socket_bind)
	},
	[__hmnet_method_socket_listen * 2] = {
		.p__actvbridgehdlr_nethandler_socket_listen = (&__actvbridgehdlr_nethandler_socket_listen)
	},
	[__hmnet_method_socket_listen * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_listen = (&__actvbridgehdlr_nethandler_compat_socket_listen)
	},
	[__hmnet_method_socket_accept * 2] = {
		.p__actvbridgehdlr_nethandler_socket_accept = (&__actvbridgehdlr_nethandler_socket_accept)
	},
	[__hmnet_method_socket_accept * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_accept = (&__actvbridgehdlr_nethandler_compat_socket_accept)
	},
	[__hmnet_method_socket_connect * 2] = {
		.p__actvbridgehdlr_nethandler_socket_connect = (&__actvbridgehdlr_nethandler_socket_connect)
	},
	[__hmnet_method_socket_connect * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_connect = (&__actvbridgehdlr_nethandler_compat_socket_connect)
	},
	[__hmnet_method_socket_send * 2] = {
		.p__actvbridgehdlr_nethandler_socket_send = (&__actvbridgehdlr_nethandler_socket_send)
	},
	[__hmnet_method_socket_send * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_send = (&__actvbridgehdlr_nethandler_compat_socket_send)
	},
	[__hmnet_method_socket_sendmsg * 2] = {
		.p__actvbridgehdlr_nethandler_socket_sendmsg = (&__actvbridgehdlr_nethandler_socket_sendmsg)
	},
	[__hmnet_method_socket_sendmsg * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_sendmsg = (&__actvbridgehdlr_nethandler_compat_socket_sendmsg)
	},
	[__hmnet_method_socket_recvmsg * 2] = {
		.p__actvbridgehdlr_nethandler_socket_recvmsg = (&__actvbridgehdlr_nethandler_socket_recvmsg)
	},
	[__hmnet_method_socket_recvmsg * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_recvmsg = (&__actvbridgehdlr_nethandler_compat_socket_recvmsg)
	},
	[__hmnet_method_socket_sendto * 2] = {
		.p__actvbridgehdlr_nethandler_socket_sendto = (&__actvbridgehdlr_nethandler_socket_sendto)
	},
	[__hmnet_method_socket_sendto * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_sendto = (&__actvbridgehdlr_nethandler_compat_socket_sendto)
	},
	[__hmnet_method_socket_recvfrom * 2] = {
		.p__actvbridgehdlr_nethandler_socket_recvfrom = (&__actvbridgehdlr_nethandler_socket_recvfrom)
	},
	[__hmnet_method_socket_recvfrom * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_recvfrom = (&__actvbridgehdlr_nethandler_compat_socket_recvfrom)
	},
	[__hmnet_method_socket_getsockopt * 2] = {
		.p__actvbridgehdlr_nethandler_socket_getsockopt = (&__actvbridgehdlr_nethandler_socket_getsockopt)
	},
	[__hmnet_method_socket_getsockopt * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_getsockopt = (&__actvbridgehdlr_nethandler_compat_socket_getsockopt)
	},
	[__hmnet_method_socket_setsockopt * 2] = {
		.p__actvbridgehdlr_nethandler_socket_setsockopt = (&__actvbridgehdlr_nethandler_socket_setsockopt)
	},
	[__hmnet_method_socket_setsockopt * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_setsockopt = (&__actvbridgehdlr_nethandler_compat_socket_setsockopt)
	},
	[__hmnet_method_socket_getsockname * 2] = {
		.p__actvbridgehdlr_nethandler_socket_getsockname = (&__actvbridgehdlr_nethandler_socket_getsockname)
	},
	[__hmnet_method_socket_getsockname * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_getsockname = (&__actvbridgehdlr_nethandler_compat_socket_getsockname)
	},
	[__hmnet_method_socket_getpeername * 2] = {
		.p__actvbridgehdlr_nethandler_socket_getpeername = (&__actvbridgehdlr_nethandler_socket_getpeername)
	},
	[__hmnet_method_socket_getpeername * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_getpeername = (&__actvbridgehdlr_nethandler_compat_socket_getpeername)
	},
	[__hmnet_method_socket_fcntl * 2] = {
		.p__actvbridgehdlr_nethandler_socket_fcntl = (&__actvbridgehdlr_nethandler_socket_fcntl)
	},
	[__hmnet_method_socket_fcntl * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_fcntl = (&__actvbridgehdlr_nethandler_compat_socket_fcntl)
	},
	[__hmnet_method_socket_ioctl * 2] = {
		.p__actvbridgehdlr_nethandler_socket_ioctl = (&__actvbridgehdlr_nethandler_socket_ioctl)
	},
	[__hmnet_method_socket_ioctl * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_ioctl = (&__actvbridgehdlr_nethandler_compat_socket_ioctl)
	},
	[__hmnet_method_socket_dup * 2] = {
		.p__actvbridgehdlr_nethandler_socket_dup = (&__actvbridgehdlr_nethandler_socket_dup)
	},
	[__hmnet_method_socket_dup * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_dup = (&__actvbridgehdlr_nethandler_compat_socket_dup)
	},
	[__hmnet_method_socket_send_fd * 2] = {
		.p__actvbridgehdlr_nethandler_socket_send_fd = (&__actvbridgehdlr_nethandler_socket_send_fd)
	},
	[__hmnet_method_socket_send_fd * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_send_fd = (&__actvbridgehdlr_nethandler_compat_socket_send_fd)
	},
	[__hmnet_method_socket_recv_fd * 2] = {
		.p__actvbridgehdlr_nethandler_socket_recv_fd = (&__actvbridgehdlr_nethandler_socket_recv_fd)
	},
	[__hmnet_method_socket_recv_fd * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_recv_fd = (&__actvbridgehdlr_nethandler_compat_socket_recv_fd)
	},
	[__hmnet_method_socket_put_send_fd * 2] = {
		.p__actvbridgehdlr_nethandler_socket_put_send_fd = (&__actvbridgehdlr_nethandler_socket_put_send_fd)
	},
	[__hmnet_method_socket_put_send_fd * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_socket_put_send_fd = (&__actvbridgehdlr_nethandler_compat_socket_put_send_fd)
	},
	[__hmnet_method_epoll_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_epoll_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_epoll_ctl * 2] = {
		.p__actvbridgehdlr_nethandler_epoll_ctl = (&__actvbridgehdlr_nethandler_epoll_ctl)
	},
	[__hmnet_method_epoll_ctl * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_epoll_ctl = (&__actvbridgehdlr_nethandler_compat_epoll_ctl)
	},
	[__hmnet_method_epoll_et_revents * 2] = {
		.p__actvbridgehdlr_nethandler_epoll_et_revents = (&__actvbridgehdlr_nethandler_epoll_et_revents)
	},
	[__hmnet_method_epoll_et_revents * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_epoll_et_revents = (&__actvbridgehdlr_nethandler_compat_epoll_et_revents)
	},
	[__hmnet_method_epoll_reinit * 2] = {
		.p__actvbridgehdlr_nethandler_epoll_reinit = (&__actvbridgehdlr_nethandler_epoll_reinit)
	},
	[__hmnet_method_epoll_reinit * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_epoll_reinit = (&__actvbridgehdlr_nethandler_compat_epoll_reinit)
	},
	[__hmnet_method_cfg_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_cfg_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_cfg_loglevel * 2] = {
		.p__actvbridgehdlr_nethandler_cfg_loglevel = (&__actvbridgehdlr_nethandler_cfg_loglevel)
	},
	[__hmnet_method_cfg_loglevel * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_cfg_loglevel = (&__actvbridgehdlr_nethandler_compat_cfg_loglevel)
	},
	[__hmnet_method_cfg_show_stats * 2] = {
		.p__actvbridgehdlr_nethandler_cfg_show_stats = (&__actvbridgehdlr_nethandler_cfg_show_stats)
	},
	[__hmnet_method_cfg_show_stats * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_cfg_show_stats = (&__actvbridgehdlr_nethandler_compat_cfg_show_stats)
	},
	[__hmnet_method_cfg_getifaddrs * 2] = {
		.p__actvbridgehdlr_nethandler_cfg_getifaddrs = (&__actvbridgehdlr_nethandler_cfg_getifaddrs)
	},
	[__hmnet_method_cfg_getifaddrs * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_cfg_getifaddrs = (&__actvbridgehdlr_nethandler_compat_cfg_getifaddrs)
	},
	[__hmnet_method_netdev_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netdev_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netdev_rx * 2] = {
		.p__actvbridgehdlr_nethandler_netdev_rx = (&__actvbridgehdlr_nethandler_netdev_rx)
	},
	[__hmnet_method_netdev_rx * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_netdev_rx = (&__actvbridgehdlr_nethandler_compat_netdev_rx)
	},
	[__hmnet_method_netdev_notify * 2] = {
		.p__actvbridgehdlr_nethandler_netdev_notify = (&__actvbridgehdlr_nethandler_netdev_notify)
	},
	[__hmnet_method_netdev_notify * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_netdev_notify = (&__actvbridgehdlr_nethandler_compat_netdev_notify)
	},
	[__hmnet_method_netdev_rx_ex_slowdata * 2] = {
		.p__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata = (&__actvbridgehdlr_nethandler_netdev_rx_ex_slowdata)
	},
	[__hmnet_method_netdev_rx_ex_slowdata * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_netdev_rx_ex_slowdata = (&__actvbridgehdlr_nethandler_compat_netdev_rx_ex_slowdata)
	},
	[__hmnet_method_procfs_read * 2] = {
		.p__actvbridgehdlr_nethandler_procfs_read = (&__actvbridgehdlr_nethandler_procfs_read)
	},
	[__hmnet_method_procfs_read * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_procfs_read = (&__actvbridgehdlr_nethandler_compat_procfs_read)
	},
	[__hmnet_method_procfs_write * 2] = {
		.p__actvbridgehdlr_nethandler_procfs_write = (&__actvbridgehdlr_nethandler_procfs_write)
	},
	[__hmnet_method_procfs_write * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_procfs_write = (&__actvbridgehdlr_nethandler_compat_procfs_write)
	},
	[__hmnet_method_procfs_fds_read * 2] = {
		.p__actvbridgehdlr_nethandler_procfs_fds_read = (&__actvbridgehdlr_nethandler_procfs_fds_read)
	},
	[__hmnet_method_procfs_fds_read * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_procfs_fds_read = (&__actvbridgehdlr_nethandler_compat_procfs_fds_read)
	},
	[__hmnet_method_procfs_get_fd_path * 2] = {
		.p__actvbridgehdlr_nethandler_procfs_get_fd_path = (&__actvbridgehdlr_nethandler_procfs_get_fd_path)
	},
	[__hmnet_method_procfs_get_fd_path * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_procfs_get_fd_path = (&__actvbridgehdlr_nethandler_compat_procfs_get_fd_path)
	},
	[__hmnet_method_netlink_rsvd_4 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_4 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_register_generic * 2] = {
		.p__actvbridgehdlr_nethandler_netlink_register_generic = (&__actvbridgehdlr_nethandler_netlink_register_generic)
	},
	[__hmnet_method_netlink_register_generic * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_netlink_register_generic = (&__actvbridgehdlr_nethandler_compat_netlink_register_generic)
	},
	[__hmnet_method_netlink_unregister_generic * 2] = {
		.p__actvbridgehdlr_nethandler_netlink_unregister_generic = (&__actvbridgehdlr_nethandler_netlink_unregister_generic)
	},
	[__hmnet_method_netlink_unregister_generic * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_netlink_unregister_generic = (&__actvbridgehdlr_nethandler_compat_netlink_unregister_generic)
	},
	[__hmnet_method_netlink_unicast * 2] = {
		.p__actvbridgehdlr_nethandler_netlink_unicast = (&__actvbridgehdlr_nethandler_netlink_unicast)
	},
	[__hmnet_method_netlink_unicast * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_netlink_unicast = (&__actvbridgehdlr_nethandler_compat_netlink_unicast)
	},
	[__hmnet_method_netlink_broadcast * 2] = {
		.p__actvbridgehdlr_nethandler_netlink_broadcast = (&__actvbridgehdlr_nethandler_netlink_broadcast)
	},
	[__hmnet_method_netlink_broadcast * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_netlink_broadcast = (&__actvbridgehdlr_nethandler_compat_netlink_broadcast)
	},
	[__hmnet_method_vsock_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_vsock_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_vsock_register_vm * 2] = {
		.p__actvbridgehdlr_nethandler_vsock_register_vm = (&__actvbridgehdlr_nethandler_vsock_register_vm)
	},
	[__hmnet_method_vsock_register_vm * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_vsock_register_vm = (&__actvbridgehdlr_nethandler_compat_vsock_register_vm)
	},
	[__hmnet_method_vsock_vm_notify * 2] = {
		.p__actvbridgehdlr_nethandler_vsock_vm_notify = (&__actvbridgehdlr_nethandler_vsock_vm_notify)
	},
	[__hmnet_method_vsock_vm_notify * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_vsock_vm_notify = (&__actvbridgehdlr_nethandler_compat_vsock_vm_notify)
	},
	[__hmnet_method_vsock_unregister_vm * 2] = {
		.p__actvbridgehdlr_nethandler_vsock_unregister_vm = (&__actvbridgehdlr_nethandler_vsock_unregister_vm)
	},
	[__hmnet_method_vsock_unregister_vm * 2 + 1] = {
		.p__actvbridgehdlr_nethandler_compat_vsock_unregister_vm = (&__actvbridgehdlr_nethandler_compat_vsock_unregister_vm)
	}
};

#endif
union hmnet_hdlrs_union sysif_hmnet_actvcapcallhdlr_table[__hmnet_method_MAX] = {
	[0 ... __ACTV_UPCALL_POOL_GRANT_CHANGE * 2U - 1U] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 1U] = {
		.p_sysif_handle_kcall_entry = (&sysif_actv_pool_handle_grant_change)
	},
	[__ACTV_UPCALL_POOL_GRANT_CHANGE * 2U + 2U ... __hmnet_method_MIN * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_default_handler)
	},
	[__hmnet_method_socket_rsvd_7 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_6 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_5 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_4 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_7 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_6 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_5 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_4 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_socket_revoke * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_revoke = (&__actvbridgecapcallhdlr_nethandler_socket_revoke)
	},
	[__hmnet_method_socket_revoke * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_revoke = (&__actvbridgecapcallhdlr_nethandler_compat_socket_revoke)
	},
	[__hmnet_method_socket_fork * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_fork = (&__actvbridgecapcallhdlr_nethandler_socket_fork)
	},
	[__hmnet_method_socket_fork * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_fork = (&__actvbridgecapcallhdlr_nethandler_compat_socket_fork)
	},
	[__hmnet_method_socket_socket * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_socket = (&__actvbridgecapcallhdlr_nethandler_socket_socket)
	},
	[__hmnet_method_socket_socket * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_socket = (&__actvbridgecapcallhdlr_nethandler_compat_socket_socket)
	},
	[__hmnet_method_socket_socketpair * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_socketpair = (&__actvbridgecapcallhdlr_nethandler_socket_socketpair)
	},
	[__hmnet_method_socket_socketpair * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_socketpair = (&__actvbridgecapcallhdlr_nethandler_compat_socket_socketpair)
	},
	[__hmnet_method_socket_close * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_close = (&__actvbridgecapcallhdlr_nethandler_socket_close)
	},
	[__hmnet_method_socket_close * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_close = (&__actvbridgecapcallhdlr_nethandler_compat_socket_close)
	},
	[__hmnet_method_socket_shutdown * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_shutdown = (&__actvbridgecapcallhdlr_nethandler_socket_shutdown)
	},
	[__hmnet_method_socket_shutdown * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_shutdown = (&__actvbridgecapcallhdlr_nethandler_compat_socket_shutdown)
	},
	[__hmnet_method_socket_bind * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_bind = (&__actvbridgecapcallhdlr_nethandler_socket_bind)
	},
	[__hmnet_method_socket_bind * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_bind = (&__actvbridgecapcallhdlr_nethandler_compat_socket_bind)
	},
	[__hmnet_method_socket_listen * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_listen = (&__actvbridgecapcallhdlr_nethandler_socket_listen)
	},
	[__hmnet_method_socket_listen * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_listen = (&__actvbridgecapcallhdlr_nethandler_compat_socket_listen)
	},
	[__hmnet_method_socket_accept * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_accept = (&__actvbridgecapcallhdlr_nethandler_socket_accept)
	},
	[__hmnet_method_socket_accept * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_accept = (&__actvbridgecapcallhdlr_nethandler_compat_socket_accept)
	},
	[__hmnet_method_socket_connect * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_connect = (&__actvbridgecapcallhdlr_nethandler_socket_connect)
	},
	[__hmnet_method_socket_connect * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_connect = (&__actvbridgecapcallhdlr_nethandler_compat_socket_connect)
	},
	[__hmnet_method_socket_send * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_send = (&__actvbridgecapcallhdlr_nethandler_socket_send)
	},
	[__hmnet_method_socket_send * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_send = (&__actvbridgecapcallhdlr_nethandler_compat_socket_send)
	},
	[__hmnet_method_socket_sendmsg * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_sendmsg = (&__actvbridgecapcallhdlr_nethandler_socket_sendmsg)
	},
	[__hmnet_method_socket_sendmsg * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_sendmsg = (&__actvbridgecapcallhdlr_nethandler_compat_socket_sendmsg)
	},
	[__hmnet_method_socket_recvmsg * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_recvmsg = (&__actvbridgecapcallhdlr_nethandler_socket_recvmsg)
	},
	[__hmnet_method_socket_recvmsg * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_recvmsg = (&__actvbridgecapcallhdlr_nethandler_compat_socket_recvmsg)
	},
	[__hmnet_method_socket_sendto * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_sendto = (&__actvbridgecapcallhdlr_nethandler_socket_sendto)
	},
	[__hmnet_method_socket_sendto * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_sendto = (&__actvbridgecapcallhdlr_nethandler_compat_socket_sendto)
	},
	[__hmnet_method_socket_recvfrom * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_recvfrom = (&__actvbridgecapcallhdlr_nethandler_socket_recvfrom)
	},
	[__hmnet_method_socket_recvfrom * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_recvfrom = (&__actvbridgecapcallhdlr_nethandler_compat_socket_recvfrom)
	},
	[__hmnet_method_socket_getsockopt * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_getsockopt = (&__actvbridgecapcallhdlr_nethandler_socket_getsockopt)
	},
	[__hmnet_method_socket_getsockopt * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_getsockopt = (&__actvbridgecapcallhdlr_nethandler_compat_socket_getsockopt)
	},
	[__hmnet_method_socket_setsockopt * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_setsockopt = (&__actvbridgecapcallhdlr_nethandler_socket_setsockopt)
	},
	[__hmnet_method_socket_setsockopt * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_setsockopt = (&__actvbridgecapcallhdlr_nethandler_compat_socket_setsockopt)
	},
	[__hmnet_method_socket_getsockname * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_getsockname = (&__actvbridgecapcallhdlr_nethandler_socket_getsockname)
	},
	[__hmnet_method_socket_getsockname * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_getsockname = (&__actvbridgecapcallhdlr_nethandler_compat_socket_getsockname)
	},
	[__hmnet_method_socket_getpeername * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_getpeername = (&__actvbridgecapcallhdlr_nethandler_socket_getpeername)
	},
	[__hmnet_method_socket_getpeername * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_getpeername = (&__actvbridgecapcallhdlr_nethandler_compat_socket_getpeername)
	},
	[__hmnet_method_socket_fcntl * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_fcntl = (&__actvbridgecapcallhdlr_nethandler_socket_fcntl)
	},
	[__hmnet_method_socket_fcntl * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_fcntl = (&__actvbridgecapcallhdlr_nethandler_compat_socket_fcntl)
	},
	[__hmnet_method_socket_ioctl * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_ioctl = (&__actvbridgecapcallhdlr_nethandler_socket_ioctl)
	},
	[__hmnet_method_socket_ioctl * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_ioctl = (&__actvbridgecapcallhdlr_nethandler_compat_socket_ioctl)
	},
	[__hmnet_method_socket_dup * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_dup = (&__actvbridgecapcallhdlr_nethandler_socket_dup)
	},
	[__hmnet_method_socket_dup * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_dup = (&__actvbridgecapcallhdlr_nethandler_compat_socket_dup)
	},
	[__hmnet_method_socket_send_fd * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_send_fd = (&__actvbridgecapcallhdlr_nethandler_socket_send_fd)
	},
	[__hmnet_method_socket_send_fd * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_send_fd = (&__actvbridgecapcallhdlr_nethandler_compat_socket_send_fd)
	},
	[__hmnet_method_socket_recv_fd * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_recv_fd = (&__actvbridgecapcallhdlr_nethandler_socket_recv_fd)
	},
	[__hmnet_method_socket_recv_fd * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_recv_fd = (&__actvbridgecapcallhdlr_nethandler_compat_socket_recv_fd)
	},
	[__hmnet_method_socket_put_send_fd * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_socket_put_send_fd = (&__actvbridgecapcallhdlr_nethandler_socket_put_send_fd)
	},
	[__hmnet_method_socket_put_send_fd * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_socket_put_send_fd = (&__actvbridgecapcallhdlr_nethandler_compat_socket_put_send_fd)
	},
	[__hmnet_method_epoll_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_epoll_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_epoll_ctl * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_epoll_ctl = (&__actvbridgecapcallhdlr_nethandler_epoll_ctl)
	},
	[__hmnet_method_epoll_ctl * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_epoll_ctl = (&__actvbridgecapcallhdlr_nethandler_compat_epoll_ctl)
	},
	[__hmnet_method_epoll_et_revents * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_epoll_et_revents = (&__actvbridgecapcallhdlr_nethandler_epoll_et_revents)
	},
	[__hmnet_method_epoll_et_revents * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_epoll_et_revents = (&__actvbridgecapcallhdlr_nethandler_compat_epoll_et_revents)
	},
	[__hmnet_method_epoll_reinit * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_epoll_reinit = (&__actvbridgecapcallhdlr_nethandler_epoll_reinit)
	},
	[__hmnet_method_epoll_reinit * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_epoll_reinit = (&__actvbridgecapcallhdlr_nethandler_compat_epoll_reinit)
	},
	[__hmnet_method_cfg_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_cfg_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_cfg_loglevel * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_cfg_loglevel = (&__actvbridgecapcallhdlr_nethandler_cfg_loglevel)
	},
	[__hmnet_method_cfg_loglevel * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_cfg_loglevel = (&__actvbridgecapcallhdlr_nethandler_compat_cfg_loglevel)
	},
	[__hmnet_method_cfg_show_stats * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_cfg_show_stats = (&__actvbridgecapcallhdlr_nethandler_cfg_show_stats)
	},
	[__hmnet_method_cfg_show_stats * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_cfg_show_stats = (&__actvbridgecapcallhdlr_nethandler_compat_cfg_show_stats)
	},
	[__hmnet_method_cfg_getifaddrs * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs = (&__actvbridgecapcallhdlr_nethandler_cfg_getifaddrs)
	},
	[__hmnet_method_cfg_getifaddrs * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_cfg_getifaddrs = (&__actvbridgecapcallhdlr_nethandler_compat_cfg_getifaddrs)
	},
	[__hmnet_method_netdev_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netdev_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netdev_rx * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_netdev_rx = (&__actvbridgecapcallhdlr_nethandler_netdev_rx)
	},
	[__hmnet_method_netdev_rx * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_netdev_rx = (&__actvbridgecapcallhdlr_nethandler_compat_netdev_rx)
	},
	[__hmnet_method_netdev_notify * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_netdev_notify = (&__actvbridgecapcallhdlr_nethandler_netdev_notify)
	},
	[__hmnet_method_netdev_notify * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_netdev_notify = (&__actvbridgecapcallhdlr_nethandler_compat_netdev_notify)
	},
	[__hmnet_method_netdev_rx_ex_slowdata * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata = (&__actvbridgecapcallhdlr_nethandler_netdev_rx_ex_slowdata)
	},
	[__hmnet_method_netdev_rx_ex_slowdata * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_netdev_rx_ex_slowdata = (&__actvbridgecapcallhdlr_nethandler_compat_netdev_rx_ex_slowdata)
	},
	[__hmnet_method_procfs_read * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_procfs_read = (&__actvbridgecapcallhdlr_nethandler_procfs_read)
	},
	[__hmnet_method_procfs_read * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_procfs_read = (&__actvbridgecapcallhdlr_nethandler_compat_procfs_read)
	},
	[__hmnet_method_procfs_write * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_procfs_write = (&__actvbridgecapcallhdlr_nethandler_procfs_write)
	},
	[__hmnet_method_procfs_write * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_procfs_write = (&__actvbridgecapcallhdlr_nethandler_compat_procfs_write)
	},
	[__hmnet_method_procfs_fds_read * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_procfs_fds_read = (&__actvbridgecapcallhdlr_nethandler_procfs_fds_read)
	},
	[__hmnet_method_procfs_fds_read * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_procfs_fds_read = (&__actvbridgecapcallhdlr_nethandler_compat_procfs_fds_read)
	},
	[__hmnet_method_procfs_get_fd_path * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path = (&__actvbridgecapcallhdlr_nethandler_procfs_get_fd_path)
	},
	[__hmnet_method_procfs_get_fd_path * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_procfs_get_fd_path = (&__actvbridgecapcallhdlr_nethandler_compat_procfs_get_fd_path)
	},
	[__hmnet_method_netlink_rsvd_4 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_3 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_2 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_4 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_3 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_2 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_netlink_register_generic * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_netlink_register_generic = (&__actvbridgecapcallhdlr_nethandler_netlink_register_generic)
	},
	[__hmnet_method_netlink_register_generic * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_netlink_register_generic = (&__actvbridgecapcallhdlr_nethandler_compat_netlink_register_generic)
	},
	[__hmnet_method_netlink_unregister_generic * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic = (&__actvbridgecapcallhdlr_nethandler_netlink_unregister_generic)
	},
	[__hmnet_method_netlink_unregister_generic * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_netlink_unregister_generic = (&__actvbridgecapcallhdlr_nethandler_compat_netlink_unregister_generic)
	},
	[__hmnet_method_netlink_unicast * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_netlink_unicast = (&__actvbridgecapcallhdlr_nethandler_netlink_unicast)
	},
	[__hmnet_method_netlink_unicast * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_netlink_unicast = (&__actvbridgecapcallhdlr_nethandler_compat_netlink_unicast)
	},
	[__hmnet_method_netlink_broadcast * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_netlink_broadcast = (&__actvbridgecapcallhdlr_nethandler_netlink_broadcast)
	},
	[__hmnet_method_netlink_broadcast * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_netlink_broadcast = (&__actvbridgecapcallhdlr_nethandler_compat_netlink_broadcast)
	},
	[__hmnet_method_vsock_rsvd_1 * 2] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_vsock_rsvd_1 * 2 + 1] = {
		.p_sysif_default_handler = (&sysif_actvhdlr_reserved_default_handler)
	},
	[__hmnet_method_vsock_register_vm * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_vsock_register_vm = (&__actvbridgecapcallhdlr_nethandler_vsock_register_vm)
	},
	[__hmnet_method_vsock_register_vm * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_vsock_register_vm = (&__actvbridgecapcallhdlr_nethandler_compat_vsock_register_vm)
	},
	[__hmnet_method_vsock_vm_notify * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_vsock_vm_notify = (&__actvbridgecapcallhdlr_nethandler_vsock_vm_notify)
	},
	[__hmnet_method_vsock_vm_notify * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_vsock_vm_notify = (&__actvbridgecapcallhdlr_nethandler_compat_vsock_vm_notify)
	},
	[__hmnet_method_vsock_unregister_vm * 2] = {
		.p__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm = (&__actvbridgecapcallhdlr_nethandler_vsock_unregister_vm)
	},
	[__hmnet_method_vsock_unregister_vm * 2 + 1] = {
		.p__actvbridgecapcallhdlr_nethandler_compat_vsock_unregister_vm = (&__actvbridgecapcallhdlr_nethandler_compat_vsock_unregister_vm)
	}
};

#endif
void sysif_show_hmnet_methods(void)
{
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "revoke", __hmnet_method_socket_revoke);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "revoke", __hmnet_method_socket_revoke);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "fork", __hmnet_method_socket_fork);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "fork", __hmnet_method_socket_fork);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "socket", __hmnet_method_socket_socket);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "socket", __hmnet_method_socket_socket);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "socketpair", __hmnet_method_socket_socketpair);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "socketpair", __hmnet_method_socket_socketpair);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "close", __hmnet_method_socket_close);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "close", __hmnet_method_socket_close);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "shutdown", __hmnet_method_socket_shutdown);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "shutdown", __hmnet_method_socket_shutdown);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "bind", __hmnet_method_socket_bind);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "bind", __hmnet_method_socket_bind);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "listen", __hmnet_method_socket_listen);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "listen", __hmnet_method_socket_listen);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "accept", __hmnet_method_socket_accept);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "accept", __hmnet_method_socket_accept);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "connect", __hmnet_method_socket_connect);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "connect", __hmnet_method_socket_connect);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "send", __hmnet_method_socket_send);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "send", __hmnet_method_socket_send);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "sendmsg", __hmnet_method_socket_sendmsg);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "sendmsg", __hmnet_method_socket_sendmsg);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "recvmsg", __hmnet_method_socket_recvmsg);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "recvmsg", __hmnet_method_socket_recvmsg);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "sendto", __hmnet_method_socket_sendto);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "sendto", __hmnet_method_socket_sendto);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "recvfrom", __hmnet_method_socket_recvfrom);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "recvfrom", __hmnet_method_socket_recvfrom);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "getsockopt", __hmnet_method_socket_getsockopt);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "getsockopt", __hmnet_method_socket_getsockopt);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "setsockopt", __hmnet_method_socket_setsockopt);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "setsockopt", __hmnet_method_socket_setsockopt);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "getsockname", __hmnet_method_socket_getsockname);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "getsockname", __hmnet_method_socket_getsockname);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "getpeername", __hmnet_method_socket_getpeername);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "getpeername", __hmnet_method_socket_getpeername);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "fcntl", __hmnet_method_socket_fcntl);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "fcntl", __hmnet_method_socket_fcntl);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "ioctl", __hmnet_method_socket_ioctl);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "ioctl", __hmnet_method_socket_ioctl);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "dup", __hmnet_method_socket_dup);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "dup", __hmnet_method_socket_dup);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "send_fd", __hmnet_method_socket_send_fd);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "send_fd", __hmnet_method_socket_send_fd);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "recv_fd", __hmnet_method_socket_recv_fd);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "recv_fd", __hmnet_method_socket_recv_fd);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "socket", "put_send_fd", __hmnet_method_socket_put_send_fd);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "socket", "put_send_fd", __hmnet_method_socket_put_send_fd);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "epoll", "ctl", __hmnet_method_epoll_ctl);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "epoll", "ctl", __hmnet_method_epoll_ctl);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "epoll", "et_revents", __hmnet_method_epoll_et_revents);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "epoll", "et_revents", __hmnet_method_epoll_et_revents);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "epoll", "reinit", __hmnet_method_epoll_reinit);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "epoll", "reinit", __hmnet_method_epoll_reinit);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "cfg", "loglevel", __hmnet_method_cfg_loglevel);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "cfg", "loglevel", __hmnet_method_cfg_loglevel);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "cfg", "show_stats", __hmnet_method_cfg_show_stats);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "cfg", "show_stats", __hmnet_method_cfg_show_stats);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "cfg", "getifaddrs", __hmnet_method_cfg_getifaddrs);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "cfg", "getifaddrs", __hmnet_method_cfg_getifaddrs);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "netdev", "rx", __hmnet_method_netdev_rx);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "netdev", "rx", __hmnet_method_netdev_rx);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "netdev", "notify", __hmnet_method_netdev_notify);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "netdev", "notify", __hmnet_method_netdev_notify);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "netdev", "rx_ex_slowdata", __hmnet_method_netdev_rx_ex_slowdata);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "netdev", "rx_ex_slowdata", __hmnet_method_netdev_rx_ex_slowdata);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "procfs", "read", __hmnet_method_procfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "procfs", "read", __hmnet_method_procfs_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "procfs", "write", __hmnet_method_procfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "procfs", "write", __hmnet_method_procfs_write);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "procfs", "fds_read", __hmnet_method_procfs_fds_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "procfs", "fds_read", __hmnet_method_procfs_fds_read);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "procfs", "get_fd_path", __hmnet_method_procfs_get_fd_path);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "procfs", "get_fd_path", __hmnet_method_procfs_get_fd_path);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "netlink", "register_generic", __hmnet_method_netlink_register_generic);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "netlink", "register_generic", __hmnet_method_netlink_register_generic);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "netlink", "unregister_generic", __hmnet_method_netlink_unregister_generic);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "netlink", "unregister_generic", __hmnet_method_netlink_unregister_generic);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "netlink", "unicast", __hmnet_method_netlink_unicast);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "netlink", "unicast", __hmnet_method_netlink_unicast);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "netlink", "broadcast", __hmnet_method_netlink_broadcast);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "netlink", "broadcast", __hmnet_method_netlink_broadcast);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "vsock", "register_vm", __hmnet_method_vsock_register_vm);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "vsock", "register_vm", __hmnet_method_vsock_register_vm);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "vsock", "vm_notify", __hmnet_method_vsock_vm_notify);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "vsock", "vm_notify", __hmnet_method_vsock_vm_notify);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvcall", "netcall", "vsock", "unregister_vm", __hmnet_method_vsock_unregister_vm);
	hm_debug("method is %s_%s_%s_%s, callnum is %u\n", "actvhdlr", "nethandler", "vsock", "unregister_vm", __hmnet_method_vsock_unregister_vm);
	hm_info("%s_%s, max method num: %d\n", "hmnet", "method", __hmnet_method_MAX);
}

int __actvcall_netcall_socket_revoke(unsigned long long __rpc_info, void *__buf)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_revoke((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcapcall_netcall_socket_revoke(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_revoke((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcall_netcall_socket_fork(unsigned long long __rpc_info, void *__buf)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_fork((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcapcall_netcall_socket_fork(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_fork((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcall_netcall_socket_socket(unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_socket((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, domain, type, protocol, fd);
}

int __actvcapcall_netcall_socket_socket(rref_t __rref, unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_socket((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, domain, type, protocol, fd);
}

int __actvcall_netcall_socket_socketpair(unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd, int fd2)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_socketpair((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, domain, type, protocol, fd, fd2);
}

int __actvcapcall_netcall_socket_socketpair(rref_t __rref, unsigned long long __rpc_info, void *__buf, int domain, int type, int protocol, int fd, int fd2)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_socketpair((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, domain, type, protocol, fd, fd2);
}

int __actvcall_netcall_socket_close(unsigned long long __rpc_info, void *__buf, int fd)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_close((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd);
}

int __actvcapcall_netcall_socket_close(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_close((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd);
}

int __actvcall_netcall_socket_shutdown(unsigned long long __rpc_info, void *__buf, int fd, int how)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_shutdown((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, how);
}

int __actvcapcall_netcall_socket_shutdown(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int how)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_shutdown((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, how);
}

int __actvcall_netcall_socket_bind(unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t len)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_bind((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, addr, len);
}

int __actvcapcall_netcall_socket_bind(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t len)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_bind((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, addr, len);
}

int __actvcall_netcall_socket_listen(unsigned long long __rpc_info, void *__buf, int fd, int backlog)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_listen((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, backlog);
}

int __actvcapcall_netcall_socket_listen(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int backlog)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_listen((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, backlog);
}

int __actvcall_netcall_socket_accept(unsigned long long __rpc_info, void *__buf, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_accept((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, sockfd, addr, addrlen, flags, fd);
}

int __actvcapcall_netcall_socket_accept(rref_t __rref, unsigned long long __rpc_info, void *__buf, int sockfd, void *addr, void *addrlen, int flags, int fd)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_accept((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, sockfd, addr, addrlen, flags, fd);
}

int __actvcall_netcall_socket_connect(unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t addrlen)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_connect((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, addr, addrlen);
}

int __actvcapcall_netcall_socket_connect(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *addr, socklen_t addrlen)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_connect((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, addr, addrlen);
}

int __actvcall_netcall_socket_send(unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_send((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, buf, len, flags);
}

int __actvcapcall_netcall_socket_send(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_send((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, buf, len, flags);
}

int __actvcall_netcall_socket_sendmsg(unsigned long long __rpc_info, void *__buf, int fd, const void *msg, int flags)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_sendmsg((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, msg, flags);
}

int __actvcapcall_netcall_socket_sendmsg(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *msg, int flags)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_sendmsg((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, msg, flags);
}

int __actvcall_netcall_socket_recvmsg(unsigned long long __rpc_info, void *__buf, int fd, void *msg, int flags)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_recvmsg((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, msg, flags);
}

int __actvcapcall_netcall_socket_recvmsg(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *msg, int flags)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_recvmsg((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, msg, flags);
}

int __actvcall_netcall_socket_sendto(unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_sendto((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, buf, len, flags, addr, addrlen);
}

int __actvcapcall_netcall_socket_sendto(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, const void *buf, size_t len, int flags, const void *addr, socklen_t addrlen)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_sendto((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, buf, len, flags, addr, addrlen);
}

int __actvcall_netcall_socket_recvfrom(unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_recvfrom((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, buf, len, flags, addr, addrlen);
}

int __actvcapcall_netcall_socket_recvfrom(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *buf, size_t len, int flags, void *addr, void *addrlen)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_recvfrom((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, buf, len, flags, addr, addrlen);
}

int __actvcall_netcall_socket_getsockopt(unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_getsockopt((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, level, optname, optval, optlen);
}

int __actvcapcall_netcall_socket_getsockopt(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, void *optval, socklen_t *optlen)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_getsockopt((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, level, optname, optval, optlen);
}

int __actvcall_netcall_socket_setsockopt(unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_setsockopt((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, level, optname, optval, optlen);
}

int __actvcapcall_netcall_socket_setsockopt(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_setsockopt((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, level, optname, optval, optlen);
}

int __actvcall_netcall_socket_getsockname(unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_getsockname((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, addr, addrlen);
}

int __actvcapcall_netcall_socket_getsockname(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_getsockname((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, addr, addrlen);
}

int __actvcall_netcall_socket_getpeername(unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_getpeername((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, addr, addrlen);
}

int __actvcapcall_netcall_socket_getpeername(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, void *addr, void *addrlen)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_getpeername((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, addr, addrlen);
}

int __actvcall_netcall_socket_fcntl(unsigned long long __rpc_info, void *__buf, int fd, int cmd, int val)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_fcntl((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, cmd, val);
}

int __actvcapcall_netcall_socket_fcntl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int cmd, int val)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_fcntl((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, cmd, val);
}

int __actvcall_netcall_socket_ioctl(unsigned long long __rpc_info, void *__buf, int fd, int request, unsigned long args)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_ioctl((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, request, args);
}

int __actvcapcall_netcall_socket_ioctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int fd, int request, unsigned long args)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_ioctl((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, fd, request, args);
}

int __actvcall_netcall_socket_dup(unsigned long long __rpc_info, void *__buf, int oldfd, int newfd)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_dup((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, oldfd, newfd);
}

int __actvcapcall_netcall_socket_dup(rref_t __rref, unsigned long long __rpc_info, void *__buf, int oldfd, int newfd)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_dup((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, oldfd, newfd);
}

int __actvcall_netcall_socket_send_fd(unsigned long long __rpc_info, void *__buf, unsigned long argu_info)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_send_fd((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, argu_info);
}

int __actvcapcall_netcall_socket_send_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long argu_info)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_send_fd((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, argu_info);
}

int __actvcall_netcall_socket_recv_fd(unsigned long long __rpc_info, void *__buf, unsigned long argu_info)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_recv_fd((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, argu_info);
}

int __actvcapcall_netcall_socket_recv_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long argu_info)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_recv_fd((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, argu_info);
}

int __actvcall_netcall_socket_put_send_fd(unsigned long long __rpc_info, void *__buf, uintptr_t argu_info)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_put_send_fd((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, argu_info);
}

int __actvcapcall_netcall_socket_put_send_fd(rref_t __rref, unsigned long long __rpc_info, void *__buf, uintptr_t argu_info)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_socket_put_send_fd((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, argu_info);
}

int __actvcall_netcall_epoll_ctl(unsigned long long __rpc_info, void *__buf, int socket_fd, int op, const void *epoll_reg_info)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_epoll_ctl((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, socket_fd, op, epoll_reg_info);
}

int __actvcapcall_netcall_epoll_ctl(rref_t __rref, unsigned long long __rpc_info, void *__buf, int socket_fd, int op, const void *epoll_reg_info)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_epoll_ctl((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, socket_fd, op, epoll_reg_info);
}

int __actvcall_netcall_epoll_et_revents(unsigned long long __rpc_info, void *__buf, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_epoll_et_revents((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, socket_fd, epi_shm_key, epi_shm_index);
}

int __actvcapcall_netcall_epoll_et_revents(rref_t __rref, unsigned long long __rpc_info, void *__buf, int socket_fd, unsigned long long epi_shm_key, unsigned int epi_shm_index)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_epoll_et_revents((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, socket_fd, epi_shm_key, epi_shm_index);
}

int __actvcall_netcall_epoll_reinit(unsigned long long __rpc_info, void *__buf, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_epoll_reinit((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, socket_fd, epoll_pre_reg_info, epoll_reg_info);
}

int __actvcapcall_netcall_epoll_reinit(rref_t __rref, unsigned long long __rpc_info, void *__buf, int socket_fd, const void *epoll_pre_reg_info, const void *epoll_reg_info)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_epoll_reinit((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, socket_fd, epoll_pre_reg_info, epoll_reg_info);
}

int __actvcall_netcall_cfg_loglevel(unsigned long long __rpc_info, void *__buf, unsigned int loglevel)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_cfg_loglevel((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, loglevel);
}

int __actvcapcall_netcall_cfg_loglevel(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int loglevel)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_cfg_loglevel((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, loglevel);
}

int __actvcall_netcall_cfg_show_stats(unsigned long long __rpc_info, void *__buf, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_cfg_show_stats((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, ss_protocol, shm_key);
}

int __actvcapcall_netcall_cfg_show_stats(rref_t __rref, unsigned long long __rpc_info, void *__buf, struct sysif_protocol ss_protocol, unsigned long long shm_key)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_cfg_show_stats((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, ss_protocol, shm_key);
}

int __actvcall_netcall_cfg_getifaddrs(unsigned long long __rpc_info, void *__buf, unsigned long long shm_key)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_cfg_getifaddrs((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, shm_key);
}

int __actvcapcall_netcall_cfg_getifaddrs(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned long long shm_key)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_cfg_getifaddrs((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, shm_key);
}

int __actvcall_netcall_netdev_rx(unsigned long long __rpc_info, void *__buf, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netdev_rx((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cell_pool_offset, shm_len, rx_len, offset, devno);
}

int __actvcapcall_netcall_netdev_rx(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cell_pool_offset, int shm_len, int rx_len, int offset, int devno)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netdev_rx((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cell_pool_offset, shm_len, rx_len, offset, devno);
}

int __actvcall_netcall_netdev_notify(unsigned long long __rpc_info, void *__buf, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netdev_notify((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, event, devno, option, ifname, features);
}

int __actvcapcall_netcall_netdev_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, enum hm_netdev_event event, int devno, int option, struct netdev_ifname ifname, unsigned long long features)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netdev_notify((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, event, devno, option, ifname, features);
}

int __actvcall_netcall_netdev_rx_ex_slowdata(unsigned long long __rpc_info, void *__buf, int num)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netdev_rx_ex_slowdata((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, num);
}

int __actvcapcall_netcall_netdev_rx_ex_slowdata(rref_t __rref, unsigned long long __rpc_info, void *__buf, int num)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netdev_rx_ex_slowdata((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, num);
}

int __actvcall_netcall_procfs_read(unsigned long long __rpc_info, void *__buf)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_procfs_read((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcapcall_netcall_procfs_read(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_procfs_read((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcall_netcall_procfs_write(unsigned long long __rpc_info, void *__buf)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_procfs_write((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcapcall_netcall_procfs_write(rref_t __rref, unsigned long long __rpc_info, void *__buf)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_procfs_write((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL);
}

int __actvcall_netcall_procfs_fds_read(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_procfs_fds_read((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cnode_idx, fd_map, max_files);
}

int __actvcapcall_netcall_procfs_fds_read(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, unsigned long long fd_map, unsigned int max_files)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_procfs_fds_read((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cnode_idx, fd_map, max_files);
}

int __actvcall_netcall_procfs_get_fd_path(unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_procfs_get_fd_path((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cnode_idx, fd, path_buf, path_buf_len);
}

int __actvcapcall_netcall_procfs_get_fd_path(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cnode_idx, int fd, unsigned long long path_buf, unsigned int path_buf_len)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_procfs_get_fd_path((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cnode_idx, fd, path_buf, path_buf_len);
}

int __actvcall_netcall_netlink_register_generic(unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned long long dh_ap_uref)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		__rply_buf,
		rply_buf_sz
	};
	return actvhdlr_nethandler_netlink_register_generic((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, dh_ap_uref);
}

int __actvcapcall_netcall_netlink_register_generic(rref_t __rref, unsigned long long __rpc_info, void *__buf, void *__rply_buf, unsigned long rply_buf_sz, unsigned long long dh_ap_uref)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		__rply_buf,
		rply_buf_sz
	};
	return actvhdlr_nethandler_netlink_register_generic((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, dh_ap_uref);
}

int __actvcall_netcall_netlink_unregister_generic(unsigned long long __rpc_info, void *__buf, unsigned short familyid)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netlink_unregister_generic((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, familyid);
}

int __actvcapcall_netcall_netlink_unregister_generic(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned short familyid)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netlink_unregister_generic((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, familyid);
}

int __actvcall_netcall_netlink_unicast(unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_port)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netlink_unicast((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, protocol, src_portid, dst_port);
}

int __actvcapcall_netcall_netlink_unicast(rref_t __rref, unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_port)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netlink_unicast((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, protocol, src_portid, dst_port);
}

int __actvcall_netcall_netlink_broadcast(unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_group)
{
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netlink_broadcast((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, protocol, src_portid, dst_group);
}

int __actvcapcall_netcall_netlink_broadcast(rref_t __rref, unsigned long long __rpc_info, void *__buf, int protocol, unsigned int src_portid, unsigned int dst_group)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		__buf,
		__RPC_INFO_DECODE_MEM_BUF_LEN((unsigned long)__rpc_info),
		NULL,
		0UL
	};
	return actvhdlr_nethandler_netlink_broadcast((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, protocol, src_portid, dst_group);
}

int __actvcall_netcall_vsock_register_vm(unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned int dev_group_id)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_vsock_register_vm((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cid, dev_group_id);
}

int __actvcapcall_netcall_vsock_register_vm(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned int dev_group_id)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_vsock_register_vm((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cid, dev_group_id);
}

int __actvcall_netcall_vsock_vm_notify(unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_vsock_vm_notify((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cid, cmd, args, size);
}

int __actvcapcall_netcall_vsock_vm_notify(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cid, unsigned short cmd, void *args, size_t size)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_vsock_vm_notify((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cid, cmd, args, size);
}

int __actvcall_netcall_vsock_unregister_vm(unsigned long long __rpc_info, void *__buf, unsigned int cid)
{
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_vsock_unregister_vm((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cid);
}

int __actvcapcall_netcall_vsock_unregister_vm(rref_t __rref, unsigned long long __rpc_info, void *__buf, unsigned int cid)
{
	UNUSED(__rref);
	struct sysif_actv_selfcall selfcall = {
		NULL,
		0UL,
		NULL,
		0UL
	};
	return actvhdlr_nethandler_vsock_unregister_vm((unsigned long long)(uintptr_t)&selfcall, __ACTV_CRED_SELFCALL, cid);
}

#endif
#endif
