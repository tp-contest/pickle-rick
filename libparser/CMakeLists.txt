# Testing setup 

include(CTest)
include(GoogleTest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# FileStorage lib

include_directories(include)
set (
    PARSER_SOURCES
    src/MultipartParser.cpp
)

add_library(pickle_parser SHARED ${PARSER_SOURCES})
# target_include_directories(filestorage PRIVATE include/libFileStorage)

# GTest

add_executable (FS_gtest test/src/main.cpp)
target_link_libraries(FS_gtest pickle_parser ${GTEST_LIBRARIES} pthread)
gtest_discover_tests(FS_gtest)