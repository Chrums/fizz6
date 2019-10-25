cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

file(GLOB CORE_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
add_library(core ${CORE_SOURCE_FILES})

find_package(Boost 1.65.1 COMPONENTS
    filesystem
    system
)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost")
endif()

target_include_directories(core PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(core
    Boost::filesystem
    common
)