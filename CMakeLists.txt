cmake_minimum_required(VERSION 3.15)
project(OmniReport VERSION 0.1 LANGUAGES CXX)

# add C++ libcpr library for http requests
include(FetchContent)

set(CPR_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(CPR_GENERATE_PKGCONFIG OFF CACHE BOOL "" FORCE)
set(CPR_BUILD_TESTS_SSL OFF CACHE BOOL "" FORCE)

set(CPR_USE_SYSTEM_CURL OFF CACHE BOOL "" FORCE)
set(CPR_USE_SYSTEM_LIBZ OFF CACHE BOOL "" FORCE)

# Disable the specific library causing the Meson error
set(FETCHCONTENT_FULLY_DISCONNECTED OFF) 
set(LIBCURL_ENABLE_PSL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    cpr 
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.10.1
)

FetchContent_MakeAvailable(cpr)

add_library(
    OmniReport SHARED
    Include/OmniReport.h
    Source/OmniReport.cpp
)

target_compile_definitions(OmniReport PRIVATE OMNIREPORT_EXPORTS)

target_include_directories(OmniReport PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
)

target_link_libraries(OmniReport PRIVATE cpr::cpr)

add_executable(ConsoleTest Examples/ConsoleTest/ConsoleTest.cpp)

target_link_libraries(ConsoleTest PRIVATE OmniReport)