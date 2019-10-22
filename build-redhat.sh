#!/bin/sh

# Config tp exit shell on error
# set -e

# Get package version
read -p "Input version [kbcb-<version>]:" version
package=kbcb-$version
build_path=./packages/redhat

# Create package dir
mkdir -p $build_path
cd $build_path
rm -rf $package
mkdir -p ./$package/$package

# Copy source to new package dir
cd ../..
cp -r include src CMakeLists.txt $build_path/$package/$package

# Build source (For testing purpose)
# When build package (debuild),
# debbuild uses dh_auto_configure which defined in debian/rules
cd $build_path/$package/$package
mkdir ./build
cd ./build
cmake .. -DENV="PRODUCTION" -DSHARED="/usr/share/kbcb/kambria-pre-push" -DVER="$version"
make

# Build package
cd ../..
tar -cvzf $package.tar.gz $package
cd ./$package
# dh_make --file ../$package.tar.gz --copyright gpl2 --indep
# debuild -us -uc

LightGreen='\033[1;32m'
NoColor='\033[0m'
echo ""
echo "${LightGreen}$package was built completely!${NoColor}"
echo ""
