#include "napi.h"

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