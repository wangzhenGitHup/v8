#ifndef _UCONTEXT_H
#define _UCONTEXT_H
#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#include <signal.h>

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define NGREG (sizeof(gregset_t)/sizeof(greg_t))
#endif

struct __ucontext;

int  getcontext(ucontext_t *ucp);
void makecontext(ucontext_t *ucp, void (*func) (void), int argc, ...);
int setcontext(const ucontext_t *ucp);
int swapcontext(ucontext_t *oucp, const ucontext_t *ucp);

#ifdef __cplusplus
}
#endif
#endif
