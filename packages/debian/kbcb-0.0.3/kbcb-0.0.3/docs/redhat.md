# REDHAT

Redhat architecture includes some well-known platforms such as CentOS, Fedora, etc.

## Installation

You can choose and download [the newest version](https://github.com/kambria-platform/kbcb/blob/master/packages/redhat/). Be noticed that the available package will be named in form of `kbcb-<version>.el8.x86_64.rpm`. After that, you could double click to install with root user.

In case, the installation might be not poped up, you would like to you the following command to install by hands.

```
sudo rpm -i <path_to_the_package.rpm>
```

## Development

The building machine must be a Redhat distro. The files you need to focus are `build.sh`, `start.sh` and `redhat/kbcb.spec`.

### Prerequisite

**CMake (Permanently for all architectures)**

```
sudo yum install cmake
```

**Packaging tools**

```
yum install -y rpm* gcc gpg* rng-tools
```

**Setup GPG key (Optional)**

```
rngd -r /dev/urandom
gpg --gen-key
gpg --armor --export
```

## `kbcb.spec`

You need to update this file frequently when you want to update the upstream package or release a new one.

The list of things you should check:

- [] Version

- [] Release

- [] Source0

- [] changelog

## start.sh

This file let you build and test the package in `development` environment.

To run (stay at root dir),

```
sh start.sh
```

Then you can test by,

```
./build/kbcb
```

## build.sh

**1. You must run this file on a Redhat-based machine like CentOS or Fedora.**

**2. You must update `kbcb.spec` before run the following commands.**

This file let you build the package in `production` environment.Tthe built bundles would appear in `packages/redhat` folder.

You may have to clarify some info like arch, version for build process.

To build (stay at root dir),

```
sh build.sh
```
