cmake_minimum_required(VERSION 3.22) 
project(SmallGameFramework)
include(FetchContent)

### CMAKE CONFIG
cmake_policy(SET CMP0134 NEW)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Og)
endif()

### DEPENDENCIES
find_package(SDL2 CONFIG REQUIRED)
FetchContent_Declare(
    EnTT
    GIT_REPOSITORY  https://github.com/skypjack/entt.git
    GIT_TAG         v3.13.2)
FetchContent_Declare(
    quill
    GIT_REPOSITORY https://github.com/odygrd/quill
    GIT_TAG        v5.1.0)

FetchContent_MakeAvailable(EnTT Quill)

add_compile_options(-Wall -Wextra -Wpedantic)
add_subdirectory(source)
add_subdirectory(sandbox)
