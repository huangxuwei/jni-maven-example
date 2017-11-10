#include "JniUtils.h"
#include "NativeMain.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_com_github_projects_demoproc_DemoProc_initialize(JNIEnv * jenv, jclass jcls) {
    NativeProc *mProc = NativeProc::getInstance();
    mProc->initialize();
}

JNIEXPORT jstring JNICALL Java_com_github_projects_demoproc_DemoProc_commit(JNIEnv *jenv, jclass jcls, jstring jstr) {
    NativeProc* mProc = NativeProc::getInstance();
    std::string in = jstring2str(jenv, jstr);
    std::string out = mProc->commit(in);
    return jenv->NewStringUTF(out.c_str());
}

#ifdef __cplusplus
}
#endif
