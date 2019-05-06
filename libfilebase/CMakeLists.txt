# Testing setup 

include(CTest)
include(GoogleTest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# FileStorage lib

include_directories(include)
set (
    STORAGE_SOURCES
    src/MemoryFile.cpp
    src/Folder.cpp
    src/FileSystem.cpp
    src/ContestStorage.cpp 
    include/FileInfo.h
    include/ContestFileInfo.h
    include/IStorage.h
    include/ContestStorage.h 
    include/FileSystem.h
    include/IFileSystemObject.h
    include/IFile.h
    include/Folder.h
    include/MemoryFile.h
)

add_library(filestorage SHARED ${STORAGE_SOURCES})
target_include_directories(filestorage PRIVATE include/libFileStorage)

# GTest

add_executable (FS_gtest test/src/main.cpp)
target_link_libraries(FS_gtest filestorage ${GTEST_LIBRARIES} pthread)
gtest_discover_tests(FS_gtest)