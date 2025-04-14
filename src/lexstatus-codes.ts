export const LexStatusCodes = {
	/**
	 * Success code.
	 */
	LA_OK: 0,

	/**
	 * Failure code.
	 */
	LA_FAIL: 1,

	/**
	 * The license has expired or system time has been tampered with. Ensure your date and time settings are correct.
	 */
	LA_EXPIRED: 20,

	/**
	 * The license has been suspended.
	 */
	LA_SUSPENDED: 21,

	/**
	 * The grace period for server sync is over.
	 */
	LA_GRACE_PERIOD_OVER: 22,

	/**
	 * The trial has expired or system time has been tampered with. Ensure your date and time settings are correct.
	 */
	LA_TRIAL_EXPIRED: 25,

	/**
	 * The local trial has expired or system time has been tampered
	 * with. Ensure your date and time settings are correct.
	 */
	LA_LOCAL_TRIAL_EXPIRED: 26,

	/**
	 * A new update is available for the product. This means a new release has been published for the product.
	 */
	LA_RELEASE_UPDATE_AVAILABLE: 30,

	/**
	 * @deprecated
	 * No new update is available for the product. The current version is latest.
	 */
	LA_RELEASE_NO_UPDATE_AVAILABLE: 31, 

	/**
	 * No new update is available for the product. The current version is latest.
	 */
	LA_RELEASE_UPDATE_NOT_AVAILABLE: 31,

	/**
	 * The update available is not allowed for this license.
	 */
	LA_RELEASE_UPDATE_AVAILABLE_NOT_ALLOWED: 32,
	
	/**
	 * Invalid file path.
	 */
	LA_E_FILE_PATH: 40,

	/**
	 * Invalid or corrupted product file.
	 */
	LA_E_PRODUCT_FILE: 41,

	/**
	 * Invalid product data.
	 */
	LA_E_PRODUCT_DATA: 42,

	/**
	 * The product id is incorrect.
	 */
	LA_E_PRODUCT_ID: 43,

	/**
	 * Insufficient system permissions. Occurs when LA_SYSTEM flag is used
	 * but application is not run with admin privileges.
	 */
	LA_E_SYSTEM_PERMISSION: 44,

	/**
	 * No permission to write to file.
	 */
	LA_E_FILE_PERMISSION: 45,

	/**
	 * Fingerprint couldn't be generated because Windows Management Instrumentation (WMI)
	 * service has been disabled. This error is specific to Windows only.
	 */
	LA_E_WMIC: 46,

	/**
	 * The difference between the network time and the system time is
	 * more than allowed clock offset.
	 */
	LA_E_TIME: 47,

	/**
	 * Failed to connect to the server due to network error.
	 */
	LA_E_INET: 48,

	/**
	 * Invalid network proxy.
	 */
	LA_E_NET_PROXY: 49,

	/**
	 * Invalid Cryptlex host url.
	 */
	LA_E_HOST_URL: 50,

	/**
	 * The buffer size was smaller than required.
	 */
	LA_E_BUFFER_SIZE: 51,

	/**
	 * App version length is more than 256 characters.
	 */
	LA_E_APP_VERSION_LENGTH: 52,

	/**
	 * The license has been revoked.
	 */
	LA_E_REVOKED: 53,

	/**
	 * Invalid license key.
	 */
	LA_E_LICENSE_KEY: 54,

	/**
	 * Invalid license type. Make sure floating license is not being used.
	 */
	LA_E_LICENSE_TYPE: 55,

	/**
	 * Invalid offline activation response file.
	 */
	LA_E_OFFLINE_RESPONSE_FILE: 56,

	/**
	 * The offline activation response has expired.
	 */
	LA_E_OFFLINE_RESPONSE_FILE_EXPIRED: 57,

	/**
	 * The license has reached it's allowed activations limit.
	 */
	LA_E_ACTIVATION_LIMIT: 58,

	/**
	 * The license activation was deleted on the server.
	 */
	LA_E_ACTIVATION_NOT_FOUND: 59,

	/**
	 * The license has reached it's allowed deactivations limit.
	 */
	LA_E_DEACTIVATION_LIMIT: 60,

	/**
	 * Trial not allowed for the product.
	 */
	LA_E_TRIAL_NOT_ALLOWED: 61,

	/**
	 * Your account has reached it's trial activations limit.
	 */
	LA_E_TRIAL_ACTIVATION_LIMIT: 62,

	/**
	 * Machine fingerprint has changed since activation.
	 */
	LA_E_MACHINE_FINGERPRINT: 63,

	/**
	 * Metadata key length is more than 256 characters.
	 */
	LA_E_METADATA_KEY_LENGTH: 64,

	/**
	 * Metadata value length is more than 4096 characters.
	 */
	LA_E_METADATA_VALUE_LENGTH: 65,

	/**
	 * The license has reached it's metadata fields limit.
	 */
	LA_E_ACTIVATION_METADATA_LIMIT: 66,

	/**
	 * The trial has reached it's metadata fields limit.
	 */
	LA_E_TRIAL_ACTIVATION_METADATA_LIMIT: 67,

	/**
	 * The metadata key does not exist.
	 */
	LA_E_METADATA_KEY_NOT_FOUND: 68,

	/**
	 * The system time has been tampered (backdated).
	 */
	LA_E_TIME_MODIFIED: 69,

	/**
	 * Invalid version format.
	 */
	LA_E_RELEASE_VERSION_FORMAT: 70,

	/**
	 * Incorrect email or password.
	 */
	LA_E_AUTHENTICATION_FAILED: 71,

	/**
	 * The meter attribute does not exist.
	 */
	LA_E_METER_ATTRIBUTE_NOT_FOUND: 72,

	/**
	 * The meter attribute has reached it's usage limit.
	 */
	LA_E_METER_ATTRIBUTE_USES_LIMIT_REACHED: 73,

	/**
	 * Custom device fingerprint length is less than 64 characters
	 * or more than 256 characters.
	 */
	LA_E_CUSTOM_FINGERPRINT_LENGTH: 74,

	/**
	 * No product version is linked with the license.
	 */
	LA_E_PRODUCT_VERSION_NOT_LINKED: 75,

	/**
	 * The product version feature flag does not exist.
	 */
	LA_E_FEATURE_FLAG_NOT_FOUND: 76,

	/**
	 * The release version is not allowed.
	 */
	LA_E_RELEASE_VERSION_NOT_ALLOWED: 77,

	/**
	 * Release platform length is more than 256 characters.
	 */
	LA_E_RELEASE_PLATFORM_LENGTH: 78,

	/**
	 * Release channel length is more than 256 characters
	 */
	LA_E_RELEASE_CHANNEL_LENGTH: 79,

	/**
	 * Application is being run inside a virtual machine / hypervisor,
	 * and activation has been disallowed in the VM.
	 */
	LA_E_VM: 80,

	/**
	 * Country is not allowed.
	 */
	LA_E_COUNTRY: 81,

	/**
	 * IP address is not allowed.
	 */
	LA_E_IP: 82,

	/**
	 * Application is being run inside a container and
	 * activation has been disallowed in the container.
	 */
	LA_E_CONTAINER: 83,

	/**
     * Invalid release version. Make sure the release version
     * uses the following formats: x.x, x.x.x, x.x.x.x (where x is a number).
     */
	LA_E_RELEASE_VERSION: 84,

	/**
	 * Release platform not set.
	 */
	LA_E_RELEASE_PLATFORM: 85,
	
	/**
	 * Release channel not set.
	 */
	LA_E_RELEASE_CHANNEL: 86,

	/**
	 * The user is not authenticated.
	 */
	LA_E_USER_NOT_AUTHENTICATED: 87,

	/**
	 * The two-factor authentication code for the user authentication is missing.
	 */
	LA_E_TWO_FACTOR_AUTHENTICATION_CODE_MISSING: 88,

	/**
	 * The two-factor authentication code provided by the user is invalid.
	 */
	LA_E_TWO_FACTOR_AUTHENTICATION_CODE_INVALID: 89,

	/**
	 * Rate limit for API has reached, try again later.
	 */
	LA_E_RATE_LIMIT: 90,

	/**
	 * Server error.
	 */
	LA_E_SERVER: 91,

	/**
	 * Client error.
	 */
	LA_E_CLIENT: 92,
	
	/**
     * Invalid account ID.
     */
    LA_E_ACCOUNT_ID: 93,

	/**
	 * The user account has been temporarily locked for 5 mins due to 5 failed attempts.
	 */
	LA_E_LOGIN_TEMPORARILY_LOCKED: 100,

	/**
	 * Invalid authentication ID token.
	 */
	LA_E_AUTHENTICATION_ID_TOKEN_INVALID: 101,

	/**
	 * OIDC SSO is not enabled.
	 */
	LA_E_OIDC_SSO_NOT_ENABLED: 102,

	/**
	 * The allowed users for this account has reached its limit.
	 */
	LA_E_USERS_LIMIT_REACHED: 103,

	/**
	 * OS user has changed since activation and the license is user-locked.
	 */
	LA_E_OS_USER: 104,
	
	/**
	 * Invalid permission flag.
	 */
	LA_E_INVALID_PERMISSION_FLAG: 105,
	
	/**
	 * The free plan has reached it's activation limit.
	 */
	LA_E_FREE_PLAN_ACTIVATION_LIMIT_REACHED : 106,

    /**
     * The feature entitlements are invalid.
     */
    LA_E_FEATURE_ENTITLEMENTS_INVALID : 107,

    /**
     * The feature entitlement does not exist.
     */
    LA_E_FEATURE_ENTITLEMENT_NOT_FOUND : 108,

    /**
     * The entitlement set is not linked.
     */
    LA_E_ENTITLEMENT_SET_NOT_LINKED : 109,

};