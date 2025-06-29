#!/usr/bin/env sh

set -xe

# Ensure build dir
mkdir -p ../../build

# cd build dir and push onto stack
pushd ../../build

# Compile from build dir
c++ ../handmade/code/sdl_handmade.cpp -o handmadehero

# Run exe
./handmadehero

# Return to original dir before pushing current onto stack
popd
