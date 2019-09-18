#!bin/sh

# Config tp exit shell on error
# set -e

# Get package version
read -p "Input version [kbcb-<version>]:" version
package=kbcb-$version

# Create package dir
cd ./packages
mkdir ./$package
mkdir ./$package/$package

# Copy source to new package dir
cd ..
cp README.md ./debian/README.Debian
cp -r debian include lib src CMakeLists.txt ./packages/$package/$package

# Build source
cd ./packages/$package/$package
rm -rf ./build
mkdir ./build
cd ./build
cmake .. -D ENV="PRODUCTION"
make

# Build package
cd ../..
tar -cvzf $package.tar.gz $package
cd ./$package
dh_make -f ../$package.tar.gz
debuild -us -uc

# LightGreen='\033[1;32m'
# echo ""
# echo "${LightGreen}$package template was built. You may wish to edit them and then run 'debuild -us -uc' in packages/$package/$package directory."
# echo ""
