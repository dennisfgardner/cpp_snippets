# C++ Snippets

## Docker

Build an image with:

```bash
export CXX_SNIPPETS_VERSION=0.0.5
docker build --build-arg CXX_SNIPPETS_VERSION=$CXX_SNIPPETS_VERSION -t cpp_snippets:$CXX_SNIPPETS_VERSION .
```

Run container interactively and mount files with:

```bash
docker run -itv $PWD:/home cpp_snippets:$CXX_SNIPPETS_VERSION
```

## Documentation

Generate documentation in a ./docs directory with the following command:

```bash
doxygen Doxyfile
```

## Build

```bash
cmake -S . -B ./build
cmake --build ./build
ctest --output-on-failure --test-dir ./build/
./build/bin/main ./test/data/
```

## Static Analysis

Cpp Check

```bash
cppcheck --enable=all --std=c++20 --suppress=missingIncludeSystem ./src/* ./test/test.cpp -I./include
```

```bash
clang-tidy -p ./build -header-filter=.* ./src/* ./test/test.cpp -extra-arg=-std=c++20 -- -I./include
```

## Memory Leak Check

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./build/bin/main ./test/data/
```

## TODO

- I need to be able to parse the data file names.
- I need to be able to take the average of all the frames.
- I need to be able to point to data and background directories.
- I eventually need a single diffraction pattern that is high-dynamic range and
    background subtracted.

I think I can create an input data handler.
It will have a have getters for the following:

- background subtracted high-dynamic-range diffraction pattern
- scan positions in meters

Ideas on how to parse the file, all inside the input data handler

There will be a structure that holds:

- prefix
- xpos
- ypos
- exposure time
- frame number

I can create a set of exposure times. Then loop through the exposure times to
average the frames. I can check to make sure the frame numbers for each expsosure time
are unique and monotoncally increase.

I think the high dynamic range algo worked as follows. A mask is created that selects pixels above a
threshold (like 200 if the camera max is 255). Values above the threshold will be replaced with the
the next shorter exposured time. The mask is created first. Then the intensities are divided by the
exposure time.

Before doing the HDR (high-dynamcic range algo) the images need to be background substracted. Any values
less than zero should be set to zero.

I can make the HDR algo a friend of the input data handler class. That way I can test it on it's own.

I will need to keep track of the max and min pixel values of the image to I can figure out the
dynamic range.

I also need to read one of the files to figure out the rows and cols.

I will need a csv reader. This can be a friend class. This can be a template
