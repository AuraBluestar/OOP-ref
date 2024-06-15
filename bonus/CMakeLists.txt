cmake_minimum_required(VERSION 3.14)
project(bonus)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GOOGLETEST_DIR "F:/Facultate/OOP-ref/bonus/external/googletest-1.14.0/googletest-1.14.0")

add_subdirectory(${GOOGLETEST_DIR} googletest)
include_directories(${PROJECT_SOURCE_DIR}/include)

include(GoogleTest)

enable_testing()

# Deque Test
add_executable(Deque_TEST tests/Deque_TEST.cc)
target_link_libraries(Deque_TEST gtest_main)
gtest_discover_tests(Deque_TEST)

# Map Test
add_executable(Map_TEST tests/Map_TEST.cc)
target_link_libraries(Map_TEST gtest_main)
gtest_discover_tests(Map_TEST)

# Set Test
add_executable(Set_TEST tests/Set_TEST.cc)
target_link_libraries(Set_TEST gtest_main)
gtest_discover_tests(Set_TEST)

# Stack Test
add_executable(Stack_TEST tests/Stack_TEST.cc)
target_link_libraries(Stack_TEST gtest_main)
gtest_discover_tests(Stack_TEST)

# Vector Test
add_executable(Vector_TEST tests/Vector_TEST.cc)
target_link_libraries(Vector_TEST gtest_main)
gtest_discover_tests(Vector_TEST)
