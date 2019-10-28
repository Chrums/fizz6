cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

file(GLOB COMMON_INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*)
file(GLOB COMMON_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
add_library(common ${COMMON_SOURCE_FILES})

set(COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

find_package(Boost 1.65.1 COMPONENTS
    filesystem
    system
)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost")
endif()

target_include_directories(common PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${COMMON_INCLUDE_DIR}
)

target_link_libraries(common
    Boost::filesystem
)

install(TARGETS common DESTINATION ${PROJECT_BINARY_DIR}/lib)