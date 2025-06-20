cmake_minimum_required(VERSION 3.11)
project(Retro_Snake)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(raylib)

add_executable(Retro_Snake main.cpp
        Scripts/GameUtils.h
        Scripts/GameLoop.cpp
        Scripts/GameLoop.h
        Scripts/Food.cpp
        Scripts/Food.h
        Scripts/Entity.h
        Scripts/Snake.cpp
        Scripts/Snake.h)

target_include_directories(Retro_Snake PRIVATE
    raylib/src
)

target_link_libraries(Retro_Snake PRIVATE raylib_static)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#if(WIN32)
#    add_custom_command(TARGET Retro_Snake POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different
#            $<TARGET_FILE:raylib>
#            $<TARGET_FILE_DIR:Retro_Snake>
#    )
#endif()