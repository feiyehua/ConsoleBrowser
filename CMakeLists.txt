cmake_minimum_required(VERSION 3.5.0)
project(ConsoleBrowser VERSION 0.1.0 LANGUAGES C)
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.c")
add_executable(ConsoleBrowser main.c ${SRC_FILES})

