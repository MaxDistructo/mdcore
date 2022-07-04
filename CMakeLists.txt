#set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.12.0)
project(mdcore)

include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        4f8fba14066156b73f1189a2b8bd568bde5284c5
)

FetchContent_MakeAvailable(nlohmann_json)
set(HEADER_ONLY_SOURCES lib/json.hpp)

add_subdirectory(mdcore)
target_link_libraries(nlohmann_json)
#add_subdirectory(test)
