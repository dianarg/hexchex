cmake_minimum_required(VERSION 2.8.2)
# silence warning about project version
if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif(POLICY CMP0048)

## PROJECT SETTINGS
project (HexChex VERSION 0.1.0)
include_directories (include)

# Require C++11
set (CMAKE_CXX_STANDARD 11)

## LIBRARY
file(GLOB_RECURSE LIB_SOURCES src/*.cpp)
list(REMOVE_ITEM LIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

## MAIN PROGRAM
add_executable(hexchex ${LIB_SOURCES} src/main.cpp)

## TESTS
file(GLOB_RECURSE TEST_SOURCES test/*.cpp)
add_executable(unit_test ${TEST_SOURCES} ${LIB_SOURCES})

# Use built-in main from googletest for unit tests
target_link_libraries(unit_test gtest_main)

# Enable `make test`
enable_testing()

# separate tests for each module
add_test (NAME PointTest COMMAND unit_test --gtest_filter=PointTest*)
add_test (NAME HexCornerTest COMMAND unit_test --gtest_filter=HexCornerTest*)
add_test (NAME AxialTest COMMAND unit_test --gtest_filter=AxialTest*)

# add `make check` target with more output
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)

####
## Setup to use googletest
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(WARNING "Build step for googletest failed: ${result}")
endif()
# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)
# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()
## End of googletest setup
####
