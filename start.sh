#!/bin/sh

# Config tp exit shell on error
set -e

# Root path
rootpath=$PWD

# Init folders
rm -rf ./dist
mkdir ./dist
rm -rf ./build
mkdir ./build

# Build
cd ./build 
cmake .. -DENV="DEVELOPMENT" -DSHARED="$rootpath/src/hooks/kambria-pre-push"
make
