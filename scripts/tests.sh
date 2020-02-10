#! /bin/sh

set -ex

export QT_QPA_PLATFORM='offscreen'

mkdir -p .build
cd .build
cmake .. -DBUILD_TESTS=On
cmake --build .

./tests
