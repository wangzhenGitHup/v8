/* Machine description for AArch64 architecture. */

#ifndef GCC_AARCH64_LINUX_H
#define GCC_AARCH64_LINUX_H

#define GLIBC_DYNAMIC_LINKER "/lib/hmld.so.elf"

#undef MUSL_DYNAMIC_LINKER
#define MUSL_DYNAMIC_LINKER "/lib/hmld.so.elf"

#undef  ASAN_CC1_SPEC
#define ASAN_CC1_SPEC "%{%:sanitize(address):-funwind-tables}"

#undef  CC1_SPEC
#define CC1_SPEC GNU_USER_TARGET_CC1_SPEC ASAN_CC1_SPEC

#define CPP_SPEC "%{pthread:-D_REENTRANT}"

#define LINUX_TARGET_LINK_SPEC  "%{h*}		\
   %{static:-Bstatic}				\
   %{shared:-shared}				\
   %{symbolic:-Bsymbolic}			\
   %{!static:					\
     %{rdynamic:-export-dynamic}		\
     %{!shared:-dynamic-linker " GNU_USER_DYNAMIC_LINKER "}} \
   -X						\
   %{mbig-endian:-EB} %{mlittle-endian:-EL}     \
   -maarch64hongmeng%{mabi=ilp32:32}%{mbig-endian:b}"

#if TARGET_FIX_ERR_A53_835769_DEFAULT
#define CA53_ERR_835769_SPEC \
  " %{!mno-fix-cortex-a53-835769:--fix-cortex-a53-835769}"
#else
#define CA53_ERR_835769_SPEC \
  " %{mfix-cortex-a53-835769:--fix-cortex-a53-835769}"
#endif

#if TARGET_FIX_ERR_A53_843419_DEFAULT
#define CA53_ERR_843419_SPEC \
  " %{!mno-fix-cortex-a53-843419:--fix-cortex-a53-843419}"
#else
#define CA53_ERR_843419_SPEC \
  " %{mfix-cortex-a53-843419:--fix-cortex-a53-843419}"
#endif

#define LINK_SPEC LINUX_TARGET_LINK_SPEC \
		  CA53_ERR_835769_SPEC \
		  CA53_ERR_843419_SPEC

#define GNU_USER_TARGET_MATHFILE_SPEC \
  "%{Ofast|ffast-math|funsafe-math-optimizations:crtfastmath.o%s}"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC   \
  GNU_USER_TARGET_MATHFILE_SPEC " " \
  GNU_USER_TARGET_ENDFILE_SPEC

#define TARGET_OS_CPP_BUILTINS()		\
  do						\
    {						\
	GNU_USER_TARGET_OS_CPP_BUILTINS();	\
    }						\
  while (0)

#define TARGET_ASM_FILE_END file_end_indicate_exec_stack

/* Uninitialized common symbols in non-PIE executables, even with
   strong definitions in dependent shared libraries, will resolve
   to COPY relocated symbol in the executable.  See PR65780.  */
#undef TARGET_BINDS_LOCAL_P
#define TARGET_BINDS_LOCAL_P default_binds_local_p_2

/* Define this to be nonzero if static stack checking is supported.  */
#define STACK_CHECK_STATIC_BUILTIN 1

#endif  /* GCC_AARCH64_LINUX_H */
