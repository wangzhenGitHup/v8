#define OPTION_GLIBC  (DEFAULT_LIBC == LIBC_GLIBC)
#define OPTION_UCLIBC (DEFAULT_LIBC == LIBC_UCLIBC)
#define OPTION_BIONIC (DEFAULT_LIBC == LIBC_BIONIC)
#undef OPTION_MUSL
#define OPTION_MUSL   (DEFAULT_LIBC == LIBC_MUSL)


#define GNU_USER_TARGET_OS_CPP_BUILTINS()			\
    do {							\
    if (OPTION_GLIBC)					\
	builtin_define ("__gnu_linux__");			\
	builtin_define_std ("hongmeng");				\
	builtin_define_std ("unix");				\
	builtin_assert ("system=hongmeng");			\
	builtin_assert ("system=unix");				\
	builtin_assert ("system=posix");			\
    } while (0)

/* Determine which dynamic linker to use depending on whether GLIBC or
   uClibc or Bionic or musl is the default C library and whether
   -muclibc or -mglibc or -mbionic or -mmusl has been passed to change
   the default.  */

#define CHOOSE_DYNAMIC_LINKER1(LIBC1, LIBC2, LIBC3, LIBC4, LD1, LD2, LD3, LD4)	\
  "%{" LIBC2 ":" LD2 ";:%{" LIBC3 ":" LD3 ";:%{" LIBC4 ":" LD4 ";:" LD1 "}}}"

#if DEFAULT_LIBC == LIBC_GLIBC
#define CHOOSE_DYNAMIC_LINKER(G, U, B, M) \
  CHOOSE_DYNAMIC_LINKER1 ("mglibc", "muclibc", "mbionic", "mmusl", G, U, B, M)
#elif DEFAULT_LIBC == LIBC_UCLIBC
#define CHOOSE_DYNAMIC_LINKER(G, U, B, M) \
  CHOOSE_DYNAMIC_LINKER1 ("muclibc", "mglibc", "mbionic", "mmusl", U, G, B, M)
#elif DEFAULT_LIBC == LIBC_BIONIC
#define CHOOSE_DYNAMIC_LINKER(G, U, B, M) \
  CHOOSE_DYNAMIC_LINKER1 ("mbionic", "mglibc", "muclibc", "mmusl", B, G, U, M)
#elif DEFAULT_LIBC == LIBC_MUSL
#define CHOOSE_DYNAMIC_LINKER(G, U, B, M) \
  CHOOSE_DYNAMIC_LINKER1 ("mmusl", "mglibc", "muclibc", "mbionic", M, G, U, B)
#else
#error "Unsupported DEFAULT_LIBC"
#endif /* DEFAULT_LIBC */

/* For most targets the following definitions suffice;
   GLIBC_DYNAMIC_LINKER must be defined for each target using them, or
   GLIBC_DYNAMIC_LINKER32 and GLIBC_DYNAMIC_LINKER64 for targets
   supporting both 32-bit and 64-bit compilation.  */
#define UCLIBC_DYNAMIC_LINKER "/lib/ld-uClibc.so.0"
#define UCLIBC_DYNAMIC_LINKER32 "/lib/ld-uClibc.so.0"
#define UCLIBC_DYNAMIC_LINKER64 "/lib/ld64-uClibc.so.0"
#define UCLIBC_DYNAMIC_LINKERX32 "/lib/ldx32-uClibc.so.0"
#define BIONIC_DYNAMIC_LINKER "/system/bin/linker"
#define BIONIC_DYNAMIC_LINKER32 "/system/bin/linker"
#define BIONIC_DYNAMIC_LINKER64 "/system/bin/linker64"
#define BIONIC_DYNAMIC_LINKERX32 "/system/bin/linkerx32"
/* Should be redefined for each target that supports musl.  */
#define MUSL_DYNAMIC_LINKER "/dev/null"
#define MUSL_DYNAMIC_LINKER32 "/dev/null"
#define MUSL_DYNAMIC_LINKER64 "/dev/null"
#define MUSL_DYNAMIC_LINKERX32 "/dev/null"

#define GNU_USER_DYNAMIC_LINKER						\
  CHOOSE_DYNAMIC_LINKER (GLIBC_DYNAMIC_LINKER, UCLIBC_DYNAMIC_LINKER,	\
			 BIONIC_DYNAMIC_LINKER, MUSL_DYNAMIC_LINKER)
#define GNU_USER_DYNAMIC_LINKER32					\
  CHOOSE_DYNAMIC_LINKER (GLIBC_DYNAMIC_LINKER32, UCLIBC_DYNAMIC_LINKER32, \
			 BIONIC_DYNAMIC_LINKER32, MUSL_DYNAMIC_LINKER32)
