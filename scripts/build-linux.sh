#!/bin/bash
# exit when any command fails
set -e
# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" finished with exit code $?."' EXIT
source ~/.bashrc
URL="https://dl.cryptlex.com/downloads/"
VERSION="v3.16.1";
wget ${URL}${VERSION}/LexActivator-Static-Linux.zip
mkdir -p ./tmp/linux
unzip -o LexActivator-Static-Linux.zip -d ./tmp/linux

cp ./tmp/linux/libs/gcc/amd64/libLexActivator.a ./
npm i
node-gyp rebuild 
cp ./build/Release/lexactivator.node ./lib/bindings/linux/gcc/x64
rm -f LexActivator-Static-Linux.zip