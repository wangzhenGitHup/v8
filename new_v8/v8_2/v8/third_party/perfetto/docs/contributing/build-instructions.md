# Perfetto build instructions

The source of truth for the Perfetto codebase lives in AOSP:
https://android.googlesource.com/platform/external/perfetto/

A read-only mirror is also available at https://github.com/google/perfetto .

Perfetto can be built both from the Android tree (AOSP) and standalone.
Standalone builds are meant only for local testing and are not shipped.
Due to the reduced dependencies they are faster to iterate on and the
suggested way to work on Perfetto.

## Get the code

**Standalone checkout**:

```bash
git clone https://android.googlesource.com/platform/external/perfetto/
```

**Android tree**:

Perfetto lives in [`external/perfetto` in the AOSP tree](https://cs.android.com/android/platform/superproject/+/master:external/perfetto/).

## Prerequisites

**Standalone checkout**:

All dependent libraries are self-hosted and pulled through:

```bash
tools/install-build-deps [--android] [--ui]
```

**Android tree**:

See https://source.android.com/setup

## Building

**Standalone checkout**:

If you are a chromium developer and have depot_tools installed you can avoid
the `tools/` prefix below and just use gn/ninja from depot_tools.

`$ tools/gn args out/android` to generate build files and enter in the editor:

```python
target_os = "android"                 # Only when building for Android
target_cpu = "arm" / "arm64" / "x64"
is_debug = true / false
cc_wrapper = "ccache"                 # Optionally speed repeated builds with ccache
```

(See the [Build Configurations](#build-configurations) section below for more)

```bash
tools/ninja -C out/android
```

**Android tree**

`mmma external/perfetto`
or
`m perfetto traced traced_probes`

This will generate artifacts `out/target/product/XXX/system/`.
Executables and shared libraries are stripped by default by the Android build
system. The unstripped artifacts are kept into `out/target/product/XXX/symbols`.

## UI development

This command pulls the UI-related dependencies (notably, the NodeJS binary)
and installs the `node_modules` in `ui/node_modules`:

```bash
tools/install-build-deps --ui
```

Build the UI:

```bash
gn args out/default  # The only relevant arg is is_debug=true|false

# This will generate the static content for serving the UI in out/default/ui/.
tools/ninja -C out/default ui
```

Test your changes on a local server using:

```bash
ui/run-dev-server out/default
```

Navigate to http://localhost:10000/ to see the changes.

## IDE setup

Use a following command in the checkout directory in order to generate the
compilation database file:

```bash
tools/ninja -C out/default -t compdb cc cxx > compile_commands.json
```

After generating, it can be used in CLion (File -> Open -> Open As Project),
Visual Studio Code with C/C++ extension and any other tool and editor that
supports the compilation database format.

## Build files

The source of truth of our build file is in the BUILD.gn files, which are based
on [GN][gn-quickstart].
The Android build file ([Android.bp](/Android.bp)) is autogenerated from the GN
files through `tools/gen_android_bp`, which needs to be invoked whenever a
change touches GN files or introduces new ones.

A presubmit check checks that the Android.bp is consistent with GN files when
submitting a CL through `git cl upload`.

The generator has a list of root targets that will be translated into the
Android.bp file. If you are adding a new target, add a new entry to the
`default_targets` variable in [`tools/gen_android_bp`](/tools/gen_android_bp).

## Supported platforms

**Linux desktop** (Debian Rodete)

- Hermetic clang + libcxx toolchain (both following chromium's revisions)
- GCC-7 and libstdc++ 6

**Android**

- Android's NDK r15c (using NDK's libcxx)
- AOSP's in-tree clang (using in-tree libcxx)

**Mac**

- XCode 9 / clang (currently maintained best-effort).

**Windows**

Windows builds are not currently supported when using the standalone checkout
and GN. Windows is supported only for a subset of the targets (mainly
`trace_processor` and the in-process version of the
[Tracing SDK](/docs/instrumentation/tracing-sdk.md)) in two ways:
(1) when building through Bazel; (2) when building as part of Chromium.

## Build configurations

TIP: `tools/build_all_configs.py` can be used to generate out/XXX folders for
most of the supported configurations.

The following [GN args][gn-quickstart] are supported:

`target_os = "android" | "linux" | "mac"`:

Defaults to the current host, set "android" to build for Android.

`target_cpu = "arm" | "arm64" | "x64"`

Defaults to `"arm"` when `target_os` == `"android"`, `"x64"` when targeting the
host. 32-bit host builds are not supported.
Note: x64 here really means x86_64. This is to keep it consistent with
Chromium's choice, which in turn follows Windows naming convention.

`is_debug = true | false`

Toggles Debug (default) / Release mode. This affects, among other things:
(i) the `-g` compiler flag; (ii) setting/unsetting `-DNDEBUG`; (iii) turning
on/off `DCHECK` and `DLOG`.
Note that debug builds of Perfetto are sensibly slower than release versions. We
strongly encourage using debug builds only for local development.

`is_clang = true | false`

Use Clang (default: true) or GCC (false).
On Linux, by default it uses the self-hosted clang (see `is_hermetic_clang`).
On Android, by default it uses clang from the NDK (in `buildtools/ndk`).
On Mac, by default it uses the system version of clang (requires Xcode).
See also the [custom toolchain](#custom-toolchain) section below.

`is_hermetic_clang = true | false`

Use bundled toolchain from `buildtools/` rather than system-wide one.

`cc = "gcc" / cxx = "g++"`

Uses a different compiler binary (default: autodetected depending on is_clang).
See also the [custom toolchain](#custom-toolchain) section below.

`cc_wrapper = "tool_name"`

Prepends all build commands with a wrapper command. Using `"ccache"` here
enables the [ccache](https://github.com/ccache/ccache) caching compiler,
which can considerably speed up repeat builds.

`is_asan = true`

Enables [Address Sanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer)

`is_lsan = true`

Enables [Leak Sanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizerLeakSanitizer)
(Linux/Mac only)

`is_msan = true`

Enables [Memory Sanitizer](https://github.com/google/sanitizers/wiki/MemorySanitizer)
(Linux only)

`is_tsan = true`

Enables [Thread Sanitizer](https://github.com/google/sanitizers/wiki/ThreadSanitizerCppManual)
(Linux/Mac only)

`is_ubsan = true`

Enables [Undefined Behavior Sanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)

### {#custom-toolchain} Using custom toolchains and CC / CXX / CFLAGS env vars

When building Perfetto as part of some other build environment it might be
necessary to switch off all the built-in toolchain-related path-guessing scripts
and manually specify the path of the toolchains.

```python
# Disable the scripts that guess the path of the toolchain.
is_system_compiler = true

ar = "/path/to/ar"
cc = "/path/to/gcc-like-compiler"
cxx = "/path/to/g++-like-compiler"
linker = ""  # This is passed to -fuse-ld=...
```

If you are using a build system that keeps the toolchain settings in
environment variables, you can set:

```python
is_system_compiler = true
ar="${AR}"
cc="${CC}"
cxx="${CXX}"
```

`is_system_compiler = true` can be used also for cross-compilation.
In case of cross-compilation, the GN variables have the following semantic:
`ar`, `cc`, `cxx`, `linker` refer to the _host_ toolchain (sometimes also called
_build_ toolchain). This toolchain is used to build: (i) auxiliary tools
(e.g. the `traceconv` conversion util) and (ii) executable artifacts that are
used during the rest of the build process for the target (e.g., the `protoc`
compiler or the `protozero_plugin` protoc compiler plugin).

The cross-toolchain used to build the artifacts that run on the device is
prefixed by `target_`: `target_ar`, `target_cc`, `target_cxx`, `target_linker`.

```python
# Cross compilation kicks in when at least one of these three variables is set
# to a value != than the host defaults.

target_cpu = "x86" | "x64" | "arm" | "arm64"
target_os = "linux" | "android"
target_triplet =  "arm-linux-gnueabi" | "x86_64-linux-gnu" | ...
```

When integrating with GNU Makefile cross-toolchains build environments, a
typical mapping of the corresponding environment variables is:

```python
ar="${BUILD_AR}"
cc="${BUILD_CC}"
cxx="${BUILD_CXX}"
target_ar="${AR}"
target_cc="${CC}"
target_cxx="${CXX}"
```

It is possible to extend the set of `CFLAGS` and `CXXFLAGS` through the
`extra_xxxflags` GN variables as follows. The extra flags are always appended
(hence, take precedence) to the set of flags that the GN build files generate.

```python
# These apply both to host and target toolchain.
extra_cflags="${CFLAGS}"
extra_cxxflags="${CXXFLAGS}"
extra_ldflags="${LDFLAGS}"

# These apply only to the host toolchain.
extra_host_cflags="${BUILD_CFLAGS}"
extra_host_cxxflags="${BUILD_CXXFLAGS}"
extra_host_ldflags="${BUILD_LDFLAGS}"

# These apply only to the target toolchain.
extra_target_cflags="${CFLAGS}"
extra_target_cxxflags="${CXXFLAGS} ${debug_flags}"
extra_target_ldflags="${LDFLAGS}"
```

[gn-quickstart]: https://gn.googlesource.com/gn/+/master/docs/quick_start.md