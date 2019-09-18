rm -rf ./build
mkdir ./build
cd ./build
cmake .. -D ENV="PRODUCTION"
make