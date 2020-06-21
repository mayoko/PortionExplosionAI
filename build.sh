#!/bin/bash

set -eu

if [ -d third_party ]; then
    mkdir third_party
fi
pushd third_party/
GOOGLETEST_VERSION=release-1.8.1
wget --quiet https://github.com/google/googletest/archive/${GOOGLETEST_VERSION}.tar.gz
tar -xf ${GOOGLETEST_VERSION}.tar.gz
rm ${GOOGLETEST_VERSION}.tar.gz
mkdir googletest-${GOOGLETEST_VERSION}/build/
cd googletest-${GOOGLETEST_VERSION}/build/
cmake ..
make
#make install
popd

rm -rf build/
mkdir build/
cd build/
cmake ..
make