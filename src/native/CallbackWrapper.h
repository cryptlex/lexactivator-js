#ifndef CALLBACK_WRAPPER_H
#define CALLBACK_WRAPPER_H

#ifndef SIZE_MAX
#define SIZE_MAX ((size_t)(-1))
#endif
#include "napi.h"
#include <string>

#ifdef _WIN32
typedef std::wstring STRING;
#else
typedef std::string STRING;
#endif

struct CallbackData
{
    uint32_t status;
    virtual ~CallbackData() = default;
};

struct StatusCallbackData : public CallbackData
{
    StatusCallbackData(uint32_t s)
    {
        status = s;
    }
};

struct ReleaseUpdateCallbackData : public CallbackData
{
    STRING releaseJson;
    void *userData;

    ReleaseUpdateCallbackData(uint32_t s, const STRING &json, void *ud)
        : releaseJson(json), userData(ud)
    {
        status = s;
    }
};

class CallbackWrapper
{
public:
    CallbackWrapper(Napi::Env env, Napi::Function callback)
    {
        tsfn = Napi::ThreadSafeFunction::New(
            env,
            callback,
            "LexActivatorCallback",
            0,  // Unlimited queue
            1   // Initial thread count
        );
    }

    ~CallbackWrapper()
    {
        tsfn.Abort();
    }

    void Call(uint32_t status)
    {
        auto *data = new StatusCallbackData(status);
        napi_status napiStatus = tsfn.NonBlockingCall(data, InvokeStatusCallback);
        if (napiStatus != napi_ok)
        {
            delete data;
        }
    }

    void Call(uint32_t status, const STRING &releaseJson, void *userData)
    {
        auto *data = new ReleaseUpdateCallbackData(status, releaseJson, userData);
        napi_status napiStatus = tsfn.NonBlockingCall(data, InvokeReleaseUpdateCallback);
        if (napiStatus != napi_ok)
        {
            delete data;
        }
    }

private:
    Napi::ThreadSafeFunction tsfn;

    static void InvokeStatusCallback(Napi::Env env, Napi::Function jsCallback, StatusCallbackData *data)
    {
        if (env != nullptr && jsCallback != nullptr && data != nullptr)
        {
            Napi::HandleScope scope(env);
            jsCallback.Call({Napi::Number::New(env, data->status)});
        }
        delete data;
    }

    static void InvokeReleaseUpdateCallback(Napi::Env env, Napi::Function jsCallback, ReleaseUpdateCallbackData *data)
    {
        if (env != nullptr && jsCallback != nullptr && data != nullptr)
        {
            Napi::HandleScope scope(env);
#ifdef _WIN32
            const wchar_t *releaseJsonPtr = data->releaseJson.c_str();
            const char16_t *utf16StringPtr = reinterpret_cast<const char16_t *>(releaseJsonPtr);
            jsCallback.Call({Napi::Number::New(env, data->status), Napi::String::New(env, utf16StringPtr),Napi::External<void>::New(env, data->userData)});
#else
            jsCallback.Call({Napi::Number::New(env, data->status), Napi::String::New(env, data->releaseJson), Napi::External<void>::New(env, data->userData)});
#endif
        }
        delete data;
    }
};
#endif // CALLBACK_WRAPPER_H
