#!/bin/bash

# Clean the build directory if it exists
if [ -d "build" ]; then
    rm -r build
fi

# Create a build directory
mkdir build
cd build

# Generate the build files using CMake
cmake ..

# Build the project
cmake --build .

# Run the tests using ctest
#ctest


#../build/FileMergerTest

