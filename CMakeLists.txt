cmake_minimum_required(VERSION 3.20)
project(homework5)

set(CMAKE_CXX_STANDARD 20)

add_executable(homework5 main.cpp)
target_include_directories(homework5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)