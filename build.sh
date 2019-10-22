#!/bin/sh

# Get package operation
read -p "Input destination operation system (debian/mac/redhat/window):" operation
executor=build-$operation.sh

# Run build
sh $executor
