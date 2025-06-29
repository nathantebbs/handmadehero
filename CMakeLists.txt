cmake_minimum_required(VERSION 3.16)
project(handmadehero)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)

add_executable(handmadehero
  handmade/code/sdl_handmade.cpp
)

target_link_libraries(handmadehero PRIVATE SDL3::SDL3)
