cmake_minimum_required(VERSION 3.12)
project(cplus)

set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX d)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

message("project[${PROJECT_NAME}] build type=${CMAKE_BUILD_TYPE}")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed"  CACHE PATH "default install path" FORCE )
endif()

message("project[${PROJECT_NAME}] install path=${CMAKE_INSTALL_PREFIX}")

#ignore the shape lib warning
if ( CMAKE_HOST_APPLE )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-tautological-compare")
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wno-tautological-compare")
endif ( CMAKE_HOST_APPLE )
#set msvc /utf-8
if(MSVC)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /utf-8")
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} /utf-8")
endif(MSVC)

#
add_subdirectory(${CMAKE_SOURCE_DIR}/design_pattern)