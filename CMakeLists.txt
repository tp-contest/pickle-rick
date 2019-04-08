cmake_minimum_required(VERSION 3.0.0)
project(Rickled_Contest VERSION 0.1.0)

# Testing setup 

include(CTest)
include(GoogleTest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# FileStorage lib

include_directories(include)
set (
    STORAGE_SOURCES
    src/libFileBase/DummyFile.cpp
    src/libFileBase/Folder.cpp
    src/libFileBase/ContestFileManagerInMemory.cpp
    include/libFileStorage/IFileSystemObject.h
    include/libFileStorage/File.h
    include/libFileStorage/IStorageManager.h
    include/libFileStorage/ContestantInfo.h
    include/libFileStorage/IContestFileManager.h
    include/libFileStorage/ContestFileManagerInMemory.h
    include/libFileStorage/Folder.h
)

add_library(filestorage SHARED ${STORAGE_SOURCES})
target_include_directories(filestorage PRIVATE include/libFileStorage)

# GTest

add_executable (FS_gtest test/src/libFileBase/main.cpp)
target_link_libraries(FS_gtest filestorage ${GTEST_LIBRARIES} pthread)
gtest_discover_tests(FS_gtest)