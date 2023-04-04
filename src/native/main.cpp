#include "LexActivator.h"
#include "CallbackWrapper.h"
#include <string>
#include <locale>
#include <map>

using namespace ::std;

#ifdef _WIN32
#include <codecvt>
typedef wchar_t CHARTYPE;
typedef wstring STRING;
#else
typedef char CHARTYPE;
typedef string STRING;
#endif

const char *MISSING_ARGUMENTS = "Wrong number of arguments";
const char *INVALID_ARGUMENT_TYPE = "Invalid argument type";
const char *MISSING_LICENSE_KEY = "License key not set";

map<STRING, CallbackWrapper *> LicenseCallbacks;
map<STRING, CallbackWrapper *> ReleaseCallbacks;
map<STRING, ReleaseUpdateCallbackWrapper *> ReleaseUpdateCallbacks;


STRING toEncodedString(Napi::String input)
{
#ifdef _WIN32
    u16string s = input.Utf16Value();
    wstring_convert<codecvt_utf16<wchar_t, 0x10ffff, little_endian>, wchar_t> converter;
    return converter.from_bytes(reinterpret_cast<const char *>(&s[0]), reinterpret_cast<const char *>(&s[0] + s.size()));
#else
    return input;
#endif
}

void licenseCallback(uint32_t status)
{
    CHARTYPE licenseKey[256];
    if (GetLicenseKey(licenseKey, 256) != LA_OK)
    {
        return;
    }
    LicenseCallbacks[STRING(licenseKey)]->status = status;
    LicenseCallbacks[STRING(licenseKey)]->Queue();
}

void softwareReleaseUpdateCallback(uint32_t status)
{
    CHARTYPE licenseKey[256];
    if (GetLicenseKey(licenseKey, 256) != LA_OK)
    {
        return;
    }
    ReleaseCallbacks[STRING(licenseKey)]->status = status;
    ReleaseCallbacks[STRING(licenseKey)]->Queue();
}

void releaseUpdateCallback(uint32_t status, const char *releaseJson)
{   
    CHARTYPE licenseKey[256];
    if (GetLicenseKey(licenseKey, 256) != LA_OK)
    {
        return;
    }
    ReleaseUpdateCallbacks[STRING(licenseKey)]->status = status;
    ReleaseUpdateCallbacks[STRING(licenseKey)]->releaseJson.assign(releaseJson);
    ReleaseUpdateCallbacks[STRING(licenseKey)]->Queue();
}

Napi::Value setProductFile(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetProductFile(arg0.c_str()));
}

Napi::Value setProductData(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetProductData(arg0.c_str()));
}

Napi::Value setProductId(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsNumber())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    uint32_t arg1 = info[1].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, SetProductId(arg0.c_str(), arg1));
}

Napi::Value setDataDirectory(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetDataDirectory(arg0.c_str()));
}

Napi::Value setCustomDeviceFingerprint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetCustomDeviceFingerprint(arg0.c_str()));
}

Napi::Value setLicenseKey(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetLicenseKey(arg0.c_str()));
}

Napi::Value setLicenseUserCredential(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    STRING arg1 = toEncodedString(info[1].As<Napi::String>());
    return Napi::Number::New(env, SetLicenseUserCredential(arg0.c_str(), arg1.c_str()));
}

Napi::Value setLicenseCallback(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsFunction())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Function callback = info[0].As<Napi::Function>();
    CHARTYPE licenseKey[256];
    int status = GetLicenseKey(licenseKey, 256);
    if (status != LA_OK)
    {
        Napi::Error::New(env, MISSING_LICENSE_KEY).ThrowAsJavaScriptException();
        return env.Null();
    }
    LicenseCallbacks[STRING(licenseKey)] = new CallbackWrapper(callback);
    LicenseCallbacks[STRING(licenseKey)]->SuppressDestruct();
    return Napi::Number::New(env, SetLicenseCallback(licenseCallback));
}

Napi::Value setActivationLeaseDuration(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsNumber())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    uint32_t arg0 = info[0].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, SetActivationLeaseDuration(arg0));
}

Napi::Value setActivationMetadata(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    STRING arg1 = toEncodedString(info[1].As<Napi::String>());
    return Napi::Number::New(env, SetActivationMetadata(arg0.c_str(), arg1.c_str()));
}

