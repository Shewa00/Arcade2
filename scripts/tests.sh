#! /bin/sh

set -ex

ls -la
ls -la Content

export QT_QPA_PLATFORM='offscreen'

mkdir -p .build
cd .build
cmake .. -DBUILD_TESTS=On
cd ..
cmake --build .build

./.build/tests
