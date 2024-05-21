cmake_minimum_required(VERSION 3.10)

project(BubbleSort)

set(CMAKE_CXX_STANDARD 14)

# Adaugă sursele programului
add_executable(main src/main.cpp)

# Include GoogleTest framework
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Adaugă testele
add_executable(bubble_sort_test bubble_sort_test.cpp)

target_link_libraries(bubble_sort_test gtest_main)

include(GoogleTest)
gtest_discover_tests(bubble_sort_test)
