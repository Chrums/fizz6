cmake_minimum_required(VERSION 3.10)
project(core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

file(GLOB CORE_INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*)
file(GLOB CORE_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

add_library(${PROJECT_NAME} ${CORE_SOURCE_FILES})
add_library(strife::core ALIAS ${PROJECT_NAME})

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
    strife::common
)

install(TARGETS core DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${CORE_INCLUDE_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/core)