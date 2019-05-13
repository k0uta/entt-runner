cmake_minimum_required(VERSION 3.14)
project(EnTT_Runner)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        EnTT_Runner
        src/main.cpp
        src/core/app.cpp
        src/core/app.hpp
        src/core/game.cpp
        src/core/game.hpp
        src/components/render.hpp
        src/components/transform.hpp
        src/systems/sprite_load.cpp
        src/systems/sprite_load.hpp
        src/systems/sprite_render.cpp
        src/systems/sprite_render.hpp
        src/systems/transform_systems.cpp
        src/systems/transform_systems.hpp
)

# EnTT
add_subdirectory("${PROJECT_SOURCE_DIR}/External/entt" EXCLUDE_FROM_ALL)
target_include_directories(EnTT_Runner PRIVATE "${CMAKE_SOURCE_DIR}/External/entt/src")

# SDL2
add_subdirectory("${PROJECT_SOURCE_DIR}/External/SDL2" EXCLUDE_FROM_ALL)
add_compile_definitions(SDL_MAIN_HANDLED)
target_link_libraries(EnTT_Runner PRIVATE SDL2-static SDL2main)

# STB
target_compile_definitions(EnTT_Runner PRIVATE STB_IMAGE_IMPLEMENTATION)
target_include_directories(EnTT_Runner PRIVATE "${PROJECT_SOURCE_DIR}/External/stb")
target_link_directories(EnTT_Runner PRIVATE "${PROJECT_SOURCE_DIR}/External/stb")

# PugiXML
set(BUILD_SHARED_AND_STATIC_LIBS ON)
add_subdirectory("${PROJECT_SOURCE_DIR}/External/pugixml" EXCLUDE_FROM_ALL)
target_link_libraries(EnTT_Runner PRIVATE pugixml-static)

# Resources - Thanks to: http://qrikko.blogspot.com/2016/05/cmake-and-how-to-copy-resources-during.html
set (source "${PROJECT_SOURCE_DIR}/resources")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/resources")
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}"
)