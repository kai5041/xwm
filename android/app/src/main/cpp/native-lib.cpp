#include <jni.h>
#include <string>
#include <sys/stat.h>

#include <fstream>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_xwm_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    const char* path = "/storage/emulated/0/xwm";
    struct stat info;
    bool exists = (stat(path, &info) == 0 && (info.st_mode & S_IFDIR));



    return env->NewStringUTF(exists ? "true" : "false");
}
