#!/bin/bash
if ! [ $PATH_TO_LLVM_BUILD ]; then echo "use: export \$PATH_TO_LLVM_BUILD=<llvm_build>"; exit 1; fi
if ! [ $1 ]; then echo "no input \*.c file" ; exit 1; fi

set -x
$PATH_TO_LLVM_BUILD/bin/clang -target sim -S $1 -o $1.s && \
./strip.py $1.s