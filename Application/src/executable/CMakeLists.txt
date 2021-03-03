cmake_minimum_required(VERSION 3.5.1)
project(Hill_executable)

if(NOT TARGET Kanzi::kzappfw)
    find_package(Kanzi REQUIRED CONFIG CMAKE_FIND_ROOT_PATH_BOTH)
endif()

include(kanzi-common)

add_executable(Hill_executable src/hill_main.cpp)

if(ANDROID)
    target_link_libraries(Hill_executable -Wl,--whole-archive Kanzi::kzappfw -Wl,--no-whole-archive)
else()
    target_link_libraries(Hill_executable Kanzi::kzappfw)
endif()

target_link_libraries(Hill_executable Kanzi::kzui Kanzi::kzcoreui Kanzi::kzjs Hill)
