#!/bin/bash
set -euo pipefail

./gradlew assembleDebug \
  --daemon \
  --parallel \
  --configure-on-demand \
  --build-cache \
  -x lint \
  -x test

APK=app/build/outputs/apk/debug/app-debug.apk
adb install-multiple -r -t "$APK"

adb shell am start -S com.example.xwm/.MainActivity
