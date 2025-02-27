# Risky OS

A simple operating system that I am developing for fun and learning purposes.
It is based on RISC-V 32 architecture and is written in C and Assembly.

## Getting Started

To build the project you need to have the following tools installed:

- [Bash](https://www.gnu.org/software/bash/)
- [Tar](https://www.gnu.org/software/tar/)
- [Clang](https://clang.llvm.org/)
- [LLD](https://lld.llvm.org/)
- [LLVM](https://llvm.org/)
- [QEMU](https://www.qemu.org/)

on macOS you can install the tools using [Homebrew](https://brew.sh/):

```bash
brew install llvm lld qemu
```

## Run

```bash
./run.sh
```

## Progress

Currently, the OS is able to boot and print a message to the screen.

- [x] Kernel
- [x] Bootloader
- [ ] Memory Management
- [ ] File System
- [ ] User Space
- [ ] Shell
- [ ] Drivers
