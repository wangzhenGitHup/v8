set(CMAKE_SYSTEM_NAME HongMeng)

set(HMSDKVERSION 0 CACHE STRING "SDK version")
set(CMAKE_SYSTEM_PROCESSOR armeb)
set(ARCH arm CACHE STRING "Architecture")
set(SUBARCH "be" CACHE STRING "Endianness")
set(CMAKE_SYSTEM_VERSION ${HMSDKVERSION} CACHE STRING "System version")

# Set --sysroot option.
# Normally the toolchain file should resides in SYSROOT/usr/share/cmake/Modules/Toolchains/
get_filename_component(GUESS_SYSROOT "${CMAKE_CURRENT_LIST_DIR}/../../../../../" ABSOLUTE)
set(CMAKE_SYSROOT ${GUESS_SYSROOT})

# Default compiler name and cflags
set(CMAKE_C_COMPILER armeb-eabi-gcc CACHE STRING "Cross C compiler")
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER} CACHE STRING "Cross ASM compiler")
set(CMAKE_LINKER ${CMAKE_C_COMPILER} CACHE STRING "Cross linker")
set(CMAKE_C_FLAGS "\
-pipe \
-march=armv7-a -mcpu=cortex-a9 -Wa,-march=armv7-a -marm -mbig-endian \
-D__HM_ARM_ARCH__=7 \
" CACHE STRING "CFLAGS")
set(CMAKE_EXE_LINKER_FLAGS "\
-nostdlib -Wl,-EB,--be8 \
-Wl,-O1,--hash-style=gnu,--as-needed \
" CACHE STRING "ELF LDFLAGS")
set(CMAKE_SHARED_LINKER_FLAGS "\
-Wl,-EB,--be8 \
-Wl,-O1,--hash-style=gnu,--as-needed \
" CACHE STRING "Shared library LDFLAGS")

# Compatibility, not used by HongMengCommon
set(CROSS_COMPILE "armeb-eabi-" CACHE STRING "Cross compiler prefix")
