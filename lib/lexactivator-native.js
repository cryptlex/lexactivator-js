const { StringDecoder } = require('string_decoder');

const LexActivatorNative = require('bindings')('lexactivator.node');

const isWindows = function () {
	return process.platform == 'win32' ? true : false;
};

const arrayToString = function (array) {
	if (isWindows()) {
		return new StringDecoder('utf16le').end(array).replace(/\0.*$/g, '');
	} else {
		return new StringDecoder('utf8').end(array).replace(/\0.*$/g, '');
	}
};

module.exports = { LexActivatorNative, arrayToString };
