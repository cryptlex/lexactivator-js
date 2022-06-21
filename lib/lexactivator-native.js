const path = require('path');
const { isNonGlibcLinux } = require('detect-libc');
const LexActivatorNative = require(getLibraryPath());

function getLibraryPath() {
	if (process.platform == 'darwin') {
		return path.join(__dirname, 'bindings/macos', process.arch, 'lexactivator.node');
	}
	if (process.platform == 'win32') {
		let arch = process.arch;
		if(arch == 'ia32'){
			arch = 'x32';
		}
		return path.join(__dirname, 'bindings/windows', process.arch, 'lexactivator.node');
	}
	if (process.platform == 'linux') {
		const compiler = isNonGlibcLinux ? 'musl' : 'gcc';
		return path.join(__dirname, 'bindings/linux', compiler, process.arch, 'lexactivator.node');
	}
}

function arrayToString(array) {
	if (process.platform == 'win32') {
		return Buffer.from(array).toString('utf16le').replace(/\0.*$/g, '');
	} else {
		return Buffer.from(array).toString('utf8').replace(/\0.*$/g, '');
	}
}

module.exports = { LexActivatorNative, arrayToString };
