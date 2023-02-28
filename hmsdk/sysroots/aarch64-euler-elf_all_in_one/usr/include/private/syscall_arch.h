#ifndef AARCH64_SYSCALL_ARCH_H
#define AARCH64_SYSCALL_ARCH_H

#define __NEED_uintptr_t
#define __NEED_size_t
#include <bits/alltypes.h>
#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

/*
 * Route syscall to __sysinfo
 * <Posix syscall>---->__syscallN---->__sysinfo---->hm_vsyscall----><hm implementation>
 * __sysinfo is the pointer to the system call entry point on hongmeng.
 */
extern size_t __sysinfo;

/* __asm_syscall on hongmeng is a function call */
#define __asm_syscall(n, ...) ((long(*)(long,...))(uintptr_t)__sysinfo)(n, ##__VA_ARGS__)

static inline long __syscall0(long n)
{
	return __asm_syscall(n);
}

static inline long __syscall1(long n, long a)
{
	return __asm_syscall(n, a);
}

static inline long __syscall2(long n, long a, long b)
{
	return __asm_syscall(n, a, b);
}

static inline long __syscall3(long n, long a, long b, long c)
{
	return __asm_syscall(n, a, b, c);
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
	return __asm_syscall(n, a, b, c, d);
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
	return __asm_syscall(n, a, b, c, d, e);
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	return __asm_syscall(n, a, b, c, d, e, f);
}

static inline long __syscall7(long n, long a, long b, long c, long d, long e, long f, long g)
{
	return __asm_syscall(n, a, b, c, d, e, f, g);
}
#define VDSO_USEFUL
#define VDSO_CGT_SYM "vdso_clock_gettime"
#define VDSO_CGT_VER ""

#define VDSO_GET_DATA_SYM "vdso_get_data"
#define VDSO_GET_DATA_VER ""

#define VDSO_GETTIME_OF_DAY_SYM "__vdso_gettimeofday"
#define VDSO_GETTIME_OF_DAY_VER  ""

#define VDSO_SAFE_COPY "safe_copy"
#define VDSO_SAFE_COPY_ALIGN "safe_copy_align"
#define VDSO_SAFE_COPY_VERSION ""

#define IPC_64 0
#endif
