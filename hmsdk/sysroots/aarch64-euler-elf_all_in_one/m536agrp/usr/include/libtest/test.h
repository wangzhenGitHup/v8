/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Tue Apr 02 21:04:46 2019
 */
#ifndef ULIBS_LIBTEST_TEST_H
#define ULIBS_LIBTEST_TEST_H

#include <libhmsrv_sys/hm_thread.h>
#include <hongmeng/syscall.h>
#include <hongmeng/errno.h>
#include <libcrt/hmcrt.h>
#include <hmkernel/sched_module.h>
#include <stdbool.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define TEST_OK		0
#define TEST_FAIL	1
#define TEST_NOTEST	2
#define TEST_TMOUT	4
#define TEST_SKIP	8
#define TEST_NULL	128

#define ALL_TEST	0
#define FUNC_TEST	1
#define PERF_TEST	2
#define STAB_TEST	3

#define SHELL_CMD_LEN 100
#define SHELL_TEST_PATH "/usr/bin/shell_test"

struct test_result {
	int total;
	int passed;
	int failed;
	int timeout;
	int skip;
	int notest;
	int unknown;
};

struct test {
	const char *desc; /* descript of this test */
	int (*func)(void);
	const char *funcname; /* name of pointer of func */
	void *priv;
	unsigned int state; /* whether failed in test */
	time_t seconds;
	unsigned int test_type;
	int (*setup)(void);
	int (*teardown)(void);
	bool use_fork; /* Create subprocess to execute the testcase. */
}; /* struct for testcases */

struct test_modules {
	const char *desc; /* descript of this test subsystem */
	const char *funcname; /* name of pointer of func */
	struct test *test_list; /* test list for this module */
	int (*setup)(void); /* setup for this module */
	int (*teardown)(void); /* tear down for this module */
	int setup_result;      /* setup() result */
	int teardown_result;   /* teardown() result */
	int do_test;	       /* whether did test this module */
}; /* struct for test modules */

#define TPRINT(level, fmt, args...) (void)printf("["#level"][%s:%d] "fmt, __func__, __LINE__, ##args)
#define TINFO(fmt, args...) TPRINT(INFO, fmt, ##args)
#define TWARN(fmt, args...) TPRINT(WARN, fmt, ##args)
#define TPASS(fmt, args...) TPRINT(PASS, fmt, ##args)
#define TFAIL(fmt, args...) TPRINT(FAIL, fmt, ##args)
#define TBROK(fmt, args...) TPRINT(BROK, fmt, ##args)

/* This is a temporary interface to output log without lock.
 *
 * The TFAIL and TINFO are implemented based on the printf which needs to
 * hold the __lockfile before accessing the stdout. If a thread used TFAIL
 * or TINFO to output the log, then it might be killed without releasing
 * the __lockfile. In this case, the main thread cannot get the __lockfile
 * to output the log and exit anymore.
 */
#define TMP_PRINT_THRESHOLD		128u

