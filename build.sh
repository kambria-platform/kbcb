#!bin/sh

# Config tp exit shell on error
# set -e

# Get package version
read -p "Input version [kbcb-<version>]:" version
package=kbcb-$version

# Create package dir
mkdir ./packages
cd ./packages
rm -rf $package
mkdir -p ./$package/$package

# Copy source to new package dir
cd ..
cp README.md ./debian/README.Debian
cp -r debian include src CMakeLists.txt ./packages/$package/$package

# Build source (For testing purpose)
# When build package,
# debbuild uses dh_auto_configure which defined in debian/rules
cd ./packages/$package/$package
mkdir ./build
cd ./build
cmake .. -DENV="PRODUCTION"
make

# Build package
cd ../..
tar -cvzf $package.tar.gz $package
cd ./$package
dh_make --file ../$package.tar.gz --copyright gpl2 --indep
debuild -us -uc

# LightGreen='\033[1;32m'
# echo ""
# echo "${LightGreen}$package template was built. You may wish to edit them and then run 'debuild -us -uc' in packages/$package/$package directory."
# echo ""
