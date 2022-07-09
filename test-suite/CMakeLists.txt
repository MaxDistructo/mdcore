project(mdcore-test)

file(GLOB_RECURSE test_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp" "src/*.hpp" "src/*.c")

add_executable(mdcore-test ${test_SRC})

target_link_libraries(mdcore-test mdcore Catch2)
target_include_directories(mdcore-test
    PUBLIC
        ${mdcore_SOURCE_DIR}/include
        ${catch2_SOURCE_DIR}/src
)
set_property(TARGET mdcore-test PROPERTY CXX_STANDARD 17)