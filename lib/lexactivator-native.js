const LexActivatorNative = require('bindings')('lexactivator.node');

const isWindows = function () {
	return process.platform == 'win32' ? true : false;
};

const arrayToString = function (array) {
	if (isWindows()) {
		return Buffer.from(array).toString('utf16le').replace(/\0.*$/g, '');
	} else {
		return Buffer.from(array).toString('utf8').replace(/\0.*$/g, '');
	}
};

module.exports = { LexActivatorNative, arrayToString };
