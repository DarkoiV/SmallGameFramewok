add_executable(Sandbox
    sandbox.cpp)

target_link_libraries(Sandbox 
    SmallGameFramework)
set_target_properties(Sandbox PROPERTIES
    CXX_STANDARD 20
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/sandbox")

add_custom_target(run
    COMMAND Sandbox)
