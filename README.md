# Kambria Codebase VLI (kbcb)

Kambria codebase CLI is a command-line tool that afilitates developers to integrate their repositories to Kambria codebase system.

# Prerequisite

## CMake

```
sudo apt-get install cmake
```

## Debian build tools

```
sudo apt-get install dh-make devscripts
```

# How to use

You should be in root folder of your repository.

```
kbcb init
```

Create your authentication key on Kambria Codebase website and add it to `.kambriarc` file.

Now you can push and do anything with your repo as usual.

For help,

```
kbcb --help
```

# For contributors

This package is based on CMake to build package. The files you need to focus are `build.sh`, `start.sh` and `debian/changelog`.

## changelog

You need to update this file frequently when you want to update the upstream package or release a new one.

The package version is followed debian standard `<version-revision>`.

If you would like to update the upstream package, update the `revision`.

If you would like to release the new one, change the `version`.

## start.sh

This file let you build and test the package in `development` environment.

To run (stay at the source root),

```
sh start.sh
```

Then, you can test by,

```
./build/kbcb
```

## build.sh

This file let you build the package in `production` environment. the built bundles would appear in `packages` folder.

To build (stay at the source root),

```
sh build.sh
```
