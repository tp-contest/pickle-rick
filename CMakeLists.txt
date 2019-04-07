cmake_minimum_required(VERSION 3.0.0)
project(Rickled_Contest VERSION 0.1.0)

# include(CTest)
# enable_testing()

# set (SOURCES src/Rickled_Contest.cpp include/File.h include/FileBase.h include/TextFile.h include/CommonFileBase.h)
# add_executable(filebase_stubs ${SOURCES})
# target_include_directories(filebase_stubs PRIVATE include)

include_directories(include)
set (
    STORAGE_SOURCES
    src/libFileBase/TextFile.cpp
    src/libFileBase/MemoryStorage.cpp
    src/libFileBase/MemoryStorageManager.cpp
    include/libFileStorage/IFile.h
    include/libFileStorage/IStorage.h
    include/libFileStorage/IStorageManager.h
    include/libFileStorage/TextFile.h
    include/libFileStorage/MemoryStorage.h
    include/libFileStorage/MemoryStorageManager.h
)

add_library(filestorage SHARED ${STORAGE_SOURCES})

add_executable (filestorage_test src/libFileBase/stubs.cpp)
link_directories(build)
target_link_libraries(filestorage_test filestorage)