Napi::Value setTrialActivationMetadata(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    STRING arg1 = toEncodedString(info[1].As<Napi::String>());
    return Napi::Number::New(env, SetTrialActivationMetadata(arg0.c_str(), arg1.c_str()));
}

Napi::Value setOfflineActivationRequestMeterAttributeUses(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsNumber())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    uint32_t arg1 = info[1].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, SetOfflineActivationRequestMeterAttributeUses(arg0.c_str(), arg1));
}

Napi::Value setAppVersion(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetAppVersion(arg0.c_str()));
}

Napi::Value setReleaseVersion(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetReleaseVersion(arg0.c_str()));
}

Napi::Value setReleasePublishedDate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsNumber())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    uint32_t arg0 = info[0].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, SetReleasePublishedDate(arg0));
}

Napi::Value setReleasePlatform(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetReleasePlatform(arg0.c_str()));
}

Napi::Value setReleaseChannel(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetReleaseChannel(arg0.c_str()));
}
Napi::Value setNetworkProxy(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetNetworkProxy(arg0.c_str()));
}

Napi::Value setCryptlexHost(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, SetCryptlexHost(arg0.c_str()));
}

Napi::Value getProductMetadata(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg1 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetProductMetadata(arg0.c_str(), arg1, length));
}

Napi::Value getProductVersionName(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetProductVersionName(arg0, length));
}

Napi::Value getProductVersionDisplayName(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetProductVersionDisplayName(arg0, length));
}

Napi::Value getProductVersionFeatureFlag(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 3)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[2].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    Napi::Uint32Array array1 = info[1].As<Napi::Uint32Array>();
    uint32_t *arg1 = reinterpret_cast<uint32_t *>(array1.ArrayBuffer().Data());
    Napi::Uint8Array array2 = info[2].As<Napi::Uint8Array>();
    CHARTYPE *arg2 = reinterpret_cast<CHARTYPE *>(array2.ArrayBuffer().Data());
    size_t length = array2.ElementLength();
    return Napi::Number::New(env, GetProductVersionFeatureFlag(arg0.c_str(), arg1, arg2, length));
}

Napi::Value getLicenseMetadata(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg1 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseMetadata(arg0.c_str(), arg1, length));
}

Napi::Value getLicenseMeterAttribute(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 4)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[2].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[3].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    Napi::Uint32Array array1 = info[1].As<Napi::Uint32Array>();
    uint32_t *arg1 = reinterpret_cast<uint32_t *>(array1.ArrayBuffer().Data());
    Napi::Uint32Array array2 = info[2].As<Napi::Uint32Array>();
    uint32_t *arg2 = reinterpret_cast<uint32_t *>(array2.ArrayBuffer().Data());
    Napi::Uint32Array array3 = info[3].As<Napi::Uint32Array>();
    uint32_t *arg3 = reinterpret_cast<uint32_t *>(array3.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseMeterAttribute(arg0.c_str(), arg1, arg2, arg3));
}

Napi::Value getLicenseKey(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseKey(arg0, length));
}

Napi::Value getLicenseAllowedActivations(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint32Array array = info[0].As<Napi::Uint32Array>();
    uint32_t *arg0 = reinterpret_cast<uint32_t *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseAllowedActivations(arg0));
}

Napi::Value getLicenseTotalActivations(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint32Array array = info[0].As<Napi::Uint32Array>();
    uint32_t *arg0 = reinterpret_cast<uint32_t *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseTotalActivations(arg0));
}

Napi::Value getLicenseExpiryDate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint32Array array = info[0].As<Napi::Uint32Array>();
    uint32_t *arg0 = reinterpret_cast<uint32_t *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseExpiryDate(arg0));
}

Napi::Value getLicenseMaintenanceExpiryDate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint32Array array = info[0].As<Napi::Uint32Array>();
    uint32_t *arg0 = reinterpret_cast<uint32_t *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseMaintenanceExpiryDate(arg0));
}

Napi::Value getLicenseMaxAllowedReleaseVersion(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseMaxAllowedReleaseVersion(arg0, length));
}

Napi::Value getLicenseUserEmail(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseUserEmail(arg0, length));
}

Napi::Value getLicenseUserName(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseUserName(arg0, length));
}

