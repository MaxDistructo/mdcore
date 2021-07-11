#set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.12.0)
project(mdcore)
set(HEADER_ONLY_SOURCES lib/json.hpp)

add_subdirectory(mdcore)
#add_subdirectory(test)
