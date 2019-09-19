# Kambria Codebase Client (kbcb)

Kambria codebase client is a tool that afilitate developers to integrate thier repositories to Kambria codebase system.

# Prerequisite

## CMake

```
sudo apt-get install cmake
sudo apt-get install dh-make devscripts
```

# How to use

You must be in root folder of your repository.

```
kbcb init
```

Create your authentication key on Kambria Codebase website and add it to `.kambriarc` file.

Now you can push and do anything with your repo as usual.

# For contributors

## Rebuild makefile

In case you has changed some things in following category, you should do this session to rebuild the makefiles.

* Add new `Makefile.am`
* Modify `configure.ac` (Linking new lib, changing package version, et al.)
* Somethings you understand and would like to rebuild.

To rebuild,

```
> sh autogen.sh
> ./configure
> make
```

