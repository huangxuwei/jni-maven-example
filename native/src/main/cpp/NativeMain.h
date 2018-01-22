#ifndef NATIVEMAIN_H
#define NATIVEMAIN_H

#include <string>

class NativeProc {
public:
    static NativeProc* getInstance()
    {
        static NativeProc* mNativeProc = new NativeProc();
        return mNativeProc;
    }

    void initialize();

    std::string commit(std::string data);

private:
    NativeProc() {}
    ~NativeProc() {}
};

#endif
