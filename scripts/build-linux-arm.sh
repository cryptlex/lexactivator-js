#!/bin/bash
# exit when any command fails
set -e
# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" finished with exit code $?."' EXIT
source ~/.bashrc

URL="https://dl.cryptlex.com/downloads/"
VERSION="v3.22.0";
wget ${URL}${VERSION}/LexActivator-Static-Linux.zip
mkdir -p ./tmp/linux
unzip -o LexActivator-Static-Linux.zip -d ./tmp/linux

cp ./tmp/linux/libs/gcc/arm64/libLexActivator.a ./
CROSS_COMPILE="aarch64-linux-gnu" 
export AR=${CROSS_COMPILE}-ar
export LD=${CROSS_COMPILE}-ld
export CC=${CROSS_COMPILE}-gcc
export CXX=${CROSS_COMPILE}-g++
npm i
node-gyp rebuild --arch=aarch64
cp ./build/Release/lexactivator.node ./lib/bindings/linux/gcc/arm64

cp ./tmp/linux/libs/gcc/armhf/libLexActivator.a ./
CROSS_COMPILE="arm-linux-gnueabihf" 
export AR=${CROSS_COMPILE}-ar
export LD=${CROSS_COMPILE}-ld
export CC=${CROSS_COMPILE}-gcc
export CXX=${CROSS_COMPILE}-g++
node-gyp rebuild --arch=armhf
cp ./build/Release/lexactivator.node ./lib/bindings/linux/gcc/arm
rm -f LexActivator-Static-Linux.zip