# MACOS

MacOS is so famous then I may not introduce it again. :)

## Installation

At the moment, kbcb package is delivered via [Homebrew](https://brew.sh/). First, you must install `homebrew` to be able to install `kbcb`. If you have already installed `homebrew`, let's go forward.

```
brew update
brew install kbcb
```

## Development

The building machine must be a MacOS. The files you need to focus are `build.sh`, `start.sh` and `formula-template.rb`.

### Prerequisite

The building machine must be a Debian distro.

**CMake (Permanently for all architectures)**

Select your a favourite version (greater than 3.10.0) [in CMake website](https://cmake.org/download/), download and install.


**MacOs build tools**

You need `homebrew` only.

### `formula-template.rb`

You need to update this file frequently when you want to update the upstream package or release a new one.

The package version is followed debian standard `<version-revision>`.

If you would like to update the upstream package, update the `revision`.

If you would like to release the new one, change the `version`.

### `start.sh`

This file let you build and test the package in `development` environment.

To run (stay at root dir),

```
sh start.sh
```

Then you can test by,

```
./build/kbcb
```

### `build.sh`

**1. You must run this file on MacOS.**

**2. You must update `formula-template.rb` before run the following commands.**

This file let you build the package in `production` environment. the built bundles would appear in `packages` folder.

You may have to clarify some info like arch, version for build process.

To build (stay at root dir),

```
sh build.sh
```
