cmake_minimum_required(VERSION 3.10)
project(drosrok)

set(CMAKE_CXX_STANDARD 23)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

# Main executable
add_executable(drosrok ${SRC_DIR}/main.cpp ${SRC_DIR}/alphabet.cpp)
target_include_directories(drosrok PRIVATE ${INCLUDE_DIR})

# GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Collect all test source files
file(GLOB TEST_SOURCES ${TEST_DIR}/*.cpp)

# Test executable
add_executable(tests ${TEST_SOURCES} ${SRC_DIR}/alphabet.cpp)
target_include_directories(tests PRIVATE ${INCLUDE_DIR})
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

# Test target
enable_testing()
add_test(NAME AllTests COMMAND tests)
