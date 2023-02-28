set(CMAKE_SYSTEM_NAME HongMeng)

set(HMSDKVERSION 0 CACHE STRING "SDK version")
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(ARCH aarch64 CACHE STRING "Architecture")
set(SUBARCH "" CACHE STRING "Endianness")
set(CMAKE_SYSTEM_VERSION ${HMSDKVERSION} CACHE STRING "System version")

# Set --sysroot option.
# Normally the toolchain file should resides in SYSROOT/usr/share/cmake/Modules/Toolchains/
get_filename_component(GUESS_SYSROOT "${CMAKE_CURRENT_LIST_DIR}/../../../../../" ABSOLUTE)
set(CMAKE_SYSROOT ${GUESS_SYSROOT})

# Default compiler name and cflags
set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc CACHE STRING "Cross C compiler")
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER} CACHE STRING "Cross ASM compiler")
set(CMAKE_LINKER ${CMAKE_C_COMPILER} CACHE STRING "Cross linker")
set(CMAKE_C_FLAGS "\
-pipe \
-march=armv8-a -mlittle-endian \
" CACHE STRING "CFLAGS")
set(CMAKE_EXE_LINKER_FLAGS "\
-nostdlib \
-Wl,-O1,--hash-style=gnu,--as-needed \
" CACHE STRING "ELF LDFLAGS")
set(CMAKE_SHARED_LINKER_FLAGS "\
-Wl,-O1,--hash-style=gnu,--as-needed \
" CACHE STRING "Shared library LDFLAGS")

# Compatibility, not used by HongMengCommon
set(CROSS_COMPILE "aarch64-linux-gnu-" CACHE STRING "Cross compiler prefix")
