# exit when any command fails
set -e
# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" finished with exit code $?."' EXIT

URL="https://dl.cryptlex.com/downloads/"
VERSION="v3.16.0";
curl ${URL}${VERSION}/LexActivator-Static-Mac.zip -o LexActivator-Static-Mac.zip
mkdir -p ./tmp/macos
unzip -o LexActivator-Static-Mac.zip -d ./tmp/macos

cp ./tmp/macos/libs/clang/universal/libLexActivator.a ./
npm i

node-gyp rebuild 
cp ./build/Release/lexactivator.node ./lib/bindings/macos/x64

SDKROOT=$(xcrun --sdk macosx --show-sdk-path) node-gyp rebuild --arch=arm64
cp ./build/Release/lexactivator.node ./lib/bindings/macos/arm64
rm -f LexActivator-Static-Mac.zip
