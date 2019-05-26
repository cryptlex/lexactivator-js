/* eslint-disable new-cap */
const FFI = require('ffi');
const ref = require('ref');
const refWchar = require('ref-wchar');

const libraryPath = process.platform == 'win32' ? './LexActivator' : './libLexActivator';

const LicenseCallback = function (callback) {
	return FFI.Callback('void', [ref.types.int], callback);
};

const SoftwareReleaseUpdateCallback = function (callback) {
	return FFI.Callback('void', [ref.types.int], callback);
};

const isWindows = function () {
	return process.platform == 'win32' ? true : false;
};

const uint32Ptr = ref.refType(ref.types.uint32);
const charPtr = isWindows() ? ref.refType(refWchar.string) : ref.refType(ref.types.char);
const stringType = isWindows() ? refWchar.string : 'string';


const LexActivatorNative = new FFI.Library(libraryPath, {
	SetProductFile: [ref.types.int, [
		stringType,
	]],
	SetProductData: [ref.types.int, [
		stringType,
	]],
	SetProductId: [ref.types.int, [
		stringType,
		ref.types.uint32,
	]],
	SetLicenseKey: [ref.types.int, [
		stringType,
	]],
	SetLicenseUserCredential: [ref.types.int, [
		stringType,
		stringType,
	]],
	SetLicenseCallback: [ref.types.int, [
		'pointer',
	]],
	SetActivationMetadata: [ref.types.int, [
		stringType,
		stringType,
	]],
	SetTrialActivationMetadata: [ref.types.int, [
		stringType,
		stringType,
	]],
	SetAppVersion: [ref.types.int, [
		stringType,
	]],
	SetNetworkProxy: [ref.types.int, [
		stringType,
	]],
	SetCryptlexHost: [ref.types.int, [
		stringType,
	]],
	GetProductMetadata: [ref.types.int, [
		stringType,
		charPtr,
		ref.types.uint32,
	]],
	GetLicenseMetadata: [ref.types.int, [
		stringType,
		charPtr,
		ref.types.uint32,
	]],
	GetLicenseMeterAttribute: [ref.types.int, [
		stringType,
		uint32Ptr,
		uint32Ptr
	]],
	GetLicenseKey: [ref.types.int, [
		charPtr,
		ref.types.uint32,
	]],
	GetLicenseExpiryDate: [ref.types.int, [
		uint32Ptr,
	]],
	GetLicenseUserEmail: [ref.types.int, [
		charPtr,
		ref.types.uint32,
	]],
	GetLicenseUserName: [ref.types.int, [
		charPtr,
		ref.types.uint32,
	]],
	GetLicenseUserCompany: [ref.types.int, [
		charPtr,
		ref.types.uint32,
	]],
	GetLicenseUserMetadata: [ref.types.int, [
		stringType,
		charPtr,
		ref.types.uint32,
	]],
	GetLicenseType: [ref.types.int, [
		charPtr,
		ref.types.uint32,
	]],
	GetActivationMetadata: [ref.types.int, [
		stringType,
		charPtr,
		ref.types.uint32,
	]],
	GetActivationMeterAttributeUses: [ref.types.int, [
		stringType,
		uint32Ptr
	]],
	GetServerSyncGracePeriodExpiryDate: [ref.types.int, [
		uint32Ptr,
	]],
	GetTrialActivationMetadata: [ref.types.int, [
		stringType,
		charPtr,
		ref.types.uint32,
	]],
	GetTrialExpiryDate: [ref.types.int, [
		uint32Ptr,
	]],
	GetTrialId: [ref.types.int, [
		charPtr,
		ref.types.uint32,
	]],
	GetLocalTrialExpiryDate: [ref.types.int, [
		uint32Ptr,
	]],
	CheckForReleaseUpdate: [ref.types.int, [
		stringType,
		stringType,
		stringType,
		'pointer'
	]],
	ActivateLicense: [ref.types.int, [
	]],
	ActivateLicenseOffline: [ref.types.int, [
		stringType,
	]],
	GenerateOfflineActivationRequest: [ref.types.int, [
		stringType,
	]],
	DeactivateLicense: [ref.types.int, [
	]],
	GenerateOfflineDeactivationRequest: [ref.types.int, [
		stringType,
	]],
	IsLicenseGenuine: [ref.types.int, [
	]],
	IsLicenseValid: [ref.types.int, [
	]],
	ActivateTrial: [ref.types.int, [
	]],
	ActivateTrialOffline: [ref.types.int, [
		stringType,
	]],
	GenerateOfflineTrialActivationRequest: [ref.types.int, [
		stringType,
	]],
	IsTrialGenuine: [ref.types.int, [
	]],
	ActivateLocalTrial: [ref.types.int, [
		ref.types.uint32
	]],
	IsLocalTrialGenuine: [ref.types.int, [
	]],
	ExtendLocalTrial: [ref.types.int, [
		ref.types.uint32
	]],
	IncrementActivationMeterAttributeUses: [ref.types.int, [
		stringType,
		ref.types.uint32
	]],
	DecrementActivationMeterAttributeUses: [ref.types.int, [
		stringType,
		ref.types.uint32
	]],
	ResetActivationMeterAttributeUses: [ref.types.int, [
		stringType
	]],
	Reset: [ref.types.int, [
	]],
});

const getStringBuffer = function (length) {
	const buffer = Buffer.alloc(length);
	buffer.type = isWindows() ? ref.refType(refWchar.string) : ref.refType(ref.types.char);
	return buffer;
};

const bufferToString = function (buffer) {
	if (isWindows()) {
		return buffer.toString('utf16le');
	} else {
		return buffer.toString();
	}
};

module.exports = { LexActivatorNative, LicenseCallback, SoftwareReleaseUpdateCallback, getStringBuffer, bufferToString };
