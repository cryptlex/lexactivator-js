#ifndef SIZE_MAX
#define SIZE_MAX ((size_t)(-1))
#endif
#include "napi.h"
#include <string>

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
    std::string releaseJson;

private:
    void Execute()
    {
    }

    void OnOK()
    {
        Napi::HandleScope scope(Env());
        Callback().Call({Napi::Number::New(Env(), status), Napi::String::New(Env(), releaseJson)});
    }
};