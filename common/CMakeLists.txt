cmake_minimum_required(VERSION 3.10)
project(common)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

file(GLOB COMMON_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

add_library(${PROJECT_NAME} ${COMMON_SOURCE_FILES})
add_library(strife::common ALIAS ${PROJECT_NAME})

find_package(Boost 1.65.1 COMPONENTS
    filesystem
    system
)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    Boost::filesystem
)