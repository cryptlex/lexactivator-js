#include "napi.h"
#include "LexActivator.h"
#include <string>

using namespace ::std;

const char *MISSING_ARGUMENTS = "Wrong number of arguments";
const char *INVALID_ARGUMENT_TYPE = "Invalid argument type";

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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
    uint32_t arg1 = info[1].As<Napi::Number>().Uint32Value();
    return Napi::Number::New(env, SetProductId(arg0.c_str(), arg1));
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
    string arg1 = info[1].As<Napi::String>();
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
    Napi::Function arg0 = info[0].As<Napi::Function>();
    return Napi::Number::New(env, 0); //Napi::Number::New(env, SetLicenseCallback(arg0));
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
    string arg0 = info[0].As<Napi::String>();
    string arg1 = info[1].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
    string arg1 = info[1].As<Napi::String>();
    return Napi::Number::New(env, SetTrialActivationMetadata(arg0.c_str(), arg1.c_str()));
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
    string arg0 = info[0].As<Napi::String>();
    return Napi::Number::New(env, SetAppVersion(arg0.c_str()));
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    char *arg1 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetProductMetadata(arg0.c_str(), arg1, length));
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
    string arg0 = info[0].As<Napi::String>();
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    char *arg1 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseMetadata(arg0.c_str(), arg1, length));
}

Napi::Value getLicenseMeterAttribute(const Napi::CallbackInfo &info)
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
    string arg0 = info[0].As<Napi::String>();
    Napi::Uint32Array array1 = info[1].As<Napi::Uint32Array>();
    uint32_t *arg1 = reinterpret_cast<uint32_t *>(array1.ArrayBuffer().Data());
    Napi::Uint32Array array2 = info[2].As<Napi::Uint32Array>();
    uint32_t *arg2 = reinterpret_cast<uint32_t *>(array2.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseMeterAttribute(arg0.c_str(), arg1, arg2));
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
    char *arg0 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetLicenseKey(arg0, length));
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
    char *arg0 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
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
    char *arg0 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
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
    char *arg0 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
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
    string arg0 = info[0].As<Napi::String>();
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    char *arg1 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
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
    char *arg0 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
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
    string arg0 = info[0].As<Napi::String>();
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    char *arg1 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
    return Napi::Number::New(env, GetActivationMetadata(arg0.c_str(), arg1, length));
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
    Napi::Uint8Array array = info[1].As<Napi::Uint8Array>();
    size_t length = array.ElementLength();
    char *arg1 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
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
    char *arg0 = reinterpret_cast<char *>(array.ArrayBuffer().Data());
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

Napi::Value checkForReleaseUpdate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 4)
    {
        Napi::TypeError::New(env, MISSING_ARGUMENTS).ThrowAsJavaScriptException();
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
    if (!info[3].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, INVALID_ARGUMENT_TYPE).ThrowAsJavaScriptException();
        return env.Null();
    }
    string arg0 = info[0].As<Napi::String>();
    string arg1 = info[1].As<Napi::String>();
    string arg2 = info[2].As<Napi::String>();
    string arg3 = info[3].As<Napi::String>();
    return Napi::Number::New(env, 0); //Napi::Number::New(env, CheckForReleaseUpdate(arg0.c_str(), arg1.c_str(), arg2.c_str(), arg3));
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
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
    string arg0 = info[0].As<Napi::String>();
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
    exports["SetProductId"] = Napi::Function::New(env, setProductId);
    exports["SetLicenseKey"] = Napi::Function::New(env, setLicenseKey);
    exports["SetLicenseUserCredential"] = Napi::Function::New(env, setLicenseUserCredential);
    exports["SetLicenseCallback"] = Napi::Function::New(env, setLicenseCallback);
    exports["SetActivationMetadata"] = Napi::Function::New(env, setActivationMetadata);
    exports["SetTrialActivationMetadata"] = Napi::Function::New(env, setTrialActivationMetadata);
    exports["SetAppVersion"] = Napi::Function::New(env, setAppVersion);
    exports["SetNetworkProxy"] = Napi::Function::New(env, setNetworkProxy);
    exports["SetCryptlexHost"] = Napi::Function::New(env, setCryptlexHost);
    exports["GetProductMetadata"] = Napi::Function::New(env, getProductMetadata);
    exports["GetLicenseMetadata"] = Napi::Function::New(env, getLicenseMetadata);
    exports["GetLicenseMeterAttribute"] = Napi::Function::New(env, getLicenseMeterAttribute);
    exports["GetLicenseKey"] = Napi::Function::New(env, getLicenseKey);
    exports["GetLicenseExpiryDate"] = Napi::Function::New(env, getLicenseExpiryDate);
    exports["GetLicenseUserEmail"] = Napi::Function::New(env, getLicenseUserEmail);
    exports["GetLicenseUserName"] = Napi::Function::New(env, getLicenseUserName);
    exports["GetLicenseUserCompany"] = Napi::Function::New(env, getLicenseUserCompany);
    exports["GetLicenseUserMetadata"] = Napi::Function::New(env, getLicenseUserMetadata);
    exports["GetLicenseType"] = Napi::Function::New(env, getLicenseType);
    exports["GetActivationMetadata"] = Napi::Function::New(env, getActivationMetadata);
    exports["GetActivationMeterAttributeUses"] = Napi::Function::New(env, getActivationMeterAttributeUses);
    exports["GetServerSyncGracePeriodExpiryDate"] = Napi::Function::New(env, getServerSyncGracePeriodExpiryDate);
    exports["GetTrialActivationMetadata"] = Napi::Function::New(env, getTrialActivationMetadata);
    exports["GetTrialExpiryDate"] = Napi::Function::New(env, getTrialExpiryDate);
    exports["GetTrialId"] = Napi::Function::New(env, getTrialId);
    exports["GetLocalTrialExpiryDate"] = Napi::Function::New(env, getLocalTrialExpiryDate);
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