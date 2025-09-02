#!/bin/sh
# exit when any command fails
set -e
# Clear existing repositories and add correct ones
echo "http://dl-cdn.alpinelinux.org/alpine/v3.12/main" > /etc/apk/repositories
echo "http://dl-cdn.alpinelinux.org/alpine/v3.12/community" >> /etc/apk/repositories

# Install Node.js 12 and essential tools
apk update
apk add --no-cache \
    nodejs=12.22.12-r0 \
    libstdc++=9.3.0-r2 \
    nghttp2-libs=1.41.0-r0 \
    curl \
    tar

# Download and extract npm@6.14.15 without changing directory
curl -L https://registry.npmjs.org/npm/-/npm-6.14.15.tgz -o npm.tgz
mkdir -p .npm-upgrade
tar -xzf npm.tgz -C .npm-upgrade --strip-components=1

# Run npm-cli.js directly from the extracted path
node .npm-upgrade/bin/npm-cli.js install -g .npm-upgrade

URL="https://dl.cryptlex.com/downloads/"
VERSION="v3.34.0";
wget ${URL}${VERSION}/LexActivator-Static-Linux.zip
mkdir -p ./tmp/linux
unzip -o LexActivator-Static-Linux.zip -d ./tmp/linux

cp ./tmp/linux/libs/musl/amd64/libLexActivator.a ./
npm i
node-gyp rebuild 
cp ./build/Release/lexactivator.node ./lib/bindings/linux/musl/x64
# Clean up
rm -f LexActivator-Static-Linux.zip
rm -rf npm.tgz .npm-upgrade