Napi::Value getLicenseUserCompany(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseUserCompany(arg0, length));
}

Napi::Value getLicenseUserMetadata(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg1 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseUserMetadata(arg0.c_str(), arg1, length));
}

Napi::Value getLicenseType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseType(arg0, length));
}

Napi::Value getActivationMetadata(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg1 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetActivationMetadata(arg0.c_str(), arg1, length));
}

Napi::Value getActivationMode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 4) 
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[2].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array1 = info[0].As<Napi::Uint8Array>();
    size_t length1 = array1.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array1.ArrayBuffer().Data());
    Napi::Uint8Array array2 = info[2].As<Napi::Uint8Array>();
    size_t length2 = array2.ElementLength();
    CHARTYPE *arg2 = reinterpret_cast<CHARTYPE *>(array2.ArrayBuffer().Data());
    return Napi::Number::New(env, GetActivationMode(arg0, length1,  arg2, length2));
}

Napi::Value getActivationMeterAttributeUses(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    Napi::Uint32Array array = info[1].As<Napi::Uint32Array>();
    uint32_t *arg1 = reinterpret_cast<uint32_t *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetActivationMeterAttributeUses(arg0.c_str(), arg1));
}

Napi::Value getServerSyncGracePeriodExpiryDate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint32Array array = info[0].As<Napi::Uint32Array>();
    uint32_t *arg0 = reinterpret_cast<uint32_t *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetServerSyncGracePeriodExpiryDate(arg0));
}

Napi::Value getTrialActivationMetadata(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg1 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetTrialActivationMetadata(arg0.c_str(), arg1, length));
}

Napi::Value getTrialExpiryDate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint32Array array = info[0].As<Napi::Uint32Array>();
    uint32_t *arg0 = reinterpret_cast<uint32_t *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetTrialExpiryDate(arg0));
}

Napi::Value getTrialId(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetTrialId(arg0, length));
}

Napi::Value getLocalTrialExpiryDate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint32Array array = info[0].As<Napi::Uint32Array>();
    uint32_t *arg0 = reinterpret_cast<uint32_t *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLocalTrialExpiryDate(arg0));
}

Napi::Value getLibraryVersion(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsTypedArray())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Uint8Array array = info[0].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    CHARTYPE *arg0 = reinterpret_cast<CHARTYPE *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLibraryVersion(arg0, length));
}

Napi::Value checkReleaseUpdate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsFunction())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsNumber())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Function callback = info[0].As<Napi::Function>();
    uint32_t arg1 = info[1].As<Napi::Number>().Uint32Value();
    CHARTYPE licenseKey[256];
    int status = GetLicenseKey(licenseKey, 256);
    if (status != LA_OK)
    {
        Napi::Error::New(env, MISSING_LICENSE_KEY).ThrowAsJavaScriptException();
        return env.Null();
    }
    ReleaseUpdateCallbacks[STRING(licenseKey)] = new ReleaseUpdateCallbackWrapper(callback);
    ReleaseUpdateCallbacks[STRING(licenseKey)]->SuppressDestruct();
    return Napi::Number::New(env, CheckReleaseUpdateInternal(releaseUpdateCallback, arg1));
}

Napi::Value checkForReleaseUpdate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 4)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[2].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[3].IsFunction())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    STRING arg1 = toEncodedString(info[1].As<Napi::String>());
    STRING arg2 = toEncodedString(info[2].As<Napi::String>());
    Napi::Function callback = info[3].As<Napi::Function>();
    CHARTYPE licenseKey[256];
    int status = GetLicenseKey(licenseKey, 256);
    if (status != LA_OK)
    {
        Napi::Error::New(env, MISSING_LICENSE_KEY).ThrowAsJavaScriptException();
        return env.Null();
    }
    ReleaseCallbacks[STRING(licenseKey)] = new CallbackWrapper(callback);
    ReleaseCallbacks[STRING(licenseKey)]->SuppressDestruct();
    return Napi::Number::New(env, CheckForReleaseUpdate(arg0.c_str(), arg1.c_str(), arg2.c_str(), softwareReleaseUpdateCallback));
}

Napi::Value activateLicense(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), ActivateLicense());
}

Napi::Value activateLicenseOffline(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, ActivateLicenseOffline(arg0.c_str()));
}

