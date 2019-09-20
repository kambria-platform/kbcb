#!bin/sh

# Config tp exit shell on error
set -e

# Init folders
rm -rf ./dist
mkdir ./dist
rm -rf ./build
mkdir ./build

# Build
cd ./build
cmake .. -DENV="DEVELOPMENT"
make
