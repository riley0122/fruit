cmake_minimum_required(VERSION 4.2.1)

project(fruit)

add_executable(fruit src/main.cpp)
target_include_directories(fruit PRIVATE include)
