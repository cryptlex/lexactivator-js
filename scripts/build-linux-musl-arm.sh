#!/bin/sh
# exit when any command fails
set -e

URL="https://dl.cryptlex.com/downloads/"
VERSION="v3.37.0";
wget ${URL}${VERSION}/LexActivator-Static-Linux.zip
mkdir -p ./tmp/linux
unzip -o LexActivator-Static-Linux.zip -d ./tmp/linux

cp ./tmp/linux/libs/musl/arm64/libLexActivator.a ./
CROSS_COMPILE="aarch64-linux-musl"
export AR=${CROSS_COMPILE}-ar
export LD=${CROSS_COMPILE}-ld
export CC=${CROSS_COMPILE}-gcc
export CXX=${CROSS_COMPILE}-g++
npm i
node-gyp rebuild --arch=aarch64
cp ./build/Release/lexactivator.node ./lib/bindings/linux/musl/arm64
rm -f LexActivator-Static-Linux.zip