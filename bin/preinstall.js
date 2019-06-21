const request = require('request');
const unzipper = require('unzipper');
const fs = require('fs');
const os = require('os');
const path = require('path');

async function download(url, files, destPath) {
	const directory = await unzipper.Open.url(request, url);
	for (let i = 0; i < files.length; i++) {
		const file = directory.files.find((file) => file.path === files[i]);
		const content = await file.buffer();
		await fs.writeFileSync(destPath + path.basename(files[i]), content);
	}
}

async function main() {
	try {
		const arch = os.arch();
		const plat = os.platform();

		console.log(`Downloading Lexactivator library for ${plat} ${arch} ...`);

		const baseUrl = 'https://dl.cryptlex.com/downloads/';
		const version = 'v3.7.0';

		let url; let files;

		switch (plat) {
		case 'darwin': // OSX
			files = ['libs/gcc/universal/libLexActivator.dylib'];
			url = '/LexActivator-Mac.zip';
			break;
		case 'win32': // windows
			files = ['libs/' + arch + '/LexActivator.dll', 'libs/' + arch + '/LexActivator.lib'];
			url = '/LexActivator-Win.zip';
			break;
		case 'linux': // linux
			url = '/LexActivator-Linux.zip';
			let dir = '';
			switch (arch) {
			case 'arm':
				dir = os.endianness() === 'LE' ? 'armle' : 'armhf';
				break;
			case 'arm64':
				dir = 'arm64';
				break;
			case 'x64':
				dir = 'amd64';
				break;
			case 'x32':
				dir = 'i386';
				break;
			default:
				throw Error('Unsupported Linux arch: ' + arch);
			}
			files = ['libs/' + dir + '/libLexActivator.so'];
			break;
		default:
			throw Error('Unsupported platform: ' + plat);
		}

		await download(baseUrl + version + url, files, './');

		console.log(`Lexactivator library successfully downloaded!`);
	} catch (error) {
		console.error(error);
	}
}

main();
