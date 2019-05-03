cmake_minimum_required(VERSION 3.14)
project(EnTT_Runner)

set(CMAKE_CXX_STANDARD 17)

add_executable(EnTT_Runner src/main.cpp)

# EnTT
add_subdirectory("${CMAKE_SOURCE_DIR}/External/entt" EXCLUDE_FROM_ALL)
target_include_directories(EnTT_Runner PRIVATE "${CMAKE_SOURCE_DIR}/External/entt/src")

# SDL2
add_subdirectory("${CMAKE_SOURCE_DIR}/External/SDL2" EXCLUDE_FROM_ALL)
add_compile_definitions(SDL_MAIN_HANDLED)
target_link_libraries(EnTT_Runner SDL2-static SDL2main)

# STB
target_compile_definitions(EnTT_Runner PRIVATE STB_IMAGE_IMPLEMENTATION)
target_include_directories(EnTT_Runner PRIVATE "${PROJECT_SOURCE_DIR}/External/stb")
target_link_directories(EnTT_Runner PRIVATE "${PROJECT_SOURCE_DIR}/External/stb")