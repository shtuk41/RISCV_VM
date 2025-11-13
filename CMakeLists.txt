cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(CMAKE_CXX_STANDARD 17)

# Build source as a library
add_library(mycode src/instructions.cpp)
target_include_directories(mycode PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Add GoogleTest
add_subdirectory(external/googletest)
include_directories(external/googletest/include)

# Build test executable
add_executable(tests tests/test_main.cpp)
target_link_libraries(tests mycode gtest gtest_main pthread)

# Ensure tests see headers
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

enable_testing()
add_test(NAME all_tests COMMAND tests)