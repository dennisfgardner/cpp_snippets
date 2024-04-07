# C++ Snippets

## Docker

Build an image with:

```bash
docker build -t cpp_snippets:0.0.1 .
```

Run container interactively and mount files with:

```bash
docker run -itv $PWD:/home cpp_snippets:0.0.1
```

## Build

```bash
cd /home
cmake -S . -B ./build
cmake --build ./build
ctest --test-dir ./build/
```

## Static Analysis

Cpp Check

```bash
cppcheck --enable=all --std=c++17 --suppress=missingIncludeSystem ./src/main.cpp -I ./include/
```

```bash
clang-tidy -p ./build -header-filter=.* ./src/main.cpp -extra-arg=-std=c++17
```

## Memory Leak Check

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./build/bin/main
```
