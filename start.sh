rm -rf ./build
mkdir ./build
cd ./build
cmake .. -D ENV="DEVELOPMENT"
make