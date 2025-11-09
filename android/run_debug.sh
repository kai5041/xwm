#!/bin/bash
set -e
# Build APK
./gradlew assembleDebug

# Install APK
adb install -r app/build/outputs/apk/debug/app-debug.apk

# Launch app
adb shell monkey -p com.example.xwm -c android.intent.category.LAUNCHER 1
