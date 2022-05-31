# Build LLVM w/ Sim backend
```bash
cmake \ 
-S ../llvm/ \
-B ../build_optimal/ \
-DLLVM_ENABLE_PROJECTS="clang" \
-DCMAKE_INSTALL_PREFIX=./build_install/ \
-DCMAKE_BUILD_TYPE=Release \
-DLLVM_ENABLE_ASSERTIONS=On \
-DLLVM_TARGETS_TO_BUILD=X86 \
-DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=Sim \
-DLLVM_INCLUDE_TESTS=OFF \
-DLLVM_INCLUDE_EXAMPLES=OFF \
../ \
```

# Usage
```bash
# in llvm-project dir:
export PATH_TO_LLVM_BUILD=<build_dir>
./compile_convert.sh tests/main.c
./compile_convert.sh tests/main2.c
# then copy to clipboard -> CPU
```

