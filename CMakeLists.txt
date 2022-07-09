#set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.12.0)
project(mdcore)

file(DOWNLOAD https://raw.githubusercontent.com/nlohmann/json/v3.10.5/single_include/nlohmann/json.hpp ${PROJECT_BINARY_DIR}/nlohmann_json/include/nlohmann/json.hpp)
include(FetchContent)

FetchContent_Declare(
   catch2
   GIT_REPOSITORY https://github.com/catchorg/Catch2.git 
   GIT_TAG        605a34765aa5d5ecbf476b4598a862ada971b0cc
)
FetchContent_MakeAvailable(catch2)

add_subdirectory(mdcore)
add_subdirectory(test-suite)

#add_subdirectory(test)
