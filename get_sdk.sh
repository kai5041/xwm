#!/bin/bash
set -euo pipefail

BASE_URL="https://raw.githubusercontent.com/kai5041/xwm/master/include/xwm"
TARGET_DIR="include/xwm"

mkdir -p "$TARGET_DIR"
echo "Downloading XWM headers into $TARGET_DIR"

HEADERS=("Architecture.hpp" "Dispatcher.hpp" "defs.hpp" "utils.hpp" "core.hpp" "Memory.hpp")

for header in "${HEADERS[@]}"; do
    echo "Downloading $header..."
    curl -fsSL -L "$BASE_URL/$header" -o "$TARGET_DIR/$header"
done

echo "All headers downloaded successfully."
