rm -rf ./build
mkdir ./build
cd ./build
cmake .. -DENV="DEVELOPMENT"
make
