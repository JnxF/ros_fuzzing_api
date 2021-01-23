cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 11)

project(fuzzing_api CXX)

add_library(fuzzing_api_library INTERFACE)
target_include_directories(fuzzing_api_library INTERFACE src)

add_executable(fuzzing_api_executable src/main.cpp)
target_link_libraries(fuzzing_api_executable fuzzing_api_library)
install()