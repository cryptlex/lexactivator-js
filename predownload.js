const request = require('request');
const unzipper = require('unzipper');
const fs = require('fs');
const os = require('os');
const path = require('path');
const args = require('yargs')(process.argv.slice(2).concat(JSON.parse(process.env.npm_config_argv).original)).argv;
const version = 'v3.9.0';

async function download(url, files, destPath) {
	const directory = await unzipper.Open.url(request, url);
	for (let i = 0; i < files.length; i++) {
		const file = directory.files.find((file) => file.path === files[i]);
		const content = await file.buffer();
		await fs.writeFileSync(destPath + path.basename(files[i]), content);
	}
}

function isMusl() {
	if (os.platform() != 'linux') {
		return false;
	}
	const output = require('child_process').spawnSync('ldd', ['--version']).stderr.toString('utf8');
	if (output.indexOf('musl') > -1) {
		return true;
	}
	return false;
}

async function main() {
	try {
		let arch = os.arch();
		const plat = args.target_platform || os.platform();
		const baseUrl = 'https://dl.cryptlex.com/downloads/';

		let url; let files;
		switch (plat) {
		case 'darwin': // OSX
			if (args.buildFromSource == null) {
				return;
			}
			files = ['libs/clang/x86_64/libLexActivator.dylib'];
			url = '/LexActivator-Mac.zip';
			break;
		case 'win32': // windows
			if (args.buildFromSource == null) {
				return;
			}
			if (args.target_arch == 'ia32') {
				arch = 'x86';
			}
			files = ['libs/vc14/' + arch + '/LexActivator.lib', 'libs/vc14/' + arch + '/LexActivator.dll'];
			url = '/LexActivator-Win.zip';
			break;
		case 'linux': // linux
			if (args.target_arch == 'ia32') {
				arch = 'x32';
			}
			url = '/LexActivator-Linux.zip';
			let dir = '';
			switch (arch) {
			case 'arm':
				dir = os.endianness() === 'LE' ? 'armel' : 'armhf';
				break;
			case 'arm64':
				dir = 'arm64';
				break;
			case 'x64':
				if (args.buildFromSource == null && !isMusl()) {
					return;
				}
				dir = 'amd64';
				break;
			case 'x32':
				dir = 'i386';
				break;
			default:
				throw Error('Unsupported Linux arch: ' + arch);
			}
			if (isMusl()) {
				files = ['libs/musl/' + dir + '/libLexActivator.so'];
			} else {
				files = ['libs/gcc/' + dir + '/libLexActivator.so'];
			}
			break;
		default:
			throw Error('Unsupported platform: ' + plat);
		}
		console.log(`Downloading LexActivator library for ${plat} ${arch} ...`);
		await download(baseUrl + version + url, files, './');

		console.log(`LexActivator library successfully downloaded!`);
		process.exit(0);
	} catch (error) {
		console.error(error);
	}
}

main();
