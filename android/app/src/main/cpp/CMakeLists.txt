cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("xwm")

# Collect all source files except main.cpp
file(GLOB_RECURSE XWM_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../src/*.cpp
)

# Remove main.cpp if it exists in the list
list(FILTER XWM_SOURCES EXCLUDE REGEX ".*/main\\.cpp$")

add_library(${CMAKE_PROJECT_NAME} SHARED
    ${XWM_SOURCES}
    native-lib.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../include
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    android
    log
)
