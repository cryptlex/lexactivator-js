const fs = require('fs');
const download = require('download');

download('https://dl.cryptlex.com/downloads/v3.7.0/LexActivator-Mac.zip', { extract: true }).then((data) => {
	fs.writeFileSync('archive.zip', data);
});
