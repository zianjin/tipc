#!/usr/bin/env bash
set -e

# Empty the build folder
rm -rf build
mkdir build

# Enter the build and rebuild
cd build
cmake ..
make -j4
