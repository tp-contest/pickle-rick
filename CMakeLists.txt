cmake_minimum_required(VERSION 3.0.0)
project(pickle-rick VERSION 0.1.0)

add_subdirectory(libscheduler)

add_executable(pickle-rick main.cpp)
target_link_libraries(pickle-rick ${PROJECT_SOURCE_DIR}/cmake-build-debug/libscheduler/libscheduler.a)
