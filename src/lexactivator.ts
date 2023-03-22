import { LexActivatorNative } from "./lexactivator-native.js";
import { LexStatusCodes } from "./lexstatus-codes.js";
import { LexActivatorException } from "./lexactivator-exception.js";
import { arrayToString } from "./lexactivator-native.js";
import { Release } from "./release.js"

/**
 *  @class LicenseMeterAttribute
 *  @constructor
 *  @property {name} name The name of the meter attribute.
 *  @property {number} allowedUses The allowed uses of the meter attribute.
 *  @property {totalUses} totalUses The total uses of the meter attribute.
 *  @property {grossUses} grossUses The gross uses of the meter attribute.
 */
export class LicenseMeterAttribute {
	name: string;
	allowedUses: number;
	totalUses: number;
	grossUses: number;

	constructor(name: string, allowedUses: number, totalUses: number, grossUses: number) {
		this.name = name;
		this.allowedUses = allowedUses;
		this.totalUses = totalUses;
		this.totalUses = totalUses;
		this.grossUses = grossUses;
	}
}
/**
 *  @class ProductVersionFeatureFlag
 *  @constructor
 *  @property {name} name The name of the feature flag.
 *  @property {enabled} enabled status of the feature flag.
 *  @property {data} data value of the feature flag.
 */
export class ProductVersionFeatureFlag {
	name: string;
	enabled: boolean;
	data: string;
	constructor(name: string, enabled: boolean, data: string) {
		this.name = name;
		this.enabled = enabled;
		this.data = data;
	}
}

/**
 * @class OrganizationAddress
 * @constructor
 * @property {string} addressLine1 
 * @property {string} addressLine2
 * @property {string} city
 * @property {string} state
 * @property {string} country
 * @property {string} postalCode
 */
export class OrganizationAddress {
    addressLine1: string;
    addressLine2: string;
    city: string;
    state: string;
    country: string;
    postalCode: string;
	constructor(addressLine1: string = '', addressLine2: string = '', city: string = '', state: string = '', country: string = '', postalCode: string =''){
		this.addressLine1 = addressLine1;
		this.addressLine2 = addressLine2;
		this.city = city;
		this.state = state;
		this.country = country;
		this.postalCode = postalCode;
	}
};

export type ActivationModes = 'online' | 'offline';

/**
 *  @class ActivationMode
 *  @constructor
 *  @property {ActivationModes} initialMode initial mode of activation.
 *  @property {ActivationModes} currentmode current mode of activation.
 */
export class ActivationMode {
	initialMode: ActivationModes;
	currentMode: ActivationModes;

	constructor(initialMode: ActivationModes, currentMode: ActivationModes) {
		this.initialMode = initialMode;
		this.currentMode = currentMode;
	}
}
/** Types of licenses supported by LexActivator. Values returned by `GetLicenseType()` */
export type LicenseType = 'node-locked' | 'hosted-floating';

/**
 * A callback function for CheckReleaseUpdate().
 *
 * @param {number} status - status of an update.
 * @param {Release} release - release object.
 * @returns {void}
 */
export type ReleaseUpdateCallback = (status: number, release: Release | {}) => void;

/**
 * @class LexActivator
 */
