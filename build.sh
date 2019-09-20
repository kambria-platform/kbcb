#!/bin/sh

# Get package operation
read -p "Input destination operation system (debian/mac):" operation
executor=build-$operation.sh

# Run build
sh $executor
