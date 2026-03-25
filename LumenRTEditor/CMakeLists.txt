project(LumenRTEditor VERSION 1.1.0 LANGUAGES CXX)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/imgui-docking)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/implot)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/icon-fonts-headers)

add_executable(LumenRTEditor)
file(GLOB_RECURSE EDITOR_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(LumenRTEditor PRIVATE ${EDITOR_SOURCES})
target_include_directories(LumenRTEditor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(LumenRTEditor PUBLIC imgui implot iconFontsHeaders LumenRTEngine)

# Define paths to editor resources
target_compile_definitions(LumenRTEditor PUBLIC
    $<$<BOOL:${BUILD_INSTALL}>:CMAKE_EDITOR_RESOURCES_PATH="./editor_res/">
    $<$<NOT:$<BOOL:${BUILD_INSTALL}>>:CMAKE_EDITOR_RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/res/">
)

# Ensure Runtime gets built
add_dependencies(LumenRTEditor LumenRTRuntime)

set_target_properties(LumenRTEditor PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>
)

# Install Step
install(TARGETS LumenRTEditor # executable
    RUNTIME DESTINATION .
)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/res/ # resources
        DESTINATION editor_res)



# Compiler definitions / flags
if(MSVC)
    if (NOT ENABLE_CONSOLE)
        # Build as a GUI app (no console)
        set_target_properties(LumenRTEditor PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
    endif()
endif()

