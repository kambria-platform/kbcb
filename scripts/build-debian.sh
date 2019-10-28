#!/bin/sh

# Config to exit shell on any error
# set -e

# Get package version
read -p "Input version [kbcb-<version>]: " version
package=kbcb-$version
build_path=./packages/debian
build_flags="-DENV='production' -DSHARED='/usr/share/kbcb/kambria-pre-push' -DVER=${version}"

# Create package dir
mkdir -p $build_path
cd $build_path
rm -rf $package
mkdir -p ./$package/$package

# Copy source to new package dir
cd ../..
cp README.md ./debian/README.Debian
cp -r debian include src lib $build_path/$package/$package
cp -r CMakeLists.txt cmake_uninstall.cmake.in $build_path/$package/$package
# Add build flags to rules
cd $build_path/$package/$package
echo $build_flags >> ./debian/rules

# Build source (For testing purpose)
# When build package (debuild),
# debuild uses dh_auto_configure which defined in debian/rules
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
cd ./$package
dh_make --file ../$package.tar.gz --copyright gpl2 --indep
debuild -us -uc

# Notification
LightGreen='\033[1;32m'
NoColor='\033[0m'
echo ""
echo "${LightGreen}$package was built completely!${NoColor}"
echo ""
