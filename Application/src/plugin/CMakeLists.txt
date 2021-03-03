cmake_minimum_required(VERSION 3.5.1)
project(Hill_plugin)

if(NOT TARGET Kanzi::kzappfw)
    find_package(Kanzi REQUIRED CONFIG CMAKE_FIND_ROOT_PATH_BOTH)
endif()

include(kanzi-common)

set(sources
    src/hill.cpp
    src/hill.hpp
    src/hill_module.cpp
    src/hill_module.hpp)

add_library(Hill ${sources})
target_link_libraries(Hill PUBLIC Kanzi::kzcore Kanzi::kzcoreui Kanzi::kzui Kanzi::kzjs)

target_include_directories(Hill PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

if(BUILD_SHARED_LIBS AND MSVC)
    target_compile_definitions(Hill PRIVATE "HILL_API=__declspec(dllexport)")
    target_compile_definitions(Hill PRIVATE "HILL_API_EXPORT")
    target_compile_definitions(Hill INTERFACE "HILL_API=__declspec(dllimport)")
else()
    target_compile_definitions(Hill PUBLIC "HILL_API=")
endif()

# Copy plugin dll for the Kanzi-studio project.
if(BUILD_SHARED_LIBS AND MSVC)
    set(KANZI_PROJECT_PLUGIN_PATH "${PROJECT_SOURCE_DIR}/lib/${CMAKE_VS_PLATFORM_NAME}/${MSVC_TAG}_$<CONFIG>_DLL")
    add_custom_command(TARGET Hill POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${KANZI_PROJECT_PLUGIN_PATH}"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:Hill>" "${KANZI_PROJECT_PLUGIN_PATH}")
endif()
