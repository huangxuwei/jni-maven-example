#include "NativeMain.h"
#include "Example.h"

NativeProc* NativeProc::mNativeProc;

void NativeProc::initialize()
{
    return;
}

std::string NativeProc::commit(std::string data)
{
    return getString();
}
