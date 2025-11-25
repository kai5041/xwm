cmake_minimum_required(VERSION 3.22.1)
project("xwm")


set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../src")

file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

add_library(${CMAKE_PROJECT_NAME} SHARED
    native-lib.cpp
    ${SRC_FILES}
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    android
    log
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ../../../../../include)
