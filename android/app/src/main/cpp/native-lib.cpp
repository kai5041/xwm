#include <jni.h>
#include <string>
#include <filesystem>
#include <unistd.h>

#include <xwm/version.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_harmonyren_xwm_MainActivity_startup(JNIEnv *env, jobject) {
    std::string msg = "NO_ERR";
    //if (std::filesystem::exists("/storage/emulated/0/xwm")) {
    //    chdir("/storage/emulated/0/xwm");
    //    msg = std::filesystem::exists("main.so") ? "main.so found" : "main.so not found";
    //
    //}

    return env->NewStringUTF(msg.c_str());
}