#define TMP_PRINT(level, fmt, args...)						\
{										\
	char buf[TMP_PRINT_THRESHOLD];						\
	(void)sprintf_s(buf, TMP_PRINT_THRESHOLD, "["#level"][%s:%d] "fmt, __func__, __LINE__, ##args); \
	(void)sysfast_kconsole_print(buf, TMP_PRINT_THRESHOLD, NULL);		\
}

#define TMP_INFO(fmt, args...) TMP_PRINT(INFO, fmt, ##args)
#define TMP_WARN(fmt, args...) TMP_PRINT(WARN, fmt, ##args)
#define TMP_PASS(fmt, args...) TMP_PRINT(PASS, fmt, ##args)
#define TMP_FAIL(fmt, args...) TMP_PRINT(FAIL, fmt, ##args)
#define TMP_BROK(fmt, args...) TMP_PRINT(BROK, fmt, ##args)

#define TBEGIN()                                                               \
	int ret = 0, err = 0;                                                  \
	cref_t ref = 0;                                                        \
	ref = ref;                                                             \
                                                                               \
	TINFO("Function begins\n");                                            \

#define TEND()                                                                 \
	do {                                                                   \
		goto errout;                                                   \
                                                                               \
errout:                                                                        \
		TINFO("Function ends\n");                                      \
	} while(0)

#define ELFTSPAWN(desc, module, func, pid, elffile)                            \
	do {                                                                   \
		const char path[] = "/usr/bin/" elffile;                       \
		const char *argv[] = {                                         \
			path,                               		       \
			module,                                                \
			func,                                                  \
			NULL,                                                  \
		};                                                             \
		const char *envp[] = {                                         \
			"PATH=/:/bin:/usr/bin",                                \
			NULL,                                                  \
		};                                                             \
		TCALL(desc, hm_spawn, pid, path, NULL, NULL, argv, envp);      \
	} while (0)

#define TWAIT(desc, pid, wstatus)                                                  \
	do {                                                                   \
		TCALL(desc, hm_waitpid, pid, 0, wstatus);           \
	} while (0)

#define EXIT_EQ(pid, wstatus, err) test_check_exit(pid, wstatus, err, false)

#define SIG_EQ(pid, wstatus, sig) test_check_exit(pid, wstatus, sig, true)

#define CCT_ASSERT(abort, cond)                                                \
do {                                                                   \
	if (!(cond)) {                                                 \
		TFAIL("CCT assertion failed : %s\n", #cond);           \
		do {                                                   \
			abort;                                         \
		} while (0);                                           \
	};                                                             \
} while (0)

#define test_assert(cond) CCT_ASSERT(ret = -1; goto errout, cond)

#define CHECK_VAR(desc, var, format, cond)                                     \
do {                                                                   \
	if (cond) {                                                    \
		TPASS(desc " - satisfied: " format "\n", var);         \
	} else {                                                       \
		TFAIL(desc " - failed: " format "\n", var);            \
		ret = -1;                                              \
		goto errout;                                           \
	}                                                              \
} while (0)

#define CHECK_VAR_INT(desc, var, cond) CHECK_VAR(desc, var, "%d", cond)

#define CHECK_VAR_U64(desc, var, cond) CHECK_VAR(desc, var, "%llu", cond)

#define TCALL_EC_O(desc, api, err_cond, args...)                               \
do {                                                                   \
	TINFO(desc " - starting...\n");                                \
	TINFO("call " #api"\n");                                       \
	err = api(args);                                               \
	if (err_cond) {                                                \
		TFAIL(desc " - failed: %s\n", hmstrerror(err));        \
	} else {                                                       \
		TPASS(desc " - succeed: %s\n", hmstrerror(err));       \
	}                                                              \
} while (0)

#define TCALL_EC(desc, api, err_cond, args...)                                 \
	do {                                                                   \
		TINFO(desc " - starting...\n");                                \
		TINFO("call " #api"\n");                                       \
		err = api(args);                                               \
		if (err_cond) {                                                \
			TFAIL(desc " - failed: %s\n", hmstrerror(err));        \
			ret = -1;                                              \
			goto errout;                                           \
		}                                                              \
		ret = ret;                                                     \
		TPASS(desc " - succeed: %s %d\n", hmstrerror(err), ret);       \
	} while (0)

#define TCALL(desc, api, args...)                                              \
	do {                                                                   \
		TCALL_EC(desc, api, (err < 0), args);                          \
	} while (0)

#define TCALL_O(desc, api, args...)					       \
	do {								       \
		TCALL_EC_O(desc, api, (err < 0), args);			       \
	} while (0)

#define TCALL_E(desc, api, error, args...)                                     \
	do {                                                                   \
		TINFO(desc " - expect error code: %s\n", hmstrerror(error));   \
		TCALL_EC(desc, api, (err != error), args);		       \
	} while (0)

#define TCALL_REF(desc, api, args...) do {                                     \
		TINFO(desc "\n");                                              \
		ref = api(args);                                               \
		if (IS_REF_ERR(ref)) {                                         \
			TFAIL(desc " failed: %s\n",                            \
			      hmstrerror(REF_TO_ERR(ref)));                    \
			ret = -1;                                              \
			goto errout;                                           \
		}                                                              \
		ret = ret;                                                     \
		TPASS(desc " success\n");                                      \
	} while(0)

#define TSPAWN(desc, module, func, pid)                                        \
	do {                                                                   \
		const char *path = "/usr/bin/hm-test.elf";                     \
		const char *argv[] = {                                         \
			"/usr/bin/hm-test.elf",                                \
			"test",                                                \
			"-s",                                                  \
			module,                                                \
			"-t",                                                  \
			func,                                                  \
			NULL,                                                  \
		};                                                             \
		const char *envp[] = {                                         \
			"PATH=/:/bin:/usr/bin",                                \
			NULL,                                                  \
		};                                                             \
		TCALL(desc, hm_spawn, pid, path, NULL, NULL, argv, envp);      \
	} while (0)

#define TFORK(desc, func, pid)              \
    do {                                    \
        pid = fork();                       \
        if (pid < 0) {                      \
            TFAIL("fork child %s faild\n", desc);   \
            ret = TEST_FAIL;                       \
            goto errout;                    \
        } else if (pid == 0) {              \
            exit(func());                           \
        }                                   \
    } while (0)

#define TWAIT_PID(desc, pid, exit_status)              \
    do {                                            \
        err = waitpid(pid, exit_status, 0);         \
        if (err == -1) {                            \
            TFAIL("wait child %s faild %d\n", desc, pid);   \
            ret = TEST_FAIL;                               \
            goto errout;                            \
        }                                           \
        if (WIFEXITED(*(exit_status))) {            \
            if (WEXITSTATUS(*(exit_status))) {      \
                TFAIL("child exit non-zero %d\n", WEXITSTATUS(*(exit_status)));     \
                ret = TEST_FAIL;                           \
            }                                       \
        } else if (WIFSIGNALED(*(exit_status))) {   \
            TINFO("child killed by signal %d\n", WTERMSIG(*(exit_status))); \
            ret = TEST_FAIL;                               \
        } else if (WCOREDUMP(*(exit_status))) {     \
            TFAIL("child core dumps\n");            \
            ret = TEST_FAIL;                               \
        } else if (WIFSTOPPED(*(exit_status))) {    \
            TINFO("child stopped by signal %d\n", WSTOPSIG(*(exit_status))); \
            ret = TEST_FAIL;                               \
        }                                           \
    } while (0)

#define DO_TEST(fun, desc)                                                     \
	do {                                                                   \
		TINFO("--------- test %s ---------\n", desc);                  \
		test_count++;                                                  \
		err = fun();                                                   \
		if (err) {                                                     \
			TFAIL("------ test %s failed ------\n", desc);         \
			failed_count++;                                        \
			ret += 1;                                              \
		} else {                                                       \
			TPASS("------ test %s success ------\n", desc);        \
			ret = ret;                                             \
		}                                                              \
	} while (0)

#define DO_TEST_NP(module, func, desc)                                         \
	do {                                                                   \
		TINFO("--------- test " func " ---------\n");                  \
		TINFO("--------- " desc " ---------\n");                       \
		test_count++;                                                  \
		test_num++;                                                    \
		err = np_exec(module, func, 1, NULL);                          \
		if (err) {                                                     \
			TFAIL("------ test " func " failed ------\n");         \
			failed_count++;                                        \
			failed_num++;                                          \
			ret += 1;                                              \
		} else {                                                       \
			TPASS("------ test " func " success ------\n");        \
			ret = ret;                                             \
		}                                                              \
	} while (0)

#define REGISTER_FUNC(funcstr, func)                                           \
	do {                                                                   \
		if (!strcmp(argv[2], funcstr)) {                               \
			func();                                                \
		}                                                              \
	} while (0)

#define TSTEP(n) do {                                                          \
	TINFO("**** test step " #n " ****\n");                                 \
} while (0)

#define REGISTER_OPTION(opt, func) do {		\
		if (!strcmp(argv[2], opt)) {	\
			func();			\
		}				\
	} while (0)

#define __DEF_TEST(f, d, x, s, t, u) {.desc = (d), .func = (f), .funcname = #f, .priv = NULL, \
	.state = TEST_NOTEST, .seconds = 0L, .test_type = (x), .setup = (s), .teardown = (t), \
	.use_fork = (u)},

#define _DEF_TEST(f, d, x, s, t) __DEF_TEST(f, d, x, s, t, true)
#define DEF_TEST(f, d, x) _DEF_TEST(f, d, x, NULL, NULL)
#define DEF_TEST_SETUP(f, d, x, s) _DEF_TEST(f, d, x, s, NULL)
#define DEF_TEST_TEARDOWN(f, d, x, t) _DEF_TEST(f, d, x, NULL, t)
#define DEF_TEST_SETUP_TEARDOWN(f, d, x, s, t) _DEF_TEST(f, d, x, s ,t)
#define TESTHM(d, f) DEF_TEST(f, d, FUNC_TEST)

#define _DEF_TEST_NFORK(f, d, x, s, t) __DEF_TEST(f, d, x, s, t, false)
#define DEF_TEST_NFORK(f, d, x) _DEF_TEST_NFORK(f, d, x, NULL, NULL)
#define DEF_TEST_NFORK_SETUP(f, d, x, s) _DEF_TEST_NFORK(f, d, x, s, NULL)
#define DEF_TEST_NFORK_TEARDOWN(f, d, x, t) _DEF_TEST_NFORK(f, d, x, NULL, t)
#define DEF_TEST_NFORK_SETUP_TEARDOWN(f, d, x, s, t) _DEF_TEST_NFORK(f, d, x, s ,t)

#define _DEF_MODULE(f, l, s, t) {.desc = #l, .funcname = #f, .test_list = (l), \
				 .setup = (s), .teardown = (t), .setup_result = 0, \
				 .teardown_result = 0, .do_test = 0},
