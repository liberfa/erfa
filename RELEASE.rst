
How to make a release
=====================

 * Clone the erfa repository

 * Change directory to the erfa directory

 * Run `./bootstrap.sh`: you need `automake`, `autoconf` and `libtool` 
   installed.

 * If no errors appear, now there is a new `./configure` file

 * Run `./configure`

 * If the checks are passed, new `Makefile` are created in the top
   level directory and in ./src

 * Run `make check`

 * Once the library is built and the test program is run sucessfully
   we can create the distribution.

 * Run `make distcheck`: this creates the distribution tarball, 
   unpackages it and runs the check inside the untarred directory.

 * A tarball named according to the version `erfa-x.x.x.tar.gz` is 
   inside the working direcory
