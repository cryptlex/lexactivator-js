const { LexStatusCodes } = require('./lexstatus-codes');

/* eslint-disable indent */
class LexActivatorException extends Error {
	constructor(code) {
		super(LexActivatorException.getErrorMessage(code));
		Error.captureStackTrace(this, this.constructor);
		this.code = code;
	}

	static getErrorMessage(code) {
		let message = 'Unknown error!';
		switch (code) {
			case LexStatusCodes.LA_E_FILE_PATH:
				message = 'Invalid file path.';
				break;

			case LexStatusCodes.LA_E_PRODUCT_FILE:
				message = 'Invalid or corrupted product file.';
				break;

			case LexStatusCodes.LA_E_PRODUCT_DATA:
				message = 'Invalid product data.';
				break;

			case LexStatusCodes.LA_E_PRODUCT_ID:
				message = 'The product id is incorrect.';
				break;

			case LexStatusCodes.LA_E_SYSTEM_PERMISSION:
				message = 'Insufficient system permissions.';
				break;

			case LexStatusCodes.LA_E_FILE_PERMISSION:
				message = 'No permission to write to file.';
				break;

			case LexStatusCodes.LA_E_WMIC:
				message = 'Fingerprint couldn\'t be generated because Windows Management Instrumentation (WMI) service has been disabled.';
				break;

			case LexStatusCodes.LA_E_TIME:
				message = 'The difference between the network time and the system time is more than allowed clock offset.';
				break;

			case LexStatusCodes.LA_E_INET:
				message = 'Failed to connect to the server due to network error.';
				break;

			case LexStatusCodes.LA_E_NET_PROXY:
				message = 'Invalid network proxy.';
				break;

			case LexStatusCodes.LA_E_HOST_URL:
				message = 'Invalid Cryptlex host url.';
				break;

			case LexStatusCodes.LA_E_BUFFER_SIZE:
				message = 'The buffer size was smaller than required.';
				break;

			case LexStatusCodes.LA_E_APP_VERSION_LENGTH:
				message = 'App version length is more than 256 characters.';
				break;

			case LexStatusCodes.LA_E_REVOKED:
				message = 'The license has been revoked.';
				break;

			case LexStatusCodes.LA_E_LICENSE_KEY:
				message = 'Invalid license key.';
				break;

			case LexStatusCodes.LA_E_LICENSE_TYPE:
				message = 'Invalid license type. Make sure floating license is not being used.';
				break;

			case LexStatusCodes.LA_E_OFFLINE_RESPONSE_FILE:
				message = 'Invalid offline activation response file.';
				break;

			case LexStatusCodes.LA_E_OFFLINE_RESPONSE_FILE_EXPIRED:
				message = 'The offline activation response has expired.';
				break;

			case LexStatusCodes.LA_E_ACTIVATION_LIMIT:
				message = 'The license has reached it\'s allowed activations limit.';
				break;

			case LexStatusCodes.LA_E_ACTIVATION_NOT_FOUND:
				message = 'The license activation was deleted on the server.';
				break;

			case LexStatusCodes.LA_E_DEACTIVATION_LIMIT:
				message = 'The license has reached it\'s allowed deactivations limit.';
				break;

			case LexStatusCodes.LA_E_TRIAL_NOT_ALLOWED:
				message = 'Trial not allowed for the product.';
				break;

			case LexStatusCodes.LA_E_TRIAL_ACTIVATION_LIMIT:
				message = 'Your account has reached it\'s trial activations limit.';
				break;

			case LexStatusCodes.LA_E_MACHINE_FINGERPRINT:
				message = 'Machine fingerprint has changed since activation.';
				break;

			case LexStatusCodes.LA_E_METADATA_KEY_LENGTH:
				message = 'Metadata key length is more than 256 characters.';
				break;

			case LexStatusCodes.LA_E_METADATA_VALUE_LENGTH:
				message = 'Metadata value length is more than 256 characters.';
				break;

			case LexStatusCodes.LA_E_ACTIVATION_METADATA_LIMIT:
				message = 'The license has reached it\'s metadata fields limit.';
				break;

			case LexStatusCodes.LA_E_TRIAL_ACTIVATION_METADATA_LIMIT:
				message = 'The trial has reached it\'s metadata fields limit.';
				break;

			case LexStatusCodes.LA_E_METADATA_KEY_NOT_FOUND:
				message = 'The metadata key does not exist.';
				break;

			case LexStatusCodes.LA_E_TIME_MODIFIED:
				message = 'The system time has been tampered (backdated).';
				break;

			case LexStatusCodes.LA_E_RELEASE_VERSION_FORMAT:
				message = 'Invalid version format.';
				break;

			case LexStatusCodes.LA_E_AUTHENTICATION_FAILED:
				message = 'Incorrect email or password.';
				break;

			case LexStatusCodes.LA_E_METER_ATTRIBUTE_NOT_FOUND:
				message = 'The meter attribute does not exist.';
				break;

			case LexStatusCodes.LA_E_METER_ATTRIBUTE_USES_LIMIT_REACHED:
				message = 'The meter attribute has reached it\'s usage limit.';
				break;

			case LexStatusCodes.LA_E_CUSTOM_FINGERPRINT_LENGTH:
				message = 'Custom device fingerprint length is less than 64 characters or more than 256 characters.';
				break;

			case LexStatusCodes.LA_E_PRODUCT_VERSION_NOT_LINKED:
				message = 'No product version is linked with the license.';
				break;

			case LexStatusCodes.LA_E_FEATURE_FLAG_NOT_FOUND:
				message = 'The product version feature flag does not exist.';
				break;

			case LexStatusCodes.LA_E_RELEASE_VERSION_NOT_ALLOWED:
				message = 'The release version is not allowed.';
				break;

			case LexStatusCodes.LA_E_VM:
				message = 'Application is being run inside a virtual machine / hypervisor, and activation has been disallowed in the VM.';
				break;

			case LexStatusCodes.LA_E_COUNTRY:
				message = 'Country is not allowed.';
				break;

			case LexStatusCodes.LA_E_IP:
				message = 'IP address is not allowed.';
				break;

			case LexStatusCodes.LA_E_CONTAINER:
				message = 'Application is being run inside a container and activation has been disallowed in the container.';
				break;

			case LexStatusCodes.LA_E_RATE_LIMIT:
				message = 'Rate limit for API has reached, try again later.';
				break;

			case LexStatusCodes.LA_E_SERVER:
				message = 'Server error.';
				break;

			case LexStatusCodes.LA_E_CLIENT:
				message = 'Client error.';
				break;

			default:
				message = 'Unknown error!';
		}
		return message;
	}
}

module.exports = { LexActivatorException };
