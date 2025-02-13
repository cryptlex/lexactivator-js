#!/bin/sh

URL="https://dl.cryptlex.com/downloads/"
VERSION="v3.31.3";
wget ${URL}${VERSION}/LexActivator-Static-Linux.zip
mkdir -p ./tmp/linux
unzip -o LexActivator-Static-Linux.zip -d ./tmp/linux

cp ./tmp/linux/libs/musl/amd64/libLexActivator.a ./
npm i
node-gyp rebuild 
cp ./build/Release/lexactivator.node ./lib/bindings/linux/musl/x64
rm -f LexActivator-Static-Linux.zip