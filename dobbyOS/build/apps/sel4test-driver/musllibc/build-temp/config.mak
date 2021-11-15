# This version of config.mak was generated by:
# /host/projects/musllibc/configure --srcdir=/host/projects/musllibc --prefix=/host/build/apps/sel4test-driver/musllibc/build-temp/stage --target=riscv --enable-warnings --disable-shared --enable-static
# Any changes made here will be lost if configure is re-run
ARCH = riscv_sel4
SUBARCH = 
ASMSUBARCH = 
srcdir = /host/projects/musllibc
prefix = /host/build/apps/sel4test-driver/musllibc/build-temp/stage
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
libdir = $(prefix)/lib
includedir = $(prefix)/include
syslibdir = /lib
CC = /opt/riscv/bin/riscv64-unknown-linux-gnu-gcc
CFLAGS = -nostdinc -fno-pic -fno-pie -fno-stack-protector -fno-asynchronous-unwind-tables -ftls-model=local-exec -march=rv64imac -mabi=lp64 -D__KERNEL_64__ 
CFLAGS_AUTO = -Os -pipe -fomit-frame-pointer -fno-unwind-tables -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections -Werror=implicit-function-declaration -Werror=implicit-int -Werror=pointer-sign -Werror=pointer-arith -Wall -Wno-parentheses -Wno-uninitialized -Wno-missing-braces -Wno-unused-value -Wno-unused-but-set-variable -Wno-unknown-pragmas -Wno-pointer-to-int-cast -include vis.h
CFLAGS_C99FSE = -std=c99 -nostdinc -ffreestanding -fexcess-precision=standard -frounding-math -Wa,--noexecstack
CFLAGS_MEMOPS = -fno-tree-loop-distribute-patterns
CFLAGS_NOSSP = -fno-stack-protector
CPPFLAGS = 
LDFLAGS = 
LDFLAGS_AUTO = -Wl,--sort-section,alignment -Wl,--sort-common -Wl,--gc-sections -Wl,--hash-style=both -Wl,--no-undefined -Wl,--exclude-libs=ALL -Wl,-Bsymbolic-functions
CROSS_COMPILE = riscv64-unknown-linux-gnu-
LIBCC = -lgcc -lgcc_eh
OPTIMIZE_GLOBS = internal/*.c malloc/*.c string/*.c
ALL_TOOLS =  obj/musl-gcc
TOOL_LIBS =  lib/musl-gcc.specs
ADD_CFI = no
SHARED_LIBS =
WRAPCC_GCC = $(CC)
