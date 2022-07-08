#set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.12.0)
project(mdcore)

file(DOWNLOAD https://raw.githubusercontent.com/nlohmann/json/v3.10.5/single_include/nlohmann/json.hpp ${PROJECT_BINARY_DIR}/nlohmann_json/include/nlohmann/json.hpp)

add_subdirectory(mdcore)

#add_subdirectory(test)
