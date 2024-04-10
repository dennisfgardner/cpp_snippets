cmake_minimum_required(VERSION 3.20)

project(MyApp VERSION $ENV{CXX_SNIPPETS_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# main
add_executable(main ./src/main.cpp)
target_compile_options(main PRIVATE -Wall -Wextra -Wshadow -Wconversion -Wpedantic -Werror)
target_include_directories(main PRIVATE ./include)

# unit testing
find_package(Catch2 REQUIRED)
add_executable(unit_tests ./test/test.cpp ./src/main.cpp)
target_compile_definitions(unit_tests PRIVATE UNIT_TESTING)
target_include_directories(unit_tests PRIVATE ./include)
target_link_libraries(unit_tests Catch2::Catch2)
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)