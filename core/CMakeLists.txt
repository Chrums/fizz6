cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

file(GLOB CORE_INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*)
file(GLOB CORE_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
add_library(core ${CORE_SOURCE_FILES})

set(CORE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

find_package(Boost 1.65.1 COMPONENTS
    filesystem
    system
)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost")
endif()

target_include_directories(core PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${COMMON_INCLUDE_DIR}
    ${CORE_INCLUDE_DIR}
)

target_link_libraries(core
    Boost::filesystem
    common
)

install(TARGETS core DESTINATION ${PROJECT_BINARY_DIR}/lib)