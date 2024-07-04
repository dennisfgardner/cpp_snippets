cmake_minimum_required(VERSION 3.20)

project(MyApp VERSION $ENV{CXX_SNIPPETS_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
    -Wall
    -Wextra
    -Wshadow
    -Wnon-virtual-dtor
    -Wconversion
    -Wpedantic
    -pedantic
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wsign-conversion
    -Wmisleading-indentation
    -Wduplicated-cond
    -Wduplicated-branches
    -Wlogical-op
    -Wnull-dereference
    -Wuseless-cast
    -Wdouble-promotion
    -Wformat=2
    -Wimplicit-fallthrough
    -Weffc++
    -Werror
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# external software
find_package( OpenCV REQUIRED )

# utilities library
add_library(utilities ./src/utilities.cpp)
target_include_directories(utilities PRIVATE ./include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(utilities ${OpenCV_LIBS})


# InputDataHandler library
add_library(InputDataHandler ./src/InputDataHandler.cpp)
target_include_directories(InputDataHandler PRIVATE ./include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(InputDataHandler utilities ${OpenCV_LIBS})

# main
add_executable(main ./src/main.cpp)
target_include_directories(main PRIVATE ./include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(main utilities InputDataHandler ${OpenCV_LIBS})

# unit testing
find_package(Catch2 REQUIRED)
add_executable(unit_tests ./test/test_main.cpp ./test/test_utilities.cpp ./test/test_InputDataHandler.cpp)
target_include_directories(unit_tests PRIVATE ./include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(unit_tests Catch2::Catch2 utilities InputDataHandler ${OpenCV_LIBS})
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)