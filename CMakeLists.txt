cmake_minimum_required(VERSION 4.2.1)

project(fruit)

file(GLOB source_files src/*.cpp)

add_executable(fruit ${source_files})
target_include_directories(fruit PRIVATE include)
