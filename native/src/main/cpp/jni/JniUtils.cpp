#include "JniUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * native char * to Java String
 */
jstring str2jstring(JNIEnv* env,const char* pt){
    jclass strClass = env->FindClass("Ljava/lang/String;");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = env->NewByteArray(strlen(pt));
    env->SetByteArrayRegion(bytes, 0, strlen(pt), (jbyte*)pt);
    jstring encoding = env->NewStringUTF("UTF8"); //GB2312");
    return (jstring)env->NewObject(strClass, ctorID, bytes, encoding);
}

/*
 * Java String to native  C string
 */
std::string jstring2str(JNIEnv* env, jstring jstr){
    if(env == NULL || jstr == NULL)
        return "";
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr,mid,strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr,JNI_FALSE);
    if(alen > 0)   {
        rtn = (char*)malloc(alen+10);
        memcpy(rtn,ba,alen);
        rtn[alen]='\0';
    }
    env->ReleaseByteArrayElements(barr,ba,0);
    if(rtn == NULL)
        return "";
    std::string stemp(rtn);
    free(rtn);
    return stemp;
}

#ifdef __cplusplus
}
#endif
