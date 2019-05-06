cmake_minimum_required(VERSION 3.0.0)

set(TARGET scheduler)
set(BUILD_FLAGS -Wall -Wextra -Werror -Wpedantic)


project(${TARGET} VERSION 0.1.0)

include_directories(include)
set(
        SOURCES
        include/scheduler.h
        src/consumer.cpp
        src/consumer.h
        src/data_container.cpp
        src/data_container.h
        src/i_queue.cpp
        src/i_queue.h
        src/producer.cpp
        src/producer.h
        src/queue.cpp
        src/queue.h
        src/scheduler.cpp
        src/string_producer.cpp
        src/string_producer.h
        src/string_consumer.cpp
        src/string_consumer.h
)

add_library(${TARGET} ${SOURCES})

set_target_properties(${TARGET} PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        set_target_properties (${TARGET} PROPERTIES COMPILE_FLAGS ${BUILD_FLAGS}))

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
