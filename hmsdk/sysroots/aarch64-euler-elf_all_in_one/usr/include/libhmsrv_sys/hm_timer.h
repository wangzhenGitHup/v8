/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: User interface of timer related function
 * Author: Huawei OS Kernel Lab
 * Create: Thu Jun 20 05:35:28 2019
 */
#ifndef ULIBS_INCLUDE_LIBHMSRV_SYS_HM_TIMER_H
#define ULIBS_INCLUDE_LIBHMSRV_SYS_HM_TIMER_H

#include <time.h>
#include <signal.h>
#include <stdbool.h>
#include <inttypes.h>
#include <sys/time.h>
#include <hongmeng/syscall.h>
#include <sys/times.h>
#include <sys/timex.h>

#define NSEC_PER_SEC		1000000000
#define USEC_PER_SEC		1000000L
#define NSEC_PER_USEC		1000
#define MSEC_PER_SEC		1000
#define NSEC_PER_MSEC		1000000

#define MAX_TOCK_OFFSET		((~0ULL) - 1ULL)

/* XXX: Remain problem: The number of posix timer is temperorily set to 512 */
#define POSIX_TIMER_MAX_NUM    (__U(1) << 9)

/* This is to conform to sigevent struct passed from musl libc */
struct ksigevent {
	union sigval sigev_value;
	int sigev_signo;
	int sigev_notify;
	int sigev_tid;
};

enum clock_type {
	CLOCK_KERNEL  = 0,
	CLOCK_PMU,
};

int hm_nanosleep(const struct timespec *req, struct timespec *rem);
int hm_clock_nanosleep(clockid_t clk_id, int abs_flag,
		       const struct timespec *req, struct timespec *rem);
int hm_clock_gettime(clockid_t clk_id, struct timespec *time_spec);
int hm_clock_settime(clockid_t clk_id, const struct timespec *time_spec);
int hm_settimeofday(const struct timeval *tv);
int hm_adjtimex(struct timex *buf);

cref_t hm_itimer_cref_of(void);
void hm_update_itimer_cref(void);
int hm_setitimer(int which, const struct itimerval *value, struct itimerval *old);
int hm_getitimer(int which, struct itimerval *value);

int hm_timer_create(clockid_t clk_id, struct ksigevent *evp, int *timerid);
int hm_timer_settime(int timerid, int flags,
		     const struct itimerspec *value, struct itimerspec *old);
int hm_timer_delete(int timerid);
int hm_timer_settype(enum clock_type type);
int hm_clock_getres(clockid_t clk_id, struct timespec *time_spec);
time_t hm_time(time_t *t);
int hm_usleep(unsigned int useconds);
int hm_gettimeofday(struct timeval *restrict tv, const void *restrict tz);
int hm_timer_gettime(int timerid, struct itimerspec *value);
int hm_timer_getoverrun(int timerid, unsigned long long *count);
long hm_times(struct tms *tm);

#ifdef CONFIG_DOPRA_TICK
long hm_dopra_tick(unsigned long long *ticks);
#endif

int timespec_to_values(const struct timespec *ts, __u64 *value);
int timespec_to_values_udata(const struct timespec *ts, __u64 *value);
int tocks_to_timespec(uint64_t tocks, struct timespec *ts);
int tocks_to_timespec_udata(uint64_t tocks, struct timespec *ts);
void mul_mov_cal(__u64 *mul, __u32 *mov, __u64 pa, __u64 pb);

static inline bool timespec_valid(const struct timespec *tsp)
{
	bool ret = true;

	if (tsp != NULL) {
		if (tsp->tv_sec < 0 || tsp->tv_nsec < 0 ||
		    (unsigned long)tsp->tv_nsec >= NSEC_PER_SEC) {
			ret = false;
		}
	}
	return ret;
}

static inline bool timeval_valid(const struct timeval *tvp)
{
	bool ret = true;

	if (tvp != NULL) {
		if (tvp->tv_sec < 0 || tvp->tv_usec < 0 ||
		    tvp->tv_usec >= USEC_PER_SEC) {
			ret = false;
		}
	}
	return ret;
}

/* milliseconds to struct timespec */
static inline void msec_to_timespec(int msec, struct timespec *tsp)
{
	if (tsp != NULL) {
		tsp->tv_sec = (time_t)(msec / MSEC_PER_SEC);
		tsp->tv_nsec = (long)((msec % MSEC_PER_SEC) * NSEC_PER_MSEC);
	}
}

#endif