export class LexActivator {
	/**
	 * Sets the absolute path of the Product.dat file.
	 *
	 * This function must be called on every start of your program before any other
	 * functions are called.
	 *
	 * @param {string} filePath absolute path of the product file (Product.dat)
	 * @throws {LexActivatorException}
	 */
	static SetProductFile(filePath: string): void {
		const status = LexActivatorNative.SetProductFile(filePath);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Embeds the Product.dat file in the application.
	 *
	 * It can be used instead of SetProductFile() in case you want to embed the
	 * Product.dat file in your application.
	 *
	 * This function must be called on every start of your program before any other
	 * functions are called.
	 *
	 * @param {string} productData content of the Product.dat file
	 * @throws {LexActivatorException}
	 */
	static SetProductData(productData: string): void {
		const status = LexActivatorNative.SetProductData(productData);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the product id of your application.
	 *
	 * This function must be called on every start of your program before any other
	 * functions are called, with the exception of SetProductFile() or
	 * SetProductData() function.
	 *
	 * @param {string} productId the unique product id of your application as mentioned on
	 * the product page in the dashboard.
	 * @param {PermissionFlags} flag depending upon whether your application requires admin/root
	 * permissions to run or not, this parameter can have one of the following values:
	 * LA_SYSTEM, LA_USER, LA_IN_MEMORY
	 * @throws {LexActivatorException}
	 */
	static SetProductId(productId: string, flag: typeof PermissionFlags[keyof typeof PermissionFlags]): void {
		const status = LexActivatorNative.SetProductId(productId, flag);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	* In case you want to change the default directory used by LexActivator to
	* store the activation data on Linux and macOS, this function can be used to
	* set a different directory.

	* If you decide to use this function, then it must be called on every start of
	* your program before calling SetProductFile() or SetProductData() function.

	* Please ensure that the directory exists and your app has read and write
	* permissions in the directory.

	*
	* @param {string} directoryPath absolute path of the directory.
	* @throws {LexActivatorException}
	*/
	static SetDataDirectory(directoryPath: string): void {
		const status = LexActivatorNative.SetDataDirectory(directoryPath);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * In case you don't want to use the LexActivator's advanced
	 * device fingerprinting algorithm, this function can be used to set a custom
	 * device fingerprint.
	 *
	 * If you decide to use your own custom device fingerprint then this function must be
	 * called on every start of your program immediately after calling SetProductFile()
	 * or SetProductData() function.
	 *
	 * The license fingerprint matching strategy is ignored if this function is used.
	 *
	 * @param {string} fingerprint string of minimum length 64 characters and maximum length 256 characters
	 * @throws {LexActivatorException}
	 */
	static SetCustomDeviceFingerprint(fingerprint: string): void {
		const status = LexActivatorNative.SetCustomDeviceFingerprint(fingerprint);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the license key required to activate the license.
	 *
	 * @param {string} licenseKey a valid license key.
	 * @throws {LexActivatorException}
	 */
	static SetLicenseKey(licenseKey: string): void {
		const status = LexActivatorNative.SetLicenseKey(licenseKey);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the license user email and password for authentication.
	 *
	 * This function must be called before ActivateLicense() or IsLicenseGenuine()
	 * function if requireAuthentication property of the license is set to true.
	 *
	 * @param {string} email user email address.
	 * @param {string} password user password.
	 * @throws {LexActivatorException}
	 */
	static SetLicenseUserCredential(email: string, password: string): void {
		const status = LexActivatorNative.SetLicenseUserCredential(email, password);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets server sync callback function.
	 *
	 * Whenever the server sync occurs in a separate thread, and server returns the
	 * response, event listener function gets invoked with the following status
	 * codes: LA_OK, LA_EXPIRED, LA_SUSPENDED, LA_E_REVOKED,
	 * LA_E_ACTIVATION_NOT_FOUND, LA_E_MACHINE_FINGERPRINT LA_E_COUNTRY, LA_E_INET,
	 * LA_E_SERVER, LA_E_RATE_LIMIT, LA_E_IP
	 *
	 * @param {function(number)} licenseCallback callback function
	 * @throws {LexActivatorException}
	 */
	// eslint-disable-next-line @typescript-eslint/no-explicit-any
	static SetLicenseCallback(licenseCallback: (x: number) => any): void {
		const status = LexActivatorNative.SetLicenseCallback(licenseCallback);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the lease duration for the activation.
	 * 
	 * The activation lease duration is honoured when the allow client
	 * lease duration property is enabled.
	 * 
	 * @param {number} leaseDuration 
	 * @throws {LexActivatorException}
	 */
	static SetActivationLeaseDuration(leaseDuration: number): void {
		const status = LexActivatorNative.SetActivationLeaseDuration(leaseDuration);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the activation metadata.
	 *
	 * The metadata appears along with the activation details of the license in
	 * dashboard.
	 *
	 * @param {string} key string of maximum length 256 characters with utf-8 encoding.
	 * @param {string} value string of maximum length 256 characters with utf-8 encoding.
	 * @throws {LexActivatorException}
	 */
	static SetActivationMetadata(key: string, value: string): void {
		const status = LexActivatorNative.SetActivationMetadata(key, value);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the trial activation metadata.
	 *
	 * The metadata appears along with the trial activation details of the product
	 * in dashboard.
	 *
	 * @param {string} key string of maximum length 256 characters with utf-8 encoding.
	 * @param {string} value string of maximum length 256 characters with utf-8 encoding.
	 * @throws {LexActivatorException}
	 */
	static SetTrialActivationMetadata(key: string, value: string): void {
		const status = LexActivatorNative.SetTrialActivationMetadata(key, value);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the current app version of your application.
	 *
	 * The app version appears along with the activation details in dashboard. It is
	 * also used to generate app analytics.
	 *
	 * @param {string} appVersion string of maximum length 256 characters with utf-8 encoding.
	 * @throws {LexActivatorException}
	 */
	static SetAppVersion(appVersion: string): void {
		const status = LexActivatorNative.SetAppVersion(appVersion);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the current release version of your application.
	 * 
	 * The release version appears along with the activation details in dashboard.
	 * 
	 * @param {string} releaseVersion string in following allowed formats: x.x, x.x.x, x.x.x.x
	 * @throws {LexActivatorException} 
	 */
	static SetReleaseVersion(releaseVersion: string): void {
		const status = LexActivatorNative.SetReleaseVersion(releaseVersion);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the release published date of your application.
	 * 
	 * @param {number} releasePublishedDate unix timestamp of release published date.
	 * @throws {LexActivatorException}
	 */
	static SetReleasePublishedDate(releasePublishedDate: number): void {
		const status = LexActivatorNative.SetReleasePublishedDate(releasePublishedDate);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the release platform e.g. windows, macos, linux
	 * 
	 * The release platform appears along with the activation details in dashboard.
	 * 
	 * @param {string} releasePlatform release platform e.g. windows, macos, linux
	 * @throws {LexActivatorException} 
	 */
	static SetReleasePlatform(releasePlatform: string): void {
		const status = LexActivatorNative.SetReleasePlatform(releasePlatform);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the release channel e.g. stable, beta
	 * 
	 * The release channel appears along with the activation details in dashboard.
	 * 
	 * @param {string} releaseChannel release channel e.g. stable
	 * @throws {LexActivatorException} 
	 */
	static SetReleaseChannel(releaseChannel: string): void {
		const status = LexActivatorNative.SetReleaseChannel(releaseChannel);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the meter attribute uses for the offline activation request.
	 *
	 * This function should only be called before GenerateOfflineActivationRequest()
	 * function to set the meter attributes in case of offline activation.
	 *
	 * @param {string} name name of the meter attribute
	 * @param {number} uses the uses value
	 * @throws {LexActivatorException}
	 */
	static SetOfflineActivationRequestMeterAttributeUses(name: string, uses: number): void {
		const status = LexActivatorNative.SetOfflineActivationRequestMeterAttributeUses(name, uses);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Sets the network proxy to be used when contacting CryptLex servers.
	 *
	 * The proxy format should be: [protocol://][username:password@]machine[:port]
	 *
	 * Note: Proxy settings of the computer are automatically detected. So,
	 * in most of the cases you don't need to care whether your user is behind a
	 * proxy server or not.
	 *
	 * @param {string} proxy proxy having correct proxy format
	 * @throws {LexActivatorException}
	 */
	static SetNetworkProxy(proxy: string): void {
		const status = LexActivatorNative.SetNetworkProxy(proxy);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * In case you are running Cryptlex on-premise, you can set the host for your
	 * on-premise server.
	 *
	 * @param {string} host the address of the Cryptlex on-premise server
	 * @throws {LexActivatorException}
	 */
	static SetCryptlexHost(host: string): void {
		const status = LexActivatorNative.SetCryptlexHost(host);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the product metadata as set in the dashboard.
	 *
	 * This is available for trial as well as license activations.
	 *
	 * @param {string} key metadata key to retrieve the value
	 * @return {string} value of metadata for the key
	 * @throws {LexActivatorException}
	 */
	static GetProductMetadata(key: string): string {
		const array = new Uint8Array(4096);
		const status = LexActivatorNative.GetProductMetadata(key, array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the product version name.
	 * @return {string} name of the product version
	 * @throws {LexActivatorException} 
	 */
	static GetProductVersionName(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetProductVersionName(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the product version display name.
	 * @return {string}  display name of the product version
	 * @throws {LexActivatorException} 
	 */
	static GetProductVersionDisplayName(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetProductVersionDisplayName(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the product version feature flag.
	 * @param {string} name name of the feature flag 
	 * @returns {ProductVersionFeatureFlag} product version feature flag.
	 * @throws {LexActivatorException}
	 */
	static GetProductVersionFeatureFlag(name: string): ProductVersionFeatureFlag {
		const enabled = new Uint32Array(1);
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetProductVersionFeatureFlag(name, enabled, array, array.length);
		if (status !== LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return new ProductVersionFeatureFlag(name, (enabled[0] ? enabled[0] : 0) > 0, arrayToString(array));
	}

	/**
	 * Gets the license metadata as set in the dashboard.
	 *
	 * @param {string} key metadata key to retrieve the value
	 * @return {string} value of metadata for the key
	 * @throws {LexActivatorException}
	 */
	static GetLicenseMetadata(key: string): string {
		const array = new Uint8Array(4096);
		const status = LexActivatorNative.GetLicenseMetadata(key, array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the license meter attribute allowed, total and gross uses.
	 *
	 * @param {string} name name of the meter attribute
	 * @return {LicenseMeterAttribute} values of meter attribute allowed, total and gross uses
	 * @throws {LexActivatorException}
	 */
	static GetLicenseMeterAttribute(name: string): LicenseMeterAttribute {
		const allowedUses = new Uint32Array(1);
		const totalUses = new Uint32Array(1);
		const grossUses = new Uint32Array(1);
		const status = LexActivatorNative.GetLicenseMeterAttribute(name, allowedUses, totalUses, grossUses);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return new LicenseMeterAttribute(name, allowedUses[0] ? allowedUses[0] : 0, totalUses[0] ? totalUses[0] : 0, grossUses[0] ? grossUses[0] : 0);
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the license key used for activation.
	 *
	 * @return {string} the license key
	 * @throws {LexActivatorException}
	 */
	static GetLicenseKey(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetLicenseKey(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the allowed activations of the license.
	 *
	 * @return {number} the allowed activations
	 * @throws {LexActivatorException}
	 */
	static GetLicenseAllowedActivations(): number {
		const allowedActivations = new Uint32Array(1);
		const status = LexActivatorNative.GetLicenseAllowedActivations(allowedActivations);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return allowedActivations[0] ? allowedActivations[0] : 0;
			case LexStatusCodes.LA_FAIL:
				return 0;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the total activations of the license.
	 *
	 * @return {number} the total activations
	 * @throws {LexActivatorException}
	 */
	static GetLicenseTotalActivations(): number {
		const totalActivations = new Uint32Array(1);
		const status = LexActivatorNative.GetLicenseTotalActivations(totalActivations);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return totalActivations[0] ? totalActivations[0] : 0;
			case LexStatusCodes.LA_FAIL:
				return 0;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the license expiry date timestamp.
	 *
	 * @return {number} the timestamp
	 * @throws {LexActivatorException}
	 */
	static GetLicenseExpiryDate(): number {
		const expiryDate = new Uint32Array(1);
		const status = LexActivatorNative.GetLicenseExpiryDate(expiryDate);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return expiryDate[0] ? expiryDate[0] : 0;
			case LexStatusCodes.LA_FAIL:
				return 0;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the license maintenance expiry date timestamp.
	 *
	 * @return {number} the timestamp
	 * @throws {LexActivatorException}
	 */
	static GetLicenseMaintenanceExpiryDate(): number {
		const maintenanceExpiryDate = new Uint32Array(1);
		const status = LexActivatorNative.GetLicenseMaintenanceExpiryDate(maintenanceExpiryDate);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return maintenanceExpiryDate[0] ? maintenanceExpiryDate[0] : 0;
			case LexStatusCodes.LA_FAIL:
				return 0;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the maximum allowed release version of the license.
	 * 
	 * @return {string} max allowed release version
	 * @throws {LexActivatorException}
	 */
	static GetLicenseMaxAllowedReleaseVersion(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetLicenseMaxAllowedReleaseVersion(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the email associated with license user.
	 *
	 * @return {string} the license user email
	 * @throws {LexActivatorException}
	 */
	static GetLicenseUserEmail(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetLicenseUserEmail(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the name associated with the license user.
	 *
	 * @return {string} the license user name
	 * @throws {LexActivatorException}
	 */
	static GetLicenseUserName(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetLicenseUserName(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the company associated with the license user.
	 *
	 * @return {string} the license user company
	 * @throws {LexActivatorException}
	 */
	static GetLicenseUserCompany(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetLicenseUserCompany(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the metadata associated with the license user.
	 *
	 * @param key metadata key to retrieve the value
	 * @return {string} value of metadata for the key
	 * @throws {LexActivatorException}
	 */
	static GetLicenseUserMetadata(key: string): string {
		const array = new Uint8Array(4096);
		const status = LexActivatorNative.GetLicenseUserMetadata(key, array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the organization name associated with the license.
	 * 
	 * @return {string} the license organization name
	 * @throws {LexActivatorException}
	 */
	static GetLicenseOrganizationName(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetLicenseOrganizationName(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the organization address associated with the license.
	 * 
	 * @return {OrganizationAddress} the license organization address
	 * @throws {LexActivatorException}
	 */
	static GetLicenseOrganizationAddress(): OrganizationAddress {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetLicenseOrganizationAddress(array, array.length)
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		let addressObject;
		try {
			addressObject = JSON.parse(arrayToString(array));
		} catch {
			addressObject = {};
		}
		const organizationAddress = new OrganizationAddress(addressObject.addressLine1, addressObject.addressLine2, addressObject.city, addressObject.state, addressObject.country, addressObject.postalCode);
		return organizationAddress;
	}

	/**
	 * Gets the license type.
	 *
	 * @return {LicenseType} the license type: node-locked or hosted-floating
	 * @throws {LexActivatorException}
	 */
	static GetLicenseType(): LicenseType {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetLicenseType(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array) as LicenseType;
	}

	/**
	 * Gets the activation metadata.
	 *
	 * @param {string} key metadata key to retrieve the value
	 * @return {string} value of metadata for the key
	 * @throws {LexActivatorException}
	 */
	static GetActivationMetadata(key: string): string {
		const array = new Uint8Array(4096);
		const status = LexActivatorNative.GetActivationMetadata(key, array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the initial and current mode of activation (online or offline).
	 *
	 * @return {ActivationMode} mode of activation.
	 * @throws {LexActivatorException}
	 */
	static GetActivationMode(): ActivationMode {
		const array1 = new Uint8Array(4096);
		const array2 = new Uint8Array(4096);
		const status = LexActivatorNative.GetActivationMode(array1, array1.length, array2, array2.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return new ActivationMode(arrayToString(array1) as ActivationModes, arrayToString(array2) as ActivationModes);
	}

	/**
	 * Gets the meter attribute uses consumed by the activation.
	 *
	 * @param {string} name name of the meter attribute
	 * @return {number} value of meter attribute uses by the activation
	 * @throws {LexActivatorException}
	 */
	static GetActivationMeterAttributeUses(name: string): number {
		const uses = new Uint32Array(1);
		const status = LexActivatorNative.GetActivationMeterAttributeUses(name, uses);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return uses[0] ? uses[0] : 0;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the server sync grace period expiry date timestamp.
	 *
	 * @return {number} the timestamp
	 * @throws {LexActivatorException}
	 */
	static GetServerSyncGracePeriodExpiryDate(): number {
		const expiryDate = new Uint32Array(1);
		const status = LexActivatorNative.GetServerSyncGracePeriodExpiryDate(expiryDate);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return expiryDate[0] ? expiryDate[0] : 0;
			case LexStatusCodes.LA_FAIL:
				return 0;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the trial activation metadata.
	 *
	 * @param {string} key metadata key to retrieve the value
	 * @return {string} value of metadata for the key
	 * @throws {LexActivatorException}
	 */
	static GetTrialActivationMetadata(key: string): string {
		const array = new Uint8Array(4096);
		const status = LexActivatorNative.GetTrialActivationMetadata(key, array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the trial expiry date timestamp.
	 *
	 * @return {number} the timestamp
	 * @throws {LexActivatorException}
	 */
	static GetTrialExpiryDate(): number {
		const expiryDate = new Uint32Array(1);
		const status = LexActivatorNative.GetTrialExpiryDate(expiryDate);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return expiryDate[0] ? expiryDate[0] : 0;
			case LexStatusCodes.LA_FAIL:
				return 0;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the trial activation id. Used in case of trial extension.
	 *
	 * @return {string} the trial id
	 * @throws {LexActivatorException}
	 */
	static GetTrialId(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetTrialId(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Gets the local trial expiry date timestamp.
	 *
	 * @return {number} the timestamp
	 * @throws {LexActivatorException}
	 */
	static GetLocalTrialExpiryDate(): number {
		const expiryDate = new Uint32Array(1);
		const status = LexActivatorNative.GetLocalTrialExpiryDate(expiryDate);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return expiryDate[0] ? expiryDate[0] : 0;
			case LexStatusCodes.LA_FAIL:
				return 0;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Gets the version of this library.
	 *
	 * @return {string} the library version
	 * @throws {LexActivatorException}
	 */
	static GetLibraryVersion(): string {
		const array = new Uint8Array(1024);
		const status = LexActivatorNative.GetLibraryVersion(array, array.length);
		if (status != LexStatusCodes.LA_OK) {
			throw new LexActivatorException(status);
		}
		return arrayToString(array);
	}

	/**
	 * Checks whether a new release is available for the product.
	 * 
	 * This function should only be used if you manage your releases through
	 * Cryptlex release management API.
	 * 
	 * When this function is called the release update callback function gets invoked 
	 * which passes the following parameters:
	 * 
	 * status - determines if any update is available or not. It also determines whether 
	 * an update is allowed or not. Expected values are LA_RELEASE_UPDATE_AVAILABLE,
	 * LA_RELEASE_UPDATE_NOT_AVAILABLE, LA_RELEASE_UPDATE_AVAILABLE_NOT_ALLOWED.
	 * 
	 * release- object of the latest available release, the object passed depends on the 
	 * flag LA_RELEASES_ALLOWED or LA_RELEASES_ALL provided to the CheckReleaseUpdate().
	 * 
	 * @param {function(number, Release)} releaseUpdateCallback callback function.
	 * @param {ReleaseFlags} flag if an update only related to the allowed release is required, 
	 * then use LA_RELEASES_ALLOWED. Otherwise, if an update for all the releases is
	 * required, then use LA_RELEASES_ALL.
	 * @throws {LexActivatorException}
	 */
	static CheckReleaseUpdate(releaseUpdateCallback: ReleaseUpdateCallback, flag: typeof ReleaseFlags[keyof typeof ReleaseFlags]): void {
		const internalReleaseUpdateCallback = function (status: number, releaseJson: string ): void {
			let release: Release | {} = {};
			if (releaseJson) {
				try {
					release = JSON.parse(releaseJson);
				} catch {}
			}
			releaseUpdateCallback(status, release);
		};
		const status = LexActivatorNative.CheckReleaseUpdate(internalReleaseUpdateCallback, flag);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Checks whether a new release is available for the product.
	 *
	 * This function should only be used if you manage your releases through
	 * Cryptlex release management API.
	 *
	 * @param {string} platform release platform e.g. windows, macos, linux
	 * @param {string} version current release version
	 * @param {string} channel release channel e.g. stable
	 * @param {function(number)} releaseCallback callback function
	 * @throws {LexActivatorException}
	 */
	static CheckForReleaseUpdate(platform: string, version: string, channel: string, releaseCallback: (x: number) => number): void {
		const status = LexActivatorNative.CheckForReleaseUpdate(platform, version, channel, releaseCallback);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Activates the license by contacting the Cryptlex servers. It validates the
	 * key and returns with encrypted and digitally signed token which it stores and
	 * uses to activate your application.
	 *
	 * This function should be executed at the time of registration, ideally on a
	 * button click.
	 *
	 * @return {number} LA_OK, LA_EXPIRED, LA_SUSPENDED, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static ActivateLicense(): number {
		const status = LexActivatorNative.ActivateLicense();
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_EXPIRED:
				return LexStatusCodes.LA_EXPIRED;
			case LexStatusCodes.LA_SUSPENDED:
				return LexStatusCodes.LA_SUSPENDED;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Activates the license using the offline activation response file.
	 *
	 * @param {string} filePath path of the offline activation response file.
	 * @return {number} LA_OK, LA_EXPIRED, LA_SUSPENDED, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static ActivateLicenseOffline(filePath: string): number {
		const status = LexActivatorNative.ActivateLicenseOffline(filePath);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_EXPIRED:
				return LexStatusCodes.LA_EXPIRED;
			case LexStatusCodes.LA_SUSPENDED:
				return LexStatusCodes.LA_SUSPENDED;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Generates the offline activation request needed for generating offline
	 * activation response in the dashboard.
	 *
	 * @param {string} filePath path of the file for the offline request.
	 * @throws {LexActivatorException}
	 */
	static GenerateOfflineActivationRequest(filePath: string): void {
		const status = LexActivatorNative.GenerateOfflineActivationRequest(filePath);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Deactivates the license activation and frees up the correponding activation
	 * slot by contacting the Cryptlex servers.
	 *
	 * This function should be executed at the time of deregistration, ideally on a
	 * button click.
	 *
	 * @return {number} LA_OK, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static DeactivateLicense(): number {
		const status = LexActivatorNative.DeactivateLicense();
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Generates the offline deactivation request needed for deactivation of the
	 * license in the dashboard and deactivates the license locally.
	 *
	 * A valid offline deactivation file confirms that the license has been
	 * successfully deactivated on the user's machine.
	 *
	 * @param {string} filePath path of the file for the offline deactivation request.
	 * @return {number} LA_OK, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static GenerateOfflineDeactivationRequest(filePath: string): number {
		const status = LexActivatorNative.GenerateOfflineDeactivationRequest(filePath);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * It verifies whether your app is genuinely activated or not. The verification
	 * is done locally by verifying the cryptographic digital signature fetched at
	 * the time of activation.
	 *
	 * After verifying locally, it schedules a server check in a separate thread.
	 * After the first server sync it periodically does further syncs at a frequency
	 * set for the license.
	 *
	 * In case server sync fails due to network error, and it continues to fail for
	 * fixed number of days (grace period), the function returns
	 * LA_GRACE_PERIOD_OVER instead of LA_OK.
	 *
	 * This function must be called on every start of your program to verify the
	 * activation of your app.
	 *
	 * Note: If application was activated offline using
	 * ActivateLicenseOffline() function, you may want to set grace period to 0 to
	 * ignore grace period.
	 *
	 * @return {number} LA_OK, LA_EXPIRED, LA_SUSPENDED, LA_GRACE_PERIOD_OVER, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static IsLicenseGenuine(): number {
		const status = LexActivatorNative.IsLicenseGenuine();
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_EXPIRED:
				return LexStatusCodes.LA_EXPIRED;
			case LexStatusCodes.LA_SUSPENDED:
				return LexStatusCodes.LA_SUSPENDED;
			case LexStatusCodes.LA_GRACE_PERIOD_OVER:
				return LexStatusCodes.LA_GRACE_PERIOD_OVER;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * It verifies whether your app is genuinely activated or not. The verification
	 * is done locally by verifying the cryptographic digital signature fetched at
	 * the time of activation.
	 *
	 * This is just an auxiliary function which you may use in some specific cases,
	 * when you want to skip the server sync.
	 *
	 * Note: You may want to set grace period to 0 to ignore grace period.
	 *
	 * @return {number} LA_OK, LA_EXPIRED, LA_SUSPENDED, LA_GRACE_PERIOD_OVER, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static IsLicenseValid(): number {
		const status = LexActivatorNative.IsLicenseValid();
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_EXPIRED:
				return LexStatusCodes.LA_EXPIRED;
			case LexStatusCodes.LA_SUSPENDED:
				return LexStatusCodes.LA_SUSPENDED;
			case LexStatusCodes.LA_GRACE_PERIOD_OVER:
				return LexStatusCodes.LA_GRACE_PERIOD_OVER;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Starts the verified trial in your application by contacting the Cryptlex
	 * servers.
	 *
	 * This function should be executed when your application starts first time on
	 * the user's computer, ideally on a button click.
	 *
	 * @return {number} LA_OK, LA_TRIAL_EXPIRED
	 * @throws {LexActivatorException}
	 */
	static ActivateTrial(): number {
		const status = LexActivatorNative.ActivateTrial();
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_TRIAL_EXPIRED:
				return LexStatusCodes.LA_TRIAL_EXPIRED;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Activates the trial using the offline activation response file.
	 *
	 * @param {string} filePath path of the offline activation response file.
	 * @return {number} LA_OK, LA_TRIAL_EXPIRED, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static ActivateTrialOffline(filePath: string): number {
		const status = LexActivatorNative.ActivateTrialOffline(filePath);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_TRIAL_EXPIRED:
				return LexStatusCodes.LA_TRIAL_EXPIRED;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Generates the offline trial activation request needed for generating offline
	 * trial activation response in the dashboard.
	 *
	 * @param {string} filePath path of the file for the offline request
	 * @throws {LexActivatorException}
	 */
	static GenerateOfflineTrialActivationRequest(filePath: string): void {
		const status = LexActivatorNative.GenerateOfflineTrialActivationRequest(filePath);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * It verifies whether trial has started and is genuine or not. The verification
	 * is done locally by verifying the cryptographic digital signature fetched at
	 * the time of trial activation.
	 *
	 * This function must be called on every start of your program during the trial
	 * period.
	 *
	 * @return {number} LA_OK, LA_TRIAL_EXPIRED, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static IsTrialGenuine(): number {
		const status = LexActivatorNative.IsTrialGenuine();
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_TRIAL_EXPIRED:
				return LexStatusCodes.LA_TRIAL_EXPIRED;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Starts the local(unverified) trial.
	 *
	 * This function should be executed when your application starts first time on
	 * the user's computer, ideally on a button click.
	 *
	 * @param {number} trialLength trial length in days
	 * @return {number} LA_OK, LA_LOCAL_TRIAL_EXPIRED, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static ActivateLocalTrial(trialLength: number): number {
		const status = LexActivatorNative.ActivateLocalTrial(trialLength);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_LOCAL_TRIAL_EXPIRED:
				return LexStatusCodes.LA_LOCAL_TRIAL_EXPIRED;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * It verifies whether trial has started and is genuine or not. The verification
	 * is done locally.
	 *
	 * This function must be called on every start of your program during the trial period.
	 *
	 * @returns {number} LA_OK, LA_LOCAL_TRIAL_EXPIRED, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static IsLocalTrialGenuine(): number {
		const status = LexActivatorNative.IsLocalTrialGenuine();
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_LOCAL_TRIAL_EXPIRED:
				return LexStatusCodes.LA_LOCAL_TRIAL_EXPIRED;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Extends the local trial.
	 *
	 * This function is only meant for unverified trials.
	 *
	 * @param {number} trialExtensionLength number of days to extend the trial
	 * @returns {number} LA_OK, LA_FAIL
	 * @throws {LexActivatorException}
	 */
	static ExtendLocalTrial(trialExtensionLength: number): number {
		const status = LexActivatorNative.ExtendLocalTrial(trialExtensionLength);
		switch (status) {
			case LexStatusCodes.LA_OK:
				return LexStatusCodes.LA_OK;
			case LexStatusCodes.LA_FAIL:
				return LexStatusCodes.LA_FAIL;
			default:
				throw new LexActivatorException(status);
		}
	}

	/**
	 * Increments the meter attribute uses of the activation.
	 *
	 * @param {string} name name of the meter attribute
	 * @param {number} increment the increment value
	 * @throws {LexActivatorException}
	 */
	static IncrementActivationMeterAttributeUses(name: string, increment: number): void {
		const status = LexActivatorNative.IncrementActivationMeterAttributeUses(name, increment);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Decrements the meter attribute uses of the activation.
	 *
	 * @param {string} name name of the meter attribute
	 * @param {number} decrement the decrement value
	 * @throws {LexActivatorException}
	 */
	static DecrementActivationMeterAttributeUses(name: string, decrement: number): void {
		const status = LexActivatorNative.DecrementActivationMeterAttributeUses(name, decrement);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Resets the meter attribute uses of the activation.
	 *
	 * @param {string} name name of the meter attribute
	 * @throws {LexActivatorException}
	 */
	static ResetActivationMeterAttributeUses(name: string): void {
		const status = LexActivatorNative.ResetActivationMeterAttributeUses(name);
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}

	/**
	 * Resets the activation and trial data stored in the machine.
	 *
	 * This function is meant for developer testing only.
	 *
	 * @throws {LexActivatorException}
	 */
	static Reset(): void {
		const status = LexActivatorNative.Reset();
		if (LexStatusCodes.LA_OK != status) {
			throw new LexActivatorException(status);
		}
	}
}

export const PermissionFlags = {
	'LA_USER': 1,
	'LA_SYSTEM': 2,
	'LA_IN_MEMORY': 4
};

export const ReleaseFlags = {
	'LA_RELEASES_ALL': 1,
	'LA_RELEASES_ALLOWED': 2
}

module.exports = { LexActivator, LicenseMeterAttribute, LexStatusCodes, LexActivatorException, PermissionFlags, ReleaseFlags };
