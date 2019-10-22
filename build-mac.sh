#!/bin/sh

# Config tp exit shell on error
set -e

# Get package version
read -p "Input version [kbcb-<version>]:" version
package=kbcb-$version
build_path=./packages/mac

# Create package dir
mkdir -p $build_path
cd $build_path
rm -rf $package
mkdir -p ./$package/$package

# Copy source to new package dir
cd ../..
cp -r include src CMakeLists.txt README.md $build_path/$package/$package

# Build source (For testing purpose)
# When intsall package (homebrew),
# homebrew will follow the formula to build package on user's machine
cd $build_path/$package/$package
mkdir ./build
cd ./build
cmake .. -DENV="PRODUCTION" -DSHARED="/usr/local/Cellar/kbcb/$version/share/kambria-pre-push" -DVER="$version"
make

# Build package
cd ../..
tar -cvzf $package.tar.gz $package

LightGreen='\033[1;32m'
NoColor='\033[0m'
echo ""
echo "${LightGreen}$package was built completely!${NoColor}"
echo ""
