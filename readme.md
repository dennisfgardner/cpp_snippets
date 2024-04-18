# C++ Snippets

## Docker

Build an image with:

```bash
export CXX_SNIPPETS_VERSION=0.0.3
docker build --build-arg CXX_SNIPPETS_VERSION=$CXX_SNIPPETS_VERSION -t cpp_snippets:$CXX_SNIPPETS_VERSION .
```

Run container interactively and mount files with:

```bash
docker run -itv $PWD:/home cpp_snippets:$CXX_SNIPPETS_VERSION
```

## Build

```bash
cmake -S . -B ./build
cmake --build ./build
ctest --test-dir ./build/
./build/bin/main
```

## Static Analysis

Cpp Check

```bash
cppcheck --enable=all --std=c++17 --suppress=missingIncludeSystem ./src/* -I./include
```

```bash
clang-tidy -p ./build -header-filter=.* ./src/* -extra-arg=-std=c++17 -- -I./include
```

## Memory Leak Check

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./build/bin/main
```