Napi::Value generateOfflineActivationRequest(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, GenerateOfflineActivationRequest(arg0.c_str()));
}

Napi::Value deactivateLicense(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), DeactivateLicense());
}

Napi::Value generateOfflineDeactivationRequest(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, GenerateOfflineDeactivationRequest(arg0.c_str()));
}

Napi::Value isLicenseGenuine(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), IsLicenseGenuine());
}

Napi::Value isLicenseValid(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), IsLicenseValid());
}

Napi::Value activateTrial(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), ActivateTrial());
}

Napi::Value activateTrialOffline(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, ActivateTrialOffline(arg0.c_str()));
}

Napi::Value generateOfflineTrialActivationRequest(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, GenerateOfflineTrialActivationRequest(arg0.c_str()));
}

Napi::Value isTrialGenuine(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), IsTrialGenuine());
}

Napi::Value activateLocalTrial(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsNumber())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    uint32_t arg0 = info[0].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, ActivateLocalTrial(arg0));
}

Napi::Value isLocalTrialGenuine(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), IsLocalTrialGenuine());
}

Napi::Value extendLocalTrial(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsNumber())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    uint32_t arg0 = info[0].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, ExtendLocalTrial(arg0));
}

Napi::Value incrementActivationMeterAttributeUses(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsNumber())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    uint32_t arg1 = info[1].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, IncrementActivationMeterAttributeUses(arg0.c_str(), arg1));
}

Napi::Value decrementActivationMeterAttributeUses(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[1].IsNumber())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    uint32_t arg1 = info[1].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, DecrementActivationMeterAttributeUses(arg0.c_str(), arg1));
}

Napi::Value resetActivationMeterAttributeUses(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    STRING arg0 = toEncodedString(info[0].As<Napi::String>());
    return Napi::Number::New(env, ResetActivationMeterAttributeUses(arg0.c_str()));
}

