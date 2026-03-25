project(LumenRTRuntime LANGUAGES CXX)

add_executable(LumenRTRuntime)

target_compile_features(LumenRTRuntime PRIVATE cxx_std_20)
file(GLOB_RECURSE RUNTIME_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(LumenRTRuntime PRIVATE ${RUNTIME_SOURCES})
target_include_directories(LumenRTRuntime PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(LumenRTRuntime PUBLIC LumenRTEngine)

# compile into the same config folder as the editor
set_target_properties(LumenRTRuntime PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/runtime
    #RUNTIME_OUTPUT_DIRECTORY C:/Dev/LumenRTExports/tst123
)

install(TARGETS LumenRTRuntime # executable
    RUNTIME DESTINATION runtime
)

if(MSVC)
    target_compile_definitions(LumenRTRuntime PUBLIC _CRT_SECURE_NO_WARNINGS)
    if(NOT ENABLE_CONSOLE)
        set_target_properties(LumenRTRuntime PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
    endif()
endif()

