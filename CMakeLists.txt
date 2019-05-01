cmake_minimum_required(VERSION 3.14)
project(EnTT_Runner)

set(CMAKE_CXX_STANDARD 17)

add_executable(EnTT_Runner main.cpp)

add_subdirectory("${CMAKE_SOURCE_DIR}/External/entt" EXCLUDE_FROM_ALL)
target_include_directories(EnTT_Runner PRIVATE "${CMAKE_SOURCE_DIR}/External/entt/src")