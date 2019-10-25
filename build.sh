#!/bin/sh

# Get package arch
read -p "Input destination operation system (debian/mac/redhat/window): " arch
executor=scripts/build-$arch.sh

# Run build
sh $executor
