cmake_minimum_required(VERSION 3.10)
project(BONUS)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include GoogleTest
add_subdirectory(googletest)

# Add directories containing source code and tests
add_subdirectory(src)
add_subdirectory(tests)
