# MICROSOFT WINDOWS

Microsoft Windows is so famous then I may not introduce it again. :)

## Installation

You can choose and download [the newest version](https://github.com/kambria-platform/kbcb/blob/master/packages/windows/). Be noticed that the available package will be named in form of `kbcb_<version>_amd64.deb`. After that, you could double click to install with root user.

## Development

The building machine must be a MacOS. The files you need to focus are `build.sh`, `start.sh` and `formula-template.rb`.

### Prerequisite

The building machine must be a Debian distro.

**CMake (Permanently for all architectures)**

Select your a favourite version (greater than 3.10.0) [in CMake website](https://cmake.org/download/), download and install.


**Activate shell script**

In order to run the convenient scripts, you need to activate the shell script by turning on the Developer mode.

```
Settings > Update & Security > For developers
```

Turn on Developer mode and wait for a second for Windows configuring your system.

Next, using search bar to find `Turn Windows features on or off` and access it. Scroll the list down and you will see `Windows Subsystem for Linux`, activate it and restart the machine.

You may require to install a Linux distribution, however, it is an easy one.

```
Windows Subsystem for Linux has no installed distributions.
Distributions can be installed by visiting the Microsoft Store:
https://aka.ms/wslstore
```

Now you can use shell script like this:

```
bash your_scripts.sh
```

### `formula-template.rb`

You need to update this file frequently when you want to update the upstream package or release a new one.

The package version is followed debian standard `<version-revision>`.

If you would like to update the upstream package, update the `revision`.

If you would like to release the new one, change the `version`.

### `start.sh`

This file let you build and test the package in `development` environment.

To run (stay at root dir),

```
bash start.sh
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
bash build.sh
```
