# Set the path to the Google Test framework
set(GTEST_ROOT "C:/Users/mirel/OneDrive/Desktop/FACULTATE/OOP/git/OOP-ref/bonus/googletest")

# Find Google Test framework
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add your test executables
add_executable(runTests Vector_TEST.cpp Deque_TEST.cpp Stack_TEST.cpp Map_TEST.cpp)

# Link Google Test framework libraries
target_link_libraries(runTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

# Specificarea locației Google Test în CMakeLists.txt din tests
set(GTEST_ROOT "C:/Users/mirel/OneDrive/Desktop/FACULTATE/OOP/git/OOP-ref/bonus/googletest")

# Găsirea pachetului Google Test
find_package(GTest REQUIRED)

# Include directoarele Google Test
include_directories(${GTEST_INCLUDE_DIRS})

# Adăugarea executabilului de teste
add_executable(runTests Deque_TEST.cpp)

# Legarea executabilului de teste cu Google Test
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
