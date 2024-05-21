cmake_minimum_required(VERSION 3.10)

# Proiectul tău
project(SelectionSort)

# Adaugă GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
# Include GoogleTest în build
FetchContent_MakeAvailable(googletest)

# Standardul C++ necesar
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adaugă sursele și executabilul pentru sortarea prin selecție
add_executable(main src/main.h)

# Adaugă sursele și executabilul pentru testele tale
add_executable(selection_sort_test selection_sort_test.cpp src/selection_sort.cpp)

# Link testele cu GoogleTest
target_link_libraries(selection_sort_test gtest_main)

# Activează testele
include(GoogleTest)
gtest_discover_tests(selection_sort_test)
