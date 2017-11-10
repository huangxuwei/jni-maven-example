#ifndef JNIUITILS_H
#define JNIUITILS_H

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

#include <jni.h>

jstring str2jstring(JNIEnv* env, const char* pat);
std::string jstring2str(JNIEnv* env, jstring jstr);

#ifdef __cplusplus
}
#endif
#endif
