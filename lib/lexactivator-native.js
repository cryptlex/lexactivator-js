const { TextDecoder } = require('util');
const LexActivatorNative = require('bindings')('lexactivator.node');

const isWindows = function () {
	return process.platform == 'win32' ? true : false;
};

const arrayToString = function (array) {
	if (isWindows()) {
		return new TextDecoder('utf16le').decode(array).replace(/\0.*$/g, '');
	} else {
		return new TextDecoder('utf-8').decode(array).replace(/\0.*$/g, '');
	}
};

module.exports = { LexActivatorNative, arrayToString };
