#!/bin/sh
mkdir build
cd build
cmake ..
make
cd bin
echo
echo "Executables are at "
pwd
echo "Please put data.txt in there"

cd ..

