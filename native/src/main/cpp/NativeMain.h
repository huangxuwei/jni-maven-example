#ifndef NATIVEMAIN_H
#define NATIVEMAIN_H

#include <string>

class NativeProc {
public:
    static NativeProc* getInstance()
    {
        if (mNativeProc == NULL) {
            mNativeProc = new NativeProc();
        }
        return mNativeProc;
    }

    void initialize();

    std::string commit(std::string data);

private:
    NativeProc() {}
    ~NativeProc() {}

private:
    static NativeProc* mNativeProc;
};

#endif
