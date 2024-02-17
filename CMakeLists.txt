cmake_minimum_required(VERSION 3.12)  # Specify the minimum CMake version required

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(MyProject)  # Set the project name

#include_directories(${CMAKE_SOURCE_DIR}/src)

# Add any additional source files or libraries if needed
# For example:
#add_library(PTPLibrary src/FileMergeManager.cpp 
#                      src/FileReader.cpp
#                      src/FileWriter.cpp
#                      )

# Add the executable target
#add_executable(FileMerger src/Main.cpp)
#target_link_libraries(FileMerger PTPLibrary)

find_package(benchmark REQUIRED)

# Add the executable target
add_executable(CacheBenchmark 
                    benchmark/cachebench.cpp)
target_link_libraries(CacheBenchmark benchmark::benchmark)

# Find the Google Test package
#find_package(GTest REQUIRED)

# Include Google Test headers
#include_directories(${GTEST_INCLUDE_DIRS})

# Add unit FileMergerTest executable

# Link any libraries if necessary
# For example:
# target_link_libraries(FileMerger PRIVATE PTPLibrary)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#enable_testing()

# Add the FileMergerTest case(s)
#add_test(NAME FileMergerTestCase COMMAND FileMergerTest)