#define GNU_USER_DYNAMIC_LINKER64					\
  CHOOSE_DYNAMIC_LINKER (GLIBC_DYNAMIC_LINKER64, UCLIBC_DYNAMIC_LINKER64, \
			 BIONIC_DYNAMIC_LINKER64, MUSL_DYNAMIC_LINKER64)
#define GNU_USER_DYNAMIC_LINKERX32					\
  CHOOSE_DYNAMIC_LINKER (GLIBC_DYNAMIC_LINKERX32, UCLIBC_DYNAMIC_LINKERX32, \
			 BIONIC_DYNAMIC_LINKERX32, MUSL_DYNAMIC_LINKERX32)


/* Whether we have Bionic libc runtime */
#undef TARGET_HAS_BIONIC
#define TARGET_HAS_BIONIC (OPTION_BIONIC)

/* musl avoids problematic includes by rearranging the include directories.
 * Unfortunately, this is mostly duplicated from cppdefault.c */
#if DEFAULT_LIBC == LIBC_MUSL
#define INCLUDE_DEFAULTS_MUSL_GPP			\
    { GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1,		\
      GPLUSPLUS_INCLUDE_DIR_ADD_SYSROOT, 0 },		\
    { GPLUSPLUS_TOOL_INCLUDE_DIR, "G++", 1, 1,		\
      GPLUSPLUS_INCLUDE_DIR_ADD_SYSROOT, 1 },		\
    { GPLUSPLUS_BACKWARD_INCLUDE_DIR, "G++", 1, 1,	\
      GPLUSPLUS_INCLUDE_DIR_ADD_SYSROOT, 0 },

#ifdef LOCAL_INCLUDE_DIR
#define INCLUDE_DEFAULTS_MUSL_LOCAL			\
    { LOCAL_INCLUDE_DIR, 0, 0, 1, 1, 2 },		\
    { LOCAL_INCLUDE_DIR, 0, 0, 1, 1, 0 },
#else
#define INCLUDE_DEFAULTS_MUSL_LOCAL
#endif

#ifdef PREFIX_INCLUDE_DIR
#define INCLUDE_DEFAULTS_MUSL_PREFIX			\
    { PREFIX_INCLUDE_DIR, 0, 0, 1, 0, 0},
#else
#define INCLUDE_DEFAULTS_MUSL_PREFIX
#endif

#ifdef CROSS_INCLUDE_DIR
#define INCLUDE_DEFAULTS_MUSL_CROSS			\
    { CROSS_INCLUDE_DIR, "GCC", 0, 0, 0, 0},
#else
#define INCLUDE_DEFAULTS_MUSL_CROSS
#endif

#ifdef TOOL_INCLUDE_DIR
#define INCLUDE_DEFAULTS_MUSL_TOOL			\
    { TOOL_INCLUDE_DIR, "BINUTILS", 0, 1, 0, 0},
#else
#define INCLUDE_DEFAULTS_MUSL_TOOL
#endif

#ifdef NATIVE_SYSTEM_HEADER_DIR
#define INCLUDE_DEFAULTS_MUSL_NATIVE			\
    { NATIVE_SYSTEM_HEADER_DIR, 0, 0, 0, 1, 2 },	\
    { NATIVE_SYSTEM_HEADER_DIR, 0, 0, 0, 1, 0 },
#else
#define INCLUDE_DEFAULTS_MUSL_NATIVE
#endif

#if defined (CROSS_DIRECTORY_STRUCTURE) && !defined (TARGET_SYSTEM_ROOT)
# undef INCLUDE_DEFAULTS_MUSL_LOCAL
# define INCLUDE_DEFAULTS_MUSL_LOCAL
# undef INCLUDE_DEFAULTS_MUSL_NATIVE
# define INCLUDE_DEFAULTS_MUSL_NATIVE
#else
# undef INCLUDE_DEFAULTS_MUSL_CROSS
# define INCLUDE_DEFAULTS_MUSL_CROSS
#endif

#undef INCLUDE_DEFAULTS
#define INCLUDE_DEFAULTS				\
  {							\
    INCLUDE_DEFAULTS_MUSL_GPP				\
    INCLUDE_DEFAULTS_MUSL_LOCAL				\
    INCLUDE_DEFAULTS_MUSL_PREFIX			\
    INCLUDE_DEFAULTS_MUSL_CROSS				\
    INCLUDE_DEFAULTS_MUSL_TOOL				\
    INCLUDE_DEFAULTS_MUSL_NATIVE			\
    { GCC_INCLUDE_DIR, "GCC", 0, 1, 0, 0 },		\
    { 0, 0, 0, 0, 0, 0 }				\
  }
#endif
