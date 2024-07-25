add_library(SmallGameFramework)

target_link_libraries(SmallGameFramework PUBLIC
    SDL2
    SDL2_image
    EnTT
    quill)
set_target_properties(SmallGameFramework PROPERTIES
    CXX_STANDARD 20)

add_subdirectory(common)
add_subdirectory(core)
