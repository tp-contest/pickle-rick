cmake_minimum_required(VERSION 3.2.0)

project(scheduler VERSION 0.1.0)

set(BUILD_FLAGS)

find_package(Boost COMPONENTS thread system REQUIRED)

include_directories(include)
file(GLOB SOURCE_FILES "src/*")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

add_dependencies(${PROJECT_NAME} clientworker)
target_link_libraries(${PROJECT_NAME} clientworker ${Boost_LIBRARIES})

target_include_directories(${PROJECT_NAME} PUBLIC "include")
set_target_properties(${PROJECT_NAME} PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        PROPERTIES COMPILE_FLAGS -Wall -Wextra -Werror -Wpedantic)