#!/bin/bash

# Create a build directory if it doesn't exist
mkdir -p build
cd build

# Run CMake to configure the project
cmake ..

# Build the project
make

# Copy resources
cp -r ../memogeister_rep/resources/ ./bin/

# Run the game
./bin/MEMOGEISTER