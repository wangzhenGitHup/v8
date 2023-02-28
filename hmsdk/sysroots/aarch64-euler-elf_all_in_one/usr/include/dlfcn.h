#ifndef	_DLFCN_H
#define	_DLFCN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define RTLD_LAZY   1
#define RTLD_NOW    2
#define RTLD_NOLOAD 4
#define RTLD_NODELETE 4096
#define RTLD_GLOBAL 256
#define RTLD_LOCAL  0

#define RTLD_NEXT    ((void *)-1)
#define RTLD_DEFAULT ((void *)0)

#define RTLD_DI_LINKMAP 2

typedef void* (*sym_reloc_hook)(void *ctx, const char *name, void *ptr);
typedef void (*sym_runtime_resolve_hook)(void);

#define RLHOOK_ERR_LAZY_BIND	256
#define RLHOOK_ERRNO_MAX	4095

int    dlclose(void *);
char  *dlerror(void);
void  *dlopen(const char *, int);
void  *dlopen5(const char *file, int mode, sym_reloc_hook reloc_hook,
	       void *reloc_ctx, sym_runtime_resolve_hook rt_resolve_hook);
void  *dlopen_from_mem(const void *, const char *, int);
void  *dlsym(void *__restrict, const char *__restrict);

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
typedef struct {
	const char *dli_fname;
	void *dli_fbase;
	const char *dli_sname;
	void *dli_saddr;
} Dl_info;
int dladdr(const void *, Dl_info *);
int dlinfo(void *, int, void *);
#endif

#if _REDIR_TIME64
__REDIR(dlsym, __dlsym_time64);
#endif

#ifdef __cplusplus
}
#endif

#endif