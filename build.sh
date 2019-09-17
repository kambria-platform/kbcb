rm -rf ./builds
mkdir ./builds
cd ./builds
cmake .. -D ENV="PRODUCTION"
make