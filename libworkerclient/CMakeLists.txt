
cmake_minimum_required(VERSION 3.7)
project(clientworker)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(cpprestsdk_DIR /usr/lib/x86_64-linux-gnu/cmake)

find_package(cpprestsdk REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)

include_directories(${PROJECT_SOURCE_DIR} include src)
file(GLOB SOURCE_FILES "include/*" "src/*")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_include_directories(clientworker PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC cpprestsdk::cpprest ${Boost_SYSTEM_LIBRARY})