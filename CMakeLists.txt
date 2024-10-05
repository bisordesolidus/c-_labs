cmake_minimum_required(VERSION 3.10)


set(CMAKE_C_COMPILER gcc)

set(CMAKE_CXX_COMPILER g++)

project(risuem_kal)

message(INFO:\ ${TASK_SOURCE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(SOURCES src/utils.cpp src/vec3.cpp src/transformations.cpp)
add_executable(kal_draw main.cpp) 
include_directories(include)
target_sources(kal_draw PUBLIC ${SOURCES})





