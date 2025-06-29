#!/usr/bin/env sh

set -xe

# Ensure build dir
mkdir -p ../../build

# cd build dir and push onto stack
pushd ../../build

# Generate Makefile
cmake ../

# Make exe
make

# Run exe
./handmadehero

# Return to original dir before pushing current onto stack
popd
