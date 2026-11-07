cmake_minimum_required(VERSION 4.2.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

project(fruit)

file(GLOB source_files src/*.cpp)

add_executable(fruit ${source_files})
target_include_directories(fruit PRIVATE include)
