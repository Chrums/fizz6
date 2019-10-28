cmake_minimum_required(VERSION 3.10)
project(strife)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(Strife_VERSION_MAJOR 1)
set(Strife_VERSION_MINOR 0)

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
)

find_package(Boost 1.65.1 COMPONENTS
    filesystem
    system
)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost")
endif()

set(STRIFE_INCLUDE_DIR ${PROJECT_BINARY_DIR}/include)

add_subdirectory(common)
add_subdirectory(core)

include_directories(${STRIFE_INCLUDE_DIR})
add_executable(strife main.cpp)

target_link_libraries(strife
    strife::common
    strife::core
)

install(TARGETS strife DESTINATION ${PROJECT_BINARY_DIR}/bin)