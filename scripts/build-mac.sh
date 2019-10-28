#!/bin/sh

# Config tp exit shell on error
set -e

# Get package version
read -p "Input version [kbcb-<version>]: " version
package=kbcb-$version
build_path=./packages/mac
build_flags="-DENV=production -DSHARED=/usr/local/Cellar/kbcb/${version}/share/kambria-pre-push -DVER=${version}"

# Create package dir
mkdir -p $build_path
cd $build_path
rm -rf $package
mkdir -p ./$package/$package

# Copy source to new package dir
cd ../..
cp -r docs README.md $build_path/$package/$package
cp -r include src lib $build_path/$package/$package
cp -r CMakeLists.txt cmake_uninstall.cmake.in $build_path/$package/$package

# Building source here onl for testing purposes
# When installing package by homebrew,
# homebrew will follow the formula to build package on user's machine
cd $build_path/$package/$package
mkdir ./test
cd ./test
cmake .. $build_flags
make
# Notification
LightGreen='\033[1;32m'
NoColor='\033[0m'
echo ""
echo "${LightGreen}$package was tested without errors!${NoColor}"
echo ""
# Remove test
cd ..
rm -rf ./test

# Build package
cd ..
tar -cvzf $package.tar.gz $package

LightGreen='\033[1;32m'
NoColor='\033[0m'
echo ""
echo "${LightGreen}$package was built completely!${NoColor}"
echo ""
