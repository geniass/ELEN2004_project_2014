ELEN2004_project_2014
=====================

Ari Croock 718005
ELEN2004 2014 Project Source Code (Power usage analysis)

BUILDING
---------------------
*) My project uses the Google Test library for unit testing. It requires cmake
to build correctly on all platforms

*) If you don't want to install cmake, you can still build my project without
unit tests by:

cd src; (cd into src code directory)
g++ --std=c++11 main.cpp DataPoint.cpp -o elen_2004_2014


*) So if you do want to run the unit tests as well, just run:

sh build.sh

in the root project folder. It will print the directory where the executables
will be found. In that directory, runUnitTests runs the unit tests, and
elen2004_2014 is the main project executable. The data file must be in this
directory.