#define DEF_MODULE(f, l) _DEF_MODULE(f, l, NULL, NULL)
#define DEF_MODULE_SETUP(f, l, s) _DEF_MODULE(f, l, s, NULL)
#define DEF_MODULE_TEARDOWN(f, l, t) _DEF_MODULE(f, l, NULL, t)
#define DEF_MODULE_SETUP_TEARDOWN(f, l, s, t) _DEF_MODULE(f, l, s, t)

#define DEF_SHELL_TEST(f)							\
	int f(void) {								\
		char cmd[SHELL_CMD_LEN];					\
		int err = snprintf_s(cmd, SHELL_CMD_LEN, SHELL_CMD_LEN - 1,	\
				"%s/%s.sh", SHELL_TEST_PATH, #f);		\
		if (err < 0) {							\
			return -1;						\
		}								\
		int ret = system(cmd);						\
		if (ret == -1 || !WIFEXITED(ret)) {				\
			return -1;						\
		}								\
		return WEXITSTATUS(ret);					\
	}

void test_run_all(int argc, char *argv[], struct test *tests, struct test_result *result);
int test_run_alltest(struct test_modules *tests, unsigned int test_type, struct test_result *result);
int test_run_module(char *name, struct test_modules *tests, unsigned int test_type, struct test_result *result);
int test_run_one(char *module, char *testname, struct test_modules *tests, struct test_result *result);
int test_do_test(struct test *tests, struct test_result *result);
void test_dump_result(char *module, char *testname, struct test_modules *tests, struct test_result *result);
void test_list_modules(struct test_modules *tests);
void test_list_tests(char *name, struct test_modules *tests);
int set_process_affinity(__cpuset_t affinity);
pid_t test_tfork_wait(int (*start)(void), int *wstatus);
bool test_check_exit(pid_t pid, int wstatus, int expect, bool is_sig);
bool is_module_valid(char *name, struct test_modules *tests);
char **get_module_list(const char *module_name);
void free_module_list(char **module_list);

#endif
