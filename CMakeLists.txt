cmake_minimum_required(VERSION 3.0.0)
project(Rickled_Contest VERSION 0.1.0)

include(CTest)
enable_testing()

set (SOURCES src/Rickled_Contest.cpp include/File.h include/FileBase.h include/TextFile.h include/CommonFileBase.h)
add_executable(Rickled_Contest ${SOURCES})
target_include_directories(Rickled_Contest PRIVATE include)