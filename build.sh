#!/bin/bash

if ! command -v git &> /dev/null
then
    echo "Git does not appear to be installed." 
    exit 1
fi

echo "Updating Submodules"
git submodule init
git submodule update


if ! command -v cmake &> /dev/null
then
    echo "CMake does not appear to be installed." 
    exit 1
fi

if ! command -v make &> /dev/null
then
    echo "Make does not appear to be installed." 
    exit 1
fi

# set up directories
rm -f CMakeCache.txt
cmake ./Remote-PC-Monitoring-Tool/server && make

# remove old binary, if it exists
if [ -f ./bin/server_linux ]; then
    echo "Removing old binary"
    rm -f ./bin/server_linux
fi

# move new binary
if [ -f server_linux ]; then
    echo "Output file located, moving"
    mv server_linux ./bin/server_linux
fi