Napi::Value reset(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), Reset());
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports["SetProductFile"] = Napi::Function::New(env, setProductFile);
    exports["SetProductData"] = Napi::Function::New(env, setProductData);
    exports["SetDataDirectory"] = Napi::Function::New(env, setDataDirectory);
    exports["SetCustomDeviceFingerprint"] = Napi::Function::New(env, setCustomDeviceFingerprint);
    exports["SetProductId"] = Napi::Function::New(env, setProductId);
    exports["SetLicenseKey"] = Napi::Function::New(env, setLicenseKey);
    exports["SetLicenseUserCredential"] = Napi::Function::New(env, setLicenseUserCredential);
    exports["SetLicenseCallback"] = Napi::Function::New(env, setLicenseCallback);
    exports["SetActivationMetadata"] = Napi::Function::New(env, setActivationMetadata);
    exports["SetTrialActivationMetadata"] = Napi::Function::New(env, setTrialActivationMetadata);
    exports["SetOfflineActivationRequestMeterAttributeUses"] = Napi::Function::New(env, setOfflineActivationRequestMeterAttributeUses);
    exports["SetAppVersion"] = Napi::Function::New(env, setAppVersion);
    exports["SetReleaseVersion"] = Napi::Function::New(env,setReleaseVersion);
    exports["SetReleasePublishedDate"] = Napi::Function::New(env,setReleasePublishedDate);
    exports["SetReleasePlatform"] = Napi::Function::New(env,setReleasePlatform);
    exports["SetReleaseChannel"] = Napi::Function::New(env,setReleaseChannel);
    exports["SetActivationLeaseDuration"] = Napi::Function::New(env, setActivationLeaseDuration);
    exports["SetNetworkProxy"] = Napi::Function::New(env, setNetworkProxy);
    exports["SetCryptlexHost"] = Napi::Function::New(env, setCryptlexHost);
    exports["GetProductMetadata"] = Napi::Function::New(env, getProductMetadata);
    exports["GetProductVersionName"] = Napi::Function::New(env, getProductVersionName);
    exports["GetProductVersionDisplayName"] = Napi::Function::New(env, getProductVersionDisplayName);
    exports["GetProductVersionFeatureFlag"] = Napi::Function::New(env, getProductVersionFeatureFlag);
    exports["GetLicenseMetadata"] = Napi::Function::New(env, getLicenseMetadata);
    exports["GetLicenseMeterAttribute"] = Napi::Function::New(env, getLicenseMeterAttribute);
    exports["GetLicenseKey"] = Napi::Function::New(env, getLicenseKey);
    exports["GetLicenseAllowedActivations"] = Napi::Function::New(env, getLicenseAllowedActivations);
    exports["GetLicenseTotalActivations"] = Napi::Function::New(env, getLicenseTotalActivations);
    exports["GetLicenseExpiryDate"] = Napi::Function::New(env, getLicenseExpiryDate);
    exports["GetLicenseMaintenanceExpiryDate"] = Napi::Function::New(env,getLicenseMaintenanceExpiryDate);
    exports["GetLicenseMaxAllowedReleaseVersion"] = Napi::Function::New(env, getLicenseMaxAllowedReleaseVersion);
    exports["GetLicenseUserEmail"] = Napi::Function::New(env, getLicenseUserEmail);
    exports["GetLicenseUserName"] = Napi::Function::New(env, getLicenseUserName);
    exports["GetLicenseUserCompany"] = Napi::Function::New(env, getLicenseUserCompany);
    exports["GetLicenseUserMetadata"] = Napi::Function::New(env, getLicenseUserMetadata);
    exports["GetLicenseType"] = Napi::Function::New(env, getLicenseType);
    exports["GetActivationMetadata"] = Napi::Function::New(env, getActivationMetadata);
    exports["GetActivationMode"] = Napi::Function::New(env, getActivationMode);
    exports["GetActivationMeterAttributeUses"] = Napi::Function::New(env, getActivationMeterAttributeUses);
    exports["GetServerSyncGracePeriodExpiryDate"] = Napi::Function::New(env, getServerSyncGracePeriodExpiryDate);
    exports["GetTrialActivationMetadata"] = Napi::Function::New(env, getTrialActivationMetadata);
    exports["GetTrialExpiryDate"] = Napi::Function::New(env, getTrialExpiryDate);
    exports["GetTrialId"] = Napi::Function::New(env, getTrialId);
    exports["GetLocalTrialExpiryDate"] = Napi::Function::New(env, getLocalTrialExpiryDate);
    exports["GetLibraryVersion"] = Napi::Function::New(env, getLibraryVersion);
    exports["CheckReleaseUpdate"] = Napi::Function::New(env, checkReleaseUpdate);
    exports["CheckForReleaseUpdate"] = Napi::Function::New(env, checkForReleaseUpdate);
    exports["ActivateLicense"] = Napi::Function::New(env, activateLicense);
    exports["ActivateLicenseOffline"] = Napi::Function::New(env, activateLicenseOffline);
    exports["GenerateOfflineActivationRequest"] = Napi::Function::New(env, generateOfflineActivationRequest);
    exports["DeactivateLicense"] = Napi::Function::New(env, deactivateLicense);
    exports["GenerateOfflineDeactivationRequest"] = Napi::Function::New(env, generateOfflineDeactivationRequest);
    exports["IsLicenseGenuine"] = Napi::Function::New(env, isLicenseGenuine);
    exports["IsLicenseValid"] = Napi::Function::New(env, isLicenseValid);
    exports["ActivateTrial"] = Napi::Function::New(env, activateTrial);
    exports["ActivateTrialOffline"] = Napi::Function::New(env, activateTrialOffline);
    exports["GenerateOfflineTrialActivationRequest"] = Napi::Function::New(env, generateOfflineTrialActivationRequest);
    exports["IsTrialGenuine"] = Napi::Function::New(env, isTrialGenuine);
    exports["ActivateLocalTrial"] = Napi::Function::New(env, activateLocalTrial);
    exports["IsLocalTrialGenuine"] = Napi::Function::New(env, isLocalTrialGenuine);
    exports["ExtendLocalTrial"] = Napi::Function::New(env, extendLocalTrial);
    exports["IncrementActivationMeterAttributeUses"] = Napi::Function::New(env, incrementActivationMeterAttributeUses);
    exports["DecrementActivationMeterAttributeUses"] = Napi::Function::New(env, decrementActivationMeterAttributeUses);
    exports["ResetActivationMeterAttributeUses"] = Napi::Function::New(env, resetActivationMeterAttributeUses);
    exports["Reset"] = Napi::Function::New(env, reset);
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)