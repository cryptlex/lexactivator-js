![Build @cryptlex/lexactivator package](https://github.com/cryptlex/lexactivator-js/workflows/Build%20@cryptlex/lexactivator%20package/badge.svg)

# @cryptlex/lexactivator

Cryptlex lets you license your software apps effortlessly. You can easily generate license keys using the REST API or Dashboard and validate the license keys in your software apps using LexActivator (Cryptlex client library).

Additionally, you can offer trials, subscriptions, floating licenses and much more.

**LexActivator.js** is a Node.js wrapper for LexActivator licensing library.

## Installation

    npm install @cryptlex/lexactivator

Then you can include it in your code:

	const { LexActivator, LexStatusCodes, LexActivatorException, PermissionFlags } = require('@cryptlex/lexactivator');

**Note:** In case you are building a cross platform **Electron** app, you should install LexActivator for all the targeted platforms:

    npm install @cryptlex/lexactivator --target_arch=ia32 --target_platform=win32
    npm install @cryptlex/lexactivator --target_arch=x64 --target_platform=win32
    npm install @cryptlex/lexactivator --target_arch=x64 --target_platform=darwin
    npm install @cryptlex/lexactivator --target_arch=x64 --target_platform=linux

This would install the precompiled binaries for the targetted platforms.


## Usage
Refer to following for documentation:

https://docs.cryptlex.com/node-locked-licenses/using-lexactivator/using-lexactivator-with-node.js
