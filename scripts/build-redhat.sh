#!/bin/sh

# Config to exit shell on error
set -e

# Get package version
read -p "Input version [kbcb-<version>]: " version
package=kbcb-$version
build_path=./packages/redhat
build_flags="-DENV='production' -DSHARED='/usr/local/share/kbcb/kambria-pre-push' -DVER=${version}"

# Create package dir
mkdir -p $build_path
cd $build_path
rm -rf $package
mkdir -p ./$package/$package

# Copy source to new package dir
cd ../..
cp README.md ./redhat/README
cp -r docs ./redhat
cp -r redhat include src lib $build_path/$package/$package
cp -r CMakeLists.txt cmake_uninstall.cmake.in $build_path/$package/$package

# Building source here only for testing purposes
# When building package (by rpmbuild),
cd $build_path/$package/$package
mkdir ./test
cd ./test
cmake .. $build_flags
make
# Notification
LightGreen='\033[1;32m'
NoColor='\033[0m'
echo ""
echo -e "${LightGreen}${package} was tested without errors!${NoColor}"
echo ""
# Remove test
cd ..
rm -rf ./test

# Pre-build package
cd ..
tar -cvzf $package.tar.gz $package
rm -rf ~/rpmbuild
rpmdev-setuptree
cp $package.tar.gz ~/rpmbuild/SOURCES
cp ./$package/redhat/kbcb.spec ~/rpmbuild/SPECS

# Build package
rpmbuild -ba ~/rpmbuild/SPECS/kbcb.spec
cp ~/rpmbuild/RPMS/x86_64/* ./

# Notification
LightGreen='\033[1;32m'
NoColor='\033[0m'
echo ""
echo -e "${LightGreen}${package} was built completely!${NoColor}"
echo ""
