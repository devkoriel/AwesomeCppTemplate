# AwesomeCppTemplate

> This project is in its infancy and I plan to continue to improve. It is designed to use C++17. I hope people be able to create the desired C++ project structure with Batch or Shell Script later. and also very welcome to the contribution.

There a lot of useful opinions that I have to look at in Reddit thread for this project.
The link is [here](https://www.reddit.com/r/cpp/comments/b1u9fp/i_created_c17_cmake_conan_ninja_project_template/).

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

To add the apt repo, find the appropriate one for your Ubuntu version below and append it to `/etc/apt/sources.list`
```
Trusty (14.04) - Last update : Tue, 26 Feb 2019 05:42:37 UTC / Revision: 354792
deb http://apt.llvm.org/trusty/ llvm-toolchain-trusty main
deb-src http://apt.llvm.org/trusty/ llvm-toolchain-trusty main
# 7 
deb http://apt.llvm.org/trusty/ llvm-toolchain-trusty-7 main
deb-src http://apt.llvm.org/trusty/ llvm-toolchain-trusty-7 main
# 8 
deb http://apt.llvm.org/trusty/ llvm-toolchain-trusty-8 main
deb-src http://apt.llvm.org/trusty/ llvm-toolchain-trusty-8 main

# Also add the following for the appropriate libstdc++
deb http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu trusty main
Xenial (16.04) - Last update : Thu, 14 Mar 2019 00:31:13 UTC / Revision: 356003
deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial main
deb-src http://apt.llvm.org/xenial/ llvm-toolchain-xenial main
# 7
deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-7 main
deb-src http://apt.llvm.org/xenial/ llvm-toolchain-xenial-7 main
# 8
deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-8 main
deb-src http://apt.llvm.org/xenial/ llvm-toolchain-xenial-8 main
Bionic (18.04) - Last update : Thu, 14 Mar 2019 03:23:34 UTC / Revision: 356096
# i386 not available
deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic main
deb-src http://apt.llvm.org/bionic/ llvm-toolchain-bionic main
# 7
deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-7 main
deb-src http://apt.llvm.org/bionic/ llvm-toolchain-bionic-7 main
# 8
deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-8 main
deb-src http://apt.llvm.org/bionic/ llvm-toolchain-bionic-8 main
Cosmic (18.10) - Last update : Wed, 13 Mar 2019 12:53:46 UTC / Revision: 356030
# i386 not available
deb http://apt.llvm.org/cosmic/ llvm-toolchain-cosmic main
deb-src http://apt.llvm.org/cosmic/ llvm-toolchain-cosmic main
# 7
deb http://apt.llvm.org/cosmic/ llvm-toolchain-cosmic-7 main
deb-src http://apt.llvm.org/cosmic/ llvm-toolchain-cosmic-7 main
# 8
deb http://apt.llvm.org/cosmic/ llvm-toolchain-cosmic-8 main
deb-src http://apt.llvm.org/cosmic/ llvm-toolchain-cosmic-8 main
Disco (19.04) - Last update : Wed, 13 Mar 2019 12:42:07 UTC / Revision: 356006
# i386 not available
deb http://apt.llvm.org/disco/ llvm-toolchain-disco main
deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco main
# 7
deb http://apt.llvm.org/disco/ llvm-toolchain-disco-7 main
deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco-7 main
# 8
deb http://apt.llvm.org/disco/ llvm-toolchain-disco-8 main
deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco-8 main
```

Update apt packages list:
```shell
$ sudo apt update
```

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
