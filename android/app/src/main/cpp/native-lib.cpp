#include <filesystem>
#include <jni.h>
#include <string>
#include <vector>

#include <xwm/cli.hpp>
#include <xwm/utils.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_xwm_MainActivity_stringFromJNI(JNIEnv *env,
                                                jobject /* this */) {

  const char *path = "/storage/emulated/0/xwm/main.so";

  // Construct vector of strings for command
  std::vector<std::string> args = {"load", path};

  // Run the CLI command and get result
  int x = xwm::Cli().run(args);

  std::string msg = "";

  if (std::filesystem::exists(path)) {
    msg = "File exists ";
  } else {
    msg = "File does not exist ";
  }

  if (x == 5) {
    msg = "x is 5";
  } else {
    msg += std::to_string(x);
  }

  return env->NewStringUTF(msg.c_str());
}
