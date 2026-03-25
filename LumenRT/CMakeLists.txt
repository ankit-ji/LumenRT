project(LumenRTEngine VERSION 1.1.0 LANGUAGES CXX)

# ---- Third-party libraries ----
# Disable unnecessary GLFW components and add libraries
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(ONLY_LIBS ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/glew-cmake)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/stb_image)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/stb_truetype)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/glm)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/assimp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/spdlog)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/entt)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/yaml-cpp)

# ---- Engine library target ----
add_library(LumenRTEngine STATIC)
set_target_properties(LumenRTEngine PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
target_compile_features(LumenRTEngine PUBLIC cxx_std_20)  # Require C++20:contentReference[oaicite:8]{index=8}
target_include_directories(LumenRTEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src )
file(GLOB_RECURSE LUMENRT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(LumenRTEngine PRIVATE ${LUMENRT_SOURCES})

# Optionally, set up precompiled header directly on the target (CMake ≥3.16)
target_precompile_headers(LumenRTEngine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/lrtpch.h")  # see CMake docs:contentReference[oaicite:9]{index=9}

target_link_libraries(LumenRTEngine PUBLIC glm spdlog::spdlog entt yaml-cpp) 
target_link_libraries(LumenRTEngine PUBLIC assimp glfw libglew_static stb_image stb_truetype) 

# Suppress array-bounds warning only for assimp
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(assimp PRIVATE -Wno-array-bounds)
endif()


# DEFINES 
target_compile_definitions(LumenRTEngine PUBLIC
    $<$<BOOL:${BUILD_INSTALL}>:BUILD_INSTALL> # if ON -> #define BUILD_INSTALL
)
target_compile_definitions(LumenRTEngine PUBLIC
    $<$<BOOL:${BUILD_INSTALL}>:CMAKE_ENGINE_RESOURCES_PATH="./engine_res/">
    $<$<NOT:$<BOOL:${BUILD_INSTALL}>>:CMAKE_ENGINE_RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/res/">
)
if(WIN32)
    target_compile_definitions(LumenRTEngine PUBLIC LRT_PLATFORM_WINDOWS)
endif()

# --target install (copy res near the executable)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/res/
        DESTINATION engine_res)