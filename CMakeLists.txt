cmake_minimum_required(VERSION 3.15)
project(OmniReport VERSION 0.1 LANGUAGES CXX)

add_library(
    OmniReport SHARED
    Include/OmniReport.h
    Source/OmniReport.cpp
)

target_compile_definitions(OmniReport PRIVATE OMNIREPORT_EXPORTS)

add_executable(ConsoleTest Examples/ConsoleTest/ConsoleTest.cpp)

target_include_directories(OmniReport PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
)

target_link_libraries(ConsoleTest PRIVATE OmniReport)