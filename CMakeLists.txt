cmake_minimum_required(VERSION 3.0)

project(v.1.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_executable(obj_vector 1.0Vector.cpp)
add_executable(obj_list 1.0list.cpp)
add_executable(obj_deque 1.0Deque.cpp)