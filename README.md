# AwesomeCppTemplate

## Suggestion of C++ programming environment

I suggest using as much cross-platform open-source software as possible:

- build system generator: CMake
- build system: Ninja
- compiler: clang++
- IDE:
  - Visual Studio Code
  - ⁠Qt Creator
- static code analyzers:
  - clang-tidy
  - Cppcheck
  - Clazy
- source code formatter: clang-format
- documentation generator: Doxygen
- package manager:
  - ⁠Conan
  - ⁠vcpkg
- libraries:
  - Standard Library
  - Boost
  - string formatting: fmt
  - logging: spdlog
  - automated tests: Google Test / Google Mock
  - GUI: Qt

## Prerequisites

### Ubuntu
---

1. Update and upgrade packages

```shell
$ sudo apt update && sudo apt upgrade -y
```

2. Install Clang and LLVM (7 release)

To retrieve the archive signature:
```shell
$ wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|sudo apt-key add -
# Fingerprint: 6084 F3CF 814B 57C1 CF12 EFD5 15CF 4D18 AF4F 7421
```

To install just clang, lld and lldb:
```shell
$ sudo apt install clang-7 lldb-7 lld-7
```

To install all key packages:
```shell
# LLVM
$ sudo apt install libllvm-7-ocaml-dev libllvm7 llvm-7 llvm-7-dev llvm-7-doc llvm-7-examples llvm-7-runtime

# Clang and co
$ sudo apt install clang-7 clang-tools-7 clang-7-doc libclang-common-7-dev libclang-7-dev libclang1-7 clang-format-7 python-clang-7

# libfuzzer
$ sudo apt install libfuzzer-7-dev

# lldb
$ sudo apt install lldb-7

# lld (linker)
$ sudo apt install lld-7

# libc++
$ sudo apt install libc++-7-dev libc++abi-7-dev

# OpenMP
$ sudo apt install libomp-7-dev
```

Finally, link each `clang-7` and `clang++-7` to `clang` and `clang++`.
```shell
$ sudo ln -s /usr/bin/clang-7 /usr/bin/clang
$ sudo ln -s /usr/bin/clang++-7 /usr/bin/clang++
```

Check if all the packages are installed fine.
```shell
$ clang++ --version
clang version 7.0.0-3~ubuntu0.18.04.1 (tags/RELEASE_700/final)
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

3. Install CMake

```shell
$ sudo apt install cmake
```

4. Install Conan

```shell
$ sudo apt install python3
$ sudo apt install python3-pip
$ sudo pip3 install --upgrade pip
$ pip install conan
```
Then change default profile of conan:
```shell
$ conan profile new default --detect
$ conan profile update settings.compiler=clang++
$ conan profile update settings.compiler.version=7.0
$ conan profile update settings.compiler.libcxx=libc++
```

5. Install Ninja

```shell
$ sudo apt install ninja-build
```

## Build examples

```shell
$ mkdir build && cd build
$ conan install ..
$ export CC=clang
$ export CXX=clang++
$ cmake .. -G Ninja
$ cmake --build .
```

Try running the example binary!

```shell
$ ./bin/md5
c3fcd3d76192e4007dfb496cca67e13b
```
