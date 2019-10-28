# DEBIAN

Debian architecture includes some well-known platforms such as Ubuntu, Debian, Linux Mint, etc.

## Installation

You can choose and download [the newest version](https://github.com/kambria-platform/kbcb/blob/master/packages/debian/). Be noticed that the available package will be named in form of `kbcb_<version>_amd64.deb`. After that, you could double click to install with root user.

In case, the installation might be not poped up, you would like to you the following command to install by hands.

```
sudo gdebi -n <path_to_the_package.deb>
```

## Development

The building machine must be a Debian distro. The files you need to focus are `build.sh`, `start.sh` and `debian/changelog`.

### Prerequisite

**CMake (Permanently for all architectures)**

```
sudo apt-get install cmake
```

**Packaging tools**

```
sudo apt-get install dh-make devscripts debhelper
```

**Setup global variables**

```
cat >>~/.bashrc <<EOF
DEBEMAIL="your_email"
DEBFULLNAME="Your Name"
export DEBEMAIL DEBFULLNAME
EOF
. ~/.bashrc
```

### `changelog`

You need to update this file frequently when you want to update the upstream package or release a new one.

The package version is followed debian standard `<version-revision>`.

* If you would like to update the upstream package, update the `revision`.
* If you would like to release the new one, change the `version`.

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

**1. You must build the package on a Debian distro like Ubuntu or Debian.**

**2. You must update `changelog` before run the following commands.**

This file let you build the package in `production` environment. The built bundles would appear in `packages/debian` folder.

You may have to clarify some info like arch, version for build process.

To build (stay at root dir),

```
sh build.sh
```
