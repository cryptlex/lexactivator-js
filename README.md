![Build @cryptlex/lexactivator package](https://github.com/cryptlex/lexactivator-js/workflows/Build%20@cryptlex/lexactivator%20package/badge.svg)

# @cryptlex/lexactivator

Cryptlex lets you license your software apps effortlessly. You can easily generate license keys using the REST API or Dashboard and validate the license keys in your software apps using LexActivator (Cryptlex client library).

Additionally, you can offer trials, subscriptions, floating licenses and much more.

**LexActivator.js** is a Node.js wrapper for LexActivator licensing library.

## Installation

    npm install @cryptlex/lexactivator

Then you can include it in your code:

	const { LexActivator, LexStatusCodes, LexActivatorException, PermissionFlags } = require('@cryptlex/lexactivator');

**Note:** On Windows make sure you install the windows-build-tools package first:

    npm install --global windows-build-tools --vs2015


## Usage
Refer to following for documentation:

https://docs.cryptlex.com/node-locked-licenses/using-lexactivator/using-lexactivator-with-node.js
