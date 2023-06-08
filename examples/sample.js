const { LexActivator, LexStatusCodes, LexActivatorException, PermissionFlags, ReleaseFlags } = require('@cryptlex/lexactivator');

function init() {
	LexActivator.SetProductData('PASTE_CONTENT_OF_PRODUCT.DAT_FILE');
	LexActivator.SetProductId('PASTE_PRODUCT_ID', PermissionFlags.LA_USER);
	LexActivator.SetReleasePlatform('RELEASE_PLATFORM'); // set the actual platform of the release e.g windows
	LexActivator.SetReleaseChannel('RELEASE_CHANNEL'); // set the actual channel of the release e.g stable
	LexActivator.SetReleaseVersion('1.0.0');  // Set this to the release version of your app
}

function activate() {
	LexActivator.SetLicenseKey('PASTE_LICENCE_KEY');
	LexActivator.SetActivationMetadata('key1', 'value1');
	const status = LexActivator.ActivateLicense();
	if (LexStatusCodes.LA_OK == status || LexStatusCodes.LA_EXPIRED == status || LexStatusCodes.LA_SUSPENDED == status) {
		console.log('License activated successfully:', status);
	} else {
		console.log('License activation failed:', status);
	}
}

function activateTrial() {
	LexActivator.SetTrialActivationMetadata('key1', 'value1');
	const status = LexActivator.ActivateTrial();
	if (LexStatusCodes.LA_OK == status) {
		console.log('Product trial activated successfully!');
	} else if (LexStatusCodes.LA_TRIAL_EXPIRED == status) {
		console.log('Product trial has expired!');
	} else {
		console.log('Product trial activation failed:', status);
	}
}

function licenseCallback(status) {
	try {
		switch (status) {
		case LexStatusCodes.LA_OK:
		case LexStatusCodes.LA_EXPIRED:
		case LexStatusCodes.LA_SUSPENDED:
			console.log('License is genuinely activated!', status);
			break;
		default:
			throw new LexActivatorException(status);
		}
	} catch (error) {
		console.log(error.code, error.message);
	}
}

function softwareReleaseUpdateCallback(status, release, userData) {
	try {
		switch (status) {
			case LexStatusCodes.LA_RELEASE_UPDATE_AVAILABLE:
				console.log('Release update available!');
				console.log("Release:",  release.notes);
				break;
			case LexStatusCodes.LA_RELEASE_UPDATE_AVAILABLE_NOT_ALLOWED:
				console.log('Release update available but not allowed!');
				console.log("Release:",  release.notes);
				break;
			case LexStatusCodes.LA_RELEASE_UPDATE_NOT_AVAILABLE:
				console.log('Release update not available!');
				break;
			default:
				throw new LexActivatorException(status);
		}
	} catch (error) {
		console.log(error.code, error.message);
	}
}

function main() {
	try {
		init();
		// activate(); // call once to activate the license
		LexActivator.SetLicenseCallback(licenseCallback);
		const status = LexActivator.IsLicenseGenuine();
		if (LexStatusCodes.LA_OK == status) {
			console.log('License is genuinely activated!');

			const expiryDate = LexActivator.GetLicenseExpiryDate();
			const daysLeft = (expiryDate - (new Date().getTime() / 1000)) / 86400;
			console.log('Days left:', daysLeft);

			const userName = LexActivator.GetLicenseUserName();
			console.log('License user name: %s\n', userName);

			// console.log('Checking for software release update...');
			// LexActivator.CheckReleaseUpdate(softwareReleaseUpdateCallback, ReleaseFlags.LA_RELEASES_ALL, null);
		} else if (LexStatusCodes.LA_EXPIRED == status) {
			console.log('License is genuinely activated but has expired!');
		} else if (LexStatusCodes.LA_SUSPENDED == status) {
			console.log('License is genuinely activated but has been suspended!');
		} else if (LexStatusCodes.LA_GRACE_PERIOD_OVER == status) {
			console.log('License is genuinely activated but grace period is over!');
		} else {
			const trialStatus = LexActivator.IsTrialGenuine();
			if (LexStatusCodes.LA_OK == trialStatus) {
				const expiryDate = LexActivator.GetTrialExpiryDate();
				const daysLeft = (expiryDate - (new Date().getTime() / 1000)) / 86400;
				console.log('Trial days left:', daysLeft);
			} else if (LexStatusCodes.LA_TRIAL_EXPIRED == trialStatus) {
				console.log('Trial has expired!');
				// Time to buy the license and activate the app
				activate();
			} else {
				console.log('Either trial has not started or has been tampered!');
				// Activating the trial
				activateTrial();
			}
		}
	} catch (error) {
		console.log(error.code, error.message);
	}
}

main();

