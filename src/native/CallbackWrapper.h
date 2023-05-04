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

class CallbackWrapper : public Napi::AsyncWorker
{
public:
    CallbackWrapper(Napi::Function &callback) : Napi::AsyncWorker(callback)
    {
    }
    uint32_t status;

private:
    void Execute()
    {
    }

    void OnOK()
    {
        Napi::HandleScope scope(Env());
        Callback().Call({Napi::Number::New(Env(), status)});
    }
};

class ReleaseUpdateCallbackWrapper : public Napi::AsyncWorker
{
public:
    ReleaseUpdateCallbackWrapper(Napi::Function &callback) : Napi::AsyncWorker(callback)
    {
    }
    uint32_t status;
    STRING releaseJson;
    void* userData;

private:
    void Execute()
    {
    }

    void OnOK()
    {
        Napi::HandleScope scope(Env());
#ifdef _WIN32
        // convert STRING to utf16 encoded string
        const wchar_t *releaseJsonPtr = releaseJson.c_str();
        const char16_t *utf16StringPtr = reinterpret_cast<const char16_t *>(releaseJsonPtr);
        Callback().Call({Napi::Number::New(Env(), status), Napi::String::New(Env(), utf16StringPtr), Napi::External<void>::New(Env(), userData)});
#else
        Callback().Call({Napi::Number::New(Env(), status), Napi::String::New(Env(), releaseJson), Napi::External<void>::New(Env(), userData)});
#endif
    }
};