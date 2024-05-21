cmake_minimum_required(VERSION 3.10)
project(SelectionSort)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Add executable for tests
add_executable(tests selection_sort_test.cpp)

# Link tests with Google Test
target_link_libraries(tests gtest)

# Enable testing
include(GoogleTest)
gtest_discover_tests(tests)
